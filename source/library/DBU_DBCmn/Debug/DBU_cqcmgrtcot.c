
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
    "DBU_cqcmgrtcot.pc"
};


static unsigned int sqlctx = 9376907;


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
            void  *sqhstv[58];
   unsigned int   sqhstl[58];
            int   sqhsts[58];
            void  *sqindv[58];
            int   sqinds[58];
   unsigned int   sqharm[58];
   unsigned int   *sqharc[58];
   unsigned short  sqadto[58];
   unsigned short  sqtdso[58];
} sqlstm = {13,58};

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
"select FACTORY ,INSP_ID ,INSP_DTL_TYPE ,INSP_COUNT ,SIZES ,MA_VALUE_1 ,MA_R\
ESULT ,WT_VALUE_1 ,WT_VALUE_2 ,WT_VALUE_3 ,WT_RESULT ,BD_VALUE_1 ,BD_RESULT ,\
TD_VALUE_1 ,TD_RESULT ,PCS_VALUE_1 ,PCS_RESULT ,PS_VALUE_1 ,PS_VALUE_2 ,PS_RE\
SULT ,CM_L ,CM_A ,CM_B ,CM_YI ,REMARKS ,COMPAC_VALUE ,ELIP_VALUE ,ROUG_VALUE \
,SURFACE_NI ,SURFACE_FE ,SURFACE_CU ,SURFACE_CR ,SURFACE_TI ,SURFACE_MN ,SURF\
ACE_CO ,SURFACE_CA ,SURFACE_MG ,SURFACE_ZN ,SURFACE_MO ,SURFACE_PB ,SURFACE_A\
L ,SURFACE_SI ,SURFACE_B ,SURFACE_NA ,CON_O_VALUE ,ELIP_VALUE2 ,SHAPE_FACTOR \
,GRAIN_SIZE ,CIRCULRARITY ,CONVEXITY ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USE\
R_ID ,UPDATE_TIME  from CQCMGRTCOT  order by FACTORY asc ,INSP_ID asc ,INSP_D\
TL_TYPE asc ,INSP_COUNT asc             ";

 static const char *sq0009 = 
"select FACTORY ,INSP_ID ,INSP_DTL_TYPE ,INSP_COUNT ,SIZES ,MA_VALUE_1 ,MA_R\
ESULT ,WT_VALUE_1 ,WT_VALUE_2 ,WT_VALUE_3 ,WT_RESULT ,BD_VALUE_1 ,BD_RESULT ,\
TD_VALUE_1 ,TD_RESULT ,PCS_VALUE_1 ,PCS_RESULT ,PS_VALUE_1 ,PS_VALUE_2 ,PS_RE\
SULT ,CM_L ,CM_A ,CM_B ,CM_YI ,REMARKS ,COMPAC_VALUE ,ELIP_VALUE ,ROUG_VALUE \
,SURFACE_NI ,SURFACE_FE ,SURFACE_CU ,SURFACE_CR ,SURFACE_TI ,SURFACE_MN ,SURF\
ACE_CO ,SURFACE_CA ,SURFACE_MG ,SURFACE_ZN ,SURFACE_MO ,SURFACE_PB ,SURFACE_A\
L ,SURFACE_SI ,SURFACE_B ,SURFACE_NA ,CON_O_VALUE ,ELIP_VALUE2 ,SHAPE_FACTOR \
,GRAIN_SIZE ,CIRCULRARITY ,CONVEXITY ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USE\
R_ID ,UPDATE_TIME  from CQCMGRTCOT where (FACTORY=:b0 and INSP_ID=:b1)       \
    ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,994,0,4,46,0,0,58,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
252,0,0,2,1006,0,4,197,0,0,58,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
499,0,0,3,123,0,4,351,0,0,5,4,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
534,0,0,4,78,0,4,361,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
561,0,0,5,105,0,2,398,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
592,0,0,6,865,0,3,430,0,0,54,54,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,
823,0,0,7,878,0,5,563,0,0,54,54,0,1,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,
1054,0,0,8,731,0,9,709,0,0,0,0,0,1,0,
1069,0,0,9,695,0,9,772,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1092,0,0,8,0,0,13,801,0,0,54,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,
1323,0,0,9,0,0,13,859,0,0,54,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,
1554,0,0,8,0,0,15,943,0,0,0,0,0,1,0,
1569,0,0,9,0,0,15,947,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmgrtcot.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-10-03 12:25:59
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
void DBU_add_null_cqcmgrtcot(struct CQCMGRTCOT_N_TAG *CQCMGRTCOT_N, struct CQCMGRTCOT_TAG *CQCMGRTCOT);
void DBU_del_null_cqcmgrtcot(struct CQCMGRTCOT_N_TAG *CQCMGRTCOT_N, struct CQCMGRTCOT_TAG *CQCMGRTCOT);


