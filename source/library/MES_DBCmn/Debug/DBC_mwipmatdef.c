
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
    "DBC_mwipmatdef.pc"
};


static unsigned int sqlctx = 9142043;


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
            void  *sqhstv[106];
   unsigned int   sqhstl[106];
            int   sqhsts[106];
            void  *sqindv[106];
            int   sqinds[106];
   unsigned int   sqharm[106];
   unsigned int   *sqharc[106];
   unsigned short  sqadto[106];
   unsigned short  sqtdso[106];
} sqlstm = {13,106};

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

 static const char *sq0015 = 
"T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 \
,APPLY_START_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_\
TIME ,RELEASE_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_US\
ER_ID ,DEACTIVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_I\
D ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC  from MWIPMATDEF \
where (FACTORY=:b0 and (MAT_ID,MAT_VER) in (select MAT_ID ,max(MAT_VER)  from\
 MWIPMATDEF where (((((FACTORY=:b0 and MAT_ID>=:b2) and MAT_ID like :b3) and \
MAT_TYPE like :b4) and DELETE_FLAG like :b5) and DEACTIVE_FLAG like :b6) grou\
p by MAT_ID)) order by MAT_ID asc             ";

 static const char *sq0016 = 
"T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 \
,APPLY_START_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_\
TIME ,RELEASE_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_US\
ER_ID ,DEACTIVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_I\
D ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC  from MWIPMATDEF \
where ((FACTORY=:b0 and (MAT_ID,MAT_VER) in (select distinct MF.MAT_ID ,MF.MA\
T_VER  from MWIPMATFLW MF ,MWIPFLWOPR FO where (((MF.FACTORY=:b0 and MF.FACTO\
RY=FO.FACTORY) and MF.FLOW=FO.FLOW) and FO.OPER=:b2))) and ((MAT_ID=:b3 and M\
AT_VER<=:b4) or MAT_ID>:b3)) order by MAT_ID asc ,MAT_VER desc             ";

 static const char *sq0018 = 
"TOCK_LEVEL ,B.HE_STOCK_LEVEL ,B.IQC_\
FLAG ,B.IQC_SAMPLE_FLAG ,B.IQC_SAMPLE_RULE ,B.OQC_FLAG ,B.OQC_SAMPLE_FLAG ,B.\
OQC_SAMPLE_RULE ,B.TARGET_YIELD ,B.TARGET_DUE_DAY ,B.TARGET_QTY_1 ,B.TARGET_Q\
TY_2 ,B.TARGET_QTY_3 ,B.APPLY_START_TIME ,B.APPLY_END_TIME ,B.APPROVAL_FLAG ,\
B.APPROVAL_USER_ID ,B.APPROVAL_TIME ,B.RELEASE_FLAG ,B.RELEASE_USER_ID ,B.REL\
EASE_TIME ,B.DEACTIVE_FLAG ,B.DEACTIVE_USER_ID ,B.DEACTIVE_TIME ,B.DELETE_FLA\
G ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE\
_USER_ID ,B.UPDATE_TIME ,B.MAT_SHORT_DESC  from MWIPMATFLW A ,MWIPMATDEF B wh\
ere (((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.FLOW=:b1) and A.MAT_ID=\
B.MAT_ID) and A.MAT_VER=B.MAT_VER) and ((A.MAT_ID=:b2 and A.MAT_VER<=:b3) or \
A.MAT_ID>:b2)) order by B.MAT_ID asc ,B.MAT_VER desc             ";

 static const char *sq0019 = 
"T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 \
,APPLY_START_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_\
TIME ,RELEASE_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_US\
ER_ID ,DEACTIVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_I\
D ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC  from MWIPMATDEF \
where (((((FACTORY=:b0 and MAT_ID=:b1) and MAT_TYPE like :b2) and MAT_VER<=:b\
3) and DELETE_FLAG like :b4) and DEACTIVE_FLAG like :b5) order by MAT_VER des\
c             ";

 static const char *sq0020 = 
