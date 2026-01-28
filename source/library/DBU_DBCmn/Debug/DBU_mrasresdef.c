
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
    "DBU_mrasresdef.pc"
};


static unsigned int sqlctx = 9421787;


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
            void  *sqhstv[94];
   unsigned int   sqhstl[94];
            int   sqhsts[94];
            void  *sqindv[94];
            int   sqinds[94];
   unsigned int   sqharm[94];
   unsigned int   *sqharc[94];
   unsigned short  sqadto[94];
   unsigned short  sqtdso[94];
} sqlstm = {13,94};

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
"CIPE_ID ,PROC_COUNT ,LAST_START_TIME\
 ,LAST_END_TIME ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,LAST_EVENT_ID ,LAST_EVEN\
T_TIME ,LAST_ACTIVE_HIST_SEQ ,LAST_HIST_SEQ ,RES_SHORT_DESC  from MRASRESDEF \
 order by FACTORY asc ,RES_ID asc             ";

 static const char *sq0010 = 
"CIPE_ID ,PROC_COUNT ,LAST_START_TIME\
 ,LAST_END_TIME ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,LAST_EVENT_ID ,LAST_EVEN\
T_TIME ,LAST_ACTIVE_HIST_SEQ ,LAST_HIST_SEQ ,RES_SHORT_DESC  from MRASRESDEF \
where (((FACTORY=:b0 and AREA_ID=:b1) and RES_GRP_1=:b2) and RES_ID>=:b3) ord\
er by RES_ID asc             ";

 static const char *sq0011 = 
"CIPE_ID ,PROC_COUNT ,LAST_START_TIME\
 ,LAST_END_TIME ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,LAST_EVENT_ID ,LAST_EVEN\
T_TIME ,LAST_ACTIVE_HIST_SEQ ,LAST_HIST_SEQ ,RES_SHORT_DESC  from MRASRESDEF \
where (FACTORY=:b0 and RES_ID in (select M.RES_ID  from MRASRESMFO M ,MWIPOPR\
DEF O where (((M.FACTORY=O.FACTORY and M.OPER=O.OPER) and M.FACTORY=:b0) and \
O.SUB_AREA_ID=:b2))) order by RES_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1698,0,4,46,0,0,93,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,1,97,0,0,1,97,
0,0,
392,0,0,2,1722,0,4,236,0,0,94,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,
783,0,0,3,1710,0,4,459,0,0,93,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,
1170,0,0,4,77,0,4,685,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
1197,0,0,5,59,0,2,722,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1220,0,0,6,1578,0,3,752,0,0,91,91,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
1599,0,0,7,1579,0,5,959,0,0,91,91,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1978,0,0,8,122,0,5,1054,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,
2017,0,0,9,1260,0,9,1187,0,0,0,0,0,1,0,
2032,0,0,10,1320,0,9,1290,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2063,0,0,11,1421,0,9,1399,0,0,3,3,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,
2090,0,0,9,0,0,13,1427,0,0,91,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2469,0,0,10,0,0,13,1522,0,0,91,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
2848,0,0,11,0,0,13,1617,0,0,91,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
3227,0,0,9,0,0,15,1737,0,0,0,0,0,1,0,
3242,0,0,10,0,0,15,1741,0,0,0,0,0,1,0,
3257,0,0,11,0,0,15,1745,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_mrasresdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-07-21 12:59:31
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
void DBU_add_null_mrasresdef(struct MRASRESDEF_N_TAG *MRASRESDEF_N, struct MRASRESDEF_TAG *MRASRESDEF);
void DBU_del_null_mrasresdef(struct MRASRESDEF_N_TAG *MRASRESDEF_N, struct MRASRESDEF_TAG *MRASRESDEF);


