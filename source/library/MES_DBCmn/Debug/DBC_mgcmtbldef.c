
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
    "DBC_mgcmtbldef.pc"
};


static unsigned int sqlctx = 9103003;


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
            void  *sqhstv[121];
   unsigned int   sqhstl[121];
            int   sqhsts[121];
            void  *sqindv[121];
            int   sqinds[121];
   unsigned int   sqharm[121];
   unsigned int   *sqharc[121];
   unsigned short  sqadto[121];
   unsigned short  sqtdso[121];
} sqlstm = {13,121};

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
"select FACTORY ,TABLE_NAME ,TABLE_DESC ,SYS_TBL_FLAG  from MGCMTBLDEF where\
 (((FACTORY=:b0 and TABLE_TYPE like :b1) and TABLE_GROUP like :b2) and TABLE_\
NAME>=:b3) order by TABLE_NAME asc             ";

 static const char *sq0009 = 
"EY_4_COL ,KEY_5_TBL ,KEY_5_COL ,KEY_\
6_TBL ,KEY_6_COL ,KEY_7_TBL ,KEY_7_COL ,KEY_8_TBL ,KEY_8_COL ,KEY_9_TBL ,KEY_\
9_COL ,KEY_10_TBL ,KEY_10_COL ,DATA_1_TBL ,DATA_1_COL ,DATA_2_TBL ,DATA_2_COL\
 ,DATA_3_TBL ,DATA_3_COL ,DATA_4_TBL ,DATA_4_COL ,DATA_5_TBL ,DATA_5_COL ,DAT\
A_6_TBL ,DATA_6_COL ,DATA_7_TBL ,DATA_7_COL ,DATA_8_TBL ,DATA_8_COL ,DATA_9_T\
BL ,DATA_9_COL ,DATA_10_TBL ,DATA_10_COL  from MGCMTBLDEF where ((FACTORY=:b0\
 and SYS_TBL_FLAG=:b1) and CENTRAL_FLAG=:b2) order by TABLE_NAME asc         \
    ";

 static const char *sq0010 = 
"select FACTORY ,TABLE_NAME ,TABLE_DESC ,SYS_TBL_FLAG  from MGCMTBLDEF where\
 ((((FACTORY=:b0 and TABLE_TYPE like :b1) and TABLE_GROUP like :b2) and TABLE\
_NAME>=:b3) and SEC_CHK_FLAG=:b4) order by TABLE_NAME asc             ";

 static const char *sq0011 = 
"select GTD.FACTORY ,GTD.TABLE_NAME ,GTD.TABLE_DESC ,GTD.SYS_TBL_FLAG  from \
MGCMTBLDEF GTD ,MSECPRVDEF PRD ,MSECPRVUSR PRU where ((((((((((PRU.FACTORY=:b\
0 and PRU.USER_ID=:b1) and PRD.FACTORY=PRU.FACTORY) and PRD.PRV_GRP_ID=PRU.PR\
V_GRP_ID) and PRD.PRV_TYPE='GCMTABLE') and GTD.FACTORY=PRD.FACTORY) and GTD.T\
ABLE_NAME=PRD.PRV_ITEM1) and GTD.TABLE_TYPE like :b2) and GTD.TABLE_GROUP lik\
e :b3) and GTD.SEC_CHK_FLAG='Y') and GTD.TABLE_NAME>=:b4) order by GTD.TABLE_\
NAME asc             ";

 static const char *sq0012 = 
"select 'DATA_2' ,DATA_2_PRT  from MG\
CMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'DATA_3' ,DA\
TA_3_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) union all se\
lect 'DATA_4' ,DATA_4_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=\
:b1) union all select 'DATA_5' ,DATA_5_PRT  from MGCMTBLDEF where (FACTORY=:b\
0 and TABLE_NAME=:b1) union all select 'DATA_6' ,DATA_6_PRT  from MGCMTBLDEF \
where (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'DATA_7' ,DATA_7_PRT \
 from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'DAT\
A_8' ,DATA_8_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) unio\
n all select 'DATA_9' ,DATA_9_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TAB\
LE_NAME=:b1) union all select 'DATA_10' ,DATA_10_PRT  from MGCMTBLDEF where (\
FACTORY=:b0 and TABLE_NAME=:b1)           ";

 static const char *sq0013 = 
"select FACTORY ,TABLE_NAME ,TABLE_DESC ,SYS_TBL_FLAG  from MGCMTBLDEF where\
 ((((((FACTORY=:b0 and SYS_TBL_FLAG=:b1) and CENTRAL_FLAG=:b2) and SEC_CHK_FL\
AG=:b3) and TABLE_TYPE like :b4) and TABLE_GROUP like :b5) and TABLE_NAME>=:b\
6) order by TABLE_NAME asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,2073,0,4,43,0,0,121,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,
504,0,0,2,2085,0,4,320,0,0,121,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,
0,0,1,97,0,0,
1003,0,0,3,81,0,4,600,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
1030,0,0,4,63,0,2,635,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1053,0,0,5,42,0,2,641,0,0,1,1,0,1,0,1,97,0,0,
1072,0,0,6,1921,0,3,668,0,0,119,119,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1563,0,0,7,1922,0,5,929,0,0,119,119,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2054,0,0,8,199,0,9,1085,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2085,0,0,9,1526,0,9,1215,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
2112,0,0,10,222,0,9,1228,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
2147,0,0,11,481,0,9,1247,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
2182,0,0,12,1872,0,9,1292,0,0,40,40,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,1,
0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,
0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,
0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
2357,0,0,13,268,0,9,1307,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,
2400,0,0,8,0,0,13,1335,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2431,0,0,9,0,0,13,1339,0,0,119,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2922,0,0,10,0,0,13,1462,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2953,0,0,11,0,0,13,1466,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2984,0,0,12,0,0,13,1470,0,0,2,0,0,1,0,2,97,0,0,2,97,0,0,
3007,0,0,13,0,0,13,1474,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3038,0,0,8,0,0,15,1504,0,0,0,0,0,1,0,
3053,0,0,9,0,0,15,1508,0,0,0,0,0,1,0,
3068,0,0,10,0,0,15,1512,0,0,0,0,0,1,0,
3083,0,0,11,0,0,15,1516,0,0,0,0,0,1,0,
3098,0,0,12,0,0,15,1520,0,0,0,0,0,1,0,
3113,0,0,13,0,0,15,1524,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mgcmtbldef.pc
**    Description : Table Access Function Source File
**    Create date : 2004/11/29 11:11:46
**
**    Generated by DB Common Generator
**    Copyright (C), MIRACOM,INC.
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
void DBC_add_null_mgcmtbldef(struct MGCMTBLDEF_N_TAG *MGCMTBLDEF_N, struct MGCMTBLDEF_TAG *MGCMTBLDEF);
void DBC_del_null_mgcmtbldef(struct MGCMTBLDEF_N_TAG *MGCMTBLDEF_N, struct MGCMTBLDEF_TAG *MGCMTBLDEF);


