
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
    "DBU_mwipmatdef.pc"
};


static unsigned int sqlctx = 9436955;


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
            void  *sqhstv[105];
   unsigned int   sqhstl[105];
            int   sqhsts[105];
            void  *sqindv[105];
            int   sqinds[105];
   unsigned int   sqharm[105];
   unsigned int   *sqharc[105];
   unsigned short  sqadto[105];
   unsigned short  sqtdso[105];
} sqlstm = {13,105};

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
"T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 \
,APPLY_START_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_\
TIME ,RELEASE_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_US\
ER_ID ,DEACTIVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_I\
D ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC  from MWIPMATDEF \
 order by FACTORY asc ,MAT_ID asc ,MAT_VER asc             ";

 static const char *sq0012 = 
"T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 \
,APPLY_START_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_\
TIME ,RELEASE_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_US\
ER_ID ,DEACTIVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_I\
D ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC  from (select *  \
from MWIPMATDEF where (FACTORY=:b0 and MAT_GRP_1=:b1) union select *  from MW\
IPMATDEF where (FACTORY=:b0 and MAT_GRP_1=' '))  order by FACTORY asc ,MAT_ID\
 asc ,MAT_VER asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,1927,0,4,46,0,0,105,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,
97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,
440,0,0,2,1929,0,4,259,0,0,105,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,
2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,
875,0,0,3,229,0,4,472,0,0,4,3,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
906,0,0,4,1939,0,4,515,0,0,105,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,
2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,
1341,0,0,5,95,0,4,764,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1372,0,0,6,895,0,4,773,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,3,0,0,
1399,0,0,7,77,0,2,829,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
1426,0,0,8,1778,0,3,860,0,0,102,102,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,
0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1849,0,0,9,1785,0,5,1089,0,0,102,102,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,
0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
2272,0,0,10,138,0,5,1195,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,
2315,0,0,11,1427,0,9,1340,0,0,0,0,0,1,0,
2330,0,0,12,1552,0,9,1460,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,
2357,0,0,11,0,0,13,1489,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,
0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2780,0,0,12,0,0,13,1595,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,
0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3203,0,0,11,0,0,15,1727,0,0,0,0,0,1,0,
3218,0,0,12,0,0,15,1731,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_mwipmatdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-07-21 12:08:50
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
void DBU_add_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF);
void DBU_del_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF);


/* SQL SELECT Function */
void DBU_select_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    MAT_DESC,
                    MAT_TYPE,
                    MAT_GRP_1,
                    MAT_GRP_2,
                    MAT_GRP_3,
                    MAT_GRP_4,
                    MAT_GRP_5,
                    MAT_GRP_6,
                    MAT_GRP_7,
                    MAT_GRP_8,
                    MAT_GRP_9,
                    MAT_GRP_10,
                    MAT_CMF_1,
                    MAT_CMF_2,
                    MAT_CMF_3,
                    MAT_CMF_4,
                    MAT_CMF_5,
                    MAT_CMF_6,
                    MAT_CMF_7,
                    MAT_CMF_8,
                    MAT_CMF_9,
                    MAT_CMF_10,
                    MAT_CMF_11,
                    MAT_CMF_12,
                    MAT_CMF_13,
                    MAT_CMF_14,
                    MAT_CMF_15,
                    MAT_CMF_16,
                    MAT_CMF_17,
                    MAT_CMF_18,
                    MAT_CMF_19,
                    MAT_CMF_20,
                    FIRST_FLOW,
                    FIRST_FLOW_SEQ_NUM,
                    LAST_FLOW,
                    LAST_FLOW_SEQ_NUM,
                    MFG_DEVISION,
                    SUBCONTRACT_FLAG,
                    BASE_MAT_ID,
                    VENDOR_ID,
                    VENDOR_MAT_ID,
                    CUSTOMER_ID,
                    CUSTOMER_MAT_ID,
                    DEF_QTY_1,
                    DEF_QTY_2,
                    DEF_QTY_3,
                    UNIT_1,
                    UNIT_2,
                    UNIT_3,
                    WEIGHT_NET,
                    WEIGHT_GROSS,
                    WEIGHT_UNIT,
                    VOLUME,
                    VOLUME_UNIT,
                    DIMENSION_HR,
                    DIMENSION_HR_UNIT,
                    DIMENSION_VT,
                    DIMENSION_VT_UNIT,
                    DIMENSION_HT,
                    DIMENSION_HT_UNIT,
                    BOM_SET_ID,
                    DEF_INV_OPER,
                    PACK_TYPE,
                    PACK_LOT_COUNT,
                    PACK_QTY,
                    LE_STOCK_LEVEL,
                    LW_STOCK_LEVEL,
                    HW_STOCK_LEVEL,
                    HE_STOCK_LEVEL,
                    IQC_FLAG,
                    IQC_SAMPLE_FLAG,
                    IQC_SAMPLE_RULE,
                    OQC_FLAG,
                    OQC_SAMPLE_FLAG,
                    OQC_SAMPLE_RULE,
                    TARGET_YIELD,
                    TARGET_DUE_DAY,
                    TARGET_QTY_1,
                    TARGET_QTY_2,
                    TARGET_QTY_3,
                    APPLY_START_TIME,
                    APPLY_END_TIME,
                    APPROVAL_FLAG,
                    APPROVAL_USER_ID,
                    APPROVAL_TIME,
                    RELEASE_FLAG,
                    RELEASE_USER_ID,
                    RELEASE_TIME,
                    DEACTIVE_FLAG,
                    DEACTIVE_USER_ID,
                    DEACTIVE_TIME,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    MAT_SHORT_DESC
                INTO 
                    :MWIPMATDEF_N.FACTORY,
                    :MWIPMATDEF_N.MAT_ID,
                    :MWIPMATDEF_N.MAT_VER,
                    :MWIPMATDEF_N.MAT_DESC,
                    :MWIPMATDEF_N.MAT_TYPE,
                    :MWIPMATDEF_N.MAT_GRP_1,
                    :MWIPMATDEF_N.MAT_GRP_2,
                    :MWIPMATDEF_N.MAT_GRP_3,
                    :MWIPMATDEF_N.MAT_GRP_4,
                    :MWIPMATDEF_N.MAT_GRP_5,
                    :MWIPMATDEF_N.MAT_GRP_6,
                    :MWIPMATDEF_N.MAT_GRP_7,
                    :MWIPMATDEF_N.MAT_GRP_8,
                    :MWIPMATDEF_N.MAT_GRP_9,
                    :MWIPMATDEF_N.MAT_GRP_10,
                    :MWIPMATDEF_N.MAT_CMF_1,
                    :MWIPMATDEF_N.MAT_CMF_2,
                    :MWIPMATDEF_N.MAT_CMF_3,
                    :MWIPMATDEF_N.MAT_CMF_4,
                    :MWIPMATDEF_N.MAT_CMF_5,
                    :MWIPMATDEF_N.MAT_CMF_6,
                    :MWIPMATDEF_N.MAT_CMF_7,
                    :MWIPMATDEF_N.MAT_CMF_8,
                    :MWIPMATDEF_N.MAT_CMF_9,
                    :MWIPMATDEF_N.MAT_CMF_10,
                    :MWIPMATDEF_N.MAT_CMF_11,
                    :MWIPMATDEF_N.MAT_CMF_12,
                    :MWIPMATDEF_N.MAT_CMF_13,
                    :MWIPMATDEF_N.MAT_CMF_14,
                    :MWIPMATDEF_N.MAT_CMF_15,
                    :MWIPMATDEF_N.MAT_CMF_16,
                    :MWIPMATDEF_N.MAT_CMF_17,
                    :MWIPMATDEF_N.MAT_CMF_18,
                    :MWIPMATDEF_N.MAT_CMF_19,
                    :MWIPMATDEF_N.MAT_CMF_20,
                    :MWIPMATDEF_N.FIRST_FLOW,
                    :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.LAST_FLOW,
                    :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.MFG_DEVISION,
                    :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                    :MWIPMATDEF_N.BASE_MAT_ID,
                    :MWIPMATDEF_N.VENDOR_ID,
                    :MWIPMATDEF_N.VENDOR_MAT_ID,
                    :MWIPMATDEF_N.CUSTOMER_ID,
                    :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                    :MWIPMATDEF_N.DEF_QTY_1,
                    :MWIPMATDEF_N.DEF_QTY_2,
                    :MWIPMATDEF_N.DEF_QTY_3,
                    :MWIPMATDEF_N.UNIT_1,
                    :MWIPMATDEF_N.UNIT_2,
                    :MWIPMATDEF_N.UNIT_3,
                    :MWIPMATDEF_N.WEIGHT_NET,
                    :MWIPMATDEF_N.WEIGHT_GROSS,
                    :MWIPMATDEF_N.WEIGHT_UNIT,
                    :MWIPMATDEF_N.VOLUME,
                    :MWIPMATDEF_N.VOLUME_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HR,
                    :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                    :MWIPMATDEF_N.DIMENSION_VT,
                    :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HT,
                    :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                    :MWIPMATDEF_N.BOM_SET_ID,
                    :MWIPMATDEF_N.DEF_INV_OPER,
                    :MWIPMATDEF_N.PACK_TYPE,
                    :MWIPMATDEF_N.PACK_LOT_COUNT,
                    :MWIPMATDEF_N.PACK_QTY,
                    :MWIPMATDEF_N.LE_STOCK_LEVEL,
                    :MWIPMATDEF_N.LW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HE_STOCK_LEVEL,
                    :MWIPMATDEF_N.IQC_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.OQC_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.TARGET_YIELD,
                    :MWIPMATDEF_N.TARGET_DUE_DAY,
                    :MWIPMATDEF_N.TARGET_QTY_1,
                    :MWIPMATDEF_N.TARGET_QTY_2,
                    :MWIPMATDEF_N.TARGET_QTY_3,
                    :MWIPMATDEF_N.APPLY_START_TIME,
                    :MWIPMATDEF_N.APPLY_END_TIME,
                    :MWIPMATDEF_N.APPROVAL_FLAG,
                    :MWIPMATDEF_N.APPROVAL_USER_ID,
                    :MWIPMATDEF_N.APPROVAL_TIME,
                    :MWIPMATDEF_N.RELEASE_FLAG,
                    :MWIPMATDEF_N.RELEASE_USER_ID,
                    :MWIPMATDEF_N.RELEASE_TIME,
                    :MWIPMATDEF_N.DEACTIVE_FLAG,
                    :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    :MWIPMATDEF_N.DEACTIVE_TIME,
                    :MWIPMATDEF_N.DELETE_FLAG,
                    :MWIPMATDEF_N.DELETE_USER_ID,
                    :MWIPMATDEF_N.DELETE_TIME,
                    :MWIPMATDEF_N.CREATE_USER_ID,
                    :MWIPMATDEF_N.CREATE_TIME,
                    :MWIPMATDEF_N.UPDATE_USER_ID,
                    :MWIPMATDEF_N.UPDATE_TIME,
                    :MWIPMATDEF_N.MAT_SHORT_DESC
                FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,MAT_DESC ,MAT_TYPE ,MAT_GRP_\
1 ,MAT_GRP_2 ,MAT_GRP_3 ,MAT_GRP_4 ,MAT_GRP_5 ,MAT_GRP_6 ,MAT_GRP_7 ,MAT_GRP\
_8 ,MAT_GRP_9 ,MAT_GRP_10 ,MAT_CMF_1 ,MAT_CMF_2 ,MAT_CMF_3 ,MAT_CMF_4 ,MAT_C\
MF_5 ,MAT_CMF_6 ,MAT_CMF_7 ,MAT_CMF_8 ,MAT_CMF_9 ,MAT_CMF_10 ,MAT_CMF_11 ,MA\
T_CMF_12 ,MAT_CMF_13 ,MAT_CMF_14 ,MAT_CMF_15 ,MAT_CMF_16 ,MAT_CMF_17 ,MAT_CM\
F_18 ,MAT_CMF_19 ,MAT_CMF_20 ,FIRST_FLOW ,FIRST_FLOW_SEQ_NUM ,LAST_FLOW ,LAS\
T_FLOW_SEQ_NUM ,MFG_DEVISION ,SUBCONTRACT_FLAG ,BASE_MAT_ID ,VENDOR_ID ,VEND\
OR_MAT_ID ,CUSTOMER_ID ,CUSTOMER_MAT_ID ,DEF_QTY_1 ,DEF_QTY_2 ,DEF_QTY_3 ,UN\
IT_1 ,UNIT_2 ,UNIT_3 ,WEIGHT_NET ,WEIGHT_GROSS ,WEIGHT_UNIT ,VOLUME ,VOLUME_\
UNIT ,DIMENSION_HR ,DIMENSION_HR_UNIT ,DIMENSION_VT ,DIMENSION_VT_UNIT ,DIME\
NSION_HT ,DIMENSION_HT_UNIT ,BOM_SET_ID ,DEF_INV_OPER ,PACK_TYPE ,PACK_LOT_C\
OUNT ,PACK_QTY ,LE_STOCK_LEVEL ,LW_STOCK_LEVEL ,HW_STOCK_LEVEL ,HE_STOCK_LEV\
EL ,IQC_FLAG ,IQC_SAMPLE_FLAG ,IQC_SAMPLE_RULE ,OQC_FLAG ,OQC_SAMPLE_FLAG ,O\
QC_SAMPLE_RULE ,TARGET_YIELD ,TARGET_DUE_DAY ,TARGE");
            sqlstm.stmt = "T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 ,APPLY_START\
_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_TIME ,RELEAS\
E_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_USER_ID ,DEACT\
IVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TI\
ME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC into :b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:\
b99,:b100,:b101  from MWIPMATDEF where ((FACTORY=:b0 and MAT_ID=:b1) and MAT_\
VER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMATDEF_N.UNIT_1);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMATDEF_N.UNIT_2);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.UNIT_3);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MWIPMATDEF_N.VOLUME);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
            sqlstm.sqhstl[62] = (unsigned int  )11;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
            sqlstm.sqhstl[64] = (unsigned int  )11;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
            sqlstm.sqhstl[71] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
            sqlstm.sqhstl[85] = (unsigned int  )2;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
            sqlstm.sqhstl[90] = (unsigned int  )15;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[93] = (unsigned int  )15;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[94] = (unsigned int  )2;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[96] = (unsigned int  )15;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
            sqlstm.sqhstl[98] = (unsigned int  )15;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[100] = (unsigned int  )15;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
            sqlstm.sqhstl[101] = (unsigned int  )51;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[102] = (unsigned int  )11;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[104] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
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
                    MAT_ID,
                    MAT_VER,
                    MAT_DESC,
                    MAT_TYPE,
                    MAT_GRP_1,
                    MAT_GRP_2,
                    MAT_GRP_3,
                    MAT_GRP_4,
                    MAT_GRP_5,
                    MAT_GRP_6,
                    MAT_GRP_7,
                    MAT_GRP_8,
                    MAT_GRP_9,
                    MAT_GRP_10,
                    MAT_CMF_1,
                    MAT_CMF_2,
                    MAT_CMF_3,
                    MAT_CMF_4,
                    MAT_CMF_5,
                    MAT_CMF_6,
                    MAT_CMF_7,
                    MAT_CMF_8,
                    MAT_CMF_9,
                    MAT_CMF_10,
                    MAT_CMF_11,
                    MAT_CMF_12,
                    MAT_CMF_13,
                    MAT_CMF_14,
                    MAT_CMF_15,
                    MAT_CMF_16,
                    MAT_CMF_17,
                    MAT_CMF_18,
                    MAT_CMF_19,
                    MAT_CMF_20,
                    FIRST_FLOW,
                    FIRST_FLOW_SEQ_NUM,
                    LAST_FLOW,
                    LAST_FLOW_SEQ_NUM,
                    MFG_DEVISION,
                    SUBCONTRACT_FLAG,
                    BASE_MAT_ID,
                    VENDOR_ID,
                    VENDOR_MAT_ID,
                    CUSTOMER_ID,
                    CUSTOMER_MAT_ID,
                    DEF_QTY_1,
                    DEF_QTY_2,
                    DEF_QTY_3,
                    UNIT_1,
                    UNIT_2,
                    UNIT_3,
                    WEIGHT_NET,
                    WEIGHT_GROSS,
                    WEIGHT_UNIT,
                    VOLUME,
                    VOLUME_UNIT,
                    DIMENSION_HR,
                    DIMENSION_HR_UNIT,
                    DIMENSION_VT,
                    DIMENSION_VT_UNIT,
                    DIMENSION_HT,
                    DIMENSION_HT_UNIT,
                    BOM_SET_ID,
                    DEF_INV_OPER,
                    PACK_TYPE,
                    PACK_LOT_COUNT,
                    PACK_QTY,
                    LE_STOCK_LEVEL,
                    LW_STOCK_LEVEL,
                    HW_STOCK_LEVEL,
                    HE_STOCK_LEVEL,
                    IQC_FLAG,
                    IQC_SAMPLE_FLAG,
                    IQC_SAMPLE_RULE,
                    OQC_FLAG,
                    OQC_SAMPLE_FLAG,
                    OQC_SAMPLE_RULE,
                    TARGET_YIELD,
                    TARGET_DUE_DAY,
                    TARGET_QTY_1,
                    TARGET_QTY_2,
                    TARGET_QTY_3,
                    APPLY_START_TIME,
                    APPLY_END_TIME,
                    APPROVAL_FLAG,
                    APPROVAL_USER_ID,
                    APPROVAL_TIME,
                    RELEASE_FLAG,
                    RELEASE_USER_ID,
                    RELEASE_TIME,
                    DEACTIVE_FLAG,
                    DEACTIVE_USER_ID,
                    DEACTIVE_TIME,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    MAT_SHORT_DESC
                INTO 
                    :MWIPMATDEF_N.FACTORY,
                    :MWIPMATDEF_N.MAT_ID,
                    :MWIPMATDEF_N.MAT_VER,
                    :MWIPMATDEF_N.MAT_DESC,
                    :MWIPMATDEF_N.MAT_TYPE,
                    :MWIPMATDEF_N.MAT_GRP_1,
                    :MWIPMATDEF_N.MAT_GRP_2,
                    :MWIPMATDEF_N.MAT_GRP_3,
                    :MWIPMATDEF_N.MAT_GRP_4,
                    :MWIPMATDEF_N.MAT_GRP_5,
                    :MWIPMATDEF_N.MAT_GRP_6,
                    :MWIPMATDEF_N.MAT_GRP_7,
                    :MWIPMATDEF_N.MAT_GRP_8,
                    :MWIPMATDEF_N.MAT_GRP_9,
                    :MWIPMATDEF_N.MAT_GRP_10,
                    :MWIPMATDEF_N.MAT_CMF_1,
                    :MWIPMATDEF_N.MAT_CMF_2,
                    :MWIPMATDEF_N.MAT_CMF_3,
                    :MWIPMATDEF_N.MAT_CMF_4,
                    :MWIPMATDEF_N.MAT_CMF_5,
                    :MWIPMATDEF_N.MAT_CMF_6,
                    :MWIPMATDEF_N.MAT_CMF_7,
                    :MWIPMATDEF_N.MAT_CMF_8,
                    :MWIPMATDEF_N.MAT_CMF_9,
                    :MWIPMATDEF_N.MAT_CMF_10,
                    :MWIPMATDEF_N.MAT_CMF_11,
                    :MWIPMATDEF_N.MAT_CMF_12,
                    :MWIPMATDEF_N.MAT_CMF_13,
                    :MWIPMATDEF_N.MAT_CMF_14,
                    :MWIPMATDEF_N.MAT_CMF_15,
                    :MWIPMATDEF_N.MAT_CMF_16,
                    :MWIPMATDEF_N.MAT_CMF_17,
                    :MWIPMATDEF_N.MAT_CMF_18,
                    :MWIPMATDEF_N.MAT_CMF_19,
                    :MWIPMATDEF_N.MAT_CMF_20,
                    :MWIPMATDEF_N.FIRST_FLOW,
                    :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.LAST_FLOW,
                    :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.MFG_DEVISION,
                    :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                    :MWIPMATDEF_N.BASE_MAT_ID,
                    :MWIPMATDEF_N.VENDOR_ID,
                    :MWIPMATDEF_N.VENDOR_MAT_ID,
                    :MWIPMATDEF_N.CUSTOMER_ID,
                    :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                    :MWIPMATDEF_N.DEF_QTY_1,
                    :MWIPMATDEF_N.DEF_QTY_2,
                    :MWIPMATDEF_N.DEF_QTY_3,
                    :MWIPMATDEF_N.UNIT_1,
                    :MWIPMATDEF_N.UNIT_2,
                    :MWIPMATDEF_N.UNIT_3,
                    :MWIPMATDEF_N.WEIGHT_NET,
                    :MWIPMATDEF_N.WEIGHT_GROSS,
                    :MWIPMATDEF_N.WEIGHT_UNIT,
                    :MWIPMATDEF_N.VOLUME,
                    :MWIPMATDEF_N.VOLUME_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HR,
                    :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                    :MWIPMATDEF_N.DIMENSION_VT,
                    :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HT,
                    :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                    :MWIPMATDEF_N.BOM_SET_ID,
                    :MWIPMATDEF_N.DEF_INV_OPER,
                    :MWIPMATDEF_N.PACK_TYPE,
                    :MWIPMATDEF_N.PACK_LOT_COUNT,
                    :MWIPMATDEF_N.PACK_QTY,
                    :MWIPMATDEF_N.LE_STOCK_LEVEL,
                    :MWIPMATDEF_N.LW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HE_STOCK_LEVEL,
                    :MWIPMATDEF_N.IQC_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.OQC_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.TARGET_YIELD,
                    :MWIPMATDEF_N.TARGET_DUE_DAY,
                    :MWIPMATDEF_N.TARGET_QTY_1,
                    :MWIPMATDEF_N.TARGET_QTY_2,
                    :MWIPMATDEF_N.TARGET_QTY_3,
                    :MWIPMATDEF_N.APPLY_START_TIME,
                    :MWIPMATDEF_N.APPLY_END_TIME,
                    :MWIPMATDEF_N.APPROVAL_FLAG,
                    :MWIPMATDEF_N.APPROVAL_USER_ID,
                    :MWIPMATDEF_N.APPROVAL_TIME,
                    :MWIPMATDEF_N.RELEASE_FLAG,
                    :MWIPMATDEF_N.RELEASE_USER_ID,
                    :MWIPMATDEF_N.RELEASE_TIME,
                    :MWIPMATDEF_N.DEACTIVE_FLAG,
                    :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    :MWIPMATDEF_N.DEACTIVE_TIME,
                    :MWIPMATDEF_N.DELETE_FLAG,
                    :MWIPMATDEF_N.DELETE_USER_ID,
                    :MWIPMATDEF_N.DELETE_TIME,
                    :MWIPMATDEF_N.CREATE_USER_ID,
                    :MWIPMATDEF_N.CREATE_TIME,
                    :MWIPMATDEF_N.UPDATE_USER_ID,
                    :MWIPMATDEF_N.UPDATE_TIME,
                    :MWIPMATDEF_N.MAT_SHORT_DESC
                FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_GRP_1 = :MWIPMATDEF_N.MAT_GRP_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,MAT_DESC ,MAT_TYPE ,MAT_GRP_\