"T_QTY_1 ,TARGET_QTY_2 ,TARGET_QTY_3 \
,APPLY_START_TIME ,APPLY_END_TIME ,APPROVAL_FLAG ,APPROVAL_USER_ID ,APPROVAL_\
TIME ,RELEASE_FLAG ,RELEASE_USER_ID ,RELEASE_TIME ,DEACTIVE_FLAG ,DEACTIVE_US\
ER_ID ,DEACTIVE_TIME ,DELETE_FLAG ,DELETE_USER_ID ,DELETE_TIME ,CREATE_USER_I\
D ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,MAT_SHORT_DESC  from MWIPMATDEF \
where (((((FACTORY=:b0 and ((MAT_ID=:b1 and MAT_VER<=:b2) or MAT_ID>:b1)) and\
 MAT_ID like :b4) and MAT_TYPE like :b5) and DELETE_FLAG like :b6) and DEACTI\
VE_FLAG like :b7) order by MAT_ID asc ,MAT_VER desc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1927,0,4,43,0,0,105,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
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
440,0,0,2,1950,0,4,256,0,0,106,4,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
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
1,97,0,0,1,3,0,0,1,97,0,0,
879,0,0,3,2004,0,4,470,0,0,106,4,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
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
1,97,0,0,1,0,0,0,1,0,0,0,
1318,0,0,4,1939,0,4,719,0,0,105,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,
0,1,97,0,0,1,3,0,0,
1753,0,0,5,2016,0,4,933,0,0,106,4,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,
0,1,97,0,0,1,0,0,0,1,0,0,0,
2192,0,0,6,77,0,4,1181,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
2219,0,0,7,80,0,4,1189,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
2246,0,0,8,77,0,2,1224,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
2273,0,0,9,1778,0,3,1253,0,0,102,102,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,
0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2696,0,0,10,1785,0,5,1480,0,0,102,102,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,4,0,0,1,
97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
3119,0,0,11,126,0,5,1586,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,
3158,0,0,12,161,0,5,1596,0,0,8,8,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
3205,0,0,13,132,0,5,1608,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,3,0,0,
3244,0,0,14,114,0,5,1618,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,
3279,0,0,15,1645,0,9,1787,0,0,7,7,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,
3322,0,0,16,1674,0,9,1907,0,0,6,6,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,0,0,0,
3361,0,0,17,0,0,17,2036,0,0,1,1,0,1,0,1,97,0,0,
3380,0,0,17,0,0,45,2038,0,0,0,0,0,1,0,
3395,0,0,18,1818,0,9,2154,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,
0,0,
3430,0,0,19,1536,0,9,2273,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,
3469,0,0,20,1586,0,9,2397,0,0,8,8,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,
3516,0,0,15,0,0,13,2425,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
3939,0,0,16,0,0,13,2530,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
4362,0,0,17,0,0,13,2635,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
4785,0,0,18,0,0,13,2740,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
5208,0,0,19,0,0,13,2845,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
5631,0,0,20,0,0,13,2950,0,0,102,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
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
6054,0,0,15,0,0,15,3082,0,0,0,0,0,1,0,
6069,0,0,16,0,0,15,3085,0,0,0,0,0,1,0,
6084,0,0,17,0,0,15,3088,0,0,0,0,0,1,0,
6099,0,0,18,0,0,15,3091,0,0,0,0,0,1,0,
6114,0,0,19,0,0,15,3094,0,0,0,0,0,1,0,
6129,0,0,20,0,0,15,3097,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mwipmatdef.pc
**    Description : Table Access Function Source File
**    Create date : 2004/11/30 19:26:08
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
void DBC_add_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF);
void DBC_del_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF);


/* SQL SELECT Function */
void DBC_select_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
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
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER
                    AND DELETE_FLAG = :MWIPMATDEF_N.DELETE_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
b99,:b100,:b101  from MWIPMATDEF where (((FACTORY=:b0 and MAT_ID=:b1) and MAT\
_VER=:b2) and DELETE_FLAG=:b94)";
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
            sqlstm.sqhstv[104] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[104] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[105] = (unsigned int  )2;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
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
                    AND MAT_VER = (
                        SELECT NVL(MAX(MAT_VER), 1) 
                        FROM MWIPMATDEF 
                        WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                            AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                        ); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
