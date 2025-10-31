
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
    "DBU_cwipinvldm.pc"
};


static unsigned int sqlctx = 9397059;


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
            void  *sqhstv[39];
   unsigned int   sqhstl[39];
            int   sqhsts[39];
            void  *sqindv[39];
            int   sqinds[39];
   unsigned int   sqharm[39];
   unsigned int   *sqharc[39];
   unsigned short  sqadto[39];
   unsigned short  sqtdso[39];
} sqlstm = {13,39};

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

 static const char *sq0018 = 
"select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID ,SUB_AREA_ID ,FLOW ,OPER ,OR\
DER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,MAT_ID ,MAT_VER ,OUT_OPER ,L\
OT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from\
 CWIPINVLDM  order by FACTORY asc ,REL_LEVEL asc ,INV_LOT_ID asc ,OPER asc ,O\
RDER_ID asc ,RES_ID asc ,LOT_ID asc             ";

 static const char *sq0019 = 
"select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID ,SUB_AREA_ID ,FLOW ,OPER ,OR\
DER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,MAT_ID ,MAT_VER ,OUT_OPER ,L\
OT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from\
 CWIPINVLDM where ((FACTORY=:b0 and REL_LEVEL=:b1) and OPER=:b2) order by MAT\
_ID,TRAN_TIME,INV_LOT_ID            ";

 static const char *sq0020 = 
"select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID ,SUB_AREA_ID ,FLOW ,OPER ,OR\
DER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,MAT_ID ,MAT_VER ,OUT_OPER ,L\
OT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from\
 CWIPINVLDM where (((FACTORY=:b0 and REL_LEVEL=:b1) and OPER=:b2) and ORDER_I\
D=:b3) order by MAT_ID,TRAN_TIME,INV_LOT_ID            ";

 static const char *sq0021 = 
"select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID ,SUB_AREA_ID ,FLOW ,OPER ,OR\
DER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,MAT_ID ,MAT_VER ,OUT_OPER ,L\
OT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,\
CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from\
 CWIPINVLDM where ((FACTORY=:b0 and REL_LEVEL=:b1) and LOT_ID=:b2) order by M\
AT_ID,TRAN_TIME,INV_LOT_ID            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,599,0,4,46,0,0,39,7,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
176,0,0,2,546,0,4,123,0,0,36,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
335,0,0,3,565,0,4,197,0,0,37,5,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
498,0,0,4,548,0,4,272,0,0,36,4,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
657,0,0,5,611,0,4,379,0,0,39,7,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
828,0,0,6,169,0,4,492,0,0,8,7,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,
875,0,0,7,102,0,4,505,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
902,0,0,8,131,0,4,514,0,0,6,5,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,
941,0,0,9,81,0,4,525,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
968,0,0,10,151,0,2,562,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,
1011,0,0,11,77,0,2,573,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1038,0,0,12,96,0,2,580,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1069,0,0,13,79,0,2,588,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1096,0,0,14,63,0,2,595,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1119,0,0,15,446,0,3,625,0,0,32,32,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,
1262,0,0,16,477,0,5,714,0,0,32,32,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,
1405,0,0,17,103,0,5,750,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,
1440,0,0,18,431,0,9,827,0,0,0,0,0,1,0,
1455,0,0,19,419,0,9,870,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1482,0,0,20,438,0,9,914,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1513,0,0,21,421,0,9,957,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1540,0,0,18,0,0,13,985,0,0,32,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,
1683,0,0,19,0,0,13,1021,0,0,32,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,
1826,0,0,20,0,0,13,1057,0,0,32,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,
1969,0,0,21,0,0,13,1093,0,0,32,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,
2112,0,0,18,0,0,15,1154,0,0,0,0,0,1,0,
2127,0,0,19,0,0,15,1158,0,0,0,0,0,1,0,
2142,0,0,20,0,0,15,1162,0,0,0,0,0,1,0,
2157,0,0,21,0,0,15,1166,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cwipinvldm.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-13 18:56:52
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
void DBU_add_null_cwipinvldm(struct CWIPINVLDM_N_TAG *CWIPINVLDM_N, struct CWIPINVLDM_TAG *CWIPINVLDM);
void DBU_del_null_cwipinvldm(struct CWIPINVLDM_N_TAG *CWIPINVLDM_N, struct CWIPINVLDM_TAG *CWIPINVLDM);