/* SQL SELECT Function */
void DBU_select_mrasresdef(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    RES_ID,
                    RES_DESC,
                    RES_TYPE,
                    RES_GRP_1,
                    RES_GRP_2,
                    RES_GRP_3,
                    RES_GRP_4,
                    RES_GRP_5,
                    RES_GRP_6,
                    RES_GRP_7,
                    RES_GRP_8,
                    RES_GRP_9,
                    RES_GRP_10,
                    USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1,
                    RES_STS_PRT_2,
                    RES_STS_PRT_3,
                    RES_STS_PRT_4,
                    RES_STS_PRT_5,
                    RES_STS_PRT_6,
                    RES_STS_PRT_7,
                    RES_STS_PRT_8,
                    RES_STS_PRT_9,
                    RES_STS_PRT_10,
                    RES_CMF_1,
                    RES_CMF_2,
                    RES_CMF_3,
                    RES_CMF_4,
                    RES_CMF_5,
                    RES_CMF_6,
                    RES_CMF_7,
                    RES_CMF_8,
                    RES_CMF_9,
                    RES_CMF_10,
                    RES_CMF_11,
                    RES_CMF_12,
                    RES_CMF_13,
                    RES_CMF_14,
                    RES_CMF_15,
                    RES_CMF_16,
                    RES_CMF_17,
                    RES_CMF_18,
                    RES_CMF_19,
                    RES_CMF_20,
                    AREA_ID,
                    SUB_AREA_ID,
                    RES_LOCATION,
                    PROC_RULE,
                    MAX_PROC_COUNT,
                    BATCH_COND_1,
                    BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    RES_UP_DOWN_FLAG,
                    RES_PRI_STS,
                    RES_STS_1,
                    RES_STS_2,
                    RES_STS_3,
                    RES_STS_4,
                    RES_STS_5,
                    RES_STS_6,
                    RES_STS_7,
                    RES_STS_8,
                    RES_STS_9,
                    RES_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LAST_RECIPE_ID,
                    PROC_COUNT,
                    LAST_START_TIME,
                    LAST_END_TIME,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID,
                    LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ,
                    RES_SHORT_DESC
                INTO 
                    :MRASRESDEF_N.FACTORY,
                    :MRASRESDEF_N.RES_ID,
                    :MRASRESDEF_N.RES_DESC,
                    :MRASRESDEF_N.RES_TYPE,
                    :MRASRESDEF_N.RES_GRP_1,
                    :MRASRESDEF_N.RES_GRP_2,
                    :MRASRESDEF_N.RES_GRP_3,
                    :MRASRESDEF_N.RES_GRP_4,
                    :MRASRESDEF_N.RES_GRP_5,
                    :MRASRESDEF_N.RES_GRP_6,
                    :MRASRESDEF_N.RES_GRP_7,
                    :MRASRESDEF_N.RES_GRP_8,
                    :MRASRESDEF_N.RES_GRP_9,
                    :MRASRESDEF_N.RES_GRP_10,
                    :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                    :MRASRESDEF_N.RES_STS_PRT_1,
                    :MRASRESDEF_N.RES_STS_PRT_2,
                    :MRASRESDEF_N.RES_STS_PRT_3,
                    :MRASRESDEF_N.RES_STS_PRT_4,
                    :MRASRESDEF_N.RES_STS_PRT_5,
                    :MRASRESDEF_N.RES_STS_PRT_6,
                    :MRASRESDEF_N.RES_STS_PRT_7,
                    :MRASRESDEF_N.RES_STS_PRT_8,
                    :MRASRESDEF_N.RES_STS_PRT_9,
                    :MRASRESDEF_N.RES_STS_PRT_10,
                    :MRASRESDEF_N.RES_CMF_1,
                    :MRASRESDEF_N.RES_CMF_2,
                    :MRASRESDEF_N.RES_CMF_3,
                    :MRASRESDEF_N.RES_CMF_4,
                    :MRASRESDEF_N.RES_CMF_5,
                    :MRASRESDEF_N.RES_CMF_6,
                    :MRASRESDEF_N.RES_CMF_7,
                    :MRASRESDEF_N.RES_CMF_8,
                    :MRASRESDEF_N.RES_CMF_9,
                    :MRASRESDEF_N.RES_CMF_10,
                    :MRASRESDEF_N.RES_CMF_11,
                    :MRASRESDEF_N.RES_CMF_12,
                    :MRASRESDEF_N.RES_CMF_13,
                    :MRASRESDEF_N.RES_CMF_14,
                    :MRASRESDEF_N.RES_CMF_15,
                    :MRASRESDEF_N.RES_CMF_16,
                    :MRASRESDEF_N.RES_CMF_17,
                    :MRASRESDEF_N.RES_CMF_18,
                    :MRASRESDEF_N.RES_CMF_19,
                    :MRASRESDEF_N.RES_CMF_20,
                    :MRASRESDEF_N.AREA_ID,
                    :MRASRESDEF_N.SUB_AREA_ID,
                    :MRASRESDEF_N.RES_LOCATION,
                    :MRASRESDEF_N.PROC_RULE,
                    :MRASRESDEF_N.MAX_PROC_COUNT,
                    :MRASRESDEF_N.BATCH_COND_1,
                    :MRASRESDEF_N.BATCH_COND_2,
                    :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                    :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                    :MRASRESDEF_N.SEC_CHK_FLAG,
                    :MRASRESDEF_N.GATHER_ALARM_FLAG,
                    :MRASRESDEF_N.DELETE_FLAG,
                    :MRASRESDEF_N.DELETE_USER_ID,
                    :MRASRESDEF_N.DELETE_TIME,
                    :MRASRESDEF_N.CREATE_USER_ID,
                    :MRASRESDEF_N.CREATE_TIME,
                    :MRASRESDEF_N.UPDATE_USER_ID,
                    :MRASRESDEF_N.UPDATE_TIME,
                    :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                    :MRASRESDEF_N.RES_PRI_STS,
                    :MRASRESDEF_N.RES_STS_1,
                    :MRASRESDEF_N.RES_STS_2,
                    :MRASRESDEF_N.RES_STS_3,
                    :MRASRESDEF_N.RES_STS_4,
                    :MRASRESDEF_N.RES_STS_5,
                    :MRASRESDEF_N.RES_STS_6,
                    :MRASRESDEF_N.RES_STS_7,
                    :MRASRESDEF_N.RES_STS_8,
                    :MRASRESDEF_N.RES_STS_9,
                    :MRASRESDEF_N.RES_STS_10,
                    :MRASRESDEF_N.LOT_ID,
                    :MRASRESDEF_N.SUBLOT_ID,
                    :MRASRESDEF_N.CRR_ID,
                    :MRASRESDEF_N.RES_CTRL_MODE,
                    :MRASRESDEF_N.RES_PROC_MODE,
                    :MRASRESDEF_N.LAST_RECIPE_ID,
                    :MRASRESDEF_N.PROC_COUNT,
                    :MRASRESDEF_N.LAST_START_TIME,
                    :MRASRESDEF_N.LAST_END_TIME,
                    :MRASRESDEF_N.LAST_DOWN_TIME,
                    :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESDEF_N.LAST_EVENT_ID,
                    :MRASRESDEF_N.LAST_EVENT_TIME,
                    :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                    :MRASRESDEF_N.LAST_HIST_SEQ,
                    :MRASRESDEF_N.RES_SHORT_DESC
                FROM MRASRESDEF
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                    AND RES_ID = :MRASRESDEF_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 93;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,RES_DESC ,RES_TYPE ,RES_GRP_1 ,RES_GR\
P_2 ,RES_GRP_3 ,RES_GRP_4 ,RES_GRP_5 ,RES_GRP_6 ,RES_GRP_7 ,RES_GRP_8 ,RES_G\
RP_9 ,RES_GRP_10 ,USE_FAC_PRT_FLAG ,RES_STS_PRT_1 ,RES_STS_PRT_2 ,RES_STS_PR\
T_3 ,RES_STS_PRT_4 ,RES_STS_PRT_5 ,RES_STS_PRT_6 ,RES_STS_PRT_7 ,RES_STS_PRT\
_8 ,RES_STS_PRT_9 ,RES_STS_PRT_10 ,RES_CMF_1 ,RES_CMF_2 ,RES_CMF_3 ,RES_CMF_\
4 ,RES_CMF_5 ,RES_CMF_6 ,RES_CMF_7 ,RES_CMF_8 ,RES_CMF_9 ,RES_CMF_10 ,RES_CM\
F_11 ,RES_CMF_12 ,RES_CMF_13 ,RES_CMF_14 ,RES_CMF_15 ,RES_CMF_16 ,RES_CMF_17\
 ,RES_CMF_18 ,RES_CMF_19 ,RES_CMF_20 ,AREA_ID ,SUB_AREA_ID ,RES_LOCATION ,PR\
OC_RULE ,MAX_PROC_COUNT ,BATCH_COND_1 ,BATCH_COND_2 ,PM_SCH_ENABLE_FLAG ,UNI\
T_BASE_ST_FLAG ,SEC_CHK_FLAG ,GATHER_ALARM_FLAG ,DELETE_FLAG ,DELETE_USER_ID\
 ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,RES\
_UP_DOWN_FLAG ,RES_PRI_STS ,RES_STS_1 ,RES_STS_2 ,RES_STS_3 ,RES_STS_4 ,RES_\
STS_5 ,RES_STS_6 ,RES_STS_7 ,RES_STS_8 ,RES_STS_9 ,RES_STS_10 ,LOT_ID ,SUBLO\
T_ID ,CRR_ID ,RES_CTRL_MODE ,RES_PROC_MODE ,LAST_RE");
            sqlstm.stmt = "CIPE_ID ,PROC_COUNT ,LAST_START_TIME ,LAST_END_T\
IME ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,LAST_EVENT_ID ,LAST_EVENT_TIME ,LAST\
_ACTIVE_HIST_SEQ ,LAST_HIST_SEQ ,RES_SHORT_DESC into :b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90  from MRASRESDEF where (FACTORY=:b0 and R\
ES_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[51] = (unsigned int  )13;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )26;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[78] = (unsigned int  )3;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )13;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[90] = (unsigned int  )51;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[91] = (unsigned int  )11;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
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
                    RES_ID,
                    RES_DESC,
                    RES_TYPE,
                    RES_GRP_1,
                    RES_GRP_2,
                    RES_GRP_3,
                    RES_GRP_4,
                    RES_GRP_5,
                    RES_GRP_6,
                    RES_GRP_7,
                    RES_GRP_8,
                    RES_GRP_9,
                    RES_GRP_10,
                    USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1,
                    RES_STS_PRT_2,
                    RES_STS_PRT_3,
                    RES_STS_PRT_4,
                    RES_STS_PRT_5,
                    RES_STS_PRT_6,
                    RES_STS_PRT_7,
                    RES_STS_PRT_8,
                    RES_STS_PRT_9,
                    RES_STS_PRT_10,
                    RES_CMF_1,
                    RES_CMF_2,
                    RES_CMF_3,
                    RES_CMF_4,
                    RES_CMF_5,
                    RES_CMF_6,
                    RES_CMF_7,
                    RES_CMF_8,
                    RES_CMF_9,
                    RES_CMF_10,
                    RES_CMF_11,
                    RES_CMF_12,
                    RES_CMF_13,
                    RES_CMF_14,
                    RES_CMF_15,
                    RES_CMF_16,
                    RES_CMF_17,
                    RES_CMF_18,
                    RES_CMF_19,
                    RES_CMF_20,
                    AREA_ID,
                    SUB_AREA_ID,
                    RES_LOCATION,
                    PROC_RULE,
                    MAX_PROC_COUNT,
                    BATCH_COND_1,
                    BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    RES_UP_DOWN_FLAG,
                    RES_PRI_STS,
                    RES_STS_1,
                    RES_STS_2,
                    RES_STS_3,
                    RES_STS_4,
                    RES_STS_5,
                    RES_STS_6,
                    RES_STS_7,
                    RES_STS_8,
                    RES_STS_9,
                    RES_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LAST_RECIPE_ID,
                    PROC_COUNT,
                    LAST_START_TIME,
                    LAST_END_TIME,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID,
                    LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ,
                    RES_SHORT_DESC
                INTO 
                    :MRASRESDEF_N.FACTORY,
                    :MRASRESDEF_N.RES_ID,
                    :MRASRESDEF_N.RES_DESC,
                    :MRASRESDEF_N.RES_TYPE,
                    :MRASRESDEF_N.RES_GRP_1,
                    :MRASRESDEF_N.RES_GRP_2,
                    :MRASRESDEF_N.RES_GRP_3,
                    :MRASRESDEF_N.RES_GRP_4,
                    :MRASRESDEF_N.RES_GRP_5,
                    :MRASRESDEF_N.RES_GRP_6,
                    :MRASRESDEF_N.RES_GRP_7,
                    :MRASRESDEF_N.RES_GRP_8,
                    :MRASRESDEF_N.RES_GRP_9,
                    :MRASRESDEF_N.RES_GRP_10,
                    :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                    :MRASRESDEF_N.RES_STS_PRT_1,
                    :MRASRESDEF_N.RES_STS_PRT_2,
                    :MRASRESDEF_N.RES_STS_PRT_3,
                    :MRASRESDEF_N.RES_STS_PRT_4,
                    :MRASRESDEF_N.RES_STS_PRT_5,
                    :MRASRESDEF_N.RES_STS_PRT_6,
                    :MRASRESDEF_N.RES_STS_PRT_7,
                    :MRASRESDEF_N.RES_STS_PRT_8,
                    :MRASRESDEF_N.RES_STS_PRT_9,
                    :MRASRESDEF_N.RES_STS_PRT_10,
                    :MRASRESDEF_N.RES_CMF_1,
                    :MRASRESDEF_N.RES_CMF_2,
                    :MRASRESDEF_N.RES_CMF_3,
                    :MRASRESDEF_N.RES_CMF_4,
                    :MRASRESDEF_N.RES_CMF_5,
                    :MRASRESDEF_N.RES_CMF_6,
                    :MRASRESDEF_N.RES_CMF_7,
                    :MRASRESDEF_N.RES_CMF_8,
                    :MRASRESDEF_N.RES_CMF_9,
                    :MRASRESDEF_N.RES_CMF_10,
                    :MRASRESDEF_N.RES_CMF_11,
                    :MRASRESDEF_N.RES_CMF_12,
                    :MRASRESDEF_N.RES_CMF_13,
                    :MRASRESDEF_N.RES_CMF_14,
                    :MRASRESDEF_N.RES_CMF_15,
                    :MRASRESDEF_N.RES_CMF_16,
                    :MRASRESDEF_N.RES_CMF_17,
                    :MRASRESDEF_N.RES_CMF_18,
                    :MRASRESDEF_N.RES_CMF_19,
                    :MRASRESDEF_N.RES_CMF_20,
                    :MRASRESDEF_N.AREA_ID,
                    :MRASRESDEF_N.SUB_AREA_ID,
                    :MRASRESDEF_N.RES_LOCATION,
                    :MRASRESDEF_N.PROC_RULE,
                    :MRASRESDEF_N.MAX_PROC_COUNT,
                    :MRASRESDEF_N.BATCH_COND_1,
                    :MRASRESDEF_N.BATCH_COND_2,
                    :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                    :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                    :MRASRESDEF_N.SEC_CHK_FLAG,
                    :MRASRESDEF_N.GATHER_ALARM_FLAG,
                    :MRASRESDEF_N.DELETE_FLAG,
                    :MRASRESDEF_N.DELETE_USER_ID,
                    :MRASRESDEF_N.DELETE_TIME,
                    :MRASRESDEF_N.CREATE_USER_ID,
                    :MRASRESDEF_N.CREATE_TIME,
                    :MRASRESDEF_N.UPDATE_USER_ID,
                    :MRASRESDEF_N.UPDATE_TIME,
                    :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                    :MRASRESDEF_N.RES_PRI_STS,
                    :MRASRESDEF_N.RES_STS_1,
                    :MRASRESDEF_N.RES_STS_2,
                    :MRASRESDEF_N.RES_STS_3,
                    :MRASRESDEF_N.RES_STS_4,
                    :MRASRESDEF_N.RES_STS_5,
                    :MRASRESDEF_N.RES_STS_6,
                    :MRASRESDEF_N.RES_STS_7,
                    :MRASRESDEF_N.RES_STS_8,
                    :MRASRESDEF_N.RES_STS_9,
                    :MRASRESDEF_N.RES_STS_10,
                    :MRASRESDEF_N.LOT_ID,
                    :MRASRESDEF_N.SUBLOT_ID,
                    :MRASRESDEF_N.CRR_ID,
                    :MRASRESDEF_N.RES_CTRL_MODE,
                    :MRASRESDEF_N.RES_PROC_MODE,
                    :MRASRESDEF_N.LAST_RECIPE_ID,
                    :MRASRESDEF_N.PROC_COUNT,
                    :MRASRESDEF_N.LAST_START_TIME,
                    :MRASRESDEF_N.LAST_END_TIME,
                    :MRASRESDEF_N.LAST_DOWN_TIME,
                    :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESDEF_N.LAST_EVENT_ID,
                    :MRASRESDEF_N.LAST_EVENT_TIME,
                    :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                    :MRASRESDEF_N.LAST_HIST_SEQ,
                    :MRASRESDEF_N.RES_SHORT_DESC
                FROM MRASRESDEF
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                  AND RES_CMF_1 = :MRASRESDEF_N.RES_CMF_1
                  AND RES_GRP_1 = :MRASRESDEF_N.RES_GRP_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,RES_DESC ,RES_TYPE ,RES_GRP_1 ,RES_GR\
P_2 ,RES_GRP_3 ,RES_GRP_4 ,RES_GRP_5 ,RES_GRP_6 ,RES_GRP_7 ,RES_GRP_8 ,RES_G\
RP_9 ,RES_GRP_10 ,USE_FAC_PRT_FLAG ,RES_STS_PRT_1 ,RES_STS_PRT_2 ,RES_STS_PR\
T_3 ,RES_STS_PRT_4 ,RES_STS_PRT_5 ,RES_STS_PRT_6 ,RES_STS_PRT_7 ,RES_STS_PRT\
_8 ,RES_STS_PRT_9 ,RES_STS_PRT_10 ,RES_CMF_1 ,RES_CMF_2 ,RES_CMF_3 ,RES_CMF_\
4 ,RES_CMF_5 ,RES_CMF_6 ,RES_CMF_7 ,RES_CMF_8 ,RES_CMF_9 ,RES_CMF_10 ,RES_CM\
F_11 ,RES_CMF_12 ,RES_CMF_13 ,RES_CMF_14 ,RES_CMF_15 ,RES_CMF_16 ,RES_CMF_17\
 ,RES_CMF_18 ,RES_CMF_19 ,RES_CMF_20 ,AREA_ID ,SUB_AREA_ID ,RES_LOCATION ,PR\
OC_RULE ,MAX_PROC_COUNT ,BATCH_COND_1 ,BATCH_COND_2 ,PM_SCH_ENABLE_FLAG ,UNI\
T_BASE_ST_FLAG ,SEC_CHK_FLAG ,GATHER_ALARM_FLAG ,DELETE_FLAG ,DELETE_USER_ID\
 ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,RES\
_UP_DOWN_FLAG ,RES_PRI_STS ,RES_STS_1 ,RES_STS_2 ,RES_STS_3 ,RES_STS_4 ,RES_\
STS_5 ,RES_STS_6 ,RES_STS_7 ,RES_STS_8 ,RES_STS_9 ,RES_STS_10 ,LOT_ID ,SUBLO\
T_ID ,CRR_ID ,RES_CTRL_MODE ,RES_PROC_MODE ,LAST_RE");
            sqlstm.stmt = "CIPE_ID ,PROC_COUNT ,LAST_START_TIME ,LAST_END_T\
IME ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,LAST_EVENT_ID ,LAST_EVENT_TIME ,LAST\
_ACTIVE_HIST_SEQ ,LAST_HIST_SEQ ,RES_SHORT_DESC into :b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90  from MRASRESDEF where ((FACTORY=:b0 and \
RES_CMF_1=:b25) and RES_GRP_1=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )392;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[51] = (unsigned int  )13;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )26;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[78] = (unsigned int  )3;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )13;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[90] = (unsigned int  )51;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[91] = (unsigned int  )11;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
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
        DBU_del_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    }

    DB_stop_query_timer("DBU_select_mrasresdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_mrasresdef_for_update(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    RES_ID,
                    RES_DESC,
                    RES_TYPE,
                    RES_GRP_1,
                    RES_GRP_2,
                    RES_GRP_3,
                    RES_GRP_4,
                    RES_GRP_5,
                    RES_GRP_6,
                    RES_GRP_7,
                    RES_GRP_8,
                    RES_GRP_9,
                    RES_GRP_10,
                    USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1,
                    RES_STS_PRT_2,
                    RES_STS_PRT_3,
                    RES_STS_PRT_4,
                    RES_STS_PRT_5,
                    RES_STS_PRT_6,
                    RES_STS_PRT_7,
                    RES_STS_PRT_8,
                    RES_STS_PRT_9,
                    RES_STS_PRT_10,
                    RES_CMF_1,
                    RES_CMF_2,
                    RES_CMF_3,
                    RES_CMF_4,
                    RES_CMF_5,
                    RES_CMF_6,
                    RES_CMF_7,
                    RES_CMF_8,
                    RES_CMF_9,
                    RES_CMF_10,
                    RES_CMF_11,
                    RES_CMF_12,
                    RES_CMF_13,
                    RES_CMF_14,
                    RES_CMF_15,
                    RES_CMF_16,
                    RES_CMF_17,
                    RES_CMF_18,
                    RES_CMF_19,
                    RES_CMF_20,
                    AREA_ID,
                    SUB_AREA_ID,
                    RES_LOCATION,
                    PROC_RULE,
                    MAX_PROC_COUNT,
                    BATCH_COND_1,
                    BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    RES_UP_DOWN_FLAG,
                    RES_PRI_STS,
                    RES_STS_1,
                    RES_STS_2,
                    RES_STS_3,
                    RES_STS_4,
                    RES_STS_5,
                    RES_STS_6,
                    RES_STS_7,
                    RES_STS_8,
                    RES_STS_9,
                    RES_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LAST_RECIPE_ID,
                    PROC_COUNT,
                    LAST_START_TIME,
                    LAST_END_TIME,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID,
                    LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ,
                    RES_SHORT_DESC
                INTO 
                    :MRASRESDEF_N.FACTORY,
                    :MRASRESDEF_N.RES_ID,
                    :MRASRESDEF_N.RES_DESC,
                    :MRASRESDEF_N.RES_TYPE,
                    :MRASRESDEF_N.RES_GRP_1,
                    :MRASRESDEF_N.RES_GRP_2,
                    :MRASRESDEF_N.RES_GRP_3,
                    :MRASRESDEF_N.RES_GRP_4,
                    :MRASRESDEF_N.RES_GRP_5,
                    :MRASRESDEF_N.RES_GRP_6,
                    :MRASRESDEF_N.RES_GRP_7,
                    :MRASRESDEF_N.RES_GRP_8,
                    :MRASRESDEF_N.RES_GRP_9,
                    :MRASRESDEF_N.RES_GRP_10,
                    :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                    :MRASRESDEF_N.RES_STS_PRT_1,
                    :MRASRESDEF_N.RES_STS_PRT_2,
                    :MRASRESDEF_N.RES_STS_PRT_3,
                    :MRASRESDEF_N.RES_STS_PRT_4,
                    :MRASRESDEF_N.RES_STS_PRT_5,
                    :MRASRESDEF_N.RES_STS_PRT_6,
                    :MRASRESDEF_N.RES_STS_PRT_7,
                    :MRASRESDEF_N.RES_STS_PRT_8,
                    :MRASRESDEF_N.RES_STS_PRT_9,
                    :MRASRESDEF_N.RES_STS_PRT_10,
                    :MRASRESDEF_N.RES_CMF_1,
                    :MRASRESDEF_N.RES_CMF_2,
                    :MRASRESDEF_N.RES_CMF_3,
                    :MRASRESDEF_N.RES_CMF_4,
                    :MRASRESDEF_N.RES_CMF_5,
                    :MRASRESDEF_N.RES_CMF_6,
                    :MRASRESDEF_N.RES_CMF_7,
                    :MRASRESDEF_N.RES_CMF_8,
                    :MRASRESDEF_N.RES_CMF_9,
                    :MRASRESDEF_N.RES_CMF_10,
                    :MRASRESDEF_N.RES_CMF_11,
                    :MRASRESDEF_N.RES_CMF_12,
                    :MRASRESDEF_N.RES_CMF_13,
                    :MRASRESDEF_N.RES_CMF_14,
                    :MRASRESDEF_N.RES_CMF_15,
                    :MRASRESDEF_N.RES_CMF_16,
                    :MRASRESDEF_N.RES_CMF_17,
                    :MRASRESDEF_N.RES_CMF_18,
                    :MRASRESDEF_N.RES_CMF_19,
                    :MRASRESDEF_N.RES_CMF_20,
                    :MRASRESDEF_N.AREA_ID,
                    :MRASRESDEF_N.SUB_AREA_ID,
                    :MRASRESDEF_N.RES_LOCATION,
                    :MRASRESDEF_N.PROC_RULE,
                    :MRASRESDEF_N.MAX_PROC_COUNT,
                    :MRASRESDEF_N.BATCH_COND_1,
                    :MRASRESDEF_N.BATCH_COND_2,
                    :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                    :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                    :MRASRESDEF_N.SEC_CHK_FLAG,
                    :MRASRESDEF_N.GATHER_ALARM_FLAG,
                    :MRASRESDEF_N.DELETE_FLAG,
                    :MRASRESDEF_N.DELETE_USER_ID,
                    :MRASRESDEF_N.DELETE_TIME,
                    :MRASRESDEF_N.CREATE_USER_ID,
                    :MRASRESDEF_N.CREATE_TIME,
                    :MRASRESDEF_N.UPDATE_USER_ID,
                    :MRASRESDEF_N.UPDATE_TIME,
                    :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                    :MRASRESDEF_N.RES_PRI_STS,
                    :MRASRESDEF_N.RES_STS_1,
                    :MRASRESDEF_N.RES_STS_2,
                    :MRASRESDEF_N.RES_STS_3,
                    :MRASRESDEF_N.RES_STS_4,
                    :MRASRESDEF_N.RES_STS_5,
                    :MRASRESDEF_N.RES_STS_6,
                    :MRASRESDEF_N.RES_STS_7,
                    :MRASRESDEF_N.RES_STS_8,
                    :MRASRESDEF_N.RES_STS_9,
                    :MRASRESDEF_N.RES_STS_10,
                    :MRASRESDEF_N.LOT_ID,
                    :MRASRESDEF_N.SUBLOT_ID,
                    :MRASRESDEF_N.CRR_ID,
                    :MRASRESDEF_N.RES_CTRL_MODE,
                    :MRASRESDEF_N.RES_PROC_MODE,
                    :MRASRESDEF_N.LAST_RECIPE_ID,
                    :MRASRESDEF_N.PROC_COUNT,
                    :MRASRESDEF_N.LAST_START_TIME,
                    :MRASRESDEF_N.LAST_END_TIME,
                    :MRASRESDEF_N.LAST_DOWN_TIME,
                    :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESDEF_N.LAST_EVENT_ID,
                    :MRASRESDEF_N.LAST_EVENT_TIME,
                    :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                    :MRASRESDEF_N.LAST_HIST_SEQ,
                    :MRASRESDEF_N.RES_SHORT_DESC
                FROM MRASRESDEF
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                    AND RES_ID = :MRASRESDEF_N.RES_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,RES_DESC ,RES_TYPE ,RES_GRP_1 ,RES_GR\
P_2 ,RES_GRP_3 ,RES_GRP_4 ,RES_GRP_5 ,RES_GRP_6 ,RES_GRP_7 ,RES_GRP_8 ,RES_G\
RP_9 ,RES_GRP_10 ,USE_FAC_PRT_FLAG ,RES_STS_PRT_1 ,RES_STS_PRT_2 ,RES_STS_PR\
T_3 ,RES_STS_PRT_4 ,RES_STS_PRT_5 ,RES_STS_PRT_6 ,RES_STS_PRT_7 ,RES_STS_PRT\
_8 ,RES_STS_PRT_9 ,RES_STS_PRT_10 ,RES_CMF_1 ,RES_CMF_2 ,RES_CMF_3 ,RES_CMF_\
4 ,RES_CMF_5 ,RES_CMF_6 ,RES_CMF_7 ,RES_CMF_8 ,RES_CMF_9 ,RES_CMF_10 ,RES_CM\
F_11 ,RES_CMF_12 ,RES_CMF_13 ,RES_CMF_14 ,RES_CMF_15 ,RES_CMF_16 ,RES_CMF_17\
 ,RES_CMF_18 ,RES_CMF_19 ,RES_CMF_20 ,AREA_ID ,SUB_AREA_ID ,RES_LOCATION ,PR\
OC_RULE ,MAX_PROC_COUNT ,BATCH_COND_1 ,BATCH_COND_2 ,PM_SCH_ENABLE_FLAG ,UNI\
T_BASE_ST_FLAG ,SEC_CHK_FLAG ,GATHER_ALARM_FLAG ,DELETE_FLAG ,DELETE_USER_ID\
 ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,RES\
_UP_DOWN_FLAG ,RES_PRI_STS ,RES_STS_1 ,RES_STS_2 ,RES_STS_3 ,RES_STS_4 ,RES_\
STS_5 ,RES_STS_6 ,RES_STS_7 ,RES_STS_8 ,RES_STS_9 ,RES_STS_10 ,LOT_ID ,SUBLO\
T_ID ,CRR_ID ,RES_CTRL_MODE ,RES_PROC_MODE ,LAST_RE");
            sqlstm.stmt = "CIPE_ID ,PROC_COUNT ,LAST_START_TIME ,LAST_END_T\
IME ,LAST_DOWN_TIME ,LAST_DOWN_HIST_SEQ ,LAST_EVENT_ID ,LAST_EVENT_TIME ,LAST\
_ACTIVE_HIST_SEQ ,LAST_HIST_SEQ ,RES_SHORT_DESC into :b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90  from MRASRESDEF where (FACTORY=:b0 and R\
ES_ID=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )783;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[51] = (unsigned int  )13;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )26;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[78] = (unsigned int  )3;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )13;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[90] = (unsigned int  )51;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[91] = (unsigned int  )11;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
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
        DBU_del_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    }

    DB_stop_query_timer("DBU_select_mrasresdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_mrasresdef_scalar(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MRASRESDEF
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                    AND RES_ID = :MRASRESDEF_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MRASRESDEF where\
 (FACTORY=:b1 and RES_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1170;
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
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_ID);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_select_mrasresdef_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_mrasresdef(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MRASRESDEF
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                    AND RES_ID = :MRASRESDEF_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MRASRESDEF  where (FACTORY=:b0 and \
RES_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1197;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
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

    DB_stop_query_timer("DBU_delete_mrasresdef", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_mrasresdef(struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MRASRESDEF( 
                    FACTORY, 
                    RES_ID, 
                    RES_DESC, 
                    RES_TYPE, 
                    RES_GRP_1, 
                    RES_GRP_2, 
                    RES_GRP_3, 
                    RES_GRP_4, 
                    RES_GRP_5, 
                    RES_GRP_6, 
                    RES_GRP_7, 
                    RES_GRP_8, 
                    RES_GRP_9, 
                    RES_GRP_10, 
                    USE_FAC_PRT_FLAG, 
                    RES_STS_PRT_1, 
                    RES_STS_PRT_2, 
                    RES_STS_PRT_3, 
                    RES_STS_PRT_4, 
                    RES_STS_PRT_5, 
                    RES_STS_PRT_6, 
                    RES_STS_PRT_7, 
                    RES_STS_PRT_8, 
                    RES_STS_PRT_9, 
                    RES_STS_PRT_10, 
                    RES_CMF_1, 
                    RES_CMF_2, 
                    RES_CMF_3, 
                    RES_CMF_4, 
                    RES_CMF_5, 
                    RES_CMF_6, 
                    RES_CMF_7, 
                    RES_CMF_8, 
                    RES_CMF_9, 
                    RES_CMF_10, 
                    RES_CMF_11, 
                    RES_CMF_12, 
                    RES_CMF_13, 
                    RES_CMF_14, 
                    RES_CMF_15, 
                    RES_CMF_16, 
                    RES_CMF_17, 
                    RES_CMF_18, 
                    RES_CMF_19, 
                    RES_CMF_20, 
                    AREA_ID, 
                    SUB_AREA_ID, 
                    RES_LOCATION, 
                    PROC_RULE, 
                    MAX_PROC_COUNT, 
                    BATCH_COND_1, 
                    BATCH_COND_2, 
                    PM_SCH_ENABLE_FLAG, 
                    UNIT_BASE_ST_FLAG, 
                    SEC_CHK_FLAG, 
                    GATHER_ALARM_FLAG, 
                    DELETE_FLAG, 
                    DELETE_USER_ID, 
                    DELETE_TIME, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    RES_UP_DOWN_FLAG, 
                    RES_PRI_STS, 
                    RES_STS_1, 
                    RES_STS_2, 
                    RES_STS_3, 
                    RES_STS_4, 
                    RES_STS_5, 
                    RES_STS_6, 
                    RES_STS_7, 
                    RES_STS_8, 
                    RES_STS_9, 
                    RES_STS_10, 
                    LOT_ID, 
                    SUBLOT_ID, 
                    CRR_ID, 
                    RES_CTRL_MODE, 
                    RES_PROC_MODE, 
                    LAST_RECIPE_ID, 
                    PROC_COUNT, 
                    LAST_START_TIME, 
                    LAST_END_TIME, 
                    LAST_DOWN_TIME, 
                    LAST_DOWN_HIST_SEQ, 
                    LAST_EVENT_ID, 
                    LAST_EVENT_TIME, 
                    LAST_ACTIVE_HIST_SEQ, 
                    LAST_HIST_SEQ, 
                    RES_SHORT_DESC
         ) 
        VALUES (
                    :MRASRESDEF_N.FACTORY,
                    :MRASRESDEF_N.RES_ID,
                    :MRASRESDEF_N.RES_DESC,
                    :MRASRESDEF_N.RES_TYPE,
                    :MRASRESDEF_N.RES_GRP_1,
                    :MRASRESDEF_N.RES_GRP_2,
                    :MRASRESDEF_N.RES_GRP_3,
                    :MRASRESDEF_N.RES_GRP_4,
                    :MRASRESDEF_N.RES_GRP_5,
                    :MRASRESDEF_N.RES_GRP_6,
                    :MRASRESDEF_N.RES_GRP_7,
                    :MRASRESDEF_N.RES_GRP_8,
                    :MRASRESDEF_N.RES_GRP_9,
                    :MRASRESDEF_N.RES_GRP_10,
                    :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                    :MRASRESDEF_N.RES_STS_PRT_1,
                    :MRASRESDEF_N.RES_STS_PRT_2,
                    :MRASRESDEF_N.RES_STS_PRT_3,
                    :MRASRESDEF_N.RES_STS_PRT_4,
                    :MRASRESDEF_N.RES_STS_PRT_5,
                    :MRASRESDEF_N.RES_STS_PRT_6,
                    :MRASRESDEF_N.RES_STS_PRT_7,
                    :MRASRESDEF_N.RES_STS_PRT_8,
                    :MRASRESDEF_N.RES_STS_PRT_9,
                    :MRASRESDEF_N.RES_STS_PRT_10,
                    :MRASRESDEF_N.RES_CMF_1,
                    :MRASRESDEF_N.RES_CMF_2,
                    :MRASRESDEF_N.RES_CMF_3,
                    :MRASRESDEF_N.RES_CMF_4,
                    :MRASRESDEF_N.RES_CMF_5,
                    :MRASRESDEF_N.RES_CMF_6,
                    :MRASRESDEF_N.RES_CMF_7,
                    :MRASRESDEF_N.RES_CMF_8,
                    :MRASRESDEF_N.RES_CMF_9,
                    :MRASRESDEF_N.RES_CMF_10,
                    :MRASRESDEF_N.RES_CMF_11,
                    :MRASRESDEF_N.RES_CMF_12,
                    :MRASRESDEF_N.RES_CMF_13,
                    :MRASRESDEF_N.RES_CMF_14,
                    :MRASRESDEF_N.RES_CMF_15,
                    :MRASRESDEF_N.RES_CMF_16,
                    :MRASRESDEF_N.RES_CMF_17,
                    :MRASRESDEF_N.RES_CMF_18,
                    :MRASRESDEF_N.RES_CMF_19,
                    :MRASRESDEF_N.RES_CMF_20,
                    :MRASRESDEF_N.AREA_ID,
                    :MRASRESDEF_N.SUB_AREA_ID,
                    :MRASRESDEF_N.RES_LOCATION,
                    :MRASRESDEF_N.PROC_RULE,
                    :MRASRESDEF_N.MAX_PROC_COUNT,
                    :MRASRESDEF_N.BATCH_COND_1,
                    :MRASRESDEF_N.BATCH_COND_2,
                    :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                    :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                    :MRASRESDEF_N.SEC_CHK_FLAG,
                    :MRASRESDEF_N.GATHER_ALARM_FLAG,
                    :MRASRESDEF_N.DELETE_FLAG,
                    :MRASRESDEF_N.DELETE_USER_ID,
                    :MRASRESDEF_N.DELETE_TIME,
                    :MRASRESDEF_N.CREATE_USER_ID,
                    :MRASRESDEF_N.CREATE_TIME,
                    :MRASRESDEF_N.UPDATE_USER_ID,
                    :MRASRESDEF_N.UPDATE_TIME,
                    :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                    :MRASRESDEF_N.RES_PRI_STS,
                    :MRASRESDEF_N.RES_STS_1,
                    :MRASRESDEF_N.RES_STS_2,
                    :MRASRESDEF_N.RES_STS_3,
                    :MRASRESDEF_N.RES_STS_4,
                    :MRASRESDEF_N.RES_STS_5,
                    :MRASRESDEF_N.RES_STS_6,
                    :MRASRESDEF_N.RES_STS_7,
                    :MRASRESDEF_N.RES_STS_8,
                    :MRASRESDEF_N.RES_STS_9,
                    :MRASRESDEF_N.RES_STS_10,
                    :MRASRESDEF_N.LOT_ID,
                    :MRASRESDEF_N.SUBLOT_ID,
                    :MRASRESDEF_N.CRR_ID,
                    :MRASRESDEF_N.RES_CTRL_MODE,
                    :MRASRESDEF_N.RES_PROC_MODE,
                    :MRASRESDEF_N.LAST_RECIPE_ID,
                    :MRASRESDEF_N.PROC_COUNT,
                    :MRASRESDEF_N.LAST_START_TIME,
                    :MRASRESDEF_N.LAST_END_TIME,
                    :MRASRESDEF_N.LAST_DOWN_TIME,
                    :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                    :MRASRESDEF_N.LAST_EVENT_ID,
                    :MRASRESDEF_N.LAST_EVENT_TIME,
                    :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                    :MRASRESDEF_N.LAST_HIST_SEQ,
                    :MRASRESDEF_N.RES_SHORT_DESC
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 94;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MRASRESDEF (FACTORY,RES_ID,RES_DESC,RES_TYPE,RES_GRP_1,RE\
S_GRP_2,RES_GRP_3,RES_GRP_4,RES_GRP_5,RES_GRP_6,RES_GRP_7,RES_GRP_8,RES_GRP_\
9,RES_GRP_10,USE_FAC_PRT_FLAG,RES_STS_PRT_1,RES_STS_PRT_2,RES_STS_PRT_3,RES_\
STS_PRT_4,RES_STS_PRT_5,RES_STS_PRT_6,RES_STS_PRT_7,RES_STS_PRT_8,RES_STS_PR\
T_9,RES_STS_PRT_10,RES_CMF_1,RES_CMF_2,RES_CMF_3,RES_CMF_4,RES_CMF_5,RES_CMF\
_6,RES_CMF_7,RES_CMF_8,RES_CMF_9,RES_CMF_10,RES_CMF_11,RES_CMF_12,RES_CMF_13\
,RES_CMF_14,RES_CMF_15,RES_CMF_16,RES_CMF_17,RES_CMF_18,RES_CMF_19,RES_CMF_2\
0,AREA_ID,SUB_AREA_ID,RES_LOCATION,PROC_RULE,MAX_PROC_COUNT,BATCH_COND_1,BAT\
CH_COND_2,PM_SCH_ENABLE_FLAG,UNIT_BASE_ST_FLAG,SEC_CHK_FLAG,GATHER_ALARM_FLA\
G,DELETE_FLAG,DELETE_USER_ID,DELETE_TIME,CREATE_USER_ID,CREATE_TIME,UPDATE_U\
SER_ID,UPDATE_TIME,RES_UP_DOWN_FLAG,RES_PRI_STS,RES_STS_1,RES_STS_2,RES_STS_\
3,RES_STS_4,RES_STS_5,RES_STS_6,RES_STS_7,RES_STS_8,RES_STS_9,RES_STS_10,LOT\
_ID,SUBLOT_ID,CRR_ID,RES_CTRL_MODE,RES_PROC_MODE,LAST_RECIPE_ID,PROC_COUNT,L\
AST_START_TIME,LAST_END_TIME,LAST_DOWN_TIME");
    sqlstm.stmt = ",LAST_DOWN_HIST_SEQ,LAST_EVENT_ID,LAST_EVENT_TIME,LAST_A\
CTIVE_HIST_SEQ,LAST_HIST_SEQ,RES_SHORT_DESC) values (:b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1220;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
    sqlstm.sqhstl[3] = (unsigned int  )21;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
    sqlstm.sqhstl[14] = (unsigned int  )2;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
    sqlstm.sqhstl[36] = (unsigned int  )31;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
    sqlstm.sqhstl[37] = (unsigned int  )31;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
    sqlstm.sqhstl[38] = (unsigned int  )31;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
    sqlstm.sqhstl[39] = (unsigned int  )31;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
    sqlstm.sqhstl[40] = (unsigned int  )31;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
    sqlstm.sqhstl[42] = (unsigned int  )31;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
    sqlstm.sqhstl[44] = (unsigned int  )31;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
    sqlstm.sqhstl[45] = (unsigned int  )21;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
    sqlstm.sqhstl[46] = (unsigned int  )21;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
    sqlstm.sqhstl[47] = (unsigned int  )21;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
    sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
    sqlstm.sqhstl[50] = (unsigned int  )13;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
    sqlstm.sqhstl[51] = (unsigned int  )13;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
    sqlstm.sqhstl[53] = (unsigned int  )2;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
    sqlstm.sqhstl[56] = (unsigned int  )2;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
    sqlstm.sqhstl[57] = (unsigned int  )21;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
    sqlstm.sqhstl[58] = (unsigned int  )15;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[59] = (unsigned int  )21;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
    sqlstm.sqhstl[60] = (unsigned int  )15;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[61] = (unsigned int  )21;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[62] = (unsigned int  )15;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
    sqlstm.sqhstl[63] = (unsigned int  )2;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
    sqlstm.sqhstl[75] = (unsigned int  )26;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
    sqlstm.sqhstl[77] = (unsigned int  )21;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
    sqlstm.sqhstl[78] = (unsigned int  )3;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
    sqlstm.sqhstl[79] = (unsigned int  )11;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
    sqlstm.sqhstl[80] = (unsigned int  )31;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
    sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
    sqlstm.sqhstl[82] = (unsigned int  )15;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
    sqlstm.sqhstl[83] = (unsigned int  )15;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
    sqlstm.sqhstl[84] = (unsigned int  )15;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
    sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
    sqlstm.sqhstl[86] = (unsigned int  )13;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
    sqlstm.sqhstl[87] = (unsigned int  )15;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
    sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
    sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
    sqlstm.sqhstl[90] = (unsigned int  )51;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_mrasresdef", 0);
}


/* SQL UPDATE Function */
void DBU_update_mrasresdef(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MRASRESDEF SET
                    RES_DESC = :MRASRESDEF_N.RES_DESC,
                    RES_TYPE = :MRASRESDEF_N.RES_TYPE,
                    RES_GRP_1 = :MRASRESDEF_N.RES_GRP_1,
                    RES_GRP_2 = :MRASRESDEF_N.RES_GRP_2,
                    RES_GRP_3 = :MRASRESDEF_N.RES_GRP_3,
                    RES_GRP_4 = :MRASRESDEF_N.RES_GRP_4,
                    RES_GRP_5 = :MRASRESDEF_N.RES_GRP_5,
                    RES_GRP_6 = :MRASRESDEF_N.RES_GRP_6,
                    RES_GRP_7 = :MRASRESDEF_N.RES_GRP_7,
                    RES_GRP_8 = :MRASRESDEF_N.RES_GRP_8,
                    RES_GRP_9 = :MRASRESDEF_N.RES_GRP_9,
                    RES_GRP_10 = :MRASRESDEF_N.RES_GRP_10,
                    USE_FAC_PRT_FLAG = :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1 = :MRASRESDEF_N.RES_STS_PRT_1,
                    RES_STS_PRT_2 = :MRASRESDEF_N.RES_STS_PRT_2,
                    RES_STS_PRT_3 = :MRASRESDEF_N.RES_STS_PRT_3,
                    RES_STS_PRT_4 = :MRASRESDEF_N.RES_STS_PRT_4,
                    RES_STS_PRT_5 = :MRASRESDEF_N.RES_STS_PRT_5,
                    RES_STS_PRT_6 = :MRASRESDEF_N.RES_STS_PRT_6,
                    RES_STS_PRT_7 = :MRASRESDEF_N.RES_STS_PRT_7,
                    RES_STS_PRT_8 = :MRASRESDEF_N.RES_STS_PRT_8,
                    RES_STS_PRT_9 = :MRASRESDEF_N.RES_STS_PRT_9,
                    RES_STS_PRT_10 = :MRASRESDEF_N.RES_STS_PRT_10,
                    RES_CMF_1 = :MRASRESDEF_N.RES_CMF_1,
                    RES_CMF_2 = :MRASRESDEF_N.RES_CMF_2,
                    RES_CMF_3 = :MRASRESDEF_N.RES_CMF_3,
                    RES_CMF_4 = :MRASRESDEF_N.RES_CMF_4,
                    RES_CMF_5 = :MRASRESDEF_N.RES_CMF_5,
                    RES_CMF_6 = :MRASRESDEF_N.RES_CMF_6,
                    RES_CMF_7 = :MRASRESDEF_N.RES_CMF_7,
                    RES_CMF_8 = :MRASRESDEF_N.RES_CMF_8,
                    RES_CMF_9 = :MRASRESDEF_N.RES_CMF_9,
                    RES_CMF_10 = :MRASRESDEF_N.RES_CMF_10,
                    RES_CMF_11 = :MRASRESDEF_N.RES_CMF_11,
                    RES_CMF_12 = :MRASRESDEF_N.RES_CMF_12,
                    RES_CMF_13 = :MRASRESDEF_N.RES_CMF_13,
                    RES_CMF_14 = :MRASRESDEF_N.RES_CMF_14,
                    RES_CMF_15 = :MRASRESDEF_N.RES_CMF_15,
                    RES_CMF_16 = :MRASRESDEF_N.RES_CMF_16,
                    RES_CMF_17 = :MRASRESDEF_N.RES_CMF_17,
                    RES_CMF_18 = :MRASRESDEF_N.RES_CMF_18,
                    RES_CMF_19 = :MRASRESDEF_N.RES_CMF_19,
                    RES_CMF_20 = :MRASRESDEF_N.RES_CMF_20,
                    AREA_ID = :MRASRESDEF_N.AREA_ID,
                    SUB_AREA_ID = :MRASRESDEF_N.SUB_AREA_ID,
                    RES_LOCATION = :MRASRESDEF_N.RES_LOCATION,
                    PROC_RULE = :MRASRESDEF_N.PROC_RULE,
                    MAX_PROC_COUNT = :MRASRESDEF_N.MAX_PROC_COUNT,
                    BATCH_COND_1 = :MRASRESDEF_N.BATCH_COND_1,
                    BATCH_COND_2 = :MRASRESDEF_N.BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG = :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG = :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG = :MRASRESDEF_N.SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG = :MRASRESDEF_N.GATHER_ALARM_FLAG,
                    DELETE_FLAG = :MRASRESDEF_N.DELETE_FLAG,
                    DELETE_USER_ID = :MRASRESDEF_N.DELETE_USER_ID,
                    DELETE_TIME = :MRASRESDEF_N.DELETE_TIME,
                    CREATE_USER_ID = :MRASRESDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MRASRESDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MRASRESDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MRASRESDEF_N.UPDATE_TIME,
                    RES_UP_DOWN_FLAG = :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                    RES_PRI_STS = :MRASRESDEF_N.RES_PRI_STS,
                    RES_STS_1 = :MRASRESDEF_N.RES_STS_1,
                    RES_STS_2 = :MRASRESDEF_N.RES_STS_2,
                    RES_STS_3 = :MRASRESDEF_N.RES_STS_3,
                    RES_STS_4 = :MRASRESDEF_N.RES_STS_4,
                    RES_STS_5 = :MRASRESDEF_N.RES_STS_5,
                    RES_STS_6 = :MRASRESDEF_N.RES_STS_6,
                    RES_STS_7 = :MRASRESDEF_N.RES_STS_7,
                    RES_STS_8 = :MRASRESDEF_N.RES_STS_8,
                    RES_STS_9 = :MRASRESDEF_N.RES_STS_9,
                    RES_STS_10 = :MRASRESDEF_N.RES_STS_10,
                    LOT_ID = :MRASRESDEF_N.LOT_ID,
                    SUBLOT_ID = :MRASRESDEF_N.SUBLOT_ID,
                    CRR_ID = :MRASRESDEF_N.CRR_ID,
                    RES_CTRL_MODE = :MRASRESDEF_N.RES_CTRL_MODE,
                    RES_PROC_MODE = :MRASRESDEF_N.RES_PROC_MODE,
                    LAST_RECIPE_ID = :MRASRESDEF_N.LAST_RECIPE_ID,
                    PROC_COUNT = :MRASRESDEF_N.PROC_COUNT,
                    LAST_START_TIME = :MRASRESDEF_N.LAST_START_TIME,
                    LAST_END_TIME = :MRASRESDEF_N.LAST_END_TIME,
                    LAST_DOWN_TIME = :MRASRESDEF_N.LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ = :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID = :MRASRESDEF_N.LAST_EVENT_ID,
                    LAST_EVENT_TIME = :MRASRESDEF_N.LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ = :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ = :MRASRESDEF_N.LAST_HIST_SEQ,
                    RES_SHORT_DESC = :MRASRESDEF_N.RES_SHORT_DESC
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                    AND RES_ID = :MRASRESDEF_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MRASRESDEF  set RES_DESC=:b0,RES_TYPE=:b1,RES_GRP_1=:b\
2,RES_GRP_2=:b3,RES_GRP_3=:b4,RES_GRP_4=:b5,RES_GRP_5=:b6,RES_GRP_6=:b7,RES_\
GRP_7=:b8,RES_GRP_8=:b9,RES_GRP_9=:b10,RES_GRP_10=:b11,USE_FAC_PRT_FLAG=:b12\
,RES_STS_PRT_1=:b13,RES_STS_PRT_2=:b14,RES_STS_PRT_3=:b15,RES_STS_PRT_4=:b16\
,RES_STS_PRT_5=:b17,RES_STS_PRT_6=:b18,RES_STS_PRT_7=:b19,RES_STS_PRT_8=:b20\
,RES_STS_PRT_9=:b21,RES_STS_PRT_10=:b22,RES_CMF_1=:b23,RES_CMF_2=:b24,RES_CM\
F_3=:b25,RES_CMF_4=:b26,RES_CMF_5=:b27,RES_CMF_6=:b28,RES_CMF_7=:b29,RES_CMF\
_8=:b30,RES_CMF_9=:b31,RES_CMF_10=:b32,RES_CMF_11=:b33,RES_CMF_12=:b34,RES_C\
MF_13=:b35,RES_CMF_14=:b36,RES_CMF_15=:b37,RES_CMF_16=:b38,RES_CMF_17=:b39,R\
ES_CMF_18=:b40,RES_CMF_19=:b41,RES_CMF_20=:b42,AREA_ID=:b43,SUB_AREA_ID=:b44\
,RES_LOCATION=:b45,PROC_RULE=:b46,MAX_PROC_COUNT=:b47,BATCH_COND_1=:b48,BATC\
H_COND_2=:b49,PM_SCH_ENABLE_FLAG=:b50,UNIT_BASE_ST_FLAG=:b51,SEC_CHK_FLAG=:b\
52,GATHER_ALARM_FLAG=:b53,DELETE_FLAG=:b54,DELETE_USER_ID=:b55,DELETE_TIME=:\
b56,CREATE_USER_ID=:b57,CREATE_TIME=:b58,UPDATE_USE");
            sqlstm.stmt = "R_ID=:b59,UPDATE_TIME=:b60,RES_UP_DOWN_FLAG=:b61\
,RES_PRI_STS=:b62,RES_STS_1=:b63,RES_STS_2=:b64,RES_STS_3=:b65,RES_STS_4=:b66\
,RES_STS_5=:b67,RES_STS_6=:b68,RES_STS_7=:b69,RES_STS_8=:b70,RES_STS_9=:b71,R\
ES_STS_10=:b72,LOT_ID=:b73,SUBLOT_ID=:b74,CRR_ID=:b75,RES_CTRL_MODE=:b76,RES_\
PROC_MODE=:b77,LAST_RECIPE_ID=:b78,PROC_COUNT=:b79,LAST_START_TIME=:b80,LAST_\
END_TIME=:b81,LAST_DOWN_TIME=:b82,LAST_DOWN_HIST_SEQ=:b83,LAST_EVENT_ID=:b84,\
LAST_EVENT_TIME=:b85,LAST_ACTIVE_HIST_SEQ=:b86,LAST_HIST_SEQ=:b87,RES_SHORT_D\
ESC=:b88 where (FACTORY=:b89 and RES_ID=:b90)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1599;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[43] = (unsigned int  )21;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[48] = (unsigned int  )13;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[49] = (unsigned int  )13;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[55] = (unsigned int  )21;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[56] = (unsigned int  )15;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[73] = (unsigned int  )26;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[76] = (unsigned int  )3;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[77] = (unsigned int  )11;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[80] = (unsigned int  )15;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[83] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[84] = (unsigned int  )13;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[85] = (unsigned int  )15;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[86] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[87] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[88] = (unsigned int  )51;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[89] = (unsigned int  )11;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[90] = (unsigned int  )21;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
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
            /* EXEC SQL UPDATE MRASRESDEF SET
                    RES_UP_DOWN_FLAG = :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                    RES_PRI_STS = :MRASRESDEF_N.RES_PRI_STS,
                    RES_STS_1 = :MRASRESDEF_N.RES_STS_1,
                    RES_STS_2 = :MRASRESDEF_N.RES_STS_2
                WHERE FACTORY = :MRASRESDEF_N.FACTORY
                    AND RES_ID = :MRASRESDEF_N.RES_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MRASRESDEF  set RES_UP_DOWN_FLAG=:b0,RES_\
PRI_STS=:b1,RES_STS_1=:b2,RES_STS_2=:b3 where (FACTORY=:b4 and RES_ID=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1978;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[5] = (unsigned int  )21;
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

    DB_stop_query_timer("DBU_update_mrasresdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_mrasresdef(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MRASRESDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    RES_ID,
                    RES_DESC,
                    RES_TYPE,
                    RES_GRP_1,
                    RES_GRP_2,
                    RES_GRP_3,
                    RES_GRP_4,
                    RES_GRP_5,
                    RES_GRP_6,
                    RES_GRP_7,
                    RES_GRP_8,
                    RES_GRP_9,
                    RES_GRP_10,
                    USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1,
                    RES_STS_PRT_2,
                    RES_STS_PRT_3,
                    RES_STS_PRT_4,
                    RES_STS_PRT_5,
                    RES_STS_PRT_6,
                    RES_STS_PRT_7,
                    RES_STS_PRT_8,
                    RES_STS_PRT_9,
                    RES_STS_PRT_10,
                    RES_CMF_1,
                    RES_CMF_2,
                    RES_CMF_3,
                    RES_CMF_4,
                    RES_CMF_5,
                    RES_CMF_6,
                    RES_CMF_7,
                    RES_CMF_8,
                    RES_CMF_9,
                    RES_CMF_10,
                    RES_CMF_11,
                    RES_CMF_12,
                    RES_CMF_13,
                    RES_CMF_14,
                    RES_CMF_15,
                    RES_CMF_16,
                    RES_CMF_17,
                    RES_CMF_18,
                    RES_CMF_19,
                    RES_CMF_20,
                    AREA_ID,
                    SUB_AREA_ID,
                    RES_LOCATION,
                    PROC_RULE,
                    MAX_PROC_COUNT,
                    BATCH_COND_1,
                    BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    RES_UP_DOWN_FLAG,
                    RES_PRI_STS,
                    RES_STS_1,
                    RES_STS_2,
                    RES_STS_3,
                    RES_STS_4,
                    RES_STS_5,
                    RES_STS_6,
                    RES_STS_7,
                    RES_STS_8,
                    RES_STS_9,
                    RES_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LAST_RECIPE_ID,
                    PROC_COUNT,
                    LAST_START_TIME,
                    LAST_END_TIME,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID,
                    LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ,
                    RES_SHORT_DESC
                FROM MRASRESDEF
                ORDER BY FACTORY ASC,
                    RES_ID ASC; */ 

            /* EXEC SQL OPEN DBU_MRASRESDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,RES_DESC ,RES_TYPE ,RES_GRP_1 ,RES_GR\
P_2 ,RES_GRP_3 ,RES_GRP_4 ,RES_GRP_5 ,RES_GRP_6 ,RES_GRP_7 ,RES_GRP_8 ,RES_G\
RP_9 ,RES_GRP_10 ,USE_FAC_PRT_FLAG ,RES_STS_PRT_1 ,RES_STS_PRT_2 ,RES_STS_PR\
T_3 ,RES_STS_PRT_4 ,RES_STS_PRT_5 ,RES_STS_PRT_6 ,RES_STS_PRT_7 ,RES_STS_PRT\
_8 ,RES_STS_PRT_9 ,RES_STS_PRT_10 ,RES_CMF_1 ,RES_CMF_2 ,RES_CMF_3 ,RES_CMF_\
4 ,RES_CMF_5 ,RES_CMF_6 ,RES_CMF_7 ,RES_CMF_8 ,RES_CMF_9 ,RES_CMF_10 ,RES_CM\
F_11 ,RES_CMF_12 ,RES_CMF_13 ,RES_CMF_14 ,RES_CMF_15 ,RES_CMF_16 ,RES_CMF_17\
 ,RES_CMF_18 ,RES_CMF_19 ,RES_CMF_20 ,AREA_ID ,SUB_AREA_ID ,RES_LOCATION ,PR\
OC_RULE ,MAX_PROC_COUNT ,BATCH_COND_1 ,BATCH_COND_2 ,PM_SCH_ENABLE_FLAG ,UNI\
T_BASE_ST_FLAG ,SEC_CHK_FLAG ,GATHER_ALARM_FLAG ,DELETE_FLAG ,DELETE_USER_ID\
 ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,RES\
_UP_DOWN_FLAG ,RES_PRI_STS ,RES_STS_1 ,RES_STS_2 ,RES_STS_3 ,RES_STS_4 ,RES_\
STS_5 ,RES_STS_6 ,RES_STS_7 ,RES_STS_8 ,RES_STS_9 ,RES_STS_10 ,LOT_ID ,SUBLO\
T_ID ,CRR_ID ,RES_CTRL_MODE ,RES_PROC_MODE ,LAST_RE");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2017;
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
            /* EXEC SQL DECLARE DBU_MRASRESDEF_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    RES_ID,
                    RES_DESC,
                    RES_TYPE,
                    RES_GRP_1,
                    RES_GRP_2,
                    RES_GRP_3,
                    RES_GRP_4,
                    RES_GRP_5,
                    RES_GRP_6,
                    RES_GRP_7,
                    RES_GRP_8,
                    RES_GRP_9,
                    RES_GRP_10,
                    USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1,
                    RES_STS_PRT_2,
                    RES_STS_PRT_3,
                    RES_STS_PRT_4,
                    RES_STS_PRT_5,
                    RES_STS_PRT_6,
                    RES_STS_PRT_7,
                    RES_STS_PRT_8,
                    RES_STS_PRT_9,
                    RES_STS_PRT_10,
                    RES_CMF_1,
                    RES_CMF_2,
                    RES_CMF_3,
                    RES_CMF_4,
                    RES_CMF_5,
                    RES_CMF_6,
                    RES_CMF_7,
                    RES_CMF_8,
                    RES_CMF_9,
                    RES_CMF_10,
                    RES_CMF_11,
                    RES_CMF_12,
                    RES_CMF_13,
                    RES_CMF_14,
                    RES_CMF_15,
                    RES_CMF_16,
                    RES_CMF_17,
                    RES_CMF_18,
                    RES_CMF_19,
                    RES_CMF_20,
                    AREA_ID,
                    SUB_AREA_ID,
                    RES_LOCATION,
                    PROC_RULE,
                    MAX_PROC_COUNT,
                    BATCH_COND_1,
                    BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    RES_UP_DOWN_FLAG,
                    RES_PRI_STS,
                    RES_STS_1,
                    RES_STS_2,
                    RES_STS_3,
                    RES_STS_4,
                    RES_STS_5,
                    RES_STS_6,
                    RES_STS_7,
                    RES_STS_8,
                    RES_STS_9,
                    RES_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LAST_RECIPE_ID,
                    PROC_COUNT,
                    LAST_START_TIME,
                    LAST_END_TIME,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID,
                    LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ,
                    RES_SHORT_DESC
                FROM MRASRESDEF
               WHERE FACTORY = :MRASRESDEF_N.FACTORY
                 AND AREA_ID = :MRASRESDEF_N.AREA_ID                
                 AND RES_GRP_1 = :MRASRESDEF_N.RES_GRP_1
                 AND RES_ID >= :MRASRESDEF_N.RES_ID
                ORDER BY RES_ID ASC; */ 

            /* EXEC SQL OPEN DBU_MRASRESDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,RES_DESC ,RES_TYPE ,RES_GRP_1 ,RES_GR\
P_2 ,RES_GRP_3 ,RES_GRP_4 ,RES_GRP_5 ,RES_GRP_6 ,RES_GRP_7 ,RES_GRP_8 ,RES_G\
RP_9 ,RES_GRP_10 ,USE_FAC_PRT_FLAG ,RES_STS_PRT_1 ,RES_STS_PRT_2 ,RES_STS_PR\
T_3 ,RES_STS_PRT_4 ,RES_STS_PRT_5 ,RES_STS_PRT_6 ,RES_STS_PRT_7 ,RES_STS_PRT\
_8 ,RES_STS_PRT_9 ,RES_STS_PRT_10 ,RES_CMF_1 ,RES_CMF_2 ,RES_CMF_3 ,RES_CMF_\
4 ,RES_CMF_5 ,RES_CMF_6 ,RES_CMF_7 ,RES_CMF_8 ,RES_CMF_9 ,RES_CMF_10 ,RES_CM\
F_11 ,RES_CMF_12 ,RES_CMF_13 ,RES_CMF_14 ,RES_CMF_15 ,RES_CMF_16 ,RES_CMF_17\
 ,RES_CMF_18 ,RES_CMF_19 ,RES_CMF_20 ,AREA_ID ,SUB_AREA_ID ,RES_LOCATION ,PR\
OC_RULE ,MAX_PROC_COUNT ,BATCH_COND_1 ,BATCH_COND_2 ,PM_SCH_ENABLE_FLAG ,UNI\
T_BASE_ST_FLAG ,SEC_CHK_FLAG ,GATHER_ALARM_FLAG ,DELETE_FLAG ,DELETE_USER_ID\
 ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,RES\
_UP_DOWN_FLAG ,RES_PRI_STS ,RES_STS_1 ,RES_STS_2 ,RES_STS_3 ,RES_STS_4 ,RES_\
STS_5 ,RES_STS_6 ,RES_STS_7 ,RES_STS_8 ,RES_STS_9 ,RES_STS_10 ,LOT_ID ,SUBLO\
T_ID ,CRR_ID ,RES_CTRL_MODE ,RES_PROC_MODE ,LAST_RE");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2032;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
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

        case 3:
            /* EXEC SQL DECLARE DBU_MRASRESDEF_CUR_3 CURSOR FOR
                SELECT 
                    FACTORY,
                    RES_ID,
                    RES_DESC,
                    RES_TYPE,
                    RES_GRP_1,
                    RES_GRP_2,
                    RES_GRP_3,
                    RES_GRP_4,
                    RES_GRP_5,
                    RES_GRP_6,
                    RES_GRP_7,
                    RES_GRP_8,
                    RES_GRP_9,
                    RES_GRP_10,
                    USE_FAC_PRT_FLAG,
                    RES_STS_PRT_1,
                    RES_STS_PRT_2,
                    RES_STS_PRT_3,
                    RES_STS_PRT_4,
                    RES_STS_PRT_5,
                    RES_STS_PRT_6,
                    RES_STS_PRT_7,
                    RES_STS_PRT_8,
                    RES_STS_PRT_9,
                    RES_STS_PRT_10,
                    RES_CMF_1,
                    RES_CMF_2,
                    RES_CMF_3,
                    RES_CMF_4,
                    RES_CMF_5,
                    RES_CMF_6,
                    RES_CMF_7,
                    RES_CMF_8,
                    RES_CMF_9,
                    RES_CMF_10,
                    RES_CMF_11,
                    RES_CMF_12,
                    RES_CMF_13,
                    RES_CMF_14,
                    RES_CMF_15,
                    RES_CMF_16,
                    RES_CMF_17,
                    RES_CMF_18,
                    RES_CMF_19,
                    RES_CMF_20,
                    AREA_ID,
                    SUB_AREA_ID,
                    RES_LOCATION,
                    PROC_RULE,
                    MAX_PROC_COUNT,
                    BATCH_COND_1,
                    BATCH_COND_2,
                    PM_SCH_ENABLE_FLAG,
                    UNIT_BASE_ST_FLAG,
                    SEC_CHK_FLAG,
                    GATHER_ALARM_FLAG,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    RES_UP_DOWN_FLAG,
                    RES_PRI_STS,
                    RES_STS_1,
                    RES_STS_2,
                    RES_STS_3,
                    RES_STS_4,
                    RES_STS_5,
                    RES_STS_6,
                    RES_STS_7,
                    RES_STS_8,
                    RES_STS_9,
                    RES_STS_10,
                    LOT_ID,
                    SUBLOT_ID,
                    CRR_ID,
                    RES_CTRL_MODE,
                    RES_PROC_MODE,
                    LAST_RECIPE_ID,
                    PROC_COUNT,
                    LAST_START_TIME,
                    LAST_END_TIME,
                    LAST_DOWN_TIME,
                    LAST_DOWN_HIST_SEQ,
                    LAST_EVENT_ID,
                    LAST_EVENT_TIME,
                    LAST_ACTIVE_HIST_SEQ,
                    LAST_HIST_SEQ,
                    RES_SHORT_DESC
                FROM MRASRESDEF
               WHERE FACTORY = :MRASRESDEF_N.FACTORY
                 AND RES_ID IN
                 (
                    SELECT M.RES_ID
                    FROM MRASRESMFO M, MWIPOPRDEF O
                    WHERE M.FACTORY = O.FACTORY
                        AND M.OPER = O.OPER                      
                        AND M.FACTORY = :MRASRESDEF_N.FACTORY
                        AND O.SUB_AREA_ID = :MRASRESDEF_N.SUB_AREA_ID
                 )
                ORDER BY RES_ID ASC; */ 

            /* EXEC SQL OPEN DBU_MRASRESDEF_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,RES_ID ,RES_DESC ,RES_TYPE ,RES_GRP_1 ,RES_GR\
P_2 ,RES_GRP_3 ,RES_GRP_4 ,RES_GRP_5 ,RES_GRP_6 ,RES_GRP_7 ,RES_GRP_8 ,RES_G\
RP_9 ,RES_GRP_10 ,USE_FAC_PRT_FLAG ,RES_STS_PRT_1 ,RES_STS_PRT_2 ,RES_STS_PR\
T_3 ,RES_STS_PRT_4 ,RES_STS_PRT_5 ,RES_STS_PRT_6 ,RES_STS_PRT_7 ,RES_STS_PRT\
_8 ,RES_STS_PRT_9 ,RES_STS_PRT_10 ,RES_CMF_1 ,RES_CMF_2 ,RES_CMF_3 ,RES_CMF_\
4 ,RES_CMF_5 ,RES_CMF_6 ,RES_CMF_7 ,RES_CMF_8 ,RES_CMF_9 ,RES_CMF_10 ,RES_CM\
F_11 ,RES_CMF_12 ,RES_CMF_13 ,RES_CMF_14 ,RES_CMF_15 ,RES_CMF_16 ,RES_CMF_17\
 ,RES_CMF_18 ,RES_CMF_19 ,RES_CMF_20 ,AREA_ID ,SUB_AREA_ID ,RES_LOCATION ,PR\
OC_RULE ,MAX_PROC_COUNT ,BATCH_COND_1 ,BATCH_COND_2 ,PM_SCH_ENABLE_FLAG ,UNI\
T_BASE_ST_FLAG ,SEC_CHK_FLAG ,GATHER_ALARM_FLAG ,DELETE_FLAG ,DELETE_USER_ID\
 ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,RES\
_UP_DOWN_FLAG ,RES_PRI_STS ,RES_STS_1 ,RES_STS_2 ,RES_STS_3 ,RES_STS_4 ,RES_\
STS_5 ,RES_STS_6 ,RES_STS_7 ,RES_STS_8 ,RES_STS_9 ,RES_STS_10 ,LOT_ID ,SUBLO\
T_ID ,CRR_ID ,RES_CTRL_MODE ,RES_PROC_MODE ,LAST_RE");
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2063;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_mrasresdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_mrasresdef(int sel_type, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASRESDEF_N_TAG MRASRESDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MRASRESDEF_CUR_1 INTO
                :MRASRESDEF_N.FACTORY,
                :MRASRESDEF_N.RES_ID,
                :MRASRESDEF_N.RES_DESC,
                :MRASRESDEF_N.RES_TYPE,
                :MRASRESDEF_N.RES_GRP_1,
                :MRASRESDEF_N.RES_GRP_2,
                :MRASRESDEF_N.RES_GRP_3,
                :MRASRESDEF_N.RES_GRP_4,
                :MRASRESDEF_N.RES_GRP_5,
                :MRASRESDEF_N.RES_GRP_6,
                :MRASRESDEF_N.RES_GRP_7,
                :MRASRESDEF_N.RES_GRP_8,
                :MRASRESDEF_N.RES_GRP_9,
                :MRASRESDEF_N.RES_GRP_10,
                :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                :MRASRESDEF_N.RES_STS_PRT_1,
                :MRASRESDEF_N.RES_STS_PRT_2,
                :MRASRESDEF_N.RES_STS_PRT_3,
                :MRASRESDEF_N.RES_STS_PRT_4,
                :MRASRESDEF_N.RES_STS_PRT_5,
                :MRASRESDEF_N.RES_STS_PRT_6,
                :MRASRESDEF_N.RES_STS_PRT_7,
                :MRASRESDEF_N.RES_STS_PRT_8,
                :MRASRESDEF_N.RES_STS_PRT_9,
                :MRASRESDEF_N.RES_STS_PRT_10,
                :MRASRESDEF_N.RES_CMF_1,
                :MRASRESDEF_N.RES_CMF_2,
                :MRASRESDEF_N.RES_CMF_3,
                :MRASRESDEF_N.RES_CMF_4,
                :MRASRESDEF_N.RES_CMF_5,
                :MRASRESDEF_N.RES_CMF_6,
                :MRASRESDEF_N.RES_CMF_7,
                :MRASRESDEF_N.RES_CMF_8,
                :MRASRESDEF_N.RES_CMF_9,
                :MRASRESDEF_N.RES_CMF_10,
                :MRASRESDEF_N.RES_CMF_11,
                :MRASRESDEF_N.RES_CMF_12,
                :MRASRESDEF_N.RES_CMF_13,
                :MRASRESDEF_N.RES_CMF_14,
                :MRASRESDEF_N.RES_CMF_15,
                :MRASRESDEF_N.RES_CMF_16,
                :MRASRESDEF_N.RES_CMF_17,
                :MRASRESDEF_N.RES_CMF_18,
                :MRASRESDEF_N.RES_CMF_19,
                :MRASRESDEF_N.RES_CMF_20,
                :MRASRESDEF_N.AREA_ID,
                :MRASRESDEF_N.SUB_AREA_ID,
                :MRASRESDEF_N.RES_LOCATION,
                :MRASRESDEF_N.PROC_RULE,
                :MRASRESDEF_N.MAX_PROC_COUNT,
                :MRASRESDEF_N.BATCH_COND_1,
                :MRASRESDEF_N.BATCH_COND_2,
                :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                :MRASRESDEF_N.SEC_CHK_FLAG,
                :MRASRESDEF_N.GATHER_ALARM_FLAG,
                :MRASRESDEF_N.DELETE_FLAG,
                :MRASRESDEF_N.DELETE_USER_ID,
                :MRASRESDEF_N.DELETE_TIME,
                :MRASRESDEF_N.CREATE_USER_ID,
                :MRASRESDEF_N.CREATE_TIME,
                :MRASRESDEF_N.UPDATE_USER_ID,
                :MRASRESDEF_N.UPDATE_TIME,
                :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                :MRASRESDEF_N.RES_PRI_STS,
                :MRASRESDEF_N.RES_STS_1,
                :MRASRESDEF_N.RES_STS_2,
                :MRASRESDEF_N.RES_STS_3,
                :MRASRESDEF_N.RES_STS_4,
                :MRASRESDEF_N.RES_STS_5,
                :MRASRESDEF_N.RES_STS_6,
                :MRASRESDEF_N.RES_STS_7,
                :MRASRESDEF_N.RES_STS_8,
                :MRASRESDEF_N.RES_STS_9,
                :MRASRESDEF_N.RES_STS_10,
                :MRASRESDEF_N.LOT_ID,
                :MRASRESDEF_N.SUBLOT_ID,
                :MRASRESDEF_N.CRR_ID,
                :MRASRESDEF_N.RES_CTRL_MODE,
                :MRASRESDEF_N.RES_PROC_MODE,
                :MRASRESDEF_N.LAST_RECIPE_ID,
                :MRASRESDEF_N.PROC_COUNT,
                :MRASRESDEF_N.LAST_START_TIME,
                :MRASRESDEF_N.LAST_END_TIME,
                :MRASRESDEF_N.LAST_DOWN_TIME,
                :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                :MRASRESDEF_N.LAST_EVENT_ID,
                :MRASRESDEF_N.LAST_EVENT_TIME,
                :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                :MRASRESDEF_N.LAST_HIST_SEQ,
                :MRASRESDEF_N.RES_SHORT_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2090;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[51] = (unsigned int  )13;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )26;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[78] = (unsigned int  )3;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )13;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[90] = (unsigned int  )51;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_MRASRESDEF_CUR_2 INTO
                :MRASRESDEF_N.FACTORY,
                :MRASRESDEF_N.RES_ID,
                :MRASRESDEF_N.RES_DESC,
                :MRASRESDEF_N.RES_TYPE,
                :MRASRESDEF_N.RES_GRP_1,
                :MRASRESDEF_N.RES_GRP_2,
                :MRASRESDEF_N.RES_GRP_3,
                :MRASRESDEF_N.RES_GRP_4,
                :MRASRESDEF_N.RES_GRP_5,
                :MRASRESDEF_N.RES_GRP_6,
                :MRASRESDEF_N.RES_GRP_7,
                :MRASRESDEF_N.RES_GRP_8,
                :MRASRESDEF_N.RES_GRP_9,
                :MRASRESDEF_N.RES_GRP_10,
                :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                :MRASRESDEF_N.RES_STS_PRT_1,
                :MRASRESDEF_N.RES_STS_PRT_2,
                :MRASRESDEF_N.RES_STS_PRT_3,
                :MRASRESDEF_N.RES_STS_PRT_4,
                :MRASRESDEF_N.RES_STS_PRT_5,
                :MRASRESDEF_N.RES_STS_PRT_6,
                :MRASRESDEF_N.RES_STS_PRT_7,
                :MRASRESDEF_N.RES_STS_PRT_8,
                :MRASRESDEF_N.RES_STS_PRT_9,
                :MRASRESDEF_N.RES_STS_PRT_10,
                :MRASRESDEF_N.RES_CMF_1,
                :MRASRESDEF_N.RES_CMF_2,
                :MRASRESDEF_N.RES_CMF_3,
                :MRASRESDEF_N.RES_CMF_4,
                :MRASRESDEF_N.RES_CMF_5,
                :MRASRESDEF_N.RES_CMF_6,
                :MRASRESDEF_N.RES_CMF_7,
                :MRASRESDEF_N.RES_CMF_8,
                :MRASRESDEF_N.RES_CMF_9,
                :MRASRESDEF_N.RES_CMF_10,
                :MRASRESDEF_N.RES_CMF_11,
                :MRASRESDEF_N.RES_CMF_12,
                :MRASRESDEF_N.RES_CMF_13,
                :MRASRESDEF_N.RES_CMF_14,
                :MRASRESDEF_N.RES_CMF_15,
                :MRASRESDEF_N.RES_CMF_16,
                :MRASRESDEF_N.RES_CMF_17,
                :MRASRESDEF_N.RES_CMF_18,
                :MRASRESDEF_N.RES_CMF_19,
                :MRASRESDEF_N.RES_CMF_20,
                :MRASRESDEF_N.AREA_ID,
                :MRASRESDEF_N.SUB_AREA_ID,
                :MRASRESDEF_N.RES_LOCATION,
                :MRASRESDEF_N.PROC_RULE,
                :MRASRESDEF_N.MAX_PROC_COUNT,
                :MRASRESDEF_N.BATCH_COND_1,
                :MRASRESDEF_N.BATCH_COND_2,
                :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                :MRASRESDEF_N.SEC_CHK_FLAG,
                :MRASRESDEF_N.GATHER_ALARM_FLAG,
                :MRASRESDEF_N.DELETE_FLAG,
                :MRASRESDEF_N.DELETE_USER_ID,
                :MRASRESDEF_N.DELETE_TIME,
                :MRASRESDEF_N.CREATE_USER_ID,
                :MRASRESDEF_N.CREATE_TIME,
                :MRASRESDEF_N.UPDATE_USER_ID,
                :MRASRESDEF_N.UPDATE_TIME,
                :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                :MRASRESDEF_N.RES_PRI_STS,
                :MRASRESDEF_N.RES_STS_1,
                :MRASRESDEF_N.RES_STS_2,
                :MRASRESDEF_N.RES_STS_3,
                :MRASRESDEF_N.RES_STS_4,
                :MRASRESDEF_N.RES_STS_5,
                :MRASRESDEF_N.RES_STS_6,
                :MRASRESDEF_N.RES_STS_7,
                :MRASRESDEF_N.RES_STS_8,
                :MRASRESDEF_N.RES_STS_9,
                :MRASRESDEF_N.RES_STS_10,
                :MRASRESDEF_N.LOT_ID,
                :MRASRESDEF_N.SUBLOT_ID,
                :MRASRESDEF_N.CRR_ID,
                :MRASRESDEF_N.RES_CTRL_MODE,
                :MRASRESDEF_N.RES_PROC_MODE,
                :MRASRESDEF_N.LAST_RECIPE_ID,
                :MRASRESDEF_N.PROC_COUNT,
                :MRASRESDEF_N.LAST_START_TIME,
                :MRASRESDEF_N.LAST_END_TIME,
                :MRASRESDEF_N.LAST_DOWN_TIME,
                :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                :MRASRESDEF_N.LAST_EVENT_ID,
                :MRASRESDEF_N.LAST_EVENT_TIME,
                :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                :MRASRESDEF_N.LAST_HIST_SEQ,
                :MRASRESDEF_N.RES_SHORT_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2469;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[51] = (unsigned int  )13;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )26;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[78] = (unsigned int  )3;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )13;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[90] = (unsigned int  )51;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_MRASRESDEF_CUR_3 INTO
                :MRASRESDEF_N.FACTORY,
                :MRASRESDEF_N.RES_ID,
                :MRASRESDEF_N.RES_DESC,
                :MRASRESDEF_N.RES_TYPE,
                :MRASRESDEF_N.RES_GRP_1,
                :MRASRESDEF_N.RES_GRP_2,
                :MRASRESDEF_N.RES_GRP_3,
                :MRASRESDEF_N.RES_GRP_4,
                :MRASRESDEF_N.RES_GRP_5,
                :MRASRESDEF_N.RES_GRP_6,
                :MRASRESDEF_N.RES_GRP_7,
                :MRASRESDEF_N.RES_GRP_8,
                :MRASRESDEF_N.RES_GRP_9,
                :MRASRESDEF_N.RES_GRP_10,
                :MRASRESDEF_N.USE_FAC_PRT_FLAG,
                :MRASRESDEF_N.RES_STS_PRT_1,
                :MRASRESDEF_N.RES_STS_PRT_2,
                :MRASRESDEF_N.RES_STS_PRT_3,
                :MRASRESDEF_N.RES_STS_PRT_4,
                :MRASRESDEF_N.RES_STS_PRT_5,
                :MRASRESDEF_N.RES_STS_PRT_6,
                :MRASRESDEF_N.RES_STS_PRT_7,
                :MRASRESDEF_N.RES_STS_PRT_8,
                :MRASRESDEF_N.RES_STS_PRT_9,
                :MRASRESDEF_N.RES_STS_PRT_10,
                :MRASRESDEF_N.RES_CMF_1,
                :MRASRESDEF_N.RES_CMF_2,
                :MRASRESDEF_N.RES_CMF_3,
                :MRASRESDEF_N.RES_CMF_4,
                :MRASRESDEF_N.RES_CMF_5,
                :MRASRESDEF_N.RES_CMF_6,
                :MRASRESDEF_N.RES_CMF_7,
                :MRASRESDEF_N.RES_CMF_8,
                :MRASRESDEF_N.RES_CMF_9,
                :MRASRESDEF_N.RES_CMF_10,
                :MRASRESDEF_N.RES_CMF_11,
                :MRASRESDEF_N.RES_CMF_12,
                :MRASRESDEF_N.RES_CMF_13,
                :MRASRESDEF_N.RES_CMF_14,
                :MRASRESDEF_N.RES_CMF_15,
                :MRASRESDEF_N.RES_CMF_16,
                :MRASRESDEF_N.RES_CMF_17,
                :MRASRESDEF_N.RES_CMF_18,
                :MRASRESDEF_N.RES_CMF_19,
                :MRASRESDEF_N.RES_CMF_20,
                :MRASRESDEF_N.AREA_ID,
                :MRASRESDEF_N.SUB_AREA_ID,
                :MRASRESDEF_N.RES_LOCATION,
                :MRASRESDEF_N.PROC_RULE,
                :MRASRESDEF_N.MAX_PROC_COUNT,
                :MRASRESDEF_N.BATCH_COND_1,
                :MRASRESDEF_N.BATCH_COND_2,
                :MRASRESDEF_N.PM_SCH_ENABLE_FLAG,
                :MRASRESDEF_N.UNIT_BASE_ST_FLAG,
                :MRASRESDEF_N.SEC_CHK_FLAG,
                :MRASRESDEF_N.GATHER_ALARM_FLAG,
                :MRASRESDEF_N.DELETE_FLAG,
                :MRASRESDEF_N.DELETE_USER_ID,
                :MRASRESDEF_N.DELETE_TIME,
                :MRASRESDEF_N.CREATE_USER_ID,
                :MRASRESDEF_N.CREATE_TIME,
                :MRASRESDEF_N.UPDATE_USER_ID,
                :MRASRESDEF_N.UPDATE_TIME,
                :MRASRESDEF_N.RES_UP_DOWN_FLAG,
                :MRASRESDEF_N.RES_PRI_STS,
                :MRASRESDEF_N.RES_STS_1,
                :MRASRESDEF_N.RES_STS_2,
                :MRASRESDEF_N.RES_STS_3,
                :MRASRESDEF_N.RES_STS_4,
                :MRASRESDEF_N.RES_STS_5,
                :MRASRESDEF_N.RES_STS_6,
                :MRASRESDEF_N.RES_STS_7,
                :MRASRESDEF_N.RES_STS_8,
                :MRASRESDEF_N.RES_STS_9,
                :MRASRESDEF_N.RES_STS_10,
                :MRASRESDEF_N.LOT_ID,
                :MRASRESDEF_N.SUBLOT_ID,
                :MRASRESDEF_N.CRR_ID,
                :MRASRESDEF_N.RES_CTRL_MODE,
                :MRASRESDEF_N.RES_PROC_MODE,
                :MRASRESDEF_N.LAST_RECIPE_ID,
                :MRASRESDEF_N.PROC_COUNT,
                :MRASRESDEF_N.LAST_START_TIME,
                :MRASRESDEF_N.LAST_END_TIME,
                :MRASRESDEF_N.LAST_DOWN_TIME,
                :MRASRESDEF_N.LAST_DOWN_HIST_SEQ,
                :MRASRESDEF_N.LAST_EVENT_ID,
                :MRASRESDEF_N.LAST_EVENT_TIME,
                :MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ,
                :MRASRESDEF_N.LAST_HIST_SEQ,
                :MRASRESDEF_N.RES_SHORT_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2848;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASRESDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASRESDEF_N.RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASRESDEF_N.RES_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASRESDEF_N.RES_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASRESDEF_N.RES_GRP_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASRESDEF_N.RES_GRP_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASRESDEF_N.RES_GRP_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASRESDEF_N.RES_GRP_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASRESDEF_N.RES_GRP_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASRESDEF_N.RES_GRP_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASRESDEF_N.RES_GRP_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASRESDEF_N.RES_GRP_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASRESDEF_N.RES_GRP_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASRESDEF_N.RES_GRP_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASRESDEF_N.USE_FAC_PRT_FLAG);
            sqlstm.sqhstl[14] = (unsigned int  )2;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASRESDEF_N.RES_STS_PRT_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASRESDEF_N.RES_CMF_1);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASRESDEF_N.RES_CMF_2);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASRESDEF_N.RES_CMF_3);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASRESDEF_N.RES_CMF_4);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASRESDEF_N.RES_CMF_5);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASRESDEF_N.RES_CMF_6);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASRESDEF_N.RES_CMF_7);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASRESDEF_N.RES_CMF_8);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASRESDEF_N.RES_CMF_9);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASRESDEF_N.RES_CMF_10);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASRESDEF_N.RES_CMF_11);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASRESDEF_N.RES_CMF_12);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASRESDEF_N.RES_CMF_13);
            sqlstm.sqhstl[37] = (unsigned int  )31;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASRESDEF_N.RES_CMF_14);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASRESDEF_N.RES_CMF_15);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASRESDEF_N.RES_CMF_16);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASRESDEF_N.RES_CMF_17);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASRESDEF_N.RES_CMF_18);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASRESDEF_N.RES_CMF_19);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASRESDEF_N.RES_CMF_20);
            sqlstm.sqhstl[44] = (unsigned int  )31;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASRESDEF_N.AREA_ID);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASRESDEF_N.SUB_AREA_ID);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASRESDEF_N.RES_LOCATION);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASRESDEF_N.PROC_RULE);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MRASRESDEF_N.MAX_PROC_COUNT);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASRESDEF_N.BATCH_COND_1);
            sqlstm.sqhstl[50] = (unsigned int  )13;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASRESDEF_N.BATCH_COND_2);
            sqlstm.sqhstl[51] = (unsigned int  )13;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASRESDEF_N.PM_SCH_ENABLE_FLAG);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASRESDEF_N.UNIT_BASE_ST_FLAG);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASRESDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASRESDEF_N.GATHER_ALARM_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASRESDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASRESDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASRESDEF_N.DELETE_TIME);
            sqlstm.sqhstl[58] = (unsigned int  )15;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASRESDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASRESDEF_N.CREATE_TIME);
            sqlstm.sqhstl[60] = (unsigned int  )15;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASRESDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[61] = (unsigned int  )21;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASRESDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[62] = (unsigned int  )15;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASRESDEF_N.RES_UP_DOWN_FLAG);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASRESDEF_N.RES_PRI_STS);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASRESDEF_N.RES_STS_1);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASRESDEF_N.RES_STS_2);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASRESDEF_N.RES_STS_3);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASRESDEF_N.RES_STS_4);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASRESDEF_N.RES_STS_5);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASRESDEF_N.RES_STS_6);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASRESDEF_N.RES_STS_7);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASRESDEF_N.RES_STS_8);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASRESDEF_N.RES_STS_9);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASRESDEF_N.RES_STS_10);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASRESDEF_N.LOT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )26;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASRESDEF_N.SUBLOT_ID);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASRESDEF_N.CRR_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASRESDEF_N.RES_CTRL_MODE);
            sqlstm.sqhstl[78] = (unsigned int  )3;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASRESDEF_N.RES_PROC_MODE);
            sqlstm.sqhstl[79] = (unsigned int  )11;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASRESDEF_N.LAST_RECIPE_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MRASRESDEF_N.PROC_COUNT);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASRESDEF_N.LAST_START_TIME);
            sqlstm.sqhstl[82] = (unsigned int  )15;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASRESDEF_N.LAST_END_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASRESDEF_N.LAST_DOWN_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)&(MRASRESDEF_N.LAST_DOWN_HIST_SEQ);
            sqlstm.sqhstl[85] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASRESDEF_N.LAST_EVENT_ID);
            sqlstm.sqhstl[86] = (unsigned int  )13;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASRESDEF_N.LAST_EVENT_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)&(MRASRESDEF_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[88] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)&(MRASRESDEF_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[89] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASRESDEF_N.RES_SHORT_DESC);
            sqlstm.sqhstl[90] = (unsigned int  )51;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
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
        DBU_del_null_mrasresdef(&MRASRESDEF_N, MRASRESDEF);
    }

    DB_stop_query_timer("DBU_fetch_mrasresdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_mrasresdef(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MRASRESDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3227;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBU_MRASRESDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3242;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

       case 3:
            /* EXEC SQL CLOSE DBU_MRASRESDEF_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 94;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3257;
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

    DB_stop_query_timer("DBU_close_mrasresdef", sel_type);
}


/* Initialize Function */
void DBU_init_mrasresdef(struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* memset by Space */
    memset(MRASRESDEF, ' ', sizeof(struct MRASRESDEF_TAG));
    
    MRASRESDEF->MAX_PROC_COUNT = 0;
    MRASRESDEF->PROC_COUNT = 0;
    MRASRESDEF->LAST_DOWN_HIST_SEQ = 0;
    MRASRESDEF->LAST_ACTIVE_HIST_SEQ = 0;
    MRASRESDEF->LAST_HIST_SEQ = 0;
}


/* Add Null Function */
void DBU_add_null_mrasresdef(struct MRASRESDEF_N_TAG *MRASRESDEF_N, struct MRASRESDEF_TAG *MRASRESDEF)
{
    /* memset by NULL */
    memset(MRASRESDEF_N, '\0', sizeof(struct MRASRESDEF_N_TAG));
    
    MEMCPY_AN(MRASRESDEF_N->FACTORY, MRASRESDEF->FACTORY, sizeof(MRASRESDEF->FACTORY));
    MEMCPY_AN(MRASRESDEF_N->RES_ID, MRASRESDEF->RES_ID, sizeof(MRASRESDEF->RES_ID));
    MEMCPY_AN(MRASRESDEF_N->RES_DESC, MRASRESDEF->RES_DESC, sizeof(MRASRESDEF->RES_DESC));
    MEMCPY_AN(MRASRESDEF_N->RES_TYPE, MRASRESDEF->RES_TYPE, sizeof(MRASRESDEF->RES_TYPE));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_1, MRASRESDEF->RES_GRP_1, sizeof(MRASRESDEF->RES_GRP_1));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_2, MRASRESDEF->RES_GRP_2, sizeof(MRASRESDEF->RES_GRP_2));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_3, MRASRESDEF->RES_GRP_3, sizeof(MRASRESDEF->RES_GRP_3));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_4, MRASRESDEF->RES_GRP_4, sizeof(MRASRESDEF->RES_GRP_4));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_5, MRASRESDEF->RES_GRP_5, sizeof(MRASRESDEF->RES_GRP_5));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_6, MRASRESDEF->RES_GRP_6, sizeof(MRASRESDEF->RES_GRP_6));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_7, MRASRESDEF->RES_GRP_7, sizeof(MRASRESDEF->RES_GRP_7));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_8, MRASRESDEF->RES_GRP_8, sizeof(MRASRESDEF->RES_GRP_8));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_9, MRASRESDEF->RES_GRP_9, sizeof(MRASRESDEF->RES_GRP_9));
    MEMCPY_AN(MRASRESDEF_N->RES_GRP_10, MRASRESDEF->RES_GRP_10, sizeof(MRASRESDEF->RES_GRP_10));
    MRASRESDEF_N->USE_FAC_PRT_FLAG[0] = MRASRESDEF->USE_FAC_PRT_FLAG;
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_1, MRASRESDEF->RES_STS_PRT_1, sizeof(MRASRESDEF->RES_STS_PRT_1));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_2, MRASRESDEF->RES_STS_PRT_2, sizeof(MRASRESDEF->RES_STS_PRT_2));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_3, MRASRESDEF->RES_STS_PRT_3, sizeof(MRASRESDEF->RES_STS_PRT_3));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_4, MRASRESDEF->RES_STS_PRT_4, sizeof(MRASRESDEF->RES_STS_PRT_4));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_5, MRASRESDEF->RES_STS_PRT_5, sizeof(MRASRESDEF->RES_STS_PRT_5));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_6, MRASRESDEF->RES_STS_PRT_6, sizeof(MRASRESDEF->RES_STS_PRT_6));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_7, MRASRESDEF->RES_STS_PRT_7, sizeof(MRASRESDEF->RES_STS_PRT_7));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_8, MRASRESDEF->RES_STS_PRT_8, sizeof(MRASRESDEF->RES_STS_PRT_8));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_9, MRASRESDEF->RES_STS_PRT_9, sizeof(MRASRESDEF->RES_STS_PRT_9));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_PRT_10, MRASRESDEF->RES_STS_PRT_10, sizeof(MRASRESDEF->RES_STS_PRT_10));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_1, MRASRESDEF->RES_CMF_1, sizeof(MRASRESDEF->RES_CMF_1));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_2, MRASRESDEF->RES_CMF_2, sizeof(MRASRESDEF->RES_CMF_2));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_3, MRASRESDEF->RES_CMF_3, sizeof(MRASRESDEF->RES_CMF_3));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_4, MRASRESDEF->RES_CMF_4, sizeof(MRASRESDEF->RES_CMF_4));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_5, MRASRESDEF->RES_CMF_5, sizeof(MRASRESDEF->RES_CMF_5));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_6, MRASRESDEF->RES_CMF_6, sizeof(MRASRESDEF->RES_CMF_6));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_7, MRASRESDEF->RES_CMF_7, sizeof(MRASRESDEF->RES_CMF_7));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_8, MRASRESDEF->RES_CMF_8, sizeof(MRASRESDEF->RES_CMF_8));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_9, MRASRESDEF->RES_CMF_9, sizeof(MRASRESDEF->RES_CMF_9));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_10, MRASRESDEF->RES_CMF_10, sizeof(MRASRESDEF->RES_CMF_10));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_11, MRASRESDEF->RES_CMF_11, sizeof(MRASRESDEF->RES_CMF_11));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_12, MRASRESDEF->RES_CMF_12, sizeof(MRASRESDEF->RES_CMF_12));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_13, MRASRESDEF->RES_CMF_13, sizeof(MRASRESDEF->RES_CMF_13));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_14, MRASRESDEF->RES_CMF_14, sizeof(MRASRESDEF->RES_CMF_14));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_15, MRASRESDEF->RES_CMF_15, sizeof(MRASRESDEF->RES_CMF_15));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_16, MRASRESDEF->RES_CMF_16, sizeof(MRASRESDEF->RES_CMF_16));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_17, MRASRESDEF->RES_CMF_17, sizeof(MRASRESDEF->RES_CMF_17));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_18, MRASRESDEF->RES_CMF_18, sizeof(MRASRESDEF->RES_CMF_18));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_19, MRASRESDEF->RES_CMF_19, sizeof(MRASRESDEF->RES_CMF_19));
    MEMCPY_AN(MRASRESDEF_N->RES_CMF_20, MRASRESDEF->RES_CMF_20, sizeof(MRASRESDEF->RES_CMF_20));
    MEMCPY_AN(MRASRESDEF_N->AREA_ID, MRASRESDEF->AREA_ID, sizeof(MRASRESDEF->AREA_ID));
    MEMCPY_AN(MRASRESDEF_N->SUB_AREA_ID, MRASRESDEF->SUB_AREA_ID, sizeof(MRASRESDEF->SUB_AREA_ID));
    MEMCPY_AN(MRASRESDEF_N->RES_LOCATION, MRASRESDEF->RES_LOCATION, sizeof(MRASRESDEF->RES_LOCATION));
    MRASRESDEF_N->PROC_RULE[0] = MRASRESDEF->PROC_RULE;
    MRASRESDEF_N->MAX_PROC_COUNT = MRASRESDEF->MAX_PROC_COUNT;
    MEMCPY_AN(MRASRESDEF_N->BATCH_COND_1, MRASRESDEF->BATCH_COND_1, sizeof(MRASRESDEF->BATCH_COND_1));
    MEMCPY_AN(MRASRESDEF_N->BATCH_COND_2, MRASRESDEF->BATCH_COND_2, sizeof(MRASRESDEF->BATCH_COND_2));
    MRASRESDEF_N->PM_SCH_ENABLE_FLAG[0] = MRASRESDEF->PM_SCH_ENABLE_FLAG;
    MRASRESDEF_N->UNIT_BASE_ST_FLAG[0] = MRASRESDEF->UNIT_BASE_ST_FLAG;
    MRASRESDEF_N->SEC_CHK_FLAG[0] = MRASRESDEF->SEC_CHK_FLAG;
    MRASRESDEF_N->GATHER_ALARM_FLAG[0] = MRASRESDEF->GATHER_ALARM_FLAG;
    MRASRESDEF_N->DELETE_FLAG[0] = MRASRESDEF->DELETE_FLAG;
    MEMCPY_AN(MRASRESDEF_N->DELETE_USER_ID, MRASRESDEF->DELETE_USER_ID, sizeof(MRASRESDEF->DELETE_USER_ID));
    MEMCPY_AN(MRASRESDEF_N->DELETE_TIME, MRASRESDEF->DELETE_TIME, sizeof(MRASRESDEF->DELETE_TIME));
    MEMCPY_AN(MRASRESDEF_N->CREATE_USER_ID, MRASRESDEF->CREATE_USER_ID, sizeof(MRASRESDEF->CREATE_USER_ID));
    MEMCPY_AN(MRASRESDEF_N->CREATE_TIME, MRASRESDEF->CREATE_TIME, sizeof(MRASRESDEF->CREATE_TIME));
    MEMCPY_AN(MRASRESDEF_N->UPDATE_USER_ID, MRASRESDEF->UPDATE_USER_ID, sizeof(MRASRESDEF->UPDATE_USER_ID));
    MEMCPY_AN(MRASRESDEF_N->UPDATE_TIME, MRASRESDEF->UPDATE_TIME, sizeof(MRASRESDEF->UPDATE_TIME));
    MRASRESDEF_N->RES_UP_DOWN_FLAG[0] = MRASRESDEF->RES_UP_DOWN_FLAG;
    MEMCPY_AN(MRASRESDEF_N->RES_PRI_STS, MRASRESDEF->RES_PRI_STS, sizeof(MRASRESDEF->RES_PRI_STS));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_1, MRASRESDEF->RES_STS_1, sizeof(MRASRESDEF->RES_STS_1));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_2, MRASRESDEF->RES_STS_2, sizeof(MRASRESDEF->RES_STS_2));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_3, MRASRESDEF->RES_STS_3, sizeof(MRASRESDEF->RES_STS_3));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_4, MRASRESDEF->RES_STS_4, sizeof(MRASRESDEF->RES_STS_4));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_5, MRASRESDEF->RES_STS_5, sizeof(MRASRESDEF->RES_STS_5));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_6, MRASRESDEF->RES_STS_6, sizeof(MRASRESDEF->RES_STS_6));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_7, MRASRESDEF->RES_STS_7, sizeof(MRASRESDEF->RES_STS_7));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_8, MRASRESDEF->RES_STS_8, sizeof(MRASRESDEF->RES_STS_8));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_9, MRASRESDEF->RES_STS_9, sizeof(MRASRESDEF->RES_STS_9));
    MEMCPY_AN(MRASRESDEF_N->RES_STS_10, MRASRESDEF->RES_STS_10, sizeof(MRASRESDEF->RES_STS_10));
    MEMCPY_AN(MRASRESDEF_N->LOT_ID, MRASRESDEF->LOT_ID, sizeof(MRASRESDEF->LOT_ID));
    MEMCPY_AN(MRASRESDEF_N->SUBLOT_ID, MRASRESDEF->SUBLOT_ID, sizeof(MRASRESDEF->SUBLOT_ID));
    MEMCPY_AN(MRASRESDEF_N->CRR_ID, MRASRESDEF->CRR_ID, sizeof(MRASRESDEF->CRR_ID));
    MEMCPY_AN(MRASRESDEF_N->RES_CTRL_MODE, MRASRESDEF->RES_CTRL_MODE, sizeof(MRASRESDEF->RES_CTRL_MODE));
    MEMCPY_AN(MRASRESDEF_N->RES_PROC_MODE, MRASRESDEF->RES_PROC_MODE, sizeof(MRASRESDEF->RES_PROC_MODE));
    MEMCPY_AN(MRASRESDEF_N->LAST_RECIPE_ID, MRASRESDEF->LAST_RECIPE_ID, sizeof(MRASRESDEF->LAST_RECIPE_ID));
    MRASRESDEF_N->PROC_COUNT = MRASRESDEF->PROC_COUNT;
    MEMCPY_AN(MRASRESDEF_N->LAST_START_TIME, MRASRESDEF->LAST_START_TIME, sizeof(MRASRESDEF->LAST_START_TIME));
    MEMCPY_AN(MRASRESDEF_N->LAST_END_TIME, MRASRESDEF->LAST_END_TIME, sizeof(MRASRESDEF->LAST_END_TIME));
    MEMCPY_AN(MRASRESDEF_N->LAST_DOWN_TIME, MRASRESDEF->LAST_DOWN_TIME, sizeof(MRASRESDEF->LAST_DOWN_TIME));
    MRASRESDEF_N->LAST_DOWN_HIST_SEQ = MRASRESDEF->LAST_DOWN_HIST_SEQ;
    MEMCPY_AN(MRASRESDEF_N->LAST_EVENT_ID, MRASRESDEF->LAST_EVENT_ID, sizeof(MRASRESDEF->LAST_EVENT_ID));
    MEMCPY_AN(MRASRESDEF_N->LAST_EVENT_TIME, MRASRESDEF->LAST_EVENT_TIME, sizeof(MRASRESDEF->LAST_EVENT_TIME));
    MRASRESDEF_N->LAST_ACTIVE_HIST_SEQ = MRASRESDEF->LAST_ACTIVE_HIST_SEQ;
    MRASRESDEF_N->LAST_HIST_SEQ = MRASRESDEF->LAST_HIST_SEQ;
    MEMCPY_AN(MRASRESDEF_N->RES_SHORT_DESC, MRASRESDEF->RES_SHORT_DESC, sizeof(MRASRESDEF->RES_SHORT_DESC));
}