1 ,MAT_GRP_2 ,MAT_GRP_3 ,MAT_GRP_4 ,MAT_GRP_5 ,MAT_GRP_6 ,MAT_GRP_7 ,MAT_GRP\
_8 ,MAT_GRP_9 ,MAT_GRP_10 ,MAT_CMF_1 ,MAT_CMF_2 ,MAT_CMF_3 ,MAT_CMF_4 ,MAT_C\
MF_5 ,MAT_CMF_6 ,MAT_CMF_7 ,MAT_CMF_8 ,MAT_CMF_9 ,MAT_CMF_10 ,MAT_CMF_11 ,MA\
T_CMF_12 ,MAT_CMF_13 ,MAT_CMF_14 ,MAT_CMF_15 ,MAT_CMF_16 ,MAT_CMF_17 ,MAT_CM\
F_18 ,MAT_CMF_19 ,MAT_CMF_20 ,FIRST_FLOW ,FIRST_FLOW_SEQ_NUM ,LAST_FLOW ,LAS\
T_FLOW_SEQ_NUM ,MFG_DEVISION ,SUBCONTRACT_FLAG ,BASE_MAT_ID ,VENDOR_ID ,VEND\
OR_MAT_ID ,CUSTOMER_ID ,CUSTOMER_MAT_ID ,DEF_QTY_1 ,DEF_QTY_2 ,DEF_QTY_3 ,UN\
IT_1 ,UNIT_2 ,UNIT_3 ,WEIGHT_NET ,WEIGHT_GROSS ,WEIGHT_UNIT ,VOLUME ,VOLUME_\
UNIT ,DIMENSION_HR ,DIMENSION_HR_UNIT ,DIMENSION_VT ,DIMENSION_VT_UNIT ,DIME\
NSION_HT ,DIMENSION_HT_UNIT ,BOM_SET_ID ,DEF_INV_OPER ,PACK_TYPE ,PACK_LOT_C\
OUNT ,PACK_QTY ,LE_STOCK_LEVEL ,LW_STOCK_LEVEL ,HW_STOCK_LEVEL ,HE_STOCK_LEV\
EL ,IQC_FLAG ,IQC_SAMPLE_FLAG ,IQC_SAMPLE_RULE ,OQC_FLAG ,OQC_SAMPLE_FLAG ,O\
QC_SAMPLE_RULE ,TARGET_YIELD ,TARGET_DUE_DAY ,TARGE");
            sqlstm.stmt = "T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 ,APPLY_START\
_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_TIME ,RELEAS\
E_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_USER_ID ,DEACT\
IVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TI\
ME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC into :b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:\
b99,:b100,:b101  from MWIPMATDEF where ((FACTORY=:b0 and MAT_ID=:b1) and MAT_\
GRP_1=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )440;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMATDEF_N.UNIT_1);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMATDEF_N.UNIT_2);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.UNIT_3);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MWIPMATDEF_N.VOLUME);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
            sqlstm.sqhstl[62] = (unsigned int  )11;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
            sqlstm.sqhstl[64] = (unsigned int  )11;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
            sqlstm.sqhstl[71] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
            sqlstm.sqhstl[85] = (unsigned int  )2;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
            sqlstm.sqhstl[90] = (unsigned int  )15;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[93] = (unsigned int  )15;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[94] = (unsigned int  )2;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[96] = (unsigned int  )15;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
            sqlstm.sqhstl[98] = (unsigned int  )15;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[100] = (unsigned int  )15;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
            sqlstm.sqhstl[101] = (unsigned int  )51;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[102] = (unsigned int  )11;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
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
                     NVL(SUBSTR(SUBSTR(A.MAT_DESC, INSTR(A.MAT_DESC, '/', 1) + 1, 5), 0, INSTR(SUBSTR(A.MAT_DESC, INSTR(A.MAT_DESC, '/', 1) + 1, 5), '.', 1, 2) - 1), '0')
                INTO 
                    :MWIPMATDEF_N.MAT_CMF_20
                FROM MWIPMATDEF A
                WHERE A.FACTORY = :MWIPMATDEF_N.FACTORY
                    AND A.MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND A.MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(SUBSTR(SUBSTR(A.MAT_DESC,(INSTR(A.MAT\
_DESC,'/',1)+1),5),0,(INSTR(SUBSTR(A.MAT_DESC,(INSTR(A.MAT_DESC,'/',1)+1),5),\
'.',1,2)-1)),'0') into :b0  from MWIPMATDEF A where ((A.FACTORY=:b1 and A.MAT\
_ID=:b2) and A.MAT_VER=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )875;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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


    if(DB_error_code == 0)
    {
        DBU_del_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    }

    DB_stop_query_timer("DBU_select_mwipmatdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_mwipmatdef_for_update(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    MAT_DESC,
                    MAT_TYPE,
                    MAT_GRP_1,
                    MAT_GRP_2,
                    MAT_GRP_3,
                    MAT_GRP_4,
                    MAT_GRP_5,
                    MAT_GRP_6,
                    MAT_GRP_7,
                    MAT_GRP_8,
                    MAT_GRP_9,
                    MAT_GRP_10,
                    MAT_CMF_1,
                    MAT_CMF_2,
                    MAT_CMF_3,
                    MAT_CMF_4,
                    MAT_CMF_5,
                    MAT_CMF_6,
                    MAT_CMF_7,
                    MAT_CMF_8,
                    MAT_CMF_9,
                    MAT_CMF_10,
                    MAT_CMF_11,
                    MAT_CMF_12,
                    MAT_CMF_13,
                    MAT_CMF_14,
                    MAT_CMF_15,
                    MAT_CMF_16,
                    MAT_CMF_17,
                    MAT_CMF_18,
                    MAT_CMF_19,
                    MAT_CMF_20,
                    FIRST_FLOW,
                    FIRST_FLOW_SEQ_NUM,
                    LAST_FLOW,
                    LAST_FLOW_SEQ_NUM,
                    MFG_DEVISION,
                    SUBCONTRACT_FLAG,
                    BASE_MAT_ID,
                    VENDOR_ID,
                    VENDOR_MAT_ID,
                    CUSTOMER_ID,
                    CUSTOMER_MAT_ID,
                    DEF_QTY_1,
                    DEF_QTY_2,
                    DEF_QTY_3,
                    UNIT_1,
                    UNIT_2,
                    UNIT_3,
                    WEIGHT_NET,
                    WEIGHT_GROSS,
                    WEIGHT_UNIT,
                    VOLUME,
                    VOLUME_UNIT,
                    DIMENSION_HR,
                    DIMENSION_HR_UNIT,
                    DIMENSION_VT,
                    DIMENSION_VT_UNIT,
                    DIMENSION_HT,
                    DIMENSION_HT_UNIT,
                    BOM_SET_ID,
                    DEF_INV_OPER,
                    PACK_TYPE,
                    PACK_LOT_COUNT,
                    PACK_QTY,
                    LE_STOCK_LEVEL,
                    LW_STOCK_LEVEL,
                    HW_STOCK_LEVEL,
                    HE_STOCK_LEVEL,
                    IQC_FLAG,
                    IQC_SAMPLE_FLAG,
                    IQC_SAMPLE_RULE,
                    OQC_FLAG,
                    OQC_SAMPLE_FLAG,
                    OQC_SAMPLE_RULE,
                    TARGET_YIELD,
                    TARGET_DUE_DAY,
                    TARGET_QTY_1,
                    TARGET_QTY_2,
                    TARGET_QTY_3,
                    APPLY_START_TIME,
                    APPLY_END_TIME,
                    APPROVAL_FLAG,
                    APPROVAL_USER_ID,
                    APPROVAL_TIME,
                    RELEASE_FLAG,
                    RELEASE_USER_ID,
                    RELEASE_TIME,
                    DEACTIVE_FLAG,
                    DEACTIVE_USER_ID,
                    DEACTIVE_TIME,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    MAT_SHORT_DESC
                INTO 
                    :MWIPMATDEF_N.FACTORY,
                    :MWIPMATDEF_N.MAT_ID,
                    :MWIPMATDEF_N.MAT_VER,
                    :MWIPMATDEF_N.MAT_DESC,
                    :MWIPMATDEF_N.MAT_TYPE,
                    :MWIPMATDEF_N.MAT_GRP_1,
                    :MWIPMATDEF_N.MAT_GRP_2,
                    :MWIPMATDEF_N.MAT_GRP_3,
                    :MWIPMATDEF_N.MAT_GRP_4,
                    :MWIPMATDEF_N.MAT_GRP_5,
                    :MWIPMATDEF_N.MAT_GRP_6,
                    :MWIPMATDEF_N.MAT_GRP_7,
                    :MWIPMATDEF_N.MAT_GRP_8,
                    :MWIPMATDEF_N.MAT_GRP_9,
                    :MWIPMATDEF_N.MAT_GRP_10,
                    :MWIPMATDEF_N.MAT_CMF_1,
                    :MWIPMATDEF_N.MAT_CMF_2,
                    :MWIPMATDEF_N.MAT_CMF_3,
                    :MWIPMATDEF_N.MAT_CMF_4,
                    :MWIPMATDEF_N.MAT_CMF_5,
                    :MWIPMATDEF_N.MAT_CMF_6,
                    :MWIPMATDEF_N.MAT_CMF_7,
                    :MWIPMATDEF_N.MAT_CMF_8,
                    :MWIPMATDEF_N.MAT_CMF_9,
                    :MWIPMATDEF_N.MAT_CMF_10,
                    :MWIPMATDEF_N.MAT_CMF_11,
                    :MWIPMATDEF_N.MAT_CMF_12,
                    :MWIPMATDEF_N.MAT_CMF_13,
                    :MWIPMATDEF_N.MAT_CMF_14,
                    :MWIPMATDEF_N.MAT_CMF_15,
                    :MWIPMATDEF_N.MAT_CMF_16,
                    :MWIPMATDEF_N.MAT_CMF_17,
                    :MWIPMATDEF_N.MAT_CMF_18,
                    :MWIPMATDEF_N.MAT_CMF_19,
                    :MWIPMATDEF_N.MAT_CMF_20,
                    :MWIPMATDEF_N.FIRST_FLOW,
                    :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.LAST_FLOW,
                    :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.MFG_DEVISION,
                    :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                    :MWIPMATDEF_N.BASE_MAT_ID,
                    :MWIPMATDEF_N.VENDOR_ID,
                    :MWIPMATDEF_N.VENDOR_MAT_ID,
                    :MWIPMATDEF_N.CUSTOMER_ID,
                    :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                    :MWIPMATDEF_N.DEF_QTY_1,
                    :MWIPMATDEF_N.DEF_QTY_2,
                    :MWIPMATDEF_N.DEF_QTY_3,
                    :MWIPMATDEF_N.UNIT_1,
                    :MWIPMATDEF_N.UNIT_2,
                    :MWIPMATDEF_N.UNIT_3,
                    :MWIPMATDEF_N.WEIGHT_NET,
                    :MWIPMATDEF_N.WEIGHT_GROSS,
                    :MWIPMATDEF_N.WEIGHT_UNIT,
                    :MWIPMATDEF_N.VOLUME,
                    :MWIPMATDEF_N.VOLUME_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HR,
                    :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                    :MWIPMATDEF_N.DIMENSION_VT,
                    :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HT,
                    :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                    :MWIPMATDEF_N.BOM_SET_ID,
                    :MWIPMATDEF_N.DEF_INV_OPER,
                    :MWIPMATDEF_N.PACK_TYPE,
                    :MWIPMATDEF_N.PACK_LOT_COUNT,
                    :MWIPMATDEF_N.PACK_QTY,
                    :MWIPMATDEF_N.LE_STOCK_LEVEL,
                    :MWIPMATDEF_N.LW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HE_STOCK_LEVEL,
                    :MWIPMATDEF_N.IQC_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.OQC_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.TARGET_YIELD,
                    :MWIPMATDEF_N.TARGET_DUE_DAY,
                    :MWIPMATDEF_N.TARGET_QTY_1,
                    :MWIPMATDEF_N.TARGET_QTY_2,
                    :MWIPMATDEF_N.TARGET_QTY_3,
                    :MWIPMATDEF_N.APPLY_START_TIME,
                    :MWIPMATDEF_N.APPLY_END_TIME,
                    :MWIPMATDEF_N.APPROVAL_FLAG,
                    :MWIPMATDEF_N.APPROVAL_USER_ID,
                    :MWIPMATDEF_N.APPROVAL_TIME,
                    :MWIPMATDEF_N.RELEASE_FLAG,
                    :MWIPMATDEF_N.RELEASE_USER_ID,
                    :MWIPMATDEF_N.RELEASE_TIME,
                    :MWIPMATDEF_N.DEACTIVE_FLAG,
                    :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    :MWIPMATDEF_N.DEACTIVE_TIME,
                    :MWIPMATDEF_N.DELETE_FLAG,
                    :MWIPMATDEF_N.DELETE_USER_ID,
                    :MWIPMATDEF_N.DELETE_TIME,
                    :MWIPMATDEF_N.CREATE_USER_ID,
                    :MWIPMATDEF_N.CREATE_TIME,
                    :MWIPMATDEF_N.UPDATE_USER_ID,
                    :MWIPMATDEF_N.UPDATE_TIME,
                    :MWIPMATDEF_N.MAT_SHORT_DESC
                FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,MAT_DESC ,MAT_TYPE ,MAT_GRP_\
1 ,MAT_GRP_2 ,MAT_GRP_3 ,MAT_GRP_4 ,MAT_GRP_5 ,MAT_GRP_6 ,MAT_GRP_7 ,MAT_GRP\
_8 ,MAT_GRP_9 ,MAT_GRP_10 ,MAT_CMF_1 ,MAT_CMF_2 ,MAT_CMF_3 ,MAT_CMF_4 ,MAT_C\
MF_5 ,MAT_CMF_6 ,MAT_CMF_7 ,MAT_CMF_8 ,MAT_CMF_9 ,MAT_CMF_10 ,MAT_CMF_11 ,MA\
T_CMF_12 ,MAT_CMF_13 ,MAT_CMF_14 ,MAT_CMF_15 ,MAT_CMF_16 ,MAT_CMF_17 ,MAT_CM\
F_18 ,MAT_CMF_19 ,MAT_CMF_20 ,FIRST_FLOW ,FIRST_FLOW_SEQ_NUM ,LAST_FLOW ,LAS\
T_FLOW_SEQ_NUM ,MFG_DEVISION ,SUBCONTRACT_FLAG ,BASE_MAT_ID ,VENDOR_ID ,VEND\
OR_MAT_ID ,CUSTOMER_ID ,CUSTOMER_MAT_ID ,DEF_QTY_1 ,DEF_QTY_2 ,DEF_QTY_3 ,UN\
IT_1 ,UNIT_2 ,UNIT_3 ,WEIGHT_NET ,WEIGHT_GROSS ,WEIGHT_UNIT ,VOLUME ,VOLUME_\
UNIT ,DIMENSION_HR ,DIMENSION_HR_UNIT ,DIMENSION_VT ,DIMENSION_VT_UNIT ,DIME\
NSION_HT ,DIMENSION_HT_UNIT ,BOM_SET_ID ,DEF_INV_OPER ,PACK_TYPE ,PACK_LOT_C\
OUNT ,PACK_QTY ,LE_STOCK_LEVEL ,LW_STOCK_LEVEL ,HW_STOCK_LEVEL ,HE_STOCK_LEV\
EL ,IQC_FLAG ,IQC_SAMPLE_FLAG ,IQC_SAMPLE_RULE ,OQC_FLAG ,OQC_SAMPLE_FLAG ,O\
QC_SAMPLE_RULE ,TARGET_YIELD ,TARGET_DUE_DAY ,TARGE");
            sqlstm.stmt = "T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 ,APPLY_START\
_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_TIME ,RELEAS\
E_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_USER_ID ,DEACT\
IVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_ID ,CREATE_TI\
ME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC into :b0,:b1,:b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:\
b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b3\
7,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,\
:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b\
68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83\
,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:\
b99,:b100,:b101  from MWIPMATDEF where ((FACTORY=:b0 and MAT_ID=:b1) and MAT_\
VER=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )906;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMATDEF_N.UNIT_1);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMATDEF_N.UNIT_2);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.UNIT_3);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MWIPMATDEF_N.VOLUME);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
            sqlstm.sqhstl[62] = (unsigned int  )11;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
            sqlstm.sqhstl[64] = (unsigned int  )11;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
            sqlstm.sqhstl[71] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
            sqlstm.sqhstl[85] = (unsigned int  )2;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
            sqlstm.sqhstl[90] = (unsigned int  )15;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[93] = (unsigned int  )15;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[94] = (unsigned int  )2;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[96] = (unsigned int  )15;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
            sqlstm.sqhstl[98] = (unsigned int  )15;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[100] = (unsigned int  )15;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
            sqlstm.sqhstl[101] = (unsigned int  )51;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[102] = (unsigned int  )11;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[104] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
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
        DBU_del_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    }

    DB_stop_query_timer("DBU_select_mwipmatdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_mwipmatdef_scalar(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPMATDEF where\
 ((FACTORY=:b1 and MAT_ID=:b2) and MAT_VER=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1341;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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

		case 2:
            /* EXEC SQL SELECT (CASE WHEN C.DATA_1 IS NOT NULL  THEN TO_NUMBER(DATA_1) ELSE (CASE WHEN SUBSTR(A.MAT_DESC,1,4) = 'IPOL' THEN CASE WHEN (B.ATTR_VALUE LIKE '%60.0%' OR
																																		  B.ATTR_VALUE LIKE '%60.5%' OR
																																		  B.ATTR_VALUE LIKE '%75.0%' OR
																																		  B.ATTR_VALUE LIKE '%75.7%' ) THEN 0.5
																																  ELSE 0 END
												WHEN SUBSTR(A.MAT_DESC,1,4) = 'IBON' THEN CASE WHEN (B.ATTR_VALUE LIKE '%55.0%' OR
																																		  B.ATTR_VALUE LIKE '%55.00%' OR
																																		  B.ATTR_VALUE LIKE '%50.00%' OR
																																		  B.ATTR_VALUE LIKE '%60.0%' OR
																																		  B.ATTR_VALUE LIKE '%50.0%' ) THEN 0
																						                                           ELSE 1 END
												ELSE 0.5 END) END) AS MINUS_VALUE
						  INTO :d_value
							FROM MWIPMATDEF A , MATRNAMSTS B ,MGCMTBLDAT C
							WHERE A.FACTORY = B.FACTORY(+)
							AND B.ATTR_TYPE(+) = 'MATERIAL'
							AND B.ATTR_NAME(+) = 'CATALOG_VALUE20'
							AND B.ATTR_KEY(+) = A.MAT_ID || ' : ' || '1'
							AND A.FACTORY = C.FACTORY(+)
							AND C.TABLE_NAME(+) = 'C_ROUND_CAL'
							AND A.MAT_GRP_1 = C.KEY_1(+)
							AND A.MAT_ID = C.KEY_2(+)
							AND A.MAT_ID = :MWIPMATDEF_N.MAT_ID
							AND A.MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select  case  when C.DATA_1 is  not null  then T\
O_NUMBER(DATA_1) else  case  when SUBSTR(A.MAT_DESC,1,4)='IPOL' then  case  w\
hen (((B.ATTR_VALUE like '%60.0%' or B.ATTR_VALUE like '%60.5%') or B.ATTR_VA\
LUE like '%75.0%') or B.ATTR_VALUE like '%75.7%') then 0.5 else 0  end  when \
SUBSTR(A.MAT_DESC,1,4)='IBON' then  case  when ((((B.ATTR_VALUE like '%55.0%'\
 or B.ATTR_VALUE like '%55.00%') or B.ATTR_VALUE like '%50.00%') or B.ATTR_VA\
LUE like '%60.0%') or B.ATTR_VALUE like '%50.0%') then 0 else 1  end  else 0.\
5  end   end  MINUS_VALUE into :b0  from MWIPMATDEF A ,MATRNAMSTS B ,MGCMTBLD\
AT C where (((((((((A.FACTORY=B.FACTORY(+) and B.ATTR_TYPE(+)='MATERIAL') and\
 B.ATTR_NAME(+)='CATALOG_VALUE20') and B.ATTR_KEY(+)=((A.MAT_ID||' : ')||'1')\
) and A.FACTORY=C.FACTORY(+)) and C.TABLE_NAME(+)='C_ROUND_CAL') and A.MAT_GR\
P_1=C.KEY_1(+)) and A.MAT_ID=C.KEY_2(+)) and A.MAT_ID=:b1) and A.MAT_VER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1372;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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

    DB_stop_query_timer("DBU_select_mwipmatdef_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPMATDEF  where ((FACTORY=:b0 and\
 MAT_ID=:b1) and MAT_VER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1399;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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

    DB_stop_query_timer("DBU_delete_mwipmatdef", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_mwipmatdef(struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MWIPMATDEF( 
                    FACTORY, 
                    MAT_ID, 
                    MAT_VER, 
                    MAT_DESC, 
                    MAT_TYPE, 
                    MAT_GRP_1, 
                    MAT_GRP_2, 
                    MAT_GRP_3, 
                    MAT_GRP_4, 
                    MAT_GRP_5, 
                    MAT_GRP_6, 
                    MAT_GRP_7, 
                    MAT_GRP_8, 
                    MAT_GRP_9, 
                    MAT_GRP_10, 
                    MAT_CMF_1, 
                    MAT_CMF_2, 
                    MAT_CMF_3, 
                    MAT_CMF_4, 
                    MAT_CMF_5, 
                    MAT_CMF_6, 
                    MAT_CMF_7, 
                    MAT_CMF_8, 
                    MAT_CMF_9, 
                    MAT_CMF_10, 
                    MAT_CMF_11, 
                    MAT_CMF_12, 
                    MAT_CMF_13, 
                    MAT_CMF_14, 
                    MAT_CMF_15, 
                    MAT_CMF_16, 
                    MAT_CMF_17, 
                    MAT_CMF_18, 
                    MAT_CMF_19, 
                    MAT_CMF_20, 
                    FIRST_FLOW, 
                    FIRST_FLOW_SEQ_NUM, 
                    LAST_FLOW, 
                    LAST_FLOW_SEQ_NUM, 
                    MFG_DEVISION, 
                    SUBCONTRACT_FLAG, 
                    BASE_MAT_ID, 
                    VENDOR_ID, 
                    VENDOR_MAT_ID, 
                    CUSTOMER_ID, 
                    CUSTOMER_MAT_ID, 
                    DEF_QTY_1, 
                    DEF_QTY_2, 
                    DEF_QTY_3, 
                    UNIT_1, 
                    UNIT_2, 
                    UNIT_3, 
                    WEIGHT_NET, 
                    WEIGHT_GROSS, 
                    WEIGHT_UNIT, 
                    VOLUME, 
                    VOLUME_UNIT, 
                    DIMENSION_HR, 
                    DIMENSION_HR_UNIT, 
                    DIMENSION_VT, 
                    DIMENSION_VT_UNIT, 
                    DIMENSION_HT, 
                    DIMENSION_HT_UNIT, 
                    BOM_SET_ID, 
                    DEF_INV_OPER, 
                    PACK_TYPE, 
                    PACK_LOT_COUNT, 
                    PACK_QTY, 
                    LE_STOCK_LEVEL, 
                    LW_STOCK_LEVEL, 
                    HW_STOCK_LEVEL, 
                    HE_STOCK_LEVEL, 
                    IQC_FLAG, 
                    IQC_SAMPLE_FLAG, 
                    IQC_SAMPLE_RULE, 
                    OQC_FLAG, 
                    OQC_SAMPLE_FLAG, 
                    OQC_SAMPLE_RULE, 
                    TARGET_YIELD, 
                    TARGET_DUE_DAY, 
                    TARGET_QTY_1, 
                    TARGET_QTY_2, 
                    TARGET_QTY_3, 
                    APPLY_START_TIME, 
                    APPLY_END_TIME, 
                    APPROVAL_FLAG, 
                    APPROVAL_USER_ID, 
                    APPROVAL_TIME, 
                    RELEASE_FLAG, 
                    RELEASE_USER_ID, 
                    RELEASE_TIME, 
                    DEACTIVE_FLAG, 
                    DEACTIVE_USER_ID, 
                    DEACTIVE_TIME, 
                    DELETE_FLAG, 
                    DELETE_USER_ID, 
                    DELETE_TIME, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    MAT_SHORT_DESC
         ) 
        VALUES (
                    :MWIPMATDEF_N.FACTORY,
                    :MWIPMATDEF_N.MAT_ID,
                    :MWIPMATDEF_N.MAT_VER,
                    :MWIPMATDEF_N.MAT_DESC,
                    :MWIPMATDEF_N.MAT_TYPE,
                    :MWIPMATDEF_N.MAT_GRP_1,
                    :MWIPMATDEF_N.MAT_GRP_2,
                    :MWIPMATDEF_N.MAT_GRP_3,
                    :MWIPMATDEF_N.MAT_GRP_4,
                    :MWIPMATDEF_N.MAT_GRP_5,
                    :MWIPMATDEF_N.MAT_GRP_6,
                    :MWIPMATDEF_N.MAT_GRP_7,
                    :MWIPMATDEF_N.MAT_GRP_8,
                    :MWIPMATDEF_N.MAT_GRP_9,
                    :MWIPMATDEF_N.MAT_GRP_10,
                    :MWIPMATDEF_N.MAT_CMF_1,
                    :MWIPMATDEF_N.MAT_CMF_2,
                    :MWIPMATDEF_N.MAT_CMF_3,
                    :MWIPMATDEF_N.MAT_CMF_4,
                    :MWIPMATDEF_N.MAT_CMF_5,
                    :MWIPMATDEF_N.MAT_CMF_6,
                    :MWIPMATDEF_N.MAT_CMF_7,
                    :MWIPMATDEF_N.MAT_CMF_8,
                    :MWIPMATDEF_N.MAT_CMF_9,
                    :MWIPMATDEF_N.MAT_CMF_10,
                    :MWIPMATDEF_N.MAT_CMF_11,
                    :MWIPMATDEF_N.MAT_CMF_12,
                    :MWIPMATDEF_N.MAT_CMF_13,
                    :MWIPMATDEF_N.MAT_CMF_14,
                    :MWIPMATDEF_N.MAT_CMF_15,
                    :MWIPMATDEF_N.MAT_CMF_16,
                    :MWIPMATDEF_N.MAT_CMF_17,
                    :MWIPMATDEF_N.MAT_CMF_18,
                    :MWIPMATDEF_N.MAT_CMF_19,
                    :MWIPMATDEF_N.MAT_CMF_20,
                    :MWIPMATDEF_N.FIRST_FLOW,
                    :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.LAST_FLOW,
                    :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                    :MWIPMATDEF_N.MFG_DEVISION,
                    :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                    :MWIPMATDEF_N.BASE_MAT_ID,
                    :MWIPMATDEF_N.VENDOR_ID,
                    :MWIPMATDEF_N.VENDOR_MAT_ID,
                    :MWIPMATDEF_N.CUSTOMER_ID,
                    :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                    :MWIPMATDEF_N.DEF_QTY_1,
                    :MWIPMATDEF_N.DEF_QTY_2,
                    :MWIPMATDEF_N.DEF_QTY_3,
                    :MWIPMATDEF_N.UNIT_1,
                    :MWIPMATDEF_N.UNIT_2,
                    :MWIPMATDEF_N.UNIT_3,
                    :MWIPMATDEF_N.WEIGHT_NET,
                    :MWIPMATDEF_N.WEIGHT_GROSS,
                    :MWIPMATDEF_N.WEIGHT_UNIT,
                    :MWIPMATDEF_N.VOLUME,
                    :MWIPMATDEF_N.VOLUME_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HR,
                    :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                    :MWIPMATDEF_N.DIMENSION_VT,
                    :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                    :MWIPMATDEF_N.DIMENSION_HT,
                    :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                    :MWIPMATDEF_N.BOM_SET_ID,
                    :MWIPMATDEF_N.DEF_INV_OPER,
                    :MWIPMATDEF_N.PACK_TYPE,
                    :MWIPMATDEF_N.PACK_LOT_COUNT,
                    :MWIPMATDEF_N.PACK_QTY,
                    :MWIPMATDEF_N.LE_STOCK_LEVEL,
                    :MWIPMATDEF_N.LW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HW_STOCK_LEVEL,
                    :MWIPMATDEF_N.HE_STOCK_LEVEL,
                    :MWIPMATDEF_N.IQC_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.OQC_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                    :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                    :MWIPMATDEF_N.TARGET_YIELD,
                    :MWIPMATDEF_N.TARGET_DUE_DAY,
                    :MWIPMATDEF_N.TARGET_QTY_1,
                    :MWIPMATDEF_N.TARGET_QTY_2,
                    :MWIPMATDEF_N.TARGET_QTY_3,
                    :MWIPMATDEF_N.APPLY_START_TIME,
                    :MWIPMATDEF_N.APPLY_END_TIME,
                    :MWIPMATDEF_N.APPROVAL_FLAG,
                    :MWIPMATDEF_N.APPROVAL_USER_ID,
                    :MWIPMATDEF_N.APPROVAL_TIME,
                    :MWIPMATDEF_N.RELEASE_FLAG,
                    :MWIPMATDEF_N.RELEASE_USER_ID,
                    :MWIPMATDEF_N.RELEASE_TIME,
                    :MWIPMATDEF_N.DEACTIVE_FLAG,
                    :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    :MWIPMATDEF_N.DEACTIVE_TIME,
                    :MWIPMATDEF_N.DELETE_FLAG,
                    :MWIPMATDEF_N.DELETE_USER_ID,
                    :MWIPMATDEF_N.DELETE_TIME,
                    :MWIPMATDEF_N.CREATE_USER_ID,
                    :MWIPMATDEF_N.CREATE_TIME,
                    :MWIPMATDEF_N.UPDATE_USER_ID,
                    :MWIPMATDEF_N.UPDATE_TIME,
                    :MWIPMATDEF_N.MAT_SHORT_DESC
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 105;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MWIPMATDEF (FACTORY,MAT_ID,MAT_VER,MAT_DESC,MAT_TYPE,MAT_\
GRP_1,MAT_GRP_2,MAT_GRP_3,MAT_GRP_4,MAT_GRP_5,MAT_GRP_6,MAT_GRP_7,MAT_GRP_8,\
MAT_GRP_9,MAT_GRP_10,MAT_CMF_1,MAT_CMF_2,MAT_CMF_3,MAT_CMF_4,MAT_CMF_5,MAT_C\
MF_6,MAT_CMF_7,MAT_CMF_8,MAT_CMF_9,MAT_CMF_10,MAT_CMF_11,MAT_CMF_12,MAT_CMF_\
13,MAT_CMF_14,MAT_CMF_15,MAT_CMF_16,MAT_CMF_17,MAT_CMF_18,MAT_CMF_19,MAT_CMF\
_20,FIRST_FLOW,FIRST_FLOW_SEQ_NUM,LAST_FLOW,LAST_FLOW_SEQ_NUM,MFG_DEVISION,S\
UBCONTRACT_FLAG,BASE_MAT_ID,VENDOR_ID,VENDOR_MAT_ID,CUSTOMER_ID,CUSTOMER_MAT\
_ID,DEF_QTY_1,DEF_QTY_2,DEF_QTY_3,UNIT_1,UNIT_2,UNIT_3,WEIGHT_NET,WEIGHT_GRO\
SS,WEIGHT_UNIT,VOLUME,VOLUME_UNIT,DIMENSION_HR,DIMENSION_HR_UNIT,DIMENSION_V\
T,DIMENSION_VT_UNIT,DIMENSION_HT,DIMENSION_HT_UNIT,BOM_SET_ID,DEF_INV_OPER,P\
ACK_TYPE,PACK_LOT_COUNT,PACK_QTY,LE_STOCK_LEVEL,LW_STOCK_LEVEL,HW_STOCK_LEVE\
L,HE_STOCK_LEVEL,IQC_FLAG,IQC_SAMPLE_FLAG,IQC_SAMPLE_RULE,OQC_FLAG,OQC_SAMPL\
E_FLAG,OQC_SAMPLE_RULE,TARGET_YIELD,TARGET_DUE_DAY,TARGET_QTY_1,TARGET_QTY_2\
,TARGET_QTY_3,APPLY_START_TIME,APPLY_END_TI");
    sqlstm.stmt = "ME,APPROVAL_FLAG,APPROVAL_USER_ID,APPROVAL_TIME,RELEASE_\
FLAG,RELEASE_USER_ID,RELEASE_TIME,DEACTIVE_FLAG,DEACTIVE_USER_ID,DEACTIVE_TIM\
E,DELETE_FLAG,DELETE_USER_ID,DELETE_TIME,CREATE_USER_ID,CREATE_TIME,UPDATE_US\
ER_ID,UPDATE_TIME,MAT_SHORT_DESC) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8\
,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b\
24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39\
,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:\
b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b7\
0,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,\
:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:\
b101)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1426;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
    sqlstm.sqhstl[35] = (unsigned int  )21;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
    sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
    sqlstm.sqhstl[37] = (unsigned int  )21;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
    sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
    sqlstm.sqhstl[39] = (unsigned int  )21;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
    sqlstm.sqhstl[40] = (unsigned int  )2;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
    sqlstm.sqhstl[42] = (unsigned int  )21;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
    sqlstm.sqhstl[43] = (unsigned int  )31;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
    sqlstm.sqhstl[44] = (unsigned int  )21;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
    sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
    sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
    sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MWIPMATDEF_N.UNIT_1);
    sqlstm.sqhstl[49] = (unsigned int  )11;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MWIPMATDEF_N.UNIT_2);
    sqlstm.sqhstl[50] = (unsigned int  )11;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.UNIT_3);
    sqlstm.sqhstl[51] = (unsigned int  )11;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
    sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
    sqlstm.sqhstl[53] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
    sqlstm.sqhstl[54] = (unsigned int  )11;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)&(MWIPMATDEF_N.VOLUME);
    sqlstm.sqhstl[55] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
    sqlstm.sqhstl[56] = (unsigned int  )11;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
    sqlstm.sqhstl[57] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
    sqlstm.sqhstl[58] = (unsigned int  )11;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
    sqlstm.sqhstl[59] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
    sqlstm.sqhstl[60] = (unsigned int  )11;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
    sqlstm.sqhstl[61] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
    sqlstm.sqhstl[62] = (unsigned int  )11;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
    sqlstm.sqhstl[63] = (unsigned int  )26;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
    sqlstm.sqhstl[64] = (unsigned int  )11;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
    sqlstm.sqhstl[65] = (unsigned int  )2;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
    sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
    sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
    sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
    sqlstm.sqhstl[69] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
    sqlstm.sqhstl[70] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
    sqlstm.sqhstl[71] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
    sqlstm.sqhstl[72] = (unsigned int  )2;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
    sqlstm.sqhstl[73] = (unsigned int  )2;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
    sqlstm.sqhstl[74] = (unsigned int  )2;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
    sqlstm.sqhstl[75] = (unsigned int  )2;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
    sqlstm.sqhstl[76] = (unsigned int  )2;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
    sqlstm.sqhstl[77] = (unsigned int  )2;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
    sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
    sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
    sqlstm.sqhstl[80] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
    sqlstm.sqhstl[81] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
    sqlstm.sqhstl[82] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
    sqlstm.sqhstl[83] = (unsigned int  )15;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
    sqlstm.sqhstl[84] = (unsigned int  )15;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
    sqlstm.sqhstl[85] = (unsigned int  )2;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
    sqlstm.sqhstl[86] = (unsigned int  )21;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
    sqlstm.sqhstl[87] = (unsigned int  )15;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
    sqlstm.sqhstl[88] = (unsigned int  )2;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
    sqlstm.sqhstl[89] = (unsigned int  )21;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
    sqlstm.sqhstl[90] = (unsigned int  )15;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
    sqlstm.sqhstl[91] = (unsigned int  )2;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
    sqlstm.sqhstl[92] = (unsigned int  )21;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
    sqlstm.sqhstl[93] = (unsigned int  )15;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
    sqlstm.sqhstl[94] = (unsigned int  )2;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
    sqlstm.sqhstl[95] = (unsigned int  )21;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
    sqlstm.sqhstl[96] = (unsigned int  )15;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[97] = (unsigned int  )21;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
    sqlstm.sqhstl[98] = (unsigned int  )15;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[99] = (unsigned int  )21;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[100] = (unsigned int  )15;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
    sqlstm.sqhstl[101] = (unsigned int  )51;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_mwipmatdef", 0);
}


/* SQL UPDATE Function */
void DBU_update_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MWIPMATDEF SET
                    MAT_DESC = :MWIPMATDEF_N.MAT_DESC,
                    MAT_TYPE = :MWIPMATDEF_N.MAT_TYPE,
                    MAT_GRP_1 = :MWIPMATDEF_N.MAT_GRP_1,
                    MAT_GRP_2 = :MWIPMATDEF_N.MAT_GRP_2,
                    MAT_GRP_3 = :MWIPMATDEF_N.MAT_GRP_3,
                    MAT_GRP_4 = :MWIPMATDEF_N.MAT_GRP_4,
                    MAT_GRP_5 = :MWIPMATDEF_N.MAT_GRP_5,
                    MAT_GRP_6 = :MWIPMATDEF_N.MAT_GRP_6,
                    MAT_GRP_7 = :MWIPMATDEF_N.MAT_GRP_7,
                    MAT_GRP_8 = :MWIPMATDEF_N.MAT_GRP_8,
                    MAT_GRP_9 = :MWIPMATDEF_N.MAT_GRP_9,
                    MAT_GRP_10 = :MWIPMATDEF_N.MAT_GRP_10,
                    MAT_CMF_1 = :MWIPMATDEF_N.MAT_CMF_1,
                    MAT_CMF_2 = :MWIPMATDEF_N.MAT_CMF_2,
                    MAT_CMF_3 = :MWIPMATDEF_N.MAT_CMF_3,
                    MAT_CMF_4 = :MWIPMATDEF_N.MAT_CMF_4,
                    MAT_CMF_5 = :MWIPMATDEF_N.MAT_CMF_5,
                    MAT_CMF_6 = :MWIPMATDEF_N.MAT_CMF_6,
                    MAT_CMF_7 = :MWIPMATDEF_N.MAT_CMF_7,
                    MAT_CMF_8 = :MWIPMATDEF_N.MAT_CMF_8,
                    MAT_CMF_9 = :MWIPMATDEF_N.MAT_CMF_9,
                    MAT_CMF_10 = :MWIPMATDEF_N.MAT_CMF_10,
                    MAT_CMF_11 = :MWIPMATDEF_N.MAT_CMF_11,
                    MAT_CMF_12 = :MWIPMATDEF_N.MAT_CMF_12,
                    MAT_CMF_13 = :MWIPMATDEF_N.MAT_CMF_13,
                    MAT_CMF_14 = :MWIPMATDEF_N.MAT_CMF_14,
                    MAT_CMF_15 = :MWIPMATDEF_N.MAT_CMF_15,
                    MAT_CMF_16 = :MWIPMATDEF_N.MAT_CMF_16,
                    MAT_CMF_17 = :MWIPMATDEF_N.MAT_CMF_17,
                    MAT_CMF_18 = :MWIPMATDEF_N.MAT_CMF_18,
                    MAT_CMF_19 = :MWIPMATDEF_N.MAT_CMF_19,
                    MAT_CMF_20 = :MWIPMATDEF_N.MAT_CMF_20,
                    FIRST_FLOW = :MWIPMATDEF_N.FIRST_FLOW,
                    FIRST_FLOW_SEQ_NUM = :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                    LAST_FLOW = :MWIPMATDEF_N.LAST_FLOW,
                    LAST_FLOW_SEQ_NUM = :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                    MFG_DEVISION = :MWIPMATDEF_N.MFG_DEVISION,
                    SUBCONTRACT_FLAG = :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                    BASE_MAT_ID = :MWIPMATDEF_N.BASE_MAT_ID,
                    VENDOR_ID = :MWIPMATDEF_N.VENDOR_ID,
                    VENDOR_MAT_ID = :MWIPMATDEF_N.VENDOR_MAT_ID,
                    CUSTOMER_ID = :MWIPMATDEF_N.CUSTOMER_ID,
                    CUSTOMER_MAT_ID = :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                    DEF_QTY_1 = :MWIPMATDEF_N.DEF_QTY_1,
                    DEF_QTY_2 = :MWIPMATDEF_N.DEF_QTY_2,
                    DEF_QTY_3 = :MWIPMATDEF_N.DEF_QTY_3,
                    UNIT_1 = :MWIPMATDEF_N.UNIT_1,
                    UNIT_2 = :MWIPMATDEF_N.UNIT_2,
                    UNIT_3 = :MWIPMATDEF_N.UNIT_3,
                    WEIGHT_NET = :MWIPMATDEF_N.WEIGHT_NET,
                    WEIGHT_GROSS = :MWIPMATDEF_N.WEIGHT_GROSS,
                    WEIGHT_UNIT = :MWIPMATDEF_N.WEIGHT_UNIT,
                    VOLUME = :MWIPMATDEF_N.VOLUME,
                    VOLUME_UNIT = :MWIPMATDEF_N.VOLUME_UNIT,
                    DIMENSION_HR = :MWIPMATDEF_N.DIMENSION_HR,
                    DIMENSION_HR_UNIT = :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                    DIMENSION_VT = :MWIPMATDEF_N.DIMENSION_VT,
                    DIMENSION_VT_UNIT = :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                    DIMENSION_HT = :MWIPMATDEF_N.DIMENSION_HT,
                    DIMENSION_HT_UNIT = :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                    BOM_SET_ID = :MWIPMATDEF_N.BOM_SET_ID,
                    DEF_INV_OPER = :MWIPMATDEF_N.DEF_INV_OPER,
                    PACK_TYPE = :MWIPMATDEF_N.PACK_TYPE,
                    PACK_LOT_COUNT = :MWIPMATDEF_N.PACK_LOT_COUNT,
                    PACK_QTY = :MWIPMATDEF_N.PACK_QTY,
                    LE_STOCK_LEVEL = :MWIPMATDEF_N.LE_STOCK_LEVEL,
                    LW_STOCK_LEVEL = :MWIPMATDEF_N.LW_STOCK_LEVEL,
                    HW_STOCK_LEVEL = :MWIPMATDEF_N.HW_STOCK_LEVEL,
                    HE_STOCK_LEVEL = :MWIPMATDEF_N.HE_STOCK_LEVEL,
                    IQC_FLAG = :MWIPMATDEF_N.IQC_FLAG,
                    IQC_SAMPLE_FLAG = :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                    IQC_SAMPLE_RULE = :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                    OQC_FLAG = :MWIPMATDEF_N.OQC_FLAG,
                    OQC_SAMPLE_FLAG = :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                    OQC_SAMPLE_RULE = :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                    TARGET_YIELD = :MWIPMATDEF_N.TARGET_YIELD,
                    TARGET_DUE_DAY = :MWIPMATDEF_N.TARGET_DUE_DAY,
                    TARGET_QTY_1 = :MWIPMATDEF_N.TARGET_QTY_1,
                    TARGET_QTY_2 = :MWIPMATDEF_N.TARGET_QTY_2,
                    TARGET_QTY_3 = :MWIPMATDEF_N.TARGET_QTY_3,
                    APPLY_START_TIME = :MWIPMATDEF_N.APPLY_START_TIME,
                    APPLY_END_TIME = :MWIPMATDEF_N.APPLY_END_TIME,
                    APPROVAL_FLAG = :MWIPMATDEF_N.APPROVAL_FLAG,
                    APPROVAL_USER_ID = :MWIPMATDEF_N.APPROVAL_USER_ID,
                    APPROVAL_TIME = :MWIPMATDEF_N.APPROVAL_TIME,
                    RELEASE_FLAG = :MWIPMATDEF_N.RELEASE_FLAG,
                    RELEASE_USER_ID = :MWIPMATDEF_N.RELEASE_USER_ID,
                    RELEASE_TIME = :MWIPMATDEF_N.RELEASE_TIME,
                    DEACTIVE_FLAG = :MWIPMATDEF_N.DEACTIVE_FLAG,
                    DEACTIVE_USER_ID = :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    DEACTIVE_TIME = :MWIPMATDEF_N.DEACTIVE_TIME,
                    DELETE_FLAG = :MWIPMATDEF_N.DELETE_FLAG,
                    DELETE_USER_ID = :MWIPMATDEF_N.DELETE_USER_ID,
                    DELETE_TIME = :MWIPMATDEF_N.DELETE_TIME,
                    CREATE_USER_ID = :MWIPMATDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MWIPMATDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MWIPMATDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPMATDEF_N.UPDATE_TIME,
                    MAT_SHORT_DESC = :MWIPMATDEF_N.MAT_SHORT_DESC
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MWIPMATDEF  set MAT_DESC=:b0,MAT_TYPE=:b1,MAT_GRP_1=:b\
2,MAT_GRP_2=:b3,MAT_GRP_3=:b4,MAT_GRP_4=:b5,MAT_GRP_5=:b6,MAT_GRP_6=:b7,MAT_\
GRP_7=:b8,MAT_GRP_8=:b9,MAT_GRP_9=:b10,MAT_GRP_10=:b11,MAT_CMF_1=:b12,MAT_CM\
F_2=:b13,MAT_CMF_3=:b14,MAT_CMF_4=:b15,MAT_CMF_5=:b16,MAT_CMF_6=:b17,MAT_CMF\
_7=:b18,MAT_CMF_8=:b19,MAT_CMF_9=:b20,MAT_CMF_10=:b21,MAT_CMF_11=:b22,MAT_CM\
F_12=:b23,MAT_CMF_13=:b24,MAT_CMF_14=:b25,MAT_CMF_15=:b26,MAT_CMF_16=:b27,MA\
T_CMF_17=:b28,MAT_CMF_18=:b29,MAT_CMF_19=:b30,MAT_CMF_20=:b31,FIRST_FLOW=:b3\
2,FIRST_FLOW_SEQ_NUM=:b33,LAST_FLOW=:b34,LAST_FLOW_SEQ_NUM=:b35,MFG_DEVISION\
=:b36,SUBCONTRACT_FLAG=:b37,BASE_MAT_ID=:b38,VENDOR_ID=:b39,VENDOR_MAT_ID=:b\
40,CUSTOMER_ID=:b41,CUSTOMER_MAT_ID=:b42,DEF_QTY_1=:b43,DEF_QTY_2=:b44,DEF_Q\
TY_3=:b45,UNIT_1=:b46,UNIT_2=:b47,UNIT_3=:b48,WEIGHT_NET=:b49,WEIGHT_GROSS=:\
b50,WEIGHT_UNIT=:b51,VOLUME=:b52,VOLUME_UNIT=:b53,DIMENSION_HR=:b54,DIMENSIO\
N_HR_UNIT=:b55,DIMENSION_VT=:b56,DIMENSION_VT_UNIT=:b57,DIMENSION_HT=:b58,DI\
MENSION_HT_UNIT=:b59,BOM_SET_ID=:b60,DEF_INV_OPER=:");
            sqlstm.stmt = "b61,PACK_TYPE=:b62,PACK_LOT_COUNT=:b63,PACK_QTY=\
:b64,LE_STOCK_LEVEL=:b65,LW_STOCK_LEVEL=:b66,HW_STOCK_LEVEL=:b67,HE_STOCK_LEV\
EL=:b68,IQC_FLAG=:b69,IQC_SAMPLE_FLAG=:b70,IQC_SAMPLE_RULE=:b71,OQC_FLAG=:b72\
,OQC_SAMPLE_FLAG=:b73,OQC_SAMPLE_RULE=:b74,TARGET_YIELD=:b75,TARGET_DUE_DAY=:\
b76,TARGET_QTY_1=:b77,TARGET_QTY_2=:b78,TARGET_QTY_3=:b79,APPLY_START_TIME=:b\
80,APPLY_END_TIME=:b81,APPROVAL_FLAG=:b82,APPROVAL_USER_ID=:b83,APPROVAL_TIME\
=:b84,RELEASE_FLAG=:b85,RELEASE_USER_ID=:b86,RELEASE_TIME=:b87,DEACTIVE_FLAG=\
:b88,DEACTIVE_USER_ID=:b89,DEACTIVE_TIME=:b90,DELETE_FLAG=:b91,DELETE_USER_ID\
=:b92,DELETE_TIME=:b93,CREATE_USER_ID=:b94,CREATE_TIME=:b95,UPDATE_USER_ID=:b\
96,UPDATE_TIME=:b97,MAT_SHORT_DESC=:b98 where ((FACTORY=:b99 and MAT_ID=:b100\
) and MAT_VER=:b101)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1849;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[33] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
            sqlstm.sqhstl[45] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MWIPMATDEF_N.UNIT_1);
            sqlstm.sqhstl[46] = (unsigned int  )11;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MWIPMATDEF_N.UNIT_2);
            sqlstm.sqhstl[47] = (unsigned int  )11;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MWIPMATDEF_N.UNIT_3);
            sqlstm.sqhstl[48] = (unsigned int  )11;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.VOLUME);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
            sqlstm.sqhstl[53] = (unsigned int  )11;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
            sqlstm.sqhstl[55] = (unsigned int  )11;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
            sqlstm.sqhstl[57] = (unsigned int  )11;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
            sqlstm.sqhstl[59] = (unsigned int  )11;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
            sqlstm.sqhstl[60] = (unsigned int  )26;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
            sqlstm.sqhstl[61] = (unsigned int  )11;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
            sqlstm.sqhstl[63] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
            sqlstm.sqhstl[70] = (unsigned int  )2;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
            sqlstm.sqhstl[71] = (unsigned int  )2;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
            sqlstm.sqhstl[75] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
            sqlstm.sqhstl[76] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
            sqlstm.sqhstl[77] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
            sqlstm.sqhstl[80] = (unsigned int  )15;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
            sqlstm.sqhstl[81] = (unsigned int  )15;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
            sqlstm.sqhstl[82] = (unsigned int  )2;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
            sqlstm.sqhstl[85] = (unsigned int  )2;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[90] = (unsigned int  )15;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[93] = (unsigned int  )15;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
            sqlstm.sqhstl[95] = (unsigned int  )15;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[96] = (unsigned int  )21;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[97] = (unsigned int  )15;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
            sqlstm.sqhstl[98] = (unsigned int  )51;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[99] = (unsigned int  )11;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[101] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
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
            /* EXEC SQL UPDATE MWIPMATDEF SET                   
                    MAT_CMF_5 = :MWIPMATDEF_N.MAT_CMF_5,
                    MAT_CMF_6 = :MWIPMATDEF_N.MAT_CMF_6,
					UPDATE_USER_ID = :MWIPMATDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPMATDEF_N.UPDATE_TIME             
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPMATDEF  set MAT_CMF_5=:b0,MAT_CMF_6=:\
b1,UPDATE_USER_ID=:b2,UPDATE_TIME=:b3 where ((FACTORY=:b4 and MAT_ID=:b5) and\
 MAT_VER=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2272;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[0] = (unsigned int  )31;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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

    DB_stop_query_timer("DBU_update_mwipmatdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MWIPMATDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    MAT_DESC,
                    MAT_TYPE,
                    MAT_GRP_1,
                    MAT_GRP_2,
                    MAT_GRP_3,
                    MAT_GRP_4,
                    MAT_GRP_5,
                    MAT_GRP_6,
                    MAT_GRP_7,
                    MAT_GRP_8,
                    MAT_GRP_9,
                    MAT_GRP_10,
                    MAT_CMF_1,
                    MAT_CMF_2,
                    MAT_CMF_3,
                    MAT_CMF_4,
                    MAT_CMF_5,
                    MAT_CMF_6,
                    MAT_CMF_7,
                    MAT_CMF_8,
                    MAT_CMF_9,
                    MAT_CMF_10,
                    MAT_CMF_11,
                    MAT_CMF_12,
                    MAT_CMF_13,
                    MAT_CMF_14,
                    MAT_CMF_15,
                    MAT_CMF_16,
                    MAT_CMF_17,
                    MAT_CMF_18,
                    MAT_CMF_19,
                    MAT_CMF_20,
                    FIRST_FLOW,
                    FIRST_FLOW_SEQ_NUM,
                    LAST_FLOW,
                    LAST_FLOW_SEQ_NUM,
                    MFG_DEVISION,
                    SUBCONTRACT_FLAG,
                    BASE_MAT_ID,
                    VENDOR_ID,
                    VENDOR_MAT_ID,
                    CUSTOMER_ID,
                    CUSTOMER_MAT_ID,
                    DEF_QTY_1,
                    DEF_QTY_2,
                    DEF_QTY_3,
                    UNIT_1,
                    UNIT_2,
                    UNIT_3,
                    WEIGHT_NET,
                    WEIGHT_GROSS,
                    WEIGHT_UNIT,
                    VOLUME,
                    VOLUME_UNIT,
                    DIMENSION_HR,
                    DIMENSION_HR_UNIT,
                    DIMENSION_VT,
                    DIMENSION_VT_UNIT,
                    DIMENSION_HT,
                    DIMENSION_HT_UNIT,
                    BOM_SET_ID,
                    DEF_INV_OPER,
                    PACK_TYPE,
                    PACK_LOT_COUNT,
                    PACK_QTY,
                    LE_STOCK_LEVEL,
                    LW_STOCK_LEVEL,
                    HW_STOCK_LEVEL,
                    HE_STOCK_LEVEL,
                    IQC_FLAG,
                    IQC_SAMPLE_FLAG,
                    IQC_SAMPLE_RULE,
                    OQC_FLAG,
                    OQC_SAMPLE_FLAG,
                    OQC_SAMPLE_RULE,
                    TARGET_YIELD,
                    TARGET_DUE_DAY,
                    TARGET_QTY_1,
                    TARGET_QTY_2,
                    TARGET_QTY_3,
                    APPLY_START_TIME,
                    APPLY_END_TIME,
                    APPROVAL_FLAG,
                    APPROVAL_USER_ID,
                    APPROVAL_TIME,
                    RELEASE_FLAG,
                    RELEASE_USER_ID,
                    RELEASE_TIME,
                    DEACTIVE_FLAG,
                    DEACTIVE_USER_ID,
                    DEACTIVE_TIME,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    MAT_SHORT_DESC
                FROM MWIPMATDEF
                ORDER BY FACTORY ASC,
                    MAT_ID ASC,
                    MAT_VER ASC; */ 

            /* EXEC SQL OPEN DBU_MWIPMATDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,MAT_DESC ,MAT_TYPE ,MAT_GRP_\
1 ,MAT_GRP_2 ,MAT_GRP_3 ,MAT_GRP_4 ,MAT_GRP_5 ,MAT_GRP_6 ,MAT_GRP_7 ,MAT_GRP\
_8 ,MAT_GRP_9 ,MAT_GRP_10 ,MAT_CMF_1 ,MAT_CMF_2 ,MAT_CMF_3 ,MAT_CMF_4 ,MAT_C\
MF_5 ,MAT_CMF_6 ,MAT_CMF_7 ,MAT_CMF_8 ,MAT_CMF_9 ,MAT_CMF_10 ,MAT_CMF_11 ,MA\
T_CMF_12 ,MAT_CMF_13 ,MAT_CMF_14 ,MAT_CMF_15 ,MAT_CMF_16 ,MAT_CMF_17 ,MAT_CM\
F_18 ,MAT_CMF_19 ,MAT_CMF_20 ,FIRST_FLOW ,FIRST_FLOW_SEQ_NUM ,LAST_FLOW ,LAS\
T_FLOW_SEQ_NUM ,MFG_DEVISION ,SUBCONTRACT_FLAG ,BASE_MAT_ID ,VENDOR_ID ,VEND\
OR_MAT_ID ,CUSTOMER_ID ,CUSTOMER_MAT_ID ,DEF_QTY_1 ,DEF_QTY_2 ,DEF_QTY_3 ,UN\
IT_1 ,UNIT_2 ,UNIT_3 ,WEIGHT_NET ,WEIGHT_GROSS ,WEIGHT_UNIT ,VOLUME ,VOLUME_\
UNIT ,DIMENSION_HR ,DIMENSION_HR_UNIT ,DIMENSION_VT ,DIMENSION_VT_UNIT ,DIME\
NSION_HT ,DIMENSION_HT_UNIT ,BOM_SET_ID ,DEF_INV_OPER ,PACK_TYPE ,PACK_LOT_C\
OUNT ,PACK_QTY ,LE_STOCK_LEVEL ,LW_STOCK_LEVEL ,HW_STOCK_LEVEL ,HE_STOCK_LEV\
EL ,IQC_FLAG ,IQC_SAMPLE_FLAG ,IQC_SAMPLE_RULE ,OQC_FLAG ,OQC_SAMPLE_FLAG ,O\
QC_SAMPLE_RULE ,TARGET_YIELD ,TARGET_DUE_DAY ,TARGE");
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2315;
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
            /* EXEC SQL DECLARE DBU_MWIPMATDEF_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    MAT_ID,
                    MAT_VER,
                    MAT_DESC,
                    MAT_TYPE,
                    MAT_GRP_1,
                    MAT_GRP_2,
                    MAT_GRP_3,
                    MAT_GRP_4,
                    MAT_GRP_5,
                    MAT_GRP_6,
                    MAT_GRP_7,
                    MAT_GRP_8,
                    MAT_GRP_9,
                    MAT_GRP_10,
                    MAT_CMF_1,
                    MAT_CMF_2,
                    MAT_CMF_3,
                    MAT_CMF_4,
                    MAT_CMF_5,
                    MAT_CMF_6,
                    MAT_CMF_7,
                    MAT_CMF_8,
                    MAT_CMF_9,
                    MAT_CMF_10,
                    MAT_CMF_11,
                    MAT_CMF_12,
                    MAT_CMF_13,
                    MAT_CMF_14,
                    MAT_CMF_15,
                    MAT_CMF_16,
                    MAT_CMF_17,
                    MAT_CMF_18,
                    MAT_CMF_19,
                    MAT_CMF_20,
                    FIRST_FLOW,
                    FIRST_FLOW_SEQ_NUM,
                    LAST_FLOW,
                    LAST_FLOW_SEQ_NUM,
                    MFG_DEVISION,
                    SUBCONTRACT_FLAG,
                    BASE_MAT_ID,
                    VENDOR_ID,
                    VENDOR_MAT_ID,
                    CUSTOMER_ID,
                    CUSTOMER_MAT_ID,
                    DEF_QTY_1,
                    DEF_QTY_2,
                    DEF_QTY_3,
                    UNIT_1,
                    UNIT_2,
                    UNIT_3,
                    WEIGHT_NET,
                    WEIGHT_GROSS,
                    WEIGHT_UNIT,
                    VOLUME,
                    VOLUME_UNIT,
                    DIMENSION_HR,
                    DIMENSION_HR_UNIT,
                    DIMENSION_VT,
                    DIMENSION_VT_UNIT,
                    DIMENSION_HT,
                    DIMENSION_HT_UNIT,
                    BOM_SET_ID,
                    DEF_INV_OPER,
                    PACK_TYPE,
                    PACK_LOT_COUNT,
                    PACK_QTY,
                    LE_STOCK_LEVEL,
                    LW_STOCK_LEVEL,
                    HW_STOCK_LEVEL,
                    HE_STOCK_LEVEL,
                    IQC_FLAG,
                    IQC_SAMPLE_FLAG,
                    IQC_SAMPLE_RULE,
                    OQC_FLAG,
                    OQC_SAMPLE_FLAG,
                    OQC_SAMPLE_RULE,
                    TARGET_YIELD,
                    TARGET_DUE_DAY,
                    TARGET_QTY_1,
                    TARGET_QTY_2,
                    TARGET_QTY_3,
                    APPLY_START_TIME,
                    APPLY_END_TIME,
                    APPROVAL_FLAG,
                    APPROVAL_USER_ID,
                    APPROVAL_TIME,
                    RELEASE_FLAG,
                    RELEASE_USER_ID,
                    RELEASE_TIME,
                    DEACTIVE_FLAG,
                    DEACTIVE_USER_ID,
                    DEACTIVE_TIME,
                    DELETE_FLAG,
                    DELETE_USER_ID,
                    DELETE_TIME,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    MAT_SHORT_DESC
				FROM (SELECT *
					  FROM MWIPMATDEF
					  WHERE FACTORY = :MWIPMATDEF_N.FACTORY 
					   AND MAT_GRP_1 = :MWIPMATDEF_N.MAT_GRP_1
					  UNION
					  SELECT *
					  FROM MWIPMATDEF
                      WHERE FACTORY = :MWIPMATDEF_N.FACTORY 
					   AND MAT_GRP_1 = ' ')
				ORDER BY FACTORY ASC, 
						 MAT_ID ASC, 
						 MAT_VER ASC; */ 

            /* EXEC SQL OPEN DBU_MWIPMATDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,MAT_ID ,MAT_VER ,MAT_DESC ,MAT_TYPE ,MAT_GRP_\
1 ,MAT_GRP_2 ,MAT_GRP_3 ,MAT_GRP_4 ,MAT_GRP_5 ,MAT_GRP_6 ,MAT_GRP_7 ,MAT_GRP\
_8 ,MAT_GRP_9 ,MAT_GRP_10 ,MAT_CMF_1 ,MAT_CMF_2 ,MAT_CMF_3 ,MAT_CMF_4 ,MAT_C\
MF_5 ,MAT_CMF_6 ,MAT_CMF_7 ,MAT_CMF_8 ,MAT_CMF_9 ,MAT_CMF_10 ,MAT_CMF_11 ,MA\
T_CMF_12 ,MAT_CMF_13 ,MAT_CMF_14 ,MAT_CMF_15 ,MAT_CMF_16 ,MAT_CMF_17 ,MAT_CM\
F_18 ,MAT_CMF_19 ,MAT_CMF_20 ,FIRST_FLOW ,FIRST_FLOW_SEQ_NUM ,LAST_FLOW ,LAS\
T_FLOW_SEQ_NUM ,MFG_DEVISION ,SUBCONTRACT_FLAG ,BASE_MAT_ID ,VENDOR_ID ,VEND\
OR_MAT_ID ,CUSTOMER_ID ,CUSTOMER_MAT_ID ,DEF_QTY_1 ,DEF_QTY_2 ,DEF_QTY_3 ,UN\
IT_1 ,UNIT_2 ,UNIT_3 ,WEIGHT_NET ,WEIGHT_GROSS ,WEIGHT_UNIT ,VOLUME ,VOLUME_\
UNIT ,DIMENSION_HR ,DIMENSION_HR_UNIT ,DIMENSION_VT ,DIMENSION_VT_UNIT ,DIME\
NSION_HT ,DIMENSION_HT_UNIT ,BOM_SET_ID ,DEF_INV_OPER ,PACK_TYPE ,PACK_LOT_C\
OUNT ,PACK_QTY ,LE_STOCK_LEVEL ,LW_STOCK_LEVEL ,HW_STOCK_LEVEL ,HE_STOCK_LEV\
EL ,IQC_FLAG ,IQC_SAMPLE_FLAG ,IQC_SAMPLE_RULE ,OQC_FLAG ,OQC_SAMPLE_FLAG ,O\
QC_SAMPLE_RULE ,TARGET_YIELD ,TARGET_DUE_DAY ,TARGE");
            sqlstm.stmt = sq0012;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2330;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.FACTORY);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_mwipmatdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MWIPMATDEF_CUR_1 INTO
                :MWIPMATDEF_N.FACTORY,
                :MWIPMATDEF_N.MAT_ID,
                :MWIPMATDEF_N.MAT_VER,
                :MWIPMATDEF_N.MAT_DESC,
                :MWIPMATDEF_N.MAT_TYPE,
                :MWIPMATDEF_N.MAT_GRP_1,
                :MWIPMATDEF_N.MAT_GRP_2,
                :MWIPMATDEF_N.MAT_GRP_3,
                :MWIPMATDEF_N.MAT_GRP_4,
                :MWIPMATDEF_N.MAT_GRP_5,
                :MWIPMATDEF_N.MAT_GRP_6,
                :MWIPMATDEF_N.MAT_GRP_7,
                :MWIPMATDEF_N.MAT_GRP_8,
                :MWIPMATDEF_N.MAT_GRP_9,
                :MWIPMATDEF_N.MAT_GRP_10,
                :MWIPMATDEF_N.MAT_CMF_1,
                :MWIPMATDEF_N.MAT_CMF_2,
                :MWIPMATDEF_N.MAT_CMF_3,
                :MWIPMATDEF_N.MAT_CMF_4,
                :MWIPMATDEF_N.MAT_CMF_5,
                :MWIPMATDEF_N.MAT_CMF_6,
                :MWIPMATDEF_N.MAT_CMF_7,
                :MWIPMATDEF_N.MAT_CMF_8,
                :MWIPMATDEF_N.MAT_CMF_9,
                :MWIPMATDEF_N.MAT_CMF_10,
                :MWIPMATDEF_N.MAT_CMF_11,
                :MWIPMATDEF_N.MAT_CMF_12,
                :MWIPMATDEF_N.MAT_CMF_13,
                :MWIPMATDEF_N.MAT_CMF_14,
                :MWIPMATDEF_N.MAT_CMF_15,
                :MWIPMATDEF_N.MAT_CMF_16,
                :MWIPMATDEF_N.MAT_CMF_17,
                :MWIPMATDEF_N.MAT_CMF_18,
                :MWIPMATDEF_N.MAT_CMF_19,
                :MWIPMATDEF_N.MAT_CMF_20,
                :MWIPMATDEF_N.FIRST_FLOW,
                :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                :MWIPMATDEF_N.LAST_FLOW,
                :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                :MWIPMATDEF_N.MFG_DEVISION,
                :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                :MWIPMATDEF_N.BASE_MAT_ID,
                :MWIPMATDEF_N.VENDOR_ID,
                :MWIPMATDEF_N.VENDOR_MAT_ID,
                :MWIPMATDEF_N.CUSTOMER_ID,
                :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                :MWIPMATDEF_N.DEF_QTY_1,
                :MWIPMATDEF_N.DEF_QTY_2,
                :MWIPMATDEF_N.DEF_QTY_3,
                :MWIPMATDEF_N.UNIT_1,
                :MWIPMATDEF_N.UNIT_2,
                :MWIPMATDEF_N.UNIT_3,
                :MWIPMATDEF_N.WEIGHT_NET,
                :MWIPMATDEF_N.WEIGHT_GROSS,
                :MWIPMATDEF_N.WEIGHT_UNIT,
                :MWIPMATDEF_N.VOLUME,
                :MWIPMATDEF_N.VOLUME_UNIT,
                :MWIPMATDEF_N.DIMENSION_HR,
                :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                :MWIPMATDEF_N.DIMENSION_VT,
                :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                :MWIPMATDEF_N.DIMENSION_HT,
                :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                :MWIPMATDEF_N.BOM_SET_ID,
                :MWIPMATDEF_N.DEF_INV_OPER,
                :MWIPMATDEF_N.PACK_TYPE,
                :MWIPMATDEF_N.PACK_LOT_COUNT,
                :MWIPMATDEF_N.PACK_QTY,
                :MWIPMATDEF_N.LE_STOCK_LEVEL,
                :MWIPMATDEF_N.LW_STOCK_LEVEL,
                :MWIPMATDEF_N.HW_STOCK_LEVEL,
                :MWIPMATDEF_N.HE_STOCK_LEVEL,
                :MWIPMATDEF_N.IQC_FLAG,
                :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                :MWIPMATDEF_N.OQC_FLAG,
                :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                :MWIPMATDEF_N.TARGET_YIELD,
                :MWIPMATDEF_N.TARGET_DUE_DAY,
                :MWIPMATDEF_N.TARGET_QTY_1,
                :MWIPMATDEF_N.TARGET_QTY_2,
                :MWIPMATDEF_N.TARGET_QTY_3,
                :MWIPMATDEF_N.APPLY_START_TIME,
                :MWIPMATDEF_N.APPLY_END_TIME,
                :MWIPMATDEF_N.APPROVAL_FLAG,
                :MWIPMATDEF_N.APPROVAL_USER_ID,
                :MWIPMATDEF_N.APPROVAL_TIME,
                :MWIPMATDEF_N.RELEASE_FLAG,
                :MWIPMATDEF_N.RELEASE_USER_ID,
                :MWIPMATDEF_N.RELEASE_TIME,
                :MWIPMATDEF_N.DEACTIVE_FLAG,
                :MWIPMATDEF_N.DEACTIVE_USER_ID,
                :MWIPMATDEF_N.DEACTIVE_TIME,
                :MWIPMATDEF_N.DELETE_FLAG,
                :MWIPMATDEF_N.DELETE_USER_ID,
                :MWIPMATDEF_N.DELETE_TIME,
                :MWIPMATDEF_N.CREATE_USER_ID,
                :MWIPMATDEF_N.CREATE_TIME,
                :MWIPMATDEF_N.UPDATE_USER_ID,
                :MWIPMATDEF_N.UPDATE_TIME,
                :MWIPMATDEF_N.MAT_SHORT_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2357;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMATDEF_N.UNIT_1);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMATDEF_N.UNIT_2);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.UNIT_3);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MWIPMATDEF_N.VOLUME);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
            sqlstm.sqhstl[62] = (unsigned int  )11;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
            sqlstm.sqhstl[64] = (unsigned int  )11;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
            sqlstm.sqhstl[71] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
            sqlstm.sqhstl[85] = (unsigned int  )2;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
            sqlstm.sqhstl[90] = (unsigned int  )15;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[93] = (unsigned int  )15;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[94] = (unsigned int  )2;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[96] = (unsigned int  )15;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
            sqlstm.sqhstl[98] = (unsigned int  )15;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[100] = (unsigned int  )15;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
            sqlstm.sqhstl[101] = (unsigned int  )51;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_MWIPMATDEF_CUR_2 INTO
                :MWIPMATDEF_N.FACTORY,
                :MWIPMATDEF_N.MAT_ID,
                :MWIPMATDEF_N.MAT_VER,
                :MWIPMATDEF_N.MAT_DESC,
                :MWIPMATDEF_N.MAT_TYPE,
                :MWIPMATDEF_N.MAT_GRP_1,
                :MWIPMATDEF_N.MAT_GRP_2,
                :MWIPMATDEF_N.MAT_GRP_3,
                :MWIPMATDEF_N.MAT_GRP_4,
                :MWIPMATDEF_N.MAT_GRP_5,
                :MWIPMATDEF_N.MAT_GRP_6,
                :MWIPMATDEF_N.MAT_GRP_7,
                :MWIPMATDEF_N.MAT_GRP_8,
                :MWIPMATDEF_N.MAT_GRP_9,
                :MWIPMATDEF_N.MAT_GRP_10,
                :MWIPMATDEF_N.MAT_CMF_1,
                :MWIPMATDEF_N.MAT_CMF_2,
                :MWIPMATDEF_N.MAT_CMF_3,
                :MWIPMATDEF_N.MAT_CMF_4,
                :MWIPMATDEF_N.MAT_CMF_5,
                :MWIPMATDEF_N.MAT_CMF_6,
                :MWIPMATDEF_N.MAT_CMF_7,
                :MWIPMATDEF_N.MAT_CMF_8,
                :MWIPMATDEF_N.MAT_CMF_9,
                :MWIPMATDEF_N.MAT_CMF_10,
                :MWIPMATDEF_N.MAT_CMF_11,
                :MWIPMATDEF_N.MAT_CMF_12,
                :MWIPMATDEF_N.MAT_CMF_13,
                :MWIPMATDEF_N.MAT_CMF_14,
                :MWIPMATDEF_N.MAT_CMF_15,
                :MWIPMATDEF_N.MAT_CMF_16,
                :MWIPMATDEF_N.MAT_CMF_17,
                :MWIPMATDEF_N.MAT_CMF_18,
                :MWIPMATDEF_N.MAT_CMF_19,
                :MWIPMATDEF_N.MAT_CMF_20,
                :MWIPMATDEF_N.FIRST_FLOW,
                :MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM,
                :MWIPMATDEF_N.LAST_FLOW,
                :MWIPMATDEF_N.LAST_FLOW_SEQ_NUM,
                :MWIPMATDEF_N.MFG_DEVISION,
                :MWIPMATDEF_N.SUBCONTRACT_FLAG,
                :MWIPMATDEF_N.BASE_MAT_ID,
                :MWIPMATDEF_N.VENDOR_ID,
                :MWIPMATDEF_N.VENDOR_MAT_ID,
                :MWIPMATDEF_N.CUSTOMER_ID,
                :MWIPMATDEF_N.CUSTOMER_MAT_ID,
                :MWIPMATDEF_N.DEF_QTY_1,
                :MWIPMATDEF_N.DEF_QTY_2,
                :MWIPMATDEF_N.DEF_QTY_3,
                :MWIPMATDEF_N.UNIT_1,
                :MWIPMATDEF_N.UNIT_2,
                :MWIPMATDEF_N.UNIT_3,
                :MWIPMATDEF_N.WEIGHT_NET,
                :MWIPMATDEF_N.WEIGHT_GROSS,
                :MWIPMATDEF_N.WEIGHT_UNIT,
                :MWIPMATDEF_N.VOLUME,
                :MWIPMATDEF_N.VOLUME_UNIT,
                :MWIPMATDEF_N.DIMENSION_HR,
                :MWIPMATDEF_N.DIMENSION_HR_UNIT,
                :MWIPMATDEF_N.DIMENSION_VT,
                :MWIPMATDEF_N.DIMENSION_VT_UNIT,
                :MWIPMATDEF_N.DIMENSION_HT,
                :MWIPMATDEF_N.DIMENSION_HT_UNIT,
                :MWIPMATDEF_N.BOM_SET_ID,
                :MWIPMATDEF_N.DEF_INV_OPER,
                :MWIPMATDEF_N.PACK_TYPE,
                :MWIPMATDEF_N.PACK_LOT_COUNT,
                :MWIPMATDEF_N.PACK_QTY,
                :MWIPMATDEF_N.LE_STOCK_LEVEL,
                :MWIPMATDEF_N.LW_STOCK_LEVEL,
                :MWIPMATDEF_N.HW_STOCK_LEVEL,
                :MWIPMATDEF_N.HE_STOCK_LEVEL,
                :MWIPMATDEF_N.IQC_FLAG,
                :MWIPMATDEF_N.IQC_SAMPLE_FLAG,
                :MWIPMATDEF_N.IQC_SAMPLE_RULE,
                :MWIPMATDEF_N.OQC_FLAG,
                :MWIPMATDEF_N.OQC_SAMPLE_FLAG,
                :MWIPMATDEF_N.OQC_SAMPLE_RULE,
                :MWIPMATDEF_N.TARGET_YIELD,
                :MWIPMATDEF_N.TARGET_DUE_DAY,
                :MWIPMATDEF_N.TARGET_QTY_1,
                :MWIPMATDEF_N.TARGET_QTY_2,
                :MWIPMATDEF_N.TARGET_QTY_3,
                :MWIPMATDEF_N.APPLY_START_TIME,
                :MWIPMATDEF_N.APPLY_END_TIME,
                :MWIPMATDEF_N.APPROVAL_FLAG,
                :MWIPMATDEF_N.APPROVAL_USER_ID,
                :MWIPMATDEF_N.APPROVAL_TIME,
                :MWIPMATDEF_N.RELEASE_FLAG,
                :MWIPMATDEF_N.RELEASE_USER_ID,
                :MWIPMATDEF_N.RELEASE_TIME,
                :MWIPMATDEF_N.DEACTIVE_FLAG,
                :MWIPMATDEF_N.DEACTIVE_USER_ID,
                :MWIPMATDEF_N.DEACTIVE_TIME,
                :MWIPMATDEF_N.DELETE_FLAG,
                :MWIPMATDEF_N.DELETE_USER_ID,
                :MWIPMATDEF_N.DELETE_TIME,
                :MWIPMATDEF_N.CREATE_USER_ID,
                :MWIPMATDEF_N.CREATE_TIME,
                :MWIPMATDEF_N.UPDATE_USER_ID,
                :MWIPMATDEF_N.UPDATE_TIME,
                :MWIPMATDEF_N.MAT_SHORT_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2780;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_GRP_1);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_GRP_2);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.MAT_GRP_3);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MWIPMATDEF_N.MAT_GRP_4);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MWIPMATDEF_N.MAT_GRP_5);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MWIPMATDEF_N.MAT_GRP_6);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MWIPMATDEF_N.MAT_GRP_7);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MWIPMATDEF_N.MAT_GRP_8);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MWIPMATDEF_N.MAT_GRP_9);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MWIPMATDEF_N.MAT_GRP_10);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MWIPMATDEF_N.MAT_CMF_1);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MWIPMATDEF_N.MAT_CMF_2);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MWIPMATDEF_N.MAT_CMF_3);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MWIPMATDEF_N.MAT_CMF_4);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MWIPMATDEF_N.MAT_CMF_5);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MWIPMATDEF_N.MAT_CMF_6);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MWIPMATDEF_N.MAT_CMF_7);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MWIPMATDEF_N.MAT_CMF_8);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MWIPMATDEF_N.MAT_CMF_9);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MWIPMATDEF_N.MAT_CMF_10);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MWIPMATDEF_N.MAT_CMF_11);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MWIPMATDEF_N.MAT_CMF_12);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MWIPMATDEF_N.MAT_CMF_13);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MWIPMATDEF_N.MAT_CMF_14);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MWIPMATDEF_N.MAT_CMF_15);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MWIPMATDEF_N.MAT_CMF_16);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MWIPMATDEF_N.MAT_CMF_17);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MWIPMATDEF_N.MAT_CMF_18);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MWIPMATDEF_N.MAT_CMF_19);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MWIPMATDEF_N.MAT_CMF_20);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(MWIPMATDEF_N.FIRST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MWIPMATDEF_N.LAST_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MWIPMATDEF_N.LAST_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MWIPMATDEF_N.MFG_DEVISION);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MWIPMATDEF_N.SUBCONTRACT_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MWIPMATDEF_N.BASE_MAT_ID);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MWIPMATDEF_N.VENDOR_ID);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MWIPMATDEF_N.VENDOR_MAT_ID);
            sqlstm.sqhstl[43] = (unsigned int  )31;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MWIPMATDEF_N.CUSTOMER_ID);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MWIPMATDEF_N.CUSTOMER_MAT_ID);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_1);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_2);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)&(MWIPMATDEF_N.DEF_QTY_3);
            sqlstm.sqhstl[48] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MWIPMATDEF_N.UNIT_1);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MWIPMATDEF_N.UNIT_2);
            sqlstm.sqhstl[50] = (unsigned int  )11;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MWIPMATDEF_N.UNIT_3);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MWIPMATDEF_N.WEIGHT_NET);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MWIPMATDEF_N.WEIGHT_GROSS);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MWIPMATDEF_N.WEIGHT_UNIT);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MWIPMATDEF_N.VOLUME);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MWIPMATDEF_N.VOLUME_UNIT);
            sqlstm.sqhstl[56] = (unsigned int  )11;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HR);
            sqlstm.sqhstl[57] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MWIPMATDEF_N.DIMENSION_HR_UNIT);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MWIPMATDEF_N.DIMENSION_VT);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MWIPMATDEF_N.DIMENSION_VT_UNIT);
            sqlstm.sqhstl[60] = (unsigned int  )11;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MWIPMATDEF_N.DIMENSION_HT);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MWIPMATDEF_N.DIMENSION_HT_UNIT);
            sqlstm.sqhstl[62] = (unsigned int  )11;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MWIPMATDEF_N.BOM_SET_ID);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MWIPMATDEF_N.DEF_INV_OPER);
            sqlstm.sqhstl[64] = (unsigned int  )11;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MWIPMATDEF_N.PACK_TYPE);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)&(MWIPMATDEF_N.PACK_LOT_COUNT);
            sqlstm.sqhstl[66] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MWIPMATDEF_N.PACK_QTY);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)&(MWIPMATDEF_N.LE_STOCK_LEVEL);
            sqlstm.sqhstl[68] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)&(MWIPMATDEF_N.LW_STOCK_LEVEL);
            sqlstm.sqhstl[69] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(MWIPMATDEF_N.HW_STOCK_LEVEL);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)&(MWIPMATDEF_N.HE_STOCK_LEVEL);
            sqlstm.sqhstl[71] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MWIPMATDEF_N.IQC_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_FLAG);
            sqlstm.sqhstl[73] = (unsigned int  )2;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MWIPMATDEF_N.IQC_SAMPLE_RULE);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MWIPMATDEF_N.OQC_FLAG);
            sqlstm.sqhstl[75] = (unsigned int  )2;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_FLAG);
            sqlstm.sqhstl[76] = (unsigned int  )2;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MWIPMATDEF_N.OQC_SAMPLE_RULE);
            sqlstm.sqhstl[77] = (unsigned int  )2;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)&(MWIPMATDEF_N.TARGET_YIELD);
            sqlstm.sqhstl[78] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)&(MWIPMATDEF_N.TARGET_DUE_DAY);
            sqlstm.sqhstl[79] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_1);
            sqlstm.sqhstl[80] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_2);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)&(MWIPMATDEF_N.TARGET_QTY_3);
            sqlstm.sqhstl[82] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MWIPMATDEF_N.APPLY_START_TIME);
            sqlstm.sqhstl[83] = (unsigned int  )15;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MWIPMATDEF_N.APPLY_END_TIME);
            sqlstm.sqhstl[84] = (unsigned int  )15;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MWIPMATDEF_N.APPROVAL_FLAG);
            sqlstm.sqhstl[85] = (unsigned int  )2;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MWIPMATDEF_N.APPROVAL_USER_ID);
            sqlstm.sqhstl[86] = (unsigned int  )21;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MWIPMATDEF_N.APPROVAL_TIME);
            sqlstm.sqhstl[87] = (unsigned int  )15;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MWIPMATDEF_N.RELEASE_FLAG);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MWIPMATDEF_N.RELEASE_USER_ID);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MWIPMATDEF_N.RELEASE_TIME);
            sqlstm.sqhstl[90] = (unsigned int  )15;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[92] = (unsigned int  )21;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[93] = (unsigned int  )15;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[94] = (unsigned int  )2;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[96] = (unsigned int  )15;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MWIPMATDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MWIPMATDEF_N.CREATE_TIME);
            sqlstm.sqhstl[98] = (unsigned int  )15;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[100] = (unsigned int  )15;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MWIPMATDEF_N.MAT_SHORT_DESC);
            sqlstm.sqhstl[101] = (unsigned int  )51;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
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
        DBU_del_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    }

    DB_stop_query_timer("DBU_fetch_mwipmatdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_mwipmatdef(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MWIPMATDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3203;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL CLOSE DBU_MWIPMATDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 105;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3218;
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

    DB_stop_query_timer("DBU_close_mwipmatdef", sel_type);
}


/* Initialize Function */
void DBU_init_mwipmatdef(struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* memset by Space */
    memset(MWIPMATDEF, ' ', sizeof(struct MWIPMATDEF_TAG));
    
    MWIPMATDEF->MAT_VER = 0;
    MWIPMATDEF->FIRST_FLOW_SEQ_NUM = 0;
    MWIPMATDEF->LAST_FLOW_SEQ_NUM = 0;
    MWIPMATDEF->DEF_QTY_1 = 0;
    MWIPMATDEF->DEF_QTY_2 = 0;
    MWIPMATDEF->DEF_QTY_3 = 0;
    MWIPMATDEF->WEIGHT_NET = 0;
    MWIPMATDEF->WEIGHT_GROSS = 0;
    MWIPMATDEF->VOLUME = 0;
    MWIPMATDEF->DIMENSION_HR = 0;
    MWIPMATDEF->DIMENSION_VT = 0;
    MWIPMATDEF->DIMENSION_HT = 0;
    MWIPMATDEF->PACK_LOT_COUNT = 0;
    MWIPMATDEF->PACK_QTY = 0;
    MWIPMATDEF->LE_STOCK_LEVEL = 0;
    MWIPMATDEF->LW_STOCK_LEVEL = 0;
    MWIPMATDEF->HW_STOCK_LEVEL = 0;
    MWIPMATDEF->HE_STOCK_LEVEL = 0;
    MWIPMATDEF->TARGET_YIELD = 0;
    MWIPMATDEF->TARGET_DUE_DAY = 0;
    MWIPMATDEF->TARGET_QTY_1 = 0;
    MWIPMATDEF->TARGET_QTY_2 = 0;
    MWIPMATDEF->TARGET_QTY_3 = 0;
}