/* SQL SELECT Function */
void DBU_select_cwipinvldm(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
             /* EXEC SQL SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                    :CWIPINVLDM_N.FACTORY,
                    :CWIPINVLDM_N.REL_LEVEL,
                    :CWIPINVLDM_N.INV_LOT_ID,
                    :CWIPINVLDM_N.AREA_ID,
                    :CWIPINVLDM_N.SUB_AREA_ID,
                    :CWIPINVLDM_N.FLOW,
                    :CWIPINVLDM_N.OPER,
                    :CWIPINVLDM_N.ORDER_ID,
                    :CWIPINVLDM_N.RES_ID,
                    :CWIPINVLDM_N.LOT_ID,
                    :CWIPINVLDM_N.BOM_QTY,
                    :CWIPINVLDM_N.QTY,
                    :CWIPINVLDM_N.TRAN_TIME,
                    :CWIPINVLDM_N.MAT_ID,
                    :CWIPINVLDM_N.MAT_VER,
                    :CWIPINVLDM_N.OUT_OPER,
                    :CWIPINVLDM_N.LOT_TYPE,
                    :CWIPINVLDM_N.INPUT_TYPE,
                    :CWIPINVLDM_N.CMF_1,
                    :CWIPINVLDM_N.CMF_2,
                    :CWIPINVLDM_N.CMF_3,
                    :CWIPINVLDM_N.CMF_4,
                    :CWIPINVLDM_N.CMF_5,
                    :CWIPINVLDM_N.CMF_6,
                    :CWIPINVLDM_N.CMF_7,
                    :CWIPINVLDM_N.CMF_8,
                    :CWIPINVLDM_N.CMF_9,
                    :CWIPINVLDM_N.CMF_10,
                    :CWIPINVLDM_N.CREATE_USER_ID,
                    :CWIPINVLDM_N.CREATE_TIME,
                    :CWIPINVLDM_N.UPDATE_USER_ID,
                    :CWIPINVLDM_N.UPDATE_TIME
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND RES_ID = :CWIPINVLDM_N.RES_ID
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 13;
             sqlstm.arrsiz = 39;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID \
,SUB_AREA_ID ,FLOW ,OPER ,ORDER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,\
MAT_ID ,MAT_VER ,OUT_OPER ,LOT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,\
CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDAT\
E_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11\
,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:\
b27,:b28,:b29,:b30,:b31  from CWIPINVLDM where ((((((FACTORY=:b0 and REL_LEVE\
L=:b1) and INV_LOT_ID=:b2) and OPER=:b6) and ORDER_ID=:b7) and RES_ID=:b8) an\
d LOT_ID=:b9)";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )5;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.sqlpfmem = (unsigned int  )0;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
             sqlstm.sqhstl[0] = (unsigned int  )11;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         void  *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned int  )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
             sqlstm.sqhstl[1] = (unsigned int  )2;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         void  *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned int  )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
             sqlstm.sqhstl[2] = (unsigned int  )26;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         void  *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned int  )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
             sqlstm.sqhstl[3] = (unsigned int  )21;
             sqlstm.sqhsts[3] = (         int  )0;
             sqlstm.sqindv[3] = (         void  *)0;
             sqlstm.sqinds[3] = (         int  )0;
             sqlstm.sqharm[3] = (unsigned int  )0;
             sqlstm.sqadto[3] = (unsigned short )0;
             sqlstm.sqtdso[3] = (unsigned short )0;
             sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
             sqlstm.sqhstl[4] = (unsigned int  )21;
             sqlstm.sqhsts[4] = (         int  )0;
             sqlstm.sqindv[4] = (         void  *)0;
             sqlstm.sqinds[4] = (         int  )0;
             sqlstm.sqharm[4] = (unsigned int  )0;
             sqlstm.sqadto[4] = (unsigned short )0;
             sqlstm.sqtdso[4] = (unsigned short )0;
             sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
             sqlstm.sqhstl[5] = (unsigned int  )21;
             sqlstm.sqhsts[5] = (         int  )0;
             sqlstm.sqindv[5] = (         void  *)0;
             sqlstm.sqinds[5] = (         int  )0;
             sqlstm.sqharm[5] = (unsigned int  )0;
             sqlstm.sqadto[5] = (unsigned short )0;
             sqlstm.sqtdso[5] = (unsigned short )0;
             sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
             sqlstm.sqhstl[6] = (unsigned int  )11;
             sqlstm.sqhsts[6] = (         int  )0;
             sqlstm.sqindv[6] = (         void  *)0;
             sqlstm.sqinds[6] = (         int  )0;
             sqlstm.sqharm[6] = (unsigned int  )0;
             sqlstm.sqadto[6] = (unsigned short )0;
             sqlstm.sqtdso[6] = (unsigned short )0;
             sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
             sqlstm.sqhstl[7] = (unsigned int  )26;
             sqlstm.sqhsts[7] = (         int  )0;
             sqlstm.sqindv[7] = (         void  *)0;
             sqlstm.sqinds[7] = (         int  )0;
             sqlstm.sqharm[7] = (unsigned int  )0;
             sqlstm.sqadto[7] = (unsigned short )0;
             sqlstm.sqtdso[7] = (unsigned short )0;
             sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
             sqlstm.sqhstl[8] = (unsigned int  )21;
             sqlstm.sqhsts[8] = (         int  )0;
             sqlstm.sqindv[8] = (         void  *)0;
             sqlstm.sqinds[8] = (         int  )0;
             sqlstm.sqharm[8] = (unsigned int  )0;
             sqlstm.sqadto[8] = (unsigned short )0;
             sqlstm.sqtdso[8] = (unsigned short )0;
             sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
             sqlstm.sqhstl[9] = (unsigned int  )26;
             sqlstm.sqhsts[9] = (         int  )0;
             sqlstm.sqindv[9] = (         void  *)0;
             sqlstm.sqinds[9] = (         int  )0;
             sqlstm.sqharm[9] = (unsigned int  )0;
             sqlstm.sqadto[9] = (unsigned short )0;
             sqlstm.sqtdso[9] = (unsigned short )0;
             sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
             sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
             sqlstm.sqhsts[10] = (         int  )0;
             sqlstm.sqindv[10] = (         void  *)0;
             sqlstm.sqinds[10] = (         int  )0;
             sqlstm.sqharm[10] = (unsigned int  )0;
             sqlstm.sqadto[10] = (unsigned short )0;
             sqlstm.sqtdso[10] = (unsigned short )0;
             sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
             sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
             sqlstm.sqhsts[11] = (         int  )0;
             sqlstm.sqindv[11] = (         void  *)0;
             sqlstm.sqinds[11] = (         int  )0;
             sqlstm.sqharm[11] = (unsigned int  )0;
             sqlstm.sqadto[11] = (unsigned short )0;
             sqlstm.sqtdso[11] = (unsigned short )0;
             sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
             sqlstm.sqhstl[12] = (unsigned int  )15;
             sqlstm.sqhsts[12] = (         int  )0;
             sqlstm.sqindv[12] = (         void  *)0;
             sqlstm.sqinds[12] = (         int  )0;
             sqlstm.sqharm[12] = (unsigned int  )0;
             sqlstm.sqadto[12] = (unsigned short )0;
             sqlstm.sqtdso[12] = (unsigned short )0;
             sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
             sqlstm.sqhstl[13] = (unsigned int  )31;
             sqlstm.sqhsts[13] = (         int  )0;
             sqlstm.sqindv[13] = (         void  *)0;
             sqlstm.sqinds[13] = (         int  )0;
             sqlstm.sqharm[13] = (unsigned int  )0;
             sqlstm.sqadto[13] = (unsigned short )0;
             sqlstm.sqtdso[13] = (unsigned short )0;
             sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
             sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
             sqlstm.sqhsts[14] = (         int  )0;
             sqlstm.sqindv[14] = (         void  *)0;
             sqlstm.sqinds[14] = (         int  )0;
             sqlstm.sqharm[14] = (unsigned int  )0;
             sqlstm.sqadto[14] = (unsigned short )0;
             sqlstm.sqtdso[14] = (unsigned short )0;
             sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
             sqlstm.sqhstl[15] = (unsigned int  )21;
             sqlstm.sqhsts[15] = (         int  )0;
             sqlstm.sqindv[15] = (         void  *)0;
             sqlstm.sqinds[15] = (         int  )0;
             sqlstm.sqharm[15] = (unsigned int  )0;
             sqlstm.sqadto[15] = (unsigned short )0;
             sqlstm.sqtdso[15] = (unsigned short )0;
             sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
             sqlstm.sqhstl[16] = (unsigned int  )11;
             sqlstm.sqhsts[16] = (         int  )0;
             sqlstm.sqindv[16] = (         void  *)0;
             sqlstm.sqinds[16] = (         int  )0;
             sqlstm.sqharm[16] = (unsigned int  )0;
             sqlstm.sqadto[16] = (unsigned short )0;
             sqlstm.sqtdso[16] = (unsigned short )0;
             sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
             sqlstm.sqhstl[17] = (unsigned int  )11;
             sqlstm.sqhsts[17] = (         int  )0;
             sqlstm.sqindv[17] = (         void  *)0;
             sqlstm.sqinds[17] = (         int  )0;
             sqlstm.sqharm[17] = (unsigned int  )0;
             sqlstm.sqadto[17] = (unsigned short )0;
             sqlstm.sqtdso[17] = (unsigned short )0;
             sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
             sqlstm.sqhstl[18] = (unsigned int  )31;
             sqlstm.sqhsts[18] = (         int  )0;
             sqlstm.sqindv[18] = (         void  *)0;
             sqlstm.sqinds[18] = (         int  )0;
             sqlstm.sqharm[18] = (unsigned int  )0;
             sqlstm.sqadto[18] = (unsigned short )0;
             sqlstm.sqtdso[18] = (unsigned short )0;
             sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
             sqlstm.sqhstl[19] = (unsigned int  )31;
             sqlstm.sqhsts[19] = (         int  )0;
             sqlstm.sqindv[19] = (         void  *)0;
             sqlstm.sqinds[19] = (         int  )0;
             sqlstm.sqharm[19] = (unsigned int  )0;
             sqlstm.sqadto[19] = (unsigned short )0;
             sqlstm.sqtdso[19] = (unsigned short )0;
             sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
             sqlstm.sqhstl[20] = (unsigned int  )31;
             sqlstm.sqhsts[20] = (         int  )0;
             sqlstm.sqindv[20] = (         void  *)0;
             sqlstm.sqinds[20] = (         int  )0;
             sqlstm.sqharm[20] = (unsigned int  )0;
             sqlstm.sqadto[20] = (unsigned short )0;
             sqlstm.sqtdso[20] = (unsigned short )0;
             sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
             sqlstm.sqhstl[21] = (unsigned int  )31;
             sqlstm.sqhsts[21] = (         int  )0;
             sqlstm.sqindv[21] = (         void  *)0;
             sqlstm.sqinds[21] = (         int  )0;
             sqlstm.sqharm[21] = (unsigned int  )0;
             sqlstm.sqadto[21] = (unsigned short )0;
             sqlstm.sqtdso[21] = (unsigned short )0;
             sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
             sqlstm.sqhstl[22] = (unsigned int  )31;
             sqlstm.sqhsts[22] = (         int  )0;
             sqlstm.sqindv[22] = (         void  *)0;
             sqlstm.sqinds[22] = (         int  )0;
             sqlstm.sqharm[22] = (unsigned int  )0;
             sqlstm.sqadto[22] = (unsigned short )0;
             sqlstm.sqtdso[22] = (unsigned short )0;
             sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
             sqlstm.sqhstl[23] = (unsigned int  )31;
             sqlstm.sqhsts[23] = (         int  )0;
             sqlstm.sqindv[23] = (         void  *)0;
             sqlstm.sqinds[23] = (         int  )0;
             sqlstm.sqharm[23] = (unsigned int  )0;
             sqlstm.sqadto[23] = (unsigned short )0;
             sqlstm.sqtdso[23] = (unsigned short )0;
             sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
             sqlstm.sqhstl[24] = (unsigned int  )31;
             sqlstm.sqhsts[24] = (         int  )0;
             sqlstm.sqindv[24] = (         void  *)0;
             sqlstm.sqinds[24] = (         int  )0;
             sqlstm.sqharm[24] = (unsigned int  )0;
             sqlstm.sqadto[24] = (unsigned short )0;
             sqlstm.sqtdso[24] = (unsigned short )0;
             sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
             sqlstm.sqhstl[25] = (unsigned int  )31;
             sqlstm.sqhsts[25] = (         int  )0;
             sqlstm.sqindv[25] = (         void  *)0;
             sqlstm.sqinds[25] = (         int  )0;
             sqlstm.sqharm[25] = (unsigned int  )0;
             sqlstm.sqadto[25] = (unsigned short )0;
             sqlstm.sqtdso[25] = (unsigned short )0;
             sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
             sqlstm.sqhstl[26] = (unsigned int  )31;
             sqlstm.sqhsts[26] = (         int  )0;
             sqlstm.sqindv[26] = (         void  *)0;
             sqlstm.sqinds[26] = (         int  )0;
             sqlstm.sqharm[26] = (unsigned int  )0;
             sqlstm.sqadto[26] = (unsigned short )0;
             sqlstm.sqtdso[26] = (unsigned short )0;
             sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
             sqlstm.sqhstl[27] = (unsigned int  )31;
             sqlstm.sqhsts[27] = (         int  )0;
             sqlstm.sqindv[27] = (         void  *)0;
             sqlstm.sqinds[27] = (         int  )0;
             sqlstm.sqharm[27] = (unsigned int  )0;
             sqlstm.sqadto[27] = (unsigned short )0;
             sqlstm.sqtdso[27] = (unsigned short )0;
             sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
             sqlstm.sqhstl[28] = (unsigned int  )21;
             sqlstm.sqhsts[28] = (         int  )0;
             sqlstm.sqindv[28] = (         void  *)0;
             sqlstm.sqinds[28] = (         int  )0;
             sqlstm.sqharm[28] = (unsigned int  )0;
             sqlstm.sqadto[28] = (unsigned short )0;
             sqlstm.sqtdso[28] = (unsigned short )0;
             sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
             sqlstm.sqhstl[29] = (unsigned int  )15;
             sqlstm.sqhsts[29] = (         int  )0;
             sqlstm.sqindv[29] = (         void  *)0;
             sqlstm.sqinds[29] = (         int  )0;
             sqlstm.sqharm[29] = (unsigned int  )0;
             sqlstm.sqadto[29] = (unsigned short )0;
             sqlstm.sqtdso[29] = (unsigned short )0;
             sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
             sqlstm.sqhstl[30] = (unsigned int  )21;
             sqlstm.sqhsts[30] = (         int  )0;
             sqlstm.sqindv[30] = (         void  *)0;
             sqlstm.sqinds[30] = (         int  )0;
             sqlstm.sqharm[30] = (unsigned int  )0;
             sqlstm.sqadto[30] = (unsigned short )0;
             sqlstm.sqtdso[30] = (unsigned short )0;
             sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
             sqlstm.sqhstl[31] = (unsigned int  )15;
             sqlstm.sqhsts[31] = (         int  )0;
             sqlstm.sqindv[31] = (         void  *)0;
             sqlstm.sqinds[31] = (         int  )0;
             sqlstm.sqharm[31] = (unsigned int  )0;
             sqlstm.sqadto[31] = (unsigned short )0;
             sqlstm.sqtdso[31] = (unsigned short )0;
             sqlstm.sqhstv[32] = (         void  *)(CWIPINVLDM_N.FACTORY);
             sqlstm.sqhstl[32] = (unsigned int  )11;
             sqlstm.sqhsts[32] = (         int  )0;
             sqlstm.sqindv[32] = (         void  *)0;
             sqlstm.sqinds[32] = (         int  )0;
             sqlstm.sqharm[32] = (unsigned int  )0;
             sqlstm.sqadto[32] = (unsigned short )0;
             sqlstm.sqtdso[32] = (unsigned short )0;
             sqlstm.sqhstv[33] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
             sqlstm.sqhstl[33] = (unsigned int  )2;
             sqlstm.sqhsts[33] = (         int  )0;
             sqlstm.sqindv[33] = (         void  *)0;
             sqlstm.sqinds[33] = (         int  )0;
             sqlstm.sqharm[33] = (unsigned int  )0;
             sqlstm.sqadto[33] = (unsigned short )0;
             sqlstm.sqtdso[33] = (unsigned short )0;
             sqlstm.sqhstv[34] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
             sqlstm.sqhstl[34] = (unsigned int  )26;
             sqlstm.sqhsts[34] = (         int  )0;
             sqlstm.sqindv[34] = (         void  *)0;
             sqlstm.sqinds[34] = (         int  )0;
             sqlstm.sqharm[34] = (unsigned int  )0;
             sqlstm.sqadto[34] = (unsigned short )0;
             sqlstm.sqtdso[34] = (unsigned short )0;
             sqlstm.sqhstv[35] = (         void  *)(CWIPINVLDM_N.OPER);
             sqlstm.sqhstl[35] = (unsigned int  )11;
             sqlstm.sqhsts[35] = (         int  )0;
             sqlstm.sqindv[35] = (         void  *)0;
             sqlstm.sqinds[35] = (         int  )0;
             sqlstm.sqharm[35] = (unsigned int  )0;
             sqlstm.sqadto[35] = (unsigned short )0;
             sqlstm.sqtdso[35] = (unsigned short )0;
             sqlstm.sqhstv[36] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
             sqlstm.sqhstl[36] = (unsigned int  )26;
             sqlstm.sqhsts[36] = (         int  )0;
             sqlstm.sqindv[36] = (         void  *)0;
             sqlstm.sqinds[36] = (         int  )0;
             sqlstm.sqharm[36] = (unsigned int  )0;
             sqlstm.sqadto[36] = (unsigned short )0;
             sqlstm.sqtdso[36] = (unsigned short )0;
             sqlstm.sqhstv[37] = (         void  *)(CWIPINVLDM_N.RES_ID);
             sqlstm.sqhstl[37] = (unsigned int  )21;
             sqlstm.sqhsts[37] = (         int  )0;
             sqlstm.sqindv[37] = (         void  *)0;
             sqlstm.sqinds[37] = (         int  )0;
             sqlstm.sqharm[37] = (unsigned int  )0;
             sqlstm.sqadto[37] = (unsigned short )0;
             sqlstm.sqtdso[37] = (unsigned short )0;
             sqlstm.sqhstv[38] = (         void  *)(CWIPINVLDM_N.LOT_ID);
             sqlstm.sqhstl[38] = (unsigned int  )26;
             sqlstm.sqhsts[38] = (         int  )0;
             sqlstm.sqindv[38] = (         void  *)0;
             sqlstm.sqinds[38] = (         int  )0;
             sqlstm.sqharm[38] = (unsigned int  )0;
             sqlstm.sqadto[38] = (unsigned short )0;
             sqlstm.sqtdso[38] = (unsigned short )0;
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
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                    :CWIPINVLDM_N.FACTORY,
                    :CWIPINVLDM_N.REL_LEVEL,
                    :CWIPINVLDM_N.INV_LOT_ID,
                    :CWIPINVLDM_N.AREA_ID,
                    :CWIPINVLDM_N.SUB_AREA_ID,
                    :CWIPINVLDM_N.FLOW,
                    :CWIPINVLDM_N.OPER,
                    :CWIPINVLDM_N.ORDER_ID,
                    :CWIPINVLDM_N.RES_ID,
                    :CWIPINVLDM_N.LOT_ID,
                    :CWIPINVLDM_N.BOM_QTY,
                    :CWIPINVLDM_N.QTY,
                    :CWIPINVLDM_N.TRAN_TIME,
                    :CWIPINVLDM_N.MAT_ID,
                    :CWIPINVLDM_N.MAT_VER,
                    :CWIPINVLDM_N.OUT_OPER,
                    :CWIPINVLDM_N.LOT_TYPE,
                    :CWIPINVLDM_N.INPUT_TYPE,
                    :CWIPINVLDM_N.CMF_1,
                    :CWIPINVLDM_N.CMF_2,
                    :CWIPINVLDM_N.CMF_3,
                    :CWIPINVLDM_N.CMF_4,
                    :CWIPINVLDM_N.CMF_5,
                    :CWIPINVLDM_N.CMF_6,
                    :CWIPINVLDM_N.CMF_7,
                    :CWIPINVLDM_N.CMF_8,
                    :CWIPINVLDM_N.CMF_9,
                    :CWIPINVLDM_N.CMF_10,
                    :CWIPINVLDM_N.CREATE_USER_ID,
                    :CWIPINVLDM_N.CREATE_TIME,
                    :CWIPINVLDM_N.UPDATE_USER_ID,
                    :CWIPINVLDM_N.UPDATE_TIME
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND OPER = :CWIPINVLDM_N.OPER; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 13;
             sqlstm.arrsiz = 39;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID \
,SUB_AREA_ID ,FLOW ,OPER ,ORDER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,\
MAT_ID ,MAT_VER ,OUT_OPER ,LOT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,\
CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDAT\
E_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11\
,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:\
b27,:b28,:b29,:b30,:b31  from CWIPINVLDM where (((FACTORY=:b0 and REL_LEVEL=:\
b1) and INV_LOT_ID=:b2) and OPER=:b6)";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )176;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.sqlpfmem = (unsigned int  )0;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
             sqlstm.sqhstl[0] = (unsigned int  )11;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         void  *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned int  )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
             sqlstm.sqhstl[1] = (unsigned int  )2;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         void  *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned int  )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
             sqlstm.sqhstl[2] = (unsigned int  )26;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         void  *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned int  )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
             sqlstm.sqhstl[3] = (unsigned int  )21;
             sqlstm.sqhsts[3] = (         int  )0;
             sqlstm.sqindv[3] = (         void  *)0;
             sqlstm.sqinds[3] = (         int  )0;
             sqlstm.sqharm[3] = (unsigned int  )0;
             sqlstm.sqadto[3] = (unsigned short )0;
             sqlstm.sqtdso[3] = (unsigned short )0;
             sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
             sqlstm.sqhstl[4] = (unsigned int  )21;
             sqlstm.sqhsts[4] = (         int  )0;
             sqlstm.sqindv[4] = (         void  *)0;
             sqlstm.sqinds[4] = (         int  )0;
             sqlstm.sqharm[4] = (unsigned int  )0;
             sqlstm.sqadto[4] = (unsigned short )0;
             sqlstm.sqtdso[4] = (unsigned short )0;
             sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
             sqlstm.sqhstl[5] = (unsigned int  )21;
             sqlstm.sqhsts[5] = (         int  )0;
             sqlstm.sqindv[5] = (         void  *)0;
             sqlstm.sqinds[5] = (         int  )0;
             sqlstm.sqharm[5] = (unsigned int  )0;
             sqlstm.sqadto[5] = (unsigned short )0;
             sqlstm.sqtdso[5] = (unsigned short )0;
             sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
             sqlstm.sqhstl[6] = (unsigned int  )11;
             sqlstm.sqhsts[6] = (         int  )0;
             sqlstm.sqindv[6] = (         void  *)0;
             sqlstm.sqinds[6] = (         int  )0;
             sqlstm.sqharm[6] = (unsigned int  )0;
             sqlstm.sqadto[6] = (unsigned short )0;
             sqlstm.sqtdso[6] = (unsigned short )0;
             sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
             sqlstm.sqhstl[7] = (unsigned int  )26;
             sqlstm.sqhsts[7] = (         int  )0;
             sqlstm.sqindv[7] = (         void  *)0;
             sqlstm.sqinds[7] = (         int  )0;
             sqlstm.sqharm[7] = (unsigned int  )0;
             sqlstm.sqadto[7] = (unsigned short )0;
             sqlstm.sqtdso[7] = (unsigned short )0;
             sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
             sqlstm.sqhstl[8] = (unsigned int  )21;
             sqlstm.sqhsts[8] = (         int  )0;
             sqlstm.sqindv[8] = (         void  *)0;
             sqlstm.sqinds[8] = (         int  )0;
             sqlstm.sqharm[8] = (unsigned int  )0;
             sqlstm.sqadto[8] = (unsigned short )0;
             sqlstm.sqtdso[8] = (unsigned short )0;
             sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
             sqlstm.sqhstl[9] = (unsigned int  )26;
             sqlstm.sqhsts[9] = (         int  )0;
             sqlstm.sqindv[9] = (         void  *)0;
             sqlstm.sqinds[9] = (         int  )0;
             sqlstm.sqharm[9] = (unsigned int  )0;
             sqlstm.sqadto[9] = (unsigned short )0;
             sqlstm.sqtdso[9] = (unsigned short )0;
             sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
             sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
             sqlstm.sqhsts[10] = (         int  )0;
             sqlstm.sqindv[10] = (         void  *)0;
             sqlstm.sqinds[10] = (         int  )0;
             sqlstm.sqharm[10] = (unsigned int  )0;
             sqlstm.sqadto[10] = (unsigned short )0;
             sqlstm.sqtdso[10] = (unsigned short )0;
             sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
             sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
             sqlstm.sqhsts[11] = (         int  )0;
             sqlstm.sqindv[11] = (         void  *)0;
             sqlstm.sqinds[11] = (         int  )0;
             sqlstm.sqharm[11] = (unsigned int  )0;
             sqlstm.sqadto[11] = (unsigned short )0;
             sqlstm.sqtdso[11] = (unsigned short )0;
             sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
             sqlstm.sqhstl[12] = (unsigned int  )15;
             sqlstm.sqhsts[12] = (         int  )0;
             sqlstm.sqindv[12] = (         void  *)0;
             sqlstm.sqinds[12] = (         int  )0;
             sqlstm.sqharm[12] = (unsigned int  )0;
             sqlstm.sqadto[12] = (unsigned short )0;
             sqlstm.sqtdso[12] = (unsigned short )0;
             sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
             sqlstm.sqhstl[13] = (unsigned int  )31;
             sqlstm.sqhsts[13] = (         int  )0;
             sqlstm.sqindv[13] = (         void  *)0;
             sqlstm.sqinds[13] = (         int  )0;
             sqlstm.sqharm[13] = (unsigned int  )0;
             sqlstm.sqadto[13] = (unsigned short )0;
             sqlstm.sqtdso[13] = (unsigned short )0;
             sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
             sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
             sqlstm.sqhsts[14] = (         int  )0;
             sqlstm.sqindv[14] = (         void  *)0;
             sqlstm.sqinds[14] = (         int  )0;
             sqlstm.sqharm[14] = (unsigned int  )0;
             sqlstm.sqadto[14] = (unsigned short )0;
             sqlstm.sqtdso[14] = (unsigned short )0;
             sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
             sqlstm.sqhstl[15] = (unsigned int  )21;
             sqlstm.sqhsts[15] = (         int  )0;
             sqlstm.sqindv[15] = (         void  *)0;
             sqlstm.sqinds[15] = (         int  )0;
             sqlstm.sqharm[15] = (unsigned int  )0;
             sqlstm.sqadto[15] = (unsigned short )0;
             sqlstm.sqtdso[15] = (unsigned short )0;
             sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
             sqlstm.sqhstl[16] = (unsigned int  )11;
             sqlstm.sqhsts[16] = (         int  )0;
             sqlstm.sqindv[16] = (         void  *)0;
             sqlstm.sqinds[16] = (         int  )0;
             sqlstm.sqharm[16] = (unsigned int  )0;
             sqlstm.sqadto[16] = (unsigned short )0;
             sqlstm.sqtdso[16] = (unsigned short )0;
             sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
             sqlstm.sqhstl[17] = (unsigned int  )11;
             sqlstm.sqhsts[17] = (         int  )0;
             sqlstm.sqindv[17] = (         void  *)0;
             sqlstm.sqinds[17] = (         int  )0;
             sqlstm.sqharm[17] = (unsigned int  )0;
             sqlstm.sqadto[17] = (unsigned short )0;
             sqlstm.sqtdso[17] = (unsigned short )0;
             sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
             sqlstm.sqhstl[18] = (unsigned int  )31;
             sqlstm.sqhsts[18] = (         int  )0;
             sqlstm.sqindv[18] = (         void  *)0;
             sqlstm.sqinds[18] = (         int  )0;
             sqlstm.sqharm[18] = (unsigned int  )0;
             sqlstm.sqadto[18] = (unsigned short )0;
             sqlstm.sqtdso[18] = (unsigned short )0;
             sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
             sqlstm.sqhstl[19] = (unsigned int  )31;
             sqlstm.sqhsts[19] = (         int  )0;
             sqlstm.sqindv[19] = (         void  *)0;
             sqlstm.sqinds[19] = (         int  )0;
             sqlstm.sqharm[19] = (unsigned int  )0;
             sqlstm.sqadto[19] = (unsigned short )0;
             sqlstm.sqtdso[19] = (unsigned short )0;
             sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
             sqlstm.sqhstl[20] = (unsigned int  )31;
             sqlstm.sqhsts[20] = (         int  )0;
             sqlstm.sqindv[20] = (         void  *)0;
             sqlstm.sqinds[20] = (         int  )0;
             sqlstm.sqharm[20] = (unsigned int  )0;
             sqlstm.sqadto[20] = (unsigned short )0;
             sqlstm.sqtdso[20] = (unsigned short )0;
             sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
             sqlstm.sqhstl[21] = (unsigned int  )31;
             sqlstm.sqhsts[21] = (         int  )0;
             sqlstm.sqindv[21] = (         void  *)0;
             sqlstm.sqinds[21] = (         int  )0;
             sqlstm.sqharm[21] = (unsigned int  )0;
             sqlstm.sqadto[21] = (unsigned short )0;
             sqlstm.sqtdso[21] = (unsigned short )0;
             sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
             sqlstm.sqhstl[22] = (unsigned int  )31;
             sqlstm.sqhsts[22] = (         int  )0;
             sqlstm.sqindv[22] = (         void  *)0;
             sqlstm.sqinds[22] = (         int  )0;
             sqlstm.sqharm[22] = (unsigned int  )0;
             sqlstm.sqadto[22] = (unsigned short )0;
             sqlstm.sqtdso[22] = (unsigned short )0;
             sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
             sqlstm.sqhstl[23] = (unsigned int  )31;
             sqlstm.sqhsts[23] = (         int  )0;
             sqlstm.sqindv[23] = (         void  *)0;
             sqlstm.sqinds[23] = (         int  )0;
             sqlstm.sqharm[23] = (unsigned int  )0;
             sqlstm.sqadto[23] = (unsigned short )0;
             sqlstm.sqtdso[23] = (unsigned short )0;
             sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
             sqlstm.sqhstl[24] = (unsigned int  )31;
             sqlstm.sqhsts[24] = (         int  )0;
             sqlstm.sqindv[24] = (         void  *)0;
             sqlstm.sqinds[24] = (         int  )0;
             sqlstm.sqharm[24] = (unsigned int  )0;
             sqlstm.sqadto[24] = (unsigned short )0;
             sqlstm.sqtdso[24] = (unsigned short )0;
             sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
             sqlstm.sqhstl[25] = (unsigned int  )31;
             sqlstm.sqhsts[25] = (         int  )0;
             sqlstm.sqindv[25] = (         void  *)0;
             sqlstm.sqinds[25] = (         int  )0;
             sqlstm.sqharm[25] = (unsigned int  )0;
             sqlstm.sqadto[25] = (unsigned short )0;
             sqlstm.sqtdso[25] = (unsigned short )0;
             sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
             sqlstm.sqhstl[26] = (unsigned int  )31;
             sqlstm.sqhsts[26] = (         int  )0;
             sqlstm.sqindv[26] = (         void  *)0;
             sqlstm.sqinds[26] = (         int  )0;
             sqlstm.sqharm[26] = (unsigned int  )0;
             sqlstm.sqadto[26] = (unsigned short )0;
             sqlstm.sqtdso[26] = (unsigned short )0;
             sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
             sqlstm.sqhstl[27] = (unsigned int  )31;
             sqlstm.sqhsts[27] = (         int  )0;
             sqlstm.sqindv[27] = (         void  *)0;
             sqlstm.sqinds[27] = (         int  )0;
             sqlstm.sqharm[27] = (unsigned int  )0;
             sqlstm.sqadto[27] = (unsigned short )0;
             sqlstm.sqtdso[27] = (unsigned short )0;
             sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
             sqlstm.sqhstl[28] = (unsigned int  )21;
             sqlstm.sqhsts[28] = (         int  )0;
             sqlstm.sqindv[28] = (         void  *)0;
             sqlstm.sqinds[28] = (         int  )0;
             sqlstm.sqharm[28] = (unsigned int  )0;
             sqlstm.sqadto[28] = (unsigned short )0;
             sqlstm.sqtdso[28] = (unsigned short )0;
             sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
             sqlstm.sqhstl[29] = (unsigned int  )15;
             sqlstm.sqhsts[29] = (         int  )0;
             sqlstm.sqindv[29] = (         void  *)0;
             sqlstm.sqinds[29] = (         int  )0;
             sqlstm.sqharm[29] = (unsigned int  )0;
             sqlstm.sqadto[29] = (unsigned short )0;
             sqlstm.sqtdso[29] = (unsigned short )0;
             sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
             sqlstm.sqhstl[30] = (unsigned int  )21;
             sqlstm.sqhsts[30] = (         int  )0;
             sqlstm.sqindv[30] = (         void  *)0;
             sqlstm.sqinds[30] = (         int  )0;
             sqlstm.sqharm[30] = (unsigned int  )0;
             sqlstm.sqadto[30] = (unsigned short )0;
             sqlstm.sqtdso[30] = (unsigned short )0;
             sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
             sqlstm.sqhstl[31] = (unsigned int  )15;
             sqlstm.sqhsts[31] = (         int  )0;
             sqlstm.sqindv[31] = (         void  *)0;
             sqlstm.sqinds[31] = (         int  )0;
             sqlstm.sqharm[31] = (unsigned int  )0;
             sqlstm.sqadto[31] = (unsigned short )0;
             sqlstm.sqtdso[31] = (unsigned short )0;
             sqlstm.sqhstv[32] = (         void  *)(CWIPINVLDM_N.FACTORY);
             sqlstm.sqhstl[32] = (unsigned int  )11;
             sqlstm.sqhsts[32] = (         int  )0;
             sqlstm.sqindv[32] = (         void  *)0;
             sqlstm.sqinds[32] = (         int  )0;
             sqlstm.sqharm[32] = (unsigned int  )0;
             sqlstm.sqadto[32] = (unsigned short )0;
             sqlstm.sqtdso[32] = (unsigned short )0;
             sqlstm.sqhstv[33] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
             sqlstm.sqhstl[33] = (unsigned int  )2;
             sqlstm.sqhsts[33] = (         int  )0;
             sqlstm.sqindv[33] = (         void  *)0;
             sqlstm.sqinds[33] = (         int  )0;
             sqlstm.sqharm[33] = (unsigned int  )0;
             sqlstm.sqadto[33] = (unsigned short )0;
             sqlstm.sqtdso[33] = (unsigned short )0;
             sqlstm.sqhstv[34] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
             sqlstm.sqhstl[34] = (unsigned int  )26;
             sqlstm.sqhsts[34] = (         int  )0;
             sqlstm.sqindv[34] = (         void  *)0;
             sqlstm.sqinds[34] = (         int  )0;
             sqlstm.sqharm[34] = (unsigned int  )0;
             sqlstm.sqadto[34] = (unsigned short )0;
             sqlstm.sqtdso[34] = (unsigned short )0;
             sqlstm.sqhstv[35] = (         void  *)(CWIPINVLDM_N.OPER);
             sqlstm.sqhstl[35] = (unsigned int  )11;
             sqlstm.sqhsts[35] = (         int  )0;
             sqlstm.sqindv[35] = (         void  *)0;
             sqlstm.sqinds[35] = (         int  )0;
             sqlstm.sqharm[35] = (unsigned int  )0;
             sqlstm.sqadto[35] = (unsigned short )0;
             sqlstm.sqtdso[35] = (unsigned short )0;
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
             /* EXEC SQL SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                    :CWIPINVLDM_N.FACTORY,
                    :CWIPINVLDM_N.REL_LEVEL,
                    :CWIPINVLDM_N.INV_LOT_ID,
                    :CWIPINVLDM_N.AREA_ID,
                    :CWIPINVLDM_N.SUB_AREA_ID,
                    :CWIPINVLDM_N.FLOW,
                    :CWIPINVLDM_N.OPER,
                    :CWIPINVLDM_N.ORDER_ID,
                    :CWIPINVLDM_N.RES_ID,
                    :CWIPINVLDM_N.LOT_ID,
                    :CWIPINVLDM_N.BOM_QTY,
                    :CWIPINVLDM_N.QTY,
                    :CWIPINVLDM_N.TRAN_TIME,
                    :CWIPINVLDM_N.MAT_ID,
                    :CWIPINVLDM_N.MAT_VER,
                    :CWIPINVLDM_N.OUT_OPER,
                    :CWIPINVLDM_N.LOT_TYPE,
                    :CWIPINVLDM_N.INPUT_TYPE,
                    :CWIPINVLDM_N.CMF_1,
                    :CWIPINVLDM_N.CMF_2,
                    :CWIPINVLDM_N.CMF_3,
                    :CWIPINVLDM_N.CMF_4,
                    :CWIPINVLDM_N.CMF_5,
                    :CWIPINVLDM_N.CMF_6,
                    :CWIPINVLDM_N.CMF_7,
                    :CWIPINVLDM_N.CMF_8,
                    :CWIPINVLDM_N.CMF_9,
                    :CWIPINVLDM_N.CMF_10,
                    :CWIPINVLDM_N.CREATE_USER_ID,
                    :CWIPINVLDM_N.CREATE_TIME,
                    :CWIPINVLDM_N.UPDATE_USER_ID,
                    :CWIPINVLDM_N.UPDATE_TIME
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND OPER = :CWIPINVLDM_N.OPER; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 13;
             sqlstm.arrsiz = 39;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID \
,SUB_AREA_ID ,FLOW ,OPER ,ORDER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,\
MAT_ID ,MAT_VER ,OUT_OPER ,LOT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,\
CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDAT\
E_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11\
,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:\
b27,:b28,:b29,:b30,:b31  from CWIPINVLDM where ((((FACTORY=:b0 and REL_LEVEL=\
:b1) and INV_LOT_ID=:b2) and ORDER_ID=:b7) and OPER=:b6)";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )335;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.sqlpfmem = (unsigned int  )0;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
             sqlstm.sqhstl[0] = (unsigned int  )11;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         void  *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned int  )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
             sqlstm.sqhstl[1] = (unsigned int  )2;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         void  *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned int  )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
             sqlstm.sqhstl[2] = (unsigned int  )26;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         void  *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned int  )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
             sqlstm.sqhstl[3] = (unsigned int  )21;
             sqlstm.sqhsts[3] = (         int  )0;
             sqlstm.sqindv[3] = (         void  *)0;
             sqlstm.sqinds[3] = (         int  )0;
             sqlstm.sqharm[3] = (unsigned int  )0;
             sqlstm.sqadto[3] = (unsigned short )0;
             sqlstm.sqtdso[3] = (unsigned short )0;
             sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
             sqlstm.sqhstl[4] = (unsigned int  )21;
             sqlstm.sqhsts[4] = (         int  )0;
             sqlstm.sqindv[4] = (         void  *)0;
             sqlstm.sqinds[4] = (         int  )0;
             sqlstm.sqharm[4] = (unsigned int  )0;
             sqlstm.sqadto[4] = (unsigned short )0;
             sqlstm.sqtdso[4] = (unsigned short )0;
             sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
             sqlstm.sqhstl[5] = (unsigned int  )21;
             sqlstm.sqhsts[5] = (         int  )0;
             sqlstm.sqindv[5] = (         void  *)0;
             sqlstm.sqinds[5] = (         int  )0;
             sqlstm.sqharm[5] = (unsigned int  )0;
             sqlstm.sqadto[5] = (unsigned short )0;
             sqlstm.sqtdso[5] = (unsigned short )0;
             sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
             sqlstm.sqhstl[6] = (unsigned int  )11;
             sqlstm.sqhsts[6] = (         int  )0;
             sqlstm.sqindv[6] = (         void  *)0;
             sqlstm.sqinds[6] = (         int  )0;
             sqlstm.sqharm[6] = (unsigned int  )0;
             sqlstm.sqadto[6] = (unsigned short )0;
             sqlstm.sqtdso[6] = (unsigned short )0;
             sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
             sqlstm.sqhstl[7] = (unsigned int  )26;
             sqlstm.sqhsts[7] = (         int  )0;
             sqlstm.sqindv[7] = (         void  *)0;
             sqlstm.sqinds[7] = (         int  )0;
             sqlstm.sqharm[7] = (unsigned int  )0;
             sqlstm.sqadto[7] = (unsigned short )0;
             sqlstm.sqtdso[7] = (unsigned short )0;
             sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
             sqlstm.sqhstl[8] = (unsigned int  )21;
             sqlstm.sqhsts[8] = (         int  )0;
             sqlstm.sqindv[8] = (         void  *)0;
             sqlstm.sqinds[8] = (         int  )0;
             sqlstm.sqharm[8] = (unsigned int  )0;
             sqlstm.sqadto[8] = (unsigned short )0;
             sqlstm.sqtdso[8] = (unsigned short )0;
             sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
             sqlstm.sqhstl[9] = (unsigned int  )26;
             sqlstm.sqhsts[9] = (         int  )0;
             sqlstm.sqindv[9] = (         void  *)0;
             sqlstm.sqinds[9] = (         int  )0;
             sqlstm.sqharm[9] = (unsigned int  )0;
             sqlstm.sqadto[9] = (unsigned short )0;
             sqlstm.sqtdso[9] = (unsigned short )0;
             sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
             sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
             sqlstm.sqhsts[10] = (         int  )0;
             sqlstm.sqindv[10] = (         void  *)0;
             sqlstm.sqinds[10] = (         int  )0;
             sqlstm.sqharm[10] = (unsigned int  )0;
             sqlstm.sqadto[10] = (unsigned short )0;
             sqlstm.sqtdso[10] = (unsigned short )0;
             sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
             sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
             sqlstm.sqhsts[11] = (         int  )0;
             sqlstm.sqindv[11] = (         void  *)0;
             sqlstm.sqinds[11] = (         int  )0;
             sqlstm.sqharm[11] = (unsigned int  )0;
             sqlstm.sqadto[11] = (unsigned short )0;
             sqlstm.sqtdso[11] = (unsigned short )0;
             sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
             sqlstm.sqhstl[12] = (unsigned int  )15;
             sqlstm.sqhsts[12] = (         int  )0;
             sqlstm.sqindv[12] = (         void  *)0;
             sqlstm.sqinds[12] = (         int  )0;
             sqlstm.sqharm[12] = (unsigned int  )0;
             sqlstm.sqadto[12] = (unsigned short )0;
             sqlstm.sqtdso[12] = (unsigned short )0;
             sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
             sqlstm.sqhstl[13] = (unsigned int  )31;
             sqlstm.sqhsts[13] = (         int  )0;
             sqlstm.sqindv[13] = (         void  *)0;
             sqlstm.sqinds[13] = (         int  )0;
             sqlstm.sqharm[13] = (unsigned int  )0;
             sqlstm.sqadto[13] = (unsigned short )0;
             sqlstm.sqtdso[13] = (unsigned short )0;
             sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
             sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
             sqlstm.sqhsts[14] = (         int  )0;
             sqlstm.sqindv[14] = (         void  *)0;
             sqlstm.sqinds[14] = (         int  )0;
             sqlstm.sqharm[14] = (unsigned int  )0;
             sqlstm.sqadto[14] = (unsigned short )0;
             sqlstm.sqtdso[14] = (unsigned short )0;
             sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
             sqlstm.sqhstl[15] = (unsigned int  )21;
             sqlstm.sqhsts[15] = (         int  )0;
             sqlstm.sqindv[15] = (         void  *)0;
             sqlstm.sqinds[15] = (         int  )0;
             sqlstm.sqharm[15] = (unsigned int  )0;
             sqlstm.sqadto[15] = (unsigned short )0;
             sqlstm.sqtdso[15] = (unsigned short )0;
             sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
             sqlstm.sqhstl[16] = (unsigned int  )11;
             sqlstm.sqhsts[16] = (         int  )0;
             sqlstm.sqindv[16] = (         void  *)0;
             sqlstm.sqinds[16] = (         int  )0;
             sqlstm.sqharm[16] = (unsigned int  )0;
             sqlstm.sqadto[16] = (unsigned short )0;
             sqlstm.sqtdso[16] = (unsigned short )0;
             sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
             sqlstm.sqhstl[17] = (unsigned int  )11;
             sqlstm.sqhsts[17] = (         int  )0;
             sqlstm.sqindv[17] = (         void  *)0;
             sqlstm.sqinds[17] = (         int  )0;
             sqlstm.sqharm[17] = (unsigned int  )0;
             sqlstm.sqadto[17] = (unsigned short )0;
             sqlstm.sqtdso[17] = (unsigned short )0;
             sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
             sqlstm.sqhstl[18] = (unsigned int  )31;
             sqlstm.sqhsts[18] = (         int  )0;
             sqlstm.sqindv[18] = (         void  *)0;
             sqlstm.sqinds[18] = (         int  )0;
             sqlstm.sqharm[18] = (unsigned int  )0;
             sqlstm.sqadto[18] = (unsigned short )0;
             sqlstm.sqtdso[18] = (unsigned short )0;
             sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
             sqlstm.sqhstl[19] = (unsigned int  )31;
             sqlstm.sqhsts[19] = (         int  )0;
             sqlstm.sqindv[19] = (         void  *)0;
             sqlstm.sqinds[19] = (         int  )0;
             sqlstm.sqharm[19] = (unsigned int  )0;
             sqlstm.sqadto[19] = (unsigned short )0;
             sqlstm.sqtdso[19] = (unsigned short )0;
             sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
             sqlstm.sqhstl[20] = (unsigned int  )31;
             sqlstm.sqhsts[20] = (         int  )0;
             sqlstm.sqindv[20] = (         void  *)0;
             sqlstm.sqinds[20] = (         int  )0;
             sqlstm.sqharm[20] = (unsigned int  )0;
             sqlstm.sqadto[20] = (unsigned short )0;
             sqlstm.sqtdso[20] = (unsigned short )0;
             sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
             sqlstm.sqhstl[21] = (unsigned int  )31;
             sqlstm.sqhsts[21] = (         int  )0;
             sqlstm.sqindv[21] = (         void  *)0;
             sqlstm.sqinds[21] = (         int  )0;
             sqlstm.sqharm[21] = (unsigned int  )0;
             sqlstm.sqadto[21] = (unsigned short )0;
             sqlstm.sqtdso[21] = (unsigned short )0;
             sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
             sqlstm.sqhstl[22] = (unsigned int  )31;
             sqlstm.sqhsts[22] = (         int  )0;
             sqlstm.sqindv[22] = (         void  *)0;
             sqlstm.sqinds[22] = (         int  )0;
             sqlstm.sqharm[22] = (unsigned int  )0;
             sqlstm.sqadto[22] = (unsigned short )0;
             sqlstm.sqtdso[22] = (unsigned short )0;
             sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
             sqlstm.sqhstl[23] = (unsigned int  )31;
             sqlstm.sqhsts[23] = (         int  )0;
             sqlstm.sqindv[23] = (         void  *)0;
             sqlstm.sqinds[23] = (         int  )0;
             sqlstm.sqharm[23] = (unsigned int  )0;
             sqlstm.sqadto[23] = (unsigned short )0;
             sqlstm.sqtdso[23] = (unsigned short )0;
             sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
             sqlstm.sqhstl[24] = (unsigned int  )31;
             sqlstm.sqhsts[24] = (         int  )0;
             sqlstm.sqindv[24] = (         void  *)0;
             sqlstm.sqinds[24] = (         int  )0;
             sqlstm.sqharm[24] = (unsigned int  )0;
             sqlstm.sqadto[24] = (unsigned short )0;
             sqlstm.sqtdso[24] = (unsigned short )0;
             sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
             sqlstm.sqhstl[25] = (unsigned int  )31;
             sqlstm.sqhsts[25] = (         int  )0;
             sqlstm.sqindv[25] = (         void  *)0;
             sqlstm.sqinds[25] = (         int  )0;
             sqlstm.sqharm[25] = (unsigned int  )0;
             sqlstm.sqadto[25] = (unsigned short )0;
             sqlstm.sqtdso[25] = (unsigned short )0;
             sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
             sqlstm.sqhstl[26] = (unsigned int  )31;
             sqlstm.sqhsts[26] = (         int  )0;
             sqlstm.sqindv[26] = (         void  *)0;
             sqlstm.sqinds[26] = (         int  )0;
             sqlstm.sqharm[26] = (unsigned int  )0;
             sqlstm.sqadto[26] = (unsigned short )0;
             sqlstm.sqtdso[26] = (unsigned short )0;
             sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
             sqlstm.sqhstl[27] = (unsigned int  )31;
             sqlstm.sqhsts[27] = (         int  )0;
             sqlstm.sqindv[27] = (         void  *)0;
             sqlstm.sqinds[27] = (         int  )0;
             sqlstm.sqharm[27] = (unsigned int  )0;
             sqlstm.sqadto[27] = (unsigned short )0;
             sqlstm.sqtdso[27] = (unsigned short )0;
             sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
             sqlstm.sqhstl[28] = (unsigned int  )21;
             sqlstm.sqhsts[28] = (         int  )0;
             sqlstm.sqindv[28] = (         void  *)0;
             sqlstm.sqinds[28] = (         int  )0;
             sqlstm.sqharm[28] = (unsigned int  )0;
             sqlstm.sqadto[28] = (unsigned short )0;
             sqlstm.sqtdso[28] = (unsigned short )0;
             sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
             sqlstm.sqhstl[29] = (unsigned int  )15;
             sqlstm.sqhsts[29] = (         int  )0;
             sqlstm.sqindv[29] = (         void  *)0;
             sqlstm.sqinds[29] = (         int  )0;
             sqlstm.sqharm[29] = (unsigned int  )0;
             sqlstm.sqadto[29] = (unsigned short )0;
             sqlstm.sqtdso[29] = (unsigned short )0;
             sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
             sqlstm.sqhstl[30] = (unsigned int  )21;
             sqlstm.sqhsts[30] = (         int  )0;
             sqlstm.sqindv[30] = (         void  *)0;
             sqlstm.sqinds[30] = (         int  )0;
             sqlstm.sqharm[30] = (unsigned int  )0;
             sqlstm.sqadto[30] = (unsigned short )0;
             sqlstm.sqtdso[30] = (unsigned short )0;
             sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
             sqlstm.sqhstl[31] = (unsigned int  )15;
             sqlstm.sqhsts[31] = (         int  )0;
             sqlstm.sqindv[31] = (         void  *)0;
             sqlstm.sqinds[31] = (         int  )0;
             sqlstm.sqharm[31] = (unsigned int  )0;
             sqlstm.sqadto[31] = (unsigned short )0;
             sqlstm.sqtdso[31] = (unsigned short )0;
             sqlstm.sqhstv[32] = (         void  *)(CWIPINVLDM_N.FACTORY);
             sqlstm.sqhstl[32] = (unsigned int  )11;
             sqlstm.sqhsts[32] = (         int  )0;
             sqlstm.sqindv[32] = (         void  *)0;
             sqlstm.sqinds[32] = (         int  )0;
             sqlstm.sqharm[32] = (unsigned int  )0;
             sqlstm.sqadto[32] = (unsigned short )0;
             sqlstm.sqtdso[32] = (unsigned short )0;
             sqlstm.sqhstv[33] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
             sqlstm.sqhstl[33] = (unsigned int  )2;
             sqlstm.sqhsts[33] = (         int  )0;
             sqlstm.sqindv[33] = (         void  *)0;
             sqlstm.sqinds[33] = (         int  )0;
             sqlstm.sqharm[33] = (unsigned int  )0;
             sqlstm.sqadto[33] = (unsigned short )0;
             sqlstm.sqtdso[33] = (unsigned short )0;
             sqlstm.sqhstv[34] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
             sqlstm.sqhstl[34] = (unsigned int  )26;
             sqlstm.sqhsts[34] = (         int  )0;
             sqlstm.sqindv[34] = (         void  *)0;
             sqlstm.sqinds[34] = (         int  )0;
             sqlstm.sqharm[34] = (unsigned int  )0;
             sqlstm.sqadto[34] = (unsigned short )0;
             sqlstm.sqtdso[34] = (unsigned short )0;
             sqlstm.sqhstv[35] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
             sqlstm.sqhstl[35] = (unsigned int  )26;
             sqlstm.sqhsts[35] = (         int  )0;
             sqlstm.sqindv[35] = (         void  *)0;
             sqlstm.sqinds[35] = (         int  )0;
             sqlstm.sqharm[35] = (unsigned int  )0;
             sqlstm.sqadto[35] = (unsigned short )0;
             sqlstm.sqtdso[35] = (unsigned short )0;
             sqlstm.sqhstv[36] = (         void  *)(CWIPINVLDM_N.OPER);
             sqlstm.sqhstl[36] = (unsigned int  )11;
             sqlstm.sqhsts[36] = (         int  )0;
             sqlstm.sqindv[36] = (         void  *)0;
             sqlstm.sqinds[36] = (         int  )0;
             sqlstm.sqharm[36] = (unsigned int  )0;
             sqlstm.sqadto[36] = (unsigned short )0;
             sqlstm.sqtdso[36] = (unsigned short )0;
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
            /* EXEC SQL SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                    :CWIPINVLDM_N.FACTORY,
                    :CWIPINVLDM_N.REL_LEVEL,
                    :CWIPINVLDM_N.INV_LOT_ID,
                    :CWIPINVLDM_N.AREA_ID,
                    :CWIPINVLDM_N.SUB_AREA_ID,
                    :CWIPINVLDM_N.FLOW,
                    :CWIPINVLDM_N.OPER,
                    :CWIPINVLDM_N.ORDER_ID,
                    :CWIPINVLDM_N.RES_ID,
                    :CWIPINVLDM_N.LOT_ID,
                    :CWIPINVLDM_N.BOM_QTY,
                    :CWIPINVLDM_N.QTY,
                    :CWIPINVLDM_N.TRAN_TIME,
                    :CWIPINVLDM_N.MAT_ID,
                    :CWIPINVLDM_N.MAT_VER,
                    :CWIPINVLDM_N.OUT_OPER,
                    :CWIPINVLDM_N.LOT_TYPE,
                    :CWIPINVLDM_N.INPUT_TYPE,
                    :CWIPINVLDM_N.CMF_1,
                    :CWIPINVLDM_N.CMF_2,
                    :CWIPINVLDM_N.CMF_3,
                    :CWIPINVLDM_N.CMF_4,
                    :CWIPINVLDM_N.CMF_5,
                    :CWIPINVLDM_N.CMF_6,
                    :CWIPINVLDM_N.CMF_7,
                    :CWIPINVLDM_N.CMF_8,
                    :CWIPINVLDM_N.CMF_9,
                    :CWIPINVLDM_N.CMF_10,
                    :CWIPINVLDM_N.CREATE_USER_ID,
                    :CWIPINVLDM_N.CREATE_TIME,
                    :CWIPINVLDM_N.UPDATE_USER_ID,
                    :CWIPINVLDM_N.UPDATE_TIME
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID ,\
SUB_AREA_ID ,FLOW ,OPER ,ORDER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,M\
AT_ID ,MAT_VER ,OUT_OPER ,LOT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,C\
MF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE\
_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,\
:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b\
27,:b28,:b29,:b30,:b31  from CWIPINVLDM where (((FACTORY=:b0 and REL_LEVEL=:b\
1) and INV_LOT_ID=:b2) and LOT_ID=:b9)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )498;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
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
        DBU_del_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    }

    DB_stop_query_timer("DBU_select_cwipinvldm", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cwipinvldm_for_update(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                    :CWIPINVLDM_N.FACTORY,
                    :CWIPINVLDM_N.REL_LEVEL,
                    :CWIPINVLDM_N.INV_LOT_ID,
                    :CWIPINVLDM_N.AREA_ID,
                    :CWIPINVLDM_N.SUB_AREA_ID,
                    :CWIPINVLDM_N.FLOW,
                    :CWIPINVLDM_N.OPER,
                    :CWIPINVLDM_N.ORDER_ID,
                    :CWIPINVLDM_N.RES_ID,
                    :CWIPINVLDM_N.LOT_ID,
                    :CWIPINVLDM_N.BOM_QTY,
                    :CWIPINVLDM_N.QTY,
                    :CWIPINVLDM_N.TRAN_TIME,
                    :CWIPINVLDM_N.MAT_ID,
                    :CWIPINVLDM_N.MAT_VER,
                    :CWIPINVLDM_N.OUT_OPER,
                    :CWIPINVLDM_N.LOT_TYPE,
                    :CWIPINVLDM_N.INPUT_TYPE,
                    :CWIPINVLDM_N.CMF_1,
                    :CWIPINVLDM_N.CMF_2,
                    :CWIPINVLDM_N.CMF_3,
                    :CWIPINVLDM_N.CMF_4,
                    :CWIPINVLDM_N.CMF_5,
                    :CWIPINVLDM_N.CMF_6,
                    :CWIPINVLDM_N.CMF_7,
                    :CWIPINVLDM_N.CMF_8,
                    :CWIPINVLDM_N.CMF_9,
                    :CWIPINVLDM_N.CMF_10,
                    :CWIPINVLDM_N.CREATE_USER_ID,
                    :CWIPINVLDM_N.CREATE_TIME,
                    :CWIPINVLDM_N.UPDATE_USER_ID,
                    :CWIPINVLDM_N.UPDATE_TIME
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND RES_ID = :CWIPINVLDM_N.RES_ID
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select FACTORY ,REL_LEVEL ,INV_LOT_ID ,AREA_ID ,\
SUB_AREA_ID ,FLOW ,OPER ,ORDER_ID ,RES_ID ,LOT_ID ,BOM_QTY ,QTY ,TRAN_TIME ,M\
AT_ID ,MAT_VER ,OUT_OPER ,LOT_TYPE ,INPUT_TYPE ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,C\
MF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE\
_USER_ID ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,\
:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b\
27,:b28,:b29,:b30,:b31  from CWIPINVLDM where ((((((FACTORY=:b0 and REL_LEVEL\
=:b1) and INV_LOT_ID=:b2) and OPER=:b6) and ORDER_ID=:b7) and RES_ID=:b8) and\
 LOT_ID=:b9) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )657;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
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
        DBU_del_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    }

    DB_stop_query_timer("DBU_select_cwipinvldm_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cwipinvldm_scalar(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND RES_ID = :CWIPINVLDM_N.RES_ID
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CWIPINVLDM where\
 ((((((FACTORY=:b1 and REL_LEVEL=:b2) and INV_LOT_ID=:b3) and OPER=:b4) and O\
RDER_ID=:b5) and RES_ID=:b6) and LOT_ID=:b7)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )828;
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
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
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
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL != '1'
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CWIPINVLDM where\
 ((FACTORY=:b1 and REL_LEVEL<>'1') and INV_LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )875;
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
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
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

        case 3:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND MAT_ID = :CWIPINVLDM_N.MAT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CWIPINVLDM where\
 ((((FACTORY=:b1 and REL_LEVEL=:b2) and OPER=:b3) and ORDER_ID=:b4) and MAT_I\
D=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )902;
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
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
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
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CWIPINVLDM where\
 (FACTORY=:b1 and INV_LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )941;
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
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
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

    DB_stop_query_timer("DBU_select_cwipinvldm_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cwipinvldm(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND RES_ID = :CWIPINVLDM_N.RES_ID
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CWIPINVLDM  where ((((((FACTORY=:b0\
 and REL_LEVEL=:b1) and INV_LOT_ID=:b2) and OPER=:b3) and ORDER_ID=:b4) and R\
ES_ID=:b5) and LOT_ID=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )968;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
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

        case 2:
            /* EXEC SQL DELETE FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND OPER = :CWIPINVLDM_N.OPER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CWIPINVLDM  where ((FACTORY=:b0 and\
 REL_LEVEL=:b1) and OPER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1011;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
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

        case 3:
            /* EXEC SQL DELETE FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CWIPINVLDM  where (((FACTORY=:b0 an\
d REL_LEVEL=:b1) and OPER=:b2) and ORDER_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1038;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
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

        case 4:
            /* EXEC SQL DELETE FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CWIPINVLDM  where ((FACTORY=:b0 and\
 REL_LEVEL=:b1) and LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1069;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
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

        case 5:
            /* EXEC SQL DELETE FROM CWIPINVLDM
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                  AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CWIPINVLDM  where (FACTORY=:b0 and \
INV_LOT_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1096;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
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

    DB_stop_query_timer("DBU_delete_cwipinvldm", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cwipinvldm(struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CWIPINVLDM( 
                    FACTORY, 
                    REL_LEVEL, 
                    INV_LOT_ID, 
                    AREA_ID, 
                    SUB_AREA_ID, 
                    FLOW, 
                    OPER, 
                    ORDER_ID, 
                    RES_ID, 
                    LOT_ID, 
                    BOM_QTY, 
                    QTY, 
                    TRAN_TIME, 
                    MAT_ID, 
                    MAT_VER, 
                    OUT_OPER, 
                    LOT_TYPE,
                    INPUT_TYPE, 
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
                    :CWIPINVLDM_N.FACTORY,
                    :CWIPINVLDM_N.REL_LEVEL,
                    :CWIPINVLDM_N.INV_LOT_ID,
                    :CWIPINVLDM_N.AREA_ID,
                    :CWIPINVLDM_N.SUB_AREA_ID,
                    :CWIPINVLDM_N.FLOW,
                    :CWIPINVLDM_N.OPER,
                    :CWIPINVLDM_N.ORDER_ID,
                    :CWIPINVLDM_N.RES_ID,
                    :CWIPINVLDM_N.LOT_ID,
                    :CWIPINVLDM_N.BOM_QTY,
                    :CWIPINVLDM_N.QTY,
                    :CWIPINVLDM_N.TRAN_TIME,
                    :CWIPINVLDM_N.MAT_ID,
                    :CWIPINVLDM_N.MAT_VER,
                    :CWIPINVLDM_N.OUT_OPER,
                    :CWIPINVLDM_N.LOT_TYPE,
                    :CWIPINVLDM_N.INPUT_TYPE,
                    :CWIPINVLDM_N.CMF_1,
                    :CWIPINVLDM_N.CMF_2,
                    :CWIPINVLDM_N.CMF_3,
                    :CWIPINVLDM_N.CMF_4,
                    :CWIPINVLDM_N.CMF_5,
                    :CWIPINVLDM_N.CMF_6,
                    :CWIPINVLDM_N.CMF_7,
                    :CWIPINVLDM_N.CMF_8,
                    :CWIPINVLDM_N.CMF_9,
                    :CWIPINVLDM_N.CMF_10,
                    :CWIPINVLDM_N.CREATE_USER_ID,
                    :CWIPINVLDM_N.CREATE_TIME,
                    :CWIPINVLDM_N.UPDATE_USER_ID,
                    :CWIPINVLDM_N.UPDATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 39;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CWIPINVLDM (FACTORY,REL_LEVEL,INV_LOT_ID,ARE\
A_ID,SUB_AREA_ID,FLOW,OPER,ORDER_ID,RES_ID,LOT_ID,BOM_QTY,QTY,TRAN_TIME,MAT_I\
D,MAT_VER,OUT_OPER,LOT_TYPE,INPUT_TYPE,CMF_1,CMF_2,CMF_3,CMF_4,CMF_5,CMF_6,CM\
F_7,CMF_8,CMF_9,CMF_10,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)\
 values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b1\
5,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,\
:b31)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1119;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
    sqlstm.sqhstl[1] = (unsigned int  )2;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
    sqlstm.sqhstl[2] = (unsigned int  )26;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
    sqlstm.sqhstl[5] = (unsigned int  )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
    sqlstm.sqhstl[6] = (unsigned int  )11;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
    sqlstm.sqhstl[7] = (unsigned int  )26;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
    sqlstm.sqhstl[9] = (unsigned int  )26;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
    sqlstm.sqhstl[12] = (unsigned int  )15;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
    sqlstm.sqhstl[15] = (unsigned int  )21;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
    sqlstm.sqhstl[16] = (unsigned int  )11;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
    sqlstm.sqhstl[17] = (unsigned int  )11;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
    sqlstm.sqhstl[28] = (unsigned int  )21;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
    sqlstm.sqhstl[29] = (unsigned int  )15;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
    sqlstm.sqhstl[31] = (unsigned int  )15;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cwipinvldm", 0);
}


/* SQL UPDATE Function */
void DBU_update_cwipinvldm(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CWIPINVLDM SET
                    AREA_ID = :CWIPINVLDM_N.AREA_ID,
                    SUB_AREA_ID = :CWIPINVLDM_N.SUB_AREA_ID,
                    FLOW = :CWIPINVLDM_N.FLOW,
                    BOM_QTY = :CWIPINVLDM_N.BOM_QTY,
                    QTY = :CWIPINVLDM_N.QTY,
                    TRAN_TIME = :CWIPINVLDM_N.TRAN_TIME,
                    MAT_ID = :CWIPINVLDM_N.MAT_ID,
                    MAT_VER = :CWIPINVLDM_N.MAT_VER,
                    OUT_OPER = :CWIPINVLDM_N.OUT_OPER,
                    LOT_TYPE = :CWIPINVLDM_N.LOT_TYPE,
                    INPUT_TYPE = :CWIPINVLDM_N.INPUT_TYPE,
                    CMF_1 = :CWIPINVLDM_N.CMF_1,
                    CMF_2 = :CWIPINVLDM_N.CMF_2,
                    CMF_3 = :CWIPINVLDM_N.CMF_3,
                    CMF_4 = :CWIPINVLDM_N.CMF_4,
                    CMF_5 = :CWIPINVLDM_N.CMF_5,
                    CMF_6 = :CWIPINVLDM_N.CMF_6,
                    CMF_7 = :CWIPINVLDM_N.CMF_7,
                    CMF_8 = :CWIPINVLDM_N.CMF_8,
                    CMF_9 = :CWIPINVLDM_N.CMF_9,
                    CMF_10 = :CWIPINVLDM_N.CMF_10,
                    CREATE_USER_ID = :CWIPINVLDM_N.CREATE_USER_ID,
                    CREATE_TIME = :CWIPINVLDM_N.CREATE_TIME,
                    UPDATE_USER_ID = :CWIPINVLDM_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CWIPINVLDM_N.UPDATE_TIME
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                    AND INV_LOT_ID = :CWIPINVLDM_N.INV_LOT_ID
                    AND OPER = :CWIPINVLDM_N.OPER
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
                    AND RES_ID = :CWIPINVLDM_N.RES_ID
                    AND LOT_ID = :CWIPINVLDM_N.LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CWIPINVLDM  set AREA_ID=:b0,SUB_AREA_ID=:\
b1,FLOW=:b2,BOM_QTY=:b3,QTY=:b4,TRAN_TIME=:b5,MAT_ID=:b6,MAT_VER=:b7,OUT_OPER\
=:b8,LOT_TYPE=:b9,INPUT_TYPE=:b10,CMF_1=:b11,CMF_2=:b12,CMF_3=:b13,CMF_4=:b14\
,CMF_5=:b15,CMF_6=:b16,CMF_7=:b17,CMF_8=:b18,CMF_9=:b19,CMF_10=:b20,CREATE_US\
ER_ID=:b21,CREATE_TIME=:b22,UPDATE_USER_ID=:b23,UPDATE_TIME=:b24 where ((((((\
FACTORY=:b25 and REL_LEVEL=:b26) and INV_LOT_ID=:b27) and OPER=:b28) and ORDE\
R_ID=:b29) and RES_ID=:b30) and LOT_ID=:b31)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1262;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[22] = (unsigned int  )15;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[24] = (unsigned int  )15;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
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
            /* EXEC SQL UPDATE CWIPINVLDM SET
                    FLOW = :CWIPINVLDM_N.FLOW,                 
                    UPDATE_USER_ID = :CWIPINVLDM_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CWIPINVLDM_N.UPDATE_TIME
                WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                    AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CWIPINVLDM  set FLOW=:b0,UPDATE_USER_ID=:\
b1,UPDATE_TIME=:b2 where (FACTORY=:b3 and ORDER_ID=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1405;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
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

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_update_cwipinvldm", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cwipinvldm(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CWIPINVLDM_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                FROM CWIPINVLDM
                ORDER BY FACTORY ASC,
                    REL_LEVEL ASC,
                    INV_LOT_ID ASC,
                    OPER ASC,
                    ORDER_ID ASC,
                    RES_ID ASC,
                    LOT_ID ASC; */ 

            /* EXEC SQL OPEN DBU_CWIPINVLDM_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0018;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1440;
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
            /* EXEC SQL DECLARE DBU_CWIPINVLDM_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                FROM CWIPINVLDM
               WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                 AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                 AND OPER = :CWIPINVLDM_N.OPER
               ORDER BY MAT_ID, TRAN_TIME, INV_LOT_ID; */ 

            /* EXEC SQL OPEN DBU_CWIPINVLDM_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0019;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1455;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 3:
            /* EXEC SQL DECLARE DBU_CWIPINVLDM_CUR_3 CURSOR FOR
                SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                FROM CWIPINVLDM
               WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                 AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                 AND OPER = :CWIPINVLDM_N.OPER
                 AND ORDER_ID = :CWIPINVLDM_N.ORDER_ID
               ORDER BY MAT_ID, TRAN_TIME, INV_LOT_ID; */ 

            /* EXEC SQL OPEN DBU_CWIPINVLDM_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0020;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1482;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4:
            /* EXEC SQL DECLARE DBU_CWIPINVLDM_CUR_4 CURSOR FOR
                SELECT 
                    FACTORY,
                    REL_LEVEL,
                    INV_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    FLOW,
                    OPER,
                    ORDER_ID,
                    RES_ID,
                    LOT_ID,
                    BOM_QTY,
                    QTY,
                    TRAN_TIME,
                    MAT_ID,
                    MAT_VER,
                    OUT_OPER,
                    LOT_TYPE,
                    INPUT_TYPE,
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
                FROM CWIPINVLDM
               WHERE FACTORY = :CWIPINVLDM_N.FACTORY
                 AND REL_LEVEL = :CWIPINVLDM_N.REL_LEVEL
                 AND LOT_ID = :CWIPINVLDM_N.LOT_ID
               ORDER BY MAT_ID, TRAN_TIME, INV_LOT_ID; */ 

            /* EXEC SQL OPEN DBU_CWIPINVLDM_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0021;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1513;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_cwipinvldm", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cwipinvldm(int sel_type, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CWIPINVLDM_N_TAG CWIPINVLDM_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CWIPINVLDM_CUR_1 INTO
                :CWIPINVLDM_N.FACTORY,
                :CWIPINVLDM_N.REL_LEVEL,
                :CWIPINVLDM_N.INV_LOT_ID,
                :CWIPINVLDM_N.AREA_ID,
                :CWIPINVLDM_N.SUB_AREA_ID,
                :CWIPINVLDM_N.FLOW,
                :CWIPINVLDM_N.OPER,
                :CWIPINVLDM_N.ORDER_ID,
                :CWIPINVLDM_N.RES_ID,
                :CWIPINVLDM_N.LOT_ID,
                :CWIPINVLDM_N.BOM_QTY,
                :CWIPINVLDM_N.QTY,
                :CWIPINVLDM_N.TRAN_TIME,
                :CWIPINVLDM_N.MAT_ID,
                :CWIPINVLDM_N.MAT_VER,
                :CWIPINVLDM_N.OUT_OPER,
                :CWIPINVLDM_N.LOT_TYPE,
                :CWIPINVLDM_N.INPUT_TYPE,
                :CWIPINVLDM_N.CMF_1,
                :CWIPINVLDM_N.CMF_2,
                :CWIPINVLDM_N.CMF_3,
                :CWIPINVLDM_N.CMF_4,
                :CWIPINVLDM_N.CMF_5,
                :CWIPINVLDM_N.CMF_6,
                :CWIPINVLDM_N.CMF_7,
                :CWIPINVLDM_N.CMF_8,
                :CWIPINVLDM_N.CMF_9,
                :CWIPINVLDM_N.CMF_10,
                :CWIPINVLDM_N.CREATE_USER_ID,
                :CWIPINVLDM_N.CREATE_TIME,
                :CWIPINVLDM_N.UPDATE_USER_ID,
                :CWIPINVLDM_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1540;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_CWIPINVLDM_CUR_2 INTO
                :CWIPINVLDM_N.FACTORY,
                :CWIPINVLDM_N.REL_LEVEL,
                :CWIPINVLDM_N.INV_LOT_ID,
                :CWIPINVLDM_N.AREA_ID,
                :CWIPINVLDM_N.SUB_AREA_ID,
                :CWIPINVLDM_N.FLOW,
                :CWIPINVLDM_N.OPER,
                :CWIPINVLDM_N.ORDER_ID,
                :CWIPINVLDM_N.RES_ID,
                :CWIPINVLDM_N.LOT_ID,
                :CWIPINVLDM_N.BOM_QTY,
                :CWIPINVLDM_N.QTY,
                :CWIPINVLDM_N.TRAN_TIME,
                :CWIPINVLDM_N.MAT_ID,
                :CWIPINVLDM_N.MAT_VER,
                :CWIPINVLDM_N.OUT_OPER,
                :CWIPINVLDM_N.LOT_TYPE,
                :CWIPINVLDM_N.INPUT_TYPE,
                :CWIPINVLDM_N.CMF_1,
                :CWIPINVLDM_N.CMF_2,
                :CWIPINVLDM_N.CMF_3,
                :CWIPINVLDM_N.CMF_4,
                :CWIPINVLDM_N.CMF_5,
                :CWIPINVLDM_N.CMF_6,
                :CWIPINVLDM_N.CMF_7,
                :CWIPINVLDM_N.CMF_8,
                :CWIPINVLDM_N.CMF_9,
                :CWIPINVLDM_N.CMF_10,
                :CWIPINVLDM_N.CREATE_USER_ID,
                :CWIPINVLDM_N.CREATE_TIME,
                :CWIPINVLDM_N.UPDATE_USER_ID,
                :CWIPINVLDM_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1683;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_CWIPINVLDM_CUR_3 INTO
                :CWIPINVLDM_N.FACTORY,
                :CWIPINVLDM_N.REL_LEVEL,
                :CWIPINVLDM_N.INV_LOT_ID,
                :CWIPINVLDM_N.AREA_ID,
                :CWIPINVLDM_N.SUB_AREA_ID,
                :CWIPINVLDM_N.FLOW,
                :CWIPINVLDM_N.OPER,
                :CWIPINVLDM_N.ORDER_ID,
                :CWIPINVLDM_N.RES_ID,
                :CWIPINVLDM_N.LOT_ID,
                :CWIPINVLDM_N.BOM_QTY,
                :CWIPINVLDM_N.QTY,
                :CWIPINVLDM_N.TRAN_TIME,
                :CWIPINVLDM_N.MAT_ID,
                :CWIPINVLDM_N.MAT_VER,
                :CWIPINVLDM_N.OUT_OPER,
                :CWIPINVLDM_N.LOT_TYPE,
                :CWIPINVLDM_N.INPUT_TYPE,
                :CWIPINVLDM_N.CMF_1,
                :CWIPINVLDM_N.CMF_2,
                :CWIPINVLDM_N.CMF_3,
                :CWIPINVLDM_N.CMF_4,
                :CWIPINVLDM_N.CMF_5,
                :CWIPINVLDM_N.CMF_6,
                :CWIPINVLDM_N.CMF_7,
                :CWIPINVLDM_N.CMF_8,
                :CWIPINVLDM_N.CMF_9,
                :CWIPINVLDM_N.CMF_10,
                :CWIPINVLDM_N.CREATE_USER_ID,
                :CWIPINVLDM_N.CREATE_TIME,
                :CWIPINVLDM_N.UPDATE_USER_ID,
                :CWIPINVLDM_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1826;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_CWIPINVLDM_CUR_4 INTO
                :CWIPINVLDM_N.FACTORY,
                :CWIPINVLDM_N.REL_LEVEL,
                :CWIPINVLDM_N.INV_LOT_ID,
                :CWIPINVLDM_N.AREA_ID,
                :CWIPINVLDM_N.SUB_AREA_ID,
                :CWIPINVLDM_N.FLOW,
                :CWIPINVLDM_N.OPER,
                :CWIPINVLDM_N.ORDER_ID,
                :CWIPINVLDM_N.RES_ID,
                :CWIPINVLDM_N.LOT_ID,
                :CWIPINVLDM_N.BOM_QTY,
                :CWIPINVLDM_N.QTY,
                :CWIPINVLDM_N.TRAN_TIME,
                :CWIPINVLDM_N.MAT_ID,
                :CWIPINVLDM_N.MAT_VER,
                :CWIPINVLDM_N.OUT_OPER,
                :CWIPINVLDM_N.LOT_TYPE,
                :CWIPINVLDM_N.INPUT_TYPE,
                :CWIPINVLDM_N.CMF_1,
                :CWIPINVLDM_N.CMF_2,
                :CWIPINVLDM_N.CMF_3,
                :CWIPINVLDM_N.CMF_4,
                :CWIPINVLDM_N.CMF_5,
                :CWIPINVLDM_N.CMF_6,
                :CWIPINVLDM_N.CMF_7,
                :CWIPINVLDM_N.CMF_8,
                :CWIPINVLDM_N.CMF_9,
                :CWIPINVLDM_N.CMF_10,
                :CWIPINVLDM_N.CREATE_USER_ID,
                :CWIPINVLDM_N.CREATE_TIME,
                :CWIPINVLDM_N.UPDATE_USER_ID,
                :CWIPINVLDM_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1969;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CWIPINVLDM_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CWIPINVLDM_N.REL_LEVEL);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CWIPINVLDM_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CWIPINVLDM_N.AREA_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CWIPINVLDM_N.SUB_AREA_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CWIPINVLDM_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CWIPINVLDM_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CWIPINVLDM_N.ORDER_ID);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CWIPINVLDM_N.RES_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CWIPINVLDM_N.LOT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(CWIPINVLDM_N.BOM_QTY);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CWIPINVLDM_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CWIPINVLDM_N.TRAN_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CWIPINVLDM_N.MAT_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(CWIPINVLDM_N.MAT_VER);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CWIPINVLDM_N.OUT_OPER);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CWIPINVLDM_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CWIPINVLDM_N.INPUT_TYPE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CWIPINVLDM_N.CMF_1);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CWIPINVLDM_N.CMF_2);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CWIPINVLDM_N.CMF_3);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CWIPINVLDM_N.CMF_4);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CWIPINVLDM_N.CMF_5);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CWIPINVLDM_N.CMF_6);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CWIPINVLDM_N.CMF_7);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CWIPINVLDM_N.CMF_8);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CWIPINVLDM_N.CMF_9);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CWIPINVLDM_N.CMF_10);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CWIPINVLDM_N.CREATE_USER_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CWIPINVLDM_N.CREATE_TIME);
            sqlstm.sqhstl[29] = (unsigned int  )15;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CWIPINVLDM_N.UPDATE_USER_ID);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CWIPINVLDM_N.UPDATE_TIME);
            sqlstm.sqhstl[31] = (unsigned int  )15;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
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
        DBU_del_null_cwipinvldm(&CWIPINVLDM_N, CWIPINVLDM);
    }

    DB_stop_query_timer("DBU_fetch_cwipinvldm", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cwipinvldm(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CWIPINVLDM_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2112;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBU_CWIPINVLDM_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2127;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 3:
            /* EXEC SQL CLOSE DBU_CWIPINVLDM_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2142;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4:
            /* EXEC SQL CLOSE DBU_CWIPINVLDM_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 39;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2157;
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

    DB_stop_query_timer("DBU_close_cwipinvldm", sel_type);
}


/* Initialize Function */
void DBU_init_cwipinvldm(struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* memset by Space */
    memset(CWIPINVLDM, ' ', sizeof(struct CWIPINVLDM_TAG));
    
    CWIPINVLDM->BOM_QTY = 0;
    CWIPINVLDM->QTY = 0;
    CWIPINVLDM->MAT_VER = 0;
}


/* Add Null Function */
void DBU_add_null_cwipinvldm(struct CWIPINVLDM_N_TAG *CWIPINVLDM_N, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    /* memset by NULL */
    memset(CWIPINVLDM_N, '\0', sizeof(struct CWIPINVLDM_N_TAG));
    
    MEMCPY_AN(CWIPINVLDM_N->FACTORY, CWIPINVLDM->FACTORY, sizeof(CWIPINVLDM->FACTORY));
    CWIPINVLDM_N->REL_LEVEL[0] = CWIPINVLDM->REL_LEVEL;
    MEMCPY_AN(CWIPINVLDM_N->INV_LOT_ID, CWIPINVLDM->INV_LOT_ID, sizeof(CWIPINVLDM->INV_LOT_ID));
    MEMCPY_AN(CWIPINVLDM_N->AREA_ID, CWIPINVLDM->AREA_ID, sizeof(CWIPINVLDM->AREA_ID));
    MEMCPY_AN(CWIPINVLDM_N->SUB_AREA_ID, CWIPINVLDM->SUB_AREA_ID, sizeof(CWIPINVLDM->SUB_AREA_ID));
    MEMCPY_AN(CWIPINVLDM_N->FLOW, CWIPINVLDM->FLOW, sizeof(CWIPINVLDM->FLOW));
    MEMCPY_AN(CWIPINVLDM_N->OPER, CWIPINVLDM->OPER, sizeof(CWIPINVLDM->OPER));
    MEMCPY_AN(CWIPINVLDM_N->ORDER_ID, CWIPINVLDM->ORDER_ID, sizeof(CWIPINVLDM->ORDER_ID));
    MEMCPY_AN(CWIPINVLDM_N->RES_ID, CWIPINVLDM->RES_ID, sizeof(CWIPINVLDM->RES_ID));
    MEMCPY_AN(CWIPINVLDM_N->LOT_ID, CWIPINVLDM->LOT_ID, sizeof(CWIPINVLDM->LOT_ID));
    CWIPINVLDM_N->BOM_QTY = CWIPINVLDM->BOM_QTY;
    CWIPINVLDM_N->QTY = CWIPINVLDM->QTY;
    MEMCPY_AN(CWIPINVLDM_N->TRAN_TIME, CWIPINVLDM->TRAN_TIME, sizeof(CWIPINVLDM->TRAN_TIME));
    MEMCPY_AN(CWIPINVLDM_N->MAT_ID, CWIPINVLDM->MAT_ID, sizeof(CWIPINVLDM->MAT_ID));
    CWIPINVLDM_N->MAT_VER = CWIPINVLDM->MAT_VER;
    MEMCPY_AN(CWIPINVLDM_N->OUT_OPER, CWIPINVLDM->OUT_OPER, sizeof(CWIPINVLDM->OUT_OPER));
    MEMCPY_AN(CWIPINVLDM_N->LOT_TYPE, CWIPINVLDM->LOT_TYPE, sizeof(CWIPINVLDM->LOT_TYPE));
    MEMCPY_AN(CWIPINVLDM_N->INPUT_TYPE, CWIPINVLDM->INPUT_TYPE, sizeof(CWIPINVLDM->INPUT_TYPE));
    MEMCPY_AN(CWIPINVLDM_N->CMF_1, CWIPINVLDM->CMF_1, sizeof(CWIPINVLDM->CMF_1));
    MEMCPY_AN(CWIPINVLDM_N->CMF_2, CWIPINVLDM->CMF_2, sizeof(CWIPINVLDM->CMF_2));
    MEMCPY_AN(CWIPINVLDM_N->CMF_3, CWIPINVLDM->CMF_3, sizeof(CWIPINVLDM->CMF_3));
    MEMCPY_AN(CWIPINVLDM_N->CMF_4, CWIPINVLDM->CMF_4, sizeof(CWIPINVLDM->CMF_4));
    MEMCPY_AN(CWIPINVLDM_N->CMF_5, CWIPINVLDM->CMF_5, sizeof(CWIPINVLDM->CMF_5));
    MEMCPY_AN(CWIPINVLDM_N->CMF_6, CWIPINVLDM->CMF_6, sizeof(CWIPINVLDM->CMF_6));
    MEMCPY_AN(CWIPINVLDM_N->CMF_7, CWIPINVLDM->CMF_7, sizeof(CWIPINVLDM->CMF_7));
    MEMCPY_AN(CWIPINVLDM_N->CMF_8, CWIPINVLDM->CMF_8, sizeof(CWIPINVLDM->CMF_8));
    MEMCPY_AN(CWIPINVLDM_N->CMF_9, CWIPINVLDM->CMF_9, sizeof(CWIPINVLDM->CMF_9));
    MEMCPY_AN(CWIPINVLDM_N->CMF_10, CWIPINVLDM->CMF_10, sizeof(CWIPINVLDM->CMF_10));
    MEMCPY_AN(CWIPINVLDM_N->CREATE_USER_ID, CWIPINVLDM->CREATE_USER_ID, sizeof(CWIPINVLDM->CREATE_USER_ID));
    MEMCPY_AN(CWIPINVLDM_N->CREATE_TIME, CWIPINVLDM->CREATE_TIME, sizeof(CWIPINVLDM->CREATE_TIME));
    MEMCPY_AN(CWIPINVLDM_N->UPDATE_USER_ID, CWIPINVLDM->UPDATE_USER_ID, sizeof(CWIPINVLDM->UPDATE_USER_ID));
    MEMCPY_AN(CWIPINVLDM_N->UPDATE_TIME, CWIPINVLDM->UPDATE_TIME, sizeof(CWIPINVLDM->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cwipinvldm(struct CWIPINVLDM_N_TAG *CWIPINVLDM_N, struct CWIPINVLDM_TAG *CWIPINVLDM)
{
    MEMCPY_DN(CWIPINVLDM->FACTORY, CWIPINVLDM_N->FACTORY, sizeof(CWIPINVLDM->FACTORY));
    CWIPINVLDM->REL_LEVEL = CWIPINVLDM_N->REL_LEVEL[0];
    MEMCPY_DN(CWIPINVLDM->INV_LOT_ID, CWIPINVLDM_N->INV_LOT_ID, sizeof(CWIPINVLDM->INV_LOT_ID));
    MEMCPY_DN(CWIPINVLDM->AREA_ID, CWIPINVLDM_N->AREA_ID, sizeof(CWIPINVLDM->AREA_ID));
    MEMCPY_DN(CWIPINVLDM->SUB_AREA_ID, CWIPINVLDM_N->SUB_AREA_ID, sizeof(CWIPINVLDM->SUB_AREA_ID));
    MEMCPY_DN(CWIPINVLDM->FLOW, CWIPINVLDM_N->FLOW, sizeof(CWIPINVLDM->FLOW));
    MEMCPY_DN(CWIPINVLDM->OPER, CWIPINVLDM_N->OPER, sizeof(CWIPINVLDM->OPER));
    MEMCPY_DN(CWIPINVLDM->ORDER_ID, CWIPINVLDM_N->ORDER_ID, sizeof(CWIPINVLDM->ORDER_ID));
    MEMCPY_DN(CWIPINVLDM->RES_ID, CWIPINVLDM_N->RES_ID, sizeof(CWIPINVLDM->RES_ID));
    MEMCPY_DN(CWIPINVLDM->LOT_ID, CWIPINVLDM_N->LOT_ID, sizeof(CWIPINVLDM->LOT_ID));
    CWIPINVLDM->BOM_QTY = CWIPINVLDM_N->BOM_QTY;
    CWIPINVLDM->QTY = CWIPINVLDM_N->QTY;
    MEMCPY_DN(CWIPINVLDM->TRAN_TIME, CWIPINVLDM_N->TRAN_TIME, sizeof(CWIPINVLDM->TRAN_TIME));
    MEMCPY_DN(CWIPINVLDM->MAT_ID, CWIPINVLDM_N->MAT_ID, sizeof(CWIPINVLDM->MAT_ID));
    CWIPINVLDM->MAT_VER = CWIPINVLDM_N->MAT_VER;
    MEMCPY_DN(CWIPINVLDM->OUT_OPER, CWIPINVLDM_N->OUT_OPER, sizeof(CWIPINVLDM->OUT_OPER));
    MEMCPY_DN(CWIPINVLDM->LOT_TYPE, CWIPINVLDM_N->LOT_TYPE, sizeof(CWIPINVLDM->LOT_TYPE));
    MEMCPY_DN(CWIPINVLDM->INPUT_TYPE, CWIPINVLDM_N->INPUT_TYPE, sizeof(CWIPINVLDM->INPUT_TYPE));
    MEMCPY_DN(CWIPINVLDM->CMF_1, CWIPINVLDM_N->CMF_1, sizeof(CWIPINVLDM->CMF_1));
    MEMCPY_DN(CWIPINVLDM->CMF_2, CWIPINVLDM_N->CMF_2, sizeof(CWIPINVLDM->CMF_2));
    MEMCPY_DN(CWIPINVLDM->CMF_3, CWIPINVLDM_N->CMF_3, sizeof(CWIPINVLDM->CMF_3));
    MEMCPY_DN(CWIPINVLDM->CMF_4, CWIPINVLDM_N->CMF_4, sizeof(CWIPINVLDM->CMF_4));
    MEMCPY_DN(CWIPINVLDM->CMF_5, CWIPINVLDM_N->CMF_5, sizeof(CWIPINVLDM->CMF_5));
    MEMCPY_DN(CWIPINVLDM->CMF_6, CWIPINVLDM_N->CMF_6, sizeof(CWIPINVLDM->CMF_6));
    MEMCPY_DN(CWIPINVLDM->CMF_7, CWIPINVLDM_N->CMF_7, sizeof(CWIPINVLDM->CMF_7));
    MEMCPY_DN(CWIPINVLDM->CMF_8, CWIPINVLDM_N->CMF_8, sizeof(CWIPINVLDM->CMF_8));
    MEMCPY_DN(CWIPINVLDM->CMF_9, CWIPINVLDM_N->CMF_9, sizeof(CWIPINVLDM->CMF_9));
    MEMCPY_DN(CWIPINVLDM->CMF_10, CWIPINVLDM_N->CMF_10, sizeof(CWIPINVLDM->CMF_10));
    MEMCPY_DN(CWIPINVLDM->CREATE_USER_ID, CWIPINVLDM_N->CREATE_USER_ID, sizeof(CWIPINVLDM->CREATE_USER_ID));
    MEMCPY_DN(CWIPINVLDM->CREATE_TIME, CWIPINVLDM_N->CREATE_TIME, sizeof(CWIPINVLDM->CREATE_TIME));
    MEMCPY_DN(CWIPINVLDM->UPDATE_USER_ID, CWIPINVLDM_N->UPDATE_USER_ID, sizeof(CWIPINVLDM->UPDATE_USER_ID));
    MEMCPY_DN(CWIPINVLDM->UPDATE_TIME, CWIPINVLDM_N->UPDATE_TIME, sizeof(CWIPINVLDM->UPDATE_TIME));
}