/* SQL SELECT Function */
void DBU_select_cqcmgrtcot(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    INSP_ID,
                    INSP_DTL_TYPE,
                    INSP_COUNT,
                    SIZES,
                    MA_VALUE_1,
                    MA_RESULT,
                    WT_VALUE_1,
                    WT_VALUE_2,
                    WT_VALUE_3,
                    WT_RESULT,
                    BD_VALUE_1,
                    BD_RESULT,
                    TD_VALUE_1,
                    TD_RESULT,
                    PCS_VALUE_1,
                    PCS_RESULT,
                    PS_VALUE_1,
                    PS_VALUE_2,
                    PS_RESULT,
                    CM_L,
                    CM_A,
                    CM_B,
                    CM_YI,
                    REMARKS,
                    COMPAC_VALUE,
                    ELIP_VALUE,
                    ROUG_VALUE,
                    SURFACE_NI,
                    SURFACE_FE,
                    SURFACE_CU,
                    SURFACE_CR,
                    SURFACE_TI,
                    SURFACE_MN,
                    SURFACE_CO,
                    SURFACE_CA,
                    SURFACE_MG,
                    SURFACE_ZN,
                    SURFACE_MO,
                    SURFACE_PB,
                    SURFACE_AL,
                    SURFACE_SI,
                    SURFACE_B,
                    SURFACE_NA,
                    CON_O_VALUE,
                    ELIP_VALUE2,
                    SHAPE_FACTOR,
                    GRAIN_SIZE,
                    CIRCULRARITY,
                    CONVEXITY,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CQCMGRTCOT_N.FACTORY,
                    :CQCMGRTCOT_N.INSP_ID,
                    :CQCMGRTCOT_N.INSP_DTL_TYPE,
                    :CQCMGRTCOT_N.INSP_COUNT,
                    :CQCMGRTCOT_N.SIZES,
                    :CQCMGRTCOT_N.MA_VALUE_1,
                    :CQCMGRTCOT_N.MA_RESULT,
                    :CQCMGRTCOT_N.WT_VALUE_1,
                    :CQCMGRTCOT_N.WT_VALUE_2,
                    :CQCMGRTCOT_N.WT_VALUE_3,
                    :CQCMGRTCOT_N.WT_RESULT,
                    :CQCMGRTCOT_N.BD_VALUE_1,
                    :CQCMGRTCOT_N.BD_RESULT,
                    :CQCMGRTCOT_N.TD_VALUE_1,
                    :CQCMGRTCOT_N.TD_RESULT,
                    :CQCMGRTCOT_N.PCS_VALUE_1,
                    :CQCMGRTCOT_N.PCS_RESULT,
                    :CQCMGRTCOT_N.PS_VALUE_1,
                    :CQCMGRTCOT_N.PS_VALUE_2,
                    :CQCMGRTCOT_N.PS_RESULT,
                    :CQCMGRTCOT_N.CM_L,
                    :CQCMGRTCOT_N.CM_A,
                    :CQCMGRTCOT_N.CM_B,
                    :CQCMGRTCOT_N.CM_YI,
                    :CQCMGRTCOT_N.REMARKS,
                    :CQCMGRTCOT_N.COMPAC_VALUE,
                    :CQCMGRTCOT_N.ELIP_VALUE,
                    :CQCMGRTCOT_N.ROUG_VALUE,
                    :CQCMGRTCOT_N.SURFACE_NI,
                    :CQCMGRTCOT_N.SURFACE_FE,
                    :CQCMGRTCOT_N.SURFACE_CU,
                    :CQCMGRTCOT_N.SURFACE_CR,
                    :CQCMGRTCOT_N.SURFACE_TI,
                    :CQCMGRTCOT_N.SURFACE_MN,
                    :CQCMGRTCOT_N.SURFACE_CO,
                    :CQCMGRTCOT_N.SURFACE_CA,
                    :CQCMGRTCOT_N.SURFACE_MG,
                    :CQCMGRTCOT_N.SURFACE_ZN,
                    :CQCMGRTCOT_N.SURFACE_MO,
                    :CQCMGRTCOT_N.SURFACE_PB,
                    :CQCMGRTCOT_N.SURFACE_AL,
                    :CQCMGRTCOT_N.SURFACE_SI,
                    :CQCMGRTCOT_N.SURFACE_B,
                    :CQCMGRTCOT_N.SURFACE_NA,
                    :CQCMGRTCOT_N.CON_O_VALUE,
                    :CQCMGRTCOT_N.ELIP_VALUE2,
                    :CQCMGRTCOT_N.SHAPE_FACTOR,
                    :CQCMGRTCOT_N.GRAIN_SIZE,
                    :CQCMGRTCOT_N.CIRCULRARITY,
                    :CQCMGRTCOT_N.CONVEXITY,
                    :CQCMGRTCOT_N.CREATE_USER_ID,
                    :CQCMGRTCOT_N.CREATE_TIME,
                    :CQCMGRTCOT_N.UPDATE_USER_ID,
                    :CQCMGRTCOT_N.UPDATE_TIME
                FROM CQCMGRTCOT
                WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
                    AND INSP_ID = :CQCMGRTCOT_N.INSP_ID
                    AND INSP_DTL_TYPE = :CQCMGRTCOT_N.INSP_DTL_TYPE
                    AND INSP_COUNT = :CQCMGRTCOT_N.INSP_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,INSP_ID ,INSP_DTL_TYPE ,INSP_COU\
NT ,SIZES ,MA_VALUE_1 ,MA_RESULT ,WT_VALUE_1 ,WT_VALUE_2 ,WT_VALUE_3 ,WT_RESU\
LT ,BD_VALUE_1 ,BD_RESULT ,TD_VALUE_1 ,TD_RESULT ,PCS_VALUE_1 ,PCS_RESULT ,PS\
_VALUE_1 ,PS_VALUE_2 ,PS_RESULT ,CM_L ,CM_A ,CM_B ,CM_YI ,REMARKS ,COMPAC_VAL\
UE ,ELIP_VALUE ,ROUG_VALUE ,SURFACE_NI ,SURFACE_FE ,SURFACE_CU ,SURFACE_CR ,S\
URFACE_TI ,SURFACE_MN ,SURFACE_CO ,SURFACE_CA ,SURFACE_MG ,SURFACE_ZN ,SURFAC\
E_MO ,SURFACE_PB ,SURFACE_AL ,SURFACE_SI ,SURFACE_B ,SURFACE_NA ,CON_O_VALUE \
,ELIP_VALUE2 ,SHAPE_FACTOR ,GRAIN_SIZE ,CIRCULRARITY ,CONVEXITY ,CREATE_USER_\
ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6\
,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22\
,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:\
b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b5\
3  from CQCMGRTCOT where (((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE=:b\
2) and INSP_COUNT=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMGRTCOT_N.SIZES);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMGRTCOT_N.MA_VALUE_1);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMGRTCOT_N.MA_RESULT);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CQCMGRTCOT_N.WT_RESULT);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMGRTCOT_N.BD_VALUE_1);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMGRTCOT_N.BD_RESULT);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMGRTCOT_N.TD_VALUE_1);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMGRTCOT_N.TD_RESULT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMGRTCOT_N.PCS_VALUE_1);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(CQCMGRTCOT_N.PCS_RESULT);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_1);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CQCMGRTCOT_N.PS_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CQCMGRTCOT_N.CM_L);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CQCMGRTCOT_N.CM_A);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CQCMGRTCOT_N.CM_B);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CQCMGRTCOT_N.CM_YI);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMGRTCOT_N.REMARKS);
            sqlstm.sqhstl[24] = (unsigned int  )301;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CQCMGRTCOT_N.COMPAC_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CQCMGRTCOT_N.ROUG_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NI);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CQCMGRTCOT_N.SURFACE_FE);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CU);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CR);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CQCMGRTCOT_N.SURFACE_TI);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MN);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CO);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CA);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MG);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMGRTCOT_N.SURFACE_ZN);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MO);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CQCMGRTCOT_N.SURFACE_PB);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CQCMGRTCOT_N.SURFACE_AL);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CQCMGRTCOT_N.SURFACE_SI);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CQCMGRTCOT_N.SURFACE_B);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NA);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CQCMGRTCOT_N.CON_O_VALUE);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE2);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CQCMGRTCOT_N.SHAPE_FACTOR);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CQCMGRTCOT_N.GRAIN_SIZE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CQCMGRTCOT_N.CIRCULRARITY);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CQCMGRTCOT_N.CONVEXITY);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMGRTCOT_N.CREATE_USER_ID);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMGRTCOT_N.CREATE_TIME);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMGRTCOT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMGRTCOT_N.UPDATE_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
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
        DBU_del_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    }

    DB_stop_query_timer("DBU_select_cqcmgrtcot", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmgrtcot_for_update(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    INSP_ID,
                    INSP_DTL_TYPE,
                    INSP_COUNT,
                    SIZES,
                    MA_VALUE_1,
                    MA_RESULT,
                    WT_VALUE_1,
                    WT_VALUE_2,
                    WT_VALUE_3,
                    WT_RESULT,
                    BD_VALUE_1,
                    BD_RESULT,
                    TD_VALUE_1,
                    TD_RESULT,
                    PCS_VALUE_1,
                    PCS_RESULT,
                    PS_VALUE_1,
                    PS_VALUE_2,
                    PS_RESULT,
                    CM_L,
                    CM_A,
                    CM_B,
                    CM_YI,
                    REMARKS,
                    COMPAC_VALUE,
                    ELIP_VALUE,
                    ROUG_VALUE,
                    SURFACE_NI,
                    SURFACE_FE,
                    SURFACE_CU,
                    SURFACE_CR,
                    SURFACE_TI,
                    SURFACE_MN,
                    SURFACE_CO,
                    SURFACE_CA,
                    SURFACE_MG,
                    SURFACE_ZN,
                    SURFACE_MO,
                    SURFACE_PB,
                    SURFACE_AL,
                    SURFACE_SI,
                    SURFACE_B,
                    SURFACE_NA,
                    CON_O_VALUE,
                    ELIP_VALUE2,
                    SHAPE_FACTOR,
                    GRAIN_SIZE,
                    CIRCULRARITY,
                    CONVEXITY,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                INTO 
                    :CQCMGRTCOT_N.FACTORY,
                    :CQCMGRTCOT_N.INSP_ID,
                    :CQCMGRTCOT_N.INSP_DTL_TYPE,
                    :CQCMGRTCOT_N.INSP_COUNT,
                    :CQCMGRTCOT_N.SIZES,
                    :CQCMGRTCOT_N.MA_VALUE_1,
                    :CQCMGRTCOT_N.MA_RESULT,
                    :CQCMGRTCOT_N.WT_VALUE_1,
                    :CQCMGRTCOT_N.WT_VALUE_2,
                    :CQCMGRTCOT_N.WT_VALUE_3,
                    :CQCMGRTCOT_N.WT_RESULT,
                    :CQCMGRTCOT_N.BD_VALUE_1,
                    :CQCMGRTCOT_N.BD_RESULT,
                    :CQCMGRTCOT_N.TD_VALUE_1,
                    :CQCMGRTCOT_N.TD_RESULT,
                    :CQCMGRTCOT_N.PCS_VALUE_1,
                    :CQCMGRTCOT_N.PCS_RESULT,
                    :CQCMGRTCOT_N.PS_VALUE_1,
                    :CQCMGRTCOT_N.PS_VALUE_2,
                    :CQCMGRTCOT_N.PS_RESULT,
                    :CQCMGRTCOT_N.CM_L,
                    :CQCMGRTCOT_N.CM_A,
                    :CQCMGRTCOT_N.CM_B,
                    :CQCMGRTCOT_N.CM_YI,
                    :CQCMGRTCOT_N.REMARKS,
                    :CQCMGRTCOT_N.COMPAC_VALUE,
                    :CQCMGRTCOT_N.ELIP_VALUE,
                    :CQCMGRTCOT_N.ROUG_VALUE,
                    :CQCMGRTCOT_N.SURFACE_NI,
                    :CQCMGRTCOT_N.SURFACE_FE,
                    :CQCMGRTCOT_N.SURFACE_CU,
                    :CQCMGRTCOT_N.SURFACE_CR,
                    :CQCMGRTCOT_N.SURFACE_TI,
                    :CQCMGRTCOT_N.SURFACE_MN,
                    :CQCMGRTCOT_N.SURFACE_CO,
                    :CQCMGRTCOT_N.SURFACE_CA,
                    :CQCMGRTCOT_N.SURFACE_MG,
                    :CQCMGRTCOT_N.SURFACE_ZN,
                    :CQCMGRTCOT_N.SURFACE_MO,
                    :CQCMGRTCOT_N.SURFACE_PB,
                    :CQCMGRTCOT_N.SURFACE_AL,
                    :CQCMGRTCOT_N.SURFACE_SI,
                    :CQCMGRTCOT_N.SURFACE_B,
                    :CQCMGRTCOT_N.SURFACE_NA,
                    :CQCMGRTCOT_N.CON_O_VALUE,
                    :CQCMGRTCOT_N.ELIP_VALUE2,
                    :CQCMGRTCOT_N.SHAPE_FACTOR,
                    :CQCMGRTCOT_N.GRAIN_SIZE,
                    :CQCMGRTCOT_N.CIRCULRARITY,
                    :CQCMGRTCOT_N.CONVEXITY,
                    :CQCMGRTCOT_N.CREATE_USER_ID,
                    :CQCMGRTCOT_N.CREATE_TIME,
                    :CQCMGRTCOT_N.UPDATE_USER_ID,
                    :CQCMGRTCOT_N.UPDATE_TIME
                FROM CQCMGRTCOT
                WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
                    AND INSP_ID = :CQCMGRTCOT_N.INSP_ID
                    AND INSP_DTL_TYPE = :CQCMGRTCOT_N.INSP_DTL_TYPE
                    AND INSP_COUNT = :CQCMGRTCOT_N.INSP_COUNT
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,INSP_ID ,INSP_DTL_TYPE ,INSP_COU\
NT ,SIZES ,MA_VALUE_1 ,MA_RESULT ,WT_VALUE_1 ,WT_VALUE_2 ,WT_VALUE_3 ,WT_RESU\
LT ,BD_VALUE_1 ,BD_RESULT ,TD_VALUE_1 ,TD_RESULT ,PCS_VALUE_1 ,PCS_RESULT ,PS\
_VALUE_1 ,PS_VALUE_2 ,PS_RESULT ,CM_L ,CM_A ,CM_B ,CM_YI ,REMARKS ,COMPAC_VAL\
UE ,ELIP_VALUE ,ROUG_VALUE ,SURFACE_NI ,SURFACE_FE ,SURFACE_CU ,SURFACE_CR ,S\
URFACE_TI ,SURFACE_MN ,SURFACE_CO ,SURFACE_CA ,SURFACE_MG ,SURFACE_ZN ,SURFAC\
E_MO ,SURFACE_PB ,SURFACE_AL ,SURFACE_SI ,SURFACE_B ,SURFACE_NA ,CON_O_VALUE \
,ELIP_VALUE2 ,SHAPE_FACTOR ,GRAIN_SIZE ,CIRCULRARITY ,CONVEXITY ,CREATE_USER_\
ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6\
,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22\
,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:\
b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b5\
3  from CQCMGRTCOT where (((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE=:b\
2) and INSP_COUNT=:b3) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )252;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMGRTCOT_N.SIZES);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMGRTCOT_N.MA_VALUE_1);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMGRTCOT_N.MA_RESULT);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CQCMGRTCOT_N.WT_RESULT);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMGRTCOT_N.BD_VALUE_1);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMGRTCOT_N.BD_RESULT);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMGRTCOT_N.TD_VALUE_1);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMGRTCOT_N.TD_RESULT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMGRTCOT_N.PCS_VALUE_1);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(CQCMGRTCOT_N.PCS_RESULT);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_1);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CQCMGRTCOT_N.PS_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CQCMGRTCOT_N.CM_L);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CQCMGRTCOT_N.CM_A);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CQCMGRTCOT_N.CM_B);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CQCMGRTCOT_N.CM_YI);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMGRTCOT_N.REMARKS);
            sqlstm.sqhstl[24] = (unsigned int  )301;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CQCMGRTCOT_N.COMPAC_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CQCMGRTCOT_N.ROUG_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NI);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CQCMGRTCOT_N.SURFACE_FE);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CU);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CR);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CQCMGRTCOT_N.SURFACE_TI);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MN);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CO);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CA);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MG);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMGRTCOT_N.SURFACE_ZN);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MO);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CQCMGRTCOT_N.SURFACE_PB);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CQCMGRTCOT_N.SURFACE_AL);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CQCMGRTCOT_N.SURFACE_SI);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CQCMGRTCOT_N.SURFACE_B);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NA);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CQCMGRTCOT_N.CON_O_VALUE);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE2);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CQCMGRTCOT_N.SHAPE_FACTOR);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CQCMGRTCOT_N.GRAIN_SIZE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CQCMGRTCOT_N.CIRCULRARITY);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CQCMGRTCOT_N.CONVEXITY);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMGRTCOT_N.CREATE_USER_ID);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMGRTCOT_N.CREATE_TIME);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMGRTCOT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMGRTCOT_N.UPDATE_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[56] = (unsigned int  )31;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
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
        DBU_del_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    }

    DB_stop_query_timer("DBU_select_cqcmgrtcot_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmgrtcot_scalar(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMGRTCOT
                WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
                    AND INSP_ID = :CQCMGRTCOT_N.INSP_ID
                    AND INSP_DTL_TYPE = :CQCMGRTCOT_N.INSP_DTL_TYPE
                    AND INSP_COUNT = :CQCMGRTCOT_N.INSP_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMGRTCOT where\
 (((FACTORY=:b1 and INSP_ID=:b2) and INSP_DTL_TYPE=:b3) and INSP_COUNT=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )499;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
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

		case 2:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMGRTCOT
                WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
                    AND INSP_ID = :CQCMGRTCOT_N.INSP_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMGRTCOT where\
 (FACTORY=:b1 and INSP_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )534;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
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

    DB_stop_query_timer("DBU_select_cqcmgrtcot_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmgrtcot(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMGRTCOT
                WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
                    AND INSP_ID = :CQCMGRTCOT_N.INSP_ID
                    AND INSP_DTL_TYPE = :CQCMGRTCOT_N.INSP_DTL_TYPE
                    AND INSP_COUNT = :CQCMGRTCOT_N.INSP_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMGRTCOT  where (((FACTORY=:b0 an\
d INSP_ID=:b1) and INSP_DTL_TYPE=:b2) and INSP_COUNT=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )561;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
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

    DB_stop_query_timer("DBU_delete_cqcmgrtcot", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmgrtcot(struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMGRTCOT( 
                    FACTORY, 
                    INSP_ID, 
                    INSP_DTL_TYPE, 
                    INSP_COUNT, 
                    SIZES, 
                    MA_VALUE_1, 
                    MA_RESULT, 
                    WT_VALUE_1, 
                    WT_VALUE_2, 
                    WT_VALUE_3, 
                    WT_RESULT, 
                    BD_VALUE_1, 
                    BD_RESULT, 
                    TD_VALUE_1, 
                    TD_RESULT, 
                    PCS_VALUE_1, 
                    PCS_RESULT, 
                    PS_VALUE_1, 
                    PS_VALUE_2, 
                    PS_RESULT, 
                    CM_L, 
                    CM_A, 
                    CM_B, 
                    CM_YI, 
                    REMARKS, 
                    COMPAC_VALUE, 
                    ELIP_VALUE, 
                    ROUG_VALUE, 
                    SURFACE_NI, 
                    SURFACE_FE, 
                    SURFACE_CU, 
                    SURFACE_CR, 
                    SURFACE_TI, 
                    SURFACE_MN, 
                    SURFACE_CO, 
                    SURFACE_CA, 
                    SURFACE_MG, 
                    SURFACE_ZN, 
                    SURFACE_MO, 
                    SURFACE_PB, 
                    SURFACE_AL, 
                    SURFACE_SI, 
                    SURFACE_B, 
                    SURFACE_NA, 
                    CON_O_VALUE, 
                    ELIP_VALUE2, 
                    SHAPE_FACTOR, 
                    GRAIN_SIZE, 
                    CIRCULRARITY, 
                    CONVEXITY, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME
         ) 
        VALUES (
                    :CQCMGRTCOT_N.FACTORY,
                    :CQCMGRTCOT_N.INSP_ID,
                    :CQCMGRTCOT_N.INSP_DTL_TYPE,
                    :CQCMGRTCOT_N.INSP_COUNT,
                    :CQCMGRTCOT_N.SIZES,
                    :CQCMGRTCOT_N.MA_VALUE_1,
                    :CQCMGRTCOT_N.MA_RESULT,
                    :CQCMGRTCOT_N.WT_VALUE_1,
                    :CQCMGRTCOT_N.WT_VALUE_2,
                    :CQCMGRTCOT_N.WT_VALUE_3,
                    :CQCMGRTCOT_N.WT_RESULT,
                    :CQCMGRTCOT_N.BD_VALUE_1,
                    :CQCMGRTCOT_N.BD_RESULT,
                    :CQCMGRTCOT_N.TD_VALUE_1,
                    :CQCMGRTCOT_N.TD_RESULT,
                    :CQCMGRTCOT_N.PCS_VALUE_1,
                    :CQCMGRTCOT_N.PCS_RESULT,
                    :CQCMGRTCOT_N.PS_VALUE_1,
                    :CQCMGRTCOT_N.PS_VALUE_2,
                    :CQCMGRTCOT_N.PS_RESULT,
                    :CQCMGRTCOT_N.CM_L,
                    :CQCMGRTCOT_N.CM_A,
                    :CQCMGRTCOT_N.CM_B,
                    :CQCMGRTCOT_N.CM_YI,
                    :CQCMGRTCOT_N.REMARKS,
                    :CQCMGRTCOT_N.COMPAC_VALUE,
                    :CQCMGRTCOT_N.ELIP_VALUE,
                    :CQCMGRTCOT_N.ROUG_VALUE,
                    :CQCMGRTCOT_N.SURFACE_NI,
                    :CQCMGRTCOT_N.SURFACE_FE,
                    :CQCMGRTCOT_N.SURFACE_CU,
                    :CQCMGRTCOT_N.SURFACE_CR,
                    :CQCMGRTCOT_N.SURFACE_TI,
                    :CQCMGRTCOT_N.SURFACE_MN,
                    :CQCMGRTCOT_N.SURFACE_CO,
                    :CQCMGRTCOT_N.SURFACE_CA,
                    :CQCMGRTCOT_N.SURFACE_MG,
                    :CQCMGRTCOT_N.SURFACE_ZN,
                    :CQCMGRTCOT_N.SURFACE_MO,
                    :CQCMGRTCOT_N.SURFACE_PB,
                    :CQCMGRTCOT_N.SURFACE_AL,
                    :CQCMGRTCOT_N.SURFACE_SI,
                    :CQCMGRTCOT_N.SURFACE_B,
                    :CQCMGRTCOT_N.SURFACE_NA,
                    :CQCMGRTCOT_N.CON_O_VALUE,
                    :CQCMGRTCOT_N.ELIP_VALUE2,
                    :CQCMGRTCOT_N.SHAPE_FACTOR,
                    :CQCMGRTCOT_N.GRAIN_SIZE,
                    :CQCMGRTCOT_N.CIRCULRARITY,
                    :CQCMGRTCOT_N.CONVEXITY,
                    :CQCMGRTCOT_N.CREATE_USER_ID,
                    :CQCMGRTCOT_N.CREATE_TIME,
                    :CQCMGRTCOT_N.UPDATE_USER_ID,
                    :CQCMGRTCOT_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 58;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CQCMGRTCOT (FACTORY,INSP_ID,INSP_DTL_TYPE,IN\
SP_COUNT,SIZES,MA_VALUE_1,MA_RESULT,WT_VALUE_1,WT_VALUE_2,WT_VALUE_3,WT_RESUL\
T,BD_VALUE_1,BD_RESULT,TD_VALUE_1,TD_RESULT,PCS_VALUE_1,PCS_RESULT,PS_VALUE_1\
,PS_VALUE_2,PS_RESULT,CM_L,CM_A,CM_B,CM_YI,REMARKS,COMPAC_VALUE,ELIP_VALUE,RO\
UG_VALUE,SURFACE_NI,SURFACE_FE,SURFACE_CU,SURFACE_CR,SURFACE_TI,SURFACE_MN,SU\
RFACE_CO,SURFACE_CA,SURFACE_MG,SURFACE_ZN,SURFACE_MO,SURFACE_PB,SURFACE_AL,SU\
RFACE_SI,SURFACE_B,SURFACE_NA,CON_O_VALUE,ELIP_VALUE2,SHAPE_FACTOR,GRAIN_SIZE\
,CIRCULRARITY,CONVEXITY,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME\
) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b\
15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30\
,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:\
b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )592;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
    sqlstm.sqhstl[2] = (unsigned int  )31;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
    sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CQCMGRTCOT_N.SIZES);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)&(CQCMGRTCOT_N.MA_VALUE_1);
    sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(CQCMGRTCOT_N.MA_RESULT);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_1);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_2);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_3);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(CQCMGRTCOT_N.WT_RESULT);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(CQCMGRTCOT_N.BD_VALUE_1);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)&(CQCMGRTCOT_N.BD_RESULT);
    sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(CQCMGRTCOT_N.TD_VALUE_1);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(CQCMGRTCOT_N.TD_RESULT);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(CQCMGRTCOT_N.PCS_VALUE_1);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(CQCMGRTCOT_N.PCS_RESULT);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_1);
    sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_2);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(CQCMGRTCOT_N.PS_RESULT);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)&(CQCMGRTCOT_N.CM_L);
    sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(CQCMGRTCOT_N.CM_A);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(CQCMGRTCOT_N.CM_B);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)&(CQCMGRTCOT_N.CM_YI);
    sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMGRTCOT_N.REMARKS);
    sqlstm.sqhstl[24] = (unsigned int  )301;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(CQCMGRTCOT_N.COMPAC_VALUE);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE);
    sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)&(CQCMGRTCOT_N.ROUG_VALUE);
    sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NI);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)&(CQCMGRTCOT_N.SURFACE_FE);
    sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CU);
    sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CR);
    sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)&(CQCMGRTCOT_N.SURFACE_TI);
    sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MN);
    sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CO);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CA);
    sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MG);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(CQCMGRTCOT_N.SURFACE_ZN);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MO);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)&(CQCMGRTCOT_N.SURFACE_PB);
    sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(CQCMGRTCOT_N.SURFACE_AL);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)&(CQCMGRTCOT_N.SURFACE_SI);
    sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)&(CQCMGRTCOT_N.SURFACE_B);
    sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NA);
    sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)&(CQCMGRTCOT_N.CON_O_VALUE);
    sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE2);
    sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)&(CQCMGRTCOT_N.SHAPE_FACTOR);
    sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)&(CQCMGRTCOT_N.GRAIN_SIZE);
    sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)&(CQCMGRTCOT_N.CIRCULRARITY);
    sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)&(CQCMGRTCOT_N.CONVEXITY);
    sqlstm.sqhstl[49] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(CQCMGRTCOT_N.CREATE_USER_ID);
    sqlstm.sqhstl[50] = (unsigned int  )21;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(CQCMGRTCOT_N.CREATE_TIME);
    sqlstm.sqhstl[51] = (unsigned int  )15;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(CQCMGRTCOT_N.UPDATE_USER_ID);
    sqlstm.sqhstl[52] = (unsigned int  )21;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(CQCMGRTCOT_N.UPDATE_TIME);
    sqlstm.sqhstl[53] = (unsigned int  )15;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cqcmgrtcot", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmgrtcot(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMGRTCOT SET
                    SIZES = :CQCMGRTCOT_N.SIZES,
                    MA_VALUE_1 = :CQCMGRTCOT_N.MA_VALUE_1,
                    MA_RESULT = :CQCMGRTCOT_N.MA_RESULT,
                    WT_VALUE_1 = :CQCMGRTCOT_N.WT_VALUE_1,
                    WT_VALUE_2 = :CQCMGRTCOT_N.WT_VALUE_2,
                    WT_VALUE_3 = :CQCMGRTCOT_N.WT_VALUE_3,
                    WT_RESULT = :CQCMGRTCOT_N.WT_RESULT,
                    BD_VALUE_1 = :CQCMGRTCOT_N.BD_VALUE_1,
                    BD_RESULT = :CQCMGRTCOT_N.BD_RESULT,
                    TD_VALUE_1 = :CQCMGRTCOT_N.TD_VALUE_1,
                    TD_RESULT = :CQCMGRTCOT_N.TD_RESULT,
                    PCS_VALUE_1 = :CQCMGRTCOT_N.PCS_VALUE_1,
                    PCS_RESULT = :CQCMGRTCOT_N.PCS_RESULT,
                    PS_VALUE_1 = :CQCMGRTCOT_N.PS_VALUE_1,
                    PS_VALUE_2 = :CQCMGRTCOT_N.PS_VALUE_2,
                    PS_RESULT = :CQCMGRTCOT_N.PS_RESULT,
                    CM_L = :CQCMGRTCOT_N.CM_L,
                    CM_A = :CQCMGRTCOT_N.CM_A,
                    CM_B = :CQCMGRTCOT_N.CM_B,
                    CM_YI = :CQCMGRTCOT_N.CM_YI,
                    REMARKS = :CQCMGRTCOT_N.REMARKS,
                    COMPAC_VALUE = :CQCMGRTCOT_N.COMPAC_VALUE,
                    ELIP_VALUE = :CQCMGRTCOT_N.ELIP_VALUE,
                    ROUG_VALUE = :CQCMGRTCOT_N.ROUG_VALUE,
                    SURFACE_NI = :CQCMGRTCOT_N.SURFACE_NI,
                    SURFACE_FE = :CQCMGRTCOT_N.SURFACE_FE,
                    SURFACE_CU = :CQCMGRTCOT_N.SURFACE_CU,
                    SURFACE_CR = :CQCMGRTCOT_N.SURFACE_CR,
                    SURFACE_TI = :CQCMGRTCOT_N.SURFACE_TI,
                    SURFACE_MN = :CQCMGRTCOT_N.SURFACE_MN,
                    SURFACE_CO = :CQCMGRTCOT_N.SURFACE_CO,
                    SURFACE_CA = :CQCMGRTCOT_N.SURFACE_CA,
                    SURFACE_MG = :CQCMGRTCOT_N.SURFACE_MG,
                    SURFACE_ZN = :CQCMGRTCOT_N.SURFACE_ZN,
                    SURFACE_MO = :CQCMGRTCOT_N.SURFACE_MO,
                    SURFACE_PB = :CQCMGRTCOT_N.SURFACE_PB,
                    SURFACE_AL = :CQCMGRTCOT_N.SURFACE_AL,
                    SURFACE_SI = :CQCMGRTCOT_N.SURFACE_SI,
                    SURFACE_B = :CQCMGRTCOT_N.SURFACE_B,
                    SURFACE_NA = :CQCMGRTCOT_N.SURFACE_NA,
                    CON_O_VALUE = :CQCMGRTCOT_N.CON_O_VALUE,
                    ELIP_VALUE2 = :CQCMGRTCOT_N.ELIP_VALUE2,
                    SHAPE_FACTOR = :CQCMGRTCOT_N.SHAPE_FACTOR,
                    GRAIN_SIZE = :CQCMGRTCOT_N.GRAIN_SIZE,
                    CIRCULRARITY = :CQCMGRTCOT_N.CIRCULRARITY,
                    CONVEXITY = :CQCMGRTCOT_N.CONVEXITY,
                    CREATE_USER_ID = :CQCMGRTCOT_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMGRTCOT_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMGRTCOT_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMGRTCOT_N.UPDATE_TIME
                WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
                    AND INSP_ID = :CQCMGRTCOT_N.INSP_ID
                    AND INSP_DTL_TYPE = :CQCMGRTCOT_N.INSP_DTL_TYPE
                    AND INSP_COUNT = :CQCMGRTCOT_N.INSP_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CQCMGRTCOT  set SIZES=:b0,MA_VALUE_1=:b1,\
