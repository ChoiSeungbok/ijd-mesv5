
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
    "DBC_mtmplothis.pc"
};


static unsigned int sqlctx = 9141827;


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
            void  *sqhstv[220];
   unsigned int   sqhstl[220];
            int   sqhsts[220];
            void  *sqindv[220];
            int   sqinds[220];
   unsigned int   sqharm[220];
   unsigned int   *sqharc[220];
   unsigned short  sqadto[220];
   unsigned short  sqtdso[220];
} sqlstm = {13,220};

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
" ,OLD_SYS_TRAN_TIME ,OLD_TRAN_CODE ,\
OLD_FACTORY ,OLD_MAT_ID ,OLD_MAT_VER ,OLD_FLOW ,OLD_FLOW_SEQ_NUM ,OLD_OPER ,O\
LD_CM_KEY_1 ,OLD_CM_KEY_2 ,OLD_CM_KEY_3 ,OLD_CM_KEY_4 ,OLD_CM_KEY_5 ,OLD_QTY_\
1 ,OLD_QTY_2 ,OLD_QTY_3 ,OLD_CRR_ID ,OLD_LOT_TYPE ,OLD_LOT_PRIORITY ,OLD_ORDE\
R_ID ,OLD_OWNER_CODE ,OLD_CREATE_CODE ,OLD_FAC_IN_TIME ,OLD_FLOW_IN_TIME ,OLD\
_OPER_IN_TIME ,OLD_RWK_FLAG ,OLD_START_FLAG ,OLD_START_TIME ,OLD_START_RES_ID\
 ,OLD_END_FLAG ,OLD_END_TIME ,OLD_END_RES_ID ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CM\
F_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,\
TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 \
,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_I\
D ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,MULTI_TR_KEY ,MULTI_TR_SEQ ,EXT_HIST_S\
EQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT ,PROCESS\
_FLAG  from MTMPLOTHIS  order by TABLE_UPDATE_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,4189,0,4,46,0,0,220,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1,3,0,0,
900,0,0,2,4201,0,4,522,0,0,220,1,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,1,3,0,0,
1795,0,0,3,69,0,4,1002,0,0,2,1,0,1,0,2,4,0,0,1,3,0,0,
1818,0,0,4,51,0,4,1008,0,0,1,0,0,1,0,2,4,0,0,
1837,0,0,5,51,0,2,1041,0,0,1,1,0,1,0,1,3,0,0,
1856,0,0,6,3949,0,3,1068,0,0,219,219,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
2747,0,0,7,3944,0,5,1529,0,0,219,219,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,
3638,0,0,8,2997,0,9,2000,0,0,0,0,0,1,0,
3653,0,0,8,0,0,13,2028,0,0,219,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,
4544,0,0,8,0,0,15,2277,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mtmplothis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2008/01/30 18:53:34
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2007 MIRACOM,INC.
**
*********************************************************************/
/* EXEC SQL BEGIN DECLARE SECTION; */ 

/*     EXEC SQL INCLUDE DBC_COMMON_N;
 */ 
/*********************************************************************
**
**    File Name   : dbc_common_n.h
**    Description : DB Common Null Structure Definition Header File
**    Create date : 2010/01/19 10:10:57
**
**    Generated by DB Common Generator
**    Copyright (C), MIRACOM,INC.
**
*********************************************************************/

#ifndef __SQL_COMMON_N_LOADED
#define __SQL_COMMON_N_LOADED

#include "dbc_q_cond_n.h"
#include "dbc_null_data_type_n.h"

#include "DBC_mmsgmsgdef_n.h"
#include "DBC_mgcmtbldef_n.h"
#include "DBC_mgcmtbldat_n.h"
#include "DBC_msecfundef_n.h"
#include "DBC_msecgrpdef_n.h"
#include "DBC_msecgrpfun_n.h"
#include "DBC_msecusrdef_n.h"
#include "DBC_msecusrfun_n.h"
#include "DBC_msecprvgrp_n.h"
#include "DBC_msecprvusr_n.h"
#include "DBC_msecprvdef_n.h"
#include "DBC_msecusrext_n.h"
#include "DBC_mseclickey_n.h"
#include "DBC_msecflxhdr_n.h"
#include "DBC_matrnamdef_n.h"
#include "DBC_matrnamsts_n.h"
#include "DBC_matrnamhis_n.h"
#include "DBC_mwipfacdef_n.h"
#include "DBC_mwipcaldef_n.h"
#include "DBC_mwipfaccmf_n.h"
#include "DBC_mwipmatdef_n.h"
#include "DBC_mwiplotsts_n.h"
#include "DBC_mwiprwkdef_n.h"
#include "DBC_mwipfacshp_n.h"
#include "DBC_mwipmatflw_n.h"
#include "DBC_mwipflwdef_n.h"
#include "DBC_mwipflwopr_n.h"
#include "DBC_mwipoprdef_n.h"
#include "DBC_mwipcytdef_n.h"
#include "DBC_mwipordsts_n.h"
#include "DBC_mwipplndef_n.h"
#include "DBC_mwipplnlot_n.h"
#include "DBC_mwipwrkord_n.h"
#include "DBC_mwipcoldef_n.h"
#include "DBC_mwiplothis_n.h"
#include "DBC_mwiplotbns_n.h"
#include "DBC_mwiplotlos_n.h"
#include "DBC_mwiplotspl_n.h"
#include "DBC_mwiplotmrg_n.h"
#include "DBC_mwiplotcmb_n.h"
#include "DBC_mwiplothld_n.h"
#include "DBC_mwiplotlsm_n.h"
#include "DBC_mwiplotbnm_n.h"
#include "DBC_mwiprmasts_n.h"
#include "DBC_mwiplotshp_n.h"
#include "DBC_mwiplotrwk_n.h"
#include "DBC_mwipmhdsts_n.h"
#include "DBC_mwipqtmdef_n.h"
#include "DBC_mwipqtmhis_n.h"
#include "DBC_mwipbakdef_n.h"
#include "DBC_mwiplotbat_n.h"
#include "DBC_mwiplotdft_n.h"
#include "DBC_mwiprepdef_n.h"
#include "DBC_mwiplotrep_n.h"
#include "DBC_mwipsltdef_n.h"
#include "DBC_mwipsltsts_n.h"
#include "DBC_mwipslthis_n.h"
#include "DBC_mwipsltlos_n.h"
/* 2013.06.14. Aiden. Sublot based Loss/Bonus History */
#include "DBC_mwipsltbos_n.h"
#include "DBC_mwipsltcvh_n.h"
#include "DBC_mrascrrdef_n.h"
#include "DBC_mrascrrhis_n.h"
#include "DBC_mrascrrgrp_n.h"
#include "DBC_mrascrrmfo_n.h"
#include "DBC_mrascgrrel_n.h"
#include "DBC_mwipcrrlot_n.h"
#include "DBC_mrascevdef_n.h"
#include "DBC_mwiplotdel_n.h"
#include "DBC_mwipgrddef_n.h"
#include "DBC_mwipylddef_n.h"
#include "DBC_mwipmfodef_n.h"
#include "DBC_mwipmfopmt_n.h"
#include "DBC_mwipidgdef_n.h"
#include "DBC_mwipidgrul_n.h"
#include "DBC_mwipidgrel_n.h"
#include "DBC_mwipidgskv_n.h"
#include "DBC_mwipidghis_n.h"
#include "DBC_mwipbatrul_n.h"
#include "DBC_mwipbatrel_n.h"
#include "DBC_mwipbatrsv_n.h"
#include "DBC_mwipbatrit_n.h"
#include "DBC_mwipbatdef_n.h"
#include "DBC_mwipbathis_n.h"
#include "DBC_mwiprshlot_n.h"
#include "DBC_mwiplotcvh_n.h"
#include "DBC_mwiplotcvm_n.h"
#include "DBC_mwipfatdef_n.h"
#include "DBC_mwipfatact_n.h"
#include "DBC_mwipfatsvc_n.h"
#include "DBC_mwipfatcnd_n.h"
#include "DBC_mwiplotmvh_n.h"
#include "DBC_mwipsltmvh_n.h"
#include "DBC_mwiplotqtm_n.h"
#include "DBC_mwipstpdef_n.h"
#include "DBC_mwipstpsts_n.h"
#include "DBC_mwipstpmfo_n.h"
#include "DBC_mwipstphis_n.h"
#include "DBC_mrasevndef_n.h"
#include "DBC_mrasresdef_n.h"
#include "DBC_mrasresevn_n.h"
#include "DBC_mrasreslab_n.h"
#include "DBC_mrasreshis_n.h"
#include "DBC_mrasreslth_n.h"
#include "DBC_mrasresdwh_n.h"
#include "DBC_mrassrsdef_n.h"
#include "DBC_mrassrslth_n.h"
#include "DBC_mrassrslot_n.h"
#include "DBC_mrassrshis_n.h"
#include "DBC_mrassrsevn_n.h"
#include "DBC_mraspmssec_n.h"
#include "DBC_mraspmssts_n.h"
#include "DBC_mrasqrydef_n.h"
#include "DBC_mrasshtcat_n.h"
#include "DBC_mrasshtdef_n.h"
#include "DBC_mrasshtdat_n.h"
#include "DBC_mrasshtrst_n.h"
#include "DBC_mrastoltye_n.h"
#include "DBC_mrastevdef_n.h"
#include "DBC_mrastoldef_n.h"
#include "DBC_mrastolevn_n.h"
#include "DBC_mrastolhis_n.h"
#include "DBC_mrastoldft_n.h"
#include "DBC_mraspotdef_n.h"
#include "DBC_mraspothis_n.h"
#include "DBC_mbomsetdef_n.h"
#include "DBC_mbomsetver_n.h"
#include "DBC_mbomsetmat_n.h"
#include "DBC_mbomlotass_n.h"
#include "DBC_mbomlotash_n.h"
#include "DBC_minvmathis_n.h"
#include "DBC_minvmatsts_n.h"
#include "DBC_minvsrlsts_n.h"
#include "DBC_medcchrdef_n.h"
#include "DBC_medccolchr_n.h"
#include "DBC_medccoldef_n.h"
#include "DBC_medclotdat_n.h"
#include "DBC_medcresdat_n.h"
#include "DBC_medccolver_n.h"
#include "DBC_medccolunt_n.h"
#include "DBC_mfmbudrloc_n.h"
#include "DBC_mfmbudrdef_n.h"
#include "DBC_mfmbresloc_n.h"
#include "DBC_mfmbfaclyt_n.h"
#include "DBC_mfmbresimg_n.h"
#include "DBC_mfmbevtclr_n.h"
#include "DBC_mfmbenvdef_n.h"
#include "DBC_mfmbgrpusr_n.h"
#include "DBC_mspcchtdef_n.h"
#include "DBC_mspcspehis_n.h"
#include "DBC_mspcedcdat_n.h"
#include "DBC_mspccaldat_n.h"
#include "DBC_mspcoochis_n.h"
#include "DBC_mspcchtusr_n.h"
#include "DBC_mspcsumdat_n.h"
#include "DBC_mspcalmhis_n.h"
#include "DBC_mspcsetdef_n.h"
#include "DBC_mspcchtset_n.h"
#include "DBC_mspcdelhis_n.h"
#include "DBC_mspcchtmfo_n.h"
#include "DBC_mspcprtdef_n.h"
#include "DBC_mspcchtunt_n.h"
#include "DBC_spccore_join_n.h"
#include "DBC_mrcprcpdef_n.h"
#include "DBC_mrcprcpver_n.h"
#include "DBC_mrcppraver_n.h"
#include "DBC_mrcpmfodef_n.h"
#include "DBC_mrcplotrcp_n.h"
#include "DBC_mrcplotpra_n.h"
#include "DBC_mrcplothis_n.h"
#include "DBC_mrcpprahis_n.h"
#include "DBC_mrcpsltrcp_n.h"
#include "DBC_mrcpsltpra_n.h"
#include "DBC_mrcpslthis_n.h"
#include "DBC_mrcpslphis_n.h"
#include "DBC_mpoplbldef_n.h"
#include "DBC_mpoplblimg_n.h"
#include "DBC_mpoplbldgn_n.h"
#include "DBC_mpopmatlbl_n.h"
#include "DBC_mpoplotprh_n.h"
#include "DBC_mrtddspdef_n.h"
#include "DBC_mrtddspopr_n.h"
#include "DBC_mrtddspres_n.h"
#include "DBC_mrtdruldef_n.h"
#include "DBC_mrtdrulitm_n.h"
#include "DBC_mrtdevncon_n.h"
#include "DBC_mrtdevnifh_n.h"
#include "DBC_mrtdevnifs_n.h"
#include "DBC_mrtdlotpdh_n.h"
#include "DBC_mrtdlotpds_n.h"
#include "DBC_mrtdrefopr_n.h"
#include "DBC_mrtdresopr_n.h"
#include "DBC_malmmsgdef_n.h"
#include "DBC_malmmsghis_n.h"
#include "DBC_malmrcvdef_n.h"
#include "DBC_malmmfores_n.h"
#include "DBC_mqcmsmpdef_n.h"
#include "DBC_mqcmsetver_n.h"
#include "DBC_mqcmsetitm_n.h"
#include "DBC_mqcmsetdef_n.h"
#include "DBC_mqcmitmdef_n.h"
#include "DBC_mqcmmatdef_n.h"
#include "DBC_qcmcore_join_n.h"
#include "DBC_mqcmbatsts_n.h"
#include "DBC_mqcmitmsts_n.h"
#include "DBC_mqcmbathis_n.h"
#include "DBC_mqcmbatisp_n.h"
#include "DBC_mqcmitmisp_n.h"
#include "DBC_mqcmbatdft_n.h"
#include "DBC_mqcmitmdft_n.h"
#include "DBC_wipcore_join_n.h"
#include "DBC_seccore_join_n.h"
#include "DBC_edccore_join_n.h"
#include "DBC_rascore_join_n.h"
#include "DBC_fmbcore_join_n.h"
#include "DBC_rcpcore_join_n.h"
#include "DBC_rtdcore_join_n.h"
#include "DBC_mtmplothis_n.h"
#include "DBC_mwiplotyld_n.h"
#include "DBC_mtmpreshis_n.h"
#include "DBC_mtmpatrhis_n.h"
#include "DBC_mtmpcrrhis_n.h"
#include "DBC_mrasrsgdef_n.h"
#include "DBC_mrasrsgres_n.h"
#include "DBC_mrasresmfo_n.h"
#include "DBC_msvmdftver_n.h"
#include "DBC_msvmkeyver_n.h"
#include "DBC_msvmmbrdef_n.h"
#include "DBC_msvmsvcdef_n.h"
#include "DBC_msvmsvcmbr_n.h"
#include "DBC_msvmsvcurt_n.h"
#include "DBC_mmsgbbshis_n.h"
#include "DBC_mmsgbbsseq_n.h"
#include "DBC_mmsgbbstxt_n.h"
#include "DBC_mrascrrshs_n.h"
#include "DBC_mbasglbdef_n.h"
#include "DBC_mbasglbpmt_n.h"
#include "DBC_mwiplotrds_n.h"
#include "DBC_mwipsltrds_n.h"
#include "DBC_medcchrfml_n.h"
#include "DBC_mbasscrdef_n.h"
#include "DBC_mwipoprinv_n.h"
#include "DBC_mwiptollth_n.h"
#include "DBC_mrastolrsh_n.h"
#include "DBC_mbasscrrel_n.h"
#include "DBC_mbasscrcnd_n.h"
#include "DBC_mwipcrrlth_n.h"

#include "DBC_mbasinqdef_n.h"
#include "DBC_mbassqldef_n.h"

#include "DBC_mwiplotlnr_n.h"
#include "DBC_mgcmlagdat_n.h"
#include "DBC_medccolche_n.h"

/* Add by J.S. 2011.10.20 for log performance, error */
#include "DBC_msvmpfmlog_n.h"
#include "DBC_msvmerrlog_n.h"

/* Add by Kelly, 2012.04.04 */
#include "DBC_mwipbindef_n.h"
#include "DBC_mwipbinver_n.h"
#include "DBC_mwipbinunt_n.h"
#include "DBC_mwipbingrd_n.h"
#include "DBC_mwipbinrel_n.h"
#include "DBC_mwipbinhis_n.h"
#include "DBC_mwipbinshs_n.h"
#include "DBC_mwipbinhss_n.h"
#include "DBC_mwipbinssh_n.h"
#include "DBC_mwippridef_n.h"
#include "DBC_mwipbinfml_n.h"
#include "DBC_mwipbinsph_n.h"

/* add by patrick, 2012,04,10 */
#include "DBC_mbasdofdef_n.h"
#include "DBC_mbasdoddef_n.h"
#include "DBC_mbasdotdef_n.h"

/* Add by J.S. 2012.04.17 */
#include "DBC_mmsgbbsfil_n.h"

/* Add by DM KIM 2012.04.18 */
#include "DBC_mwiptstpgm_n.h"

/* Add by bs.Kwak, 2012.03.29 */
#include "DBC_mqcgactdef_n.h"
#include "DBC_mqcglotdef_n.h"
#include "DBC_mqcglothis_n.h"
#include "DBC_mqcgmforel_n.h"
#include "DBC_mqcgsltdef_n.h"
#include "DBC_mqcgslthis_n.h"
#include "DBC_mqcgsmpdef_n.h"
#include "DBC_mwiplyddef_n.h"
#include "DBC_mwiplydcod_n.h"

/* Add by JYPARK, 2012.04.16 (SPM Module Table) */
#include "DBC_medcspmver_n.h"
#include "DBC_mspmchrdsv_n.h"
#include "DBC_mspmrelchr_n.h"
#include "DBC_mspmreldef_n.h"
#include "DBC_mspmrelver_n.h"
#include "DBC_mspmatrsts_n.h"
#include "DBC_mspmatrhis_n.h"
#include "DBC_mspmdocimg_n.h"
#include "DBC_spmcore_join_n.h"

#include "DBC_mwemstpact_n.h"
#include "DBC_mwemstpdef_n.h"
#include "DBC_mwemstpsts_n.h"
#include "DBC_mwemstsdef_n.h"
#include "DBC_mwemtyedef_n.h"
#include "DBC_mwemactact_n.h"
#include "DBC_mwemactcnd_n.h"
#include "DBC_mwemactdef_n.h"
#include "DBC_mwemprcdef_n.h"
#include "DBC_mwemprcstp_n.h"
#include "DBC_mwemprcusr_n.h"
#include "DBC_mwemevnsts_n.h"
#include "DBC_mwemevnhis_n.h"
#include "DBC_mwemevnsvl_n.h"
#include "DBC_mwemevnsvh_n.h"


/* Add by YGSON, 2012.11.16 (BAS Module Table) */
#include "DBC_mbaschklsa_n.h"
#include "DBC_mbaschklsh_n.h"
#include "DBC_mbaschklsq_n.h"
#include "DBC_mbaschklsr_n.h"
#include "DBC_mbaschklst_n.h"
#include "DBC_mbaschkqry_n.h"

/* Add by JU.Heo 2012.12.03 */
#include "DBC_medcprtdef_n.h"

/* Add for Batch Process */
#include "DBC_mbatprcdef_n.h"
#include "DBC_mbatprcsts_n.h"
#include "DBC_mbatprchis_n.h"

/* Add by Mihwa 2013.01.21 */
#include "DBC_mrastolrel_n.h"

/* Add by Aiden 2013.08.28 */
#include "DBC_mwipidgscf_n.h"
/* Add by Aiden 2014.03.05 */
#include "DBC_mwiplotfqt_n.h"
/* Added by YJJung 2015.08.11 */
#include "DBC_mrtdrulext_n.h"

/* Added By YJJung 2016.02.17 */
#include "DBC_mspcrulext_n.h"
#include "DBC_mspcoocext_n.h"

#include "DBC_mpoplbldex_n.h"
#include "DBC_mgcmtblhis_n.h"
#include "DBC_mgcmdathis_n.h"

/* Direct View ฐüทร */
#include "DBC_mdnmdvuhdr_n.h"
#include "DBC_mdnmdvwcnd_n.h"
#include "DBC_mdnmdvwhdr_n.h"
#include "DBC_mdnmsqldef_n.h"
#include "DBC_mdnmsqlhis_n.h"

#include "DBC_mtmppothis_n.h"
#endif /* __SQL_COMMON_N_LOADED */

/* EXEC SQL END DECLARE SECTION; */ 


/* SQL Common Header File */
#include "DBC_common.h"


/* SQL Error Handling */
/* EXEC SQL WHENEVER SQLERROR DO DB_usr_error(); */ 

/* EXEC SQL WHENEVER NOT FOUND DO DB_usr_error(); */ 




/* Function Declaration */
void DBC_add_null_mtmplothis(struct MTMPLOTHIS_N_TAG *MTMPLOTHIS_N, struct MTMPLOTHIS_TAG *MTMPLOTHIS);
void DBC_del_null_mtmplothis(struct MTMPLOTHIS_N_TAG *MTMPLOTHIS_N, struct MTMPLOTHIS_TAG *MTMPLOTHIS);


/* SQL SELECT Function */
void DBC_select_mtmplothis(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         TABLE_UPDATE_SEQ,
                         CM_KEY_1,
                         CM_KEY_2,
                         CM_KEY_3,
                         CM_KEY_4,
                         CM_KEY_5,
                         LOT_ID,
                         SUB_LOT_ID,
                         SUB_LOT_FLAG,
                         HIST_SEQ,
                         TRAN_TIME,
                         SYS_TRAN_TIME,
                         TRAN_CODE,
                         LOT_DESC,
                         FACTORY,
                         MAT_ID,
                         MAT_VER,
                         FLOW,
                         FLOW_SEQ_NUM,
                         OPER,
                         QTY_1,
                         QTY_2,
                         QTY_3,
                         CRR_ID,
                         LOT_TYPE,
                         OWNER_CODE,
                         CREATE_CODE,
                         LOT_PRIORITY,
                         LOT_STATUS,
                         HOLD_FLAG,
                         HOLD_CODE,
                         HOLD_PASSWORD,
                         HOLD_PRV_GRP_ID,
                         OPER_IN_QTY_1,
                         OPER_IN_QTY_2,
                         OPER_IN_QTY_3,
                         CREATE_QTY_1,
                         CREATE_QTY_2,
                         CREATE_QTY_3,
                         START_QTY_1,
                         START_QTY_2,
                         START_QTY_3,
                         INV_FLAG,
                         TRANSIT_FLAG,
                         UNIT_EXIST_FLAG,
                         INV_UNIT,
                         RWK_FLAG,
                         RWK_CODE,
                         RWK_COUNT,
                         RWK_RET_FLOW,
                         RWK_RET_FLOW_SEQ_NUM,
                         RWK_RET_OPER,
                         RWK_END_FLOW,
                         RWK_END_FLOW_SEQ_NUM,
                         RWK_END_OPER,
                         RWK_RET_CLEAR_FLAG,
                         RWK_TIME,
                         NSTD_FLAG,
                         NSTD_RET_FLOW,
                         NSTD_RET_FLOW_SEQ_NUM,
                         NSTD_RET_OPER,
                         NSTD_TIME,
                         REP_FLAG,
                         REP_RET_OPER,
                         STR_RET_FLOW,
                         STR_RET_FLOW_SEQ_NUM,
                         STR_RET_OPER,
                         START_FLAG,
                         START_TIME,
                         START_RES_ID,
                         END_FLAG,
                         END_TIME,
                         END_RES_ID,
                         SAMPLE_FLAG,
                         SAMPLE_WAIT_FLAG,
                         SAMPLE_RESULT,
                         FROM_TO_FLAG,
                         FROM_TO_LOT_ID,
                         SHIP_CODE,
                         SHIP_TIME,
                         ORG_DUE_TIME,
                         SCH_DUE_TIME,
                         CREATE_TIME,
                         FAC_IN_TIME,
                         FLOW_IN_TIME,
                         OPER_IN_TIME,
                         RESERVE_RES_ID,
                         PORT_ID,
                         BATCH_ID,
                         BATCH_SEQ,
                         ORDER_ID,
                         ADD_ORDER_ID_1,
                         ADD_ORDER_ID_2,
                         ADD_ORDER_ID_3,
                         LOT_LOCATION_1,
                         LOT_LOCATION_2,
                         LOT_LOCATION_3,
                         LOT_CMF_1,
                         LOT_CMF_2,
                         LOT_CMF_3,
                         LOT_CMF_4,
                         LOT_CMF_5,
                         LOT_CMF_6,
                         LOT_CMF_7,
                         LOT_CMF_8,
                         LOT_CMF_9,
                         LOT_CMF_10,
                         LOT_CMF_11,
                         LOT_CMF_12,
                         LOT_CMF_13,
                         LOT_CMF_14,
                         LOT_CMF_15,
                         LOT_CMF_16,
                         LOT_CMF_17,
                         LOT_CMF_18,
                         LOT_CMF_19,
                         LOT_CMF_20,
                         LOT_DEL_FLAG,
                         LOT_DEL_CODE,
                         LOT_DEL_TIME,
                         BOM_SET_ID,
                         BOM_SET_VERSION,
                         BOM_ACTIVE_HIST_SEQ,
                         BOM_HIST_SEQ,
                         CRITICAL_RES_ID,
                         CRITICAL_RES_GROUP_ID,
                         SAVE_RES_ID_1,
                         SAVE_RES_ID_2,
                         SUBRES_ID,
                         LOT_GROUP_ID_1,
                         LOT_GROUP_ID_2,
                         LOT_GROUP_ID_3,
                         YIELD_1,
                         YIELD_2,
                         YIELD_3,
                         GOOD_QTY,
                         RESV_FIELD_1,
                         RESV_FIELD_2,
                         RESV_FIELD_3,
                         RESV_FIELD_4,
                         RESV_FIELD_5,
                         RESV_FLAG_1,
                         RESV_FLAG_2,
                         RESV_FLAG_3,
                         RESV_FLAG_4,
                         RESV_FLAG_5,
                         FROM_TO_MAT_ID,
                         FROM_TO_MAT_VER,
                         FROM_TO_FLOW,
                         FROM_TO_FLOW_SEQ_NUM,
                         FROM_TO_OPER,
                         FROM_TO_QTY_1,
                         FROM_TO_QTY_2,
                         FROM_TO_QTY_3,
                         FROM_TO_HIST_SEQ,
                         OLD_TRAN_TIME,
                         OLD_SYS_TRAN_TIME,
                         OLD_TRAN_CODE,
                         OLD_FACTORY,
                         OLD_MAT_ID,
                         OLD_MAT_VER,
                         OLD_FLOW,
                         OLD_FLOW_SEQ_NUM,
                         OLD_OPER,
                         OLD_CM_KEY_1,
                         OLD_CM_KEY_2,
                         OLD_CM_KEY_3,
                         OLD_CM_KEY_4,
                         OLD_CM_KEY_5,
                         OLD_QTY_1,
                         OLD_QTY_2,
                         OLD_QTY_3,
                         OLD_CRR_ID,
                         OLD_LOT_TYPE,
                         OLD_LOT_PRIORITY,
                         OLD_ORDER_ID,
                         OLD_OWNER_CODE,
                         OLD_CREATE_CODE,
                         OLD_FAC_IN_TIME,
                         OLD_FLOW_IN_TIME,
                         OLD_OPER_IN_TIME,
                         OLD_RWK_FLAG,
                         OLD_START_FLAG,
                         OLD_START_TIME,
                         OLD_START_RES_ID,
                         OLD_END_FLAG,
                         OLD_END_TIME,
                         OLD_END_RES_ID,
                         TRAN_CMF_1,
                         TRAN_CMF_2,
                         TRAN_CMF_3,
                         TRAN_CMF_4,
                         TRAN_CMF_5,
                         TRAN_CMF_6,
                         TRAN_CMF_7,
                         TRAN_CMF_8,
                         TRAN_CMF_9,
                         TRAN_CMF_10,
                         TRAN_CMF_11,
                         TRAN_CMF_12,
                         TRAN_CMF_13,
                         TRAN_CMF_14,
                         TRAN_CMF_15,
                         TRAN_CMF_16,
                         TRAN_CMF_17,
                         TRAN_CMF_18,
                         TRAN_CMF_19,
                         TRAN_CMF_20,
                         TRAN_USER_ID,
                         TRAN_COMMENT,
                         PREV_ACTIVE_HIST_SEQ,
                         MULTI_TR_KEY,
                         MULTI_TR_SEQ,
                         EXT_HIST_SEQ,
                         HIST_DEL_FLAG,
                         HIST_DEL_TIME,
                         HIST_DEL_USER_ID,
                         HIST_DEL_COMMENT,
                         PROCESS_FLAG
                INTO 
                    :MTMPLOTHIS_N.TABLE_UPDATE_SEQ,
                    :MTMPLOTHIS_N.CM_KEY_1,
                    :MTMPLOTHIS_N.CM_KEY_2,
                    :MTMPLOTHIS_N.CM_KEY_3,
                    :MTMPLOTHIS_N.CM_KEY_4,
                    :MTMPLOTHIS_N.CM_KEY_5,
                    :MTMPLOTHIS_N.LOT_ID,
                    :MTMPLOTHIS_N.SUB_LOT_ID,
                    :MTMPLOTHIS_N.SUB_LOT_FLAG,
                    :MTMPLOTHIS_N.HIST_SEQ,
                    :MTMPLOTHIS_N.TRAN_TIME,
                    :MTMPLOTHIS_N.SYS_TRAN_TIME,
                    :MTMPLOTHIS_N.TRAN_CODE,
                    :MTMPLOTHIS_N.LOT_DESC,
                    :MTMPLOTHIS_N.FACTORY,
                    :MTMPLOTHIS_N.MAT_ID,
                    :MTMPLOTHIS_N.MAT_VER,
                    :MTMPLOTHIS_N.FLOW,
                    :MTMPLOTHIS_N.FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.OPER,
                    :MTMPLOTHIS_N.QTY_1,
                    :MTMPLOTHIS_N.QTY_2,
                    :MTMPLOTHIS_N.QTY_3,
                    :MTMPLOTHIS_N.CRR_ID,
                    :MTMPLOTHIS_N.LOT_TYPE,
                    :MTMPLOTHIS_N.OWNER_CODE,
                    :MTMPLOTHIS_N.CREATE_CODE,
                    :MTMPLOTHIS_N.LOT_PRIORITY,
                    :MTMPLOTHIS_N.LOT_STATUS,
                    :MTMPLOTHIS_N.HOLD_FLAG,
                    :MTMPLOTHIS_N.HOLD_CODE,
                    :MTMPLOTHIS_N.HOLD_PASSWORD,
                    :MTMPLOTHIS_N.HOLD_PRV_GRP_ID,
                    :MTMPLOTHIS_N.OPER_IN_QTY_1,
                    :MTMPLOTHIS_N.OPER_IN_QTY_2,
                    :MTMPLOTHIS_N.OPER_IN_QTY_3,
                    :MTMPLOTHIS_N.CREATE_QTY_1,
                    :MTMPLOTHIS_N.CREATE_QTY_2,
                    :MTMPLOTHIS_N.CREATE_QTY_3,
                    :MTMPLOTHIS_N.START_QTY_1,
                    :MTMPLOTHIS_N.START_QTY_2,
                    :MTMPLOTHIS_N.START_QTY_3,
                    :MTMPLOTHIS_N.INV_FLAG,
                    :MTMPLOTHIS_N.TRANSIT_FLAG,
                    :MTMPLOTHIS_N.UNIT_EXIST_FLAG,
                    :MTMPLOTHIS_N.INV_UNIT,
                    :MTMPLOTHIS_N.RWK_FLAG,
                    :MTMPLOTHIS_N.RWK_CODE,
                    :MTMPLOTHIS_N.RWK_COUNT,
                    :MTMPLOTHIS_N.RWK_RET_FLOW,
                    :MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.RWK_RET_OPER,
                    :MTMPLOTHIS_N.RWK_END_FLOW,
                    :MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.RWK_END_OPER,
                    :MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG,
                    :MTMPLOTHIS_N.RWK_TIME,
                    :MTMPLOTHIS_N.NSTD_FLAG,
                    :MTMPLOTHIS_N.NSTD_RET_FLOW,
                    :MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.NSTD_RET_OPER,
                    :MTMPLOTHIS_N.NSTD_TIME,
                    :MTMPLOTHIS_N.REP_FLAG,
                    :MTMPLOTHIS_N.REP_RET_OPER,
                    :MTMPLOTHIS_N.STR_RET_FLOW,
                    :MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.STR_RET_OPER,
                    :MTMPLOTHIS_N.START_FLAG,
                    :MTMPLOTHIS_N.START_TIME,
                    :MTMPLOTHIS_N.START_RES_ID,
                    :MTMPLOTHIS_N.END_FLAG,
                    :MTMPLOTHIS_N.END_TIME,
                    :MTMPLOTHIS_N.END_RES_ID,
                    :MTMPLOTHIS_N.SAMPLE_FLAG,
                    :MTMPLOTHIS_N.SAMPLE_WAIT_FLAG,
                    :MTMPLOTHIS_N.SAMPLE_RESULT,
                    :MTMPLOTHIS_N.FROM_TO_FLAG,
                    :MTMPLOTHIS_N.FROM_TO_LOT_ID,
                    :MTMPLOTHIS_N.SHIP_CODE,
                    :MTMPLOTHIS_N.SHIP_TIME,
                    :MTMPLOTHIS_N.ORG_DUE_TIME,
                    :MTMPLOTHIS_N.SCH_DUE_TIME,
                    :MTMPLOTHIS_N.CREATE_TIME,
                    :MTMPLOTHIS_N.FAC_IN_TIME,
                    :MTMPLOTHIS_N.FLOW_IN_TIME,
                    :MTMPLOTHIS_N.OPER_IN_TIME,
                    :MTMPLOTHIS_N.RESERVE_RES_ID,
                    :MTMPLOTHIS_N.PORT_ID,
                    :MTMPLOTHIS_N.BATCH_ID,
                    :MTMPLOTHIS_N.BATCH_SEQ,
                    :MTMPLOTHIS_N.ORDER_ID,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_1,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_2,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_3,
                    :MTMPLOTHIS_N.LOT_LOCATION_1,
                    :MTMPLOTHIS_N.LOT_LOCATION_2,
                    :MTMPLOTHIS_N.LOT_LOCATION_3,
                    :MTMPLOTHIS_N.LOT_CMF_1,
                    :MTMPLOTHIS_N.LOT_CMF_2,
                    :MTMPLOTHIS_N.LOT_CMF_3,
                    :MTMPLOTHIS_N.LOT_CMF_4,
                    :MTMPLOTHIS_N.LOT_CMF_5,
                    :MTMPLOTHIS_N.LOT_CMF_6,
                    :MTMPLOTHIS_N.LOT_CMF_7,
                    :MTMPLOTHIS_N.LOT_CMF_8,
                    :MTMPLOTHIS_N.LOT_CMF_9,
                    :MTMPLOTHIS_N.LOT_CMF_10,
                    :MTMPLOTHIS_N.LOT_CMF_11,
                    :MTMPLOTHIS_N.LOT_CMF_12,
                    :MTMPLOTHIS_N.LOT_CMF_13,
                    :MTMPLOTHIS_N.LOT_CMF_14,
                    :MTMPLOTHIS_N.LOT_CMF_15,
                    :MTMPLOTHIS_N.LOT_CMF_16,
                    :MTMPLOTHIS_N.LOT_CMF_17,
                    :MTMPLOTHIS_N.LOT_CMF_18,
                    :MTMPLOTHIS_N.LOT_CMF_19,
                    :MTMPLOTHIS_N.LOT_CMF_20,
                    :MTMPLOTHIS_N.LOT_DEL_FLAG,
                    :MTMPLOTHIS_N.LOT_DEL_CODE,
                    :MTMPLOTHIS_N.LOT_DEL_TIME,
                    :MTMPLOTHIS_N.BOM_SET_ID,
                    :MTMPLOTHIS_N.BOM_SET_VERSION,
                    :MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ,
                    :MTMPLOTHIS_N.BOM_HIST_SEQ,
                    :MTMPLOTHIS_N.CRITICAL_RES_ID,
                    :MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID,
                    :MTMPLOTHIS_N.SAVE_RES_ID_1,
                    :MTMPLOTHIS_N.SAVE_RES_ID_2,
                    :MTMPLOTHIS_N.SUBRES_ID,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_1,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_2,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_3,
                    :MTMPLOTHIS_N.YIELD_1,
                    :MTMPLOTHIS_N.YIELD_2,
                    :MTMPLOTHIS_N.YIELD_3,
                    :MTMPLOTHIS_N.GOOD_QTY,
                    :MTMPLOTHIS_N.RESV_FIELD_1,
                    :MTMPLOTHIS_N.RESV_FIELD_2,
                    :MTMPLOTHIS_N.RESV_FIELD_3,
                    :MTMPLOTHIS_N.RESV_FIELD_4,
                    :MTMPLOTHIS_N.RESV_FIELD_5,
                    :MTMPLOTHIS_N.RESV_FLAG_1,
                    :MTMPLOTHIS_N.RESV_FLAG_2,
                    :MTMPLOTHIS_N.RESV_FLAG_3,
                    :MTMPLOTHIS_N.RESV_FLAG_4,
                    :MTMPLOTHIS_N.RESV_FLAG_5,
                    :MTMPLOTHIS_N.FROM_TO_MAT_ID,
                    :MTMPLOTHIS_N.FROM_TO_MAT_VER,
                    :MTMPLOTHIS_N.FROM_TO_FLOW,
                    :MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.FROM_TO_OPER,
                    :MTMPLOTHIS_N.FROM_TO_QTY_1,
                    :MTMPLOTHIS_N.FROM_TO_QTY_2,
                    :MTMPLOTHIS_N.FROM_TO_QTY_3,
                    :MTMPLOTHIS_N.FROM_TO_HIST_SEQ,
                    :MTMPLOTHIS_N.OLD_TRAN_TIME,
                    :MTMPLOTHIS_N.OLD_SYS_TRAN_TIME,
                    :MTMPLOTHIS_N.OLD_TRAN_CODE,
                    :MTMPLOTHIS_N.OLD_FACTORY,
                    :MTMPLOTHIS_N.OLD_MAT_ID,
                    :MTMPLOTHIS_N.OLD_MAT_VER,
                    :MTMPLOTHIS_N.OLD_FLOW,
                    :MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.OLD_OPER,
                    :MTMPLOTHIS_N.OLD_CM_KEY_1,
                    :MTMPLOTHIS_N.OLD_CM_KEY_2,
                    :MTMPLOTHIS_N.OLD_CM_KEY_3,
                    :MTMPLOTHIS_N.OLD_CM_KEY_4,
                    :MTMPLOTHIS_N.OLD_CM_KEY_5,
                    :MTMPLOTHIS_N.OLD_QTY_1,
                    :MTMPLOTHIS_N.OLD_QTY_2,
                    :MTMPLOTHIS_N.OLD_QTY_3,
                    :MTMPLOTHIS_N.OLD_CRR_ID,
                    :MTMPLOTHIS_N.OLD_LOT_TYPE,
                    :MTMPLOTHIS_N.OLD_LOT_PRIORITY,
                    :MTMPLOTHIS_N.OLD_ORDER_ID,
                    :MTMPLOTHIS_N.OLD_OWNER_CODE,
                    :MTMPLOTHIS_N.OLD_CREATE_CODE,
                    :MTMPLOTHIS_N.OLD_FAC_IN_TIME,
                    :MTMPLOTHIS_N.OLD_FLOW_IN_TIME,
                    :MTMPLOTHIS_N.OLD_OPER_IN_TIME,
                    :MTMPLOTHIS_N.OLD_RWK_FLAG,
                    :MTMPLOTHIS_N.OLD_START_FLAG,
                    :MTMPLOTHIS_N.OLD_START_TIME,
                    :MTMPLOTHIS_N.OLD_START_RES_ID,
                    :MTMPLOTHIS_N.OLD_END_FLAG,
                    :MTMPLOTHIS_N.OLD_END_TIME,
                    :MTMPLOTHIS_N.OLD_END_RES_ID,
                    :MTMPLOTHIS_N.TRAN_CMF_1,
                    :MTMPLOTHIS_N.TRAN_CMF_2,
                    :MTMPLOTHIS_N.TRAN_CMF_3,
                    :MTMPLOTHIS_N.TRAN_CMF_4,
                    :MTMPLOTHIS_N.TRAN_CMF_5,
                    :MTMPLOTHIS_N.TRAN_CMF_6,
                    :MTMPLOTHIS_N.TRAN_CMF_7,
                    :MTMPLOTHIS_N.TRAN_CMF_8,
                    :MTMPLOTHIS_N.TRAN_CMF_9,
                    :MTMPLOTHIS_N.TRAN_CMF_10,
                    :MTMPLOTHIS_N.TRAN_CMF_11,
                    :MTMPLOTHIS_N.TRAN_CMF_12,
                    :MTMPLOTHIS_N.TRAN_CMF_13,
                    :MTMPLOTHIS_N.TRAN_CMF_14,
                    :MTMPLOTHIS_N.TRAN_CMF_15,
                    :MTMPLOTHIS_N.TRAN_CMF_16,
                    :MTMPLOTHIS_N.TRAN_CMF_17,
                    :MTMPLOTHIS_N.TRAN_CMF_18,
                    :MTMPLOTHIS_N.TRAN_CMF_19,
                    :MTMPLOTHIS_N.TRAN_CMF_20,
                    :MTMPLOTHIS_N.TRAN_USER_ID,
                    :MTMPLOTHIS_N.TRAN_COMMENT,
                    :MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MTMPLOTHIS_N.MULTI_TR_KEY,
                    :MTMPLOTHIS_N.MULTI_TR_SEQ,
                    :MTMPLOTHIS_N.EXT_HIST_SEQ,
                    :MTMPLOTHIS_N.HIST_DEL_FLAG,
                    :MTMPLOTHIS_N.HIST_DEL_TIME,
                    :MTMPLOTHIS_N.HIST_DEL_USER_ID,
                    :MTMPLOTHIS_N.HIST_DEL_COMMENT,
                    :MTMPLOTHIS_N.PROCESS_FLAG
                FROM MTMPLOTHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPLOTHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select TABLE_UPDATE_SEQ ,CM_KEY_1 ,CM_KEY_2 ,CM_KEY_3 ,CM_KEY\
_4 ,CM_KEY_5 ,LOT_ID ,SUB_LOT_ID ,SUB_LOT_FLAG ,HIST_SEQ ,TRAN_TIME ,SYS_TRA\
N_TIME ,TRAN_CODE ,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,O\
PER ,QTY_1 ,QTY_2 ,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRI\
ORITY ,LOT_STATUS ,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,OPE\
R_IN_QTY_1 ,OPER_IN_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,CREATE\
_QTY_3 ,START_QTY_1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,UNIT_\
EXIST_FLAG ,INV_UNIT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_RET_F\
LOW_SEQ_NUM ,RWK_RET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_OPER \
,RWK_RET_CLEAR_FLAG ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_SEQ_N\
UM ,NSTD_RET_OPER ,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR_RET_\
FLOW_SEQ_NUM ,STR_RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_FLAG ,\
END_TIME ,END_RES_ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FROM_TO_\
FLAG ,FROM_TO_LOT_ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE");
            sqlbuft((void **)0,
              "_TIME ,SCH_DUE_TIME ,CREATE_TIME ,FAC_IN_TIME ,FLOW_IN_TIME ,\
OPER_IN_TIME ,RESERVE_RES_ID ,PORT_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,ADD_OR\
DER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_2 ,LO\
T_LOCATION_3 ,LOT_CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF\
_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT\
_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF\
_19 ,LOT_CMF_20 ,LOT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,BOM_S\
ET_VERSION ,BOM_ACTIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICAL_RES\
_GROUP_ID ,SAVE_RES_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT_GROU\
P_ID_2 ,LOT_GROUP_ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD_1 ,R\
ESV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RESV_FLA\
G_2 ,RESV_FLAG_3 ,RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT_VER \
,FROM_TO_FLOW ,FROM_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_TO_QT\
Y_2 ,FROM_TO_QTY_3 ,FROM_TO_HIST_SEQ ,OLD_TRAN_TIME");
            sqlbuft((void **)0,
              " ,OLD_SYS_TRAN_TIME ,OLD_TRAN_CODE ,OLD_FACTORY ,OLD_MAT_ID ,\
OLD_MAT_VER ,OLD_FLOW ,OLD_FLOW_SEQ_NUM ,OLD_OPER ,OLD_CM_KEY_1 ,OLD_CM_KEY_\
2 ,OLD_CM_KEY_3 ,OLD_CM_KEY_4 ,OLD_CM_KEY_5 ,OLD_QTY_1 ,OLD_QTY_2 ,OLD_QTY_3\
 ,OLD_CRR_ID ,OLD_LOT_TYPE ,OLD_LOT_PRIORITY ,OLD_ORDER_ID ,OLD_OWNER_CODE ,\
OLD_CREATE_CODE ,OLD_FAC_IN_TIME ,OLD_FLOW_IN_TIME ,OLD_OPER_IN_TIME ,OLD_RW\
K_FLAG ,OLD_START_FLAG ,OLD_START_TIME ,OLD_START_RES_ID ,OLD_END_FLAG ,OLD_\
END_TIME ,OLD_END_RES_ID ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TR\
AN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_\
CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRA\
N_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT \
,PREV_ACTIVE_HIST_SEQ ,MULTI_TR_KEY ,MULTI_TR_SEQ ,EXT_HIST_SEQ ,HIST_DEL_FL\
AG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT ,PROCESS_FLAG into :b0\
,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17\
,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,");
            sqlbuft((void **)0,
              ":b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:\
b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b\
55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b7\
0,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85\
,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100\
,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b1\
13,:b114,:b115,:b116,:b117,:b118,:b119,:b120,:b121,:b122,:b123,:b124,:b125,:\
b126,:b127,:b128,:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136,:b137,:b138\
,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150,:b1\
51,:b152,:b153,:b154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b162,:b163,:\
b164,:b165,:b166,:b167,:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b175,:b176\
,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:b188,:b1\
89,:b190,:b191,:b192,:b193,:b194,:b195,:b196,:b197,:b198,:b199,:b200,:b201,:\
b202,:b203,:b204,:b205,:b206,:b207,:b208,:b209,:b21");
            sqlstm.stmt = "0,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b21\
8  from MTMPLOTHIS where TABLE_UPDATE_SEQ=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPLOTHIS_N.CM_KEY_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPLOTHIS_N.CM_KEY_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPLOTHIS_N.CM_KEY_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPLOTHIS_N.CM_KEY_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPLOTHIS_N.CM_KEY_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MTMPLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )13;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPLOTHIS_N.LOT_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MTMPLOTHIS_N.FACTORY);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MTMPLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MTMPLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPLOTHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MTMPLOTHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPLOTHIS_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MTMPLOTHIS_N.QTY_1);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MTMPLOTHIS_N.QTY_2);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MTMPLOTHIS_N.QTY_3);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPLOTHIS_N.LOT_TYPE);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPLOTHIS_N.OWNER_CODE);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPLOTHIS_N.CREATE_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MTMPLOTHIS_N.LOT_PRIORITY);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MTMPLOTHIS_N.LOT_STATUS);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MTMPLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MTMPLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPLOTHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPLOTHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_1);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(MTMPLOTHIS_N.START_QTY_1);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MTMPLOTHIS_N.START_QTY_2);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MTMPLOTHIS_N.START_QTY_3);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPLOTHIS_N.INV_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPLOTHIS_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPLOTHIS_N.INV_UNIT);
            sqlstm.sqhstl[45] = (unsigned int  )11;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPLOTHIS_N.RWK_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPLOTHIS_N.RWK_CODE);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MTMPLOTHIS_N.RWK_COUNT);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPLOTHIS_N.RWK_RET_FLOW);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPLOTHIS_N.RWK_RET_OPER);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPLOTHIS_N.RWK_END_FLOW);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPLOTHIS_N.RWK_END_OPER);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPLOTHIS_N.RWK_TIME);
            sqlstm.sqhstl[56] = (unsigned int  )15;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPLOTHIS_N.NSTD_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_OPER);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPLOTHIS_N.NSTD_TIME);
            sqlstm.sqhstl[61] = (unsigned int  )15;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPLOTHIS_N.REP_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPLOTHIS_N.REP_RET_OPER);
            sqlstm.sqhstl[63] = (unsigned int  )11;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPLOTHIS_N.STR_RET_FLOW);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPLOTHIS_N.STR_RET_OPER);
            sqlstm.sqhstl[66] = (unsigned int  )11;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPLOTHIS_N.START_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPLOTHIS_N.START_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPLOTHIS_N.START_RES_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPLOTHIS_N.END_FLAG);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPLOTHIS_N.END_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPLOTHIS_N.END_RES_ID);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPLOTHIS_N.SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPLOTHIS_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPLOTHIS_N.SAMPLE_RESULT);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPLOTHIS_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[77] = (unsigned int  )26;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MTMPLOTHIS_N.SHIP_CODE);
            sqlstm.sqhstl[78] = (unsigned int  )11;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MTMPLOTHIS_N.SHIP_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MTMPLOTHIS_N.ORG_DUE_TIME);
            sqlstm.sqhstl[80] = (unsigned int  )15;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MTMPLOTHIS_N.SCH_DUE_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MTMPLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MTMPLOTHIS_N.FAC_IN_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MTMPLOTHIS_N.FLOW_IN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MTMPLOTHIS_N.OPER_IN_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MTMPLOTHIS_N.RESERVE_RES_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MTMPLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[87] = (unsigned int  )11;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MTMPLOTHIS_N.BATCH_ID);
            sqlstm.sqhstl[88] = (unsigned int  )26;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MTMPLOTHIS_N.BATCH_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MTMPLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[91] = (unsigned int  )26;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[93] = (unsigned int  )26;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_1);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_2);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_3);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[117] = (unsigned int  )2;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_CODE);
            sqlstm.sqhstl[118] = (unsigned int  )11;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_TIME);
            sqlstm.sqhstl[119] = (unsigned int  )15;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MTMPLOTHIS_N.BOM_SET_ID);
            sqlstm.sqhstl[120] = (unsigned int  )26;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)&(MTMPLOTHIS_N.BOM_SET_VERSION);
            sqlstm.sqhstl[121] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)&(MTMPLOTHIS_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[123] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[124] = (unsigned int  )21;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[125] = (unsigned int  )21;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[126] = (unsigned int  )21;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[127] = (unsigned int  )21;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MTMPLOTHIS_N.SUBRES_ID);
            sqlstm.sqhstl[128] = (unsigned int  )21;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[129] = (unsigned int  )26;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[130] = (unsigned int  )26;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[131] = (unsigned int  )26;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)&(MTMPLOTHIS_N.YIELD_1);
            sqlstm.sqhstl[132] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)&(MTMPLOTHIS_N.YIELD_2);
            sqlstm.sqhstl[133] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)&(MTMPLOTHIS_N.YIELD_3);
            sqlstm.sqhstl[134] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)&(MTMPLOTHIS_N.GOOD_QTY);
            sqlstm.sqhstl[135] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_1);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_2);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_3);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_4);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_5);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_1);
            sqlstm.sqhstl[141] = (unsigned int  )2;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_2);
            sqlstm.sqhstl[142] = (unsigned int  )2;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_3);
            sqlstm.sqhstl[143] = (unsigned int  )2;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_4);
            sqlstm.sqhstl[144] = (unsigned int  )2;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_5);
            sqlstm.sqhstl[145] = (unsigned int  )2;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MTMPLOTHIS_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[147] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLOW);
            sqlstm.sqhstl[148] = (unsigned int  )21;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MTMPLOTHIS_N.FROM_TO_OPER);
            sqlstm.sqhstl[150] = (unsigned int  )11;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[152] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[155] = (unsigned int  )15;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MTMPLOTHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[156] = (unsigned int  )15;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )13;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MTMPLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MTMPLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[159] = (unsigned int  )31;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)&(MTMPLOTHIS_N.OLD_MAT_VER);
            sqlstm.sqhstl[160] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW);
            sqlstm.sqhstl[161] = (unsigned int  )21;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)&(MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[162] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MTMPLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[163] = (unsigned int  )11;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_1);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_2);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_3);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_4);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_5);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_1);
            sqlstm.sqhstl[169] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[170] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[171] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MTMPLOTHIS_N.OLD_CRR_ID);
            sqlstm.sqhstl[172] = (unsigned int  )21;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_PRIORITY);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MTMPLOTHIS_N.OLD_ORDER_ID);
            sqlstm.sqhstl[175] = (unsigned int  )26;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MTMPLOTHIS_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[176] = (unsigned int  )11;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MTMPLOTHIS_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[177] = (unsigned int  )11;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MTMPLOTHIS_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[178] = (unsigned int  )15;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[179] = (unsigned int  )15;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MTMPLOTHIS_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[180] = (unsigned int  )15;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MTMPLOTHIS_N.OLD_RWK_FLAG);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MTMPLOTHIS_N.OLD_START_FLAG);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MTMPLOTHIS_N.OLD_START_TIME);
            sqlstm.sqhstl[183] = (unsigned int  )15;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MTMPLOTHIS_N.OLD_START_RES_ID);
            sqlstm.sqhstl[184] = (unsigned int  )21;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MTMPLOTHIS_N.OLD_END_FLAG);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MTMPLOTHIS_N.OLD_END_TIME);
            sqlstm.sqhstl[186] = (unsigned int  )15;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MTMPLOTHIS_N.OLD_END_RES_ID);
            sqlstm.sqhstl[187] = (unsigned int  )21;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MTMPLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[208] = (unsigned int  )21;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MTMPLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[209] = (unsigned int  )401;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)&(MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[210] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MTMPLOTHIS_N.MULTI_TR_KEY);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)&(MTMPLOTHIS_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[212] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)&(MTMPLOTHIS_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[213] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[215] = (unsigned int  )15;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[216] = (unsigned int  )21;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[217] = (unsigned int  )401;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MTMPLOTHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[219] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
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
        DBC_del_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    }
    DB_stop_query_timer("DBC_select_mtmplothis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mtmplothis_for_update(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         TABLE_UPDATE_SEQ,
                         CM_KEY_1,
                         CM_KEY_2,
                         CM_KEY_3,
                         CM_KEY_4,
                         CM_KEY_5,
                         LOT_ID,
                         SUB_LOT_ID,
                         SUB_LOT_FLAG,
                         HIST_SEQ,
                         TRAN_TIME,
                         SYS_TRAN_TIME,
                         TRAN_CODE,
                         LOT_DESC,
                         FACTORY,
                         MAT_ID,
                         MAT_VER,
                         FLOW,
                         FLOW_SEQ_NUM,
                         OPER,
                         QTY_1,
                         QTY_2,
                         QTY_3,
                         CRR_ID,
                         LOT_TYPE,
                         OWNER_CODE,
                         CREATE_CODE,
                         LOT_PRIORITY,
                         LOT_STATUS,
                         HOLD_FLAG,
                         HOLD_CODE,
                         HOLD_PASSWORD,
                         HOLD_PRV_GRP_ID,
                         OPER_IN_QTY_1,
                         OPER_IN_QTY_2,
                         OPER_IN_QTY_3,
                         CREATE_QTY_1,
                         CREATE_QTY_2,
                         CREATE_QTY_3,
                         START_QTY_1,
                         START_QTY_2,
                         START_QTY_3,
                         INV_FLAG,
                         TRANSIT_FLAG,
                         UNIT_EXIST_FLAG,
                         INV_UNIT,
                         RWK_FLAG,
                         RWK_CODE,
                         RWK_COUNT,
                         RWK_RET_FLOW,
                         RWK_RET_FLOW_SEQ_NUM,
                         RWK_RET_OPER,
                         RWK_END_FLOW,
                         RWK_END_FLOW_SEQ_NUM,
                         RWK_END_OPER,
                         RWK_RET_CLEAR_FLAG,
                         RWK_TIME,
                         NSTD_FLAG,
                         NSTD_RET_FLOW,
                         NSTD_RET_FLOW_SEQ_NUM,
                         NSTD_RET_OPER,
                         NSTD_TIME,
                         REP_FLAG,
                         REP_RET_OPER,
                         STR_RET_FLOW,
                         STR_RET_FLOW_SEQ_NUM,
                         STR_RET_OPER,
                         START_FLAG,
                         START_TIME,
                         START_RES_ID,
                         END_FLAG,
                         END_TIME,
                         END_RES_ID,
                         SAMPLE_FLAG,
                         SAMPLE_WAIT_FLAG,
                         SAMPLE_RESULT,
                         FROM_TO_FLAG,
                         FROM_TO_LOT_ID,
                         SHIP_CODE,
                         SHIP_TIME,
                         ORG_DUE_TIME,
                         SCH_DUE_TIME,
                         CREATE_TIME,
                         FAC_IN_TIME,
                         FLOW_IN_TIME,
                         OPER_IN_TIME,
                         RESERVE_RES_ID,
                         PORT_ID,
                         BATCH_ID,
                         BATCH_SEQ,
                         ORDER_ID,
                         ADD_ORDER_ID_1,
                         ADD_ORDER_ID_2,
                         ADD_ORDER_ID_3,
                         LOT_LOCATION_1,
                         LOT_LOCATION_2,
                         LOT_LOCATION_3,
                         LOT_CMF_1,
                         LOT_CMF_2,
                         LOT_CMF_3,
                         LOT_CMF_4,
                         LOT_CMF_5,
                         LOT_CMF_6,
                         LOT_CMF_7,
                         LOT_CMF_8,
                         LOT_CMF_9,
                         LOT_CMF_10,
                         LOT_CMF_11,
                         LOT_CMF_12,
                         LOT_CMF_13,
                         LOT_CMF_14,
                         LOT_CMF_15,
                         LOT_CMF_16,
                         LOT_CMF_17,
                         LOT_CMF_18,
                         LOT_CMF_19,
                         LOT_CMF_20,
                         LOT_DEL_FLAG,
                         LOT_DEL_CODE,
                         LOT_DEL_TIME,
                         BOM_SET_ID,
                         BOM_SET_VERSION,
                         BOM_ACTIVE_HIST_SEQ,
                         BOM_HIST_SEQ,
                         CRITICAL_RES_ID,
                         CRITICAL_RES_GROUP_ID,
                         SAVE_RES_ID_1,
                         SAVE_RES_ID_2,
                         SUBRES_ID,
                         LOT_GROUP_ID_1,
                         LOT_GROUP_ID_2,
                         LOT_GROUP_ID_3,
                         YIELD_1,
                         YIELD_2,
                         YIELD_3,
                         GOOD_QTY,
                         RESV_FIELD_1,
                         RESV_FIELD_2,
                         RESV_FIELD_3,
                         RESV_FIELD_4,
                         RESV_FIELD_5,
                         RESV_FLAG_1,
                         RESV_FLAG_2,
                         RESV_FLAG_3,
                         RESV_FLAG_4,
                         RESV_FLAG_5,
                         FROM_TO_MAT_ID,
                         FROM_TO_MAT_VER,
                         FROM_TO_FLOW,
                         FROM_TO_FLOW_SEQ_NUM,
                         FROM_TO_OPER,
                         FROM_TO_QTY_1,
                         FROM_TO_QTY_2,
                         FROM_TO_QTY_3,
                         FROM_TO_HIST_SEQ,
                         OLD_TRAN_TIME,
                         OLD_SYS_TRAN_TIME,
                         OLD_TRAN_CODE,
                         OLD_FACTORY,
                         OLD_MAT_ID,
                         OLD_MAT_VER,
                         OLD_FLOW,
                         OLD_FLOW_SEQ_NUM,
                         OLD_OPER,
                         OLD_CM_KEY_1,
                         OLD_CM_KEY_2,
                         OLD_CM_KEY_3,
                         OLD_CM_KEY_4,
                         OLD_CM_KEY_5,
                         OLD_QTY_1,
                         OLD_QTY_2,
                         OLD_QTY_3,
                         OLD_CRR_ID,
                         OLD_LOT_TYPE,
                         OLD_LOT_PRIORITY,
                         OLD_ORDER_ID,
                         OLD_OWNER_CODE,
                         OLD_CREATE_CODE,
                         OLD_FAC_IN_TIME,
                         OLD_FLOW_IN_TIME,
                         OLD_OPER_IN_TIME,
                         OLD_RWK_FLAG,
                         OLD_START_FLAG,
                         OLD_START_TIME,
                         OLD_START_RES_ID,
                         OLD_END_FLAG,
                         OLD_END_TIME,
                         OLD_END_RES_ID,
                         TRAN_CMF_1,
                         TRAN_CMF_2,
                         TRAN_CMF_3,
                         TRAN_CMF_4,
                         TRAN_CMF_5,
                         TRAN_CMF_6,
                         TRAN_CMF_7,
                         TRAN_CMF_8,
                         TRAN_CMF_9,
                         TRAN_CMF_10,
                         TRAN_CMF_11,
                         TRAN_CMF_12,
                         TRAN_CMF_13,
                         TRAN_CMF_14,
                         TRAN_CMF_15,
                         TRAN_CMF_16,
                         TRAN_CMF_17,
                         TRAN_CMF_18,
                         TRAN_CMF_19,
                         TRAN_CMF_20,
                         TRAN_USER_ID,
                         TRAN_COMMENT,
                         PREV_ACTIVE_HIST_SEQ,
                         MULTI_TR_KEY,
                         MULTI_TR_SEQ,
                         EXT_HIST_SEQ,
                         HIST_DEL_FLAG,
                         HIST_DEL_TIME,
                         HIST_DEL_USER_ID,
                         HIST_DEL_COMMENT,
                         PROCESS_FLAG
                INTO 
                    :MTMPLOTHIS_N.TABLE_UPDATE_SEQ,
                    :MTMPLOTHIS_N.CM_KEY_1,
                    :MTMPLOTHIS_N.CM_KEY_2,
                    :MTMPLOTHIS_N.CM_KEY_3,
                    :MTMPLOTHIS_N.CM_KEY_4,
                    :MTMPLOTHIS_N.CM_KEY_5,
                    :MTMPLOTHIS_N.LOT_ID,
                    :MTMPLOTHIS_N.SUB_LOT_ID,
                    :MTMPLOTHIS_N.SUB_LOT_FLAG,
                    :MTMPLOTHIS_N.HIST_SEQ,
                    :MTMPLOTHIS_N.TRAN_TIME,
                    :MTMPLOTHIS_N.SYS_TRAN_TIME,
                    :MTMPLOTHIS_N.TRAN_CODE,
                    :MTMPLOTHIS_N.LOT_DESC,
                    :MTMPLOTHIS_N.FACTORY,
                    :MTMPLOTHIS_N.MAT_ID,
                    :MTMPLOTHIS_N.MAT_VER,
                    :MTMPLOTHIS_N.FLOW,
                    :MTMPLOTHIS_N.FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.OPER,
                    :MTMPLOTHIS_N.QTY_1,
                    :MTMPLOTHIS_N.QTY_2,
                    :MTMPLOTHIS_N.QTY_3,
                    :MTMPLOTHIS_N.CRR_ID,
                    :MTMPLOTHIS_N.LOT_TYPE,
                    :MTMPLOTHIS_N.OWNER_CODE,
                    :MTMPLOTHIS_N.CREATE_CODE,
                    :MTMPLOTHIS_N.LOT_PRIORITY,
                    :MTMPLOTHIS_N.LOT_STATUS,
                    :MTMPLOTHIS_N.HOLD_FLAG,
                    :MTMPLOTHIS_N.HOLD_CODE,
                    :MTMPLOTHIS_N.HOLD_PASSWORD,
                    :MTMPLOTHIS_N.HOLD_PRV_GRP_ID,
                    :MTMPLOTHIS_N.OPER_IN_QTY_1,
                    :MTMPLOTHIS_N.OPER_IN_QTY_2,
                    :MTMPLOTHIS_N.OPER_IN_QTY_3,
                    :MTMPLOTHIS_N.CREATE_QTY_1,
                    :MTMPLOTHIS_N.CREATE_QTY_2,
                    :MTMPLOTHIS_N.CREATE_QTY_3,
                    :MTMPLOTHIS_N.START_QTY_1,
                    :MTMPLOTHIS_N.START_QTY_2,
                    :MTMPLOTHIS_N.START_QTY_3,
                    :MTMPLOTHIS_N.INV_FLAG,
                    :MTMPLOTHIS_N.TRANSIT_FLAG,
                    :MTMPLOTHIS_N.UNIT_EXIST_FLAG,
                    :MTMPLOTHIS_N.INV_UNIT,
                    :MTMPLOTHIS_N.RWK_FLAG,
                    :MTMPLOTHIS_N.RWK_CODE,
                    :MTMPLOTHIS_N.RWK_COUNT,
                    :MTMPLOTHIS_N.RWK_RET_FLOW,
                    :MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.RWK_RET_OPER,
                    :MTMPLOTHIS_N.RWK_END_FLOW,
                    :MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.RWK_END_OPER,
                    :MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG,
                    :MTMPLOTHIS_N.RWK_TIME,
                    :MTMPLOTHIS_N.NSTD_FLAG,
                    :MTMPLOTHIS_N.NSTD_RET_FLOW,
                    :MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.NSTD_RET_OPER,
                    :MTMPLOTHIS_N.NSTD_TIME,
                    :MTMPLOTHIS_N.REP_FLAG,
                    :MTMPLOTHIS_N.REP_RET_OPER,
                    :MTMPLOTHIS_N.STR_RET_FLOW,
                    :MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.STR_RET_OPER,
                    :MTMPLOTHIS_N.START_FLAG,
                    :MTMPLOTHIS_N.START_TIME,
                    :MTMPLOTHIS_N.START_RES_ID,
                    :MTMPLOTHIS_N.END_FLAG,
                    :MTMPLOTHIS_N.END_TIME,
                    :MTMPLOTHIS_N.END_RES_ID,
                    :MTMPLOTHIS_N.SAMPLE_FLAG,
                    :MTMPLOTHIS_N.SAMPLE_WAIT_FLAG,
                    :MTMPLOTHIS_N.SAMPLE_RESULT,
                    :MTMPLOTHIS_N.FROM_TO_FLAG,
                    :MTMPLOTHIS_N.FROM_TO_LOT_ID,
                    :MTMPLOTHIS_N.SHIP_CODE,
                    :MTMPLOTHIS_N.SHIP_TIME,
                    :MTMPLOTHIS_N.ORG_DUE_TIME,
                    :MTMPLOTHIS_N.SCH_DUE_TIME,
                    :MTMPLOTHIS_N.CREATE_TIME,
                    :MTMPLOTHIS_N.FAC_IN_TIME,
                    :MTMPLOTHIS_N.FLOW_IN_TIME,
                    :MTMPLOTHIS_N.OPER_IN_TIME,
                    :MTMPLOTHIS_N.RESERVE_RES_ID,
                    :MTMPLOTHIS_N.PORT_ID,
                    :MTMPLOTHIS_N.BATCH_ID,
                    :MTMPLOTHIS_N.BATCH_SEQ,
                    :MTMPLOTHIS_N.ORDER_ID,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_1,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_2,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_3,
                    :MTMPLOTHIS_N.LOT_LOCATION_1,
                    :MTMPLOTHIS_N.LOT_LOCATION_2,
                    :MTMPLOTHIS_N.LOT_LOCATION_3,
                    :MTMPLOTHIS_N.LOT_CMF_1,
                    :MTMPLOTHIS_N.LOT_CMF_2,
                    :MTMPLOTHIS_N.LOT_CMF_3,
                    :MTMPLOTHIS_N.LOT_CMF_4,
                    :MTMPLOTHIS_N.LOT_CMF_5,
                    :MTMPLOTHIS_N.LOT_CMF_6,
                    :MTMPLOTHIS_N.LOT_CMF_7,
                    :MTMPLOTHIS_N.LOT_CMF_8,
                    :MTMPLOTHIS_N.LOT_CMF_9,
                    :MTMPLOTHIS_N.LOT_CMF_10,
                    :MTMPLOTHIS_N.LOT_CMF_11,
                    :MTMPLOTHIS_N.LOT_CMF_12,
                    :MTMPLOTHIS_N.LOT_CMF_13,
                    :MTMPLOTHIS_N.LOT_CMF_14,
                    :MTMPLOTHIS_N.LOT_CMF_15,
                    :MTMPLOTHIS_N.LOT_CMF_16,
                    :MTMPLOTHIS_N.LOT_CMF_17,
                    :MTMPLOTHIS_N.LOT_CMF_18,
                    :MTMPLOTHIS_N.LOT_CMF_19,
                    :MTMPLOTHIS_N.LOT_CMF_20,
                    :MTMPLOTHIS_N.LOT_DEL_FLAG,
                    :MTMPLOTHIS_N.LOT_DEL_CODE,
                    :MTMPLOTHIS_N.LOT_DEL_TIME,
                    :MTMPLOTHIS_N.BOM_SET_ID,
                    :MTMPLOTHIS_N.BOM_SET_VERSION,
                    :MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ,
                    :MTMPLOTHIS_N.BOM_HIST_SEQ,
                    :MTMPLOTHIS_N.CRITICAL_RES_ID,
                    :MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID,
                    :MTMPLOTHIS_N.SAVE_RES_ID_1,
                    :MTMPLOTHIS_N.SAVE_RES_ID_2,
                    :MTMPLOTHIS_N.SUBRES_ID,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_1,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_2,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_3,
                    :MTMPLOTHIS_N.YIELD_1,
                    :MTMPLOTHIS_N.YIELD_2,
                    :MTMPLOTHIS_N.YIELD_3,
                    :MTMPLOTHIS_N.GOOD_QTY,
                    :MTMPLOTHIS_N.RESV_FIELD_1,
                    :MTMPLOTHIS_N.RESV_FIELD_2,
                    :MTMPLOTHIS_N.RESV_FIELD_3,
                    :MTMPLOTHIS_N.RESV_FIELD_4,
                    :MTMPLOTHIS_N.RESV_FIELD_5,
                    :MTMPLOTHIS_N.RESV_FLAG_1,
                    :MTMPLOTHIS_N.RESV_FLAG_2,
                    :MTMPLOTHIS_N.RESV_FLAG_3,
                    :MTMPLOTHIS_N.RESV_FLAG_4,
                    :MTMPLOTHIS_N.RESV_FLAG_5,
                    :MTMPLOTHIS_N.FROM_TO_MAT_ID,
                    :MTMPLOTHIS_N.FROM_TO_MAT_VER,
                    :MTMPLOTHIS_N.FROM_TO_FLOW,
                    :MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.FROM_TO_OPER,
                    :MTMPLOTHIS_N.FROM_TO_QTY_1,
                    :MTMPLOTHIS_N.FROM_TO_QTY_2,
                    :MTMPLOTHIS_N.FROM_TO_QTY_3,
                    :MTMPLOTHIS_N.FROM_TO_HIST_SEQ,
                    :MTMPLOTHIS_N.OLD_TRAN_TIME,
                    :MTMPLOTHIS_N.OLD_SYS_TRAN_TIME,
                    :MTMPLOTHIS_N.OLD_TRAN_CODE,
                    :MTMPLOTHIS_N.OLD_FACTORY,
                    :MTMPLOTHIS_N.OLD_MAT_ID,
                    :MTMPLOTHIS_N.OLD_MAT_VER,
                    :MTMPLOTHIS_N.OLD_FLOW,
                    :MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.OLD_OPER,
                    :MTMPLOTHIS_N.OLD_CM_KEY_1,
                    :MTMPLOTHIS_N.OLD_CM_KEY_2,
                    :MTMPLOTHIS_N.OLD_CM_KEY_3,
                    :MTMPLOTHIS_N.OLD_CM_KEY_4,
                    :MTMPLOTHIS_N.OLD_CM_KEY_5,
                    :MTMPLOTHIS_N.OLD_QTY_1,
                    :MTMPLOTHIS_N.OLD_QTY_2,
                    :MTMPLOTHIS_N.OLD_QTY_3,
                    :MTMPLOTHIS_N.OLD_CRR_ID,
                    :MTMPLOTHIS_N.OLD_LOT_TYPE,
                    :MTMPLOTHIS_N.OLD_LOT_PRIORITY,
                    :MTMPLOTHIS_N.OLD_ORDER_ID,
                    :MTMPLOTHIS_N.OLD_OWNER_CODE,
                    :MTMPLOTHIS_N.OLD_CREATE_CODE,
                    :MTMPLOTHIS_N.OLD_FAC_IN_TIME,
                    :MTMPLOTHIS_N.OLD_FLOW_IN_TIME,
                    :MTMPLOTHIS_N.OLD_OPER_IN_TIME,
                    :MTMPLOTHIS_N.OLD_RWK_FLAG,
                    :MTMPLOTHIS_N.OLD_START_FLAG,
                    :MTMPLOTHIS_N.OLD_START_TIME,
                    :MTMPLOTHIS_N.OLD_START_RES_ID,
                    :MTMPLOTHIS_N.OLD_END_FLAG,
                    :MTMPLOTHIS_N.OLD_END_TIME,
                    :MTMPLOTHIS_N.OLD_END_RES_ID,
                    :MTMPLOTHIS_N.TRAN_CMF_1,
                    :MTMPLOTHIS_N.TRAN_CMF_2,
                    :MTMPLOTHIS_N.TRAN_CMF_3,
                    :MTMPLOTHIS_N.TRAN_CMF_4,
                    :MTMPLOTHIS_N.TRAN_CMF_5,
                    :MTMPLOTHIS_N.TRAN_CMF_6,
                    :MTMPLOTHIS_N.TRAN_CMF_7,
                    :MTMPLOTHIS_N.TRAN_CMF_8,
                    :MTMPLOTHIS_N.TRAN_CMF_9,
                    :MTMPLOTHIS_N.TRAN_CMF_10,
                    :MTMPLOTHIS_N.TRAN_CMF_11,
                    :MTMPLOTHIS_N.TRAN_CMF_12,
                    :MTMPLOTHIS_N.TRAN_CMF_13,
                    :MTMPLOTHIS_N.TRAN_CMF_14,
                    :MTMPLOTHIS_N.TRAN_CMF_15,
                    :MTMPLOTHIS_N.TRAN_CMF_16,
                    :MTMPLOTHIS_N.TRAN_CMF_17,
                    :MTMPLOTHIS_N.TRAN_CMF_18,
                    :MTMPLOTHIS_N.TRAN_CMF_19,
                    :MTMPLOTHIS_N.TRAN_CMF_20,
                    :MTMPLOTHIS_N.TRAN_USER_ID,
                    :MTMPLOTHIS_N.TRAN_COMMENT,
                    :MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MTMPLOTHIS_N.MULTI_TR_KEY,
                    :MTMPLOTHIS_N.MULTI_TR_SEQ,
                    :MTMPLOTHIS_N.EXT_HIST_SEQ,
                    :MTMPLOTHIS_N.HIST_DEL_FLAG,
                    :MTMPLOTHIS_N.HIST_DEL_TIME,
                    :MTMPLOTHIS_N.HIST_DEL_USER_ID,
                    :MTMPLOTHIS_N.HIST_DEL_COMMENT,
                    :MTMPLOTHIS_N.PROCESS_FLAG
                FROM MTMPLOTHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPLOTHIS_N.TABLE_UPDATE_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select TABLE_UPDATE_SEQ ,CM_KEY_1 ,CM_KEY_2 ,CM_KEY_3 ,CM_KEY\
_4 ,CM_KEY_5 ,LOT_ID ,SUB_LOT_ID ,SUB_LOT_FLAG ,HIST_SEQ ,TRAN_TIME ,SYS_TRA\
N_TIME ,TRAN_CODE ,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,O\
PER ,QTY_1 ,QTY_2 ,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRI\
ORITY ,LOT_STATUS ,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,OPE\
R_IN_QTY_1 ,OPER_IN_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,CREATE\
_QTY_3 ,START_QTY_1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,UNIT_\
EXIST_FLAG ,INV_UNIT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_RET_F\
LOW_SEQ_NUM ,RWK_RET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_OPER \
,RWK_RET_CLEAR_FLAG ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_SEQ_N\
UM ,NSTD_RET_OPER ,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR_RET_\
FLOW_SEQ_NUM ,STR_RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_FLAG ,\
END_TIME ,END_RES_ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FROM_TO_\
FLAG ,FROM_TO_LOT_ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE");
            sqlbuft((void **)0,
              "_TIME ,SCH_DUE_TIME ,CREATE_TIME ,FAC_IN_TIME ,FLOW_IN_TIME ,\
OPER_IN_TIME ,RESERVE_RES_ID ,PORT_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,ADD_OR\
DER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_2 ,LO\
T_LOCATION_3 ,LOT_CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF\
_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT\
_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF\
_19 ,LOT_CMF_20 ,LOT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,BOM_S\
ET_VERSION ,BOM_ACTIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICAL_RES\
_GROUP_ID ,SAVE_RES_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT_GROU\
P_ID_2 ,LOT_GROUP_ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD_1 ,R\
ESV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RESV_FLA\
G_2 ,RESV_FLAG_3 ,RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT_VER \
,FROM_TO_FLOW ,FROM_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_TO_QT\
Y_2 ,FROM_TO_QTY_3 ,FROM_TO_HIST_SEQ ,OLD_TRAN_TIME");
            sqlbuft((void **)0,
              " ,OLD_SYS_TRAN_TIME ,OLD_TRAN_CODE ,OLD_FACTORY ,OLD_MAT_ID ,\
OLD_MAT_VER ,OLD_FLOW ,OLD_FLOW_SEQ_NUM ,OLD_OPER ,OLD_CM_KEY_1 ,OLD_CM_KEY_\
2 ,OLD_CM_KEY_3 ,OLD_CM_KEY_4 ,OLD_CM_KEY_5 ,OLD_QTY_1 ,OLD_QTY_2 ,OLD_QTY_3\
 ,OLD_CRR_ID ,OLD_LOT_TYPE ,OLD_LOT_PRIORITY ,OLD_ORDER_ID ,OLD_OWNER_CODE ,\
OLD_CREATE_CODE ,OLD_FAC_IN_TIME ,OLD_FLOW_IN_TIME ,OLD_OPER_IN_TIME ,OLD_RW\
K_FLAG ,OLD_START_FLAG ,OLD_START_TIME ,OLD_START_RES_ID ,OLD_END_FLAG ,OLD_\
END_TIME ,OLD_END_RES_ID ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TR\
AN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_\
CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRA\
N_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT \
,PREV_ACTIVE_HIST_SEQ ,MULTI_TR_KEY ,MULTI_TR_SEQ ,EXT_HIST_SEQ ,HIST_DEL_FL\
AG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT ,PROCESS_FLAG into :b0\
,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17\
,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,");
            sqlbuft((void **)0,
              ":b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:\
b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b\
55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b7\
0,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85\
,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100\
,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b1\
13,:b114,:b115,:b116,:b117,:b118,:b119,:b120,:b121,:b122,:b123,:b124,:b125,:\
b126,:b127,:b128,:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136,:b137,:b138\
,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150,:b1\
51,:b152,:b153,:b154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b162,:b163,:\
b164,:b165,:b166,:b167,:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b175,:b176\
,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:b188,:b1\
89,:b190,:b191,:b192,:b193,:b194,:b195,:b196,:b197,:b198,:b199,:b200,:b201,:\
b202,:b203,:b204,:b205,:b206,:b207,:b208,:b209,:b21");
            sqlstm.stmt = "0,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b21\
8  from MTMPLOTHIS where TABLE_UPDATE_SEQ=:b0 for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )900;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPLOTHIS_N.CM_KEY_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPLOTHIS_N.CM_KEY_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPLOTHIS_N.CM_KEY_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPLOTHIS_N.CM_KEY_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPLOTHIS_N.CM_KEY_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MTMPLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )13;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPLOTHIS_N.LOT_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MTMPLOTHIS_N.FACTORY);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MTMPLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MTMPLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPLOTHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MTMPLOTHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPLOTHIS_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MTMPLOTHIS_N.QTY_1);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MTMPLOTHIS_N.QTY_2);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MTMPLOTHIS_N.QTY_3);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPLOTHIS_N.LOT_TYPE);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPLOTHIS_N.OWNER_CODE);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPLOTHIS_N.CREATE_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MTMPLOTHIS_N.LOT_PRIORITY);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MTMPLOTHIS_N.LOT_STATUS);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MTMPLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MTMPLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPLOTHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPLOTHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_1);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(MTMPLOTHIS_N.START_QTY_1);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MTMPLOTHIS_N.START_QTY_2);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MTMPLOTHIS_N.START_QTY_3);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPLOTHIS_N.INV_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPLOTHIS_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPLOTHIS_N.INV_UNIT);
            sqlstm.sqhstl[45] = (unsigned int  )11;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPLOTHIS_N.RWK_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPLOTHIS_N.RWK_CODE);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MTMPLOTHIS_N.RWK_COUNT);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPLOTHIS_N.RWK_RET_FLOW);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPLOTHIS_N.RWK_RET_OPER);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPLOTHIS_N.RWK_END_FLOW);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPLOTHIS_N.RWK_END_OPER);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPLOTHIS_N.RWK_TIME);
            sqlstm.sqhstl[56] = (unsigned int  )15;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPLOTHIS_N.NSTD_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_OPER);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPLOTHIS_N.NSTD_TIME);
            sqlstm.sqhstl[61] = (unsigned int  )15;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPLOTHIS_N.REP_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPLOTHIS_N.REP_RET_OPER);
            sqlstm.sqhstl[63] = (unsigned int  )11;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPLOTHIS_N.STR_RET_FLOW);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPLOTHIS_N.STR_RET_OPER);
            sqlstm.sqhstl[66] = (unsigned int  )11;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPLOTHIS_N.START_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPLOTHIS_N.START_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPLOTHIS_N.START_RES_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPLOTHIS_N.END_FLAG);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPLOTHIS_N.END_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPLOTHIS_N.END_RES_ID);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPLOTHIS_N.SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPLOTHIS_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPLOTHIS_N.SAMPLE_RESULT);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPLOTHIS_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[77] = (unsigned int  )26;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MTMPLOTHIS_N.SHIP_CODE);
            sqlstm.sqhstl[78] = (unsigned int  )11;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MTMPLOTHIS_N.SHIP_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MTMPLOTHIS_N.ORG_DUE_TIME);
            sqlstm.sqhstl[80] = (unsigned int  )15;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MTMPLOTHIS_N.SCH_DUE_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MTMPLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MTMPLOTHIS_N.FAC_IN_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MTMPLOTHIS_N.FLOW_IN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MTMPLOTHIS_N.OPER_IN_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MTMPLOTHIS_N.RESERVE_RES_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MTMPLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[87] = (unsigned int  )11;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MTMPLOTHIS_N.BATCH_ID);
            sqlstm.sqhstl[88] = (unsigned int  )26;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MTMPLOTHIS_N.BATCH_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MTMPLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[91] = (unsigned int  )26;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[93] = (unsigned int  )26;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_1);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_2);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_3);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[117] = (unsigned int  )2;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_CODE);
            sqlstm.sqhstl[118] = (unsigned int  )11;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_TIME);
            sqlstm.sqhstl[119] = (unsigned int  )15;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MTMPLOTHIS_N.BOM_SET_ID);
            sqlstm.sqhstl[120] = (unsigned int  )26;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)&(MTMPLOTHIS_N.BOM_SET_VERSION);
            sqlstm.sqhstl[121] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)&(MTMPLOTHIS_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[123] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[124] = (unsigned int  )21;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[125] = (unsigned int  )21;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[126] = (unsigned int  )21;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[127] = (unsigned int  )21;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MTMPLOTHIS_N.SUBRES_ID);
            sqlstm.sqhstl[128] = (unsigned int  )21;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[129] = (unsigned int  )26;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[130] = (unsigned int  )26;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[131] = (unsigned int  )26;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)&(MTMPLOTHIS_N.YIELD_1);
            sqlstm.sqhstl[132] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)&(MTMPLOTHIS_N.YIELD_2);
            sqlstm.sqhstl[133] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)&(MTMPLOTHIS_N.YIELD_3);
            sqlstm.sqhstl[134] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)&(MTMPLOTHIS_N.GOOD_QTY);
            sqlstm.sqhstl[135] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_1);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_2);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_3);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_4);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_5);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_1);
            sqlstm.sqhstl[141] = (unsigned int  )2;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_2);
            sqlstm.sqhstl[142] = (unsigned int  )2;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_3);
            sqlstm.sqhstl[143] = (unsigned int  )2;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_4);
            sqlstm.sqhstl[144] = (unsigned int  )2;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_5);
            sqlstm.sqhstl[145] = (unsigned int  )2;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MTMPLOTHIS_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[147] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLOW);
            sqlstm.sqhstl[148] = (unsigned int  )21;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MTMPLOTHIS_N.FROM_TO_OPER);
            sqlstm.sqhstl[150] = (unsigned int  )11;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[152] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[155] = (unsigned int  )15;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MTMPLOTHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[156] = (unsigned int  )15;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )13;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MTMPLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MTMPLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[159] = (unsigned int  )31;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)&(MTMPLOTHIS_N.OLD_MAT_VER);
            sqlstm.sqhstl[160] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW);
            sqlstm.sqhstl[161] = (unsigned int  )21;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)&(MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[162] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MTMPLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[163] = (unsigned int  )11;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_1);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_2);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_3);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_4);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_5);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_1);
            sqlstm.sqhstl[169] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[170] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[171] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MTMPLOTHIS_N.OLD_CRR_ID);
            sqlstm.sqhstl[172] = (unsigned int  )21;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_PRIORITY);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MTMPLOTHIS_N.OLD_ORDER_ID);
            sqlstm.sqhstl[175] = (unsigned int  )26;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MTMPLOTHIS_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[176] = (unsigned int  )11;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MTMPLOTHIS_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[177] = (unsigned int  )11;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MTMPLOTHIS_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[178] = (unsigned int  )15;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[179] = (unsigned int  )15;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MTMPLOTHIS_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[180] = (unsigned int  )15;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MTMPLOTHIS_N.OLD_RWK_FLAG);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MTMPLOTHIS_N.OLD_START_FLAG);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MTMPLOTHIS_N.OLD_START_TIME);
            sqlstm.sqhstl[183] = (unsigned int  )15;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MTMPLOTHIS_N.OLD_START_RES_ID);
            sqlstm.sqhstl[184] = (unsigned int  )21;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MTMPLOTHIS_N.OLD_END_FLAG);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MTMPLOTHIS_N.OLD_END_TIME);
            sqlstm.sqhstl[186] = (unsigned int  )15;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MTMPLOTHIS_N.OLD_END_RES_ID);
            sqlstm.sqhstl[187] = (unsigned int  )21;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MTMPLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[208] = (unsigned int  )21;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MTMPLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[209] = (unsigned int  )401;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)&(MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[210] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MTMPLOTHIS_N.MULTI_TR_KEY);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)&(MTMPLOTHIS_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[212] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)&(MTMPLOTHIS_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[213] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[215] = (unsigned int  )15;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[216] = (unsigned int  )21;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[217] = (unsigned int  )401;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MTMPLOTHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[219] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
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
        DBC_del_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    }
    DB_stop_query_timer("DBC_select_mtmplothis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mtmplothis_scalar(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MTMPLOTHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPLOTHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MTMPLOTHIS where\
 TABLE_UPDATE_SEQ=:b1";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1795;
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
            sqlstm.sqhstv[1] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
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
        case 2:
            /* EXEC SQL SELECT MTMPLOTHIS_SEQ.NEXTVAL  
                INTO :d_value
                FROM DUAL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select MTMPLOTHIS_SEQ.nextval  into :b0  from DU\
AL ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1818;
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

    DB_stop_query_timer("DBC_select_mtmplothis_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mtmplothis(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MTMPLOTHIS
                WHERE TABLE_UPDATE_SEQ = :MTMPLOTHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MTMPLOTHIS  where TABLE_UPDATE_SEQ=\
:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1837;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
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
    DB_stop_query_timer("DBC_delete_mtmplothis", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mtmplothis(struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MTMPLOTHIS (
                    TABLE_UPDATE_SEQ,
                    CM_KEY_1,
                    CM_KEY_2,
                    CM_KEY_3,
                    CM_KEY_4,
                    CM_KEY_5,
                    LOT_ID,
                    SUB_LOT_ID,
                    SUB_LOT_FLAG,
                    HIST_SEQ,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_CODE,
                    LOT_DESC,
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    QTY_1,
                    QTY_2,
                    QTY_3,
                    CRR_ID,
                    LOT_TYPE,
                    OWNER_CODE,
                    CREATE_CODE,
                    LOT_PRIORITY,
                    LOT_STATUS,
                    HOLD_FLAG,
                    HOLD_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    OPER_IN_QTY_1,
                    OPER_IN_QTY_2,
                    OPER_IN_QTY_3,
                    CREATE_QTY_1,
                    CREATE_QTY_2,
                    CREATE_QTY_3,
                    START_QTY_1,
                    START_QTY_2,
                    START_QTY_3,
                    INV_FLAG,
                    TRANSIT_FLAG,
                    UNIT_EXIST_FLAG,
                    INV_UNIT,
                    RWK_FLAG,
                    RWK_CODE,
                    RWK_COUNT,
                    RWK_RET_FLOW,
                    RWK_RET_FLOW_SEQ_NUM,
                    RWK_RET_OPER,
                    RWK_END_FLOW,
                    RWK_END_FLOW_SEQ_NUM,
                    RWK_END_OPER,
                    RWK_RET_CLEAR_FLAG,
                    RWK_TIME,
                    NSTD_FLAG,
                    NSTD_RET_FLOW,
                    NSTD_RET_FLOW_SEQ_NUM,
                    NSTD_RET_OPER,
                    NSTD_TIME,
                    REP_FLAG,
                    REP_RET_OPER,
                    STR_RET_FLOW,
                    STR_RET_FLOW_SEQ_NUM,
                    STR_RET_OPER,
                    START_FLAG,
                    START_TIME,
                    START_RES_ID,
                    END_FLAG,
                    END_TIME,
                    END_RES_ID,
                    SAMPLE_FLAG,
                    SAMPLE_WAIT_FLAG,
                    SAMPLE_RESULT,
                    FROM_TO_FLAG,
                    FROM_TO_LOT_ID,
                    SHIP_CODE,
                    SHIP_TIME,
                    ORG_DUE_TIME,
                    SCH_DUE_TIME,
                    CREATE_TIME,
                    FAC_IN_TIME,
                    FLOW_IN_TIME,
                    OPER_IN_TIME,
                    RESERVE_RES_ID,
                    PORT_ID,
                    BATCH_ID,
                    BATCH_SEQ,
                    ORDER_ID,
                    ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3,
                    LOT_LOCATION_1,
                    LOT_LOCATION_2,
                    LOT_LOCATION_3,
                    LOT_CMF_1,
                    LOT_CMF_2,
                    LOT_CMF_3,
                    LOT_CMF_4,
                    LOT_CMF_5,
                    LOT_CMF_6,
                    LOT_CMF_7,
                    LOT_CMF_8,
                    LOT_CMF_9,
                    LOT_CMF_10,
                    LOT_CMF_11,
                    LOT_CMF_12,
                    LOT_CMF_13,
                    LOT_CMF_14,
                    LOT_CMF_15,
                    LOT_CMF_16,
                    LOT_CMF_17,
                    LOT_CMF_18,
                    LOT_CMF_19,
                    LOT_CMF_20,
                    LOT_DEL_FLAG,
                    LOT_DEL_CODE,
                    LOT_DEL_TIME,
                    BOM_SET_ID,
                    BOM_SET_VERSION,
                    BOM_ACTIVE_HIST_SEQ,
                    BOM_HIST_SEQ,
                    CRITICAL_RES_ID,
                    CRITICAL_RES_GROUP_ID,
                    SAVE_RES_ID_1,
                    SAVE_RES_ID_2,
                    SUBRES_ID,
                    LOT_GROUP_ID_1,
                    LOT_GROUP_ID_2,
                    LOT_GROUP_ID_3,
                    YIELD_1,
                    YIELD_2,
                    YIELD_3,
                    GOOD_QTY,
                    RESV_FIELD_1,
                    RESV_FIELD_2,
                    RESV_FIELD_3,
                    RESV_FIELD_4,
                    RESV_FIELD_5,
                    RESV_FLAG_1,
                    RESV_FLAG_2,
                    RESV_FLAG_3,
                    RESV_FLAG_4,
                    RESV_FLAG_5,
                    FROM_TO_MAT_ID,
                    FROM_TO_MAT_VER,
                    FROM_TO_FLOW,
                    FROM_TO_FLOW_SEQ_NUM,
                    FROM_TO_OPER,
                    FROM_TO_QTY_1,
                    FROM_TO_QTY_2,
                    FROM_TO_QTY_3,
                    FROM_TO_HIST_SEQ,
                    OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME,
                    OLD_TRAN_CODE,
                    OLD_FACTORY,
                    OLD_MAT_ID,
                    OLD_MAT_VER,
                    OLD_FLOW,
                    OLD_FLOW_SEQ_NUM,
                    OLD_OPER,
                    OLD_CM_KEY_1,
                    OLD_CM_KEY_2,
                    OLD_CM_KEY_3,
                    OLD_CM_KEY_4,
                    OLD_CM_KEY_5,
                    OLD_QTY_1,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_CRR_ID,
                    OLD_LOT_TYPE,
                    OLD_LOT_PRIORITY,
                    OLD_ORDER_ID,
                    OLD_OWNER_CODE,
                    OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME,
                    OLD_RWK_FLAG,
                    OLD_START_FLAG,
                    OLD_START_TIME,
                    OLD_START_RES_ID,
                    OLD_END_FLAG,
                    OLD_END_TIME,
                    OLD_END_RES_ID,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ,
                    MULTI_TR_KEY,
                    MULTI_TR_SEQ,
                    EXT_HIST_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT,
                    PROCESS_FLAG
        )
        VALUES (
                    :MTMPLOTHIS_N.TABLE_UPDATE_SEQ,
                    :MTMPLOTHIS_N.CM_KEY_1,
                    :MTMPLOTHIS_N.CM_KEY_2,
                    :MTMPLOTHIS_N.CM_KEY_3,
                    :MTMPLOTHIS_N.CM_KEY_4,
                    :MTMPLOTHIS_N.CM_KEY_5,
                    :MTMPLOTHIS_N.LOT_ID,
                    :MTMPLOTHIS_N.SUB_LOT_ID,
                    :MTMPLOTHIS_N.SUB_LOT_FLAG,
                    :MTMPLOTHIS_N.HIST_SEQ,
                    :MTMPLOTHIS_N.TRAN_TIME,
                    :MTMPLOTHIS_N.SYS_TRAN_TIME,
                    :MTMPLOTHIS_N.TRAN_CODE,
                    :MTMPLOTHIS_N.LOT_DESC,
                    :MTMPLOTHIS_N.FACTORY,
                    :MTMPLOTHIS_N.MAT_ID,
                    :MTMPLOTHIS_N.MAT_VER,
                    :MTMPLOTHIS_N.FLOW,
                    :MTMPLOTHIS_N.FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.OPER,
                    :MTMPLOTHIS_N.QTY_1,
                    :MTMPLOTHIS_N.QTY_2,
                    :MTMPLOTHIS_N.QTY_3,
                    :MTMPLOTHIS_N.CRR_ID,
                    :MTMPLOTHIS_N.LOT_TYPE,
                    :MTMPLOTHIS_N.OWNER_CODE,
                    :MTMPLOTHIS_N.CREATE_CODE,
                    :MTMPLOTHIS_N.LOT_PRIORITY,
                    :MTMPLOTHIS_N.LOT_STATUS,
                    :MTMPLOTHIS_N.HOLD_FLAG,
                    :MTMPLOTHIS_N.HOLD_CODE,
                    :MTMPLOTHIS_N.HOLD_PASSWORD,
                    :MTMPLOTHIS_N.HOLD_PRV_GRP_ID,
                    :MTMPLOTHIS_N.OPER_IN_QTY_1,
                    :MTMPLOTHIS_N.OPER_IN_QTY_2,
                    :MTMPLOTHIS_N.OPER_IN_QTY_3,
                    :MTMPLOTHIS_N.CREATE_QTY_1,
                    :MTMPLOTHIS_N.CREATE_QTY_2,
                    :MTMPLOTHIS_N.CREATE_QTY_3,
                    :MTMPLOTHIS_N.START_QTY_1,
                    :MTMPLOTHIS_N.START_QTY_2,
                    :MTMPLOTHIS_N.START_QTY_3,
                    :MTMPLOTHIS_N.INV_FLAG,
                    :MTMPLOTHIS_N.TRANSIT_FLAG,
                    :MTMPLOTHIS_N.UNIT_EXIST_FLAG,
                    :MTMPLOTHIS_N.INV_UNIT,
                    :MTMPLOTHIS_N.RWK_FLAG,
                    :MTMPLOTHIS_N.RWK_CODE,
                    :MTMPLOTHIS_N.RWK_COUNT,
                    :MTMPLOTHIS_N.RWK_RET_FLOW,
                    :MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.RWK_RET_OPER,
                    :MTMPLOTHIS_N.RWK_END_FLOW,
                    :MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.RWK_END_OPER,
                    :MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG,
                    :MTMPLOTHIS_N.RWK_TIME,
                    :MTMPLOTHIS_N.NSTD_FLAG,
                    :MTMPLOTHIS_N.NSTD_RET_FLOW,
                    :MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.NSTD_RET_OPER,
                    :MTMPLOTHIS_N.NSTD_TIME,
                    :MTMPLOTHIS_N.REP_FLAG,
                    :MTMPLOTHIS_N.REP_RET_OPER,
                    :MTMPLOTHIS_N.STR_RET_FLOW,
                    :MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.STR_RET_OPER,
                    :MTMPLOTHIS_N.START_FLAG,
                    :MTMPLOTHIS_N.START_TIME,
                    :MTMPLOTHIS_N.START_RES_ID,
                    :MTMPLOTHIS_N.END_FLAG,
                    :MTMPLOTHIS_N.END_TIME,
                    :MTMPLOTHIS_N.END_RES_ID,
                    :MTMPLOTHIS_N.SAMPLE_FLAG,
                    :MTMPLOTHIS_N.SAMPLE_WAIT_FLAG,
                    :MTMPLOTHIS_N.SAMPLE_RESULT,
                    :MTMPLOTHIS_N.FROM_TO_FLAG,
                    :MTMPLOTHIS_N.FROM_TO_LOT_ID,
                    :MTMPLOTHIS_N.SHIP_CODE,
                    :MTMPLOTHIS_N.SHIP_TIME,
                    :MTMPLOTHIS_N.ORG_DUE_TIME,
                    :MTMPLOTHIS_N.SCH_DUE_TIME,
                    :MTMPLOTHIS_N.CREATE_TIME,
                    :MTMPLOTHIS_N.FAC_IN_TIME,
                    :MTMPLOTHIS_N.FLOW_IN_TIME,
                    :MTMPLOTHIS_N.OPER_IN_TIME,
                    :MTMPLOTHIS_N.RESERVE_RES_ID,
                    :MTMPLOTHIS_N.PORT_ID,
                    :MTMPLOTHIS_N.BATCH_ID,
                    :MTMPLOTHIS_N.BATCH_SEQ,
                    :MTMPLOTHIS_N.ORDER_ID,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_1,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_2,
                    :MTMPLOTHIS_N.ADD_ORDER_ID_3,
                    :MTMPLOTHIS_N.LOT_LOCATION_1,
                    :MTMPLOTHIS_N.LOT_LOCATION_2,
                    :MTMPLOTHIS_N.LOT_LOCATION_3,
                    :MTMPLOTHIS_N.LOT_CMF_1,
                    :MTMPLOTHIS_N.LOT_CMF_2,
                    :MTMPLOTHIS_N.LOT_CMF_3,
                    :MTMPLOTHIS_N.LOT_CMF_4,
                    :MTMPLOTHIS_N.LOT_CMF_5,
                    :MTMPLOTHIS_N.LOT_CMF_6,
                    :MTMPLOTHIS_N.LOT_CMF_7,
                    :MTMPLOTHIS_N.LOT_CMF_8,
                    :MTMPLOTHIS_N.LOT_CMF_9,
                    :MTMPLOTHIS_N.LOT_CMF_10,
                    :MTMPLOTHIS_N.LOT_CMF_11,
                    :MTMPLOTHIS_N.LOT_CMF_12,
                    :MTMPLOTHIS_N.LOT_CMF_13,
                    :MTMPLOTHIS_N.LOT_CMF_14,
                    :MTMPLOTHIS_N.LOT_CMF_15,
                    :MTMPLOTHIS_N.LOT_CMF_16,
                    :MTMPLOTHIS_N.LOT_CMF_17,
                    :MTMPLOTHIS_N.LOT_CMF_18,
                    :MTMPLOTHIS_N.LOT_CMF_19,
                    :MTMPLOTHIS_N.LOT_CMF_20,
                    :MTMPLOTHIS_N.LOT_DEL_FLAG,
                    :MTMPLOTHIS_N.LOT_DEL_CODE,
                    :MTMPLOTHIS_N.LOT_DEL_TIME,
                    :MTMPLOTHIS_N.BOM_SET_ID,
                    :MTMPLOTHIS_N.BOM_SET_VERSION,
                    :MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ,
                    :MTMPLOTHIS_N.BOM_HIST_SEQ,
                    :MTMPLOTHIS_N.CRITICAL_RES_ID,
                    :MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID,
                    :MTMPLOTHIS_N.SAVE_RES_ID_1,
                    :MTMPLOTHIS_N.SAVE_RES_ID_2,
                    :MTMPLOTHIS_N.SUBRES_ID,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_1,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_2,
                    :MTMPLOTHIS_N.LOT_GROUP_ID_3,
                    :MTMPLOTHIS_N.YIELD_1,
                    :MTMPLOTHIS_N.YIELD_2,
                    :MTMPLOTHIS_N.YIELD_3,
                    :MTMPLOTHIS_N.GOOD_QTY,
                    :MTMPLOTHIS_N.RESV_FIELD_1,
                    :MTMPLOTHIS_N.RESV_FIELD_2,
                    :MTMPLOTHIS_N.RESV_FIELD_3,
                    :MTMPLOTHIS_N.RESV_FIELD_4,
                    :MTMPLOTHIS_N.RESV_FIELD_5,
                    :MTMPLOTHIS_N.RESV_FLAG_1,
                    :MTMPLOTHIS_N.RESV_FLAG_2,
                    :MTMPLOTHIS_N.RESV_FLAG_3,
                    :MTMPLOTHIS_N.RESV_FLAG_4,
                    :MTMPLOTHIS_N.RESV_FLAG_5,
                    :MTMPLOTHIS_N.FROM_TO_MAT_ID,
                    :MTMPLOTHIS_N.FROM_TO_MAT_VER,
                    :MTMPLOTHIS_N.FROM_TO_FLOW,
                    :MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.FROM_TO_OPER,
                    :MTMPLOTHIS_N.FROM_TO_QTY_1,
                    :MTMPLOTHIS_N.FROM_TO_QTY_2,
                    :MTMPLOTHIS_N.FROM_TO_QTY_3,
                    :MTMPLOTHIS_N.FROM_TO_HIST_SEQ,
                    :MTMPLOTHIS_N.OLD_TRAN_TIME,
                    :MTMPLOTHIS_N.OLD_SYS_TRAN_TIME,
                    :MTMPLOTHIS_N.OLD_TRAN_CODE,
                    :MTMPLOTHIS_N.OLD_FACTORY,
                    :MTMPLOTHIS_N.OLD_MAT_ID,
                    :MTMPLOTHIS_N.OLD_MAT_VER,
                    :MTMPLOTHIS_N.OLD_FLOW,
                    :MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM,
                    :MTMPLOTHIS_N.OLD_OPER,
                    :MTMPLOTHIS_N.OLD_CM_KEY_1,
                    :MTMPLOTHIS_N.OLD_CM_KEY_2,
                    :MTMPLOTHIS_N.OLD_CM_KEY_3,
                    :MTMPLOTHIS_N.OLD_CM_KEY_4,
                    :MTMPLOTHIS_N.OLD_CM_KEY_5,
                    :MTMPLOTHIS_N.OLD_QTY_1,
                    :MTMPLOTHIS_N.OLD_QTY_2,
                    :MTMPLOTHIS_N.OLD_QTY_3,
                    :MTMPLOTHIS_N.OLD_CRR_ID,
                    :MTMPLOTHIS_N.OLD_LOT_TYPE,
                    :MTMPLOTHIS_N.OLD_LOT_PRIORITY,
                    :MTMPLOTHIS_N.OLD_ORDER_ID,
                    :MTMPLOTHIS_N.OLD_OWNER_CODE,
                    :MTMPLOTHIS_N.OLD_CREATE_CODE,
                    :MTMPLOTHIS_N.OLD_FAC_IN_TIME,
                    :MTMPLOTHIS_N.OLD_FLOW_IN_TIME,
                    :MTMPLOTHIS_N.OLD_OPER_IN_TIME,
                    :MTMPLOTHIS_N.OLD_RWK_FLAG,
                    :MTMPLOTHIS_N.OLD_START_FLAG,
                    :MTMPLOTHIS_N.OLD_START_TIME,
                    :MTMPLOTHIS_N.OLD_START_RES_ID,
                    :MTMPLOTHIS_N.OLD_END_FLAG,
                    :MTMPLOTHIS_N.OLD_END_TIME,
                    :MTMPLOTHIS_N.OLD_END_RES_ID,
                    :MTMPLOTHIS_N.TRAN_CMF_1,
                    :MTMPLOTHIS_N.TRAN_CMF_2,
                    :MTMPLOTHIS_N.TRAN_CMF_3,
                    :MTMPLOTHIS_N.TRAN_CMF_4,
                    :MTMPLOTHIS_N.TRAN_CMF_5,
                    :MTMPLOTHIS_N.TRAN_CMF_6,
                    :MTMPLOTHIS_N.TRAN_CMF_7,
                    :MTMPLOTHIS_N.TRAN_CMF_8,
                    :MTMPLOTHIS_N.TRAN_CMF_9,
                    :MTMPLOTHIS_N.TRAN_CMF_10,
                    :MTMPLOTHIS_N.TRAN_CMF_11,
                    :MTMPLOTHIS_N.TRAN_CMF_12,
                    :MTMPLOTHIS_N.TRAN_CMF_13,
                    :MTMPLOTHIS_N.TRAN_CMF_14,
                    :MTMPLOTHIS_N.TRAN_CMF_15,
                    :MTMPLOTHIS_N.TRAN_CMF_16,
                    :MTMPLOTHIS_N.TRAN_CMF_17,
                    :MTMPLOTHIS_N.TRAN_CMF_18,
                    :MTMPLOTHIS_N.TRAN_CMF_19,
                    :MTMPLOTHIS_N.TRAN_CMF_20,
                    :MTMPLOTHIS_N.TRAN_USER_ID,
                    :MTMPLOTHIS_N.TRAN_COMMENT,
                    :MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ,
                    :MTMPLOTHIS_N.MULTI_TR_KEY,
                    :MTMPLOTHIS_N.MULTI_TR_SEQ,
                    :MTMPLOTHIS_N.EXT_HIST_SEQ,
                    :MTMPLOTHIS_N.HIST_DEL_FLAG,
                    :MTMPLOTHIS_N.HIST_DEL_TIME,
                    :MTMPLOTHIS_N.HIST_DEL_USER_ID,
                    :MTMPLOTHIS_N.HIST_DEL_COMMENT,
                    :MTMPLOTHIS_N.PROCESS_FLAG
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 220;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MTMPLOTHIS (TABLE_UPDATE_SEQ,CM_KEY_1,CM_KEY_2,CM_KEY_3,C\
M_KEY_4,CM_KEY_5,LOT_ID,SUB_LOT_ID,SUB_LOT_FLAG,HIST_SEQ,TRAN_TIME,SYS_TRAN_\
TIME,TRAN_CODE,LOT_DESC,FACTORY,MAT_ID,MAT_VER,FLOW,FLOW_SEQ_NUM,OPER,QTY_1,\
QTY_2,QTY_3,CRR_ID,LOT_TYPE,OWNER_CODE,CREATE_CODE,LOT_PRIORITY,LOT_STATUS,H\
OLD_FLAG,HOLD_CODE,HOLD_PASSWORD,HOLD_PRV_GRP_ID,OPER_IN_QTY_1,OPER_IN_QTY_2\
,OPER_IN_QTY_3,CREATE_QTY_1,CREATE_QTY_2,CREATE_QTY_3,START_QTY_1,START_QTY_\
2,START_QTY_3,INV_FLAG,TRANSIT_FLAG,UNIT_EXIST_FLAG,INV_UNIT,RWK_FLAG,RWK_CO\
DE,RWK_COUNT,RWK_RET_FLOW,RWK_RET_FLOW_SEQ_NUM,RWK_RET_OPER,RWK_END_FLOW,RWK\
_END_FLOW_SEQ_NUM,RWK_END_OPER,RWK_RET_CLEAR_FLAG,RWK_TIME,NSTD_FLAG,NSTD_RE\
T_FLOW,NSTD_RET_FLOW_SEQ_NUM,NSTD_RET_OPER,NSTD_TIME,REP_FLAG,REP_RET_OPER,S\
TR_RET_FLOW,STR_RET_FLOW_SEQ_NUM,STR_RET_OPER,START_FLAG,START_TIME,START_RE\
S_ID,END_FLAG,END_TIME,END_RES_ID,SAMPLE_FLAG,SAMPLE_WAIT_FLAG,SAMPLE_RESULT\
,FROM_TO_FLAG,FROM_TO_LOT_ID,SHIP_CODE,SHIP_TIME,ORG_DUE_TIME,SCH_DUE_TIME,C\
REATE_TIME,FAC_IN_TIME,FLOW_IN_TIME,OPER_IN");
    sqlbuft((void **)0,
      "_TIME,RESERVE_RES_ID,PORT_ID,BATCH_ID,BATCH_SEQ,ORDER_ID,ADD_ORDER_ID\
_1,ADD_ORDER_ID_2,ADD_ORDER_ID_3,LOT_LOCATION_1,LOT_LOCATION_2,LOT_LOCATION_\
3,LOT_CMF_1,LOT_CMF_2,LOT_CMF_3,LOT_CMF_4,LOT_CMF_5,LOT_CMF_6,LOT_CMF_7,LOT_\
CMF_8,LOT_CMF_9,LOT_CMF_10,LOT_CMF_11,LOT_CMF_12,LOT_CMF_13,LOT_CMF_14,LOT_C\
MF_15,LOT_CMF_16,LOT_CMF_17,LOT_CMF_18,LOT_CMF_19,LOT_CMF_20,LOT_DEL_FLAG,LO\
T_DEL_CODE,LOT_DEL_TIME,BOM_SET_ID,BOM_SET_VERSION,BOM_ACTIVE_HIST_SEQ,BOM_H\
IST_SEQ,CRITICAL_RES_ID,CRITICAL_RES_GROUP_ID,SAVE_RES_ID_1,SAVE_RES_ID_2,SU\
BRES_ID,LOT_GROUP_ID_1,LOT_GROUP_ID_2,LOT_GROUP_ID_3,YIELD_1,YIELD_2,YIELD_3\
,GOOD_QTY,RESV_FIELD_1,RESV_FIELD_2,RESV_FIELD_3,RESV_FIELD_4,RESV_FIELD_5,R\
ESV_FLAG_1,RESV_FLAG_2,RESV_FLAG_3,RESV_FLAG_4,RESV_FLAG_5,FROM_TO_MAT_ID,FR\
OM_TO_MAT_VER,FROM_TO_FLOW,FROM_TO_FLOW_SEQ_NUM,FROM_TO_OPER,FROM_TO_QTY_1,F\
ROM_TO_QTY_2,FROM_TO_QTY_3,FROM_TO_HIST_SEQ,OLD_TRAN_TIME,OLD_SYS_TRAN_TIME,\
OLD_TRAN_CODE,OLD_FACTORY,OLD_MAT_ID,OLD_MAT_VER,OLD_FLOW,OLD_FLOW_SEQ_NUM,O\
LD_OPER,OLD_CM_KEY_1,OLD_CM_KEY_2,OLD_CM_KE");
    sqlbuft((void **)0,
      "Y_3,OLD_CM_KEY_4,OLD_CM_KEY_5,OLD_QTY_1,OLD_QTY_2,OLD_QTY_3,OLD_CRR_I\
D,OLD_LOT_TYPE,OLD_LOT_PRIORITY,OLD_ORDER_ID,OLD_OWNER_CODE,OLD_CREATE_CODE,\
OLD_FAC_IN_TIME,OLD_FLOW_IN_TIME,OLD_OPER_IN_TIME,OLD_RWK_FLAG,OLD_START_FLA\
G,OLD_START_TIME,OLD_START_RES_ID,OLD_END_FLAG,OLD_END_TIME,OLD_END_RES_ID,T\
RAN_CMF_1,TRAN_CMF_2,TRAN_CMF_3,TRAN_CMF_4,TRAN_CMF_5,TRAN_CMF_6,TRAN_CMF_7,\
TRAN_CMF_8,TRAN_CMF_9,TRAN_CMF_10,TRAN_CMF_11,TRAN_CMF_12,TRAN_CMF_13,TRAN_C\
MF_14,TRAN_CMF_15,TRAN_CMF_16,TRAN_CMF_17,TRAN_CMF_18,TRAN_CMF_19,TRAN_CMF_2\
0,TRAN_USER_ID,TRAN_COMMENT,PREV_ACTIVE_HIST_SEQ,MULTI_TR_KEY,MULTI_TR_SEQ,E\
XT_HIST_SEQ,HIST_DEL_FLAG,HIST_DEL_TIME,HIST_DEL_USER_ID,HIST_DEL_COMMENT,PR\
OCESS_FLAG) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:\
b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b4\
3,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58\
,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b");
    sqlstm.stmt = "67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b7\
8,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,\
:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107\
,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b12\
0,:b121,:b122,:b123,:b124,:b125,:b126,:b127,:b128,:b129,:b130,:b131,:b132,:b1\
33,:b134,:b135,:b136,:b137,:b138,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b\
146,:b147,:b148,:b149,:b150,:b151,:b152,:b153,:b154,:b155,:b156,:b157,:b158,:\
b159,:b160,:b161,:b162,:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170,:b171,\
:b172,:b173,:b174,:b175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b184\
,:b185,:b186,:b187,:b188,:b189,:b190,:b191,:b192,:b193,:b194,:b195,:b196,:b19\
7,:b198,:b199,:b200,:b201,:b202,:b203,:b204,:b205,:b206,:b207,:b208,:b209,:b2\
10,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b218)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1856;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MTMPLOTHIS_N.CM_KEY_1);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MTMPLOTHIS_N.CM_KEY_2);
    sqlstm.sqhstl[2] = (unsigned int  )31;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MTMPLOTHIS_N.CM_KEY_3);
    sqlstm.sqhstl[3] = (unsigned int  )31;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MTMPLOTHIS_N.CM_KEY_4);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MTMPLOTHIS_N.CM_KEY_5);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MTMPLOTHIS_N.LOT_ID);
    sqlstm.sqhstl[6] = (unsigned int  )26;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_ID);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_FLAG);
    sqlstm.sqhstl[8] = (unsigned int  )2;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)&(MTMPLOTHIS_N.HIST_SEQ);
    sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MTMPLOTHIS_N.TRAN_TIME);
    sqlstm.sqhstl[10] = (unsigned int  )15;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MTMPLOTHIS_N.SYS_TRAN_TIME);
    sqlstm.sqhstl[11] = (unsigned int  )15;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MTMPLOTHIS_N.TRAN_CODE);
    sqlstm.sqhstl[12] = (unsigned int  )13;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MTMPLOTHIS_N.LOT_DESC);
    sqlstm.sqhstl[13] = (unsigned int  )201;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MTMPLOTHIS_N.FACTORY);
    sqlstm.sqhstl[14] = (unsigned int  )11;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MTMPLOTHIS_N.MAT_ID);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(MTMPLOTHIS_N.MAT_VER);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MTMPLOTHIS_N.FLOW);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)&(MTMPLOTHIS_N.FLOW_SEQ_NUM);
    sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MTMPLOTHIS_N.OPER);
    sqlstm.sqhstl[19] = (unsigned int  )11;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)&(MTMPLOTHIS_N.QTY_1);
    sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)&(MTMPLOTHIS_N.QTY_2);
    sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(MTMPLOTHIS_N.QTY_3);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MTMPLOTHIS_N.CRR_ID);
    sqlstm.sqhstl[23] = (unsigned int  )21;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MTMPLOTHIS_N.LOT_TYPE);
    sqlstm.sqhstl[24] = (unsigned int  )2;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MTMPLOTHIS_N.OWNER_CODE);
    sqlstm.sqhstl[25] = (unsigned int  )11;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MTMPLOTHIS_N.CREATE_CODE);
    sqlstm.sqhstl[26] = (unsigned int  )11;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MTMPLOTHIS_N.LOT_PRIORITY);
    sqlstm.sqhstl[27] = (unsigned int  )2;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MTMPLOTHIS_N.LOT_STATUS);
    sqlstm.sqhstl[28] = (unsigned int  )11;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MTMPLOTHIS_N.HOLD_FLAG);
    sqlstm.sqhstl[29] = (unsigned int  )2;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MTMPLOTHIS_N.HOLD_CODE);
    sqlstm.sqhstl[30] = (unsigned int  )11;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MTMPLOTHIS_N.HOLD_PASSWORD);
    sqlstm.sqhstl[31] = (unsigned int  )21;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MTMPLOTHIS_N.HOLD_PRV_GRP_ID);
    sqlstm.sqhstl[32] = (unsigned int  )21;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_1);
    sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_2);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_3);
    sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_1);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_2);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_3);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)&(MTMPLOTHIS_N.START_QTY_1);
    sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(MTMPLOTHIS_N.START_QTY_2);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)&(MTMPLOTHIS_N.START_QTY_3);
    sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MTMPLOTHIS_N.INV_FLAG);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MTMPLOTHIS_N.TRANSIT_FLAG);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MTMPLOTHIS_N.UNIT_EXIST_FLAG);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MTMPLOTHIS_N.INV_UNIT);
    sqlstm.sqhstl[45] = (unsigned int  )11;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MTMPLOTHIS_N.RWK_FLAG);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MTMPLOTHIS_N.RWK_CODE);
    sqlstm.sqhstl[47] = (unsigned int  )11;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)&(MTMPLOTHIS_N.RWK_COUNT);
    sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MTMPLOTHIS_N.RWK_RET_FLOW);
    sqlstm.sqhstl[49] = (unsigned int  )21;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)&(MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MTMPLOTHIS_N.RWK_RET_OPER);
    sqlstm.sqhstl[51] = (unsigned int  )11;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MTMPLOTHIS_N.RWK_END_FLOW);
    sqlstm.sqhstl[52] = (unsigned int  )21;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)&(MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM);
    sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MTMPLOTHIS_N.RWK_END_OPER);
    sqlstm.sqhstl[54] = (unsigned int  )11;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MTMPLOTHIS_N.RWK_TIME);
    sqlstm.sqhstl[56] = (unsigned int  )15;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MTMPLOTHIS_N.NSTD_FLAG);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_FLOW);
    sqlstm.sqhstl[58] = (unsigned int  )21;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)&(MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_OPER);
    sqlstm.sqhstl[60] = (unsigned int  )11;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MTMPLOTHIS_N.NSTD_TIME);
    sqlstm.sqhstl[61] = (unsigned int  )15;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MTMPLOTHIS_N.REP_FLAG);
    sqlstm.sqhstl[62] = (unsigned int  )2;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MTMPLOTHIS_N.REP_RET_OPER);
    sqlstm.sqhstl[63] = (unsigned int  )11;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MTMPLOTHIS_N.STR_RET_FLOW);
    sqlstm.sqhstl[64] = (unsigned int  )21;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)&(MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM);
    sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MTMPLOTHIS_N.STR_RET_OPER);
    sqlstm.sqhstl[66] = (unsigned int  )11;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MTMPLOTHIS_N.START_FLAG);
    sqlstm.sqhstl[67] = (unsigned int  )2;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MTMPLOTHIS_N.START_TIME);
    sqlstm.sqhstl[68] = (unsigned int  )15;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MTMPLOTHIS_N.START_RES_ID);
    sqlstm.sqhstl[69] = (unsigned int  )21;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MTMPLOTHIS_N.END_FLAG);
    sqlstm.sqhstl[70] = (unsigned int  )2;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MTMPLOTHIS_N.END_TIME);
    sqlstm.sqhstl[71] = (unsigned int  )15;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MTMPLOTHIS_N.END_RES_ID);
    sqlstm.sqhstl[72] = (unsigned int  )21;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MTMPLOTHIS_N.SAMPLE_FLAG);
    sqlstm.sqhstl[73] = (unsigned int  )2;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MTMPLOTHIS_N.SAMPLE_WAIT_FLAG);
    sqlstm.sqhstl[74] = (unsigned int  )2;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MTMPLOTHIS_N.SAMPLE_RESULT);
    sqlstm.sqhstl[75] = (unsigned int  )2;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLAG);
    sqlstm.sqhstl[76] = (unsigned int  )2;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MTMPLOTHIS_N.FROM_TO_LOT_ID);
    sqlstm.sqhstl[77] = (unsigned int  )26;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MTMPLOTHIS_N.SHIP_CODE);
    sqlstm.sqhstl[78] = (unsigned int  )11;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MTMPLOTHIS_N.SHIP_TIME);
    sqlstm.sqhstl[79] = (unsigned int  )15;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MTMPLOTHIS_N.ORG_DUE_TIME);
    sqlstm.sqhstl[80] = (unsigned int  )15;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MTMPLOTHIS_N.SCH_DUE_TIME);
    sqlstm.sqhstl[81] = (unsigned int  )15;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MTMPLOTHIS_N.CREATE_TIME);
    sqlstm.sqhstl[82] = (unsigned int  )15;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MTMPLOTHIS_N.FAC_IN_TIME);
    sqlstm.sqhstl[83] = (unsigned int  )15;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MTMPLOTHIS_N.FLOW_IN_TIME);
    sqlstm.sqhstl[84] = (unsigned int  )15;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MTMPLOTHIS_N.OPER_IN_TIME);
    sqlstm.sqhstl[85] = (unsigned int  )15;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MTMPLOTHIS_N.RESERVE_RES_ID);
    sqlstm.sqhstl[86] = (unsigned int  )21;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MTMPLOTHIS_N.PORT_ID);
    sqlstm.sqhstl[87] = (unsigned int  )11;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MTMPLOTHIS_N.BATCH_ID);
    sqlstm.sqhstl[88] = (unsigned int  )26;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)&(MTMPLOTHIS_N.BATCH_SEQ);
    sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MTMPLOTHIS_N.ORDER_ID);
    sqlstm.sqhstl[90] = (unsigned int  )26;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_1);
    sqlstm.sqhstl[91] = (unsigned int  )26;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_2);
    sqlstm.sqhstl[92] = (unsigned int  )26;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_3);
    sqlstm.sqhstl[93] = (unsigned int  )26;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_1);
    sqlstm.sqhstl[94] = (unsigned int  )21;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_2);
    sqlstm.sqhstl[95] = (unsigned int  )21;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_3);
    sqlstm.sqhstl[96] = (unsigned int  )21;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_1);
    sqlstm.sqhstl[97] = (unsigned int  )31;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_2);
    sqlstm.sqhstl[98] = (unsigned int  )31;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_3);
    sqlstm.sqhstl[99] = (unsigned int  )31;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_4);
    sqlstm.sqhstl[100] = (unsigned int  )31;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_5);
    sqlstm.sqhstl[101] = (unsigned int  )31;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_6);
    sqlstm.sqhstl[102] = (unsigned int  )31;
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_7);
    sqlstm.sqhstl[103] = (unsigned int  )31;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_8);
    sqlstm.sqhstl[104] = (unsigned int  )31;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_9);
    sqlstm.sqhstl[105] = (unsigned int  )31;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_10);
    sqlstm.sqhstl[106] = (unsigned int  )31;
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_11);
    sqlstm.sqhstl[107] = (unsigned int  )31;
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
    sqlstm.sqhstv[108] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_12);
    sqlstm.sqhstl[108] = (unsigned int  )31;
    sqlstm.sqhsts[108] = (         int  )0;
    sqlstm.sqindv[108] = (         void  *)0;
    sqlstm.sqinds[108] = (         int  )0;
    sqlstm.sqharm[108] = (unsigned int  )0;
    sqlstm.sqadto[108] = (unsigned short )0;
    sqlstm.sqtdso[108] = (unsigned short )0;
    sqlstm.sqhstv[109] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_13);
    sqlstm.sqhstl[109] = (unsigned int  )31;
    sqlstm.sqhsts[109] = (         int  )0;
    sqlstm.sqindv[109] = (         void  *)0;
    sqlstm.sqinds[109] = (         int  )0;
    sqlstm.sqharm[109] = (unsigned int  )0;
    sqlstm.sqadto[109] = (unsigned short )0;
    sqlstm.sqtdso[109] = (unsigned short )0;
    sqlstm.sqhstv[110] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_14);
    sqlstm.sqhstl[110] = (unsigned int  )31;
    sqlstm.sqhsts[110] = (         int  )0;
    sqlstm.sqindv[110] = (         void  *)0;
    sqlstm.sqinds[110] = (         int  )0;
    sqlstm.sqharm[110] = (unsigned int  )0;
    sqlstm.sqadto[110] = (unsigned short )0;
    sqlstm.sqtdso[110] = (unsigned short )0;
    sqlstm.sqhstv[111] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_15);
    sqlstm.sqhstl[111] = (unsigned int  )31;
    sqlstm.sqhsts[111] = (         int  )0;
    sqlstm.sqindv[111] = (         void  *)0;
    sqlstm.sqinds[111] = (         int  )0;
    sqlstm.sqharm[111] = (unsigned int  )0;
    sqlstm.sqadto[111] = (unsigned short )0;
    sqlstm.sqtdso[111] = (unsigned short )0;
    sqlstm.sqhstv[112] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_16);
    sqlstm.sqhstl[112] = (unsigned int  )31;
    sqlstm.sqhsts[112] = (         int  )0;
    sqlstm.sqindv[112] = (         void  *)0;
    sqlstm.sqinds[112] = (         int  )0;
    sqlstm.sqharm[112] = (unsigned int  )0;
    sqlstm.sqadto[112] = (unsigned short )0;
    sqlstm.sqtdso[112] = (unsigned short )0;
    sqlstm.sqhstv[113] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_17);
    sqlstm.sqhstl[113] = (unsigned int  )31;
    sqlstm.sqhsts[113] = (         int  )0;
    sqlstm.sqindv[113] = (         void  *)0;
    sqlstm.sqinds[113] = (         int  )0;
    sqlstm.sqharm[113] = (unsigned int  )0;
    sqlstm.sqadto[113] = (unsigned short )0;
    sqlstm.sqtdso[113] = (unsigned short )0;
    sqlstm.sqhstv[114] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_18);
    sqlstm.sqhstl[114] = (unsigned int  )31;
    sqlstm.sqhsts[114] = (         int  )0;
    sqlstm.sqindv[114] = (         void  *)0;
    sqlstm.sqinds[114] = (         int  )0;
    sqlstm.sqharm[114] = (unsigned int  )0;
    sqlstm.sqadto[114] = (unsigned short )0;
    sqlstm.sqtdso[114] = (unsigned short )0;
    sqlstm.sqhstv[115] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_19);
    sqlstm.sqhstl[115] = (unsigned int  )31;
    sqlstm.sqhsts[115] = (         int  )0;
    sqlstm.sqindv[115] = (         void  *)0;
    sqlstm.sqinds[115] = (         int  )0;
    sqlstm.sqharm[115] = (unsigned int  )0;
    sqlstm.sqadto[115] = (unsigned short )0;
    sqlstm.sqtdso[115] = (unsigned short )0;
    sqlstm.sqhstv[116] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_20);
    sqlstm.sqhstl[116] = (unsigned int  )31;
    sqlstm.sqhsts[116] = (         int  )0;
    sqlstm.sqindv[116] = (         void  *)0;
    sqlstm.sqinds[116] = (         int  )0;
    sqlstm.sqharm[116] = (unsigned int  )0;
    sqlstm.sqadto[116] = (unsigned short )0;
    sqlstm.sqtdso[116] = (unsigned short )0;
    sqlstm.sqhstv[117] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_FLAG);
    sqlstm.sqhstl[117] = (unsigned int  )2;
    sqlstm.sqhsts[117] = (         int  )0;
    sqlstm.sqindv[117] = (         void  *)0;
    sqlstm.sqinds[117] = (         int  )0;
    sqlstm.sqharm[117] = (unsigned int  )0;
    sqlstm.sqadto[117] = (unsigned short )0;
    sqlstm.sqtdso[117] = (unsigned short )0;
    sqlstm.sqhstv[118] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_CODE);
    sqlstm.sqhstl[118] = (unsigned int  )11;
    sqlstm.sqhsts[118] = (         int  )0;
    sqlstm.sqindv[118] = (         void  *)0;
    sqlstm.sqinds[118] = (         int  )0;
    sqlstm.sqharm[118] = (unsigned int  )0;
    sqlstm.sqadto[118] = (unsigned short )0;
    sqlstm.sqtdso[118] = (unsigned short )0;
    sqlstm.sqhstv[119] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_TIME);
    sqlstm.sqhstl[119] = (unsigned int  )15;
    sqlstm.sqhsts[119] = (         int  )0;
    sqlstm.sqindv[119] = (         void  *)0;
    sqlstm.sqinds[119] = (         int  )0;
    sqlstm.sqharm[119] = (unsigned int  )0;
    sqlstm.sqadto[119] = (unsigned short )0;
    sqlstm.sqtdso[119] = (unsigned short )0;
    sqlstm.sqhstv[120] = (         void  *)(MTMPLOTHIS_N.BOM_SET_ID);
    sqlstm.sqhstl[120] = (unsigned int  )26;
    sqlstm.sqhsts[120] = (         int  )0;
    sqlstm.sqindv[120] = (         void  *)0;
    sqlstm.sqinds[120] = (         int  )0;
    sqlstm.sqharm[120] = (unsigned int  )0;
    sqlstm.sqadto[120] = (unsigned short )0;
    sqlstm.sqtdso[120] = (unsigned short )0;
    sqlstm.sqhstv[121] = (         void  *)&(MTMPLOTHIS_N.BOM_SET_VERSION);
    sqlstm.sqhstl[121] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[121] = (         int  )0;
    sqlstm.sqindv[121] = (         void  *)0;
    sqlstm.sqinds[121] = (         int  )0;
    sqlstm.sqharm[121] = (unsigned int  )0;
    sqlstm.sqadto[121] = (unsigned short )0;
    sqlstm.sqtdso[121] = (unsigned short )0;
    sqlstm.sqhstv[122] = (         void  *)&(MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ);
    sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[122] = (         int  )0;
    sqlstm.sqindv[122] = (         void  *)0;
    sqlstm.sqinds[122] = (         int  )0;
    sqlstm.sqharm[122] = (unsigned int  )0;
    sqlstm.sqadto[122] = (unsigned short )0;
    sqlstm.sqtdso[122] = (unsigned short )0;
    sqlstm.sqhstv[123] = (         void  *)&(MTMPLOTHIS_N.BOM_HIST_SEQ);
    sqlstm.sqhstl[123] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[123] = (         int  )0;
    sqlstm.sqindv[123] = (         void  *)0;
    sqlstm.sqinds[123] = (         int  )0;
    sqlstm.sqharm[123] = (unsigned int  )0;
    sqlstm.sqadto[123] = (unsigned short )0;
    sqlstm.sqtdso[123] = (unsigned short )0;
    sqlstm.sqhstv[124] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_ID);
    sqlstm.sqhstl[124] = (unsigned int  )21;
    sqlstm.sqhsts[124] = (         int  )0;
    sqlstm.sqindv[124] = (         void  *)0;
    sqlstm.sqinds[124] = (         int  )0;
    sqlstm.sqharm[124] = (unsigned int  )0;
    sqlstm.sqadto[124] = (unsigned short )0;
    sqlstm.sqtdso[124] = (unsigned short )0;
    sqlstm.sqhstv[125] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID);
    sqlstm.sqhstl[125] = (unsigned int  )21;
    sqlstm.sqhsts[125] = (         int  )0;
    sqlstm.sqindv[125] = (         void  *)0;
    sqlstm.sqinds[125] = (         int  )0;
    sqlstm.sqharm[125] = (unsigned int  )0;
    sqlstm.sqadto[125] = (unsigned short )0;
    sqlstm.sqtdso[125] = (unsigned short )0;
    sqlstm.sqhstv[126] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_1);
    sqlstm.sqhstl[126] = (unsigned int  )21;
    sqlstm.sqhsts[126] = (         int  )0;
    sqlstm.sqindv[126] = (         void  *)0;
    sqlstm.sqinds[126] = (         int  )0;
    sqlstm.sqharm[126] = (unsigned int  )0;
    sqlstm.sqadto[126] = (unsigned short )0;
    sqlstm.sqtdso[126] = (unsigned short )0;
    sqlstm.sqhstv[127] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_2);
    sqlstm.sqhstl[127] = (unsigned int  )21;
    sqlstm.sqhsts[127] = (         int  )0;
    sqlstm.sqindv[127] = (         void  *)0;
    sqlstm.sqinds[127] = (         int  )0;
    sqlstm.sqharm[127] = (unsigned int  )0;
    sqlstm.sqadto[127] = (unsigned short )0;
    sqlstm.sqtdso[127] = (unsigned short )0;
    sqlstm.sqhstv[128] = (         void  *)(MTMPLOTHIS_N.SUBRES_ID);
    sqlstm.sqhstl[128] = (unsigned int  )21;
    sqlstm.sqhsts[128] = (         int  )0;
    sqlstm.sqindv[128] = (         void  *)0;
    sqlstm.sqinds[128] = (         int  )0;
    sqlstm.sqharm[128] = (unsigned int  )0;
    sqlstm.sqadto[128] = (unsigned short )0;
    sqlstm.sqtdso[128] = (unsigned short )0;
    sqlstm.sqhstv[129] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_1);
    sqlstm.sqhstl[129] = (unsigned int  )26;
    sqlstm.sqhsts[129] = (         int  )0;
    sqlstm.sqindv[129] = (         void  *)0;
    sqlstm.sqinds[129] = (         int  )0;
    sqlstm.sqharm[129] = (unsigned int  )0;
    sqlstm.sqadto[129] = (unsigned short )0;
    sqlstm.sqtdso[129] = (unsigned short )0;
    sqlstm.sqhstv[130] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_2);
    sqlstm.sqhstl[130] = (unsigned int  )26;
    sqlstm.sqhsts[130] = (         int  )0;
    sqlstm.sqindv[130] = (         void  *)0;
    sqlstm.sqinds[130] = (         int  )0;
    sqlstm.sqharm[130] = (unsigned int  )0;
    sqlstm.sqadto[130] = (unsigned short )0;
    sqlstm.sqtdso[130] = (unsigned short )0;
    sqlstm.sqhstv[131] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_3);
    sqlstm.sqhstl[131] = (unsigned int  )26;
    sqlstm.sqhsts[131] = (         int  )0;
    sqlstm.sqindv[131] = (         void  *)0;
    sqlstm.sqinds[131] = (         int  )0;
    sqlstm.sqharm[131] = (unsigned int  )0;
    sqlstm.sqadto[131] = (unsigned short )0;
    sqlstm.sqtdso[131] = (unsigned short )0;
    sqlstm.sqhstv[132] = (         void  *)&(MTMPLOTHIS_N.YIELD_1);
    sqlstm.sqhstl[132] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[132] = (         int  )0;
    sqlstm.sqindv[132] = (         void  *)0;
    sqlstm.sqinds[132] = (         int  )0;
    sqlstm.sqharm[132] = (unsigned int  )0;
    sqlstm.sqadto[132] = (unsigned short )0;
    sqlstm.sqtdso[132] = (unsigned short )0;
    sqlstm.sqhstv[133] = (         void  *)&(MTMPLOTHIS_N.YIELD_2);
    sqlstm.sqhstl[133] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[133] = (         int  )0;
    sqlstm.sqindv[133] = (         void  *)0;
    sqlstm.sqinds[133] = (         int  )0;
    sqlstm.sqharm[133] = (unsigned int  )0;
    sqlstm.sqadto[133] = (unsigned short )0;
    sqlstm.sqtdso[133] = (unsigned short )0;
    sqlstm.sqhstv[134] = (         void  *)&(MTMPLOTHIS_N.YIELD_3);
    sqlstm.sqhstl[134] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[134] = (         int  )0;
    sqlstm.sqindv[134] = (         void  *)0;
    sqlstm.sqinds[134] = (         int  )0;
    sqlstm.sqharm[134] = (unsigned int  )0;
    sqlstm.sqadto[134] = (unsigned short )0;
    sqlstm.sqtdso[134] = (unsigned short )0;
    sqlstm.sqhstv[135] = (         void  *)&(MTMPLOTHIS_N.GOOD_QTY);
    sqlstm.sqhstl[135] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[135] = (         int  )0;
    sqlstm.sqindv[135] = (         void  *)0;
    sqlstm.sqinds[135] = (         int  )0;
    sqlstm.sqharm[135] = (unsigned int  )0;
    sqlstm.sqadto[135] = (unsigned short )0;
    sqlstm.sqtdso[135] = (unsigned short )0;
    sqlstm.sqhstv[136] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_1);
    sqlstm.sqhstl[136] = (unsigned int  )31;
    sqlstm.sqhsts[136] = (         int  )0;
    sqlstm.sqindv[136] = (         void  *)0;
    sqlstm.sqinds[136] = (         int  )0;
    sqlstm.sqharm[136] = (unsigned int  )0;
    sqlstm.sqadto[136] = (unsigned short )0;
    sqlstm.sqtdso[136] = (unsigned short )0;
    sqlstm.sqhstv[137] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_2);
    sqlstm.sqhstl[137] = (unsigned int  )31;
    sqlstm.sqhsts[137] = (         int  )0;
    sqlstm.sqindv[137] = (         void  *)0;
    sqlstm.sqinds[137] = (         int  )0;
    sqlstm.sqharm[137] = (unsigned int  )0;
    sqlstm.sqadto[137] = (unsigned short )0;
    sqlstm.sqtdso[137] = (unsigned short )0;
    sqlstm.sqhstv[138] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_3);
    sqlstm.sqhstl[138] = (unsigned int  )31;
    sqlstm.sqhsts[138] = (         int  )0;
    sqlstm.sqindv[138] = (         void  *)0;
    sqlstm.sqinds[138] = (         int  )0;
    sqlstm.sqharm[138] = (unsigned int  )0;
    sqlstm.sqadto[138] = (unsigned short )0;
    sqlstm.sqtdso[138] = (unsigned short )0;
    sqlstm.sqhstv[139] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_4);
    sqlstm.sqhstl[139] = (unsigned int  )31;
    sqlstm.sqhsts[139] = (         int  )0;
    sqlstm.sqindv[139] = (         void  *)0;
    sqlstm.sqinds[139] = (         int  )0;
    sqlstm.sqharm[139] = (unsigned int  )0;
    sqlstm.sqadto[139] = (unsigned short )0;
    sqlstm.sqtdso[139] = (unsigned short )0;
    sqlstm.sqhstv[140] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_5);
    sqlstm.sqhstl[140] = (unsigned int  )31;
    sqlstm.sqhsts[140] = (         int  )0;
    sqlstm.sqindv[140] = (         void  *)0;
    sqlstm.sqinds[140] = (         int  )0;
    sqlstm.sqharm[140] = (unsigned int  )0;
    sqlstm.sqadto[140] = (unsigned short )0;
    sqlstm.sqtdso[140] = (unsigned short )0;
    sqlstm.sqhstv[141] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_1);
    sqlstm.sqhstl[141] = (unsigned int  )2;
    sqlstm.sqhsts[141] = (         int  )0;
    sqlstm.sqindv[141] = (         void  *)0;
    sqlstm.sqinds[141] = (         int  )0;
    sqlstm.sqharm[141] = (unsigned int  )0;
    sqlstm.sqadto[141] = (unsigned short )0;
    sqlstm.sqtdso[141] = (unsigned short )0;
    sqlstm.sqhstv[142] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_2);
    sqlstm.sqhstl[142] = (unsigned int  )2;
    sqlstm.sqhsts[142] = (         int  )0;
    sqlstm.sqindv[142] = (         void  *)0;
    sqlstm.sqinds[142] = (         int  )0;
    sqlstm.sqharm[142] = (unsigned int  )0;
    sqlstm.sqadto[142] = (unsigned short )0;
    sqlstm.sqtdso[142] = (unsigned short )0;
    sqlstm.sqhstv[143] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_3);
    sqlstm.sqhstl[143] = (unsigned int  )2;
    sqlstm.sqhsts[143] = (         int  )0;
    sqlstm.sqindv[143] = (         void  *)0;
    sqlstm.sqinds[143] = (         int  )0;
    sqlstm.sqharm[143] = (unsigned int  )0;
    sqlstm.sqadto[143] = (unsigned short )0;
    sqlstm.sqtdso[143] = (unsigned short )0;
    sqlstm.sqhstv[144] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_4);
    sqlstm.sqhstl[144] = (unsigned int  )2;
    sqlstm.sqhsts[144] = (         int  )0;
    sqlstm.sqindv[144] = (         void  *)0;
    sqlstm.sqinds[144] = (         int  )0;
    sqlstm.sqharm[144] = (unsigned int  )0;
    sqlstm.sqadto[144] = (unsigned short )0;
    sqlstm.sqtdso[144] = (unsigned short )0;
    sqlstm.sqhstv[145] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_5);
    sqlstm.sqhstl[145] = (unsigned int  )2;
    sqlstm.sqhsts[145] = (         int  )0;
    sqlstm.sqindv[145] = (         void  *)0;
    sqlstm.sqinds[145] = (         int  )0;
    sqlstm.sqharm[145] = (unsigned int  )0;
    sqlstm.sqadto[145] = (unsigned short )0;
    sqlstm.sqtdso[145] = (unsigned short )0;
    sqlstm.sqhstv[146] = (         void  *)(MTMPLOTHIS_N.FROM_TO_MAT_ID);
    sqlstm.sqhstl[146] = (unsigned int  )31;
    sqlstm.sqhsts[146] = (         int  )0;
    sqlstm.sqindv[146] = (         void  *)0;
    sqlstm.sqinds[146] = (         int  )0;
    sqlstm.sqharm[146] = (unsigned int  )0;
    sqlstm.sqadto[146] = (unsigned short )0;
    sqlstm.sqtdso[146] = (unsigned short )0;
    sqlstm.sqhstv[147] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_MAT_VER);
    sqlstm.sqhstl[147] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[147] = (         int  )0;
    sqlstm.sqindv[147] = (         void  *)0;
    sqlstm.sqinds[147] = (         int  )0;
    sqlstm.sqharm[147] = (unsigned int  )0;
    sqlstm.sqadto[147] = (unsigned short )0;
    sqlstm.sqtdso[147] = (unsigned short )0;
    sqlstm.sqhstv[148] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLOW);
    sqlstm.sqhstl[148] = (unsigned int  )21;
    sqlstm.sqhsts[148] = (         int  )0;
    sqlstm.sqindv[148] = (         void  *)0;
    sqlstm.sqinds[148] = (         int  )0;
    sqlstm.sqharm[148] = (unsigned int  )0;
    sqlstm.sqadto[148] = (unsigned short )0;
    sqlstm.sqtdso[148] = (unsigned short )0;
    sqlstm.sqhstv[149] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM);
    sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[149] = (         int  )0;
    sqlstm.sqindv[149] = (         void  *)0;
    sqlstm.sqinds[149] = (         int  )0;
    sqlstm.sqharm[149] = (unsigned int  )0;
    sqlstm.sqadto[149] = (unsigned short )0;
    sqlstm.sqtdso[149] = (unsigned short )0;
    sqlstm.sqhstv[150] = (         void  *)(MTMPLOTHIS_N.FROM_TO_OPER);
    sqlstm.sqhstl[150] = (unsigned int  )11;
    sqlstm.sqhsts[150] = (         int  )0;
    sqlstm.sqindv[150] = (         void  *)0;
    sqlstm.sqinds[150] = (         int  )0;
    sqlstm.sqharm[150] = (unsigned int  )0;
    sqlstm.sqadto[150] = (unsigned short )0;
    sqlstm.sqtdso[150] = (unsigned short )0;
    sqlstm.sqhstv[151] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_1);
    sqlstm.sqhstl[151] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[151] = (         int  )0;
    sqlstm.sqindv[151] = (         void  *)0;
    sqlstm.sqinds[151] = (         int  )0;
    sqlstm.sqharm[151] = (unsigned int  )0;
    sqlstm.sqadto[151] = (unsigned short )0;
    sqlstm.sqtdso[151] = (unsigned short )0;
    sqlstm.sqhstv[152] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_2);
    sqlstm.sqhstl[152] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[152] = (         int  )0;
    sqlstm.sqindv[152] = (         void  *)0;
    sqlstm.sqinds[152] = (         int  )0;
    sqlstm.sqharm[152] = (unsigned int  )0;
    sqlstm.sqadto[152] = (unsigned short )0;
    sqlstm.sqtdso[152] = (unsigned short )0;
    sqlstm.sqhstv[153] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_3);
    sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[153] = (         int  )0;
    sqlstm.sqindv[153] = (         void  *)0;
    sqlstm.sqinds[153] = (         int  )0;
    sqlstm.sqharm[153] = (unsigned int  )0;
    sqlstm.sqadto[153] = (unsigned short )0;
    sqlstm.sqtdso[153] = (unsigned short )0;
    sqlstm.sqhstv[154] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_HIST_SEQ);
    sqlstm.sqhstl[154] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[154] = (         int  )0;
    sqlstm.sqindv[154] = (         void  *)0;
    sqlstm.sqinds[154] = (         int  )0;
    sqlstm.sqharm[154] = (unsigned int  )0;
    sqlstm.sqadto[154] = (unsigned short )0;
    sqlstm.sqtdso[154] = (unsigned short )0;
    sqlstm.sqhstv[155] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_TIME);
    sqlstm.sqhstl[155] = (unsigned int  )15;
    sqlstm.sqhsts[155] = (         int  )0;
    sqlstm.sqindv[155] = (         void  *)0;
    sqlstm.sqinds[155] = (         int  )0;
    sqlstm.sqharm[155] = (unsigned int  )0;
    sqlstm.sqadto[155] = (unsigned short )0;
    sqlstm.sqtdso[155] = (unsigned short )0;
    sqlstm.sqhstv[156] = (         void  *)(MTMPLOTHIS_N.OLD_SYS_TRAN_TIME);
    sqlstm.sqhstl[156] = (unsigned int  )15;
    sqlstm.sqhsts[156] = (         int  )0;
    sqlstm.sqindv[156] = (         void  *)0;
    sqlstm.sqinds[156] = (         int  )0;
    sqlstm.sqharm[156] = (unsigned int  )0;
    sqlstm.sqadto[156] = (unsigned short )0;
    sqlstm.sqtdso[156] = (unsigned short )0;
    sqlstm.sqhstv[157] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_CODE);
    sqlstm.sqhstl[157] = (unsigned int  )13;
    sqlstm.sqhsts[157] = (         int  )0;
    sqlstm.sqindv[157] = (         void  *)0;
    sqlstm.sqinds[157] = (         int  )0;
    sqlstm.sqharm[157] = (unsigned int  )0;
    sqlstm.sqadto[157] = (unsigned short )0;
    sqlstm.sqtdso[157] = (unsigned short )0;
    sqlstm.sqhstv[158] = (         void  *)(MTMPLOTHIS_N.OLD_FACTORY);
    sqlstm.sqhstl[158] = (unsigned int  )11;
    sqlstm.sqhsts[158] = (         int  )0;
    sqlstm.sqindv[158] = (         void  *)0;
    sqlstm.sqinds[158] = (         int  )0;
    sqlstm.sqharm[158] = (unsigned int  )0;
    sqlstm.sqadto[158] = (unsigned short )0;
    sqlstm.sqtdso[158] = (unsigned short )0;
    sqlstm.sqhstv[159] = (         void  *)(MTMPLOTHIS_N.OLD_MAT_ID);
    sqlstm.sqhstl[159] = (unsigned int  )31;
    sqlstm.sqhsts[159] = (         int  )0;
    sqlstm.sqindv[159] = (         void  *)0;
    sqlstm.sqinds[159] = (         int  )0;
    sqlstm.sqharm[159] = (unsigned int  )0;
    sqlstm.sqadto[159] = (unsigned short )0;
    sqlstm.sqtdso[159] = (unsigned short )0;
    sqlstm.sqhstv[160] = (         void  *)&(MTMPLOTHIS_N.OLD_MAT_VER);
    sqlstm.sqhstl[160] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[160] = (         int  )0;
    sqlstm.sqindv[160] = (         void  *)0;
    sqlstm.sqinds[160] = (         int  )0;
    sqlstm.sqharm[160] = (unsigned int  )0;
    sqlstm.sqadto[160] = (unsigned short )0;
    sqlstm.sqtdso[160] = (unsigned short )0;
    sqlstm.sqhstv[161] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW);
    sqlstm.sqhstl[161] = (unsigned int  )21;
    sqlstm.sqhsts[161] = (         int  )0;
    sqlstm.sqindv[161] = (         void  *)0;
    sqlstm.sqinds[161] = (         int  )0;
    sqlstm.sqharm[161] = (unsigned int  )0;
    sqlstm.sqadto[161] = (unsigned short )0;
    sqlstm.sqtdso[161] = (unsigned short )0;
    sqlstm.sqhstv[162] = (         void  *)&(MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM);
    sqlstm.sqhstl[162] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[162] = (         int  )0;
    sqlstm.sqindv[162] = (         void  *)0;
    sqlstm.sqinds[162] = (         int  )0;
    sqlstm.sqharm[162] = (unsigned int  )0;
    sqlstm.sqadto[162] = (unsigned short )0;
    sqlstm.sqtdso[162] = (unsigned short )0;
    sqlstm.sqhstv[163] = (         void  *)(MTMPLOTHIS_N.OLD_OPER);
    sqlstm.sqhstl[163] = (unsigned int  )11;
    sqlstm.sqhsts[163] = (         int  )0;
    sqlstm.sqindv[163] = (         void  *)0;
    sqlstm.sqinds[163] = (         int  )0;
    sqlstm.sqharm[163] = (unsigned int  )0;
    sqlstm.sqadto[163] = (unsigned short )0;
    sqlstm.sqtdso[163] = (unsigned short )0;
    sqlstm.sqhstv[164] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_1);
    sqlstm.sqhstl[164] = (unsigned int  )31;
    sqlstm.sqhsts[164] = (         int  )0;
    sqlstm.sqindv[164] = (         void  *)0;
    sqlstm.sqinds[164] = (         int  )0;
    sqlstm.sqharm[164] = (unsigned int  )0;
    sqlstm.sqadto[164] = (unsigned short )0;
    sqlstm.sqtdso[164] = (unsigned short )0;
    sqlstm.sqhstv[165] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_2);
    sqlstm.sqhstl[165] = (unsigned int  )31;
    sqlstm.sqhsts[165] = (         int  )0;
    sqlstm.sqindv[165] = (         void  *)0;
    sqlstm.sqinds[165] = (         int  )0;
    sqlstm.sqharm[165] = (unsigned int  )0;
    sqlstm.sqadto[165] = (unsigned short )0;
    sqlstm.sqtdso[165] = (unsigned short )0;
    sqlstm.sqhstv[166] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_3);
    sqlstm.sqhstl[166] = (unsigned int  )31;
    sqlstm.sqhsts[166] = (         int  )0;
    sqlstm.sqindv[166] = (         void  *)0;
    sqlstm.sqinds[166] = (         int  )0;
    sqlstm.sqharm[166] = (unsigned int  )0;
    sqlstm.sqadto[166] = (unsigned short )0;
    sqlstm.sqtdso[166] = (unsigned short )0;
    sqlstm.sqhstv[167] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_4);
    sqlstm.sqhstl[167] = (unsigned int  )31;
    sqlstm.sqhsts[167] = (         int  )0;
    sqlstm.sqindv[167] = (         void  *)0;
    sqlstm.sqinds[167] = (         int  )0;
    sqlstm.sqharm[167] = (unsigned int  )0;
    sqlstm.sqadto[167] = (unsigned short )0;
    sqlstm.sqtdso[167] = (unsigned short )0;
    sqlstm.sqhstv[168] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_5);
    sqlstm.sqhstl[168] = (unsigned int  )31;
    sqlstm.sqhsts[168] = (         int  )0;
    sqlstm.sqindv[168] = (         void  *)0;
    sqlstm.sqinds[168] = (         int  )0;
    sqlstm.sqharm[168] = (unsigned int  )0;
    sqlstm.sqadto[168] = (unsigned short )0;
    sqlstm.sqtdso[168] = (unsigned short )0;
    sqlstm.sqhstv[169] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_1);
    sqlstm.sqhstl[169] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[169] = (         int  )0;
    sqlstm.sqindv[169] = (         void  *)0;
    sqlstm.sqinds[169] = (         int  )0;
    sqlstm.sqharm[169] = (unsigned int  )0;
    sqlstm.sqadto[169] = (unsigned short )0;
    sqlstm.sqtdso[169] = (unsigned short )0;
    sqlstm.sqhstv[170] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_2);
    sqlstm.sqhstl[170] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[170] = (         int  )0;
    sqlstm.sqindv[170] = (         void  *)0;
    sqlstm.sqinds[170] = (         int  )0;
    sqlstm.sqharm[170] = (unsigned int  )0;
    sqlstm.sqadto[170] = (unsigned short )0;
    sqlstm.sqtdso[170] = (unsigned short )0;
    sqlstm.sqhstv[171] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_3);
    sqlstm.sqhstl[171] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[171] = (         int  )0;
    sqlstm.sqindv[171] = (         void  *)0;
    sqlstm.sqinds[171] = (         int  )0;
    sqlstm.sqharm[171] = (unsigned int  )0;
    sqlstm.sqadto[171] = (unsigned short )0;
    sqlstm.sqtdso[171] = (unsigned short )0;
    sqlstm.sqhstv[172] = (         void  *)(MTMPLOTHIS_N.OLD_CRR_ID);
    sqlstm.sqhstl[172] = (unsigned int  )21;
    sqlstm.sqhsts[172] = (         int  )0;
    sqlstm.sqindv[172] = (         void  *)0;
    sqlstm.sqinds[172] = (         int  )0;
    sqlstm.sqharm[172] = (unsigned int  )0;
    sqlstm.sqadto[172] = (unsigned short )0;
    sqlstm.sqtdso[172] = (unsigned short )0;
    sqlstm.sqhstv[173] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_TYPE);
    sqlstm.sqhstl[173] = (unsigned int  )2;
    sqlstm.sqhsts[173] = (         int  )0;
    sqlstm.sqindv[173] = (         void  *)0;
    sqlstm.sqinds[173] = (         int  )0;
    sqlstm.sqharm[173] = (unsigned int  )0;
    sqlstm.sqadto[173] = (unsigned short )0;
    sqlstm.sqtdso[173] = (unsigned short )0;
    sqlstm.sqhstv[174] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_PRIORITY);
    sqlstm.sqhstl[174] = (unsigned int  )2;
    sqlstm.sqhsts[174] = (         int  )0;
    sqlstm.sqindv[174] = (         void  *)0;
    sqlstm.sqinds[174] = (         int  )0;
    sqlstm.sqharm[174] = (unsigned int  )0;
    sqlstm.sqadto[174] = (unsigned short )0;
    sqlstm.sqtdso[174] = (unsigned short )0;
    sqlstm.sqhstv[175] = (         void  *)(MTMPLOTHIS_N.OLD_ORDER_ID);
    sqlstm.sqhstl[175] = (unsigned int  )26;
    sqlstm.sqhsts[175] = (         int  )0;
    sqlstm.sqindv[175] = (         void  *)0;
    sqlstm.sqinds[175] = (         int  )0;
    sqlstm.sqharm[175] = (unsigned int  )0;
    sqlstm.sqadto[175] = (unsigned short )0;
    sqlstm.sqtdso[175] = (unsigned short )0;
    sqlstm.sqhstv[176] = (         void  *)(MTMPLOTHIS_N.OLD_OWNER_CODE);
    sqlstm.sqhstl[176] = (unsigned int  )11;
    sqlstm.sqhsts[176] = (         int  )0;
    sqlstm.sqindv[176] = (         void  *)0;
    sqlstm.sqinds[176] = (         int  )0;
    sqlstm.sqharm[176] = (unsigned int  )0;
    sqlstm.sqadto[176] = (unsigned short )0;
    sqlstm.sqtdso[176] = (unsigned short )0;
    sqlstm.sqhstv[177] = (         void  *)(MTMPLOTHIS_N.OLD_CREATE_CODE);
    sqlstm.sqhstl[177] = (unsigned int  )11;
    sqlstm.sqhsts[177] = (         int  )0;
    sqlstm.sqindv[177] = (         void  *)0;
    sqlstm.sqinds[177] = (         int  )0;
    sqlstm.sqharm[177] = (unsigned int  )0;
    sqlstm.sqadto[177] = (unsigned short )0;
    sqlstm.sqtdso[177] = (unsigned short )0;
    sqlstm.sqhstv[178] = (         void  *)(MTMPLOTHIS_N.OLD_FAC_IN_TIME);
    sqlstm.sqhstl[178] = (unsigned int  )15;
    sqlstm.sqhsts[178] = (         int  )0;
    sqlstm.sqindv[178] = (         void  *)0;
    sqlstm.sqinds[178] = (         int  )0;
    sqlstm.sqharm[178] = (unsigned int  )0;
    sqlstm.sqadto[178] = (unsigned short )0;
    sqlstm.sqtdso[178] = (unsigned short )0;
    sqlstm.sqhstv[179] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW_IN_TIME);
    sqlstm.sqhstl[179] = (unsigned int  )15;
    sqlstm.sqhsts[179] = (         int  )0;
    sqlstm.sqindv[179] = (         void  *)0;
    sqlstm.sqinds[179] = (         int  )0;
    sqlstm.sqharm[179] = (unsigned int  )0;
    sqlstm.sqadto[179] = (unsigned short )0;
    sqlstm.sqtdso[179] = (unsigned short )0;
    sqlstm.sqhstv[180] = (         void  *)(MTMPLOTHIS_N.OLD_OPER_IN_TIME);
    sqlstm.sqhstl[180] = (unsigned int  )15;
    sqlstm.sqhsts[180] = (         int  )0;
    sqlstm.sqindv[180] = (         void  *)0;
    sqlstm.sqinds[180] = (         int  )0;
    sqlstm.sqharm[180] = (unsigned int  )0;
    sqlstm.sqadto[180] = (unsigned short )0;
    sqlstm.sqtdso[180] = (unsigned short )0;
    sqlstm.sqhstv[181] = (         void  *)(MTMPLOTHIS_N.OLD_RWK_FLAG);
    sqlstm.sqhstl[181] = (unsigned int  )2;
    sqlstm.sqhsts[181] = (         int  )0;
    sqlstm.sqindv[181] = (         void  *)0;
    sqlstm.sqinds[181] = (         int  )0;
    sqlstm.sqharm[181] = (unsigned int  )0;
    sqlstm.sqadto[181] = (unsigned short )0;
    sqlstm.sqtdso[181] = (unsigned short )0;
    sqlstm.sqhstv[182] = (         void  *)(MTMPLOTHIS_N.OLD_START_FLAG);
    sqlstm.sqhstl[182] = (unsigned int  )2;
    sqlstm.sqhsts[182] = (         int  )0;
    sqlstm.sqindv[182] = (         void  *)0;
    sqlstm.sqinds[182] = (         int  )0;
    sqlstm.sqharm[182] = (unsigned int  )0;
    sqlstm.sqadto[182] = (unsigned short )0;
    sqlstm.sqtdso[182] = (unsigned short )0;
    sqlstm.sqhstv[183] = (         void  *)(MTMPLOTHIS_N.OLD_START_TIME);
    sqlstm.sqhstl[183] = (unsigned int  )15;
    sqlstm.sqhsts[183] = (         int  )0;
    sqlstm.sqindv[183] = (         void  *)0;
    sqlstm.sqinds[183] = (         int  )0;
    sqlstm.sqharm[183] = (unsigned int  )0;
    sqlstm.sqadto[183] = (unsigned short )0;
    sqlstm.sqtdso[183] = (unsigned short )0;
    sqlstm.sqhstv[184] = (         void  *)(MTMPLOTHIS_N.OLD_START_RES_ID);
    sqlstm.sqhstl[184] = (unsigned int  )21;
    sqlstm.sqhsts[184] = (         int  )0;
    sqlstm.sqindv[184] = (         void  *)0;
    sqlstm.sqinds[184] = (         int  )0;
    sqlstm.sqharm[184] = (unsigned int  )0;
    sqlstm.sqadto[184] = (unsigned short )0;
    sqlstm.sqtdso[184] = (unsigned short )0;
    sqlstm.sqhstv[185] = (         void  *)(MTMPLOTHIS_N.OLD_END_FLAG);
    sqlstm.sqhstl[185] = (unsigned int  )2;
    sqlstm.sqhsts[185] = (         int  )0;
    sqlstm.sqindv[185] = (         void  *)0;
    sqlstm.sqinds[185] = (         int  )0;
    sqlstm.sqharm[185] = (unsigned int  )0;
    sqlstm.sqadto[185] = (unsigned short )0;
    sqlstm.sqtdso[185] = (unsigned short )0;
    sqlstm.sqhstv[186] = (         void  *)(MTMPLOTHIS_N.OLD_END_TIME);
    sqlstm.sqhstl[186] = (unsigned int  )15;
    sqlstm.sqhsts[186] = (         int  )0;
    sqlstm.sqindv[186] = (         void  *)0;
    sqlstm.sqinds[186] = (         int  )0;
    sqlstm.sqharm[186] = (unsigned int  )0;
    sqlstm.sqadto[186] = (unsigned short )0;
    sqlstm.sqtdso[186] = (unsigned short )0;
    sqlstm.sqhstv[187] = (         void  *)(MTMPLOTHIS_N.OLD_END_RES_ID);
    sqlstm.sqhstl[187] = (unsigned int  )21;
    sqlstm.sqhsts[187] = (         int  )0;
    sqlstm.sqindv[187] = (         void  *)0;
    sqlstm.sqinds[187] = (         int  )0;
    sqlstm.sqharm[187] = (unsigned int  )0;
    sqlstm.sqadto[187] = (unsigned short )0;
    sqlstm.sqtdso[187] = (unsigned short )0;
    sqlstm.sqhstv[188] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_1);
    sqlstm.sqhstl[188] = (unsigned int  )31;
    sqlstm.sqhsts[188] = (         int  )0;
    sqlstm.sqindv[188] = (         void  *)0;
    sqlstm.sqinds[188] = (         int  )0;
    sqlstm.sqharm[188] = (unsigned int  )0;
    sqlstm.sqadto[188] = (unsigned short )0;
    sqlstm.sqtdso[188] = (unsigned short )0;
    sqlstm.sqhstv[189] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_2);
    sqlstm.sqhstl[189] = (unsigned int  )31;
    sqlstm.sqhsts[189] = (         int  )0;
    sqlstm.sqindv[189] = (         void  *)0;
    sqlstm.sqinds[189] = (         int  )0;
    sqlstm.sqharm[189] = (unsigned int  )0;
    sqlstm.sqadto[189] = (unsigned short )0;
    sqlstm.sqtdso[189] = (unsigned short )0;
    sqlstm.sqhstv[190] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_3);
    sqlstm.sqhstl[190] = (unsigned int  )31;
    sqlstm.sqhsts[190] = (         int  )0;
    sqlstm.sqindv[190] = (         void  *)0;
    sqlstm.sqinds[190] = (         int  )0;
    sqlstm.sqharm[190] = (unsigned int  )0;
    sqlstm.sqadto[190] = (unsigned short )0;
    sqlstm.sqtdso[190] = (unsigned short )0;
    sqlstm.sqhstv[191] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_4);
    sqlstm.sqhstl[191] = (unsigned int  )31;
    sqlstm.sqhsts[191] = (         int  )0;
    sqlstm.sqindv[191] = (         void  *)0;
    sqlstm.sqinds[191] = (         int  )0;
    sqlstm.sqharm[191] = (unsigned int  )0;
    sqlstm.sqadto[191] = (unsigned short )0;
    sqlstm.sqtdso[191] = (unsigned short )0;
    sqlstm.sqhstv[192] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_5);
    sqlstm.sqhstl[192] = (unsigned int  )31;
    sqlstm.sqhsts[192] = (         int  )0;
    sqlstm.sqindv[192] = (         void  *)0;
    sqlstm.sqinds[192] = (         int  )0;
    sqlstm.sqharm[192] = (unsigned int  )0;
    sqlstm.sqadto[192] = (unsigned short )0;
    sqlstm.sqtdso[192] = (unsigned short )0;
    sqlstm.sqhstv[193] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_6);
    sqlstm.sqhstl[193] = (unsigned int  )31;
    sqlstm.sqhsts[193] = (         int  )0;
    sqlstm.sqindv[193] = (         void  *)0;
    sqlstm.sqinds[193] = (         int  )0;
    sqlstm.sqharm[193] = (unsigned int  )0;
    sqlstm.sqadto[193] = (unsigned short )0;
    sqlstm.sqtdso[193] = (unsigned short )0;
    sqlstm.sqhstv[194] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_7);
    sqlstm.sqhstl[194] = (unsigned int  )31;
    sqlstm.sqhsts[194] = (         int  )0;
    sqlstm.sqindv[194] = (         void  *)0;
    sqlstm.sqinds[194] = (         int  )0;
    sqlstm.sqharm[194] = (unsigned int  )0;
    sqlstm.sqadto[194] = (unsigned short )0;
    sqlstm.sqtdso[194] = (unsigned short )0;
    sqlstm.sqhstv[195] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_8);
    sqlstm.sqhstl[195] = (unsigned int  )31;
    sqlstm.sqhsts[195] = (         int  )0;
    sqlstm.sqindv[195] = (         void  *)0;
    sqlstm.sqinds[195] = (         int  )0;
    sqlstm.sqharm[195] = (unsigned int  )0;
    sqlstm.sqadto[195] = (unsigned short )0;
    sqlstm.sqtdso[195] = (unsigned short )0;
    sqlstm.sqhstv[196] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_9);
    sqlstm.sqhstl[196] = (unsigned int  )31;
    sqlstm.sqhsts[196] = (         int  )0;
    sqlstm.sqindv[196] = (         void  *)0;
    sqlstm.sqinds[196] = (         int  )0;
    sqlstm.sqharm[196] = (unsigned int  )0;
    sqlstm.sqadto[196] = (unsigned short )0;
    sqlstm.sqtdso[196] = (unsigned short )0;
    sqlstm.sqhstv[197] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_10);
    sqlstm.sqhstl[197] = (unsigned int  )31;
    sqlstm.sqhsts[197] = (         int  )0;
    sqlstm.sqindv[197] = (         void  *)0;
    sqlstm.sqinds[197] = (         int  )0;
    sqlstm.sqharm[197] = (unsigned int  )0;
    sqlstm.sqadto[197] = (unsigned short )0;
    sqlstm.sqtdso[197] = (unsigned short )0;
    sqlstm.sqhstv[198] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_11);
    sqlstm.sqhstl[198] = (unsigned int  )31;
    sqlstm.sqhsts[198] = (         int  )0;
    sqlstm.sqindv[198] = (         void  *)0;
    sqlstm.sqinds[198] = (         int  )0;
    sqlstm.sqharm[198] = (unsigned int  )0;
    sqlstm.sqadto[198] = (unsigned short )0;
    sqlstm.sqtdso[198] = (unsigned short )0;
    sqlstm.sqhstv[199] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_12);
    sqlstm.sqhstl[199] = (unsigned int  )31;
    sqlstm.sqhsts[199] = (         int  )0;
    sqlstm.sqindv[199] = (         void  *)0;
    sqlstm.sqinds[199] = (         int  )0;
    sqlstm.sqharm[199] = (unsigned int  )0;
    sqlstm.sqadto[199] = (unsigned short )0;
    sqlstm.sqtdso[199] = (unsigned short )0;
    sqlstm.sqhstv[200] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_13);
    sqlstm.sqhstl[200] = (unsigned int  )31;
    sqlstm.sqhsts[200] = (         int  )0;
    sqlstm.sqindv[200] = (         void  *)0;
    sqlstm.sqinds[200] = (         int  )0;
    sqlstm.sqharm[200] = (unsigned int  )0;
    sqlstm.sqadto[200] = (unsigned short )0;
    sqlstm.sqtdso[200] = (unsigned short )0;
    sqlstm.sqhstv[201] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_14);
    sqlstm.sqhstl[201] = (unsigned int  )31;
    sqlstm.sqhsts[201] = (         int  )0;
    sqlstm.sqindv[201] = (         void  *)0;
    sqlstm.sqinds[201] = (         int  )0;
    sqlstm.sqharm[201] = (unsigned int  )0;
    sqlstm.sqadto[201] = (unsigned short )0;
    sqlstm.sqtdso[201] = (unsigned short )0;
    sqlstm.sqhstv[202] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_15);
    sqlstm.sqhstl[202] = (unsigned int  )31;
    sqlstm.sqhsts[202] = (         int  )0;
    sqlstm.sqindv[202] = (         void  *)0;
    sqlstm.sqinds[202] = (         int  )0;
    sqlstm.sqharm[202] = (unsigned int  )0;
    sqlstm.sqadto[202] = (unsigned short )0;
    sqlstm.sqtdso[202] = (unsigned short )0;
    sqlstm.sqhstv[203] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_16);
    sqlstm.sqhstl[203] = (unsigned int  )31;
    sqlstm.sqhsts[203] = (         int  )0;
    sqlstm.sqindv[203] = (         void  *)0;
    sqlstm.sqinds[203] = (         int  )0;
    sqlstm.sqharm[203] = (unsigned int  )0;
    sqlstm.sqadto[203] = (unsigned short )0;
    sqlstm.sqtdso[203] = (unsigned short )0;
    sqlstm.sqhstv[204] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_17);
    sqlstm.sqhstl[204] = (unsigned int  )31;
    sqlstm.sqhsts[204] = (         int  )0;
    sqlstm.sqindv[204] = (         void  *)0;
    sqlstm.sqinds[204] = (         int  )0;
    sqlstm.sqharm[204] = (unsigned int  )0;
    sqlstm.sqadto[204] = (unsigned short )0;
    sqlstm.sqtdso[204] = (unsigned short )0;
    sqlstm.sqhstv[205] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_18);
    sqlstm.sqhstl[205] = (unsigned int  )31;
    sqlstm.sqhsts[205] = (         int  )0;
    sqlstm.sqindv[205] = (         void  *)0;
    sqlstm.sqinds[205] = (         int  )0;
    sqlstm.sqharm[205] = (unsigned int  )0;
    sqlstm.sqadto[205] = (unsigned short )0;
    sqlstm.sqtdso[205] = (unsigned short )0;
    sqlstm.sqhstv[206] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_19);
    sqlstm.sqhstl[206] = (unsigned int  )31;
    sqlstm.sqhsts[206] = (         int  )0;
    sqlstm.sqindv[206] = (         void  *)0;
    sqlstm.sqinds[206] = (         int  )0;
    sqlstm.sqharm[206] = (unsigned int  )0;
    sqlstm.sqadto[206] = (unsigned short )0;
    sqlstm.sqtdso[206] = (unsigned short )0;
    sqlstm.sqhstv[207] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_20);
    sqlstm.sqhstl[207] = (unsigned int  )31;
    sqlstm.sqhsts[207] = (         int  )0;
    sqlstm.sqindv[207] = (         void  *)0;
    sqlstm.sqinds[207] = (         int  )0;
    sqlstm.sqharm[207] = (unsigned int  )0;
    sqlstm.sqadto[207] = (unsigned short )0;
    sqlstm.sqtdso[207] = (unsigned short )0;
    sqlstm.sqhstv[208] = (         void  *)(MTMPLOTHIS_N.TRAN_USER_ID);
    sqlstm.sqhstl[208] = (unsigned int  )21;
    sqlstm.sqhsts[208] = (         int  )0;
    sqlstm.sqindv[208] = (         void  *)0;
    sqlstm.sqinds[208] = (         int  )0;
    sqlstm.sqharm[208] = (unsigned int  )0;
    sqlstm.sqadto[208] = (unsigned short )0;
    sqlstm.sqtdso[208] = (unsigned short )0;
    sqlstm.sqhstv[209] = (         void  *)(MTMPLOTHIS_N.TRAN_COMMENT);
    sqlstm.sqhstl[209] = (unsigned int  )401;
    sqlstm.sqhsts[209] = (         int  )0;
    sqlstm.sqindv[209] = (         void  *)0;
    sqlstm.sqinds[209] = (         int  )0;
    sqlstm.sqharm[209] = (unsigned int  )0;
    sqlstm.sqadto[209] = (unsigned short )0;
    sqlstm.sqtdso[209] = (unsigned short )0;
    sqlstm.sqhstv[210] = (         void  *)&(MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ);
    sqlstm.sqhstl[210] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[210] = (         int  )0;
    sqlstm.sqindv[210] = (         void  *)0;
    sqlstm.sqinds[210] = (         int  )0;
    sqlstm.sqharm[210] = (unsigned int  )0;
    sqlstm.sqadto[210] = (unsigned short )0;
    sqlstm.sqtdso[210] = (unsigned short )0;
    sqlstm.sqhstv[211] = (         void  *)(MTMPLOTHIS_N.MULTI_TR_KEY);
    sqlstm.sqhstl[211] = (unsigned int  )31;
    sqlstm.sqhsts[211] = (         int  )0;
    sqlstm.sqindv[211] = (         void  *)0;
    sqlstm.sqinds[211] = (         int  )0;
    sqlstm.sqharm[211] = (unsigned int  )0;
    sqlstm.sqadto[211] = (unsigned short )0;
    sqlstm.sqtdso[211] = (unsigned short )0;
    sqlstm.sqhstv[212] = (         void  *)&(MTMPLOTHIS_N.MULTI_TR_SEQ);
    sqlstm.sqhstl[212] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[212] = (         int  )0;
    sqlstm.sqindv[212] = (         void  *)0;
    sqlstm.sqinds[212] = (         int  )0;
    sqlstm.sqharm[212] = (unsigned int  )0;
    sqlstm.sqadto[212] = (unsigned short )0;
    sqlstm.sqtdso[212] = (unsigned short )0;
    sqlstm.sqhstv[213] = (         void  *)&(MTMPLOTHIS_N.EXT_HIST_SEQ);
    sqlstm.sqhstl[213] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[213] = (         int  )0;
    sqlstm.sqindv[213] = (         void  *)0;
    sqlstm.sqinds[213] = (         int  )0;
    sqlstm.sqharm[213] = (unsigned int  )0;
    sqlstm.sqadto[213] = (unsigned short )0;
    sqlstm.sqtdso[213] = (unsigned short )0;
    sqlstm.sqhstv[214] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[214] = (unsigned int  )2;
    sqlstm.sqhsts[214] = (         int  )0;
    sqlstm.sqindv[214] = (         void  *)0;
    sqlstm.sqinds[214] = (         int  )0;
    sqlstm.sqharm[214] = (unsigned int  )0;
    sqlstm.sqadto[214] = (unsigned short )0;
    sqlstm.sqtdso[214] = (unsigned short )0;
    sqlstm.sqhstv[215] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_TIME);
    sqlstm.sqhstl[215] = (unsigned int  )15;
    sqlstm.sqhsts[215] = (         int  )0;
    sqlstm.sqindv[215] = (         void  *)0;
    sqlstm.sqinds[215] = (         int  )0;
    sqlstm.sqharm[215] = (unsigned int  )0;
    sqlstm.sqadto[215] = (unsigned short )0;
    sqlstm.sqtdso[215] = (unsigned short )0;
    sqlstm.sqhstv[216] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_USER_ID);
    sqlstm.sqhstl[216] = (unsigned int  )21;
    sqlstm.sqhsts[216] = (         int  )0;
    sqlstm.sqindv[216] = (         void  *)0;
    sqlstm.sqinds[216] = (         int  )0;
    sqlstm.sqharm[216] = (unsigned int  )0;
    sqlstm.sqadto[216] = (unsigned short )0;
    sqlstm.sqtdso[216] = (unsigned short )0;
    sqlstm.sqhstv[217] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_COMMENT);
    sqlstm.sqhstl[217] = (unsigned int  )401;
    sqlstm.sqhsts[217] = (         int  )0;
    sqlstm.sqindv[217] = (         void  *)0;
    sqlstm.sqinds[217] = (         int  )0;
    sqlstm.sqharm[217] = (unsigned int  )0;
    sqlstm.sqadto[217] = (unsigned short )0;
    sqlstm.sqtdso[217] = (unsigned short )0;
    sqlstm.sqhstv[218] = (         void  *)(MTMPLOTHIS_N.PROCESS_FLAG);
    sqlstm.sqhstl[218] = (unsigned int  )2;
    sqlstm.sqhsts[218] = (         int  )0;
    sqlstm.sqindv[218] = (         void  *)0;
    sqlstm.sqinds[218] = (         int  )0;
    sqlstm.sqharm[218] = (unsigned int  )0;
    sqlstm.sqadto[218] = (unsigned short )0;
    sqlstm.sqtdso[218] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mtmplothis", 0);
}


/* SQL UPDATE Function */
void DBC_update_mtmplothis(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MTMPLOTHIS SET
                    CM_KEY_1 = :MTMPLOTHIS_N.CM_KEY_1,
                    CM_KEY_2 = :MTMPLOTHIS_N.CM_KEY_2,
                    CM_KEY_3 = :MTMPLOTHIS_N.CM_KEY_3,
                    CM_KEY_4 = :MTMPLOTHIS_N.CM_KEY_4,
                    CM_KEY_5 = :MTMPLOTHIS_N.CM_KEY_5,
                    LOT_ID = :MTMPLOTHIS_N.LOT_ID,
                    SUB_LOT_ID = :MTMPLOTHIS_N.SUB_LOT_ID,
                    SUB_LOT_FLAG = :MTMPLOTHIS_N.SUB_LOT_FLAG,
                    HIST_SEQ = :MTMPLOTHIS_N.HIST_SEQ,
                    TRAN_TIME = :MTMPLOTHIS_N.TRAN_TIME,
                    SYS_TRAN_TIME = :MTMPLOTHIS_N.SYS_TRAN_TIME,
                    TRAN_CODE = :MTMPLOTHIS_N.TRAN_CODE,
                    LOT_DESC = :MTMPLOTHIS_N.LOT_DESC,
                    FACTORY = :MTMPLOTHIS_N.FACTORY,
                    MAT_ID = :MTMPLOTHIS_N.MAT_ID,
                    MAT_VER = :MTMPLOTHIS_N.MAT_VER,
                    FLOW = :MTMPLOTHIS_N.FLOW,
                    FLOW_SEQ_NUM = :MTMPLOTHIS_N.FLOW_SEQ_NUM,
                    OPER = :MTMPLOTHIS_N.OPER,
                    QTY_1 = :MTMPLOTHIS_N.QTY_1,
                    QTY_2 = :MTMPLOTHIS_N.QTY_2,
                    QTY_3 = :MTMPLOTHIS_N.QTY_3,
                    CRR_ID = :MTMPLOTHIS_N.CRR_ID,
                    LOT_TYPE = :MTMPLOTHIS_N.LOT_TYPE,
                    OWNER_CODE = :MTMPLOTHIS_N.OWNER_CODE,
                    CREATE_CODE = :MTMPLOTHIS_N.CREATE_CODE,
                    LOT_PRIORITY = :MTMPLOTHIS_N.LOT_PRIORITY,
                    LOT_STATUS = :MTMPLOTHIS_N.LOT_STATUS,
                    HOLD_FLAG = :MTMPLOTHIS_N.HOLD_FLAG,
                    HOLD_CODE = :MTMPLOTHIS_N.HOLD_CODE,
                    HOLD_PASSWORD = :MTMPLOTHIS_N.HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID = :MTMPLOTHIS_N.HOLD_PRV_GRP_ID,
                    OPER_IN_QTY_1 = :MTMPLOTHIS_N.OPER_IN_QTY_1,
                    OPER_IN_QTY_2 = :MTMPLOTHIS_N.OPER_IN_QTY_2,
                    OPER_IN_QTY_3 = :MTMPLOTHIS_N.OPER_IN_QTY_3,
                    CREATE_QTY_1 = :MTMPLOTHIS_N.CREATE_QTY_1,
                    CREATE_QTY_2 = :MTMPLOTHIS_N.CREATE_QTY_2,
                    CREATE_QTY_3 = :MTMPLOTHIS_N.CREATE_QTY_3,
                    START_QTY_1 = :MTMPLOTHIS_N.START_QTY_1,
                    START_QTY_2 = :MTMPLOTHIS_N.START_QTY_2,
                    START_QTY_3 = :MTMPLOTHIS_N.START_QTY_3,
                    INV_FLAG = :MTMPLOTHIS_N.INV_FLAG,
                    TRANSIT_FLAG = :MTMPLOTHIS_N.TRANSIT_FLAG,
                    UNIT_EXIST_FLAG = :MTMPLOTHIS_N.UNIT_EXIST_FLAG,
                    INV_UNIT = :MTMPLOTHIS_N.INV_UNIT,
                    RWK_FLAG = :MTMPLOTHIS_N.RWK_FLAG,
                    RWK_CODE = :MTMPLOTHIS_N.RWK_CODE,
                    RWK_COUNT = :MTMPLOTHIS_N.RWK_COUNT,
                    RWK_RET_FLOW = :MTMPLOTHIS_N.RWK_RET_FLOW,
                    RWK_RET_FLOW_SEQ_NUM = :MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM,
                    RWK_RET_OPER = :MTMPLOTHIS_N.RWK_RET_OPER,
                    RWK_END_FLOW = :MTMPLOTHIS_N.RWK_END_FLOW,
                    RWK_END_FLOW_SEQ_NUM = :MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM,
                    RWK_END_OPER = :MTMPLOTHIS_N.RWK_END_OPER,
                    RWK_RET_CLEAR_FLAG = :MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG,
                    RWK_TIME = :MTMPLOTHIS_N.RWK_TIME,
                    NSTD_FLAG = :MTMPLOTHIS_N.NSTD_FLAG,
                    NSTD_RET_FLOW = :MTMPLOTHIS_N.NSTD_RET_FLOW,
                    NSTD_RET_FLOW_SEQ_NUM = :MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM,
                    NSTD_RET_OPER = :MTMPLOTHIS_N.NSTD_RET_OPER,
                    NSTD_TIME = :MTMPLOTHIS_N.NSTD_TIME,
                    REP_FLAG = :MTMPLOTHIS_N.REP_FLAG,
                    REP_RET_OPER = :MTMPLOTHIS_N.REP_RET_OPER,
                    STR_RET_FLOW = :MTMPLOTHIS_N.STR_RET_FLOW,
                    STR_RET_FLOW_SEQ_NUM = :MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM,
                    STR_RET_OPER = :MTMPLOTHIS_N.STR_RET_OPER,
                    START_FLAG = :MTMPLOTHIS_N.START_FLAG,
                    START_TIME = :MTMPLOTHIS_N.START_TIME,
                    START_RES_ID = :MTMPLOTHIS_N.START_RES_ID,
                    END_FLAG = :MTMPLOTHIS_N.END_FLAG,
                    END_TIME = :MTMPLOTHIS_N.END_TIME,
                    END_RES_ID = :MTMPLOTHIS_N.END_RES_ID,
                    SAMPLE_FLAG = :MTMPLOTHIS_N.SAMPLE_FLAG,
                    SAMPLE_WAIT_FLAG = :MTMPLOTHIS_N.SAMPLE_WAIT_FLAG,
                    SAMPLE_RESULT = :MTMPLOTHIS_N.SAMPLE_RESULT,
                    FROM_TO_FLAG = :MTMPLOTHIS_N.FROM_TO_FLAG,
                    FROM_TO_LOT_ID = :MTMPLOTHIS_N.FROM_TO_LOT_ID,
                    SHIP_CODE = :MTMPLOTHIS_N.SHIP_CODE,
                    SHIP_TIME = :MTMPLOTHIS_N.SHIP_TIME,
                    ORG_DUE_TIME = :MTMPLOTHIS_N.ORG_DUE_TIME,
                    SCH_DUE_TIME = :MTMPLOTHIS_N.SCH_DUE_TIME,
                    CREATE_TIME = :MTMPLOTHIS_N.CREATE_TIME,
                    FAC_IN_TIME = :MTMPLOTHIS_N.FAC_IN_TIME,
                    FLOW_IN_TIME = :MTMPLOTHIS_N.FLOW_IN_TIME,
                    OPER_IN_TIME = :MTMPLOTHIS_N.OPER_IN_TIME,
                    RESERVE_RES_ID = :MTMPLOTHIS_N.RESERVE_RES_ID,
                    PORT_ID = :MTMPLOTHIS_N.PORT_ID,
                    BATCH_ID = :MTMPLOTHIS_N.BATCH_ID,
                    BATCH_SEQ = :MTMPLOTHIS_N.BATCH_SEQ,
                    ORDER_ID = :MTMPLOTHIS_N.ORDER_ID,
                    ADD_ORDER_ID_1 = :MTMPLOTHIS_N.ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2 = :MTMPLOTHIS_N.ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3 = :MTMPLOTHIS_N.ADD_ORDER_ID_3,
                    LOT_LOCATION_1 = :MTMPLOTHIS_N.LOT_LOCATION_1,
                    LOT_LOCATION_2 = :MTMPLOTHIS_N.LOT_LOCATION_2,
                    LOT_LOCATION_3 = :MTMPLOTHIS_N.LOT_LOCATION_3,
                    LOT_CMF_1 = :MTMPLOTHIS_N.LOT_CMF_1,
                    LOT_CMF_2 = :MTMPLOTHIS_N.LOT_CMF_2,
                    LOT_CMF_3 = :MTMPLOTHIS_N.LOT_CMF_3,
                    LOT_CMF_4 = :MTMPLOTHIS_N.LOT_CMF_4,
                    LOT_CMF_5 = :MTMPLOTHIS_N.LOT_CMF_5,
                    LOT_CMF_6 = :MTMPLOTHIS_N.LOT_CMF_6,
                    LOT_CMF_7 = :MTMPLOTHIS_N.LOT_CMF_7,
                    LOT_CMF_8 = :MTMPLOTHIS_N.LOT_CMF_8,
                    LOT_CMF_9 = :MTMPLOTHIS_N.LOT_CMF_9,
                    LOT_CMF_10 = :MTMPLOTHIS_N.LOT_CMF_10,
                    LOT_CMF_11 = :MTMPLOTHIS_N.LOT_CMF_11,
                    LOT_CMF_12 = :MTMPLOTHIS_N.LOT_CMF_12,
                    LOT_CMF_13 = :MTMPLOTHIS_N.LOT_CMF_13,
                    LOT_CMF_14 = :MTMPLOTHIS_N.LOT_CMF_14,
                    LOT_CMF_15 = :MTMPLOTHIS_N.LOT_CMF_15,
                    LOT_CMF_16 = :MTMPLOTHIS_N.LOT_CMF_16,
                    LOT_CMF_17 = :MTMPLOTHIS_N.LOT_CMF_17,
                    LOT_CMF_18 = :MTMPLOTHIS_N.LOT_CMF_18,
                    LOT_CMF_19 = :MTMPLOTHIS_N.LOT_CMF_19,
                    LOT_CMF_20 = :MTMPLOTHIS_N.LOT_CMF_20,
                    LOT_DEL_FLAG = :MTMPLOTHIS_N.LOT_DEL_FLAG,
                    LOT_DEL_CODE = :MTMPLOTHIS_N.LOT_DEL_CODE,
                    LOT_DEL_TIME = :MTMPLOTHIS_N.LOT_DEL_TIME,
                    BOM_SET_ID = :MTMPLOTHIS_N.BOM_SET_ID,
                    BOM_SET_VERSION = :MTMPLOTHIS_N.BOM_SET_VERSION,
                    BOM_ACTIVE_HIST_SEQ = :MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ,
                    BOM_HIST_SEQ = :MTMPLOTHIS_N.BOM_HIST_SEQ,
                    CRITICAL_RES_ID = :MTMPLOTHIS_N.CRITICAL_RES_ID,
                    CRITICAL_RES_GROUP_ID = :MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID,
                    SAVE_RES_ID_1 = :MTMPLOTHIS_N.SAVE_RES_ID_1,
                    SAVE_RES_ID_2 = :MTMPLOTHIS_N.SAVE_RES_ID_2,
                    SUBRES_ID = :MTMPLOTHIS_N.SUBRES_ID,
                    LOT_GROUP_ID_1 = :MTMPLOTHIS_N.LOT_GROUP_ID_1,
                    LOT_GROUP_ID_2 = :MTMPLOTHIS_N.LOT_GROUP_ID_2,
                    LOT_GROUP_ID_3 = :MTMPLOTHIS_N.LOT_GROUP_ID_3,
                    YIELD_1 = :MTMPLOTHIS_N.YIELD_1,
                    YIELD_2 = :MTMPLOTHIS_N.YIELD_2,
                    YIELD_3 = :MTMPLOTHIS_N.YIELD_3,
                    GOOD_QTY = :MTMPLOTHIS_N.GOOD_QTY,
                    RESV_FIELD_1 = :MTMPLOTHIS_N.RESV_FIELD_1,
                    RESV_FIELD_2 = :MTMPLOTHIS_N.RESV_FIELD_2,
                    RESV_FIELD_3 = :MTMPLOTHIS_N.RESV_FIELD_3,
                    RESV_FIELD_4 = :MTMPLOTHIS_N.RESV_FIELD_4,
                    RESV_FIELD_5 = :MTMPLOTHIS_N.RESV_FIELD_5,
                    RESV_FLAG_1 = :MTMPLOTHIS_N.RESV_FLAG_1,
                    RESV_FLAG_2 = :MTMPLOTHIS_N.RESV_FLAG_2,
                    RESV_FLAG_3 = :MTMPLOTHIS_N.RESV_FLAG_3,
                    RESV_FLAG_4 = :MTMPLOTHIS_N.RESV_FLAG_4,
                    RESV_FLAG_5 = :MTMPLOTHIS_N.RESV_FLAG_5,
                    FROM_TO_MAT_ID = :MTMPLOTHIS_N.FROM_TO_MAT_ID,
                    FROM_TO_MAT_VER = :MTMPLOTHIS_N.FROM_TO_MAT_VER,
                    FROM_TO_FLOW = :MTMPLOTHIS_N.FROM_TO_FLOW,
                    FROM_TO_FLOW_SEQ_NUM = :MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM,
                    FROM_TO_OPER = :MTMPLOTHIS_N.FROM_TO_OPER,
                    FROM_TO_QTY_1 = :MTMPLOTHIS_N.FROM_TO_QTY_1,
                    FROM_TO_QTY_2 = :MTMPLOTHIS_N.FROM_TO_QTY_2,
                    FROM_TO_QTY_3 = :MTMPLOTHIS_N.FROM_TO_QTY_3,
                    FROM_TO_HIST_SEQ = :MTMPLOTHIS_N.FROM_TO_HIST_SEQ,
                    OLD_TRAN_TIME = :MTMPLOTHIS_N.OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME = :MTMPLOTHIS_N.OLD_SYS_TRAN_TIME,
                    OLD_TRAN_CODE = :MTMPLOTHIS_N.OLD_TRAN_CODE,
                    OLD_FACTORY = :MTMPLOTHIS_N.OLD_FACTORY,
                    OLD_MAT_ID = :MTMPLOTHIS_N.OLD_MAT_ID,
                    OLD_MAT_VER = :MTMPLOTHIS_N.OLD_MAT_VER,
                    OLD_FLOW = :MTMPLOTHIS_N.OLD_FLOW,
                    OLD_FLOW_SEQ_NUM = :MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM,
                    OLD_OPER = :MTMPLOTHIS_N.OLD_OPER,
                    OLD_CM_KEY_1 = :MTMPLOTHIS_N.OLD_CM_KEY_1,
                    OLD_CM_KEY_2 = :MTMPLOTHIS_N.OLD_CM_KEY_2,
                    OLD_CM_KEY_3 = :MTMPLOTHIS_N.OLD_CM_KEY_3,
                    OLD_CM_KEY_4 = :MTMPLOTHIS_N.OLD_CM_KEY_4,
                    OLD_CM_KEY_5 = :MTMPLOTHIS_N.OLD_CM_KEY_5,
                    OLD_QTY_1 = :MTMPLOTHIS_N.OLD_QTY_1,
                    OLD_QTY_2 = :MTMPLOTHIS_N.OLD_QTY_2,
                    OLD_QTY_3 = :MTMPLOTHIS_N.OLD_QTY_3,
                    OLD_CRR_ID = :MTMPLOTHIS_N.OLD_CRR_ID,
                    OLD_LOT_TYPE = :MTMPLOTHIS_N.OLD_LOT_TYPE,
                    OLD_LOT_PRIORITY = :MTMPLOTHIS_N.OLD_LOT_PRIORITY,
                    OLD_ORDER_ID = :MTMPLOTHIS_N.OLD_ORDER_ID,
                    OLD_OWNER_CODE = :MTMPLOTHIS_N.OLD_OWNER_CODE,
                    OLD_CREATE_CODE = :MTMPLOTHIS_N.OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME = :MTMPLOTHIS_N.OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME = :MTMPLOTHIS_N.OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME = :MTMPLOTHIS_N.OLD_OPER_IN_TIME,
                    OLD_RWK_FLAG = :MTMPLOTHIS_N.OLD_RWK_FLAG,
                    OLD_START_FLAG = :MTMPLOTHIS_N.OLD_START_FLAG,
                    OLD_START_TIME = :MTMPLOTHIS_N.OLD_START_TIME,
                    OLD_START_RES_ID = :MTMPLOTHIS_N.OLD_START_RES_ID,
                    OLD_END_FLAG = :MTMPLOTHIS_N.OLD_END_FLAG,
                    OLD_END_TIME = :MTMPLOTHIS_N.OLD_END_TIME,
                    OLD_END_RES_ID = :MTMPLOTHIS_N.OLD_END_RES_ID,
                    TRAN_CMF_1 = :MTMPLOTHIS_N.TRAN_CMF_1,
                    TRAN_CMF_2 = :MTMPLOTHIS_N.TRAN_CMF_2,
                    TRAN_CMF_3 = :MTMPLOTHIS_N.TRAN_CMF_3,
                    TRAN_CMF_4 = :MTMPLOTHIS_N.TRAN_CMF_4,
                    TRAN_CMF_5 = :MTMPLOTHIS_N.TRAN_CMF_5,
                    TRAN_CMF_6 = :MTMPLOTHIS_N.TRAN_CMF_6,
                    TRAN_CMF_7 = :MTMPLOTHIS_N.TRAN_CMF_7,
                    TRAN_CMF_8 = :MTMPLOTHIS_N.TRAN_CMF_8,
                    TRAN_CMF_9 = :MTMPLOTHIS_N.TRAN_CMF_9,
                    TRAN_CMF_10 = :MTMPLOTHIS_N.TRAN_CMF_10,
                    TRAN_CMF_11 = :MTMPLOTHIS_N.TRAN_CMF_11,
                    TRAN_CMF_12 = :MTMPLOTHIS_N.TRAN_CMF_12,
                    TRAN_CMF_13 = :MTMPLOTHIS_N.TRAN_CMF_13,
                    TRAN_CMF_14 = :MTMPLOTHIS_N.TRAN_CMF_14,
                    TRAN_CMF_15 = :MTMPLOTHIS_N.TRAN_CMF_15,
                    TRAN_CMF_16 = :MTMPLOTHIS_N.TRAN_CMF_16,
                    TRAN_CMF_17 = :MTMPLOTHIS_N.TRAN_CMF_17,
                    TRAN_CMF_18 = :MTMPLOTHIS_N.TRAN_CMF_18,
                    TRAN_CMF_19 = :MTMPLOTHIS_N.TRAN_CMF_19,
                    TRAN_CMF_20 = :MTMPLOTHIS_N.TRAN_CMF_20,
                    TRAN_USER_ID = :MTMPLOTHIS_N.TRAN_USER_ID,
                    TRAN_COMMENT = :MTMPLOTHIS_N.TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ = :MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ,
                    MULTI_TR_KEY = :MTMPLOTHIS_N.MULTI_TR_KEY,
                    MULTI_TR_SEQ = :MTMPLOTHIS_N.MULTI_TR_SEQ,
                    EXT_HIST_SEQ = :MTMPLOTHIS_N.EXT_HIST_SEQ,
                    HIST_DEL_FLAG = :MTMPLOTHIS_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MTMPLOTHIS_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MTMPLOTHIS_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MTMPLOTHIS_N.HIST_DEL_COMMENT,
                    PROCESS_FLAG = :MTMPLOTHIS_N.PROCESS_FLAG
                WHERE TABLE_UPDATE_SEQ = :MTMPLOTHIS_N.TABLE_UPDATE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MTMPLOTHIS  set CM_KEY_1=:b0,CM_KEY_2=:b1,CM_KEY_3=:b2\
,CM_KEY_4=:b3,CM_KEY_5=:b4,LOT_ID=:b5,SUB_LOT_ID=:b6,SUB_LOT_FLAG=:b7,HIST_S\
EQ=:b8,TRAN_TIME=:b9,SYS_TRAN_TIME=:b10,TRAN_CODE=:b11,LOT_DESC=:b12,FACTORY\
=:b13,MAT_ID=:b14,MAT_VER=:b15,FLOW=:b16,FLOW_SEQ_NUM=:b17,OPER=:b18,QTY_1=:\
b19,QTY_2=:b20,QTY_3=:b21,CRR_ID=:b22,LOT_TYPE=:b23,OWNER_CODE=:b24,CREATE_C\
ODE=:b25,LOT_PRIORITY=:b26,LOT_STATUS=:b27,HOLD_FLAG=:b28,HOLD_CODE=:b29,HOL\
D_PASSWORD=:b30,HOLD_PRV_GRP_ID=:b31,OPER_IN_QTY_1=:b32,OPER_IN_QTY_2=:b33,O\
PER_IN_QTY_3=:b34,CREATE_QTY_1=:b35,CREATE_QTY_2=:b36,CREATE_QTY_3=:b37,STAR\
T_QTY_1=:b38,START_QTY_2=:b39,START_QTY_3=:b40,INV_FLAG=:b41,TRANSIT_FLAG=:b\
42,UNIT_EXIST_FLAG=:b43,INV_UNIT=:b44,RWK_FLAG=:b45,RWK_CODE=:b46,RWK_COUNT=\
:b47,RWK_RET_FLOW=:b48,RWK_RET_FLOW_SEQ_NUM=:b49,RWK_RET_OPER=:b50,RWK_END_F\
LOW=:b51,RWK_END_FLOW_SEQ_NUM=:b52,RWK_END_OPER=:b53,RWK_RET_CLEAR_FLAG=:b54\
,RWK_TIME=:b55,NSTD_FLAG=:b56,NSTD_RET_FLOW=:b57,NSTD_RET_FLOW_SEQ_NUM=:b58,\
NSTD_RET_OPER=:b59,NSTD_TIME=:b60,REP_FLAG=:b61,REP");
            sqlbuft((void **)0,
              "_RET_OPER=:b62,STR_RET_FLOW=:b63,STR_RET_FLOW_SEQ_NUM=:b64,ST\
R_RET_OPER=:b65,START_FLAG=:b66,START_TIME=:b67,START_RES_ID=:b68,END_FLAG=:\
b69,END_TIME=:b70,END_RES_ID=:b71,SAMPLE_FLAG=:b72,SAMPLE_WAIT_FLAG=:b73,SAM\
PLE_RESULT=:b74,FROM_TO_FLAG=:b75,FROM_TO_LOT_ID=:b76,SHIP_CODE=:b77,SHIP_TI\
ME=:b78,ORG_DUE_TIME=:b79,SCH_DUE_TIME=:b80,CREATE_TIME=:b81,FAC_IN_TIME=:b8\
2,FLOW_IN_TIME=:b83,OPER_IN_TIME=:b84,RESERVE_RES_ID=:b85,PORT_ID=:b86,BATCH\
_ID=:b87,BATCH_SEQ=:b88,ORDER_ID=:b89,ADD_ORDER_ID_1=:b90,ADD_ORDER_ID_2=:b9\
1,ADD_ORDER_ID_3=:b92,LOT_LOCATION_1=:b93,LOT_LOCATION_2=:b94,LOT_LOCATION_3\
=:b95,LOT_CMF_1=:b96,LOT_CMF_2=:b97,LOT_CMF_3=:b98,LOT_CMF_4=:b99,LOT_CMF_5=\
:b100,LOT_CMF_6=:b101,LOT_CMF_7=:b102,LOT_CMF_8=:b103,LOT_CMF_9=:b104,LOT_CM\
F_10=:b105,LOT_CMF_11=:b106,LOT_CMF_12=:b107,LOT_CMF_13=:b108,LOT_CMF_14=:b1\
09,LOT_CMF_15=:b110,LOT_CMF_16=:b111,LOT_CMF_17=:b112,LOT_CMF_18=:b113,LOT_C\
MF_19=:b114,LOT_CMF_20=:b115,LOT_DEL_FLAG=:b116,LOT_DEL_CODE=:b117,LOT_DEL_T\
IME=:b118,BOM_SET_ID=:b119,BOM_SET_VERSION=:b120,BO");
            sqlbuft((void **)0,
              "M_ACTIVE_HIST_SEQ=:b121,BOM_HIST_SEQ=:b122,CRITICAL_RES_ID=:b\
123,CRITICAL_RES_GROUP_ID=:b124,SAVE_RES_ID_1=:b125,SAVE_RES_ID_2=:b126,SUBR\
ES_ID=:b127,LOT_GROUP_ID_1=:b128,LOT_GROUP_ID_2=:b129,LOT_GROUP_ID_3=:b130,Y\
IELD_1=:b131,YIELD_2=:b132,YIELD_3=:b133,GOOD_QTY=:b134,RESV_FIELD_1=:b135,R\
ESV_FIELD_2=:b136,RESV_FIELD_3=:b137,RESV_FIELD_4=:b138,RESV_FIELD_5=:b139,R\
ESV_FLAG_1=:b140,RESV_FLAG_2=:b141,RESV_FLAG_3=:b142,RESV_FLAG_4=:b143,RESV_\
FLAG_5=:b144,FROM_TO_MAT_ID=:b145,FROM_TO_MAT_VER=:b146,FROM_TO_FLOW=:b147,F\
ROM_TO_FLOW_SEQ_NUM=:b148,FROM_TO_OPER=:b149,FROM_TO_QTY_1=:b150,FROM_TO_QTY\
_2=:b151,FROM_TO_QTY_3=:b152,FROM_TO_HIST_SEQ=:b153,OLD_TRAN_TIME=:b154,OLD_\
SYS_TRAN_TIME=:b155,OLD_TRAN_CODE=:b156,OLD_FACTORY=:b157,OLD_MAT_ID=:b158,O\
LD_MAT_VER=:b159,OLD_FLOW=:b160,OLD_FLOW_SEQ_NUM=:b161,OLD_OPER=:b162,OLD_CM\
_KEY_1=:b163,OLD_CM_KEY_2=:b164,OLD_CM_KEY_3=:b165,OLD_CM_KEY_4=:b166,OLD_CM\
_KEY_5=:b167,OLD_QTY_1=:b168,OLD_QTY_2=:b169,OLD_QTY_3=:b170,OLD_CRR_ID=:b17\
1,OLD_LOT_TYPE=:b172,OLD_LOT_PRIORITY=:b173,OLD_ORD");
            sqlstm.stmt = "ER_ID=:b174,OLD_OWNER_CODE=:b175,OLD_CREATE_CODE\
=:b176,OLD_FAC_IN_TIME=:b177,OLD_FLOW_IN_TIME=:b178,OLD_OPER_IN_TIME=:b179,OL\
D_RWK_FLAG=:b180,OLD_START_FLAG=:b181,OLD_START_TIME=:b182,OLD_START_RES_ID=:\
b183,OLD_END_FLAG=:b184,OLD_END_TIME=:b185,OLD_END_RES_ID=:b186,TRAN_CMF_1=:b\
187,TRAN_CMF_2=:b188,TRAN_CMF_3=:b189,TRAN_CMF_4=:b190,TRAN_CMF_5=:b191,TRAN_\
CMF_6=:b192,TRAN_CMF_7=:b193,TRAN_CMF_8=:b194,TRAN_CMF_9=:b195,TRAN_CMF_10=:b\
196,TRAN_CMF_11=:b197,TRAN_CMF_12=:b198,TRAN_CMF_13=:b199,TRAN_CMF_14=:b200,T\
RAN_CMF_15=:b201,TRAN_CMF_16=:b202,TRAN_CMF_17=:b203,TRAN_CMF_18=:b204,TRAN_C\
MF_19=:b205,TRAN_CMF_20=:b206,TRAN_USER_ID=:b207,TRAN_COMMENT=:b208,PREV_ACTI\
VE_HIST_SEQ=:b209,MULTI_TR_KEY=:b210,MULTI_TR_SEQ=:b211,EXT_HIST_SEQ=:b212,HI\
ST_DEL_FLAG=:b213,HIST_DEL_TIME=:b214,HIST_DEL_USER_ID=:b215,HIST_DEL_COMMENT\
=:b216,PROCESS_FLAG=:b217 where TABLE_UPDATE_SEQ=:b218";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2747;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MTMPLOTHIS_N.CM_KEY_1);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPLOTHIS_N.CM_KEY_2);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPLOTHIS_N.CM_KEY_3);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPLOTHIS_N.CM_KEY_4);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPLOTHIS_N.CM_KEY_5);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MTMPLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MTMPLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[11] = (unsigned int  )13;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPLOTHIS_N.LOT_DESC);
            sqlstm.sqhstl[12] = (unsigned int  )201;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPLOTHIS_N.FACTORY);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MTMPLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MTMPLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MTMPLOTHIS_N.FLOW);
            sqlstm.sqhstl[16] = (unsigned int  )21;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MTMPLOTHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MTMPLOTHIS_N.OPER);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MTMPLOTHIS_N.QTY_1);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MTMPLOTHIS_N.QTY_2);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MTMPLOTHIS_N.QTY_3);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MTMPLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[22] = (unsigned int  )21;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPLOTHIS_N.LOT_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPLOTHIS_N.OWNER_CODE);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPLOTHIS_N.CREATE_CODE);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPLOTHIS_N.LOT_PRIORITY);
            sqlstm.sqhstl[26] = (unsigned int  )2;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MTMPLOTHIS_N.LOT_STATUS);
            sqlstm.sqhstl[27] = (unsigned int  )11;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MTMPLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MTMPLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[29] = (unsigned int  )11;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MTMPLOTHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPLOTHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_1);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MTMPLOTHIS_N.START_QTY_1);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(MTMPLOTHIS_N.START_QTY_2);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MTMPLOTHIS_N.START_QTY_3);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MTMPLOTHIS_N.INV_FLAG);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPLOTHIS_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPLOTHIS_N.INV_UNIT);
            sqlstm.sqhstl[44] = (unsigned int  )11;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPLOTHIS_N.RWK_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPLOTHIS_N.RWK_CODE);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MTMPLOTHIS_N.RWK_COUNT);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MTMPLOTHIS_N.RWK_RET_FLOW);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MTMPLOTHIS_N.RWK_RET_OPER);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPLOTHIS_N.RWK_END_FLOW);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MTMPLOTHIS_N.RWK_END_OPER);
            sqlstm.sqhstl[53] = (unsigned int  )11;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPLOTHIS_N.RWK_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPLOTHIS_N.NSTD_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_OPER);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPLOTHIS_N.NSTD_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPLOTHIS_N.REP_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPLOTHIS_N.REP_RET_OPER);
            sqlstm.sqhstl[62] = (unsigned int  )11;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPLOTHIS_N.STR_RET_FLOW);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MTMPLOTHIS_N.STR_RET_OPER);
            sqlstm.sqhstl[65] = (unsigned int  )11;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPLOTHIS_N.START_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPLOTHIS_N.START_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPLOTHIS_N.START_RES_ID);
            sqlstm.sqhstl[68] = (unsigned int  )21;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPLOTHIS_N.END_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPLOTHIS_N.END_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPLOTHIS_N.END_RES_ID);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPLOTHIS_N.SAMPLE_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPLOTHIS_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPLOTHIS_N.SAMPLE_RESULT);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPLOTHIS_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )26;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPLOTHIS_N.SHIP_CODE);
            sqlstm.sqhstl[77] = (unsigned int  )11;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MTMPLOTHIS_N.SHIP_TIME);
            sqlstm.sqhstl[78] = (unsigned int  )15;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MTMPLOTHIS_N.ORG_DUE_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MTMPLOTHIS_N.SCH_DUE_TIME);
            sqlstm.sqhstl[80] = (unsigned int  )15;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MTMPLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MTMPLOTHIS_N.FAC_IN_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MTMPLOTHIS_N.FLOW_IN_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MTMPLOTHIS_N.OPER_IN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MTMPLOTHIS_N.RESERVE_RES_ID);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MTMPLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )11;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MTMPLOTHIS_N.BATCH_ID);
            sqlstm.sqhstl[87] = (unsigned int  )26;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MTMPLOTHIS_N.BATCH_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MTMPLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )26;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[91] = (unsigned int  )26;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_1);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_2);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_3);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[116] = (unsigned int  )2;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_CODE);
            sqlstm.sqhstl[117] = (unsigned int  )11;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_TIME);
            sqlstm.sqhstl[118] = (unsigned int  )15;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MTMPLOTHIS_N.BOM_SET_ID);
            sqlstm.sqhstl[119] = (unsigned int  )26;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)&(MTMPLOTHIS_N.BOM_SET_VERSION);
            sqlstm.sqhstl[120] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)&(MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[121] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MTMPLOTHIS_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[123] = (unsigned int  )21;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[124] = (unsigned int  )21;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[125] = (unsigned int  )21;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[126] = (unsigned int  )21;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MTMPLOTHIS_N.SUBRES_ID);
            sqlstm.sqhstl[127] = (unsigned int  )21;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[128] = (unsigned int  )26;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[129] = (unsigned int  )26;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[130] = (unsigned int  )26;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)&(MTMPLOTHIS_N.YIELD_1);
            sqlstm.sqhstl[131] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)&(MTMPLOTHIS_N.YIELD_2);
            sqlstm.sqhstl[132] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)&(MTMPLOTHIS_N.YIELD_3);
            sqlstm.sqhstl[133] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)&(MTMPLOTHIS_N.GOOD_QTY);
            sqlstm.sqhstl[134] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_1);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_2);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_3);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_4);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_5);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_1);
            sqlstm.sqhstl[140] = (unsigned int  )2;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_2);
            sqlstm.sqhstl[141] = (unsigned int  )2;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_3);
            sqlstm.sqhstl[142] = (unsigned int  )2;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_4);
            sqlstm.sqhstl[143] = (unsigned int  )2;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_5);
            sqlstm.sqhstl[144] = (unsigned int  )2;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MTMPLOTHIS_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[146] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLOW);
            sqlstm.sqhstl[147] = (unsigned int  )21;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[148] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MTMPLOTHIS_N.FROM_TO_OPER);
            sqlstm.sqhstl[149] = (unsigned int  )11;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[150] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[152] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[154] = (unsigned int  )15;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MTMPLOTHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[155] = (unsigned int  )15;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_CODE);
            sqlstm.sqhstl[156] = (unsigned int  )13;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MTMPLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[157] = (unsigned int  )11;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MTMPLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[158] = (unsigned int  )31;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)&(MTMPLOTHIS_N.OLD_MAT_VER);
            sqlstm.sqhstl[159] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW);
            sqlstm.sqhstl[160] = (unsigned int  )21;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)&(MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[161] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MTMPLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[162] = (unsigned int  )11;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_1);
            sqlstm.sqhstl[163] = (unsigned int  )31;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_2);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_3);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_4);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_5);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_1);
            sqlstm.sqhstl[168] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[169] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[170] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MTMPLOTHIS_N.OLD_CRR_ID);
            sqlstm.sqhstl[171] = (unsigned int  )21;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_PRIORITY);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MTMPLOTHIS_N.OLD_ORDER_ID);
            sqlstm.sqhstl[174] = (unsigned int  )26;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MTMPLOTHIS_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[175] = (unsigned int  )11;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MTMPLOTHIS_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[176] = (unsigned int  )11;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MTMPLOTHIS_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[177] = (unsigned int  )15;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[178] = (unsigned int  )15;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MTMPLOTHIS_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[179] = (unsigned int  )15;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MTMPLOTHIS_N.OLD_RWK_FLAG);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MTMPLOTHIS_N.OLD_START_FLAG);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MTMPLOTHIS_N.OLD_START_TIME);
            sqlstm.sqhstl[182] = (unsigned int  )15;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MTMPLOTHIS_N.OLD_START_RES_ID);
            sqlstm.sqhstl[183] = (unsigned int  )21;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MTMPLOTHIS_N.OLD_END_FLAG);
            sqlstm.sqhstl[184] = (unsigned int  )2;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MTMPLOTHIS_N.OLD_END_TIME);
            sqlstm.sqhstl[185] = (unsigned int  )15;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MTMPLOTHIS_N.OLD_END_RES_ID);
            sqlstm.sqhstl[186] = (unsigned int  )21;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MTMPLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[207] = (unsigned int  )21;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MTMPLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[208] = (unsigned int  )401;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)&(MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[209] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MTMPLOTHIS_N.MULTI_TR_KEY);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)&(MTMPLOTHIS_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[211] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)&(MTMPLOTHIS_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[212] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[213] = (unsigned int  )2;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[214] = (unsigned int  )15;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[215] = (unsigned int  )21;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[216] = (unsigned int  )401;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MTMPLOTHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[218] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mtmplothis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mtmplothis(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MTMPLOTHIS_CUR_1 CURSOR FOR
                SELECT 
                    TABLE_UPDATE_SEQ,
                    CM_KEY_1,
                    CM_KEY_2,
                    CM_KEY_3,
                    CM_KEY_4,
                    CM_KEY_5,
                    LOT_ID,
                    SUB_LOT_ID,
                    SUB_LOT_FLAG,
                    HIST_SEQ,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_CODE,
                    LOT_DESC,
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    FLOW,
                    FLOW_SEQ_NUM,
                    OPER,
                    QTY_1,
                    QTY_2,
                    QTY_3,
                    CRR_ID,
                    LOT_TYPE,
                    OWNER_CODE,
                    CREATE_CODE,
                    LOT_PRIORITY,
                    LOT_STATUS,
                    HOLD_FLAG,
                    HOLD_CODE,
                    HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID,
                    OPER_IN_QTY_1,
                    OPER_IN_QTY_2,
                    OPER_IN_QTY_3,
                    CREATE_QTY_1,
                    CREATE_QTY_2,
                    CREATE_QTY_3,
                    START_QTY_1,
                    START_QTY_2,
                    START_QTY_3,
                    INV_FLAG,
                    TRANSIT_FLAG,
                    UNIT_EXIST_FLAG,
                    INV_UNIT,
                    RWK_FLAG,
                    RWK_CODE,
                    RWK_COUNT,
                    RWK_RET_FLOW,
                    RWK_RET_FLOW_SEQ_NUM,
                    RWK_RET_OPER,
                    RWK_END_FLOW,
                    RWK_END_FLOW_SEQ_NUM,
                    RWK_END_OPER,
                    RWK_RET_CLEAR_FLAG,
                    RWK_TIME,
                    NSTD_FLAG,
                    NSTD_RET_FLOW,
                    NSTD_RET_FLOW_SEQ_NUM,
                    NSTD_RET_OPER,
                    NSTD_TIME,
                    REP_FLAG,
                    REP_RET_OPER,
                    STR_RET_FLOW,
                    STR_RET_FLOW_SEQ_NUM,
                    STR_RET_OPER,
                    START_FLAG,
                    START_TIME,
                    START_RES_ID,
                    END_FLAG,
                    END_TIME,
                    END_RES_ID,
                    SAMPLE_FLAG,
                    SAMPLE_WAIT_FLAG,
                    SAMPLE_RESULT,
                    FROM_TO_FLAG,
                    FROM_TO_LOT_ID,
                    SHIP_CODE,
                    SHIP_TIME,
                    ORG_DUE_TIME,
                    SCH_DUE_TIME,
                    CREATE_TIME,
                    FAC_IN_TIME,
                    FLOW_IN_TIME,
                    OPER_IN_TIME,
                    RESERVE_RES_ID,
                    PORT_ID,
                    BATCH_ID,
                    BATCH_SEQ,
                    ORDER_ID,
                    ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3,
                    LOT_LOCATION_1,
                    LOT_LOCATION_2,
                    LOT_LOCATION_3,
                    LOT_CMF_1,
                    LOT_CMF_2,
                    LOT_CMF_3,
                    LOT_CMF_4,
                    LOT_CMF_5,
                    LOT_CMF_6,
                    LOT_CMF_7,
                    LOT_CMF_8,
                    LOT_CMF_9,
                    LOT_CMF_10,
                    LOT_CMF_11,
                    LOT_CMF_12,
                    LOT_CMF_13,
                    LOT_CMF_14,
                    LOT_CMF_15,
                    LOT_CMF_16,
                    LOT_CMF_17,
                    LOT_CMF_18,
                    LOT_CMF_19,
                    LOT_CMF_20,
                    LOT_DEL_FLAG,
                    LOT_DEL_CODE,
                    LOT_DEL_TIME,
                    BOM_SET_ID,
                    BOM_SET_VERSION,
                    BOM_ACTIVE_HIST_SEQ,
                    BOM_HIST_SEQ,
                    CRITICAL_RES_ID,
                    CRITICAL_RES_GROUP_ID,
                    SAVE_RES_ID_1,
                    SAVE_RES_ID_2,
                    SUBRES_ID,
                    LOT_GROUP_ID_1,
                    LOT_GROUP_ID_2,
                    LOT_GROUP_ID_3,
                    YIELD_1,
                    YIELD_2,
                    YIELD_3,
                    GOOD_QTY,
                    RESV_FIELD_1,
                    RESV_FIELD_2,
                    RESV_FIELD_3,
                    RESV_FIELD_4,
                    RESV_FIELD_5,
                    RESV_FLAG_1,
                    RESV_FLAG_2,
                    RESV_FLAG_3,
                    RESV_FLAG_4,
                    RESV_FLAG_5,
                    FROM_TO_MAT_ID,
                    FROM_TO_MAT_VER,
                    FROM_TO_FLOW,
                    FROM_TO_FLOW_SEQ_NUM,
                    FROM_TO_OPER,
                    FROM_TO_QTY_1,
                    FROM_TO_QTY_2,
                    FROM_TO_QTY_3,
                    FROM_TO_HIST_SEQ,
                    OLD_TRAN_TIME,
                    OLD_SYS_TRAN_TIME,
                    OLD_TRAN_CODE,
                    OLD_FACTORY,
                    OLD_MAT_ID,
                    OLD_MAT_VER,
                    OLD_FLOW,
                    OLD_FLOW_SEQ_NUM,
                    OLD_OPER,
                    OLD_CM_KEY_1,
                    OLD_CM_KEY_2,
                    OLD_CM_KEY_3,
                    OLD_CM_KEY_4,
                    OLD_CM_KEY_5,
                    OLD_QTY_1,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_CRR_ID,
                    OLD_LOT_TYPE,
                    OLD_LOT_PRIORITY,
                    OLD_ORDER_ID,
                    OLD_OWNER_CODE,
                    OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME,
                    OLD_RWK_FLAG,
                    OLD_START_FLAG,
                    OLD_START_TIME,
                    OLD_START_RES_ID,
                    OLD_END_FLAG,
                    OLD_END_TIME,
                    OLD_END_RES_ID,
                    TRAN_CMF_1,
                    TRAN_CMF_2,
                    TRAN_CMF_3,
                    TRAN_CMF_4,
                    TRAN_CMF_5,
                    TRAN_CMF_6,
                    TRAN_CMF_7,
                    TRAN_CMF_8,
                    TRAN_CMF_9,
                    TRAN_CMF_10,
                    TRAN_CMF_11,
                    TRAN_CMF_12,
                    TRAN_CMF_13,
                    TRAN_CMF_14,
                    TRAN_CMF_15,
                    TRAN_CMF_16,
                    TRAN_CMF_17,
                    TRAN_CMF_18,
                    TRAN_CMF_19,
                    TRAN_CMF_20,
                    TRAN_USER_ID,
                    TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ,
                    MULTI_TR_KEY,
                    MULTI_TR_SEQ,
                    EXT_HIST_SEQ,
                    HIST_DEL_FLAG,
                    HIST_DEL_TIME,
                    HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT,
                    PROCESS_FLAG
                FROM MTMPLOTHIS
                ORDER BY TABLE_UPDATE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_MTMPLOTHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select TABLE_UPDATE_SEQ ,CM_KEY_1 ,CM_KEY_2 ,CM_KEY_3 ,CM_KEY\
_4 ,CM_KEY_5 ,LOT_ID ,SUB_LOT_ID ,SUB_LOT_FLAG ,HIST_SEQ ,TRAN_TIME ,SYS_TRA\
N_TIME ,TRAN_CODE ,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,O\
PER ,QTY_1 ,QTY_2 ,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRI\
ORITY ,LOT_STATUS ,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,OPE\
R_IN_QTY_1 ,OPER_IN_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,CREATE\
_QTY_3 ,START_QTY_1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,UNIT_\
EXIST_FLAG ,INV_UNIT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_RET_F\
LOW_SEQ_NUM ,RWK_RET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_OPER \
,RWK_RET_CLEAR_FLAG ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_SEQ_N\
UM ,NSTD_RET_OPER ,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR_RET_\
FLOW_SEQ_NUM ,STR_RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_FLAG ,\
END_TIME ,END_RES_ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FROM_TO_\
FLAG ,FROM_TO_LOT_ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE");
            sqlbuft((void **)0,
              "_TIME ,SCH_DUE_TIME ,CREATE_TIME ,FAC_IN_TIME ,FLOW_IN_TIME ,\
OPER_IN_TIME ,RESERVE_RES_ID ,PORT_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,ADD_OR\
DER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_2 ,LO\
T_LOCATION_3 ,LOT_CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF\
_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT\
_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF\
_19 ,LOT_CMF_20 ,LOT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,BOM_S\
ET_VERSION ,BOM_ACTIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICAL_RES\
_GROUP_ID ,SAVE_RES_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT_GROU\
P_ID_2 ,LOT_GROUP_ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD_1 ,R\
ESV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RESV_FLA\
G_2 ,RESV_FLAG_3 ,RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT_VER \
,FROM_TO_FLOW ,FROM_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_TO_QT\
Y_2 ,FROM_TO_QTY_3 ,FROM_TO_HIST_SEQ ,OLD_TRAN_TIME");
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3638;
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
    DB_stop_query_timer("DBC_open_mtmplothis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mtmplothis(int sel_type, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MTMPLOTHIS_N_TAG MTMPLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MTMPLOTHIS_CUR_1 INTO 
                                                    :MTMPLOTHIS_N.TABLE_UPDATE_SEQ,
                                                    :MTMPLOTHIS_N.CM_KEY_1,
                                                    :MTMPLOTHIS_N.CM_KEY_2,
                                                    :MTMPLOTHIS_N.CM_KEY_3,
                                                    :MTMPLOTHIS_N.CM_KEY_4,
                                                    :MTMPLOTHIS_N.CM_KEY_5,
                                                    :MTMPLOTHIS_N.LOT_ID,
                                                    :MTMPLOTHIS_N.SUB_LOT_ID,
                                                    :MTMPLOTHIS_N.SUB_LOT_FLAG,
                                                    :MTMPLOTHIS_N.HIST_SEQ,
                                                    :MTMPLOTHIS_N.TRAN_TIME,
                                                    :MTMPLOTHIS_N.SYS_TRAN_TIME,
                                                    :MTMPLOTHIS_N.TRAN_CODE,
                                                    :MTMPLOTHIS_N.LOT_DESC,
                                                    :MTMPLOTHIS_N.FACTORY,
                                                    :MTMPLOTHIS_N.MAT_ID,
                                                    :MTMPLOTHIS_N.MAT_VER,
                                                    :MTMPLOTHIS_N.FLOW,
                                                    :MTMPLOTHIS_N.FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.OPER,
                                                    :MTMPLOTHIS_N.QTY_1,
                                                    :MTMPLOTHIS_N.QTY_2,
                                                    :MTMPLOTHIS_N.QTY_3,
                                                    :MTMPLOTHIS_N.CRR_ID,
                                                    :MTMPLOTHIS_N.LOT_TYPE,
                                                    :MTMPLOTHIS_N.OWNER_CODE,
                                                    :MTMPLOTHIS_N.CREATE_CODE,
                                                    :MTMPLOTHIS_N.LOT_PRIORITY,
                                                    :MTMPLOTHIS_N.LOT_STATUS,
                                                    :MTMPLOTHIS_N.HOLD_FLAG,
                                                    :MTMPLOTHIS_N.HOLD_CODE,
                                                    :MTMPLOTHIS_N.HOLD_PASSWORD,
                                                    :MTMPLOTHIS_N.HOLD_PRV_GRP_ID,
                                                    :MTMPLOTHIS_N.OPER_IN_QTY_1,
                                                    :MTMPLOTHIS_N.OPER_IN_QTY_2,
                                                    :MTMPLOTHIS_N.OPER_IN_QTY_3,
                                                    :MTMPLOTHIS_N.CREATE_QTY_1,
                                                    :MTMPLOTHIS_N.CREATE_QTY_2,
                                                    :MTMPLOTHIS_N.CREATE_QTY_3,
                                                    :MTMPLOTHIS_N.START_QTY_1,
                                                    :MTMPLOTHIS_N.START_QTY_2,
                                                    :MTMPLOTHIS_N.START_QTY_3,
                                                    :MTMPLOTHIS_N.INV_FLAG,
                                                    :MTMPLOTHIS_N.TRANSIT_FLAG,
                                                    :MTMPLOTHIS_N.UNIT_EXIST_FLAG,
                                                    :MTMPLOTHIS_N.INV_UNIT,
                                                    :MTMPLOTHIS_N.RWK_FLAG,
                                                    :MTMPLOTHIS_N.RWK_CODE,
                                                    :MTMPLOTHIS_N.RWK_COUNT,
                                                    :MTMPLOTHIS_N.RWK_RET_FLOW,
                                                    :MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.RWK_RET_OPER,
                                                    :MTMPLOTHIS_N.RWK_END_FLOW,
                                                    :MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.RWK_END_OPER,
                                                    :MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG,
                                                    :MTMPLOTHIS_N.RWK_TIME,
                                                    :MTMPLOTHIS_N.NSTD_FLAG,
                                                    :MTMPLOTHIS_N.NSTD_RET_FLOW,
                                                    :MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.NSTD_RET_OPER,
                                                    :MTMPLOTHIS_N.NSTD_TIME,
                                                    :MTMPLOTHIS_N.REP_FLAG,
                                                    :MTMPLOTHIS_N.REP_RET_OPER,
                                                    :MTMPLOTHIS_N.STR_RET_FLOW,
                                                    :MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.STR_RET_OPER,
                                                    :MTMPLOTHIS_N.START_FLAG,
                                                    :MTMPLOTHIS_N.START_TIME,
                                                    :MTMPLOTHIS_N.START_RES_ID,
                                                    :MTMPLOTHIS_N.END_FLAG,
                                                    :MTMPLOTHIS_N.END_TIME,
                                                    :MTMPLOTHIS_N.END_RES_ID,
                                                    :MTMPLOTHIS_N.SAMPLE_FLAG,
                                                    :MTMPLOTHIS_N.SAMPLE_WAIT_FLAG,
                                                    :MTMPLOTHIS_N.SAMPLE_RESULT,
                                                    :MTMPLOTHIS_N.FROM_TO_FLAG,
                                                    :MTMPLOTHIS_N.FROM_TO_LOT_ID,
                                                    :MTMPLOTHIS_N.SHIP_CODE,
                                                    :MTMPLOTHIS_N.SHIP_TIME,
                                                    :MTMPLOTHIS_N.ORG_DUE_TIME,
                                                    :MTMPLOTHIS_N.SCH_DUE_TIME,
                                                    :MTMPLOTHIS_N.CREATE_TIME,
                                                    :MTMPLOTHIS_N.FAC_IN_TIME,
                                                    :MTMPLOTHIS_N.FLOW_IN_TIME,
                                                    :MTMPLOTHIS_N.OPER_IN_TIME,
                                                    :MTMPLOTHIS_N.RESERVE_RES_ID,
                                                    :MTMPLOTHIS_N.PORT_ID,
                                                    :MTMPLOTHIS_N.BATCH_ID,
                                                    :MTMPLOTHIS_N.BATCH_SEQ,
                                                    :MTMPLOTHIS_N.ORDER_ID,
                                                    :MTMPLOTHIS_N.ADD_ORDER_ID_1,
                                                    :MTMPLOTHIS_N.ADD_ORDER_ID_2,
                                                    :MTMPLOTHIS_N.ADD_ORDER_ID_3,
                                                    :MTMPLOTHIS_N.LOT_LOCATION_1,
                                                    :MTMPLOTHIS_N.LOT_LOCATION_2,
                                                    :MTMPLOTHIS_N.LOT_LOCATION_3,
                                                    :MTMPLOTHIS_N.LOT_CMF_1,
                                                    :MTMPLOTHIS_N.LOT_CMF_2,
                                                    :MTMPLOTHIS_N.LOT_CMF_3,
                                                    :MTMPLOTHIS_N.LOT_CMF_4,
                                                    :MTMPLOTHIS_N.LOT_CMF_5,
                                                    :MTMPLOTHIS_N.LOT_CMF_6,
                                                    :MTMPLOTHIS_N.LOT_CMF_7,
                                                    :MTMPLOTHIS_N.LOT_CMF_8,
                                                    :MTMPLOTHIS_N.LOT_CMF_9,
                                                    :MTMPLOTHIS_N.LOT_CMF_10,
                                                    :MTMPLOTHIS_N.LOT_CMF_11,
                                                    :MTMPLOTHIS_N.LOT_CMF_12,
                                                    :MTMPLOTHIS_N.LOT_CMF_13,
                                                    :MTMPLOTHIS_N.LOT_CMF_14,
                                                    :MTMPLOTHIS_N.LOT_CMF_15,
                                                    :MTMPLOTHIS_N.LOT_CMF_16,
                                                    :MTMPLOTHIS_N.LOT_CMF_17,
                                                    :MTMPLOTHIS_N.LOT_CMF_18,
                                                    :MTMPLOTHIS_N.LOT_CMF_19,
                                                    :MTMPLOTHIS_N.LOT_CMF_20,
                                                    :MTMPLOTHIS_N.LOT_DEL_FLAG,
                                                    :MTMPLOTHIS_N.LOT_DEL_CODE,
                                                    :MTMPLOTHIS_N.LOT_DEL_TIME,
                                                    :MTMPLOTHIS_N.BOM_SET_ID,
                                                    :MTMPLOTHIS_N.BOM_SET_VERSION,
                                                    :MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ,
                                                    :MTMPLOTHIS_N.BOM_HIST_SEQ,
                                                    :MTMPLOTHIS_N.CRITICAL_RES_ID,
                                                    :MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID,
                                                    :MTMPLOTHIS_N.SAVE_RES_ID_1,
                                                    :MTMPLOTHIS_N.SAVE_RES_ID_2,
                                                    :MTMPLOTHIS_N.SUBRES_ID,
                                                    :MTMPLOTHIS_N.LOT_GROUP_ID_1,
                                                    :MTMPLOTHIS_N.LOT_GROUP_ID_2,
                                                    :MTMPLOTHIS_N.LOT_GROUP_ID_3,
                                                    :MTMPLOTHIS_N.YIELD_1,
                                                    :MTMPLOTHIS_N.YIELD_2,
                                                    :MTMPLOTHIS_N.YIELD_3,
                                                    :MTMPLOTHIS_N.GOOD_QTY,
                                                    :MTMPLOTHIS_N.RESV_FIELD_1,
                                                    :MTMPLOTHIS_N.RESV_FIELD_2,
                                                    :MTMPLOTHIS_N.RESV_FIELD_3,
                                                    :MTMPLOTHIS_N.RESV_FIELD_4,
                                                    :MTMPLOTHIS_N.RESV_FIELD_5,
                                                    :MTMPLOTHIS_N.RESV_FLAG_1,
                                                    :MTMPLOTHIS_N.RESV_FLAG_2,
                                                    :MTMPLOTHIS_N.RESV_FLAG_3,
                                                    :MTMPLOTHIS_N.RESV_FLAG_4,
                                                    :MTMPLOTHIS_N.RESV_FLAG_5,
                                                    :MTMPLOTHIS_N.FROM_TO_MAT_ID,
                                                    :MTMPLOTHIS_N.FROM_TO_MAT_VER,
                                                    :MTMPLOTHIS_N.FROM_TO_FLOW,
                                                    :MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.FROM_TO_OPER,
                                                    :MTMPLOTHIS_N.FROM_TO_QTY_1,
                                                    :MTMPLOTHIS_N.FROM_TO_QTY_2,
                                                    :MTMPLOTHIS_N.FROM_TO_QTY_3,
                                                    :MTMPLOTHIS_N.FROM_TO_HIST_SEQ,
                                                    :MTMPLOTHIS_N.OLD_TRAN_TIME,
                                                    :MTMPLOTHIS_N.OLD_SYS_TRAN_TIME,
                                                    :MTMPLOTHIS_N.OLD_TRAN_CODE,
                                                    :MTMPLOTHIS_N.OLD_FACTORY,
                                                    :MTMPLOTHIS_N.OLD_MAT_ID,
                                                    :MTMPLOTHIS_N.OLD_MAT_VER,
                                                    :MTMPLOTHIS_N.OLD_FLOW,
                                                    :MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM,
                                                    :MTMPLOTHIS_N.OLD_OPER,
                                                    :MTMPLOTHIS_N.OLD_CM_KEY_1,
                                                    :MTMPLOTHIS_N.OLD_CM_KEY_2,
                                                    :MTMPLOTHIS_N.OLD_CM_KEY_3,
                                                    :MTMPLOTHIS_N.OLD_CM_KEY_4,
                                                    :MTMPLOTHIS_N.OLD_CM_KEY_5,
                                                    :MTMPLOTHIS_N.OLD_QTY_1,
                                                    :MTMPLOTHIS_N.OLD_QTY_2,
                                                    :MTMPLOTHIS_N.OLD_QTY_3,
                                                    :MTMPLOTHIS_N.OLD_CRR_ID,
                                                    :MTMPLOTHIS_N.OLD_LOT_TYPE,
                                                    :MTMPLOTHIS_N.OLD_LOT_PRIORITY,
                                                    :MTMPLOTHIS_N.OLD_ORDER_ID,
                                                    :MTMPLOTHIS_N.OLD_OWNER_CODE,
                                                    :MTMPLOTHIS_N.OLD_CREATE_CODE,
                                                    :MTMPLOTHIS_N.OLD_FAC_IN_TIME,
                                                    :MTMPLOTHIS_N.OLD_FLOW_IN_TIME,
                                                    :MTMPLOTHIS_N.OLD_OPER_IN_TIME,
                                                    :MTMPLOTHIS_N.OLD_RWK_FLAG,
                                                    :MTMPLOTHIS_N.OLD_START_FLAG,
                                                    :MTMPLOTHIS_N.OLD_START_TIME,
                                                    :MTMPLOTHIS_N.OLD_START_RES_ID,
                                                    :MTMPLOTHIS_N.OLD_END_FLAG,
                                                    :MTMPLOTHIS_N.OLD_END_TIME,
                                                    :MTMPLOTHIS_N.OLD_END_RES_ID,
                                                    :MTMPLOTHIS_N.TRAN_CMF_1,
                                                    :MTMPLOTHIS_N.TRAN_CMF_2,
                                                    :MTMPLOTHIS_N.TRAN_CMF_3,
                                                    :MTMPLOTHIS_N.TRAN_CMF_4,
                                                    :MTMPLOTHIS_N.TRAN_CMF_5,
                                                    :MTMPLOTHIS_N.TRAN_CMF_6,
                                                    :MTMPLOTHIS_N.TRAN_CMF_7,
                                                    :MTMPLOTHIS_N.TRAN_CMF_8,
                                                    :MTMPLOTHIS_N.TRAN_CMF_9,
                                                    :MTMPLOTHIS_N.TRAN_CMF_10,
                                                    :MTMPLOTHIS_N.TRAN_CMF_11,
                                                    :MTMPLOTHIS_N.TRAN_CMF_12,
                                                    :MTMPLOTHIS_N.TRAN_CMF_13,
                                                    :MTMPLOTHIS_N.TRAN_CMF_14,
                                                    :MTMPLOTHIS_N.TRAN_CMF_15,
                                                    :MTMPLOTHIS_N.TRAN_CMF_16,
                                                    :MTMPLOTHIS_N.TRAN_CMF_17,
                                                    :MTMPLOTHIS_N.TRAN_CMF_18,
                                                    :MTMPLOTHIS_N.TRAN_CMF_19,
                                                    :MTMPLOTHIS_N.TRAN_CMF_20,
                                                    :MTMPLOTHIS_N.TRAN_USER_ID,
                                                    :MTMPLOTHIS_N.TRAN_COMMENT,
                                                    :MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ,
                                                    :MTMPLOTHIS_N.MULTI_TR_KEY,
                                                    :MTMPLOTHIS_N.MULTI_TR_SEQ,
                                                    :MTMPLOTHIS_N.EXT_HIST_SEQ,
                                                    :MTMPLOTHIS_N.HIST_DEL_FLAG,
                                                    :MTMPLOTHIS_N.HIST_DEL_TIME,
                                                    :MTMPLOTHIS_N.HIST_DEL_USER_ID,
                                                    :MTMPLOTHIS_N.HIST_DEL_COMMENT,
                                                    :MTMPLOTHIS_N.PROCESS_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3653;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(MTMPLOTHIS_N.TABLE_UPDATE_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MTMPLOTHIS_N.CM_KEY_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MTMPLOTHIS_N.CM_KEY_2);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MTMPLOTHIS_N.CM_KEY_3);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MTMPLOTHIS_N.CM_KEY_4);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MTMPLOTHIS_N.CM_KEY_5);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MTMPLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MTMPLOTHIS_N.SUB_LOT_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MTMPLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MTMPLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MTMPLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MTMPLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[12] = (unsigned int  )13;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MTMPLOTHIS_N.LOT_DESC);
            sqlstm.sqhstl[13] = (unsigned int  )201;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MTMPLOTHIS_N.FACTORY);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MTMPLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MTMPLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MTMPLOTHIS_N.FLOW);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(MTMPLOTHIS_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MTMPLOTHIS_N.OPER);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MTMPLOTHIS_N.QTY_1);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(MTMPLOTHIS_N.QTY_2);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MTMPLOTHIS_N.QTY_3);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MTMPLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MTMPLOTHIS_N.LOT_TYPE);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MTMPLOTHIS_N.OWNER_CODE);
            sqlstm.sqhstl[25] = (unsigned int  )11;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MTMPLOTHIS_N.CREATE_CODE);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MTMPLOTHIS_N.LOT_PRIORITY);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MTMPLOTHIS_N.LOT_STATUS);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MTMPLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[29] = (unsigned int  )2;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MTMPLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[30] = (unsigned int  )11;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MTMPLOTHIS_N.HOLD_PASSWORD);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MTMPLOTHIS_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(MTMPLOTHIS_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_1);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MTMPLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(MTMPLOTHIS_N.START_QTY_1);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MTMPLOTHIS_N.START_QTY_2);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MTMPLOTHIS_N.START_QTY_3);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MTMPLOTHIS_N.INV_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MTMPLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MTMPLOTHIS_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MTMPLOTHIS_N.INV_UNIT);
            sqlstm.sqhstl[45] = (unsigned int  )11;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MTMPLOTHIS_N.RWK_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MTMPLOTHIS_N.RWK_CODE);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MTMPLOTHIS_N.RWK_COUNT);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MTMPLOTHIS_N.RWK_RET_FLOW);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MTMPLOTHIS_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MTMPLOTHIS_N.RWK_RET_OPER);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MTMPLOTHIS_N.RWK_END_FLOW);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MTMPLOTHIS_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MTMPLOTHIS_N.RWK_END_OPER);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MTMPLOTHIS_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MTMPLOTHIS_N.RWK_TIME);
            sqlstm.sqhstl[56] = (unsigned int  )15;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MTMPLOTHIS_N.NSTD_FLAG);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MTMPLOTHIS_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MTMPLOTHIS_N.NSTD_RET_OPER);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MTMPLOTHIS_N.NSTD_TIME);
            sqlstm.sqhstl[61] = (unsigned int  )15;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MTMPLOTHIS_N.REP_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MTMPLOTHIS_N.REP_RET_OPER);
            sqlstm.sqhstl[63] = (unsigned int  )11;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MTMPLOTHIS_N.STR_RET_FLOW);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MTMPLOTHIS_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MTMPLOTHIS_N.STR_RET_OPER);
            sqlstm.sqhstl[66] = (unsigned int  )11;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MTMPLOTHIS_N.START_FLAG);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MTMPLOTHIS_N.START_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MTMPLOTHIS_N.START_RES_ID);
            sqlstm.sqhstl[69] = (unsigned int  )21;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MTMPLOTHIS_N.END_FLAG);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MTMPLOTHIS_N.END_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MTMPLOTHIS_N.END_RES_ID);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MTMPLOTHIS_N.SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MTMPLOTHIS_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MTMPLOTHIS_N.SAMPLE_RESULT);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MTMPLOTHIS_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[77] = (unsigned int  )26;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MTMPLOTHIS_N.SHIP_CODE);
            sqlstm.sqhstl[78] = (unsigned int  )11;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MTMPLOTHIS_N.SHIP_TIME);
            sqlstm.sqhstl[79] = (unsigned int  )15;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MTMPLOTHIS_N.ORG_DUE_TIME);
            sqlstm.sqhstl[80] = (unsigned int  )15;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MTMPLOTHIS_N.SCH_DUE_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MTMPLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MTMPLOTHIS_N.FAC_IN_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MTMPLOTHIS_N.FLOW_IN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MTMPLOTHIS_N.OPER_IN_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MTMPLOTHIS_N.RESERVE_RES_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MTMPLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[87] = (unsigned int  )11;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MTMPLOTHIS_N.BATCH_ID);
            sqlstm.sqhstl[88] = (unsigned int  )26;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MTMPLOTHIS_N.BATCH_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MTMPLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[91] = (unsigned int  )26;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MTMPLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[93] = (unsigned int  )26;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_1);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_2);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MTMPLOTHIS_N.LOT_LOCATION_3);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MTMPLOTHIS_N.LOT_CMF_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[117] = (unsigned int  )2;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_CODE);
            sqlstm.sqhstl[118] = (unsigned int  )11;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MTMPLOTHIS_N.LOT_DEL_TIME);
            sqlstm.sqhstl[119] = (unsigned int  )15;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MTMPLOTHIS_N.BOM_SET_ID);
            sqlstm.sqhstl[120] = (unsigned int  )26;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)&(MTMPLOTHIS_N.BOM_SET_VERSION);
            sqlstm.sqhstl[121] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MTMPLOTHIS_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)&(MTMPLOTHIS_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[123] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[124] = (unsigned int  )21;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MTMPLOTHIS_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[125] = (unsigned int  )21;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[126] = (unsigned int  )21;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MTMPLOTHIS_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[127] = (unsigned int  )21;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MTMPLOTHIS_N.SUBRES_ID);
            sqlstm.sqhstl[128] = (unsigned int  )21;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[129] = (unsigned int  )26;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[130] = (unsigned int  )26;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MTMPLOTHIS_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[131] = (unsigned int  )26;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)&(MTMPLOTHIS_N.YIELD_1);
            sqlstm.sqhstl[132] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)&(MTMPLOTHIS_N.YIELD_2);
            sqlstm.sqhstl[133] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)&(MTMPLOTHIS_N.YIELD_3);
            sqlstm.sqhstl[134] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)&(MTMPLOTHIS_N.GOOD_QTY);
            sqlstm.sqhstl[135] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_1);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_2);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_3);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_4);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MTMPLOTHIS_N.RESV_FIELD_5);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_1);
            sqlstm.sqhstl[141] = (unsigned int  )2;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_2);
            sqlstm.sqhstl[142] = (unsigned int  )2;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_3);
            sqlstm.sqhstl[143] = (unsigned int  )2;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_4);
            sqlstm.sqhstl[144] = (unsigned int  )2;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MTMPLOTHIS_N.RESV_FLAG_5);
            sqlstm.sqhstl[145] = (unsigned int  )2;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MTMPLOTHIS_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[147] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MTMPLOTHIS_N.FROM_TO_FLOW);
            sqlstm.sqhstl[148] = (unsigned int  )21;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MTMPLOTHIS_N.FROM_TO_OPER);
            sqlstm.sqhstl[150] = (unsigned int  )11;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[152] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MTMPLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_TIME);
            sqlstm.sqhstl[155] = (unsigned int  )15;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MTMPLOTHIS_N.OLD_SYS_TRAN_TIME);
            sqlstm.sqhstl[156] = (unsigned int  )15;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MTMPLOTHIS_N.OLD_TRAN_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )13;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MTMPLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MTMPLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[159] = (unsigned int  )31;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)&(MTMPLOTHIS_N.OLD_MAT_VER);
            sqlstm.sqhstl[160] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW);
            sqlstm.sqhstl[161] = (unsigned int  )21;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)&(MTMPLOTHIS_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[162] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MTMPLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[163] = (unsigned int  )11;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_1);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_2);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_3);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_4);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MTMPLOTHIS_N.OLD_CM_KEY_5);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_1);
            sqlstm.sqhstl[169] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[170] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)&(MTMPLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[171] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MTMPLOTHIS_N.OLD_CRR_ID);
            sqlstm.sqhstl[172] = (unsigned int  )21;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MTMPLOTHIS_N.OLD_LOT_PRIORITY);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MTMPLOTHIS_N.OLD_ORDER_ID);
            sqlstm.sqhstl[175] = (unsigned int  )26;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MTMPLOTHIS_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[176] = (unsigned int  )11;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MTMPLOTHIS_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[177] = (unsigned int  )11;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MTMPLOTHIS_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[178] = (unsigned int  )15;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MTMPLOTHIS_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[179] = (unsigned int  )15;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MTMPLOTHIS_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[180] = (unsigned int  )15;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MTMPLOTHIS_N.OLD_RWK_FLAG);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MTMPLOTHIS_N.OLD_START_FLAG);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MTMPLOTHIS_N.OLD_START_TIME);
            sqlstm.sqhstl[183] = (unsigned int  )15;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MTMPLOTHIS_N.OLD_START_RES_ID);
            sqlstm.sqhstl[184] = (unsigned int  )21;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MTMPLOTHIS_N.OLD_END_FLAG);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MTMPLOTHIS_N.OLD_END_TIME);
            sqlstm.sqhstl[186] = (unsigned int  )15;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MTMPLOTHIS_N.OLD_END_RES_ID);
            sqlstm.sqhstl[187] = (unsigned int  )21;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_11);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_12);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_13);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_14);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_15);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_16);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_17);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_18);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_19);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MTMPLOTHIS_N.TRAN_CMF_20);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MTMPLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[208] = (unsigned int  )21;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MTMPLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[209] = (unsigned int  )401;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)&(MTMPLOTHIS_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[210] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MTMPLOTHIS_N.MULTI_TR_KEY);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)&(MTMPLOTHIS_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[212] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)&(MTMPLOTHIS_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[213] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[215] = (unsigned int  )15;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[216] = (unsigned int  )21;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MTMPLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[217] = (unsigned int  )401;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MTMPLOTHIS_N.PROCESS_FLAG);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
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
        DBC_del_null_mtmplothis(&MTMPLOTHIS_N, MTMPLOTHIS);
    }
    DB_stop_query_timer("DBC_fetch_mtmplothis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mtmplothis(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MTMPLOTHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 220;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4544;
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
    DB_stop_query_timer("DBC_close_mtmplothis", sel_type);
}


/* Initialize Function */
void DBC_init_mtmplothis(struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* memset by Space */
    memset(MTMPLOTHIS, ' ', sizeof(struct MTMPLOTHIS_TAG));
    
    MTMPLOTHIS->TABLE_UPDATE_SEQ = 0;
    MTMPLOTHIS->HIST_SEQ = 0;
    MTMPLOTHIS->MAT_VER = 0;
    MTMPLOTHIS->FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->QTY_1 = 0;
    MTMPLOTHIS->QTY_2 = 0;
    MTMPLOTHIS->QTY_3 = 0;
    MTMPLOTHIS->OPER_IN_QTY_1 = 0;
    MTMPLOTHIS->OPER_IN_QTY_2 = 0;
    MTMPLOTHIS->OPER_IN_QTY_3 = 0;
    MTMPLOTHIS->CREATE_QTY_1 = 0;
    MTMPLOTHIS->CREATE_QTY_2 = 0;
    MTMPLOTHIS->CREATE_QTY_3 = 0;
    MTMPLOTHIS->START_QTY_1 = 0;
    MTMPLOTHIS->START_QTY_2 = 0;
    MTMPLOTHIS->START_QTY_3 = 0;
    MTMPLOTHIS->RWK_COUNT = 0;
    MTMPLOTHIS->RWK_RET_FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->RWK_END_FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->NSTD_RET_FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->BATCH_SEQ = 0;
    MTMPLOTHIS->BOM_SET_VERSION = 0;
    MTMPLOTHIS->BOM_ACTIVE_HIST_SEQ = 0;
    MTMPLOTHIS->BOM_HIST_SEQ = 0;
    MTMPLOTHIS->FROM_TO_MAT_VER = 0;
    MTMPLOTHIS->FROM_TO_FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->FROM_TO_QTY_1 = 0;
    MTMPLOTHIS->FROM_TO_QTY_2 = 0;
    MTMPLOTHIS->FROM_TO_QTY_3 = 0;
    MTMPLOTHIS->FROM_TO_HIST_SEQ = 0;
    MTMPLOTHIS->OLD_MAT_VER = 0;
    MTMPLOTHIS->OLD_FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->OLD_QTY_1 = 0;
    MTMPLOTHIS->OLD_QTY_2 = 0;
    MTMPLOTHIS->OLD_QTY_3 = 0;
    MTMPLOTHIS->PREV_ACTIVE_HIST_SEQ = 0;
    MTMPLOTHIS->MULTI_TR_SEQ = 0;
    MTMPLOTHIS->STR_RET_FLOW_SEQ_NUM = 0;
    MTMPLOTHIS->YIELD_1 = 0;
    MTMPLOTHIS->YIELD_2 = 0;
    MTMPLOTHIS->YIELD_3 = 0;
    MTMPLOTHIS->GOOD_QTY = 0;
    MTMPLOTHIS->EXT_HIST_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_mtmplothis(struct MTMPLOTHIS_N_TAG *MTMPLOTHIS_N, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    /* memset by NULL */
    memset(MTMPLOTHIS_N, '\0', sizeof(struct MTMPLOTHIS_N_TAG));
    
    MTMPLOTHIS_N->TABLE_UPDATE_SEQ = MTMPLOTHIS->TABLE_UPDATE_SEQ;
    MEMCPY_AN(MTMPLOTHIS_N->CM_KEY_1, MTMPLOTHIS->CM_KEY_1, sizeof(MTMPLOTHIS->CM_KEY_1));
    MEMCPY_AN(MTMPLOTHIS_N->CM_KEY_2, MTMPLOTHIS->CM_KEY_2, sizeof(MTMPLOTHIS->CM_KEY_2));
    MEMCPY_AN(MTMPLOTHIS_N->CM_KEY_3, MTMPLOTHIS->CM_KEY_3, sizeof(MTMPLOTHIS->CM_KEY_3));
    MEMCPY_AN(MTMPLOTHIS_N->CM_KEY_4, MTMPLOTHIS->CM_KEY_4, sizeof(MTMPLOTHIS->CM_KEY_4));
    MEMCPY_AN(MTMPLOTHIS_N->CM_KEY_5, MTMPLOTHIS->CM_KEY_5, sizeof(MTMPLOTHIS->CM_KEY_5));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_ID, MTMPLOTHIS->LOT_ID, sizeof(MTMPLOTHIS->LOT_ID));
    MEMCPY_AN(MTMPLOTHIS_N->SUB_LOT_ID, MTMPLOTHIS->SUB_LOT_ID, sizeof(MTMPLOTHIS->SUB_LOT_ID));
    MTMPLOTHIS_N->SUB_LOT_FLAG[0] = MTMPLOTHIS->SUB_LOT_FLAG;
    MTMPLOTHIS_N->HIST_SEQ = MTMPLOTHIS->HIST_SEQ;
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_TIME, MTMPLOTHIS->TRAN_TIME, sizeof(MTMPLOTHIS->TRAN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->SYS_TRAN_TIME, MTMPLOTHIS->SYS_TRAN_TIME, sizeof(MTMPLOTHIS->SYS_TRAN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CODE, MTMPLOTHIS->TRAN_CODE, sizeof(MTMPLOTHIS->TRAN_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_DESC, MTMPLOTHIS->LOT_DESC, sizeof(MTMPLOTHIS->LOT_DESC));
    MEMCPY_AN(MTMPLOTHIS_N->FACTORY, MTMPLOTHIS->FACTORY, sizeof(MTMPLOTHIS->FACTORY));
    MEMCPY_AN(MTMPLOTHIS_N->MAT_ID, MTMPLOTHIS->MAT_ID, sizeof(MTMPLOTHIS->MAT_ID));
    MTMPLOTHIS_N->MAT_VER = MTMPLOTHIS->MAT_VER;
    MEMCPY_AN(MTMPLOTHIS_N->FLOW, MTMPLOTHIS->FLOW, sizeof(MTMPLOTHIS->FLOW));
    MTMPLOTHIS_N->FLOW_SEQ_NUM = MTMPLOTHIS->FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->OPER, MTMPLOTHIS->OPER, sizeof(MTMPLOTHIS->OPER));
    MTMPLOTHIS_N->QTY_1 = MTMPLOTHIS->QTY_1;
    MTMPLOTHIS_N->QTY_2 = MTMPLOTHIS->QTY_2;
    MTMPLOTHIS_N->QTY_3 = MTMPLOTHIS->QTY_3;
    MEMCPY_AN(MTMPLOTHIS_N->CRR_ID, MTMPLOTHIS->CRR_ID, sizeof(MTMPLOTHIS->CRR_ID));
    MTMPLOTHIS_N->LOT_TYPE[0] = MTMPLOTHIS->LOT_TYPE;
    MEMCPY_AN(MTMPLOTHIS_N->OWNER_CODE, MTMPLOTHIS->OWNER_CODE, sizeof(MTMPLOTHIS->OWNER_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->CREATE_CODE, MTMPLOTHIS->CREATE_CODE, sizeof(MTMPLOTHIS->CREATE_CODE));
    MTMPLOTHIS_N->LOT_PRIORITY[0] = MTMPLOTHIS->LOT_PRIORITY;
    MEMCPY_AN(MTMPLOTHIS_N->LOT_STATUS, MTMPLOTHIS->LOT_STATUS, sizeof(MTMPLOTHIS->LOT_STATUS));
    MTMPLOTHIS_N->HOLD_FLAG[0] = MTMPLOTHIS->HOLD_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->HOLD_CODE, MTMPLOTHIS->HOLD_CODE, sizeof(MTMPLOTHIS->HOLD_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->HOLD_PASSWORD, MTMPLOTHIS->HOLD_PASSWORD, sizeof(MTMPLOTHIS->HOLD_PASSWORD));
    MEMCPY_AN(MTMPLOTHIS_N->HOLD_PRV_GRP_ID, MTMPLOTHIS->HOLD_PRV_GRP_ID, sizeof(MTMPLOTHIS->HOLD_PRV_GRP_ID));
    MTMPLOTHIS_N->OPER_IN_QTY_1 = MTMPLOTHIS->OPER_IN_QTY_1;
    MTMPLOTHIS_N->OPER_IN_QTY_2 = MTMPLOTHIS->OPER_IN_QTY_2;
    MTMPLOTHIS_N->OPER_IN_QTY_3 = MTMPLOTHIS->OPER_IN_QTY_3;
    MTMPLOTHIS_N->CREATE_QTY_1 = MTMPLOTHIS->CREATE_QTY_1;
    MTMPLOTHIS_N->CREATE_QTY_2 = MTMPLOTHIS->CREATE_QTY_2;
    MTMPLOTHIS_N->CREATE_QTY_3 = MTMPLOTHIS->CREATE_QTY_3;
    MTMPLOTHIS_N->START_QTY_1 = MTMPLOTHIS->START_QTY_1;
    MTMPLOTHIS_N->START_QTY_2 = MTMPLOTHIS->START_QTY_2;
    MTMPLOTHIS_N->START_QTY_3 = MTMPLOTHIS->START_QTY_3;
    MTMPLOTHIS_N->INV_FLAG[0] = MTMPLOTHIS->INV_FLAG;
    MTMPLOTHIS_N->TRANSIT_FLAG[0] = MTMPLOTHIS->TRANSIT_FLAG;
    MTMPLOTHIS_N->UNIT_EXIST_FLAG[0] = MTMPLOTHIS->UNIT_EXIST_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->INV_UNIT, MTMPLOTHIS->INV_UNIT, sizeof(MTMPLOTHIS->INV_UNIT));
    MTMPLOTHIS_N->RWK_FLAG[0] = MTMPLOTHIS->RWK_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->RWK_CODE, MTMPLOTHIS->RWK_CODE, sizeof(MTMPLOTHIS->RWK_CODE));
    MTMPLOTHIS_N->RWK_COUNT = MTMPLOTHIS->RWK_COUNT;
    MEMCPY_AN(MTMPLOTHIS_N->RWK_RET_FLOW, MTMPLOTHIS->RWK_RET_FLOW, sizeof(MTMPLOTHIS->RWK_RET_FLOW));
    MTMPLOTHIS_N->RWK_RET_FLOW_SEQ_NUM = MTMPLOTHIS->RWK_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->RWK_RET_OPER, MTMPLOTHIS->RWK_RET_OPER, sizeof(MTMPLOTHIS->RWK_RET_OPER));
    MEMCPY_AN(MTMPLOTHIS_N->RWK_END_FLOW, MTMPLOTHIS->RWK_END_FLOW, sizeof(MTMPLOTHIS->RWK_END_FLOW));
    MTMPLOTHIS_N->RWK_END_FLOW_SEQ_NUM = MTMPLOTHIS->RWK_END_FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->RWK_END_OPER, MTMPLOTHIS->RWK_END_OPER, sizeof(MTMPLOTHIS->RWK_END_OPER));
    MTMPLOTHIS_N->RWK_RET_CLEAR_FLAG[0] = MTMPLOTHIS->RWK_RET_CLEAR_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->RWK_TIME, MTMPLOTHIS->RWK_TIME, sizeof(MTMPLOTHIS->RWK_TIME));
    MTMPLOTHIS_N->NSTD_FLAG[0] = MTMPLOTHIS->NSTD_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->NSTD_RET_FLOW, MTMPLOTHIS->NSTD_RET_FLOW, sizeof(MTMPLOTHIS->NSTD_RET_FLOW));
    MTMPLOTHIS_N->NSTD_RET_FLOW_SEQ_NUM = MTMPLOTHIS->NSTD_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->NSTD_RET_OPER, MTMPLOTHIS->NSTD_RET_OPER, sizeof(MTMPLOTHIS->NSTD_RET_OPER));
    MEMCPY_AN(MTMPLOTHIS_N->NSTD_TIME, MTMPLOTHIS->NSTD_TIME, sizeof(MTMPLOTHIS->NSTD_TIME));
    MTMPLOTHIS_N->REP_FLAG[0] = MTMPLOTHIS->REP_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->REP_RET_OPER, MTMPLOTHIS->REP_RET_OPER, sizeof(MTMPLOTHIS->REP_RET_OPER));
    MEMCPY_AN(MTMPLOTHIS_N->STR_RET_FLOW, MTMPLOTHIS->STR_RET_FLOW, sizeof(MTMPLOTHIS->STR_RET_FLOW));
    MTMPLOTHIS_N->STR_RET_FLOW_SEQ_NUM = MTMPLOTHIS->STR_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->STR_RET_OPER, MTMPLOTHIS->STR_RET_OPER, sizeof(MTMPLOTHIS->STR_RET_OPER));
    MTMPLOTHIS_N->START_FLAG[0] = MTMPLOTHIS->START_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->START_TIME, MTMPLOTHIS->START_TIME, sizeof(MTMPLOTHIS->START_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->START_RES_ID, MTMPLOTHIS->START_RES_ID, sizeof(MTMPLOTHIS->START_RES_ID));
    MTMPLOTHIS_N->END_FLAG[0] = MTMPLOTHIS->END_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->END_TIME, MTMPLOTHIS->END_TIME, sizeof(MTMPLOTHIS->END_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->END_RES_ID, MTMPLOTHIS->END_RES_ID, sizeof(MTMPLOTHIS->END_RES_ID));
    MTMPLOTHIS_N->SAMPLE_FLAG[0] = MTMPLOTHIS->SAMPLE_FLAG;
    MTMPLOTHIS_N->SAMPLE_WAIT_FLAG[0] = MTMPLOTHIS->SAMPLE_WAIT_FLAG;
    MTMPLOTHIS_N->SAMPLE_RESULT[0] = MTMPLOTHIS->SAMPLE_RESULT;
    MTMPLOTHIS_N->FROM_TO_FLAG[0] = MTMPLOTHIS->FROM_TO_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->FROM_TO_LOT_ID, MTMPLOTHIS->FROM_TO_LOT_ID, sizeof(MTMPLOTHIS->FROM_TO_LOT_ID));
    MEMCPY_AN(MTMPLOTHIS_N->SHIP_CODE, MTMPLOTHIS->SHIP_CODE, sizeof(MTMPLOTHIS->SHIP_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->SHIP_TIME, MTMPLOTHIS->SHIP_TIME, sizeof(MTMPLOTHIS->SHIP_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->ORG_DUE_TIME, MTMPLOTHIS->ORG_DUE_TIME, sizeof(MTMPLOTHIS->ORG_DUE_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->SCH_DUE_TIME, MTMPLOTHIS->SCH_DUE_TIME, sizeof(MTMPLOTHIS->SCH_DUE_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->CREATE_TIME, MTMPLOTHIS->CREATE_TIME, sizeof(MTMPLOTHIS->CREATE_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->FAC_IN_TIME, MTMPLOTHIS->FAC_IN_TIME, sizeof(MTMPLOTHIS->FAC_IN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->FLOW_IN_TIME, MTMPLOTHIS->FLOW_IN_TIME, sizeof(MTMPLOTHIS->FLOW_IN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OPER_IN_TIME, MTMPLOTHIS->OPER_IN_TIME, sizeof(MTMPLOTHIS->OPER_IN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->RESERVE_RES_ID, MTMPLOTHIS->RESERVE_RES_ID, sizeof(MTMPLOTHIS->RESERVE_RES_ID));
    MEMCPY_AN(MTMPLOTHIS_N->PORT_ID, MTMPLOTHIS->PORT_ID, sizeof(MTMPLOTHIS->PORT_ID));
    MEMCPY_AN(MTMPLOTHIS_N->BATCH_ID, MTMPLOTHIS->BATCH_ID, sizeof(MTMPLOTHIS->BATCH_ID));
    MTMPLOTHIS_N->BATCH_SEQ = MTMPLOTHIS->BATCH_SEQ;
    MEMCPY_AN(MTMPLOTHIS_N->ORDER_ID, MTMPLOTHIS->ORDER_ID, sizeof(MTMPLOTHIS->ORDER_ID));
    MEMCPY_AN(MTMPLOTHIS_N->ADD_ORDER_ID_1, MTMPLOTHIS->ADD_ORDER_ID_1, sizeof(MTMPLOTHIS->ADD_ORDER_ID_1));
    MEMCPY_AN(MTMPLOTHIS_N->ADD_ORDER_ID_2, MTMPLOTHIS->ADD_ORDER_ID_2, sizeof(MTMPLOTHIS->ADD_ORDER_ID_2));
    MEMCPY_AN(MTMPLOTHIS_N->ADD_ORDER_ID_3, MTMPLOTHIS->ADD_ORDER_ID_3, sizeof(MTMPLOTHIS->ADD_ORDER_ID_3));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_LOCATION_1, MTMPLOTHIS->LOT_LOCATION_1, sizeof(MTMPLOTHIS->LOT_LOCATION_1));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_LOCATION_2, MTMPLOTHIS->LOT_LOCATION_2, sizeof(MTMPLOTHIS->LOT_LOCATION_2));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_LOCATION_3, MTMPLOTHIS->LOT_LOCATION_3, sizeof(MTMPLOTHIS->LOT_LOCATION_3));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_1, MTMPLOTHIS->LOT_CMF_1, sizeof(MTMPLOTHIS->LOT_CMF_1));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_2, MTMPLOTHIS->LOT_CMF_2, sizeof(MTMPLOTHIS->LOT_CMF_2));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_3, MTMPLOTHIS->LOT_CMF_3, sizeof(MTMPLOTHIS->LOT_CMF_3));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_4, MTMPLOTHIS->LOT_CMF_4, sizeof(MTMPLOTHIS->LOT_CMF_4));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_5, MTMPLOTHIS->LOT_CMF_5, sizeof(MTMPLOTHIS->LOT_CMF_5));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_6, MTMPLOTHIS->LOT_CMF_6, sizeof(MTMPLOTHIS->LOT_CMF_6));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_7, MTMPLOTHIS->LOT_CMF_7, sizeof(MTMPLOTHIS->LOT_CMF_7));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_8, MTMPLOTHIS->LOT_CMF_8, sizeof(MTMPLOTHIS->LOT_CMF_8));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_9, MTMPLOTHIS->LOT_CMF_9, sizeof(MTMPLOTHIS->LOT_CMF_9));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_10, MTMPLOTHIS->LOT_CMF_10, sizeof(MTMPLOTHIS->LOT_CMF_10));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_11, MTMPLOTHIS->LOT_CMF_11, sizeof(MTMPLOTHIS->LOT_CMF_11));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_12, MTMPLOTHIS->LOT_CMF_12, sizeof(MTMPLOTHIS->LOT_CMF_12));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_13, MTMPLOTHIS->LOT_CMF_13, sizeof(MTMPLOTHIS->LOT_CMF_13));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_14, MTMPLOTHIS->LOT_CMF_14, sizeof(MTMPLOTHIS->LOT_CMF_14));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_15, MTMPLOTHIS->LOT_CMF_15, sizeof(MTMPLOTHIS->LOT_CMF_15));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_16, MTMPLOTHIS->LOT_CMF_16, sizeof(MTMPLOTHIS->LOT_CMF_16));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_17, MTMPLOTHIS->LOT_CMF_17, sizeof(MTMPLOTHIS->LOT_CMF_17));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_18, MTMPLOTHIS->LOT_CMF_18, sizeof(MTMPLOTHIS->LOT_CMF_18));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_19, MTMPLOTHIS->LOT_CMF_19, sizeof(MTMPLOTHIS->LOT_CMF_19));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_CMF_20, MTMPLOTHIS->LOT_CMF_20, sizeof(MTMPLOTHIS->LOT_CMF_20));
    MTMPLOTHIS_N->LOT_DEL_FLAG[0] = MTMPLOTHIS->LOT_DEL_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->LOT_DEL_CODE, MTMPLOTHIS->LOT_DEL_CODE, sizeof(MTMPLOTHIS->LOT_DEL_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_DEL_TIME, MTMPLOTHIS->LOT_DEL_TIME, sizeof(MTMPLOTHIS->LOT_DEL_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->BOM_SET_ID, MTMPLOTHIS->BOM_SET_ID, sizeof(MTMPLOTHIS->BOM_SET_ID));
    MTMPLOTHIS_N->BOM_SET_VERSION = MTMPLOTHIS->BOM_SET_VERSION;
    MTMPLOTHIS_N->BOM_ACTIVE_HIST_SEQ = MTMPLOTHIS->BOM_ACTIVE_HIST_SEQ;
    MTMPLOTHIS_N->BOM_HIST_SEQ = MTMPLOTHIS->BOM_HIST_SEQ;
    MEMCPY_AN(MTMPLOTHIS_N->CRITICAL_RES_ID, MTMPLOTHIS->CRITICAL_RES_ID, sizeof(MTMPLOTHIS->CRITICAL_RES_ID));
    MEMCPY_AN(MTMPLOTHIS_N->CRITICAL_RES_GROUP_ID, MTMPLOTHIS->CRITICAL_RES_GROUP_ID, sizeof(MTMPLOTHIS->CRITICAL_RES_GROUP_ID));
    MEMCPY_AN(MTMPLOTHIS_N->SAVE_RES_ID_1, MTMPLOTHIS->SAVE_RES_ID_1, sizeof(MTMPLOTHIS->SAVE_RES_ID_1));
    MEMCPY_AN(MTMPLOTHIS_N->SAVE_RES_ID_2, MTMPLOTHIS->SAVE_RES_ID_2, sizeof(MTMPLOTHIS->SAVE_RES_ID_2));
    MEMCPY_AN(MTMPLOTHIS_N->SUBRES_ID, MTMPLOTHIS->SUBRES_ID, sizeof(MTMPLOTHIS->SUBRES_ID));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_GROUP_ID_1, MTMPLOTHIS->LOT_GROUP_ID_1, sizeof(MTMPLOTHIS->LOT_GROUP_ID_1));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_GROUP_ID_2, MTMPLOTHIS->LOT_GROUP_ID_2, sizeof(MTMPLOTHIS->LOT_GROUP_ID_2));
    MEMCPY_AN(MTMPLOTHIS_N->LOT_GROUP_ID_3, MTMPLOTHIS->LOT_GROUP_ID_3, sizeof(MTMPLOTHIS->LOT_GROUP_ID_3));
    MTMPLOTHIS_N->YIELD_1 = MTMPLOTHIS->YIELD_1;
    MTMPLOTHIS_N->YIELD_2 = MTMPLOTHIS->YIELD_2;
    MTMPLOTHIS_N->YIELD_3 = MTMPLOTHIS->YIELD_3;
    MTMPLOTHIS_N->GOOD_QTY = MTMPLOTHIS->GOOD_QTY;
    MEMCPY_AN(MTMPLOTHIS_N->RESV_FIELD_1, MTMPLOTHIS->RESV_FIELD_1, sizeof(MTMPLOTHIS->RESV_FIELD_1));
    MEMCPY_AN(MTMPLOTHIS_N->RESV_FIELD_2, MTMPLOTHIS->RESV_FIELD_2, sizeof(MTMPLOTHIS->RESV_FIELD_2));
    MEMCPY_AN(MTMPLOTHIS_N->RESV_FIELD_3, MTMPLOTHIS->RESV_FIELD_3, sizeof(MTMPLOTHIS->RESV_FIELD_3));
    MEMCPY_AN(MTMPLOTHIS_N->RESV_FIELD_4, MTMPLOTHIS->RESV_FIELD_4, sizeof(MTMPLOTHIS->RESV_FIELD_4));
    MEMCPY_AN(MTMPLOTHIS_N->RESV_FIELD_5, MTMPLOTHIS->RESV_FIELD_5, sizeof(MTMPLOTHIS->RESV_FIELD_5));
    MTMPLOTHIS_N->RESV_FLAG_1[0] = MTMPLOTHIS->RESV_FLAG_1;
    MTMPLOTHIS_N->RESV_FLAG_2[0] = MTMPLOTHIS->RESV_FLAG_2;
    MTMPLOTHIS_N->RESV_FLAG_3[0] = MTMPLOTHIS->RESV_FLAG_3;
    MTMPLOTHIS_N->RESV_FLAG_4[0] = MTMPLOTHIS->RESV_FLAG_4;
    MTMPLOTHIS_N->RESV_FLAG_5[0] = MTMPLOTHIS->RESV_FLAG_5;
    MEMCPY_AN(MTMPLOTHIS_N->FROM_TO_MAT_ID, MTMPLOTHIS->FROM_TO_MAT_ID, sizeof(MTMPLOTHIS->FROM_TO_MAT_ID));
    MTMPLOTHIS_N->FROM_TO_MAT_VER = MTMPLOTHIS->FROM_TO_MAT_VER;
    MEMCPY_AN(MTMPLOTHIS_N->FROM_TO_FLOW, MTMPLOTHIS->FROM_TO_FLOW, sizeof(MTMPLOTHIS->FROM_TO_FLOW));
    MTMPLOTHIS_N->FROM_TO_FLOW_SEQ_NUM = MTMPLOTHIS->FROM_TO_FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->FROM_TO_OPER, MTMPLOTHIS->FROM_TO_OPER, sizeof(MTMPLOTHIS->FROM_TO_OPER));
    MTMPLOTHIS_N->FROM_TO_QTY_1 = MTMPLOTHIS->FROM_TO_QTY_1;
    MTMPLOTHIS_N->FROM_TO_QTY_2 = MTMPLOTHIS->FROM_TO_QTY_2;
    MTMPLOTHIS_N->FROM_TO_QTY_3 = MTMPLOTHIS->FROM_TO_QTY_3;
    MTMPLOTHIS_N->FROM_TO_HIST_SEQ = MTMPLOTHIS->FROM_TO_HIST_SEQ;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_TRAN_TIME, MTMPLOTHIS->OLD_TRAN_TIME, sizeof(MTMPLOTHIS->OLD_TRAN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_SYS_TRAN_TIME, MTMPLOTHIS->OLD_SYS_TRAN_TIME, sizeof(MTMPLOTHIS->OLD_SYS_TRAN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_TRAN_CODE, MTMPLOTHIS->OLD_TRAN_CODE, sizeof(MTMPLOTHIS->OLD_TRAN_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_FACTORY, MTMPLOTHIS->OLD_FACTORY, sizeof(MTMPLOTHIS->OLD_FACTORY));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_MAT_ID, MTMPLOTHIS->OLD_MAT_ID, sizeof(MTMPLOTHIS->OLD_MAT_ID));
    MTMPLOTHIS_N->OLD_MAT_VER = MTMPLOTHIS->OLD_MAT_VER;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_FLOW, MTMPLOTHIS->OLD_FLOW, sizeof(MTMPLOTHIS->OLD_FLOW));
    MTMPLOTHIS_N->OLD_FLOW_SEQ_NUM = MTMPLOTHIS->OLD_FLOW_SEQ_NUM;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_OPER, MTMPLOTHIS->OLD_OPER, sizeof(MTMPLOTHIS->OLD_OPER));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CM_KEY_1, MTMPLOTHIS->OLD_CM_KEY_1, sizeof(MTMPLOTHIS->OLD_CM_KEY_1));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CM_KEY_2, MTMPLOTHIS->OLD_CM_KEY_2, sizeof(MTMPLOTHIS->OLD_CM_KEY_2));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CM_KEY_3, MTMPLOTHIS->OLD_CM_KEY_3, sizeof(MTMPLOTHIS->OLD_CM_KEY_3));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CM_KEY_4, MTMPLOTHIS->OLD_CM_KEY_4, sizeof(MTMPLOTHIS->OLD_CM_KEY_4));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CM_KEY_5, MTMPLOTHIS->OLD_CM_KEY_5, sizeof(MTMPLOTHIS->OLD_CM_KEY_5));
    MTMPLOTHIS_N->OLD_QTY_1 = MTMPLOTHIS->OLD_QTY_1;
    MTMPLOTHIS_N->OLD_QTY_2 = MTMPLOTHIS->OLD_QTY_2;
    MTMPLOTHIS_N->OLD_QTY_3 = MTMPLOTHIS->OLD_QTY_3;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CRR_ID, MTMPLOTHIS->OLD_CRR_ID, sizeof(MTMPLOTHIS->OLD_CRR_ID));
    MTMPLOTHIS_N->OLD_LOT_TYPE[0] = MTMPLOTHIS->OLD_LOT_TYPE;
    MTMPLOTHIS_N->OLD_LOT_PRIORITY[0] = MTMPLOTHIS->OLD_LOT_PRIORITY;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_ORDER_ID, MTMPLOTHIS->OLD_ORDER_ID, sizeof(MTMPLOTHIS->OLD_ORDER_ID));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_OWNER_CODE, MTMPLOTHIS->OLD_OWNER_CODE, sizeof(MTMPLOTHIS->OLD_OWNER_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_CREATE_CODE, MTMPLOTHIS->OLD_CREATE_CODE, sizeof(MTMPLOTHIS->OLD_CREATE_CODE));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_FAC_IN_TIME, MTMPLOTHIS->OLD_FAC_IN_TIME, sizeof(MTMPLOTHIS->OLD_FAC_IN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_FLOW_IN_TIME, MTMPLOTHIS->OLD_FLOW_IN_TIME, sizeof(MTMPLOTHIS->OLD_FLOW_IN_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_OPER_IN_TIME, MTMPLOTHIS->OLD_OPER_IN_TIME, sizeof(MTMPLOTHIS->OLD_OPER_IN_TIME));
    MTMPLOTHIS_N->OLD_RWK_FLAG[0] = MTMPLOTHIS->OLD_RWK_FLAG;
    MTMPLOTHIS_N->OLD_START_FLAG[0] = MTMPLOTHIS->OLD_START_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_START_TIME, MTMPLOTHIS->OLD_START_TIME, sizeof(MTMPLOTHIS->OLD_START_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_START_RES_ID, MTMPLOTHIS->OLD_START_RES_ID, sizeof(MTMPLOTHIS->OLD_START_RES_ID));
    MTMPLOTHIS_N->OLD_END_FLAG[0] = MTMPLOTHIS->OLD_END_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->OLD_END_TIME, MTMPLOTHIS->OLD_END_TIME, sizeof(MTMPLOTHIS->OLD_END_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->OLD_END_RES_ID, MTMPLOTHIS->OLD_END_RES_ID, sizeof(MTMPLOTHIS->OLD_END_RES_ID));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_1, MTMPLOTHIS->TRAN_CMF_1, sizeof(MTMPLOTHIS->TRAN_CMF_1));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_2, MTMPLOTHIS->TRAN_CMF_2, sizeof(MTMPLOTHIS->TRAN_CMF_2));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_3, MTMPLOTHIS->TRAN_CMF_3, sizeof(MTMPLOTHIS->TRAN_CMF_3));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_4, MTMPLOTHIS->TRAN_CMF_4, sizeof(MTMPLOTHIS->TRAN_CMF_4));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_5, MTMPLOTHIS->TRAN_CMF_5, sizeof(MTMPLOTHIS->TRAN_CMF_5));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_6, MTMPLOTHIS->TRAN_CMF_6, sizeof(MTMPLOTHIS->TRAN_CMF_6));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_7, MTMPLOTHIS->TRAN_CMF_7, sizeof(MTMPLOTHIS->TRAN_CMF_7));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_8, MTMPLOTHIS->TRAN_CMF_8, sizeof(MTMPLOTHIS->TRAN_CMF_8));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_9, MTMPLOTHIS->TRAN_CMF_9, sizeof(MTMPLOTHIS->TRAN_CMF_9));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_10, MTMPLOTHIS->TRAN_CMF_10, sizeof(MTMPLOTHIS->TRAN_CMF_10));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_11, MTMPLOTHIS->TRAN_CMF_11, sizeof(MTMPLOTHIS->TRAN_CMF_11));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_12, MTMPLOTHIS->TRAN_CMF_12, sizeof(MTMPLOTHIS->TRAN_CMF_12));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_13, MTMPLOTHIS->TRAN_CMF_13, sizeof(MTMPLOTHIS->TRAN_CMF_13));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_14, MTMPLOTHIS->TRAN_CMF_14, sizeof(MTMPLOTHIS->TRAN_CMF_14));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_15, MTMPLOTHIS->TRAN_CMF_15, sizeof(MTMPLOTHIS->TRAN_CMF_15));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_16, MTMPLOTHIS->TRAN_CMF_16, sizeof(MTMPLOTHIS->TRAN_CMF_16));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_17, MTMPLOTHIS->TRAN_CMF_17, sizeof(MTMPLOTHIS->TRAN_CMF_17));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_18, MTMPLOTHIS->TRAN_CMF_18, sizeof(MTMPLOTHIS->TRAN_CMF_18));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_19, MTMPLOTHIS->TRAN_CMF_19, sizeof(MTMPLOTHIS->TRAN_CMF_19));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_CMF_20, MTMPLOTHIS->TRAN_CMF_20, sizeof(MTMPLOTHIS->TRAN_CMF_20));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_USER_ID, MTMPLOTHIS->TRAN_USER_ID, sizeof(MTMPLOTHIS->TRAN_USER_ID));
    MEMCPY_AN(MTMPLOTHIS_N->TRAN_COMMENT, MTMPLOTHIS->TRAN_COMMENT, sizeof(MTMPLOTHIS->TRAN_COMMENT));
    MTMPLOTHIS_N->PREV_ACTIVE_HIST_SEQ = MTMPLOTHIS->PREV_ACTIVE_HIST_SEQ;
    MEMCPY_AN(MTMPLOTHIS_N->MULTI_TR_KEY, MTMPLOTHIS->MULTI_TR_KEY, sizeof(MTMPLOTHIS->MULTI_TR_KEY));
    MTMPLOTHIS_N->MULTI_TR_SEQ = MTMPLOTHIS->MULTI_TR_SEQ;
    MTMPLOTHIS_N->EXT_HIST_SEQ = MTMPLOTHIS->EXT_HIST_SEQ;
    MTMPLOTHIS_N->HIST_DEL_FLAG[0] = MTMPLOTHIS->HIST_DEL_FLAG;
    MEMCPY_AN(MTMPLOTHIS_N->HIST_DEL_TIME, MTMPLOTHIS->HIST_DEL_TIME, sizeof(MTMPLOTHIS->HIST_DEL_TIME));
    MEMCPY_AN(MTMPLOTHIS_N->HIST_DEL_USER_ID, MTMPLOTHIS->HIST_DEL_USER_ID, sizeof(MTMPLOTHIS->HIST_DEL_USER_ID));
    MEMCPY_AN(MTMPLOTHIS_N->HIST_DEL_COMMENT, MTMPLOTHIS->HIST_DEL_COMMENT, sizeof(MTMPLOTHIS->HIST_DEL_COMMENT));
    MTMPLOTHIS_N->PROCESS_FLAG[0] = MTMPLOTHIS->PROCESS_FLAG;
}


/* Del Null Function */
void DBC_del_null_mtmplothis(struct MTMPLOTHIS_N_TAG *MTMPLOTHIS_N, struct MTMPLOTHIS_TAG *MTMPLOTHIS)
{
    MTMPLOTHIS->TABLE_UPDATE_SEQ = MTMPLOTHIS_N->TABLE_UPDATE_SEQ;
    MEMCPY_DN(MTMPLOTHIS->CM_KEY_1, MTMPLOTHIS_N->CM_KEY_1, sizeof(MTMPLOTHIS->CM_KEY_1));
    MEMCPY_DN(MTMPLOTHIS->CM_KEY_2, MTMPLOTHIS_N->CM_KEY_2, sizeof(MTMPLOTHIS->CM_KEY_2));
    MEMCPY_DN(MTMPLOTHIS->CM_KEY_3, MTMPLOTHIS_N->CM_KEY_3, sizeof(MTMPLOTHIS->CM_KEY_3));
    MEMCPY_DN(MTMPLOTHIS->CM_KEY_4, MTMPLOTHIS_N->CM_KEY_4, sizeof(MTMPLOTHIS->CM_KEY_4));
    MEMCPY_DN(MTMPLOTHIS->CM_KEY_5, MTMPLOTHIS_N->CM_KEY_5, sizeof(MTMPLOTHIS->CM_KEY_5));
    MEMCPY_DN(MTMPLOTHIS->LOT_ID, MTMPLOTHIS_N->LOT_ID, sizeof(MTMPLOTHIS->LOT_ID));
    MEMCPY_DN(MTMPLOTHIS->SUB_LOT_ID, MTMPLOTHIS_N->SUB_LOT_ID, sizeof(MTMPLOTHIS->SUB_LOT_ID));
    MTMPLOTHIS->SUB_LOT_FLAG = MTMPLOTHIS_N->SUB_LOT_FLAG[0];
    MTMPLOTHIS->HIST_SEQ = MTMPLOTHIS_N->HIST_SEQ;
    MEMCPY_DN(MTMPLOTHIS->TRAN_TIME, MTMPLOTHIS_N->TRAN_TIME, sizeof(MTMPLOTHIS->TRAN_TIME));
    MEMCPY_DN(MTMPLOTHIS->SYS_TRAN_TIME, MTMPLOTHIS_N->SYS_TRAN_TIME, sizeof(MTMPLOTHIS->SYS_TRAN_TIME));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CODE, MTMPLOTHIS_N->TRAN_CODE, sizeof(MTMPLOTHIS->TRAN_CODE));
    MEMCPY_DN(MTMPLOTHIS->LOT_DESC, MTMPLOTHIS_N->LOT_DESC, sizeof(MTMPLOTHIS->LOT_DESC));
    MEMCPY_DN(MTMPLOTHIS->FACTORY, MTMPLOTHIS_N->FACTORY, sizeof(MTMPLOTHIS->FACTORY));
    MEMCPY_DN(MTMPLOTHIS->MAT_ID, MTMPLOTHIS_N->MAT_ID, sizeof(MTMPLOTHIS->MAT_ID));
    MTMPLOTHIS->MAT_VER = MTMPLOTHIS_N->MAT_VER;
    MEMCPY_DN(MTMPLOTHIS->FLOW, MTMPLOTHIS_N->FLOW, sizeof(MTMPLOTHIS->FLOW));
    MTMPLOTHIS->FLOW_SEQ_NUM = MTMPLOTHIS_N->FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->OPER, MTMPLOTHIS_N->OPER, sizeof(MTMPLOTHIS->OPER));
    MTMPLOTHIS->QTY_1 = MTMPLOTHIS_N->QTY_1;
    MTMPLOTHIS->QTY_2 = MTMPLOTHIS_N->QTY_2;
    MTMPLOTHIS->QTY_3 = MTMPLOTHIS_N->QTY_3;
    MEMCPY_DN(MTMPLOTHIS->CRR_ID, MTMPLOTHIS_N->CRR_ID, sizeof(MTMPLOTHIS->CRR_ID));
    MTMPLOTHIS->LOT_TYPE = MTMPLOTHIS_N->LOT_TYPE[0];
    MEMCPY_DN(MTMPLOTHIS->OWNER_CODE, MTMPLOTHIS_N->OWNER_CODE, sizeof(MTMPLOTHIS->OWNER_CODE));
    MEMCPY_DN(MTMPLOTHIS->CREATE_CODE, MTMPLOTHIS_N->CREATE_CODE, sizeof(MTMPLOTHIS->CREATE_CODE));
    MTMPLOTHIS->LOT_PRIORITY = MTMPLOTHIS_N->LOT_PRIORITY[0];
    MEMCPY_DN(MTMPLOTHIS->LOT_STATUS, MTMPLOTHIS_N->LOT_STATUS, sizeof(MTMPLOTHIS->LOT_STATUS));
    MTMPLOTHIS->HOLD_FLAG = MTMPLOTHIS_N->HOLD_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->HOLD_CODE, MTMPLOTHIS_N->HOLD_CODE, sizeof(MTMPLOTHIS->HOLD_CODE));
    MEMCPY_DN(MTMPLOTHIS->HOLD_PASSWORD, MTMPLOTHIS_N->HOLD_PASSWORD, sizeof(MTMPLOTHIS->HOLD_PASSWORD));
    MEMCPY_DN(MTMPLOTHIS->HOLD_PRV_GRP_ID, MTMPLOTHIS_N->HOLD_PRV_GRP_ID, sizeof(MTMPLOTHIS->HOLD_PRV_GRP_ID));
    MTMPLOTHIS->OPER_IN_QTY_1 = MTMPLOTHIS_N->OPER_IN_QTY_1;
    MTMPLOTHIS->OPER_IN_QTY_2 = MTMPLOTHIS_N->OPER_IN_QTY_2;
    MTMPLOTHIS->OPER_IN_QTY_3 = MTMPLOTHIS_N->OPER_IN_QTY_3;
    MTMPLOTHIS->CREATE_QTY_1 = MTMPLOTHIS_N->CREATE_QTY_1;
    MTMPLOTHIS->CREATE_QTY_2 = MTMPLOTHIS_N->CREATE_QTY_2;
    MTMPLOTHIS->CREATE_QTY_3 = MTMPLOTHIS_N->CREATE_QTY_3;
    MTMPLOTHIS->START_QTY_1 = MTMPLOTHIS_N->START_QTY_1;
    MTMPLOTHIS->START_QTY_2 = MTMPLOTHIS_N->START_QTY_2;
    MTMPLOTHIS->START_QTY_3 = MTMPLOTHIS_N->START_QTY_3;
    MTMPLOTHIS->INV_FLAG = MTMPLOTHIS_N->INV_FLAG[0];
    MTMPLOTHIS->TRANSIT_FLAG = MTMPLOTHIS_N->TRANSIT_FLAG[0];
    MTMPLOTHIS->UNIT_EXIST_FLAG = MTMPLOTHIS_N->UNIT_EXIST_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->INV_UNIT, MTMPLOTHIS_N->INV_UNIT, sizeof(MTMPLOTHIS->INV_UNIT));
    MTMPLOTHIS->RWK_FLAG = MTMPLOTHIS_N->RWK_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->RWK_CODE, MTMPLOTHIS_N->RWK_CODE, sizeof(MTMPLOTHIS->RWK_CODE));
    MTMPLOTHIS->RWK_COUNT = MTMPLOTHIS_N->RWK_COUNT;
    MEMCPY_DN(MTMPLOTHIS->RWK_RET_FLOW, MTMPLOTHIS_N->RWK_RET_FLOW, sizeof(MTMPLOTHIS->RWK_RET_FLOW));
    MTMPLOTHIS->RWK_RET_FLOW_SEQ_NUM = MTMPLOTHIS_N->RWK_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->RWK_RET_OPER, MTMPLOTHIS_N->RWK_RET_OPER, sizeof(MTMPLOTHIS->RWK_RET_OPER));
    MEMCPY_DN(MTMPLOTHIS->RWK_END_FLOW, MTMPLOTHIS_N->RWK_END_FLOW, sizeof(MTMPLOTHIS->RWK_END_FLOW));
    MTMPLOTHIS->RWK_END_FLOW_SEQ_NUM = MTMPLOTHIS_N->RWK_END_FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->RWK_END_OPER, MTMPLOTHIS_N->RWK_END_OPER, sizeof(MTMPLOTHIS->RWK_END_OPER));
    MTMPLOTHIS->RWK_RET_CLEAR_FLAG = MTMPLOTHIS_N->RWK_RET_CLEAR_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->RWK_TIME, MTMPLOTHIS_N->RWK_TIME, sizeof(MTMPLOTHIS->RWK_TIME));
    MTMPLOTHIS->NSTD_FLAG = MTMPLOTHIS_N->NSTD_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->NSTD_RET_FLOW, MTMPLOTHIS_N->NSTD_RET_FLOW, sizeof(MTMPLOTHIS->NSTD_RET_FLOW));
    MTMPLOTHIS->NSTD_RET_FLOW_SEQ_NUM = MTMPLOTHIS_N->NSTD_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->NSTD_RET_OPER, MTMPLOTHIS_N->NSTD_RET_OPER, sizeof(MTMPLOTHIS->NSTD_RET_OPER));
    MEMCPY_DN(MTMPLOTHIS->NSTD_TIME, MTMPLOTHIS_N->NSTD_TIME, sizeof(MTMPLOTHIS->NSTD_TIME));
    MTMPLOTHIS->REP_FLAG = MTMPLOTHIS_N->REP_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->REP_RET_OPER, MTMPLOTHIS_N->REP_RET_OPER, sizeof(MTMPLOTHIS->REP_RET_OPER));
    MEMCPY_DN(MTMPLOTHIS->STR_RET_FLOW, MTMPLOTHIS_N->STR_RET_FLOW, sizeof(MTMPLOTHIS->STR_RET_FLOW));
    MTMPLOTHIS->STR_RET_FLOW_SEQ_NUM = MTMPLOTHIS_N->STR_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->STR_RET_OPER, MTMPLOTHIS_N->STR_RET_OPER, sizeof(MTMPLOTHIS->STR_RET_OPER));
    MTMPLOTHIS->START_FLAG = MTMPLOTHIS_N->START_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->START_TIME, MTMPLOTHIS_N->START_TIME, sizeof(MTMPLOTHIS->START_TIME));
    MEMCPY_DN(MTMPLOTHIS->START_RES_ID, MTMPLOTHIS_N->START_RES_ID, sizeof(MTMPLOTHIS->START_RES_ID));
    MTMPLOTHIS->END_FLAG = MTMPLOTHIS_N->END_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->END_TIME, MTMPLOTHIS_N->END_TIME, sizeof(MTMPLOTHIS->END_TIME));
    MEMCPY_DN(MTMPLOTHIS->END_RES_ID, MTMPLOTHIS_N->END_RES_ID, sizeof(MTMPLOTHIS->END_RES_ID));
    MTMPLOTHIS->SAMPLE_FLAG = MTMPLOTHIS_N->SAMPLE_FLAG[0];
    MTMPLOTHIS->SAMPLE_WAIT_FLAG = MTMPLOTHIS_N->SAMPLE_WAIT_FLAG[0];
    MTMPLOTHIS->SAMPLE_RESULT = MTMPLOTHIS_N->SAMPLE_RESULT[0];
    MTMPLOTHIS->FROM_TO_FLAG = MTMPLOTHIS_N->FROM_TO_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->FROM_TO_LOT_ID, MTMPLOTHIS_N->FROM_TO_LOT_ID, sizeof(MTMPLOTHIS->FROM_TO_LOT_ID));
    MEMCPY_DN(MTMPLOTHIS->SHIP_CODE, MTMPLOTHIS_N->SHIP_CODE, sizeof(MTMPLOTHIS->SHIP_CODE));
    MEMCPY_DN(MTMPLOTHIS->SHIP_TIME, MTMPLOTHIS_N->SHIP_TIME, sizeof(MTMPLOTHIS->SHIP_TIME));
    MEMCPY_DN(MTMPLOTHIS->ORG_DUE_TIME, MTMPLOTHIS_N->ORG_DUE_TIME, sizeof(MTMPLOTHIS->ORG_DUE_TIME));
    MEMCPY_DN(MTMPLOTHIS->SCH_DUE_TIME, MTMPLOTHIS_N->SCH_DUE_TIME, sizeof(MTMPLOTHIS->SCH_DUE_TIME));
    MEMCPY_DN(MTMPLOTHIS->CREATE_TIME, MTMPLOTHIS_N->CREATE_TIME, sizeof(MTMPLOTHIS->CREATE_TIME));
    MEMCPY_DN(MTMPLOTHIS->FAC_IN_TIME, MTMPLOTHIS_N->FAC_IN_TIME, sizeof(MTMPLOTHIS->FAC_IN_TIME));
    MEMCPY_DN(MTMPLOTHIS->FLOW_IN_TIME, MTMPLOTHIS_N->FLOW_IN_TIME, sizeof(MTMPLOTHIS->FLOW_IN_TIME));
    MEMCPY_DN(MTMPLOTHIS->OPER_IN_TIME, MTMPLOTHIS_N->OPER_IN_TIME, sizeof(MTMPLOTHIS->OPER_IN_TIME));
    MEMCPY_DN(MTMPLOTHIS->RESERVE_RES_ID, MTMPLOTHIS_N->RESERVE_RES_ID, sizeof(MTMPLOTHIS->RESERVE_RES_ID));
    MEMCPY_DN(MTMPLOTHIS->PORT_ID, MTMPLOTHIS_N->PORT_ID, sizeof(MTMPLOTHIS->PORT_ID));
    MEMCPY_DN(MTMPLOTHIS->BATCH_ID, MTMPLOTHIS_N->BATCH_ID, sizeof(MTMPLOTHIS->BATCH_ID));
    MTMPLOTHIS->BATCH_SEQ = MTMPLOTHIS_N->BATCH_SEQ;
    MEMCPY_DN(MTMPLOTHIS->ORDER_ID, MTMPLOTHIS_N->ORDER_ID, sizeof(MTMPLOTHIS->ORDER_ID));
    MEMCPY_DN(MTMPLOTHIS->ADD_ORDER_ID_1, MTMPLOTHIS_N->ADD_ORDER_ID_1, sizeof(MTMPLOTHIS->ADD_ORDER_ID_1));
    MEMCPY_DN(MTMPLOTHIS->ADD_ORDER_ID_2, MTMPLOTHIS_N->ADD_ORDER_ID_2, sizeof(MTMPLOTHIS->ADD_ORDER_ID_2));
    MEMCPY_DN(MTMPLOTHIS->ADD_ORDER_ID_3, MTMPLOTHIS_N->ADD_ORDER_ID_3, sizeof(MTMPLOTHIS->ADD_ORDER_ID_3));
    MEMCPY_DN(MTMPLOTHIS->LOT_LOCATION_1, MTMPLOTHIS_N->LOT_LOCATION_1, sizeof(MTMPLOTHIS->LOT_LOCATION_1));
    MEMCPY_DN(MTMPLOTHIS->LOT_LOCATION_2, MTMPLOTHIS_N->LOT_LOCATION_2, sizeof(MTMPLOTHIS->LOT_LOCATION_2));
    MEMCPY_DN(MTMPLOTHIS->LOT_LOCATION_3, MTMPLOTHIS_N->LOT_LOCATION_3, sizeof(MTMPLOTHIS->LOT_LOCATION_3));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_1, MTMPLOTHIS_N->LOT_CMF_1, sizeof(MTMPLOTHIS->LOT_CMF_1));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_2, MTMPLOTHIS_N->LOT_CMF_2, sizeof(MTMPLOTHIS->LOT_CMF_2));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_3, MTMPLOTHIS_N->LOT_CMF_3, sizeof(MTMPLOTHIS->LOT_CMF_3));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_4, MTMPLOTHIS_N->LOT_CMF_4, sizeof(MTMPLOTHIS->LOT_CMF_4));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_5, MTMPLOTHIS_N->LOT_CMF_5, sizeof(MTMPLOTHIS->LOT_CMF_5));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_6, MTMPLOTHIS_N->LOT_CMF_6, sizeof(MTMPLOTHIS->LOT_CMF_6));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_7, MTMPLOTHIS_N->LOT_CMF_7, sizeof(MTMPLOTHIS->LOT_CMF_7));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_8, MTMPLOTHIS_N->LOT_CMF_8, sizeof(MTMPLOTHIS->LOT_CMF_8));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_9, MTMPLOTHIS_N->LOT_CMF_9, sizeof(MTMPLOTHIS->LOT_CMF_9));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_10, MTMPLOTHIS_N->LOT_CMF_10, sizeof(MTMPLOTHIS->LOT_CMF_10));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_11, MTMPLOTHIS_N->LOT_CMF_11, sizeof(MTMPLOTHIS->LOT_CMF_11));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_12, MTMPLOTHIS_N->LOT_CMF_12, sizeof(MTMPLOTHIS->LOT_CMF_12));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_13, MTMPLOTHIS_N->LOT_CMF_13, sizeof(MTMPLOTHIS->LOT_CMF_13));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_14, MTMPLOTHIS_N->LOT_CMF_14, sizeof(MTMPLOTHIS->LOT_CMF_14));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_15, MTMPLOTHIS_N->LOT_CMF_15, sizeof(MTMPLOTHIS->LOT_CMF_15));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_16, MTMPLOTHIS_N->LOT_CMF_16, sizeof(MTMPLOTHIS->LOT_CMF_16));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_17, MTMPLOTHIS_N->LOT_CMF_17, sizeof(MTMPLOTHIS->LOT_CMF_17));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_18, MTMPLOTHIS_N->LOT_CMF_18, sizeof(MTMPLOTHIS->LOT_CMF_18));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_19, MTMPLOTHIS_N->LOT_CMF_19, sizeof(MTMPLOTHIS->LOT_CMF_19));
    MEMCPY_DN(MTMPLOTHIS->LOT_CMF_20, MTMPLOTHIS_N->LOT_CMF_20, sizeof(MTMPLOTHIS->LOT_CMF_20));
    MTMPLOTHIS->LOT_DEL_FLAG = MTMPLOTHIS_N->LOT_DEL_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->LOT_DEL_CODE, MTMPLOTHIS_N->LOT_DEL_CODE, sizeof(MTMPLOTHIS->LOT_DEL_CODE));
    MEMCPY_DN(MTMPLOTHIS->LOT_DEL_TIME, MTMPLOTHIS_N->LOT_DEL_TIME, sizeof(MTMPLOTHIS->LOT_DEL_TIME));
    MEMCPY_DN(MTMPLOTHIS->BOM_SET_ID, MTMPLOTHIS_N->BOM_SET_ID, sizeof(MTMPLOTHIS->BOM_SET_ID));
    MTMPLOTHIS->BOM_SET_VERSION = MTMPLOTHIS_N->BOM_SET_VERSION;
    MTMPLOTHIS->BOM_ACTIVE_HIST_SEQ = MTMPLOTHIS_N->BOM_ACTIVE_HIST_SEQ;
    MTMPLOTHIS->BOM_HIST_SEQ = MTMPLOTHIS_N->BOM_HIST_SEQ;
    MEMCPY_DN(MTMPLOTHIS->CRITICAL_RES_ID, MTMPLOTHIS_N->CRITICAL_RES_ID, sizeof(MTMPLOTHIS->CRITICAL_RES_ID));
    MEMCPY_DN(MTMPLOTHIS->CRITICAL_RES_GROUP_ID, MTMPLOTHIS_N->CRITICAL_RES_GROUP_ID, sizeof(MTMPLOTHIS->CRITICAL_RES_GROUP_ID));
    MEMCPY_DN(MTMPLOTHIS->SAVE_RES_ID_1, MTMPLOTHIS_N->SAVE_RES_ID_1, sizeof(MTMPLOTHIS->SAVE_RES_ID_1));
    MEMCPY_DN(MTMPLOTHIS->SAVE_RES_ID_2, MTMPLOTHIS_N->SAVE_RES_ID_2, sizeof(MTMPLOTHIS->SAVE_RES_ID_2));
    MEMCPY_DN(MTMPLOTHIS->SUBRES_ID, MTMPLOTHIS_N->SUBRES_ID, sizeof(MTMPLOTHIS->SUBRES_ID));
    MEMCPY_DN(MTMPLOTHIS->LOT_GROUP_ID_1, MTMPLOTHIS_N->LOT_GROUP_ID_1, sizeof(MTMPLOTHIS->LOT_GROUP_ID_1));
    MEMCPY_DN(MTMPLOTHIS->LOT_GROUP_ID_2, MTMPLOTHIS_N->LOT_GROUP_ID_2, sizeof(MTMPLOTHIS->LOT_GROUP_ID_2));
    MEMCPY_DN(MTMPLOTHIS->LOT_GROUP_ID_3, MTMPLOTHIS_N->LOT_GROUP_ID_3, sizeof(MTMPLOTHIS->LOT_GROUP_ID_3));
    MTMPLOTHIS->YIELD_1 = MTMPLOTHIS_N->YIELD_1;
    MTMPLOTHIS->YIELD_2 = MTMPLOTHIS_N->YIELD_2;
    MTMPLOTHIS->YIELD_3 = MTMPLOTHIS_N->YIELD_3;
    MTMPLOTHIS->GOOD_QTY = MTMPLOTHIS_N->GOOD_QTY;
    MEMCPY_DN(MTMPLOTHIS->RESV_FIELD_1, MTMPLOTHIS_N->RESV_FIELD_1, sizeof(MTMPLOTHIS->RESV_FIELD_1));
    MEMCPY_DN(MTMPLOTHIS->RESV_FIELD_2, MTMPLOTHIS_N->RESV_FIELD_2, sizeof(MTMPLOTHIS->RESV_FIELD_2));
    MEMCPY_DN(MTMPLOTHIS->RESV_FIELD_3, MTMPLOTHIS_N->RESV_FIELD_3, sizeof(MTMPLOTHIS->RESV_FIELD_3));
    MEMCPY_DN(MTMPLOTHIS->RESV_FIELD_4, MTMPLOTHIS_N->RESV_FIELD_4, sizeof(MTMPLOTHIS->RESV_FIELD_4));
    MEMCPY_DN(MTMPLOTHIS->RESV_FIELD_5, MTMPLOTHIS_N->RESV_FIELD_5, sizeof(MTMPLOTHIS->RESV_FIELD_5));
    MTMPLOTHIS->RESV_FLAG_1 = MTMPLOTHIS_N->RESV_FLAG_1[0];
    MTMPLOTHIS->RESV_FLAG_2 = MTMPLOTHIS_N->RESV_FLAG_2[0];
    MTMPLOTHIS->RESV_FLAG_3 = MTMPLOTHIS_N->RESV_FLAG_3[0];
    MTMPLOTHIS->RESV_FLAG_4 = MTMPLOTHIS_N->RESV_FLAG_4[0];
    MTMPLOTHIS->RESV_FLAG_5 = MTMPLOTHIS_N->RESV_FLAG_5[0];
    MEMCPY_DN(MTMPLOTHIS->FROM_TO_MAT_ID, MTMPLOTHIS_N->FROM_TO_MAT_ID, sizeof(MTMPLOTHIS->FROM_TO_MAT_ID));
    MTMPLOTHIS->FROM_TO_MAT_VER = MTMPLOTHIS_N->FROM_TO_MAT_VER;
    MEMCPY_DN(MTMPLOTHIS->FROM_TO_FLOW, MTMPLOTHIS_N->FROM_TO_FLOW, sizeof(MTMPLOTHIS->FROM_TO_FLOW));
    MTMPLOTHIS->FROM_TO_FLOW_SEQ_NUM = MTMPLOTHIS_N->FROM_TO_FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->FROM_TO_OPER, MTMPLOTHIS_N->FROM_TO_OPER, sizeof(MTMPLOTHIS->FROM_TO_OPER));
    MTMPLOTHIS->FROM_TO_QTY_1 = MTMPLOTHIS_N->FROM_TO_QTY_1;
    MTMPLOTHIS->FROM_TO_QTY_2 = MTMPLOTHIS_N->FROM_TO_QTY_2;
    MTMPLOTHIS->FROM_TO_QTY_3 = MTMPLOTHIS_N->FROM_TO_QTY_3;
    MTMPLOTHIS->FROM_TO_HIST_SEQ = MTMPLOTHIS_N->FROM_TO_HIST_SEQ;
    MEMCPY_DN(MTMPLOTHIS->OLD_TRAN_TIME, MTMPLOTHIS_N->OLD_TRAN_TIME, sizeof(MTMPLOTHIS->OLD_TRAN_TIME));
    MEMCPY_DN(MTMPLOTHIS->OLD_SYS_TRAN_TIME, MTMPLOTHIS_N->OLD_SYS_TRAN_TIME, sizeof(MTMPLOTHIS->OLD_SYS_TRAN_TIME));
    MEMCPY_DN(MTMPLOTHIS->OLD_TRAN_CODE, MTMPLOTHIS_N->OLD_TRAN_CODE, sizeof(MTMPLOTHIS->OLD_TRAN_CODE));
    MEMCPY_DN(MTMPLOTHIS->OLD_FACTORY, MTMPLOTHIS_N->OLD_FACTORY, sizeof(MTMPLOTHIS->OLD_FACTORY));
    MEMCPY_DN(MTMPLOTHIS->OLD_MAT_ID, MTMPLOTHIS_N->OLD_MAT_ID, sizeof(MTMPLOTHIS->OLD_MAT_ID));
    MTMPLOTHIS->OLD_MAT_VER = MTMPLOTHIS_N->OLD_MAT_VER;
    MEMCPY_DN(MTMPLOTHIS->OLD_FLOW, MTMPLOTHIS_N->OLD_FLOW, sizeof(MTMPLOTHIS->OLD_FLOW));
    MTMPLOTHIS->OLD_FLOW_SEQ_NUM = MTMPLOTHIS_N->OLD_FLOW_SEQ_NUM;
    MEMCPY_DN(MTMPLOTHIS->OLD_OPER, MTMPLOTHIS_N->OLD_OPER, sizeof(MTMPLOTHIS->OLD_OPER));
    MEMCPY_DN(MTMPLOTHIS->OLD_CM_KEY_1, MTMPLOTHIS_N->OLD_CM_KEY_1, sizeof(MTMPLOTHIS->OLD_CM_KEY_1));
    MEMCPY_DN(MTMPLOTHIS->OLD_CM_KEY_2, MTMPLOTHIS_N->OLD_CM_KEY_2, sizeof(MTMPLOTHIS->OLD_CM_KEY_2));
    MEMCPY_DN(MTMPLOTHIS->OLD_CM_KEY_3, MTMPLOTHIS_N->OLD_CM_KEY_3, sizeof(MTMPLOTHIS->OLD_CM_KEY_3));
    MEMCPY_DN(MTMPLOTHIS->OLD_CM_KEY_4, MTMPLOTHIS_N->OLD_CM_KEY_4, sizeof(MTMPLOTHIS->OLD_CM_KEY_4));
    MEMCPY_DN(MTMPLOTHIS->OLD_CM_KEY_5, MTMPLOTHIS_N->OLD_CM_KEY_5, sizeof(MTMPLOTHIS->OLD_CM_KEY_5));
    MTMPLOTHIS->OLD_QTY_1 = MTMPLOTHIS_N->OLD_QTY_1;
    MTMPLOTHIS->OLD_QTY_2 = MTMPLOTHIS_N->OLD_QTY_2;
    MTMPLOTHIS->OLD_QTY_3 = MTMPLOTHIS_N->OLD_QTY_3;
    MEMCPY_DN(MTMPLOTHIS->OLD_CRR_ID, MTMPLOTHIS_N->OLD_CRR_ID, sizeof(MTMPLOTHIS->OLD_CRR_ID));
    MTMPLOTHIS->OLD_LOT_TYPE = MTMPLOTHIS_N->OLD_LOT_TYPE[0];
    MTMPLOTHIS->OLD_LOT_PRIORITY = MTMPLOTHIS_N->OLD_LOT_PRIORITY[0];
    MEMCPY_DN(MTMPLOTHIS->OLD_ORDER_ID, MTMPLOTHIS_N->OLD_ORDER_ID, sizeof(MTMPLOTHIS->OLD_ORDER_ID));
    MEMCPY_DN(MTMPLOTHIS->OLD_OWNER_CODE, MTMPLOTHIS_N->OLD_OWNER_CODE, sizeof(MTMPLOTHIS->OLD_OWNER_CODE));
    MEMCPY_DN(MTMPLOTHIS->OLD_CREATE_CODE, MTMPLOTHIS_N->OLD_CREATE_CODE, sizeof(MTMPLOTHIS->OLD_CREATE_CODE));
    MEMCPY_DN(MTMPLOTHIS->OLD_FAC_IN_TIME, MTMPLOTHIS_N->OLD_FAC_IN_TIME, sizeof(MTMPLOTHIS->OLD_FAC_IN_TIME));
    MEMCPY_DN(MTMPLOTHIS->OLD_FLOW_IN_TIME, MTMPLOTHIS_N->OLD_FLOW_IN_TIME, sizeof(MTMPLOTHIS->OLD_FLOW_IN_TIME));
    MEMCPY_DN(MTMPLOTHIS->OLD_OPER_IN_TIME, MTMPLOTHIS_N->OLD_OPER_IN_TIME, sizeof(MTMPLOTHIS->OLD_OPER_IN_TIME));
    MTMPLOTHIS->OLD_RWK_FLAG = MTMPLOTHIS_N->OLD_RWK_FLAG[0];
    MTMPLOTHIS->OLD_START_FLAG = MTMPLOTHIS_N->OLD_START_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->OLD_START_TIME, MTMPLOTHIS_N->OLD_START_TIME, sizeof(MTMPLOTHIS->OLD_START_TIME));
    MEMCPY_DN(MTMPLOTHIS->OLD_START_RES_ID, MTMPLOTHIS_N->OLD_START_RES_ID, sizeof(MTMPLOTHIS->OLD_START_RES_ID));
    MTMPLOTHIS->OLD_END_FLAG = MTMPLOTHIS_N->OLD_END_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->OLD_END_TIME, MTMPLOTHIS_N->OLD_END_TIME, sizeof(MTMPLOTHIS->OLD_END_TIME));
    MEMCPY_DN(MTMPLOTHIS->OLD_END_RES_ID, MTMPLOTHIS_N->OLD_END_RES_ID, sizeof(MTMPLOTHIS->OLD_END_RES_ID));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_1, MTMPLOTHIS_N->TRAN_CMF_1, sizeof(MTMPLOTHIS->TRAN_CMF_1));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_2, MTMPLOTHIS_N->TRAN_CMF_2, sizeof(MTMPLOTHIS->TRAN_CMF_2));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_3, MTMPLOTHIS_N->TRAN_CMF_3, sizeof(MTMPLOTHIS->TRAN_CMF_3));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_4, MTMPLOTHIS_N->TRAN_CMF_4, sizeof(MTMPLOTHIS->TRAN_CMF_4));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_5, MTMPLOTHIS_N->TRAN_CMF_5, sizeof(MTMPLOTHIS->TRAN_CMF_5));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_6, MTMPLOTHIS_N->TRAN_CMF_6, sizeof(MTMPLOTHIS->TRAN_CMF_6));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_7, MTMPLOTHIS_N->TRAN_CMF_7, sizeof(MTMPLOTHIS->TRAN_CMF_7));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_8, MTMPLOTHIS_N->TRAN_CMF_8, sizeof(MTMPLOTHIS->TRAN_CMF_8));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_9, MTMPLOTHIS_N->TRAN_CMF_9, sizeof(MTMPLOTHIS->TRAN_CMF_9));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_10, MTMPLOTHIS_N->TRAN_CMF_10, sizeof(MTMPLOTHIS->TRAN_CMF_10));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_11, MTMPLOTHIS_N->TRAN_CMF_11, sizeof(MTMPLOTHIS->TRAN_CMF_11));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_12, MTMPLOTHIS_N->TRAN_CMF_12, sizeof(MTMPLOTHIS->TRAN_CMF_12));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_13, MTMPLOTHIS_N->TRAN_CMF_13, sizeof(MTMPLOTHIS->TRAN_CMF_13));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_14, MTMPLOTHIS_N->TRAN_CMF_14, sizeof(MTMPLOTHIS->TRAN_CMF_14));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_15, MTMPLOTHIS_N->TRAN_CMF_15, sizeof(MTMPLOTHIS->TRAN_CMF_15));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_16, MTMPLOTHIS_N->TRAN_CMF_16, sizeof(MTMPLOTHIS->TRAN_CMF_16));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_17, MTMPLOTHIS_N->TRAN_CMF_17, sizeof(MTMPLOTHIS->TRAN_CMF_17));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_18, MTMPLOTHIS_N->TRAN_CMF_18, sizeof(MTMPLOTHIS->TRAN_CMF_18));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_19, MTMPLOTHIS_N->TRAN_CMF_19, sizeof(MTMPLOTHIS->TRAN_CMF_19));
    MEMCPY_DN(MTMPLOTHIS->TRAN_CMF_20, MTMPLOTHIS_N->TRAN_CMF_20, sizeof(MTMPLOTHIS->TRAN_CMF_20));
    MEMCPY_DN(MTMPLOTHIS->TRAN_USER_ID, MTMPLOTHIS_N->TRAN_USER_ID, sizeof(MTMPLOTHIS->TRAN_USER_ID));
    MEMCPY_DN(MTMPLOTHIS->TRAN_COMMENT, MTMPLOTHIS_N->TRAN_COMMENT, sizeof(MTMPLOTHIS->TRAN_COMMENT));
    MTMPLOTHIS->PREV_ACTIVE_HIST_SEQ = MTMPLOTHIS_N->PREV_ACTIVE_HIST_SEQ;
    MEMCPY_DN(MTMPLOTHIS->MULTI_TR_KEY, MTMPLOTHIS_N->MULTI_TR_KEY, sizeof(MTMPLOTHIS->MULTI_TR_KEY));
    MTMPLOTHIS->MULTI_TR_SEQ = MTMPLOTHIS_N->MULTI_TR_SEQ;
    MTMPLOTHIS->EXT_HIST_SEQ = MTMPLOTHIS_N->EXT_HIST_SEQ;
    MTMPLOTHIS->HIST_DEL_FLAG = MTMPLOTHIS_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MTMPLOTHIS->HIST_DEL_TIME, MTMPLOTHIS_N->HIST_DEL_TIME, sizeof(MTMPLOTHIS->HIST_DEL_TIME));
    MEMCPY_DN(MTMPLOTHIS->HIST_DEL_USER_ID, MTMPLOTHIS_N->HIST_DEL_USER_ID, sizeof(MTMPLOTHIS->HIST_DEL_USER_ID));
    MEMCPY_DN(MTMPLOTHIS->HIST_DEL_COMMENT, MTMPLOTHIS_N->HIST_DEL_COMMENT, sizeof(MTMPLOTHIS->HIST_DEL_COMMENT));
    MTMPLOTHIS->PROCESS_FLAG = MTMPLOTHIS_N->PROCESS_FLAG[0];
}