/* Add Null Function */
void DBU_add_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* memset by NULL */
    memset(MWIPMATDEF_N, '\0', sizeof(struct MWIPMATDEF_N_TAG));
    
    MEMCPY_AN(MWIPMATDEF_N->FACTORY, MWIPMATDEF->FACTORY, sizeof(MWIPMATDEF->FACTORY));
    MEMCPY_AN(MWIPMATDEF_N->MAT_ID, MWIPMATDEF->MAT_ID, sizeof(MWIPMATDEF->MAT_ID));
    MWIPMATDEF_N->MAT_VER = MWIPMATDEF->MAT_VER;
    MEMCPY_AN(MWIPMATDEF_N->MAT_DESC, MWIPMATDEF->MAT_DESC, sizeof(MWIPMATDEF->MAT_DESC));
    MEMCPY_AN(MWIPMATDEF_N->MAT_TYPE, MWIPMATDEF->MAT_TYPE, sizeof(MWIPMATDEF->MAT_TYPE));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_1, MWIPMATDEF->MAT_GRP_1, sizeof(MWIPMATDEF->MAT_GRP_1));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_2, MWIPMATDEF->MAT_GRP_2, sizeof(MWIPMATDEF->MAT_GRP_2));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_3, MWIPMATDEF->MAT_GRP_3, sizeof(MWIPMATDEF->MAT_GRP_3));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_4, MWIPMATDEF->MAT_GRP_4, sizeof(MWIPMATDEF->MAT_GRP_4));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_5, MWIPMATDEF->MAT_GRP_5, sizeof(MWIPMATDEF->MAT_GRP_5));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_6, MWIPMATDEF->MAT_GRP_6, sizeof(MWIPMATDEF->MAT_GRP_6));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_7, MWIPMATDEF->MAT_GRP_7, sizeof(MWIPMATDEF->MAT_GRP_7));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_8, MWIPMATDEF->MAT_GRP_8, sizeof(MWIPMATDEF->MAT_GRP_8));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_9, MWIPMATDEF->MAT_GRP_9, sizeof(MWIPMATDEF->MAT_GRP_9));
    MEMCPY_AN(MWIPMATDEF_N->MAT_GRP_10, MWIPMATDEF->MAT_GRP_10, sizeof(MWIPMATDEF->MAT_GRP_10));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_1, MWIPMATDEF->MAT_CMF_1, sizeof(MWIPMATDEF->MAT_CMF_1));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_2, MWIPMATDEF->MAT_CMF_2, sizeof(MWIPMATDEF->MAT_CMF_2));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_3, MWIPMATDEF->MAT_CMF_3, sizeof(MWIPMATDEF->MAT_CMF_3));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_4, MWIPMATDEF->MAT_CMF_4, sizeof(MWIPMATDEF->MAT_CMF_4));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_5, MWIPMATDEF->MAT_CMF_5, sizeof(MWIPMATDEF->MAT_CMF_5));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_6, MWIPMATDEF->MAT_CMF_6, sizeof(MWIPMATDEF->MAT_CMF_6));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_7, MWIPMATDEF->MAT_CMF_7, sizeof(MWIPMATDEF->MAT_CMF_7));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_8, MWIPMATDEF->MAT_CMF_8, sizeof(MWIPMATDEF->MAT_CMF_8));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_9, MWIPMATDEF->MAT_CMF_9, sizeof(MWIPMATDEF->MAT_CMF_9));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_10, MWIPMATDEF->MAT_CMF_10, sizeof(MWIPMATDEF->MAT_CMF_10));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_11, MWIPMATDEF->MAT_CMF_11, sizeof(MWIPMATDEF->MAT_CMF_11));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_12, MWIPMATDEF->MAT_CMF_12, sizeof(MWIPMATDEF->MAT_CMF_12));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_13, MWIPMATDEF->MAT_CMF_13, sizeof(MWIPMATDEF->MAT_CMF_13));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_14, MWIPMATDEF->MAT_CMF_14, sizeof(MWIPMATDEF->MAT_CMF_14));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_15, MWIPMATDEF->MAT_CMF_15, sizeof(MWIPMATDEF->MAT_CMF_15));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_16, MWIPMATDEF->MAT_CMF_16, sizeof(MWIPMATDEF->MAT_CMF_16));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_17, MWIPMATDEF->MAT_CMF_17, sizeof(MWIPMATDEF->MAT_CMF_17));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_18, MWIPMATDEF->MAT_CMF_18, sizeof(MWIPMATDEF->MAT_CMF_18));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_19, MWIPMATDEF->MAT_CMF_19, sizeof(MWIPMATDEF->MAT_CMF_19));
    MEMCPY_AN(MWIPMATDEF_N->MAT_CMF_20, MWIPMATDEF->MAT_CMF_20, sizeof(MWIPMATDEF->MAT_CMF_20));
    MEMCPY_AN(MWIPMATDEF_N->FIRST_FLOW, MWIPMATDEF->FIRST_FLOW, sizeof(MWIPMATDEF->FIRST_FLOW));
    MWIPMATDEF_N->FIRST_FLOW_SEQ_NUM = MWIPMATDEF->FIRST_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPMATDEF_N->LAST_FLOW, MWIPMATDEF->LAST_FLOW, sizeof(MWIPMATDEF->LAST_FLOW));
    MWIPMATDEF_N->LAST_FLOW_SEQ_NUM = MWIPMATDEF->LAST_FLOW_SEQ_NUM;
    MEMCPY_AN(MWIPMATDEF_N->MFG_DEVISION, MWIPMATDEF->MFG_DEVISION, sizeof(MWIPMATDEF->MFG_DEVISION));
    MWIPMATDEF_N->SUBCONTRACT_FLAG[0] = MWIPMATDEF->SUBCONTRACT_FLAG;
    MEMCPY_AN(MWIPMATDEF_N->BASE_MAT_ID, MWIPMATDEF->BASE_MAT_ID, sizeof(MWIPMATDEF->BASE_MAT_ID));
    MEMCPY_AN(MWIPMATDEF_N->VENDOR_ID, MWIPMATDEF->VENDOR_ID, sizeof(MWIPMATDEF->VENDOR_ID));
    MEMCPY_AN(MWIPMATDEF_N->VENDOR_MAT_ID, MWIPMATDEF->VENDOR_MAT_ID, sizeof(MWIPMATDEF->VENDOR_MAT_ID));
    MEMCPY_AN(MWIPMATDEF_N->CUSTOMER_ID, MWIPMATDEF->CUSTOMER_ID, sizeof(MWIPMATDEF->CUSTOMER_ID));
    MEMCPY_AN(MWIPMATDEF_N->CUSTOMER_MAT_ID, MWIPMATDEF->CUSTOMER_MAT_ID, sizeof(MWIPMATDEF->CUSTOMER_MAT_ID));
    MWIPMATDEF_N->DEF_QTY_1 = MWIPMATDEF->DEF_QTY_1;
    MWIPMATDEF_N->DEF_QTY_2 = MWIPMATDEF->DEF_QTY_2;
    MWIPMATDEF_N->DEF_QTY_3 = MWIPMATDEF->DEF_QTY_3;
    MEMCPY_AN(MWIPMATDEF_N->UNIT_1, MWIPMATDEF->UNIT_1, sizeof(MWIPMATDEF->UNIT_1));
    MEMCPY_AN(MWIPMATDEF_N->UNIT_2, MWIPMATDEF->UNIT_2, sizeof(MWIPMATDEF->UNIT_2));
    MEMCPY_AN(MWIPMATDEF_N->UNIT_3, MWIPMATDEF->UNIT_3, sizeof(MWIPMATDEF->UNIT_3));
    MWIPMATDEF_N->WEIGHT_NET = MWIPMATDEF->WEIGHT_NET;
    MWIPMATDEF_N->WEIGHT_GROSS = MWIPMATDEF->WEIGHT_GROSS;
    MEMCPY_AN(MWIPMATDEF_N->WEIGHT_UNIT, MWIPMATDEF->WEIGHT_UNIT, sizeof(MWIPMATDEF->WEIGHT_UNIT));
    MWIPMATDEF_N->VOLUME = MWIPMATDEF->VOLUME;
    MEMCPY_AN(MWIPMATDEF_N->VOLUME_UNIT, MWIPMATDEF->VOLUME_UNIT, sizeof(MWIPMATDEF->VOLUME_UNIT));
    MWIPMATDEF_N->DIMENSION_HR = MWIPMATDEF->DIMENSION_HR;
    MEMCPY_AN(MWIPMATDEF_N->DIMENSION_HR_UNIT, MWIPMATDEF->DIMENSION_HR_UNIT, sizeof(MWIPMATDEF->DIMENSION_HR_UNIT));
    MWIPMATDEF_N->DIMENSION_VT = MWIPMATDEF->DIMENSION_VT;
    MEMCPY_AN(MWIPMATDEF_N->DIMENSION_VT_UNIT, MWIPMATDEF->DIMENSION_VT_UNIT, sizeof(MWIPMATDEF->DIMENSION_VT_UNIT));
    MWIPMATDEF_N->DIMENSION_HT = MWIPMATDEF->DIMENSION_HT;
    MEMCPY_AN(MWIPMATDEF_N->DIMENSION_HT_UNIT, MWIPMATDEF->DIMENSION_HT_UNIT, sizeof(MWIPMATDEF->DIMENSION_HT_UNIT));
    MEMCPY_AN(MWIPMATDEF_N->BOM_SET_ID, MWIPMATDEF->BOM_SET_ID, sizeof(MWIPMATDEF->BOM_SET_ID));
    MEMCPY_AN(MWIPMATDEF_N->DEF_INV_OPER, MWIPMATDEF->DEF_INV_OPER, sizeof(MWIPMATDEF->DEF_INV_OPER));
    MWIPMATDEF_N->PACK_TYPE[0] = MWIPMATDEF->PACK_TYPE;
    MWIPMATDEF_N->PACK_LOT_COUNT = MWIPMATDEF->PACK_LOT_COUNT;
    MWIPMATDEF_N->PACK_QTY = MWIPMATDEF->PACK_QTY;
    MWIPMATDEF_N->LE_STOCK_LEVEL = MWIPMATDEF->LE_STOCK_LEVEL;
    MWIPMATDEF_N->LW_STOCK_LEVEL = MWIPMATDEF->LW_STOCK_LEVEL;
    MWIPMATDEF_N->HW_STOCK_LEVEL = MWIPMATDEF->HW_STOCK_LEVEL;
    MWIPMATDEF_N->HE_STOCK_LEVEL = MWIPMATDEF->HE_STOCK_LEVEL;
    MWIPMATDEF_N->IQC_FLAG[0] = MWIPMATDEF->IQC_FLAG;
    MWIPMATDEF_N->IQC_SAMPLE_FLAG[0] = MWIPMATDEF->IQC_SAMPLE_FLAG;
    MWIPMATDEF_N->IQC_SAMPLE_RULE[0] = MWIPMATDEF->IQC_SAMPLE_RULE;
    MWIPMATDEF_N->OQC_FLAG[0] = MWIPMATDEF->OQC_FLAG;
    MWIPMATDEF_N->OQC_SAMPLE_FLAG[0] = MWIPMATDEF->OQC_SAMPLE_FLAG;
    MWIPMATDEF_N->OQC_SAMPLE_RULE[0] = MWIPMATDEF->OQC_SAMPLE_RULE;
    MWIPMATDEF_N->TARGET_YIELD = MWIPMATDEF->TARGET_YIELD;
    MWIPMATDEF_N->TARGET_DUE_DAY = MWIPMATDEF->TARGET_DUE_DAY;
    MWIPMATDEF_N->TARGET_QTY_1 = MWIPMATDEF->TARGET_QTY_1;
    MWIPMATDEF_N->TARGET_QTY_2 = MWIPMATDEF->TARGET_QTY_2;
    MWIPMATDEF_N->TARGET_QTY_3 = MWIPMATDEF->TARGET_QTY_3;
    MEMCPY_AN(MWIPMATDEF_N->APPLY_START_TIME, MWIPMATDEF->APPLY_START_TIME, sizeof(MWIPMATDEF->APPLY_START_TIME));
    MEMCPY_AN(MWIPMATDEF_N->APPLY_END_TIME, MWIPMATDEF->APPLY_END_TIME, sizeof(MWIPMATDEF->APPLY_END_TIME));
    MWIPMATDEF_N->APPROVAL_FLAG[0] = MWIPMATDEF->APPROVAL_FLAG;
    MEMCPY_AN(MWIPMATDEF_N->APPROVAL_USER_ID, MWIPMATDEF->APPROVAL_USER_ID, sizeof(MWIPMATDEF->APPROVAL_USER_ID));
    MEMCPY_AN(MWIPMATDEF_N->APPROVAL_TIME, MWIPMATDEF->APPROVAL_TIME, sizeof(MWIPMATDEF->APPROVAL_TIME));
    MWIPMATDEF_N->RELEASE_FLAG[0] = MWIPMATDEF->RELEASE_FLAG;
    MEMCPY_AN(MWIPMATDEF_N->RELEASE_USER_ID, MWIPMATDEF->RELEASE_USER_ID, sizeof(MWIPMATDEF->RELEASE_USER_ID));
    MEMCPY_AN(MWIPMATDEF_N->RELEASE_TIME, MWIPMATDEF->RELEASE_TIME, sizeof(MWIPMATDEF->RELEASE_TIME));
    MWIPMATDEF_N->DEACTIVE_FLAG[0] = MWIPMATDEF->DEACTIVE_FLAG;
    MEMCPY_AN(MWIPMATDEF_N->DEACTIVE_USER_ID, MWIPMATDEF->DEACTIVE_USER_ID, sizeof(MWIPMATDEF->DEACTIVE_USER_ID));
    MEMCPY_AN(MWIPMATDEF_N->DEACTIVE_TIME, MWIPMATDEF->DEACTIVE_TIME, sizeof(MWIPMATDEF->DEACTIVE_TIME));
    MWIPMATDEF_N->DELETE_FLAG[0] = MWIPMATDEF->DELETE_FLAG;
    MEMCPY_AN(MWIPMATDEF_N->DELETE_USER_ID, MWIPMATDEF->DELETE_USER_ID, sizeof(MWIPMATDEF->DELETE_USER_ID));
    MEMCPY_AN(MWIPMATDEF_N->DELETE_TIME, MWIPMATDEF->DELETE_TIME, sizeof(MWIPMATDEF->DELETE_TIME));
    MEMCPY_AN(MWIPMATDEF_N->CREATE_USER_ID, MWIPMATDEF->CREATE_USER_ID, sizeof(MWIPMATDEF->CREATE_USER_ID));
    MEMCPY_AN(MWIPMATDEF_N->CREATE_TIME, MWIPMATDEF->CREATE_TIME, sizeof(MWIPMATDEF->CREATE_TIME));
    MEMCPY_AN(MWIPMATDEF_N->UPDATE_USER_ID, MWIPMATDEF->UPDATE_USER_ID, sizeof(MWIPMATDEF->UPDATE_USER_ID));
    MEMCPY_AN(MWIPMATDEF_N->UPDATE_TIME, MWIPMATDEF->UPDATE_TIME, sizeof(MWIPMATDEF->UPDATE_TIME));
    MEMCPY_AN(MWIPMATDEF_N->MAT_SHORT_DESC, MWIPMATDEF->MAT_SHORT_DESC, sizeof(MWIPMATDEF->MAT_SHORT_DESC));
}


