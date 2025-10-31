
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
           char  filnam[20];
};
static const struct sqlcxp sqlfpn =
{
    19,
    "DBC_spccore_join.pc"
};


static unsigned int sqlctx = 36569467;


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
            void  *sqhstv[82];
   unsigned int   sqhstl[82];
            int   sqhsts[82];
            void  *sqindv[82];
            int   sqinds[82];
   unsigned int   sqharm[82];
   unsigned int   *sqharc[82];
   unsigned short  sqadto[82];
   unsigned short  sqtdso[82];
} sqlstm = {13,82};

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

 static const char *sq0001 = 
" from MSPCCALDAT A ,MEDCLOTDAT B whe\
re ((((((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.CHART_ID=:b1) and\
 (A.EXCLUDE_FLAG=:b2 or EXCLUDE_FLAG=' ')) and A.LOT_ID=B.LOT_ID) and A.COL_S\
ET_ID=B.COL_SET_ID) and A.EDC_CHAR_SEQ=B.CHAR_SEQ_NUM) and A.EDC_HIST_SEQ=B.H\
IST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and A.UNIT_SEQ=B.UNIT_SEQ_NUM) and ((A.\
HIST_SEQ<:b3 or (A.HIST_SEQ=:b3 and A.UNIT_SEQ<:b5)) or ((A.HIST_SEQ=:b3 and \
A.UNIT_SEQ=:b5) and B.VALUE_SEQ_NUM>=:b8))) and A.TRAN_TIME<=:b9) and A.TRAN_\
TIME>=:b10) order by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM as\
c             ";

 static const char *sq0002 = 
" from MSPCCALDAT A ,MEDCLOTDAT B whe\
re (((((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.CHART_ID=:b1) and \
(A.EXCLUDE_FLAG=:b2 or EXCLUDE_FLAG=' ')) and A.LOT_ID=B.LOT_ID) and A.COL_SE\
T_ID=B.COL_SET_ID) and A.EDC_CHAR_SEQ=B.CHAR_SEQ_NUM) and A.EDC_HIST_SEQ=B.HI\
ST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and ((A.HIST_SEQ<:b3 or (A.HIST_SEQ=:b3 \
and A.UNIT_SEQ<:b5)) or ((A.HIST_SEQ=:b3 and A.UNIT_SEQ=:b5) and B.VALUE_SEQ_\
NUM>=:b8))) and A.TRAN_TIME<=:b9) and A.TRAN_TIME>=:b10) order by A.HIST_SEQ \
desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc             ";

 static const char *sq0003 = 
" from MSPCCALDAT A ,MEDCLOTDAT B whe\
re (((((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.CHART_ID=:b1) and \
A.LOT_ID=B.LOT_ID) and A.COL_SET_ID=B.COL_SET_ID) and A.EDC_CHAR_SEQ=B.CHAR_S\
EQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and A.UNI\
T_SEQ=B.UNIT_SEQ_NUM) and A.HIST_SEQ=:b2) and A.TRAN_TIME<=:b3) and A.TRAN_TI\
ME>=:b4) order by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc  \
           ";

 static const char *sq0004 = 
" from MSPCCALDAT A ,MEDCLOTDAT B whe\
re ((((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.CHART_ID=:b1) and A\
.LOT_ID=B.LOT_ID) and A.COL_SET_ID=B.COL_SET_ID) and A.EDC_CHAR_SEQ=B.CHAR_SE\
Q_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and A.HIST\
_SEQ=:b2) and A.TRAN_TIME<=:b3) and A.TRAN_TIME>=:b4) order by A.HIST_SEQ des\
c ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc             ";

 static const char *sq0005 = 
" from MSPCCALDAT A ,MEDCLOTDAT B whe\
re ((((((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.CHART_ID=:b1) and\
 A.LOT_ID=B.LOT_ID) and A.COL_SET_ID=B.COL_SET_ID) and A.EDC_CHAR_SEQ=B.CHAR_\
SEQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and A.UN\
IT_SEQ=B.UNIT_SEQ_NUM) and A.HIST_SEQ=:b2) and A.UNIT_SEQ=:b3) and A.TRAN_TIM\
E<=:b4) and A.TRAN_TIME>=:b5) order by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,\
B.VALUE_SEQ_NUM asc             ";

 static const char *sq0006 = 
" from MSPCCALDAT A ,MEDCLOTDAT B whe\
re (((((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and A.CHART_ID=:b1) and \
A.LOT_ID=B.LOT_ID) and A.COL_SET_ID=B.COL_SET_ID) and A.EDC_CHAR_SEQ=B.CHAR_S\
EQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and A.HIS\
T_SEQ=:b2) and A.UNIT_SEQ=:b3) and A.TRAN_TIME<=:b4) and A.TRAN_TIME>=:b5) or\
der by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc             ";

 static const char *sq0007 = 
"0 and A.FACTORY=B.FACTORY) and A.CHA\
RT_ID=:b1) and (A.EXCLUDE_FLAG=:b2 or EXCLUDE_FLAG=' ')) and A.RES_ID=B.RES_I\
D) and A.SUBRES_ID=B.SUBRES_ID) and A.EDC_CHAR_SEQ=B.CHAR_SEQ_NUM) and A.EDC_\
HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and A.UNIT_SEQ=B.UNIT_SEQ_N\
UM) and ((A.HIST_SEQ<:b3 or (A.HIST_SEQ=:b3 and A.UNIT_SEQ<:b5)) or ((A.HIST_\
SEQ=:b3 and A.UNIT_SEQ=:b5) and B.VALUE_SEQ_NUM>=:b8))) and A.TRAN_TIME<=:b9)\
 and A.TRAN_TIME>=:b10) order by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALU\
E_SEQ_NUM asc             ";

 static const char *sq0008 = 
" and A.FACTORY=B.FACTORY) and A.CHAR\
T_ID=:b1) and (A.EXCLUDE_FLAG=:b2 or EXCLUDE_FLAG=' ')) and A.RES_ID=B.RES_ID\
) and A.SUBRES_ID=B.SUBRES_ID) and A.EDC_CHAR_SEQ=B.CHAR_SEQ_NUM) and A.EDC_H\
IST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ) and ((A.HIST_SEQ<:b3 or (A.H\
IST_SEQ=:b3 and A.UNIT_SEQ<:b5)) or ((A.HIST_SEQ=:b3 and A.UNIT_SEQ=:b5) and \
B.VALUE_SEQ_NUM>=:b8))) and A.TRAN_TIME<=:b9) and A.TRAN_TIME>=:b10) order by\
 A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc             ";

 static const char *sq0009 = 
" and A.FACTORY=B.FACTORY) and A.CHAR\
T_ID=:b1) and A.RES_ID=B.RES_ID) and A.SUBRES_ID=B.SUBRES_ID) and A.EDC_CHAR_\
SEQ=B.CHAR_SEQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SE\
Q) and A.UNIT_SEQ=B.UNIT_SEQ_NUM) and A.HIST_SEQ=:b2) and A.TRAN_TIME<=:b3) a\
nd A.TRAN_TIME>=:b4) order by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_S\
EQ_NUM asc             ";

 static const char *sq0010 = 
"and A.FACTORY=B.FACTORY) and A.CHART\
_ID=:b1) and A.RES_ID=B.RES_ID) and A.SUBRES_ID=B.SUBRES_ID) and A.EDC_CHAR_S\
EQ=B.CHAR_SEQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SEQ\
) and A.HIST_SEQ=:b2) and A.TRAN_TIME<=:b3) and A.TRAN_TIME>=:b4) order by A.\
HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc             ";

 static const char *sq0011 = 
"0 and A.FACTORY=B.FACTORY) and A.CHA\
RT_ID=:b1) and A.RES_ID=B.RES_ID) and A.SUBRES_ID=B.SUBRES_ID) and A.EDC_CHAR\
_SEQ=B.CHAR_SEQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_S\
EQ) and A.UNIT_SEQ=B.UNIT_SEQ_NUM) and A.HIST_SEQ=:b2) and A.UNIT_SEQ=:b3) an\
d A.TRAN_TIME<=:b4) and A.TRAN_TIME>=:b5) order by A.HIST_SEQ desc ,B.UNIT_SE\
Q_NUM desc ,B.VALUE_SEQ_NUM asc             ";

 static const char *sq0012 = 
" and A.FACTORY=B.FACTORY) and A.CHAR\
T_ID=:b1) and A.RES_ID=B.RES_ID) and A.SUBRES_ID=B.SUBRES_ID) and A.EDC_CHAR_\
SEQ=B.CHAR_SEQ_NUM) and A.EDC_HIST_SEQ=B.HIST_SEQ) and A.EDC_COL_SEQ=B.COL_SE\
Q) and A.HIST_SEQ=:b2) and A.UNIT_SEQ=:b3) and A.TRAN_TIME<=:b4) and A.TRAN_T\
IME>=:b5) order by A.HIST_SEQ desc ,B.UNIT_SEQ_NUM desc ,B.VALUE_SEQ_NUM asc \
            ";

 static const char *sq0013 = 
"E_FLAG=' ')) and A.CHART_ID=B.CHART_\
ID) and A.HIST_SEQ=B.HIST_SEQ) and A.UNIT_SEQ=B.UNIT_SEQ) and ((A.HIST_SEQ<:b\
3 or (A.HIST_SEQ=:b3 and A.UNIT_SEQ<:b5)) or ((A.HIST_SEQ=:b3 and A.UNIT_SEQ=\
:b5) and B.VALUE_SEQ>=:b8))) and A.TRAN_TIME<=:b9) and A.TRAN_TIME>=:b10) ord\
er by B.HIST_SEQ desc ,B.UNIT_SEQ desc ,B.VALUE_SEQ asc             ";

 static const char *sq0014 = 
"_FLAG=' ')) and A.CHART_ID=B.CHART_I\
D) and A.HIST_SEQ=B.HIST_SEQ) and ((A.HIST_SEQ<:b3 or (A.HIST_SEQ=:b3 and A.U\
NIT_SEQ<:b5)) or ((A.HIST_SEQ=:b3 and A.UNIT_SEQ=:b5) and B.VALUE_SEQ>=:b8)))\
 and A.TRAN_TIME<=:b9) and A.TRAN_TIME>=:b10) order by B.HIST_SEQ desc ,B.UNI\
T_SEQ desc ,B.VALUE_SEQ asc             ";

 static const char *sq0015 = 
"IST_SEQ=B.HIST_SEQ) and A.UNIT_SEQ=B\
.UNIT_SEQ) and A.HIST_SEQ=:b2) and A.TRAN_TIME<=:b3) and A.TRAN_TIME>=:b4) or\
der by B.HIST_SEQ desc ,B.UNIT_SEQ desc ,B.VALUE_SEQ asc             ";

 static const char *sq0016 = 
"ST_SEQ=B.HIST_SEQ) and A.HIST_SEQ=:b\
2) and A.TRAN_TIME<=:b3) and A.TRAN_TIME>=:b4) order by B.HIST_SEQ desc ,B.UN\
IT_SEQ desc ,B.VALUE_SEQ asc             ";

 static const char *sq0017 = 
"HIST_SEQ=B.HIST_SEQ) and A.UNIT_SEQ=\
B.UNIT_SEQ) and A.HIST_SEQ=:b2) and A.UNIT_SEQ=:b3) and A.TRAN_TIME<=:b4) and\
 A.TRAN_TIME>=:b5) order by B.HIST_SEQ desc ,B.UNIT_SEQ desc ,B.VALUE_SEQ asc\
             ";

 static const char *sq0018 = 