MA_RESULT=:b2,WT_VALUE_1=:b3,WT_VALUE_2=:b4,WT_VALUE_3=:b5,WT_RESULT=:b6,BD_V\
ALUE_1=:b7,BD_RESULT=:b8,TD_VALUE_1=:b9,TD_RESULT=:b10,PCS_VALUE_1=:b11,PCS_R\
ESULT=:b12,PS_VALUE_1=:b13,PS_VALUE_2=:b14,PS_RESULT=:b15,CM_L=:b16,CM_A=:b17\
,CM_B=:b18,CM_YI=:b19,REMARKS=:b20,COMPAC_VALUE=:b21,ELIP_VALUE=:b22,ROUG_VAL\
UE=:b23,SURFACE_NI=:b24,SURFACE_FE=:b25,SURFACE_CU=:b26,SURFACE_CR=:b27,SURFA\
CE_TI=:b28,SURFACE_MN=:b29,SURFACE_CO=:b30,SURFACE_CA=:b31,SURFACE_MG=:b32,SU\
RFACE_ZN=:b33,SURFACE_MO=:b34,SURFACE_PB=:b35,SURFACE_AL=:b36,SURFACE_SI=:b37\
,SURFACE_B=:b38,SURFACE_NA=:b39,CON_O_VALUE=:b40,ELIP_VALUE2=:b41,SHAPE_FACTO\
R=:b42,GRAIN_SIZE=:b43,CIRCULRARITY=:b44,CONVEXITY=:b45,CREATE_USER_ID=:b46,C\
REATE_TIME=:b47,UPDATE_USER_ID=:b48,UPDATE_TIME=:b49 where (((FACTORY=:b50 an\
d INSP_ID=:b51) and INSP_DTL_TYPE=:b52) and INSP_COUNT=:b53)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )823;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.SIZES);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CQCMGRTCOT_N.MA_VALUE_1);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMGRTCOT_N.MA_RESULT);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_1);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_2);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_3);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMGRTCOT_N.WT_RESULT);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMGRTCOT_N.BD_VALUE_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMGRTCOT_N.BD_RESULT);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CQCMGRTCOT_N.TD_VALUE_1);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CQCMGRTCOT_N.TD_RESULT);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMGRTCOT_N.PCS_VALUE_1);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMGRTCOT_N.PCS_RESULT);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_1);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_2);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMGRTCOT_N.PS_RESULT);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(CQCMGRTCOT_N.CM_L);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CQCMGRTCOT_N.CM_A);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CQCMGRTCOT_N.CM_B);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CQCMGRTCOT_N.CM_YI);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMGRTCOT_N.REMARKS);
            sqlstm.sqhstl[20] = (unsigned int  )301;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CQCMGRTCOT_N.COMPAC_VALUE);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CQCMGRTCOT_N.ROUG_VALUE);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NI);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CQCMGRTCOT_N.SURFACE_FE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CU);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CR);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(CQCMGRTCOT_N.SURFACE_TI);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MN);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CO);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CA);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MG);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(CQCMGRTCOT_N.SURFACE_ZN);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MO);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMGRTCOT_N.SURFACE_PB);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CQCMGRTCOT_N.SURFACE_AL);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMGRTCOT_N.SURFACE_SI);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMGRTCOT_N.SURFACE_B);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NA);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CQCMGRTCOT_N.CON_O_VALUE);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE2);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CQCMGRTCOT_N.SHAPE_FACTOR);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CQCMGRTCOT_N.GRAIN_SIZE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CQCMGRTCOT_N.CIRCULRARITY);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CQCMGRTCOT_N.CONVEXITY);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMGRTCOT_N.CREATE_USER_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMGRTCOT_N.CREATE_TIME);
            sqlstm.sqhstl[47] = (unsigned int  )15;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMGRTCOT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMGRTCOT_N.UPDATE_TIME);
            sqlstm.sqhstl[49] = (unsigned int  )15;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[51] = (unsigned int  )31;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_cqcmgrtcot", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmgrtcot(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMGRTCOT_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    INSP_ID,
                    INSP_DTL_TYPE,
                    INSP_COUNT,
                    SIZES,
                    MA_VALUE_1,
                    MA_RESULT,
                    WT_VALUE_1,
                    WT_VALUE_2,
                    WT_VALUE_3,
                    WT_RESULT,
                    BD_VALUE_1,
                    BD_RESULT,
                    TD_VALUE_1,
                    TD_RESULT,
                    PCS_VALUE_1,
                    PCS_RESULT,
                    PS_VALUE_1,
                    PS_VALUE_2,
                    PS_RESULT,
                    CM_L,
                    CM_A,
                    CM_B,
                    CM_YI,
                    REMARKS,
                    COMPAC_VALUE,
                    ELIP_VALUE,
                    ROUG_VALUE,
                    SURFACE_NI,
                    SURFACE_FE,
                    SURFACE_CU,
                    SURFACE_CR,
                    SURFACE_TI,
                    SURFACE_MN,
                    SURFACE_CO,
                    SURFACE_CA,
                    SURFACE_MG,
                    SURFACE_ZN,
                    SURFACE_MO,
                    SURFACE_PB,
                    SURFACE_AL,
                    SURFACE_SI,
                    SURFACE_B,
                    SURFACE_NA,
                    CON_O_VALUE,
                    ELIP_VALUE2,
                    SHAPE_FACTOR,
                    GRAIN_SIZE,
                    CIRCULRARITY,
                    CONVEXITY,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM CQCMGRTCOT
                ORDER BY FACTORY ASC,
                    INSP_ID ASC,
                    INSP_DTL_TYPE ASC,
                    INSP_COUNT ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMGRTCOT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1054;
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

		case 2:
            /* EXEC SQL DECLARE DBU_CQCMGRTCOT_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    INSP_ID,
                    INSP_DTL_TYPE,
                    INSP_COUNT,
                    SIZES,
                    MA_VALUE_1,
                    MA_RESULT,
                    WT_VALUE_1,
                    WT_VALUE_2,
                    WT_VALUE_3,
                    WT_RESULT,
                    BD_VALUE_1,
                    BD_RESULT,
                    TD_VALUE_1,
                    TD_RESULT,
                    PCS_VALUE_1,
                    PCS_RESULT,
                    PS_VALUE_1,
                    PS_VALUE_2,
                    PS_RESULT,
                    CM_L,
                    CM_A,
                    CM_B,
                    CM_YI,
                    REMARKS,
                    COMPAC_VALUE,
                    ELIP_VALUE,
                    ROUG_VALUE,
                    SURFACE_NI,
                    SURFACE_FE,
                    SURFACE_CU,
                    SURFACE_CR,
                    SURFACE_TI,
                    SURFACE_MN,
                    SURFACE_CO,
                    SURFACE_CA,
                    SURFACE_MG,
                    SURFACE_ZN,
                    SURFACE_MO,
                    SURFACE_PB,
                    SURFACE_AL,
                    SURFACE_SI,
                    SURFACE_B,
                    SURFACE_NA,
                    CON_O_VALUE,
                    ELIP_VALUE2,
                    SHAPE_FACTOR,
                    GRAIN_SIZE,
                    CIRCULRARITY,
                    CONVEXITY,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME
                FROM CQCMGRTCOT
			  WHERE FACTORY = :CQCMGRTCOT_N.FACTORY
			     AND INSP_ID = :CQCMGRTCOT_N.INSP_ID; */ 

            /* EXEC SQL OPEN DBU_CQCMGRTCOT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1069;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_cqcmgrtcot", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmgrtcot(int sel_type, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMGRTCOT_N_TAG CQCMGRTCOT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMGRTCOT_CUR_1 INTO
                :CQCMGRTCOT_N.FACTORY,
                :CQCMGRTCOT_N.INSP_ID,
                :CQCMGRTCOT_N.INSP_DTL_TYPE,
                :CQCMGRTCOT_N.INSP_COUNT,
                :CQCMGRTCOT_N.SIZES,
                :CQCMGRTCOT_N.MA_VALUE_1,
                :CQCMGRTCOT_N.MA_RESULT,
                :CQCMGRTCOT_N.WT_VALUE_1,
                :CQCMGRTCOT_N.WT_VALUE_2,
                :CQCMGRTCOT_N.WT_VALUE_3,
                :CQCMGRTCOT_N.WT_RESULT,
                :CQCMGRTCOT_N.BD_VALUE_1,
                :CQCMGRTCOT_N.BD_RESULT,
                :CQCMGRTCOT_N.TD_VALUE_1,
                :CQCMGRTCOT_N.TD_RESULT,
                :CQCMGRTCOT_N.PCS_VALUE_1,
                :CQCMGRTCOT_N.PCS_RESULT,
                :CQCMGRTCOT_N.PS_VALUE_1,
                :CQCMGRTCOT_N.PS_VALUE_2,
                :CQCMGRTCOT_N.PS_RESULT,
                :CQCMGRTCOT_N.CM_L,
                :CQCMGRTCOT_N.CM_A,
                :CQCMGRTCOT_N.CM_B,
                :CQCMGRTCOT_N.CM_YI,
                :CQCMGRTCOT_N.REMARKS,
                :CQCMGRTCOT_N.COMPAC_VALUE,
                :CQCMGRTCOT_N.ELIP_VALUE,
                :CQCMGRTCOT_N.ROUG_VALUE,
                :CQCMGRTCOT_N.SURFACE_NI,
                :CQCMGRTCOT_N.SURFACE_FE,
                :CQCMGRTCOT_N.SURFACE_CU,
                :CQCMGRTCOT_N.SURFACE_CR,
                :CQCMGRTCOT_N.SURFACE_TI,
                :CQCMGRTCOT_N.SURFACE_MN,
                :CQCMGRTCOT_N.SURFACE_CO,
                :CQCMGRTCOT_N.SURFACE_CA,
                :CQCMGRTCOT_N.SURFACE_MG,
                :CQCMGRTCOT_N.SURFACE_ZN,
                :CQCMGRTCOT_N.SURFACE_MO,
                :CQCMGRTCOT_N.SURFACE_PB,
                :CQCMGRTCOT_N.SURFACE_AL,
                :CQCMGRTCOT_N.SURFACE_SI,
                :CQCMGRTCOT_N.SURFACE_B,
                :CQCMGRTCOT_N.SURFACE_NA,
                :CQCMGRTCOT_N.CON_O_VALUE,
                :CQCMGRTCOT_N.ELIP_VALUE2,
                :CQCMGRTCOT_N.SHAPE_FACTOR,
                :CQCMGRTCOT_N.GRAIN_SIZE,
                :CQCMGRTCOT_N.CIRCULRARITY,
                :CQCMGRTCOT_N.CONVEXITY,
                :CQCMGRTCOT_N.CREATE_USER_ID,
                :CQCMGRTCOT_N.CREATE_TIME,
                :CQCMGRTCOT_N.UPDATE_USER_ID,
                :CQCMGRTCOT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1092;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMGRTCOT_N.SIZES);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMGRTCOT_N.MA_VALUE_1);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMGRTCOT_N.MA_RESULT);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CQCMGRTCOT_N.WT_RESULT);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMGRTCOT_N.BD_VALUE_1);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMGRTCOT_N.BD_RESULT);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMGRTCOT_N.TD_VALUE_1);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMGRTCOT_N.TD_RESULT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMGRTCOT_N.PCS_VALUE_1);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(CQCMGRTCOT_N.PCS_RESULT);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_1);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CQCMGRTCOT_N.PS_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CQCMGRTCOT_N.CM_L);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CQCMGRTCOT_N.CM_A);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CQCMGRTCOT_N.CM_B);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CQCMGRTCOT_N.CM_YI);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMGRTCOT_N.REMARKS);
            sqlstm.sqhstl[24] = (unsigned int  )301;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CQCMGRTCOT_N.COMPAC_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CQCMGRTCOT_N.ROUG_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NI);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CQCMGRTCOT_N.SURFACE_FE);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CU);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CR);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CQCMGRTCOT_N.SURFACE_TI);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MN);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CO);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CA);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MG);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMGRTCOT_N.SURFACE_ZN);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MO);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CQCMGRTCOT_N.SURFACE_PB);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CQCMGRTCOT_N.SURFACE_AL);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CQCMGRTCOT_N.SURFACE_SI);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CQCMGRTCOT_N.SURFACE_B);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NA);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CQCMGRTCOT_N.CON_O_VALUE);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE2);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CQCMGRTCOT_N.SHAPE_FACTOR);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CQCMGRTCOT_N.GRAIN_SIZE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CQCMGRTCOT_N.CIRCULRARITY);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CQCMGRTCOT_N.CONVEXITY);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMGRTCOT_N.CREATE_USER_ID);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMGRTCOT_N.CREATE_TIME);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMGRTCOT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMGRTCOT_N.UPDATE_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_CQCMGRTCOT_CUR_2 INTO
                :CQCMGRTCOT_N.FACTORY,
                :CQCMGRTCOT_N.INSP_ID,
                :CQCMGRTCOT_N.INSP_DTL_TYPE,
                :CQCMGRTCOT_N.INSP_COUNT,
                :CQCMGRTCOT_N.SIZES,
                :CQCMGRTCOT_N.MA_VALUE_1,
                :CQCMGRTCOT_N.MA_RESULT,
                :CQCMGRTCOT_N.WT_VALUE_1,
                :CQCMGRTCOT_N.WT_VALUE_2,
                :CQCMGRTCOT_N.WT_VALUE_3,
                :CQCMGRTCOT_N.WT_RESULT,
                :CQCMGRTCOT_N.BD_VALUE_1,
                :CQCMGRTCOT_N.BD_RESULT,
                :CQCMGRTCOT_N.TD_VALUE_1,
                :CQCMGRTCOT_N.TD_RESULT,
                :CQCMGRTCOT_N.PCS_VALUE_1,
                :CQCMGRTCOT_N.PCS_RESULT,
                :CQCMGRTCOT_N.PS_VALUE_1,
                :CQCMGRTCOT_N.PS_VALUE_2,
                :CQCMGRTCOT_N.PS_RESULT,
                :CQCMGRTCOT_N.CM_L,
                :CQCMGRTCOT_N.CM_A,
                :CQCMGRTCOT_N.CM_B,
                :CQCMGRTCOT_N.CM_YI,
                :CQCMGRTCOT_N.REMARKS,
                :CQCMGRTCOT_N.COMPAC_VALUE,
                :CQCMGRTCOT_N.ELIP_VALUE,
                :CQCMGRTCOT_N.ROUG_VALUE,
                :CQCMGRTCOT_N.SURFACE_NI,
                :CQCMGRTCOT_N.SURFACE_FE,
                :CQCMGRTCOT_N.SURFACE_CU,
                :CQCMGRTCOT_N.SURFACE_CR,
                :CQCMGRTCOT_N.SURFACE_TI,
                :CQCMGRTCOT_N.SURFACE_MN,
                :CQCMGRTCOT_N.SURFACE_CO,
                :CQCMGRTCOT_N.SURFACE_CA,
                :CQCMGRTCOT_N.SURFACE_MG,
                :CQCMGRTCOT_N.SURFACE_ZN,
                :CQCMGRTCOT_N.SURFACE_MO,
                :CQCMGRTCOT_N.SURFACE_PB,
                :CQCMGRTCOT_N.SURFACE_AL,
                :CQCMGRTCOT_N.SURFACE_SI,
                :CQCMGRTCOT_N.SURFACE_B,
                :CQCMGRTCOT_N.SURFACE_NA,
                :CQCMGRTCOT_N.CON_O_VALUE,
                :CQCMGRTCOT_N.ELIP_VALUE2,
                :CQCMGRTCOT_N.SHAPE_FACTOR,
                :CQCMGRTCOT_N.GRAIN_SIZE,
                :CQCMGRTCOT_N.CIRCULRARITY,
                :CQCMGRTCOT_N.CONVEXITY,
                :CQCMGRTCOT_N.CREATE_USER_ID,
                :CQCMGRTCOT_N.CREATE_TIME,
                :CQCMGRTCOT_N.UPDATE_USER_ID,
                :CQCMGRTCOT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1323;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMGRTCOT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMGRTCOT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMGRTCOT_N.INSP_DTL_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMGRTCOT_N.INSP_COUNT);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMGRTCOT_N.SIZES);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMGRTCOT_N.MA_VALUE_1);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMGRTCOT_N.MA_RESULT);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CQCMGRTCOT_N.WT_VALUE_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CQCMGRTCOT_N.WT_RESULT);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMGRTCOT_N.BD_VALUE_1);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(CQCMGRTCOT_N.BD_RESULT);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(CQCMGRTCOT_N.TD_VALUE_1);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CQCMGRTCOT_N.TD_RESULT);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(CQCMGRTCOT_N.PCS_VALUE_1);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(CQCMGRTCOT_N.PCS_RESULT);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_1);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(CQCMGRTCOT_N.PS_VALUE_2);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(CQCMGRTCOT_N.PS_RESULT);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(CQCMGRTCOT_N.CM_L);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(CQCMGRTCOT_N.CM_A);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(CQCMGRTCOT_N.CM_B);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(CQCMGRTCOT_N.CM_YI);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMGRTCOT_N.REMARKS);
            sqlstm.sqhstl[24] = (unsigned int  )301;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(CQCMGRTCOT_N.COMPAC_VALUE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(CQCMGRTCOT_N.ROUG_VALUE);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NI);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CQCMGRTCOT_N.SURFACE_FE);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CU);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CR);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(CQCMGRTCOT_N.SURFACE_TI);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MN);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CO);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMGRTCOT_N.SURFACE_CA);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MG);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMGRTCOT_N.SURFACE_ZN);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMGRTCOT_N.SURFACE_MO);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CQCMGRTCOT_N.SURFACE_PB);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(CQCMGRTCOT_N.SURFACE_AL);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(CQCMGRTCOT_N.SURFACE_SI);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(CQCMGRTCOT_N.SURFACE_B);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(CQCMGRTCOT_N.SURFACE_NA);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(CQCMGRTCOT_N.CON_O_VALUE);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(CQCMGRTCOT_N.ELIP_VALUE2);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(CQCMGRTCOT_N.SHAPE_FACTOR);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(CQCMGRTCOT_N.GRAIN_SIZE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(CQCMGRTCOT_N.CIRCULRARITY);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(CQCMGRTCOT_N.CONVEXITY);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMGRTCOT_N.CREATE_USER_ID);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMGRTCOT_N.CREATE_TIME);
            sqlstm.sqhstl[51] = (unsigned int  )15;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMGRTCOT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMGRTCOT_N.UPDATE_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
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
        DBU_del_null_cqcmgrtcot(&CQCMGRTCOT_N, CQCMGRTCOT);
    }

    DB_stop_query_timer("DBU_fetch_cqcmgrtcot", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmgrtcot(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMGRTCOT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1554;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL CLOSE DBU_CQCMGRTCOT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 58;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1569;
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

    DB_stop_query_timer("DBU_close_cqcmgrtcot", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmgrtcot(struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* memset by Space */
    memset(CQCMGRTCOT, ' ', sizeof(struct CQCMGRTCOT_TAG));
    
    CQCMGRTCOT->INSP_COUNT = 0;
    CQCMGRTCOT->MA_VALUE_1 = 0;
    CQCMGRTCOT->MA_RESULT = 0;
    CQCMGRTCOT->WT_VALUE_1 = 0;
    CQCMGRTCOT->WT_VALUE_2 = 0;
    CQCMGRTCOT->WT_VALUE_3 = 0;
    CQCMGRTCOT->WT_RESULT = 0;
    CQCMGRTCOT->BD_VALUE_1 = 0;
    CQCMGRTCOT->BD_RESULT = 0;
    CQCMGRTCOT->TD_VALUE_1 = 0;
    CQCMGRTCOT->TD_RESULT = 0;
    CQCMGRTCOT->PCS_VALUE_1 = 0;
    CQCMGRTCOT->PCS_RESULT = 0;
    CQCMGRTCOT->PS_VALUE_1 = 0;
    CQCMGRTCOT->PS_VALUE_2 = 0;
    CQCMGRTCOT->PS_RESULT = 0;
    CQCMGRTCOT->CM_L = 0;
    CQCMGRTCOT->CM_A = 0;
    CQCMGRTCOT->CM_B = 0;
    CQCMGRTCOT->CM_YI = 0;
    CQCMGRTCOT->COMPAC_VALUE = 0;
    CQCMGRTCOT->ELIP_VALUE = 0;
    CQCMGRTCOT->ROUG_VALUE = 0;
    CQCMGRTCOT->SURFACE_NI = 0;
    CQCMGRTCOT->SURFACE_FE = 0;
    CQCMGRTCOT->SURFACE_CU = 0;
    CQCMGRTCOT->SURFACE_CR = 0;
    CQCMGRTCOT->SURFACE_TI = 0;
    CQCMGRTCOT->SURFACE_MN = 0;
    CQCMGRTCOT->SURFACE_CO = 0;
    CQCMGRTCOT->SURFACE_CA = 0;
    CQCMGRTCOT->SURFACE_MG = 0;
    CQCMGRTCOT->SURFACE_ZN = 0;
    CQCMGRTCOT->SURFACE_MO = 0;
    CQCMGRTCOT->SURFACE_PB = 0;
    CQCMGRTCOT->SURFACE_AL = 0;
    CQCMGRTCOT->SURFACE_SI = 0;
    CQCMGRTCOT->SURFACE_B = 0;
    CQCMGRTCOT->SURFACE_NA = 0;
    CQCMGRTCOT->CON_O_VALUE = 0;
    CQCMGRTCOT->ELIP_VALUE2 = 0;
    CQCMGRTCOT->SHAPE_FACTOR = 0;
    CQCMGRTCOT->GRAIN_SIZE = 0;
    CQCMGRTCOT->CIRCULRARITY = 0;
    CQCMGRTCOT->CONVEXITY = 0;
}


