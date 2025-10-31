
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
    "DBU_cqcmrptgrn.pc"
};


static unsigned int sqlctx = 9379595;


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
            void  *sqhstv[83];
   unsigned int   sqhstl[83];
            int   sqhsts[83];
            void  *sqindv[83];
            int   sqinds[83];
   unsigned int   sqharm[83];
   unsigned int   *sqharc[83];
   unsigned short  sqadto[83];
   unsigned short  sqtdso[83];
} sqlstm = {13,83};

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
"select FACTORY ,REPORT_NO ,LOT_ID ,GRADE ,SIZES ,ORDER_NO ,CUST_NO ,GRADE_S\
PEC ,SIZES_SPEC ,TI_SPEC ,TTI_SPEC ,MA_SPEC ,WT_SPEC ,BD_SPEC ,TD_SPEC ,PCS_S\
PEC ,PSD_TS_SPEC ,PSD_US_SPEC ,PSD_SS_SPEC ,PSD_OS_SPEC ,PSD_LS_SPEC ,PSD_FS_\
SPEC ,HLT_TI_SPEC ,TI_VAL ,TTI_VAL ,MA_VAL ,WT_VAL ,BD_VAL ,TD_VAL ,PCS_VAL ,\
PSD_TS_VAL ,PSD_US_VAL ,PSD_SS_VAL ,PSD_OS_VAL ,PSD_LS_VAL ,PSD_FS_VAL ,HLT_T\
I_VAL ,ATTRIBUTE01 ,ATTRIBUTE02 ,ATTRIBUTE03 ,ATTRIBUTE04 ,ATTRIBUTE05 ,ATTRI\
BUTE06 ,ATTRIBUTE07 ,ATTRIBUTE08 ,ATTRIBUTE09 ,ATTRIBUTE10 ,REMARKS ,USE_YN ,\
CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,IMAGE_NUM ,BD_TI_SP\
EC ,BD_TTI_SPEC ,BD_TTI_VAL ,BD_TI_VAL ,SURFACE_B_VAL ,HEADER_ID ,LINE_NUMBER\
 ,IMAGE_NUM2 ,IMAGE_NUM3 ,CM_L_VAL ,CM_A_VAL ,CM_B_VAL ,RPT_CMF_1 ,RPT_CMF_2 \
,RPT_CMF_3 ,RPT_CMF_4 ,RPT_CMF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CMF_8 ,RPT_CMF_9 \
,RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,RPT_CMF_13 ,RPT_CMF_14 ,RPT_CMF_15  from\
 CQCMRPTGRN  order by REPORT_NO asc ,LOT_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1370,0,4,46,0,0,83,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
352,0,0,2,1368,0,4,249,0,0,82,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,
695,0,0,3,79,0,4,453,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
722,0,0,4,62,0,4,461,0,0,2,1,0,1,0,2,4,0,0,1,97,0,0,
745,0,0,5,61,0,2,497,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
768,0,0,6,44,0,2,503,0,0,1,1,0,1,0,1,97,0,0,
787,0,0,7,1258,0,3,532,0,0,81,81,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1126,0,0,8,1246,0,5,719,0,0,80,80,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1461,0,0,9,982,0,9,916,0,0,0,0,0,1,0,
1476,0,0,9,0,0,13,945,0,0,81,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1815,0,0,9,0,0,15,1056,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmrptgrn.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-05 20:35:39
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
void DBU_add_null_cqcmrptgrn(struct CQCMRPTGRN_N_TAG *CQCMRPTGRN_N, struct CQCMRPTGRN_TAG *CQCMRPTGRN);
void DBU_del_null_cqcmrptgrn(struct CQCMRPTGRN_N_TAG *CQCMRPTGRN_N, struct CQCMRPTGRN_TAG *CQCMRPTGRN);


