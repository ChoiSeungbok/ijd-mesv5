
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
    "DBU_medclotdat.pc"
};


static unsigned int sqlctx = 9389899;


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
            void  *sqhstv[67];
   unsigned int   sqhstl[67];
            int   sqhsts[67];
            void  *sqindv[67];
            int   sqinds[67];
   unsigned int   sqharm[67];
   unsigned int   *sqharc[67];
   unsigned short  sqadto[67];
   unsigned short  sqtdso[67];
} sqlstm = {13,67};

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

 static const char *sq0010 = 
"select LOT_ID ,HIST_SEQ ,COL_SEQ ,TRAN_TIME ,HIST_DEL_FLAG ,FACTORY ,MAT_ID\
 ,MAT_VER ,FLOW ,OPER ,MEAS_RES_ID ,PROC_FLOW ,PROC_OPER ,PROC_RES_ID ,RECIPE\
_ID ,RECIPE_VERSION ,COL_SET_ID ,COL_SET_VERSION ,CHAR_SEQ_NUM ,CHAR_ID ,UNIT\
_SEQ_NUM ,UNIT_ID ,VALUE_SEQ_NUM ,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,\
VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALU\
E_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,V\
ALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_C\
OUNT ,NOMINAL ,PROCESS_SIGMA ,SPEC_OUT_MASK ,CREATE_USER_ID ,CREATE_TIME ,UPD\
ATE_USER_ID ,UPDATE_TIME ,DELETE_USER_ID ,DELETE_TIME  from MEDCLOTDAT  order\
 by LOT_ID asc ,HIST_SEQ asc ,COL_SEQ asc ,COL_SET_ID asc ,CHAR_SEQ_NUM asc ,\
UNIT_SEQ_NUM asc ,VALUE_SEQ_NUM asc             ";

 static const char *sq0011 = 
"select LOT_ID ,HIST_SEQ ,COL_SEQ ,TRAN_TIME ,HIST_DEL_FLAG ,FACTORY ,MAT_ID\
 ,MAT_VER ,FLOW ,OPER ,MEAS_RES_ID ,PROC_FLOW ,PROC_OPER ,PROC_RES_ID ,RECIPE\
_ID ,RECIPE_VERSION ,COL_SET_ID ,COL_SET_VERSION ,CHAR_SEQ_NUM ,CHAR_ID ,UNIT\
_SEQ_NUM ,UNIT_ID ,VALUE_SEQ_NUM ,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,\
VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALU\
E_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,V\
ALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_C\
OUNT ,NOMINAL ,PROCESS_SIGMA ,SPEC_OUT_MASK ,CREATE_USER_ID ,CREATE_TIME ,UPD\
ATE_USER_ID ,UPDATE_TIME ,DELETE_USER_ID ,DELETE_TIME  from MEDCLOTDAT A wher\
e (((LOT_ID=:b0 and COL_SET_ID=(select COL_SET_ID  from MEDCCOLDEF where COL_\
CMF_2='A')) and TRAN_TIME=(select max(TRAN_TIME)  from MEDCLOTDAT where ((FAC\
TORY=A.FACTORY and LOT_ID=A.LOT_ID) and COL_SET_ID=A.COL_SET_ID))) and CHAR_I\
D in ('ALL-T','FLAT','MAX-D','REAL-D')) order by A.CHAR_SEQ_NUM            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1128,0,4,46,0,0,67,7,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
288,0,0,2,1140,0,4,212,0,0,67,7,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
571,0,0,3,187,0,4,381,0,0,8,7,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,
618,0,0,4,140,0,4,394,0,0,6,5,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,3,0,0,
657,0,0,5,173,0,4,405,0,0,6,5,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,
696,0,0,6,207,0,4,417,0,0,6,5,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,
735,0,0,7,169,0,2,459,0,0,7,7,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,
778,0,0,8,925,0,3,494,0,0,60,60,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,
1033,0,0,9,956,0,5,639,0,0,60,60,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,
1288,0,0,10,816,0,9,800,0,0,0,0,0,1,0,
1303,0,0,11,997,0,9,875,0,0,1,1,0,1,0,1,97,0,0,
1322,0,0,10,0,0,13,903,0,0,60,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,
1577,0,0,11,0,0,13,967,0,0,60,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,
1832,0,0,10,0,0,15,1056,0,0,0,0,0,1,0,
1847,0,0,11,0,0,15,1060,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_medclotdat.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-09-08 16:46:46
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
void DBU_add_null_medclotdat(struct MEDCLOTDAT_N_TAG *MEDCLOTDAT_N, struct MEDCLOTDAT_TAG *MEDCLOTDAT);
void DBU_del_null_medclotdat(struct MEDCLOTDAT_N_TAG *MEDCLOTDAT_N, struct MEDCLOTDAT_TAG *MEDCLOTDAT);


