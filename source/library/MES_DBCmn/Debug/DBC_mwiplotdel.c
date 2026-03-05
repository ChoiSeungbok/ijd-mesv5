
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
    "DBC_mwiplotdel.pc"
};


static unsigned int sqlctx = 9143627;


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
            void  *sqhstv[195];
   unsigned int   sqhstl[195];
            int   sqhsts[195];
            void  *sqindv[195];
            int   sqinds[195];
   unsigned int   sqharm[195];
   unsigned int   *sqharc[195];
   unsigned short  sqadto[195];
   unsigned short  sqtdso[195];
} sqlstm = {13,195};

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

 static const char *sq0011 = 
" ,OLD_LOT_TYPE ,OLD_OWNER_CODE ,OLD_\
CREATE_CODE ,OLD_FAC_IN_TIME ,OLD_FLOW_IN_TIME ,OLD_OPER_IN_TIME ,TRAN_CMF_1 \
,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN\
_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_\
CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN\
_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,MULTI_TR_KEY ,MULT\
I_TR_SEQ ,EXT_HIST_SEQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_\
DEL_COMMENT  from MWIPLOTDEL  order by LOT_ID asc ,HIST_SEQ asc ,SYS_TRAN_TIM\
E asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,3681,0,4,44,0,0,195,3,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,
800,0,0,2,3693,0,4,468,0,0,195,3,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,
0,0,1,3,0,0,1,97,0,0,
1595,0,0,3,102,0,4,896,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1626,0,0,4,84,0,4,905,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
1653,0,0,5,84,0,2,940,0,0,3,3,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,
1680,0,0,6,65,0,2,947,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1703,0,0,7,66,0,2,953,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1726,0,0,8,3435,0,3,982,0,0,192,192,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,
2509,0,0,9,2615,0,3,1373,0,0,1,1,0,1,0,1,97,0,0,
2528,0,0,10,3442,0,5,1596,0,0,192,192,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,3,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,
3311,0,0,11,2641,0,9,2015,0,0,0,0,0,1,0,
3326,0,0,11,0,0,13,2043,0,0,192,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,
4109,0,0,11,0,0,15,2265,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwiplotdel.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2006/03/30 18:02:57
**
**    Generated by DB Common Generator
**    Copyright (C) 1998-2005 MIRACOM,INC.
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
void DBC_add_null_mwiplotdel(struct MWIPLOTDEL_N_TAG *MWIPLOTDEL_N, struct MWIPLOTDEL_TAG *MWIPLOTDEL);
void DBC_del_null_mwiplotdel(struct MWIPLOTDEL_N_TAG *MWIPLOTDEL_N, struct MWIPLOTDEL_TAG *MWIPLOTDEL);