/* SQL SELECT Function */
void DBU_select_cqcmrptgrn(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT
			        FACTORY, 
                    REPORT_NO,
                    LOT_ID,
                    GRADE,
                    SIZES,
                    ORDER_NO,
                    CUST_NO,
                    GRADE_SPEC,
                    SIZES_SPEC,
                    TI_SPEC,
                    TTI_SPEC,
                    MA_SPEC,
                    WT_SPEC,
                    BD_SPEC,
                    TD_SPEC,
                    PCS_SPEC,
                    PSD_TS_SPEC,
                    PSD_US_SPEC,
                    PSD_SS_SPEC,
                    PSD_OS_SPEC,
                    PSD_LS_SPEC,
                    PSD_FS_SPEC,
                    HLT_TI_SPEC,
                    TI_VAL,
                    TTI_VAL,
                    MA_VAL,
                    WT_VAL,
                    BD_VAL,
                    TD_VAL,
                    PCS_VAL,
                    PSD_TS_VAL,
                    PSD_US_VAL,
                    PSD_SS_VAL,
                    PSD_OS_VAL,
                    PSD_LS_VAL,
                    PSD_FS_VAL,
                    HLT_TI_VAL,
                    ATTRIBUTE01,
                    ATTRIBUTE02,
                    ATTRIBUTE03,
                    ATTRIBUTE04,
                    ATTRIBUTE05,
                    ATTRIBUTE06,
                    ATTRIBUTE07,
                    ATTRIBUTE08,
                    ATTRIBUTE09,
                    ATTRIBUTE10,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    IMAGE_NUM,
                    BD_TI_SPEC,
                    BD_TTI_SPEC,
                    BD_TTI_VAL,
                    BD_TI_VAL,
                    SURFACE_B_VAL,
                    HEADER_ID,
                    LINE_NUMBER,
                    IMAGE_NUM2,
                    IMAGE_NUM3,
                    CM_L_VAL,
                    CM_A_VAL,
                    CM_B_VAL,
                    RPT_CMF_1,
                    RPT_CMF_2,
                    RPT_CMF_3,
                    RPT_CMF_4,
                    RPT_CMF_5,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15
                INTO 
				    :CQCMRPTGRN_N.FACTORY,
                    :CQCMRPTGRN_N.REPORT_NO,
                    :CQCMRPTGRN_N.LOT_ID,
                    :CQCMRPTGRN_N.GRADE,
                    :CQCMRPTGRN_N.SIZES,
                    :CQCMRPTGRN_N.ORDER_NO,
                    :CQCMRPTGRN_N.CUST_NO,
                    :CQCMRPTGRN_N.GRADE_SPEC,
                    :CQCMRPTGRN_N.SIZES_SPEC,
                    :CQCMRPTGRN_N.TI_SPEC,
                    :CQCMRPTGRN_N.TTI_SPEC,
                    :CQCMRPTGRN_N.MA_SPEC,
                    :CQCMRPTGRN_N.WT_SPEC,
                    :CQCMRPTGRN_N.BD_SPEC,
                    :CQCMRPTGRN_N.TD_SPEC,
                    :CQCMRPTGRN_N.PCS_SPEC,
                    :CQCMRPTGRN_N.PSD_TS_SPEC,
                    :CQCMRPTGRN_N.PSD_US_SPEC,
                    :CQCMRPTGRN_N.PSD_SS_SPEC,
                    :CQCMRPTGRN_N.PSD_OS_SPEC,
                    :CQCMRPTGRN_N.PSD_LS_SPEC,
                    :CQCMRPTGRN_N.PSD_FS_SPEC,
                    :CQCMRPTGRN_N.HLT_TI_SPEC,
                    :CQCMRPTGRN_N.TI_VAL,
                    :CQCMRPTGRN_N.TTI_VAL,
                    :CQCMRPTGRN_N.MA_VAL,
                    :CQCMRPTGRN_N.WT_VAL,
                    :CQCMRPTGRN_N.BD_VAL,
                    :CQCMRPTGRN_N.TD_VAL,
                    :CQCMRPTGRN_N.PCS_VAL,
                    :CQCMRPTGRN_N.PSD_TS_VAL,
                    :CQCMRPTGRN_N.PSD_US_VAL,
                    :CQCMRPTGRN_N.PSD_SS_VAL,
                    :CQCMRPTGRN_N.PSD_OS_VAL,
                    :CQCMRPTGRN_N.PSD_LS_VAL,
                    :CQCMRPTGRN_N.PSD_FS_VAL,
                    :CQCMRPTGRN_N.HLT_TI_VAL,
                    :CQCMRPTGRN_N.ATTRIBUTE01,
                    :CQCMRPTGRN_N.ATTRIBUTE02,
                    :CQCMRPTGRN_N.ATTRIBUTE03,
                    :CQCMRPTGRN_N.ATTRIBUTE04,
                    :CQCMRPTGRN_N.ATTRIBUTE05,
                    :CQCMRPTGRN_N.ATTRIBUTE06,
                    :CQCMRPTGRN_N.ATTRIBUTE07,
                    :CQCMRPTGRN_N.ATTRIBUTE08,
                    :CQCMRPTGRN_N.ATTRIBUTE09,
                    :CQCMRPTGRN_N.ATTRIBUTE10,
                    :CQCMRPTGRN_N.REMARKS,
                    :CQCMRPTGRN_N.USE_YN,
                    :CQCMRPTGRN_N.CREATE_USER_ID,
                    :CQCMRPTGRN_N.CREATE_TIME,
                    :CQCMRPTGRN_N.UPDATE_USER_ID,
                    :CQCMRPTGRN_N.UPDATE_TIME,
                    :CQCMRPTGRN_N.IMAGE_NUM,
                    :CQCMRPTGRN_N.BD_TI_SPEC,
                    :CQCMRPTGRN_N.BD_TTI_SPEC,
                    :CQCMRPTGRN_N.BD_TTI_VAL,
                    :CQCMRPTGRN_N.BD_TI_VAL,
                    :CQCMRPTGRN_N.SURFACE_B_VAL,
                    :CQCMRPTGRN_N.HEADER_ID,
                    :CQCMRPTGRN_N.LINE_NUMBER,
                    :CQCMRPTGRN_N.IMAGE_NUM2,
                    :CQCMRPTGRN_N.IMAGE_NUM3,
                    :CQCMRPTGRN_N.CM_L_VAL,
                    :CQCMRPTGRN_N.CM_A_VAL,
                    :CQCMRPTGRN_N.CM_B_VAL,
                    :CQCMRPTGRN_N.RPT_CMF_1,
                    :CQCMRPTGRN_N.RPT_CMF_2,
                    :CQCMRPTGRN_N.RPT_CMF_3,
                    :CQCMRPTGRN_N.RPT_CMF_4,
                    :CQCMRPTGRN_N.RPT_CMF_5,
                    :CQCMRPTGRN_N.RPT_CMF_6,
                    :CQCMRPTGRN_N.RPT_CMF_7,
                    :CQCMRPTGRN_N.RPT_CMF_8,
                    :CQCMRPTGRN_N.RPT_CMF_9,
                    :CQCMRPTGRN_N.RPT_CMF_10,
                    :CQCMRPTGRN_N.RPT_CMF_11,
                    :CQCMRPTGRN_N.RPT_CMF_12,
                    :CQCMRPTGRN_N.RPT_CMF_13,
                    :CQCMRPTGRN_N.RPT_CMF_14,
                    :CQCMRPTGRN_N.RPT_CMF_15
                FROM CQCMRPTGRN
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRN_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,REPORT_NO ,LOT_ID ,GRADE ,SIZES ,ORDER_NO ,CU\
ST_NO ,GRADE_SPEC ,SIZES_SPEC ,TI_SPEC ,TTI_SPEC ,MA_SPEC ,WT_SPEC ,BD_SPEC \
,TD_SPEC ,PCS_SPEC ,PSD_TS_SPEC ,PSD_US_SPEC ,PSD_SS_SPEC ,PSD_OS_SPEC ,PSD_\
LS_SPEC ,PSD_FS_SPEC ,HLT_TI_SPEC ,TI_VAL ,TTI_VAL ,MA_VAL ,WT_VAL ,BD_VAL ,\
TD_VAL ,PCS_VAL ,PSD_TS_VAL ,PSD_US_VAL ,PSD_SS_VAL ,PSD_OS_VAL ,PSD_LS_VAL \
,PSD_FS_VAL ,HLT_TI_VAL ,ATTRIBUTE01 ,ATTRIBUTE02 ,ATTRIBUTE03 ,ATTRIBUTE04 \
,ATTRIBUTE05 ,ATTRIBUTE06 ,ATTRIBUTE07 ,ATTRIBUTE08 ,ATTRIBUTE09 ,ATTRIBUTE1\
0 ,REMARKS ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME\
 ,IMAGE_NUM ,BD_TI_SPEC ,BD_TTI_SPEC ,BD_TTI_VAL ,BD_TI_VAL ,SURFACE_B_VAL ,\
HEADER_ID ,LINE_NUMBER ,IMAGE_NUM2 ,IMAGE_NUM3 ,CM_L_VAL ,CM_A_VAL ,CM_B_VAL\
 ,RPT_CMF_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_CMF_5 ,RPT_CMF_6 ,RPT_CMF_\
7 ,RPT_CMF_8 ,RPT_CMF_9 ,RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,RPT_CMF_13 ,RPT\
_CMF_14 ,RPT_CMF_15 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:\
b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b");
            sqlstm.stmt = "22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,\
:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b\
47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62\
,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:\
b78,:b79,:b80  from CQCMRPTGRN where (REPORT_NO=:b1 and LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRN_N.GRADE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRN_N.SIZES);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRN_N.ORDER_NO);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRN_N.CUST_NO);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGRN_N.GRADE_SPEC);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRN_N.SIZES_SPEC);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRN_N.TI_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRN_N.TTI_SPEC);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRN_N.MA_SPEC);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRN_N.WT_SPEC);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRN_N.BD_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRN_N.TD_SPEC);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRN_N.PCS_SPEC);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRN_N.PSD_TS_SPEC);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRN_N.PSD_US_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRN_N.PSD_SS_SPEC);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRN_N.PSD_OS_SPEC);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRN_N.PSD_LS_SPEC);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRN_N.PSD_FS_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRN_N.HLT_TI_SPEC);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRN_N.TI_VAL);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRN_N.TTI_VAL);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRN_N.MA_VAL);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRN_N.WT_VAL);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRN_N.BD_VAL);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRN_N.TD_VAL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRN_N.PCS_VAL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRN_N.PSD_TS_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRN_N.PSD_US_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRN_N.PSD_SS_VAL);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRN_N.PSD_OS_VAL);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRN_N.PSD_LS_VAL);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRN_N.PSD_FS_VAL);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRN_N.HLT_TI_VAL);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE01);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE02);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE03);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE04);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE05);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE06);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE07);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE08);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE09);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRN_N.REMARKS);
            sqlstm.sqhstl[47] = (unsigned int  )101;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRN_N.USE_YN);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRN_N.CREATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRN_N.CREATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRN_N.UPDATE_USER_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRN_N.UPDATE_TIME);
            sqlstm.sqhstl[52] = (unsigned int  )15;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRN_N.BD_TI_SPEC);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRN_N.BD_TTI_SPEC);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRN_N.BD_TTI_VAL);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRN_N.BD_TI_VAL);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRN_N.SURFACE_B_VAL);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRN_N.HEADER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRN_N.LINE_NUMBER);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM2);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM3);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRN_N.CM_L_VAL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRN_N.CM_A_VAL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRN_N.CM_B_VAL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_1);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_2);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_3);
            sqlstm.sqhstl[68] = (unsigned int  )51;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_4);
            sqlstm.sqhstl[69] = (unsigned int  )51;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_5);
            sqlstm.sqhstl[70] = (unsigned int  )51;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_6);
            sqlstm.sqhstl[71] = (unsigned int  )51;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_7);
            sqlstm.sqhstl[72] = (unsigned int  )51;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_8);
            sqlstm.sqhstl[73] = (unsigned int  )51;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_9);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_10);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_11);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_12);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_13);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_14);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_15);
            sqlstm.sqhstl[80] = (unsigned int  )51;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    }

    DB_stop_query_timer("DBU_select_cqcmrptgrn", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmrptgrn_for_update(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    REPORT_NO,
                    LOT_ID,
                    GRADE,
                    SIZES,
                    ORDER_NO,
                    CUST_NO,
                    GRADE_SPEC,
                    SIZES_SPEC,
                    TI_SPEC,
                    TTI_SPEC,
                    MA_SPEC,
                    WT_SPEC,
                    BD_SPEC,
                    TD_SPEC,
                    PCS_SPEC,
                    PSD_TS_SPEC,
                    PSD_US_SPEC,
                    PSD_SS_SPEC,
                    PSD_OS_SPEC,
                    PSD_LS_SPEC,
                    PSD_FS_SPEC,
                    HLT_TI_SPEC,
                    TI_VAL,
                    TTI_VAL,
                    MA_VAL,
                    WT_VAL,
                    BD_VAL,
                    TD_VAL,
                    PCS_VAL,
                    PSD_TS_VAL,
                    PSD_US_VAL,
                    PSD_SS_VAL,
                    PSD_OS_VAL,
                    PSD_LS_VAL,
                    PSD_FS_VAL,
                    HLT_TI_VAL,
                    ATTRIBUTE01,
                    ATTRIBUTE02,
                    ATTRIBUTE03,
                    ATTRIBUTE04,
                    ATTRIBUTE05,
                    ATTRIBUTE06,
                    ATTRIBUTE07,
                    ATTRIBUTE08,
                    ATTRIBUTE09,
                    ATTRIBUTE10,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    IMAGE_NUM,
                    BD_TI_SPEC,
                    BD_TTI_SPEC,
                    BD_TTI_VAL,
                    BD_TI_VAL,
                    SURFACE_B_VAL,
                    HEADER_ID,
                    LINE_NUMBER,
                    IMAGE_NUM2,
                    IMAGE_NUM3,
                    CM_L_VAL,
                    CM_A_VAL,
                    CM_B_VAL,
                    RPT_CMF_1,
                    RPT_CMF_2,
                    RPT_CMF_3,
                    RPT_CMF_4,
                    RPT_CMF_5,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15
                INTO 
                    :CQCMRPTGRN_N.REPORT_NO,
                    :CQCMRPTGRN_N.LOT_ID,
                    :CQCMRPTGRN_N.GRADE,
                    :CQCMRPTGRN_N.SIZES,
                    :CQCMRPTGRN_N.ORDER_NO,
                    :CQCMRPTGRN_N.CUST_NO,
                    :CQCMRPTGRN_N.GRADE_SPEC,
                    :CQCMRPTGRN_N.SIZES_SPEC,
                    :CQCMRPTGRN_N.TI_SPEC,
                    :CQCMRPTGRN_N.TTI_SPEC,
                    :CQCMRPTGRN_N.MA_SPEC,
                    :CQCMRPTGRN_N.WT_SPEC,
                    :CQCMRPTGRN_N.BD_SPEC,
                    :CQCMRPTGRN_N.TD_SPEC,
                    :CQCMRPTGRN_N.PCS_SPEC,
                    :CQCMRPTGRN_N.PSD_TS_SPEC,
                    :CQCMRPTGRN_N.PSD_US_SPEC,
                    :CQCMRPTGRN_N.PSD_SS_SPEC,
                    :CQCMRPTGRN_N.PSD_OS_SPEC,
                    :CQCMRPTGRN_N.PSD_LS_SPEC,
                    :CQCMRPTGRN_N.PSD_FS_SPEC,
                    :CQCMRPTGRN_N.HLT_TI_SPEC,
                    :CQCMRPTGRN_N.TI_VAL,
                    :CQCMRPTGRN_N.TTI_VAL,
                    :CQCMRPTGRN_N.MA_VAL,
                    :CQCMRPTGRN_N.WT_VAL,
                    :CQCMRPTGRN_N.BD_VAL,
                    :CQCMRPTGRN_N.TD_VAL,
                    :CQCMRPTGRN_N.PCS_VAL,
                    :CQCMRPTGRN_N.PSD_TS_VAL,
                    :CQCMRPTGRN_N.PSD_US_VAL,
                    :CQCMRPTGRN_N.PSD_SS_VAL,
                    :CQCMRPTGRN_N.PSD_OS_VAL,
                    :CQCMRPTGRN_N.PSD_LS_VAL,
                    :CQCMRPTGRN_N.PSD_FS_VAL,
                    :CQCMRPTGRN_N.HLT_TI_VAL,
                    :CQCMRPTGRN_N.ATTRIBUTE01,
                    :CQCMRPTGRN_N.ATTRIBUTE02,
                    :CQCMRPTGRN_N.ATTRIBUTE03,
                    :CQCMRPTGRN_N.ATTRIBUTE04,
                    :CQCMRPTGRN_N.ATTRIBUTE05,
                    :CQCMRPTGRN_N.ATTRIBUTE06,
                    :CQCMRPTGRN_N.ATTRIBUTE07,
                    :CQCMRPTGRN_N.ATTRIBUTE08,
                    :CQCMRPTGRN_N.ATTRIBUTE09,
                    :CQCMRPTGRN_N.ATTRIBUTE10,
                    :CQCMRPTGRN_N.REMARKS,
                    :CQCMRPTGRN_N.USE_YN,
                    :CQCMRPTGRN_N.CREATE_USER_ID,
                    :CQCMRPTGRN_N.CREATE_TIME,
                    :CQCMRPTGRN_N.UPDATE_USER_ID,
                    :CQCMRPTGRN_N.UPDATE_TIME,
                    :CQCMRPTGRN_N.IMAGE_NUM,
                    :CQCMRPTGRN_N.BD_TI_SPEC,
                    :CQCMRPTGRN_N.BD_TTI_SPEC,
                    :CQCMRPTGRN_N.BD_TTI_VAL,
                    :CQCMRPTGRN_N.BD_TI_VAL,
                    :CQCMRPTGRN_N.SURFACE_B_VAL,
                    :CQCMRPTGRN_N.HEADER_ID,
                    :CQCMRPTGRN_N.LINE_NUMBER,
                    :CQCMRPTGRN_N.IMAGE_NUM2,
                    :CQCMRPTGRN_N.IMAGE_NUM3,
                    :CQCMRPTGRN_N.CM_L_VAL,
                    :CQCMRPTGRN_N.CM_A_VAL,
                    :CQCMRPTGRN_N.CM_B_VAL,
                    :CQCMRPTGRN_N.RPT_CMF_1,
                    :CQCMRPTGRN_N.RPT_CMF_2,
                    :CQCMRPTGRN_N.RPT_CMF_3,
                    :CQCMRPTGRN_N.RPT_CMF_4,
                    :CQCMRPTGRN_N.RPT_CMF_5,
                    :CQCMRPTGRN_N.RPT_CMF_6,
                    :CQCMRPTGRN_N.RPT_CMF_7,
                    :CQCMRPTGRN_N.RPT_CMF_8,
                    :CQCMRPTGRN_N.RPT_CMF_9,
                    :CQCMRPTGRN_N.RPT_CMF_10,
                    :CQCMRPTGRN_N.RPT_CMF_11,
                    :CQCMRPTGRN_N.RPT_CMF_12,
                    :CQCMRPTGRN_N.RPT_CMF_13,
                    :CQCMRPTGRN_N.RPT_CMF_14,
                    :CQCMRPTGRN_N.RPT_CMF_15
                FROM CQCMRPTGRN
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRN_N.LOT_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select REPORT_NO ,LOT_ID ,GRADE ,SIZES ,ORDER_NO ,CUST_NO ,GR\
ADE_SPEC ,SIZES_SPEC ,TI_SPEC ,TTI_SPEC ,MA_SPEC ,WT_SPEC ,BD_SPEC ,TD_SPEC \
,PCS_SPEC ,PSD_TS_SPEC ,PSD_US_SPEC ,PSD_SS_SPEC ,PSD_OS_SPEC ,PSD_LS_SPEC ,\
PSD_FS_SPEC ,HLT_TI_SPEC ,TI_VAL ,TTI_VAL ,MA_VAL ,WT_VAL ,BD_VAL ,TD_VAL ,P\
CS_VAL ,PSD_TS_VAL ,PSD_US_VAL ,PSD_SS_VAL ,PSD_OS_VAL ,PSD_LS_VAL ,PSD_FS_V\
AL ,HLT_TI_VAL ,ATTRIBUTE01 ,ATTRIBUTE02 ,ATTRIBUTE03 ,ATTRIBUTE04 ,ATTRIBUT\
E05 ,ATTRIBUTE06 ,ATTRIBUTE07 ,ATTRIBUTE08 ,ATTRIBUTE09 ,ATTRIBUTE10 ,REMARK\
S ,USE_YN ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,IMAGE_N\
UM ,BD_TI_SPEC ,BD_TTI_SPEC ,BD_TTI_VAL ,BD_TI_VAL ,SURFACE_B_VAL ,HEADER_ID\
 ,LINE_NUMBER ,IMAGE_NUM2 ,IMAGE_NUM3 ,CM_L_VAL ,CM_A_VAL ,CM_B_VAL ,RPT_CMF\
_1 ,RPT_CMF_2 ,RPT_CMF_3 ,RPT_CMF_4 ,RPT_CMF_5 ,RPT_CMF_6 ,RPT_CMF_7 ,RPT_CM\
F_8 ,RPT_CMF_9 ,RPT_CMF_10 ,RPT_CMF_11 ,RPT_CMF_12 ,RPT_CMF_13 ,RPT_CMF_14 ,\
RPT_CMF_15 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,\
:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:");
            sqlstm.stmt = "b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33\
,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:\
b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b6\
4,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79 \
 from CQCMRPTGRN where (REPORT_NO=:b0 and LOT_ID=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )352;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRN_N.GRADE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRN_N.SIZES);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRN_N.ORDER_NO);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRN_N.CUST_NO);
            sqlstm.sqhstl[5] = (unsigned int  )101;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRN_N.GRADE_SPEC);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGRN_N.SIZES_SPEC);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRN_N.TI_SPEC);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRN_N.TTI_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRN_N.MA_SPEC);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRN_N.WT_SPEC);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRN_N.BD_SPEC);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRN_N.TD_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRN_N.PCS_SPEC);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRN_N.PSD_TS_SPEC);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRN_N.PSD_US_SPEC);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRN_N.PSD_SS_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRN_N.PSD_OS_SPEC);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRN_N.PSD_LS_SPEC);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRN_N.PSD_FS_SPEC);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRN_N.HLT_TI_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRN_N.TI_VAL);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRN_N.TTI_VAL);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRN_N.MA_VAL);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRN_N.WT_VAL);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRN_N.BD_VAL);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRN_N.TD_VAL);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRN_N.PCS_VAL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRN_N.PSD_TS_VAL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRN_N.PSD_US_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRN_N.PSD_SS_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRN_N.PSD_OS_VAL);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRN_N.PSD_LS_VAL);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRN_N.PSD_FS_VAL);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRN_N.HLT_TI_VAL);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE01);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE02);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE03);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE04);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE05);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE06);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE07);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE08);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE09);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE10);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRN_N.REMARKS);
            sqlstm.sqhstl[46] = (unsigned int  )101;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRN_N.USE_YN);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRN_N.CREATE_USER_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRN_N.CREATE_TIME);
            sqlstm.sqhstl[49] = (unsigned int  )15;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRN_N.UPDATE_USER_ID);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRN_N.UPDATE_TIME);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRN_N.BD_TI_SPEC);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRN_N.BD_TTI_SPEC);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRN_N.BD_TTI_VAL);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRN_N.BD_TI_VAL);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRN_N.SURFACE_B_VAL);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRN_N.HEADER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRN_N.LINE_NUMBER);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM2);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM3);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRN_N.CM_L_VAL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRN_N.CM_A_VAL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRN_N.CM_B_VAL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_1);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_2);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_3);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_4);
            sqlstm.sqhstl[68] = (unsigned int  )51;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_5);
            sqlstm.sqhstl[69] = (unsigned int  )51;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_6);
            sqlstm.sqhstl[70] = (unsigned int  )51;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_7);
            sqlstm.sqhstl[71] = (unsigned int  )51;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_8);
            sqlstm.sqhstl[72] = (unsigned int  )51;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_9);
            sqlstm.sqhstl[73] = (unsigned int  )51;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_10);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_11);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_12);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_13);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_14);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_15);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[80] = (unsigned int  )21;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    }

    DB_stop_query_timer("DBU_select_cqcmrptgrn_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmrptgrn_scalar(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTGRN
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRN_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTGRN where\
 (REPORT_NO=:b1 and LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )695;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
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

		case 2:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMRPTGRN
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMRPTGRN where\
 REPORT_NO=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )722;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
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

    DB_stop_query_timer("DBU_select_cqcmrptgrn_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmrptgrn(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMRPTGRN
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRN_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTGRN  where (REPORT_NO=:b0 an\
d LOT_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )745;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
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
            /* EXEC SQL DELETE FROM CQCMRPTGRN
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMRPTGRN  where REPORT_NO=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )768;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[0] = (unsigned int  )21;
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

    DB_stop_query_timer("DBU_delete_cqcmrptgrn", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmrptgrn(struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMRPTGRN( 
	                FACTORY,
                    REPORT_NO, 
                    LOT_ID, 
                    GRADE, 
                    SIZES, 
                    ORDER_NO, 
                    CUST_NO, 
                    GRADE_SPEC, 
                    SIZES_SPEC, 
                    TI_SPEC, 
                    TTI_SPEC, 
                    MA_SPEC, 
                    WT_SPEC, 
                    BD_SPEC, 
                    TD_SPEC, 
                    PCS_SPEC, 
                    PSD_TS_SPEC, 
                    PSD_US_SPEC, 
                    PSD_SS_SPEC, 
                    PSD_OS_SPEC, 
                    PSD_LS_SPEC, 
                    PSD_FS_SPEC, 
                    HLT_TI_SPEC, 
                    TI_VAL, 
                    TTI_VAL, 
                    MA_VAL, 
                    WT_VAL, 
                    BD_VAL, 
                    TD_VAL, 
                    PCS_VAL, 
                    PSD_TS_VAL, 
                    PSD_US_VAL, 
                    PSD_SS_VAL, 
                    PSD_OS_VAL, 
                    PSD_LS_VAL, 
                    PSD_FS_VAL, 
                    HLT_TI_VAL, 
                    ATTRIBUTE01, 
                    ATTRIBUTE02, 
                    ATTRIBUTE03, 
                    ATTRIBUTE04, 
                    ATTRIBUTE05, 
                    ATTRIBUTE06, 
                    ATTRIBUTE07, 
                    ATTRIBUTE08, 
                    ATTRIBUTE09, 
                    ATTRIBUTE10, 
                    REMARKS, 
                    USE_YN, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    IMAGE_NUM, 
                    BD_TI_SPEC, 
                    BD_TTI_SPEC, 
                    BD_TTI_VAL, 
                    BD_TI_VAL, 
                    SURFACE_B_VAL, 
                    HEADER_ID, 
                    LINE_NUMBER, 
                    IMAGE_NUM2, 
                    IMAGE_NUM3, 
                    CM_L_VAL, 
                    CM_A_VAL, 
                    CM_B_VAL, 
                    RPT_CMF_1, 
                    RPT_CMF_2, 
                    RPT_CMF_3, 
                    RPT_CMF_4, 
                    RPT_CMF_5, 
                    RPT_CMF_6, 
                    RPT_CMF_7, 
                    RPT_CMF_8, 
                    RPT_CMF_9, 
                    RPT_CMF_10, 
                    RPT_CMF_11, 
                    RPT_CMF_12, 
                    RPT_CMF_13, 
                    RPT_CMF_14, 
                    RPT_CMF_15
         ) 
        VALUES (
		            :CQCMRPTGRN_N.FACTORY,
                    :CQCMRPTGRN_N.REPORT_NO,
                    :CQCMRPTGRN_N.LOT_ID,
                    :CQCMRPTGRN_N.GRADE,
                    :CQCMRPTGRN_N.SIZES,
                    :CQCMRPTGRN_N.ORDER_NO,
                    :CQCMRPTGRN_N.CUST_NO,
                    :CQCMRPTGRN_N.GRADE_SPEC,
                    :CQCMRPTGRN_N.SIZES_SPEC,
                    :CQCMRPTGRN_N.TI_SPEC,
                    :CQCMRPTGRN_N.TTI_SPEC,
                    :CQCMRPTGRN_N.MA_SPEC,
                    :CQCMRPTGRN_N.WT_SPEC,
                    :CQCMRPTGRN_N.BD_SPEC,
                    :CQCMRPTGRN_N.TD_SPEC,
                    :CQCMRPTGRN_N.PCS_SPEC,
                    :CQCMRPTGRN_N.PSD_TS_SPEC,
                    :CQCMRPTGRN_N.PSD_US_SPEC,
                    :CQCMRPTGRN_N.PSD_SS_SPEC,
                    :CQCMRPTGRN_N.PSD_OS_SPEC,
                    :CQCMRPTGRN_N.PSD_LS_SPEC,
                    :CQCMRPTGRN_N.PSD_FS_SPEC,
                    :CQCMRPTGRN_N.HLT_TI_SPEC,
                    :CQCMRPTGRN_N.TI_VAL,
                    :CQCMRPTGRN_N.TTI_VAL,
                    :CQCMRPTGRN_N.MA_VAL,
                    :CQCMRPTGRN_N.WT_VAL,
                    :CQCMRPTGRN_N.BD_VAL,
                    :CQCMRPTGRN_N.TD_VAL,
                    :CQCMRPTGRN_N.PCS_VAL,
                    :CQCMRPTGRN_N.PSD_TS_VAL,
                    :CQCMRPTGRN_N.PSD_US_VAL,
                    :CQCMRPTGRN_N.PSD_SS_VAL,
                    :CQCMRPTGRN_N.PSD_OS_VAL,
                    :CQCMRPTGRN_N.PSD_LS_VAL,
                    :CQCMRPTGRN_N.PSD_FS_VAL,
                    :CQCMRPTGRN_N.HLT_TI_VAL,
                    :CQCMRPTGRN_N.ATTRIBUTE01,
                    :CQCMRPTGRN_N.ATTRIBUTE02,
                    :CQCMRPTGRN_N.ATTRIBUTE03,
                    :CQCMRPTGRN_N.ATTRIBUTE04,
                    :CQCMRPTGRN_N.ATTRIBUTE05,
                    :CQCMRPTGRN_N.ATTRIBUTE06,
                    :CQCMRPTGRN_N.ATTRIBUTE07,
                    :CQCMRPTGRN_N.ATTRIBUTE08,
                    :CQCMRPTGRN_N.ATTRIBUTE09,
                    :CQCMRPTGRN_N.ATTRIBUTE10,
                    :CQCMRPTGRN_N.REMARKS,
                    :CQCMRPTGRN_N.USE_YN,
                    :CQCMRPTGRN_N.CREATE_USER_ID,
                    :CQCMRPTGRN_N.CREATE_TIME,
                    :CQCMRPTGRN_N.UPDATE_USER_ID,
                    :CQCMRPTGRN_N.UPDATE_TIME,
                    :CQCMRPTGRN_N.IMAGE_NUM,
                    :CQCMRPTGRN_N.BD_TI_SPEC,
                    :CQCMRPTGRN_N.BD_TTI_SPEC,
                    :CQCMRPTGRN_N.BD_TTI_VAL,
                    :CQCMRPTGRN_N.BD_TI_VAL,
                    :CQCMRPTGRN_N.SURFACE_B_VAL,
                    :CQCMRPTGRN_N.HEADER_ID,
                    :CQCMRPTGRN_N.LINE_NUMBER,
                    :CQCMRPTGRN_N.IMAGE_NUM2,
                    :CQCMRPTGRN_N.IMAGE_NUM3,
                    :CQCMRPTGRN_N.CM_L_VAL,
                    :CQCMRPTGRN_N.CM_A_VAL,
                    :CQCMRPTGRN_N.CM_B_VAL,
                    :CQCMRPTGRN_N.RPT_CMF_1,
                    :CQCMRPTGRN_N.RPT_CMF_2,
                    :CQCMRPTGRN_N.RPT_CMF_3,
                    :CQCMRPTGRN_N.RPT_CMF_4,
                    :CQCMRPTGRN_N.RPT_CMF_5,
                    :CQCMRPTGRN_N.RPT_CMF_6,
                    :CQCMRPTGRN_N.RPT_CMF_7,
                    :CQCMRPTGRN_N.RPT_CMF_8,
                    :CQCMRPTGRN_N.RPT_CMF_9,
                    :CQCMRPTGRN_N.RPT_CMF_10,
                    :CQCMRPTGRN_N.RPT_CMF_11,
                    :CQCMRPTGRN_N.RPT_CMF_12,
                    :CQCMRPTGRN_N.RPT_CMF_13,
                    :CQCMRPTGRN_N.RPT_CMF_14,
                    :CQCMRPTGRN_N.RPT_CMF_15
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 83;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into CQCMRPTGRN (FACTORY,REPORT_NO,LOT_ID,GRADE,SIZES,ORDER_NO\
,CUST_NO,GRADE_SPEC,SIZES_SPEC,TI_SPEC,TTI_SPEC,MA_SPEC,WT_SPEC,BD_SPEC,TD_S\
PEC,PCS_SPEC,PSD_TS_SPEC,PSD_US_SPEC,PSD_SS_SPEC,PSD_OS_SPEC,PSD_LS_SPEC,PSD\
_FS_SPEC,HLT_TI_SPEC,TI_VAL,TTI_VAL,MA_VAL,WT_VAL,BD_VAL,TD_VAL,PCS_VAL,PSD_\
TS_VAL,PSD_US_VAL,PSD_SS_VAL,PSD_OS_VAL,PSD_LS_VAL,PSD_FS_VAL,HLT_TI_VAL,ATT\
RIBUTE01,ATTRIBUTE02,ATTRIBUTE03,ATTRIBUTE04,ATTRIBUTE05,ATTRIBUTE06,ATTRIBU\
TE07,ATTRIBUTE08,ATTRIBUTE09,ATTRIBUTE10,REMARKS,USE_YN,CREATE_USER_ID,CREAT\
E_TIME,UPDATE_USER_ID,UPDATE_TIME,IMAGE_NUM,BD_TI_SPEC,BD_TTI_SPEC,BD_TTI_VA\
L,BD_TI_VAL,SURFACE_B_VAL,HEADER_ID,LINE_NUMBER,IMAGE_NUM2,IMAGE_NUM3,CM_L_V\
AL,CM_A_VAL,CM_B_VAL,RPT_CMF_1,RPT_CMF_2,RPT_CMF_3,RPT_CMF_4,RPT_CMF_5,RPT_C\
MF_6,RPT_CMF_7,RPT_CMF_8,RPT_CMF_9,RPT_CMF_10,RPT_CMF_11,RPT_CMF_12,RPT_CMF_\
13,RPT_CMF_14,RPT_CMF_15) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b\
10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b2\
5,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:");
    sqlstm.stmt = "b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b\
45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60\
,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:\
b76,:b77,:b78,:b79,:b80)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )787;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
    sqlstm.sqhstl[2] = (unsigned int  )21;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRN_N.GRADE);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRN_N.SIZES);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRN_N.ORDER_NO);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRN_N.CUST_NO);
    sqlstm.sqhstl[6] = (unsigned int  )101;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGRN_N.GRADE_SPEC);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRN_N.SIZES_SPEC);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRN_N.TI_SPEC);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRN_N.TTI_SPEC);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRN_N.MA_SPEC);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRN_N.WT_SPEC);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRN_N.BD_SPEC);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRN_N.TD_SPEC);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRN_N.PCS_SPEC);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRN_N.PSD_TS_SPEC);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRN_N.PSD_US_SPEC);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRN_N.PSD_SS_SPEC);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRN_N.PSD_OS_SPEC);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRN_N.PSD_LS_SPEC);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRN_N.PSD_FS_SPEC);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRN_N.HLT_TI_SPEC);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRN_N.TI_VAL);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRN_N.TTI_VAL);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRN_N.MA_VAL);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRN_N.WT_VAL);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRN_N.BD_VAL);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRN_N.TD_VAL);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRN_N.PCS_VAL);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRN_N.PSD_TS_VAL);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRN_N.PSD_US_VAL);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRN_N.PSD_SS_VAL);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRN_N.PSD_OS_VAL);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRN_N.PSD_LS_VAL);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRN_N.PSD_FS_VAL);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRN_N.HLT_TI_VAL);
    sqlstm.sqhstl[36] = (unsigned int  )31;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE01);
    sqlstm.sqhstl[37] = (unsigned int  )51;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE02);
    sqlstm.sqhstl[38] = (unsigned int  )51;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE03);
    sqlstm.sqhstl[39] = (unsigned int  )51;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE04);
    sqlstm.sqhstl[40] = (unsigned int  )51;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE05);
    sqlstm.sqhstl[41] = (unsigned int  )51;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE06);
    sqlstm.sqhstl[42] = (unsigned int  )51;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE07);
    sqlstm.sqhstl[43] = (unsigned int  )51;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE08);
    sqlstm.sqhstl[44] = (unsigned int  )51;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE09);
    sqlstm.sqhstl[45] = (unsigned int  )51;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE10);
    sqlstm.sqhstl[46] = (unsigned int  )51;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRN_N.REMARKS);
    sqlstm.sqhstl[47] = (unsigned int  )101;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRN_N.USE_YN);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRN_N.CREATE_USER_ID);
    sqlstm.sqhstl[49] = (unsigned int  )21;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRN_N.CREATE_TIME);
    sqlstm.sqhstl[50] = (unsigned int  )15;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRN_N.UPDATE_USER_ID);
    sqlstm.sqhstl[51] = (unsigned int  )21;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRN_N.UPDATE_TIME);
    sqlstm.sqhstl[52] = (unsigned int  )15;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM);
    sqlstm.sqhstl[53] = (unsigned int  )21;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRN_N.BD_TI_SPEC);
    sqlstm.sqhstl[54] = (unsigned int  )31;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRN_N.BD_TTI_SPEC);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRN_N.BD_TTI_VAL);
    sqlstm.sqhstl[56] = (unsigned int  )31;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRN_N.BD_TI_VAL);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRN_N.SURFACE_B_VAL);
    sqlstm.sqhstl[58] = (unsigned int  )31;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRN_N.HEADER_ID);
    sqlstm.sqhstl[59] = (unsigned int  )21;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRN_N.LINE_NUMBER);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM2);
    sqlstm.sqhstl[61] = (unsigned int  )21;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM3);
    sqlstm.sqhstl[62] = (unsigned int  )21;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRN_N.CM_L_VAL);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRN_N.CM_A_VAL);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRN_N.CM_B_VAL);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_1);
    sqlstm.sqhstl[66] = (unsigned int  )51;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_2);
    sqlstm.sqhstl[67] = (unsigned int  )51;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_3);
    sqlstm.sqhstl[68] = (unsigned int  )51;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_4);
    sqlstm.sqhstl[69] = (unsigned int  )51;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_5);
    sqlstm.sqhstl[70] = (unsigned int  )51;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_6);
    sqlstm.sqhstl[71] = (unsigned int  )51;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_7);
    sqlstm.sqhstl[72] = (unsigned int  )51;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_8);
    sqlstm.sqhstl[73] = (unsigned int  )51;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_9);
    sqlstm.sqhstl[74] = (unsigned int  )51;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_10);
    sqlstm.sqhstl[75] = (unsigned int  )51;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_11);
    sqlstm.sqhstl[76] = (unsigned int  )51;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_12);
    sqlstm.sqhstl[77] = (unsigned int  )51;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_13);
    sqlstm.sqhstl[78] = (unsigned int  )51;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_14);
    sqlstm.sqhstl[79] = (unsigned int  )51;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_15);
    sqlstm.sqhstl[80] = (unsigned int  )51;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cqcmrptgrn", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmrptgrn(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMRPTGRN SET
                    GRADE = :CQCMRPTGRN_N.GRADE,
                    SIZES = :CQCMRPTGRN_N.SIZES,
                    ORDER_NO = :CQCMRPTGRN_N.ORDER_NO,
                    CUST_NO = :CQCMRPTGRN_N.CUST_NO,
                    GRADE_SPEC = :CQCMRPTGRN_N.GRADE_SPEC,
                    SIZES_SPEC = :CQCMRPTGRN_N.SIZES_SPEC,
                    TI_SPEC = :CQCMRPTGRN_N.TI_SPEC,
                    TTI_SPEC = :CQCMRPTGRN_N.TTI_SPEC,
                    MA_SPEC = :CQCMRPTGRN_N.MA_SPEC,
                    WT_SPEC = :CQCMRPTGRN_N.WT_SPEC,
                    BD_SPEC = :CQCMRPTGRN_N.BD_SPEC,
                    TD_SPEC = :CQCMRPTGRN_N.TD_SPEC,
                    PCS_SPEC = :CQCMRPTGRN_N.PCS_SPEC,
                    PSD_TS_SPEC = :CQCMRPTGRN_N.PSD_TS_SPEC,
                    PSD_US_SPEC = :CQCMRPTGRN_N.PSD_US_SPEC,
                    PSD_SS_SPEC = :CQCMRPTGRN_N.PSD_SS_SPEC,
                    PSD_OS_SPEC = :CQCMRPTGRN_N.PSD_OS_SPEC,
                    PSD_LS_SPEC = :CQCMRPTGRN_N.PSD_LS_SPEC,
                    PSD_FS_SPEC = :CQCMRPTGRN_N.PSD_FS_SPEC,
                    HLT_TI_SPEC = :CQCMRPTGRN_N.HLT_TI_SPEC,
                    TI_VAL = :CQCMRPTGRN_N.TI_VAL,
                    TTI_VAL = :CQCMRPTGRN_N.TTI_VAL,
                    MA_VAL = :CQCMRPTGRN_N.MA_VAL,
                    WT_VAL = :CQCMRPTGRN_N.WT_VAL,
                    BD_VAL = :CQCMRPTGRN_N.BD_VAL,
                    TD_VAL = :CQCMRPTGRN_N.TD_VAL,
                    PCS_VAL = :CQCMRPTGRN_N.PCS_VAL,
                    PSD_TS_VAL = :CQCMRPTGRN_N.PSD_TS_VAL,
                    PSD_US_VAL = :CQCMRPTGRN_N.PSD_US_VAL,
                    PSD_SS_VAL = :CQCMRPTGRN_N.PSD_SS_VAL,
                    PSD_OS_VAL = :CQCMRPTGRN_N.PSD_OS_VAL,
                    PSD_LS_VAL = :CQCMRPTGRN_N.PSD_LS_VAL,
                    PSD_FS_VAL = :CQCMRPTGRN_N.PSD_FS_VAL,
                    HLT_TI_VAL = :CQCMRPTGRN_N.HLT_TI_VAL,
                    ATTRIBUTE01 = :CQCMRPTGRN_N.ATTRIBUTE01,
                    ATTRIBUTE02 = :CQCMRPTGRN_N.ATTRIBUTE02,
                    ATTRIBUTE03 = :CQCMRPTGRN_N.ATTRIBUTE03,
                    ATTRIBUTE04 = :CQCMRPTGRN_N.ATTRIBUTE04,
                    ATTRIBUTE05 = :CQCMRPTGRN_N.ATTRIBUTE05,
                    ATTRIBUTE06 = :CQCMRPTGRN_N.ATTRIBUTE06,
                    ATTRIBUTE07 = :CQCMRPTGRN_N.ATTRIBUTE07,
                    ATTRIBUTE08 = :CQCMRPTGRN_N.ATTRIBUTE08,
                    ATTRIBUTE09 = :CQCMRPTGRN_N.ATTRIBUTE09,
                    ATTRIBUTE10 = :CQCMRPTGRN_N.ATTRIBUTE10,
                    REMARKS = :CQCMRPTGRN_N.REMARKS,
                    USE_YN = :CQCMRPTGRN_N.USE_YN,
                    CREATE_USER_ID = :CQCMRPTGRN_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMRPTGRN_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMRPTGRN_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMRPTGRN_N.UPDATE_TIME,
                    IMAGE_NUM = :CQCMRPTGRN_N.IMAGE_NUM,
                    BD_TI_SPEC = :CQCMRPTGRN_N.BD_TI_SPEC,
                    BD_TTI_SPEC = :CQCMRPTGRN_N.BD_TTI_SPEC,
                    BD_TTI_VAL = :CQCMRPTGRN_N.BD_TTI_VAL,
                    BD_TI_VAL = :CQCMRPTGRN_N.BD_TI_VAL,
                    SURFACE_B_VAL = :CQCMRPTGRN_N.SURFACE_B_VAL,
                    HEADER_ID = :CQCMRPTGRN_N.HEADER_ID,
                    LINE_NUMBER = :CQCMRPTGRN_N.LINE_NUMBER,
                    IMAGE_NUM2 = :CQCMRPTGRN_N.IMAGE_NUM2,
                    IMAGE_NUM3 = :CQCMRPTGRN_N.IMAGE_NUM3,
                    CM_L_VAL = :CQCMRPTGRN_N.CM_L_VAL,
                    CM_A_VAL = :CQCMRPTGRN_N.CM_A_VAL,
                    CM_B_VAL = :CQCMRPTGRN_N.CM_B_VAL,
                    RPT_CMF_1 = :CQCMRPTGRN_N.RPT_CMF_1,
                    RPT_CMF_2 = :CQCMRPTGRN_N.RPT_CMF_2,
                    RPT_CMF_3 = :CQCMRPTGRN_N.RPT_CMF_3,
                    RPT_CMF_4 = :CQCMRPTGRN_N.RPT_CMF_4,
                    RPT_CMF_5 = :CQCMRPTGRN_N.RPT_CMF_5,
                    RPT_CMF_6 = :CQCMRPTGRN_N.RPT_CMF_6,
                    RPT_CMF_7 = :CQCMRPTGRN_N.RPT_CMF_7,
                    RPT_CMF_8 = :CQCMRPTGRN_N.RPT_CMF_8,
                    RPT_CMF_9 = :CQCMRPTGRN_N.RPT_CMF_9,
                    RPT_CMF_10 = :CQCMRPTGRN_N.RPT_CMF_10,
                    RPT_CMF_11 = :CQCMRPTGRN_N.RPT_CMF_11,
                    RPT_CMF_12 = :CQCMRPTGRN_N.RPT_CMF_12,
                    RPT_CMF_13 = :CQCMRPTGRN_N.RPT_CMF_13,
                    RPT_CMF_14 = :CQCMRPTGRN_N.RPT_CMF_14,
                    RPT_CMF_15 = :CQCMRPTGRN_N.RPT_CMF_15
                WHERE REPORT_NO = :CQCMRPTGRN_N.REPORT_NO
                    AND LOT_ID = :CQCMRPTGRN_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update CQCMRPTGRN  set GRADE=:b0,SIZES=:b1,ORDER_NO=:b2,CUST_\
NO=:b3,GRADE_SPEC=:b4,SIZES_SPEC=:b5,TI_SPEC=:b6,TTI_SPEC=:b7,MA_SPEC=:b8,WT\
_SPEC=:b9,BD_SPEC=:b10,TD_SPEC=:b11,PCS_SPEC=:b12,PSD_TS_SPEC=:b13,PSD_US_SP\
EC=:b14,PSD_SS_SPEC=:b15,PSD_OS_SPEC=:b16,PSD_LS_SPEC=:b17,PSD_FS_SPEC=:b18,\
HLT_TI_SPEC=:b19,TI_VAL=:b20,TTI_VAL=:b21,MA_VAL=:b22,WT_VAL=:b23,BD_VAL=:b2\
4,TD_VAL=:b25,PCS_VAL=:b26,PSD_TS_VAL=:b27,PSD_US_VAL=:b28,PSD_SS_VAL=:b29,P\
SD_OS_VAL=:b30,PSD_LS_VAL=:b31,PSD_FS_VAL=:b32,HLT_TI_VAL=:b33,ATTRIBUTE01=:\
b34,ATTRIBUTE02=:b35,ATTRIBUTE03=:b36,ATTRIBUTE04=:b37,ATTRIBUTE05=:b38,ATTR\
IBUTE06=:b39,ATTRIBUTE07=:b40,ATTRIBUTE08=:b41,ATTRIBUTE09=:b42,ATTRIBUTE10=\
:b43,REMARKS=:b44,USE_YN=:b45,CREATE_USER_ID=:b46,CREATE_TIME=:b47,UPDATE_US\
ER_ID=:b48,UPDATE_TIME=:b49,IMAGE_NUM=:b50,BD_TI_SPEC=:b51,BD_TTI_SPEC=:b52,\
BD_TTI_VAL=:b53,BD_TI_VAL=:b54,SURFACE_B_VAL=:b55,HEADER_ID=:b56,LINE_NUMBER\
=:b57,IMAGE_NUM2=:b58,IMAGE_NUM3=:b59,CM_L_VAL=:b60,CM_A_VAL=:b61,CM_B_VAL=:\
b62,RPT_CMF_1=:b63,RPT_CMF_2=:b64,RPT_CMF_3=:b65,RP");
            sqlstm.stmt = "T_CMF_4=:b66,RPT_CMF_5=:b67,RPT_CMF_6=:b68,RPT_C\
MF_7=:b69,RPT_CMF_8=:b70,RPT_CMF_9=:b71,RPT_CMF_10=:b72,RPT_CMF_11=:b73,RPT_C\
MF_12=:b74,RPT_CMF_13=:b75,RPT_CMF_14=:b76,RPT_CMF_15=:b77 where (REPORT_NO=:\
b78 and LOT_ID=:b79)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1126;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.GRADE);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.SIZES);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRN_N.ORDER_NO);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRN_N.CUST_NO);
            sqlstm.sqhstl[3] = (unsigned int  )101;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRN_N.GRADE_SPEC);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRN_N.SIZES_SPEC);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRN_N.TI_SPEC);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGRN_N.TTI_SPEC);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRN_N.MA_SPEC);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRN_N.WT_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRN_N.BD_SPEC);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRN_N.TD_SPEC);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRN_N.PCS_SPEC);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRN_N.PSD_TS_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRN_N.PSD_US_SPEC);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRN_N.PSD_SS_SPEC);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRN_N.PSD_OS_SPEC);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRN_N.PSD_LS_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRN_N.PSD_FS_SPEC);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRN_N.HLT_TI_SPEC);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRN_N.TI_VAL);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRN_N.TTI_VAL);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRN_N.MA_VAL);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRN_N.WT_VAL);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRN_N.BD_VAL);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRN_N.TD_VAL);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRN_N.PCS_VAL);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRN_N.PSD_TS_VAL);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRN_N.PSD_US_VAL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRN_N.PSD_SS_VAL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRN_N.PSD_OS_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRN_N.PSD_LS_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRN_N.PSD_FS_VAL);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRN_N.HLT_TI_VAL);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE01);
            sqlstm.sqhstl[34] = (unsigned int  )51;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE02);
            sqlstm.sqhstl[35] = (unsigned int  )51;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE03);
            sqlstm.sqhstl[36] = (unsigned int  )51;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE04);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE05);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE06);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE07);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE08);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE09);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE10);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRN_N.REMARKS);
            sqlstm.sqhstl[44] = (unsigned int  )101;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRN_N.USE_YN);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRN_N.CREATE_USER_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRN_N.CREATE_TIME);
            sqlstm.sqhstl[47] = (unsigned int  )15;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRN_N.UPDATE_USER_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRN_N.UPDATE_TIME);
            sqlstm.sqhstl[49] = (unsigned int  )15;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRN_N.BD_TI_SPEC);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRN_N.BD_TTI_SPEC);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRN_N.BD_TTI_VAL);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRN_N.BD_TI_VAL);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRN_N.SURFACE_B_VAL);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRN_N.HEADER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRN_N.LINE_NUMBER);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM2);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM3);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRN_N.CM_L_VAL);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRN_N.CM_A_VAL);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRN_N.CM_B_VAL);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_1);
            sqlstm.sqhstl[63] = (unsigned int  )51;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_2);
            sqlstm.sqhstl[64] = (unsigned int  )51;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_3);
            sqlstm.sqhstl[65] = (unsigned int  )51;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_4);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_5);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_6);
            sqlstm.sqhstl[68] = (unsigned int  )51;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_7);
            sqlstm.sqhstl[69] = (unsigned int  )51;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_8);
            sqlstm.sqhstl[70] = (unsigned int  )51;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_9);
            sqlstm.sqhstl[71] = (unsigned int  )51;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_10);
            sqlstm.sqhstl[72] = (unsigned int  )51;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_11);
            sqlstm.sqhstl[73] = (unsigned int  )51;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_12);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_13);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_14);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_15);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_cqcmrptgrn", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmrptgrn(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMRPTGRN_CUR_1 CURSOR FOR
                SELECT
				    FACTORY, 
                    REPORT_NO,
                    LOT_ID,
                    GRADE,
                    SIZES,
                    ORDER_NO,
                    CUST_NO,
                    GRADE_SPEC,
                    SIZES_SPEC,
                    TI_SPEC,
                    TTI_SPEC,
                    MA_SPEC,
                    WT_SPEC,
                    BD_SPEC,
                    TD_SPEC,
                    PCS_SPEC,
                    PSD_TS_SPEC,
                    PSD_US_SPEC,
                    PSD_SS_SPEC,
                    PSD_OS_SPEC,
                    PSD_LS_SPEC,
                    PSD_FS_SPEC,
                    HLT_TI_SPEC,
                    TI_VAL,
                    TTI_VAL,
                    MA_VAL,
                    WT_VAL,
                    BD_VAL,
                    TD_VAL,
                    PCS_VAL,
                    PSD_TS_VAL,
                    PSD_US_VAL,
                    PSD_SS_VAL,
                    PSD_OS_VAL,
                    PSD_LS_VAL,
                    PSD_FS_VAL,
                    HLT_TI_VAL,
                    ATTRIBUTE01,
                    ATTRIBUTE02,
                    ATTRIBUTE03,
                    ATTRIBUTE04,
                    ATTRIBUTE05,
                    ATTRIBUTE06,
                    ATTRIBUTE07,
                    ATTRIBUTE08,
                    ATTRIBUTE09,
                    ATTRIBUTE10,
                    REMARKS,
                    USE_YN,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    IMAGE_NUM,
                    BD_TI_SPEC,
                    BD_TTI_SPEC,
                    BD_TTI_VAL,
                    BD_TI_VAL,
                    SURFACE_B_VAL,
                    HEADER_ID,
                    LINE_NUMBER,
                    IMAGE_NUM2,
                    IMAGE_NUM3,
                    CM_L_VAL,
                    CM_A_VAL,
                    CM_B_VAL,
                    RPT_CMF_1,
                    RPT_CMF_2,
                    RPT_CMF_3,
                    RPT_CMF_4,
                    RPT_CMF_5,
                    RPT_CMF_6,
                    RPT_CMF_7,
                    RPT_CMF_8,
                    RPT_CMF_9,
                    RPT_CMF_10,
                    RPT_CMF_11,
                    RPT_CMF_12,
                    RPT_CMF_13,
                    RPT_CMF_14,
                    RPT_CMF_15
                FROM CQCMRPTGRN
                ORDER BY REPORT_NO ASC,
                    LOT_ID ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMRPTGRN_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1461;
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

    DB_stop_query_timer("DBU_open_cqcmrptgrn", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmrptgrn(int sel_type, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMRPTGRN_N_TAG CQCMRPTGRN_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMRPTGRN_CUR_1 INTO
			    :CQCMRPTGRN_N.FACTORY,
                :CQCMRPTGRN_N.REPORT_NO,
                :CQCMRPTGRN_N.LOT_ID,
                :CQCMRPTGRN_N.GRADE,
                :CQCMRPTGRN_N.SIZES,
                :CQCMRPTGRN_N.ORDER_NO,
                :CQCMRPTGRN_N.CUST_NO,
                :CQCMRPTGRN_N.GRADE_SPEC,
                :CQCMRPTGRN_N.SIZES_SPEC,
                :CQCMRPTGRN_N.TI_SPEC,
                :CQCMRPTGRN_N.TTI_SPEC,
                :CQCMRPTGRN_N.MA_SPEC,
                :CQCMRPTGRN_N.WT_SPEC,
                :CQCMRPTGRN_N.BD_SPEC,
                :CQCMRPTGRN_N.TD_SPEC,
                :CQCMRPTGRN_N.PCS_SPEC,
                :CQCMRPTGRN_N.PSD_TS_SPEC,
                :CQCMRPTGRN_N.PSD_US_SPEC,
                :CQCMRPTGRN_N.PSD_SS_SPEC,
                :CQCMRPTGRN_N.PSD_OS_SPEC,
                :CQCMRPTGRN_N.PSD_LS_SPEC,
                :CQCMRPTGRN_N.PSD_FS_SPEC,
                :CQCMRPTGRN_N.HLT_TI_SPEC,
                :CQCMRPTGRN_N.TI_VAL,
                :CQCMRPTGRN_N.TTI_VAL,
                :CQCMRPTGRN_N.MA_VAL,
                :CQCMRPTGRN_N.WT_VAL,
                :CQCMRPTGRN_N.BD_VAL,
                :CQCMRPTGRN_N.TD_VAL,
                :CQCMRPTGRN_N.PCS_VAL,
                :CQCMRPTGRN_N.PSD_TS_VAL,
                :CQCMRPTGRN_N.PSD_US_VAL,
                :CQCMRPTGRN_N.PSD_SS_VAL,
                :CQCMRPTGRN_N.PSD_OS_VAL,
                :CQCMRPTGRN_N.PSD_LS_VAL,
                :CQCMRPTGRN_N.PSD_FS_VAL,
                :CQCMRPTGRN_N.HLT_TI_VAL,
                :CQCMRPTGRN_N.ATTRIBUTE01,
                :CQCMRPTGRN_N.ATTRIBUTE02,
                :CQCMRPTGRN_N.ATTRIBUTE03,
                :CQCMRPTGRN_N.ATTRIBUTE04,
                :CQCMRPTGRN_N.ATTRIBUTE05,
                :CQCMRPTGRN_N.ATTRIBUTE06,
                :CQCMRPTGRN_N.ATTRIBUTE07,
                :CQCMRPTGRN_N.ATTRIBUTE08,
                :CQCMRPTGRN_N.ATTRIBUTE09,
                :CQCMRPTGRN_N.ATTRIBUTE10,
                :CQCMRPTGRN_N.REMARKS,
                :CQCMRPTGRN_N.USE_YN,
                :CQCMRPTGRN_N.CREATE_USER_ID,
                :CQCMRPTGRN_N.CREATE_TIME,
                :CQCMRPTGRN_N.UPDATE_USER_ID,
                :CQCMRPTGRN_N.UPDATE_TIME,
                :CQCMRPTGRN_N.IMAGE_NUM,
                :CQCMRPTGRN_N.BD_TI_SPEC,
                :CQCMRPTGRN_N.BD_TTI_SPEC,
                :CQCMRPTGRN_N.BD_TTI_VAL,
                :CQCMRPTGRN_N.BD_TI_VAL,
                :CQCMRPTGRN_N.SURFACE_B_VAL,
                :CQCMRPTGRN_N.HEADER_ID,
                :CQCMRPTGRN_N.LINE_NUMBER,
                :CQCMRPTGRN_N.IMAGE_NUM2,
                :CQCMRPTGRN_N.IMAGE_NUM3,
                :CQCMRPTGRN_N.CM_L_VAL,
                :CQCMRPTGRN_N.CM_A_VAL,
                :CQCMRPTGRN_N.CM_B_VAL,
                :CQCMRPTGRN_N.RPT_CMF_1,
                :CQCMRPTGRN_N.RPT_CMF_2,
                :CQCMRPTGRN_N.RPT_CMF_3,
                :CQCMRPTGRN_N.RPT_CMF_4,
                :CQCMRPTGRN_N.RPT_CMF_5,
                :CQCMRPTGRN_N.RPT_CMF_6,
                :CQCMRPTGRN_N.RPT_CMF_7,
                :CQCMRPTGRN_N.RPT_CMF_8,
                :CQCMRPTGRN_N.RPT_CMF_9,
                :CQCMRPTGRN_N.RPT_CMF_10,
                :CQCMRPTGRN_N.RPT_CMF_11,
                :CQCMRPTGRN_N.RPT_CMF_12,
                :CQCMRPTGRN_N.RPT_CMF_13,
                :CQCMRPTGRN_N.RPT_CMF_14,
                :CQCMRPTGRN_N.RPT_CMF_15; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1476;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMRPTGRN_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMRPTGRN_N.REPORT_NO);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMRPTGRN_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMRPTGRN_N.GRADE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMRPTGRN_N.SIZES);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMRPTGRN_N.ORDER_NO);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMRPTGRN_N.CUST_NO);
            sqlstm.sqhstl[6] = (unsigned int  )101;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMRPTGRN_N.GRADE_SPEC);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMRPTGRN_N.SIZES_SPEC);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMRPTGRN_N.TI_SPEC);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMRPTGRN_N.TTI_SPEC);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMRPTGRN_N.MA_SPEC);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMRPTGRN_N.WT_SPEC);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMRPTGRN_N.BD_SPEC);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMRPTGRN_N.TD_SPEC);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMRPTGRN_N.PCS_SPEC);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMRPTGRN_N.PSD_TS_SPEC);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMRPTGRN_N.PSD_US_SPEC);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMRPTGRN_N.PSD_SS_SPEC);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMRPTGRN_N.PSD_OS_SPEC);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMRPTGRN_N.PSD_LS_SPEC);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMRPTGRN_N.PSD_FS_SPEC);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMRPTGRN_N.HLT_TI_SPEC);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMRPTGRN_N.TI_VAL);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMRPTGRN_N.TTI_VAL);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMRPTGRN_N.MA_VAL);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMRPTGRN_N.WT_VAL);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMRPTGRN_N.BD_VAL);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMRPTGRN_N.TD_VAL);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMRPTGRN_N.PCS_VAL);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMRPTGRN_N.PSD_TS_VAL);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMRPTGRN_N.PSD_US_VAL);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMRPTGRN_N.PSD_SS_VAL);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMRPTGRN_N.PSD_OS_VAL);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMRPTGRN_N.PSD_LS_VAL);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMRPTGRN_N.PSD_FS_VAL);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMRPTGRN_N.HLT_TI_VAL);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE01);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE02);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE03);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE04);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE05);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE06);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE07);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE08);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE09);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMRPTGRN_N.ATTRIBUTE10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMRPTGRN_N.REMARKS);
            sqlstm.sqhstl[47] = (unsigned int  )101;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMRPTGRN_N.USE_YN);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMRPTGRN_N.CREATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMRPTGRN_N.CREATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMRPTGRN_N.UPDATE_USER_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMRPTGRN_N.UPDATE_TIME);
            sqlstm.sqhstl[52] = (unsigned int  )15;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMRPTGRN_N.BD_TI_SPEC);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMRPTGRN_N.BD_TTI_SPEC);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMRPTGRN_N.BD_TTI_VAL);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMRPTGRN_N.BD_TI_VAL);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMRPTGRN_N.SURFACE_B_VAL);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMRPTGRN_N.HEADER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMRPTGRN_N.LINE_NUMBER);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM2);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(CQCMRPTGRN_N.IMAGE_NUM3);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(CQCMRPTGRN_N.CM_L_VAL);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(CQCMRPTGRN_N.CM_A_VAL);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(CQCMRPTGRN_N.CM_B_VAL);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_1);
            sqlstm.sqhstl[66] = (unsigned int  )51;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_2);
            sqlstm.sqhstl[67] = (unsigned int  )51;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_3);
            sqlstm.sqhstl[68] = (unsigned int  )51;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_4);
            sqlstm.sqhstl[69] = (unsigned int  )51;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_5);
            sqlstm.sqhstl[70] = (unsigned int  )51;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_6);
            sqlstm.sqhstl[71] = (unsigned int  )51;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_7);
            sqlstm.sqhstl[72] = (unsigned int  )51;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_8);
            sqlstm.sqhstl[73] = (unsigned int  )51;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_9);
            sqlstm.sqhstl[74] = (unsigned int  )51;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_10);
            sqlstm.sqhstl[75] = (unsigned int  )51;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_11);
            sqlstm.sqhstl[76] = (unsigned int  )51;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_12);
            sqlstm.sqhstl[77] = (unsigned int  )51;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_13);
            sqlstm.sqhstl[78] = (unsigned int  )51;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_14);
            sqlstm.sqhstl[79] = (unsigned int  )51;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(CQCMRPTGRN_N.RPT_CMF_15);
            sqlstm.sqhstl[80] = (unsigned int  )51;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
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
        DBU_del_null_cqcmrptgrn(&CQCMRPTGRN_N, CQCMRPTGRN);
    }

    DB_stop_query_timer("DBU_fetch_cqcmrptgrn", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmrptgrn(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMRPTGRN_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 83;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1815;
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

    DB_stop_query_timer("DBU_close_cqcmrptgrn", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmrptgrn(struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* memset by Space */
    memset(CQCMRPTGRN, ' ', sizeof(struct CQCMRPTGRN_TAG));
    
}