/* SQL SELECT Function */
void DBU_select_medclotdat(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    LOT_ID,
                    HIST_SEQ,
                    COL_SEQ,
                    TRAN_TIME,
                    HIST_DEL_FLAG,
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    MEAS_RES_ID,
                    PROC_FLOW,
                    PROC_OPER,
                    PROC_RES_ID,
                    RECIPE_ID,
                    RECIPE_VERSION,
                    COL_SET_ID,
                    COL_SET_VERSION,
                    CHAR_SEQ_NUM,
                    CHAR_ID,
                    UNIT_SEQ_NUM,
                    UNIT_ID,
                    VALUE_SEQ_NUM,
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
                    NOMINAL,
                    PROCESS_SIGMA,
                    SPEC_OUT_MASK,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    DELETE_USER_ID,
                    DELETE_TIME
                INTO 
                    :MEDCLOTDAT_N.LOT_ID,
                    :MEDCLOTDAT_N.HIST_SEQ,
                    :MEDCLOTDAT_N.COL_SEQ,
                    :MEDCLOTDAT_N.TRAN_TIME,
                    :MEDCLOTDAT_N.HIST_DEL_FLAG,
                    :MEDCLOTDAT_N.FACTORY,
                    :MEDCLOTDAT_N.MAT_ID,
                    :MEDCLOTDAT_N.MAT_VER,
                    :MEDCLOTDAT_N.FLOW,
                    :MEDCLOTDAT_N.OPER,
                    :MEDCLOTDAT_N.MEAS_RES_ID,
                    :MEDCLOTDAT_N.PROC_FLOW,
                    :MEDCLOTDAT_N.PROC_OPER,
                    :MEDCLOTDAT_N.PROC_RES_ID,
                    :MEDCLOTDAT_N.RECIPE_ID,
                    :MEDCLOTDAT_N.RECIPE_VERSION,
                    :MEDCLOTDAT_N.COL_SET_ID,
                    :MEDCLOTDAT_N.COL_SET_VERSION,
                    :MEDCLOTDAT_N.CHAR_SEQ_NUM,
                    :MEDCLOTDAT_N.CHAR_ID,
                    :MEDCLOTDAT_N.UNIT_SEQ_NUM,
                    :MEDCLOTDAT_N.UNIT_ID,
                    :MEDCLOTDAT_N.VALUE_SEQ_NUM,
                    :MEDCLOTDAT_N.VALUE_TYPE,
                    :MEDCLOTDAT_N.VALUE_COUNT,
                    :MEDCLOTDAT_N.VALUE_1,
                    :MEDCLOTDAT_N.VALUE_2,
                    :MEDCLOTDAT_N.VALUE_3,
                    :MEDCLOTDAT_N.VALUE_4,
                    :MEDCLOTDAT_N.VALUE_5,
                    :MEDCLOTDAT_N.VALUE_6,
                    :MEDCLOTDAT_N.VALUE_7,
                    :MEDCLOTDAT_N.VALUE_8,
                    :MEDCLOTDAT_N.VALUE_9,
                    :MEDCLOTDAT_N.VALUE_10,
                    :MEDCLOTDAT_N.VALUE_11,
                    :MEDCLOTDAT_N.VALUE_12,
                    :MEDCLOTDAT_N.VALUE_13,
                    :MEDCLOTDAT_N.VALUE_14,
                    :MEDCLOTDAT_N.VALUE_15,
                    :MEDCLOTDAT_N.VALUE_16,
                    :MEDCLOTDAT_N.VALUE_17,
                    :MEDCLOTDAT_N.VALUE_18,
                    :MEDCLOTDAT_N.VALUE_19,
                    :MEDCLOTDAT_N.VALUE_20,
                    :MEDCLOTDAT_N.VALUE_21,
                    :MEDCLOTDAT_N.VALUE_22,
                    :MEDCLOTDAT_N.VALUE_23,
                    :MEDCLOTDAT_N.VALUE_24,
                    :MEDCLOTDAT_N.VALUE_25,
                    :MEDCLOTDAT_N.SAMPLE_COUNT,
                    :MEDCLOTDAT_N.NOMINAL,
                    :MEDCLOTDAT_N.PROCESS_SIGMA,
                    :MEDCLOTDAT_N.SPEC_OUT_MASK,
                    :MEDCLOTDAT_N.CREATE_USER_ID,
                    :MEDCLOTDAT_N.CREATE_TIME,
                    :MEDCLOTDAT_N.UPDATE_USER_ID,
                    :MEDCLOTDAT_N.UPDATE_TIME,
                    :MEDCLOTDAT_N.DELETE_USER_ID,
                    :MEDCLOTDAT_N.DELETE_TIME
                FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                    AND HIST_SEQ = :MEDCLOTDAT_N.HIST_SEQ
                    AND COL_SEQ = :MEDCLOTDAT_N.COL_SEQ
                    AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                    AND CHAR_SEQ_NUM = :MEDCLOTDAT_N.CHAR_SEQ_NUM
                    AND UNIT_SEQ_NUM = :MEDCLOTDAT_N.UNIT_SEQ_NUM
                    AND VALUE_SEQ_NUM = :MEDCLOTDAT_N.VALUE_SEQ_NUM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,COL_SEQ ,TRAN_TIME ,HIST_DEL_FLAG ,F\
ACTORY ,MAT_ID ,MAT_VER ,FLOW ,OPER ,MEAS_RES_ID ,PROC_FLOW ,PROC_OPER ,PROC\
_RES_ID ,RECIPE_ID ,RECIPE_VERSION ,COL_SET_ID ,COL_SET_VERSION ,CHAR_SEQ_NU\
M ,CHAR_ID ,UNIT_SEQ_NUM ,UNIT_ID ,VALUE_SEQ_NUM ,VALUE_TYPE ,VALUE_COUNT ,V\
ALUE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE\
_9 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VA\
LUE_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24\
 ,VALUE_25 ,SAMPLE_COUNT ,NOMINAL ,PROCESS_SIGMA ,SPEC_OUT_MASK ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,DELETE_USER_ID ,DELETE_TIME i\
nto :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b\
16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b3\
1,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46\
,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59  from MEDC\
LOTDAT where ((((((LOT_ID=:b0 and HIST_SEQ=:b1) and");
            sqlstm.stmt = " COL_SEQ=:b2) and COL_SET_ID=:b16) and CHAR_SEQ_\
NUM=:b18) and UNIT_SEQ_NUM=:b20) and VALUE_SEQ_NUM=:b22)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCLOTDAT_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MEDCLOTDAT_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCLOTDAT_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCLOTDAT_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCLOTDAT_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCLOTDAT_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCLOTDAT_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCLOTDAT_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MEDCLOTDAT_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCLOTDAT_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCLOTDAT_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCLOTDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MEDCLOTDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCLOTDAT_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCLOTDAT_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCLOTDAT_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCLOTDAT_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCLOTDAT_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCLOTDAT_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCLOTDAT_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCLOTDAT_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCLOTDAT_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCLOTDAT_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCLOTDAT_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MEDCLOTDAT_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MEDCLOTDAT_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MEDCLOTDAT_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MEDCLOTDAT_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MEDCLOTDAT_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MEDCLOTDAT_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MEDCLOTDAT_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MEDCLOTDAT_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MEDCLOTDAT_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MEDCLOTDAT_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MEDCLOTDAT_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MEDCLOTDAT_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MEDCLOTDAT_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MEDCLOTDAT_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MEDCLOTDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MEDCLOTDAT_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MEDCLOTDAT_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MEDCLOTDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MEDCLOTDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MEDCLOTDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MEDCLOTDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MEDCLOTDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MEDCLOTDAT_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MEDCLOTDAT_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )26;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
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


    if(DB_error_code == 0)
    {
        DBU_del_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    }

    DB_stop_query_timer("DBU_select_medclotdat", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_medclotdat_for_update(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    LOT_ID,
                    HIST_SEQ,
                    COL_SEQ,
                    TRAN_TIME,
                    HIST_DEL_FLAG,
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    MEAS_RES_ID,
                    PROC_FLOW,
                    PROC_OPER,
                    PROC_RES_ID,
                    RECIPE_ID,
                    RECIPE_VERSION,
                    COL_SET_ID,
                    COL_SET_VERSION,
                    CHAR_SEQ_NUM,
                    CHAR_ID,
                    UNIT_SEQ_NUM,
                    UNIT_ID,
                    VALUE_SEQ_NUM,
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
                    NOMINAL,
                    PROCESS_SIGMA,
                    SPEC_OUT_MASK,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    DELETE_USER_ID,
                    DELETE_TIME
                INTO 
                    :MEDCLOTDAT_N.LOT_ID,
                    :MEDCLOTDAT_N.HIST_SEQ,
                    :MEDCLOTDAT_N.COL_SEQ,
                    :MEDCLOTDAT_N.TRAN_TIME,
                    :MEDCLOTDAT_N.HIST_DEL_FLAG,
                    :MEDCLOTDAT_N.FACTORY,
                    :MEDCLOTDAT_N.MAT_ID,
                    :MEDCLOTDAT_N.MAT_VER,
                    :MEDCLOTDAT_N.FLOW,
                    :MEDCLOTDAT_N.OPER,
                    :MEDCLOTDAT_N.MEAS_RES_ID,
                    :MEDCLOTDAT_N.PROC_FLOW,
                    :MEDCLOTDAT_N.PROC_OPER,
                    :MEDCLOTDAT_N.PROC_RES_ID,
                    :MEDCLOTDAT_N.RECIPE_ID,
                    :MEDCLOTDAT_N.RECIPE_VERSION,
                    :MEDCLOTDAT_N.COL_SET_ID,
                    :MEDCLOTDAT_N.COL_SET_VERSION,
                    :MEDCLOTDAT_N.CHAR_SEQ_NUM,
                    :MEDCLOTDAT_N.CHAR_ID,
                    :MEDCLOTDAT_N.UNIT_SEQ_NUM,
                    :MEDCLOTDAT_N.UNIT_ID,
                    :MEDCLOTDAT_N.VALUE_SEQ_NUM,
                    :MEDCLOTDAT_N.VALUE_TYPE,
                    :MEDCLOTDAT_N.VALUE_COUNT,
                    :MEDCLOTDAT_N.VALUE_1,
                    :MEDCLOTDAT_N.VALUE_2,
                    :MEDCLOTDAT_N.VALUE_3,
                    :MEDCLOTDAT_N.VALUE_4,
                    :MEDCLOTDAT_N.VALUE_5,
                    :MEDCLOTDAT_N.VALUE_6,
                    :MEDCLOTDAT_N.VALUE_7,
                    :MEDCLOTDAT_N.VALUE_8,
                    :MEDCLOTDAT_N.VALUE_9,
                    :MEDCLOTDAT_N.VALUE_10,
                    :MEDCLOTDAT_N.VALUE_11,
                    :MEDCLOTDAT_N.VALUE_12,
                    :MEDCLOTDAT_N.VALUE_13,
                    :MEDCLOTDAT_N.VALUE_14,
                    :MEDCLOTDAT_N.VALUE_15,
                    :MEDCLOTDAT_N.VALUE_16,
                    :MEDCLOTDAT_N.VALUE_17,
                    :MEDCLOTDAT_N.VALUE_18,
                    :MEDCLOTDAT_N.VALUE_19,
                    :MEDCLOTDAT_N.VALUE_20,
                    :MEDCLOTDAT_N.VALUE_21,
                    :MEDCLOTDAT_N.VALUE_22,
                    :MEDCLOTDAT_N.VALUE_23,
                    :MEDCLOTDAT_N.VALUE_24,
                    :MEDCLOTDAT_N.VALUE_25,
                    :MEDCLOTDAT_N.SAMPLE_COUNT,
                    :MEDCLOTDAT_N.NOMINAL,
                    :MEDCLOTDAT_N.PROCESS_SIGMA,
                    :MEDCLOTDAT_N.SPEC_OUT_MASK,
                    :MEDCLOTDAT_N.CREATE_USER_ID,
                    :MEDCLOTDAT_N.CREATE_TIME,
                    :MEDCLOTDAT_N.UPDATE_USER_ID,
                    :MEDCLOTDAT_N.UPDATE_TIME,
                    :MEDCLOTDAT_N.DELETE_USER_ID,
                    :MEDCLOTDAT_N.DELETE_TIME
                FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                    AND HIST_SEQ = :MEDCLOTDAT_N.HIST_SEQ
                    AND COL_SEQ = :MEDCLOTDAT_N.COL_SEQ
                    AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                    AND CHAR_SEQ_NUM = :MEDCLOTDAT_N.CHAR_SEQ_NUM
                    AND UNIT_SEQ_NUM = :MEDCLOTDAT_N.UNIT_SEQ_NUM
                    AND VALUE_SEQ_NUM = :MEDCLOTDAT_N.VALUE_SEQ_NUM
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,COL_SEQ ,TRAN_TIME ,HIST_DEL_FLAG ,F\
ACTORY ,MAT_ID ,MAT_VER ,FLOW ,OPER ,MEAS_RES_ID ,PROC_FLOW ,PROC_OPER ,PROC\
_RES_ID ,RECIPE_ID ,RECIPE_VERSION ,COL_SET_ID ,COL_SET_VERSION ,CHAR_SEQ_NU\
M ,CHAR_ID ,UNIT_SEQ_NUM ,UNIT_ID ,VALUE_SEQ_NUM ,VALUE_TYPE ,VALUE_COUNT ,V\
ALUE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE\
_9 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VA\
LUE_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24\
 ,VALUE_25 ,SAMPLE_COUNT ,NOMINAL ,PROCESS_SIGMA ,SPEC_OUT_MASK ,CREATE_USER\
_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,DELETE_USER_ID ,DELETE_TIME i\
nto :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b\
16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b3\
1,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46\
,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59  from MEDC\
LOTDAT where ((((((LOT_ID=:b0 and HIST_SEQ=:b1) and");
            sqlstm.stmt = " COL_SEQ=:b2) and COL_SET_ID=:b16) and CHAR_SEQ_\
NUM=:b18) and UNIT_SEQ_NUM=:b20) and VALUE_SEQ_NUM=:b22) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )288;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCLOTDAT_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MEDCLOTDAT_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCLOTDAT_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCLOTDAT_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCLOTDAT_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCLOTDAT_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCLOTDAT_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCLOTDAT_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MEDCLOTDAT_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCLOTDAT_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCLOTDAT_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCLOTDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MEDCLOTDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCLOTDAT_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCLOTDAT_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCLOTDAT_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCLOTDAT_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCLOTDAT_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCLOTDAT_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCLOTDAT_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCLOTDAT_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCLOTDAT_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCLOTDAT_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCLOTDAT_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MEDCLOTDAT_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MEDCLOTDAT_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MEDCLOTDAT_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MEDCLOTDAT_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MEDCLOTDAT_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MEDCLOTDAT_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MEDCLOTDAT_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MEDCLOTDAT_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MEDCLOTDAT_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MEDCLOTDAT_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MEDCLOTDAT_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MEDCLOTDAT_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MEDCLOTDAT_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MEDCLOTDAT_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MEDCLOTDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MEDCLOTDAT_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MEDCLOTDAT_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MEDCLOTDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MEDCLOTDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MEDCLOTDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MEDCLOTDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MEDCLOTDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MEDCLOTDAT_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MEDCLOTDAT_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )26;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
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


    if(DB_error_code == 0)
    {
        DBU_del_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    }

    DB_stop_query_timer("DBU_select_medclotdat_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_medclotdat_scalar(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                    AND HIST_SEQ = :MEDCLOTDAT_N.HIST_SEQ
                    AND COL_SEQ = :MEDCLOTDAT_N.COL_SEQ
                    AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                    AND CHAR_SEQ_NUM = :MEDCLOTDAT_N.CHAR_SEQ_NUM
                    AND UNIT_SEQ_NUM = :MEDCLOTDAT_N.UNIT_SEQ_NUM
                    AND VALUE_SEQ_NUM = :MEDCLOTDAT_N.VALUE_SEQ_NUM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MEDCLOTDAT where\
 ((((((LOT_ID=:b1 and HIST_SEQ=:b2) and COL_SEQ=:b3) and COL_SET_ID=:b4) and \
CHAR_SEQ_NUM=:b5) and UNIT_SEQ_NUM=:b6) and VALUE_SEQ_NUM=:b7)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )571;
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
            sqlstm.sqhstv[1] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
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

        case 2:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                  AND OPER = :MEDCLOTDAT_N.OPER
                  AND HIST_SEQ = :MEDCLOTDAT_N.HIST_SEQ
                  AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                  AND COL_SET_VERSION = :MEDCLOTDAT_N.COL_SET_VERSION; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MEDCLOTDAT where\
 ((((LOT_ID=:b1 and OPER=:b2) and HIST_SEQ=:b3) and COL_SET_ID=:b4) and COL_S\
ET_VERSION=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )618;
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
            sqlstm.sqhstv[1] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
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

		case 3:
            /* EXEC SQL SELECT NVL(MAX(HIST_SEQ),0)
                INTO :d_value
                FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                  AND OPER = :MEDCLOTDAT_N.OPER
				  AND MAT_ID = :MEDCLOTDAT_N.MAT_ID
                  AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                  AND COL_SET_VERSION = :MEDCLOTDAT_N.COL_SET_VERSION
				  AND HIST_DEL_FLAG = ' '; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(max(HIST_SEQ),0) into :b0  from MEDCL\
OTDAT where (((((LOT_ID=:b1 and OPER=:b2) and MAT_ID=:b3) and COL_SET_ID=:b4)\
 and COL_SET_VERSION=:b5) and HIST_DEL_FLAG=' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )657;
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
            sqlstm.sqhstv[1] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
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

		case 4:
            /* EXEC SQL SELECT NVL(MAX(HIST_SEQ),0)
                INTO :d_value
                FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                  AND OPER = :MEDCLOTDAT_N.OPER
				  AND MAT_ID = :MEDCLOTDAT_N.MAT_ID
                  AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                  AND COL_SET_VERSION = :MEDCLOTDAT_N.COL_SET_VERSION
				  AND COL_SET_VERSION = 'PDAT00002'
				  AND HIST_DEL_FLAG = ' '; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(max(HIST_SEQ),0) into :b0  from MEDCL\
OTDAT where ((((((LOT_ID=:b1 and OPER=:b2) and MAT_ID=:b3) and COL_SET_ID=:b4\
) and COL_SET_VERSION=:b5) and COL_SET_VERSION='PDAT00002') and HIST_DEL_FLAG\
=' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )696;
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
            sqlstm.sqhstv[1] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
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

    DB_stop_query_timer("DBU_select_medclotdat_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_medclotdat(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MEDCLOTDAT
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                    AND HIST_SEQ = :MEDCLOTDAT_N.HIST_SEQ
                    AND COL_SEQ = :MEDCLOTDAT_N.COL_SEQ
                    AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                    AND CHAR_SEQ_NUM = :MEDCLOTDAT_N.CHAR_SEQ_NUM
                    AND UNIT_SEQ_NUM = :MEDCLOTDAT_N.UNIT_SEQ_NUM
                    AND VALUE_SEQ_NUM = :MEDCLOTDAT_N.VALUE_SEQ_NUM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MEDCLOTDAT  where ((((((LOT_ID=:b0 \
and HIST_SEQ=:b1) and COL_SEQ=:b2) and COL_SET_ID=:b3) and CHAR_SEQ_NUM=:b4) \
and UNIT_SEQ_NUM=:b5) and VALUE_SEQ_NUM=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )735;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_delete_medclotdat", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_medclotdat(struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MEDCLOTDAT( 
                    LOT_ID, 
                    HIST_SEQ, 
                    COL_SEQ, 
                    TRAN_TIME, 
                    HIST_DEL_FLAG, 
                    FACTORY, 
                    MAT_ID, 
                    MAT_VER, 
                    FLOW, 
                    OPER, 
                    MEAS_RES_ID, 
                    PROC_FLOW, 
                    PROC_OPER, 
                    PROC_RES_ID, 
                    RECIPE_ID, 
                    RECIPE_VERSION, 
                    COL_SET_ID, 
                    COL_SET_VERSION, 
                    CHAR_SEQ_NUM, 
                    CHAR_ID, 
                    UNIT_SEQ_NUM, 
                    UNIT_ID, 
                    VALUE_SEQ_NUM, 
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
                    NOMINAL, 
                    PROCESS_SIGMA, 
                    SPEC_OUT_MASK, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    DELETE_USER_ID, 
                    DELETE_TIME
         ) 
        VALUES (
                    :MEDCLOTDAT_N.LOT_ID,
                    :MEDCLOTDAT_N.HIST_SEQ,
                    :MEDCLOTDAT_N.COL_SEQ,
                    :MEDCLOTDAT_N.TRAN_TIME,
                    :MEDCLOTDAT_N.HIST_DEL_FLAG,
                    :MEDCLOTDAT_N.FACTORY,
                    :MEDCLOTDAT_N.MAT_ID,
                    :MEDCLOTDAT_N.MAT_VER,
                    :MEDCLOTDAT_N.FLOW,
                    :MEDCLOTDAT_N.OPER,
                    :MEDCLOTDAT_N.MEAS_RES_ID,
                    :MEDCLOTDAT_N.PROC_FLOW,
                    :MEDCLOTDAT_N.PROC_OPER,
                    :MEDCLOTDAT_N.PROC_RES_ID,
                    :MEDCLOTDAT_N.RECIPE_ID,
                    :MEDCLOTDAT_N.RECIPE_VERSION,
                    :MEDCLOTDAT_N.COL_SET_ID,
                    :MEDCLOTDAT_N.COL_SET_VERSION,
                    :MEDCLOTDAT_N.CHAR_SEQ_NUM,
                    :MEDCLOTDAT_N.CHAR_ID,
                    :MEDCLOTDAT_N.UNIT_SEQ_NUM,
                    :MEDCLOTDAT_N.UNIT_ID,
                    :MEDCLOTDAT_N.VALUE_SEQ_NUM,
                    :MEDCLOTDAT_N.VALUE_TYPE,
                    :MEDCLOTDAT_N.VALUE_COUNT,
                    :MEDCLOTDAT_N.VALUE_1,
                    :MEDCLOTDAT_N.VALUE_2,
                    :MEDCLOTDAT_N.VALUE_3,
                    :MEDCLOTDAT_N.VALUE_4,
                    :MEDCLOTDAT_N.VALUE_5,
                    :MEDCLOTDAT_N.VALUE_6,
                    :MEDCLOTDAT_N.VALUE_7,
                    :MEDCLOTDAT_N.VALUE_8,
                    :MEDCLOTDAT_N.VALUE_9,
                    :MEDCLOTDAT_N.VALUE_10,
                    :MEDCLOTDAT_N.VALUE_11,
                    :MEDCLOTDAT_N.VALUE_12,
                    :MEDCLOTDAT_N.VALUE_13,
                    :MEDCLOTDAT_N.VALUE_14,
                    :MEDCLOTDAT_N.VALUE_15,
                    :MEDCLOTDAT_N.VALUE_16,
                    :MEDCLOTDAT_N.VALUE_17,
                    :MEDCLOTDAT_N.VALUE_18,
                    :MEDCLOTDAT_N.VALUE_19,
                    :MEDCLOTDAT_N.VALUE_20,
                    :MEDCLOTDAT_N.VALUE_21,
                    :MEDCLOTDAT_N.VALUE_22,
                    :MEDCLOTDAT_N.VALUE_23,
                    :MEDCLOTDAT_N.VALUE_24,
                    :MEDCLOTDAT_N.VALUE_25,
                    :MEDCLOTDAT_N.SAMPLE_COUNT,
                    :MEDCLOTDAT_N.NOMINAL,
                    :MEDCLOTDAT_N.PROCESS_SIGMA,
                    :MEDCLOTDAT_N.SPEC_OUT_MASK,
                    :MEDCLOTDAT_N.CREATE_USER_ID,
                    :MEDCLOTDAT_N.CREATE_TIME,
                    :MEDCLOTDAT_N.UPDATE_USER_ID,
                    :MEDCLOTDAT_N.UPDATE_TIME,
                    :MEDCLOTDAT_N.DELETE_USER_ID,
                    :MEDCLOTDAT_N.DELETE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 67;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into MEDCLOTDAT (LOT_ID,HIST_SEQ,COL_SEQ,TRAN_TIM\
E,HIST_DEL_FLAG,FACTORY,MAT_ID,MAT_VER,FLOW,OPER,MEAS_RES_ID,PROC_FLOW,PROC_O\
PER,PROC_RES_ID,RECIPE_ID,RECIPE_VERSION,COL_SET_ID,COL_SET_VERSION,CHAR_SEQ_\
NUM,CHAR_ID,UNIT_SEQ_NUM,UNIT_ID,VALUE_SEQ_NUM,VALUE_TYPE,VALUE_COUNT,VALUE_1\
,VALUE_2,VALUE_3,VALUE_4,VALUE_5,VALUE_6,VALUE_7,VALUE_8,VALUE_9,VALUE_10,VAL\
UE_11,VALUE_12,VALUE_13,VALUE_14,VALUE_15,VALUE_16,VALUE_17,VALUE_18,VALUE_19\
,VALUE_20,VALUE_21,VALUE_22,VALUE_23,VALUE_24,VALUE_25,SAMPLE_COUNT,NOMINAL,P\
ROCESS_SIGMA,SPEC_OUT_MASK,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_T\
IME,DELETE_USER_ID,DELETE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:\
b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24\
,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:\
b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b5\
5,:b56,:b57,:b58,:b59)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )778;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
    sqlstm.sqhstl[0] = (unsigned int  )26;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.TRAN_TIME);
    sqlstm.sqhstl[3] = (unsigned int  )15;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MEDCLOTDAT_N.FACTORY);
    sqlstm.sqhstl[5] = (unsigned int  )11;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(MEDCLOTDAT_N.MAT_VER);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MEDCLOTDAT_N.FLOW);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MEDCLOTDAT_N.OPER);
    sqlstm.sqhstl[9] = (unsigned int  )11;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MEDCLOTDAT_N.MEAS_RES_ID);
    sqlstm.sqhstl[10] = (unsigned int  )21;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MEDCLOTDAT_N.PROC_FLOW);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MEDCLOTDAT_N.PROC_OPER);
    sqlstm.sqhstl[12] = (unsigned int  )11;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MEDCLOTDAT_N.PROC_RES_ID);
    sqlstm.sqhstl[13] = (unsigned int  )21;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MEDCLOTDAT_N.RECIPE_ID);
    sqlstm.sqhstl[14] = (unsigned int  )26;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(MEDCLOTDAT_N.RECIPE_VERSION);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
    sqlstm.sqhstl[16] = (unsigned int  )26;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
    sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MEDCLOTDAT_N.CHAR_ID);
    sqlstm.sqhstl[19] = (unsigned int  )26;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
    sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MEDCLOTDAT_N.UNIT_ID);
    sqlstm.sqhstl[21] = (unsigned int  )51;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MEDCLOTDAT_N.VALUE_TYPE);
    sqlstm.sqhstl[23] = (unsigned int  )2;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)&(MEDCLOTDAT_N.VALUE_COUNT);
    sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MEDCLOTDAT_N.VALUE_1);
    sqlstm.sqhstl[25] = (unsigned int  )26;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MEDCLOTDAT_N.VALUE_2);
    sqlstm.sqhstl[26] = (unsigned int  )26;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MEDCLOTDAT_N.VALUE_3);
    sqlstm.sqhstl[27] = (unsigned int  )26;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MEDCLOTDAT_N.VALUE_4);
    sqlstm.sqhstl[28] = (unsigned int  )26;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MEDCLOTDAT_N.VALUE_5);
    sqlstm.sqhstl[29] = (unsigned int  )26;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MEDCLOTDAT_N.VALUE_6);
    sqlstm.sqhstl[30] = (unsigned int  )26;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MEDCLOTDAT_N.VALUE_7);
    sqlstm.sqhstl[31] = (unsigned int  )26;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MEDCLOTDAT_N.VALUE_8);
    sqlstm.sqhstl[32] = (unsigned int  )26;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MEDCLOTDAT_N.VALUE_9);
    sqlstm.sqhstl[33] = (unsigned int  )26;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MEDCLOTDAT_N.VALUE_10);
    sqlstm.sqhstl[34] = (unsigned int  )26;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MEDCLOTDAT_N.VALUE_11);
    sqlstm.sqhstl[35] = (unsigned int  )26;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MEDCLOTDAT_N.VALUE_12);
    sqlstm.sqhstl[36] = (unsigned int  )26;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MEDCLOTDAT_N.VALUE_13);
    sqlstm.sqhstl[37] = (unsigned int  )26;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MEDCLOTDAT_N.VALUE_14);
    sqlstm.sqhstl[38] = (unsigned int  )26;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MEDCLOTDAT_N.VALUE_15);
    sqlstm.sqhstl[39] = (unsigned int  )26;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MEDCLOTDAT_N.VALUE_16);
    sqlstm.sqhstl[40] = (unsigned int  )26;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MEDCLOTDAT_N.VALUE_17);
    sqlstm.sqhstl[41] = (unsigned int  )26;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MEDCLOTDAT_N.VALUE_18);
    sqlstm.sqhstl[42] = (unsigned int  )26;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MEDCLOTDAT_N.VALUE_19);
    sqlstm.sqhstl[43] = (unsigned int  )26;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MEDCLOTDAT_N.VALUE_20);
    sqlstm.sqhstl[44] = (unsigned int  )26;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MEDCLOTDAT_N.VALUE_21);
    sqlstm.sqhstl[45] = (unsigned int  )26;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MEDCLOTDAT_N.VALUE_22);
    sqlstm.sqhstl[46] = (unsigned int  )26;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MEDCLOTDAT_N.VALUE_23);
    sqlstm.sqhstl[47] = (unsigned int  )26;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MEDCLOTDAT_N.VALUE_24);
    sqlstm.sqhstl[48] = (unsigned int  )26;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MEDCLOTDAT_N.VALUE_25);
    sqlstm.sqhstl[49] = (unsigned int  )26;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)&(MEDCLOTDAT_N.SAMPLE_COUNT);
    sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MEDCLOTDAT_N.NOMINAL);
    sqlstm.sqhstl[51] = (unsigned int  )26;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MEDCLOTDAT_N.PROCESS_SIGMA);
    sqlstm.sqhstl[52] = (unsigned int  )26;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MEDCLOTDAT_N.SPEC_OUT_MASK);
    sqlstm.sqhstl[53] = (unsigned int  )26;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MEDCLOTDAT_N.CREATE_USER_ID);
    sqlstm.sqhstl[54] = (unsigned int  )21;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MEDCLOTDAT_N.CREATE_TIME);
    sqlstm.sqhstl[55] = (unsigned int  )15;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MEDCLOTDAT_N.UPDATE_USER_ID);
    sqlstm.sqhstl[56] = (unsigned int  )21;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MEDCLOTDAT_N.UPDATE_TIME);
    sqlstm.sqhstl[57] = (unsigned int  )15;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MEDCLOTDAT_N.DELETE_USER_ID);
    sqlstm.sqhstl[58] = (unsigned int  )21;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MEDCLOTDAT_N.DELETE_TIME);
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



    DB_stop_query_timer("DBU_insert_medclotdat", 0);
}


/* SQL UPDATE Function */
void DBU_update_medclotdat(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MEDCLOTDAT SET
                    TRAN_TIME = :MEDCLOTDAT_N.TRAN_TIME,
                    HIST_DEL_FLAG = :MEDCLOTDAT_N.HIST_DEL_FLAG,
                    FACTORY = :MEDCLOTDAT_N.FACTORY,
                    MAT_ID = :MEDCLOTDAT_N.MAT_ID,
                    MAT_VER = :MEDCLOTDAT_N.MAT_VER,
                    FLOW = :MEDCLOTDAT_N.FLOW,
                    OPER = :MEDCLOTDAT_N.OPER,
                    MEAS_RES_ID = :MEDCLOTDAT_N.MEAS_RES_ID,
                    PROC_FLOW = :MEDCLOTDAT_N.PROC_FLOW,
                    PROC_OPER = :MEDCLOTDAT_N.PROC_OPER,
                    PROC_RES_ID = :MEDCLOTDAT_N.PROC_RES_ID,
                    RECIPE_ID = :MEDCLOTDAT_N.RECIPE_ID,
                    RECIPE_VERSION = :MEDCLOTDAT_N.RECIPE_VERSION,
                    COL_SET_VERSION = :MEDCLOTDAT_N.COL_SET_VERSION,
                    CHAR_ID = :MEDCLOTDAT_N.CHAR_ID,
                    UNIT_ID = :MEDCLOTDAT_N.UNIT_ID,
                    VALUE_TYPE = :MEDCLOTDAT_N.VALUE_TYPE,
                    VALUE_COUNT = :MEDCLOTDAT_N.VALUE_COUNT,
                    VALUE_1 = :MEDCLOTDAT_N.VALUE_1,
                    VALUE_2 = :MEDCLOTDAT_N.VALUE_2,
                    VALUE_3 = :MEDCLOTDAT_N.VALUE_3,
                    VALUE_4 = :MEDCLOTDAT_N.VALUE_4,
                    VALUE_5 = :MEDCLOTDAT_N.VALUE_5,
                    VALUE_6 = :MEDCLOTDAT_N.VALUE_6,
                    VALUE_7 = :MEDCLOTDAT_N.VALUE_7,
                    VALUE_8 = :MEDCLOTDAT_N.VALUE_8,
                    VALUE_9 = :MEDCLOTDAT_N.VALUE_9,
                    VALUE_10 = :MEDCLOTDAT_N.VALUE_10,
                    VALUE_11 = :MEDCLOTDAT_N.VALUE_11,
                    VALUE_12 = :MEDCLOTDAT_N.VALUE_12,
                    VALUE_13 = :MEDCLOTDAT_N.VALUE_13,
                    VALUE_14 = :MEDCLOTDAT_N.VALUE_14,
                    VALUE_15 = :MEDCLOTDAT_N.VALUE_15,
                    VALUE_16 = :MEDCLOTDAT_N.VALUE_16,
                    VALUE_17 = :MEDCLOTDAT_N.VALUE_17,
                    VALUE_18 = :MEDCLOTDAT_N.VALUE_18,
                    VALUE_19 = :MEDCLOTDAT_N.VALUE_19,
                    VALUE_20 = :MEDCLOTDAT_N.VALUE_20,
                    VALUE_21 = :MEDCLOTDAT_N.VALUE_21,
                    VALUE_22 = :MEDCLOTDAT_N.VALUE_22,
                    VALUE_23 = :MEDCLOTDAT_N.VALUE_23,
                    VALUE_24 = :MEDCLOTDAT_N.VALUE_24,
                    VALUE_25 = :MEDCLOTDAT_N.VALUE_25,
                    SAMPLE_COUNT = :MEDCLOTDAT_N.SAMPLE_COUNT,
                    NOMINAL = :MEDCLOTDAT_N.NOMINAL,
                    PROCESS_SIGMA = :MEDCLOTDAT_N.PROCESS_SIGMA,
                    SPEC_OUT_MASK = :MEDCLOTDAT_N.SPEC_OUT_MASK,
                    CREATE_USER_ID = :MEDCLOTDAT_N.CREATE_USER_ID,
                    CREATE_TIME = :MEDCLOTDAT_N.CREATE_TIME,
                    UPDATE_USER_ID = :MEDCLOTDAT_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MEDCLOTDAT_N.UPDATE_TIME,
                    DELETE_USER_ID = :MEDCLOTDAT_N.DELETE_USER_ID,
                    DELETE_TIME = :MEDCLOTDAT_N.DELETE_TIME
                WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
                    AND HIST_SEQ = :MEDCLOTDAT_N.HIST_SEQ
                    AND COL_SEQ = :MEDCLOTDAT_N.COL_SEQ
                    AND COL_SET_ID = :MEDCLOTDAT_N.COL_SET_ID
                    AND CHAR_SEQ_NUM = :MEDCLOTDAT_N.CHAR_SEQ_NUM
                    AND UNIT_SEQ_NUM = :MEDCLOTDAT_N.UNIT_SEQ_NUM
                    AND VALUE_SEQ_NUM = :MEDCLOTDAT_N.VALUE_SEQ_NUM; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MEDCLOTDAT  set TRAN_TIME=:b0,HIST_DEL_FL\
AG=:b1,FACTORY=:b2,MAT_ID=:b3,MAT_VER=:b4,FLOW=:b5,OPER=:b6,MEAS_RES_ID=:b7,P\
ROC_FLOW=:b8,PROC_OPER=:b9,PROC_RES_ID=:b10,RECIPE_ID=:b11,RECIPE_VERSION=:b1\
2,COL_SET_VERSION=:b13,CHAR_ID=:b14,UNIT_ID=:b15,VALUE_TYPE=:b16,VALUE_COUNT=\
:b17,VALUE_1=:b18,VALUE_2=:b19,VALUE_3=:b20,VALUE_4=:b21,VALUE_5=:b22,VALUE_6\
=:b23,VALUE_7=:b24,VALUE_8=:b25,VALUE_9=:b26,VALUE_10=:b27,VALUE_11=:b28,VALU\
E_12=:b29,VALUE_13=:b30,VALUE_14=:b31,VALUE_15=:b32,VALUE_16=:b33,VALUE_17=:b\
34,VALUE_18=:b35,VALUE_19=:b36,VALUE_20=:b37,VALUE_21=:b38,VALUE_22=:b39,VALU\
E_23=:b40,VALUE_24=:b41,VALUE_25=:b42,SAMPLE_COUNT=:b43,NOMINAL=:b44,PROCESS_\
SIGMA=:b45,SPEC_OUT_MASK=:b46,CREATE_USER_ID=:b47,CREATE_TIME=:b48,UPDATE_USE\
R_ID=:b49,UPDATE_TIME=:b50,DELETE_USER_ID=:b51,DELETE_TIME=:b52 where ((((((L\
OT_ID=:b53 and HIST_SEQ=:b54) and COL_SEQ=:b55) and COL_SET_ID=:b56) and CHAR\
_SEQ_NUM=:b57) and UNIT_SEQ_NUM=:b58) and VALUE_SEQ_NUM=:b59)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1033;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.TRAN_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MEDCLOTDAT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MEDCLOTDAT_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MEDCLOTDAT_N.MAT_VER);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCLOTDAT_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MEDCLOTDAT_N.MEAS_RES_ID);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCLOTDAT_N.PROC_FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCLOTDAT_N.PROC_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCLOTDAT_N.PROC_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCLOTDAT_N.RECIPE_ID);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MEDCLOTDAT_N.RECIPE_VERSION);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCLOTDAT_N.CHAR_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MEDCLOTDAT_N.UNIT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )51;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCLOTDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MEDCLOTDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MEDCLOTDAT_N.VALUE_1);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCLOTDAT_N.VALUE_2);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MEDCLOTDAT_N.VALUE_3);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCLOTDAT_N.VALUE_4);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MEDCLOTDAT_N.VALUE_5);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCLOTDAT_N.VALUE_6);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MEDCLOTDAT_N.VALUE_7);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCLOTDAT_N.VALUE_8);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCLOTDAT_N.VALUE_9);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCLOTDAT_N.VALUE_10);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCLOTDAT_N.VALUE_11);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCLOTDAT_N.VALUE_12);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCLOTDAT_N.VALUE_13);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCLOTDAT_N.VALUE_14);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCLOTDAT_N.VALUE_15);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCLOTDAT_N.VALUE_16);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCLOTDAT_N.VALUE_17);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCLOTDAT_N.VALUE_18);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MEDCLOTDAT_N.VALUE_19);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MEDCLOTDAT_N.VALUE_20);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MEDCLOTDAT_N.VALUE_21);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MEDCLOTDAT_N.VALUE_22);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MEDCLOTDAT_N.VALUE_23);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MEDCLOTDAT_N.VALUE_24);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MEDCLOTDAT_N.VALUE_25);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(MEDCLOTDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MEDCLOTDAT_N.NOMINAL);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MEDCLOTDAT_N.PROCESS_SIGMA);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MEDCLOTDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MEDCLOTDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MEDCLOTDAT_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MEDCLOTDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MEDCLOTDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MEDCLOTDAT_N.DELETE_USER_ID);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MEDCLOTDAT_N.DELETE_TIME);
            sqlstm.sqhstl[52] = (unsigned int  )15;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[56] = (unsigned int  )26;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_update_medclotdat", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_medclotdat(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MEDCLOTDAT_CUR_1 CURSOR FOR
                SELECT 
                    LOT_ID,
                    HIST_SEQ,
                    COL_SEQ,
                    TRAN_TIME,
                    HIST_DEL_FLAG,
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    OPER,
                    MEAS_RES_ID,
                    PROC_FLOW,
                    PROC_OPER,
                    PROC_RES_ID,
                    RECIPE_ID,
                    RECIPE_VERSION,
                    COL_SET_ID,
                    COL_SET_VERSION,
                    CHAR_SEQ_NUM,
                    CHAR_ID,
                    UNIT_SEQ_NUM,
                    UNIT_ID,
                    VALUE_SEQ_NUM,
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
                    NOMINAL,
                    PROCESS_SIGMA,
                    SPEC_OUT_MASK,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    DELETE_USER_ID,
                    DELETE_TIME
                FROM MEDCLOTDAT
                ORDER BY LOT_ID ASC,
                    HIST_SEQ ASC,
                    COL_SEQ ASC,
                    COL_SET_ID ASC,
                    CHAR_SEQ_NUM ASC,
                    UNIT_SEQ_NUM ASC,
                    VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBU_MEDCLOTDAT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1288;
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
            /* EXEC SQL DECLARE DBU_MEDCLOTDAT_CUR_2 CURSOR FOR
                SELECT LOT_ID,
							HIST_SEQ,
							COL_SEQ,
							TRAN_TIME,
							HIST_DEL_FLAG,
							FACTORY,
							MAT_ID,
							MAT_VER,
							FLOW,
							OPER,
							MEAS_RES_ID,
							PROC_FLOW,
							PROC_OPER,
							PROC_RES_ID,
							RECIPE_ID,
							RECIPE_VERSION,
							COL_SET_ID,
							COL_SET_VERSION,
							CHAR_SEQ_NUM,
							CHAR_ID,
							UNIT_SEQ_NUM,
							UNIT_ID,
							VALUE_SEQ_NUM,
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
							NOMINAL,
							PROCESS_SIGMA,
							SPEC_OUT_MASK,
							CREATE_USER_ID,
							CREATE_TIME,
							UPDATE_USER_ID,
							UPDATE_TIME,
							DELETE_USER_ID,
							DELETE_TIME
					  FROM MEDCLOTDAT A
					 WHERE LOT_ID = :MEDCLOTDAT_N.LOT_ID
					   AND COL_SET_ID = (SELECT COL_SET_ID FROM MEDCCOLDEF WHERE COL_CMF_2 = 'A')
					   AND TRAN_TIME = (SELECT MAX(TRAN_TIME) FROM MEDCLOTDAT
										WHERE FACTORY = A.FACTORY
										  AND LOT_ID = A.LOT_ID
										  AND COL_SET_ID = A.COL_SET_ID
										)
						AND CHAR_ID IN ('ALL-T','FLAT','MAX-D','REAL-D')
					 ORDER BY A.CHAR_SEQ_NUM; */ 

            /* EXEC SQL OPEN DBU_MEDCLOTDAT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1303;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
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

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_medclotdat", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_medclotdat(int sel_type, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MEDCLOTDAT_N_TAG MEDCLOTDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MEDCLOTDAT_CUR_1 INTO
                :MEDCLOTDAT_N.LOT_ID,
                :MEDCLOTDAT_N.HIST_SEQ,
                :MEDCLOTDAT_N.COL_SEQ,
                :MEDCLOTDAT_N.TRAN_TIME,
                :MEDCLOTDAT_N.HIST_DEL_FLAG,
                :MEDCLOTDAT_N.FACTORY,
                :MEDCLOTDAT_N.MAT_ID,
                :MEDCLOTDAT_N.MAT_VER,
                :MEDCLOTDAT_N.FLOW,
                :MEDCLOTDAT_N.OPER,
                :MEDCLOTDAT_N.MEAS_RES_ID,
                :MEDCLOTDAT_N.PROC_FLOW,
                :MEDCLOTDAT_N.PROC_OPER,
                :MEDCLOTDAT_N.PROC_RES_ID,
                :MEDCLOTDAT_N.RECIPE_ID,
                :MEDCLOTDAT_N.RECIPE_VERSION,
                :MEDCLOTDAT_N.COL_SET_ID,
                :MEDCLOTDAT_N.COL_SET_VERSION,
                :MEDCLOTDAT_N.CHAR_SEQ_NUM,
                :MEDCLOTDAT_N.CHAR_ID,
                :MEDCLOTDAT_N.UNIT_SEQ_NUM,
                :MEDCLOTDAT_N.UNIT_ID,
                :MEDCLOTDAT_N.VALUE_SEQ_NUM,
                :MEDCLOTDAT_N.VALUE_TYPE,
                :MEDCLOTDAT_N.VALUE_COUNT,
                :MEDCLOTDAT_N.VALUE_1,
                :MEDCLOTDAT_N.VALUE_2,
                :MEDCLOTDAT_N.VALUE_3,
                :MEDCLOTDAT_N.VALUE_4,
                :MEDCLOTDAT_N.VALUE_5,
                :MEDCLOTDAT_N.VALUE_6,
                :MEDCLOTDAT_N.VALUE_7,
                :MEDCLOTDAT_N.VALUE_8,
                :MEDCLOTDAT_N.VALUE_9,
                :MEDCLOTDAT_N.VALUE_10,
                :MEDCLOTDAT_N.VALUE_11,
                :MEDCLOTDAT_N.VALUE_12,
                :MEDCLOTDAT_N.VALUE_13,
                :MEDCLOTDAT_N.VALUE_14,
                :MEDCLOTDAT_N.VALUE_15,
                :MEDCLOTDAT_N.VALUE_16,
                :MEDCLOTDAT_N.VALUE_17,
                :MEDCLOTDAT_N.VALUE_18,
                :MEDCLOTDAT_N.VALUE_19,
                :MEDCLOTDAT_N.VALUE_20,
                :MEDCLOTDAT_N.VALUE_21,
                :MEDCLOTDAT_N.VALUE_22,
                :MEDCLOTDAT_N.VALUE_23,
                :MEDCLOTDAT_N.VALUE_24,
                :MEDCLOTDAT_N.VALUE_25,
                :MEDCLOTDAT_N.SAMPLE_COUNT,
                :MEDCLOTDAT_N.NOMINAL,
                :MEDCLOTDAT_N.PROCESS_SIGMA,
                :MEDCLOTDAT_N.SPEC_OUT_MASK,
                :MEDCLOTDAT_N.CREATE_USER_ID,
                :MEDCLOTDAT_N.CREATE_TIME,
                :MEDCLOTDAT_N.UPDATE_USER_ID,
                :MEDCLOTDAT_N.UPDATE_TIME,
                :MEDCLOTDAT_N.DELETE_USER_ID,
                :MEDCLOTDAT_N.DELETE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1322;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCLOTDAT_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MEDCLOTDAT_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCLOTDAT_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCLOTDAT_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCLOTDAT_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCLOTDAT_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCLOTDAT_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCLOTDAT_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MEDCLOTDAT_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCLOTDAT_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCLOTDAT_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCLOTDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MEDCLOTDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCLOTDAT_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCLOTDAT_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCLOTDAT_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCLOTDAT_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCLOTDAT_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCLOTDAT_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCLOTDAT_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCLOTDAT_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCLOTDAT_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCLOTDAT_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCLOTDAT_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MEDCLOTDAT_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MEDCLOTDAT_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MEDCLOTDAT_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MEDCLOTDAT_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MEDCLOTDAT_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MEDCLOTDAT_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MEDCLOTDAT_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MEDCLOTDAT_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MEDCLOTDAT_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MEDCLOTDAT_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MEDCLOTDAT_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MEDCLOTDAT_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MEDCLOTDAT_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MEDCLOTDAT_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MEDCLOTDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MEDCLOTDAT_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MEDCLOTDAT_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MEDCLOTDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MEDCLOTDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MEDCLOTDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MEDCLOTDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MEDCLOTDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MEDCLOTDAT_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MEDCLOTDAT_N.DELETE_TIME);
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

		case 2:
            /* EXEC SQL FETCH DBU_MEDCLOTDAT_CUR_2 INTO
                :MEDCLOTDAT_N.LOT_ID,
                :MEDCLOTDAT_N.HIST_SEQ,
                :MEDCLOTDAT_N.COL_SEQ,
                :MEDCLOTDAT_N.TRAN_TIME,
                :MEDCLOTDAT_N.HIST_DEL_FLAG,
                :MEDCLOTDAT_N.FACTORY,
                :MEDCLOTDAT_N.MAT_ID,
                :MEDCLOTDAT_N.MAT_VER,
                :MEDCLOTDAT_N.FLOW,
                :MEDCLOTDAT_N.OPER,
                :MEDCLOTDAT_N.MEAS_RES_ID,
                :MEDCLOTDAT_N.PROC_FLOW,
                :MEDCLOTDAT_N.PROC_OPER,
                :MEDCLOTDAT_N.PROC_RES_ID,
                :MEDCLOTDAT_N.RECIPE_ID,
                :MEDCLOTDAT_N.RECIPE_VERSION,
                :MEDCLOTDAT_N.COL_SET_ID,
                :MEDCLOTDAT_N.COL_SET_VERSION,
                :MEDCLOTDAT_N.CHAR_SEQ_NUM,
                :MEDCLOTDAT_N.CHAR_ID,
                :MEDCLOTDAT_N.UNIT_SEQ_NUM,
                :MEDCLOTDAT_N.UNIT_ID,
                :MEDCLOTDAT_N.VALUE_SEQ_NUM,
                :MEDCLOTDAT_N.VALUE_TYPE,
                :MEDCLOTDAT_N.VALUE_COUNT,
                :MEDCLOTDAT_N.VALUE_1,
                :MEDCLOTDAT_N.VALUE_2,
                :MEDCLOTDAT_N.VALUE_3,
                :MEDCLOTDAT_N.VALUE_4,
                :MEDCLOTDAT_N.VALUE_5,
                :MEDCLOTDAT_N.VALUE_6,
                :MEDCLOTDAT_N.VALUE_7,
                :MEDCLOTDAT_N.VALUE_8,
                :MEDCLOTDAT_N.VALUE_9,
                :MEDCLOTDAT_N.VALUE_10,
                :MEDCLOTDAT_N.VALUE_11,
                :MEDCLOTDAT_N.VALUE_12,
                :MEDCLOTDAT_N.VALUE_13,
                :MEDCLOTDAT_N.VALUE_14,
                :MEDCLOTDAT_N.VALUE_15,
                :MEDCLOTDAT_N.VALUE_16,
                :MEDCLOTDAT_N.VALUE_17,
                :MEDCLOTDAT_N.VALUE_18,
                :MEDCLOTDAT_N.VALUE_19,
                :MEDCLOTDAT_N.VALUE_20,
                :MEDCLOTDAT_N.VALUE_21,
                :MEDCLOTDAT_N.VALUE_22,
                :MEDCLOTDAT_N.VALUE_23,
                :MEDCLOTDAT_N.VALUE_24,
                :MEDCLOTDAT_N.VALUE_25,
                :MEDCLOTDAT_N.SAMPLE_COUNT,
                :MEDCLOTDAT_N.NOMINAL,
                :MEDCLOTDAT_N.PROCESS_SIGMA,
                :MEDCLOTDAT_N.SPEC_OUT_MASK,
                :MEDCLOTDAT_N.CREATE_USER_ID,
                :MEDCLOTDAT_N.CREATE_TIME,
                :MEDCLOTDAT_N.UPDATE_USER_ID,
                :MEDCLOTDAT_N.UPDATE_TIME,
                :MEDCLOTDAT_N.DELETE_USER_ID,
                :MEDCLOTDAT_N.DELETE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1577;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MEDCLOTDAT_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MEDCLOTDAT_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MEDCLOTDAT_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MEDCLOTDAT_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MEDCLOTDAT_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MEDCLOTDAT_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MEDCLOTDAT_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MEDCLOTDAT_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MEDCLOTDAT_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MEDCLOTDAT_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MEDCLOTDAT_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MEDCLOTDAT_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MEDCLOTDAT_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MEDCLOTDAT_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MEDCLOTDAT_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MEDCLOTDAT_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MEDCLOTDAT_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MEDCLOTDAT_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MEDCLOTDAT_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MEDCLOTDAT_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MEDCLOTDAT_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MEDCLOTDAT_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MEDCLOTDAT_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MEDCLOTDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MEDCLOTDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MEDCLOTDAT_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MEDCLOTDAT_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MEDCLOTDAT_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MEDCLOTDAT_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MEDCLOTDAT_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MEDCLOTDAT_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MEDCLOTDAT_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MEDCLOTDAT_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MEDCLOTDAT_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MEDCLOTDAT_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MEDCLOTDAT_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MEDCLOTDAT_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MEDCLOTDAT_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MEDCLOTDAT_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MEDCLOTDAT_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MEDCLOTDAT_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MEDCLOTDAT_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MEDCLOTDAT_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MEDCLOTDAT_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MEDCLOTDAT_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MEDCLOTDAT_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MEDCLOTDAT_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MEDCLOTDAT_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MEDCLOTDAT_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MEDCLOTDAT_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MEDCLOTDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MEDCLOTDAT_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MEDCLOTDAT_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MEDCLOTDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MEDCLOTDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MEDCLOTDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MEDCLOTDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MEDCLOTDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MEDCLOTDAT_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MEDCLOTDAT_N.DELETE_TIME);
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
        DBU_del_null_medclotdat(&MEDCLOTDAT_N, MEDCLOTDAT);
    }

    DB_stop_query_timer("DBU_fetch_medclotdat", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_medclotdat(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MEDCLOTDAT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1832;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL CLOSE DBU_MEDCLOTDAT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 67;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1847;
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

    DB_stop_query_timer("DBU_close_medclotdat", sel_type);
}


/* Initialize Function */
void DBU_init_medclotdat(struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* memset by Space */
    memset(MEDCLOTDAT, ' ', sizeof(struct MEDCLOTDAT_TAG));
    
    MEDCLOTDAT->HIST_SEQ = 0;
    MEDCLOTDAT->COL_SEQ = 0;
    MEDCLOTDAT->MAT_VER = 0;
    MEDCLOTDAT->RECIPE_VERSION = 0;
    MEDCLOTDAT->COL_SET_VERSION = 0;
    MEDCLOTDAT->CHAR_SEQ_NUM = 0;
    MEDCLOTDAT->UNIT_SEQ_NUM = 0;
    MEDCLOTDAT->VALUE_SEQ_NUM = 0;
    MEDCLOTDAT->VALUE_COUNT = 0;
    MEDCLOTDAT->SAMPLE_COUNT = 0;
}