/* SQL SELECT Function */
void DBC_select_mwiplotdel(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         LOT_ID,
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
                         OLD_FACTORY,
                         OLD_MAT_ID,
                         OLD_MAT_VER,
                         OLD_FLOW,
                         OLD_FLOW_SEQ_NUM,
                         OLD_OPER,
                         OLD_QTY_1,
                         OLD_QTY_2,
                         OLD_QTY_3,
                         OLD_LOT_TYPE,
                         OLD_OWNER_CODE,
                         OLD_CREATE_CODE,
                         OLD_FAC_IN_TIME,
                         OLD_FLOW_IN_TIME,
                         OLD_OPER_IN_TIME,
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
                         HIST_DEL_COMMENT
                INTO 
                    :MWIPLOTDEL_N.LOT_ID,
                    :MWIPLOTDEL_N.HIST_SEQ,
                    :MWIPLOTDEL_N.TRAN_TIME,
                    :MWIPLOTDEL_N.SYS_TRAN_TIME,
                    :MWIPLOTDEL_N.TRAN_CODE,
                    :MWIPLOTDEL_N.LOT_DESC,
                    :MWIPLOTDEL_N.FACTORY,
                    :MWIPLOTDEL_N.MAT_ID,
                    :MWIPLOTDEL_N.MAT_VER,
                    :MWIPLOTDEL_N.FLOW,
                    :MWIPLOTDEL_N.FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.OPER,
                    :MWIPLOTDEL_N.QTY_1,
                    :MWIPLOTDEL_N.QTY_2,
                    :MWIPLOTDEL_N.QTY_3,
                    :MWIPLOTDEL_N.CRR_ID,
                    :MWIPLOTDEL_N.LOT_TYPE,
                    :MWIPLOTDEL_N.OWNER_CODE,
                    :MWIPLOTDEL_N.CREATE_CODE,
                    :MWIPLOTDEL_N.LOT_PRIORITY,
                    :MWIPLOTDEL_N.LOT_STATUS,
                    :MWIPLOTDEL_N.HOLD_FLAG,
                    :MWIPLOTDEL_N.HOLD_CODE,
                    :MWIPLOTDEL_N.HOLD_PASSWORD,
                    :MWIPLOTDEL_N.HOLD_PRV_GRP_ID,
                    :MWIPLOTDEL_N.OPER_IN_QTY_1,
                    :MWIPLOTDEL_N.OPER_IN_QTY_2,
                    :MWIPLOTDEL_N.OPER_IN_QTY_3,
                    :MWIPLOTDEL_N.CREATE_QTY_1,
                    :MWIPLOTDEL_N.CREATE_QTY_2,
                    :MWIPLOTDEL_N.CREATE_QTY_3,
                    :MWIPLOTDEL_N.START_QTY_1,
                    :MWIPLOTDEL_N.START_QTY_2,
                    :MWIPLOTDEL_N.START_QTY_3,
                    :MWIPLOTDEL_N.INV_FLAG,
                    :MWIPLOTDEL_N.TRANSIT_FLAG,
                    :MWIPLOTDEL_N.UNIT_EXIST_FLAG,
                    :MWIPLOTDEL_N.INV_UNIT,
                    :MWIPLOTDEL_N.RWK_FLAG,
                    :MWIPLOTDEL_N.RWK_CODE,
                    :MWIPLOTDEL_N.RWK_COUNT,
                    :MWIPLOTDEL_N.RWK_RET_FLOW,
                    :MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.RWK_RET_OPER,
                    :MWIPLOTDEL_N.RWK_END_FLOW,
                    :MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.RWK_END_OPER,
                    :MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG,
                    :MWIPLOTDEL_N.RWK_TIME,
                    :MWIPLOTDEL_N.NSTD_FLAG,
                    :MWIPLOTDEL_N.NSTD_RET_FLOW,
                    :MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.NSTD_RET_OPER,
                    :MWIPLOTDEL_N.NSTD_TIME,
                    :MWIPLOTDEL_N.REP_FLAG,
                    :MWIPLOTDEL_N.REP_RET_OPER,
                    :MWIPLOTDEL_N.STR_RET_FLOW,
                    :MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.STR_RET_OPER,
                    :MWIPLOTDEL_N.START_FLAG,
                    :MWIPLOTDEL_N.START_TIME,
                    :MWIPLOTDEL_N.START_RES_ID,
                    :MWIPLOTDEL_N.END_FLAG,
                    :MWIPLOTDEL_N.END_TIME,
                    :MWIPLOTDEL_N.END_RES_ID,
                    :MWIPLOTDEL_N.SAMPLE_FLAG,
                    :MWIPLOTDEL_N.SAMPLE_WAIT_FLAG,
                    :MWIPLOTDEL_N.SAMPLE_RESULT,
                    :MWIPLOTDEL_N.FROM_TO_FLAG,
                    :MWIPLOTDEL_N.FROM_TO_LOT_ID,
                    :MWIPLOTDEL_N.SHIP_CODE,
                    :MWIPLOTDEL_N.SHIP_TIME,
                    :MWIPLOTDEL_N.ORG_DUE_TIME,
                    :MWIPLOTDEL_N.SCH_DUE_TIME,
                    :MWIPLOTDEL_N.CREATE_TIME,
                    :MWIPLOTDEL_N.FAC_IN_TIME,
                    :MWIPLOTDEL_N.FLOW_IN_TIME,
                    :MWIPLOTDEL_N.OPER_IN_TIME,
                    :MWIPLOTDEL_N.RESERVE_RES_ID,
                    :MWIPLOTDEL_N.PORT_ID,
                    :MWIPLOTDEL_N.BATCH_ID,
                    :MWIPLOTDEL_N.BATCH_SEQ,
                    :MWIPLOTDEL_N.ORDER_ID,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_1,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_2,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_3,
                    :MWIPLOTDEL_N.LOT_LOCATION_1,
                    :MWIPLOTDEL_N.LOT_LOCATION_2,
                    :MWIPLOTDEL_N.LOT_LOCATION_3,
                    :MWIPLOTDEL_N.LOT_CMF_1,
                    :MWIPLOTDEL_N.LOT_CMF_2,
                    :MWIPLOTDEL_N.LOT_CMF_3,
                    :MWIPLOTDEL_N.LOT_CMF_4,
                    :MWIPLOTDEL_N.LOT_CMF_5,
                    :MWIPLOTDEL_N.LOT_CMF_6,
                    :MWIPLOTDEL_N.LOT_CMF_7,
                    :MWIPLOTDEL_N.LOT_CMF_8,
                    :MWIPLOTDEL_N.LOT_CMF_9,
                    :MWIPLOTDEL_N.LOT_CMF_10,
                    :MWIPLOTDEL_N.LOT_CMF_11,
                    :MWIPLOTDEL_N.LOT_CMF_12,
                    :MWIPLOTDEL_N.LOT_CMF_13,
                    :MWIPLOTDEL_N.LOT_CMF_14,
                    :MWIPLOTDEL_N.LOT_CMF_15,
                    :MWIPLOTDEL_N.LOT_CMF_16,
                    :MWIPLOTDEL_N.LOT_CMF_17,
                    :MWIPLOTDEL_N.LOT_CMF_18,
                    :MWIPLOTDEL_N.LOT_CMF_19,
                    :MWIPLOTDEL_N.LOT_CMF_20,
                    :MWIPLOTDEL_N.LOT_DEL_FLAG,
                    :MWIPLOTDEL_N.LOT_DEL_CODE,
                    :MWIPLOTDEL_N.LOT_DEL_TIME,
                    :MWIPLOTDEL_N.BOM_SET_ID,
                    :MWIPLOTDEL_N.BOM_SET_VERSION,
                    :MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ,
                    :MWIPLOTDEL_N.BOM_HIST_SEQ,
                    :MWIPLOTDEL_N.CRITICAL_RES_ID,
                    :MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID,
                    :MWIPLOTDEL_N.SAVE_RES_ID_1,
                    :MWIPLOTDEL_N.SAVE_RES_ID_2,
                    :MWIPLOTDEL_N.SUBRES_ID,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_1,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_2,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_3,
                    :MWIPLOTDEL_N.YIELD_1,
                    :MWIPLOTDEL_N.YIELD_2,
                    :MWIPLOTDEL_N.YIELD_3,
                    :MWIPLOTDEL_N.GOOD_QTY,
                    :MWIPLOTDEL_N.RESV_FIELD_1,
                    :MWIPLOTDEL_N.RESV_FIELD_2,
                    :MWIPLOTDEL_N.RESV_FIELD_3,
                    :MWIPLOTDEL_N.RESV_FIELD_4,
                    :MWIPLOTDEL_N.RESV_FIELD_5,
                    :MWIPLOTDEL_N.RESV_FLAG_1,
                    :MWIPLOTDEL_N.RESV_FLAG_2,
                    :MWIPLOTDEL_N.RESV_FLAG_3,
                    :MWIPLOTDEL_N.RESV_FLAG_4,
                    :MWIPLOTDEL_N.RESV_FLAG_5,
                    :MWIPLOTDEL_N.FROM_TO_MAT_ID,
                    :MWIPLOTDEL_N.FROM_TO_MAT_VER,
                    :MWIPLOTDEL_N.FROM_TO_FLOW,
                    :MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.FROM_TO_OPER,
                    :MWIPLOTDEL_N.FROM_TO_QTY_1,
                    :MWIPLOTDEL_N.FROM_TO_QTY_2,
                    :MWIPLOTDEL_N.FROM_TO_QTY_3,
                    :MWIPLOTDEL_N.FROM_TO_HIST_SEQ,
                    :MWIPLOTDEL_N.OLD_FACTORY,
                    :MWIPLOTDEL_N.OLD_MAT_ID,
                    :MWIPLOTDEL_N.OLD_MAT_VER,
                    :MWIPLOTDEL_N.OLD_FLOW,
                    :MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.OLD_OPER,
                    :MWIPLOTDEL_N.OLD_QTY_1,
                    :MWIPLOTDEL_N.OLD_QTY_2,
                    :MWIPLOTDEL_N.OLD_QTY_3,
                    :MWIPLOTDEL_N.OLD_LOT_TYPE,
                    :MWIPLOTDEL_N.OLD_OWNER_CODE,
                    :MWIPLOTDEL_N.OLD_CREATE_CODE,
                    :MWIPLOTDEL_N.OLD_FAC_IN_TIME,
                    :MWIPLOTDEL_N.OLD_FLOW_IN_TIME,
                    :MWIPLOTDEL_N.OLD_OPER_IN_TIME,
                    :MWIPLOTDEL_N.TRAN_CMF_1,
                    :MWIPLOTDEL_N.TRAN_CMF_2,
                    :MWIPLOTDEL_N.TRAN_CMF_3,
                    :MWIPLOTDEL_N.TRAN_CMF_4,
                    :MWIPLOTDEL_N.TRAN_CMF_5,
                    :MWIPLOTDEL_N.TRAN_CMF_6,
                    :MWIPLOTDEL_N.TRAN_CMF_7,
                    :MWIPLOTDEL_N.TRAN_CMF_8,
                    :MWIPLOTDEL_N.TRAN_CMF_9,
                    :MWIPLOTDEL_N.TRAN_CMF_10,
                    :MWIPLOTDEL_N.TRAN_CMF_11,
                    :MWIPLOTDEL_N.TRAN_CMF_12,
                    :MWIPLOTDEL_N.TRAN_CMF_13,
                    :MWIPLOTDEL_N.TRAN_CMF_14,
                    :MWIPLOTDEL_N.TRAN_CMF_15,
                    :MWIPLOTDEL_N.TRAN_CMF_16,
                    :MWIPLOTDEL_N.TRAN_CMF_17,
                    :MWIPLOTDEL_N.TRAN_CMF_18,
                    :MWIPLOTDEL_N.TRAN_CMF_19,
                    :MWIPLOTDEL_N.TRAN_CMF_20,
                    :MWIPLOTDEL_N.TRAN_USER_ID,
                    :MWIPLOTDEL_N.TRAN_COMMENT,
                    :MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ,
                    :MWIPLOTDEL_N.MULTI_TR_KEY,
                    :MWIPLOTDEL_N.MULTI_TR_SEQ,
                    :MWIPLOTDEL_N.EXT_HIST_SEQ,
                    :MWIPLOTDEL_N.HIST_DEL_FLAG,
                    :MWIPLOTDEL_N.HIST_DEL_TIME,
                    :MWIPLOTDEL_N.HIST_DEL_USER_ID,
                    :MWIPLOTDEL_N.HIST_DEL_COMMENT
                FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND HIST_SEQ = :MWIPLOTDEL_N.HIST_SEQ
                    AND SYS_TRAN_TIME = :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_CODE \
,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,QTY_1 ,QTY_2 \
,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRIORITY ,LOT_STATUS \
,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,OPER_IN_QTY_1 ,OPER_I\
N_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,CREATE_QTY_3 ,START_QTY_\
1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,UNIT_EXIST_FLAG ,INV_UN\
IT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_RET_FLOW_SEQ_NUM ,RWK_R\
ET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_OPER ,RWK_RET_CLEAR_FLA\
G ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_SEQ_NUM ,NSTD_RET_OPER \
,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR_RET_FLOW_SEQ_NUM ,STR_\
RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_FLAG ,END_TIME ,END_RES_\
ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FROM_TO_FLAG ,FROM_TO_LOT_\
ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE_TIME ,SCH_DUE_TIME ,CREATE_TIME ,FAC_IN_TI\
ME ,FLOW_IN_TIME ,OPER_IN_TIME ,RESERVE_RES_ID ,POR");
            sqlbuft((void **)0,
              "T_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDE\
R_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_2 ,LOT_LOCATION_3 ,LOT_\
CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT\
_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_1\
4 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20 ,L\
OT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,BOM_SET_VERSION ,BOM_AC\
TIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICAL_RES_GROUP_ID ,SAVE_RE\
S_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT_GROUP_ID_2 ,LOT_GROUP_\
ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_\
FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RESV_FLAG_2 ,RESV_FLAG_3 ,\
RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT_VER ,FROM_TO_FLOW ,FRO\
M_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_TO_QTY_2 ,FROM_TO_QTY_3\
 ,FROM_TO_HIST_SEQ ,OLD_FACTORY ,OLD_MAT_ID ,OLD_MAT_VER ,OLD_FLOW ,OLD_FLOW\
_SEQ_NUM ,OLD_OPER ,OLD_QTY_1 ,OLD_QTY_2 ,OLD_QTY_3");
            sqlbuft((void **)0,
              " ,OLD_LOT_TYPE ,OLD_OWNER_CODE ,OLD_CREATE_CODE ,OLD_FAC_IN_T\
IME ,OLD_FLOW_IN_TIME ,OLD_OPER_IN_TIME ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 \
,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRA\
N_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,T\
RAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID\
 ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,MULTI_TR_KEY ,MULTI_TR_SEQ ,EXT_HIST_S\
EQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT into :b\
0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b1\
7,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32\
,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,\
:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:\
b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b\
78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b9\
3,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:");
            sqlstm.stmt = "b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:\
b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b120,:b121,:b122,:b123,\
:b124,:b125,:b126,:b127,:b128,:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136\
,:b137,:b138,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b14\
9,:b150,:b151,:b152,:b153,:b154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b1\
62,:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b\
175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:\
b188,:b189,:b190,:b191  from MWIPLOTDEL where ((LOT_ID=:b0 and HIST_SEQ=:b1) \
and SYS_TRAN_TIME=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPLOTDEL_N.TRAN_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPLOTDEL_N.LOT_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPLOTDEL_N.FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPLOTDEL_N.MAT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPLOTDEL_N.MAT_VER);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPLOTDEL_N.FLOW);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPLOTDEL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPLOTDEL_N.OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPLOTDEL_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPLOTDEL_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPLOTDEL_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPLOTDEL_N.CRR_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPLOTDEL_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPLOTDEL_N.OWNER_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPLOTDEL_N.CREATE_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPLOTDEL_N.LOT_PRIORITY);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPLOTDEL_N.LOT_STATUS);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPLOTDEL_N.HOLD_FLAG);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPLOTDEL_N.HOLD_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPLOTDEL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPLOTDEL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTDEL_N.START_QTY_1);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTDEL_N.START_QTY_2);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTDEL_N.START_QTY_3);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPLOTDEL_N.INV_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPLOTDEL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPLOTDEL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPLOTDEL_N.INV_UNIT);
            sqlstm.sqhstl[37] = (unsigned int  )11;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPLOTDEL_N.RWK_FLAG);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPLOTDEL_N.RWK_CODE);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MWIPLOTDEL_N.RWK_COUNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPLOTDEL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPLOTDEL_N.RWK_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPLOTDEL_N.RWK_END_FLOW);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPLOTDEL_N.RWK_END_OPER);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPLOTDEL_N.RWK_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPLOTDEL_N.NSTD_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)&(MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[51] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPLOTDEL_N.NSTD_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPLOTDEL_N.REP_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPLOTDEL_N.REP_RET_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPLOTDEL_N.STR_RET_FLOW);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPLOTDEL_N.STR_RET_OPER);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPLOTDEL_N.START_FLAG);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPLOTDEL_N.START_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPLOTDEL_N.START_RES_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPLOTDEL_N.END_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPLOTDEL_N.END_TIME);
            sqlstm.sqhstl[63] = (unsigned int  )15;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPLOTDEL_N.END_RES_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPLOTDEL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPLOTDEL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPLOTDEL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPLOTDEL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[69] = (unsigned int  )26;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPLOTDEL_N.SHIP_CODE);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPLOTDEL_N.SHIP_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPLOTDEL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPLOTDEL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPLOTDEL_N.CREATE_TIME);
            sqlstm.sqhstl[74] = (unsigned int  )15;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPLOTDEL_N.FAC_IN_TIME);
            sqlstm.sqhstl[75] = (unsigned int  )15;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPLOTDEL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPLOTDEL_N.OPER_IN_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPLOTDEL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPLOTDEL_N.PORT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPLOTDEL_N.BATCH_ID);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPLOTDEL_N.BATCH_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPLOTDEL_N.ORDER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )26;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[83] = (unsigned int  )26;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[84] = (unsigned int  )26;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[85] = (unsigned int  )26;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_1);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_2);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_3);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_4);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_5);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_6);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_7);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_8);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_9);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_10);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_11);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_12);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_13);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_14);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_15);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_16);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_17);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_18);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_19);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_20);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[109] = (unsigned int  )2;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[110] = (unsigned int  )11;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[111] = (unsigned int  )15;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MWIPLOTDEL_N.BOM_SET_ID);
            sqlstm.sqhstl[112] = (unsigned int  )26;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)&(MWIPLOTDEL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[113] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)&(MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[114] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)&(MWIPLOTDEL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[115] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[116] = (unsigned int  )21;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[119] = (unsigned int  )21;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MWIPLOTDEL_N.SUBRES_ID);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[121] = (unsigned int  )26;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[122] = (unsigned int  )26;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[123] = (unsigned int  )26;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)&(MWIPLOTDEL_N.YIELD_1);
            sqlstm.sqhstl[124] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)&(MWIPLOTDEL_N.YIELD_2);
            sqlstm.sqhstl[125] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)&(MWIPLOTDEL_N.YIELD_3);
            sqlstm.sqhstl[126] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)&(MWIPLOTDEL_N.GOOD_QTY);
            sqlstm.sqhstl[127] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_1);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_2);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_3);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_4);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_5);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_1);
            sqlstm.sqhstl[133] = (unsigned int  )2;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_2);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_3);
            sqlstm.sqhstl[135] = (unsigned int  )2;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_4);
            sqlstm.sqhstl[136] = (unsigned int  )2;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_5);
            sqlstm.sqhstl[137] = (unsigned int  )2;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MWIPLOTDEL_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[139] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLOW);
            sqlstm.sqhstl[140] = (unsigned int  )21;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[141] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MWIPLOTDEL_N.FROM_TO_OPER);
            sqlstm.sqhstl[142] = (unsigned int  )11;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[143] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[144] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[145] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[146] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MWIPLOTDEL_N.OLD_FACTORY);
            sqlstm.sqhstl[147] = (unsigned int  )11;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MWIPLOTDEL_N.OLD_MAT_ID);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MWIPLOTDEL_N.OLD_MAT_VER);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW);
            sqlstm.sqhstl[150] = (unsigned int  )21;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MWIPLOTDEL_N.OLD_OPER);
            sqlstm.sqhstl[152] = (unsigned int  )11;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_1);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_2);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_3);
            sqlstm.sqhstl[155] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MWIPLOTDEL_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MWIPLOTDEL_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )11;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MWIPLOTDEL_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MWIPLOTDEL_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[159] = (unsigned int  )15;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[160] = (unsigned int  )15;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MWIPLOTDEL_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[161] = (unsigned int  )15;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_1);
            sqlstm.sqhstl[162] = (unsigned int  )31;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_2);
            sqlstm.sqhstl[163] = (unsigned int  )31;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_3);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_4);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_5);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_6);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_7);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_8);
            sqlstm.sqhstl[169] = (unsigned int  )31;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_9);
            sqlstm.sqhstl[170] = (unsigned int  )31;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_10);
            sqlstm.sqhstl[171] = (unsigned int  )31;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_11);
            sqlstm.sqhstl[172] = (unsigned int  )31;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_12);
            sqlstm.sqhstl[173] = (unsigned int  )31;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_13);
            sqlstm.sqhstl[174] = (unsigned int  )31;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_14);
            sqlstm.sqhstl[175] = (unsigned int  )31;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_15);
            sqlstm.sqhstl[176] = (unsigned int  )31;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_16);
            sqlstm.sqhstl[177] = (unsigned int  )31;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_17);
            sqlstm.sqhstl[178] = (unsigned int  )31;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_18);
            sqlstm.sqhstl[179] = (unsigned int  )31;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_19);
            sqlstm.sqhstl[180] = (unsigned int  )31;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_20);
            sqlstm.sqhstl[181] = (unsigned int  )31;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MWIPLOTDEL_N.TRAN_USER_ID);
            sqlstm.sqhstl[182] = (unsigned int  )21;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MWIPLOTDEL_N.TRAN_COMMENT);
            sqlstm.sqhstl[183] = (unsigned int  )401;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)&(MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[184] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MWIPLOTDEL_N.MULTI_TR_KEY);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)&(MWIPLOTDEL_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[186] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)&(MWIPLOTDEL_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[187] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[188] = (unsigned int  )2;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_TIME);
            sqlstm.sqhstl[189] = (unsigned int  )15;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[190] = (unsigned int  )21;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[191] = (unsigned int  )401;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[192] = (unsigned int  )26;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[193] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[194] = (unsigned int  )15;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
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
        DBC_del_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    }
    DB_stop_query_timer("DBC_select_mwiplotdel", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwiplotdel_for_update(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         LOT_ID,
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
                         OLD_FACTORY,
                         OLD_MAT_ID,
                         OLD_MAT_VER,
                         OLD_FLOW,
                         OLD_FLOW_SEQ_NUM,
                         OLD_OPER,
                         OLD_QTY_1,
                         OLD_QTY_2,
                         OLD_QTY_3,
                         OLD_LOT_TYPE,
                         OLD_OWNER_CODE,
                         OLD_CREATE_CODE,
                         OLD_FAC_IN_TIME,
                         OLD_FLOW_IN_TIME,
                         OLD_OPER_IN_TIME,
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
                         HIST_DEL_COMMENT
                INTO 
                    :MWIPLOTDEL_N.LOT_ID,
                    :MWIPLOTDEL_N.HIST_SEQ,
                    :MWIPLOTDEL_N.TRAN_TIME,
                    :MWIPLOTDEL_N.SYS_TRAN_TIME,
                    :MWIPLOTDEL_N.TRAN_CODE,
                    :MWIPLOTDEL_N.LOT_DESC,
                    :MWIPLOTDEL_N.FACTORY,
                    :MWIPLOTDEL_N.MAT_ID,
                    :MWIPLOTDEL_N.MAT_VER,
                    :MWIPLOTDEL_N.FLOW,
                    :MWIPLOTDEL_N.FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.OPER,
                    :MWIPLOTDEL_N.QTY_1,
                    :MWIPLOTDEL_N.QTY_2,
                    :MWIPLOTDEL_N.QTY_3,
                    :MWIPLOTDEL_N.CRR_ID,
                    :MWIPLOTDEL_N.LOT_TYPE,
                    :MWIPLOTDEL_N.OWNER_CODE,
                    :MWIPLOTDEL_N.CREATE_CODE,
                    :MWIPLOTDEL_N.LOT_PRIORITY,
                    :MWIPLOTDEL_N.LOT_STATUS,
                    :MWIPLOTDEL_N.HOLD_FLAG,
                    :MWIPLOTDEL_N.HOLD_CODE,
                    :MWIPLOTDEL_N.HOLD_PASSWORD,
                    :MWIPLOTDEL_N.HOLD_PRV_GRP_ID,
                    :MWIPLOTDEL_N.OPER_IN_QTY_1,
                    :MWIPLOTDEL_N.OPER_IN_QTY_2,
                    :MWIPLOTDEL_N.OPER_IN_QTY_3,
                    :MWIPLOTDEL_N.CREATE_QTY_1,
                    :MWIPLOTDEL_N.CREATE_QTY_2,
                    :MWIPLOTDEL_N.CREATE_QTY_3,
                    :MWIPLOTDEL_N.START_QTY_1,
                    :MWIPLOTDEL_N.START_QTY_2,
                    :MWIPLOTDEL_N.START_QTY_3,
                    :MWIPLOTDEL_N.INV_FLAG,
                    :MWIPLOTDEL_N.TRANSIT_FLAG,
                    :MWIPLOTDEL_N.UNIT_EXIST_FLAG,
                    :MWIPLOTDEL_N.INV_UNIT,
                    :MWIPLOTDEL_N.RWK_FLAG,
                    :MWIPLOTDEL_N.RWK_CODE,
                    :MWIPLOTDEL_N.RWK_COUNT,
                    :MWIPLOTDEL_N.RWK_RET_FLOW,
                    :MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.RWK_RET_OPER,
                    :MWIPLOTDEL_N.RWK_END_FLOW,
                    :MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.RWK_END_OPER,
                    :MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG,
                    :MWIPLOTDEL_N.RWK_TIME,
                    :MWIPLOTDEL_N.NSTD_FLAG,
                    :MWIPLOTDEL_N.NSTD_RET_FLOW,
                    :MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.NSTD_RET_OPER,
                    :MWIPLOTDEL_N.NSTD_TIME,
                    :MWIPLOTDEL_N.REP_FLAG,
                    :MWIPLOTDEL_N.REP_RET_OPER,
                    :MWIPLOTDEL_N.STR_RET_FLOW,
                    :MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.STR_RET_OPER,
                    :MWIPLOTDEL_N.START_FLAG,
                    :MWIPLOTDEL_N.START_TIME,
                    :MWIPLOTDEL_N.START_RES_ID,
                    :MWIPLOTDEL_N.END_FLAG,
                    :MWIPLOTDEL_N.END_TIME,
                    :MWIPLOTDEL_N.END_RES_ID,
                    :MWIPLOTDEL_N.SAMPLE_FLAG,
                    :MWIPLOTDEL_N.SAMPLE_WAIT_FLAG,
                    :MWIPLOTDEL_N.SAMPLE_RESULT,
                    :MWIPLOTDEL_N.FROM_TO_FLAG,
                    :MWIPLOTDEL_N.FROM_TO_LOT_ID,
                    :MWIPLOTDEL_N.SHIP_CODE,
                    :MWIPLOTDEL_N.SHIP_TIME,
                    :MWIPLOTDEL_N.ORG_DUE_TIME,
                    :MWIPLOTDEL_N.SCH_DUE_TIME,
                    :MWIPLOTDEL_N.CREATE_TIME,
                    :MWIPLOTDEL_N.FAC_IN_TIME,
                    :MWIPLOTDEL_N.FLOW_IN_TIME,
                    :MWIPLOTDEL_N.OPER_IN_TIME,
                    :MWIPLOTDEL_N.RESERVE_RES_ID,
                    :MWIPLOTDEL_N.PORT_ID,
                    :MWIPLOTDEL_N.BATCH_ID,
                    :MWIPLOTDEL_N.BATCH_SEQ,
                    :MWIPLOTDEL_N.ORDER_ID,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_1,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_2,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_3,
                    :MWIPLOTDEL_N.LOT_LOCATION_1,
                    :MWIPLOTDEL_N.LOT_LOCATION_2,
                    :MWIPLOTDEL_N.LOT_LOCATION_3,
                    :MWIPLOTDEL_N.LOT_CMF_1,
                    :MWIPLOTDEL_N.LOT_CMF_2,
                    :MWIPLOTDEL_N.LOT_CMF_3,
                    :MWIPLOTDEL_N.LOT_CMF_4,
                    :MWIPLOTDEL_N.LOT_CMF_5,
                    :MWIPLOTDEL_N.LOT_CMF_6,
                    :MWIPLOTDEL_N.LOT_CMF_7,
                    :MWIPLOTDEL_N.LOT_CMF_8,
                    :MWIPLOTDEL_N.LOT_CMF_9,
                    :MWIPLOTDEL_N.LOT_CMF_10,
                    :MWIPLOTDEL_N.LOT_CMF_11,
                    :MWIPLOTDEL_N.LOT_CMF_12,
                    :MWIPLOTDEL_N.LOT_CMF_13,
                    :MWIPLOTDEL_N.LOT_CMF_14,
                    :MWIPLOTDEL_N.LOT_CMF_15,
                    :MWIPLOTDEL_N.LOT_CMF_16,
                    :MWIPLOTDEL_N.LOT_CMF_17,
                    :MWIPLOTDEL_N.LOT_CMF_18,
                    :MWIPLOTDEL_N.LOT_CMF_19,
                    :MWIPLOTDEL_N.LOT_CMF_20,
                    :MWIPLOTDEL_N.LOT_DEL_FLAG,
                    :MWIPLOTDEL_N.LOT_DEL_CODE,
                    :MWIPLOTDEL_N.LOT_DEL_TIME,
                    :MWIPLOTDEL_N.BOM_SET_ID,
                    :MWIPLOTDEL_N.BOM_SET_VERSION,
                    :MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ,
                    :MWIPLOTDEL_N.BOM_HIST_SEQ,
                    :MWIPLOTDEL_N.CRITICAL_RES_ID,
                    :MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID,
                    :MWIPLOTDEL_N.SAVE_RES_ID_1,
                    :MWIPLOTDEL_N.SAVE_RES_ID_2,
                    :MWIPLOTDEL_N.SUBRES_ID,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_1,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_2,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_3,
                    :MWIPLOTDEL_N.YIELD_1,
                    :MWIPLOTDEL_N.YIELD_2,
                    :MWIPLOTDEL_N.YIELD_3,
                    :MWIPLOTDEL_N.GOOD_QTY,
                    :MWIPLOTDEL_N.RESV_FIELD_1,
                    :MWIPLOTDEL_N.RESV_FIELD_2,
                    :MWIPLOTDEL_N.RESV_FIELD_3,
                    :MWIPLOTDEL_N.RESV_FIELD_4,
                    :MWIPLOTDEL_N.RESV_FIELD_5,
                    :MWIPLOTDEL_N.RESV_FLAG_1,
                    :MWIPLOTDEL_N.RESV_FLAG_2,
                    :MWIPLOTDEL_N.RESV_FLAG_3,
                    :MWIPLOTDEL_N.RESV_FLAG_4,
                    :MWIPLOTDEL_N.RESV_FLAG_5,
                    :MWIPLOTDEL_N.FROM_TO_MAT_ID,
                    :MWIPLOTDEL_N.FROM_TO_MAT_VER,
                    :MWIPLOTDEL_N.FROM_TO_FLOW,
                    :MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.FROM_TO_OPER,
                    :MWIPLOTDEL_N.FROM_TO_QTY_1,
                    :MWIPLOTDEL_N.FROM_TO_QTY_2,
                    :MWIPLOTDEL_N.FROM_TO_QTY_3,
                    :MWIPLOTDEL_N.FROM_TO_HIST_SEQ,
                    :MWIPLOTDEL_N.OLD_FACTORY,
                    :MWIPLOTDEL_N.OLD_MAT_ID,
                    :MWIPLOTDEL_N.OLD_MAT_VER,
                    :MWIPLOTDEL_N.OLD_FLOW,
                    :MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.OLD_OPER,
                    :MWIPLOTDEL_N.OLD_QTY_1,
                    :MWIPLOTDEL_N.OLD_QTY_2,
                    :MWIPLOTDEL_N.OLD_QTY_3,
                    :MWIPLOTDEL_N.OLD_LOT_TYPE,
                    :MWIPLOTDEL_N.OLD_OWNER_CODE,
                    :MWIPLOTDEL_N.OLD_CREATE_CODE,
                    :MWIPLOTDEL_N.OLD_FAC_IN_TIME,
                    :MWIPLOTDEL_N.OLD_FLOW_IN_TIME,
                    :MWIPLOTDEL_N.OLD_OPER_IN_TIME,
                    :MWIPLOTDEL_N.TRAN_CMF_1,
                    :MWIPLOTDEL_N.TRAN_CMF_2,
                    :MWIPLOTDEL_N.TRAN_CMF_3,
                    :MWIPLOTDEL_N.TRAN_CMF_4,
                    :MWIPLOTDEL_N.TRAN_CMF_5,
                    :MWIPLOTDEL_N.TRAN_CMF_6,
                    :MWIPLOTDEL_N.TRAN_CMF_7,
                    :MWIPLOTDEL_N.TRAN_CMF_8,
                    :MWIPLOTDEL_N.TRAN_CMF_9,
                    :MWIPLOTDEL_N.TRAN_CMF_10,
                    :MWIPLOTDEL_N.TRAN_CMF_11,
                    :MWIPLOTDEL_N.TRAN_CMF_12,
                    :MWIPLOTDEL_N.TRAN_CMF_13,
                    :MWIPLOTDEL_N.TRAN_CMF_14,
                    :MWIPLOTDEL_N.TRAN_CMF_15,
                    :MWIPLOTDEL_N.TRAN_CMF_16,
                    :MWIPLOTDEL_N.TRAN_CMF_17,
                    :MWIPLOTDEL_N.TRAN_CMF_18,
                    :MWIPLOTDEL_N.TRAN_CMF_19,
                    :MWIPLOTDEL_N.TRAN_CMF_20,
                    :MWIPLOTDEL_N.TRAN_USER_ID,
                    :MWIPLOTDEL_N.TRAN_COMMENT,
                    :MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ,
                    :MWIPLOTDEL_N.MULTI_TR_KEY,
                    :MWIPLOTDEL_N.MULTI_TR_SEQ,
                    :MWIPLOTDEL_N.EXT_HIST_SEQ,
                    :MWIPLOTDEL_N.HIST_DEL_FLAG,
                    :MWIPLOTDEL_N.HIST_DEL_TIME,
                    :MWIPLOTDEL_N.HIST_DEL_USER_ID,
                    :MWIPLOTDEL_N.HIST_DEL_COMMENT
                FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND HIST_SEQ = :MWIPLOTDEL_N.HIST_SEQ
                    AND SYS_TRAN_TIME = :MWIPLOTDEL_N.SYS_TRAN_TIME
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_CODE \
,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,QTY_1 ,QTY_2 \
,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRIORITY ,LOT_STATUS \
,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,OPER_IN_QTY_1 ,OPER_I\
N_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,CREATE_QTY_3 ,START_QTY_\
1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,UNIT_EXIST_FLAG ,INV_UN\
IT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_RET_FLOW_SEQ_NUM ,RWK_R\
ET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_OPER ,RWK_RET_CLEAR_FLA\
G ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_SEQ_NUM ,NSTD_RET_OPER \
,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR_RET_FLOW_SEQ_NUM ,STR_\
RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_FLAG ,END_TIME ,END_RES_\
ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FROM_TO_FLAG ,FROM_TO_LOT_\
ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE_TIME ,SCH_DUE_TIME ,CREATE_TIME ,FAC_IN_TI\
ME ,FLOW_IN_TIME ,OPER_IN_TIME ,RESERVE_RES_ID ,POR");
            sqlbuft((void **)0,
              "T_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDE\
R_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_2 ,LOT_LOCATION_3 ,LOT_\
CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT\
_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_1\
4 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20 ,L\
OT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,BOM_SET_VERSION ,BOM_AC\
TIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICAL_RES_GROUP_ID ,SAVE_RE\
S_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT_GROUP_ID_2 ,LOT_GROUP_\
ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_\
FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RESV_FLAG_2 ,RESV_FLAG_3 ,\
RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT_VER ,FROM_TO_FLOW ,FRO\
M_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_TO_QTY_2 ,FROM_TO_QTY_3\
 ,FROM_TO_HIST_SEQ ,OLD_FACTORY ,OLD_MAT_ID ,OLD_MAT_VER ,OLD_FLOW ,OLD_FLOW\
_SEQ_NUM ,OLD_OPER ,OLD_QTY_1 ,OLD_QTY_2 ,OLD_QTY_3");
            sqlbuft((void **)0,
              " ,OLD_LOT_TYPE ,OLD_OWNER_CODE ,OLD_CREATE_CODE ,OLD_FAC_IN_T\
IME ,OLD_FLOW_IN_TIME ,OLD_OPER_IN_TIME ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 \
,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRA\
N_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CMF_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,T\
RAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_CMF_19 ,TRAN_CMF_20 ,TRAN_USER_ID\
 ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,MULTI_TR_KEY ,MULTI_TR_SEQ ,EXT_HIST_S\
EQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USER_ID ,HIST_DEL_COMMENT into :b\
0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b1\
7,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32\
,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,\
:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:\
b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b\
78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b9\
3,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:");
            sqlstm.stmt = "b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:\
b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b120,:b121,:b122,:b123,\
:b124,:b125,:b126,:b127,:b128,:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136\
,:b137,:b138,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b14\
9,:b150,:b151,:b152,:b153,:b154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b1\
62,:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b\
175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:\
b188,:b189,:b190,:b191  from MWIPLOTDEL where ((LOT_ID=:b0 and HIST_SEQ=:b1) \
and SYS_TRAN_TIME=:b3) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )800;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPLOTDEL_N.TRAN_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPLOTDEL_N.LOT_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPLOTDEL_N.FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPLOTDEL_N.MAT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPLOTDEL_N.MAT_VER);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPLOTDEL_N.FLOW);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPLOTDEL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPLOTDEL_N.OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPLOTDEL_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPLOTDEL_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPLOTDEL_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPLOTDEL_N.CRR_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPLOTDEL_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPLOTDEL_N.OWNER_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPLOTDEL_N.CREATE_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPLOTDEL_N.LOT_PRIORITY);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPLOTDEL_N.LOT_STATUS);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPLOTDEL_N.HOLD_FLAG);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPLOTDEL_N.HOLD_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPLOTDEL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPLOTDEL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTDEL_N.START_QTY_1);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTDEL_N.START_QTY_2);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTDEL_N.START_QTY_3);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPLOTDEL_N.INV_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPLOTDEL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPLOTDEL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPLOTDEL_N.INV_UNIT);
            sqlstm.sqhstl[37] = (unsigned int  )11;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPLOTDEL_N.RWK_FLAG);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPLOTDEL_N.RWK_CODE);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MWIPLOTDEL_N.RWK_COUNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPLOTDEL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPLOTDEL_N.RWK_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPLOTDEL_N.RWK_END_FLOW);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPLOTDEL_N.RWK_END_OPER);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPLOTDEL_N.RWK_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPLOTDEL_N.NSTD_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)&(MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[51] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPLOTDEL_N.NSTD_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPLOTDEL_N.REP_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPLOTDEL_N.REP_RET_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPLOTDEL_N.STR_RET_FLOW);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPLOTDEL_N.STR_RET_OPER);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPLOTDEL_N.START_FLAG);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPLOTDEL_N.START_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPLOTDEL_N.START_RES_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPLOTDEL_N.END_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPLOTDEL_N.END_TIME);
            sqlstm.sqhstl[63] = (unsigned int  )15;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPLOTDEL_N.END_RES_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPLOTDEL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPLOTDEL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPLOTDEL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPLOTDEL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[69] = (unsigned int  )26;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPLOTDEL_N.SHIP_CODE);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPLOTDEL_N.SHIP_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPLOTDEL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPLOTDEL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPLOTDEL_N.CREATE_TIME);
            sqlstm.sqhstl[74] = (unsigned int  )15;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPLOTDEL_N.FAC_IN_TIME);
            sqlstm.sqhstl[75] = (unsigned int  )15;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPLOTDEL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPLOTDEL_N.OPER_IN_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPLOTDEL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPLOTDEL_N.PORT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPLOTDEL_N.BATCH_ID);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPLOTDEL_N.BATCH_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPLOTDEL_N.ORDER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )26;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[83] = (unsigned int  )26;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[84] = (unsigned int  )26;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[85] = (unsigned int  )26;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_1);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_2);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_3);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_4);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_5);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_6);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_7);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_8);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_9);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_10);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_11);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_12);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_13);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_14);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_15);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_16);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_17);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_18);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_19);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_20);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[109] = (unsigned int  )2;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[110] = (unsigned int  )11;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[111] = (unsigned int  )15;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MWIPLOTDEL_N.BOM_SET_ID);
            sqlstm.sqhstl[112] = (unsigned int  )26;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)&(MWIPLOTDEL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[113] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)&(MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[114] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)&(MWIPLOTDEL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[115] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[116] = (unsigned int  )21;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[119] = (unsigned int  )21;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MWIPLOTDEL_N.SUBRES_ID);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[121] = (unsigned int  )26;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[122] = (unsigned int  )26;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[123] = (unsigned int  )26;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)&(MWIPLOTDEL_N.YIELD_1);
            sqlstm.sqhstl[124] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)&(MWIPLOTDEL_N.YIELD_2);
            sqlstm.sqhstl[125] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)&(MWIPLOTDEL_N.YIELD_3);
            sqlstm.sqhstl[126] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)&(MWIPLOTDEL_N.GOOD_QTY);
            sqlstm.sqhstl[127] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_1);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_2);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_3);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_4);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_5);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_1);
            sqlstm.sqhstl[133] = (unsigned int  )2;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_2);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_3);
            sqlstm.sqhstl[135] = (unsigned int  )2;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_4);
            sqlstm.sqhstl[136] = (unsigned int  )2;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_5);
            sqlstm.sqhstl[137] = (unsigned int  )2;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MWIPLOTDEL_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[139] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLOW);
            sqlstm.sqhstl[140] = (unsigned int  )21;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[141] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MWIPLOTDEL_N.FROM_TO_OPER);
            sqlstm.sqhstl[142] = (unsigned int  )11;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[143] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[144] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[145] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[146] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MWIPLOTDEL_N.OLD_FACTORY);
            sqlstm.sqhstl[147] = (unsigned int  )11;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MWIPLOTDEL_N.OLD_MAT_ID);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MWIPLOTDEL_N.OLD_MAT_VER);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW);
            sqlstm.sqhstl[150] = (unsigned int  )21;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MWIPLOTDEL_N.OLD_OPER);
            sqlstm.sqhstl[152] = (unsigned int  )11;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_1);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_2);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_3);
            sqlstm.sqhstl[155] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MWIPLOTDEL_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MWIPLOTDEL_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )11;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MWIPLOTDEL_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MWIPLOTDEL_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[159] = (unsigned int  )15;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[160] = (unsigned int  )15;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MWIPLOTDEL_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[161] = (unsigned int  )15;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_1);
            sqlstm.sqhstl[162] = (unsigned int  )31;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_2);
            sqlstm.sqhstl[163] = (unsigned int  )31;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_3);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_4);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_5);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_6);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_7);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_8);
            sqlstm.sqhstl[169] = (unsigned int  )31;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_9);
            sqlstm.sqhstl[170] = (unsigned int  )31;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_10);
            sqlstm.sqhstl[171] = (unsigned int  )31;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_11);
            sqlstm.sqhstl[172] = (unsigned int  )31;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_12);
            sqlstm.sqhstl[173] = (unsigned int  )31;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_13);
            sqlstm.sqhstl[174] = (unsigned int  )31;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_14);
            sqlstm.sqhstl[175] = (unsigned int  )31;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_15);
            sqlstm.sqhstl[176] = (unsigned int  )31;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_16);
            sqlstm.sqhstl[177] = (unsigned int  )31;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_17);
            sqlstm.sqhstl[178] = (unsigned int  )31;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_18);
            sqlstm.sqhstl[179] = (unsigned int  )31;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_19);
            sqlstm.sqhstl[180] = (unsigned int  )31;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_20);
            sqlstm.sqhstl[181] = (unsigned int  )31;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MWIPLOTDEL_N.TRAN_USER_ID);
            sqlstm.sqhstl[182] = (unsigned int  )21;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MWIPLOTDEL_N.TRAN_COMMENT);
            sqlstm.sqhstl[183] = (unsigned int  )401;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)&(MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[184] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MWIPLOTDEL_N.MULTI_TR_KEY);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)&(MWIPLOTDEL_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[186] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)&(MWIPLOTDEL_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[187] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[188] = (unsigned int  )2;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_TIME);
            sqlstm.sqhstl[189] = (unsigned int  )15;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[190] = (unsigned int  )21;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[191] = (unsigned int  )401;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[192] = (unsigned int  )26;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[193] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[194] = (unsigned int  )15;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
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
        DBC_del_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    }
    DB_stop_query_timer("DBC_select_mwiplotdel_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwiplotdel_scalar(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    

    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND HIST_SEQ = :MWIPLOTDEL_N.HIST_SEQ
                    AND SYS_TRAN_TIME = :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPLOTDEL where\
 ((LOT_ID=:b1 and HIST_SEQ=:b2) and SYS_TRAN_TIME=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1595;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
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

        case 2: /* Add by J.S. 2011.10.04 for dllh */
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND SYS_TRAN_TIME >= :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPLOTDEL where\
 (LOT_ID=:b1 and SYS_TRAN_TIME>=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1626;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
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

    DB_stop_query_timer("DBC_select_mwiplotdel_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwiplotdel(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND HIST_SEQ = :MWIPLOTDEL_N.HIST_SEQ
                    AND SYS_TRAN_TIME = :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPLOTDEL  where ((LOT_ID=:b0 and \
HIST_SEQ=:b1) and SYS_TRAN_TIME=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1653;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
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
            /* EXEC SQL DELETE FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND SYS_TRAN_TIME = :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPLOTDEL  where (LOT_ID=:b0 and S\
YS_TRAN_TIME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1680;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
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

        case 3: /* Add by J.S. 2011.10.04 for dllh */
            /* EXEC SQL DELETE FROM MWIPLOTDEL
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND SYS_TRAN_TIME >= :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPLOTDEL  where (LOT_ID=:b0 and S\
YS_TRAN_TIME>=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1703;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[1] = (unsigned int  )15;
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
    DB_stop_query_timer("DBC_delete_mwiplotdel", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwiplotdel(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL INSERT INTO MWIPLOTDEL (
                    LOT_ID,
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
                    OLD_FACTORY,
                    OLD_MAT_ID,
                    OLD_MAT_VER,
                    OLD_FLOW,
                    OLD_FLOW_SEQ_NUM,
                    OLD_OPER,
                    OLD_QTY_1,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_LOT_TYPE,
                    OLD_OWNER_CODE,
                    OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME,
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
                    HIST_DEL_COMMENT
        )
        VALUES (
                    :MWIPLOTDEL_N.LOT_ID,
                    :MWIPLOTDEL_N.HIST_SEQ,
                    :MWIPLOTDEL_N.TRAN_TIME,
                    :MWIPLOTDEL_N.SYS_TRAN_TIME,
                    :MWIPLOTDEL_N.TRAN_CODE,
                    :MWIPLOTDEL_N.LOT_DESC,
                    :MWIPLOTDEL_N.FACTORY,
                    :MWIPLOTDEL_N.MAT_ID,
                    :MWIPLOTDEL_N.MAT_VER,
                    :MWIPLOTDEL_N.FLOW,
                    :MWIPLOTDEL_N.FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.OPER,
                    :MWIPLOTDEL_N.QTY_1,
                    :MWIPLOTDEL_N.QTY_2,
                    :MWIPLOTDEL_N.QTY_3,
                    :MWIPLOTDEL_N.CRR_ID,
                    :MWIPLOTDEL_N.LOT_TYPE,
                    :MWIPLOTDEL_N.OWNER_CODE,
                    :MWIPLOTDEL_N.CREATE_CODE,
                    :MWIPLOTDEL_N.LOT_PRIORITY,
                    :MWIPLOTDEL_N.LOT_STATUS,
                    :MWIPLOTDEL_N.HOLD_FLAG,
                    :MWIPLOTDEL_N.HOLD_CODE,
                    :MWIPLOTDEL_N.HOLD_PASSWORD,
                    :MWIPLOTDEL_N.HOLD_PRV_GRP_ID,
                    :MWIPLOTDEL_N.OPER_IN_QTY_1,
                    :MWIPLOTDEL_N.OPER_IN_QTY_2,
                    :MWIPLOTDEL_N.OPER_IN_QTY_3,
                    :MWIPLOTDEL_N.CREATE_QTY_1,
                    :MWIPLOTDEL_N.CREATE_QTY_2,
                    :MWIPLOTDEL_N.CREATE_QTY_3,
                    :MWIPLOTDEL_N.START_QTY_1,
                    :MWIPLOTDEL_N.START_QTY_2,
                    :MWIPLOTDEL_N.START_QTY_3,
                    :MWIPLOTDEL_N.INV_FLAG,
                    :MWIPLOTDEL_N.TRANSIT_FLAG,
                    :MWIPLOTDEL_N.UNIT_EXIST_FLAG,
                    :MWIPLOTDEL_N.INV_UNIT,
                    :MWIPLOTDEL_N.RWK_FLAG,
                    :MWIPLOTDEL_N.RWK_CODE,
                    :MWIPLOTDEL_N.RWK_COUNT,
                    :MWIPLOTDEL_N.RWK_RET_FLOW,
                    :MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.RWK_RET_OPER,
                    :MWIPLOTDEL_N.RWK_END_FLOW,
                    :MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.RWK_END_OPER,
                    :MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG,
                    :MWIPLOTDEL_N.RWK_TIME,
                    :MWIPLOTDEL_N.NSTD_FLAG,
                    :MWIPLOTDEL_N.NSTD_RET_FLOW,
                    :MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.NSTD_RET_OPER,
                    :MWIPLOTDEL_N.NSTD_TIME,
                    :MWIPLOTDEL_N.REP_FLAG,
                    :MWIPLOTDEL_N.REP_RET_OPER,
                    :MWIPLOTDEL_N.STR_RET_FLOW,
                    :MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.STR_RET_OPER,
                    :MWIPLOTDEL_N.START_FLAG,
                    :MWIPLOTDEL_N.START_TIME,
                    :MWIPLOTDEL_N.START_RES_ID,
                    :MWIPLOTDEL_N.END_FLAG,
                    :MWIPLOTDEL_N.END_TIME,
                    :MWIPLOTDEL_N.END_RES_ID,
                    :MWIPLOTDEL_N.SAMPLE_FLAG,
                    :MWIPLOTDEL_N.SAMPLE_WAIT_FLAG,
                    :MWIPLOTDEL_N.SAMPLE_RESULT,
                    :MWIPLOTDEL_N.FROM_TO_FLAG,
                    :MWIPLOTDEL_N.FROM_TO_LOT_ID,
                    :MWIPLOTDEL_N.SHIP_CODE,
                    :MWIPLOTDEL_N.SHIP_TIME,
                    :MWIPLOTDEL_N.ORG_DUE_TIME,
                    :MWIPLOTDEL_N.SCH_DUE_TIME,
                    :MWIPLOTDEL_N.CREATE_TIME,
                    :MWIPLOTDEL_N.FAC_IN_TIME,
                    :MWIPLOTDEL_N.FLOW_IN_TIME,
                    :MWIPLOTDEL_N.OPER_IN_TIME,
                    :MWIPLOTDEL_N.RESERVE_RES_ID,
                    :MWIPLOTDEL_N.PORT_ID,
                    :MWIPLOTDEL_N.BATCH_ID,
                    :MWIPLOTDEL_N.BATCH_SEQ,
                    :MWIPLOTDEL_N.ORDER_ID,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_1,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_2,
                    :MWIPLOTDEL_N.ADD_ORDER_ID_3,
                    :MWIPLOTDEL_N.LOT_LOCATION_1,
                    :MWIPLOTDEL_N.LOT_LOCATION_2,
                    :MWIPLOTDEL_N.LOT_LOCATION_3,
                    :MWIPLOTDEL_N.LOT_CMF_1,
                    :MWIPLOTDEL_N.LOT_CMF_2,
                    :MWIPLOTDEL_N.LOT_CMF_3,
                    :MWIPLOTDEL_N.LOT_CMF_4,
                    :MWIPLOTDEL_N.LOT_CMF_5,
                    :MWIPLOTDEL_N.LOT_CMF_6,
                    :MWIPLOTDEL_N.LOT_CMF_7,
                    :MWIPLOTDEL_N.LOT_CMF_8,
                    :MWIPLOTDEL_N.LOT_CMF_9,
                    :MWIPLOTDEL_N.LOT_CMF_10,
                    :MWIPLOTDEL_N.LOT_CMF_11,
                    :MWIPLOTDEL_N.LOT_CMF_12,
                    :MWIPLOTDEL_N.LOT_CMF_13,
                    :MWIPLOTDEL_N.LOT_CMF_14,
                    :MWIPLOTDEL_N.LOT_CMF_15,
                    :MWIPLOTDEL_N.LOT_CMF_16,
                    :MWIPLOTDEL_N.LOT_CMF_17,
                    :MWIPLOTDEL_N.LOT_CMF_18,
                    :MWIPLOTDEL_N.LOT_CMF_19,
                    :MWIPLOTDEL_N.LOT_CMF_20,
                    :MWIPLOTDEL_N.LOT_DEL_FLAG,
                    :MWIPLOTDEL_N.LOT_DEL_CODE,
                    :MWIPLOTDEL_N.LOT_DEL_TIME,
                    :MWIPLOTDEL_N.BOM_SET_ID,
                    :MWIPLOTDEL_N.BOM_SET_VERSION,
                    :MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ,
                    :MWIPLOTDEL_N.BOM_HIST_SEQ,
                    :MWIPLOTDEL_N.CRITICAL_RES_ID,
                    :MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID,
                    :MWIPLOTDEL_N.SAVE_RES_ID_1,
                    :MWIPLOTDEL_N.SAVE_RES_ID_2,
                    :MWIPLOTDEL_N.SUBRES_ID,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_1,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_2,
                    :MWIPLOTDEL_N.LOT_GROUP_ID_3,
                    :MWIPLOTDEL_N.YIELD_1,
                    :MWIPLOTDEL_N.YIELD_2,
                    :MWIPLOTDEL_N.YIELD_3,
                    :MWIPLOTDEL_N.GOOD_QTY,
                    :MWIPLOTDEL_N.RESV_FIELD_1,
                    :MWIPLOTDEL_N.RESV_FIELD_2,
                    :MWIPLOTDEL_N.RESV_FIELD_3,
                    :MWIPLOTDEL_N.RESV_FIELD_4,
                    :MWIPLOTDEL_N.RESV_FIELD_5,
                    :MWIPLOTDEL_N.RESV_FLAG_1,
                    :MWIPLOTDEL_N.RESV_FLAG_2,
                    :MWIPLOTDEL_N.RESV_FLAG_3,
                    :MWIPLOTDEL_N.RESV_FLAG_4,
                    :MWIPLOTDEL_N.RESV_FLAG_5,
                    :MWIPLOTDEL_N.FROM_TO_MAT_ID,
                    :MWIPLOTDEL_N.FROM_TO_MAT_VER,
                    :MWIPLOTDEL_N.FROM_TO_FLOW,
                    :MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.FROM_TO_OPER,
                    :MWIPLOTDEL_N.FROM_TO_QTY_1,
                    :MWIPLOTDEL_N.FROM_TO_QTY_2,
                    :MWIPLOTDEL_N.FROM_TO_QTY_3,
                    :MWIPLOTDEL_N.FROM_TO_HIST_SEQ,
                    :MWIPLOTDEL_N.OLD_FACTORY,
                    :MWIPLOTDEL_N.OLD_MAT_ID,
                    :MWIPLOTDEL_N.OLD_MAT_VER,
                    :MWIPLOTDEL_N.OLD_FLOW,
                    :MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM,
                    :MWIPLOTDEL_N.OLD_OPER,
                    :MWIPLOTDEL_N.OLD_QTY_1,
                    :MWIPLOTDEL_N.OLD_QTY_2,
                    :MWIPLOTDEL_N.OLD_QTY_3,
                    :MWIPLOTDEL_N.OLD_LOT_TYPE,
                    :MWIPLOTDEL_N.OLD_OWNER_CODE,
                    :MWIPLOTDEL_N.OLD_CREATE_CODE,
                    :MWIPLOTDEL_N.OLD_FAC_IN_TIME,
                    :MWIPLOTDEL_N.OLD_FLOW_IN_TIME,
                    :MWIPLOTDEL_N.OLD_OPER_IN_TIME,
                    :MWIPLOTDEL_N.TRAN_CMF_1,
                    :MWIPLOTDEL_N.TRAN_CMF_2,
                    :MWIPLOTDEL_N.TRAN_CMF_3,
                    :MWIPLOTDEL_N.TRAN_CMF_4,
                    :MWIPLOTDEL_N.TRAN_CMF_5,
                    :MWIPLOTDEL_N.TRAN_CMF_6,
                    :MWIPLOTDEL_N.TRAN_CMF_7,
                    :MWIPLOTDEL_N.TRAN_CMF_8,
                    :MWIPLOTDEL_N.TRAN_CMF_9,
                    :MWIPLOTDEL_N.TRAN_CMF_10,
                    :MWIPLOTDEL_N.TRAN_CMF_11,
                    :MWIPLOTDEL_N.TRAN_CMF_12,
                    :MWIPLOTDEL_N.TRAN_CMF_13,
                    :MWIPLOTDEL_N.TRAN_CMF_14,
                    :MWIPLOTDEL_N.TRAN_CMF_15,
                    :MWIPLOTDEL_N.TRAN_CMF_16,
                    :MWIPLOTDEL_N.TRAN_CMF_17,
                    :MWIPLOTDEL_N.TRAN_CMF_18,
                    :MWIPLOTDEL_N.TRAN_CMF_19,
                    :MWIPLOTDEL_N.TRAN_CMF_20,
                    :MWIPLOTDEL_N.TRAN_USER_ID,
                    :MWIPLOTDEL_N.TRAN_COMMENT,
                    :MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ,
                    :MWIPLOTDEL_N.MULTI_TR_KEY,
                    :MWIPLOTDEL_N.MULTI_TR_SEQ,
                    :MWIPLOTDEL_N.EXT_HIST_SEQ,
                    :MWIPLOTDEL_N.HIST_DEL_FLAG,
                    :MWIPLOTDEL_N.HIST_DEL_TIME,
                    :MWIPLOTDEL_N.HIST_DEL_USER_ID,
                    :MWIPLOTDEL_N.HIST_DEL_COMMENT
        ); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "insert into MWIPLOTDEL (LOT_ID,HIST_SEQ,TRAN_TIME,SYS_TRAN_TI\
ME,TRAN_CODE,LOT_DESC,FACTORY,MAT_ID,MAT_VER,FLOW,FLOW_SEQ_NUM,OPER,QTY_1,QT\
Y_2,QTY_3,CRR_ID,LOT_TYPE,OWNER_CODE,CREATE_CODE,LOT_PRIORITY,LOT_STATUS,HOL\
D_FLAG,HOLD_CODE,HOLD_PASSWORD,HOLD_PRV_GRP_ID,OPER_IN_QTY_1,OPER_IN_QTY_2,O\
PER_IN_QTY_3,CREATE_QTY_1,CREATE_QTY_2,CREATE_QTY_3,START_QTY_1,START_QTY_2,\
START_QTY_3,INV_FLAG,TRANSIT_FLAG,UNIT_EXIST_FLAG,INV_UNIT,RWK_FLAG,RWK_CODE\
,RWK_COUNT,RWK_RET_FLOW,RWK_RET_FLOW_SEQ_NUM,RWK_RET_OPER,RWK_END_FLOW,RWK_E\
ND_FLOW_SEQ_NUM,RWK_END_OPER,RWK_RET_CLEAR_FLAG,RWK_TIME,NSTD_FLAG,NSTD_RET_\
FLOW,NSTD_RET_FLOW_SEQ_NUM,NSTD_RET_OPER,NSTD_TIME,REP_FLAG,REP_RET_OPER,STR\
_RET_FLOW,STR_RET_FLOW_SEQ_NUM,STR_RET_OPER,START_FLAG,START_TIME,START_RES_\
ID,END_FLAG,END_TIME,END_RES_ID,SAMPLE_FLAG,SAMPLE_WAIT_FLAG,SAMPLE_RESULT,F\
ROM_TO_FLAG,FROM_TO_LOT_ID,SHIP_CODE,SHIP_TIME,ORG_DUE_TIME,SCH_DUE_TIME,CRE\
ATE_TIME,FAC_IN_TIME,FLOW_IN_TIME,OPER_IN_TIME,RESERVE_RES_ID,PORT_ID,BATCH_\
ID,BATCH_SEQ,ORDER_ID,ADD_ORDER_ID_1,ADD_ORDER_ID_2");
            sqlbuft((void **)0,
              ",ADD_ORDER_ID_3,LOT_LOCATION_1,LOT_LOCATION_2,LOT_LOCATION_3,\
LOT_CMF_1,LOT_CMF_2,LOT_CMF_3,LOT_CMF_4,LOT_CMF_5,LOT_CMF_6,LOT_CMF_7,LOT_CM\
F_8,LOT_CMF_9,LOT_CMF_10,LOT_CMF_11,LOT_CMF_12,LOT_CMF_13,LOT_CMF_14,LOT_CMF\
_15,LOT_CMF_16,LOT_CMF_17,LOT_CMF_18,LOT_CMF_19,LOT_CMF_20,LOT_DEL_FLAG,LOT_\
DEL_CODE,LOT_DEL_TIME,BOM_SET_ID,BOM_SET_VERSION,BOM_ACTIVE_HIST_SEQ,BOM_HIS\
T_SEQ,CRITICAL_RES_ID,CRITICAL_RES_GROUP_ID,SAVE_RES_ID_1,SAVE_RES_ID_2,SUBR\
ES_ID,LOT_GROUP_ID_1,LOT_GROUP_ID_2,LOT_GROUP_ID_3,YIELD_1,YIELD_2,YIELD_3,G\
OOD_QTY,RESV_FIELD_1,RESV_FIELD_2,RESV_FIELD_3,RESV_FIELD_4,RESV_FIELD_5,RES\
V_FLAG_1,RESV_FLAG_2,RESV_FLAG_3,RESV_FLAG_4,RESV_FLAG_5,FROM_TO_MAT_ID,FROM\
_TO_MAT_VER,FROM_TO_FLOW,FROM_TO_FLOW_SEQ_NUM,FROM_TO_OPER,FROM_TO_QTY_1,FRO\
M_TO_QTY_2,FROM_TO_QTY_3,FROM_TO_HIST_SEQ,OLD_FACTORY,OLD_MAT_ID,OLD_MAT_VER\
,OLD_FLOW,OLD_FLOW_SEQ_NUM,OLD_OPER,OLD_QTY_1,OLD_QTY_2,OLD_QTY_3,OLD_LOT_TY\
PE,OLD_OWNER_CODE,OLD_CREATE_CODE,OLD_FAC_IN_TIME,OLD_FLOW_IN_TIME,OLD_OPER_\
IN_TIME,TRAN_CMF_1,TRAN_CMF_2,TRAN_CMF_3,TRAN_CMF_4");
            sqlbuft((void **)0,
              ",TRAN_CMF_5,TRAN_CMF_6,TRAN_CMF_7,TRAN_CMF_8,TRAN_CMF_9,TRAN_\
CMF_10,TRAN_CMF_11,TRAN_CMF_12,TRAN_CMF_13,TRAN_CMF_14,TRAN_CMF_15,TRAN_CMF_\
16,TRAN_CMF_17,TRAN_CMF_18,TRAN_CMF_19,TRAN_CMF_20,TRAN_USER_ID,TRAN_COMMENT\
,PREV_ACTIVE_HIST_SEQ,MULTI_TR_KEY,MULTI_TR_SEQ,EXT_HIST_SEQ,HIST_DEL_FLAG,H\
IST_DEL_TIME,HIST_DEL_USER_ID,HIST_DEL_COMMENT) values (:b0,:b1,:b2,:b3,:b4,\
:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:\
b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b\
36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b5\
1,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66\
,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,\
:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:\
b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108,:b109,:b\
110,:b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b120,:b121,:b122,\
:b123,:b124,:b125,:b126,:b127,:b128,:b129,:b130,:b1");
            sqlstm.stmt = "31,:b132,:b133,:b134,:b135,:b136,:b137,:b138,:b1\
39,:b140,:b141,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150,:b151,:b\
152,:b153,:b154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b162,:b163,:b164,:\
b165,:b166,:b167,:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b175,:b176,:b177,\
:b178,:b179,:b180,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:b188,:b189,:b190\
,:b191)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1726;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPLOTDEL_N.TRAN_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPLOTDEL_N.LOT_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPLOTDEL_N.FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPLOTDEL_N.MAT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPLOTDEL_N.MAT_VER);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPLOTDEL_N.FLOW);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPLOTDEL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPLOTDEL_N.OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPLOTDEL_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPLOTDEL_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPLOTDEL_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPLOTDEL_N.CRR_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPLOTDEL_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPLOTDEL_N.OWNER_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPLOTDEL_N.CREATE_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPLOTDEL_N.LOT_PRIORITY);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPLOTDEL_N.LOT_STATUS);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPLOTDEL_N.HOLD_FLAG);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPLOTDEL_N.HOLD_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPLOTDEL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPLOTDEL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTDEL_N.START_QTY_1);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTDEL_N.START_QTY_2);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTDEL_N.START_QTY_3);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPLOTDEL_N.INV_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPLOTDEL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPLOTDEL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPLOTDEL_N.INV_UNIT);
            sqlstm.sqhstl[37] = (unsigned int  )11;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPLOTDEL_N.RWK_FLAG);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPLOTDEL_N.RWK_CODE);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MWIPLOTDEL_N.RWK_COUNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPLOTDEL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPLOTDEL_N.RWK_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPLOTDEL_N.RWK_END_FLOW);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPLOTDEL_N.RWK_END_OPER);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPLOTDEL_N.RWK_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPLOTDEL_N.NSTD_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)&(MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[51] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPLOTDEL_N.NSTD_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPLOTDEL_N.REP_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPLOTDEL_N.REP_RET_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPLOTDEL_N.STR_RET_FLOW);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPLOTDEL_N.STR_RET_OPER);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPLOTDEL_N.START_FLAG);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPLOTDEL_N.START_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPLOTDEL_N.START_RES_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPLOTDEL_N.END_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPLOTDEL_N.END_TIME);
            sqlstm.sqhstl[63] = (unsigned int  )15;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPLOTDEL_N.END_RES_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPLOTDEL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPLOTDEL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPLOTDEL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPLOTDEL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[69] = (unsigned int  )26;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPLOTDEL_N.SHIP_CODE);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPLOTDEL_N.SHIP_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPLOTDEL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPLOTDEL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPLOTDEL_N.CREATE_TIME);
            sqlstm.sqhstl[74] = (unsigned int  )15;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPLOTDEL_N.FAC_IN_TIME);
            sqlstm.sqhstl[75] = (unsigned int  )15;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPLOTDEL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPLOTDEL_N.OPER_IN_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPLOTDEL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPLOTDEL_N.PORT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPLOTDEL_N.BATCH_ID);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPLOTDEL_N.BATCH_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPLOTDEL_N.ORDER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )26;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[83] = (unsigned int  )26;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[84] = (unsigned int  )26;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[85] = (unsigned int  )26;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_1);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_2);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_3);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_4);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_5);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_6);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_7);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_8);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_9);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_10);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_11);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_12);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_13);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_14);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_15);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_16);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_17);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_18);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_19);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_20);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[109] = (unsigned int  )2;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[110] = (unsigned int  )11;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[111] = (unsigned int  )15;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MWIPLOTDEL_N.BOM_SET_ID);
            sqlstm.sqhstl[112] = (unsigned int  )26;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)&(MWIPLOTDEL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[113] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)&(MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[114] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)&(MWIPLOTDEL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[115] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[116] = (unsigned int  )21;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[119] = (unsigned int  )21;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MWIPLOTDEL_N.SUBRES_ID);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[121] = (unsigned int  )26;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[122] = (unsigned int  )26;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[123] = (unsigned int  )26;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)&(MWIPLOTDEL_N.YIELD_1);
            sqlstm.sqhstl[124] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)&(MWIPLOTDEL_N.YIELD_2);
            sqlstm.sqhstl[125] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)&(MWIPLOTDEL_N.YIELD_3);
            sqlstm.sqhstl[126] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)&(MWIPLOTDEL_N.GOOD_QTY);
            sqlstm.sqhstl[127] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_1);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_2);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_3);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_4);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_5);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_1);
            sqlstm.sqhstl[133] = (unsigned int  )2;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_2);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_3);
            sqlstm.sqhstl[135] = (unsigned int  )2;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_4);
            sqlstm.sqhstl[136] = (unsigned int  )2;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_5);
            sqlstm.sqhstl[137] = (unsigned int  )2;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MWIPLOTDEL_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[139] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLOW);
            sqlstm.sqhstl[140] = (unsigned int  )21;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[141] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MWIPLOTDEL_N.FROM_TO_OPER);
            sqlstm.sqhstl[142] = (unsigned int  )11;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[143] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[144] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[145] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[146] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MWIPLOTDEL_N.OLD_FACTORY);
            sqlstm.sqhstl[147] = (unsigned int  )11;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MWIPLOTDEL_N.OLD_MAT_ID);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MWIPLOTDEL_N.OLD_MAT_VER);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW);
            sqlstm.sqhstl[150] = (unsigned int  )21;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MWIPLOTDEL_N.OLD_OPER);
            sqlstm.sqhstl[152] = (unsigned int  )11;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_1);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_2);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_3);
            sqlstm.sqhstl[155] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MWIPLOTDEL_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MWIPLOTDEL_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )11;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MWIPLOTDEL_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MWIPLOTDEL_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[159] = (unsigned int  )15;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[160] = (unsigned int  )15;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MWIPLOTDEL_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[161] = (unsigned int  )15;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_1);
            sqlstm.sqhstl[162] = (unsigned int  )31;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_2);
            sqlstm.sqhstl[163] = (unsigned int  )31;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_3);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_4);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_5);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_6);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_7);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_8);
            sqlstm.sqhstl[169] = (unsigned int  )31;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_9);
            sqlstm.sqhstl[170] = (unsigned int  )31;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_10);
            sqlstm.sqhstl[171] = (unsigned int  )31;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_11);
            sqlstm.sqhstl[172] = (unsigned int  )31;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_12);
            sqlstm.sqhstl[173] = (unsigned int  )31;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_13);
            sqlstm.sqhstl[174] = (unsigned int  )31;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_14);
            sqlstm.sqhstl[175] = (unsigned int  )31;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_15);
            sqlstm.sqhstl[176] = (unsigned int  )31;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_16);
            sqlstm.sqhstl[177] = (unsigned int  )31;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_17);
            sqlstm.sqhstl[178] = (unsigned int  )31;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_18);
            sqlstm.sqhstl[179] = (unsigned int  )31;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_19);
            sqlstm.sqhstl[180] = (unsigned int  )31;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_20);
            sqlstm.sqhstl[181] = (unsigned int  )31;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MWIPLOTDEL_N.TRAN_USER_ID);
            sqlstm.sqhstl[182] = (unsigned int  )21;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MWIPLOTDEL_N.TRAN_COMMENT);
            sqlstm.sqhstl[183] = (unsigned int  )401;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)&(MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[184] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MWIPLOTDEL_N.MULTI_TR_KEY);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)&(MWIPLOTDEL_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[186] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)&(MWIPLOTDEL_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[187] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[188] = (unsigned int  )2;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_TIME);
            sqlstm.sqhstl[189] = (unsigned int  )15;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[190] = (unsigned int  )21;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[191] = (unsigned int  )401;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
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
           /* EXEC SQL INSERT INTO MWIPLOTDEL 
                SELECT 
                    LOT_ID,
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
                    OLD_FACTORY,
                    OLD_MAT_ID,
                    OLD_MAT_VER,
                    OLD_FLOW,
                    OLD_FLOW_SEQ_NUM,
                    OLD_OPER,
                    OLD_QTY_1,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_LOT_TYPE,
                    OLD_OWNER_CODE,
                    OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME,
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
                    HIST_DEL_COMMENT
                FROM MWIPLOTHIS 
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 13;
           sqlstm.arrsiz = 195;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlbuft((void **)0,
             "insert into MWIPLOTDEL  select LOT_ID ,HIST_SEQ ,TRAN_TIME ,SY\
S_TRAN_TIME ,TRAN_CODE ,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_N\
UM ,OPER ,QTY_1 ,QTY_2 ,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LO\
T_PRIORITY ,LOT_STATUS ,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID\
 ,OPER_IN_QTY_1 ,OPER_IN_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,C\
REATE_QTY_3 ,START_QTY_1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,\
UNIT_EXIST_FLAG ,INV_UNIT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_\
RET_FLOW_SEQ_NUM ,RWK_RET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_\
OPER ,RWK_RET_CLEAR_FLAG ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_\
SEQ_NUM ,NSTD_RET_OPER ,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR\
_RET_FLOW_SEQ_NUM ,STR_RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_F\
LAG ,END_TIME ,END_RES_ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FRO\
M_TO_FLAG ,FROM_TO_LOT_ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE_TIME ,SCH_DUE_TIME \
,CREATE_TIME ,FAC_IN_TIME ,FLOW_IN_TIME ,OPER_IN_T");
           sqlbuft((void **)0,
             "IME ,RESERVE_RES_ID ,PORT_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,A\
DD_ORDER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_\
2 ,LOT_LOCATION_3 ,LOT_CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LO\
T_CMF_6 ,LOT_CMF_7 ,LOT_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12\
 ,LOT_CMF_13 ,LOT_CMF_14 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LO\
T_CMF_19 ,LOT_CMF_20 ,LOT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,\
BOM_SET_VERSION ,BOM_ACTIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICA\
L_RES_GROUP_ID ,SAVE_RES_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT\
_GROUP_ID_2 ,LOT_GROUP_ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD\
_1 ,RESV_FIELD_2 ,RESV_FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RES\
V_FLAG_2 ,RESV_FLAG_3 ,RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT\
_VER ,FROM_TO_FLOW ,FROM_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_\
TO_QTY_2 ,FROM_TO_QTY_3 ,FROM_TO_HIST_SEQ ,OLD_FACTORY ,OLD_MAT_ID ,OLD_MAT_\
VER ,OLD_FLOW ,OLD_FLOW_SEQ_NUM ,OLD_OPER ,OLD_QTY");
           sqlstm.stmt = "_1 ,OLD_QTY_2 ,OLD_QTY_3 ,OLD_LOT_TYPE ,OLD_OWNER\
_CODE ,OLD_CREATE_CODE ,OLD_FAC_IN_TIME ,OLD_FLOW_IN_TIME ,OLD_OPER_IN_TIME ,\
TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_CMF_6 ,TRAN_\
CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF_10 ,TRAN_CMF_11 ,TRAN_CMF_12 ,TRAN_CM\
F_13 ,TRAN_CMF_14 ,TRAN_CMF_15 ,TRAN_CMF_16 ,TRAN_CMF_17 ,TRAN_CMF_18 ,TRAN_C\
MF_19 ,TRAN_CMF_20 ,TRAN_USER_ID ,TRAN_COMMENT ,PREV_ACTIVE_HIST_SEQ ,MULTI_T\
R_KEY ,MULTI_TR_SEQ ,EXT_HIST_SEQ ,HIST_DEL_FLAG ,HIST_DEL_TIME ,HIST_DEL_USE\
R_ID ,HIST_DEL_COMMENT  from MWIPLOTHIS where LOT_ID=:b0";
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )2509;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
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
}


/* SQL UPDATE Function */
void DBC_update_mwiplotdel(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPLOTDEL SET
                    TRAN_TIME = :MWIPLOTDEL_N.TRAN_TIME,
                    TRAN_CODE = :MWIPLOTDEL_N.TRAN_CODE,
                    LOT_DESC = :MWIPLOTDEL_N.LOT_DESC,
                    FACTORY = :MWIPLOTDEL_N.FACTORY,
                    MAT_ID = :MWIPLOTDEL_N.MAT_ID,
                    MAT_VER = :MWIPLOTDEL_N.MAT_VER,
                    FLOW = :MWIPLOTDEL_N.FLOW,
                    FLOW_SEQ_NUM = :MWIPLOTDEL_N.FLOW_SEQ_NUM,
                    OPER = :MWIPLOTDEL_N.OPER,
                    QTY_1 = :MWIPLOTDEL_N.QTY_1,
                    QTY_2 = :MWIPLOTDEL_N.QTY_2,
                    QTY_3 = :MWIPLOTDEL_N.QTY_3,
                    CRR_ID = :MWIPLOTDEL_N.CRR_ID,
                    LOT_TYPE = :MWIPLOTDEL_N.LOT_TYPE,
                    OWNER_CODE = :MWIPLOTDEL_N.OWNER_CODE,
                    CREATE_CODE = :MWIPLOTDEL_N.CREATE_CODE,
                    LOT_PRIORITY = :MWIPLOTDEL_N.LOT_PRIORITY,
                    LOT_STATUS = :MWIPLOTDEL_N.LOT_STATUS,
                    HOLD_FLAG = :MWIPLOTDEL_N.HOLD_FLAG,
                    HOLD_CODE = :MWIPLOTDEL_N.HOLD_CODE,
                    HOLD_PASSWORD = :MWIPLOTDEL_N.HOLD_PASSWORD,
                    HOLD_PRV_GRP_ID = :MWIPLOTDEL_N.HOLD_PRV_GRP_ID,
                    OPER_IN_QTY_1 = :MWIPLOTDEL_N.OPER_IN_QTY_1,
                    OPER_IN_QTY_2 = :MWIPLOTDEL_N.OPER_IN_QTY_2,
                    OPER_IN_QTY_3 = :MWIPLOTDEL_N.OPER_IN_QTY_3,
                    CREATE_QTY_1 = :MWIPLOTDEL_N.CREATE_QTY_1,
                    CREATE_QTY_2 = :MWIPLOTDEL_N.CREATE_QTY_2,
                    CREATE_QTY_3 = :MWIPLOTDEL_N.CREATE_QTY_3,
                    START_QTY_1 = :MWIPLOTDEL_N.START_QTY_1,
                    START_QTY_2 = :MWIPLOTDEL_N.START_QTY_2,
                    START_QTY_3 = :MWIPLOTDEL_N.START_QTY_3,
                    INV_FLAG = :MWIPLOTDEL_N.INV_FLAG,
                    TRANSIT_FLAG = :MWIPLOTDEL_N.TRANSIT_FLAG,
                    UNIT_EXIST_FLAG = :MWIPLOTDEL_N.UNIT_EXIST_FLAG,
                    INV_UNIT = :MWIPLOTDEL_N.INV_UNIT,
                    RWK_FLAG = :MWIPLOTDEL_N.RWK_FLAG,
                    RWK_CODE = :MWIPLOTDEL_N.RWK_CODE,
                    RWK_COUNT = :MWIPLOTDEL_N.RWK_COUNT,
                    RWK_RET_FLOW = :MWIPLOTDEL_N.RWK_RET_FLOW,
                    RWK_RET_FLOW_SEQ_NUM = :MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM,
                    RWK_RET_OPER = :MWIPLOTDEL_N.RWK_RET_OPER,
                    RWK_END_FLOW = :MWIPLOTDEL_N.RWK_END_FLOW,
                    RWK_END_FLOW_SEQ_NUM = :MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM,
                    RWK_END_OPER = :MWIPLOTDEL_N.RWK_END_OPER,
                    RWK_RET_CLEAR_FLAG = :MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG,
                    RWK_TIME = :MWIPLOTDEL_N.RWK_TIME,
                    NSTD_FLAG = :MWIPLOTDEL_N.NSTD_FLAG,
                    NSTD_RET_FLOW = :MWIPLOTDEL_N.NSTD_RET_FLOW,
                    NSTD_RET_FLOW_SEQ_NUM = :MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM,
                    NSTD_RET_OPER = :MWIPLOTDEL_N.NSTD_RET_OPER,
                    NSTD_TIME = :MWIPLOTDEL_N.NSTD_TIME,
                    REP_FLAG = :MWIPLOTDEL_N.REP_FLAG,
                    REP_RET_OPER = :MWIPLOTDEL_N.REP_RET_OPER,
                    STR_RET_FLOW = :MWIPLOTDEL_N.STR_RET_FLOW,
                    STR_RET_FLOW_SEQ_NUM = :MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM,
                    STR_RET_OPER = :MWIPLOTDEL_N.STR_RET_OPER,
                    START_FLAG = :MWIPLOTDEL_N.START_FLAG,
                    START_TIME = :MWIPLOTDEL_N.START_TIME,
                    START_RES_ID = :MWIPLOTDEL_N.START_RES_ID,
                    END_FLAG = :MWIPLOTDEL_N.END_FLAG,
                    END_TIME = :MWIPLOTDEL_N.END_TIME,
                    END_RES_ID = :MWIPLOTDEL_N.END_RES_ID,
                    SAMPLE_FLAG = :MWIPLOTDEL_N.SAMPLE_FLAG,
                    SAMPLE_WAIT_FLAG = :MWIPLOTDEL_N.SAMPLE_WAIT_FLAG,
                    SAMPLE_RESULT = :MWIPLOTDEL_N.SAMPLE_RESULT,
                    FROM_TO_FLAG = :MWIPLOTDEL_N.FROM_TO_FLAG,
                    FROM_TO_LOT_ID = :MWIPLOTDEL_N.FROM_TO_LOT_ID,
                    SHIP_CODE = :MWIPLOTDEL_N.SHIP_CODE,
                    SHIP_TIME = :MWIPLOTDEL_N.SHIP_TIME,
                    ORG_DUE_TIME = :MWIPLOTDEL_N.ORG_DUE_TIME,
                    SCH_DUE_TIME = :MWIPLOTDEL_N.SCH_DUE_TIME,
                    CREATE_TIME = :MWIPLOTDEL_N.CREATE_TIME,
                    FAC_IN_TIME = :MWIPLOTDEL_N.FAC_IN_TIME,
                    FLOW_IN_TIME = :MWIPLOTDEL_N.FLOW_IN_TIME,
                    OPER_IN_TIME = :MWIPLOTDEL_N.OPER_IN_TIME,
                    RESERVE_RES_ID = :MWIPLOTDEL_N.RESERVE_RES_ID,
                    PORT_ID = :MWIPLOTDEL_N.PORT_ID,
                    BATCH_ID = :MWIPLOTDEL_N.BATCH_ID,
                    BATCH_SEQ = :MWIPLOTDEL_N.BATCH_SEQ,
                    ORDER_ID = :MWIPLOTDEL_N.ORDER_ID,
                    ADD_ORDER_ID_1 = :MWIPLOTDEL_N.ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2 = :MWIPLOTDEL_N.ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3 = :MWIPLOTDEL_N.ADD_ORDER_ID_3,
                    LOT_LOCATION_1 = :MWIPLOTDEL_N.LOT_LOCATION_1,
                    LOT_LOCATION_2 = :MWIPLOTDEL_N.LOT_LOCATION_2,
                    LOT_LOCATION_3 = :MWIPLOTDEL_N.LOT_LOCATION_3,
                    LOT_CMF_1 = :MWIPLOTDEL_N.LOT_CMF_1,
                    LOT_CMF_2 = :MWIPLOTDEL_N.LOT_CMF_2,
                    LOT_CMF_3 = :MWIPLOTDEL_N.LOT_CMF_3,
                    LOT_CMF_4 = :MWIPLOTDEL_N.LOT_CMF_4,
                    LOT_CMF_5 = :MWIPLOTDEL_N.LOT_CMF_5,
                    LOT_CMF_6 = :MWIPLOTDEL_N.LOT_CMF_6,
                    LOT_CMF_7 = :MWIPLOTDEL_N.LOT_CMF_7,
                    LOT_CMF_8 = :MWIPLOTDEL_N.LOT_CMF_8,
                    LOT_CMF_9 = :MWIPLOTDEL_N.LOT_CMF_9,
                    LOT_CMF_10 = :MWIPLOTDEL_N.LOT_CMF_10,
                    LOT_CMF_11 = :MWIPLOTDEL_N.LOT_CMF_11,
                    LOT_CMF_12 = :MWIPLOTDEL_N.LOT_CMF_12,
                    LOT_CMF_13 = :MWIPLOTDEL_N.LOT_CMF_13,
                    LOT_CMF_14 = :MWIPLOTDEL_N.LOT_CMF_14,
                    LOT_CMF_15 = :MWIPLOTDEL_N.LOT_CMF_15,
                    LOT_CMF_16 = :MWIPLOTDEL_N.LOT_CMF_16,
                    LOT_CMF_17 = :MWIPLOTDEL_N.LOT_CMF_17,
                    LOT_CMF_18 = :MWIPLOTDEL_N.LOT_CMF_18,
                    LOT_CMF_19 = :MWIPLOTDEL_N.LOT_CMF_19,
                    LOT_CMF_20 = :MWIPLOTDEL_N.LOT_CMF_20,
                    LOT_DEL_FLAG = :MWIPLOTDEL_N.LOT_DEL_FLAG,
                    LOT_DEL_CODE = :MWIPLOTDEL_N.LOT_DEL_CODE,
                    LOT_DEL_TIME = :MWIPLOTDEL_N.LOT_DEL_TIME,
                    BOM_SET_ID = :MWIPLOTDEL_N.BOM_SET_ID,
                    BOM_SET_VERSION = :MWIPLOTDEL_N.BOM_SET_VERSION,
                    BOM_ACTIVE_HIST_SEQ = :MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ,
                    BOM_HIST_SEQ = :MWIPLOTDEL_N.BOM_HIST_SEQ,
                    CRITICAL_RES_ID = :MWIPLOTDEL_N.CRITICAL_RES_ID,
                    CRITICAL_RES_GROUP_ID = :MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID,
                    SAVE_RES_ID_1 = :MWIPLOTDEL_N.SAVE_RES_ID_1,
                    SAVE_RES_ID_2 = :MWIPLOTDEL_N.SAVE_RES_ID_2,
                    SUBRES_ID = :MWIPLOTDEL_N.SUBRES_ID,
                    LOT_GROUP_ID_1 = :MWIPLOTDEL_N.LOT_GROUP_ID_1,
                    LOT_GROUP_ID_2 = :MWIPLOTDEL_N.LOT_GROUP_ID_2,
                    LOT_GROUP_ID_3 = :MWIPLOTDEL_N.LOT_GROUP_ID_3,
                    YIELD_1 = :MWIPLOTDEL_N.YIELD_1,
                    YIELD_2 = :MWIPLOTDEL_N.YIELD_2,
                    YIELD_3 = :MWIPLOTDEL_N.YIELD_3,
                    GOOD_QTY = :MWIPLOTDEL_N.GOOD_QTY,
                    RESV_FIELD_1 = :MWIPLOTDEL_N.RESV_FIELD_1,
                    RESV_FIELD_2 = :MWIPLOTDEL_N.RESV_FIELD_2,
                    RESV_FIELD_3 = :MWIPLOTDEL_N.RESV_FIELD_3,
                    RESV_FIELD_4 = :MWIPLOTDEL_N.RESV_FIELD_4,
                    RESV_FIELD_5 = :MWIPLOTDEL_N.RESV_FIELD_5,
                    RESV_FLAG_1 = :MWIPLOTDEL_N.RESV_FLAG_1,
                    RESV_FLAG_2 = :MWIPLOTDEL_N.RESV_FLAG_2,
                    RESV_FLAG_3 = :MWIPLOTDEL_N.RESV_FLAG_3,
                    RESV_FLAG_4 = :MWIPLOTDEL_N.RESV_FLAG_4,
                    RESV_FLAG_5 = :MWIPLOTDEL_N.RESV_FLAG_5,
                    FROM_TO_MAT_ID = :MWIPLOTDEL_N.FROM_TO_MAT_ID,
                    FROM_TO_MAT_VER = :MWIPLOTDEL_N.FROM_TO_MAT_VER,
                    FROM_TO_FLOW = :MWIPLOTDEL_N.FROM_TO_FLOW,
                    FROM_TO_FLOW_SEQ_NUM = :MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM,
                    FROM_TO_OPER = :MWIPLOTDEL_N.FROM_TO_OPER,
                    FROM_TO_QTY_1 = :MWIPLOTDEL_N.FROM_TO_QTY_1,
                    FROM_TO_QTY_2 = :MWIPLOTDEL_N.FROM_TO_QTY_2,
                    FROM_TO_QTY_3 = :MWIPLOTDEL_N.FROM_TO_QTY_3,
                    FROM_TO_HIST_SEQ = :MWIPLOTDEL_N.FROM_TO_HIST_SEQ,
                    OLD_FACTORY = :MWIPLOTDEL_N.OLD_FACTORY,
                    OLD_MAT_ID = :MWIPLOTDEL_N.OLD_MAT_ID,
                    OLD_MAT_VER = :MWIPLOTDEL_N.OLD_MAT_VER,
                    OLD_FLOW = :MWIPLOTDEL_N.OLD_FLOW,
                    OLD_FLOW_SEQ_NUM = :MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM,
                    OLD_OPER = :MWIPLOTDEL_N.OLD_OPER,
                    OLD_QTY_1 = :MWIPLOTDEL_N.OLD_QTY_1,
                    OLD_QTY_2 = :MWIPLOTDEL_N.OLD_QTY_2,
                    OLD_QTY_3 = :MWIPLOTDEL_N.OLD_QTY_3,
                    OLD_LOT_TYPE = :MWIPLOTDEL_N.OLD_LOT_TYPE,
                    OLD_OWNER_CODE = :MWIPLOTDEL_N.OLD_OWNER_CODE,
                    OLD_CREATE_CODE = :MWIPLOTDEL_N.OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME = :MWIPLOTDEL_N.OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME = :MWIPLOTDEL_N.OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME = :MWIPLOTDEL_N.OLD_OPER_IN_TIME,
                    TRAN_CMF_1 = :MWIPLOTDEL_N.TRAN_CMF_1,
                    TRAN_CMF_2 = :MWIPLOTDEL_N.TRAN_CMF_2,
                    TRAN_CMF_3 = :MWIPLOTDEL_N.TRAN_CMF_3,
                    TRAN_CMF_4 = :MWIPLOTDEL_N.TRAN_CMF_4,
                    TRAN_CMF_5 = :MWIPLOTDEL_N.TRAN_CMF_5,
                    TRAN_CMF_6 = :MWIPLOTDEL_N.TRAN_CMF_6,
                    TRAN_CMF_7 = :MWIPLOTDEL_N.TRAN_CMF_7,
                    TRAN_CMF_8 = :MWIPLOTDEL_N.TRAN_CMF_8,
                    TRAN_CMF_9 = :MWIPLOTDEL_N.TRAN_CMF_9,
                    TRAN_CMF_10 = :MWIPLOTDEL_N.TRAN_CMF_10,
                    TRAN_CMF_11 = :MWIPLOTDEL_N.TRAN_CMF_11,
                    TRAN_CMF_12 = :MWIPLOTDEL_N.TRAN_CMF_12,
                    TRAN_CMF_13 = :MWIPLOTDEL_N.TRAN_CMF_13,
                    TRAN_CMF_14 = :MWIPLOTDEL_N.TRAN_CMF_14,
                    TRAN_CMF_15 = :MWIPLOTDEL_N.TRAN_CMF_15,
                    TRAN_CMF_16 = :MWIPLOTDEL_N.TRAN_CMF_16,
                    TRAN_CMF_17 = :MWIPLOTDEL_N.TRAN_CMF_17,
                    TRAN_CMF_18 = :MWIPLOTDEL_N.TRAN_CMF_18,
                    TRAN_CMF_19 = :MWIPLOTDEL_N.TRAN_CMF_19,
                    TRAN_CMF_20 = :MWIPLOTDEL_N.TRAN_CMF_20,
                    TRAN_USER_ID = :MWIPLOTDEL_N.TRAN_USER_ID,
                    TRAN_COMMENT = :MWIPLOTDEL_N.TRAN_COMMENT,
                    PREV_ACTIVE_HIST_SEQ = :MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ,
                    MULTI_TR_KEY = :MWIPLOTDEL_N.MULTI_TR_KEY,
                    MULTI_TR_SEQ = :MWIPLOTDEL_N.MULTI_TR_SEQ,
                    EXT_HIST_SEQ = :MWIPLOTDEL_N.EXT_HIST_SEQ,
                    HIST_DEL_FLAG = :MWIPLOTDEL_N.HIST_DEL_FLAG,
                    HIST_DEL_TIME = :MWIPLOTDEL_N.HIST_DEL_TIME,
                    HIST_DEL_USER_ID = :MWIPLOTDEL_N.HIST_DEL_USER_ID,
                    HIST_DEL_COMMENT = :MWIPLOTDEL_N.HIST_DEL_COMMENT
                WHERE LOT_ID = :MWIPLOTDEL_N.LOT_ID
                    AND HIST_SEQ = :MWIPLOTDEL_N.HIST_SEQ
                    AND SYS_TRAN_TIME = :MWIPLOTDEL_N.SYS_TRAN_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPLOTDEL  set TRAN_TIME=:b0,TRAN_CODE=:b1,LOT_DESC=:\
b2,FACTORY=:b3,MAT_ID=:b4,MAT_VER=:b5,FLOW=:b6,FLOW_SEQ_NUM=:b7,OPER=:b8,QTY\
_1=:b9,QTY_2=:b10,QTY_3=:b11,CRR_ID=:b12,LOT_TYPE=:b13,OWNER_CODE=:b14,CREAT\
E_CODE=:b15,LOT_PRIORITY=:b16,LOT_STATUS=:b17,HOLD_FLAG=:b18,HOLD_CODE=:b19,\
HOLD_PASSWORD=:b20,HOLD_PRV_GRP_ID=:b21,OPER_IN_QTY_1=:b22,OPER_IN_QTY_2=:b2\
3,OPER_IN_QTY_3=:b24,CREATE_QTY_1=:b25,CREATE_QTY_2=:b26,CREATE_QTY_3=:b27,S\
TART_QTY_1=:b28,START_QTY_2=:b29,START_QTY_3=:b30,INV_FLAG=:b31,TRANSIT_FLAG\
=:b32,UNIT_EXIST_FLAG=:b33,INV_UNIT=:b34,RWK_FLAG=:b35,RWK_CODE=:b36,RWK_COU\
NT=:b37,RWK_RET_FLOW=:b38,RWK_RET_FLOW_SEQ_NUM=:b39,RWK_RET_OPER=:b40,RWK_EN\
D_FLOW=:b41,RWK_END_FLOW_SEQ_NUM=:b42,RWK_END_OPER=:b43,RWK_RET_CLEAR_FLAG=:\
b44,RWK_TIME=:b45,NSTD_FLAG=:b46,NSTD_RET_FLOW=:b47,NSTD_RET_FLOW_SEQ_NUM=:b\
48,NSTD_RET_OPER=:b49,NSTD_TIME=:b50,REP_FLAG=:b51,REP_RET_OPER=:b52,STR_RET\
_FLOW=:b53,STR_RET_FLOW_SEQ_NUM=:b54,STR_RET_OPER=:b55,START_FLAG=:b56,START\
_TIME=:b57,START_RES_ID=:b58,END_FLAG=:b59,END_TIME");
            sqlbuft((void **)0,
              "=:b60,END_RES_ID=:b61,SAMPLE_FLAG=:b62,SAMPLE_WAIT_FLAG=:b63,\
SAMPLE_RESULT=:b64,FROM_TO_FLAG=:b65,FROM_TO_LOT_ID=:b66,SHIP_CODE=:b67,SHIP\
_TIME=:b68,ORG_DUE_TIME=:b69,SCH_DUE_TIME=:b70,CREATE_TIME=:b71,FAC_IN_TIME=\
:b72,FLOW_IN_TIME=:b73,OPER_IN_TIME=:b74,RESERVE_RES_ID=:b75,PORT_ID=:b76,BA\
TCH_ID=:b77,BATCH_SEQ=:b78,ORDER_ID=:b79,ADD_ORDER_ID_1=:b80,ADD_ORDER_ID_2=\
:b81,ADD_ORDER_ID_3=:b82,LOT_LOCATION_1=:b83,LOT_LOCATION_2=:b84,LOT_LOCATIO\
N_3=:b85,LOT_CMF_1=:b86,LOT_CMF_2=:b87,LOT_CMF_3=:b88,LOT_CMF_4=:b89,LOT_CMF\
_5=:b90,LOT_CMF_6=:b91,LOT_CMF_7=:b92,LOT_CMF_8=:b93,LOT_CMF_9=:b94,LOT_CMF_\
10=:b95,LOT_CMF_11=:b96,LOT_CMF_12=:b97,LOT_CMF_13=:b98,LOT_CMF_14=:b99,LOT_\
CMF_15=:b100,LOT_CMF_16=:b101,LOT_CMF_17=:b102,LOT_CMF_18=:b103,LOT_CMF_19=:\
b104,LOT_CMF_20=:b105,LOT_DEL_FLAG=:b106,LOT_DEL_CODE=:b107,LOT_DEL_TIME=:b1\
08,BOM_SET_ID=:b109,BOM_SET_VERSION=:b110,BOM_ACTIVE_HIST_SEQ=:b111,BOM_HIST\
_SEQ=:b112,CRITICAL_RES_ID=:b113,CRITICAL_RES_GROUP_ID=:b114,SAVE_RES_ID_1=:\
b115,SAVE_RES_ID_2=:b116,SUBRES_ID=:b117,LOT_GROUP_");
            sqlbuft((void **)0,
              "ID_1=:b118,LOT_GROUP_ID_2=:b119,LOT_GROUP_ID_3=:b120,YIELD_1=\
:b121,YIELD_2=:b122,YIELD_3=:b123,GOOD_QTY=:b124,RESV_FIELD_1=:b125,RESV_FIE\
LD_2=:b126,RESV_FIELD_3=:b127,RESV_FIELD_4=:b128,RESV_FIELD_5=:b129,RESV_FLA\
G_1=:b130,RESV_FLAG_2=:b131,RESV_FLAG_3=:b132,RESV_FLAG_4=:b133,RESV_FLAG_5=\
:b134,FROM_TO_MAT_ID=:b135,FROM_TO_MAT_VER=:b136,FROM_TO_FLOW=:b137,FROM_TO_\
FLOW_SEQ_NUM=:b138,FROM_TO_OPER=:b139,FROM_TO_QTY_1=:b140,FROM_TO_QTY_2=:b14\
1,FROM_TO_QTY_3=:b142,FROM_TO_HIST_SEQ=:b143,OLD_FACTORY=:b144,OLD_MAT_ID=:b\
145,OLD_MAT_VER=:b146,OLD_FLOW=:b147,OLD_FLOW_SEQ_NUM=:b148,OLD_OPER=:b149,O\
LD_QTY_1=:b150,OLD_QTY_2=:b151,OLD_QTY_3=:b152,OLD_LOT_TYPE=:b153,OLD_OWNER_\
CODE=:b154,OLD_CREATE_CODE=:b155,OLD_FAC_IN_TIME=:b156,OLD_FLOW_IN_TIME=:b15\
7,OLD_OPER_IN_TIME=:b158,TRAN_CMF_1=:b159,TRAN_CMF_2=:b160,TRAN_CMF_3=:b161,\
TRAN_CMF_4=:b162,TRAN_CMF_5=:b163,TRAN_CMF_6=:b164,TRAN_CMF_7=:b165,TRAN_CMF\
_8=:b166,TRAN_CMF_9=:b167,TRAN_CMF_10=:b168,TRAN_CMF_11=:b169,TRAN_CMF_12=:b\
170,TRAN_CMF_13=:b171,TRAN_CMF_14=:b172,TRAN_CMF_15");
            sqlstm.stmt = "=:b173,TRAN_CMF_16=:b174,TRAN_CMF_17=:b175,TRAN_\
CMF_18=:b176,TRAN_CMF_19=:b177,TRAN_CMF_20=:b178,TRAN_USER_ID=:b179,TRAN_COMM\
ENT=:b180,PREV_ACTIVE_HIST_SEQ=:b181,MULTI_TR_KEY=:b182,MULTI_TR_SEQ=:b183,EX\
T_HIST_SEQ=:b184,HIST_DEL_FLAG=:b185,HIST_DEL_TIME=:b186,HIST_DEL_USER_ID=:b1\
87,HIST_DEL_COMMENT=:b188 where ((LOT_ID=:b189 and HIST_SEQ=:b190) and SYS_TR\
AN_TIME=:b191)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2528;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.TRAN_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPLOTDEL_N.TRAN_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.LOT_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPLOTDEL_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPLOTDEL_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPLOTDEL_N.MAT_VER);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPLOTDEL_N.FLOW);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MWIPLOTDEL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPLOTDEL_N.OPER);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(MWIPLOTDEL_N.QTY_1);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPLOTDEL_N.QTY_2);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MWIPLOTDEL_N.QTY_3);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPLOTDEL_N.CRR_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPLOTDEL_N.LOT_TYPE);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPLOTDEL_N.OWNER_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPLOTDEL_N.CREATE_CODE);
            sqlstm.sqhstl[15] = (unsigned int  )11;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPLOTDEL_N.LOT_PRIORITY);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPLOTDEL_N.LOT_STATUS);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPLOTDEL_N.HOLD_FLAG);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPLOTDEL_N.HOLD_CODE);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPLOTDEL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPLOTDEL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_1);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_2);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_3);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTDEL_N.START_QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTDEL_N.START_QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTDEL_N.START_QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPLOTDEL_N.INV_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPLOTDEL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPLOTDEL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPLOTDEL_N.INV_UNIT);
            sqlstm.sqhstl[34] = (unsigned int  )11;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPLOTDEL_N.RWK_FLAG);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPLOTDEL_N.RWK_CODE);
            sqlstm.sqhstl[36] = (unsigned int  )11;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MWIPLOTDEL_N.RWK_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPLOTDEL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPLOTDEL_N.RWK_RET_OPER);
            sqlstm.sqhstl[40] = (unsigned int  )11;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPLOTDEL_N.RWK_END_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPLOTDEL_N.RWK_END_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPLOTDEL_N.RWK_TIME);
            sqlstm.sqhstl[45] = (unsigned int  )15;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPLOTDEL_N.NSTD_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPLOTDEL_N.NSTD_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPLOTDEL_N.REP_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPLOTDEL_N.REP_RET_OPER);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPLOTDEL_N.STR_RET_FLOW);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPLOTDEL_N.STR_RET_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPLOTDEL_N.START_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPLOTDEL_N.START_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPLOTDEL_N.START_RES_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPLOTDEL_N.END_FLAG);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPLOTDEL_N.END_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPLOTDEL_N.END_RES_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPLOTDEL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPLOTDEL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPLOTDEL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPLOTDEL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPLOTDEL_N.SHIP_CODE);
            sqlstm.sqhstl[67] = (unsigned int  )11;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPLOTDEL_N.SHIP_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPLOTDEL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPLOTDEL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPLOTDEL_N.CREATE_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPLOTDEL_N.FAC_IN_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPLOTDEL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPLOTDEL_N.OPER_IN_TIME);
            sqlstm.sqhstl[74] = (unsigned int  )15;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPLOTDEL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPLOTDEL_N.PORT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )11;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPLOTDEL_N.BATCH_ID);
            sqlstm.sqhstl[77] = (unsigned int  )26;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPLOTDEL_N.BATCH_SEQ);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPLOTDEL_N.ORDER_ID);
            sqlstm.sqhstl[79] = (unsigned int  )26;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[81] = (unsigned int  )26;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[82] = (unsigned int  )26;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_1);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_2);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_3);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_4);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_5);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_6);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_7);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_8);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_9);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_10);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_11);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_12);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_13);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_14);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_15);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_16);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_17);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_18);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_19);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_20);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[106] = (unsigned int  )2;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[107] = (unsigned int  )11;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[108] = (unsigned int  )15;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPLOTDEL_N.BOM_SET_ID);
            sqlstm.sqhstl[109] = (unsigned int  )26;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(MWIPLOTDEL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)&(MWIPLOTDEL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[112] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[113] = (unsigned int  )21;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[114] = (unsigned int  )21;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[115] = (unsigned int  )21;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[116] = (unsigned int  )21;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MWIPLOTDEL_N.SUBRES_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[118] = (unsigned int  )26;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[119] = (unsigned int  )26;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[120] = (unsigned int  )26;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)&(MWIPLOTDEL_N.YIELD_1);
            sqlstm.sqhstl[121] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MWIPLOTDEL_N.YIELD_2);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)&(MWIPLOTDEL_N.YIELD_3);
            sqlstm.sqhstl[123] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)&(MWIPLOTDEL_N.GOOD_QTY);
            sqlstm.sqhstl[124] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_1);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_2);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_3);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_4);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_5);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_1);
            sqlstm.sqhstl[130] = (unsigned int  )2;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_2);
            sqlstm.sqhstl[131] = (unsigned int  )2;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_3);
            sqlstm.sqhstl[132] = (unsigned int  )2;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_4);
            sqlstm.sqhstl[133] = (unsigned int  )2;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_5);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MWIPLOTDEL_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[136] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLOW);
            sqlstm.sqhstl[137] = (unsigned int  )21;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[138] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MWIPLOTDEL_N.FROM_TO_OPER);
            sqlstm.sqhstl[139] = (unsigned int  )11;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[140] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[141] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[142] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[143] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MWIPLOTDEL_N.OLD_FACTORY);
            sqlstm.sqhstl[144] = (unsigned int  )11;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MWIPLOTDEL_N.OLD_MAT_ID);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)&(MWIPLOTDEL_N.OLD_MAT_VER);
            sqlstm.sqhstl[146] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW);
            sqlstm.sqhstl[147] = (unsigned int  )21;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)&(MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[148] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MWIPLOTDEL_N.OLD_OPER);
            sqlstm.sqhstl[149] = (unsigned int  )11;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_1);
            sqlstm.sqhstl[150] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_2);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_3);
            sqlstm.sqhstl[152] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MWIPLOTDEL_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[153] = (unsigned int  )2;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MWIPLOTDEL_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[154] = (unsigned int  )11;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MWIPLOTDEL_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[155] = (unsigned int  )11;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MWIPLOTDEL_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[156] = (unsigned int  )15;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[157] = (unsigned int  )15;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MWIPLOTDEL_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[158] = (unsigned int  )15;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_1);
            sqlstm.sqhstl[159] = (unsigned int  )31;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_2);
            sqlstm.sqhstl[160] = (unsigned int  )31;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_3);
            sqlstm.sqhstl[161] = (unsigned int  )31;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_4);
            sqlstm.sqhstl[162] = (unsigned int  )31;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_5);
            sqlstm.sqhstl[163] = (unsigned int  )31;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_6);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_7);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_8);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_9);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_10);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_11);
            sqlstm.sqhstl[169] = (unsigned int  )31;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_12);
            sqlstm.sqhstl[170] = (unsigned int  )31;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_13);
            sqlstm.sqhstl[171] = (unsigned int  )31;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_14);
            sqlstm.sqhstl[172] = (unsigned int  )31;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_15);
            sqlstm.sqhstl[173] = (unsigned int  )31;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_16);
            sqlstm.sqhstl[174] = (unsigned int  )31;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_17);
            sqlstm.sqhstl[175] = (unsigned int  )31;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_18);
            sqlstm.sqhstl[176] = (unsigned int  )31;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_19);
            sqlstm.sqhstl[177] = (unsigned int  )31;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_20);
            sqlstm.sqhstl[178] = (unsigned int  )31;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MWIPLOTDEL_N.TRAN_USER_ID);
            sqlstm.sqhstl[179] = (unsigned int  )21;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MWIPLOTDEL_N.TRAN_COMMENT);
            sqlstm.sqhstl[180] = (unsigned int  )401;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)&(MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[181] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MWIPLOTDEL_N.MULTI_TR_KEY);
            sqlstm.sqhstl[182] = (unsigned int  )31;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)&(MWIPLOTDEL_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[183] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)&(MWIPLOTDEL_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[184] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_TIME);
            sqlstm.sqhstl[186] = (unsigned int  )15;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[187] = (unsigned int  )21;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[188] = (unsigned int  )401;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[189] = (unsigned int  )26;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[190] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[191] = (unsigned int  )15;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mwiplotdel", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwiplotdel(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MWIPLOTDEL_CUR_1 CURSOR FOR
                SELECT 
                    LOT_ID,
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
                    OLD_FACTORY,
                    OLD_MAT_ID,
                    OLD_MAT_VER,
                    OLD_FLOW,
                    OLD_FLOW_SEQ_NUM,
                    OLD_OPER,
                    OLD_QTY_1,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_LOT_TYPE,
                    OLD_OWNER_CODE,
                    OLD_CREATE_CODE,
                    OLD_FAC_IN_TIME,
                    OLD_FLOW_IN_TIME,
                    OLD_OPER_IN_TIME,
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
                    HIST_DEL_COMMENT
                FROM MWIPLOTDEL
                ORDER BY LOT_ID ASC,
                    HIST_SEQ ASC,
                    SYS_TRAN_TIME ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPLOTDEL_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LOT_ID ,HIST_SEQ ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_CODE \