/* Add Null Function */
void DBU_add_null_cqcmrptgrn(struct CQCMRPTGRN_N_TAG *CQCMRPTGRN_N, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    /* memset by NULL */
    memset(CQCMRPTGRN_N, '\0', sizeof(struct CQCMRPTGRN_N_TAG));
    
	 MEMCPY_AN(CQCMRPTGRN_N->FACTORY, CQCMRPTGRN->FACTORY, sizeof(CQCMRPTGRN->FACTORY));
    MEMCPY_AN(CQCMRPTGRN_N->REPORT_NO, CQCMRPTGRN->REPORT_NO, sizeof(CQCMRPTGRN->REPORT_NO));
    MEMCPY_AN(CQCMRPTGRN_N->LOT_ID, CQCMRPTGRN->LOT_ID, sizeof(CQCMRPTGRN->LOT_ID));
    MEMCPY_AN(CQCMRPTGRN_N->GRADE, CQCMRPTGRN->GRADE, sizeof(CQCMRPTGRN->GRADE));
    MEMCPY_AN(CQCMRPTGRN_N->SIZES, CQCMRPTGRN->SIZES, sizeof(CQCMRPTGRN->SIZES));
    MEMCPY_AN(CQCMRPTGRN_N->ORDER_NO, CQCMRPTGRN->ORDER_NO, sizeof(CQCMRPTGRN->ORDER_NO));
    MEMCPY_AN(CQCMRPTGRN_N->CUST_NO, CQCMRPTGRN->CUST_NO, sizeof(CQCMRPTGRN->CUST_NO));
    MEMCPY_AN(CQCMRPTGRN_N->GRADE_SPEC, CQCMRPTGRN->GRADE_SPEC, sizeof(CQCMRPTGRN->GRADE_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->SIZES_SPEC, CQCMRPTGRN->SIZES_SPEC, sizeof(CQCMRPTGRN->SIZES_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->TI_SPEC, CQCMRPTGRN->TI_SPEC, sizeof(CQCMRPTGRN->TI_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->TTI_SPEC, CQCMRPTGRN->TTI_SPEC, sizeof(CQCMRPTGRN->TTI_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->MA_SPEC, CQCMRPTGRN->MA_SPEC, sizeof(CQCMRPTGRN->MA_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->WT_SPEC, CQCMRPTGRN->WT_SPEC, sizeof(CQCMRPTGRN->WT_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->BD_SPEC, CQCMRPTGRN->BD_SPEC, sizeof(CQCMRPTGRN->BD_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->TD_SPEC, CQCMRPTGRN->TD_SPEC, sizeof(CQCMRPTGRN->TD_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PCS_SPEC, CQCMRPTGRN->PCS_SPEC, sizeof(CQCMRPTGRN->PCS_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_TS_SPEC, CQCMRPTGRN->PSD_TS_SPEC, sizeof(CQCMRPTGRN->PSD_TS_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_US_SPEC, CQCMRPTGRN->PSD_US_SPEC, sizeof(CQCMRPTGRN->PSD_US_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_SS_SPEC, CQCMRPTGRN->PSD_SS_SPEC, sizeof(CQCMRPTGRN->PSD_SS_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_OS_SPEC, CQCMRPTGRN->PSD_OS_SPEC, sizeof(CQCMRPTGRN->PSD_OS_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_LS_SPEC, CQCMRPTGRN->PSD_LS_SPEC, sizeof(CQCMRPTGRN->PSD_LS_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_FS_SPEC, CQCMRPTGRN->PSD_FS_SPEC, sizeof(CQCMRPTGRN->PSD_FS_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->HLT_TI_SPEC, CQCMRPTGRN->HLT_TI_SPEC, sizeof(CQCMRPTGRN->HLT_TI_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->TI_VAL, CQCMRPTGRN->TI_VAL, sizeof(CQCMRPTGRN->TI_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->TTI_VAL, CQCMRPTGRN->TTI_VAL, sizeof(CQCMRPTGRN->TTI_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->MA_VAL, CQCMRPTGRN->MA_VAL, sizeof(CQCMRPTGRN->MA_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->WT_VAL, CQCMRPTGRN->WT_VAL, sizeof(CQCMRPTGRN->WT_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->BD_VAL, CQCMRPTGRN->BD_VAL, sizeof(CQCMRPTGRN->BD_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->TD_VAL, CQCMRPTGRN->TD_VAL, sizeof(CQCMRPTGRN->TD_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PCS_VAL, CQCMRPTGRN->PCS_VAL, sizeof(CQCMRPTGRN->PCS_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_TS_VAL, CQCMRPTGRN->PSD_TS_VAL, sizeof(CQCMRPTGRN->PSD_TS_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_US_VAL, CQCMRPTGRN->PSD_US_VAL, sizeof(CQCMRPTGRN->PSD_US_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_SS_VAL, CQCMRPTGRN->PSD_SS_VAL, sizeof(CQCMRPTGRN->PSD_SS_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_OS_VAL, CQCMRPTGRN->PSD_OS_VAL, sizeof(CQCMRPTGRN->PSD_OS_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_LS_VAL, CQCMRPTGRN->PSD_LS_VAL, sizeof(CQCMRPTGRN->PSD_LS_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->PSD_FS_VAL, CQCMRPTGRN->PSD_FS_VAL, sizeof(CQCMRPTGRN->PSD_FS_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->HLT_TI_VAL, CQCMRPTGRN->HLT_TI_VAL, sizeof(CQCMRPTGRN->HLT_TI_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE01, CQCMRPTGRN->ATTRIBUTE01, sizeof(CQCMRPTGRN->ATTRIBUTE01));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE02, CQCMRPTGRN->ATTRIBUTE02, sizeof(CQCMRPTGRN->ATTRIBUTE02));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE03, CQCMRPTGRN->ATTRIBUTE03, sizeof(CQCMRPTGRN->ATTRIBUTE03));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE04, CQCMRPTGRN->ATTRIBUTE04, sizeof(CQCMRPTGRN->ATTRIBUTE04));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE05, CQCMRPTGRN->ATTRIBUTE05, sizeof(CQCMRPTGRN->ATTRIBUTE05));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE06, CQCMRPTGRN->ATTRIBUTE06, sizeof(CQCMRPTGRN->ATTRIBUTE06));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE07, CQCMRPTGRN->ATTRIBUTE07, sizeof(CQCMRPTGRN->ATTRIBUTE07));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE08, CQCMRPTGRN->ATTRIBUTE08, sizeof(CQCMRPTGRN->ATTRIBUTE08));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE09, CQCMRPTGRN->ATTRIBUTE09, sizeof(CQCMRPTGRN->ATTRIBUTE09));
    MEMCPY_AN(CQCMRPTGRN_N->ATTRIBUTE10, CQCMRPTGRN->ATTRIBUTE10, sizeof(CQCMRPTGRN->ATTRIBUTE10));
    MEMCPY_AN(CQCMRPTGRN_N->REMARKS, CQCMRPTGRN->REMARKS, sizeof(CQCMRPTGRN->REMARKS));
    CQCMRPTGRN_N->USE_YN[0] = CQCMRPTGRN->USE_YN;
    MEMCPY_AN(CQCMRPTGRN_N->CREATE_USER_ID, CQCMRPTGRN->CREATE_USER_ID, sizeof(CQCMRPTGRN->CREATE_USER_ID));
    MEMCPY_AN(CQCMRPTGRN_N->CREATE_TIME, CQCMRPTGRN->CREATE_TIME, sizeof(CQCMRPTGRN->CREATE_TIME));
    MEMCPY_AN(CQCMRPTGRN_N->UPDATE_USER_ID, CQCMRPTGRN->UPDATE_USER_ID, sizeof(CQCMRPTGRN->UPDATE_USER_ID));
    MEMCPY_AN(CQCMRPTGRN_N->UPDATE_TIME, CQCMRPTGRN->UPDATE_TIME, sizeof(CQCMRPTGRN->UPDATE_TIME));
    MEMCPY_AN(CQCMRPTGRN_N->IMAGE_NUM, CQCMRPTGRN->IMAGE_NUM, sizeof(CQCMRPTGRN->IMAGE_NUM));
    MEMCPY_AN(CQCMRPTGRN_N->BD_TI_SPEC, CQCMRPTGRN->BD_TI_SPEC, sizeof(CQCMRPTGRN->BD_TI_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->BD_TTI_SPEC, CQCMRPTGRN->BD_TTI_SPEC, sizeof(CQCMRPTGRN->BD_TTI_SPEC));
    MEMCPY_AN(CQCMRPTGRN_N->BD_TTI_VAL, CQCMRPTGRN->BD_TTI_VAL, sizeof(CQCMRPTGRN->BD_TTI_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->BD_TI_VAL, CQCMRPTGRN->BD_TI_VAL, sizeof(CQCMRPTGRN->BD_TI_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->SURFACE_B_VAL, CQCMRPTGRN->SURFACE_B_VAL, sizeof(CQCMRPTGRN->SURFACE_B_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->HEADER_ID, CQCMRPTGRN->HEADER_ID, sizeof(CQCMRPTGRN->HEADER_ID));
    MEMCPY_AN(CQCMRPTGRN_N->LINE_NUMBER, CQCMRPTGRN->LINE_NUMBER, sizeof(CQCMRPTGRN->LINE_NUMBER));
    MEMCPY_AN(CQCMRPTGRN_N->IMAGE_NUM2, CQCMRPTGRN->IMAGE_NUM2, sizeof(CQCMRPTGRN->IMAGE_NUM2));
    MEMCPY_AN(CQCMRPTGRN_N->IMAGE_NUM3, CQCMRPTGRN->IMAGE_NUM3, sizeof(CQCMRPTGRN->IMAGE_NUM3));
    MEMCPY_AN(CQCMRPTGRN_N->CM_L_VAL, CQCMRPTGRN->CM_L_VAL, sizeof(CQCMRPTGRN->CM_L_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->CM_A_VAL, CQCMRPTGRN->CM_A_VAL, sizeof(CQCMRPTGRN->CM_A_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->CM_B_VAL, CQCMRPTGRN->CM_B_VAL, sizeof(CQCMRPTGRN->CM_B_VAL));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_1, CQCMRPTGRN->RPT_CMF_1, sizeof(CQCMRPTGRN->RPT_CMF_1));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_2, CQCMRPTGRN->RPT_CMF_2, sizeof(CQCMRPTGRN->RPT_CMF_2));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_3, CQCMRPTGRN->RPT_CMF_3, sizeof(CQCMRPTGRN->RPT_CMF_3));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_4, CQCMRPTGRN->RPT_CMF_4, sizeof(CQCMRPTGRN->RPT_CMF_4));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_5, CQCMRPTGRN->RPT_CMF_5, sizeof(CQCMRPTGRN->RPT_CMF_5));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_6, CQCMRPTGRN->RPT_CMF_6, sizeof(CQCMRPTGRN->RPT_CMF_6));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_7, CQCMRPTGRN->RPT_CMF_7, sizeof(CQCMRPTGRN->RPT_CMF_7));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_8, CQCMRPTGRN->RPT_CMF_8, sizeof(CQCMRPTGRN->RPT_CMF_8));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_9, CQCMRPTGRN->RPT_CMF_9, sizeof(CQCMRPTGRN->RPT_CMF_9));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_10, CQCMRPTGRN->RPT_CMF_10, sizeof(CQCMRPTGRN->RPT_CMF_10));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_11, CQCMRPTGRN->RPT_CMF_11, sizeof(CQCMRPTGRN->RPT_CMF_11));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_12, CQCMRPTGRN->RPT_CMF_12, sizeof(CQCMRPTGRN->RPT_CMF_12));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_13, CQCMRPTGRN->RPT_CMF_13, sizeof(CQCMRPTGRN->RPT_CMF_13));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_14, CQCMRPTGRN->RPT_CMF_14, sizeof(CQCMRPTGRN->RPT_CMF_14));
    MEMCPY_AN(CQCMRPTGRN_N->RPT_CMF_15, CQCMRPTGRN->RPT_CMF_15, sizeof(CQCMRPTGRN->RPT_CMF_15));
}


/* Del Null Function */
void DBU_del_null_cqcmrptgrn(struct CQCMRPTGRN_N_TAG *CQCMRPTGRN_N, struct CQCMRPTGRN_TAG *CQCMRPTGRN)
{
    MEMCPY_DN(CQCMRPTGRN->FACTORY, CQCMRPTGRN_N->FACTORY, sizeof(CQCMRPTGRN->FACTORY));
    MEMCPY_DN(CQCMRPTGRN->REPORT_NO, CQCMRPTGRN_N->REPORT_NO, sizeof(CQCMRPTGRN->REPORT_NO));
    MEMCPY_DN(CQCMRPTGRN->LOT_ID, CQCMRPTGRN_N->LOT_ID, sizeof(CQCMRPTGRN->LOT_ID));
    MEMCPY_DN(CQCMRPTGRN->GRADE, CQCMRPTGRN_N->GRADE, sizeof(CQCMRPTGRN->GRADE));
    MEMCPY_DN(CQCMRPTGRN->SIZES, CQCMRPTGRN_N->SIZES, sizeof(CQCMRPTGRN->SIZES));
    MEMCPY_DN(CQCMRPTGRN->ORDER_NO, CQCMRPTGRN_N->ORDER_NO, sizeof(CQCMRPTGRN->ORDER_NO));
    MEMCPY_DN(CQCMRPTGRN->CUST_NO, CQCMRPTGRN_N->CUST_NO, sizeof(CQCMRPTGRN->CUST_NO));
    MEMCPY_DN(CQCMRPTGRN->GRADE_SPEC, CQCMRPTGRN_N->GRADE_SPEC, sizeof(CQCMRPTGRN->GRADE_SPEC));
    MEMCPY_DN(CQCMRPTGRN->SIZES_SPEC, CQCMRPTGRN_N->SIZES_SPEC, sizeof(CQCMRPTGRN->SIZES_SPEC));
    MEMCPY_DN(CQCMRPTGRN->TI_SPEC, CQCMRPTGRN_N->TI_SPEC, sizeof(CQCMRPTGRN->TI_SPEC));
    MEMCPY_DN(CQCMRPTGRN->TTI_SPEC, CQCMRPTGRN_N->TTI_SPEC, sizeof(CQCMRPTGRN->TTI_SPEC));
    MEMCPY_DN(CQCMRPTGRN->MA_SPEC, CQCMRPTGRN_N->MA_SPEC, sizeof(CQCMRPTGRN->MA_SPEC));
    MEMCPY_DN(CQCMRPTGRN->WT_SPEC, CQCMRPTGRN_N->WT_SPEC, sizeof(CQCMRPTGRN->WT_SPEC));
    MEMCPY_DN(CQCMRPTGRN->BD_SPEC, CQCMRPTGRN_N->BD_SPEC, sizeof(CQCMRPTGRN->BD_SPEC));
    MEMCPY_DN(CQCMRPTGRN->TD_SPEC, CQCMRPTGRN_N->TD_SPEC, sizeof(CQCMRPTGRN->TD_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PCS_SPEC, CQCMRPTGRN_N->PCS_SPEC, sizeof(CQCMRPTGRN->PCS_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PSD_TS_SPEC, CQCMRPTGRN_N->PSD_TS_SPEC, sizeof(CQCMRPTGRN->PSD_TS_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PSD_US_SPEC, CQCMRPTGRN_N->PSD_US_SPEC, sizeof(CQCMRPTGRN->PSD_US_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PSD_SS_SPEC, CQCMRPTGRN_N->PSD_SS_SPEC, sizeof(CQCMRPTGRN->PSD_SS_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PSD_OS_SPEC, CQCMRPTGRN_N->PSD_OS_SPEC, sizeof(CQCMRPTGRN->PSD_OS_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PSD_LS_SPEC, CQCMRPTGRN_N->PSD_LS_SPEC, sizeof(CQCMRPTGRN->PSD_LS_SPEC));
    MEMCPY_DN(CQCMRPTGRN->PSD_FS_SPEC, CQCMRPTGRN_N->PSD_FS_SPEC, sizeof(CQCMRPTGRN->PSD_FS_SPEC));
    MEMCPY_DN(CQCMRPTGRN->HLT_TI_SPEC, CQCMRPTGRN_N->HLT_TI_SPEC, sizeof(CQCMRPTGRN->HLT_TI_SPEC));
    MEMCPY_DN(CQCMRPTGRN->TI_VAL, CQCMRPTGRN_N->TI_VAL, sizeof(CQCMRPTGRN->TI_VAL));
    MEMCPY_DN(CQCMRPTGRN->TTI_VAL, CQCMRPTGRN_N->TTI_VAL, sizeof(CQCMRPTGRN->TTI_VAL));
    MEMCPY_DN(CQCMRPTGRN->MA_VAL, CQCMRPTGRN_N->MA_VAL, sizeof(CQCMRPTGRN->MA_VAL));
    MEMCPY_DN(CQCMRPTGRN->WT_VAL, CQCMRPTGRN_N->WT_VAL, sizeof(CQCMRPTGRN->WT_VAL));
    MEMCPY_DN(CQCMRPTGRN->BD_VAL, CQCMRPTGRN_N->BD_VAL, sizeof(CQCMRPTGRN->BD_VAL));
    MEMCPY_DN(CQCMRPTGRN->TD_VAL, CQCMRPTGRN_N->TD_VAL, sizeof(CQCMRPTGRN->TD_VAL));
    MEMCPY_DN(CQCMRPTGRN->PCS_VAL, CQCMRPTGRN_N->PCS_VAL, sizeof(CQCMRPTGRN->PCS_VAL));
    MEMCPY_DN(CQCMRPTGRN->PSD_TS_VAL, CQCMRPTGRN_N->PSD_TS_VAL, sizeof(CQCMRPTGRN->PSD_TS_VAL));
    MEMCPY_DN(CQCMRPTGRN->PSD_US_VAL, CQCMRPTGRN_N->PSD_US_VAL, sizeof(CQCMRPTGRN->PSD_US_VAL));
    MEMCPY_DN(CQCMRPTGRN->PSD_SS_VAL, CQCMRPTGRN_N->PSD_SS_VAL, sizeof(CQCMRPTGRN->PSD_SS_VAL));
    MEMCPY_DN(CQCMRPTGRN->PSD_OS_VAL, CQCMRPTGRN_N->PSD_OS_VAL, sizeof(CQCMRPTGRN->PSD_OS_VAL));
    MEMCPY_DN(CQCMRPTGRN->PSD_LS_VAL, CQCMRPTGRN_N->PSD_LS_VAL, sizeof(CQCMRPTGRN->PSD_LS_VAL));
    MEMCPY_DN(CQCMRPTGRN->PSD_FS_VAL, CQCMRPTGRN_N->PSD_FS_VAL, sizeof(CQCMRPTGRN->PSD_FS_VAL));
    MEMCPY_DN(CQCMRPTGRN->HLT_TI_VAL, CQCMRPTGRN_N->HLT_TI_VAL, sizeof(CQCMRPTGRN->HLT_TI_VAL));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE01, CQCMRPTGRN_N->ATTRIBUTE01, sizeof(CQCMRPTGRN->ATTRIBUTE01));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE02, CQCMRPTGRN_N->ATTRIBUTE02, sizeof(CQCMRPTGRN->ATTRIBUTE02));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE03, CQCMRPTGRN_N->ATTRIBUTE03, sizeof(CQCMRPTGRN->ATTRIBUTE03));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE04, CQCMRPTGRN_N->ATTRIBUTE04, sizeof(CQCMRPTGRN->ATTRIBUTE04));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE05, CQCMRPTGRN_N->ATTRIBUTE05, sizeof(CQCMRPTGRN->ATTRIBUTE05));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE06, CQCMRPTGRN_N->ATTRIBUTE06, sizeof(CQCMRPTGRN->ATTRIBUTE06));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE07, CQCMRPTGRN_N->ATTRIBUTE07, sizeof(CQCMRPTGRN->ATTRIBUTE07));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE08, CQCMRPTGRN_N->ATTRIBUTE08, sizeof(CQCMRPTGRN->ATTRIBUTE08));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE09, CQCMRPTGRN_N->ATTRIBUTE09, sizeof(CQCMRPTGRN->ATTRIBUTE09));
    MEMCPY_DN(CQCMRPTGRN->ATTRIBUTE10, CQCMRPTGRN_N->ATTRIBUTE10, sizeof(CQCMRPTGRN->ATTRIBUTE10));
    MEMCPY_DN(CQCMRPTGRN->REMARKS, CQCMRPTGRN_N->REMARKS, sizeof(CQCMRPTGRN->REMARKS));
    CQCMRPTGRN->USE_YN = CQCMRPTGRN_N->USE_YN[0];
    MEMCPY_DN(CQCMRPTGRN->CREATE_USER_ID, CQCMRPTGRN_N->CREATE_USER_ID, sizeof(CQCMRPTGRN->CREATE_USER_ID));
    MEMCPY_DN(CQCMRPTGRN->CREATE_TIME, CQCMRPTGRN_N->CREATE_TIME, sizeof(CQCMRPTGRN->CREATE_TIME));
    MEMCPY_DN(CQCMRPTGRN->UPDATE_USER_ID, CQCMRPTGRN_N->UPDATE_USER_ID, sizeof(CQCMRPTGRN->UPDATE_USER_ID));
    MEMCPY_DN(CQCMRPTGRN->UPDATE_TIME, CQCMRPTGRN_N->UPDATE_TIME, sizeof(CQCMRPTGRN->UPDATE_TIME));
    MEMCPY_DN(CQCMRPTGRN->IMAGE_NUM, CQCMRPTGRN_N->IMAGE_NUM, sizeof(CQCMRPTGRN->IMAGE_NUM));
    MEMCPY_DN(CQCMRPTGRN->BD_TI_SPEC, CQCMRPTGRN_N->BD_TI_SPEC, sizeof(CQCMRPTGRN->BD_TI_SPEC));
    MEMCPY_DN(CQCMRPTGRN->BD_TTI_SPEC, CQCMRPTGRN_N->BD_TTI_SPEC, sizeof(CQCMRPTGRN->BD_TTI_SPEC));
    MEMCPY_DN(CQCMRPTGRN->BD_TTI_VAL, CQCMRPTGRN_N->BD_TTI_VAL, sizeof(CQCMRPTGRN->BD_TTI_VAL));
    MEMCPY_DN(CQCMRPTGRN->BD_TI_VAL, CQCMRPTGRN_N->BD_TI_VAL, sizeof(CQCMRPTGRN->BD_TI_VAL));
    MEMCPY_DN(CQCMRPTGRN->SURFACE_B_VAL, CQCMRPTGRN_N->SURFACE_B_VAL, sizeof(CQCMRPTGRN->SURFACE_B_VAL));
    MEMCPY_DN(CQCMRPTGRN->HEADER_ID, CQCMRPTGRN_N->HEADER_ID, sizeof(CQCMRPTGRN->HEADER_ID));
    MEMCPY_DN(CQCMRPTGRN->LINE_NUMBER, CQCMRPTGRN_N->LINE_NUMBER, sizeof(CQCMRPTGRN->LINE_NUMBER));
    MEMCPY_DN(CQCMRPTGRN->IMAGE_NUM2, CQCMRPTGRN_N->IMAGE_NUM2, sizeof(CQCMRPTGRN->IMAGE_NUM2));
    MEMCPY_DN(CQCMRPTGRN->IMAGE_NUM3, CQCMRPTGRN_N->IMAGE_NUM3, sizeof(CQCMRPTGRN->IMAGE_NUM3));
    MEMCPY_DN(CQCMRPTGRN->CM_L_VAL, CQCMRPTGRN_N->CM_L_VAL, sizeof(CQCMRPTGRN->CM_L_VAL));
    MEMCPY_DN(CQCMRPTGRN->CM_A_VAL, CQCMRPTGRN_N->CM_A_VAL, sizeof(CQCMRPTGRN->CM_A_VAL));
    MEMCPY_DN(CQCMRPTGRN->CM_B_VAL, CQCMRPTGRN_N->CM_B_VAL, sizeof(CQCMRPTGRN->CM_B_VAL));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_1, CQCMRPTGRN_N->RPT_CMF_1, sizeof(CQCMRPTGRN->RPT_CMF_1));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_2, CQCMRPTGRN_N->RPT_CMF_2, sizeof(CQCMRPTGRN->RPT_CMF_2));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_3, CQCMRPTGRN_N->RPT_CMF_3, sizeof(CQCMRPTGRN->RPT_CMF_3));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_4, CQCMRPTGRN_N->RPT_CMF_4, sizeof(CQCMRPTGRN->RPT_CMF_4));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_5, CQCMRPTGRN_N->RPT_CMF_5, sizeof(CQCMRPTGRN->RPT_CMF_5));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_6, CQCMRPTGRN_N->RPT_CMF_6, sizeof(CQCMRPTGRN->RPT_CMF_6));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_7, CQCMRPTGRN_N->RPT_CMF_7, sizeof(CQCMRPTGRN->RPT_CMF_7));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_8, CQCMRPTGRN_N->RPT_CMF_8, sizeof(CQCMRPTGRN->RPT_CMF_8));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_9, CQCMRPTGRN_N->RPT_CMF_9, sizeof(CQCMRPTGRN->RPT_CMF_9));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_10, CQCMRPTGRN_N->RPT_CMF_10, sizeof(CQCMRPTGRN->RPT_CMF_10));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_11, CQCMRPTGRN_N->RPT_CMF_11, sizeof(CQCMRPTGRN->RPT_CMF_11));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_12, CQCMRPTGRN_N->RPT_CMF_12, sizeof(CQCMRPTGRN->RPT_CMF_12));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_13, CQCMRPTGRN_N->RPT_CMF_13, sizeof(CQCMRPTGRN->RPT_CMF_13));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_14, CQCMRPTGRN_N->RPT_CMF_14, sizeof(CQCMRPTGRN->RPT_CMF_14));
    MEMCPY_DN(CQCMRPTGRN->RPT_CMF_15, CQCMRPTGRN_N->RPT_CMF_15, sizeof(CQCMRPTGRN->RPT_CMF_15));
}