/* Add Null Function */
void DBU_add_null_medclotdat(struct MEDCLOTDAT_N_TAG *MEDCLOTDAT_N, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    /* memset by NULL */
    memset(MEDCLOTDAT_N, '\0', sizeof(struct MEDCLOTDAT_N_TAG));
    
    MEMCPY_AN(MEDCLOTDAT_N->LOT_ID, MEDCLOTDAT->LOT_ID, sizeof(MEDCLOTDAT->LOT_ID));
    MEDCLOTDAT_N->HIST_SEQ = MEDCLOTDAT->HIST_SEQ;
    MEDCLOTDAT_N->COL_SEQ = MEDCLOTDAT->COL_SEQ;
    MEMCPY_AN(MEDCLOTDAT_N->TRAN_TIME, MEDCLOTDAT->TRAN_TIME, sizeof(MEDCLOTDAT->TRAN_TIME));
    MEDCLOTDAT_N->HIST_DEL_FLAG[0] = MEDCLOTDAT->HIST_DEL_FLAG;
    MEMCPY_AN(MEDCLOTDAT_N->FACTORY, MEDCLOTDAT->FACTORY, sizeof(MEDCLOTDAT->FACTORY));
    MEMCPY_AN(MEDCLOTDAT_N->MAT_ID, MEDCLOTDAT->MAT_ID, sizeof(MEDCLOTDAT->MAT_ID));
    MEDCLOTDAT_N->MAT_VER = MEDCLOTDAT->MAT_VER;
    MEMCPY_AN(MEDCLOTDAT_N->FLOW, MEDCLOTDAT->FLOW, sizeof(MEDCLOTDAT->FLOW));
    MEMCPY_AN(MEDCLOTDAT_N->OPER, MEDCLOTDAT->OPER, sizeof(MEDCLOTDAT->OPER));
    MEMCPY_AN(MEDCLOTDAT_N->MEAS_RES_ID, MEDCLOTDAT->MEAS_RES_ID, sizeof(MEDCLOTDAT->MEAS_RES_ID));
    MEMCPY_AN(MEDCLOTDAT_N->PROC_FLOW, MEDCLOTDAT->PROC_FLOW, sizeof(MEDCLOTDAT->PROC_FLOW));
    MEMCPY_AN(MEDCLOTDAT_N->PROC_OPER, MEDCLOTDAT->PROC_OPER, sizeof(MEDCLOTDAT->PROC_OPER));
    MEMCPY_AN(MEDCLOTDAT_N->PROC_RES_ID, MEDCLOTDAT->PROC_RES_ID, sizeof(MEDCLOTDAT->PROC_RES_ID));
    MEMCPY_AN(MEDCLOTDAT_N->RECIPE_ID, MEDCLOTDAT->RECIPE_ID, sizeof(MEDCLOTDAT->RECIPE_ID));
    MEDCLOTDAT_N->RECIPE_VERSION = MEDCLOTDAT->RECIPE_VERSION;
    MEMCPY_AN(MEDCLOTDAT_N->COL_SET_ID, MEDCLOTDAT->COL_SET_ID, sizeof(MEDCLOTDAT->COL_SET_ID));
    MEDCLOTDAT_N->COL_SET_VERSION = MEDCLOTDAT->COL_SET_VERSION;
    MEDCLOTDAT_N->CHAR_SEQ_NUM = MEDCLOTDAT->CHAR_SEQ_NUM;
    MEMCPY_AN(MEDCLOTDAT_N->CHAR_ID, MEDCLOTDAT->CHAR_ID, sizeof(MEDCLOTDAT->CHAR_ID));
    MEDCLOTDAT_N->UNIT_SEQ_NUM = MEDCLOTDAT->UNIT_SEQ_NUM;
    MEMCPY_AN(MEDCLOTDAT_N->UNIT_ID, MEDCLOTDAT->UNIT_ID, sizeof(MEDCLOTDAT->UNIT_ID));
    MEDCLOTDAT_N->VALUE_SEQ_NUM = MEDCLOTDAT->VALUE_SEQ_NUM;
    MEDCLOTDAT_N->VALUE_TYPE[0] = MEDCLOTDAT->VALUE_TYPE;
    MEDCLOTDAT_N->VALUE_COUNT = MEDCLOTDAT->VALUE_COUNT;
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_1, MEDCLOTDAT->VALUE_1, sizeof(MEDCLOTDAT->VALUE_1));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_2, MEDCLOTDAT->VALUE_2, sizeof(MEDCLOTDAT->VALUE_2));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_3, MEDCLOTDAT->VALUE_3, sizeof(MEDCLOTDAT->VALUE_3));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_4, MEDCLOTDAT->VALUE_4, sizeof(MEDCLOTDAT->VALUE_4));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_5, MEDCLOTDAT->VALUE_5, sizeof(MEDCLOTDAT->VALUE_5));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_6, MEDCLOTDAT->VALUE_6, sizeof(MEDCLOTDAT->VALUE_6));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_7, MEDCLOTDAT->VALUE_7, sizeof(MEDCLOTDAT->VALUE_7));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_8, MEDCLOTDAT->VALUE_8, sizeof(MEDCLOTDAT->VALUE_8));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_9, MEDCLOTDAT->VALUE_9, sizeof(MEDCLOTDAT->VALUE_9));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_10, MEDCLOTDAT->VALUE_10, sizeof(MEDCLOTDAT->VALUE_10));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_11, MEDCLOTDAT->VALUE_11, sizeof(MEDCLOTDAT->VALUE_11));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_12, MEDCLOTDAT->VALUE_12, sizeof(MEDCLOTDAT->VALUE_12));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_13, MEDCLOTDAT->VALUE_13, sizeof(MEDCLOTDAT->VALUE_13));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_14, MEDCLOTDAT->VALUE_14, sizeof(MEDCLOTDAT->VALUE_14));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_15, MEDCLOTDAT->VALUE_15, sizeof(MEDCLOTDAT->VALUE_15));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_16, MEDCLOTDAT->VALUE_16, sizeof(MEDCLOTDAT->VALUE_16));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_17, MEDCLOTDAT->VALUE_17, sizeof(MEDCLOTDAT->VALUE_17));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_18, MEDCLOTDAT->VALUE_18, sizeof(MEDCLOTDAT->VALUE_18));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_19, MEDCLOTDAT->VALUE_19, sizeof(MEDCLOTDAT->VALUE_19));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_20, MEDCLOTDAT->VALUE_20, sizeof(MEDCLOTDAT->VALUE_20));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_21, MEDCLOTDAT->VALUE_21, sizeof(MEDCLOTDAT->VALUE_21));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_22, MEDCLOTDAT->VALUE_22, sizeof(MEDCLOTDAT->VALUE_22));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_23, MEDCLOTDAT->VALUE_23, sizeof(MEDCLOTDAT->VALUE_23));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_24, MEDCLOTDAT->VALUE_24, sizeof(MEDCLOTDAT->VALUE_24));
    MEMCPY_AN(MEDCLOTDAT_N->VALUE_25, MEDCLOTDAT->VALUE_25, sizeof(MEDCLOTDAT->VALUE_25));
    MEDCLOTDAT_N->SAMPLE_COUNT = MEDCLOTDAT->SAMPLE_COUNT;
    MEMCPY_AN(MEDCLOTDAT_N->NOMINAL, MEDCLOTDAT->NOMINAL, sizeof(MEDCLOTDAT->NOMINAL));
    MEMCPY_AN(MEDCLOTDAT_N->PROCESS_SIGMA, MEDCLOTDAT->PROCESS_SIGMA, sizeof(MEDCLOTDAT->PROCESS_SIGMA));
    MEMCPY_AN(MEDCLOTDAT_N->SPEC_OUT_MASK, MEDCLOTDAT->SPEC_OUT_MASK, sizeof(MEDCLOTDAT->SPEC_OUT_MASK));
    MEMCPY_AN(MEDCLOTDAT_N->CREATE_USER_ID, MEDCLOTDAT->CREATE_USER_ID, sizeof(MEDCLOTDAT->CREATE_USER_ID));
    MEMCPY_AN(MEDCLOTDAT_N->CREATE_TIME, MEDCLOTDAT->CREATE_TIME, sizeof(MEDCLOTDAT->CREATE_TIME));
    MEMCPY_AN(MEDCLOTDAT_N->UPDATE_USER_ID, MEDCLOTDAT->UPDATE_USER_ID, sizeof(MEDCLOTDAT->UPDATE_USER_ID));
    MEMCPY_AN(MEDCLOTDAT_N->UPDATE_TIME, MEDCLOTDAT->UPDATE_TIME, sizeof(MEDCLOTDAT->UPDATE_TIME));
    MEMCPY_AN(MEDCLOTDAT_N->DELETE_USER_ID, MEDCLOTDAT->DELETE_USER_ID, sizeof(MEDCLOTDAT->DELETE_USER_ID));
    MEMCPY_AN(MEDCLOTDAT_N->DELETE_TIME, MEDCLOTDAT->DELETE_TIME, sizeof(MEDCLOTDAT->DELETE_TIME));
}