VER=(select NVL(max(MAT_VER),1)  from MWIPMATDEF where (FACTORY=:b0 and MAT_I\
D=:b1)))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )879;
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
            sqlstm.sqhstv[104] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[104] = (unsigned int  )11;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
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
        DBC_del_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    }
    DB_stop_query_timer("DBC_select_mwipmatdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mwipmatdef_for_update(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
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
            sqlstm.arrsiz = 106;
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
            sqlstm.offset = (unsigned int  )1318;
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
            
        case 3:
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
                    AND MAT_VER = (SELECT NVL(MAX(MAT_VER), 1) FROM MWIPMATDEF WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                                                                                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID)
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
VER=(select NVL(max(MAT_VER),1)  from MWIPMATDEF where (FACTORY=:b0 and MAT_I\
D=:b1))) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1753;
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
            sqlstm.sqhstv[104] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[104] = (unsigned int  )11;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
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

 


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }


    if(DB_error_code == 0)
    {
        DBC_del_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    }
    DB_stop_query_timer("DBC_select_mwipmatdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mwipmatdef_scalar(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    

    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MWIPMATDEF where\
 (FACTORY=:b1 and MAT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2192;
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
            /* EXEC SQL SELECT MAX(MAT_VER)
                INTO :d_value
                FROM MWIPMATDEF
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select max(MAT_VER) into :b0  from MWIPMATDEF wh\
ere (FACTORY=:b1 and MAT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2219;
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

    DB_stop_query_timer("DBC_select_mwipmatdef_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MWIPMATDEF  where ((FACTORY=:b0 and\
 MAT_ID=:b1) and MAT_VER=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2246;
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
    DB_stop_query_timer("DBC_delete_mwipmatdef", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mwipmatdef(struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MWIPMATDEF (
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
    sqlstm.arrsiz = 106;
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
    sqlstm.offset = (unsigned int  )2273;
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


    DB_stop_query_timer("DBC_insert_mwipmatdef", 0);
}


/* SQL UPDATE Function */
void DBC_update_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
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
            sqlstm.arrsiz = 106;
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
            sqlstm.offset = (unsigned int  )2696;
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
                    DELETE_FLAG = :MWIPMATDEF_N.DELETE_FLAG,
                    DELETE_USER_ID = :MWIPMATDEF_N.DELETE_USER_ID,
                    DELETE_TIME = :MWIPMATDEF_N.DELETE_TIME
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPMATDEF  set DELETE_FLAG=:b0,DELETE_US\
ER_ID=:b1,DELETE_TIME=:b2 where ((FACTORY=:b3 and MAT_ID=:b4) and MAT_VER=:b5\
)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3119;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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
            /* EXEC SQL UPDATE MWIPMATDEF SET
                    DELETE_FLAG = :MWIPMATDEF_N.DELETE_FLAG,
                    DELETE_USER_ID = :MWIPMATDEF_N.DELETE_USER_ID,
                    DELETE_TIME = :MWIPMATDEF_N.DELETE_TIME,
                    UPDATE_USER_ID = :MWIPMATDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MWIPMATDEF_N.UPDATE_TIME                    
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPMATDEF  set DELETE_FLAG=:b0,DELETE_US\
ER_ID=:b1,DELETE_TIME=:b2,UPDATE_USER_ID=:b3,UPDATE_TIME=:b4 where ((FACTORY=\
:b5 and MAT_ID=:b6) and MAT_VER=:b7)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3158;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.DELETE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.DELETE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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

        case 4:
            /* EXEC SQL UPDATE MWIPMATDEF SET
                    DEACTIVE_FLAG = :MWIPMATDEF_N.DEACTIVE_FLAG,
                    DEACTIVE_USER_ID = :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    DEACTIVE_TIME = :MWIPMATDEF_N.DEACTIVE_TIME
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_VER = :MWIPMATDEF_N.MAT_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPMATDEF  set DEACTIVE_FLAG=:b0,DEACTIV\
E_USER_ID=:b1,DEACTIVE_TIME=:b2 where ((FACTORY=:b3 and MAT_ID=:b4) and MAT_V\
ER=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3205;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
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

        case 5:
            /* EXEC SQL UPDATE MWIPMATDEF SET
                    DEACTIVE_FLAG = :MWIPMATDEF_N.DEACTIVE_FLAG,
                    DEACTIVE_USER_ID = :MWIPMATDEF_N.DEACTIVE_USER_ID,
                    DEACTIVE_TIME = :MWIPMATDEF_N.DEACTIVE_TIME
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update MWIPMATDEF  set DEACTIVE_FLAG=:b0,DEACTIV\
E_USER_ID=:b1,DEACTIVE_TIME=:b2 where (FACTORY=:b3 and MAT_ID=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3244;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[0] = (unsigned int  )2;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.DEACTIVE_USER_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.DEACTIVE_TIME);
            sqlstm.sqhstl[2] = (unsigned int  )15;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
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
    DB_stop_query_timer("DBC_update_mwipmatdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
        char   sql[5120];
        char   ts1[100];
        char   ts2[100];
        char   ts3[100];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();


    DBC_add_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    DB_error_code = 0;
    
    memset( ts1, 0x00, sizeof(ts1));
    memset( ts2, 0x00, sizeof(ts2));
    memset( ts3, 0x00, sizeof(ts3));

    switch(sel_type)
    {
        case 1:
            if(ISSPACE(MWIPMATDEF->MAT_DESC, sizeof(MWIPMATDEF->MAT_DESC)) == DB_TRUE)
                MWIPMATDEF_N.MAT_DESC[0] = '%';
            else
                strcat(MWIPMATDEF_N.MAT_DESC, "%");

            if(ISSPACE(MWIPMATDEF->MAT_TYPE, sizeof(MWIPMATDEF->MAT_TYPE)) == DB_TRUE)
                MWIPMATDEF_N.MAT_TYPE[0] = '%';

            /* EXEC SQL DECLARE DBC_MWIPMATDEF_CUR_1 CURSOR FOR
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
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND (MAT_ID, MAT_VER) IN (
                        SELECT MAT_ID, MAX(MAT_VER)
                        FROM MWIPMATDEF 
                        WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                            AND MAT_ID >= :MWIPMATDEF_N.MAT_ID
                            AND MAT_ID LIKE :MWIPMATDEF_N.MAT_DESC
                            AND MAT_TYPE LIKE :MWIPMATDEF_N.MAT_TYPE
                            AND DELETE_FLAG LIKE :MWIPMATDEF_N.DELETE_FLAG      /o ' ' - Undeleted Material, 'Y' - Deleted Material,  '%' - All Material o/
                            AND DEACTIVE_FLAG LIKE :MWIPMATDEF_N.DEACTIVE_FLAG  /o ' ' - Active Material,    'Y' - Deactive Material, '%' - All Material o/
                        GROUP BY MAT_ID
                    ) 
                ORDER BY MAT_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MWIPMATDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
            sqlstm.stmt = sq0015;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3279;
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
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
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
        
        case 2:
            /* EXEC SQL DECLARE DBC_MWIPMATDEF_CUR_2 CURSOR FOR
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
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND (MAT_ID, MAT_VER) IN (
                        SELECT DISTINCT MF.MAT_ID, MF.MAT_VER 
                        FROM MWIPMATFLW MF, MWIPFLWOPR FO 
                        WHERE MF.FACTORY = :MWIPMATDEF_N.FACTORY
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND FO.OPER = :MWIPMATDEF_N.MAT_DESC
                        ) 
                    AND ((MAT_ID = :MWIPMATDEF_N.MAT_ID AND MAT_VER <= :MWIPMATDEF_N.MAT_VER) OR MAT_ID > :MWIPMATDEF_N.MAT_ID)
                ORDER BY MAT_ID ASC, MAT_VER DESC; */ 

            /* EXEC SQL OPEN DBC_MWIPMATDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
            sqlstm.stmt = sq0016;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3322;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(MWIPMATDEF_N.MAT_VER);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
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
            memset( sql, 0x00, sizeof(sql));
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "FACTORY, ");
            sprintf(sql + strlen(sql),   "MAT_ID, ");
            sprintf(sql + strlen(sql),   "MAT_VER, ");
            sprintf(sql + strlen(sql),   "MAT_DESC, ");
            sprintf(sql + strlen(sql),   "MAT_TYPE, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_1, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_2, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_3, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_4, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_5, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_6, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_7, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_8, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_9, ");
            sprintf(sql + strlen(sql),   "MAT_GRP_10, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_1, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_2, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_3, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_4, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_5, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_6, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_7, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_8, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_9, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_10, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_11, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_12, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_13, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_14, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_15, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_16, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_17, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_18, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_19, ");
            sprintf(sql + strlen(sql),   "MAT_CMF_20, ");
            sprintf(sql + strlen(sql),   "FIRST_FLOW, ");
            sprintf(sql + strlen(sql),   "FIRST_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "LAST_FLOW, ");
            sprintf(sql + strlen(sql),   "LAST_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "MFG_DEVISION, ");
            sprintf(sql + strlen(sql),   "SUBCONTRACT_FLAG, ");
            sprintf(sql + strlen(sql),   "BASE_MAT_ID, ");
            sprintf(sql + strlen(sql),   "VENDOR_ID, ");
            sprintf(sql + strlen(sql),   "VENDOR_MAT_ID, ");
            sprintf(sql + strlen(sql),   "CUSTOMER_ID, ");
            sprintf(sql + strlen(sql),   "CUSTOMER_MAT_ID, ");
            sprintf(sql + strlen(sql),   "DEF_QTY_1, ");
            sprintf(sql + strlen(sql),   "DEF_QTY_2, ");
            sprintf(sql + strlen(sql),   "DEF_QTY_3, ");
            sprintf(sql + strlen(sql),   "UNIT_1, ");
            sprintf(sql + strlen(sql),   "UNIT_2, ");
            sprintf(sql + strlen(sql),   "UNIT_3, ");
            sprintf(sql + strlen(sql),   "WEIGHT_NET, ");
            sprintf(sql + strlen(sql),   "WEIGHT_GROSS, ");
            sprintf(sql + strlen(sql),   "WEIGHT_UNIT, ");
            sprintf(sql + strlen(sql),   "VOLUME, ");
            sprintf(sql + strlen(sql),   "VOLUME_UNIT, ");
            sprintf(sql + strlen(sql),   "DIMENSION_HR, ");
            sprintf(sql + strlen(sql),   "DIMENSION_HR_UNIT, ");
            sprintf(sql + strlen(sql),   "DIMENSION_VT, ");
            sprintf(sql + strlen(sql),   "DIMENSION_VT_UNIT, ");
            sprintf(sql + strlen(sql),   "DIMENSION_HT, ");
            sprintf(sql + strlen(sql),   "DIMENSION_HT_UNIT, ");
            sprintf(sql + strlen(sql),   "BOM_SET_ID, ");
            sprintf(sql + strlen(sql),   "DEF_INV_OPER, ");
            sprintf(sql + strlen(sql),   "PACK_TYPE, ");
            sprintf(sql + strlen(sql),   "PACK_LOT_COUNT, ");
            sprintf(sql + strlen(sql),   "PACK_QTY, ");
            sprintf(sql + strlen(sql),   "LE_STOCK_LEVEL, ");
            sprintf(sql + strlen(sql),   "LW_STOCK_LEVEL, ");
            sprintf(sql + strlen(sql),   "HW_STOCK_LEVEL, ");
            sprintf(sql + strlen(sql),   "HE_STOCK_LEVEL, ");
            sprintf(sql + strlen(sql),   "IQC_FLAG, ");
            sprintf(sql + strlen(sql),   "IQC_SAMPLE_FLAG, ");
            sprintf(sql + strlen(sql),   "IQC_SAMPLE_RULE, ");
            sprintf(sql + strlen(sql),   "OQC_FLAG, ");
            sprintf(sql + strlen(sql),   "OQC_SAMPLE_FLAG, ");
            sprintf(sql + strlen(sql),   "OQC_SAMPLE_RULE, ");
            sprintf(sql + strlen(sql),   "TARGET_YIELD, ");
            sprintf(sql + strlen(sql),   "TARGET_DUE_DAY, ");
            sprintf(sql + strlen(sql),   "TARGET_QTY_1, ");
            sprintf(sql + strlen(sql),   "TARGET_QTY_2, ");
            sprintf(sql + strlen(sql),   "TARGET_QTY_3, ");
            sprintf(sql + strlen(sql),   "APPLY_START_TIME, ");
            sprintf(sql + strlen(sql),   "APPLY_END_TIME, ");
            sprintf(sql + strlen(sql),   "APPROVAL_FLAG, ");
            sprintf(sql + strlen(sql),   "APPROVAL_USER_ID, ");
            sprintf(sql + strlen(sql),   "APPROVAL_TIME, ");
            sprintf(sql + strlen(sql),   "RELEASE_FLAG, ");
            sprintf(sql + strlen(sql),   "RELEASE_USER_ID, ");
            sprintf(sql + strlen(sql),   "RELEASE_TIME, ");
            sprintf(sql + strlen(sql),   "DEACTIVE_FLAG, ");
            sprintf(sql + strlen(sql),   "DEACTIVE_USER_ID, ");
            sprintf(sql + strlen(sql),   "DEACTIVE_TIME, ");
            sprintf(sql + strlen(sql),   "DELETE_FLAG, ");
            sprintf(sql + strlen(sql),   "DELETE_USER_ID, ");
            sprintf(sql + strlen(sql),   "DELETE_TIME, ");
            sprintf(sql + strlen(sql),   "CREATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "UPDATE_USER_ID, ");
            sprintf(sql + strlen(sql),   "UPDATE_TIME, ");
			sprintf(sql + strlen(sql),   "MAT_SHORT_DESC ");
            sprintf(sql + strlen(sql), "FROM MWIPMATDEF WHERE ");
            
            make_valid_quote(ts1, MWIPMATDEF_N.FACTORY);
            make_valid_quote(ts2, MWIPMATDEF_N.MAT_ID);

            sprintf(sql + strlen(sql), "DELETE_FLAG = ' ' AND FACTORY = '%s' AND ((MAT_ID = '%s' AND MAT_VER <= %d) OR MAT_ID > '%s') ", 
                ts1, ts2, MWIPMATDEF_N.MAT_VER, ts2);
            if(ISSPACE(MWIPMATDEF->MAT_TYPE, sizeof(MWIPMATDEF->MAT_TYPE)) == DB_FALSE)
            {
                make_valid_quote(ts1, MWIPMATDEF_N.MAT_TYPE);
                sprintf(sql + strlen(sql), "AND MAT_TYPE = '%s' ", ts1);
            }
            if(ISSPACE(MWIPMATDEF->MAT_GRP_1, sizeof(MWIPMATDEF->MAT_GRP_1)) == DB_FALSE)
            {
                make_valid_quote(ts1, MWIPMATDEF_N.MAT_GRP_1);
                sprintf(sql + strlen(sql), "AND (MAT_GRP_1 = '%s' OR MAT_GRP_2 = '%s' OR MAT_GRP_3 = '%s' OR MAT_GRP_4 = '%s' OR MAT_GRP_5 = '%s' OR MAT_GRP_6 = '%s' OR MAT_GRP_7 = '%s' OR MAT_GRP_8 = '%s' OR MAT_GRP_9 = '%s' OR MAT_GRP_10 = '%s') "
                , ts1, ts1, ts1, ts1, ts1, ts1, ts1, ts1, ts1, ts1);
            }

            sprintf(sql + strlen(sql), "ORDER BY MAT_ID ASC, MAT_VER DESC");

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3361;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )5120;
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


            /* EXEC SQL DECLARE DBC_MWIPMATDEF_CUR_3 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_MWIPMATDEF_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3380;
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

        case 4:
            /* EXEC SQL DECLARE DBC_MWIPMATDEF_CUR_4 CURSOR FOR
                SELECT DISTINCT
                                    B.FACTORY,
                                    B.MAT_ID,
                                    B.MAT_VER,
                                    B.MAT_DESC,
                                    B.MAT_TYPE,
                                    B.MAT_GRP_1,
                                    B.MAT_GRP_2,
                                    B.MAT_GRP_3,
                                    B.MAT_GRP_4,
                                    B.MAT_GRP_5,
                                    B.MAT_GRP_6,
                                    B.MAT_GRP_7,
                                    B.MAT_GRP_8,
                                    B.MAT_GRP_9,
                                    B.MAT_GRP_10,
                                    B.MAT_CMF_1,
                                    B.MAT_CMF_2,
                                    B.MAT_CMF_3,
                                    B.MAT_CMF_4,
                                    B.MAT_CMF_5,
                                    B.MAT_CMF_6,
                                    B.MAT_CMF_7,
                                    B.MAT_CMF_8,
                                    B.MAT_CMF_9,
                                    B.MAT_CMF_10,
                                    B.MAT_CMF_11,
                                    B.MAT_CMF_12,
                                    B.MAT_CMF_13,
                                    B.MAT_CMF_14,
                                    B.MAT_CMF_15,
                                    B.MAT_CMF_16,
                                    B.MAT_CMF_17,
                                    B.MAT_CMF_18,
                                    B.MAT_CMF_19,
                                    B.MAT_CMF_20,
                                    B.FIRST_FLOW,
                                    B.FIRST_FLOW_SEQ_NUM,
                                    B.LAST_FLOW,
                                    B.LAST_FLOW_SEQ_NUM,
                                    B.MFG_DEVISION,
                                    B.SUBCONTRACT_FLAG,
                                    B.BASE_MAT_ID,
                                    B.VENDOR_ID,
                                    B.VENDOR_MAT_ID,
                                    B.CUSTOMER_ID,
                                    B.CUSTOMER_MAT_ID,
                                    B.DEF_QTY_1,
                                    B.DEF_QTY_2,
                                    B.DEF_QTY_3,
                                    B.UNIT_1,
                                    B.UNIT_2,
                                    B.UNIT_3,
                                    B.WEIGHT_NET,
                                    B.WEIGHT_GROSS,
                                    B.WEIGHT_UNIT,
                                    B.VOLUME,
                                    B.VOLUME_UNIT,
                                    B.DIMENSION_HR,
                                    B.DIMENSION_HR_UNIT,
                                    B.DIMENSION_VT,
                                    B.DIMENSION_VT_UNIT,
                                    B.DIMENSION_HT,
                                    B.DIMENSION_HT_UNIT,
                                    B.BOM_SET_ID,
                                    B.DEF_INV_OPER,
                                    B.PACK_TYPE,
                                    B.PACK_LOT_COUNT,
                                    B.PACK_QTY,
                                    B.LE_STOCK_LEVEL,
                                    B.LW_STOCK_LEVEL,
                                    B.HW_STOCK_LEVEL,
                                    B.HE_STOCK_LEVEL,
                                    B.IQC_FLAG,
                                    B.IQC_SAMPLE_FLAG,
                                    B.IQC_SAMPLE_RULE,
                                    B.OQC_FLAG,
                                    B.OQC_SAMPLE_FLAG,
                                    B.OQC_SAMPLE_RULE,
                                    B.TARGET_YIELD,
                                    B.TARGET_DUE_DAY,
                                    B.TARGET_QTY_1,
                                    B.TARGET_QTY_2,
                                    B.TARGET_QTY_3,
                                    B.APPLY_START_TIME,
                                    B.APPLY_END_TIME,
                                    B.APPROVAL_FLAG,
                                    B.APPROVAL_USER_ID,
                                    B.APPROVAL_TIME,
                                    B.RELEASE_FLAG,
                                    B.RELEASE_USER_ID,
                                    B.RELEASE_TIME,
                                    B.DEACTIVE_FLAG,
                                    B.DEACTIVE_USER_ID,
                                    B.DEACTIVE_TIME,
                                    B.DELETE_FLAG,
                                    B.DELETE_USER_ID,
                                    B.DELETE_TIME,
                                    B.CREATE_USER_ID,
                                    B.CREATE_TIME,
                                    B.UPDATE_USER_ID,
                                    B.UPDATE_TIME,
									B.MAT_SHORT_DESC
                FROM MWIPMATFLW A, MWIPMATDEF B
                WHERE A.FACTORY = :MWIPMATDEF_N.FACTORY
                AND A.FACTORY = B.FACTORY
                AND A.FLOW = :MWIPMATDEF_N.FIRST_FLOW
                AND A.MAT_ID = B.MAT_ID
                AND A.MAT_VER = B.MAT_VER
                AND ((A.MAT_ID = :MWIPMATDEF_N.MAT_ID AND A.MAT_VER <= :MWIPMATDEF_N.MAT_VER) OR A.MAT_ID > :MWIPMATDEF_N.MAT_ID)
                ORDER BY B.MAT_ID ASC, B.MAT_VER DESC; */ 

            /* EXEC SQL OPEN DBC_MWIPMATDEF_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select distinct B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.MAT_DESC ,B\
.MAT_TYPE ,B.MAT_GRP_1 ,B.MAT_GRP_2 ,B.MAT_GRP_3 ,B.MAT_GRP_4 ,B.MAT_GRP_5 ,\
B.MAT_GRP_6 ,B.MAT_GRP_7 ,B.MAT_GRP_8 ,B.MAT_GRP_9 ,B.MAT_GRP_10 ,B.MAT_CMF_\
1 ,B.MAT_CMF_2 ,B.MAT_CMF_3 ,B.MAT_CMF_4 ,B.MAT_CMF_5 ,B.MAT_CMF_6 ,B.MAT_CM\
F_7 ,B.MAT_CMF_8 ,B.MAT_CMF_9 ,B.MAT_CMF_10 ,B.MAT_CMF_11 ,B.MAT_CMF_12 ,B.M\
AT_CMF_13 ,B.MAT_CMF_14 ,B.MAT_CMF_15 ,B.MAT_CMF_16 ,B.MAT_CMF_17 ,B.MAT_CMF\
_18 ,B.MAT_CMF_19 ,B.MAT_CMF_20 ,B.FIRST_FLOW ,B.FIRST_FLOW_SEQ_NUM ,B.LAST_\
FLOW ,B.LAST_FLOW_SEQ_NUM ,B.MFG_DEVISION ,B.SUBCONTRACT_FLAG ,B.BASE_MAT_ID\
 ,B.VENDOR_ID ,B.VENDOR_MAT_ID ,B.CUSTOMER_ID ,B.CUSTOMER_MAT_ID ,B.DEF_QTY_\
1 ,B.DEF_QTY_2 ,B.DEF_QTY_3 ,B.UNIT_1 ,B.UNIT_2 ,B.UNIT_3 ,B.WEIGHT_NET ,B.W\
EIGHT_GROSS ,B.WEIGHT_UNIT ,B.VOLUME ,B.VOLUME_UNIT ,B.DIMENSION_HR ,B.DIMEN\
SION_HR_UNIT ,B.DIMENSION_VT ,B.DIMENSION_VT_UNIT ,B.DIMENSION_HT ,B.DIMENSI\
ON_HT_UNIT ,B.BOM_SET_ID ,B.DEF_INV_OPER ,B.PACK_TYPE ,B.PACK_LOT_COUNT ,B.P\
ACK_QTY ,B.LE_STOCK_LEVEL ,B.LW_STOCK_LEVEL ,B.HW_S");
            sqlstm.stmt = sq0018;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3395;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.FIRST_FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
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
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
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
            if(ISSPACE(MWIPMATDEF->MAT_TYPE, sizeof(MWIPMATDEF->MAT_TYPE)) == DB_TRUE)
                MWIPMATDEF_N.MAT_TYPE[0] = '%';

            /* EXEC SQL DECLARE DBC_MWIPMATDEF_CUR_5 CURSOR FOR
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
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND MAT_ID = :MWIPMATDEF_N.MAT_ID
                    AND MAT_TYPE LIKE :MWIPMATDEF_N.MAT_TYPE
                    AND MAT_VER <= :MWIPMATDEF_N.MAT_VER
                    AND DELETE_FLAG LIKE :MWIPMATDEF_N.DELETE_FLAG      /o ' ' - Undeleted Material, 'Y' - Deleted Material,  '%' - All Material o/
                    AND DEACTIVE_FLAG LIKE :MWIPMATDEF_N.DEACTIVE_FLAG  /o ' ' - Active Material,    'Y' - Deactive Material, '%' - All Material o/
                ORDER BY MAT_VER DESC; */ 

            /* EXEC SQL OPEN DBC_MWIPMATDEF_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
            sqlstm.stmt = sq0019;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3430;
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
            sqlstm.sqhstv[1] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
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
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}

               
            break;

        case 6:
            if(ISSPACE(MWIPMATDEF->MAT_DESC, sizeof(MWIPMATDEF->MAT_DESC)) == DB_TRUE)
                MWIPMATDEF_N.MAT_DESC[0] = '%';
            else
                strcat(MWIPMATDEF_N.MAT_DESC, "%");

            if(ISSPACE(MWIPMATDEF->MAT_TYPE, sizeof(MWIPMATDEF->MAT_TYPE)) == DB_TRUE)
                MWIPMATDEF_N.MAT_TYPE[0] = '%';

            /* EXEC SQL DECLARE DBC_MWIPMATDEF_CUR_6 CURSOR FOR
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
                WHERE FACTORY = :MWIPMATDEF_N.FACTORY
                    AND ((MAT_ID = :MWIPMATDEF_N.MAT_ID AND MAT_VER <= :MWIPMATDEF_N.MAT_VER) OR MAT_ID > :MWIPMATDEF_N.MAT_ID)
                    AND MAT_ID LIKE :MWIPMATDEF_N.MAT_DESC
                    AND MAT_TYPE LIKE :MWIPMATDEF_N.MAT_TYPE
                    AND DELETE_FLAG LIKE :MWIPMATDEF_N.DELETE_FLAG      /o ' ' - Undeleted Material, 'Y' - Deleted Material,  '%' - All Material o/
                    AND DEACTIVE_FLAG LIKE :MWIPMATDEF_N.DEACTIVE_FLAG  /o ' ' - Active Material,    'Y' - Deactive Material, '%' - All Material o/
                ORDER BY MAT_ID ASC, MAT_VER DESC; */ 

            /* EXEC SQL OPEN DBC_MWIPMATDEF_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
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
            sqlstm.stmt = sq0020;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3469;
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
            sqlstm.sqhstv[3] = (         void  *)(MWIPMATDEF_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MWIPMATDEF_N.MAT_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MWIPMATDEF_N.MAT_TYPE);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MWIPMATDEF_N.DELETE_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MWIPMATDEF_N.DEACTIVE_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}

               
            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_mwipmatdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mwipmatdef(int sel_type, struct MWIPMATDEF_TAG *MWIPMATDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MWIPMATDEF_N_TAG MWIPMATDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MWIPMATDEF_CUR_1 INTO 
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3516;
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
            /* EXEC SQL FETCH DBC_MWIPMATDEF_CUR_2 INTO 
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3939;
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
        case 3:
            /* EXEC SQL FETCH DBC_MWIPMATDEF_CUR_3 INTO 
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4362;
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
        case 4:
            /* EXEC SQL FETCH DBC_MWIPMATDEF_CUR_4 INTO 
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4785;
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
        case 5:
            /* EXEC SQL FETCH DBC_MWIPMATDEF_CUR_5 INTO 
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5208;
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
        case 6:
            /* EXEC SQL FETCH DBC_MWIPMATDEF_CUR_6 INTO 
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
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5631;
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
        DBC_del_null_mwipmatdef(&MWIPMATDEF_N, MWIPMATDEF);
    }
    DB_stop_query_timer("DBC_fetch_mwipmatdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mwipmatdef(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MWIPMATDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6054;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CLOSE DBC_MWIPMATDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6069;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 3:
            /* EXEC SQL CLOSE DBC_MWIPMATDEF_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6084;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}

            
            break;
        case 4:
            /* EXEC SQL CLOSE DBC_MWIPMATDEF_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6099;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}

            
            break;
        case 5:
            /* EXEC SQL CLOSE DBC_MWIPMATDEF_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6114;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}

            
            break;
        case 6:
            /* EXEC SQL CLOSE DBC_MWIPMATDEF_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 106;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6129;
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
    DB_stop_query_timer("DBC_close_mwipmatdef", sel_type);
}


/* Initialize Function */
void DBC_init_mwipmatdef(struct MWIPMATDEF_TAG *MWIPMATDEF)
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
void DBC_add_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF)
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
void DBC_del_null_mwipmatdef(struct MWIPMATDEF_N_TAG *MWIPMATDEF_N, struct MWIPMATDEF_TAG *MWIPMATDEF)
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