,LOT_DESC ,FACTORY ,MAT_ID ,MAT_VER ,FLOW ,FLOW_SEQ_NUM ,OPER ,QTY_1 ,QTY_2 \
,QTY_3 ,CRR_ID ,LOT_TYPE ,OWNER_CODE ,CREATE_CODE ,LOT_PRIORITY ,LOT_STATUS \
,HOLD_FLAG ,HOLD_CODE ,HOLD_PASSWORD ,HOLD_PRV_GRP_ID ,OPER_IN_QTY_1 ,OPER_I\
N_QTY_2 ,OPER_IN_QTY_3 ,CREATE_QTY_1 ,CREATE_QTY_2 ,CREATE_QTY_3 ,START_QTY_\
1 ,START_QTY_2 ,START_QTY_3 ,INV_FLAG ,TRANSIT_FLAG ,UNIT_EXIST_FLAG ,INV_UN\
IT ,RWK_FLAG ,RWK_CODE ,RWK_COUNT ,RWK_RET_FLOW ,RWK_RET_FLOW_SEQ_NUM ,RWK_R\
ET_OPER ,RWK_END_FLOW ,RWK_END_FLOW_SEQ_NUM ,RWK_END_OPER ,RWK_RET_CLEAR_FLA\
G ,RWK_TIME ,NSTD_FLAG ,NSTD_RET_FLOW ,NSTD_RET_FLOW_SEQ_NUM ,NSTD_RET_OPER \
,NSTD_TIME ,REP_FLAG ,REP_RET_OPER ,STR_RET_FLOW ,STR_RET_FLOW_SEQ_NUM ,STR_\
RET_OPER ,START_FLAG ,START_TIME ,START_RES_ID ,END_FLAG ,END_TIME ,END_RES_\
ID ,SAMPLE_FLAG ,SAMPLE_WAIT_FLAG ,SAMPLE_RESULT ,FROM_TO_FLAG ,FROM_TO_LOT_\
ID ,SHIP_CODE ,SHIP_TIME ,ORG_DUE_TIME ,SCH_DUE_TIME ,CREATE_TIME ,FAC_IN_TI\
ME ,FLOW_IN_TIME ,OPER_IN_TIME ,RESERVE_RES_ID ,POR");
            sqlbuft((void **)0,
              "T_ID ,BATCH_ID ,BATCH_SEQ ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDE\
R_ID_2 ,ADD_ORDER_ID_3 ,LOT_LOCATION_1 ,LOT_LOCATION_2 ,LOT_LOCATION_3 ,LOT_\
CMF_1 ,LOT_CMF_2 ,LOT_CMF_3 ,LOT_CMF_4 ,LOT_CMF_5 ,LOT_CMF_6 ,LOT_CMF_7 ,LOT\
_CMF_8 ,LOT_CMF_9 ,LOT_CMF_10 ,LOT_CMF_11 ,LOT_CMF_12 ,LOT_CMF_13 ,LOT_CMF_1\
4 ,LOT_CMF_15 ,LOT_CMF_16 ,LOT_CMF_17 ,LOT_CMF_18 ,LOT_CMF_19 ,LOT_CMF_20 ,L\
OT_DEL_FLAG ,LOT_DEL_CODE ,LOT_DEL_TIME ,BOM_SET_ID ,BOM_SET_VERSION ,BOM_AC\
TIVE_HIST_SEQ ,BOM_HIST_SEQ ,CRITICAL_RES_ID ,CRITICAL_RES_GROUP_ID ,SAVE_RE\
S_ID_1 ,SAVE_RES_ID_2 ,SUBRES_ID ,LOT_GROUP_ID_1 ,LOT_GROUP_ID_2 ,LOT_GROUP_\
ID_3 ,YIELD_1 ,YIELD_2 ,YIELD_3 ,GOOD_QTY ,RESV_FIELD_1 ,RESV_FIELD_2 ,RESV_\
FIELD_3 ,RESV_FIELD_4 ,RESV_FIELD_5 ,RESV_FLAG_1 ,RESV_FLAG_2 ,RESV_FLAG_3 ,\
RESV_FLAG_4 ,RESV_FLAG_5 ,FROM_TO_MAT_ID ,FROM_TO_MAT_VER ,FROM_TO_FLOW ,FRO\
M_TO_FLOW_SEQ_NUM ,FROM_TO_OPER ,FROM_TO_QTY_1 ,FROM_TO_QTY_2 ,FROM_TO_QTY_3\
 ,FROM_TO_HIST_SEQ ,OLD_FACTORY ,OLD_MAT_ID ,OLD_MAT_VER ,OLD_FLOW ,OLD_FLOW\
_SEQ_NUM ,OLD_OPER ,OLD_QTY_1 ,OLD_QTY_2 ,OLD_QTY_3");
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3311;
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
    DB_stop_query_timer("DBC_open_mwiplotdel", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwiplotdel(int sel_type, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPLOTDEL_N_TAG MWIPLOTDEL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPLOTDEL_CUR_1 INTO 
                                                    :MWIPLOTDEL_N.LOT_ID,
                                                    :MWIPLOTDEL_N.HIST_SEQ,
                                                    :MWIPLOTDEL_N.TRAN_TIME,
                                                    :MWIPLOTDEL_N.SYS_TRAN_TIME,
                                                    :MWIPLOTDEL_N.TRAN_CODE,
                                                    :MWIPLOTDEL_N.LOT_DESC,
                                                    :MWIPLOTDEL_N.FACTORY,
                                                    :MWIPLOTDEL_N.MAT_ID,
                                                    :MWIPLOTDEL_N.MAT_VER,
                                                    :MWIPLOTDEL_N.FLOW,
                                                    :MWIPLOTDEL_N.FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.OPER,
                                                    :MWIPLOTDEL_N.QTY_1,
                                                    :MWIPLOTDEL_N.QTY_2,
                                                    :MWIPLOTDEL_N.QTY_3,
                                                    :MWIPLOTDEL_N.CRR_ID,
                                                    :MWIPLOTDEL_N.LOT_TYPE,
                                                    :MWIPLOTDEL_N.OWNER_CODE,
                                                    :MWIPLOTDEL_N.CREATE_CODE,
                                                    :MWIPLOTDEL_N.LOT_PRIORITY,
                                                    :MWIPLOTDEL_N.LOT_STATUS,
                                                    :MWIPLOTDEL_N.HOLD_FLAG,
                                                    :MWIPLOTDEL_N.HOLD_CODE,
                                                    :MWIPLOTDEL_N.HOLD_PASSWORD,
                                                    :MWIPLOTDEL_N.HOLD_PRV_GRP_ID,
                                                    :MWIPLOTDEL_N.OPER_IN_QTY_1,
                                                    :MWIPLOTDEL_N.OPER_IN_QTY_2,
                                                    :MWIPLOTDEL_N.OPER_IN_QTY_3,
                                                    :MWIPLOTDEL_N.CREATE_QTY_1,
                                                    :MWIPLOTDEL_N.CREATE_QTY_2,
                                                    :MWIPLOTDEL_N.CREATE_QTY_3,
                                                    :MWIPLOTDEL_N.START_QTY_1,
                                                    :MWIPLOTDEL_N.START_QTY_2,
                                                    :MWIPLOTDEL_N.START_QTY_3,
                                                    :MWIPLOTDEL_N.INV_FLAG,
                                                    :MWIPLOTDEL_N.TRANSIT_FLAG,
                                                    :MWIPLOTDEL_N.UNIT_EXIST_FLAG,
                                                    :MWIPLOTDEL_N.INV_UNIT,
                                                    :MWIPLOTDEL_N.RWK_FLAG,
                                                    :MWIPLOTDEL_N.RWK_CODE,
                                                    :MWIPLOTDEL_N.RWK_COUNT,
                                                    :MWIPLOTDEL_N.RWK_RET_FLOW,
                                                    :MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.RWK_RET_OPER,
                                                    :MWIPLOTDEL_N.RWK_END_FLOW,
                                                    :MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.RWK_END_OPER,
                                                    :MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG,
                                                    :MWIPLOTDEL_N.RWK_TIME,
                                                    :MWIPLOTDEL_N.NSTD_FLAG,
                                                    :MWIPLOTDEL_N.NSTD_RET_FLOW,
                                                    :MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.NSTD_RET_OPER,
                                                    :MWIPLOTDEL_N.NSTD_TIME,
                                                    :MWIPLOTDEL_N.REP_FLAG,
                                                    :MWIPLOTDEL_N.REP_RET_OPER,
                                                    :MWIPLOTDEL_N.STR_RET_FLOW,
                                                    :MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.STR_RET_OPER,
                                                    :MWIPLOTDEL_N.START_FLAG,
                                                    :MWIPLOTDEL_N.START_TIME,
                                                    :MWIPLOTDEL_N.START_RES_ID,
                                                    :MWIPLOTDEL_N.END_FLAG,
                                                    :MWIPLOTDEL_N.END_TIME,
                                                    :MWIPLOTDEL_N.END_RES_ID,
                                                    :MWIPLOTDEL_N.SAMPLE_FLAG,
                                                    :MWIPLOTDEL_N.SAMPLE_WAIT_FLAG,
                                                    :MWIPLOTDEL_N.SAMPLE_RESULT,
                                                    :MWIPLOTDEL_N.FROM_TO_FLAG,
                                                    :MWIPLOTDEL_N.FROM_TO_LOT_ID,
                                                    :MWIPLOTDEL_N.SHIP_CODE,
                                                    :MWIPLOTDEL_N.SHIP_TIME,
                                                    :MWIPLOTDEL_N.ORG_DUE_TIME,
                                                    :MWIPLOTDEL_N.SCH_DUE_TIME,
                                                    :MWIPLOTDEL_N.CREATE_TIME,
                                                    :MWIPLOTDEL_N.FAC_IN_TIME,
                                                    :MWIPLOTDEL_N.FLOW_IN_TIME,
                                                    :MWIPLOTDEL_N.OPER_IN_TIME,
                                                    :MWIPLOTDEL_N.RESERVE_RES_ID,
                                                    :MWIPLOTDEL_N.PORT_ID,
                                                    :MWIPLOTDEL_N.BATCH_ID,
                                                    :MWIPLOTDEL_N.BATCH_SEQ,
                                                    :MWIPLOTDEL_N.ORDER_ID,
                                                    :MWIPLOTDEL_N.ADD_ORDER_ID_1,
                                                    :MWIPLOTDEL_N.ADD_ORDER_ID_2,
                                                    :MWIPLOTDEL_N.ADD_ORDER_ID_3,
                                                    :MWIPLOTDEL_N.LOT_LOCATION_1,
                                                    :MWIPLOTDEL_N.LOT_LOCATION_2,
                                                    :MWIPLOTDEL_N.LOT_LOCATION_3,
                                                    :MWIPLOTDEL_N.LOT_CMF_1,
                                                    :MWIPLOTDEL_N.LOT_CMF_2,
                                                    :MWIPLOTDEL_N.LOT_CMF_3,
                                                    :MWIPLOTDEL_N.LOT_CMF_4,
                                                    :MWIPLOTDEL_N.LOT_CMF_5,
                                                    :MWIPLOTDEL_N.LOT_CMF_6,
                                                    :MWIPLOTDEL_N.LOT_CMF_7,
                                                    :MWIPLOTDEL_N.LOT_CMF_8,
                                                    :MWIPLOTDEL_N.LOT_CMF_9,
                                                    :MWIPLOTDEL_N.LOT_CMF_10,
                                                    :MWIPLOTDEL_N.LOT_CMF_11,
                                                    :MWIPLOTDEL_N.LOT_CMF_12,
                                                    :MWIPLOTDEL_N.LOT_CMF_13,
                                                    :MWIPLOTDEL_N.LOT_CMF_14,
                                                    :MWIPLOTDEL_N.LOT_CMF_15,
                                                    :MWIPLOTDEL_N.LOT_CMF_16,
                                                    :MWIPLOTDEL_N.LOT_CMF_17,
                                                    :MWIPLOTDEL_N.LOT_CMF_18,
                                                    :MWIPLOTDEL_N.LOT_CMF_19,
                                                    :MWIPLOTDEL_N.LOT_CMF_20,
                                                    :MWIPLOTDEL_N.LOT_DEL_FLAG,
                                                    :MWIPLOTDEL_N.LOT_DEL_CODE,
                                                    :MWIPLOTDEL_N.LOT_DEL_TIME,
                                                    :MWIPLOTDEL_N.BOM_SET_ID,
                                                    :MWIPLOTDEL_N.BOM_SET_VERSION,
                                                    :MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ,
                                                    :MWIPLOTDEL_N.BOM_HIST_SEQ,
                                                    :MWIPLOTDEL_N.CRITICAL_RES_ID,
                                                    :MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID,
                                                    :MWIPLOTDEL_N.SAVE_RES_ID_1,
                                                    :MWIPLOTDEL_N.SAVE_RES_ID_2,
                                                    :MWIPLOTDEL_N.SUBRES_ID,
                                                    :MWIPLOTDEL_N.LOT_GROUP_ID_1,
                                                    :MWIPLOTDEL_N.LOT_GROUP_ID_2,
                                                    :MWIPLOTDEL_N.LOT_GROUP_ID_3,
                                                    :MWIPLOTDEL_N.YIELD_1,
                                                    :MWIPLOTDEL_N.YIELD_2,
                                                    :MWIPLOTDEL_N.YIELD_3,
                                                    :MWIPLOTDEL_N.GOOD_QTY,
                                                    :MWIPLOTDEL_N.RESV_FIELD_1,
                                                    :MWIPLOTDEL_N.RESV_FIELD_2,
                                                    :MWIPLOTDEL_N.RESV_FIELD_3,
                                                    :MWIPLOTDEL_N.RESV_FIELD_4,
                                                    :MWIPLOTDEL_N.RESV_FIELD_5,
                                                    :MWIPLOTDEL_N.RESV_FLAG_1,
                                                    :MWIPLOTDEL_N.RESV_FLAG_2,
                                                    :MWIPLOTDEL_N.RESV_FLAG_3,
                                                    :MWIPLOTDEL_N.RESV_FLAG_4,
                                                    :MWIPLOTDEL_N.RESV_FLAG_5,
                                                    :MWIPLOTDEL_N.FROM_TO_MAT_ID,
                                                    :MWIPLOTDEL_N.FROM_TO_MAT_VER,
                                                    :MWIPLOTDEL_N.FROM_TO_FLOW,
                                                    :MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.FROM_TO_OPER,
                                                    :MWIPLOTDEL_N.FROM_TO_QTY_1,
                                                    :MWIPLOTDEL_N.FROM_TO_QTY_2,
                                                    :MWIPLOTDEL_N.FROM_TO_QTY_3,
                                                    :MWIPLOTDEL_N.FROM_TO_HIST_SEQ,
                                                    :MWIPLOTDEL_N.OLD_FACTORY,
                                                    :MWIPLOTDEL_N.OLD_MAT_ID,
                                                    :MWIPLOTDEL_N.OLD_MAT_VER,
                                                    :MWIPLOTDEL_N.OLD_FLOW,
                                                    :MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM,
                                                    :MWIPLOTDEL_N.OLD_OPER,
                                                    :MWIPLOTDEL_N.OLD_QTY_1,
                                                    :MWIPLOTDEL_N.OLD_QTY_2,
                                                    :MWIPLOTDEL_N.OLD_QTY_3,
                                                    :MWIPLOTDEL_N.OLD_LOT_TYPE,
                                                    :MWIPLOTDEL_N.OLD_OWNER_CODE,
                                                    :MWIPLOTDEL_N.OLD_CREATE_CODE,
                                                    :MWIPLOTDEL_N.OLD_FAC_IN_TIME,
                                                    :MWIPLOTDEL_N.OLD_FLOW_IN_TIME,
                                                    :MWIPLOTDEL_N.OLD_OPER_IN_TIME,
                                                    :MWIPLOTDEL_N.TRAN_CMF_1,
                                                    :MWIPLOTDEL_N.TRAN_CMF_2,
                                                    :MWIPLOTDEL_N.TRAN_CMF_3,
                                                    :MWIPLOTDEL_N.TRAN_CMF_4,
                                                    :MWIPLOTDEL_N.TRAN_CMF_5,
                                                    :MWIPLOTDEL_N.TRAN_CMF_6,
                                                    :MWIPLOTDEL_N.TRAN_CMF_7,
                                                    :MWIPLOTDEL_N.TRAN_CMF_8,
                                                    :MWIPLOTDEL_N.TRAN_CMF_9,
                                                    :MWIPLOTDEL_N.TRAN_CMF_10,
                                                    :MWIPLOTDEL_N.TRAN_CMF_11,
                                                    :MWIPLOTDEL_N.TRAN_CMF_12,
                                                    :MWIPLOTDEL_N.TRAN_CMF_13,
                                                    :MWIPLOTDEL_N.TRAN_CMF_14,
                                                    :MWIPLOTDEL_N.TRAN_CMF_15,
                                                    :MWIPLOTDEL_N.TRAN_CMF_16,
                                                    :MWIPLOTDEL_N.TRAN_CMF_17,
                                                    :MWIPLOTDEL_N.TRAN_CMF_18,
                                                    :MWIPLOTDEL_N.TRAN_CMF_19,
                                                    :MWIPLOTDEL_N.TRAN_CMF_20,
                                                    :MWIPLOTDEL_N.TRAN_USER_ID,
                                                    :MWIPLOTDEL_N.TRAN_COMMENT,
                                                    :MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ,
                                                    :MWIPLOTDEL_N.MULTI_TR_KEY,
                                                    :MWIPLOTDEL_N.MULTI_TR_SEQ,
                                                    :MWIPLOTDEL_N.EXT_HIST_SEQ,
                                                    :MWIPLOTDEL_N.HIST_DEL_FLAG,
                                                    :MWIPLOTDEL_N.HIST_DEL_TIME,
                                                    :MWIPLOTDEL_N.HIST_DEL_USER_ID,
                                                    :MWIPLOTDEL_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3326;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPLOTDEL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(MWIPLOTDEL_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPLOTDEL_N.TRAN_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPLOTDEL_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPLOTDEL_N.TRAN_CODE);
            sqlstm.sqhstl[4] = (unsigned int  )13;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPLOTDEL_N.LOT_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPLOTDEL_N.FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPLOTDEL_N.MAT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MWIPLOTDEL_N.MAT_VER);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPLOTDEL_N.FLOW);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MWIPLOTDEL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPLOTDEL_N.OPER);
            sqlstm.sqhstl[11] = (unsigned int  )11;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MWIPLOTDEL_N.QTY_1);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MWIPLOTDEL_N.QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MWIPLOTDEL_N.QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPLOTDEL_N.CRR_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPLOTDEL_N.LOT_TYPE);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPLOTDEL_N.OWNER_CODE);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPLOTDEL_N.CREATE_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPLOTDEL_N.LOT_PRIORITY);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPLOTDEL_N.LOT_STATUS);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPLOTDEL_N.HOLD_FLAG);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPLOTDEL_N.HOLD_CODE);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPLOTDEL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPLOTDEL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(MWIPLOTDEL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_1);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_2);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(MWIPLOTDEL_N.CREATE_QTY_3);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MWIPLOTDEL_N.START_QTY_1);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(MWIPLOTDEL_N.START_QTY_2);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MWIPLOTDEL_N.START_QTY_3);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPLOTDEL_N.INV_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPLOTDEL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPLOTDEL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPLOTDEL_N.INV_UNIT);
            sqlstm.sqhstl[37] = (unsigned int  )11;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPLOTDEL_N.RWK_FLAG);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPLOTDEL_N.RWK_CODE);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MWIPLOTDEL_N.RWK_COUNT);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPLOTDEL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)&(MWIPLOTDEL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[42] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPLOTDEL_N.RWK_RET_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPLOTDEL_N.RWK_END_FLOW);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MWIPLOTDEL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPLOTDEL_N.RWK_END_OPER);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPLOTDEL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPLOTDEL_N.RWK_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPLOTDEL_N.NSTD_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)&(MWIPLOTDEL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[51] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MWIPLOTDEL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPLOTDEL_N.NSTD_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPLOTDEL_N.REP_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPLOTDEL_N.REP_RET_OPER);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPLOTDEL_N.STR_RET_FLOW);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPLOTDEL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPLOTDEL_N.STR_RET_OPER);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPLOTDEL_N.START_FLAG);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPLOTDEL_N.START_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPLOTDEL_N.START_RES_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPLOTDEL_N.END_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPLOTDEL_N.END_TIME);
            sqlstm.sqhstl[63] = (unsigned int  )15;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPLOTDEL_N.END_RES_ID);
            sqlstm.sqhstl[64] = (unsigned int  )21;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPLOTDEL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MWIPLOTDEL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MWIPLOTDEL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPLOTDEL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[69] = (unsigned int  )26;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPLOTDEL_N.SHIP_CODE);
            sqlstm.sqhstl[70] = (unsigned int  )11;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPLOTDEL_N.SHIP_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPLOTDEL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPLOTDEL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPLOTDEL_N.CREATE_TIME);
            sqlstm.sqhstl[74] = (unsigned int  )15;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPLOTDEL_N.FAC_IN_TIME);
            sqlstm.sqhstl[75] = (unsigned int  )15;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPLOTDEL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPLOTDEL_N.OPER_IN_TIME);
            sqlstm.sqhstl[77] = (unsigned int  )15;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MWIPLOTDEL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MWIPLOTDEL_N.PORT_ID);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPLOTDEL_N.BATCH_ID);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPLOTDEL_N.BATCH_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPLOTDEL_N.ORDER_ID);
            sqlstm.sqhstl[82] = (unsigned int  )26;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[83] = (unsigned int  )26;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[84] = (unsigned int  )26;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPLOTDEL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[85] = (unsigned int  )26;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPLOTDEL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[88] = (unsigned int  )21;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_1);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_2);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_3);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_4);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_5);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_6);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_7);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_8);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_9);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_10);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_11);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_12);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_13);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_14);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_15);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_16);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_17);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_18);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_19);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MWIPLOTDEL_N.LOT_CMF_20);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[109] = (unsigned int  )2;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[110] = (unsigned int  )11;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MWIPLOTDEL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[111] = (unsigned int  )15;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MWIPLOTDEL_N.BOM_SET_ID);
            sqlstm.sqhstl[112] = (unsigned int  )26;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)&(MWIPLOTDEL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[113] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)&(MWIPLOTDEL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[114] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)&(MWIPLOTDEL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[115] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[116] = (unsigned int  )21;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MWIPLOTDEL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MWIPLOTDEL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[119] = (unsigned int  )21;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MWIPLOTDEL_N.SUBRES_ID);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[121] = (unsigned int  )26;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[122] = (unsigned int  )26;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MWIPLOTDEL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[123] = (unsigned int  )26;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)&(MWIPLOTDEL_N.YIELD_1);
            sqlstm.sqhstl[124] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)&(MWIPLOTDEL_N.YIELD_2);
            sqlstm.sqhstl[125] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)&(MWIPLOTDEL_N.YIELD_3);
            sqlstm.sqhstl[126] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)&(MWIPLOTDEL_N.GOOD_QTY);
            sqlstm.sqhstl[127] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_1);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_2);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_3);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_4);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MWIPLOTDEL_N.RESV_FIELD_5);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_1);
            sqlstm.sqhstl[133] = (unsigned int  )2;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_2);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_3);
            sqlstm.sqhstl[135] = (unsigned int  )2;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_4);
            sqlstm.sqhstl[136] = (unsigned int  )2;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MWIPLOTDEL_N.RESV_FLAG_5);
            sqlstm.sqhstl[137] = (unsigned int  )2;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MWIPLOTDEL_N.FROM_TO_MAT_ID);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_MAT_VER);
            sqlstm.sqhstl[139] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MWIPLOTDEL_N.FROM_TO_FLOW);
            sqlstm.sqhstl[140] = (unsigned int  )21;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_FLOW_SEQ_NUM);
            sqlstm.sqhstl[141] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MWIPLOTDEL_N.FROM_TO_OPER);
            sqlstm.sqhstl[142] = (unsigned int  )11;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_1);
            sqlstm.sqhstl[143] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_2);
            sqlstm.sqhstl[144] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_QTY_3);
            sqlstm.sqhstl[145] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)&(MWIPLOTDEL_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[146] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MWIPLOTDEL_N.OLD_FACTORY);
            sqlstm.sqhstl[147] = (unsigned int  )11;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MWIPLOTDEL_N.OLD_MAT_ID);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)&(MWIPLOTDEL_N.OLD_MAT_VER);
            sqlstm.sqhstl[149] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW);
            sqlstm.sqhstl[150] = (unsigned int  )21;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)&(MWIPLOTDEL_N.OLD_FLOW_SEQ_NUM);
            sqlstm.sqhstl[151] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MWIPLOTDEL_N.OLD_OPER);
            sqlstm.sqhstl[152] = (unsigned int  )11;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_1);
            sqlstm.sqhstl[153] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_2);
            sqlstm.sqhstl[154] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)&(MWIPLOTDEL_N.OLD_QTY_3);
            sqlstm.sqhstl[155] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MWIPLOTDEL_N.OLD_LOT_TYPE);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MWIPLOTDEL_N.OLD_OWNER_CODE);
            sqlstm.sqhstl[157] = (unsigned int  )11;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MWIPLOTDEL_N.OLD_CREATE_CODE);
            sqlstm.sqhstl[158] = (unsigned int  )11;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MWIPLOTDEL_N.OLD_FAC_IN_TIME);
            sqlstm.sqhstl[159] = (unsigned int  )15;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MWIPLOTDEL_N.OLD_FLOW_IN_TIME);
            sqlstm.sqhstl[160] = (unsigned int  )15;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MWIPLOTDEL_N.OLD_OPER_IN_TIME);
            sqlstm.sqhstl[161] = (unsigned int  )15;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_1);
            sqlstm.sqhstl[162] = (unsigned int  )31;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_2);
            sqlstm.sqhstl[163] = (unsigned int  )31;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_3);
            sqlstm.sqhstl[164] = (unsigned int  )31;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_4);
            sqlstm.sqhstl[165] = (unsigned int  )31;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_5);
            sqlstm.sqhstl[166] = (unsigned int  )31;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_6);
            sqlstm.sqhstl[167] = (unsigned int  )31;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_7);
            sqlstm.sqhstl[168] = (unsigned int  )31;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_8);
            sqlstm.sqhstl[169] = (unsigned int  )31;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_9);
            sqlstm.sqhstl[170] = (unsigned int  )31;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_10);
            sqlstm.sqhstl[171] = (unsigned int  )31;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_11);
            sqlstm.sqhstl[172] = (unsigned int  )31;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_12);
            sqlstm.sqhstl[173] = (unsigned int  )31;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_13);
            sqlstm.sqhstl[174] = (unsigned int  )31;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_14);
            sqlstm.sqhstl[175] = (unsigned int  )31;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_15);
            sqlstm.sqhstl[176] = (unsigned int  )31;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_16);
            sqlstm.sqhstl[177] = (unsigned int  )31;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_17);
            sqlstm.sqhstl[178] = (unsigned int  )31;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_18);
            sqlstm.sqhstl[179] = (unsigned int  )31;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_19);
            sqlstm.sqhstl[180] = (unsigned int  )31;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MWIPLOTDEL_N.TRAN_CMF_20);
            sqlstm.sqhstl[181] = (unsigned int  )31;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MWIPLOTDEL_N.TRAN_USER_ID);
            sqlstm.sqhstl[182] = (unsigned int  )21;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MWIPLOTDEL_N.TRAN_COMMENT);
            sqlstm.sqhstl[183] = (unsigned int  )401;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)&(MWIPLOTDEL_N.PREV_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[184] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MWIPLOTDEL_N.MULTI_TR_KEY);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)&(MWIPLOTDEL_N.MULTI_TR_SEQ);
            sqlstm.sqhstl[186] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)&(MWIPLOTDEL_N.EXT_HIST_SEQ);
            sqlstm.sqhstl[187] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[188] = (unsigned int  )2;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_TIME);
            sqlstm.sqhstl[189] = (unsigned int  )15;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[190] = (unsigned int  )21;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MWIPLOTDEL_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[191] = (unsigned int  )401;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
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
        DBC_del_null_mwiplotdel(&MWIPLOTDEL_N, MWIPLOTDEL);
    }
    DB_stop_query_timer("DBC_fetch_mwiplotdel", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwiplotdel(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPLOTDEL_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 195;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4109;
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
    DB_stop_query_timer("DBC_close_mwiplotdel", sel_type);
}


/* Initialize Function */
void DBC_init_mwiplotdel(struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* memset by Space */
    memset(MWIPLOTDEL, ' ', sizeof(struct MWIPLOTDEL_TAG));
    
    MWIPLOTDEL->HIST_SEQ = 0;
    MWIPLOTDEL->MAT_VER = 0;
    MWIPLOTDEL->FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->QTY_1 = 0;
    MWIPLOTDEL->QTY_2 = 0;
    MWIPLOTDEL->QTY_3 = 0;
    MWIPLOTDEL->OPER_IN_QTY_1 = 0;
    MWIPLOTDEL->OPER_IN_QTY_2 = 0;
    MWIPLOTDEL->OPER_IN_QTY_3 = 0;
    MWIPLOTDEL->CREATE_QTY_1 = 0;
    MWIPLOTDEL->CREATE_QTY_2 = 0;
    MWIPLOTDEL->CREATE_QTY_3 = 0;
    MWIPLOTDEL->START_QTY_1 = 0;
    MWIPLOTDEL->START_QTY_2 = 0;
    MWIPLOTDEL->START_QTY_3 = 0;
    MWIPLOTDEL->RWK_COUNT = 0;
    MWIPLOTDEL->RWK_RET_FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->RWK_END_FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->NSTD_RET_FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->BATCH_SEQ = 0;
    MWIPLOTDEL->BOM_SET_VERSION = 0;
    MWIPLOTDEL->BOM_ACTIVE_HIST_SEQ = 0;
    MWIPLOTDEL->BOM_HIST_SEQ = 0;
    MWIPLOTDEL->FROM_TO_MAT_VER = 0;
    MWIPLOTDEL->FROM_TO_FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->FROM_TO_QTY_1 = 0;
    MWIPLOTDEL->FROM_TO_QTY_2 = 0;
    MWIPLOTDEL->FROM_TO_QTY_3 = 0;
    MWIPLOTDEL->FROM_TO_HIST_SEQ = 0;
    MWIPLOTDEL->OLD_MAT_VER = 0;
    MWIPLOTDEL->OLD_FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->OLD_QTY_1 = 0;
    MWIPLOTDEL->OLD_QTY_2 = 0;
    MWIPLOTDEL->OLD_QTY_3 = 0;
    MWIPLOTDEL->PREV_ACTIVE_HIST_SEQ = 0;
    MWIPLOTDEL->MULTI_TR_SEQ = 0;
    MWIPLOTDEL->STR_RET_FLOW_SEQ_NUM = 0;
    MWIPLOTDEL->YIELD_1 = 0;
    MWIPLOTDEL->YIELD_2 = 0;
    MWIPLOTDEL->YIELD_3 = 0;
    MWIPLOTDEL->GOOD_QTY = 0;
    MWIPLOTDEL->EXT_HIST_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_mwiplotdel(struct MWIPLOTDEL_N_TAG *MWIPLOTDEL_N, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    /* memset by NULL */
    memset(MWIPLOTDEL_N, '\0', sizeof(struct MWIPLOTDEL_N_TAG));
    
    MEMCPY_AN(MWIPLOTDEL_N->LOT_ID, MWIPLOTDEL->LOT_ID, sizeof(MWIPLOTDEL->LOT_ID));
    MWIPLOTDEL_N->HIST_SEQ = MWIPLOTDEL->HIST_SEQ;
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_TIME, MWIPLOTDEL->TRAN_TIME, sizeof(MWIPLOTDEL->TRAN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->SYS_TRAN_TIME, MWIPLOTDEL->SYS_TRAN_TIME, sizeof(MWIPLOTDEL->SYS_TRAN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CODE, MWIPLOTDEL->TRAN_CODE, sizeof(MWIPLOTDEL->TRAN_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_DESC, MWIPLOTDEL->LOT_DESC, sizeof(MWIPLOTDEL->LOT_DESC));
    MEMCPY_AN(MWIPLOTDEL_N->FACTORY, MWIPLOTDEL->FACTORY, sizeof(MWIPLOTDEL->FACTORY));
    MEMCPY_AN(MWIPLOTDEL_N->MAT_ID, MWIPLOTDEL->MAT_ID, sizeof(MWIPLOTDEL->MAT_ID));
    MWIPLOTDEL_N->MAT_VER = MWIPLOTDEL->MAT_VER;
    MEMCPY_AN(MWIPLOTDEL_N->FLOW, MWIPLOTDEL->FLOW, sizeof(MWIPLOTDEL->FLOW));
    MWIPLOTDEL_N->FLOW_SEQ_NUM = MWIPLOTDEL->FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->OPER, MWIPLOTDEL->OPER, sizeof(MWIPLOTDEL->OPER));
    MWIPLOTDEL_N->QTY_1 = MWIPLOTDEL->QTY_1;
    MWIPLOTDEL_N->QTY_2 = MWIPLOTDEL->QTY_2;
    MWIPLOTDEL_N->QTY_3 = MWIPLOTDEL->QTY_3;
    MEMCPY_AN(MWIPLOTDEL_N->CRR_ID, MWIPLOTDEL->CRR_ID, sizeof(MWIPLOTDEL->CRR_ID));
    MWIPLOTDEL_N->LOT_TYPE[0] = MWIPLOTDEL->LOT_TYPE;
    MEMCPY_AN(MWIPLOTDEL_N->OWNER_CODE, MWIPLOTDEL->OWNER_CODE, sizeof(MWIPLOTDEL->OWNER_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->CREATE_CODE, MWIPLOTDEL->CREATE_CODE, sizeof(MWIPLOTDEL->CREATE_CODE));
    MWIPLOTDEL_N->LOT_PRIORITY[0] = MWIPLOTDEL->LOT_PRIORITY;
    MEMCPY_AN(MWIPLOTDEL_N->LOT_STATUS, MWIPLOTDEL->LOT_STATUS, sizeof(MWIPLOTDEL->LOT_STATUS));
    MWIPLOTDEL_N->HOLD_FLAG[0] = MWIPLOTDEL->HOLD_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->HOLD_CODE, MWIPLOTDEL->HOLD_CODE, sizeof(MWIPLOTDEL->HOLD_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->HOLD_PASSWORD, MWIPLOTDEL->HOLD_PASSWORD, sizeof(MWIPLOTDEL->HOLD_PASSWORD));
    MEMCPY_AN(MWIPLOTDEL_N->HOLD_PRV_GRP_ID, MWIPLOTDEL->HOLD_PRV_GRP_ID, sizeof(MWIPLOTDEL->HOLD_PRV_GRP_ID));
    MWIPLOTDEL_N->OPER_IN_QTY_1 = MWIPLOTDEL->OPER_IN_QTY_1;
    MWIPLOTDEL_N->OPER_IN_QTY_2 = MWIPLOTDEL->OPER_IN_QTY_2;
    MWIPLOTDEL_N->OPER_IN_QTY_3 = MWIPLOTDEL->OPER_IN_QTY_3;
    MWIPLOTDEL_N->CREATE_QTY_1 = MWIPLOTDEL->CREATE_QTY_1;
    MWIPLOTDEL_N->CREATE_QTY_2 = MWIPLOTDEL->CREATE_QTY_2;
    MWIPLOTDEL_N->CREATE_QTY_3 = MWIPLOTDEL->CREATE_QTY_3;
    MWIPLOTDEL_N->START_QTY_1 = MWIPLOTDEL->START_QTY_1;
    MWIPLOTDEL_N->START_QTY_2 = MWIPLOTDEL->START_QTY_2;
    MWIPLOTDEL_N->START_QTY_3 = MWIPLOTDEL->START_QTY_3;
    MWIPLOTDEL_N->INV_FLAG[0] = MWIPLOTDEL->INV_FLAG;
    MWIPLOTDEL_N->TRANSIT_FLAG[0] = MWIPLOTDEL->TRANSIT_FLAG;
    MWIPLOTDEL_N->UNIT_EXIST_FLAG[0] = MWIPLOTDEL->UNIT_EXIST_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->INV_UNIT, MWIPLOTDEL->INV_UNIT, sizeof(MWIPLOTDEL->INV_UNIT));
    MWIPLOTDEL_N->RWK_FLAG[0] = MWIPLOTDEL->RWK_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->RWK_CODE, MWIPLOTDEL->RWK_CODE, sizeof(MWIPLOTDEL->RWK_CODE));
    MWIPLOTDEL_N->RWK_COUNT = MWIPLOTDEL->RWK_COUNT;
    MEMCPY_AN(MWIPLOTDEL_N->RWK_RET_FLOW, MWIPLOTDEL->RWK_RET_FLOW, sizeof(MWIPLOTDEL->RWK_RET_FLOW));
    MWIPLOTDEL_N->RWK_RET_FLOW_SEQ_NUM = MWIPLOTDEL->RWK_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->RWK_RET_OPER, MWIPLOTDEL->RWK_RET_OPER, sizeof(MWIPLOTDEL->RWK_RET_OPER));
    MEMCPY_AN(MWIPLOTDEL_N->RWK_END_FLOW, MWIPLOTDEL->RWK_END_FLOW, sizeof(MWIPLOTDEL->RWK_END_FLOW));
    MWIPLOTDEL_N->RWK_END_FLOW_SEQ_NUM = MWIPLOTDEL->RWK_END_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->RWK_END_OPER, MWIPLOTDEL->RWK_END_OPER, sizeof(MWIPLOTDEL->RWK_END_OPER));
    MWIPLOTDEL_N->RWK_RET_CLEAR_FLAG[0] = MWIPLOTDEL->RWK_RET_CLEAR_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->RWK_TIME, MWIPLOTDEL->RWK_TIME, sizeof(MWIPLOTDEL->RWK_TIME));
    MWIPLOTDEL_N->NSTD_FLAG[0] = MWIPLOTDEL->NSTD_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->NSTD_RET_FLOW, MWIPLOTDEL->NSTD_RET_FLOW, sizeof(MWIPLOTDEL->NSTD_RET_FLOW));
    MWIPLOTDEL_N->NSTD_RET_FLOW_SEQ_NUM = MWIPLOTDEL->NSTD_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->NSTD_RET_OPER, MWIPLOTDEL->NSTD_RET_OPER, sizeof(MWIPLOTDEL->NSTD_RET_OPER));
    MEMCPY_AN(MWIPLOTDEL_N->NSTD_TIME, MWIPLOTDEL->NSTD_TIME, sizeof(MWIPLOTDEL->NSTD_TIME));
    MWIPLOTDEL_N->REP_FLAG[0] = MWIPLOTDEL->REP_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->REP_RET_OPER, MWIPLOTDEL->REP_RET_OPER, sizeof(MWIPLOTDEL->REP_RET_OPER));
    MEMCPY_AN(MWIPLOTDEL_N->STR_RET_FLOW, MWIPLOTDEL->STR_RET_FLOW, sizeof(MWIPLOTDEL->STR_RET_FLOW));
    MWIPLOTDEL_N->STR_RET_FLOW_SEQ_NUM = MWIPLOTDEL->STR_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->STR_RET_OPER, MWIPLOTDEL->STR_RET_OPER, sizeof(MWIPLOTDEL->STR_RET_OPER));
    MWIPLOTDEL_N->START_FLAG[0] = MWIPLOTDEL->START_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->START_TIME, MWIPLOTDEL->START_TIME, sizeof(MWIPLOTDEL->START_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->START_RES_ID, MWIPLOTDEL->START_RES_ID, sizeof(MWIPLOTDEL->START_RES_ID));
    MWIPLOTDEL_N->END_FLAG[0] = MWIPLOTDEL->END_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->END_TIME, MWIPLOTDEL->END_TIME, sizeof(MWIPLOTDEL->END_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->END_RES_ID, MWIPLOTDEL->END_RES_ID, sizeof(MWIPLOTDEL->END_RES_ID));
    MWIPLOTDEL_N->SAMPLE_FLAG[0] = MWIPLOTDEL->SAMPLE_FLAG;
    MWIPLOTDEL_N->SAMPLE_WAIT_FLAG[0] = MWIPLOTDEL->SAMPLE_WAIT_FLAG;
    MWIPLOTDEL_N->SAMPLE_RESULT[0] = MWIPLOTDEL->SAMPLE_RESULT;
    MWIPLOTDEL_N->FROM_TO_FLAG[0] = MWIPLOTDEL->FROM_TO_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->FROM_TO_LOT_ID, MWIPLOTDEL->FROM_TO_LOT_ID, sizeof(MWIPLOTDEL->FROM_TO_LOT_ID));
    MEMCPY_AN(MWIPLOTDEL_N->SHIP_CODE, MWIPLOTDEL->SHIP_CODE, sizeof(MWIPLOTDEL->SHIP_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->SHIP_TIME, MWIPLOTDEL->SHIP_TIME, sizeof(MWIPLOTDEL->SHIP_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->ORG_DUE_TIME, MWIPLOTDEL->ORG_DUE_TIME, sizeof(MWIPLOTDEL->ORG_DUE_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->SCH_DUE_TIME, MWIPLOTDEL->SCH_DUE_TIME, sizeof(MWIPLOTDEL->SCH_DUE_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->CREATE_TIME, MWIPLOTDEL->CREATE_TIME, sizeof(MWIPLOTDEL->CREATE_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->FAC_IN_TIME, MWIPLOTDEL->FAC_IN_TIME, sizeof(MWIPLOTDEL->FAC_IN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->FLOW_IN_TIME, MWIPLOTDEL->FLOW_IN_TIME, sizeof(MWIPLOTDEL->FLOW_IN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->OPER_IN_TIME, MWIPLOTDEL->OPER_IN_TIME, sizeof(MWIPLOTDEL->OPER_IN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->RESERVE_RES_ID, MWIPLOTDEL->RESERVE_RES_ID, sizeof(MWIPLOTDEL->RESERVE_RES_ID));
    MEMCPY_AN(MWIPLOTDEL_N->PORT_ID, MWIPLOTDEL->PORT_ID, sizeof(MWIPLOTDEL->PORT_ID));
    MEMCPY_AN(MWIPLOTDEL_N->BATCH_ID, MWIPLOTDEL->BATCH_ID, sizeof(MWIPLOTDEL->BATCH_ID));
    MWIPLOTDEL_N->BATCH_SEQ = MWIPLOTDEL->BATCH_SEQ;
    MEMCPY_AN(MWIPLOTDEL_N->ORDER_ID, MWIPLOTDEL->ORDER_ID, sizeof(MWIPLOTDEL->ORDER_ID));
    MEMCPY_AN(MWIPLOTDEL_N->ADD_ORDER_ID_1, MWIPLOTDEL->ADD_ORDER_ID_1, sizeof(MWIPLOTDEL->ADD_ORDER_ID_1));
    MEMCPY_AN(MWIPLOTDEL_N->ADD_ORDER_ID_2, MWIPLOTDEL->ADD_ORDER_ID_2, sizeof(MWIPLOTDEL->ADD_ORDER_ID_2));
    MEMCPY_AN(MWIPLOTDEL_N->ADD_ORDER_ID_3, MWIPLOTDEL->ADD_ORDER_ID_3, sizeof(MWIPLOTDEL->ADD_ORDER_ID_3));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_LOCATION_1, MWIPLOTDEL->LOT_LOCATION_1, sizeof(MWIPLOTDEL->LOT_LOCATION_1));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_LOCATION_2, MWIPLOTDEL->LOT_LOCATION_2, sizeof(MWIPLOTDEL->LOT_LOCATION_2));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_LOCATION_3, MWIPLOTDEL->LOT_LOCATION_3, sizeof(MWIPLOTDEL->LOT_LOCATION_3));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_1, MWIPLOTDEL->LOT_CMF_1, sizeof(MWIPLOTDEL->LOT_CMF_1));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_2, MWIPLOTDEL->LOT_CMF_2, sizeof(MWIPLOTDEL->LOT_CMF_2));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_3, MWIPLOTDEL->LOT_CMF_3, sizeof(MWIPLOTDEL->LOT_CMF_3));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_4, MWIPLOTDEL->LOT_CMF_4, sizeof(MWIPLOTDEL->LOT_CMF_4));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_5, MWIPLOTDEL->LOT_CMF_5, sizeof(MWIPLOTDEL->LOT_CMF_5));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_6, MWIPLOTDEL->LOT_CMF_6, sizeof(MWIPLOTDEL->LOT_CMF_6));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_7, MWIPLOTDEL->LOT_CMF_7, sizeof(MWIPLOTDEL->LOT_CMF_7));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_8, MWIPLOTDEL->LOT_CMF_8, sizeof(MWIPLOTDEL->LOT_CMF_8));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_9, MWIPLOTDEL->LOT_CMF_9, sizeof(MWIPLOTDEL->LOT_CMF_9));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_10, MWIPLOTDEL->LOT_CMF_10, sizeof(MWIPLOTDEL->LOT_CMF_10));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_11, MWIPLOTDEL->LOT_CMF_11, sizeof(MWIPLOTDEL->LOT_CMF_11));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_12, MWIPLOTDEL->LOT_CMF_12, sizeof(MWIPLOTDEL->LOT_CMF_12));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_13, MWIPLOTDEL->LOT_CMF_13, sizeof(MWIPLOTDEL->LOT_CMF_13));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_14, MWIPLOTDEL->LOT_CMF_14, sizeof(MWIPLOTDEL->LOT_CMF_14));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_15, MWIPLOTDEL->LOT_CMF_15, sizeof(MWIPLOTDEL->LOT_CMF_15));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_16, MWIPLOTDEL->LOT_CMF_16, sizeof(MWIPLOTDEL->LOT_CMF_16));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_17, MWIPLOTDEL->LOT_CMF_17, sizeof(MWIPLOTDEL->LOT_CMF_17));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_18, MWIPLOTDEL->LOT_CMF_18, sizeof(MWIPLOTDEL->LOT_CMF_18));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_19, MWIPLOTDEL->LOT_CMF_19, sizeof(MWIPLOTDEL->LOT_CMF_19));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_CMF_20, MWIPLOTDEL->LOT_CMF_20, sizeof(MWIPLOTDEL->LOT_CMF_20));
    MWIPLOTDEL_N->LOT_DEL_FLAG[0] = MWIPLOTDEL->LOT_DEL_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->LOT_DEL_CODE, MWIPLOTDEL->LOT_DEL_CODE, sizeof(MWIPLOTDEL->LOT_DEL_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_DEL_TIME, MWIPLOTDEL->LOT_DEL_TIME, sizeof(MWIPLOTDEL->LOT_DEL_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->BOM_SET_ID, MWIPLOTDEL->BOM_SET_ID, sizeof(MWIPLOTDEL->BOM_SET_ID));
    MWIPLOTDEL_N->BOM_SET_VERSION = MWIPLOTDEL->BOM_SET_VERSION;
    MWIPLOTDEL_N->BOM_ACTIVE_HIST_SEQ = MWIPLOTDEL->BOM_ACTIVE_HIST_SEQ;
    MWIPLOTDEL_N->BOM_HIST_SEQ = MWIPLOTDEL->BOM_HIST_SEQ;
    MEMCPY_AN(MWIPLOTDEL_N->CRITICAL_RES_ID, MWIPLOTDEL->CRITICAL_RES_ID, sizeof(MWIPLOTDEL->CRITICAL_RES_ID));
    MEMCPY_AN(MWIPLOTDEL_N->CRITICAL_RES_GROUP_ID, MWIPLOTDEL->CRITICAL_RES_GROUP_ID, sizeof(MWIPLOTDEL->CRITICAL_RES_GROUP_ID));
    MEMCPY_AN(MWIPLOTDEL_N->SAVE_RES_ID_1, MWIPLOTDEL->SAVE_RES_ID_1, sizeof(MWIPLOTDEL->SAVE_RES_ID_1));
    MEMCPY_AN(MWIPLOTDEL_N->SAVE_RES_ID_2, MWIPLOTDEL->SAVE_RES_ID_2, sizeof(MWIPLOTDEL->SAVE_RES_ID_2));
    MEMCPY_AN(MWIPLOTDEL_N->SUBRES_ID, MWIPLOTDEL->SUBRES_ID, sizeof(MWIPLOTDEL->SUBRES_ID));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_GROUP_ID_1, MWIPLOTDEL->LOT_GROUP_ID_1, sizeof(MWIPLOTDEL->LOT_GROUP_ID_1));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_GROUP_ID_2, MWIPLOTDEL->LOT_GROUP_ID_2, sizeof(MWIPLOTDEL->LOT_GROUP_ID_2));
    MEMCPY_AN(MWIPLOTDEL_N->LOT_GROUP_ID_3, MWIPLOTDEL->LOT_GROUP_ID_3, sizeof(MWIPLOTDEL->LOT_GROUP_ID_3));
    MWIPLOTDEL_N->YIELD_1 = MWIPLOTDEL->YIELD_1;
    MWIPLOTDEL_N->YIELD_2 = MWIPLOTDEL->YIELD_2;
    MWIPLOTDEL_N->YIELD_3 = MWIPLOTDEL->YIELD_3;
    MWIPLOTDEL_N->GOOD_QTY = MWIPLOTDEL->GOOD_QTY;
    MEMCPY_AN(MWIPLOTDEL_N->RESV_FIELD_1, MWIPLOTDEL->RESV_FIELD_1, sizeof(MWIPLOTDEL->RESV_FIELD_1));
    MEMCPY_AN(MWIPLOTDEL_N->RESV_FIELD_2, MWIPLOTDEL->RESV_FIELD_2, sizeof(MWIPLOTDEL->RESV_FIELD_2));
    MEMCPY_AN(MWIPLOTDEL_N->RESV_FIELD_3, MWIPLOTDEL->RESV_FIELD_3, sizeof(MWIPLOTDEL->RESV_FIELD_3));
    MEMCPY_AN(MWIPLOTDEL_N->RESV_FIELD_4, MWIPLOTDEL->RESV_FIELD_4, sizeof(MWIPLOTDEL->RESV_FIELD_4));
    MEMCPY_AN(MWIPLOTDEL_N->RESV_FIELD_5, MWIPLOTDEL->RESV_FIELD_5, sizeof(MWIPLOTDEL->RESV_FIELD_5));
    MWIPLOTDEL_N->RESV_FLAG_1[0] = MWIPLOTDEL->RESV_FLAG_1;
    MWIPLOTDEL_N->RESV_FLAG_2[0] = MWIPLOTDEL->RESV_FLAG_2;
    MWIPLOTDEL_N->RESV_FLAG_3[0] = MWIPLOTDEL->RESV_FLAG_3;
    MWIPLOTDEL_N->RESV_FLAG_4[0] = MWIPLOTDEL->RESV_FLAG_4;
    MWIPLOTDEL_N->RESV_FLAG_5[0] = MWIPLOTDEL->RESV_FLAG_5;
    MEMCPY_AN(MWIPLOTDEL_N->FROM_TO_MAT_ID, MWIPLOTDEL->FROM_TO_MAT_ID, sizeof(MWIPLOTDEL->FROM_TO_MAT_ID));
    MWIPLOTDEL_N->FROM_TO_MAT_VER = MWIPLOTDEL->FROM_TO_MAT_VER;
    MEMCPY_AN(MWIPLOTDEL_N->FROM_TO_FLOW, MWIPLOTDEL->FROM_TO_FLOW, sizeof(MWIPLOTDEL->FROM_TO_FLOW));
    MWIPLOTDEL_N->FROM_TO_FLOW_SEQ_NUM = MWIPLOTDEL->FROM_TO_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->FROM_TO_OPER, MWIPLOTDEL->FROM_TO_OPER, sizeof(MWIPLOTDEL->FROM_TO_OPER));
    MWIPLOTDEL_N->FROM_TO_QTY_1 = MWIPLOTDEL->FROM_TO_QTY_1;
    MWIPLOTDEL_N->FROM_TO_QTY_2 = MWIPLOTDEL->FROM_TO_QTY_2;
    MWIPLOTDEL_N->FROM_TO_QTY_3 = MWIPLOTDEL->FROM_TO_QTY_3;
    MWIPLOTDEL_N->FROM_TO_HIST_SEQ = MWIPLOTDEL->FROM_TO_HIST_SEQ;
    MEMCPY_AN(MWIPLOTDEL_N->OLD_FACTORY, MWIPLOTDEL->OLD_FACTORY, sizeof(MWIPLOTDEL->OLD_FACTORY));
    MEMCPY_AN(MWIPLOTDEL_N->OLD_MAT_ID, MWIPLOTDEL->OLD_MAT_ID, sizeof(MWIPLOTDEL->OLD_MAT_ID));
    MWIPLOTDEL_N->OLD_MAT_VER = MWIPLOTDEL->OLD_MAT_VER;
    MEMCPY_AN(MWIPLOTDEL_N->OLD_FLOW, MWIPLOTDEL->OLD_FLOW, sizeof(MWIPLOTDEL->OLD_FLOW));
    MWIPLOTDEL_N->OLD_FLOW_SEQ_NUM = MWIPLOTDEL->OLD_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPLOTDEL_N->OLD_OPER, MWIPLOTDEL->OLD_OPER, sizeof(MWIPLOTDEL->OLD_OPER));
    MWIPLOTDEL_N->OLD_QTY_1 = MWIPLOTDEL->OLD_QTY_1;
    MWIPLOTDEL_N->OLD_QTY_2 = MWIPLOTDEL->OLD_QTY_2;
    MWIPLOTDEL_N->OLD_QTY_3 = MWIPLOTDEL->OLD_QTY_3;
    MWIPLOTDEL_N->OLD_LOT_TYPE[0] = MWIPLOTDEL->OLD_LOT_TYPE;
    MEMCPY_AN(MWIPLOTDEL_N->OLD_OWNER_CODE, MWIPLOTDEL->OLD_OWNER_CODE, sizeof(MWIPLOTDEL->OLD_OWNER_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->OLD_CREATE_CODE, MWIPLOTDEL->OLD_CREATE_CODE, sizeof(MWIPLOTDEL->OLD_CREATE_CODE));
    MEMCPY_AN(MWIPLOTDEL_N->OLD_FAC_IN_TIME, MWIPLOTDEL->OLD_FAC_IN_TIME, sizeof(MWIPLOTDEL->OLD_FAC_IN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->OLD_FLOW_IN_TIME, MWIPLOTDEL->OLD_FLOW_IN_TIME, sizeof(MWIPLOTDEL->OLD_FLOW_IN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->OLD_OPER_IN_TIME, MWIPLOTDEL->OLD_OPER_IN_TIME, sizeof(MWIPLOTDEL->OLD_OPER_IN_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_1, MWIPLOTDEL->TRAN_CMF_1, sizeof(MWIPLOTDEL->TRAN_CMF_1));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_2, MWIPLOTDEL->TRAN_CMF_2, sizeof(MWIPLOTDEL->TRAN_CMF_2));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_3, MWIPLOTDEL->TRAN_CMF_3, sizeof(MWIPLOTDEL->TRAN_CMF_3));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_4, MWIPLOTDEL->TRAN_CMF_4, sizeof(MWIPLOTDEL->TRAN_CMF_4));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_5, MWIPLOTDEL->TRAN_CMF_5, sizeof(MWIPLOTDEL->TRAN_CMF_5));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_6, MWIPLOTDEL->TRAN_CMF_6, sizeof(MWIPLOTDEL->TRAN_CMF_6));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_7, MWIPLOTDEL->TRAN_CMF_7, sizeof(MWIPLOTDEL->TRAN_CMF_7));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_8, MWIPLOTDEL->TRAN_CMF_8, sizeof(MWIPLOTDEL->TRAN_CMF_8));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_9, MWIPLOTDEL->TRAN_CMF_9, sizeof(MWIPLOTDEL->TRAN_CMF_9));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_10, MWIPLOTDEL->TRAN_CMF_10, sizeof(MWIPLOTDEL->TRAN_CMF_10));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_11, MWIPLOTDEL->TRAN_CMF_11, sizeof(MWIPLOTDEL->TRAN_CMF_11));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_12, MWIPLOTDEL->TRAN_CMF_12, sizeof(MWIPLOTDEL->TRAN_CMF_12));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_13, MWIPLOTDEL->TRAN_CMF_13, sizeof(MWIPLOTDEL->TRAN_CMF_13));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_14, MWIPLOTDEL->TRAN_CMF_14, sizeof(MWIPLOTDEL->TRAN_CMF_14));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_15, MWIPLOTDEL->TRAN_CMF_15, sizeof(MWIPLOTDEL->TRAN_CMF_15));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_16, MWIPLOTDEL->TRAN_CMF_16, sizeof(MWIPLOTDEL->TRAN_CMF_16));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_17, MWIPLOTDEL->TRAN_CMF_17, sizeof(MWIPLOTDEL->TRAN_CMF_17));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_18, MWIPLOTDEL->TRAN_CMF_18, sizeof(MWIPLOTDEL->TRAN_CMF_18));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_19, MWIPLOTDEL->TRAN_CMF_19, sizeof(MWIPLOTDEL->TRAN_CMF_19));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_CMF_20, MWIPLOTDEL->TRAN_CMF_20, sizeof(MWIPLOTDEL->TRAN_CMF_20));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_USER_ID, MWIPLOTDEL->TRAN_USER_ID, sizeof(MWIPLOTDEL->TRAN_USER_ID));
    MEMCPY_AN(MWIPLOTDEL_N->TRAN_COMMENT, MWIPLOTDEL->TRAN_COMMENT, sizeof(MWIPLOTDEL->TRAN_COMMENT));
    MWIPLOTDEL_N->PREV_ACTIVE_HIST_SEQ = MWIPLOTDEL->PREV_ACTIVE_HIST_SEQ;
    MEMCPY_AN(MWIPLOTDEL_N->MULTI_TR_KEY, MWIPLOTDEL->MULTI_TR_KEY, sizeof(MWIPLOTDEL->MULTI_TR_KEY));
    MWIPLOTDEL_N->MULTI_TR_SEQ = MWIPLOTDEL->MULTI_TR_SEQ;
    MWIPLOTDEL_N->EXT_HIST_SEQ = MWIPLOTDEL->EXT_HIST_SEQ;
    MWIPLOTDEL_N->HIST_DEL_FLAG[0] = MWIPLOTDEL->HIST_DEL_FLAG;
    MEMCPY_AN(MWIPLOTDEL_N->HIST_DEL_TIME, MWIPLOTDEL->HIST_DEL_TIME, sizeof(MWIPLOTDEL->HIST_DEL_TIME));
    MEMCPY_AN(MWIPLOTDEL_N->HIST_DEL_USER_ID, MWIPLOTDEL->HIST_DEL_USER_ID, sizeof(MWIPLOTDEL->HIST_DEL_USER_ID));
    MEMCPY_AN(MWIPLOTDEL_N->HIST_DEL_COMMENT, MWIPLOTDEL->HIST_DEL_COMMENT, sizeof(MWIPLOTDEL->HIST_DEL_COMMENT));
}