/* Add Null Function */
void DBU_add_null_cqcmgrtcot(struct CQCMGRTCOT_N_TAG *CQCMGRTCOT_N, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    /* memset by NULL */
    memset(CQCMGRTCOT_N, '\0', sizeof(struct CQCMGRTCOT_N_TAG));
    
    MEMCPY_AN(CQCMGRTCOT_N->FACTORY, CQCMGRTCOT->FACTORY, sizeof(CQCMGRTCOT->FACTORY));
    MEMCPY_AN(CQCMGRTCOT_N->INSP_ID, CQCMGRTCOT->INSP_ID, sizeof(CQCMGRTCOT->INSP_ID));
    MEMCPY_AN(CQCMGRTCOT_N->INSP_DTL_TYPE, CQCMGRTCOT->INSP_DTL_TYPE, sizeof(CQCMGRTCOT->INSP_DTL_TYPE));
    CQCMGRTCOT_N->INSP_COUNT = CQCMGRTCOT->INSP_COUNT;
    MEMCPY_AN(CQCMGRTCOT_N->SIZES, CQCMGRTCOT->SIZES, sizeof(CQCMGRTCOT->SIZES));
    CQCMGRTCOT_N->MA_VALUE_1 = CQCMGRTCOT->MA_VALUE_1;
    CQCMGRTCOT_N->MA_RESULT = CQCMGRTCOT->MA_RESULT;
    CQCMGRTCOT_N->WT_VALUE_1 = CQCMGRTCOT->WT_VALUE_1;
    CQCMGRTCOT_N->WT_VALUE_2 = CQCMGRTCOT->WT_VALUE_2;
    CQCMGRTCOT_N->WT_VALUE_3 = CQCMGRTCOT->WT_VALUE_3;
    CQCMGRTCOT_N->WT_RESULT = CQCMGRTCOT->WT_RESULT;
    CQCMGRTCOT_N->BD_VALUE_1 = CQCMGRTCOT->BD_VALUE_1;
    CQCMGRTCOT_N->BD_RESULT = CQCMGRTCOT->BD_RESULT;
    CQCMGRTCOT_N->TD_VALUE_1 = CQCMGRTCOT->TD_VALUE_1;
    CQCMGRTCOT_N->TD_RESULT = CQCMGRTCOT->TD_RESULT;
    CQCMGRTCOT_N->PCS_VALUE_1 = CQCMGRTCOT->PCS_VALUE_1;
    CQCMGRTCOT_N->PCS_RESULT = CQCMGRTCOT->PCS_RESULT;
    CQCMGRTCOT_N->PS_VALUE_1 = CQCMGRTCOT->PS_VALUE_1;
    CQCMGRTCOT_N->PS_VALUE_2 = CQCMGRTCOT->PS_VALUE_2;
    CQCMGRTCOT_N->PS_RESULT = CQCMGRTCOT->PS_RESULT;
    CQCMGRTCOT_N->CM_L = CQCMGRTCOT->CM_L;
    CQCMGRTCOT_N->CM_A = CQCMGRTCOT->CM_A;
    CQCMGRTCOT_N->CM_B = CQCMGRTCOT->CM_B;
    CQCMGRTCOT_N->CM_YI = CQCMGRTCOT->CM_YI;
    MEMCPY_AN(CQCMGRTCOT_N->REMARKS, CQCMGRTCOT->REMARKS, sizeof(CQCMGRTCOT->REMARKS));
    CQCMGRTCOT_N->COMPAC_VALUE = CQCMGRTCOT->COMPAC_VALUE;
    CQCMGRTCOT_N->ELIP_VALUE = CQCMGRTCOT->ELIP_VALUE;
    CQCMGRTCOT_N->ROUG_VALUE = CQCMGRTCOT->ROUG_VALUE;
    CQCMGRTCOT_N->SURFACE_NI = CQCMGRTCOT->SURFACE_NI;
    CQCMGRTCOT_N->SURFACE_FE = CQCMGRTCOT->SURFACE_FE;
    CQCMGRTCOT_N->SURFACE_CU = CQCMGRTCOT->SURFACE_CU;
    CQCMGRTCOT_N->SURFACE_CR = CQCMGRTCOT->SURFACE_CR;
    CQCMGRTCOT_N->SURFACE_TI = CQCMGRTCOT->SURFACE_TI;
    CQCMGRTCOT_N->SURFACE_MN = CQCMGRTCOT->SURFACE_MN;
    CQCMGRTCOT_N->SURFACE_CO = CQCMGRTCOT->SURFACE_CO;
    CQCMGRTCOT_N->SURFACE_CA = CQCMGRTCOT->SURFACE_CA;
    CQCMGRTCOT_N->SURFACE_MG = CQCMGRTCOT->SURFACE_MG;
    CQCMGRTCOT_N->SURFACE_ZN = CQCMGRTCOT->SURFACE_ZN;
    CQCMGRTCOT_N->SURFACE_MO = CQCMGRTCOT->SURFACE_MO;
    CQCMGRTCOT_N->SURFACE_PB = CQCMGRTCOT->SURFACE_PB;
    CQCMGRTCOT_N->SURFACE_AL = CQCMGRTCOT->SURFACE_AL;
    CQCMGRTCOT_N->SURFACE_SI = CQCMGRTCOT->SURFACE_SI;
    CQCMGRTCOT_N->SURFACE_B = CQCMGRTCOT->SURFACE_B;
    CQCMGRTCOT_N->SURFACE_NA = CQCMGRTCOT->SURFACE_NA;
    CQCMGRTCOT_N->CON_O_VALUE = CQCMGRTCOT->CON_O_VALUE;
    CQCMGRTCOT_N->ELIP_VALUE2 = CQCMGRTCOT->ELIP_VALUE2;
    CQCMGRTCOT_N->SHAPE_FACTOR = CQCMGRTCOT->SHAPE_FACTOR;
    CQCMGRTCOT_N->GRAIN_SIZE = CQCMGRTCOT->GRAIN_SIZE;
    CQCMGRTCOT_N->CIRCULRARITY = CQCMGRTCOT->CIRCULRARITY;
    CQCMGRTCOT_N->CONVEXITY = CQCMGRTCOT->CONVEXITY;
    MEMCPY_AN(CQCMGRTCOT_N->CREATE_USER_ID, CQCMGRTCOT->CREATE_USER_ID, sizeof(CQCMGRTCOT->CREATE_USER_ID));
    MEMCPY_AN(CQCMGRTCOT_N->CREATE_TIME, CQCMGRTCOT->CREATE_TIME, sizeof(CQCMGRTCOT->CREATE_TIME));
    MEMCPY_AN(CQCMGRTCOT_N->UPDATE_USER_ID, CQCMGRTCOT->UPDATE_USER_ID, sizeof(CQCMGRTCOT->UPDATE_USER_ID));
    MEMCPY_AN(CQCMGRTCOT_N->UPDATE_TIME, CQCMGRTCOT->UPDATE_TIME, sizeof(CQCMGRTCOT->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cqcmgrtcot(struct CQCMGRTCOT_N_TAG *CQCMGRTCOT_N, struct CQCMGRTCOT_TAG *CQCMGRTCOT)
{
    MEMCPY_DN(CQCMGRTCOT->FACTORY, CQCMGRTCOT_N->FACTORY, sizeof(CQCMGRTCOT->FACTORY));
    MEMCPY_DN(CQCMGRTCOT->INSP_ID, CQCMGRTCOT_N->INSP_ID, sizeof(CQCMGRTCOT->INSP_ID));
    MEMCPY_DN(CQCMGRTCOT->INSP_DTL_TYPE, CQCMGRTCOT_N->INSP_DTL_TYPE, sizeof(CQCMGRTCOT->INSP_DTL_TYPE));
    CQCMGRTCOT->INSP_COUNT = CQCMGRTCOT_N->INSP_COUNT;
    MEMCPY_DN(CQCMGRTCOT->SIZES, CQCMGRTCOT_N->SIZES, sizeof(CQCMGRTCOT->SIZES));
    CQCMGRTCOT->MA_VALUE_1 = CQCMGRTCOT_N->MA_VALUE_1;
    CQCMGRTCOT->MA_RESULT = CQCMGRTCOT_N->MA_RESULT;
    CQCMGRTCOT->WT_VALUE_1 = CQCMGRTCOT_N->WT_VALUE_1;
    CQCMGRTCOT->WT_VALUE_2 = CQCMGRTCOT_N->WT_VALUE_2;
    CQCMGRTCOT->WT_VALUE_3 = CQCMGRTCOT_N->WT_VALUE_3;
    CQCMGRTCOT->WT_RESULT = CQCMGRTCOT_N->WT_RESULT;
    CQCMGRTCOT->BD_VALUE_1 = CQCMGRTCOT_N->BD_VALUE_1;
    CQCMGRTCOT->BD_RESULT = CQCMGRTCOT_N->BD_RESULT;
    CQCMGRTCOT->TD_VALUE_1 = CQCMGRTCOT_N->TD_VALUE_1;
    CQCMGRTCOT->TD_RESULT = CQCMGRTCOT_N->TD_RESULT;
    CQCMGRTCOT->PCS_VALUE_1 = CQCMGRTCOT_N->PCS_VALUE_1;
    CQCMGRTCOT->PCS_RESULT = CQCMGRTCOT_N->PCS_RESULT;
    CQCMGRTCOT->PS_VALUE_1 = CQCMGRTCOT_N->PS_VALUE_1;
    CQCMGRTCOT->PS_VALUE_2 = CQCMGRTCOT_N->PS_VALUE_2;
    CQCMGRTCOT->PS_RESULT = CQCMGRTCOT_N->PS_RESULT;
    CQCMGRTCOT->CM_L = CQCMGRTCOT_N->CM_L;
    CQCMGRTCOT->CM_A = CQCMGRTCOT_N->CM_A;
    CQCMGRTCOT->CM_B = CQCMGRTCOT_N->CM_B;
    CQCMGRTCOT->CM_YI = CQCMGRTCOT_N->CM_YI;
    MEMCPY_DN(CQCMGRTCOT->REMARKS, CQCMGRTCOT_N->REMARKS, sizeof(CQCMGRTCOT->REMARKS));
    CQCMGRTCOT->COMPAC_VALUE = CQCMGRTCOT_N->COMPAC_VALUE;
    CQCMGRTCOT->ELIP_VALUE = CQCMGRTCOT_N->ELIP_VALUE;
    CQCMGRTCOT->ROUG_VALUE = CQCMGRTCOT_N->ROUG_VALUE;
    CQCMGRTCOT->SURFACE_NI = CQCMGRTCOT_N->SURFACE_NI;
    CQCMGRTCOT->SURFACE_FE = CQCMGRTCOT_N->SURFACE_FE;
    CQCMGRTCOT->SURFACE_CU = CQCMGRTCOT_N->SURFACE_CU;
    CQCMGRTCOT->SURFACE_CR = CQCMGRTCOT_N->SURFACE_CR;
    CQCMGRTCOT->SURFACE_TI = CQCMGRTCOT_N->SURFACE_TI;
    CQCMGRTCOT->SURFACE_MN = CQCMGRTCOT_N->SURFACE_MN;
    CQCMGRTCOT->SURFACE_CO = CQCMGRTCOT_N->SURFACE_CO;
    CQCMGRTCOT->SURFACE_CA = CQCMGRTCOT_N->SURFACE_CA;
    CQCMGRTCOT->SURFACE_MG = CQCMGRTCOT_N->SURFACE_MG;
    CQCMGRTCOT->SURFACE_ZN = CQCMGRTCOT_N->SURFACE_ZN;
    CQCMGRTCOT->SURFACE_MO = CQCMGRTCOT_N->SURFACE_MO;
    CQCMGRTCOT->SURFACE_PB = CQCMGRTCOT_N->SURFACE_PB;
    CQCMGRTCOT->SURFACE_AL = CQCMGRTCOT_N->SURFACE_AL;
    CQCMGRTCOT->SURFACE_SI = CQCMGRTCOT_N->SURFACE_SI;
    CQCMGRTCOT->SURFACE_B = CQCMGRTCOT_N->SURFACE_B;
    CQCMGRTCOT->SURFACE_NA = CQCMGRTCOT_N->SURFACE_NA;
    CQCMGRTCOT->CON_O_VALUE = CQCMGRTCOT_N->CON_O_VALUE;
    CQCMGRTCOT->ELIP_VALUE2 = CQCMGRTCOT_N->ELIP_VALUE2;
    CQCMGRTCOT->SHAPE_FACTOR = CQCMGRTCOT_N->SHAPE_FACTOR;
    CQCMGRTCOT->GRAIN_SIZE = CQCMGRTCOT_N->GRAIN_SIZE;
    CQCMGRTCOT->CIRCULRARITY = CQCMGRTCOT_N->CIRCULRARITY;
    CQCMGRTCOT->CONVEXITY = CQCMGRTCOT_N->CONVEXITY;
    MEMCPY_DN(CQCMGRTCOT->CREATE_USER_ID, CQCMGRTCOT_N->CREATE_USER_ID, sizeof(CQCMGRTCOT->CREATE_USER_ID));
    MEMCPY_DN(CQCMGRTCOT->CREATE_TIME, CQCMGRTCOT_N->CREATE_TIME, sizeof(CQCMGRTCOT->CREATE_TIME));
    MEMCPY_DN(CQCMGRTCOT->UPDATE_USER_ID, CQCMGRTCOT_N->UPDATE_USER_ID, sizeof(CQCMGRTCOT->UPDATE_USER_ID));
    MEMCPY_DN(CQCMGRTCOT->UPDATE_TIME, CQCMGRTCOT_N->UPDATE_TIME, sizeof(CQCMGRTCOT->UPDATE_TIME));
}