/* SQL SELECT Function */
void DBC_select_mgcmtbldef(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         TABLE_NAME,
                         TABLE_DESC,
                         SYS_TBL_FLAG,
                         CENTRAL_FLAG,
                         TABLE_TYPE,
                         USE_SQL_FLAG,
                         TABLE_GROUP,
                         KEY_1_PRT,
                         KEY_1_FMT,
                         KEY_1_SIZE,
                         KEY_2_PRT,
                         KEY_2_FMT,
                         KEY_2_SIZE,
                         KEY_3_PRT,
                         KEY_3_FMT,
                         KEY_3_SIZE,
                         KEY_4_PRT,
                         KEY_4_FMT,
                         KEY_4_SIZE,
                         KEY_5_PRT,
                         KEY_5_FMT,
                         KEY_5_SIZE,
                         KEY_6_PRT,
                         KEY_6_FMT,
                         KEY_6_SIZE,
                         KEY_7_PRT,
                         KEY_7_FMT,
                         KEY_7_SIZE,
                         KEY_8_PRT,
                         KEY_8_FMT,
                         KEY_8_SIZE,
                         KEY_9_PRT,
                         KEY_9_FMT,
                         KEY_9_SIZE,
                         KEY_10_PRT,
                         KEY_10_FMT,
                         KEY_10_SIZE,
                         DATA_1_PRT,
                         DATA_1_FMT,
                         DATA_1_SIZE,
                         DATA_2_PRT,
                         DATA_2_FMT,
                         DATA_2_SIZE,
                         DATA_3_PRT,
                         DATA_3_FMT,
                         DATA_3_SIZE,
                         DATA_4_PRT,
                         DATA_4_FMT,
                         DATA_4_SIZE,
                         DATA_5_PRT,
                         DATA_5_FMT,
                         DATA_5_SIZE,
                         DATA_6_PRT,
                         DATA_6_FMT,
                         DATA_6_SIZE,
                         DATA_7_PRT,
                         DATA_7_FMT,
                         DATA_7_SIZE,
                         DATA_8_PRT,
                         DATA_8_FMT,
                         DATA_8_SIZE,
                         DATA_9_PRT,
                         DATA_9_FMT,
                         DATA_9_SIZE,
                         DATA_10_PRT,
                         DATA_10_FMT,
                         DATA_10_SIZE,
                         SQL_1,
                         SQL_2,
                         SQL_3,
                         SQL_4,
                         SQL_5,
                         TABLE_PASSWORD,
                         SEC_CHK_FLAG,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME,
                         KEY_1_TBL,
                         KEY_1_COL,
                         KEY_2_TBL,
                         KEY_2_COL,
                         KEY_3_TBL,
                         KEY_3_COL,
                         KEY_4_TBL,
                         KEY_4_COL,
                         KEY_5_TBL,
                         KEY_5_COL,
                         KEY_6_TBL,
                         KEY_6_COL,
                         KEY_7_TBL,
                         KEY_7_COL,
                         KEY_8_TBL,
                         KEY_8_COL,
                         KEY_9_TBL,
                         KEY_9_COL,
                         KEY_10_TBL,
                         KEY_10_COL,
                         DATA_1_TBL,
                         DATA_1_COL,
                         DATA_2_TBL,
                         DATA_2_COL,
                         DATA_3_TBL,
                         DATA_3_COL,
                         DATA_4_TBL,
                         DATA_4_COL,
                         DATA_5_TBL,
                         DATA_5_COL,
                         DATA_6_TBL,
                         DATA_6_COL,
                         DATA_7_TBL,
                         DATA_7_COL,
                         DATA_8_TBL,
                         DATA_8_COL,
                         DATA_9_TBL,
                         DATA_9_COL,
                         DATA_10_TBL,
                         DATA_10_COL
                INTO 
                    :MGCMTBLDEF_N.FACTORY,
                    :MGCMTBLDEF_N.TABLE_NAME,
                    :MGCMTBLDEF_N.TABLE_DESC,
                    :MGCMTBLDEF_N.SYS_TBL_FLAG,
                    :MGCMTBLDEF_N.CENTRAL_FLAG,
                    :MGCMTBLDEF_N.TABLE_TYPE,
                    :MGCMTBLDEF_N.USE_SQL_FLAG,
                    :MGCMTBLDEF_N.TABLE_GROUP,
                    :MGCMTBLDEF_N.KEY_1_PRT,
                    :MGCMTBLDEF_N.KEY_1_FMT,
                    :MGCMTBLDEF_N.KEY_1_SIZE,
                    :MGCMTBLDEF_N.KEY_2_PRT,
                    :MGCMTBLDEF_N.KEY_2_FMT,
                    :MGCMTBLDEF_N.KEY_2_SIZE,
                    :MGCMTBLDEF_N.KEY_3_PRT,
                    :MGCMTBLDEF_N.KEY_3_FMT,
                    :MGCMTBLDEF_N.KEY_3_SIZE,
                    :MGCMTBLDEF_N.KEY_4_PRT,
                    :MGCMTBLDEF_N.KEY_4_FMT,
                    :MGCMTBLDEF_N.KEY_4_SIZE,
                    :MGCMTBLDEF_N.KEY_5_PRT,
                    :MGCMTBLDEF_N.KEY_5_FMT,
                    :MGCMTBLDEF_N.KEY_5_SIZE,
                    :MGCMTBLDEF_N.KEY_6_PRT,
                    :MGCMTBLDEF_N.KEY_6_FMT,
                    :MGCMTBLDEF_N.KEY_6_SIZE,
                    :MGCMTBLDEF_N.KEY_7_PRT,
                    :MGCMTBLDEF_N.KEY_7_FMT,
                    :MGCMTBLDEF_N.KEY_7_SIZE,
                    :MGCMTBLDEF_N.KEY_8_PRT,
                    :MGCMTBLDEF_N.KEY_8_FMT,
                    :MGCMTBLDEF_N.KEY_8_SIZE,
                    :MGCMTBLDEF_N.KEY_9_PRT,
                    :MGCMTBLDEF_N.KEY_9_FMT,
                    :MGCMTBLDEF_N.KEY_9_SIZE,
                    :MGCMTBLDEF_N.KEY_10_PRT,
                    :MGCMTBLDEF_N.KEY_10_FMT,
                    :MGCMTBLDEF_N.KEY_10_SIZE,
                    :MGCMTBLDEF_N.DATA_1_PRT,
                    :MGCMTBLDEF_N.DATA_1_FMT,
                    :MGCMTBLDEF_N.DATA_1_SIZE,
                    :MGCMTBLDEF_N.DATA_2_PRT,
                    :MGCMTBLDEF_N.DATA_2_FMT,
                    :MGCMTBLDEF_N.DATA_2_SIZE,
                    :MGCMTBLDEF_N.DATA_3_PRT,
                    :MGCMTBLDEF_N.DATA_3_FMT,
                    :MGCMTBLDEF_N.DATA_3_SIZE,
                    :MGCMTBLDEF_N.DATA_4_PRT,
                    :MGCMTBLDEF_N.DATA_4_FMT,
                    :MGCMTBLDEF_N.DATA_4_SIZE,
                    :MGCMTBLDEF_N.DATA_5_PRT,
                    :MGCMTBLDEF_N.DATA_5_FMT,
                    :MGCMTBLDEF_N.DATA_5_SIZE,
                    :MGCMTBLDEF_N.DATA_6_PRT,
                    :MGCMTBLDEF_N.DATA_6_FMT,
                    :MGCMTBLDEF_N.DATA_6_SIZE,
                    :MGCMTBLDEF_N.DATA_7_PRT,
                    :MGCMTBLDEF_N.DATA_7_FMT,
                    :MGCMTBLDEF_N.DATA_7_SIZE,
                    :MGCMTBLDEF_N.DATA_8_PRT,
                    :MGCMTBLDEF_N.DATA_8_FMT,
                    :MGCMTBLDEF_N.DATA_8_SIZE,
                    :MGCMTBLDEF_N.DATA_9_PRT,
                    :MGCMTBLDEF_N.DATA_9_FMT,
                    :MGCMTBLDEF_N.DATA_9_SIZE,
                    :MGCMTBLDEF_N.DATA_10_PRT,
                    :MGCMTBLDEF_N.DATA_10_FMT,
                    :MGCMTBLDEF_N.DATA_10_SIZE,
                    :MGCMTBLDEF_N.SQL_1,
                    :MGCMTBLDEF_N.SQL_2,
                    :MGCMTBLDEF_N.SQL_3,
                    :MGCMTBLDEF_N.SQL_4,
                    :MGCMTBLDEF_N.SQL_5,
                    :MGCMTBLDEF_N.TABLE_PASSWORD,
                    :MGCMTBLDEF_N.SEC_CHK_FLAG,
                    :MGCMTBLDEF_N.CREATE_USER_ID,
                    :MGCMTBLDEF_N.CREATE_TIME,
                    :MGCMTBLDEF_N.UPDATE_USER_ID,
                    :MGCMTBLDEF_N.UPDATE_TIME,
                    :MGCMTBLDEF_N.KEY_1_TBL,
                    :MGCMTBLDEF_N.KEY_1_COL,
                    :MGCMTBLDEF_N.KEY_2_TBL,
                    :MGCMTBLDEF_N.KEY_2_COL,
                    :MGCMTBLDEF_N.KEY_3_TBL,
                    :MGCMTBLDEF_N.KEY_3_COL,
                    :MGCMTBLDEF_N.KEY_4_TBL,
                    :MGCMTBLDEF_N.KEY_4_COL,
                    :MGCMTBLDEF_N.KEY_5_TBL,
                    :MGCMTBLDEF_N.KEY_5_COL,
                    :MGCMTBLDEF_N.KEY_6_TBL,
                    :MGCMTBLDEF_N.KEY_6_COL,
                    :MGCMTBLDEF_N.KEY_7_TBL,
                    :MGCMTBLDEF_N.KEY_7_COL,
                    :MGCMTBLDEF_N.KEY_8_TBL,
                    :MGCMTBLDEF_N.KEY_8_COL,
                    :MGCMTBLDEF_N.KEY_9_TBL,
                    :MGCMTBLDEF_N.KEY_9_COL,
                    :MGCMTBLDEF_N.KEY_10_TBL,
                    :MGCMTBLDEF_N.KEY_10_COL,
                    :MGCMTBLDEF_N.DATA_1_TBL,
                    :MGCMTBLDEF_N.DATA_1_COL,
                    :MGCMTBLDEF_N.DATA_2_TBL,
                    :MGCMTBLDEF_N.DATA_2_COL,
                    :MGCMTBLDEF_N.DATA_3_TBL,
                    :MGCMTBLDEF_N.DATA_3_COL,
                    :MGCMTBLDEF_N.DATA_4_TBL,
                    :MGCMTBLDEF_N.DATA_4_COL,
                    :MGCMTBLDEF_N.DATA_5_TBL,
                    :MGCMTBLDEF_N.DATA_5_COL,
                    :MGCMTBLDEF_N.DATA_6_TBL,
                    :MGCMTBLDEF_N.DATA_6_COL,
                    :MGCMTBLDEF_N.DATA_7_TBL,
                    :MGCMTBLDEF_N.DATA_7_COL,
                    :MGCMTBLDEF_N.DATA_8_TBL,
                    :MGCMTBLDEF_N.DATA_8_COL,
                    :MGCMTBLDEF_N.DATA_9_TBL,
                    :MGCMTBLDEF_N.DATA_9_COL,
                    :MGCMTBLDEF_N.DATA_10_TBL,
                    :MGCMTBLDEF_N.DATA_10_COL
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TABLE_NAME ,TABLE_DESC ,SYS_TBL_FLAG ,CENTRAL\
_FLAG ,TABLE_TYPE ,USE_SQL_FLAG ,TABLE_GROUP ,KEY_1_PRT ,KEY_1_FMT ,KEY_1_SI\
ZE ,KEY_2_PRT ,KEY_2_FMT ,KEY_2_SIZE ,KEY_3_PRT ,KEY_3_FMT ,KEY_3_SIZE ,KEY_\
4_PRT ,KEY_4_FMT ,KEY_4_SIZE ,KEY_5_PRT ,KEY_5_FMT ,KEY_5_SIZE ,KEY_6_PRT ,K\
EY_6_FMT ,KEY_6_SIZE ,KEY_7_PRT ,KEY_7_FMT ,KEY_7_SIZE ,KEY_8_PRT ,KEY_8_FMT\
 ,KEY_8_SIZE ,KEY_9_PRT ,KEY_9_FMT ,KEY_9_SIZE ,KEY_10_PRT ,KEY_10_FMT ,KEY_\
10_SIZE ,DATA_1_PRT ,DATA_1_FMT ,DATA_1_SIZE ,DATA_2_PRT ,DATA_2_FMT ,DATA_2\
_SIZE ,DATA_3_PRT ,DATA_3_FMT ,DATA_3_SIZE ,DATA_4_PRT ,DATA_4_FMT ,DATA_4_S\
IZE ,DATA_5_PRT ,DATA_5_FMT ,DATA_5_SIZE ,DATA_6_PRT ,DATA_6_FMT ,DATA_6_SIZ\
E ,DATA_7_PRT ,DATA_7_FMT ,DATA_7_SIZE ,DATA_8_PRT ,DATA_8_FMT ,DATA_8_SIZE \
,DATA_9_PRT ,DATA_9_FMT ,DATA_9_SIZE ,DATA_10_PRT ,DATA_10_FMT ,DATA_10_SIZE\
 ,SQL_1 ,SQL_2 ,SQL_3 ,SQL_4 ,SQL_5 ,TABLE_PASSWORD ,SEC_CHK_FLAG ,CREATE_US\
ER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,KEY_1_TBL ,KEY_1_COL ,KEY_2\
_TBL ,KEY_2_COL ,KEY_3_TBL ,KEY_3_COL ,KEY_4_TBL ,K");
            sqlbuft((void **)0,
              "EY_4_COL ,KEY_5_TBL ,KEY_5_COL ,KEY_6_TBL ,KEY_6_COL ,KEY_7_T\
BL ,KEY_7_COL ,KEY_8_TBL ,KEY_8_COL ,KEY_9_TBL ,KEY_9_COL ,KEY_10_TBL ,KEY_1\
0_COL ,DATA_1_TBL ,DATA_1_COL ,DATA_2_TBL ,DATA_2_COL ,DATA_3_TBL ,DATA_3_CO\
L ,DATA_4_TBL ,DATA_4_COL ,DATA_5_TBL ,DATA_5_COL ,DATA_6_TBL ,DATA_6_COL ,D\
ATA_7_TBL ,DATA_7_COL ,DATA_8_TBL ,DATA_8_COL ,DATA_9_TBL ,DATA_9_COL ,DATA_\
10_TBL ,DATA_10_COL into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:\
b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b\
27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b4\
2,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57\
,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,\
:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:\
b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102\
,:b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b1\
15,:b116,:b117,:b118  from MGCMTBLDEF where (FACTOR");
            sqlstm.stmt = "Y=:b0 and TABLE_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.USE_SQL_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMTBLDEF_N.KEY_1_PRT);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMTBLDEF_N.KEY_1_FMT);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MGCMTBLDEF_N.KEY_1_SIZE);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMTBLDEF_N.KEY_2_PRT);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMTBLDEF_N.KEY_2_FMT);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MGCMTBLDEF_N.KEY_2_SIZE);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMTBLDEF_N.KEY_3_PRT);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMTBLDEF_N.KEY_3_FMT);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MGCMTBLDEF_N.KEY_3_SIZE);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMTBLDEF_N.KEY_4_PRT);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMTBLDEF_N.KEY_4_FMT);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MGCMTBLDEF_N.KEY_4_SIZE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMTBLDEF_N.KEY_5_PRT);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMTBLDEF_N.KEY_5_FMT);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MGCMTBLDEF_N.KEY_5_SIZE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMTBLDEF_N.KEY_6_PRT);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMTBLDEF_N.KEY_6_FMT);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MGCMTBLDEF_N.KEY_6_SIZE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMTBLDEF_N.KEY_7_PRT);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMTBLDEF_N.KEY_7_FMT);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MGCMTBLDEF_N.KEY_7_SIZE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMTBLDEF_N.KEY_8_PRT);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMTBLDEF_N.KEY_8_FMT);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MGCMTBLDEF_N.KEY_8_SIZE);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMTBLDEF_N.KEY_9_PRT);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMTBLDEF_N.KEY_9_FMT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MGCMTBLDEF_N.KEY_9_SIZE);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMTBLDEF_N.KEY_10_PRT);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMTBLDEF_N.KEY_10_FMT);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MGCMTBLDEF_N.KEY_10_SIZE);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMTBLDEF_N.DATA_1_PRT);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMTBLDEF_N.DATA_1_FMT);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MGCMTBLDEF_N.DATA_1_SIZE);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MGCMTBLDEF_N.DATA_2_PRT);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MGCMTBLDEF_N.DATA_2_FMT);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(MGCMTBLDEF_N.DATA_2_SIZE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MGCMTBLDEF_N.DATA_3_PRT);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MGCMTBLDEF_N.DATA_3_FMT);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MGCMTBLDEF_N.DATA_3_SIZE);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MGCMTBLDEF_N.DATA_4_PRT);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MGCMTBLDEF_N.DATA_4_FMT);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MGCMTBLDEF_N.DATA_4_SIZE);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MGCMTBLDEF_N.DATA_5_PRT);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MGCMTBLDEF_N.DATA_5_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MGCMTBLDEF_N.DATA_5_SIZE);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MGCMTBLDEF_N.DATA_6_PRT);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MGCMTBLDEF_N.DATA_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MGCMTBLDEF_N.DATA_6_SIZE);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MGCMTBLDEF_N.DATA_7_PRT);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MGCMTBLDEF_N.DATA_7_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MGCMTBLDEF_N.DATA_7_SIZE);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MGCMTBLDEF_N.DATA_8_PRT);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MGCMTBLDEF_N.DATA_8_FMT);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MGCMTBLDEF_N.DATA_8_SIZE);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MGCMTBLDEF_N.DATA_9_PRT);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MGCMTBLDEF_N.DATA_9_FMT);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MGCMTBLDEF_N.DATA_9_SIZE);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MGCMTBLDEF_N.DATA_10_PRT);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MGCMTBLDEF_N.DATA_10_FMT);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MGCMTBLDEF_N.DATA_10_SIZE);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MGCMTBLDEF_N.SQL_1);
            sqlstm.sqhstl[68] = (unsigned int  )2001;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MGCMTBLDEF_N.SQL_2);
            sqlstm.sqhstl[69] = (unsigned int  )2001;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MGCMTBLDEF_N.SQL_3);
            sqlstm.sqhstl[70] = (unsigned int  )2001;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MGCMTBLDEF_N.SQL_4);
            sqlstm.sqhstl[71] = (unsigned int  )2001;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MGCMTBLDEF_N.SQL_5);
            sqlstm.sqhstl[72] = (unsigned int  )2001;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MGCMTBLDEF_N.TABLE_PASSWORD);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MGCMTBLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MGCMTBLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MGCMTBLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MGCMTBLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[78] = (unsigned int  )15;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MGCMTBLDEF_N.KEY_1_TBL);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MGCMTBLDEF_N.KEY_1_COL);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MGCMTBLDEF_N.KEY_2_TBL);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MGCMTBLDEF_N.KEY_2_COL);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MGCMTBLDEF_N.KEY_3_TBL);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MGCMTBLDEF_N.KEY_3_COL);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MGCMTBLDEF_N.KEY_4_TBL);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MGCMTBLDEF_N.KEY_4_COL);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MGCMTBLDEF_N.KEY_5_TBL);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MGCMTBLDEF_N.KEY_5_COL);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MGCMTBLDEF_N.KEY_6_TBL);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MGCMTBLDEF_N.KEY_6_COL);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MGCMTBLDEF_N.KEY_7_TBL);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MGCMTBLDEF_N.KEY_7_COL);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MGCMTBLDEF_N.KEY_8_TBL);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MGCMTBLDEF_N.KEY_8_COL);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MGCMTBLDEF_N.KEY_9_TBL);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MGCMTBLDEF_N.KEY_9_COL);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MGCMTBLDEF_N.KEY_10_TBL);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MGCMTBLDEF_N.KEY_10_COL);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MGCMTBLDEF_N.DATA_1_TBL);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MGCMTBLDEF_N.DATA_1_COL);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MGCMTBLDEF_N.DATA_2_TBL);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MGCMTBLDEF_N.DATA_2_COL);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MGCMTBLDEF_N.DATA_3_TBL);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MGCMTBLDEF_N.DATA_3_COL);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MGCMTBLDEF_N.DATA_4_TBL);
            sqlstm.sqhstl[105] = (unsigned int  )21;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MGCMTBLDEF_N.DATA_4_COL);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MGCMTBLDEF_N.DATA_5_TBL);
            sqlstm.sqhstl[107] = (unsigned int  )21;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MGCMTBLDEF_N.DATA_5_COL);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MGCMTBLDEF_N.DATA_6_TBL);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MGCMTBLDEF_N.DATA_6_COL);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MGCMTBLDEF_N.DATA_7_TBL);
            sqlstm.sqhstl[111] = (unsigned int  )21;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MGCMTBLDEF_N.DATA_7_COL);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MGCMTBLDEF_N.DATA_8_TBL);
            sqlstm.sqhstl[113] = (unsigned int  )21;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MGCMTBLDEF_N.DATA_8_COL);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MGCMTBLDEF_N.DATA_9_TBL);
            sqlstm.sqhstl[115] = (unsigned int  )21;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MGCMTBLDEF_N.DATA_9_COL);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MGCMTBLDEF_N.DATA_10_TBL);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MGCMTBLDEF_N.DATA_10_COL);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[119] = (unsigned int  )11;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
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
        DBC_del_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    }
    DB_stop_query_timer("DBC_select_mgcmtbldef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mgcmtbldef_for_update(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         TABLE_NAME,
                         TABLE_DESC,
                         SYS_TBL_FLAG,
                         CENTRAL_FLAG,
                         TABLE_TYPE,
                         USE_SQL_FLAG,
                         TABLE_GROUP,
                         KEY_1_PRT,
                         KEY_1_FMT,
                         KEY_1_SIZE,
                         KEY_2_PRT,
                         KEY_2_FMT,
                         KEY_2_SIZE,
                         KEY_3_PRT,
                         KEY_3_FMT,
                         KEY_3_SIZE,
                         KEY_4_PRT,
                         KEY_4_FMT,
                         KEY_4_SIZE,
                         KEY_5_PRT,
                         KEY_5_FMT,
                         KEY_5_SIZE,
                         KEY_6_PRT,
                         KEY_6_FMT,
                         KEY_6_SIZE,
                         KEY_7_PRT,
                         KEY_7_FMT,
                         KEY_7_SIZE,
                         KEY_8_PRT,
                         KEY_8_FMT,
                         KEY_8_SIZE,
                         KEY_9_PRT,
                         KEY_9_FMT,
                         KEY_9_SIZE,
                         KEY_10_PRT,
                         KEY_10_FMT,
                         KEY_10_SIZE,
                         DATA_1_PRT,
                         DATA_1_FMT,
                         DATA_1_SIZE,
                         DATA_2_PRT,
                         DATA_2_FMT,
                         DATA_2_SIZE,
                         DATA_3_PRT,
                         DATA_3_FMT,
                         DATA_3_SIZE,
                         DATA_4_PRT,
                         DATA_4_FMT,
                         DATA_4_SIZE,
                         DATA_5_PRT,
                         DATA_5_FMT,
                         DATA_5_SIZE,
                         DATA_6_PRT,
                         DATA_6_FMT,
                         DATA_6_SIZE,
                         DATA_7_PRT,
                         DATA_7_FMT,
                         DATA_7_SIZE,
                         DATA_8_PRT,
                         DATA_8_FMT,
                         DATA_8_SIZE,
                         DATA_9_PRT,
                         DATA_9_FMT,
                         DATA_9_SIZE,
                         DATA_10_PRT,
                         DATA_10_FMT,
                         DATA_10_SIZE,
                         SQL_1,
                         SQL_2,
                         SQL_3,
                         SQL_4,
                         SQL_5,
                         TABLE_PASSWORD,
                         SEC_CHK_FLAG,
                         CREATE_USER_ID,
                         CREATE_TIME,
                         UPDATE_USER_ID,
                         UPDATE_TIME,
                         KEY_1_TBL,
                         KEY_1_COL,
                         KEY_2_TBL,
                         KEY_2_COL,
                         KEY_3_TBL,
                         KEY_3_COL,
                         KEY_4_TBL,
                         KEY_4_COL,
                         KEY_5_TBL,
                         KEY_5_COL,
                         KEY_6_TBL,
                         KEY_6_COL,
                         KEY_7_TBL,
                         KEY_7_COL,
                         KEY_8_TBL,
                         KEY_8_COL,
                         KEY_9_TBL,
                         KEY_9_COL,
                         KEY_10_TBL,
                         KEY_10_COL,
                         DATA_1_TBL,
                         DATA_1_COL,
                         DATA_2_TBL,
                         DATA_2_COL,
                         DATA_3_TBL,
                         DATA_3_COL,
                         DATA_4_TBL,
                         DATA_4_COL,
                         DATA_5_TBL,
                         DATA_5_COL,
                         DATA_6_TBL,
                         DATA_6_COL,
                         DATA_7_TBL,
                         DATA_7_COL,
                         DATA_8_TBL,
                         DATA_8_COL,
                         DATA_9_TBL,
                         DATA_9_COL,
                         DATA_10_TBL,
                         DATA_10_COL
                INTO 
                    :MGCMTBLDEF_N.FACTORY,
                    :MGCMTBLDEF_N.TABLE_NAME,
                    :MGCMTBLDEF_N.TABLE_DESC,
                    :MGCMTBLDEF_N.SYS_TBL_FLAG,
                    :MGCMTBLDEF_N.CENTRAL_FLAG,
                    :MGCMTBLDEF_N.TABLE_TYPE,
                    :MGCMTBLDEF_N.USE_SQL_FLAG,
                    :MGCMTBLDEF_N.TABLE_GROUP,
                    :MGCMTBLDEF_N.KEY_1_PRT,
                    :MGCMTBLDEF_N.KEY_1_FMT,
                    :MGCMTBLDEF_N.KEY_1_SIZE,
                    :MGCMTBLDEF_N.KEY_2_PRT,
                    :MGCMTBLDEF_N.KEY_2_FMT,
                    :MGCMTBLDEF_N.KEY_2_SIZE,
                    :MGCMTBLDEF_N.KEY_3_PRT,
                    :MGCMTBLDEF_N.KEY_3_FMT,
                    :MGCMTBLDEF_N.KEY_3_SIZE,
                    :MGCMTBLDEF_N.KEY_4_PRT,
                    :MGCMTBLDEF_N.KEY_4_FMT,
                    :MGCMTBLDEF_N.KEY_4_SIZE,
                    :MGCMTBLDEF_N.KEY_5_PRT,
                    :MGCMTBLDEF_N.KEY_5_FMT,
                    :MGCMTBLDEF_N.KEY_5_SIZE,
                    :MGCMTBLDEF_N.KEY_6_PRT,
                    :MGCMTBLDEF_N.KEY_6_FMT,
                    :MGCMTBLDEF_N.KEY_6_SIZE,
                    :MGCMTBLDEF_N.KEY_7_PRT,
                    :MGCMTBLDEF_N.KEY_7_FMT,
                    :MGCMTBLDEF_N.KEY_7_SIZE,
                    :MGCMTBLDEF_N.KEY_8_PRT,
                    :MGCMTBLDEF_N.KEY_8_FMT,
                    :MGCMTBLDEF_N.KEY_8_SIZE,
                    :MGCMTBLDEF_N.KEY_9_PRT,
                    :MGCMTBLDEF_N.KEY_9_FMT,
                    :MGCMTBLDEF_N.KEY_9_SIZE,
                    :MGCMTBLDEF_N.KEY_10_PRT,
                    :MGCMTBLDEF_N.KEY_10_FMT,
                    :MGCMTBLDEF_N.KEY_10_SIZE,
                    :MGCMTBLDEF_N.DATA_1_PRT,
                    :MGCMTBLDEF_N.DATA_1_FMT,
                    :MGCMTBLDEF_N.DATA_1_SIZE,
                    :MGCMTBLDEF_N.DATA_2_PRT,
                    :MGCMTBLDEF_N.DATA_2_FMT,
                    :MGCMTBLDEF_N.DATA_2_SIZE,
                    :MGCMTBLDEF_N.DATA_3_PRT,
                    :MGCMTBLDEF_N.DATA_3_FMT,
                    :MGCMTBLDEF_N.DATA_3_SIZE,
                    :MGCMTBLDEF_N.DATA_4_PRT,
                    :MGCMTBLDEF_N.DATA_4_FMT,
                    :MGCMTBLDEF_N.DATA_4_SIZE,
                    :MGCMTBLDEF_N.DATA_5_PRT,
                    :MGCMTBLDEF_N.DATA_5_FMT,
                    :MGCMTBLDEF_N.DATA_5_SIZE,
                    :MGCMTBLDEF_N.DATA_6_PRT,
                    :MGCMTBLDEF_N.DATA_6_FMT,
                    :MGCMTBLDEF_N.DATA_6_SIZE,
                    :MGCMTBLDEF_N.DATA_7_PRT,
                    :MGCMTBLDEF_N.DATA_7_FMT,
                    :MGCMTBLDEF_N.DATA_7_SIZE,
                    :MGCMTBLDEF_N.DATA_8_PRT,
                    :MGCMTBLDEF_N.DATA_8_FMT,
                    :MGCMTBLDEF_N.DATA_8_SIZE,
                    :MGCMTBLDEF_N.DATA_9_PRT,
                    :MGCMTBLDEF_N.DATA_9_FMT,
                    :MGCMTBLDEF_N.DATA_9_SIZE,
                    :MGCMTBLDEF_N.DATA_10_PRT,
                    :MGCMTBLDEF_N.DATA_10_FMT,
                    :MGCMTBLDEF_N.DATA_10_SIZE,
                    :MGCMTBLDEF_N.SQL_1,
                    :MGCMTBLDEF_N.SQL_2,
                    :MGCMTBLDEF_N.SQL_3,
                    :MGCMTBLDEF_N.SQL_4,
                    :MGCMTBLDEF_N.SQL_5,
                    :MGCMTBLDEF_N.TABLE_PASSWORD,
                    :MGCMTBLDEF_N.SEC_CHK_FLAG,
                    :MGCMTBLDEF_N.CREATE_USER_ID,
                    :MGCMTBLDEF_N.CREATE_TIME,
                    :MGCMTBLDEF_N.UPDATE_USER_ID,
                    :MGCMTBLDEF_N.UPDATE_TIME,
                    :MGCMTBLDEF_N.KEY_1_TBL,
                    :MGCMTBLDEF_N.KEY_1_COL,
                    :MGCMTBLDEF_N.KEY_2_TBL,
                    :MGCMTBLDEF_N.KEY_2_COL,
                    :MGCMTBLDEF_N.KEY_3_TBL,
                    :MGCMTBLDEF_N.KEY_3_COL,
                    :MGCMTBLDEF_N.KEY_4_TBL,
                    :MGCMTBLDEF_N.KEY_4_COL,
                    :MGCMTBLDEF_N.KEY_5_TBL,
                    :MGCMTBLDEF_N.KEY_5_COL,
                    :MGCMTBLDEF_N.KEY_6_TBL,
                    :MGCMTBLDEF_N.KEY_6_COL,
                    :MGCMTBLDEF_N.KEY_7_TBL,
                    :MGCMTBLDEF_N.KEY_7_COL,
                    :MGCMTBLDEF_N.KEY_8_TBL,
                    :MGCMTBLDEF_N.KEY_8_COL,
                    :MGCMTBLDEF_N.KEY_9_TBL,
                    :MGCMTBLDEF_N.KEY_9_COL,
                    :MGCMTBLDEF_N.KEY_10_TBL,
                    :MGCMTBLDEF_N.KEY_10_COL,
                    :MGCMTBLDEF_N.DATA_1_TBL,
                    :MGCMTBLDEF_N.DATA_1_COL,
                    :MGCMTBLDEF_N.DATA_2_TBL,
                    :MGCMTBLDEF_N.DATA_2_COL,
                    :MGCMTBLDEF_N.DATA_3_TBL,
                    :MGCMTBLDEF_N.DATA_3_COL,
                    :MGCMTBLDEF_N.DATA_4_TBL,
                    :MGCMTBLDEF_N.DATA_4_COL,
                    :MGCMTBLDEF_N.DATA_5_TBL,
                    :MGCMTBLDEF_N.DATA_5_COL,
                    :MGCMTBLDEF_N.DATA_6_TBL,
                    :MGCMTBLDEF_N.DATA_6_COL,
                    :MGCMTBLDEF_N.DATA_7_TBL,
                    :MGCMTBLDEF_N.DATA_7_COL,
                    :MGCMTBLDEF_N.DATA_8_TBL,
                    :MGCMTBLDEF_N.DATA_8_COL,
                    :MGCMTBLDEF_N.DATA_9_TBL,
                    :MGCMTBLDEF_N.DATA_9_COL,
                    :MGCMTBLDEF_N.DATA_10_TBL,
                    :MGCMTBLDEF_N.DATA_10_COL
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TABLE_NAME ,TABLE_DESC ,SYS_TBL_FLAG ,CENTRAL\
_FLAG ,TABLE_TYPE ,USE_SQL_FLAG ,TABLE_GROUP ,KEY_1_PRT ,KEY_1_FMT ,KEY_1_SI\
ZE ,KEY_2_PRT ,KEY_2_FMT ,KEY_2_SIZE ,KEY_3_PRT ,KEY_3_FMT ,KEY_3_SIZE ,KEY_\
4_PRT ,KEY_4_FMT ,KEY_4_SIZE ,KEY_5_PRT ,KEY_5_FMT ,KEY_5_SIZE ,KEY_6_PRT ,K\
EY_6_FMT ,KEY_6_SIZE ,KEY_7_PRT ,KEY_7_FMT ,KEY_7_SIZE ,KEY_8_PRT ,KEY_8_FMT\
 ,KEY_8_SIZE ,KEY_9_PRT ,KEY_9_FMT ,KEY_9_SIZE ,KEY_10_PRT ,KEY_10_FMT ,KEY_\
10_SIZE ,DATA_1_PRT ,DATA_1_FMT ,DATA_1_SIZE ,DATA_2_PRT ,DATA_2_FMT ,DATA_2\
_SIZE ,DATA_3_PRT ,DATA_3_FMT ,DATA_3_SIZE ,DATA_4_PRT ,DATA_4_FMT ,DATA_4_S\
IZE ,DATA_5_PRT ,DATA_5_FMT ,DATA_5_SIZE ,DATA_6_PRT ,DATA_6_FMT ,DATA_6_SIZ\
E ,DATA_7_PRT ,DATA_7_FMT ,DATA_7_SIZE ,DATA_8_PRT ,DATA_8_FMT ,DATA_8_SIZE \
,DATA_9_PRT ,DATA_9_FMT ,DATA_9_SIZE ,DATA_10_PRT ,DATA_10_FMT ,DATA_10_SIZE\
 ,SQL_1 ,SQL_2 ,SQL_3 ,SQL_4 ,SQL_5 ,TABLE_PASSWORD ,SEC_CHK_FLAG ,CREATE_US\
ER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,KEY_1_TBL ,KEY_1_COL ,KEY_2\
_TBL ,KEY_2_COL ,KEY_3_TBL ,KEY_3_COL ,KEY_4_TBL ,K");
            sqlbuft((void **)0,
              "EY_4_COL ,KEY_5_TBL ,KEY_5_COL ,KEY_6_TBL ,KEY_6_COL ,KEY_7_T\
BL ,KEY_7_COL ,KEY_8_TBL ,KEY_8_COL ,KEY_9_TBL ,KEY_9_COL ,KEY_10_TBL ,KEY_1\
0_COL ,DATA_1_TBL ,DATA_1_COL ,DATA_2_TBL ,DATA_2_COL ,DATA_3_TBL ,DATA_3_CO\
L ,DATA_4_TBL ,DATA_4_COL ,DATA_5_TBL ,DATA_5_COL ,DATA_6_TBL ,DATA_6_COL ,D\
ATA_7_TBL ,DATA_7_COL ,DATA_8_TBL ,DATA_8_COL ,DATA_9_TBL ,DATA_9_COL ,DATA_\
10_TBL ,DATA_10_COL into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:\
b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b\
27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b4\
2,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57\
,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,\
:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:\
b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102\
,:b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b1\
15,:b116,:b117,:b118  from MGCMTBLDEF where (FACTOR");
            sqlstm.stmt = "Y=:b0 and TABLE_NAME=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )504;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.USE_SQL_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMTBLDEF_N.KEY_1_PRT);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMTBLDEF_N.KEY_1_FMT);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MGCMTBLDEF_N.KEY_1_SIZE);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMTBLDEF_N.KEY_2_PRT);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMTBLDEF_N.KEY_2_FMT);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MGCMTBLDEF_N.KEY_2_SIZE);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMTBLDEF_N.KEY_3_PRT);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMTBLDEF_N.KEY_3_FMT);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MGCMTBLDEF_N.KEY_3_SIZE);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMTBLDEF_N.KEY_4_PRT);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMTBLDEF_N.KEY_4_FMT);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MGCMTBLDEF_N.KEY_4_SIZE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMTBLDEF_N.KEY_5_PRT);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMTBLDEF_N.KEY_5_FMT);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MGCMTBLDEF_N.KEY_5_SIZE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMTBLDEF_N.KEY_6_PRT);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMTBLDEF_N.KEY_6_FMT);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MGCMTBLDEF_N.KEY_6_SIZE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMTBLDEF_N.KEY_7_PRT);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMTBLDEF_N.KEY_7_FMT);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MGCMTBLDEF_N.KEY_7_SIZE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMTBLDEF_N.KEY_8_PRT);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMTBLDEF_N.KEY_8_FMT);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MGCMTBLDEF_N.KEY_8_SIZE);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMTBLDEF_N.KEY_9_PRT);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMTBLDEF_N.KEY_9_FMT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MGCMTBLDEF_N.KEY_9_SIZE);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMTBLDEF_N.KEY_10_PRT);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMTBLDEF_N.KEY_10_FMT);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MGCMTBLDEF_N.KEY_10_SIZE);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMTBLDEF_N.DATA_1_PRT);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMTBLDEF_N.DATA_1_FMT);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MGCMTBLDEF_N.DATA_1_SIZE);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MGCMTBLDEF_N.DATA_2_PRT);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MGCMTBLDEF_N.DATA_2_FMT);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(MGCMTBLDEF_N.DATA_2_SIZE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MGCMTBLDEF_N.DATA_3_PRT);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MGCMTBLDEF_N.DATA_3_FMT);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MGCMTBLDEF_N.DATA_3_SIZE);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MGCMTBLDEF_N.DATA_4_PRT);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MGCMTBLDEF_N.DATA_4_FMT);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MGCMTBLDEF_N.DATA_4_SIZE);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MGCMTBLDEF_N.DATA_5_PRT);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MGCMTBLDEF_N.DATA_5_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MGCMTBLDEF_N.DATA_5_SIZE);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MGCMTBLDEF_N.DATA_6_PRT);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MGCMTBLDEF_N.DATA_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MGCMTBLDEF_N.DATA_6_SIZE);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MGCMTBLDEF_N.DATA_7_PRT);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MGCMTBLDEF_N.DATA_7_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MGCMTBLDEF_N.DATA_7_SIZE);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MGCMTBLDEF_N.DATA_8_PRT);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MGCMTBLDEF_N.DATA_8_FMT);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MGCMTBLDEF_N.DATA_8_SIZE);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MGCMTBLDEF_N.DATA_9_PRT);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MGCMTBLDEF_N.DATA_9_FMT);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MGCMTBLDEF_N.DATA_9_SIZE);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MGCMTBLDEF_N.DATA_10_PRT);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MGCMTBLDEF_N.DATA_10_FMT);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MGCMTBLDEF_N.DATA_10_SIZE);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MGCMTBLDEF_N.SQL_1);
            sqlstm.sqhstl[68] = (unsigned int  )2001;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MGCMTBLDEF_N.SQL_2);
            sqlstm.sqhstl[69] = (unsigned int  )2001;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MGCMTBLDEF_N.SQL_3);
            sqlstm.sqhstl[70] = (unsigned int  )2001;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MGCMTBLDEF_N.SQL_4);
            sqlstm.sqhstl[71] = (unsigned int  )2001;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MGCMTBLDEF_N.SQL_5);
            sqlstm.sqhstl[72] = (unsigned int  )2001;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MGCMTBLDEF_N.TABLE_PASSWORD);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MGCMTBLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MGCMTBLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MGCMTBLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MGCMTBLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[78] = (unsigned int  )15;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MGCMTBLDEF_N.KEY_1_TBL);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MGCMTBLDEF_N.KEY_1_COL);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MGCMTBLDEF_N.KEY_2_TBL);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MGCMTBLDEF_N.KEY_2_COL);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MGCMTBLDEF_N.KEY_3_TBL);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MGCMTBLDEF_N.KEY_3_COL);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MGCMTBLDEF_N.KEY_4_TBL);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MGCMTBLDEF_N.KEY_4_COL);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MGCMTBLDEF_N.KEY_5_TBL);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MGCMTBLDEF_N.KEY_5_COL);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MGCMTBLDEF_N.KEY_6_TBL);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MGCMTBLDEF_N.KEY_6_COL);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MGCMTBLDEF_N.KEY_7_TBL);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MGCMTBLDEF_N.KEY_7_COL);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MGCMTBLDEF_N.KEY_8_TBL);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MGCMTBLDEF_N.KEY_8_COL);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MGCMTBLDEF_N.KEY_9_TBL);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MGCMTBLDEF_N.KEY_9_COL);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MGCMTBLDEF_N.KEY_10_TBL);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MGCMTBLDEF_N.KEY_10_COL);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MGCMTBLDEF_N.DATA_1_TBL);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MGCMTBLDEF_N.DATA_1_COL);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MGCMTBLDEF_N.DATA_2_TBL);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MGCMTBLDEF_N.DATA_2_COL);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MGCMTBLDEF_N.DATA_3_TBL);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MGCMTBLDEF_N.DATA_3_COL);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MGCMTBLDEF_N.DATA_4_TBL);
            sqlstm.sqhstl[105] = (unsigned int  )21;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MGCMTBLDEF_N.DATA_4_COL);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MGCMTBLDEF_N.DATA_5_TBL);
            sqlstm.sqhstl[107] = (unsigned int  )21;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MGCMTBLDEF_N.DATA_5_COL);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MGCMTBLDEF_N.DATA_6_TBL);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MGCMTBLDEF_N.DATA_6_COL);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MGCMTBLDEF_N.DATA_7_TBL);
            sqlstm.sqhstl[111] = (unsigned int  )21;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MGCMTBLDEF_N.DATA_7_COL);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MGCMTBLDEF_N.DATA_8_TBL);
            sqlstm.sqhstl[113] = (unsigned int  )21;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MGCMTBLDEF_N.DATA_8_COL);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MGCMTBLDEF_N.DATA_9_TBL);
            sqlstm.sqhstl[115] = (unsigned int  )21;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MGCMTBLDEF_N.DATA_9_COL);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MGCMTBLDEF_N.DATA_10_TBL);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MGCMTBLDEF_N.DATA_10_COL);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[119] = (unsigned int  )11;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
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
        DBC_del_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    }
    DB_stop_query_timer("DBC_select_mgcmtbldef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mgcmtbldef_scalar(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    
    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MGCMTBLDEF where\
 (FACTORY=:b1 and TABLE_NAME=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1003;
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
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
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

    DB_stop_query_timer("DBC_select_mgcmtbldef_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mgcmtbldef(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MGCMTBLDEF  where (FACTORY=:b0 and \
TABLE_NAME=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1030;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
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
            /* EXEC SQL DELETE FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MGCMTBLDEF  where FACTORY=:b0";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1053;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
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
    DB_stop_query_timer("DBC_delete_mgcmtbldef", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mgcmtbldef(struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MGCMTBLDEF (
                    FACTORY,
                    TABLE_NAME,
                    TABLE_DESC,
                    SYS_TBL_FLAG,
                    CENTRAL_FLAG,
                    TABLE_TYPE,
                    USE_SQL_FLAG,
                    TABLE_GROUP,
                    KEY_1_PRT,
                    KEY_1_FMT,
                    KEY_1_SIZE,
                    KEY_2_PRT,
                    KEY_2_FMT,
                    KEY_2_SIZE,
                    KEY_3_PRT,
                    KEY_3_FMT,
                    KEY_3_SIZE,
                    KEY_4_PRT,
                    KEY_4_FMT,
                    KEY_4_SIZE,
                    KEY_5_PRT,
                    KEY_5_FMT,
                    KEY_5_SIZE,
                    KEY_6_PRT,
                    KEY_6_FMT,
                    KEY_6_SIZE,
                    KEY_7_PRT,
                    KEY_7_FMT,
                    KEY_7_SIZE,
                    KEY_8_PRT,
                    KEY_8_FMT,
                    KEY_8_SIZE,
                    KEY_9_PRT,
                    KEY_9_FMT,
                    KEY_9_SIZE,
                    KEY_10_PRT,
                    KEY_10_FMT,
                    KEY_10_SIZE,
                    DATA_1_PRT,
                    DATA_1_FMT,
                    DATA_1_SIZE,
                    DATA_2_PRT,
                    DATA_2_FMT,
                    DATA_2_SIZE,
                    DATA_3_PRT,
                    DATA_3_FMT,
                    DATA_3_SIZE,
                    DATA_4_PRT,
                    DATA_4_FMT,
                    DATA_4_SIZE,
                    DATA_5_PRT,
                    DATA_5_FMT,
                    DATA_5_SIZE,
                    DATA_6_PRT,
                    DATA_6_FMT,
                    DATA_6_SIZE,
                    DATA_7_PRT,
                    DATA_7_FMT,
                    DATA_7_SIZE,
                    DATA_8_PRT,
                    DATA_8_FMT,
                    DATA_8_SIZE,
                    DATA_9_PRT,
                    DATA_9_FMT,
                    DATA_9_SIZE,
                    DATA_10_PRT,
                    DATA_10_FMT,
                    DATA_10_SIZE,
                    SQL_1,
                    SQL_2,
                    SQL_3,
                    SQL_4,
                    SQL_5,
                    TABLE_PASSWORD,
                    SEC_CHK_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    KEY_1_TBL,
                    KEY_1_COL,
                    KEY_2_TBL,
                    KEY_2_COL,
                    KEY_3_TBL,
                    KEY_3_COL,
                    KEY_4_TBL,
                    KEY_4_COL,
                    KEY_5_TBL,
                    KEY_5_COL,
                    KEY_6_TBL,
                    KEY_6_COL,
                    KEY_7_TBL,
                    KEY_7_COL,
                    KEY_8_TBL,
                    KEY_8_COL,
                    KEY_9_TBL,
                    KEY_9_COL,
                    KEY_10_TBL,
                    KEY_10_COL,
                    DATA_1_TBL,
                    DATA_1_COL,
                    DATA_2_TBL,
                    DATA_2_COL,
                    DATA_3_TBL,
                    DATA_3_COL,
                    DATA_4_TBL,
                    DATA_4_COL,
                    DATA_5_TBL,
                    DATA_5_COL,
                    DATA_6_TBL,
                    DATA_6_COL,
                    DATA_7_TBL,
                    DATA_7_COL,
                    DATA_8_TBL,
                    DATA_8_COL,
                    DATA_9_TBL,
                    DATA_9_COL,
                    DATA_10_TBL,
                    DATA_10_COL
        )
        VALUES (
                    :MGCMTBLDEF_N.FACTORY,
                    :MGCMTBLDEF_N.TABLE_NAME,
                    :MGCMTBLDEF_N.TABLE_DESC,
                    :MGCMTBLDEF_N.SYS_TBL_FLAG,
                    :MGCMTBLDEF_N.CENTRAL_FLAG,
                    :MGCMTBLDEF_N.TABLE_TYPE,
                    :MGCMTBLDEF_N.USE_SQL_FLAG,
                    :MGCMTBLDEF_N.TABLE_GROUP,
                    :MGCMTBLDEF_N.KEY_1_PRT,
                    :MGCMTBLDEF_N.KEY_1_FMT,
                    :MGCMTBLDEF_N.KEY_1_SIZE,
                    :MGCMTBLDEF_N.KEY_2_PRT,
                    :MGCMTBLDEF_N.KEY_2_FMT,
                    :MGCMTBLDEF_N.KEY_2_SIZE,
                    :MGCMTBLDEF_N.KEY_3_PRT,
                    :MGCMTBLDEF_N.KEY_3_FMT,
                    :MGCMTBLDEF_N.KEY_3_SIZE,
                    :MGCMTBLDEF_N.KEY_4_PRT,
                    :MGCMTBLDEF_N.KEY_4_FMT,
                    :MGCMTBLDEF_N.KEY_4_SIZE,
                    :MGCMTBLDEF_N.KEY_5_PRT,
                    :MGCMTBLDEF_N.KEY_5_FMT,
                    :MGCMTBLDEF_N.KEY_5_SIZE,
                    :MGCMTBLDEF_N.KEY_6_PRT,
                    :MGCMTBLDEF_N.KEY_6_FMT,
                    :MGCMTBLDEF_N.KEY_6_SIZE,
                    :MGCMTBLDEF_N.KEY_7_PRT,
                    :MGCMTBLDEF_N.KEY_7_FMT,
                    :MGCMTBLDEF_N.KEY_7_SIZE,
                    :MGCMTBLDEF_N.KEY_8_PRT,
                    :MGCMTBLDEF_N.KEY_8_FMT,
                    :MGCMTBLDEF_N.KEY_8_SIZE,
                    :MGCMTBLDEF_N.KEY_9_PRT,
                    :MGCMTBLDEF_N.KEY_9_FMT,
                    :MGCMTBLDEF_N.KEY_9_SIZE,
                    :MGCMTBLDEF_N.KEY_10_PRT,
                    :MGCMTBLDEF_N.KEY_10_FMT,
                    :MGCMTBLDEF_N.KEY_10_SIZE,
                    :MGCMTBLDEF_N.DATA_1_PRT,
                    :MGCMTBLDEF_N.DATA_1_FMT,
                    :MGCMTBLDEF_N.DATA_1_SIZE,
                    :MGCMTBLDEF_N.DATA_2_PRT,
                    :MGCMTBLDEF_N.DATA_2_FMT,
                    :MGCMTBLDEF_N.DATA_2_SIZE,
                    :MGCMTBLDEF_N.DATA_3_PRT,
                    :MGCMTBLDEF_N.DATA_3_FMT,
                    :MGCMTBLDEF_N.DATA_3_SIZE,
                    :MGCMTBLDEF_N.DATA_4_PRT,
                    :MGCMTBLDEF_N.DATA_4_FMT,
                    :MGCMTBLDEF_N.DATA_4_SIZE,
                    :MGCMTBLDEF_N.DATA_5_PRT,
                    :MGCMTBLDEF_N.DATA_5_FMT,
                    :MGCMTBLDEF_N.DATA_5_SIZE,
                    :MGCMTBLDEF_N.DATA_6_PRT,
                    :MGCMTBLDEF_N.DATA_6_FMT,
                    :MGCMTBLDEF_N.DATA_6_SIZE,
                    :MGCMTBLDEF_N.DATA_7_PRT,
                    :MGCMTBLDEF_N.DATA_7_FMT,
                    :MGCMTBLDEF_N.DATA_7_SIZE,
                    :MGCMTBLDEF_N.DATA_8_PRT,
                    :MGCMTBLDEF_N.DATA_8_FMT,
                    :MGCMTBLDEF_N.DATA_8_SIZE,
                    :MGCMTBLDEF_N.DATA_9_PRT,
                    :MGCMTBLDEF_N.DATA_9_FMT,
                    :MGCMTBLDEF_N.DATA_9_SIZE,
                    :MGCMTBLDEF_N.DATA_10_PRT,
                    :MGCMTBLDEF_N.DATA_10_FMT,
                    :MGCMTBLDEF_N.DATA_10_SIZE,
                    :MGCMTBLDEF_N.SQL_1,
                    :MGCMTBLDEF_N.SQL_2,
                    :MGCMTBLDEF_N.SQL_3,
                    :MGCMTBLDEF_N.SQL_4,
                    :MGCMTBLDEF_N.SQL_5,
                    :MGCMTBLDEF_N.TABLE_PASSWORD,
                    :MGCMTBLDEF_N.SEC_CHK_FLAG,
                    :MGCMTBLDEF_N.CREATE_USER_ID,
                    :MGCMTBLDEF_N.CREATE_TIME,
                    :MGCMTBLDEF_N.UPDATE_USER_ID,
                    :MGCMTBLDEF_N.UPDATE_TIME,
                    :MGCMTBLDEF_N.KEY_1_TBL,
                    :MGCMTBLDEF_N.KEY_1_COL,
                    :MGCMTBLDEF_N.KEY_2_TBL,
                    :MGCMTBLDEF_N.KEY_2_COL,
                    :MGCMTBLDEF_N.KEY_3_TBL,
                    :MGCMTBLDEF_N.KEY_3_COL,
                    :MGCMTBLDEF_N.KEY_4_TBL,
                    :MGCMTBLDEF_N.KEY_4_COL,
                    :MGCMTBLDEF_N.KEY_5_TBL,
                    :MGCMTBLDEF_N.KEY_5_COL,
                    :MGCMTBLDEF_N.KEY_6_TBL,
                    :MGCMTBLDEF_N.KEY_6_COL,
                    :MGCMTBLDEF_N.KEY_7_TBL,
                    :MGCMTBLDEF_N.KEY_7_COL,
                    :MGCMTBLDEF_N.KEY_8_TBL,
                    :MGCMTBLDEF_N.KEY_8_COL,
                    :MGCMTBLDEF_N.KEY_9_TBL,
                    :MGCMTBLDEF_N.KEY_9_COL,
                    :MGCMTBLDEF_N.KEY_10_TBL,
                    :MGCMTBLDEF_N.KEY_10_COL,
                    :MGCMTBLDEF_N.DATA_1_TBL,
                    :MGCMTBLDEF_N.DATA_1_COL,
                    :MGCMTBLDEF_N.DATA_2_TBL,
                    :MGCMTBLDEF_N.DATA_2_COL,
                    :MGCMTBLDEF_N.DATA_3_TBL,
                    :MGCMTBLDEF_N.DATA_3_COL,
                    :MGCMTBLDEF_N.DATA_4_TBL,
                    :MGCMTBLDEF_N.DATA_4_COL,
                    :MGCMTBLDEF_N.DATA_5_TBL,
                    :MGCMTBLDEF_N.DATA_5_COL,
                    :MGCMTBLDEF_N.DATA_6_TBL,
                    :MGCMTBLDEF_N.DATA_6_COL,
                    :MGCMTBLDEF_N.DATA_7_TBL,
                    :MGCMTBLDEF_N.DATA_7_COL,
                    :MGCMTBLDEF_N.DATA_8_TBL,
                    :MGCMTBLDEF_N.DATA_8_COL,
                    :MGCMTBLDEF_N.DATA_9_TBL,
                    :MGCMTBLDEF_N.DATA_9_COL,
                    :MGCMTBLDEF_N.DATA_10_TBL,
                    :MGCMTBLDEF_N.DATA_10_COL
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 121;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MGCMTBLDEF (FACTORY,TABLE_NAME,TABLE_DESC,SYS_TBL_FLAG,CE\
NTRAL_FLAG,TABLE_TYPE,USE_SQL_FLAG,TABLE_GROUP,KEY_1_PRT,KEY_1_FMT,KEY_1_SIZ\
E,KEY_2_PRT,KEY_2_FMT,KEY_2_SIZE,KEY_3_PRT,KEY_3_FMT,KEY_3_SIZE,KEY_4_PRT,KE\
Y_4_FMT,KEY_4_SIZE,KEY_5_PRT,KEY_5_FMT,KEY_5_SIZE,KEY_6_PRT,KEY_6_FMT,KEY_6_\
SIZE,KEY_7_PRT,KEY_7_FMT,KEY_7_SIZE,KEY_8_PRT,KEY_8_FMT,KEY_8_SIZE,KEY_9_PRT\
,KEY_9_FMT,KEY_9_SIZE,KEY_10_PRT,KEY_10_FMT,KEY_10_SIZE,DATA_1_PRT,DATA_1_FM\
T,DATA_1_SIZE,DATA_2_PRT,DATA_2_FMT,DATA_2_SIZE,DATA_3_PRT,DATA_3_FMT,DATA_3\
_SIZE,DATA_4_PRT,DATA_4_FMT,DATA_4_SIZE,DATA_5_PRT,DATA_5_FMT,DATA_5_SIZE,DA\
TA_6_PRT,DATA_6_FMT,DATA_6_SIZE,DATA_7_PRT,DATA_7_FMT,DATA_7_SIZE,DATA_8_PRT\
,DATA_8_FMT,DATA_8_SIZE,DATA_9_PRT,DATA_9_FMT,DATA_9_SIZE,DATA_10_PRT,DATA_1\
0_FMT,DATA_10_SIZE,SQL_1,SQL_2,SQL_3,SQL_4,SQL_5,TABLE_PASSWORD,SEC_CHK_FLAG\
,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME,KEY_1_TBL,KEY_1_COL,K\
EY_2_TBL,KEY_2_COL,KEY_3_TBL,KEY_3_COL,KEY_4_TBL,KEY_4_COL,KEY_5_TBL,KEY_5_C\
OL,KEY_6_TBL,KEY_6_COL,KEY_7_TBL,KEY_7_COL,");
    sqlstm.stmt = "KEY_8_TBL,KEY_8_COL,KEY_9_TBL,KEY_9_COL,KEY_10_TBL,KEY_1\
0_COL,DATA_1_TBL,DATA_1_COL,DATA_2_TBL,DATA_2_COL,DATA_3_TBL,DATA_3_COL,DATA_\
4_TBL,DATA_4_COL,DATA_5_TBL,DATA_5_COL,DATA_6_TBL,DATA_6_COL,DATA_7_TBL,DATA_\
7_COL,DATA_8_TBL,DATA_8_COL,DATA_9_TBL,DATA_9_COL,DATA_10_TBL,DATA_10_COL) va\
lues (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:\
b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b3\
1,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,\
:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b\
62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77\
,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:\
b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:\
b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1072;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
    sqlstm.sqhstl[3] = (unsigned int  )2;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
    sqlstm.sqhstl[5] = (unsigned int  )2;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.USE_SQL_FLAG);
    sqlstm.sqhstl[6] = (unsigned int  )2;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
    sqlstm.sqhstl[7] = (unsigned int  )21;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MGCMTBLDEF_N.KEY_1_PRT);
    sqlstm.sqhstl[8] = (unsigned int  )21;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MGCMTBLDEF_N.KEY_1_FMT);
    sqlstm.sqhstl[9] = (unsigned int  )2;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)&(MGCMTBLDEF_N.KEY_1_SIZE);
    sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MGCMTBLDEF_N.KEY_2_PRT);
    sqlstm.sqhstl[11] = (unsigned int  )21;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MGCMTBLDEF_N.KEY_2_FMT);
    sqlstm.sqhstl[12] = (unsigned int  )2;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(MGCMTBLDEF_N.KEY_2_SIZE);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MGCMTBLDEF_N.KEY_3_PRT);
    sqlstm.sqhstl[14] = (unsigned int  )21;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MGCMTBLDEF_N.KEY_3_FMT);
    sqlstm.sqhstl[15] = (unsigned int  )2;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(MGCMTBLDEF_N.KEY_3_SIZE);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MGCMTBLDEF_N.KEY_4_PRT);
    sqlstm.sqhstl[17] = (unsigned int  )21;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MGCMTBLDEF_N.KEY_4_FMT);
    sqlstm.sqhstl[18] = (unsigned int  )2;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)&(MGCMTBLDEF_N.KEY_4_SIZE);
    sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MGCMTBLDEF_N.KEY_5_PRT);
    sqlstm.sqhstl[20] = (unsigned int  )21;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MGCMTBLDEF_N.KEY_5_FMT);
    sqlstm.sqhstl[21] = (unsigned int  )2;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)&(MGCMTBLDEF_N.KEY_5_SIZE);
    sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MGCMTBLDEF_N.KEY_6_PRT);
    sqlstm.sqhstl[23] = (unsigned int  )21;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MGCMTBLDEF_N.KEY_6_FMT);
    sqlstm.sqhstl[24] = (unsigned int  )2;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(MGCMTBLDEF_N.KEY_6_SIZE);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MGCMTBLDEF_N.KEY_7_PRT);
    sqlstm.sqhstl[26] = (unsigned int  )21;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MGCMTBLDEF_N.KEY_7_FMT);
    sqlstm.sqhstl[27] = (unsigned int  )2;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)&(MGCMTBLDEF_N.KEY_7_SIZE);
    sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MGCMTBLDEF_N.KEY_8_PRT);
    sqlstm.sqhstl[29] = (unsigned int  )21;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MGCMTBLDEF_N.KEY_8_FMT);
    sqlstm.sqhstl[30] = (unsigned int  )2;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)&(MGCMTBLDEF_N.KEY_8_SIZE);
    sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MGCMTBLDEF_N.KEY_9_PRT);
    sqlstm.sqhstl[32] = (unsigned int  )21;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MGCMTBLDEF_N.KEY_9_FMT);
    sqlstm.sqhstl[33] = (unsigned int  )2;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)&(MGCMTBLDEF_N.KEY_9_SIZE);
    sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MGCMTBLDEF_N.KEY_10_PRT);
    sqlstm.sqhstl[35] = (unsigned int  )21;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MGCMTBLDEF_N.KEY_10_FMT);
    sqlstm.sqhstl[36] = (unsigned int  )2;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(MGCMTBLDEF_N.KEY_10_SIZE);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MGCMTBLDEF_N.DATA_1_PRT);
    sqlstm.sqhstl[38] = (unsigned int  )21;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MGCMTBLDEF_N.DATA_1_FMT);
    sqlstm.sqhstl[39] = (unsigned int  )2;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(MGCMTBLDEF_N.DATA_1_SIZE);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MGCMTBLDEF_N.DATA_2_PRT);
    sqlstm.sqhstl[41] = (unsigned int  )21;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MGCMTBLDEF_N.DATA_2_FMT);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)&(MGCMTBLDEF_N.DATA_2_SIZE);
    sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MGCMTBLDEF_N.DATA_3_PRT);
    sqlstm.sqhstl[44] = (unsigned int  )21;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MGCMTBLDEF_N.DATA_3_FMT);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)&(MGCMTBLDEF_N.DATA_3_SIZE);
    sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MGCMTBLDEF_N.DATA_4_PRT);
    sqlstm.sqhstl[47] = (unsigned int  )21;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MGCMTBLDEF_N.DATA_4_FMT);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)&(MGCMTBLDEF_N.DATA_4_SIZE);
    sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MGCMTBLDEF_N.DATA_5_PRT);
    sqlstm.sqhstl[50] = (unsigned int  )21;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MGCMTBLDEF_N.DATA_5_FMT);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)&(MGCMTBLDEF_N.DATA_5_SIZE);
    sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MGCMTBLDEF_N.DATA_6_PRT);
    sqlstm.sqhstl[53] = (unsigned int  )21;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MGCMTBLDEF_N.DATA_6_FMT);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)&(MGCMTBLDEF_N.DATA_6_SIZE);
    sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MGCMTBLDEF_N.DATA_7_PRT);
    sqlstm.sqhstl[56] = (unsigned int  )21;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MGCMTBLDEF_N.DATA_7_FMT);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)&(MGCMTBLDEF_N.DATA_7_SIZE);
    sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MGCMTBLDEF_N.DATA_8_PRT);
    sqlstm.sqhstl[59] = (unsigned int  )21;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MGCMTBLDEF_N.DATA_8_FMT);
    sqlstm.sqhstl[60] = (unsigned int  )2;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)&(MGCMTBLDEF_N.DATA_8_SIZE);
    sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MGCMTBLDEF_N.DATA_9_PRT);
    sqlstm.sqhstl[62] = (unsigned int  )21;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MGCMTBLDEF_N.DATA_9_FMT);
    sqlstm.sqhstl[63] = (unsigned int  )2;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)&(MGCMTBLDEF_N.DATA_9_SIZE);
    sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MGCMTBLDEF_N.DATA_10_PRT);
    sqlstm.sqhstl[65] = (unsigned int  )21;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MGCMTBLDEF_N.DATA_10_FMT);
    sqlstm.sqhstl[66] = (unsigned int  )2;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)&(MGCMTBLDEF_N.DATA_10_SIZE);
    sqlstm.sqhstl[67] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MGCMTBLDEF_N.SQL_1);
    sqlstm.sqhstl[68] = (unsigned int  )2001;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MGCMTBLDEF_N.SQL_2);
    sqlstm.sqhstl[69] = (unsigned int  )2001;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MGCMTBLDEF_N.SQL_3);
    sqlstm.sqhstl[70] = (unsigned int  )2001;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MGCMTBLDEF_N.SQL_4);
    sqlstm.sqhstl[71] = (unsigned int  )2001;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MGCMTBLDEF_N.SQL_5);
    sqlstm.sqhstl[72] = (unsigned int  )2001;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MGCMTBLDEF_N.TABLE_PASSWORD);
    sqlstm.sqhstl[73] = (unsigned int  )21;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
    sqlstm.sqhstl[74] = (unsigned int  )2;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MGCMTBLDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[75] = (unsigned int  )21;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MGCMTBLDEF_N.CREATE_TIME);
    sqlstm.sqhstl[76] = (unsigned int  )15;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MGCMTBLDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[77] = (unsigned int  )21;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MGCMTBLDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[78] = (unsigned int  )15;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MGCMTBLDEF_N.KEY_1_TBL);
    sqlstm.sqhstl[79] = (unsigned int  )21;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MGCMTBLDEF_N.KEY_1_COL);
    sqlstm.sqhstl[80] = (unsigned int  )31;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MGCMTBLDEF_N.KEY_2_TBL);
    sqlstm.sqhstl[81] = (unsigned int  )21;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MGCMTBLDEF_N.KEY_2_COL);
    sqlstm.sqhstl[82] = (unsigned int  )31;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MGCMTBLDEF_N.KEY_3_TBL);
    sqlstm.sqhstl[83] = (unsigned int  )21;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MGCMTBLDEF_N.KEY_3_COL);
    sqlstm.sqhstl[84] = (unsigned int  )31;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MGCMTBLDEF_N.KEY_4_TBL);
    sqlstm.sqhstl[85] = (unsigned int  )21;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MGCMTBLDEF_N.KEY_4_COL);
    sqlstm.sqhstl[86] = (unsigned int  )31;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MGCMTBLDEF_N.KEY_5_TBL);
    sqlstm.sqhstl[87] = (unsigned int  )21;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MGCMTBLDEF_N.KEY_5_COL);
    sqlstm.sqhstl[88] = (unsigned int  )31;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MGCMTBLDEF_N.KEY_6_TBL);
    sqlstm.sqhstl[89] = (unsigned int  )21;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MGCMTBLDEF_N.KEY_6_COL);
    sqlstm.sqhstl[90] = (unsigned int  )31;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MGCMTBLDEF_N.KEY_7_TBL);
    sqlstm.sqhstl[91] = (unsigned int  )21;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MGCMTBLDEF_N.KEY_7_COL);
    sqlstm.sqhstl[92] = (unsigned int  )31;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MGCMTBLDEF_N.KEY_8_TBL);
    sqlstm.sqhstl[93] = (unsigned int  )21;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MGCMTBLDEF_N.KEY_8_COL);
    sqlstm.sqhstl[94] = (unsigned int  )31;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MGCMTBLDEF_N.KEY_9_TBL);
    sqlstm.sqhstl[95] = (unsigned int  )21;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MGCMTBLDEF_N.KEY_9_COL);
    sqlstm.sqhstl[96] = (unsigned int  )31;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MGCMTBLDEF_N.KEY_10_TBL);
    sqlstm.sqhstl[97] = (unsigned int  )21;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MGCMTBLDEF_N.KEY_10_COL);
    sqlstm.sqhstl[98] = (unsigned int  )31;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MGCMTBLDEF_N.DATA_1_TBL);
    sqlstm.sqhstl[99] = (unsigned int  )21;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MGCMTBLDEF_N.DATA_1_COL);
    sqlstm.sqhstl[100] = (unsigned int  )31;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MGCMTBLDEF_N.DATA_2_TBL);
    sqlstm.sqhstl[101] = (unsigned int  )21;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)(MGCMTBLDEF_N.DATA_2_COL);
    sqlstm.sqhstl[102] = (unsigned int  )31;
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MGCMTBLDEF_N.DATA_3_TBL);
    sqlstm.sqhstl[103] = (unsigned int  )21;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MGCMTBLDEF_N.DATA_3_COL);
    sqlstm.sqhstl[104] = (unsigned int  )31;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MGCMTBLDEF_N.DATA_4_TBL);
    sqlstm.sqhstl[105] = (unsigned int  )21;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)(MGCMTBLDEF_N.DATA_4_COL);
    sqlstm.sqhstl[106] = (unsigned int  )31;
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)(MGCMTBLDEF_N.DATA_5_TBL);
    sqlstm.sqhstl[107] = (unsigned int  )21;
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
    sqlstm.sqhstv[108] = (         void  *)(MGCMTBLDEF_N.DATA_5_COL);
    sqlstm.sqhstl[108] = (unsigned int  )31;
    sqlstm.sqhsts[108] = (         int  )0;
    sqlstm.sqindv[108] = (         void  *)0;
    sqlstm.sqinds[108] = (         int  )0;
    sqlstm.sqharm[108] = (unsigned int  )0;
    sqlstm.sqadto[108] = (unsigned short )0;
    sqlstm.sqtdso[108] = (unsigned short )0;
    sqlstm.sqhstv[109] = (         void  *)(MGCMTBLDEF_N.DATA_6_TBL);
    sqlstm.sqhstl[109] = (unsigned int  )21;
    sqlstm.sqhsts[109] = (         int  )0;
    sqlstm.sqindv[109] = (         void  *)0;
    sqlstm.sqinds[109] = (         int  )0;
    sqlstm.sqharm[109] = (unsigned int  )0;
    sqlstm.sqadto[109] = (unsigned short )0;
    sqlstm.sqtdso[109] = (unsigned short )0;
    sqlstm.sqhstv[110] = (         void  *)(MGCMTBLDEF_N.DATA_6_COL);
    sqlstm.sqhstl[110] = (unsigned int  )31;
    sqlstm.sqhsts[110] = (         int  )0;
    sqlstm.sqindv[110] = (         void  *)0;
    sqlstm.sqinds[110] = (         int  )0;
    sqlstm.sqharm[110] = (unsigned int  )0;
    sqlstm.sqadto[110] = (unsigned short )0;
    sqlstm.sqtdso[110] = (unsigned short )0;
    sqlstm.sqhstv[111] = (         void  *)(MGCMTBLDEF_N.DATA_7_TBL);
    sqlstm.sqhstl[111] = (unsigned int  )21;
    sqlstm.sqhsts[111] = (         int  )0;
    sqlstm.sqindv[111] = (         void  *)0;
    sqlstm.sqinds[111] = (         int  )0;
    sqlstm.sqharm[111] = (unsigned int  )0;
    sqlstm.sqadto[111] = (unsigned short )0;
    sqlstm.sqtdso[111] = (unsigned short )0;
    sqlstm.sqhstv[112] = (         void  *)(MGCMTBLDEF_N.DATA_7_COL);
    sqlstm.sqhstl[112] = (unsigned int  )31;
    sqlstm.sqhsts[112] = (         int  )0;
    sqlstm.sqindv[112] = (         void  *)0;
    sqlstm.sqinds[112] = (         int  )0;
    sqlstm.sqharm[112] = (unsigned int  )0;
    sqlstm.sqadto[112] = (unsigned short )0;
    sqlstm.sqtdso[112] = (unsigned short )0;
    sqlstm.sqhstv[113] = (         void  *)(MGCMTBLDEF_N.DATA_8_TBL);
    sqlstm.sqhstl[113] = (unsigned int  )21;
    sqlstm.sqhsts[113] = (         int  )0;
    sqlstm.sqindv[113] = (         void  *)0;
    sqlstm.sqinds[113] = (         int  )0;
    sqlstm.sqharm[113] = (unsigned int  )0;
    sqlstm.sqadto[113] = (unsigned short )0;
    sqlstm.sqtdso[113] = (unsigned short )0;
    sqlstm.sqhstv[114] = (         void  *)(MGCMTBLDEF_N.DATA_8_COL);
    sqlstm.sqhstl[114] = (unsigned int  )31;
    sqlstm.sqhsts[114] = (         int  )0;
    sqlstm.sqindv[114] = (         void  *)0;
    sqlstm.sqinds[114] = (         int  )0;
    sqlstm.sqharm[114] = (unsigned int  )0;
    sqlstm.sqadto[114] = (unsigned short )0;
    sqlstm.sqtdso[114] = (unsigned short )0;
    sqlstm.sqhstv[115] = (         void  *)(MGCMTBLDEF_N.DATA_9_TBL);
    sqlstm.sqhstl[115] = (unsigned int  )21;
    sqlstm.sqhsts[115] = (         int  )0;
    sqlstm.sqindv[115] = (         void  *)0;
    sqlstm.sqinds[115] = (         int  )0;
    sqlstm.sqharm[115] = (unsigned int  )0;
    sqlstm.sqadto[115] = (unsigned short )0;
    sqlstm.sqtdso[115] = (unsigned short )0;
    sqlstm.sqhstv[116] = (         void  *)(MGCMTBLDEF_N.DATA_9_COL);
    sqlstm.sqhstl[116] = (unsigned int  )31;
    sqlstm.sqhsts[116] = (         int  )0;
    sqlstm.sqindv[116] = (         void  *)0;
    sqlstm.sqinds[116] = (         int  )0;
    sqlstm.sqharm[116] = (unsigned int  )0;
    sqlstm.sqadto[116] = (unsigned short )0;
    sqlstm.sqtdso[116] = (unsigned short )0;
    sqlstm.sqhstv[117] = (         void  *)(MGCMTBLDEF_N.DATA_10_TBL);
    sqlstm.sqhstl[117] = (unsigned int  )21;
    sqlstm.sqhsts[117] = (         int  )0;
    sqlstm.sqindv[117] = (         void  *)0;
    sqlstm.sqinds[117] = (         int  )0;
    sqlstm.sqharm[117] = (unsigned int  )0;
    sqlstm.sqadto[117] = (unsigned short )0;
    sqlstm.sqtdso[117] = (unsigned short )0;
    sqlstm.sqhstv[118] = (         void  *)(MGCMTBLDEF_N.DATA_10_COL);
    sqlstm.sqhstl[118] = (unsigned int  )31;
    sqlstm.sqhsts[118] = (         int  )0;
    sqlstm.sqindv[118] = (         void  *)0;
    sqlstm.sqinds[118] = (         int  )0;
    sqlstm.sqharm[118] = (unsigned int  )0;
    sqlstm.sqadto[118] = (unsigned short )0;
    sqlstm.sqtdso[118] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mgcmtbldef", 0);
}


/* SQL UPDATE Function */
void DBC_update_mgcmtbldef(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MGCMTBLDEF SET
                    TABLE_DESC = :MGCMTBLDEF_N.TABLE_DESC,
                    SYS_TBL_FLAG = :MGCMTBLDEF_N.SYS_TBL_FLAG,
                    CENTRAL_FLAG = :MGCMTBLDEF_N.CENTRAL_FLAG,
                    TABLE_TYPE = :MGCMTBLDEF_N.TABLE_TYPE,
                    USE_SQL_FLAG = :MGCMTBLDEF_N.USE_SQL_FLAG,
                    TABLE_GROUP = :MGCMTBLDEF_N.TABLE_GROUP,
                    KEY_1_PRT = :MGCMTBLDEF_N.KEY_1_PRT,
                    KEY_1_FMT = :MGCMTBLDEF_N.KEY_1_FMT,
                    KEY_1_SIZE = :MGCMTBLDEF_N.KEY_1_SIZE,
                    KEY_2_PRT = :MGCMTBLDEF_N.KEY_2_PRT,
                    KEY_2_FMT = :MGCMTBLDEF_N.KEY_2_FMT,
                    KEY_2_SIZE = :MGCMTBLDEF_N.KEY_2_SIZE,
                    KEY_3_PRT = :MGCMTBLDEF_N.KEY_3_PRT,
                    KEY_3_FMT = :MGCMTBLDEF_N.KEY_3_FMT,
                    KEY_3_SIZE = :MGCMTBLDEF_N.KEY_3_SIZE,
                    KEY_4_PRT = :MGCMTBLDEF_N.KEY_4_PRT,
                    KEY_4_FMT = :MGCMTBLDEF_N.KEY_4_FMT,
                    KEY_4_SIZE = :MGCMTBLDEF_N.KEY_4_SIZE,
                    KEY_5_PRT = :MGCMTBLDEF_N.KEY_5_PRT,
                    KEY_5_FMT = :MGCMTBLDEF_N.KEY_5_FMT,
                    KEY_5_SIZE = :MGCMTBLDEF_N.KEY_5_SIZE,
                    KEY_6_PRT = :MGCMTBLDEF_N.KEY_6_PRT,
                    KEY_6_FMT = :MGCMTBLDEF_N.KEY_6_FMT,
                    KEY_6_SIZE = :MGCMTBLDEF_N.KEY_6_SIZE,
                    KEY_7_PRT = :MGCMTBLDEF_N.KEY_7_PRT,
                    KEY_7_FMT = :MGCMTBLDEF_N.KEY_7_FMT,
                    KEY_7_SIZE = :MGCMTBLDEF_N.KEY_7_SIZE,
                    KEY_8_PRT = :MGCMTBLDEF_N.KEY_8_PRT,
                    KEY_8_FMT = :MGCMTBLDEF_N.KEY_8_FMT,
                    KEY_8_SIZE = :MGCMTBLDEF_N.KEY_8_SIZE,
                    KEY_9_PRT = :MGCMTBLDEF_N.KEY_9_PRT,
                    KEY_9_FMT = :MGCMTBLDEF_N.KEY_9_FMT,
                    KEY_9_SIZE = :MGCMTBLDEF_N.KEY_9_SIZE,
                    KEY_10_PRT = :MGCMTBLDEF_N.KEY_10_PRT,
                    KEY_10_FMT = :MGCMTBLDEF_N.KEY_10_FMT,
                    KEY_10_SIZE = :MGCMTBLDEF_N.KEY_10_SIZE,
                    DATA_1_PRT = :MGCMTBLDEF_N.DATA_1_PRT,
                    DATA_1_FMT = :MGCMTBLDEF_N.DATA_1_FMT,
                    DATA_1_SIZE = :MGCMTBLDEF_N.DATA_1_SIZE,
                    DATA_2_PRT = :MGCMTBLDEF_N.DATA_2_PRT,
                    DATA_2_FMT = :MGCMTBLDEF_N.DATA_2_FMT,
                    DATA_2_SIZE = :MGCMTBLDEF_N.DATA_2_SIZE,
                    DATA_3_PRT = :MGCMTBLDEF_N.DATA_3_PRT,
                    DATA_3_FMT = :MGCMTBLDEF_N.DATA_3_FMT,
                    DATA_3_SIZE = :MGCMTBLDEF_N.DATA_3_SIZE,
                    DATA_4_PRT = :MGCMTBLDEF_N.DATA_4_PRT,
                    DATA_4_FMT = :MGCMTBLDEF_N.DATA_4_FMT,
                    DATA_4_SIZE = :MGCMTBLDEF_N.DATA_4_SIZE,
                    DATA_5_PRT = :MGCMTBLDEF_N.DATA_5_PRT,
                    DATA_5_FMT = :MGCMTBLDEF_N.DATA_5_FMT,
                    DATA_5_SIZE = :MGCMTBLDEF_N.DATA_5_SIZE,
                    DATA_6_PRT = :MGCMTBLDEF_N.DATA_6_PRT,
                    DATA_6_FMT = :MGCMTBLDEF_N.DATA_6_FMT,
                    DATA_6_SIZE = :MGCMTBLDEF_N.DATA_6_SIZE,
                    DATA_7_PRT = :MGCMTBLDEF_N.DATA_7_PRT,
                    DATA_7_FMT = :MGCMTBLDEF_N.DATA_7_FMT,
                    DATA_7_SIZE = :MGCMTBLDEF_N.DATA_7_SIZE,
                    DATA_8_PRT = :MGCMTBLDEF_N.DATA_8_PRT,
                    DATA_8_FMT = :MGCMTBLDEF_N.DATA_8_FMT,
                    DATA_8_SIZE = :MGCMTBLDEF_N.DATA_8_SIZE,
                    DATA_9_PRT = :MGCMTBLDEF_N.DATA_9_PRT,
                    DATA_9_FMT = :MGCMTBLDEF_N.DATA_9_FMT,
                    DATA_9_SIZE = :MGCMTBLDEF_N.DATA_9_SIZE,
                    DATA_10_PRT = :MGCMTBLDEF_N.DATA_10_PRT,
                    DATA_10_FMT = :MGCMTBLDEF_N.DATA_10_FMT,
                    DATA_10_SIZE = :MGCMTBLDEF_N.DATA_10_SIZE,
                    SQL_1 = :MGCMTBLDEF_N.SQL_1,
                    SQL_2 = :MGCMTBLDEF_N.SQL_2,
                    SQL_3 = :MGCMTBLDEF_N.SQL_3,
                    SQL_4 = :MGCMTBLDEF_N.SQL_4,
                    SQL_5 = :MGCMTBLDEF_N.SQL_5,
                    TABLE_PASSWORD = :MGCMTBLDEF_N.TABLE_PASSWORD,
                    SEC_CHK_FLAG = :MGCMTBLDEF_N.SEC_CHK_FLAG,
                    CREATE_USER_ID = :MGCMTBLDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MGCMTBLDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MGCMTBLDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MGCMTBLDEF_N.UPDATE_TIME,
                    KEY_1_TBL = :MGCMTBLDEF_N.KEY_1_TBL,
                    KEY_1_COL = :MGCMTBLDEF_N.KEY_1_COL,
                    KEY_2_TBL = :MGCMTBLDEF_N.KEY_2_TBL,
                    KEY_2_COL = :MGCMTBLDEF_N.KEY_2_COL,
                    KEY_3_TBL = :MGCMTBLDEF_N.KEY_3_TBL,
                    KEY_3_COL = :MGCMTBLDEF_N.KEY_3_COL,
                    KEY_4_TBL = :MGCMTBLDEF_N.KEY_4_TBL,
                    KEY_4_COL = :MGCMTBLDEF_N.KEY_4_COL,
                    KEY_5_TBL = :MGCMTBLDEF_N.KEY_5_TBL,
                    KEY_5_COL = :MGCMTBLDEF_N.KEY_5_COL,
                    KEY_6_TBL = :MGCMTBLDEF_N.KEY_6_TBL,
                    KEY_6_COL = :MGCMTBLDEF_N.KEY_6_COL,
                    KEY_7_TBL = :MGCMTBLDEF_N.KEY_7_TBL,
                    KEY_7_COL = :MGCMTBLDEF_N.KEY_7_COL,
                    KEY_8_TBL = :MGCMTBLDEF_N.KEY_8_TBL,
                    KEY_8_COL = :MGCMTBLDEF_N.KEY_8_COL,
                    KEY_9_TBL = :MGCMTBLDEF_N.KEY_9_TBL,
                    KEY_9_COL = :MGCMTBLDEF_N.KEY_9_COL,
                    KEY_10_TBL = :MGCMTBLDEF_N.KEY_10_TBL,
                    KEY_10_COL = :MGCMTBLDEF_N.KEY_10_COL,
                    DATA_1_TBL = :MGCMTBLDEF_N.DATA_1_TBL,
                    DATA_1_COL = :MGCMTBLDEF_N.DATA_1_COL,
                    DATA_2_TBL = :MGCMTBLDEF_N.DATA_2_TBL,
                    DATA_2_COL = :MGCMTBLDEF_N.DATA_2_COL,
                    DATA_3_TBL = :MGCMTBLDEF_N.DATA_3_TBL,
                    DATA_3_COL = :MGCMTBLDEF_N.DATA_3_COL,
                    DATA_4_TBL = :MGCMTBLDEF_N.DATA_4_TBL,
                    DATA_4_COL = :MGCMTBLDEF_N.DATA_4_COL,
                    DATA_5_TBL = :MGCMTBLDEF_N.DATA_5_TBL,
                    DATA_5_COL = :MGCMTBLDEF_N.DATA_5_COL,
                    DATA_6_TBL = :MGCMTBLDEF_N.DATA_6_TBL,
                    DATA_6_COL = :MGCMTBLDEF_N.DATA_6_COL,
                    DATA_7_TBL = :MGCMTBLDEF_N.DATA_7_TBL,
                    DATA_7_COL = :MGCMTBLDEF_N.DATA_7_COL,
                    DATA_8_TBL = :MGCMTBLDEF_N.DATA_8_TBL,
                    DATA_8_COL = :MGCMTBLDEF_N.DATA_8_COL,
                    DATA_9_TBL = :MGCMTBLDEF_N.DATA_9_TBL,
                    DATA_9_COL = :MGCMTBLDEF_N.DATA_9_COL,
                    DATA_10_TBL = :MGCMTBLDEF_N.DATA_10_TBL,
                    DATA_10_COL = :MGCMTBLDEF_N.DATA_10_COL
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MGCMTBLDEF  set TABLE_DESC=:b0,SYS_TBL_FLAG=:b1,CENTRA\
L_FLAG=:b2,TABLE_TYPE=:b3,USE_SQL_FLAG=:b4,TABLE_GROUP=:b5,KEY_1_PRT=:b6,KEY\
_1_FMT=:b7,KEY_1_SIZE=:b8,KEY_2_PRT=:b9,KEY_2_FMT=:b10,KEY_2_SIZE=:b11,KEY_3\
_PRT=:b12,KEY_3_FMT=:b13,KEY_3_SIZE=:b14,KEY_4_PRT=:b15,KEY_4_FMT=:b16,KEY_4\
_SIZE=:b17,KEY_5_PRT=:b18,KEY_5_FMT=:b19,KEY_5_SIZE=:b20,KEY_6_PRT=:b21,KEY_\
6_FMT=:b22,KEY_6_SIZE=:b23,KEY_7_PRT=:b24,KEY_7_FMT=:b25,KEY_7_SIZE=:b26,KEY\
_8_PRT=:b27,KEY_8_FMT=:b28,KEY_8_SIZE=:b29,KEY_9_PRT=:b30,KEY_9_FMT=:b31,KEY\
_9_SIZE=:b32,KEY_10_PRT=:b33,KEY_10_FMT=:b34,KEY_10_SIZE=:b35,DATA_1_PRT=:b3\
6,DATA_1_FMT=:b37,DATA_1_SIZE=:b38,DATA_2_PRT=:b39,DATA_2_FMT=:b40,DATA_2_SI\
ZE=:b41,DATA_3_PRT=:b42,DATA_3_FMT=:b43,DATA_3_SIZE=:b44,DATA_4_PRT=:b45,DAT\
A_4_FMT=:b46,DATA_4_SIZE=:b47,DATA_5_PRT=:b48,DATA_5_FMT=:b49,DATA_5_SIZE=:b\
50,DATA_6_PRT=:b51,DATA_6_FMT=:b52,DATA_6_SIZE=:b53,DATA_7_PRT=:b54,DATA_7_F\
MT=:b55,DATA_7_SIZE=:b56,DATA_8_PRT=:b57,DATA_8_FMT=:b58,DATA_8_SIZE=:b59,DA\
TA_9_PRT=:b60,DATA_9_FMT=:b61,DATA_9_SIZE=:b62,DATA");
            sqlstm.stmt = "_10_PRT=:b63,DATA_10_FMT=:b64,DATA_10_SIZE=:b65,\
SQL_1=:b66,SQL_2=:b67,SQL_3=:b68,SQL_4=:b69,SQL_5=:b70,TABLE_PASSWORD=:b71,SE\
C_CHK_FLAG=:b72,CREATE_USER_ID=:b73,CREATE_TIME=:b74,UPDATE_USER_ID=:b75,UPDA\
TE_TIME=:b76,KEY_1_TBL=:b77,KEY_1_COL=:b78,KEY_2_TBL=:b79,KEY_2_COL=:b80,KEY_\
3_TBL=:b81,KEY_3_COL=:b82,KEY_4_TBL=:b83,KEY_4_COL=:b84,KEY_5_TBL=:b85,KEY_5_\
COL=:b86,KEY_6_TBL=:b87,KEY_6_COL=:b88,KEY_7_TBL=:b89,KEY_7_COL=:b90,KEY_8_TB\
L=:b91,KEY_8_COL=:b92,KEY_9_TBL=:b93,KEY_9_COL=:b94,KEY_10_TBL=:b95,KEY_10_CO\
L=:b96,DATA_1_TBL=:b97,DATA_1_COL=:b98,DATA_2_TBL=:b99,DATA_2_COL=:b100,DATA_\
3_TBL=:b101,DATA_3_COL=:b102,DATA_4_TBL=:b103,DATA_4_COL=:b104,DATA_5_TBL=:b1\
05,DATA_5_COL=:b106,DATA_6_TBL=:b107,DATA_6_COL=:b108,DATA_7_TBL=:b109,DATA_7\
_COL=:b110,DATA_8_TBL=:b111,DATA_8_COL=:b112,DATA_9_TBL=:b113,DATA_9_COL=:b11\
4,DATA_10_TBL=:b115,DATA_10_COL=:b116 where (FACTORY=:b117 and TABLE_NAME=:b1\
18)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1563;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.USE_SQL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.KEY_1_PRT);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMTBLDEF_N.KEY_1_FMT);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(MGCMTBLDEF_N.KEY_1_SIZE);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMTBLDEF_N.KEY_2_PRT);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MGCMTBLDEF_N.KEY_2_FMT);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MGCMTBLDEF_N.KEY_2_SIZE);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMTBLDEF_N.KEY_3_PRT);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MGCMTBLDEF_N.KEY_3_FMT);
            sqlstm.sqhstl[13] = (unsigned int  )2;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MGCMTBLDEF_N.KEY_3_SIZE);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMTBLDEF_N.KEY_4_PRT);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MGCMTBLDEF_N.KEY_4_FMT);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(MGCMTBLDEF_N.KEY_4_SIZE);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMTBLDEF_N.KEY_5_PRT);
            sqlstm.sqhstl[18] = (unsigned int  )21;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MGCMTBLDEF_N.KEY_5_FMT);
            sqlstm.sqhstl[19] = (unsigned int  )2;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(MGCMTBLDEF_N.KEY_5_SIZE);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMTBLDEF_N.KEY_6_PRT);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MGCMTBLDEF_N.KEY_6_FMT);
            sqlstm.sqhstl[22] = (unsigned int  )2;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(MGCMTBLDEF_N.KEY_6_SIZE);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMTBLDEF_N.KEY_7_PRT);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MGCMTBLDEF_N.KEY_7_FMT);
            sqlstm.sqhstl[25] = (unsigned int  )2;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(MGCMTBLDEF_N.KEY_7_SIZE);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMTBLDEF_N.KEY_8_PRT);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MGCMTBLDEF_N.KEY_8_FMT);
            sqlstm.sqhstl[28] = (unsigned int  )2;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(MGCMTBLDEF_N.KEY_8_SIZE);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMTBLDEF_N.KEY_9_PRT);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MGCMTBLDEF_N.KEY_9_FMT);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)&(MGCMTBLDEF_N.KEY_9_SIZE);
            sqlstm.sqhstl[32] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMTBLDEF_N.KEY_10_PRT);
            sqlstm.sqhstl[33] = (unsigned int  )21;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MGCMTBLDEF_N.KEY_10_FMT);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(MGCMTBLDEF_N.KEY_10_SIZE);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMTBLDEF_N.DATA_1_PRT);
            sqlstm.sqhstl[36] = (unsigned int  )21;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MGCMTBLDEF_N.DATA_1_FMT);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(MGCMTBLDEF_N.DATA_1_SIZE);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMTBLDEF_N.DATA_2_PRT);
            sqlstm.sqhstl[39] = (unsigned int  )21;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MGCMTBLDEF_N.DATA_2_FMT);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(MGCMTBLDEF_N.DATA_2_SIZE);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MGCMTBLDEF_N.DATA_3_PRT);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MGCMTBLDEF_N.DATA_3_FMT);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)&(MGCMTBLDEF_N.DATA_3_SIZE);
            sqlstm.sqhstl[44] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MGCMTBLDEF_N.DATA_4_PRT);
            sqlstm.sqhstl[45] = (unsigned int  )21;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MGCMTBLDEF_N.DATA_4_FMT);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(MGCMTBLDEF_N.DATA_4_SIZE);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MGCMTBLDEF_N.DATA_5_PRT);
            sqlstm.sqhstl[48] = (unsigned int  )21;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MGCMTBLDEF_N.DATA_5_FMT);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(MGCMTBLDEF_N.DATA_5_SIZE);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MGCMTBLDEF_N.DATA_6_PRT);
            sqlstm.sqhstl[51] = (unsigned int  )21;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MGCMTBLDEF_N.DATA_6_FMT);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MGCMTBLDEF_N.DATA_6_SIZE);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MGCMTBLDEF_N.DATA_7_PRT);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MGCMTBLDEF_N.DATA_7_FMT);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MGCMTBLDEF_N.DATA_7_SIZE);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MGCMTBLDEF_N.DATA_8_PRT);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MGCMTBLDEF_N.DATA_8_FMT);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MGCMTBLDEF_N.DATA_8_SIZE);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MGCMTBLDEF_N.DATA_9_PRT);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MGCMTBLDEF_N.DATA_9_FMT);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(MGCMTBLDEF_N.DATA_9_SIZE);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MGCMTBLDEF_N.DATA_10_PRT);
            sqlstm.sqhstl[63] = (unsigned int  )21;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MGCMTBLDEF_N.DATA_10_FMT);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)&(MGCMTBLDEF_N.DATA_10_SIZE);
            sqlstm.sqhstl[65] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MGCMTBLDEF_N.SQL_1);
            sqlstm.sqhstl[66] = (unsigned int  )2001;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MGCMTBLDEF_N.SQL_2);
            sqlstm.sqhstl[67] = (unsigned int  )2001;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MGCMTBLDEF_N.SQL_3);
            sqlstm.sqhstl[68] = (unsigned int  )2001;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MGCMTBLDEF_N.SQL_4);
            sqlstm.sqhstl[69] = (unsigned int  )2001;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MGCMTBLDEF_N.SQL_5);
            sqlstm.sqhstl[70] = (unsigned int  )2001;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MGCMTBLDEF_N.TABLE_PASSWORD);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[72] = (unsigned int  )2;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MGCMTBLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MGCMTBLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[74] = (unsigned int  )15;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MGCMTBLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MGCMTBLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MGCMTBLDEF_N.KEY_1_TBL);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MGCMTBLDEF_N.KEY_1_COL);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MGCMTBLDEF_N.KEY_2_TBL);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MGCMTBLDEF_N.KEY_2_COL);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MGCMTBLDEF_N.KEY_3_TBL);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MGCMTBLDEF_N.KEY_3_COL);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MGCMTBLDEF_N.KEY_4_TBL);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MGCMTBLDEF_N.KEY_4_COL);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MGCMTBLDEF_N.KEY_5_TBL);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MGCMTBLDEF_N.KEY_5_COL);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MGCMTBLDEF_N.KEY_6_TBL);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MGCMTBLDEF_N.KEY_6_COL);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MGCMTBLDEF_N.KEY_7_TBL);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MGCMTBLDEF_N.KEY_7_COL);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MGCMTBLDEF_N.KEY_8_TBL);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MGCMTBLDEF_N.KEY_8_COL);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MGCMTBLDEF_N.KEY_9_TBL);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MGCMTBLDEF_N.KEY_9_COL);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MGCMTBLDEF_N.KEY_10_TBL);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MGCMTBLDEF_N.KEY_10_COL);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MGCMTBLDEF_N.DATA_1_TBL);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MGCMTBLDEF_N.DATA_1_COL);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MGCMTBLDEF_N.DATA_2_TBL);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MGCMTBLDEF_N.DATA_2_COL);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MGCMTBLDEF_N.DATA_3_TBL);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MGCMTBLDEF_N.DATA_3_COL);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MGCMTBLDEF_N.DATA_4_TBL);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MGCMTBLDEF_N.DATA_4_COL);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MGCMTBLDEF_N.DATA_5_TBL);
            sqlstm.sqhstl[105] = (unsigned int  )21;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MGCMTBLDEF_N.DATA_5_COL);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MGCMTBLDEF_N.DATA_6_TBL);
            sqlstm.sqhstl[107] = (unsigned int  )21;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MGCMTBLDEF_N.DATA_6_COL);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MGCMTBLDEF_N.DATA_7_TBL);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MGCMTBLDEF_N.DATA_7_COL);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MGCMTBLDEF_N.DATA_8_TBL);
            sqlstm.sqhstl[111] = (unsigned int  )21;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MGCMTBLDEF_N.DATA_8_COL);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MGCMTBLDEF_N.DATA_9_TBL);
            sqlstm.sqhstl[113] = (unsigned int  )21;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MGCMTBLDEF_N.DATA_9_COL);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MGCMTBLDEF_N.DATA_10_TBL);
            sqlstm.sqhstl[115] = (unsigned int  )21;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MGCMTBLDEF_N.DATA_10_COL);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[117] = (unsigned int  )11;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mgcmtbldef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mgcmtbldef(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MGCMTBLDEF_CUR_1 CURSOR FOR
                SELECT FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG 
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_TYPE LIKE :MGCMTBLDEF_N.TABLE_TYPE
                    AND TABLE_GROUP LIKE :MGCMTBLDEF_N.TABLE_GROUP
                    AND TABLE_NAME >= :MGCMTBLDEF_N.TABLE_NAME
                ORDER BY TABLE_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MGCMTBLDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2054;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
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
            
        case 2:
            /* EXEC SQL DECLARE DBC_MGCMTBLDEF_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    TABLE_NAME,
                    TABLE_DESC,
                    SYS_TBL_FLAG,
                    CENTRAL_FLAG,
                    TABLE_TYPE,
                    USE_SQL_FLAG,
                    TABLE_GROUP,
                    KEY_1_PRT,
                    KEY_1_FMT,
                    KEY_1_SIZE,
                    KEY_2_PRT,
                    KEY_2_FMT,
                    KEY_2_SIZE,
                    KEY_3_PRT,
                    KEY_3_FMT,
                    KEY_3_SIZE,
                    KEY_4_PRT,
                    KEY_4_FMT,
                    KEY_4_SIZE,
                    KEY_5_PRT,
                    KEY_5_FMT,
                    KEY_5_SIZE,
                    KEY_6_PRT,
                    KEY_6_FMT,
                    KEY_6_SIZE,
                    KEY_7_PRT,
                    KEY_7_FMT,
                    KEY_7_SIZE,
                    KEY_8_PRT,
                    KEY_8_FMT,
                    KEY_8_SIZE,
                    KEY_9_PRT,
                    KEY_9_FMT,
                    KEY_9_SIZE,
                    KEY_10_PRT,
                    KEY_10_FMT,
                    KEY_10_SIZE,
                    DATA_1_PRT,
                    DATA_1_FMT,
                    DATA_1_SIZE,
                    DATA_2_PRT,
                    DATA_2_FMT,
                    DATA_2_SIZE,
                    DATA_3_PRT,
                    DATA_3_FMT,
                    DATA_3_SIZE,
                    DATA_4_PRT,
                    DATA_4_FMT,
                    DATA_4_SIZE,
                    DATA_5_PRT,
                    DATA_5_FMT,
                    DATA_5_SIZE,
                    DATA_6_PRT,
                    DATA_6_FMT,
                    DATA_6_SIZE,
                    DATA_7_PRT,
                    DATA_7_FMT,
                    DATA_7_SIZE,
                    DATA_8_PRT,
                    DATA_8_FMT,
                    DATA_8_SIZE,
                    DATA_9_PRT,
                    DATA_9_FMT,
                    DATA_9_SIZE,
                    DATA_10_PRT,
                    DATA_10_FMT,
                    DATA_10_SIZE,
                    SQL_1,
                    SQL_2,
                    SQL_3,
                    SQL_4,
                    SQL_5,
                    TABLE_PASSWORD,
                    SEC_CHK_FLAG,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    KEY_1_TBL,
                    KEY_1_COL,
                    KEY_2_TBL,
                    KEY_2_COL,
                    KEY_3_TBL,
                    KEY_3_COL,
                    KEY_4_TBL,
                    KEY_4_COL,
                    KEY_5_TBL,
                    KEY_5_COL,
                    KEY_6_TBL,
                    KEY_6_COL,
                    KEY_7_TBL,
                    KEY_7_COL,
                    KEY_8_TBL,
                    KEY_8_COL,
                    KEY_9_TBL,
                    KEY_9_COL,
                    KEY_10_TBL,
                    KEY_10_COL,
                    DATA_1_TBL,
                    DATA_1_COL,
                    DATA_2_TBL,
                    DATA_2_COL,
                    DATA_3_TBL,
                    DATA_3_COL,
                    DATA_4_TBL,
                    DATA_4_COL,
                    DATA_5_TBL,
                    DATA_5_COL,
                    DATA_6_TBL,
                    DATA_6_COL,
                    DATA_7_TBL,
                    DATA_7_COL,
                    DATA_8_TBL,
                    DATA_8_COL,
                    DATA_9_TBL,
                    DATA_9_COL,
                    DATA_10_TBL,
                    DATA_10_COL
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                AND SYS_TBL_FLAG = :MGCMTBLDEF_N.SYS_TBL_FLAG
                AND CENTRAL_FLAG = :MGCMTBLDEF_N.CENTRAL_FLAG
                ORDER BY TABLE_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MGCMTBLDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TABLE_NAME ,TABLE_DESC ,SYS_TBL_FLAG ,CENTRAL\
_FLAG ,TABLE_TYPE ,USE_SQL_FLAG ,TABLE_GROUP ,KEY_1_PRT ,KEY_1_FMT ,KEY_1_SI\
ZE ,KEY_2_PRT ,KEY_2_FMT ,KEY_2_SIZE ,KEY_3_PRT ,KEY_3_FMT ,KEY_3_SIZE ,KEY_\
4_PRT ,KEY_4_FMT ,KEY_4_SIZE ,KEY_5_PRT ,KEY_5_FMT ,KEY_5_SIZE ,KEY_6_PRT ,K\
EY_6_FMT ,KEY_6_SIZE ,KEY_7_PRT ,KEY_7_FMT ,KEY_7_SIZE ,KEY_8_PRT ,KEY_8_FMT\
 ,KEY_8_SIZE ,KEY_9_PRT ,KEY_9_FMT ,KEY_9_SIZE ,KEY_10_PRT ,KEY_10_FMT ,KEY_\
10_SIZE ,DATA_1_PRT ,DATA_1_FMT ,DATA_1_SIZE ,DATA_2_PRT ,DATA_2_FMT ,DATA_2\
_SIZE ,DATA_3_PRT ,DATA_3_FMT ,DATA_3_SIZE ,DATA_4_PRT ,DATA_4_FMT ,DATA_4_S\
IZE ,DATA_5_PRT ,DATA_5_FMT ,DATA_5_SIZE ,DATA_6_PRT ,DATA_6_FMT ,DATA_6_SIZ\
E ,DATA_7_PRT ,DATA_7_FMT ,DATA_7_SIZE ,DATA_8_PRT ,DATA_8_FMT ,DATA_8_SIZE \
,DATA_9_PRT ,DATA_9_FMT ,DATA_9_SIZE ,DATA_10_PRT ,DATA_10_FMT ,DATA_10_SIZE\
 ,SQL_1 ,SQL_2 ,SQL_3 ,SQL_4 ,SQL_5 ,TABLE_PASSWORD ,SEC_CHK_FLAG ,CREATE_US\
ER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,KEY_1_TBL ,KEY_1_COL ,KEY_2\
_TBL ,KEY_2_COL ,KEY_3_TBL ,KEY_3_COL ,KEY_4_TBL ,K");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2085;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
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
            /* EXEC SQL DECLARE DBC_MGCMTBLDEF_CUR_3 CURSOR FOR
                SELECT FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG 
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND TABLE_TYPE LIKE :MGCMTBLDEF_N.TABLE_TYPE
                    AND TABLE_GROUP LIKE :MGCMTBLDEF_N.TABLE_GROUP
                    AND TABLE_NAME >= :MGCMTBLDEF_N.TABLE_NAME
                    AND SEC_CHK_FLAG = :MGCMTBLDEF_N.SEC_CHK_FLAG
                ORDER BY TABLE_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MGCMTBLDEF_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2112;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

       case 4:
            /* EXEC SQL DECLARE DBC_MGCMTBLDEF_CUR_4 CURSOR FOR
                SELECT GTD.FACTORY, GTD.TABLE_NAME, GTD.TABLE_DESC, GTD.SYS_TBL_FLAG 
                FROM MGCMTBLDEF GTD, MSECPRVDEF PRD, MSECPRVUSR PRU
                WHERE PRU.FACTORY = :MGCMTBLDEF_N.FACTORY
                    AND PRU.USER_ID = :MGCMTBLDEF_N.CREATE_USER_ID
                    AND PRD.FACTORY = PRU.FACTORY
                    AND PRD.PRV_GRP_ID = PRU.PRV_GRP_ID
                    AND PRD.PRV_TYPE = 'GCMTABLE'
                    AND GTD.FACTORY = PRD.FACTORY
                    AND GTD.TABLE_NAME = PRD.PRV_ITEM1
                    AND GTD.TABLE_TYPE LIKE :MGCMTBLDEF_N.TABLE_TYPE
                    AND GTD.TABLE_GROUP LIKE :MGCMTBLDEF_N.TABLE_GROUP
                    AND GTD.SEC_CHK_FLAG = 'Y'
                    AND GTD.TABLE_NAME >= :MGCMTBLDEF_N.TABLE_NAME
                ORDER BY GTD.TABLE_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MGCMTBLDEF_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2147;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[4] = (unsigned int  )21;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 5:
			/*** #753 GCM Reference (2012.04.04 by JYPARK) ***/
			/* EXEC SQL DECLARE DBC_MGCMTBLDEF_CUR_5 CURSOR FOR
				SELECT 'KEY_1' AS COL, KEY_1_PRT AS PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_2', KEY_2_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_3', KEY_3_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_4', KEY_4_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_5', KEY_5_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_6', KEY_6_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_7', KEY_7_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_8', KEY_8_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_9', KEY_9_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'KEY_10', KEY_10_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_1', DATA_1_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_2', DATA_2_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_3', DATA_3_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_4', DATA_4_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_5', DATA_5_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_6', DATA_6_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_7', DATA_7_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_8', DATA_8_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_9', DATA_9_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME 
                UNION ALL
                SELECT 'DATA_10', DATA_10_PRT FROM MGCMTBLDEF WHERE FACTORY = :MGCMTBLDEF_N.FACTORY AND TABLE_NAME = :MGCMTBLDEF_N.TABLE_NAME; */ 

			/* EXEC SQL OPEN DBC_MGCMTBLDEF_CUR_5; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 121;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlbuft((void **)0,
     "select 'KEY_1' COL ,KEY_1_PRT PRT  from MGCMTBLDEF where (FACTORY=:b0 \
and TABLE_NAME=:b1) union all select 'KEY_2' ,KEY_2_PRT  from MGCMTBLDEF whe\
re (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'KEY_3' ,KEY_3_PRT  fro\
m MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'KEY_4'\
 ,KEY_4_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) union al\
l select 'KEY_5' ,KEY_5_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NA\
ME=:b1) union all select 'KEY_6' ,KEY_6_PRT  from MGCMTBLDEF where (FACTORY=\
:b0 and TABLE_NAME=:b1) union all select 'KEY_7' ,KEY_7_PRT  from MGCMTBLDEF\
 where (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'KEY_8' ,KEY_8_PRT \
 from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) union all select 'KE\
Y_9' ,KEY_9_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TABLE_NAME=:b1) unio\
n all select 'KEY_10' ,KEY_10_PRT  from MGCMTBLDEF where (FACTORY=:b0 and TA\
BLE_NAME=:b1) union all select 'DATA_1' ,DATA_1_PRT  from MGCMTBLDEF where (\
FACTORY=:b0 and TABLE_NAME=:b1) union all ");
   sqlstm.stmt = sq0012;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2182;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[0] = (unsigned int  )11;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[1] = (unsigned int  )21;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[2] = (unsigned int  )11;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         void  *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned int  )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[3] = (unsigned int  )21;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         void  *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned int  )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[4] = (unsigned int  )11;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         void  *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned int  )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[5] = (unsigned int  )21;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         void  *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned int  )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[6] = (unsigned int  )11;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         void  *)0;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned int  )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[7] = (unsigned int  )21;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         void  *)0;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned int  )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[8] = (unsigned int  )11;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         void  *)0;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned int  )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[9] = (unsigned int  )21;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         void  *)0;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned int  )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[10] = (unsigned int  )11;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         void  *)0;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned int  )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[11] = (unsigned int  )21;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         void  *)0;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned int  )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[12] = (unsigned int  )11;
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         void  *)0;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned int  )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[13] = (unsigned int  )21;
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         void  *)0;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned int  )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[14] = (unsigned int  )11;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         void  *)0;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned int  )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[15] = (unsigned int  )21;
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         void  *)0;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned int  )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[16] = (unsigned int  )11;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         void  *)0;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned int  )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[17] = (unsigned int  )21;
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         void  *)0;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned int  )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[18] = (unsigned int  )11;
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         void  *)0;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned int  )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[19] = (unsigned int  )21;
   sqlstm.sqhsts[19] = (         int  )0;
   sqlstm.sqindv[19] = (         void  *)0;
   sqlstm.sqinds[19] = (         int  )0;
   sqlstm.sqharm[19] = (unsigned int  )0;
   sqlstm.sqadto[19] = (unsigned short )0;
   sqlstm.sqtdso[19] = (unsigned short )0;
   sqlstm.sqhstv[20] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[20] = (unsigned int  )11;
   sqlstm.sqhsts[20] = (         int  )0;
   sqlstm.sqindv[20] = (         void  *)0;
   sqlstm.sqinds[20] = (         int  )0;
   sqlstm.sqharm[20] = (unsigned int  )0;
   sqlstm.sqadto[20] = (unsigned short )0;
   sqlstm.sqtdso[20] = (unsigned short )0;
   sqlstm.sqhstv[21] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[21] = (unsigned int  )21;
   sqlstm.sqhsts[21] = (         int  )0;
   sqlstm.sqindv[21] = (         void  *)0;
   sqlstm.sqinds[21] = (         int  )0;
   sqlstm.sqharm[21] = (unsigned int  )0;
   sqlstm.sqadto[21] = (unsigned short )0;
   sqlstm.sqtdso[21] = (unsigned short )0;
   sqlstm.sqhstv[22] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[22] = (unsigned int  )11;
   sqlstm.sqhsts[22] = (         int  )0;
   sqlstm.sqindv[22] = (         void  *)0;
   sqlstm.sqinds[22] = (         int  )0;
   sqlstm.sqharm[22] = (unsigned int  )0;
   sqlstm.sqadto[22] = (unsigned short )0;
   sqlstm.sqtdso[22] = (unsigned short )0;
   sqlstm.sqhstv[23] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[23] = (unsigned int  )21;
   sqlstm.sqhsts[23] = (         int  )0;
   sqlstm.sqindv[23] = (         void  *)0;
   sqlstm.sqinds[23] = (         int  )0;
   sqlstm.sqharm[23] = (unsigned int  )0;
   sqlstm.sqadto[23] = (unsigned short )0;
   sqlstm.sqtdso[23] = (unsigned short )0;
   sqlstm.sqhstv[24] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[24] = (unsigned int  )11;
   sqlstm.sqhsts[24] = (         int  )0;
   sqlstm.sqindv[24] = (         void  *)0;
   sqlstm.sqinds[24] = (         int  )0;
   sqlstm.sqharm[24] = (unsigned int  )0;
   sqlstm.sqadto[24] = (unsigned short )0;
   sqlstm.sqtdso[24] = (unsigned short )0;
   sqlstm.sqhstv[25] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[25] = (unsigned int  )21;
   sqlstm.sqhsts[25] = (         int  )0;
   sqlstm.sqindv[25] = (         void  *)0;
   sqlstm.sqinds[25] = (         int  )0;
   sqlstm.sqharm[25] = (unsigned int  )0;
   sqlstm.sqadto[25] = (unsigned short )0;
   sqlstm.sqtdso[25] = (unsigned short )0;
   sqlstm.sqhstv[26] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[26] = (unsigned int  )11;
   sqlstm.sqhsts[26] = (         int  )0;
   sqlstm.sqindv[26] = (         void  *)0;
   sqlstm.sqinds[26] = (         int  )0;
   sqlstm.sqharm[26] = (unsigned int  )0;
   sqlstm.sqadto[26] = (unsigned short )0;
   sqlstm.sqtdso[26] = (unsigned short )0;
   sqlstm.sqhstv[27] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[27] = (unsigned int  )21;
   sqlstm.sqhsts[27] = (         int  )0;
   sqlstm.sqindv[27] = (         void  *)0;
   sqlstm.sqinds[27] = (         int  )0;
   sqlstm.sqharm[27] = (unsigned int  )0;
   sqlstm.sqadto[27] = (unsigned short )0;
   sqlstm.sqtdso[27] = (unsigned short )0;
   sqlstm.sqhstv[28] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[28] = (unsigned int  )11;
   sqlstm.sqhsts[28] = (         int  )0;
   sqlstm.sqindv[28] = (         void  *)0;
   sqlstm.sqinds[28] = (         int  )0;
   sqlstm.sqharm[28] = (unsigned int  )0;
   sqlstm.sqadto[28] = (unsigned short )0;
   sqlstm.sqtdso[28] = (unsigned short )0;
   sqlstm.sqhstv[29] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[29] = (unsigned int  )21;
   sqlstm.sqhsts[29] = (         int  )0;
   sqlstm.sqindv[29] = (         void  *)0;
   sqlstm.sqinds[29] = (         int  )0;
   sqlstm.sqharm[29] = (unsigned int  )0;
   sqlstm.sqadto[29] = (unsigned short )0;
   sqlstm.sqtdso[29] = (unsigned short )0;
   sqlstm.sqhstv[30] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[30] = (unsigned int  )11;
   sqlstm.sqhsts[30] = (         int  )0;
   sqlstm.sqindv[30] = (         void  *)0;
   sqlstm.sqinds[30] = (         int  )0;
   sqlstm.sqharm[30] = (unsigned int  )0;
   sqlstm.sqadto[30] = (unsigned short )0;
   sqlstm.sqtdso[30] = (unsigned short )0;
   sqlstm.sqhstv[31] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[31] = (unsigned int  )21;
   sqlstm.sqhsts[31] = (         int  )0;
   sqlstm.sqindv[31] = (         void  *)0;
   sqlstm.sqinds[31] = (         int  )0;
   sqlstm.sqharm[31] = (unsigned int  )0;
   sqlstm.sqadto[31] = (unsigned short )0;
   sqlstm.sqtdso[31] = (unsigned short )0;
   sqlstm.sqhstv[32] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[32] = (unsigned int  )11;
   sqlstm.sqhsts[32] = (         int  )0;
   sqlstm.sqindv[32] = (         void  *)0;
   sqlstm.sqinds[32] = (         int  )0;
   sqlstm.sqharm[32] = (unsigned int  )0;
   sqlstm.sqadto[32] = (unsigned short )0;
   sqlstm.sqtdso[32] = (unsigned short )0;
   sqlstm.sqhstv[33] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[33] = (unsigned int  )21;
   sqlstm.sqhsts[33] = (         int  )0;
   sqlstm.sqindv[33] = (         void  *)0;
   sqlstm.sqinds[33] = (         int  )0;
   sqlstm.sqharm[33] = (unsigned int  )0;
   sqlstm.sqadto[33] = (unsigned short )0;
   sqlstm.sqtdso[33] = (unsigned short )0;
   sqlstm.sqhstv[34] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[34] = (unsigned int  )11;
   sqlstm.sqhsts[34] = (         int  )0;
   sqlstm.sqindv[34] = (         void  *)0;
   sqlstm.sqinds[34] = (         int  )0;
   sqlstm.sqharm[34] = (unsigned int  )0;
   sqlstm.sqadto[34] = (unsigned short )0;
   sqlstm.sqtdso[34] = (unsigned short )0;
   sqlstm.sqhstv[35] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[35] = (unsigned int  )21;
   sqlstm.sqhsts[35] = (         int  )0;
   sqlstm.sqindv[35] = (         void  *)0;
   sqlstm.sqinds[35] = (         int  )0;
   sqlstm.sqharm[35] = (unsigned int  )0;
   sqlstm.sqadto[35] = (unsigned short )0;
   sqlstm.sqtdso[35] = (unsigned short )0;
   sqlstm.sqhstv[36] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[36] = (unsigned int  )11;
   sqlstm.sqhsts[36] = (         int  )0;
   sqlstm.sqindv[36] = (         void  *)0;
   sqlstm.sqinds[36] = (         int  )0;
   sqlstm.sqharm[36] = (unsigned int  )0;
   sqlstm.sqadto[36] = (unsigned short )0;
   sqlstm.sqtdso[36] = (unsigned short )0;
   sqlstm.sqhstv[37] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[37] = (unsigned int  )21;
   sqlstm.sqhsts[37] = (         int  )0;
   sqlstm.sqindv[37] = (         void  *)0;
   sqlstm.sqinds[37] = (         int  )0;
   sqlstm.sqharm[37] = (unsigned int  )0;
   sqlstm.sqadto[37] = (unsigned short )0;
   sqlstm.sqtdso[37] = (unsigned short )0;
   sqlstm.sqhstv[38] = (         void  *)(MGCMTBLDEF_N.FACTORY);
   sqlstm.sqhstl[38] = (unsigned int  )11;
   sqlstm.sqhsts[38] = (         int  )0;
   sqlstm.sqindv[38] = (         void  *)0;
   sqlstm.sqinds[38] = (         int  )0;
   sqlstm.sqharm[38] = (unsigned int  )0;
   sqlstm.sqadto[38] = (unsigned short )0;
   sqlstm.sqtdso[38] = (unsigned short )0;
   sqlstm.sqhstv[39] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
   sqlstm.sqhstl[39] = (unsigned int  )21;
   sqlstm.sqhsts[39] = (         int  )0;
   sqlstm.sqindv[39] = (         void  *)0;
   sqlstm.sqinds[39] = (         int  )0;
   sqlstm.sqharm[39] = (unsigned int  )0;
   sqlstm.sqadto[39] = (unsigned short )0;
   sqlstm.sqtdso[39] = (unsigned short )0;
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

        case 6:
            /* EXEC SQL DECLARE DBC_MGCMTBLDEF_CUR_6 CURSOR FOR
                SELECT FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG 
                FROM MGCMTBLDEF
                WHERE FACTORY = :MGCMTBLDEF_N.FACTORY
                AND SYS_TBL_FLAG = :MGCMTBLDEF_N.SYS_TBL_FLAG
                AND CENTRAL_FLAG = :MGCMTBLDEF_N.CENTRAL_FLAG
                AND SEC_CHK_FLAG = :MGCMTBLDEF_N.SEC_CHK_FLAG
                AND TABLE_TYPE LIKE :MGCMTBLDEF_N.TABLE_TYPE
                AND TABLE_GROUP LIKE :MGCMTBLDEF_N.TABLE_GROUP
                AND TABLE_NAME >= :MGCMTBLDEF_N.TABLE_NAME
                ORDER BY TABLE_NAME ASC; */ 

            /* EXEC SQL OPEN DBC_MGCMTBLDEF_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0013;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2357;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[6] = (unsigned int  )21;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_mgcmtbldef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mgcmtbldef(int sel_type, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MGCMTBLDEF_N_TAG MGCMTBLDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MGCMTBLDEF_CUR_1 INTO :MGCMTBLDEF_N.FACTORY, :MGCMTBLDEF_N.TABLE_NAME, :MGCMTBLDEF_N.TABLE_DESC, :MGCMTBLDEF_N.SYS_TBL_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2400;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
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
            /* EXEC SQL FETCH DBC_MGCMTBLDEF_CUR_2 INTO 
                                                    :MGCMTBLDEF_N.FACTORY,
                                                    :MGCMTBLDEF_N.TABLE_NAME,
                                                    :MGCMTBLDEF_N.TABLE_DESC,
                                                    :MGCMTBLDEF_N.SYS_TBL_FLAG,
                                                    :MGCMTBLDEF_N.CENTRAL_FLAG,
                                                    :MGCMTBLDEF_N.TABLE_TYPE,
                                                    :MGCMTBLDEF_N.USE_SQL_FLAG,
                                                    :MGCMTBLDEF_N.TABLE_GROUP,
                                                    :MGCMTBLDEF_N.KEY_1_PRT,
                                                    :MGCMTBLDEF_N.KEY_1_FMT,
                                                    :MGCMTBLDEF_N.KEY_1_SIZE,
                                                    :MGCMTBLDEF_N.KEY_2_PRT,
                                                    :MGCMTBLDEF_N.KEY_2_FMT,
                                                    :MGCMTBLDEF_N.KEY_2_SIZE,
                                                    :MGCMTBLDEF_N.KEY_3_PRT,
                                                    :MGCMTBLDEF_N.KEY_3_FMT,
                                                    :MGCMTBLDEF_N.KEY_3_SIZE,
                                                    :MGCMTBLDEF_N.KEY_4_PRT,
                                                    :MGCMTBLDEF_N.KEY_4_FMT,
                                                    :MGCMTBLDEF_N.KEY_4_SIZE,
                                                    :MGCMTBLDEF_N.KEY_5_PRT,
                                                    :MGCMTBLDEF_N.KEY_5_FMT,
                                                    :MGCMTBLDEF_N.KEY_5_SIZE,
                                                    :MGCMTBLDEF_N.KEY_6_PRT,
                                                    :MGCMTBLDEF_N.KEY_6_FMT,
                                                    :MGCMTBLDEF_N.KEY_6_SIZE,
                                                    :MGCMTBLDEF_N.KEY_7_PRT,
                                                    :MGCMTBLDEF_N.KEY_7_FMT,
                                                    :MGCMTBLDEF_N.KEY_7_SIZE,
                                                    :MGCMTBLDEF_N.KEY_8_PRT,
                                                    :MGCMTBLDEF_N.KEY_8_FMT,
                                                    :MGCMTBLDEF_N.KEY_8_SIZE,
                                                    :MGCMTBLDEF_N.KEY_9_PRT,
                                                    :MGCMTBLDEF_N.KEY_9_FMT,
                                                    :MGCMTBLDEF_N.KEY_9_SIZE,
                                                    :MGCMTBLDEF_N.KEY_10_PRT,
                                                    :MGCMTBLDEF_N.KEY_10_FMT,
                                                    :MGCMTBLDEF_N.KEY_10_SIZE,
                                                    :MGCMTBLDEF_N.DATA_1_PRT,
                                                    :MGCMTBLDEF_N.DATA_1_FMT,
                                                    :MGCMTBLDEF_N.DATA_1_SIZE,
                                                    :MGCMTBLDEF_N.DATA_2_PRT,
                                                    :MGCMTBLDEF_N.DATA_2_FMT,
                                                    :MGCMTBLDEF_N.DATA_2_SIZE,
                                                    :MGCMTBLDEF_N.DATA_3_PRT,
                                                    :MGCMTBLDEF_N.DATA_3_FMT,
                                                    :MGCMTBLDEF_N.DATA_3_SIZE,
                                                    :MGCMTBLDEF_N.DATA_4_PRT,
                                                    :MGCMTBLDEF_N.DATA_4_FMT,
                                                    :MGCMTBLDEF_N.DATA_4_SIZE,
                                                    :MGCMTBLDEF_N.DATA_5_PRT,
                                                    :MGCMTBLDEF_N.DATA_5_FMT,
                                                    :MGCMTBLDEF_N.DATA_5_SIZE,
                                                    :MGCMTBLDEF_N.DATA_6_PRT,
                                                    :MGCMTBLDEF_N.DATA_6_FMT,
                                                    :MGCMTBLDEF_N.DATA_6_SIZE,
                                                    :MGCMTBLDEF_N.DATA_7_PRT,
                                                    :MGCMTBLDEF_N.DATA_7_FMT,
                                                    :MGCMTBLDEF_N.DATA_7_SIZE,
                                                    :MGCMTBLDEF_N.DATA_8_PRT,
                                                    :MGCMTBLDEF_N.DATA_8_FMT,
                                                    :MGCMTBLDEF_N.DATA_8_SIZE,
                                                    :MGCMTBLDEF_N.DATA_9_PRT,
                                                    :MGCMTBLDEF_N.DATA_9_FMT,
                                                    :MGCMTBLDEF_N.DATA_9_SIZE,
                                                    :MGCMTBLDEF_N.DATA_10_PRT,
                                                    :MGCMTBLDEF_N.DATA_10_FMT,
                                                    :MGCMTBLDEF_N.DATA_10_SIZE,
                                                    :MGCMTBLDEF_N.SQL_1,
                                                    :MGCMTBLDEF_N.SQL_2,
                                                    :MGCMTBLDEF_N.SQL_3,
                                                    :MGCMTBLDEF_N.SQL_4,
                                                    :MGCMTBLDEF_N.SQL_5,
                                                    :MGCMTBLDEF_N.TABLE_PASSWORD,
                                                    :MGCMTBLDEF_N.SEC_CHK_FLAG,
                                                    :MGCMTBLDEF_N.CREATE_USER_ID,
                                                    :MGCMTBLDEF_N.CREATE_TIME,
                                                    :MGCMTBLDEF_N.UPDATE_USER_ID,
                                                    :MGCMTBLDEF_N.UPDATE_TIME,
                                                    :MGCMTBLDEF_N.KEY_1_TBL,
                                                    :MGCMTBLDEF_N.KEY_1_COL,
                                                    :MGCMTBLDEF_N.KEY_2_TBL,
                                                    :MGCMTBLDEF_N.KEY_2_COL,
                                                    :MGCMTBLDEF_N.KEY_3_TBL,
                                                    :MGCMTBLDEF_N.KEY_3_COL,
                                                    :MGCMTBLDEF_N.KEY_4_TBL,
                                                    :MGCMTBLDEF_N.KEY_4_COL,
                                                    :MGCMTBLDEF_N.KEY_5_TBL,
                                                    :MGCMTBLDEF_N.KEY_5_COL,
                                                    :MGCMTBLDEF_N.KEY_6_TBL,
                                                    :MGCMTBLDEF_N.KEY_6_COL,
                                                    :MGCMTBLDEF_N.KEY_7_TBL,
                                                    :MGCMTBLDEF_N.KEY_7_COL,
                                                    :MGCMTBLDEF_N.KEY_8_TBL,
                                                    :MGCMTBLDEF_N.KEY_8_COL,
                                                    :MGCMTBLDEF_N.KEY_9_TBL,
                                                    :MGCMTBLDEF_N.KEY_9_COL,
                                                    :MGCMTBLDEF_N.KEY_10_TBL,
                                                    :MGCMTBLDEF_N.KEY_10_COL,
                                                    :MGCMTBLDEF_N.DATA_1_TBL,
                                                    :MGCMTBLDEF_N.DATA_1_COL,
                                                    :MGCMTBLDEF_N.DATA_2_TBL,
                                                    :MGCMTBLDEF_N.DATA_2_COL,
                                                    :MGCMTBLDEF_N.DATA_3_TBL,
                                                    :MGCMTBLDEF_N.DATA_3_COL,
                                                    :MGCMTBLDEF_N.DATA_4_TBL,
                                                    :MGCMTBLDEF_N.DATA_4_COL,
                                                    :MGCMTBLDEF_N.DATA_5_TBL,
                                                    :MGCMTBLDEF_N.DATA_5_COL,
                                                    :MGCMTBLDEF_N.DATA_6_TBL,
                                                    :MGCMTBLDEF_N.DATA_6_COL,
                                                    :MGCMTBLDEF_N.DATA_7_TBL,
                                                    :MGCMTBLDEF_N.DATA_7_COL,
                                                    :MGCMTBLDEF_N.DATA_8_TBL,
                                                    :MGCMTBLDEF_N.DATA_8_COL,
                                                    :MGCMTBLDEF_N.DATA_9_TBL,
                                                    :MGCMTBLDEF_N.DATA_9_COL,
                                                    :MGCMTBLDEF_N.DATA_10_TBL,
                                                    :MGCMTBLDEF_N.DATA_10_COL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2431;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MGCMTBLDEF_N.CENTRAL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MGCMTBLDEF_N.TABLE_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MGCMTBLDEF_N.USE_SQL_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MGCMTBLDEF_N.TABLE_GROUP);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MGCMTBLDEF_N.KEY_1_PRT);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MGCMTBLDEF_N.KEY_1_FMT);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MGCMTBLDEF_N.KEY_1_SIZE);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MGCMTBLDEF_N.KEY_2_PRT);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MGCMTBLDEF_N.KEY_2_FMT);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MGCMTBLDEF_N.KEY_2_SIZE);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MGCMTBLDEF_N.KEY_3_PRT);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MGCMTBLDEF_N.KEY_3_FMT);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MGCMTBLDEF_N.KEY_3_SIZE);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MGCMTBLDEF_N.KEY_4_PRT);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MGCMTBLDEF_N.KEY_4_FMT);
            sqlstm.sqhstl[18] = (unsigned int  )2;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)&(MGCMTBLDEF_N.KEY_4_SIZE);
            sqlstm.sqhstl[19] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MGCMTBLDEF_N.KEY_5_PRT);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MGCMTBLDEF_N.KEY_5_FMT);
            sqlstm.sqhstl[21] = (unsigned int  )2;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MGCMTBLDEF_N.KEY_5_SIZE);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MGCMTBLDEF_N.KEY_6_PRT);
            sqlstm.sqhstl[23] = (unsigned int  )21;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MGCMTBLDEF_N.KEY_6_FMT);
            sqlstm.sqhstl[24] = (unsigned int  )2;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MGCMTBLDEF_N.KEY_6_SIZE);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MGCMTBLDEF_N.KEY_7_PRT);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MGCMTBLDEF_N.KEY_7_FMT);
            sqlstm.sqhstl[27] = (unsigned int  )2;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(MGCMTBLDEF_N.KEY_7_SIZE);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MGCMTBLDEF_N.KEY_8_PRT);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MGCMTBLDEF_N.KEY_8_FMT);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)&(MGCMTBLDEF_N.KEY_8_SIZE);
            sqlstm.sqhstl[31] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MGCMTBLDEF_N.KEY_9_PRT);
            sqlstm.sqhstl[32] = (unsigned int  )21;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MGCMTBLDEF_N.KEY_9_FMT);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)&(MGCMTBLDEF_N.KEY_9_SIZE);
            sqlstm.sqhstl[34] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MGCMTBLDEF_N.KEY_10_PRT);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MGCMTBLDEF_N.KEY_10_FMT);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MGCMTBLDEF_N.KEY_10_SIZE);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MGCMTBLDEF_N.DATA_1_PRT);
            sqlstm.sqhstl[38] = (unsigned int  )21;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MGCMTBLDEF_N.DATA_1_FMT);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MGCMTBLDEF_N.DATA_1_SIZE);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MGCMTBLDEF_N.DATA_2_PRT);
            sqlstm.sqhstl[41] = (unsigned int  )21;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MGCMTBLDEF_N.DATA_2_FMT);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)&(MGCMTBLDEF_N.DATA_2_SIZE);
            sqlstm.sqhstl[43] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MGCMTBLDEF_N.DATA_3_PRT);
            sqlstm.sqhstl[44] = (unsigned int  )21;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MGCMTBLDEF_N.DATA_3_FMT);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)&(MGCMTBLDEF_N.DATA_3_SIZE);
            sqlstm.sqhstl[46] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MGCMTBLDEF_N.DATA_4_PRT);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MGCMTBLDEF_N.DATA_4_FMT);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)&(MGCMTBLDEF_N.DATA_4_SIZE);
            sqlstm.sqhstl[49] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MGCMTBLDEF_N.DATA_5_PRT);
            sqlstm.sqhstl[50] = (unsigned int  )21;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MGCMTBLDEF_N.DATA_5_FMT);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)&(MGCMTBLDEF_N.DATA_5_SIZE);
            sqlstm.sqhstl[52] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MGCMTBLDEF_N.DATA_6_PRT);
            sqlstm.sqhstl[53] = (unsigned int  )21;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MGCMTBLDEF_N.DATA_6_FMT);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MGCMTBLDEF_N.DATA_6_SIZE);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MGCMTBLDEF_N.DATA_7_PRT);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MGCMTBLDEF_N.DATA_7_FMT);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MGCMTBLDEF_N.DATA_7_SIZE);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MGCMTBLDEF_N.DATA_8_PRT);
            sqlstm.sqhstl[59] = (unsigned int  )21;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MGCMTBLDEF_N.DATA_8_FMT);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(MGCMTBLDEF_N.DATA_8_SIZE);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MGCMTBLDEF_N.DATA_9_PRT);
            sqlstm.sqhstl[62] = (unsigned int  )21;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MGCMTBLDEF_N.DATA_9_FMT);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(MGCMTBLDEF_N.DATA_9_SIZE);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MGCMTBLDEF_N.DATA_10_PRT);
            sqlstm.sqhstl[65] = (unsigned int  )21;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MGCMTBLDEF_N.DATA_10_FMT);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)&(MGCMTBLDEF_N.DATA_10_SIZE);
            sqlstm.sqhstl[67] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MGCMTBLDEF_N.SQL_1);
            sqlstm.sqhstl[68] = (unsigned int  )2001;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MGCMTBLDEF_N.SQL_2);
            sqlstm.sqhstl[69] = (unsigned int  )2001;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MGCMTBLDEF_N.SQL_3);
            sqlstm.sqhstl[70] = (unsigned int  )2001;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MGCMTBLDEF_N.SQL_4);
            sqlstm.sqhstl[71] = (unsigned int  )2001;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MGCMTBLDEF_N.SQL_5);
            sqlstm.sqhstl[72] = (unsigned int  )2001;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MGCMTBLDEF_N.TABLE_PASSWORD);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MGCMTBLDEF_N.SEC_CHK_FLAG);
            sqlstm.sqhstl[74] = (unsigned int  )2;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MGCMTBLDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MGCMTBLDEF_N.CREATE_TIME);
            sqlstm.sqhstl[76] = (unsigned int  )15;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MGCMTBLDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MGCMTBLDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[78] = (unsigned int  )15;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MGCMTBLDEF_N.KEY_1_TBL);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MGCMTBLDEF_N.KEY_1_COL);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MGCMTBLDEF_N.KEY_2_TBL);
            sqlstm.sqhstl[81] = (unsigned int  )21;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MGCMTBLDEF_N.KEY_2_COL);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MGCMTBLDEF_N.KEY_3_TBL);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MGCMTBLDEF_N.KEY_3_COL);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MGCMTBLDEF_N.KEY_4_TBL);
            sqlstm.sqhstl[85] = (unsigned int  )21;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MGCMTBLDEF_N.KEY_4_COL);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MGCMTBLDEF_N.KEY_5_TBL);
            sqlstm.sqhstl[87] = (unsigned int  )21;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MGCMTBLDEF_N.KEY_5_COL);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MGCMTBLDEF_N.KEY_6_TBL);
            sqlstm.sqhstl[89] = (unsigned int  )21;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MGCMTBLDEF_N.KEY_6_COL);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MGCMTBLDEF_N.KEY_7_TBL);
            sqlstm.sqhstl[91] = (unsigned int  )21;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MGCMTBLDEF_N.KEY_7_COL);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MGCMTBLDEF_N.KEY_8_TBL);
            sqlstm.sqhstl[93] = (unsigned int  )21;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MGCMTBLDEF_N.KEY_8_COL);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MGCMTBLDEF_N.KEY_9_TBL);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MGCMTBLDEF_N.KEY_9_COL);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MGCMTBLDEF_N.KEY_10_TBL);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MGCMTBLDEF_N.KEY_10_COL);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MGCMTBLDEF_N.DATA_1_TBL);
            sqlstm.sqhstl[99] = (unsigned int  )21;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MGCMTBLDEF_N.DATA_1_COL);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MGCMTBLDEF_N.DATA_2_TBL);
            sqlstm.sqhstl[101] = (unsigned int  )21;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MGCMTBLDEF_N.DATA_2_COL);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MGCMTBLDEF_N.DATA_3_TBL);
            sqlstm.sqhstl[103] = (unsigned int  )21;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MGCMTBLDEF_N.DATA_3_COL);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MGCMTBLDEF_N.DATA_4_TBL);
            sqlstm.sqhstl[105] = (unsigned int  )21;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MGCMTBLDEF_N.DATA_4_COL);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MGCMTBLDEF_N.DATA_5_TBL);
            sqlstm.sqhstl[107] = (unsigned int  )21;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MGCMTBLDEF_N.DATA_5_COL);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MGCMTBLDEF_N.DATA_6_TBL);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MGCMTBLDEF_N.DATA_6_COL);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MGCMTBLDEF_N.DATA_7_TBL);
            sqlstm.sqhstl[111] = (unsigned int  )21;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MGCMTBLDEF_N.DATA_7_COL);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MGCMTBLDEF_N.DATA_8_TBL);
            sqlstm.sqhstl[113] = (unsigned int  )21;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MGCMTBLDEF_N.DATA_8_COL);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MGCMTBLDEF_N.DATA_9_TBL);
            sqlstm.sqhstl[115] = (unsigned int  )21;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MGCMTBLDEF_N.DATA_9_COL);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MGCMTBLDEF_N.DATA_10_TBL);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MGCMTBLDEF_N.DATA_10_COL);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_MGCMTBLDEF_CUR_3 INTO :MGCMTBLDEF_N.FACTORY, :MGCMTBLDEF_N.TABLE_NAME, :MGCMTBLDEF_N.TABLE_DESC, :MGCMTBLDEF_N.SYS_TBL_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2922;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
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
            /* EXEC SQL FETCH DBC_MGCMTBLDEF_CUR_4 INTO :MGCMTBLDEF_N.FACTORY, :MGCMTBLDEF_N.TABLE_NAME, :MGCMTBLDEF_N.TABLE_DESC, :MGCMTBLDEF_N.SYS_TBL_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2953;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
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

		case 5:
            /* EXEC SQL FETCH DBC_MGCMTBLDEF_CUR_5 INTO :MGCMTBLDEF_N.TABLE_NAME, :MGCMTBLDEF_N.KEY_1_PRT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2984;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.KEY_1_PRT);
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

        case 6:
            /* EXEC SQL FETCH DBC_MGCMTBLDEF_CUR_6 INTO :MGCMTBLDEF_N.FACTORY, :MGCMTBLDEF_N.TABLE_NAME, :MGCMTBLDEF_N.TABLE_DESC, :MGCMTBLDEF_N.SYS_TBL_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3007;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MGCMTBLDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MGCMTBLDEF_N.TABLE_NAME);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MGCMTBLDEF_N.TABLE_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MGCMTBLDEF_N.SYS_TBL_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
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
        DBC_del_null_mgcmtbldef(&MGCMTBLDEF_N, MGCMTBLDEF);
    }
    DB_stop_query_timer("DBC_fetch_mgcmtbldef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mgcmtbldef(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MGCMTBLDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3038;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL CLOSE DBC_MGCMTBLDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3053;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        
        case 3:
            /* EXEC SQL CLOSE DBC_MGCMTBLDEF_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3068;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4:
            /* EXEC SQL CLOSE DBC_MGCMTBLDEF_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3083;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 5:
            /* EXEC SQL CLOSE DBC_MGCMTBLDEF_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3098;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 6:
            /* EXEC SQL CLOSE DBC_MGCMTBLDEF_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 121;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3113;
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
    DB_stop_query_timer("DBC_close_mgcmtbldef", sel_type);
}


/* Initialize Function */
void DBC_init_mgcmtbldef(struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* memset by Space */
    memset(MGCMTBLDEF, ' ', sizeof(struct MGCMTBLDEF_TAG));
    
    MGCMTBLDEF->KEY_1_SIZE = 0;
    MGCMTBLDEF->KEY_2_SIZE = 0;
    MGCMTBLDEF->KEY_3_SIZE = 0;
    MGCMTBLDEF->KEY_4_SIZE = 0;
    MGCMTBLDEF->KEY_5_SIZE = 0;
    MGCMTBLDEF->KEY_6_SIZE = 0;
    MGCMTBLDEF->KEY_7_SIZE = 0;
    MGCMTBLDEF->KEY_8_SIZE = 0;
    MGCMTBLDEF->KEY_9_SIZE = 0;
    MGCMTBLDEF->KEY_10_SIZE = 0;
    MGCMTBLDEF->DATA_1_SIZE = 0;
    MGCMTBLDEF->DATA_2_SIZE = 0;
    MGCMTBLDEF->DATA_3_SIZE = 0;
    MGCMTBLDEF->DATA_4_SIZE = 0;
    MGCMTBLDEF->DATA_5_SIZE = 0;
    MGCMTBLDEF->DATA_6_SIZE = 0;
    MGCMTBLDEF->DATA_7_SIZE = 0;
    MGCMTBLDEF->DATA_8_SIZE = 0;
    MGCMTBLDEF->DATA_9_SIZE = 0;
    MGCMTBLDEF->DATA_10_SIZE = 0;
}

/* Add Null Function */
void DBC_add_null_mgcmtbldef(struct MGCMTBLDEF_N_TAG *MGCMTBLDEF_N, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    /* memset by NULL */
    memset(MGCMTBLDEF_N, '\0', sizeof(struct MGCMTBLDEF_N_TAG));
    
    MEMCPY_AN(MGCMTBLDEF_N->FACTORY, MGCMTBLDEF->FACTORY, sizeof(MGCMTBLDEF->FACTORY));
    MEMCPY_AN(MGCMTBLDEF_N->TABLE_NAME, MGCMTBLDEF->TABLE_NAME, sizeof(MGCMTBLDEF->TABLE_NAME));
    MEMCPY_AN(MGCMTBLDEF_N->TABLE_DESC, MGCMTBLDEF->TABLE_DESC, sizeof(MGCMTBLDEF->TABLE_DESC));
    MGCMTBLDEF_N->SYS_TBL_FLAG[0] = MGCMTBLDEF->SYS_TBL_FLAG;
    MGCMTBLDEF_N->CENTRAL_FLAG[0] = MGCMTBLDEF->CENTRAL_FLAG;
    MGCMTBLDEF_N->TABLE_TYPE[0] = MGCMTBLDEF->TABLE_TYPE;
    MGCMTBLDEF_N->USE_SQL_FLAG[0] = MGCMTBLDEF->USE_SQL_FLAG;
    MEMCPY_AN(MGCMTBLDEF_N->TABLE_GROUP, MGCMTBLDEF->TABLE_GROUP, sizeof(MGCMTBLDEF->TABLE_GROUP));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_1_PRT, MGCMTBLDEF->KEY_1_PRT, sizeof(MGCMTBLDEF->KEY_1_PRT));
    MGCMTBLDEF_N->KEY_1_FMT[0] = MGCMTBLDEF->KEY_1_FMT;
    MGCMTBLDEF_N->KEY_1_SIZE = MGCMTBLDEF->KEY_1_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_2_PRT, MGCMTBLDEF->KEY_2_PRT, sizeof(MGCMTBLDEF->KEY_2_PRT));
    MGCMTBLDEF_N->KEY_2_FMT[0] = MGCMTBLDEF->KEY_2_FMT;
    MGCMTBLDEF_N->KEY_2_SIZE = MGCMTBLDEF->KEY_2_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_3_PRT, MGCMTBLDEF->KEY_3_PRT, sizeof(MGCMTBLDEF->KEY_3_PRT));
    MGCMTBLDEF_N->KEY_3_FMT[0] = MGCMTBLDEF->KEY_3_FMT;
    MGCMTBLDEF_N->KEY_3_SIZE = MGCMTBLDEF->KEY_3_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_4_PRT, MGCMTBLDEF->KEY_4_PRT, sizeof(MGCMTBLDEF->KEY_4_PRT));
    MGCMTBLDEF_N->KEY_4_FMT[0] = MGCMTBLDEF->KEY_4_FMT;
    MGCMTBLDEF_N->KEY_4_SIZE = MGCMTBLDEF->KEY_4_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_5_PRT, MGCMTBLDEF->KEY_5_PRT, sizeof(MGCMTBLDEF->KEY_5_PRT));
    MGCMTBLDEF_N->KEY_5_FMT[0] = MGCMTBLDEF->KEY_5_FMT;
    MGCMTBLDEF_N->KEY_5_SIZE = MGCMTBLDEF->KEY_5_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_6_PRT, MGCMTBLDEF->KEY_6_PRT, sizeof(MGCMTBLDEF->KEY_6_PRT));
    MGCMTBLDEF_N->KEY_6_FMT[0] = MGCMTBLDEF->KEY_6_FMT;
    MGCMTBLDEF_N->KEY_6_SIZE = MGCMTBLDEF->KEY_6_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_7_PRT, MGCMTBLDEF->KEY_7_PRT, sizeof(MGCMTBLDEF->KEY_7_PRT));
    MGCMTBLDEF_N->KEY_7_FMT[0] = MGCMTBLDEF->KEY_7_FMT;
    MGCMTBLDEF_N->KEY_7_SIZE = MGCMTBLDEF->KEY_7_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_8_PRT, MGCMTBLDEF->KEY_8_PRT, sizeof(MGCMTBLDEF->KEY_8_PRT));
    MGCMTBLDEF_N->KEY_8_FMT[0] = MGCMTBLDEF->KEY_8_FMT;
    MGCMTBLDEF_N->KEY_8_SIZE = MGCMTBLDEF->KEY_8_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_9_PRT, MGCMTBLDEF->KEY_9_PRT, sizeof(MGCMTBLDEF->KEY_9_PRT));
    MGCMTBLDEF_N->KEY_9_FMT[0] = MGCMTBLDEF->KEY_9_FMT;
    MGCMTBLDEF_N->KEY_9_SIZE = MGCMTBLDEF->KEY_9_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->KEY_10_PRT, MGCMTBLDEF->KEY_10_PRT, sizeof(MGCMTBLDEF->KEY_10_PRT));
    MGCMTBLDEF_N->KEY_10_FMT[0] = MGCMTBLDEF->KEY_10_FMT;
    MGCMTBLDEF_N->KEY_10_SIZE = MGCMTBLDEF->KEY_10_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_1_PRT, MGCMTBLDEF->DATA_1_PRT, sizeof(MGCMTBLDEF->DATA_1_PRT));
    MGCMTBLDEF_N->DATA_1_FMT[0] = MGCMTBLDEF->DATA_1_FMT;
    MGCMTBLDEF_N->DATA_1_SIZE = MGCMTBLDEF->DATA_1_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_2_PRT, MGCMTBLDEF->DATA_2_PRT, sizeof(MGCMTBLDEF->DATA_2_PRT));
    MGCMTBLDEF_N->DATA_2_FMT[0] = MGCMTBLDEF->DATA_2_FMT;
    MGCMTBLDEF_N->DATA_2_SIZE = MGCMTBLDEF->DATA_2_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_3_PRT, MGCMTBLDEF->DATA_3_PRT, sizeof(MGCMTBLDEF->DATA_3_PRT));
    MGCMTBLDEF_N->DATA_3_FMT[0] = MGCMTBLDEF->DATA_3_FMT;
    MGCMTBLDEF_N->DATA_3_SIZE = MGCMTBLDEF->DATA_3_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_4_PRT, MGCMTBLDEF->DATA_4_PRT, sizeof(MGCMTBLDEF->DATA_4_PRT));
    MGCMTBLDEF_N->DATA_4_FMT[0] = MGCMTBLDEF->DATA_4_FMT;
    MGCMTBLDEF_N->DATA_4_SIZE = MGCMTBLDEF->DATA_4_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_5_PRT, MGCMTBLDEF->DATA_5_PRT, sizeof(MGCMTBLDEF->DATA_5_PRT));
    MGCMTBLDEF_N->DATA_5_FMT[0] = MGCMTBLDEF->DATA_5_FMT;
    MGCMTBLDEF_N->DATA_5_SIZE = MGCMTBLDEF->DATA_5_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_6_PRT, MGCMTBLDEF->DATA_6_PRT, sizeof(MGCMTBLDEF->DATA_6_PRT));
    MGCMTBLDEF_N->DATA_6_FMT[0] = MGCMTBLDEF->DATA_6_FMT;
    MGCMTBLDEF_N->DATA_6_SIZE = MGCMTBLDEF->DATA_6_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_7_PRT, MGCMTBLDEF->DATA_7_PRT, sizeof(MGCMTBLDEF->DATA_7_PRT));
    MGCMTBLDEF_N->DATA_7_FMT[0] = MGCMTBLDEF->DATA_7_FMT;
    MGCMTBLDEF_N->DATA_7_SIZE = MGCMTBLDEF->DATA_7_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_8_PRT, MGCMTBLDEF->DATA_8_PRT, sizeof(MGCMTBLDEF->DATA_8_PRT));
    MGCMTBLDEF_N->DATA_8_FMT[0] = MGCMTBLDEF->DATA_8_FMT;
    MGCMTBLDEF_N->DATA_8_SIZE = MGCMTBLDEF->DATA_8_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_9_PRT, MGCMTBLDEF->DATA_9_PRT, sizeof(MGCMTBLDEF->DATA_9_PRT));
    MGCMTBLDEF_N->DATA_9_FMT[0] = MGCMTBLDEF->DATA_9_FMT;
    MGCMTBLDEF_N->DATA_9_SIZE = MGCMTBLDEF->DATA_9_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->DATA_10_PRT, MGCMTBLDEF->DATA_10_PRT, sizeof(MGCMTBLDEF->DATA_10_PRT));
    MGCMTBLDEF_N->DATA_10_FMT[0] = MGCMTBLDEF->DATA_10_FMT;
    MGCMTBLDEF_N->DATA_10_SIZE = MGCMTBLDEF->DATA_10_SIZE;
    MEMCPY_AN(MGCMTBLDEF_N->SQL_1, MGCMTBLDEF->SQL_1, sizeof(MGCMTBLDEF->SQL_1));
    MEMCPY_AN(MGCMTBLDEF_N->SQL_2, MGCMTBLDEF->SQL_2, sizeof(MGCMTBLDEF->SQL_2));
    MEMCPY_AN(MGCMTBLDEF_N->SQL_3, MGCMTBLDEF->SQL_3, sizeof(MGCMTBLDEF->SQL_3));
    MEMCPY_AN(MGCMTBLDEF_N->SQL_4, MGCMTBLDEF->SQL_4, sizeof(MGCMTBLDEF->SQL_4));
    MEMCPY_AN(MGCMTBLDEF_N->SQL_5, MGCMTBLDEF->SQL_5, sizeof(MGCMTBLDEF->SQL_5));
    MEMCPY_AN(MGCMTBLDEF_N->TABLE_PASSWORD, MGCMTBLDEF->TABLE_PASSWORD, sizeof(MGCMTBLDEF->TABLE_PASSWORD));
    MGCMTBLDEF_N->SEC_CHK_FLAG[0] = MGCMTBLDEF->SEC_CHK_FLAG;
    MEMCPY_AN(MGCMTBLDEF_N->CREATE_USER_ID, MGCMTBLDEF->CREATE_USER_ID, sizeof(MGCMTBLDEF->CREATE_USER_ID));
    MEMCPY_AN(MGCMTBLDEF_N->CREATE_TIME, MGCMTBLDEF->CREATE_TIME, sizeof(MGCMTBLDEF->CREATE_TIME));
    MEMCPY_AN(MGCMTBLDEF_N->UPDATE_USER_ID, MGCMTBLDEF->UPDATE_USER_ID, sizeof(MGCMTBLDEF->UPDATE_USER_ID));
    MEMCPY_AN(MGCMTBLDEF_N->UPDATE_TIME, MGCMTBLDEF->UPDATE_TIME, sizeof(MGCMTBLDEF->UPDATE_TIME));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_1_TBL, MGCMTBLDEF->KEY_1_TBL, sizeof(MGCMTBLDEF->KEY_1_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_1_COL, MGCMTBLDEF->KEY_1_COL, sizeof(MGCMTBLDEF->KEY_1_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_2_TBL, MGCMTBLDEF->KEY_2_TBL, sizeof(MGCMTBLDEF->KEY_2_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_2_COL, MGCMTBLDEF->KEY_2_COL, sizeof(MGCMTBLDEF->KEY_2_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_3_TBL, MGCMTBLDEF->KEY_3_TBL, sizeof(MGCMTBLDEF->KEY_3_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_3_COL, MGCMTBLDEF->KEY_3_COL, sizeof(MGCMTBLDEF->KEY_3_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_4_TBL, MGCMTBLDEF->KEY_4_TBL, sizeof(MGCMTBLDEF->KEY_4_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_4_COL, MGCMTBLDEF->KEY_4_COL, sizeof(MGCMTBLDEF->KEY_4_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_5_TBL, MGCMTBLDEF->KEY_5_TBL, sizeof(MGCMTBLDEF->KEY_5_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_5_COL, MGCMTBLDEF->KEY_5_COL, sizeof(MGCMTBLDEF->KEY_5_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_6_TBL, MGCMTBLDEF->KEY_6_TBL, sizeof(MGCMTBLDEF->KEY_6_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_6_COL, MGCMTBLDEF->KEY_6_COL, sizeof(MGCMTBLDEF->KEY_6_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_7_TBL, MGCMTBLDEF->KEY_7_TBL, sizeof(MGCMTBLDEF->KEY_7_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_7_COL, MGCMTBLDEF->KEY_7_COL, sizeof(MGCMTBLDEF->KEY_7_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_8_TBL, MGCMTBLDEF->KEY_8_TBL, sizeof(MGCMTBLDEF->KEY_8_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_8_COL, MGCMTBLDEF->KEY_8_COL, sizeof(MGCMTBLDEF->KEY_8_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_9_TBL, MGCMTBLDEF->KEY_9_TBL, sizeof(MGCMTBLDEF->KEY_9_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_9_COL, MGCMTBLDEF->KEY_9_COL, sizeof(MGCMTBLDEF->KEY_9_COL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_10_TBL, MGCMTBLDEF->KEY_10_TBL, sizeof(MGCMTBLDEF->KEY_10_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->KEY_10_COL, MGCMTBLDEF->KEY_10_COL, sizeof(MGCMTBLDEF->KEY_10_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_1_TBL, MGCMTBLDEF->DATA_1_TBL, sizeof(MGCMTBLDEF->DATA_1_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_1_COL, MGCMTBLDEF->DATA_1_COL, sizeof(MGCMTBLDEF->DATA_1_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_2_TBL, MGCMTBLDEF->DATA_2_TBL, sizeof(MGCMTBLDEF->DATA_2_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_2_COL, MGCMTBLDEF->DATA_2_COL, sizeof(MGCMTBLDEF->DATA_2_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_3_TBL, MGCMTBLDEF->DATA_3_TBL, sizeof(MGCMTBLDEF->DATA_3_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_3_COL, MGCMTBLDEF->DATA_3_COL, sizeof(MGCMTBLDEF->DATA_3_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_4_TBL, MGCMTBLDEF->DATA_4_TBL, sizeof(MGCMTBLDEF->DATA_4_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_4_COL, MGCMTBLDEF->DATA_4_COL, sizeof(MGCMTBLDEF->DATA_4_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_5_TBL, MGCMTBLDEF->DATA_5_TBL, sizeof(MGCMTBLDEF->DATA_5_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_5_COL, MGCMTBLDEF->DATA_5_COL, sizeof(MGCMTBLDEF->DATA_5_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_6_TBL, MGCMTBLDEF->DATA_6_TBL, sizeof(MGCMTBLDEF->DATA_6_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_6_COL, MGCMTBLDEF->DATA_6_COL, sizeof(MGCMTBLDEF->DATA_6_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_7_TBL, MGCMTBLDEF->DATA_7_TBL, sizeof(MGCMTBLDEF->DATA_7_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_7_COL, MGCMTBLDEF->DATA_7_COL, sizeof(MGCMTBLDEF->DATA_7_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_8_TBL, MGCMTBLDEF->DATA_8_TBL, sizeof(MGCMTBLDEF->DATA_8_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_8_COL, MGCMTBLDEF->DATA_8_COL, sizeof(MGCMTBLDEF->DATA_8_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_9_TBL, MGCMTBLDEF->DATA_9_TBL, sizeof(MGCMTBLDEF->DATA_9_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_9_COL, MGCMTBLDEF->DATA_9_COL, sizeof(MGCMTBLDEF->DATA_9_COL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_10_TBL, MGCMTBLDEF->DATA_10_TBL, sizeof(MGCMTBLDEF->DATA_10_TBL));
    MEMCPY_AN(MGCMTBLDEF_N->DATA_10_COL, MGCMTBLDEF->DATA_10_COL, sizeof(MGCMTBLDEF->DATA_10_COL));
}


/* Del Null Function */
void DBC_del_null_mgcmtbldef(struct MGCMTBLDEF_N_TAG *MGCMTBLDEF_N, struct MGCMTBLDEF_TAG *MGCMTBLDEF)
{
    MEMCPY_DN(MGCMTBLDEF->FACTORY, MGCMTBLDEF_N->FACTORY, sizeof(MGCMTBLDEF->FACTORY));
    MEMCPY_DN(MGCMTBLDEF->TABLE_NAME, MGCMTBLDEF_N->TABLE_NAME, sizeof(MGCMTBLDEF->TABLE_NAME));
    MEMCPY_DN(MGCMTBLDEF->TABLE_DESC, MGCMTBLDEF_N->TABLE_DESC, sizeof(MGCMTBLDEF->TABLE_DESC));
    MGCMTBLDEF->SYS_TBL_FLAG = MGCMTBLDEF_N->SYS_TBL_FLAG[0];
    MGCMTBLDEF->CENTRAL_FLAG = MGCMTBLDEF_N->CENTRAL_FLAG[0];
    MGCMTBLDEF->TABLE_TYPE = MGCMTBLDEF_N->TABLE_TYPE[0];
    MGCMTBLDEF->USE_SQL_FLAG = MGCMTBLDEF_N->USE_SQL_FLAG[0];
    MEMCPY_DN(MGCMTBLDEF->TABLE_GROUP, MGCMTBLDEF_N->TABLE_GROUP, sizeof(MGCMTBLDEF->TABLE_GROUP));
    MEMCPY_DN(MGCMTBLDEF->KEY_1_PRT, MGCMTBLDEF_N->KEY_1_PRT, sizeof(MGCMTBLDEF->KEY_1_PRT));
    MGCMTBLDEF->KEY_1_FMT = MGCMTBLDEF_N->KEY_1_FMT[0];
    MGCMTBLDEF->KEY_1_SIZE = MGCMTBLDEF_N->KEY_1_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_2_PRT, MGCMTBLDEF_N->KEY_2_PRT, sizeof(MGCMTBLDEF->KEY_2_PRT));
    MGCMTBLDEF->KEY_2_FMT = MGCMTBLDEF_N->KEY_2_FMT[0];
    MGCMTBLDEF->KEY_2_SIZE = MGCMTBLDEF_N->KEY_2_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_3_PRT, MGCMTBLDEF_N->KEY_3_PRT, sizeof(MGCMTBLDEF->KEY_3_PRT));
    MGCMTBLDEF->KEY_3_FMT = MGCMTBLDEF_N->KEY_3_FMT[0];
    MGCMTBLDEF->KEY_3_SIZE = MGCMTBLDEF_N->KEY_3_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_4_PRT, MGCMTBLDEF_N->KEY_4_PRT, sizeof(MGCMTBLDEF->KEY_4_PRT));
    MGCMTBLDEF->KEY_4_FMT = MGCMTBLDEF_N->KEY_4_FMT[0];
    MGCMTBLDEF->KEY_4_SIZE = MGCMTBLDEF_N->KEY_4_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_5_PRT, MGCMTBLDEF_N->KEY_5_PRT, sizeof(MGCMTBLDEF->KEY_5_PRT));
    MGCMTBLDEF->KEY_5_FMT = MGCMTBLDEF_N->KEY_5_FMT[0];
    MGCMTBLDEF->KEY_5_SIZE = MGCMTBLDEF_N->KEY_5_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_6_PRT, MGCMTBLDEF_N->KEY_6_PRT, sizeof(MGCMTBLDEF->KEY_6_PRT));
    MGCMTBLDEF->KEY_6_FMT = MGCMTBLDEF_N->KEY_6_FMT[0];
    MGCMTBLDEF->KEY_6_SIZE = MGCMTBLDEF_N->KEY_6_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_7_PRT, MGCMTBLDEF_N->KEY_7_PRT, sizeof(MGCMTBLDEF->KEY_7_PRT));
    MGCMTBLDEF->KEY_7_FMT = MGCMTBLDEF_N->KEY_7_FMT[0];
    MGCMTBLDEF->KEY_7_SIZE = MGCMTBLDEF_N->KEY_7_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_8_PRT, MGCMTBLDEF_N->KEY_8_PRT, sizeof(MGCMTBLDEF->KEY_8_PRT));
    MGCMTBLDEF->KEY_8_FMT = MGCMTBLDEF_N->KEY_8_FMT[0];
    MGCMTBLDEF->KEY_8_SIZE = MGCMTBLDEF_N->KEY_8_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_9_PRT, MGCMTBLDEF_N->KEY_9_PRT, sizeof(MGCMTBLDEF->KEY_9_PRT));
    MGCMTBLDEF->KEY_9_FMT = MGCMTBLDEF_N->KEY_9_FMT[0];
    MGCMTBLDEF->KEY_9_SIZE = MGCMTBLDEF_N->KEY_9_SIZE;
    MEMCPY_DN(MGCMTBLDEF->KEY_10_PRT, MGCMTBLDEF_N->KEY_10_PRT, sizeof(MGCMTBLDEF->KEY_10_PRT));
    MGCMTBLDEF->KEY_10_FMT = MGCMTBLDEF_N->KEY_10_FMT[0];
    MGCMTBLDEF->KEY_10_SIZE = MGCMTBLDEF_N->KEY_10_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_1_PRT, MGCMTBLDEF_N->DATA_1_PRT, sizeof(MGCMTBLDEF->DATA_1_PRT));
    MGCMTBLDEF->DATA_1_FMT = MGCMTBLDEF_N->DATA_1_FMT[0];
    MGCMTBLDEF->DATA_1_SIZE = MGCMTBLDEF_N->DATA_1_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_2_PRT, MGCMTBLDEF_N->DATA_2_PRT, sizeof(MGCMTBLDEF->DATA_2_PRT));
    MGCMTBLDEF->DATA_2_FMT = MGCMTBLDEF_N->DATA_2_FMT[0];
    MGCMTBLDEF->DATA_2_SIZE = MGCMTBLDEF_N->DATA_2_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_3_PRT, MGCMTBLDEF_N->DATA_3_PRT, sizeof(MGCMTBLDEF->DATA_3_PRT));
    MGCMTBLDEF->DATA_3_FMT = MGCMTBLDEF_N->DATA_3_FMT[0];
    MGCMTBLDEF->DATA_3_SIZE = MGCMTBLDEF_N->DATA_3_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_4_PRT, MGCMTBLDEF_N->DATA_4_PRT, sizeof(MGCMTBLDEF->DATA_4_PRT));
    MGCMTBLDEF->DATA_4_FMT = MGCMTBLDEF_N->DATA_4_FMT[0];
    MGCMTBLDEF->DATA_4_SIZE = MGCMTBLDEF_N->DATA_4_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_5_PRT, MGCMTBLDEF_N->DATA_5_PRT, sizeof(MGCMTBLDEF->DATA_5_PRT));
    MGCMTBLDEF->DATA_5_FMT = MGCMTBLDEF_N->DATA_5_FMT[0];
    MGCMTBLDEF->DATA_5_SIZE = MGCMTBLDEF_N->DATA_5_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_6_PRT, MGCMTBLDEF_N->DATA_6_PRT, sizeof(MGCMTBLDEF->DATA_6_PRT));
    MGCMTBLDEF->DATA_6_FMT = MGCMTBLDEF_N->DATA_6_FMT[0];
    MGCMTBLDEF->DATA_6_SIZE = MGCMTBLDEF_N->DATA_6_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_7_PRT, MGCMTBLDEF_N->DATA_7_PRT, sizeof(MGCMTBLDEF->DATA_7_PRT));
    MGCMTBLDEF->DATA_7_FMT = MGCMTBLDEF_N->DATA_7_FMT[0];
    MGCMTBLDEF->DATA_7_SIZE = MGCMTBLDEF_N->DATA_7_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_8_PRT, MGCMTBLDEF_N->DATA_8_PRT, sizeof(MGCMTBLDEF->DATA_8_PRT));
    MGCMTBLDEF->DATA_8_FMT = MGCMTBLDEF_N->DATA_8_FMT[0];
    MGCMTBLDEF->DATA_8_SIZE = MGCMTBLDEF_N->DATA_8_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_9_PRT, MGCMTBLDEF_N->DATA_9_PRT, sizeof(MGCMTBLDEF->DATA_9_PRT));
    MGCMTBLDEF->DATA_9_FMT = MGCMTBLDEF_N->DATA_9_FMT[0];
    MGCMTBLDEF->DATA_9_SIZE = MGCMTBLDEF_N->DATA_9_SIZE;
    MEMCPY_DN(MGCMTBLDEF->DATA_10_PRT, MGCMTBLDEF_N->DATA_10_PRT, sizeof(MGCMTBLDEF->DATA_10_PRT));
    MGCMTBLDEF->DATA_10_FMT = MGCMTBLDEF_N->DATA_10_FMT[0];
    MGCMTBLDEF->DATA_10_SIZE = MGCMTBLDEF_N->DATA_10_SIZE;
    MEMCPY_DN(MGCMTBLDEF->SQL_1, MGCMTBLDEF_N->SQL_1, sizeof(MGCMTBLDEF->SQL_1));
    MEMCPY_DN(MGCMTBLDEF->SQL_2, MGCMTBLDEF_N->SQL_2, sizeof(MGCMTBLDEF->SQL_2));
    MEMCPY_DN(MGCMTBLDEF->SQL_3, MGCMTBLDEF_N->SQL_3, sizeof(MGCMTBLDEF->SQL_3));
    MEMCPY_DN(MGCMTBLDEF->SQL_4, MGCMTBLDEF_N->SQL_4, sizeof(MGCMTBLDEF->SQL_4));
    MEMCPY_DN(MGCMTBLDEF->SQL_5, MGCMTBLDEF_N->SQL_5, sizeof(MGCMTBLDEF->SQL_5));
    MEMCPY_DN(MGCMTBLDEF->TABLE_PASSWORD, MGCMTBLDEF_N->TABLE_PASSWORD, sizeof(MGCMTBLDEF->TABLE_PASSWORD));
    MGCMTBLDEF->SEC_CHK_FLAG = MGCMTBLDEF_N->SEC_CHK_FLAG[0];
    MEMCPY_DN(MGCMTBLDEF->CREATE_USER_ID, MGCMTBLDEF_N->CREATE_USER_ID, sizeof(MGCMTBLDEF->CREATE_USER_ID));
    MEMCPY_DN(MGCMTBLDEF->CREATE_TIME, MGCMTBLDEF_N->CREATE_TIME, sizeof(MGCMTBLDEF->CREATE_TIME));
    MEMCPY_DN(MGCMTBLDEF->UPDATE_USER_ID, MGCMTBLDEF_N->UPDATE_USER_ID, sizeof(MGCMTBLDEF->UPDATE_USER_ID));
    MEMCPY_DN(MGCMTBLDEF->UPDATE_TIME, MGCMTBLDEF_N->UPDATE_TIME, sizeof(MGCMTBLDEF->UPDATE_TIME));
    MEMCPY_DN(MGCMTBLDEF->KEY_1_TBL, MGCMTBLDEF_N->KEY_1_TBL, sizeof(MGCMTBLDEF->KEY_1_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_1_COL, MGCMTBLDEF_N->KEY_1_COL, sizeof(MGCMTBLDEF->KEY_1_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_2_TBL, MGCMTBLDEF_N->KEY_2_TBL, sizeof(MGCMTBLDEF->KEY_2_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_2_COL, MGCMTBLDEF_N->KEY_2_COL, sizeof(MGCMTBLDEF->KEY_2_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_3_TBL, MGCMTBLDEF_N->KEY_3_TBL, sizeof(MGCMTBLDEF->KEY_3_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_3_COL, MGCMTBLDEF_N->KEY_3_COL, sizeof(MGCMTBLDEF->KEY_3_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_4_TBL, MGCMTBLDEF_N->KEY_4_TBL, sizeof(MGCMTBLDEF->KEY_4_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_4_COL, MGCMTBLDEF_N->KEY_4_COL, sizeof(MGCMTBLDEF->KEY_4_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_5_TBL, MGCMTBLDEF_N->KEY_5_TBL, sizeof(MGCMTBLDEF->KEY_5_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_5_COL, MGCMTBLDEF_N->KEY_5_COL, sizeof(MGCMTBLDEF->KEY_5_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_6_TBL, MGCMTBLDEF_N->KEY_6_TBL, sizeof(MGCMTBLDEF->KEY_6_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_6_COL, MGCMTBLDEF_N->KEY_6_COL, sizeof(MGCMTBLDEF->KEY_6_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_7_TBL, MGCMTBLDEF_N->KEY_7_TBL, sizeof(MGCMTBLDEF->KEY_7_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_7_COL, MGCMTBLDEF_N->KEY_7_COL, sizeof(MGCMTBLDEF->KEY_7_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_8_TBL, MGCMTBLDEF_N->KEY_8_TBL, sizeof(MGCMTBLDEF->KEY_8_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_8_COL, MGCMTBLDEF_N->KEY_8_COL, sizeof(MGCMTBLDEF->KEY_8_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_9_TBL, MGCMTBLDEF_N->KEY_9_TBL, sizeof(MGCMTBLDEF->KEY_9_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_9_COL, MGCMTBLDEF_N->KEY_9_COL, sizeof(MGCMTBLDEF->KEY_9_COL));
    MEMCPY_DN(MGCMTBLDEF->KEY_10_TBL, MGCMTBLDEF_N->KEY_10_TBL, sizeof(MGCMTBLDEF->KEY_10_TBL));
    MEMCPY_DN(MGCMTBLDEF->KEY_10_COL, MGCMTBLDEF_N->KEY_10_COL, sizeof(MGCMTBLDEF->KEY_10_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_1_TBL, MGCMTBLDEF_N->DATA_1_TBL, sizeof(MGCMTBLDEF->DATA_1_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_1_COL, MGCMTBLDEF_N->DATA_1_COL, sizeof(MGCMTBLDEF->DATA_1_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_2_TBL, MGCMTBLDEF_N->DATA_2_TBL, sizeof(MGCMTBLDEF->DATA_2_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_2_COL, MGCMTBLDEF_N->DATA_2_COL, sizeof(MGCMTBLDEF->DATA_2_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_3_TBL, MGCMTBLDEF_N->DATA_3_TBL, sizeof(MGCMTBLDEF->DATA_3_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_3_COL, MGCMTBLDEF_N->DATA_3_COL, sizeof(MGCMTBLDEF->DATA_3_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_4_TBL, MGCMTBLDEF_N->DATA_4_TBL, sizeof(MGCMTBLDEF->DATA_4_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_4_COL, MGCMTBLDEF_N->DATA_4_COL, sizeof(MGCMTBLDEF->DATA_4_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_5_TBL, MGCMTBLDEF_N->DATA_5_TBL, sizeof(MGCMTBLDEF->DATA_5_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_5_COL, MGCMTBLDEF_N->DATA_5_COL, sizeof(MGCMTBLDEF->DATA_5_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_6_TBL, MGCMTBLDEF_N->DATA_6_TBL, sizeof(MGCMTBLDEF->DATA_6_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_6_COL, MGCMTBLDEF_N->DATA_6_COL, sizeof(MGCMTBLDEF->DATA_6_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_7_TBL, MGCMTBLDEF_N->DATA_7_TBL, sizeof(MGCMTBLDEF->DATA_7_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_7_COL, MGCMTBLDEF_N->DATA_7_COL, sizeof(MGCMTBLDEF->DATA_7_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_8_TBL, MGCMTBLDEF_N->DATA_8_TBL, sizeof(MGCMTBLDEF->DATA_8_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_8_COL, MGCMTBLDEF_N->DATA_8_COL, sizeof(MGCMTBLDEF->DATA_8_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_9_TBL, MGCMTBLDEF_N->DATA_9_TBL, sizeof(MGCMTBLDEF->DATA_9_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_9_COL, MGCMTBLDEF_N->DATA_9_COL, sizeof(MGCMTBLDEF->DATA_9_COL));
    MEMCPY_DN(MGCMTBLDEF->DATA_10_TBL, MGCMTBLDEF_N->DATA_10_TBL, sizeof(MGCMTBLDEF->DATA_10_TBL));
    MEMCPY_DN(MGCMTBLDEF->DATA_10_COL, MGCMTBLDEF_N->DATA_10_COL, sizeof(MGCMTBLDEF->DATA_10_COL));
}