/* Del Null Function */
void DBU_del_null_medclotdat(struct MEDCLOTDAT_N_TAG *MEDCLOTDAT_N, struct MEDCLOTDAT_TAG *MEDCLOTDAT)
{
    MEMCPY_DN(MEDCLOTDAT->LOT_ID, MEDCLOTDAT_N->LOT_ID, sizeof(MEDCLOTDAT->LOT_ID));
    MEDCLOTDAT->HIST_SEQ = MEDCLOTDAT_N->HIST_SEQ;
    MEDCLOTDAT->COL_SEQ = MEDCLOTDAT_N->COL_SEQ;
    MEMCPY_DN(MEDCLOTDAT->TRAN_TIME, MEDCLOTDAT_N->TRAN_TIME, sizeof(MEDCLOTDAT->TRAN_TIME));
    MEDCLOTDAT->HIST_DEL_FLAG = MEDCLOTDAT_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MEDCLOTDAT->FACTORY, MEDCLOTDAT_N->FACTORY, sizeof(MEDCLOTDAT->FACTORY));
    MEMCPY_DN(MEDCLOTDAT->MAT_ID, MEDCLOTDAT_N->MAT_ID, sizeof(MEDCLOTDAT->MAT_ID));
    MEDCLOTDAT->MAT_VER = MEDCLOTDAT_N->MAT_VER;
    MEMCPY_DN(MEDCLOTDAT->FLOW, MEDCLOTDAT_N->FLOW, sizeof(MEDCLOTDAT->FLOW));
    MEMCPY_DN(MEDCLOTDAT->OPER, MEDCLOTDAT_N->OPER, sizeof(MEDCLOTDAT->OPER));
    MEMCPY_DN(MEDCLOTDAT->MEAS_RES_ID, MEDCLOTDAT_N->MEAS_RES_ID, sizeof(MEDCLOTDAT->MEAS_RES_ID));
    MEMCPY_DN(MEDCLOTDAT->PROC_FLOW, MEDCLOTDAT_N->PROC_FLOW, sizeof(MEDCLOTDAT->PROC_FLOW));
    MEMCPY_DN(MEDCLOTDAT->PROC_OPER, MEDCLOTDAT_N->PROC_OPER, sizeof(MEDCLOTDAT->PROC_OPER));
    MEMCPY_DN(MEDCLOTDAT->PROC_RES_ID, MEDCLOTDAT_N->PROC_RES_ID, sizeof(MEDCLOTDAT->PROC_RES_ID));
    MEMCPY_DN(MEDCLOTDAT->RECIPE_ID, MEDCLOTDAT_N->RECIPE_ID, sizeof(MEDCLOTDAT->RECIPE_ID));
    MEDCLOTDAT->RECIPE_VERSION = MEDCLOTDAT_N->RECIPE_VERSION;
    MEMCPY_DN(MEDCLOTDAT->COL_SET_ID, MEDCLOTDAT_N->COL_SET_ID, sizeof(MEDCLOTDAT->COL_SET_ID));
    MEDCLOTDAT->COL_SET_VERSION = MEDCLOTDAT_N->COL_SET_VERSION;
    MEDCLOTDAT->CHAR_SEQ_NUM = MEDCLOTDAT_N->CHAR_SEQ_NUM;
    MEMCPY_DN(MEDCLOTDAT->CHAR_ID, MEDCLOTDAT_N->CHAR_ID, sizeof(MEDCLOTDAT->CHAR_ID));
    MEDCLOTDAT->UNIT_SEQ_NUM = MEDCLOTDAT_N->UNIT_SEQ_NUM;
    MEMCPY_DN(MEDCLOTDAT->UNIT_ID, MEDCLOTDAT_N->UNIT_ID, sizeof(MEDCLOTDAT->UNIT_ID));
    MEDCLOTDAT->VALUE_SEQ_NUM = MEDCLOTDAT_N->VALUE_SEQ_NUM;
    MEDCLOTDAT->VALUE_TYPE = MEDCLOTDAT_N->VALUE_TYPE[0];
    MEDCLOTDAT->VALUE_COUNT = MEDCLOTDAT_N->VALUE_COUNT;
    MEMCPY_DN(MEDCLOTDAT->VALUE_1, MEDCLOTDAT_N->VALUE_1, sizeof(MEDCLOTDAT->VALUE_1));
    MEMCPY_DN(MEDCLOTDAT->VALUE_2, MEDCLOTDAT_N->VALUE_2, sizeof(MEDCLOTDAT->VALUE_2));
    MEMCPY_DN(MEDCLOTDAT->VALUE_3, MEDCLOTDAT_N->VALUE_3, sizeof(MEDCLOTDAT->VALUE_3));
    MEMCPY_DN(MEDCLOTDAT->VALUE_4, MEDCLOTDAT_N->VALUE_4, sizeof(MEDCLOTDAT->VALUE_4));
    MEMCPY_DN(MEDCLOTDAT->VALUE_5, MEDCLOTDAT_N->VALUE_5, sizeof(MEDCLOTDAT->VALUE_5));
    MEMCPY_DN(MEDCLOTDAT->VALUE_6, MEDCLOTDAT_N->VALUE_6, sizeof(MEDCLOTDAT->VALUE_6));
    MEMCPY_DN(MEDCLOTDAT->VALUE_7, MEDCLOTDAT_N->VALUE_7, sizeof(MEDCLOTDAT->VALUE_7));
    MEMCPY_DN(MEDCLOTDAT->VALUE_8, MEDCLOTDAT_N->VALUE_8, sizeof(MEDCLOTDAT->VALUE_8));
    MEMCPY_DN(MEDCLOTDAT->VALUE_9, MEDCLOTDAT_N->VALUE_9, sizeof(MEDCLOTDAT->VALUE_9));
    MEMCPY_DN(MEDCLOTDAT->VALUE_10, MEDCLOTDAT_N->VALUE_10, sizeof(MEDCLOTDAT->VALUE_10));
    MEMCPY_DN(MEDCLOTDAT->VALUE_11, MEDCLOTDAT_N->VALUE_11, sizeof(MEDCLOTDAT->VALUE_11));
    MEMCPY_DN(MEDCLOTDAT->VALUE_12, MEDCLOTDAT_N->VALUE_12, sizeof(MEDCLOTDAT->VALUE_12));
    MEMCPY_DN(MEDCLOTDAT->VALUE_13, MEDCLOTDAT_N->VALUE_13, sizeof(MEDCLOTDAT->VALUE_13));
    MEMCPY_DN(MEDCLOTDAT->VALUE_14, MEDCLOTDAT_N->VALUE_14, sizeof(MEDCLOTDAT->VALUE_14));
    MEMCPY_DN(MEDCLOTDAT->VALUE_15, MEDCLOTDAT_N->VALUE_15, sizeof(MEDCLOTDAT->VALUE_15));
    MEMCPY_DN(MEDCLOTDAT->VALUE_16, MEDCLOTDAT_N->VALUE_16, sizeof(MEDCLOTDAT->VALUE_16));
    MEMCPY_DN(MEDCLOTDAT->VALUE_17, MEDCLOTDAT_N->VALUE_17, sizeof(MEDCLOTDAT->VALUE_17));
    MEMCPY_DN(MEDCLOTDAT->VALUE_18, MEDCLOTDAT_N->VALUE_18, sizeof(MEDCLOTDAT->VALUE_18));
    MEMCPY_DN(MEDCLOTDAT->VALUE_19, MEDCLOTDAT_N->VALUE_19, sizeof(MEDCLOTDAT->VALUE_19));
    MEMCPY_DN(MEDCLOTDAT->VALUE_20, MEDCLOTDAT_N->VALUE_20, sizeof(MEDCLOTDAT->VALUE_20));
    MEMCPY_DN(MEDCLOTDAT->VALUE_21, MEDCLOTDAT_N->VALUE_21, sizeof(MEDCLOTDAT->VALUE_21));
    MEMCPY_DN(MEDCLOTDAT->VALUE_22, MEDCLOTDAT_N->VALUE_22, sizeof(MEDCLOTDAT->VALUE_22));
    MEMCPY_DN(MEDCLOTDAT->VALUE_23, MEDCLOTDAT_N->VALUE_23, sizeof(MEDCLOTDAT->VALUE_23));
    MEMCPY_DN(MEDCLOTDAT->VALUE_24, MEDCLOTDAT_N->VALUE_24, sizeof(MEDCLOTDAT->VALUE_24));
    MEMCPY_DN(MEDCLOTDAT->VALUE_25, MEDCLOTDAT_N->VALUE_25, sizeof(MEDCLOTDAT->VALUE_25));
    MEDCLOTDAT->SAMPLE_COUNT = MEDCLOTDAT_N->SAMPLE_COUNT;
    MEMCPY_DN(MEDCLOTDAT->NOMINAL, MEDCLOTDAT_N->NOMINAL, sizeof(MEDCLOTDAT->NOMINAL));
    MEMCPY_DN(MEDCLOTDAT->PROCESS_SIGMA, MEDCLOTDAT_N->PROCESS_SIGMA, sizeof(MEDCLOTDAT->PROCESS_SIGMA));
    MEMCPY_DN(MEDCLOTDAT->SPEC_OUT_MASK, MEDCLOTDAT_N->SPEC_OUT_MASK, sizeof(MEDCLOTDAT->SPEC_OUT_MASK));
    MEMCPY_DN(MEDCLOTDAT->CREATE_USER_ID, MEDCLOTDAT_N->CREATE_USER_ID, sizeof(MEDCLOTDAT->CREATE_USER_ID));
    MEMCPY_DN(MEDCLOTDAT->CREATE_TIME, MEDCLOTDAT_N->CREATE_TIME, sizeof(MEDCLOTDAT->CREATE_TIME));
    MEMCPY_DN(MEDCLOTDAT->UPDATE_USER_ID, MEDCLOTDAT_N->UPDATE_USER_ID, sizeof(MEDCLOTDAT->UPDATE_USER_ID));
    MEMCPY_DN(MEDCLOTDAT->UPDATE_TIME, MEDCLOTDAT_N->UPDATE_TIME, sizeof(MEDCLOTDAT->UPDATE_TIME));
    MEMCPY_DN(MEDCLOTDAT->DELETE_USER_ID, MEDCLOTDAT_N->DELETE_USER_ID, sizeof(MEDCLOTDAT->DELETE_USER_ID));
    MEMCPY_DN(MEDCLOTDAT->DELETE_TIME, MEDCLOTDAT_N->DELETE_TIME, sizeof(MEDCLOTDAT->DELETE_TIME));
}