/* Del Null Function */
void DBC_del_null_mwiplotdel(struct MWIPLOTDEL_N_TAG *MWIPLOTDEL_N, struct MWIPLOTDEL_TAG *MWIPLOTDEL)
{
    MEMCPY_DN(MWIPLOTDEL->LOT_ID, MWIPLOTDEL_N->LOT_ID, sizeof(MWIPLOTDEL->LOT_ID));
    MWIPLOTDEL->HIST_SEQ = MWIPLOTDEL_N->HIST_SEQ;
    MEMCPY_DN(MWIPLOTDEL->TRAN_TIME, MWIPLOTDEL_N->TRAN_TIME, sizeof(MWIPLOTDEL->TRAN_TIME));
    MEMCPY_DN(MWIPLOTDEL->SYS_TRAN_TIME, MWIPLOTDEL_N->SYS_TRAN_TIME, sizeof(MWIPLOTDEL->SYS_TRAN_TIME));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CODE, MWIPLOTDEL_N->TRAN_CODE, sizeof(MWIPLOTDEL->TRAN_CODE));
    MEMCPY_DN(MWIPLOTDEL->LOT_DESC, MWIPLOTDEL_N->LOT_DESC, sizeof(MWIPLOTDEL->LOT_DESC));
    MEMCPY_DN(MWIPLOTDEL->FACTORY, MWIPLOTDEL_N->FACTORY, sizeof(MWIPLOTDEL->FACTORY));
    MEMCPY_DN(MWIPLOTDEL->MAT_ID, MWIPLOTDEL_N->MAT_ID, sizeof(MWIPLOTDEL->MAT_ID));
    MWIPLOTDEL->MAT_VER = MWIPLOTDEL_N->MAT_VER;
    MEMCPY_DN(MWIPLOTDEL->FLOW, MWIPLOTDEL_N->FLOW, sizeof(MWIPLOTDEL->FLOW));
    MWIPLOTDEL->FLOW_SEQ_NUM = MWIPLOTDEL_N->FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->OPER, MWIPLOTDEL_N->OPER, sizeof(MWIPLOTDEL->OPER));
    MWIPLOTDEL->QTY_1 = MWIPLOTDEL_N->QTY_1;
    MWIPLOTDEL->QTY_2 = MWIPLOTDEL_N->QTY_2;
    MWIPLOTDEL->QTY_3 = MWIPLOTDEL_N->QTY_3;
    MEMCPY_DN(MWIPLOTDEL->CRR_ID, MWIPLOTDEL_N->CRR_ID, sizeof(MWIPLOTDEL->CRR_ID));
    MWIPLOTDEL->LOT_TYPE = MWIPLOTDEL_N->LOT_TYPE[0];
    MEMCPY_DN(MWIPLOTDEL->OWNER_CODE, MWIPLOTDEL_N->OWNER_CODE, sizeof(MWIPLOTDEL->OWNER_CODE));
    MEMCPY_DN(MWIPLOTDEL->CREATE_CODE, MWIPLOTDEL_N->CREATE_CODE, sizeof(MWIPLOTDEL->CREATE_CODE));
    MWIPLOTDEL->LOT_PRIORITY = MWIPLOTDEL_N->LOT_PRIORITY[0];
    MEMCPY_DN(MWIPLOTDEL->LOT_STATUS, MWIPLOTDEL_N->LOT_STATUS, sizeof(MWIPLOTDEL->LOT_STATUS));
    MWIPLOTDEL->HOLD_FLAG = MWIPLOTDEL_N->HOLD_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->HOLD_CODE, MWIPLOTDEL_N->HOLD_CODE, sizeof(MWIPLOTDEL->HOLD_CODE));
    MEMCPY_DN(MWIPLOTDEL->HOLD_PASSWORD, MWIPLOTDEL_N->HOLD_PASSWORD, sizeof(MWIPLOTDEL->HOLD_PASSWORD));
    MEMCPY_DN(MWIPLOTDEL->HOLD_PRV_GRP_ID, MWIPLOTDEL_N->HOLD_PRV_GRP_ID, sizeof(MWIPLOTDEL->HOLD_PRV_GRP_ID));
    MWIPLOTDEL->OPER_IN_QTY_1 = MWIPLOTDEL_N->OPER_IN_QTY_1;
    MWIPLOTDEL->OPER_IN_QTY_2 = MWIPLOTDEL_N->OPER_IN_QTY_2;
    MWIPLOTDEL->OPER_IN_QTY_3 = MWIPLOTDEL_N->OPER_IN_QTY_3;
    MWIPLOTDEL->CREATE_QTY_1 = MWIPLOTDEL_N->CREATE_QTY_1;
    MWIPLOTDEL->CREATE_QTY_2 = MWIPLOTDEL_N->CREATE_QTY_2;
    MWIPLOTDEL->CREATE_QTY_3 = MWIPLOTDEL_N->CREATE_QTY_3;
    MWIPLOTDEL->START_QTY_1 = MWIPLOTDEL_N->START_QTY_1;
    MWIPLOTDEL->START_QTY_2 = MWIPLOTDEL_N->START_QTY_2;
    MWIPLOTDEL->START_QTY_3 = MWIPLOTDEL_N->START_QTY_3;
    MWIPLOTDEL->INV_FLAG = MWIPLOTDEL_N->INV_FLAG[0];
    MWIPLOTDEL->TRANSIT_FLAG = MWIPLOTDEL_N->TRANSIT_FLAG[0];
    MWIPLOTDEL->UNIT_EXIST_FLAG = MWIPLOTDEL_N->UNIT_EXIST_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->INV_UNIT, MWIPLOTDEL_N->INV_UNIT, sizeof(MWIPLOTDEL->INV_UNIT));
    MWIPLOTDEL->RWK_FLAG = MWIPLOTDEL_N->RWK_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->RWK_CODE, MWIPLOTDEL_N->RWK_CODE, sizeof(MWIPLOTDEL->RWK_CODE));
    MWIPLOTDEL->RWK_COUNT = MWIPLOTDEL_N->RWK_COUNT;
    MEMCPY_DN(MWIPLOTDEL->RWK_RET_FLOW, MWIPLOTDEL_N->RWK_RET_FLOW, sizeof(MWIPLOTDEL->RWK_RET_FLOW));
    MWIPLOTDEL->RWK_RET_FLOW_SEQ_NUM = MWIPLOTDEL_N->RWK_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->RWK_RET_OPER, MWIPLOTDEL_N->RWK_RET_OPER, sizeof(MWIPLOTDEL->RWK_RET_OPER));
    MEMCPY_DN(MWIPLOTDEL->RWK_END_FLOW, MWIPLOTDEL_N->RWK_END_FLOW, sizeof(MWIPLOTDEL->RWK_END_FLOW));
    MWIPLOTDEL->RWK_END_FLOW_SEQ_NUM = MWIPLOTDEL_N->RWK_END_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->RWK_END_OPER, MWIPLOTDEL_N->RWK_END_OPER, sizeof(MWIPLOTDEL->RWK_END_OPER));
    MWIPLOTDEL->RWK_RET_CLEAR_FLAG = MWIPLOTDEL_N->RWK_RET_CLEAR_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->RWK_TIME, MWIPLOTDEL_N->RWK_TIME, sizeof(MWIPLOTDEL->RWK_TIME));
    MWIPLOTDEL->NSTD_FLAG = MWIPLOTDEL_N->NSTD_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->NSTD_RET_FLOW, MWIPLOTDEL_N->NSTD_RET_FLOW, sizeof(MWIPLOTDEL->NSTD_RET_FLOW));
    MWIPLOTDEL->NSTD_RET_FLOW_SEQ_NUM = MWIPLOTDEL_N->NSTD_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->NSTD_RET_OPER, MWIPLOTDEL_N->NSTD_RET_OPER, sizeof(MWIPLOTDEL->NSTD_RET_OPER));
    MEMCPY_DN(MWIPLOTDEL->NSTD_TIME, MWIPLOTDEL_N->NSTD_TIME, sizeof(MWIPLOTDEL->NSTD_TIME));
    MWIPLOTDEL->REP_FLAG = MWIPLOTDEL_N->REP_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->REP_RET_OPER, MWIPLOTDEL_N->REP_RET_OPER, sizeof(MWIPLOTDEL->REP_RET_OPER));
    MEMCPY_DN(MWIPLOTDEL->STR_RET_FLOW, MWIPLOTDEL_N->STR_RET_FLOW, sizeof(MWIPLOTDEL->STR_RET_FLOW));
    MWIPLOTDEL->STR_RET_FLOW_SEQ_NUM = MWIPLOTDEL_N->STR_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->STR_RET_OPER, MWIPLOTDEL_N->STR_RET_OPER, sizeof(MWIPLOTDEL->STR_RET_OPER));
    MWIPLOTDEL->START_FLAG = MWIPLOTDEL_N->START_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->START_TIME, MWIPLOTDEL_N->START_TIME, sizeof(MWIPLOTDEL->START_TIME));
    MEMCPY_DN(MWIPLOTDEL->START_RES_ID, MWIPLOTDEL_N->START_RES_ID, sizeof(MWIPLOTDEL->START_RES_ID));
    MWIPLOTDEL->END_FLAG = MWIPLOTDEL_N->END_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->END_TIME, MWIPLOTDEL_N->END_TIME, sizeof(MWIPLOTDEL->END_TIME));
    MEMCPY_DN(MWIPLOTDEL->END_RES_ID, MWIPLOTDEL_N->END_RES_ID, sizeof(MWIPLOTDEL->END_RES_ID));
    MWIPLOTDEL->SAMPLE_FLAG = MWIPLOTDEL_N->SAMPLE_FLAG[0];
    MWIPLOTDEL->SAMPLE_WAIT_FLAG = MWIPLOTDEL_N->SAMPLE_WAIT_FLAG[0];
    MWIPLOTDEL->SAMPLE_RESULT = MWIPLOTDEL_N->SAMPLE_RESULT[0];
    MWIPLOTDEL->FROM_TO_FLAG = MWIPLOTDEL_N->FROM_TO_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->FROM_TO_LOT_ID, MWIPLOTDEL_N->FROM_TO_LOT_ID, sizeof(MWIPLOTDEL->FROM_TO_LOT_ID));
    MEMCPY_DN(MWIPLOTDEL->SHIP_CODE, MWIPLOTDEL_N->SHIP_CODE, sizeof(MWIPLOTDEL->SHIP_CODE));
    MEMCPY_DN(MWIPLOTDEL->SHIP_TIME, MWIPLOTDEL_N->SHIP_TIME, sizeof(MWIPLOTDEL->SHIP_TIME));
    MEMCPY_DN(MWIPLOTDEL->ORG_DUE_TIME, MWIPLOTDEL_N->ORG_DUE_TIME, sizeof(MWIPLOTDEL->ORG_DUE_TIME));
    MEMCPY_DN(MWIPLOTDEL->SCH_DUE_TIME, MWIPLOTDEL_N->SCH_DUE_TIME, sizeof(MWIPLOTDEL->SCH_DUE_TIME));
    MEMCPY_DN(MWIPLOTDEL->CREATE_TIME, MWIPLOTDEL_N->CREATE_TIME, sizeof(MWIPLOTDEL->CREATE_TIME));
    MEMCPY_DN(MWIPLOTDEL->FAC_IN_TIME, MWIPLOTDEL_N->FAC_IN_TIME, sizeof(MWIPLOTDEL->FAC_IN_TIME));
    MEMCPY_DN(MWIPLOTDEL->FLOW_IN_TIME, MWIPLOTDEL_N->FLOW_IN_TIME, sizeof(MWIPLOTDEL->FLOW_IN_TIME));
    MEMCPY_DN(MWIPLOTDEL->OPER_IN_TIME, MWIPLOTDEL_N->OPER_IN_TIME, sizeof(MWIPLOTDEL->OPER_IN_TIME));
    MEMCPY_DN(MWIPLOTDEL->RESERVE_RES_ID, MWIPLOTDEL_N->RESERVE_RES_ID, sizeof(MWIPLOTDEL->RESERVE_RES_ID));
    MEMCPY_DN(MWIPLOTDEL->PORT_ID, MWIPLOTDEL_N->PORT_ID, sizeof(MWIPLOTDEL->PORT_ID));
    MEMCPY_DN(MWIPLOTDEL->BATCH_ID, MWIPLOTDEL_N->BATCH_ID, sizeof(MWIPLOTDEL->BATCH_ID));
    MWIPLOTDEL->BATCH_SEQ = MWIPLOTDEL_N->BATCH_SEQ;
    MEMCPY_DN(MWIPLOTDEL->ORDER_ID, MWIPLOTDEL_N->ORDER_ID, sizeof(MWIPLOTDEL->ORDER_ID));
    MEMCPY_DN(MWIPLOTDEL->ADD_ORDER_ID_1, MWIPLOTDEL_N->ADD_ORDER_ID_1, sizeof(MWIPLOTDEL->ADD_ORDER_ID_1));
    MEMCPY_DN(MWIPLOTDEL->ADD_ORDER_ID_2, MWIPLOTDEL_N->ADD_ORDER_ID_2, sizeof(MWIPLOTDEL->ADD_ORDER_ID_2));
    MEMCPY_DN(MWIPLOTDEL->ADD_ORDER_ID_3, MWIPLOTDEL_N->ADD_ORDER_ID_3, sizeof(MWIPLOTDEL->ADD_ORDER_ID_3));
    MEMCPY_DN(MWIPLOTDEL->LOT_LOCATION_1, MWIPLOTDEL_N->LOT_LOCATION_1, sizeof(MWIPLOTDEL->LOT_LOCATION_1));
    MEMCPY_DN(MWIPLOTDEL->LOT_LOCATION_2, MWIPLOTDEL_N->LOT_LOCATION_2, sizeof(MWIPLOTDEL->LOT_LOCATION_2));
    MEMCPY_DN(MWIPLOTDEL->LOT_LOCATION_3, MWIPLOTDEL_N->LOT_LOCATION_3, sizeof(MWIPLOTDEL->LOT_LOCATION_3));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_1, MWIPLOTDEL_N->LOT_CMF_1, sizeof(MWIPLOTDEL->LOT_CMF_1));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_2, MWIPLOTDEL_N->LOT_CMF_2, sizeof(MWIPLOTDEL->LOT_CMF_2));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_3, MWIPLOTDEL_N->LOT_CMF_3, sizeof(MWIPLOTDEL->LOT_CMF_3));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_4, MWIPLOTDEL_N->LOT_CMF_4, sizeof(MWIPLOTDEL->LOT_CMF_4));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_5, MWIPLOTDEL_N->LOT_CMF_5, sizeof(MWIPLOTDEL->LOT_CMF_5));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_6, MWIPLOTDEL_N->LOT_CMF_6, sizeof(MWIPLOTDEL->LOT_CMF_6));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_7, MWIPLOTDEL_N->LOT_CMF_7, sizeof(MWIPLOTDEL->LOT_CMF_7));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_8, MWIPLOTDEL_N->LOT_CMF_8, sizeof(MWIPLOTDEL->LOT_CMF_8));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_9, MWIPLOTDEL_N->LOT_CMF_9, sizeof(MWIPLOTDEL->LOT_CMF_9));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_10, MWIPLOTDEL_N->LOT_CMF_10, sizeof(MWIPLOTDEL->LOT_CMF_10));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_11, MWIPLOTDEL_N->LOT_CMF_11, sizeof(MWIPLOTDEL->LOT_CMF_11));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_12, MWIPLOTDEL_N->LOT_CMF_12, sizeof(MWIPLOTDEL->LOT_CMF_12));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_13, MWIPLOTDEL_N->LOT_CMF_13, sizeof(MWIPLOTDEL->LOT_CMF_13));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_14, MWIPLOTDEL_N->LOT_CMF_14, sizeof(MWIPLOTDEL->LOT_CMF_14));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_15, MWIPLOTDEL_N->LOT_CMF_15, sizeof(MWIPLOTDEL->LOT_CMF_15));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_16, MWIPLOTDEL_N->LOT_CMF_16, sizeof(MWIPLOTDEL->LOT_CMF_16));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_17, MWIPLOTDEL_N->LOT_CMF_17, sizeof(MWIPLOTDEL->LOT_CMF_17));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_18, MWIPLOTDEL_N->LOT_CMF_18, sizeof(MWIPLOTDEL->LOT_CMF_18));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_19, MWIPLOTDEL_N->LOT_CMF_19, sizeof(MWIPLOTDEL->LOT_CMF_19));
    MEMCPY_DN(MWIPLOTDEL->LOT_CMF_20, MWIPLOTDEL_N->LOT_CMF_20, sizeof(MWIPLOTDEL->LOT_CMF_20));
    MWIPLOTDEL->LOT_DEL_FLAG = MWIPLOTDEL_N->LOT_DEL_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->LOT_DEL_CODE, MWIPLOTDEL_N->LOT_DEL_CODE, sizeof(MWIPLOTDEL->LOT_DEL_CODE));
    MEMCPY_DN(MWIPLOTDEL->LOT_DEL_TIME, MWIPLOTDEL_N->LOT_DEL_TIME, sizeof(MWIPLOTDEL->LOT_DEL_TIME));
    MEMCPY_DN(MWIPLOTDEL->BOM_SET_ID, MWIPLOTDEL_N->BOM_SET_ID, sizeof(MWIPLOTDEL->BOM_SET_ID));
    MWIPLOTDEL->BOM_SET_VERSION = MWIPLOTDEL_N->BOM_SET_VERSION;
    MWIPLOTDEL->BOM_ACTIVE_HIST_SEQ = MWIPLOTDEL_N->BOM_ACTIVE_HIST_SEQ;
    MWIPLOTDEL->BOM_HIST_SEQ = MWIPLOTDEL_N->BOM_HIST_SEQ;
    MEMCPY_DN(MWIPLOTDEL->CRITICAL_RES_ID, MWIPLOTDEL_N->CRITICAL_RES_ID, sizeof(MWIPLOTDEL->CRITICAL_RES_ID));
    MEMCPY_DN(MWIPLOTDEL->CRITICAL_RES_GROUP_ID, MWIPLOTDEL_N->CRITICAL_RES_GROUP_ID, sizeof(MWIPLOTDEL->CRITICAL_RES_GROUP_ID));
    MEMCPY_DN(MWIPLOTDEL->SAVE_RES_ID_1, MWIPLOTDEL_N->SAVE_RES_ID_1, sizeof(MWIPLOTDEL->SAVE_RES_ID_1));
    MEMCPY_DN(MWIPLOTDEL->SAVE_RES_ID_2, MWIPLOTDEL_N->SAVE_RES_ID_2, sizeof(MWIPLOTDEL->SAVE_RES_ID_2));
    MEMCPY_DN(MWIPLOTDEL->SUBRES_ID, MWIPLOTDEL_N->SUBRES_ID, sizeof(MWIPLOTDEL->SUBRES_ID));
    MEMCPY_DN(MWIPLOTDEL->LOT_GROUP_ID_1, MWIPLOTDEL_N->LOT_GROUP_ID_1, sizeof(MWIPLOTDEL->LOT_GROUP_ID_1));
    MEMCPY_DN(MWIPLOTDEL->LOT_GROUP_ID_2, MWIPLOTDEL_N->LOT_GROUP_ID_2, sizeof(MWIPLOTDEL->LOT_GROUP_ID_2));
    MEMCPY_DN(MWIPLOTDEL->LOT_GROUP_ID_3, MWIPLOTDEL_N->LOT_GROUP_ID_3, sizeof(MWIPLOTDEL->LOT_GROUP_ID_3));
    MWIPLOTDEL->YIELD_1 = MWIPLOTDEL_N->YIELD_1;
    MWIPLOTDEL->YIELD_2 = MWIPLOTDEL_N->YIELD_2;
    MWIPLOTDEL->YIELD_3 = MWIPLOTDEL_N->YIELD_3;
    MWIPLOTDEL->GOOD_QTY = MWIPLOTDEL_N->GOOD_QTY;
    MEMCPY_DN(MWIPLOTDEL->RESV_FIELD_1, MWIPLOTDEL_N->RESV_FIELD_1, sizeof(MWIPLOTDEL->RESV_FIELD_1));
    MEMCPY_DN(MWIPLOTDEL->RESV_FIELD_2, MWIPLOTDEL_N->RESV_FIELD_2, sizeof(MWIPLOTDEL->RESV_FIELD_2));
    MEMCPY_DN(MWIPLOTDEL->RESV_FIELD_3, MWIPLOTDEL_N->RESV_FIELD_3, sizeof(MWIPLOTDEL->RESV_FIELD_3));
    MEMCPY_DN(MWIPLOTDEL->RESV_FIELD_4, MWIPLOTDEL_N->RESV_FIELD_4, sizeof(MWIPLOTDEL->RESV_FIELD_4));
    MEMCPY_DN(MWIPLOTDEL->RESV_FIELD_5, MWIPLOTDEL_N->RESV_FIELD_5, sizeof(MWIPLOTDEL->RESV_FIELD_5));
    MWIPLOTDEL->RESV_FLAG_1 = MWIPLOTDEL_N->RESV_FLAG_1[0];
    MWIPLOTDEL->RESV_FLAG_2 = MWIPLOTDEL_N->RESV_FLAG_2[0];
    MWIPLOTDEL->RESV_FLAG_3 = MWIPLOTDEL_N->RESV_FLAG_3[0];
    MWIPLOTDEL->RESV_FLAG_4 = MWIPLOTDEL_N->RESV_FLAG_4[0];
    MWIPLOTDEL->RESV_FLAG_5 = MWIPLOTDEL_N->RESV_FLAG_5[0];
    MEMCPY_DN(MWIPLOTDEL->FROM_TO_MAT_ID, MWIPLOTDEL_N->FROM_TO_MAT_ID, sizeof(MWIPLOTDEL->FROM_TO_MAT_ID));
    MWIPLOTDEL->FROM_TO_MAT_VER = MWIPLOTDEL_N->FROM_TO_MAT_VER;
    MEMCPY_DN(MWIPLOTDEL->FROM_TO_FLOW, MWIPLOTDEL_N->FROM_TO_FLOW, sizeof(MWIPLOTDEL->FROM_TO_FLOW));
    MWIPLOTDEL->FROM_TO_FLOW_SEQ_NUM = MWIPLOTDEL_N->FROM_TO_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->FROM_TO_OPER, MWIPLOTDEL_N->FROM_TO_OPER, sizeof(MWIPLOTDEL->FROM_TO_OPER));
    MWIPLOTDEL->FROM_TO_QTY_1 = MWIPLOTDEL_N->FROM_TO_QTY_1;
    MWIPLOTDEL->FROM_TO_QTY_2 = MWIPLOTDEL_N->FROM_TO_QTY_2;
    MWIPLOTDEL->FROM_TO_QTY_3 = MWIPLOTDEL_N->FROM_TO_QTY_3;
    MWIPLOTDEL->FROM_TO_HIST_SEQ = MWIPLOTDEL_N->FROM_TO_HIST_SEQ;
    MEMCPY_DN(MWIPLOTDEL->OLD_FACTORY, MWIPLOTDEL_N->OLD_FACTORY, sizeof(MWIPLOTDEL->OLD_FACTORY));
    MEMCPY_DN(MWIPLOTDEL->OLD_MAT_ID, MWIPLOTDEL_N->OLD_MAT_ID, sizeof(MWIPLOTDEL->OLD_MAT_ID));
    MWIPLOTDEL->OLD_MAT_VER = MWIPLOTDEL_N->OLD_MAT_VER;
    MEMCPY_DN(MWIPLOTDEL->OLD_FLOW, MWIPLOTDEL_N->OLD_FLOW, sizeof(MWIPLOTDEL->OLD_FLOW));
    MWIPLOTDEL->OLD_FLOW_SEQ_NUM = MWIPLOTDEL_N->OLD_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPLOTDEL->OLD_OPER, MWIPLOTDEL_N->OLD_OPER, sizeof(MWIPLOTDEL->OLD_OPER));
    MWIPLOTDEL->OLD_QTY_1 = MWIPLOTDEL_N->OLD_QTY_1;
    MWIPLOTDEL->OLD_QTY_2 = MWIPLOTDEL_N->OLD_QTY_2;
    MWIPLOTDEL->OLD_QTY_3 = MWIPLOTDEL_N->OLD_QTY_3;
    MWIPLOTDEL->OLD_LOT_TYPE = MWIPLOTDEL_N->OLD_LOT_TYPE[0];
    MEMCPY_DN(MWIPLOTDEL->OLD_OWNER_CODE, MWIPLOTDEL_N->OLD_OWNER_CODE, sizeof(MWIPLOTDEL->OLD_OWNER_CODE));
    MEMCPY_DN(MWIPLOTDEL->OLD_CREATE_CODE, MWIPLOTDEL_N->OLD_CREATE_CODE, sizeof(MWIPLOTDEL->OLD_CREATE_CODE));
    MEMCPY_DN(MWIPLOTDEL->OLD_FAC_IN_TIME, MWIPLOTDEL_N->OLD_FAC_IN_TIME, sizeof(MWIPLOTDEL->OLD_FAC_IN_TIME));
    MEMCPY_DN(MWIPLOTDEL->OLD_FLOW_IN_TIME, MWIPLOTDEL_N->OLD_FLOW_IN_TIME, sizeof(MWIPLOTDEL->OLD_FLOW_IN_TIME));
    MEMCPY_DN(MWIPLOTDEL->OLD_OPER_IN_TIME, MWIPLOTDEL_N->OLD_OPER_IN_TIME, sizeof(MWIPLOTDEL->OLD_OPER_IN_TIME));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_1, MWIPLOTDEL_N->TRAN_CMF_1, sizeof(MWIPLOTDEL->TRAN_CMF_1));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_2, MWIPLOTDEL_N->TRAN_CMF_2, sizeof(MWIPLOTDEL->TRAN_CMF_2));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_3, MWIPLOTDEL_N->TRAN_CMF_3, sizeof(MWIPLOTDEL->TRAN_CMF_3));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_4, MWIPLOTDEL_N->TRAN_CMF_4, sizeof(MWIPLOTDEL->TRAN_CMF_4));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_5, MWIPLOTDEL_N->TRAN_CMF_5, sizeof(MWIPLOTDEL->TRAN_CMF_5));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_6, MWIPLOTDEL_N->TRAN_CMF_6, sizeof(MWIPLOTDEL->TRAN_CMF_6));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_7, MWIPLOTDEL_N->TRAN_CMF_7, sizeof(MWIPLOTDEL->TRAN_CMF_7));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_8, MWIPLOTDEL_N->TRAN_CMF_8, sizeof(MWIPLOTDEL->TRAN_CMF_8));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_9, MWIPLOTDEL_N->TRAN_CMF_9, sizeof(MWIPLOTDEL->TRAN_CMF_9));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_10, MWIPLOTDEL_N->TRAN_CMF_10, sizeof(MWIPLOTDEL->TRAN_CMF_10));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_11, MWIPLOTDEL_N->TRAN_CMF_11, sizeof(MWIPLOTDEL->TRAN_CMF_11));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_12, MWIPLOTDEL_N->TRAN_CMF_12, sizeof(MWIPLOTDEL->TRAN_CMF_12));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_13, MWIPLOTDEL_N->TRAN_CMF_13, sizeof(MWIPLOTDEL->TRAN_CMF_13));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_14, MWIPLOTDEL_N->TRAN_CMF_14, sizeof(MWIPLOTDEL->TRAN_CMF_14));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_15, MWIPLOTDEL_N->TRAN_CMF_15, sizeof(MWIPLOTDEL->TRAN_CMF_15));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_16, MWIPLOTDEL_N->TRAN_CMF_16, sizeof(MWIPLOTDEL->TRAN_CMF_16));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_17, MWIPLOTDEL_N->TRAN_CMF_17, sizeof(MWIPLOTDEL->TRAN_CMF_17));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_18, MWIPLOTDEL_N->TRAN_CMF_18, sizeof(MWIPLOTDEL->TRAN_CMF_18));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_19, MWIPLOTDEL_N->TRAN_CMF_19, sizeof(MWIPLOTDEL->TRAN_CMF_19));
    MEMCPY_DN(MWIPLOTDEL->TRAN_CMF_20, MWIPLOTDEL_N->TRAN_CMF_20, sizeof(MWIPLOTDEL->TRAN_CMF_20));
    MEMCPY_DN(MWIPLOTDEL->TRAN_USER_ID, MWIPLOTDEL_N->TRAN_USER_ID, sizeof(MWIPLOTDEL->TRAN_USER_ID));
    MEMCPY_DN(MWIPLOTDEL->TRAN_COMMENT, MWIPLOTDEL_N->TRAN_COMMENT, sizeof(MWIPLOTDEL->TRAN_COMMENT));
    MWIPLOTDEL->PREV_ACTIVE_HIST_SEQ = MWIPLOTDEL_N->PREV_ACTIVE_HIST_SEQ;
    MEMCPY_DN(MWIPLOTDEL->MULTI_TR_KEY, MWIPLOTDEL_N->MULTI_TR_KEY, sizeof(MWIPLOTDEL->MULTI_TR_KEY));
    MWIPLOTDEL->MULTI_TR_SEQ = MWIPLOTDEL_N->MULTI_TR_SEQ;
    MWIPLOTDEL->EXT_HIST_SEQ = MWIPLOTDEL_N->EXT_HIST_SEQ;
    MWIPLOTDEL->HIST_DEL_FLAG = MWIPLOTDEL_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MWIPLOTDEL->HIST_DEL_TIME, MWIPLOTDEL_N->HIST_DEL_TIME, sizeof(MWIPLOTDEL->HIST_DEL_TIME));
    MEMCPY_DN(MWIPLOTDEL->HIST_DEL_USER_ID, MWIPLOTDEL_N->HIST_DEL_USER_ID, sizeof(MWIPLOTDEL->HIST_DEL_USER_ID));
    MEMCPY_DN(MWIPLOTDEL->HIST_DEL_COMMENT, MWIPLOTDEL_N->HIST_DEL_COMMENT, sizeof(MWIPLOTDEL->HIST_DEL_COMMENT));
}