/* Del Null Function */
void DBU_del_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    MEMCPY_DN(MWIPMATDEF->FACTORY, MWIPMATDEF_N->FACTORY, sizeof(MWIPMATDEF->FACTORY));
    MEMCPY_DN(MWIPMATDEF->MAT_ID, MWIPMATDEF_N->MAT_ID, sizeof(MWIPMATDEF->MAT_ID));
    MWIPMATDEF->MAT_VER = MWIPMATDEF_N->MAT_VER;
    MEMCPY_DN(MWIPMATDEF->MAT_DESC, MWIPMATDEF_N->MAT_DESC, sizeof(MWIPMATDEF->MAT_DESC));
    MEMCPY_DN(MWIPMATDEF->MAT_TYPE, MWIPMATDEF_N->MAT_TYPE, sizeof(MWIPMATDEF->MAT_TYPE));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_1, MWIPMATDEF_N->MAT_GRP_1, sizeof(MWIPMATDEF->MAT_GRP_1));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_2, MWIPMATDEF_N->MAT_GRP_2, sizeof(MWIPMATDEF->MAT_GRP_2));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_3, MWIPMATDEF_N->MAT_GRP_3, sizeof(MWIPMATDEF->MAT_GRP_3));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_4, MWIPMATDEF_N->MAT_GRP_4, sizeof(MWIPMATDEF->MAT_GRP_4));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_5, MWIPMATDEF_N->MAT_GRP_5, sizeof(MWIPMATDEF->MAT_GRP_5));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_6, MWIPMATDEF_N->MAT_GRP_6, sizeof(MWIPMATDEF->MAT_GRP_6));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_7, MWIPMATDEF_N->MAT_GRP_7, sizeof(MWIPMATDEF->MAT_GRP_7));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_8, MWIPMATDEF_N->MAT_GRP_8, sizeof(MWIPMATDEF->MAT_GRP_8));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_9, MWIPMATDEF_N->MAT_GRP_9, sizeof(MWIPMATDEF->MAT_GRP_9));
    MEMCPY_DN(MWIPMATDEF->MAT_GRP_10, MWIPMATDEF_N->MAT_GRP_10, sizeof(MWIPMATDEF->MAT_GRP_10));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_1, MWIPMATDEF_N->MAT_CMF_1, sizeof(MWIPMATDEF->MAT_CMF_1));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_2, MWIPMATDEF_N->MAT_CMF_2, sizeof(MWIPMATDEF->MAT_CMF_2));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_3, MWIPMATDEF_N->MAT_CMF_3, sizeof(MWIPMATDEF->MAT_CMF_3));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_4, MWIPMATDEF_N->MAT_CMF_4, sizeof(MWIPMATDEF->MAT_CMF_4));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_5, MWIPMATDEF_N->MAT_CMF_5, sizeof(MWIPMATDEF->MAT_CMF_5));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_6, MWIPMATDEF_N->MAT_CMF_6, sizeof(MWIPMATDEF->MAT_CMF_6));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_7, MWIPMATDEF_N->MAT_CMF_7, sizeof(MWIPMATDEF->MAT_CMF_7));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_8, MWIPMATDEF_N->MAT_CMF_8, sizeof(MWIPMATDEF->MAT_CMF_8));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_9, MWIPMATDEF_N->MAT_CMF_9, sizeof(MWIPMATDEF->MAT_CMF_9));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_10, MWIPMATDEF_N->MAT_CMF_10, sizeof(MWIPMATDEF->MAT_CMF_10));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_11, MWIPMATDEF_N->MAT_CMF_11, sizeof(MWIPMATDEF->MAT_CMF_11));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_12, MWIPMATDEF_N->MAT_CMF_12, sizeof(MWIPMATDEF->MAT_CMF_12));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_13, MWIPMATDEF_N->MAT_CMF_13, sizeof(MWIPMATDEF->MAT_CMF_13));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_14, MWIPMATDEF_N->MAT_CMF_14, sizeof(MWIPMATDEF->MAT_CMF_14));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_15, MWIPMATDEF_N->MAT_CMF_15, sizeof(MWIPMATDEF->MAT_CMF_15));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_16, MWIPMATDEF_N->MAT_CMF_16, sizeof(MWIPMATDEF->MAT_CMF_16));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_17, MWIPMATDEF_N->MAT_CMF_17, sizeof(MWIPMATDEF->MAT_CMF_17));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_18, MWIPMATDEF_N->MAT_CMF_18, sizeof(MWIPMATDEF->MAT_CMF_18));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_19, MWIPMATDEF_N->MAT_CMF_19, sizeof(MWIPMATDEF->MAT_CMF_19));
    MEMCPY_DN(MWIPMATDEF->MAT_CMF_20, MWIPMATDEF_N->MAT_CMF_20, sizeof(MWIPMATDEF->MAT_CMF_20));
    MEMCPY_DN(MWIPMATDEF->FIRST_FLOW, MWIPMATDEF_N->FIRST_FLOW, sizeof(MWIPMATDEF->FIRST_FLOW));
    MWIPMATDEF->FIRST_FLOW_SEQ_NUM = MWIPMATDEF_N->FIRST_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPMATDEF->LAST_FLOW, MWIPMATDEF_N->LAST_FLOW, sizeof(MWIPMATDEF->LAST_FLOW));
    MWIPMATDEF->LAST_FLOW_SEQ_NUM = MWIPMATDEF_N->LAST_FLOW_SEQ_NUM;
    MEMCPY_DN(MWIPMATDEF->MFG_DEVISION, MWIPMATDEF_N->MFG_DEVISION, sizeof(MWIPMATDEF->MFG_DEVISION));
    MWIPMATDEF->SUBCONTRACT_FLAG = MWIPMATDEF_N->SUBCONTRACT_FLAG[0];
    MEMCPY_DN(MWIPMATDEF->BASE_MAT_ID, MWIPMATDEF_N->BASE_MAT_ID, sizeof(MWIPMATDEF->BASE_MAT_ID));
    MEMCPY_DN(MWIPMATDEF->VENDOR_ID, MWIPMATDEF_N->VENDOR_ID, sizeof(MWIPMATDEF->VENDOR_ID));
    MEMCPY_DN(MWIPMATDEF->VENDOR_MAT_ID, MWIPMATDEF_N->VENDOR_MAT_ID, sizeof(MWIPMATDEF->VENDOR_MAT_ID));
    MEMCPY_DN(MWIPMATDEF->CUSTOMER_ID, MWIPMATDEF_N->CUSTOMER_ID, sizeof(MWIPMATDEF->CUSTOMER_ID));
    MEMCPY_DN(MWIPMATDEF->CUSTOMER_MAT_ID, MWIPMATDEF_N->CUSTOMER_MAT_ID, sizeof(MWIPMATDEF->CUSTOMER_MAT_ID));
    MWIPMATDEF->DEF_QTY_1 = MWIPMATDEF_N->DEF_QTY_1;
    MWIPMATDEF->DEF_QTY_2 = MWIPMATDEF_N->DEF_QTY_2;
    MWIPMATDEF->DEF_QTY_3 = MWIPMATDEF_N->DEF_QTY_3;
    MEMCPY_DN(MWIPMATDEF->UNIT_1, MWIPMATDEF_N->UNIT_1, sizeof(MWIPMATDEF->UNIT_1));
    MEMCPY_DN(MWIPMATDEF->UNIT_2, MWIPMATDEF_N->UNIT_2, sizeof(MWIPMATDEF->UNIT_2));
    MEMCPY_DN(MWIPMATDEF->UNIT_3, MWIPMATDEF_N->UNIT_3, sizeof(MWIPMATDEF->UNIT_3));
    MWIPMATDEF->WEIGHT_NET = MWIPMATDEF_N->WEIGHT_NET;
    MWIPMATDEF->WEIGHT_GROSS = MWIPMATDEF_N->WEIGHT_GROSS;
    MEMCPY_DN(MWIPMATDEF->WEIGHT_UNIT, MWIPMATDEF_N->WEIGHT_UNIT, sizeof(MWIPMATDEF->WEIGHT_UNIT));
    MWIPMATDEF->VOLUME = MWIPMATDEF_N->VOLUME;
    MEMCPY_DN(MWIPMATDEF->VOLUME_UNIT, MWIPMATDEF_N->VOLUME_UNIT, sizeof(MWIPMATDEF->VOLUME_UNIT));
    MWIPMATDEF->DIMENSION_HR = MWIPMATDEF_N->DIMENSION_HR;
    MEMCPY_DN(MWIPMATDEF->DIMENSION_HR_UNIT, MWIPMATDEF_N->DIMENSION_HR_UNIT, sizeof(MWIPMATDEF->DIMENSION_HR_UNIT));
    MWIPMATDEF->DIMENSION_VT = MWIPMATDEF_N->DIMENSION_VT;
    MEMCPY_DN(MWIPMATDEF->DIMENSION_VT_UNIT, MWIPMATDEF_N->DIMENSION_VT_UNIT, sizeof(MWIPMATDEF->DIMENSION_VT_UNIT));
    MWIPMATDEF->DIMENSION_HT = MWIPMATDEF_N->DIMENSION_HT;
    MEMCPY_DN(MWIPMATDEF->DIMENSION_HT_UNIT, MWIPMATDEF_N->DIMENSION_HT_UNIT, sizeof(MWIPMATDEF->DIMENSION_HT_UNIT));
    MEMCPY_DN(MWIPMATDEF->BOM_SET_ID, MWIPMATDEF_N->BOM_SET_ID, sizeof(MWIPMATDEF->BOM_SET_ID));
    MEMCPY_DN(MWIPMATDEF->DEF_INV_OPER, MWIPMATDEF_N->DEF_INV_OPER, sizeof(MWIPMATDEF->DEF_INV_OPER));
    MWIPMATDEF->PACK_TYPE = MWIPMATDEF_N->PACK_TYPE[0];
    MWIPMATDEF->PACK_LOT_COUNT = MWIPMATDEF_N->PACK_LOT_COUNT;
    MWIPMATDEF->PACK_QTY = MWIPMATDEF_N->PACK_QTY;
    MWIPMATDEF->LE_STOCK_LEVEL = MWIPMATDEF_N->LE_STOCK_LEVEL;
    MWIPMATDEF->LW_STOCK_LEVEL = MWIPMATDEF_N->LW_STOCK_LEVEL;
    MWIPMATDEF->HW_STOCK_LEVEL = MWIPMATDEF_N->HW_STOCK_LEVEL;
    MWIPMATDEF->HE_STOCK_LEVEL = MWIPMATDEF_N->HE_STOCK_LEVEL;
    MWIPMATDEF->IQC_FLAG = MWIPMATDEF_N->IQC_FLAG[0];
    MWIPMATDEF->IQC_SAMPLE_FLAG = MWIPMATDEF_N->IQC_SAMPLE_FLAG[0];
    MWIPMATDEF->IQC_SAMPLE_RULE = MWIPMATDEF_N->IQC_SAMPLE_RULE[0];
    MWIPMATDEF->OQC_FLAG = MWIPMATDEF_N->OQC_FLAG[0];
    MWIPMATDEF->OQC_SAMPLE_FLAG = MWIPMATDEF_N->OQC_SAMPLE_FLAG[0];
    MWIPMATDEF->OQC_SAMPLE_RULE = MWIPMATDEF_N->OQC_SAMPLE_RULE[0];
    MWIPMATDEF->TARGET_YIELD = MWIPMATDEF_N->TARGET_YIELD;
    MWIPMATDEF->TARGET_DUE_DAY = MWIPMATDEF_N->TARGET_DUE_DAY;
    MWIPMATDEF->TARGET_QTY_1 = MWIPMATDEF_N->TARGET_QTY_1;
    MWIPMATDEF->TARGET_QTY_2 = MWIPMATDEF_N->TARGET_QTY_2;
    MWIPMATDEF->TARGET_QTY_3 = MWIPMATDEF_N->TARGET_QTY_3;
    MEMCPY_DN(MWIPMATDEF->APPLY_START_TIME, MWIPMATDEF_N->APPLY_START_TIME, sizeof(MWIPMATDEF->APPLY_START_TIME));
    MEMCPY_DN(MWIPMATDEF->APPLY_END_TIME, MWIPMATDEF_N->APPLY_END_TIME, sizeof(MWIPMATDEF->APPLY_END_TIME));
    MWIPMATDEF->APPROVAL_FLAG = MWIPMATDEF_N->APPROVAL_FLAG[0];
    MEMCPY_DN(MWIPMATDEF->APPROVAL_USER_ID, MWIPMATDEF_N->APPROVAL_USER_ID, sizeof(MWIPMATDEF->APPROVAL_USER_ID));
    MEMCPY_DN(MWIPMATDEF->APPROVAL_TIME, MWIPMATDEF_N->APPROVAL_TIME, sizeof(MWIPMATDEF->APPROVAL_TIME));
    MWIPMATDEF->RELEASE_FLAG = MWIPMATDEF_N->RELEASE_FLAG[0];
    MEMCPY_DN(MWIPMATDEF->RELEASE_USER_ID, MWIPMATDEF_N->RELEASE_USER_ID, sizeof(MWIPMATDEF->RELEASE_USER_ID));
    MEMCPY_DN(MWIPMATDEF->RELEASE_TIME, MWIPMATDEF_N->RELEASE_TIME, sizeof(MWIPMATDEF->RELEASE_TIME));
    MWIPMATDEF->DEACTIVE_FLAG = MWIPMATDEF_N->DEACTIVE_FLAG[0];
    MEMCPY_DN(MWIPMATDEF->DEACTIVE_USER_ID, MWIPMATDEF_N->DEACTIVE_USER_ID, sizeof(MWIPMATDEF->DEACTIVE_USER_ID));
    MEMCPY_DN(MWIPMATDEF->DEACTIVE_TIME, MWIPMATDEF_N->DEACTIVE_TIME, sizeof(MWIPMATDEF->DEACTIVE_TIME));
    MWIPMATDEF->DELETE_FLAG = MWIPMATDEF_N->DELETE_FLAG[0];
    MEMCPY_DN(MWIPMATDEF->DELETE_USER_ID, MWIPMATDEF_N->DELETE_USER_ID, sizeof(MWIPMATDEF->DELETE_USER_ID));
    MEMCPY_DN(MWIPMATDEF->DELETE_TIME, MWIPMATDEF_N->DELETE_TIME, sizeof(MWIPMATDEF->DELETE_TIME));
    MEMCPY_DN(MWIPMATDEF->CREATE_USER_ID, MWIPMATDEF_N->CREATE_USER_ID, sizeof(MWIPMATDEF->CREATE_USER_ID));
    MEMCPY_DN(MWIPMATDEF->CREATE_TIME, MWIPMATDEF_N->CREATE_TIME, sizeof(MWIPMATDEF->CREATE_TIME));
    MEMCPY_DN(MWIPMATDEF->UPDATE_USER_ID, MWIPMATDEF_N->UPDATE_USER_ID, sizeof(MWIPMATDEF->UPDATE_USER_ID));
    MEMCPY_DN(MWIPMATDEF->UPDATE_TIME, MWIPMATDEF_N->UPDATE_TIME, sizeof(MWIPMATDEF->UPDATE_TIME));
    MEMCPY_DN(MWIPMATDEF->MAT_SHORT_DESC, MWIPMATDEF_N->MAT_SHORT_DESC, sizeof(MWIPMATDEF->MAT_SHORT_DESC));
}