"IST_SEQ=B.HIST_SEQ) and A.HIST_SEQ=:\
b2) and A.UNIT_SEQ=:b3) and A.TRAN_TIME<=:b4) and A.TRAN_TIME>=:b5) order by \
B.HIST_SEQ desc ,B.UNIT_SEQ desc ,B.VALUE_SEQ asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1613,0,9,124,0,0,11,11,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,
0,1,3,0,0,1,0,0,0,1,0,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
64,0,0,2,1581,0,9,208,0,0,11,11,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,
0,1,3,0,0,1,0,0,0,1,0,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
123,0,0,3,1456,0,9,289,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,
158,0,0,4,1424,0,9,370,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,
193,0,0,5,1477,0,9,453,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,
232,0,0,6,1445,0,9,535,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,
271,0,0,7,1548,0,9,566,0,0,11,11,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,
0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
330,0,0,8,1516,0,9,595,0,0,11,11,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,
0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
389,0,0,9,1391,0,9,621,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,
424,0,0,10,1359,0,9,647,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,
459,0,0,11,1412,0,9,675,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,
498,0,0,12,1380,0,9,702,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,
537,0,0,13,1359,0,9,729,0,0,11,11,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,
0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
596,0,0,14,1331,0,9,755,0,0,11,11,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,
0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
655,0,0,15,1206,0,9,778,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,
690,0,0,16,1178,0,9,801,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,
0,0,
725,0,0,17,1227,0,9,826,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,
764,0,0,18,1199,0,9,850,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,97,0,0,
803,0,0,1,0,0,13,878,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
1146,0,0,2,0,0,13,964,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
1489,0,0,3,0,0,13,1050,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
1832,0,0,4,0,0,13,1136,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2175,0,0,5,0,0,13,1222,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2518,0,0,6,0,0,13,1308,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2861,0,0,7,0,0,13,1394,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
3204,0,0,8,0,0,13,1480,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
3547,0,0,9,0,0,13,1566,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
3890,0,0,10,0,0,13,1652,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
4233,0,0,11,0,0,13,1738,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
4576,0,0,12,0,0,13,1824,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
4919,0,0,13,0,0,13,1910,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
5262,0,0,14,0,0,13,1996,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
5605,0,0,15,0,0,13,2082,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
5948,0,0,16,0,0,13,2168,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6291,0,0,17,0,0,13,2254,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6634,0,0,18,0,0,13,2340,0,0,82,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
6977,0,0,1,0,0,15,2454,0,0,0,0,0,1,0,
6992,0,0,2,0,0,15,2457,0,0,0,0,0,1,0,
7007,0,0,3,0,0,15,2460,0,0,0,0,0,1,0,
7022,0,0,4,0,0,15,2463,0,0,0,0,0,1,0,
7037,0,0,5,0,0,15,2466,0,0,0,0,0,1,0,
7052,0,0,6,0,0,15,2469,0,0,0,0,0,1,0,
7067,0,0,7,0,0,15,2473,0,0,0,0,0,1,0,
7082,0,0,8,0,0,15,2477,0,0,0,0,0,1,0,
7097,0,0,9,0,0,15,2481,0,0,0,0,0,1,0,
7112,0,0,10,0,0,15,2485,0,0,0,0,0,1,0,
7127,0,0,11,0,0,15,2489,0,0,0,0,0,1,0,
7142,0,0,12,0,0,15,2493,0,0,0,0,0,1,0,
7157,0,0,13,0,0,15,2497,0,0,0,0,0,1,0,
7172,0,0,14,0,0,15,2500,0,0,0,0,0,1,0,
7187,0,0,15,0,0,15,2503,0,0,0,0,0,1,0,
7202,0,0,16,0,0,15,2506,0,0,0,0,0,1,0,
7217,0,0,17,0,0,15,2510,0,0,0,0,0,1,0,
7232,0,0,18,0,0,15,2514,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_spccore_join.pc
**    Description : Table Access Function Source File
**    Create date : 2005/05/27 16:36:50
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
void DBC_add_null_edcdata(struct EDCDATA_N_TAG *EDCDATA_N, struct EDCDATA_TAG *EDCDATA);
void DBC_del_null_edcdata(struct EDCDATA_N_TAG *EDCDATA_N, struct EDCDATA_TAG *EDCDATA);


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_edcdata(int sel_type, struct EDCDATA_TAG *EDCDATA)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct EDCDATA_N_TAG EDCDATA_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_edcdata(&EDCDATA_N, EDCDATA);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_1 CURSOR FOR
                SELECT
                       B.LOT_ID,
                       B.HIST_SEQ,
                       B.COL_SEQ,
                       B.TRAN_TIME,
                       B.HIST_DEL_FLAG,
                       B.FACTORY,
                       B.MAT_ID,
                       B.MAT_VER,
                       B.FLOW,
                       B.OPER,
                       B.MEAS_RES_ID,
                       B.PROC_FLOW,
                       B.PROC_OPER,
                       B.PROC_RES_ID,
                       B.RECIPE_ID,
                       B.RECIPE_VERSION,
                       B.COL_SET_ID,
                       B.COL_SET_VERSION,
                       B.CHAR_SEQ_NUM,
                       B.CHAR_ID,
                       B.UNIT_SEQ_NUM,
                       B.UNIT_ID,
                       B.VALUE_SEQ_NUM,
                       B.VALUE_TYPE,
                       B.VALUE_COUNT,
                       B.VALUE_1,
                       B.VALUE_2,
                       B.VALUE_3,
                       B.VALUE_4,
                       B.VALUE_5,
                       B.VALUE_6,
                       B.VALUE_7,
                       B.VALUE_8,
                       B.VALUE_9,
                       B.VALUE_10,
                       B.VALUE_11,
                       B.VALUE_12,
                       B.VALUE_13,
                       B.VALUE_14,
                       B.VALUE_15,
                       B.VALUE_16,
                       B.VALUE_17,
                       B.VALUE_18,
                       B.VALUE_19,
                       B.VALUE_20,
                       B.VALUE_21,
                       B.VALUE_22,
                       B.VALUE_23,
                       B.VALUE_24,
                       B.VALUE_25,
                       B.SAMPLE_COUNT,
                       B.NOMINAL,
                       B.PROCESS_SIGMA,
                       B.SPEC_OUT_MASK,
                       B.CREATE_USER_ID,
                       B.CREATE_TIME,
                       B.UPDATE_USER_ID,
                       B.UPDATE_TIME,
                       B.DELETE_USER_ID,
                       B.DELETE_TIME,
                       ' ', A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCLOTDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND (A.EXCLUDE_FLAG = :EDCDATA_N.HIST_DEL_FLAG OR EXCLUDE_FLAG = ' ')
                        AND A.LOT_ID = B.LOT_ID
                        AND A.COL_SET_ID = B.COL_SET_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ_NUM
                        AND (A.HIST_SEQ < :EDCDATA_N.HIST_SEQ
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ < :EDCDATA_N.UNIT_SEQ_NUM)
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM AND B.VALUE_SEQ_NUM >= :EDCDATA_N.VALUE_SEQ_NUM))
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_D\
EL_FLAG ,B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.MEAS_RES_ID ,B.PR\
OC_FLOW ,B.PROC_OPER ,B.PROC_RES_ID ,B.RECIPE_ID ,B.RECIPE_VERSION ,B.COL_SE\
T_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.UNIT_I\
D ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VAL\
UE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VA\
LUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_\
16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,\
B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCESS_SIG\
MA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID ,B.UP\
DATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,' ' ,A.WEIGHT_VALUE ,A.AVERAGE ,\
A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_TYPE2 ,A.EXCL\
UDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.UCL ,A.CL ,A.\
LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ ");
            sqlstm.stmt = sq0001;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_2 CURSOR FOR
                SELECT
                       B.LOT_ID,
                       B.HIST_SEQ,
                       B.COL_SEQ,
                       B.TRAN_TIME,
                       B.HIST_DEL_FLAG,
                       B.FACTORY,
                       B.MAT_ID,
                       B.MAT_VER,
                       B.FLOW,
                       B.OPER,
                       B.MEAS_RES_ID,
                       B.PROC_FLOW,
                       B.PROC_OPER,
                       B.PROC_RES_ID,
                       B.RECIPE_ID,
                       B.RECIPE_VERSION,
                       B.COL_SET_ID,
                       B.COL_SET_VERSION,
                       B.CHAR_SEQ_NUM,
                       B.CHAR_ID,
                       B.UNIT_SEQ_NUM,
                       B.UNIT_ID,
                       B.VALUE_SEQ_NUM,
                       B.VALUE_TYPE,
                       B.VALUE_COUNT,
                       B.VALUE_1,
                       B.VALUE_2,
                       B.VALUE_3,
                       B.VALUE_4,
                       B.VALUE_5,
                       B.VALUE_6,
                       B.VALUE_7,
                       B.VALUE_8,
                       B.VALUE_9,
                       B.VALUE_10,
                       B.VALUE_11,
                       B.VALUE_12,
                       B.VALUE_13,
                       B.VALUE_14,
                       B.VALUE_15,
                       B.VALUE_16,
                       B.VALUE_17,
                       B.VALUE_18,
                       B.VALUE_19,
                       B.VALUE_20,
                       B.VALUE_21,
                       B.VALUE_22,
                       B.VALUE_23,
                       B.VALUE_24,
                       B.VALUE_25,
                       B.SAMPLE_COUNT,
                       B.NOMINAL,
                       B.PROCESS_SIGMA,
                       B.SPEC_OUT_MASK,
                       B.CREATE_USER_ID,
                       B.CREATE_TIME,
                       B.UPDATE_USER_ID,
                       B.UPDATE_TIME,
                       B.DELETE_USER_ID,
                       B.DELETE_TIME,
                       ' ', A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCLOTDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND (A.EXCLUDE_FLAG = :EDCDATA_N.HIST_DEL_FLAG OR EXCLUDE_FLAG = ' ')
                        AND A.LOT_ID = B.LOT_ID
                        AND A.COL_SET_ID = B.COL_SET_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND (A.HIST_SEQ < :EDCDATA_N.HIST_SEQ
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ < :EDCDATA_N.UNIT_SEQ_NUM)
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM AND B.VALUE_SEQ_NUM >= :EDCDATA_N.VALUE_SEQ_NUM))
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_D\
EL_FLAG ,B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.MEAS_RES_ID ,B.PR\
OC_FLOW ,B.PROC_OPER ,B.PROC_RES_ID ,B.RECIPE_ID ,B.RECIPE_VERSION ,B.COL_SE\
T_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.UNIT_I\
D ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VAL\
UE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VA\
LUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_\
16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,\
B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCESS_SIG\
MA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID ,B.UP\
DATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,' ' ,A.WEIGHT_VALUE ,A.AVERAGE ,\
A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_TYPE2 ,A.EXCL\
UDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.UCL ,A.CL ,A.\
LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ ");
            sqlstm.stmt = sq0002;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )64;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_3 CURSOR FOR
                SELECT
                       B.LOT_ID,
                       B.HIST_SEQ,
                       B.COL_SEQ,
                       B.TRAN_TIME,
                       B.HIST_DEL_FLAG,
                       B.FACTORY,
                       B.MAT_ID,
                       B.MAT_VER,
                       B.FLOW,
                       B.OPER,
                       B.MEAS_RES_ID,
                       B.PROC_FLOW,
                       B.PROC_OPER,
                       B.PROC_RES_ID,
                       B.RECIPE_ID,
                       B.RECIPE_VERSION,
                       B.COL_SET_ID,
                       B.COL_SET_VERSION,
                       B.CHAR_SEQ_NUM,
                       B.CHAR_ID,
                       B.UNIT_SEQ_NUM,
                       B.UNIT_ID,
                       B.VALUE_SEQ_NUM,
                       B.VALUE_TYPE,
                       B.VALUE_COUNT,
                       B.VALUE_1,
                       B.VALUE_2,
                       B.VALUE_3,
                       B.VALUE_4,
                       B.VALUE_5,
                       B.VALUE_6,
                       B.VALUE_7,
                       B.VALUE_8,
                       B.VALUE_9,
                       B.VALUE_10,
                       B.VALUE_11,
                       B.VALUE_12,
                       B.VALUE_13,
                       B.VALUE_14,
                       B.VALUE_15,
                       B.VALUE_16,
                       B.VALUE_17,
                       B.VALUE_18,
                       B.VALUE_19,
                       B.VALUE_20,
                       B.VALUE_21,
                       B.VALUE_22,
                       B.VALUE_23,
                       B.VALUE_24,
                       B.VALUE_25,
                       B.SAMPLE_COUNT,
                       B.NOMINAL,
                       B.PROCESS_SIGMA,
                       B.SPEC_OUT_MASK,
                       B.CREATE_USER_ID,
                       B.CREATE_TIME,
                       B.UPDATE_USER_ID,
                       B.UPDATE_TIME,
                       B.DELETE_USER_ID,
                       B.DELETE_TIME,
                       ' ', A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCLOTDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.LOT_ID = B.LOT_ID
                        AND A.COL_SET_ID = B.COL_SET_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ_NUM
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_D\
EL_FLAG ,B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.MEAS_RES_ID ,B.PR\
OC_FLOW ,B.PROC_OPER ,B.PROC_RES_ID ,B.RECIPE_ID ,B.RECIPE_VERSION ,B.COL_SE\
T_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.UNIT_I\
D ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VAL\
UE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VA\
LUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_\
16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,\
B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCESS_SIG\
MA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID ,B.UP\
DATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,' ' ,A.WEIGHT_VALUE ,A.AVERAGE ,\
A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_TYPE2 ,A.EXCL\
UDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.UCL ,A.CL ,A.\
LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ ");
            sqlstm.stmt = sq0003;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )123;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
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
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_4 CURSOR FOR
                SELECT
                       B.LOT_ID,
                       B.HIST_SEQ,
                       B.COL_SEQ,
                       B.TRAN_TIME,
                       B.HIST_DEL_FLAG,
                       B.FACTORY,
                       B.MAT_ID,
                       B.MAT_VER,
                       B.FLOW,
                       B.OPER,
                       B.MEAS_RES_ID,
                       B.PROC_FLOW,
                       B.PROC_OPER,
                       B.PROC_RES_ID,
                       B.RECIPE_ID,
                       B.RECIPE_VERSION,
                       B.COL_SET_ID,
                       B.COL_SET_VERSION,
                       B.CHAR_SEQ_NUM,
                       B.CHAR_ID,
                       B.UNIT_SEQ_NUM,
                       B.UNIT_ID,
                       B.VALUE_SEQ_NUM,
                       B.VALUE_TYPE,
                       B.VALUE_COUNT,
                       B.VALUE_1,
                       B.VALUE_2,
                       B.VALUE_3,
                       B.VALUE_4,
                       B.VALUE_5,
                       B.VALUE_6,
                       B.VALUE_7,
                       B.VALUE_8,
                       B.VALUE_9,
                       B.VALUE_10,
                       B.VALUE_11,
                       B.VALUE_12,
                       B.VALUE_13,
                       B.VALUE_14,
                       B.VALUE_15,
                       B.VALUE_16,
                       B.VALUE_17,
                       B.VALUE_18,
                       B.VALUE_19,
                       B.VALUE_20,
                       B.VALUE_21,
                       B.VALUE_22,
                       B.VALUE_23,
                       B.VALUE_24,
                       B.VALUE_25,
                       B.SAMPLE_COUNT,
                       B.NOMINAL,
                       B.PROCESS_SIGMA,
                       B.SPEC_OUT_MASK,
                       B.CREATE_USER_ID,
                       B.CREATE_TIME,
                       B.UPDATE_USER_ID,
                       B.UPDATE_TIME,
                       B.DELETE_USER_ID,
                       B.DELETE_TIME,
                       ' ', A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCLOTDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.LOT_ID = B.LOT_ID
                        AND A.COL_SET_ID = B.COL_SET_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_D\