/* Del Null Function */
void DBU_del_null_mrasresdef(struct MRASRESDEF_N_TAG *MRASRESDEF_N, struct MRASRESDEF_TAG *MRASRESDEF)
{
    MEMCPY_DN(MRASRESDEF->FACTORY, MRASRESDEF_N->FACTORY, sizeof(MRASRESDEF->FACTORY));
    MEMCPY_DN(MRASRESDEF->RES_ID, MRASRESDEF_N->RES_ID, sizeof(MRASRESDEF->RES_ID));
    MEMCPY_DN(MRASRESDEF->RES_DESC, MRASRESDEF_N->RES_DESC, sizeof(MRASRESDEF->RES_DESC));
    MEMCPY_DN(MRASRESDEF->RES_TYPE, MRASRESDEF_N->RES_TYPE, sizeof(MRASRESDEF->RES_TYPE));
    MEMCPY_DN(MRASRESDEF->RES_GRP_1, MRASRESDEF_N->RES_GRP_1, sizeof(MRASRESDEF->RES_GRP_1));
    MEMCPY_DN(MRASRESDEF->RES_GRP_2, MRASRESDEF_N->RES_GRP_2, sizeof(MRASRESDEF->RES_GRP_2));
    MEMCPY_DN(MRASRESDEF->RES_GRP_3, MRASRESDEF_N->RES_GRP_3, sizeof(MRASRESDEF->RES_GRP_3));
    MEMCPY_DN(MRASRESDEF->RES_GRP_4, MRASRESDEF_N->RES_GRP_4, sizeof(MRASRESDEF->RES_GRP_4));
    MEMCPY_DN(MRASRESDEF->RES_GRP_5, MRASRESDEF_N->RES_GRP_5, sizeof(MRASRESDEF->RES_GRP_5));
    MEMCPY_DN(MRASRESDEF->RES_GRP_6, MRASRESDEF_N->RES_GRP_6, sizeof(MRASRESDEF->RES_GRP_6));
    MEMCPY_DN(MRASRESDEF->RES_GRP_7, MRASRESDEF_N->RES_GRP_7, sizeof(MRASRESDEF->RES_GRP_7));
    MEMCPY_DN(MRASRESDEF->RES_GRP_8, MRASRESDEF_N->RES_GRP_8, sizeof(MRASRESDEF->RES_GRP_8));
    MEMCPY_DN(MRASRESDEF->RES_GRP_9, MRASRESDEF_N->RES_GRP_9, sizeof(MRASRESDEF->RES_GRP_9));
    MEMCPY_DN(MRASRESDEF->RES_GRP_10, MRASRESDEF_N->RES_GRP_10, sizeof(MRASRESDEF->RES_GRP_10));
    MRASRESDEF->USE_FAC_PRT_FLAG = MRASRESDEF_N->USE_FAC_PRT_FLAG[0];
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_1, MRASRESDEF_N->RES_STS_PRT_1, sizeof(MRASRESDEF->RES_STS_PRT_1));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_2, MRASRESDEF_N->RES_STS_PRT_2, sizeof(MRASRESDEF->RES_STS_PRT_2));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_3, MRASRESDEF_N->RES_STS_PRT_3, sizeof(MRASRESDEF->RES_STS_PRT_3));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_4, MRASRESDEF_N->RES_STS_PRT_4, sizeof(MRASRESDEF->RES_STS_PRT_4));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_5, MRASRESDEF_N->RES_STS_PRT_5, sizeof(MRASRESDEF->RES_STS_PRT_5));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_6, MRASRESDEF_N->RES_STS_PRT_6, sizeof(MRASRESDEF->RES_STS_PRT_6));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_7, MRASRESDEF_N->RES_STS_PRT_7, sizeof(MRASRESDEF->RES_STS_PRT_7));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_8, MRASRESDEF_N->RES_STS_PRT_8, sizeof(MRASRESDEF->RES_STS_PRT_8));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_9, MRASRESDEF_N->RES_STS_PRT_9, sizeof(MRASRESDEF->RES_STS_PRT_9));
    MEMCPY_DN(MRASRESDEF->RES_STS_PRT_10, MRASRESDEF_N->RES_STS_PRT_10, sizeof(MRASRESDEF->RES_STS_PRT_10));
    MEMCPY_DN(MRASRESDEF->RES_CMF_1, MRASRESDEF_N->RES_CMF_1, sizeof(MRASRESDEF->RES_CMF_1));
    MEMCPY_DN(MRASRESDEF->RES_CMF_2, MRASRESDEF_N->RES_CMF_2, sizeof(MRASRESDEF->RES_CMF_2));
    MEMCPY_DN(MRASRESDEF->RES_CMF_3, MRASRESDEF_N->RES_CMF_3, sizeof(MRASRESDEF->RES_CMF_3));
    MEMCPY_DN(MRASRESDEF->RES_CMF_4, MRASRESDEF_N->RES_CMF_4, sizeof(MRASRESDEF->RES_CMF_4));
    MEMCPY_DN(MRASRESDEF->RES_CMF_5, MRASRESDEF_N->RES_CMF_5, sizeof(MRASRESDEF->RES_CMF_5));
    MEMCPY_DN(MRASRESDEF->RES_CMF_6, MRASRESDEF_N->RES_CMF_6, sizeof(MRASRESDEF->RES_CMF_6));
    MEMCPY_DN(MRASRESDEF->RES_CMF_7, MRASRESDEF_N->RES_CMF_7, sizeof(MRASRESDEF->RES_CMF_7));
    MEMCPY_DN(MRASRESDEF->RES_CMF_8, MRASRESDEF_N->RES_CMF_8, sizeof(MRASRESDEF->RES_CMF_8));
    MEMCPY_DN(MRASRESDEF->RES_CMF_9, MRASRESDEF_N->RES_CMF_9, sizeof(MRASRESDEF->RES_CMF_9));
    MEMCPY_DN(MRASRESDEF->RES_CMF_10, MRASRESDEF_N->RES_CMF_10, sizeof(MRASRESDEF->RES_CMF_10));
    MEMCPY_DN(MRASRESDEF->RES_CMF_11, MRASRESDEF_N->RES_CMF_11, sizeof(MRASRESDEF->RES_CMF_11));
    MEMCPY_DN(MRASRESDEF->RES_CMF_12, MRASRESDEF_N->RES_CMF_12, sizeof(MRASRESDEF->RES_CMF_12));
    MEMCPY_DN(MRASRESDEF->RES_CMF_13, MRASRESDEF_N->RES_CMF_13, sizeof(MRASRESDEF->RES_CMF_13));
    MEMCPY_DN(MRASRESDEF->RES_CMF_14, MRASRESDEF_N->RES_CMF_14, sizeof(MRASRESDEF->RES_CMF_14));
    MEMCPY_DN(MRASRESDEF->RES_CMF_15, MRASRESDEF_N->RES_CMF_15, sizeof(MRASRESDEF->RES_CMF_15));
    MEMCPY_DN(MRASRESDEF->RES_CMF_16, MRASRESDEF_N->RES_CMF_16, sizeof(MRASRESDEF->RES_CMF_16));
    MEMCPY_DN(MRASRESDEF->RES_CMF_17, MRASRESDEF_N->RES_CMF_17, sizeof(MRASRESDEF->RES_CMF_17));
    MEMCPY_DN(MRASRESDEF->RES_CMF_18, MRASRESDEF_N->RES_CMF_18, sizeof(MRASRESDEF->RES_CMF_18));
    MEMCPY_DN(MRASRESDEF->RES_CMF_19, MRASRESDEF_N->RES_CMF_19, sizeof(MRASRESDEF->RES_CMF_19));
    MEMCPY_DN(MRASRESDEF->RES_CMF_20, MRASRESDEF_N->RES_CMF_20, sizeof(MRASRESDEF->RES_CMF_20));
    MEMCPY_DN(MRASRESDEF->AREA_ID, MRASRESDEF_N->AREA_ID, sizeof(MRASRESDEF->AREA_ID));
    MEMCPY_DN(MRASRESDEF->SUB_AREA_ID, MRASRESDEF_N->SUB_AREA_ID, sizeof(MRASRESDEF->SUB_AREA_ID));
    MEMCPY_DN(MRASRESDEF->RES_LOCATION, MRASRESDEF_N->RES_LOCATION, sizeof(MRASRESDEF->RES_LOCATION));
    MRASRESDEF->PROC_RULE = MRASRESDEF_N->PROC_RULE[0];
    MRASRESDEF->MAX_PROC_COUNT = MRASRESDEF_N->MAX_PROC_COUNT;
    MEMCPY_DN(MRASRESDEF->BATCH_COND_1, MRASRESDEF_N->BATCH_COND_1, sizeof(MRASRESDEF->BATCH_COND_1));
    MEMCPY_DN(MRASRESDEF->BATCH_COND_2, MRASRESDEF_N->BATCH_COND_2, sizeof(MRASRESDEF->BATCH_COND_2));
    MRASRESDEF->PM_SCH_ENABLE_FLAG = MRASRESDEF_N->PM_SCH_ENABLE_FLAG[0];
    MRASRESDEF->UNIT_BASE_ST_FLAG = MRASRESDEF_N->UNIT_BASE_ST_FLAG[0];
    MRASRESDEF->SEC_CHK_FLAG = MRASRESDEF_N->SEC_CHK_FLAG[0];
    MRASRESDEF->GATHER_ALARM_FLAG = MRASRESDEF_N->GATHER_ALARM_FLAG[0];
    MRASRESDEF->DELETE_FLAG = MRASRESDEF_N->DELETE_FLAG[0];
    MEMCPY_DN(MRASRESDEF->DELETE_USER_ID, MRASRESDEF_N->DELETE_USER_ID, sizeof(MRASRESDEF->DELETE_USER_ID));
    MEMCPY_DN(MRASRESDEF->DELETE_TIME, MRASRESDEF_N->DELETE_TIME, sizeof(MRASRESDEF->DELETE_TIME));
    MEMCPY_DN(MRASRESDEF->CREATE_USER_ID, MRASRESDEF_N->CREATE_USER_ID, sizeof(MRASRESDEF->CREATE_USER_ID));
    MEMCPY_DN(MRASRESDEF->CREATE_TIME, MRASRESDEF_N->CREATE_TIME, sizeof(MRASRESDEF->CREATE_TIME));
    MEMCPY_DN(MRASRESDEF->UPDATE_USER_ID, MRASRESDEF_N->UPDATE_USER_ID, sizeof(MRASRESDEF->UPDATE_USER_ID));
    MEMCPY_DN(MRASRESDEF->UPDATE_TIME, MRASRESDEF_N->UPDATE_TIME, sizeof(MRASRESDEF->UPDATE_TIME));
    MRASRESDEF->RES_UP_DOWN_FLAG = MRASRESDEF_N->RES_UP_DOWN_FLAG[0];
    MEMCPY_DN(MRASRESDEF->RES_PRI_STS, MRASRESDEF_N->RES_PRI_STS, sizeof(MRASRESDEF->RES_PRI_STS));
    MEMCPY_DN(MRASRESDEF->RES_STS_1, MRASRESDEF_N->RES_STS_1, sizeof(MRASRESDEF->RES_STS_1));
    MEMCPY_DN(MRASRESDEF->RES_STS_2, MRASRESDEF_N->RES_STS_2, sizeof(MRASRESDEF->RES_STS_2));
    MEMCPY_DN(MRASRESDEF->RES_STS_3, MRASRESDEF_N->RES_STS_3, sizeof(MRASRESDEF->RES_STS_3));
    MEMCPY_DN(MRASRESDEF->RES_STS_4, MRASRESDEF_N->RES_STS_4, sizeof(MRASRESDEF->RES_STS_4));
    MEMCPY_DN(MRASRESDEF->RES_STS_5, MRASRESDEF_N->RES_STS_5, sizeof(MRASRESDEF->RES_STS_5));
    MEMCPY_DN(MRASRESDEF->RES_STS_6, MRASRESDEF_N->RES_STS_6, sizeof(MRASRESDEF->RES_STS_6));
    MEMCPY_DN(MRASRESDEF->RES_STS_7, MRASRESDEF_N->RES_STS_7, sizeof(MRASRESDEF->RES_STS_7));
    MEMCPY_DN(MRASRESDEF->RES_STS_8, MRASRESDEF_N->RES_STS_8, sizeof(MRASRESDEF->RES_STS_8));
    MEMCPY_DN(MRASRESDEF->RES_STS_9, MRASRESDEF_N->RES_STS_9, sizeof(MRASRESDEF->RES_STS_9));
    MEMCPY_DN(MRASRESDEF->RES_STS_10, MRASRESDEF_N->RES_STS_10, sizeof(MRASRESDEF->RES_STS_10));
    MEMCPY_DN(MRASRESDEF->LOT_ID, MRASRESDEF_N->LOT_ID, sizeof(MRASRESDEF->LOT_ID));
    MEMCPY_DN(MRASRESDEF->SUBLOT_ID, MRASRESDEF_N->SUBLOT_ID, sizeof(MRASRESDEF->SUBLOT_ID));
    MEMCPY_DN(MRASRESDEF->CRR_ID, MRASRESDEF_N->CRR_ID, sizeof(MRASRESDEF->CRR_ID));
    MEMCPY_DN(MRASRESDEF->RES_CTRL_MODE, MRASRESDEF_N->RES_CTRL_MODE, sizeof(MRASRESDEF->RES_CTRL_MODE));
    MEMCPY_DN(MRASRESDEF->RES_PROC_MODE, MRASRESDEF_N->RES_PROC_MODE, sizeof(MRASRESDEF->RES_PROC_MODE));
    MEMCPY_DN(MRASRESDEF->LAST_RECIPE_ID, MRASRESDEF_N->LAST_RECIPE_ID, sizeof(MRASRESDEF->LAST_RECIPE_ID));
    MRASRESDEF->PROC_COUNT = MRASRESDEF_N->PROC_COUNT;
    MEMCPY_DN(MRASRESDEF->LAST_START_TIME, MRASRESDEF_N->LAST_START_TIME, sizeof(MRASRESDEF->LAST_START_TIME));
    MEMCPY_DN(MRASRESDEF->LAST_END_TIME, MRASRESDEF_N->LAST_END_TIME, sizeof(MRASRESDEF->LAST_END_TIME));
    MEMCPY_DN(MRASRESDEF->LAST_DOWN_TIME, MRASRESDEF_N->LAST_DOWN_TIME, sizeof(MRASRESDEF->LAST_DOWN_TIME));
    MRASRESDEF->LAST_DOWN_HIST_SEQ = MRASRESDEF_N->LAST_DOWN_HIST_SEQ;
    MEMCPY_DN(MRASRESDEF->LAST_EVENT_ID, MRASRESDEF_N->LAST_EVENT_ID, sizeof(MRASRESDEF->LAST_EVENT_ID));
    MEMCPY_DN(MRASRESDEF->LAST_EVENT_TIME, MRASRESDEF_N->LAST_EVENT_TIME, sizeof(MRASRESDEF->LAST_EVENT_TIME));
    MRASRESDEF->LAST_ACTIVE_HIST_SEQ = MRASRESDEF_N->LAST_ACTIVE_HIST_SEQ;
    MRASRESDEF->LAST_HIST_SEQ = MRASRESDEF_N->LAST_HIST_SEQ;
    MEMCPY_DN(MRASRESDEF->RES_SHORT_DESC, MRASRESDEF_N->RES_SHORT_DESC, sizeof(MRASRESDEF->RES_SHORT_DESC));
}