EL_FLAG ,B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.MEAS_RES_ID ,B.PR\
OC_FLOW ,B.PROC_OPER ,B.PROC_RES_ID ,B.RECIPE_ID ,B.RECIPE_VERSION ,B.COL_SE\
T_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.UNIT_I\
D ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VAL\
UE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VA\
LUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_\
16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,\
B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCESS_SIG\
MA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID ,B.UP\
DATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,' ' ,A.WEIGHT_VALUE ,A.AVERAGE ,\
A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_TYPE2 ,A.EXCL\
UDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.UCL ,A.CL ,A.\
LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ ");
            sqlstm.stmt = sq0004;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )158;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
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
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_5 CURSOR FOR
                SELECT
                       B.LOT_ID,
                       B.HIST_SEQ,
                       B.COL_SEQ,
                       B.TRAN_TIME,
                       B.HIST_DEL_FLAG,
                       B.FACTORY,
                       B.MAT_ID,
                       B.MAT_VER,
                       B.FLOW,
                       B.OPER,
                       B.MEAS_RES_ID,
                       B.PROC_FLOW,
                       B.PROC_OPER,
                       B.PROC_RES_ID,
                       B.RECIPE_ID,
                       B.RECIPE_VERSION,
                       B.COL_SET_ID,
                       B.COL_SET_VERSION,
                       B.CHAR_SEQ_NUM,
                       B.CHAR_ID,
                       B.UNIT_SEQ_NUM,
                       B.UNIT_ID,
                       B.VALUE_SEQ_NUM,
                       B.VALUE_TYPE,
                       B.VALUE_COUNT,
                       B.VALUE_1,
                       B.VALUE_2,
                       B.VALUE_3,
                       B.VALUE_4,
                       B.VALUE_5,
                       B.VALUE_6,
                       B.VALUE_7,
                       B.VALUE_8,
                       B.VALUE_9,
                       B.VALUE_10,
                       B.VALUE_11,
                       B.VALUE_12,
                       B.VALUE_13,
                       B.VALUE_14,
                       B.VALUE_15,
                       B.VALUE_16,
                       B.VALUE_17,
                       B.VALUE_18,
                       B.VALUE_19,
                       B.VALUE_20,
                       B.VALUE_21,
                       B.VALUE_22,
                       B.VALUE_23,
                       B.VALUE_24,
                       B.VALUE_25,
                       B.SAMPLE_COUNT,
                       B.NOMINAL,
                       B.PROCESS_SIGMA,
                       B.SPEC_OUT_MASK,
                       B.CREATE_USER_ID,
                       B.CREATE_TIME,
                       B.UPDATE_USER_ID,
                       B.UPDATE_TIME,
                       B.DELETE_USER_ID,
                       B.DELETE_TIME,
                       ' ', A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCLOTDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.LOT_ID = B.LOT_ID
                        AND A.COL_SET_ID = B.COL_SET_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ_NUM
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_D\
EL_FLAG ,B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.MEAS_RES_ID ,B.PR\
OC_FLOW ,B.PROC_OPER ,B.PROC_RES_ID ,B.RECIPE_ID ,B.RECIPE_VERSION ,B.COL_SE\
T_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.UNIT_I\
D ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VAL\
UE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VA\
LUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_\
16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,\
B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCESS_SIG\
MA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID ,B.UP\
DATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,' ' ,A.WEIGHT_VALUE ,A.AVERAGE ,\
A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_TYPE2 ,A.EXCL\
UDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.UCL ,A.CL ,A.\
LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ ");
            sqlstm.stmt = sq0005;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )193;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
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
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_6 CURSOR FOR
                SELECT
                       B.LOT_ID,
                       B.HIST_SEQ,
                       B.COL_SEQ,
                       B.TRAN_TIME,
                       B.HIST_DEL_FLAG,
                       B.FACTORY,
                       B.MAT_ID,
                       B.MAT_VER,
                       B.FLOW,
                       B.OPER,
                       B.MEAS_RES_ID,
                       B.PROC_FLOW,
                       B.PROC_OPER,
                       B.PROC_RES_ID,
                       B.RECIPE_ID,
                       B.RECIPE_VERSION,
                       B.COL_SET_ID,
                       B.COL_SET_VERSION,
                       B.CHAR_SEQ_NUM,
                       B.CHAR_ID,
                       B.UNIT_SEQ_NUM,
                       B.UNIT_ID,
                       B.VALUE_SEQ_NUM,
                       B.VALUE_TYPE,
                       B.VALUE_COUNT,
                       B.VALUE_1,
                       B.VALUE_2,
                       B.VALUE_3,
                       B.VALUE_4,
                       B.VALUE_5,
                       B.VALUE_6,
                       B.VALUE_7,
                       B.VALUE_8,
                       B.VALUE_9,
                       B.VALUE_10,
                       B.VALUE_11,
                       B.VALUE_12,
                       B.VALUE_13,
                       B.VALUE_14,
                       B.VALUE_15,
                       B.VALUE_16,
                       B.VALUE_17,
                       B.VALUE_18,
                       B.VALUE_19,
                       B.VALUE_20,
                       B.VALUE_21,
                       B.VALUE_22,
                       B.VALUE_23,
                       B.VALUE_24,
                       B.VALUE_25,
                       B.SAMPLE_COUNT,
                       B.NOMINAL,
                       B.PROCESS_SIGMA,
                       B.SPEC_OUT_MASK,
                       B.CREATE_USER_ID,
                       B.CREATE_TIME,
                       B.UPDATE_USER_ID,
                       B.UPDATE_TIME,
                       B.DELETE_USER_ID,
                       B.DELETE_TIME,
                       ' ', A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCLOTDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.LOT_ID = B.LOT_ID
                        AND A.COL_SET_ID = B.COL_SET_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_D\
EL_FLAG ,B.FACTORY ,B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.MEAS_RES_ID ,B.PR\
OC_FLOW ,B.PROC_OPER ,B.PROC_RES_ID ,B.RECIPE_ID ,B.RECIPE_VERSION ,B.COL_SE\
T_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.UNIT_I\
D ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VAL\
UE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VA\
LUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_\
16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,\
B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCESS_SIG\
MA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID ,B.UP\
DATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,' ' ,A.WEIGHT_VALUE ,A.AVERAGE ,\
A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_TYPE2 ,A.EXCL\
UDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.UCL ,A.CL ,A.\
LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ ");
            sqlstm.stmt = sq0006;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )232;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
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
            
      case 7:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_7 CURSOR FOR
                SELECT ' ', B.HIST_SEQ, B.COL_SEQ, B.TRAN_TIME, B.HIST_DEL_FLAG, B.FACTORY, ' ', 0, ' ', ' ', B.RES_ID,  B.SUBRES_ID, 
                        ' ', ' ', ' ', 0, B.COL_SET_ID, B.COL_SET_VERSION, B.CHAR_SEQ_NUM, B.CHAR_ID, B.UNIT_SEQ_NUM, 
                        B.UNIT_ID, B.VALUE_SEQ_NUM, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, B.SAMPLE_COUNT, B.NOMINAL, B.PROCESS_SIGMA, B.SPEC_OUT_MASK, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, B.DELETE_USER_ID, B.DELETE_TIME, B.EVENT_ID, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCRESDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND (A.EXCLUDE_FLAG = :EDCDATA_N.HIST_DEL_FLAG OR EXCLUDE_FLAG = ' ')
                        AND A.RES_ID = B.RES_ID
                        AND A.SUBRES_ID = B.SUBRES_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ_NUM
                        AND (A.HIST_SEQ < :EDCDATA_N.HIST_SEQ
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ < :EDCDATA_N.UNIT_SEQ_NUM)
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM AND B.VALUE_SEQ_NUM >= :EDCDATA_N.VALUE_SEQ_NUM))
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_7; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select ' ' ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_DEL_FL\
AG ,B.FACTORY ,' ' ,0 ,' ' ,' ' ,B.RES_ID ,B.SUBRES_ID ,' ' ,' ' ,' ' ,0 ,B.\
COL_SET_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.\
UNIT_ID ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 \
,B.VALUE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9\
 ,B.VALUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.\
VALUE_16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALU\
E_22 ,B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCE\
SS_SIGMA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID\
 ,B.UPDATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.EVENT_ID ,A.WEIGHT_VALUE\
 ,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_\
TYPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.\
UCL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCA\
LDAT A ,MEDCRESDAT B where ((((((((((((A.FACTORY=:b");
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )271;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
        case 8:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_8 CURSOR FOR
                SELECT ' ', B.HIST_SEQ, B.COL_SEQ, B.TRAN_TIME, B.HIST_DEL_FLAG, B.FACTORY, ' ', 0, ' ', ' ', B.RES_ID,  B.SUBRES_ID, 
                        ' ', ' ', ' ', 0, B.COL_SET_ID, B.COL_SET_VERSION, B.CHAR_SEQ_NUM, B.CHAR_ID, B.UNIT_SEQ_NUM, 
                        B.UNIT_ID, B.VALUE_SEQ_NUM, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, B.SAMPLE_COUNT, B.NOMINAL, B.PROCESS_SIGMA, B.SPEC_OUT_MASK, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, B.DELETE_USER_ID, B.DELETE_TIME, B.EVENT_ID, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCRESDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND (A.EXCLUDE_FLAG = :EDCDATA_N.HIST_DEL_FLAG OR EXCLUDE_FLAG = ' ')
                        AND A.RES_ID = B.RES_ID
                        AND A.SUBRES_ID = B.SUBRES_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND (A.HIST_SEQ < :EDCDATA_N.HIST_SEQ
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ < :EDCDATA_N.UNIT_SEQ_NUM)
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM AND B.VALUE_SEQ_NUM >= :EDCDATA_N.VALUE_SEQ_NUM))
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_8; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select ' ' ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_DEL_FL\
AG ,B.FACTORY ,' ' ,0 ,' ' ,' ' ,B.RES_ID ,B.SUBRES_ID ,' ' ,' ' ,' ' ,0 ,B.\
COL_SET_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.\
UNIT_ID ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 \
,B.VALUE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9\
 ,B.VALUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.\
VALUE_16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALU\
E_22 ,B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCE\
SS_SIGMA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID\
 ,B.UPDATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.EVENT_ID ,A.WEIGHT_VALUE\
 ,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_\
TYPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.\
UCL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCA\
LDAT A ,MEDCRESDAT B where (((((((((((A.FACTORY=:b0");
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )330;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
    case 9:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_9 CURSOR FOR
                SELECT ' ', B.HIST_SEQ, B.COL_SEQ, B.TRAN_TIME, B.HIST_DEL_FLAG, B.FACTORY, ' ', 0, ' ', ' ', B.RES_ID,  B.SUBRES_ID, 
                        ' ', ' ', ' ', 0, B.COL_SET_ID, B.COL_SET_VERSION, B.CHAR_SEQ_NUM, B.CHAR_ID, B.UNIT_SEQ_NUM, 
                        B.UNIT_ID, B.VALUE_SEQ_NUM, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, B.SAMPLE_COUNT, B.NOMINAL, B.PROCESS_SIGMA, B.SPEC_OUT_MASK, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, B.DELETE_USER_ID, B.DELETE_TIME, B.EVENT_ID, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCRESDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.RES_ID = B.RES_ID
                        AND A.SUBRES_ID = B.SUBRES_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ_NUM
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_9; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select ' ' ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_DEL_FL\
AG ,B.FACTORY ,' ' ,0 ,' ' ,' ' ,B.RES_ID ,B.SUBRES_ID ,' ' ,' ' ,' ' ,0 ,B.\
COL_SET_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.\
UNIT_ID ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 \
,B.VALUE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9\
 ,B.VALUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.\
VALUE_16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALU\
E_22 ,B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCE\
SS_SIGMA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID\
 ,B.UPDATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.EVENT_ID ,A.WEIGHT_VALUE\
 ,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_\
TYPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.\
UCL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCA\
LDAT A ,MEDCRESDAT B where (((((((((((A.FACTORY=:b0");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )389;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
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

    case 10:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_10 CURSOR FOR
                SELECT ' ', B.HIST_SEQ, B.COL_SEQ, B.TRAN_TIME, B.HIST_DEL_FLAG, B.FACTORY, ' ', 0, ' ', ' ', B.RES_ID,  B.SUBRES_ID, 
                        ' ', ' ', ' ', 0, B.COL_SET_ID, B.COL_SET_VERSION, B.CHAR_SEQ_NUM, B.CHAR_ID, B.UNIT_SEQ_NUM, 
                        B.UNIT_ID, B.VALUE_SEQ_NUM, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, B.SAMPLE_COUNT, B.NOMINAL, B.PROCESS_SIGMA, B.SPEC_OUT_MASK, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, B.DELETE_USER_ID, B.DELETE_TIME, B.EVENT_ID, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCRESDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.RES_ID = B.RES_ID
                        AND A.SUBRES_ID = B.SUBRES_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_10; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select ' ' ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_DEL_FL\
AG ,B.FACTORY ,' ' ,0 ,' ' ,' ' ,B.RES_ID ,B.SUBRES_ID ,' ' ,' ' ,' ' ,0 ,B.\
COL_SET_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.\
UNIT_ID ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 \
,B.VALUE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9\
 ,B.VALUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.\
VALUE_16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALU\
E_22 ,B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCE\
SS_SIGMA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID\
 ,B.UPDATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.EVENT_ID ,A.WEIGHT_VALUE\
 ,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_\
TYPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.\
UCL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCA\
LDAT A ,MEDCRESDAT B where ((((((((((A.FACTORY=:b0 ");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )424;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
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
         
    case 11:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_11 CURSOR FOR
                SELECT ' ', B.HIST_SEQ, B.COL_SEQ, B.TRAN_TIME, B.HIST_DEL_FLAG, B.FACTORY, ' ', 0, ' ', ' ', B.RES_ID,  B.SUBRES_ID,
                        ' ', ' ', ' ', 0, B.COL_SET_ID, B.COL_SET_VERSION, B.CHAR_SEQ_NUM, B.CHAR_ID, B.UNIT_SEQ_NUM, 
                        B.UNIT_ID, B.VALUE_SEQ_NUM, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, B.SAMPLE_COUNT, B.NOMINAL, B.PROCESS_SIGMA, B.SPEC_OUT_MASK, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, B.DELETE_USER_ID, B.DELETE_TIME, B.EVENT_ID, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCRESDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.RES_ID = B.RES_ID
                        AND A.SUBRES_ID = B.SUBRES_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ_NUM
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_11; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select ' ' ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_DEL_FL\
AG ,B.FACTORY ,' ' ,0 ,' ' ,' ' ,B.RES_ID ,B.SUBRES_ID ,' ' ,' ' ,' ' ,0 ,B.\
COL_SET_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.\
UNIT_ID ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 \
,B.VALUE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9\
 ,B.VALUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.\
VALUE_16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALU\
E_22 ,B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCE\
SS_SIGMA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID\
 ,B.UPDATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.EVENT_ID ,A.WEIGHT_VALUE\
 ,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_\
TYPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.\
UCL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCA\
LDAT A ,MEDCRESDAT B where ((((((((((((A.FACTORY=:b");
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )459;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
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
            
    case 12:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_12 CURSOR FOR
                SELECT ' ', B.HIST_SEQ, B.COL_SEQ, B.TRAN_TIME, B.HIST_DEL_FLAG, B.FACTORY, ' ', 0, ' ', ' ', B.RES_ID,  B.SUBRES_ID, 
                        ' ', ' ', ' ', 0, B.COL_SET_ID, B.COL_SET_VERSION, B.CHAR_SEQ_NUM, B.CHAR_ID, B.UNIT_SEQ_NUM, 
                        B.UNIT_ID, B.VALUE_SEQ_NUM, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, B.SAMPLE_COUNT, B.NOMINAL, B.PROCESS_SIGMA, B.SPEC_OUT_MASK, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, B.DELETE_USER_ID, B.DELETE_TIME, B.EVENT_ID, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MEDCRESDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.RES_ID = B.RES_ID
                        AND A.SUBRES_ID = B.SUBRES_ID
                        AND A.EDC_CHAR_SEQ = B.CHAR_SEQ_NUM
                        AND A.EDC_HIST_SEQ = B.HIST_SEQ
                        AND A.EDC_COL_SEQ = B.COL_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY A.HIST_SEQ DESC, B.UNIT_SEQ_NUM DESC, B.VALUE_SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_12; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select ' ' ,B.HIST_SEQ ,B.COL_SEQ ,B.TRAN_TIME ,B.HIST_DEL_FL\
AG ,B.FACTORY ,' ' ,0 ,' ' ,' ' ,B.RES_ID ,B.SUBRES_ID ,' ' ,' ' ,' ' ,0 ,B.\
COL_SET_ID ,B.COL_SET_VERSION ,B.CHAR_SEQ_NUM ,B.CHAR_ID ,B.UNIT_SEQ_NUM ,B.\
UNIT_ID ,B.VALUE_SEQ_NUM ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 \
,B.VALUE_3 ,B.VALUE_4 ,B.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9\
 ,B.VALUE_10 ,B.VALUE_11 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.\
VALUE_16 ,B.VALUE_17 ,B.VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALU\
E_22 ,B.VALUE_23 ,B.VALUE_24 ,B.VALUE_25 ,B.SAMPLE_COUNT ,B.NOMINAL ,B.PROCE\
SS_SIGMA ,B.SPEC_OUT_MASK ,B.CREATE_USER_ID ,B.CREATE_TIME ,B.UPDATE_USER_ID\
 ,B.UPDATE_TIME ,B.DELETE_USER_ID ,B.DELETE_TIME ,B.EVENT_ID ,A.WEIGHT_VALUE\
 ,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_\
TYPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.\
UCL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCA\
LDAT A ,MEDCRESDAT B where (((((((((((A.FACTORY=:b0");
            sqlstm.stmt = sq0012;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )498;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
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
    case 13:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_13 CURSOR FOR
                SELECT B.LOT_ID, B.HIST_SEQ, 0, B.TRAN_TIME, ' ', B.FACTORY, B.MAT_ID, B.MAT_VER, B.FLOW, B.OPER, B.RES_ID,  A.SUBRES_ID, 
                        B.PROC_OPER, B.PROC_RES_ID, ' ', 0, ' ', 0, 0, B.CHAR_ID, B.UNIT_SEQ, 
                        B.UNIT_ID, B.VALUE_SEQ, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, 0, B.NOMINAL, B.PROCESS_SIGMA, 0, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, ' ', ' ', B.EVENT, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MSPCEDCDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND (A.EXCLUDE_FLAG = :EDCDATA_N.HIST_DEL_FLAG OR EXCLUDE_FLAG = ' ')
                        AND A.CHART_ID = B.CHART_ID
                        AND A.HIST_SEQ = B.HIST_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ
                        AND (A.HIST_SEQ < :EDCDATA_N.HIST_SEQ
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ < :EDCDATA_N.UNIT_SEQ_NUM)
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM AND B.VALUE_SEQ >= :EDCDATA_N.VALUE_SEQ_NUM))
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY B.HIST_SEQ DESC, B.UNIT_SEQ DESC, B.VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_13; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,0 ,B.TRAN_TIME ,' ' ,B.FACTORY ,\
B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.RES_ID ,A.SUBRES_ID ,B.PROC_OPER ,B.P\
ROC_RES_ID ,' ' ,0 ,' ' ,0 ,0 ,B.CHAR_ID ,B.UNIT_SEQ ,B.UNIT_ID ,B.VALUE_SEQ\
 ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VALUE_3 ,B.VALUE_4 ,B\
.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VALUE_10 ,B.VALUE_11\
 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_16 ,B.VALUE_17 ,B.\
VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,B.VALUE_23 ,B.VALU\
E_24 ,B.VALUE_25 ,0 ,B.NOMINAL ,B.PROCESS_SIGMA ,0 ,B.CREATE_USER_ID ,B.CREA\
TE_TIME ,B.UPDATE_USER_ID ,B.UPDATE_TIME ,' ' ,' ' ,B.EVENT ,A.WEIGHT_VALUE \
,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_T\
YPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.U\
CL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCAL\
DAT A ,MSPCEDCDAT B where (((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) an\
d A.CHART_ID=:b1) and (A.EXCLUDE_FLAG=:b2 or EXCLUD");
            sqlstm.stmt = sq0013;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )537;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
        case 14:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_14 CURSOR FOR
                SELECT B.LOT_ID, B.HIST_SEQ, 0, B.TRAN_TIME, ' ', B.FACTORY, B.MAT_ID, B.MAT_VER, B.FLOW, B.OPER, B.RES_ID,  A.SUBRES_ID, 
                        B.PROC_OPER, B.PROC_RES_ID, ' ', 0, ' ', 0, 0, B.CHAR_ID, B.UNIT_SEQ, 
                        B.UNIT_ID, B.VALUE_SEQ, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, 0, B.NOMINAL, B.PROCESS_SIGMA, 0, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, ' ', ' ', B.EVENT, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MSPCEDCDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND (A.EXCLUDE_FLAG = :EDCDATA_N.HIST_DEL_FLAG OR EXCLUDE_FLAG = ' ')
                        AND A.CHART_ID = B.CHART_ID
                        AND A.HIST_SEQ = B.HIST_SEQ
                        AND (A.HIST_SEQ < :EDCDATA_N.HIST_SEQ
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ < :EDCDATA_N.UNIT_SEQ_NUM)
                        OR (A.HIST_SEQ = :EDCDATA_N.HIST_SEQ AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM AND B.VALUE_SEQ >= :EDCDATA_N.VALUE_SEQ_NUM))
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY B.HIST_SEQ DESC, B.UNIT_SEQ DESC, B.VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_14; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,0 ,B.TRAN_TIME ,' ' ,B.FACTORY ,\
B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.RES_ID ,A.SUBRES_ID ,B.PROC_OPER ,B.P\
ROC_RES_ID ,' ' ,0 ,' ' ,0 ,0 ,B.CHAR_ID ,B.UNIT_SEQ ,B.UNIT_ID ,B.VALUE_SEQ\
 ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VALUE_3 ,B.VALUE_4 ,B\
.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VALUE_10 ,B.VALUE_11\
 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_16 ,B.VALUE_17 ,B.\
VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,B.VALUE_23 ,B.VALU\
E_24 ,B.VALUE_25 ,0 ,B.NOMINAL ,B.PROCESS_SIGMA ,0 ,B.CREATE_USER_ID ,B.CREA\
TE_TIME ,B.UPDATE_USER_ID ,B.UPDATE_TIME ,' ' ,' ' ,B.EVENT ,A.WEIGHT_VALUE \
,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_T\
YPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.U\
CL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCAL\
DAT A ,MSPCEDCDAT B where ((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and\
 A.CHART_ID=:b1) and (A.EXCLUDE_FLAG=:b2 or EXCLUDE");
            sqlstm.stmt = sq0014;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )596;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
    case 15:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_15 CURSOR FOR
                SELECT B.LOT_ID, B.HIST_SEQ, 0, B.TRAN_TIME, ' ', B.FACTORY, B.MAT_ID, B.MAT_VER, B.FLOW, B.OPER, B.RES_ID,  A.SUBRES_ID,  
                        B.PROC_OPER, B.PROC_RES_ID, ' ', 0, ' ', 0, 0, B.CHAR_ID, B.UNIT_SEQ, 
                        B.UNIT_ID, B.VALUE_SEQ, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, 0, B.NOMINAL, B.PROCESS_SIGMA, 0, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, ' ', ' ', B.EVENT, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MSPCEDCDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.CHART_ID = B.CHART_ID
                        AND A.HIST_SEQ = B.HIST_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY B.HIST_SEQ DESC, B.UNIT_SEQ DESC, B.VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_15; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,0 ,B.TRAN_TIME ,' ' ,B.FACTORY ,\
B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.RES_ID ,A.SUBRES_ID ,B.PROC_OPER ,B.P\
ROC_RES_ID ,' ' ,0 ,' ' ,0 ,0 ,B.CHAR_ID ,B.UNIT_SEQ ,B.UNIT_ID ,B.VALUE_SEQ\
 ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VALUE_3 ,B.VALUE_4 ,B\
.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VALUE_10 ,B.VALUE_11\
 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_16 ,B.VALUE_17 ,B.\
VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,B.VALUE_23 ,B.VALU\
E_24 ,B.VALUE_25 ,0 ,B.NOMINAL ,B.PROCESS_SIGMA ,0 ,B.CREATE_USER_ID ,B.CREA\
TE_TIME ,B.UPDATE_USER_ID ,B.UPDATE_TIME ,' ' ,' ' ,B.EVENT ,A.WEIGHT_VALUE \
,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_T\
YPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.U\
CL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCAL\
DAT A ,MSPCEDCDAT B where ((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and\
 A.CHART_ID=:b1) and A.CHART_ID=B.CHART_ID) and A.H");
            sqlstm.stmt = sq0015;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )655;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
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

    case 16:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_16 CURSOR FOR
                SELECT B.LOT_ID, B.HIST_SEQ, 0, B.TRAN_TIME, ' ', B.FACTORY, B.MAT_ID, B.MAT_VER, B.FLOW, B.OPER, B.RES_ID,  A.SUBRES_ID, 
                        B.PROC_OPER, B.PROC_RES_ID, ' ', 0, ' ', 0, 0, B.CHAR_ID, B.UNIT_SEQ, 
                        B.UNIT_ID, B.VALUE_SEQ, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, 0, B.NOMINAL, B.PROCESS_SIGMA, 0, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, ' ', ' ', B.EVENT, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MSPCEDCDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.CHART_ID = B.CHART_ID
                        AND A.HIST_SEQ = B.HIST_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY B.HIST_SEQ DESC, B.UNIT_SEQ DESC, B.VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_16; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,0 ,B.TRAN_TIME ,' ' ,B.FACTORY ,\
B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.RES_ID ,A.SUBRES_ID ,B.PROC_OPER ,B.P\
ROC_RES_ID ,' ' ,0 ,' ' ,0 ,0 ,B.CHAR_ID ,B.UNIT_SEQ ,B.UNIT_ID ,B.VALUE_SEQ\
 ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VALUE_3 ,B.VALUE_4 ,B\
.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VALUE_10 ,B.VALUE_11\
 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_16 ,B.VALUE_17 ,B.\
VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,B.VALUE_23 ,B.VALU\
E_24 ,B.VALUE_25 ,0 ,B.NOMINAL ,B.PROCESS_SIGMA ,0 ,B.CREATE_USER_ID ,B.CREA\
TE_TIME ,B.UPDATE_USER_ID ,B.UPDATE_TIME ,' ' ,' ' ,B.EVENT ,A.WEIGHT_VALUE \
,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_T\
YPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.U\
CL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCAL\
DAT A ,MSPCEDCDAT B where (((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and \
A.CHART_ID=:b1) and A.CHART_ID=B.CHART_ID) and A.HI");
            sqlstm.stmt = sq0016;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )690;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
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
         
    case 17:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_17 CURSOR FOR
                SELECT B.LOT_ID, B.HIST_SEQ, 0, B.TRAN_TIME, ' ', B.FACTORY, B.MAT_ID, B.MAT_VER, B.FLOW, B.OPER, B.RES_ID,  A.SUBRES_ID, 
                        B.PROC_OPER, B.PROC_RES_ID, ' ', 0, ' ', 0, 0, B.CHAR_ID, B.UNIT_SEQ, 
                        B.UNIT_ID, B.VALUE_SEQ, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, 0, B.NOMINAL, B.PROCESS_SIGMA, 0, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, ' ', ' ', B.EVENT, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MSPCEDCDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.CHART_ID = B.CHART_ID
                        AND A.HIST_SEQ = B.HIST_SEQ
                        AND A.UNIT_SEQ = B.UNIT_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY B.HIST_SEQ DESC, B.UNIT_SEQ DESC, B.VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_17; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,0 ,B.TRAN_TIME ,' ' ,B.FACTORY ,\
B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.RES_ID ,A.SUBRES_ID ,B.PROC_OPER ,B.P\
ROC_RES_ID ,' ' ,0 ,' ' ,0 ,0 ,B.CHAR_ID ,B.UNIT_SEQ ,B.UNIT_ID ,B.VALUE_SEQ\
 ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VALUE_3 ,B.VALUE_4 ,B\
.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VALUE_10 ,B.VALUE_11\
 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_16 ,B.VALUE_17 ,B.\
VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,B.VALUE_23 ,B.VALU\
E_24 ,B.VALUE_25 ,0 ,B.NOMINAL ,B.PROCESS_SIGMA ,0 ,B.CREATE_USER_ID ,B.CREA\
TE_TIME ,B.UPDATE_USER_ID ,B.UPDATE_TIME ,' ' ,' ' ,B.EVENT ,A.WEIGHT_VALUE \
,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_T\
YPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.U\
CL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCAL\
DAT A ,MSPCEDCDAT B where (((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) an\
d A.CHART_ID=:b1) and A.CHART_ID=B.CHART_ID) and A.");
            sqlstm.stmt = sq0017;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )725;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
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
            
    case 18:
        DB_add_null_condition(&DBC_Q_COND, &DBC_Q_COND_N); 
            /* EXEC SQL DECLARE DBC_EDCDATA_CUR_18 CURSOR FOR
                SELECT B.LOT_ID, B.HIST_SEQ, 0, B.TRAN_TIME, ' ', B.FACTORY, B.MAT_ID, B.MAT_VER, B.FLOW, B.OPER, B.RES_ID,  A.SUBRES_ID, 
                        B.PROC_OPER, B.PROC_RES_ID, ' ', 0, ' ', 0, 0, B.CHAR_ID, B.UNIT_SEQ, 
                        B.UNIT_ID, B.VALUE_SEQ, B.VALUE_TYPE, B.VALUE_COUNT, B.VALUE_1, B.VALUE_2, B.VALUE_3, B.VALUE_4, B.VALUE_5, B.VALUE_6, B.VALUE_7, 
                        B.VALUE_8, B.VALUE_9, B.VALUE_10, B.VALUE_11, B.VALUE_12, B.VALUE_13, B.VALUE_14, B.VALUE_15, B.VALUE_16, B.VALUE_17, B.VALUE_18, 
                        B.VALUE_19, B.VALUE_20, B.VALUE_21, B.VALUE_22, B.VALUE_23, B.VALUE_24, B.VALUE_25, 0, B.NOMINAL, B.PROCESS_SIGMA, 0, 
                        B.CREATE_USER_ID, B.CREATE_TIME, B.UPDATE_USER_ID, B.UPDATE_TIME, ' ', ' ', B.EVENT, 
                        A.WEIGHT_VALUE, A.AVERAGE, A.STDDEV ,A.RANGE, A.MIN_VALUE, A.MAX_VALUE, A.OOC_TYPE, A.OOC_TYPE2, A.EXCLUDE_FLAG, A.VALUE_COUNT as CAL_VAL_CNT,
                       A.USL, A.TARGET, A.LSL, A.UCL, A.CL, A.LCL, A.UCL2, A.CL2, A.LCL2, A.CHART_ID, A.HIST_SEQ
                    FROM MSPCCALDAT A, MSPCEDCDAT B
                    WHERE A.FACTORY = :EDCDATA_N.FACTORY
                        AND A.FACTORY = B.FACTORY
                        AND A.CHART_ID = :EDCDATA_N.CHART_ID
                        AND A.CHART_ID = B.CHART_ID
                        AND A.HIST_SEQ = B.HIST_SEQ
                        AND A.HIST_SEQ = :EDCDATA_N.HIST_SEQ
                        AND A.UNIT_SEQ = :EDCDATA_N.UNIT_SEQ_NUM
                        AND A.TRAN_TIME <= :DBC_Q_COND_N.TO_TIME AND A.TRAN_TIME >= :DBC_Q_COND_N.FROM_TIME
                    ORDER BY B.HIST_SEQ DESC, B.UNIT_SEQ DESC, B.VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBC_EDCDATA_CUR_18; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select B.LOT_ID ,B.HIST_SEQ ,0 ,B.TRAN_TIME ,' ' ,B.FACTORY ,\
B.MAT_ID ,B.MAT_VER ,B.FLOW ,B.OPER ,B.RES_ID ,A.SUBRES_ID ,B.PROC_OPER ,B.P\
ROC_RES_ID ,' ' ,0 ,' ' ,0 ,0 ,B.CHAR_ID ,B.UNIT_SEQ ,B.UNIT_ID ,B.VALUE_SEQ\
 ,B.VALUE_TYPE ,B.VALUE_COUNT ,B.VALUE_1 ,B.VALUE_2 ,B.VALUE_3 ,B.VALUE_4 ,B\
.VALUE_5 ,B.VALUE_6 ,B.VALUE_7 ,B.VALUE_8 ,B.VALUE_9 ,B.VALUE_10 ,B.VALUE_11\
 ,B.VALUE_12 ,B.VALUE_13 ,B.VALUE_14 ,B.VALUE_15 ,B.VALUE_16 ,B.VALUE_17 ,B.\
VALUE_18 ,B.VALUE_19 ,B.VALUE_20 ,B.VALUE_21 ,B.VALUE_22 ,B.VALUE_23 ,B.VALU\
E_24 ,B.VALUE_25 ,0 ,B.NOMINAL ,B.PROCESS_SIGMA ,0 ,B.CREATE_USER_ID ,B.CREA\
TE_TIME ,B.UPDATE_USER_ID ,B.UPDATE_TIME ,' ' ,' ' ,B.EVENT ,A.WEIGHT_VALUE \
,A.AVERAGE ,A.stddev ,A.RANGE ,A.MIN_VALUE ,A.MAX_VALUE ,A.OOC_TYPE ,A.OOC_T\
YPE2 ,A.EXCLUDE_FLAG ,A.VALUE_COUNT CAL_VAL_CNT ,A.USL ,A.TARGET ,A.LSL ,A.U\
CL ,A.CL ,A.LCL ,A.UCL2 ,A.CL2 ,A.LCL2 ,A.CHART_ID ,A.HIST_SEQ  from MSPCCAL\
DAT A ,MSPCEDCDAT B where ((((((((A.FACTORY=:b0 and A.FACTORY=B.FACTORY) and\
 A.CHART_ID=:b1) and A.CHART_ID=B.CHART_ID) and A.H");
            sqlstm.stmt = sq0018;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )764;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(DBC_Q_COND_N.TO_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(DBC_Q_COND_N.FROM_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
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
   

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_edcdata", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_edcdata(int sel_type, struct EDCDATA_TAG *EDCDATA)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct EDCDATA_N_TAG EDCDATA_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_1 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )803;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
        
        case 2:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_2 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1146;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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

        case 3:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_3 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1489;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 4:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_4 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1832;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
        
        case 5:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_5 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2175;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 6:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_6 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2518;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 7:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_7 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2861;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 8:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_8 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3204;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
        
        case 9:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_9 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3547;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 10:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_10 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3890;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 11:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_11 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4233;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 12:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_12 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4576;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 13:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_13 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4919;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 14:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_14 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5262;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
        
        case 15:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_15 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5605;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 16:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_16 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5948;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 17:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_17 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6291;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
            
        case 18:
            /* EXEC SQL FETCH DBC_EDCDATA_CUR_18 INTO
                                                :EDCDATA_N.LOT_ID,
                                                :EDCDATA_N.HIST_SEQ,
                                                :EDCDATA_N.COL_SEQ,
                                                :EDCDATA_N.TRAN_TIME,
                                                :EDCDATA_N.HIST_DEL_FLAG,
                                                :EDCDATA_N.FACTORY,
                                                :EDCDATA_N.MAT_ID,
                                                :EDCDATA_N.MAT_VER,
                                                :EDCDATA_N.FLOW,
                                                :EDCDATA_N.OPER,
                                                :EDCDATA_N.MEAS_RES_ID,
                                                :EDCDATA_N.PROC_FLOW,
                                                :EDCDATA_N.PROC_OPER,
                                                :EDCDATA_N.PROC_RES_ID,
                                                :EDCDATA_N.RECIPE_ID,
                                                :EDCDATA_N.RECIPE_VERSION,
                                                :EDCDATA_N.COL_SET_ID,
                                                :EDCDATA_N.COL_SET_VERSION,
                                                :EDCDATA_N.CHAR_SEQ_NUM,
                                                :EDCDATA_N.CHAR_ID,
                                                :EDCDATA_N.UNIT_SEQ_NUM,
                                                :EDCDATA_N.UNIT_ID,
                                                :EDCDATA_N.VALUE_SEQ_NUM,
                                                :EDCDATA_N.VALUE_TYPE,
                                                :EDCDATA_N.VALUE_COUNT,
                                                :EDCDATA_N.VALUE_1,
                                                :EDCDATA_N.VALUE_2,
                                                :EDCDATA_N.VALUE_3,
                                                :EDCDATA_N.VALUE_4,
                                                :EDCDATA_N.VALUE_5,
                                                :EDCDATA_N.VALUE_6,
                                                :EDCDATA_N.VALUE_7,
                                                :EDCDATA_N.VALUE_8,
                                                :EDCDATA_N.VALUE_9,
                                                :EDCDATA_N.VALUE_10,
                                                :EDCDATA_N.VALUE_11,
                                                :EDCDATA_N.VALUE_12,
                                                :EDCDATA_N.VALUE_13,
                                                :EDCDATA_N.VALUE_14,
                                                :EDCDATA_N.VALUE_15,
                                                :EDCDATA_N.VALUE_16,
                                                :EDCDATA_N.VALUE_17,
                                                :EDCDATA_N.VALUE_18,
                                                :EDCDATA_N.VALUE_19,
                                                :EDCDATA_N.VALUE_20,
                                                :EDCDATA_N.VALUE_21,
                                                :EDCDATA_N.VALUE_22,
                                                :EDCDATA_N.VALUE_23,
                                                :EDCDATA_N.VALUE_24,
                                                :EDCDATA_N.VALUE_25,
                                                :EDCDATA_N.SAMPLE_COUNT,
                                                :EDCDATA_N.NOMINAL,
                                                :EDCDATA_N.PROCESS_SIGMA,
                                                :EDCDATA_N.SPEC_OUT_MASK,
                                                :EDCDATA_N.CREATE_USER_ID,
                                                :EDCDATA_N.CREATE_TIME,
                                                :EDCDATA_N.UPDATE_USER_ID,
                                                :EDCDATA_N.UPDATE_TIME,
                                                :EDCDATA_N.DELETE_USER_ID,
                                                :EDCDATA_N.DELETE_TIME,
                                                :EDCDATA_N.EVENT_ID,
                                                :EDCDATA_N.WEIGHT_VALUE,
                                                :EDCDATA_N.AVERAGE,
                                                :EDCDATA_N.STDDEV,
                                                :EDCDATA_N.RANGE,
                                                :EDCDATA_N.MIN_VALUE,
                                                :EDCDATA_N.MAX_VALUE,
                                                :EDCDATA_N.OOC_TYPE,
                                                :EDCDATA_N.OOC_TYPE2,
                                                :EDCDATA_N.EXCLUDE_FLAG,
                                                :EDCDATA_N.CAL_VAL_CNT,
                                                :EDCDATA_N.USL,
                                                :EDCDATA_N.TARGET,
                                                :EDCDATA_N.LSL,
                                                :EDCDATA_N.UCL,
                                                :EDCDATA_N.CL,
                                                :EDCDATA_N.LCL,
                                                :EDCDATA_N.UCL2,
                                                :EDCDATA_N.CL2,
                                                :EDCDATA_N.LCL2,
                                                :EDCDATA_N.CHART_ID,
                                                :EDCDATA_N.CAL_HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6634;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(EDCDATA_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(EDCDATA_N.HIST_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(EDCDATA_N.COL_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(EDCDATA_N.TRAN_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(EDCDATA_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(EDCDATA_N.FACTORY);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(EDCDATA_N.MAT_ID);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(EDCDATA_N.MAT_VER);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(EDCDATA_N.FLOW);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(EDCDATA_N.OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(EDCDATA_N.MEAS_RES_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(EDCDATA_N.PROC_FLOW);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(EDCDATA_N.PROC_OPER);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(EDCDATA_N.PROC_RES_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(EDCDATA_N.RECIPE_ID);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(EDCDATA_N.RECIPE_VERSION);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(EDCDATA_N.COL_SET_ID);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)&(EDCDATA_N.COL_SET_VERSION);
            sqlstm.sqhstl[17] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(EDCDATA_N.CHAR_SEQ_NUM);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(EDCDATA_N.CHAR_ID);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(EDCDATA_N.UNIT_SEQ_NUM);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(EDCDATA_N.UNIT_ID);
            sqlstm.sqhstl[21] = (unsigned int  )51;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(EDCDATA_N.VALUE_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(EDCDATA_N.VALUE_TYPE);
            sqlstm.sqhstl[23] = (unsigned int  )2;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(EDCDATA_N.VALUE_COUNT);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(EDCDATA_N.VALUE_1);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(EDCDATA_N.VALUE_2);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(EDCDATA_N.VALUE_3);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(EDCDATA_N.VALUE_4);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(EDCDATA_N.VALUE_5);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(EDCDATA_N.VALUE_6);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(EDCDATA_N.VALUE_7);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(EDCDATA_N.VALUE_8);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(EDCDATA_N.VALUE_9);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(EDCDATA_N.VALUE_10);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(EDCDATA_N.VALUE_11);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(EDCDATA_N.VALUE_12);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(EDCDATA_N.VALUE_13);
            sqlstm.sqhstl[37] = (unsigned int  )26;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(EDCDATA_N.VALUE_14);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(EDCDATA_N.VALUE_15);
            sqlstm.sqhstl[39] = (unsigned int  )26;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(EDCDATA_N.VALUE_16);
            sqlstm.sqhstl[40] = (unsigned int  )26;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(EDCDATA_N.VALUE_17);
            sqlstm.sqhstl[41] = (unsigned int  )26;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(EDCDATA_N.VALUE_18);
            sqlstm.sqhstl[42] = (unsigned int  )26;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(EDCDATA_N.VALUE_19);
            sqlstm.sqhstl[43] = (unsigned int  )26;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(EDCDATA_N.VALUE_20);
            sqlstm.sqhstl[44] = (unsigned int  )26;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(EDCDATA_N.VALUE_21);
            sqlstm.sqhstl[45] = (unsigned int  )26;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(EDCDATA_N.VALUE_22);
            sqlstm.sqhstl[46] = (unsigned int  )26;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(EDCDATA_N.VALUE_23);
            sqlstm.sqhstl[47] = (unsigned int  )26;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(EDCDATA_N.VALUE_24);
            sqlstm.sqhstl[48] = (unsigned int  )26;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(EDCDATA_N.VALUE_25);
            sqlstm.sqhstl[49] = (unsigned int  )26;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)&(EDCDATA_N.SAMPLE_COUNT);
            sqlstm.sqhstl[50] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(EDCDATA_N.NOMINAL);
            sqlstm.sqhstl[51] = (unsigned int  )26;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(EDCDATA_N.PROCESS_SIGMA);
            sqlstm.sqhstl[52] = (unsigned int  )26;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(EDCDATA_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(EDCDATA_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(EDCDATA_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(EDCDATA_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(EDCDATA_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(EDCDATA_N.DELETE_USER_ID);
            sqlstm.sqhstl[58] = (unsigned int  )21;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(EDCDATA_N.DELETE_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(EDCDATA_N.EVENT_ID);
            sqlstm.sqhstl[60] = (unsigned int  )13;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(EDCDATA_N.WEIGHT_VALUE);
            sqlstm.sqhstl[61] = (unsigned int  )26;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(EDCDATA_N.AVERAGE);
            sqlstm.sqhstl[62] = (unsigned int  )26;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(EDCDATA_N.STDDEV);
            sqlstm.sqhstl[63] = (unsigned int  )26;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(EDCDATA_N.RANGE);
            sqlstm.sqhstl[64] = (unsigned int  )26;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(EDCDATA_N.MIN_VALUE);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(EDCDATA_N.MAX_VALUE);
            sqlstm.sqhstl[66] = (unsigned int  )26;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(EDCDATA_N.OOC_TYPE);
            sqlstm.sqhstl[67] = (unsigned int  )2;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(EDCDATA_N.OOC_TYPE2);
            sqlstm.sqhstl[68] = (unsigned int  )2;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(EDCDATA_N.EXCLUDE_FLAG);
            sqlstm.sqhstl[69] = (unsigned int  )2;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)&(EDCDATA_N.CAL_VAL_CNT);
            sqlstm.sqhstl[70] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(EDCDATA_N.USL);
            sqlstm.sqhstl[71] = (unsigned int  )21;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(EDCDATA_N.TARGET);
            sqlstm.sqhstl[72] = (unsigned int  )21;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(EDCDATA_N.LSL);
            sqlstm.sqhstl[73] = (unsigned int  )21;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(EDCDATA_N.UCL);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(EDCDATA_N.CL);
            sqlstm.sqhstl[75] = (unsigned int  )21;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(EDCDATA_N.LCL);
            sqlstm.sqhstl[76] = (unsigned int  )21;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(EDCDATA_N.UCL2);
            sqlstm.sqhstl[77] = (unsigned int  )21;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(EDCDATA_N.CL2);
            sqlstm.sqhstl[78] = (unsigned int  )21;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(EDCDATA_N.LCL2);
            sqlstm.sqhstl[79] = (unsigned int  )21;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(EDCDATA_N.CHART_ID);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)&(EDCDATA_N.CAL_HIST_SEQ);
            sqlstm.sqhstl[81] = (unsigned int  )sizeof(int);
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
        DBC_del_null_edcdata(&EDCDATA_N, EDCDATA);
    }
    DB_stop_query_timer("DBC_fetch_edcdata", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_edcdata(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6977;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6992;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 3:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7007;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 4:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7022;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;    
        case 5:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7037;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 6:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7052;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;  
            
        case 7:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_7; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7067;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            
            
        case 8:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_8; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7082;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            
      
        case 9:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_9; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7097;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            
            
       case 10:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_10; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7112;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            
            
       case 11:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_11; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7127;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            
            
       case 12:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_12; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7142;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 13:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_13; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7157;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 14:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_14; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7172;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;    
        case 15:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_15; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7187;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 16:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_16; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7202;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;  
            
        case 17:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_17; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7217;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            
            
        case 18:
            /* EXEC SQL CLOSE DBC_EDCDATA_CUR_18; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 82;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )7232;
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
    DB_stop_query_timer("DBC_close_edcdata", sel_type);
}


/* Initialize Function */
void DBC_init_edcdata(struct EDCDATA_TAG *EDCDATA)
{
    /* memset by Space */
    memset(EDCDATA, ' ', sizeof(struct EDCDATA_TAG));
    
    EDCDATA->HIST_SEQ = 0;
    EDCDATA->COL_SEQ = 0;
    EDCDATA->MAT_VER = 0;
    EDCDATA->RECIPE_VERSION = 0;
    EDCDATA->COL_SET_VERSION = 0;
    EDCDATA->CHAR_SEQ_NUM = 0;
    EDCDATA->UNIT_SEQ_NUM = 0;
    EDCDATA->VALUE_SEQ_NUM = 0;
    EDCDATA->VALUE_COUNT = 0;
    EDCDATA->CAL_VAL_CNT = 0;
    EDCDATA->CAL_HIST_SEQ = 0;

}


/* Add Null Function */
void DBC_add_null_edcdata(struct EDCDATA_N_TAG *EDCDATA_N, struct EDCDATA_TAG *EDCDATA)
{
    /* memset by NULL */
    memset(EDCDATA_N, '\0', sizeof(struct EDCDATA_N_TAG));
    
    MEMCPY_AN(EDCDATA_N->LOT_ID, EDCDATA->LOT_ID, sizeof(EDCDATA->LOT_ID));
    EDCDATA_N->HIST_SEQ = EDCDATA->HIST_SEQ;
    EDCDATA_N->COL_SEQ = EDCDATA->COL_SEQ;
    MEMCPY_AN(EDCDATA_N->TRAN_TIME, EDCDATA->TRAN_TIME, sizeof(EDCDATA->TRAN_TIME));
    EDCDATA_N->HIST_DEL_FLAG[0] = EDCDATA->HIST_DEL_FLAG;
    MEMCPY_AN(EDCDATA_N->FACTORY, EDCDATA->FACTORY, sizeof(EDCDATA->FACTORY));
    MEMCPY_AN(EDCDATA_N->MAT_ID, EDCDATA->MAT_ID, sizeof(EDCDATA->MAT_ID));
    EDCDATA_N->MAT_VER = EDCDATA->MAT_VER;
    MEMCPY_AN(EDCDATA_N->FLOW, EDCDATA->FLOW, sizeof(EDCDATA->FLOW));
    MEMCPY_AN(EDCDATA_N->OPER, EDCDATA->OPER, sizeof(EDCDATA->OPER));
    MEMCPY_AN(EDCDATA_N->MEAS_RES_ID, EDCDATA->MEAS_RES_ID, sizeof(EDCDATA->MEAS_RES_ID));
    MEMCPY_AN(EDCDATA_N->PROC_FLOW, EDCDATA->PROC_FLOW, sizeof(EDCDATA->PROC_FLOW));
    MEMCPY_AN(EDCDATA_N->PROC_OPER, EDCDATA->PROC_OPER, sizeof(EDCDATA->PROC_OPER));
    MEMCPY_AN(EDCDATA_N->PROC_RES_ID, EDCDATA->PROC_RES_ID, sizeof(EDCDATA->PROC_RES_ID));
    MEMCPY_AN(EDCDATA_N->RECIPE_ID, EDCDATA->RECIPE_ID, sizeof(EDCDATA->RECIPE_ID));
    EDCDATA_N->RECIPE_VERSION = EDCDATA->RECIPE_VERSION;
    MEMCPY_AN(EDCDATA_N->COL_SET_ID, EDCDATA->COL_SET_ID, sizeof(EDCDATA->COL_SET_ID));
    EDCDATA_N->COL_SET_VERSION = EDCDATA->COL_SET_VERSION;
    EDCDATA_N->CHAR_SEQ_NUM = EDCDATA->CHAR_SEQ_NUM;
    MEMCPY_AN(EDCDATA_N->CHAR_ID, EDCDATA->CHAR_ID, sizeof(EDCDATA->CHAR_ID));
    EDCDATA_N->UNIT_SEQ_NUM = EDCDATA->UNIT_SEQ_NUM;
    MEMCPY_AN(EDCDATA_N->UNIT_ID, EDCDATA->UNIT_ID, sizeof(EDCDATA->UNIT_ID));
    EDCDATA_N->VALUE_SEQ_NUM = EDCDATA->VALUE_SEQ_NUM;
    EDCDATA_N->VALUE_TYPE[0] = EDCDATA->VALUE_TYPE;
    EDCDATA_N->VALUE_COUNT = EDCDATA->VALUE_COUNT;
    MEMCPY_AN(EDCDATA_N->VALUE_1, EDCDATA->VALUE_1, sizeof(EDCDATA->VALUE_1));
    MEMCPY_AN(EDCDATA_N->VALUE_2, EDCDATA->VALUE_2, sizeof(EDCDATA->VALUE_2));
    MEMCPY_AN(EDCDATA_N->VALUE_3, EDCDATA->VALUE_3, sizeof(EDCDATA->VALUE_3));
    MEMCPY_AN(EDCDATA_N->VALUE_4, EDCDATA->VALUE_4, sizeof(EDCDATA->VALUE_4));
    MEMCPY_AN(EDCDATA_N->VALUE_5, EDCDATA->VALUE_5, sizeof(EDCDATA->VALUE_5));
    MEMCPY_AN(EDCDATA_N->VALUE_6, EDCDATA->VALUE_6, sizeof(EDCDATA->VALUE_6));
    MEMCPY_AN(EDCDATA_N->VALUE_7, EDCDATA->VALUE_7, sizeof(EDCDATA->VALUE_7));
    MEMCPY_AN(EDCDATA_N->VALUE_8, EDCDATA->VALUE_8, sizeof(EDCDATA->VALUE_8));
    MEMCPY_AN(EDCDATA_N->VALUE_9, EDCDATA->VALUE_9, sizeof(EDCDATA->VALUE_9));
    MEMCPY_AN(EDCDATA_N->VALUE_10, EDCDATA->VALUE_10, sizeof(EDCDATA->VALUE_10));
    MEMCPY_AN(EDCDATA_N->VALUE_11, EDCDATA->VALUE_11, sizeof(EDCDATA->VALUE_11));
    MEMCPY_AN(EDCDATA_N->VALUE_12, EDCDATA->VALUE_12, sizeof(EDCDATA->VALUE_12));
    MEMCPY_AN(EDCDATA_N->VALUE_13, EDCDATA->VALUE_13, sizeof(EDCDATA->VALUE_13));
    MEMCPY_AN(EDCDATA_N->VALUE_14, EDCDATA->VALUE_14, sizeof(EDCDATA->VALUE_14));
    MEMCPY_AN(EDCDATA_N->VALUE_15, EDCDATA->VALUE_15, sizeof(EDCDATA->VALUE_15));
    MEMCPY_AN(EDCDATA_N->VALUE_16, EDCDATA->VALUE_16, sizeof(EDCDATA->VALUE_16));
    MEMCPY_AN(EDCDATA_N->VALUE_17, EDCDATA->VALUE_17, sizeof(EDCDATA->VALUE_17));
    MEMCPY_AN(EDCDATA_N->VALUE_18, EDCDATA->VALUE_18, sizeof(EDCDATA->VALUE_18));
    MEMCPY_AN(EDCDATA_N->VALUE_19, EDCDATA->VALUE_19, sizeof(EDCDATA->VALUE_19));
    MEMCPY_AN(EDCDATA_N->VALUE_20, EDCDATA->VALUE_20, sizeof(EDCDATA->VALUE_20));
    MEMCPY_AN(EDCDATA_N->VALUE_21, EDCDATA->VALUE_21, sizeof(EDCDATA->VALUE_21));
    MEMCPY_AN(EDCDATA_N->VALUE_22, EDCDATA->VALUE_22, sizeof(EDCDATA->VALUE_22));
    MEMCPY_AN(EDCDATA_N->VALUE_23, EDCDATA->VALUE_23, sizeof(EDCDATA->VALUE_23));
    MEMCPY_AN(EDCDATA_N->VALUE_24, EDCDATA->VALUE_24, sizeof(EDCDATA->VALUE_24));
    MEMCPY_AN(EDCDATA_N->VALUE_25, EDCDATA->VALUE_25, sizeof(EDCDATA->VALUE_25));
    EDCDATA_N->SAMPLE_COUNT = EDCDATA->SAMPLE_COUNT;
    MEMCPY_AN(EDCDATA_N->NOMINAL, EDCDATA->NOMINAL, sizeof(EDCDATA->NOMINAL));
    MEMCPY_AN(EDCDATA_N->PROCESS_SIGMA, EDCDATA->PROCESS_SIGMA, sizeof(EDCDATA->PROCESS_SIGMA));
    MEMCPY_AN(EDCDATA_N->SPEC_OUT_MASK, EDCDATA->SPEC_OUT_MASK, sizeof(EDCDATA->SPEC_OUT_MASK));
    MEMCPY_AN(EDCDATA_N->CREATE_USER_ID, EDCDATA->CREATE_USER_ID, sizeof(EDCDATA->CREATE_USER_ID));
    MEMCPY_AN(EDCDATA_N->CREATE_TIME, EDCDATA->CREATE_TIME, sizeof(EDCDATA->CREATE_TIME));
    MEMCPY_AN(EDCDATA_N->UPDATE_USER_ID, EDCDATA->UPDATE_USER_ID, sizeof(EDCDATA->UPDATE_USER_ID));
    MEMCPY_AN(EDCDATA_N->UPDATE_TIME, EDCDATA->UPDATE_TIME, sizeof(EDCDATA->UPDATE_TIME));
    MEMCPY_AN(EDCDATA_N->DELETE_USER_ID, EDCDATA->DELETE_USER_ID, sizeof(EDCDATA->DELETE_USER_ID));
    MEMCPY_AN(EDCDATA_N->DELETE_TIME, EDCDATA->DELETE_TIME, sizeof(EDCDATA->DELETE_TIME));
    MEMCPY_AN(EDCDATA_N->EVENT_ID, EDCDATA->EVENT_ID, sizeof(EDCDATA->EVENT_ID));
    MEMCPY_AN(EDCDATA_N->WEIGHT_VALUE, EDCDATA->WEIGHT_VALUE, sizeof(EDCDATA->WEIGHT_VALUE));
    MEMCPY_AN(EDCDATA_N->AVERAGE, EDCDATA->AVERAGE, sizeof(EDCDATA->AVERAGE));
    MEMCPY_AN(EDCDATA_N->STDDEV, EDCDATA->STDDEV, sizeof(EDCDATA->STDDEV));
    MEMCPY_AN(EDCDATA_N->RANGE, EDCDATA->RANGE, sizeof(EDCDATA->RANGE));
    MEMCPY_AN(EDCDATA_N->MIN_VALUE, EDCDATA->MIN_VALUE, sizeof(EDCDATA->MIN_VALUE));
    MEMCPY_AN(EDCDATA_N->MAX_VALUE, EDCDATA->MAX_VALUE, sizeof(EDCDATA->MAX_VALUE));
    EDCDATA_N->OOC_TYPE[0] = EDCDATA->OOC_TYPE;
    EDCDATA_N->OOC_TYPE2[0] = EDCDATA->OOC_TYPE2;
    EDCDATA_N->EXCLUDE_FLAG[0] = EDCDATA->EXCLUDE_FLAG;
    EDCDATA_N->CAL_VAL_CNT = EDCDATA->CAL_VAL_CNT;
    MEMCPY_AN(EDCDATA_N->USL, EDCDATA->USL, sizeof(EDCDATA->USL));
    MEMCPY_AN(EDCDATA_N->TARGET, EDCDATA->TARGET, sizeof(EDCDATA->TARGET));
    MEMCPY_AN(EDCDATA_N->LSL, EDCDATA->LSL, sizeof(EDCDATA->LSL));
    MEMCPY_AN(EDCDATA_N->UCL, EDCDATA->UCL, sizeof(EDCDATA->UCL));
    MEMCPY_AN(EDCDATA_N->CL, EDCDATA->CL, sizeof(EDCDATA->CL));
    MEMCPY_AN(EDCDATA_N->LCL, EDCDATA->LCL, sizeof(EDCDATA->LCL));
    MEMCPY_AN(EDCDATA_N->UCL2, EDCDATA->UCL2, sizeof(EDCDATA->UCL2));
    MEMCPY_AN(EDCDATA_N->CL2, EDCDATA->CL2, sizeof(EDCDATA->CL2));
    MEMCPY_AN(EDCDATA_N->LCL2, EDCDATA->LCL2, sizeof(EDCDATA->LCL2)); 
    MEMCPY_AN(EDCDATA_N->CHART_ID, EDCDATA->CHART_ID, sizeof(EDCDATA->CHART_ID)); 
    EDCDATA_N->CAL_HIST_SEQ = EDCDATA->CAL_HIST_SEQ;   
    
}


/* Del Null Function */
void DBC_del_null_edcdata(struct EDCDATA_N_TAG *EDCDATA_N, struct EDCDATA_TAG *EDCDATA)
{
    MEMCPY_DN(EDCDATA->LOT_ID, EDCDATA_N->LOT_ID, sizeof(EDCDATA->LOT_ID));
    EDCDATA->HIST_SEQ = EDCDATA_N->HIST_SEQ;
    EDCDATA->COL_SEQ = EDCDATA_N->COL_SEQ;
    MEMCPY_DN(EDCDATA->TRAN_TIME, EDCDATA_N->TRAN_TIME, sizeof(EDCDATA->TRAN_TIME));
    EDCDATA->HIST_DEL_FLAG = EDCDATA_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(EDCDATA->FACTORY, EDCDATA_N->FACTORY, sizeof(EDCDATA->FACTORY));
    MEMCPY_DN(EDCDATA->MAT_ID, EDCDATA_N->MAT_ID, sizeof(EDCDATA->MAT_ID));
    EDCDATA->MAT_VER = EDCDATA_N->MAT_VER;
    MEMCPY_DN(EDCDATA->FLOW, EDCDATA_N->FLOW, sizeof(EDCDATA->FLOW));
    MEMCPY_DN(EDCDATA->OPER, EDCDATA_N->OPER, sizeof(EDCDATA->OPER));
    MEMCPY_DN(EDCDATA->MEAS_RES_ID, EDCDATA_N->MEAS_RES_ID, sizeof(EDCDATA->MEAS_RES_ID));
    MEMCPY_DN(EDCDATA->PROC_FLOW, EDCDATA_N->PROC_FLOW, sizeof(EDCDATA->PROC_FLOW));
    MEMCPY_DN(EDCDATA->PROC_OPER, EDCDATA_N->PROC_OPER, sizeof(EDCDATA->PROC_OPER));
    MEMCPY_DN(EDCDATA->PROC_RES_ID, EDCDATA_N->PROC_RES_ID, sizeof(EDCDATA->PROC_RES_ID));
    MEMCPY_DN(EDCDATA->RECIPE_ID, EDCDATA_N->RECIPE_ID, sizeof(EDCDATA->RECIPE_ID));
    EDCDATA->RECIPE_VERSION = EDCDATA_N->RECIPE_VERSION;
    MEMCPY_DN(EDCDATA->COL_SET_ID, EDCDATA_N->COL_SET_ID, sizeof(EDCDATA->COL_SET_ID));
    EDCDATA->COL_SET_VERSION = EDCDATA_N->COL_SET_VERSION;
    EDCDATA->CHAR_SEQ_NUM = EDCDATA_N->CHAR_SEQ_NUM;
    MEMCPY_DN(EDCDATA->CHAR_ID, EDCDATA_N->CHAR_ID, sizeof(EDCDATA->CHAR_ID));
    EDCDATA->UNIT_SEQ_NUM = EDCDATA_N->UNIT_SEQ_NUM;
    MEMCPY_DN(EDCDATA->UNIT_ID, EDCDATA_N->UNIT_ID, sizeof(EDCDATA->UNIT_ID));
    EDCDATA->VALUE_SEQ_NUM = EDCDATA_N->VALUE_SEQ_NUM;
    EDCDATA->VALUE_TYPE = EDCDATA_N->VALUE_TYPE[0];
    EDCDATA->VALUE_COUNT = EDCDATA_N->VALUE_COUNT;
    MEMCPY_DN(EDCDATA->VALUE_1, EDCDATA_N->VALUE_1, sizeof(EDCDATA->VALUE_1));
    MEMCPY_DN(EDCDATA->VALUE_2, EDCDATA_N->VALUE_2, sizeof(EDCDATA->VALUE_2));
    MEMCPY_DN(EDCDATA->VALUE_3, EDCDATA_N->VALUE_3, sizeof(EDCDATA->VALUE_3));
    MEMCPY_DN(EDCDATA->VALUE_4, EDCDATA_N->VALUE_4, sizeof(EDCDATA->VALUE_4));
    MEMCPY_DN(EDCDATA->VALUE_5, EDCDATA_N->VALUE_5, sizeof(EDCDATA->VALUE_5));
    MEMCPY_DN(EDCDATA->VALUE_6, EDCDATA_N->VALUE_6, sizeof(EDCDATA->VALUE_6));
    MEMCPY_DN(EDCDATA->VALUE_7, EDCDATA_N->VALUE_7, sizeof(EDCDATA->VALUE_7));
    MEMCPY_DN(EDCDATA->VALUE_8, EDCDATA_N->VALUE_8, sizeof(EDCDATA->VALUE_8));
    MEMCPY_DN(EDCDATA->VALUE_9, EDCDATA_N->VALUE_9, sizeof(EDCDATA->VALUE_9));
    MEMCPY_DN(EDCDATA->VALUE_10, EDCDATA_N->VALUE_10, sizeof(EDCDATA->VALUE_10));
    MEMCPY_DN(EDCDATA->VALUE_11, EDCDATA_N->VALUE_11, sizeof(EDCDATA->VALUE_11));
    MEMCPY_DN(EDCDATA->VALUE_12, EDCDATA_N->VALUE_12, sizeof(EDCDATA->VALUE_12));
    MEMCPY_DN(EDCDATA->VALUE_13, EDCDATA_N->VALUE_13, sizeof(EDCDATA->VALUE_13));
    MEMCPY_DN(EDCDATA->VALUE_14, EDCDATA_N->VALUE_14, sizeof(EDCDATA->VALUE_14));
    MEMCPY_DN(EDCDATA->VALUE_15, EDCDATA_N->VALUE_15, sizeof(EDCDATA->VALUE_15));
    MEMCPY_DN(EDCDATA->VALUE_16, EDCDATA_N->VALUE_16, sizeof(EDCDATA->VALUE_16));
    MEMCPY_DN(EDCDATA->VALUE_17, EDCDATA_N->VALUE_17, sizeof(EDCDATA->VALUE_17));
    MEMCPY_DN(EDCDATA->VALUE_18, EDCDATA_N->VALUE_18, sizeof(EDCDATA->VALUE_18));
    MEMCPY_DN(EDCDATA->VALUE_19, EDCDATA_N->VALUE_19, sizeof(EDCDATA->VALUE_19));
    MEMCPY_DN(EDCDATA->VALUE_20, EDCDATA_N->VALUE_20, sizeof(EDCDATA->VALUE_20));
    MEMCPY_DN(EDCDATA->VALUE_21, EDCDATA_N->VALUE_21, sizeof(EDCDATA->VALUE_21));
    MEMCPY_DN(EDCDATA->VALUE_22, EDCDATA_N->VALUE_22, sizeof(EDCDATA->VALUE_22));
    MEMCPY_DN(EDCDATA->VALUE_23, EDCDATA_N->VALUE_23, sizeof(EDCDATA->VALUE_23));
    MEMCPY_DN(EDCDATA->VALUE_24, EDCDATA_N->VALUE_24, sizeof(EDCDATA->VALUE_24));
    MEMCPY_DN(EDCDATA->VALUE_25, EDCDATA_N->VALUE_25, sizeof(EDCDATA->VALUE_25));
    EDCDATA->SAMPLE_COUNT = EDCDATA_N->SAMPLE_COUNT;
    MEMCPY_DN(EDCDATA->NOMINAL, EDCDATA_N->NOMINAL, sizeof(EDCDATA->NOMINAL));
    MEMCPY_DN(EDCDATA->PROCESS_SIGMA, EDCDATA_N->PROCESS_SIGMA, sizeof(EDCDATA->PROCESS_SIGMA));
    MEMCPY_DN(EDCDATA->SPEC_OUT_MASK, EDCDATA_N->SPEC_OUT_MASK, sizeof(EDCDATA->SPEC_OUT_MASK));
    MEMCPY_DN(EDCDATA->CREATE_USER_ID, EDCDATA_N->CREATE_USER_ID, sizeof(EDCDATA->CREATE_USER_ID));
    MEMCPY_DN(EDCDATA->CREATE_TIME, EDCDATA_N->CREATE_TIME, sizeof(EDCDATA->CREATE_TIME));
    MEMCPY_DN(EDCDATA->UPDATE_USER_ID, EDCDATA_N->UPDATE_USER_ID, sizeof(EDCDATA->UPDATE_USER_ID));
    MEMCPY_DN(EDCDATA->UPDATE_TIME, EDCDATA_N->UPDATE_TIME, sizeof(EDCDATA->UPDATE_TIME));
    MEMCPY_DN(EDCDATA->DELETE_USER_ID, EDCDATA_N->DELETE_USER_ID, sizeof(EDCDATA->DELETE_USER_ID));
    MEMCPY_DN(EDCDATA->DELETE_TIME, EDCDATA_N->DELETE_TIME, sizeof(EDCDATA->DELETE_TIME));
    MEMCPY_DN(EDCDATA->EVENT_ID, EDCDATA_N->EVENT_ID, sizeof(EDCDATA->EVENT_ID));
    MEMCPY_DN(EDCDATA->WEIGHT_VALUE, EDCDATA_N->WEIGHT_VALUE, sizeof(EDCDATA->WEIGHT_VALUE));
    MEMCPY_DN(EDCDATA->AVERAGE, EDCDATA_N->AVERAGE, sizeof(EDCDATA->AVERAGE));
    MEMCPY_DN(EDCDATA->STDDEV, EDCDATA_N->STDDEV, sizeof(EDCDATA->STDDEV));
    MEMCPY_DN(EDCDATA->RANGE, EDCDATA_N->RANGE, sizeof(EDCDATA->RANGE));
    MEMCPY_DN(EDCDATA->MIN_VALUE, EDCDATA_N->MIN_VALUE, sizeof(EDCDATA->MIN_VALUE));
    MEMCPY_DN(EDCDATA->MAX_VALUE, EDCDATA_N->MAX_VALUE, sizeof(EDCDATA->MAX_VALUE));
    EDCDATA->OOC_TYPE = EDCDATA_N->OOC_TYPE[0];
    EDCDATA->OOC_TYPE2 = EDCDATA_N->OOC_TYPE2[0];
    EDCDATA->EXCLUDE_FLAG = EDCDATA_N->EXCLUDE_FLAG[0];
    EDCDATA->CAL_VAL_CNT = EDCDATA_N->CAL_VAL_CNT;
    MEMCPY_DN(EDCDATA->USL, EDCDATA_N->USL, sizeof(EDCDATA->USL));
    MEMCPY_DN(EDCDATA->TARGET, EDCDATA_N->TARGET, sizeof(EDCDATA->TARGET));
    MEMCPY_DN(EDCDATA->LSL, EDCDATA_N->LSL, sizeof(EDCDATA->LSL));
    MEMCPY_DN(EDCDATA->UCL, EDCDATA_N->UCL, sizeof(EDCDATA->UCL));
    MEMCPY_DN(EDCDATA->CL, EDCDATA_N->CL, sizeof(EDCDATA->CL));
    MEMCPY_DN(EDCDATA->LCL, EDCDATA_N->LCL, sizeof(EDCDATA->LCL));
    MEMCPY_DN(EDCDATA->UCL2, EDCDATA_N->UCL2, sizeof(EDCDATA->UCL2));
    MEMCPY_DN(EDCDATA->CL2, EDCDATA_N->CL2, sizeof(EDCDATA->CL2));
    MEMCPY_DN(EDCDATA->LCL2, EDCDATA_N->LCL2, sizeof(EDCDATA->LCL2));
    MEMCPY_DN(EDCDATA->CHART_ID, EDCDATA_N->CHART_ID, sizeof(EDCDATA->CHART_ID));
    EDCDATA->CAL_HIST_SEQ = EDCDATA_N->CAL_HIST_SEQ;
     
}


