
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
    "DBU_cqcmispdat.pc"
};


static unsigned int sqlctx = 9377099;


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
            void  *sqhstv[65];
   unsigned int   sqhstl[65];
            int   sqhsts[65];
            void  *sqindv[65];
            int   sqinds[65];
   unsigned int   sqharm[65];
   unsigned int   *sqharc[65];
   unsigned short  sqadto[65];
   unsigned short  sqtdso[65];
} sqlstm = {13,65};

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

 static const char *sq0019 = 
"select FACTORY ,INSP_ID ,COL_SET_ID ,COL_SET_VER ,INSP_SEQ ,CHAR_ID ,CHAR_S\
EQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,\
VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALU\
E_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,V\
ALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_C\
OUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE_TYPE ,INSP_JUDGE_TIME ,RWK_F\
LOW ,RWK_OPER ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 \
,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CQCMI\
SPDAT  order by FACTORY asc ,INSP_ID asc ,COL_SET_ID asc ,INSP_SEQ asc ,UNIT_\
SEQ asc ,VALUE_SEQ asc             ";

 static const char *sq0020 = 
"select A.CHAR_ID ,A.VALUE_1 ,count(*)  SAMPLE_COUNT  from CQCMISPDAT A ,CQC\
MISPDAT B where (((((((((((((A.FACTORY=B.FACTORY and A.COL_SET_ID=B.COL_SET_I\
D) and A.COL_SET_VER=B.COL_SET_VER) and A.INSP_ID=B.INSP_ID) and B.INSP_SEQ=1\
) and B.CHAR_ID='JUDGE_REWORK') and B.VALUE_1='N') and A.UNIT_SEQ=B.UNIT_SEQ)\
 and A.FACTORY=:b0) and A.INSP_ID=:b1) and A.COL_SET_ID=:b2) and A.INSP_SEQ=1\
) and A.CHAR_ID='JUDGE_LOSS') and A.VALUE_1>' ') group by A.CHAR_ID,A.VALUE_1\
           ";

 static const char *sq0021 = 
"select VALUE_1 ,count(*)  CNT  from CQCMISPDAT where ((((((FACTORY=:b0 and \
INSP_ID=:b1) and COL_SET_ID=:b2) and COL_SET_VER=(select max(COL_SET_VER)  fr\
om CQCMISPDAT where ((FACTORY=:b0 and INSP_ID=:b1) and COL_SET_ID=:b2))) and \
INSP_SEQ=:b6) and CHAR_ID=:b7) and VALUE_1>' ') group by VALUE_1           ";

 static const char *sq0022 = 
"SP_ID=:b1) and INSP_DTL_TYPE='COATIN\
G') and INSP_COUNT=1)) B ) X where (((A.CHAR_ID=X.CHAR_ID(+) and A.FACTORY=:b\
0) and A.COL_SET_ID=:b27) and A.COL_SET_VERSION=(select max(COL_SET_VERSION) \
 from MEDCCOLVER where ((FACTORY=:b0 and COL_SET_ID=:b27) and RELEASE_FLAG='Y\
'))) order by A.SEQ_NUM            ";

 static const char *sq0023 = 
"select FACTORY ,INSP_ID ,COL_SET_ID ,COL_SET_VER ,INSP_SEQ ,CHAR_ID ,CHAR_S\
EQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,\
VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALU\
E_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,V\
ALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_C\
OUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE_TYPE ,INSP_JUDGE_TIME ,RWK_F\
LOW ,RWK_OPER ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 \
,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CQCMI\
SPDAT A where ((FACTORY=:b0 and INSP_ID=:b1) and INSP_SEQ=(select max(INSP_SE\
Q)  from CQCMISPDAT where (FACTORY=:b0 and INSP_ID=:b1)))           ";

 static const char *sq0024 = 
"select FACTORY ,INSP_ID ,COL_SET_ID ,COL_SET_VER ,INSP_SEQ ,CHAR_ID ,CHAR_S\
EQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,\
VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALU\
E_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,V\
ALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_C\
OUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE_TYPE ,INSP_JUDGE_TIME ,RWK_F\
LOW ,RWK_OPER ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 \
,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CQCMI\
SPDAT A where ((FACTORY=:b0 and INSP_ID=:b1) and INSP_SEQ=(select max(INSP_SE\
Q)  from CQCMISPDAT where (FACTORY=:b0 and INSP_ID=:b1)))           ";

 static const char *sq0025 = 
"select FACTORY ,INSP_ID ,COL_SET_ID ,COL_SET_VER ,INSP_SEQ ,CHAR_ID ,CHAR_S\
EQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VALUE_COUNT ,VALUE_1 ,VALUE_2 ,\
VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9 ,VALUE_10 ,VALU\
E_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALUE_17 ,VALUE_18 ,V\
ALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,VALUE_25 ,SAMPLE_C\
OUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE_TYPE ,INSP_JUDGE_TIME ,RWK_F\
LOW ,RWK_OPER ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,CMF_7 ,CMF_8 ,CMF_9 \
,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from CQCMI\
SPDAT A where (FACTORY=:b0 and INSP_ID=:b1)           ";

 static const char *sq0026 = 
"elect 'REAL-D' CHAR_ID ,(OUTER_DIAME\
TER_1-1) VALUE_1 ,(OUTER_DIAMETER_2-1) VALUE_2 ,null  VALUE_3 ,null  VALUE_4 \
,null  VALUE_5 ,null  VALUE_6 ,null  VALUE_7 ,null  VALUE_8 ,null  VALUE_9 ,n\
ull  VALUE_10 ,null  VALUE_11 ,null  VALUE_12 ,null  VALUE_13  from cwiplotrn\
d where (lot_id=:b0 and hist_seq=:b1)) B ,MEDCCHRDEF C where (((A.CHAR_ID=B.C\
HAR_ID and A.COL_SET_ID=(select COL_SET_ID  from MEDCCOLDEF where COL_CMF_2='\
A')) and A.FACTORY=C.FACTORY) and A.CHAR_ID=C.CHAR_ID) order by A.SEQ_NUM    \
        ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1038,0,4,46,0,0,65,7,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
280,0,0,2,1050,0,4,208,0,0,65,7,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
555,0,0,3,176,0,4,373,0,0,8,7,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,
602,0,0,4,99,0,4,386,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
633,0,0,5,405,0,4,395,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
664,0,0,6,177,0,4,416,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
695,0,0,7,78,0,4,429,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
722,0,0,8,122,0,4,437,0,0,5,4,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
757,0,0,9,100,0,4,447,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
788,0,0,10,78,0,4,456,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
815,0,0,11,105,0,4,464,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
842,0,0,12,158,0,2,502,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,
885,0,0,13,60,0,2,513,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
908,0,0,14,104,0,2,519,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
939,0,0,15,82,0,2,527,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
966,0,0,16,613,0,3,558,0,0,41,41,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,
1145,0,0,17,883,0,5,665,0,0,58,58,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,
1392,0,0,18,627,0,5,727,0,0,40,40,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,
1567,0,0,19,726,0,9,865,0,0,0,0,0,1,0,
1582,0,0,20,471,0,9,889,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
1609,0,0,21,304,0,9,909,0,0,8,8,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,
0,1,0,0,0,1,3,0,0,1,97,0,0,
1656,0,0,22,4398,0,9,1129,0,0,30,30,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,1,
0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,
0,1,0,0,0,1,0,0,0,1,0,0,0,1,97,0,0,1,0,0,0,1,0,0,0,
1791,0,0,23,759,0,9,1201,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,
1822,0,0,24,759,0,9,1274,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,
1853,0,0,25,668,0,9,1342,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1876,0,0,26,2554,0,9,1451,0,0,8,8,0,1,0,1,97,0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,0,0,
0,1,0,0,0,1,0,0,0,1,0,0,0,
1923,0,0,19,0,0,13,1479,0,0,58,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
2170,0,0,20,0,0,13,1541,0,0,3,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,
2197,0,0,21,0,0,13,1548,0,0,2,0,0,1,0,2,97,0,0,2,3,0,0,
2220,0,0,22,0,0,13,1554,0,0,56,0,0,1,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2459,0,0,23,0,0,13,1614,0,0,58,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
2706,0,0,24,0,0,13,1676,0,0,58,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
2953,0,0,25,0,0,13,1738,0,0,58,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,
3200,0,0,26,0,0,13,1800,0,0,18,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3287,0,0,19,0,0,15,1847,0,0,0,0,0,1,0,
3302,0,0,20,0,0,15,1851,0,0,0,0,0,1,0,
3317,0,0,21,0,0,15,1855,0,0,0,0,0,1,0,
3332,0,0,22,0,0,15,1859,0,0,0,0,0,1,0,
3347,0,0,23,0,0,15,1863,0,0,0,0,0,1,0,
3362,0,0,24,0,0,15,1867,0,0,0,0,0,1,0,
3377,0,0,25,0,0,15,1871,0,0,0,0,0,1,0,
3392,0,0,26,0,0,15,1875,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_cqcmispdat.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-09-07 08:55:58
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
void DBU_add_null_cqcmispdat(struct CQCMISPDAT_N_TAG *CQCMISPDAT_N, struct CQCMISPDAT_TAG *CQCMISPDAT);
void DBU_del_null_cqcmispdat(struct CQCMISPDAT_N_TAG *CQCMISPDAT_N, struct CQCMISPDAT_TAG *CQCMISPDAT);


/* SQL SELECT Function */
void DBU_select_cqcmispdat(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    INSP_SEQ,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
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
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RWK_FLOW,
                    RWK_OPER,
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
                    :CQCMISPDAT_N.FACTORY,
                    :CQCMISPDAT_N.INSP_ID,
                    :CQCMISPDAT_N.COL_SET_ID,
                    :CQCMISPDAT_N.COL_SET_VER,
                    :CQCMISPDAT_N.INSP_SEQ,
                    :CQCMISPDAT_N.CHAR_ID,
                    :CQCMISPDAT_N.CHAR_SEQ,
                    :CQCMISPDAT_N.UNIT_SEQ,
                    :CQCMISPDAT_N.VALUE_SEQ,
                    :CQCMISPDAT_N.UNIT_ID,
                    :CQCMISPDAT_N.VALUE_TYPE,
                    :CQCMISPDAT_N.VALUE_COUNT,
                    :CQCMISPDAT_N.VALUE_1,
                    :CQCMISPDAT_N.VALUE_2,
                    :CQCMISPDAT_N.VALUE_3,
                    :CQCMISPDAT_N.VALUE_4,
                    :CQCMISPDAT_N.VALUE_5,
                    :CQCMISPDAT_N.VALUE_6,
                    :CQCMISPDAT_N.VALUE_7,
                    :CQCMISPDAT_N.VALUE_8,
                    :CQCMISPDAT_N.VALUE_9,
                    :CQCMISPDAT_N.VALUE_10,
                    :CQCMISPDAT_N.VALUE_11,
                    :CQCMISPDAT_N.VALUE_12,
                    :CQCMISPDAT_N.VALUE_13,
                    :CQCMISPDAT_N.VALUE_14,
                    :CQCMISPDAT_N.VALUE_15,
                    :CQCMISPDAT_N.VALUE_16,
                    :CQCMISPDAT_N.VALUE_17,
                    :CQCMISPDAT_N.VALUE_18,
                    :CQCMISPDAT_N.VALUE_19,
                    :CQCMISPDAT_N.VALUE_20,
                    :CQCMISPDAT_N.VALUE_21,
                    :CQCMISPDAT_N.VALUE_22,
                    :CQCMISPDAT_N.VALUE_23,
                    :CQCMISPDAT_N.VALUE_24,
                    :CQCMISPDAT_N.VALUE_25,
                    :CQCMISPDAT_N.SAMPLE_COUNT,
                    :CQCMISPDAT_N.SPEC_OUT_MASK,
                    :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                    :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                    :CQCMISPDAT_N.INSP_JUDGE_TIME,
                    :CQCMISPDAT_N.RWK_FLOW,
                    :CQCMISPDAT_N.RWK_OPER,
                    :CQCMISPDAT_N.CMF_1,
                    :CQCMISPDAT_N.CMF_2,
                    :CQCMISPDAT_N.CMF_3,
                    :CQCMISPDAT_N.CMF_4,
                    :CQCMISPDAT_N.CMF_5,
                    :CQCMISPDAT_N.CMF_6,
                    :CQCMISPDAT_N.CMF_7,
                    :CQCMISPDAT_N.CMF_8,
                    :CQCMISPDAT_N.CMF_9,
                    :CQCMISPDAT_N.CMF_10,
                    :CQCMISPDAT_N.CREATE_USER_ID,
                    :CQCMISPDAT_N.CREATE_TIME,
                    :CQCMISPDAT_N.UPDATE_USER_ID,
                    :CQCMISPDAT_N.UPDATE_TIME
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
					AND CHAR_SEQ =:CQCMISPDAT_N.CHAR_SEQ
                    AND UNIT_SEQ = :CQCMISPDAT_N.UNIT_SEQ
                    AND VALUE_SEQ = :CQCMISPDAT_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,INSP_ID ,COL_SET_ID ,COL_SET_VER ,INSP_SEQ ,C\
HAR_ID ,CHAR_SEQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VALUE_COUNT ,VAL\
UE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9\
 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALU\
E_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,\
VALUE_25 ,SAMPLE_COUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE_TYPE ,INS\
P_JUDGE_TIME ,RWK_FLOW ,RWK_OPER ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,\
CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UP\
DATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:\
b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b\
29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b4\
4,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57  from CQC\
MISPDAT where ((((((FACTORY=:b0 and INSP_ID=:b1) and COL_SET_ID=:b2) and INS\
P_SEQ=:b4) and CHAR_SEQ=:b6) and UNIT_SEQ=:b7) and ");
            sqlstm.stmt = "VALUE_SEQ=:b8)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )51;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[60] = (unsigned int  )26;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[63] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
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
        DBU_del_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    }

    DB_stop_query_timer("DBU_select_cqcmispdat", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_cqcmispdat_for_update(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    INSP_SEQ,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
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
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RWK_FLOW,
                    RWK_OPER,
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
                    :CQCMISPDAT_N.FACTORY,
                    :CQCMISPDAT_N.INSP_ID,
                    :CQCMISPDAT_N.COL_SET_ID,
                    :CQCMISPDAT_N.COL_SET_VER,
                    :CQCMISPDAT_N.INSP_SEQ,
                    :CQCMISPDAT_N.CHAR_ID,
                    :CQCMISPDAT_N.CHAR_SEQ,
                    :CQCMISPDAT_N.UNIT_SEQ,
                    :CQCMISPDAT_N.VALUE_SEQ,
                    :CQCMISPDAT_N.UNIT_ID,
                    :CQCMISPDAT_N.VALUE_TYPE,
                    :CQCMISPDAT_N.VALUE_COUNT,
                    :CQCMISPDAT_N.VALUE_1,
                    :CQCMISPDAT_N.VALUE_2,
                    :CQCMISPDAT_N.VALUE_3,
                    :CQCMISPDAT_N.VALUE_4,
                    :CQCMISPDAT_N.VALUE_5,
                    :CQCMISPDAT_N.VALUE_6,
                    :CQCMISPDAT_N.VALUE_7,
                    :CQCMISPDAT_N.VALUE_8,
                    :CQCMISPDAT_N.VALUE_9,
                    :CQCMISPDAT_N.VALUE_10,
                    :CQCMISPDAT_N.VALUE_11,
                    :CQCMISPDAT_N.VALUE_12,
                    :CQCMISPDAT_N.VALUE_13,
                    :CQCMISPDAT_N.VALUE_14,
                    :CQCMISPDAT_N.VALUE_15,
                    :CQCMISPDAT_N.VALUE_16,
                    :CQCMISPDAT_N.VALUE_17,
                    :CQCMISPDAT_N.VALUE_18,
                    :CQCMISPDAT_N.VALUE_19,
                    :CQCMISPDAT_N.VALUE_20,
                    :CQCMISPDAT_N.VALUE_21,
                    :CQCMISPDAT_N.VALUE_22,
                    :CQCMISPDAT_N.VALUE_23,
                    :CQCMISPDAT_N.VALUE_24,
                    :CQCMISPDAT_N.VALUE_25,
                    :CQCMISPDAT_N.SAMPLE_COUNT,
                    :CQCMISPDAT_N.SPEC_OUT_MASK,
                    :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                    :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                    :CQCMISPDAT_N.INSP_JUDGE_TIME,
                    :CQCMISPDAT_N.RWK_FLOW,
                    :CQCMISPDAT_N.RWK_OPER,
                    :CQCMISPDAT_N.CMF_1,
                    :CQCMISPDAT_N.CMF_2,
                    :CQCMISPDAT_N.CMF_3,
                    :CQCMISPDAT_N.CMF_4,
                    :CQCMISPDAT_N.CMF_5,
                    :CQCMISPDAT_N.CMF_6,
                    :CQCMISPDAT_N.CMF_7,
                    :CQCMISPDAT_N.CMF_8,
                    :CQCMISPDAT_N.CMF_9,
                    :CQCMISPDAT_N.CMF_10,
                    :CQCMISPDAT_N.CREATE_USER_ID,
                    :CQCMISPDAT_N.CREATE_TIME,
                    :CQCMISPDAT_N.UPDATE_USER_ID,
                    :CQCMISPDAT_N.UPDATE_TIME
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
					AND CHAR_SEQ =:CQCMISPDAT_N.CHAR_SEQ
                    AND UNIT_SEQ = :CQCMISPDAT_N.UNIT_SEQ
                    AND VALUE_SEQ = :CQCMISPDAT_N.VALUE_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,INSP_ID ,COL_SET_ID ,COL_SET_VER ,INSP_SEQ ,C\
HAR_ID ,CHAR_SEQ ,UNIT_SEQ ,VALUE_SEQ ,UNIT_ID ,VALUE_TYPE ,VALUE_COUNT ,VAL\
UE_1 ,VALUE_2 ,VALUE_3 ,VALUE_4 ,VALUE_5 ,VALUE_6 ,VALUE_7 ,VALUE_8 ,VALUE_9\
 ,VALUE_10 ,VALUE_11 ,VALUE_12 ,VALUE_13 ,VALUE_14 ,VALUE_15 ,VALUE_16 ,VALU\
E_17 ,VALUE_18 ,VALUE_19 ,VALUE_20 ,VALUE_21 ,VALUE_22 ,VALUE_23 ,VALUE_24 ,\
VALUE_25 ,SAMPLE_COUNT ,SPEC_OUT_MASK ,INSP_JUDGE_FLAG ,INSP_JUDGE_TYPE ,INS\
P_JUDGE_TIME ,RWK_FLOW ,RWK_OPER ,CMF_1 ,CMF_2 ,CMF_3 ,CMF_4 ,CMF_5 ,CMF_6 ,\
CMF_7 ,CMF_8 ,CMF_9 ,CMF_10 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UP\
DATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:\
b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b\
29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b4\
4,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57  from CQC\
MISPDAT where ((((((FACTORY=:b0 and INSP_ID=:b1) and COL_SET_ID=:b2) and INS\
P_SEQ=:b4) and CHAR_SEQ=:b6) and UNIT_SEQ=:b7) and ");
            sqlstm.stmt = "VALUE_SEQ=:b8) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )280;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )51;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[58] = (unsigned int  )11;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[60] = (unsigned int  )26;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[61] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[62] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[63] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[64] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
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
        DBU_del_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    }

    DB_stop_query_timer("DBU_select_cqcmispdat_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_cqcmispdat_scalar(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
					AND CHAR_SEQ = :CQCMISPDAT_N.CHAR_SEQ
                    AND UNIT_SEQ = :CQCMISPDAT_N.UNIT_SEQ
                    AND VALUE_SEQ = :CQCMISPDAT_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 ((((((FACTORY=:b1 and INSP_ID=:b2) and COL_SET_ID=:b3) and INSP_SEQ=:b4) and\
 CHAR_SEQ=:b5) and UNIT_SEQ=:b6) and VALUE_SEQ=:b7)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )555;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
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
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 ((FACTORY=:b1 and INSP_ID=:b2) and COL_SET_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )602;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
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

		case 3:
            /* EXEC SQL SELECT COUNT(*)
						  INTO :d_value
						  FROM CQCMISPDAT A, CQCMISPDAT B
						 WHERE A.FACTORY = B.FACTORY
						   AND A.COL_SET_ID = B.COL_SET_ID
						   AND A.COL_SET_VER = B.COL_SET_VER
						   AND A.INSP_ID = B.INSP_ID
						   AND B.INSP_SEQ = 1
						   AND B.CHAR_ID = 'JUDGE_REWORK'
						   AND B.VALUE_1 = 'N'
						   AND A.UNIT_SEQ = B.UNIT_SEQ 
						   AND A.FACTORY = :CQCMISPDAT_N.FACTORY
						   AND A.INSP_ID = :CQCMISPDAT_N.INSP_ID
						   AND A.COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
						  /o AND A.COL_SET_VER = 1 o/ /o이거 외 걸어놨었는지는 모르겠음..문제안될거 같아 일단 제거(21/07/05)o/
						   AND A.INSP_SEQ = 1
						   AND A.CHAR_ID = 'JUDGE_LOSS' 
						   AND A.VALUE_1 > ' ' ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT A ,CQ\
CMISPDAT B where (((((((((((((A.FACTORY=B.FACTORY and A.COL_SET_ID=B.COL_SET_\
ID) and A.COL_SET_VER=B.COL_SET_VER) and A.INSP_ID=B.INSP_ID) and B.INSP_SEQ=\
1) and B.CHAR_ID='JUDGE_REWORK') and B.VALUE_1='N') and A.UNIT_SEQ=B.UNIT_SEQ\
) and A.FACTORY=:b1) and A.INSP_ID=:b2) and A.COL_SET_ID=:b3) and A.INSP_SEQ=\
1) and A.CHAR_ID='JUDGE_LOSS') and A.VALUE_1>' ')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )633;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
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
            /* EXEC SQL SELECT COUNT(*) 
							   INTO :d_value
						    FROM CQCMISPDAT A
						  WHERE A.FACTORY = :CQCMISPDAT_N.FACTORY
							   AND A.INSP_ID = :CQCMISPDAT_N.INSP_ID
							   AND A.COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
							   /o AND A.COL_SET_VER = 1 o/ /o이거 외 걸어놨었는지는 모르겠음..문제안될거 같아 일단 제거(21/07/05)o/
							   AND A.INSP_SEQ = 1
							   AND A.CHAR_ID = 'JUDGE_REWORK' 
							   AND A.VALUE_1 = 'Y'; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT A whe\
re (((((A.FACTORY=:b1 and A.INSP_ID=:b2) and A.COL_SET_ID=:b3) and A.INSP_SEQ\
=1) and A.CHAR_ID='JUDGE_REWORK') and A.VALUE_1='Y')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )664;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
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

		case 5:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 (FACTORY=:b1 and INSP_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )695;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
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

		case 6:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
					AND COL_SET_VER != :CQCMISPDAT_N.COL_SET_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 (((FACTORY=:b1 and INSP_ID=:b2) and COL_SET_ID=:b3) and COL_SET_VER<>:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )722;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
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

		case 7:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID != :CQCMISPDAT_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 ((FACTORY=:b1 and INSP_ID=:b2) and COL_SET_ID<>:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )757;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
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

		case 8:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 (FACTORY=:b1 and INSP_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )788;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
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

		case 9:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
					AND CHAR_ID = 'JUDGE_PASS'; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from CQCMISPDAT where\
 ((FACTORY=:b1 and INSP_ID=:b2) and CHAR_ID='JUDGE_PASS')";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )815;
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
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.INSP_ID);
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

    DB_stop_query_timer("DBU_select_cqcmispdat_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_cqcmispdat(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
					AND CHAR_SEQ =:CQCMISPDAT_N.CHAR_SEQ
                    AND UNIT_SEQ = :CQCMISPDAT_N.UNIT_SEQ
                    AND VALUE_SEQ = :CQCMISPDAT_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMISPDAT  where ((((((FACTORY=:b0\
 and INSP_ID=:b1) and COL_SET_ID=:b2) and INSP_SEQ=:b3) and CHAR_SEQ=:b4) and\
 UNIT_SEQ=:b5) and VALUE_SEQ=:b6)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )842;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
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

		 case 2:
            /* EXEC SQL DELETE FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMISPDAT  where (FACTORY=:b0 and \
INSP_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )885;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
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
            if (sqlca.sqlcode == 1403) DB_usr_error();
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 3:
            /* EXEC SQL DELETE FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
					AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
					AND COL_SET_VER != :CQCMISPDAT_N.COL_SET_VER; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMISPDAT  where (((FACTORY=:b0 an\
d INSP_ID=:b1) and COL_SET_ID=:b2) and COL_SET_VER<>:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )908;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
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

		case 4:
            /* EXEC SQL DELETE FROM CQCMISPDAT
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
					AND COL_SET_ID != :CQCMISPDAT_N.COL_SET_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from CQCMISPDAT  where ((FACTORY=:b0 and\
 INSP_ID=:b1) and COL_SET_ID<>:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )939;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
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

    DB_stop_query_timer("DBU_delete_cqcmispdat", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_cqcmispdat(struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO CQCMISPDAT( 
                    FACTORY, 
                    INSP_ID, 
                    COL_SET_ID, 
                    COL_SET_VER, 
                    INSP_SEQ, 
                    CHAR_ID, 
                    CHAR_SEQ, 
                    UNIT_SEQ, 
                    VALUE_SEQ, 
                    UNIT_ID, 
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
                    SPEC_OUT_MASK, 
                    CREATE_USER_ID, 
                    CREATE_TIME
         ) 
        VALUES (
                    :CQCMISPDAT_N.FACTORY,
                    :CQCMISPDAT_N.INSP_ID,
                    :CQCMISPDAT_N.COL_SET_ID,
                    :CQCMISPDAT_N.COL_SET_VER,
                    :CQCMISPDAT_N.INSP_SEQ,
                    :CQCMISPDAT_N.CHAR_ID,
                    :CQCMISPDAT_N.CHAR_SEQ,
                    :CQCMISPDAT_N.UNIT_SEQ,
                    :CQCMISPDAT_N.VALUE_SEQ,
                    :CQCMISPDAT_N.UNIT_ID,
                    :CQCMISPDAT_N.VALUE_TYPE,
                    :CQCMISPDAT_N.VALUE_COUNT,
                    :CQCMISPDAT_N.VALUE_1,
                    :CQCMISPDAT_N.VALUE_2,
                    :CQCMISPDAT_N.VALUE_3,
                    :CQCMISPDAT_N.VALUE_4,
                    :CQCMISPDAT_N.VALUE_5,
                    :CQCMISPDAT_N.VALUE_6,
                    :CQCMISPDAT_N.VALUE_7,
                    :CQCMISPDAT_N.VALUE_8,
                    :CQCMISPDAT_N.VALUE_9,
                    :CQCMISPDAT_N.VALUE_10,
                    :CQCMISPDAT_N.VALUE_11,
                    :CQCMISPDAT_N.VALUE_12,
                    :CQCMISPDAT_N.VALUE_13,
                    :CQCMISPDAT_N.VALUE_14,
                    :CQCMISPDAT_N.VALUE_15,
                    :CQCMISPDAT_N.VALUE_16,
                    :CQCMISPDAT_N.VALUE_17,
                    :CQCMISPDAT_N.VALUE_18,
                    :CQCMISPDAT_N.VALUE_19,
                    :CQCMISPDAT_N.VALUE_20,
                    :CQCMISPDAT_N.VALUE_21,
                    :CQCMISPDAT_N.VALUE_22,
                    :CQCMISPDAT_N.VALUE_23,
                    :CQCMISPDAT_N.VALUE_24,
                    :CQCMISPDAT_N.VALUE_25,
                    :CQCMISPDAT_N.SAMPLE_COUNT,
                    :CQCMISPDAT_N.SPEC_OUT_MASK,
                    :CQCMISPDAT_N.CREATE_USER_ID,
                    :CQCMISPDAT_N.CREATE_TIME
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 65;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into CQCMISPDAT (FACTORY,INSP_ID,COL_SET_ID,COL_S\
ET_VER,INSP_SEQ,CHAR_ID,CHAR_SEQ,UNIT_SEQ,VALUE_SEQ,UNIT_ID,VALUE_TYPE,VALUE_\
COUNT,VALUE_1,VALUE_2,VALUE_3,VALUE_4,VALUE_5,VALUE_6,VALUE_7,VALUE_8,VALUE_9\
,VALUE_10,VALUE_11,VALUE_12,VALUE_13,VALUE_14,VALUE_15,VALUE_16,VALUE_17,VALU\
E_18,VALUE_19,VALUE_20,VALUE_21,VALUE_22,VALUE_23,VALUE_24,VALUE_25,SAMPLE_CO\
UNT,SPEC_OUT_MASK,CREATE_USER_ID,CREATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5\
,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,\
:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b\
37,:b38,:b39,:b40)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )966;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
    sqlstm.sqhstl[1] = (unsigned int  )31;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
    sqlstm.sqhstl[2] = (unsigned int  )26;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
    sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
    sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
    sqlstm.sqhstl[5] = (unsigned int  )26;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
    sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
    sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
    sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
    sqlstm.sqhstl[9] = (unsigned int  )51;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
    sqlstm.sqhstl[10] = (unsigned int  )2;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
    sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
    sqlstm.sqhstl[12] = (unsigned int  )26;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
    sqlstm.sqhstl[13] = (unsigned int  )26;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
    sqlstm.sqhstl[14] = (unsigned int  )26;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
    sqlstm.sqhstl[15] = (unsigned int  )26;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
    sqlstm.sqhstl[16] = (unsigned int  )26;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
    sqlstm.sqhstl[17] = (unsigned int  )26;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
    sqlstm.sqhstl[18] = (unsigned int  )26;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
    sqlstm.sqhstl[19] = (unsigned int  )26;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
    sqlstm.sqhstl[20] = (unsigned int  )26;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
    sqlstm.sqhstl[21] = (unsigned int  )26;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
    sqlstm.sqhstl[22] = (unsigned int  )26;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
    sqlstm.sqhstl[23] = (unsigned int  )26;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
    sqlstm.sqhstl[24] = (unsigned int  )26;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
    sqlstm.sqhstl[25] = (unsigned int  )26;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
    sqlstm.sqhstl[26] = (unsigned int  )26;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
    sqlstm.sqhstl[27] = (unsigned int  )26;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
    sqlstm.sqhstl[28] = (unsigned int  )26;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
    sqlstm.sqhstl[29] = (unsigned int  )26;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
    sqlstm.sqhstl[30] = (unsigned int  )26;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
    sqlstm.sqhstl[31] = (unsigned int  )26;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
    sqlstm.sqhstl[32] = (unsigned int  )26;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
    sqlstm.sqhstl[33] = (unsigned int  )26;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
    sqlstm.sqhstl[34] = (unsigned int  )26;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
    sqlstm.sqhstl[35] = (unsigned int  )26;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
    sqlstm.sqhstl[36] = (unsigned int  )26;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
    sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
    sqlstm.sqhstl[38] = (unsigned int  )26;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
    sqlstm.sqhstl[39] = (unsigned int  )21;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
    sqlstm.sqhstl[40] = (unsigned int  )15;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_cqcmispdat", 0);
}


/* SQL UPDATE Function */
void DBU_update_cqcmispdat(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE CQCMISPDAT SET
                    COL_SET_VER = :CQCMISPDAT_N.COL_SET_VER,
                    CHAR_ID = :CQCMISPDAT_N.CHAR_ID,
                    UNIT_ID = :CQCMISPDAT_N.UNIT_ID,
                    VALUE_TYPE = :CQCMISPDAT_N.VALUE_TYPE,
                    VALUE_COUNT = :CQCMISPDAT_N.VALUE_COUNT,
                    VALUE_1 = :CQCMISPDAT_N.VALUE_1,
                    VALUE_2 = :CQCMISPDAT_N.VALUE_2,
                    VALUE_3 = :CQCMISPDAT_N.VALUE_3,
                    VALUE_4 = :CQCMISPDAT_N.VALUE_4,
                    VALUE_5 = :CQCMISPDAT_N.VALUE_5,
                    VALUE_6 = :CQCMISPDAT_N.VALUE_6,
                    VALUE_7 = :CQCMISPDAT_N.VALUE_7,
                    VALUE_8 = :CQCMISPDAT_N.VALUE_8,
                    VALUE_9 = :CQCMISPDAT_N.VALUE_9,
                    VALUE_10 = :CQCMISPDAT_N.VALUE_10,
                    VALUE_11 = :CQCMISPDAT_N.VALUE_11,
                    VALUE_12 = :CQCMISPDAT_N.VALUE_12,
                    VALUE_13 = :CQCMISPDAT_N.VALUE_13,
                    VALUE_14 = :CQCMISPDAT_N.VALUE_14,
                    VALUE_15 = :CQCMISPDAT_N.VALUE_15,
                    VALUE_16 = :CQCMISPDAT_N.VALUE_16,
                    VALUE_17 = :CQCMISPDAT_N.VALUE_17,
                    VALUE_18 = :CQCMISPDAT_N.VALUE_18,
                    VALUE_19 = :CQCMISPDAT_N.VALUE_19,
                    VALUE_20 = :CQCMISPDAT_N.VALUE_20,
                    VALUE_21 = :CQCMISPDAT_N.VALUE_21,
                    VALUE_22 = :CQCMISPDAT_N.VALUE_22,
                    VALUE_23 = :CQCMISPDAT_N.VALUE_23,
                    VALUE_24 = :CQCMISPDAT_N.VALUE_24,
                    VALUE_25 = :CQCMISPDAT_N.VALUE_25,
                    SAMPLE_COUNT = :CQCMISPDAT_N.SAMPLE_COUNT,
                    SPEC_OUT_MASK = :CQCMISPDAT_N.SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG = :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE = :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME = :CQCMISPDAT_N.INSP_JUDGE_TIME,
                    RWK_FLOW = :CQCMISPDAT_N.RWK_FLOW,
                    RWK_OPER = :CQCMISPDAT_N.RWK_OPER,
                    CMF_1 = :CQCMISPDAT_N.CMF_1,
                    CMF_2 = :CQCMISPDAT_N.CMF_2,
                    CMF_3 = :CQCMISPDAT_N.CMF_3,
                    CMF_4 = :CQCMISPDAT_N.CMF_4,
                    CMF_5 = :CQCMISPDAT_N.CMF_5,
                    CMF_6 = :CQCMISPDAT_N.CMF_6,
                    CMF_7 = :CQCMISPDAT_N.CMF_7,
                    CMF_8 = :CQCMISPDAT_N.CMF_8,
                    CMF_9 = :CQCMISPDAT_N.CMF_9,
                    CMF_10 = :CQCMISPDAT_N.CMF_10,
                    CREATE_USER_ID = :CQCMISPDAT_N.CREATE_USER_ID,
                    CREATE_TIME = :CQCMISPDAT_N.CREATE_TIME,
                    UPDATE_USER_ID = :CQCMISPDAT_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMISPDAT_N.UPDATE_TIME
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
					AND CHAR_SEQ = :CQCMISPDAT_N.CHAR_SEQ
                    AND UNIT_SEQ = :CQCMISPDAT_N.UNIT_SEQ
                    AND VALUE_SEQ = :CQCMISPDAT_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CQCMISPDAT  set COL_SET_VER=:b0,CHAR_ID=:\
b1,UNIT_ID=:b2,VALUE_TYPE=:b3,VALUE_COUNT=:b4,VALUE_1=:b5,VALUE_2=:b6,VALUE_3\
=:b7,VALUE_4=:b8,VALUE_5=:b9,VALUE_6=:b10,VALUE_7=:b11,VALUE_8=:b12,VALUE_9=:\
b13,VALUE_10=:b14,VALUE_11=:b15,VALUE_12=:b16,VALUE_13=:b17,VALUE_14=:b18,VAL\
UE_15=:b19,VALUE_16=:b20,VALUE_17=:b21,VALUE_18=:b22,VALUE_19=:b23,VALUE_20=:\
b24,VALUE_21=:b25,VALUE_22=:b26,VALUE_23=:b27,VALUE_24=:b28,VALUE_25=:b29,SAM\
PLE_COUNT=:b30,SPEC_OUT_MASK=:b31,INSP_JUDGE_FLAG=:b32,INSP_JUDGE_TYPE=:b33,I\
NSP_JUDGE_TIME=:b34,RWK_FLOW=:b35,RWK_OPER=:b36,CMF_1=:b37,CMF_2=:b38,CMF_3=:\
b39,CMF_4=:b40,CMF_5=:b41,CMF_6=:b42,CMF_7=:b43,CMF_8=:b44,CMF_9=:b45,CMF_10=\
:b46,CREATE_USER_ID=:b47,CREATE_TIME=:b48,UPDATE_USER_ID=:b49,UPDATE_TIME=:b5\
0 where ((((((FACTORY=:b51 and INSP_ID=:b52) and COL_SET_ID=:b53) and INSP_SE\
Q=:b54) and CHAR_SEQ=:b55) and UNIT_SEQ=:b56) and VALUE_SEQ=:b57)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1145;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[10] = (unsigned int  )26;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[30] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[35] = (unsigned int  )21;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[36] = (unsigned int  )11;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[37] = (unsigned int  )51;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[38] = (unsigned int  )51;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[39] = (unsigned int  )51;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[40] = (unsigned int  )51;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[41] = (unsigned int  )51;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[47] = (unsigned int  )21;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[48] = (unsigned int  )15;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[49] = (unsigned int  )21;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[50] = (unsigned int  )15;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[53] = (unsigned int  )26;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
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

		case 2:
            /* EXEC SQL UPDATE CQCMISPDAT SET
                    CHAR_ID = :CQCMISPDAT_N.CHAR_ID,
                    UNIT_ID = :CQCMISPDAT_N.UNIT_ID,
                    VALUE_TYPE = :CQCMISPDAT_N.VALUE_TYPE,
                    VALUE_COUNT = :CQCMISPDAT_N.VALUE_COUNT,
                    VALUE_1 = :CQCMISPDAT_N.VALUE_1,
                    VALUE_2 = :CQCMISPDAT_N.VALUE_2,
                    VALUE_3 = :CQCMISPDAT_N.VALUE_3,
                    VALUE_4 = :CQCMISPDAT_N.VALUE_4,
                    VALUE_5 = :CQCMISPDAT_N.VALUE_5,
                    VALUE_6 = :CQCMISPDAT_N.VALUE_6,
                    VALUE_7 = :CQCMISPDAT_N.VALUE_7,
                    VALUE_8 = :CQCMISPDAT_N.VALUE_8,
                    VALUE_9 = :CQCMISPDAT_N.VALUE_9,
                    VALUE_10 = :CQCMISPDAT_N.VALUE_10,
                    VALUE_11 = :CQCMISPDAT_N.VALUE_11,
                    VALUE_12 = :CQCMISPDAT_N.VALUE_12,
                    VALUE_13 = :CQCMISPDAT_N.VALUE_13,
                    VALUE_14 = :CQCMISPDAT_N.VALUE_14,
                    VALUE_15 = :CQCMISPDAT_N.VALUE_15,
                    VALUE_16 = :CQCMISPDAT_N.VALUE_16,
                    VALUE_17 = :CQCMISPDAT_N.VALUE_17,
                    VALUE_18 = :CQCMISPDAT_N.VALUE_18,
                    VALUE_19 = :CQCMISPDAT_N.VALUE_19,
                    VALUE_20 = :CQCMISPDAT_N.VALUE_20,
                    VALUE_21 = :CQCMISPDAT_N.VALUE_21,
                    VALUE_22 = :CQCMISPDAT_N.VALUE_22,
                    VALUE_23 = :CQCMISPDAT_N.VALUE_23,
                    VALUE_24 = :CQCMISPDAT_N.VALUE_24,
                    VALUE_25 = :CQCMISPDAT_N.VALUE_25,
                    SAMPLE_COUNT = :CQCMISPDAT_N.SAMPLE_COUNT,
                    SPEC_OUT_MASK = :CQCMISPDAT_N.SPEC_OUT_MASK,
                    UPDATE_USER_ID = :CQCMISPDAT_N.UPDATE_USER_ID,
                    UPDATE_TIME = :CQCMISPDAT_N.UPDATE_TIME
                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                    AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                    AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
					AND CHAR_SEQ = :CQCMISPDAT_N.CHAR_SEQ
                    AND UNIT_SEQ = :CQCMISPDAT_N.UNIT_SEQ
                    AND VALUE_SEQ = :CQCMISPDAT_N.VALUE_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update CQCMISPDAT  set CHAR_ID=:b0,UNIT_ID=:b1,V\
ALUE_TYPE=:b2,VALUE_COUNT=:b3,VALUE_1=:b4,VALUE_2=:b5,VALUE_3=:b6,VALUE_4=:b7\
,VALUE_5=:b8,VALUE_6=:b9,VALUE_7=:b10,VALUE_8=:b11,VALUE_9=:b12,VALUE_10=:b13\
,VALUE_11=:b14,VALUE_12=:b15,VALUE_13=:b16,VALUE_14=:b17,VALUE_15=:b18,VALUE_\
16=:b19,VALUE_17=:b20,VALUE_18=:b21,VALUE_19=:b22,VALUE_20=:b23,VALUE_21=:b24\
,VALUE_22=:b25,VALUE_23=:b26,VALUE_24=:b27,VALUE_25=:b28,SAMPLE_COUNT=:b29,SP\
EC_OUT_MASK=:b30,UPDATE_USER_ID=:b31,UPDATE_TIME=:b32 where ((((((FACTORY=:b3\
3 and INSP_ID=:b34) and COL_SET_ID=:b35) and INSP_SEQ=:b36) and CHAR_SEQ=:b37\
) and UNIT_SEQ=:b38) and VALUE_SEQ=:b39)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1392;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )51;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[10] = (unsigned int  )26;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[32] = (unsigned int  )15;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[33] = (unsigned int  )11;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[39] = (unsigned int  )sizeof(int);
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

    DB_stop_query_timer("DBU_update_cqcmispdat", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_cqcmispdat(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    INSP_SEQ,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
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
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RWK_FLOW,
                    RWK_OPER,
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
                FROM CQCMISPDAT
                ORDER BY FACTORY ASC,
                    INSP_ID ASC,
                    COL_SET_ID ASC,
                    INSP_SEQ ASC,
                    UNIT_SEQ ASC,
                    VALUE_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0019;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1567;
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
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_2 CURSOR FOR
                SELECT A.CHAR_ID,
						    A.VALUE_1,
						    COUNT(*) AS SAMPLE_COUNT
				  FROM CQCMISPDAT A, CQCMISPDAT B
			    WHERE A.FACTORY = B.FACTORY
					AND A.COL_SET_ID = B.COL_SET_ID
					AND A.COL_SET_VER = B.COL_SET_VER
					AND A.INSP_ID = B.INSP_ID
					AND B.INSP_SEQ = 1
					AND B.CHAR_ID = 'JUDGE_REWORK'
					AND B.VALUE_1 = 'N'
					AND A.UNIT_SEQ = B.UNIT_SEQ 
					AND A.FACTORY = :CQCMISPDAT_N.FACTORY
					AND A.INSP_ID = :CQCMISPDAT_N.INSP_ID
					AND A.COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
					AND A.INSP_SEQ = 1
					AND A.CHAR_ID = 'JUDGE_LOSS' 
					AND A.VALUE_1 > ' ' 
			GROUP BY A.CHAR_ID, A.VALUE_1; */ 

            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0020;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1582;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
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

		case 3:
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_3 CURSOR FOR
                SELECT VALUE_1,
							COUNT(*) AS CNT
						FROM CQCMISPDAT
						WHERE FACTORY = :CQCMISPDAT_N.FACTORY
						AND INSP_ID = :CQCMISPDAT_N.INSP_ID
						AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
						AND COL_SET_VER = (SELECT MAX(COL_SET_VER) FROM CQCMISPDAT
											WHERE FACTORY = :CQCMISPDAT_N.FACTORY
											AND INSP_ID = :CQCMISPDAT_N.INSP_ID
											AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
											)
						AND INSP_SEQ = :CQCMISPDAT_N.INSP_SEQ
						AND CHAR_ID = :CQCMISPDAT_N.CHAR_ID
						AND VALUE_1 > ' '
					GROUP BY VALUE_1; */ 

            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0021;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1609;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 4:
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_4 CURSOR FOR
                SELECT A.COL_SET_ID AS COL_SET_ID,
                           A.COL_SET_VERSION AS COL_SET_VER,
                           1 AS INSP_SEQ,
                           A.CHAR_ID AS CHAR_ID,
                           A.SEQ_NUM AS CHAR_SEQ,
                           1 AS UNIT_SEQ,
                           1 AS VALUE_SEQ,
                           ' ' AS UNIT_ID,
                           'N' AS VALUE_TYPE,
                           A.VALUE_COUNT AS VALUE_COUNT,
                           RTRIM(TO_CHAR(NVL(X.VALUE_1,0),'FM9999999990.09999'),'.') AS VALUE_1,
                           ' ' AS VALUE_2,
                           ' ' AS VALUE_3,
                           ' ' AS VALUE_4,
                           ' ' AS VALUE_5,
                           ' ' AS VALUE_6,
                           ' ' AS VALUE_7,
                           ' ' AS VALUE_8,
                           ' ' AS VALUE_9,
                           ' ' AS VALUE_10,
                           ' ' AS VALUE_11,
                           ' ' AS VALUE_12,
                           ' ' AS VALUE_13,
                           ' ' AS VALUE_14,
                           ' ' AS VALUE_15,
                           ' ' AS VALUE_16,
                           ' ' AS VALUE_17,
                           ' ' AS VALUE_18,
                           ' ' AS VALUE_19,
                           ' ' AS VALUE_20,
                           ' ' AS VALUE_21,
                           ' ' AS VALUE_22,
                           ' ' AS VALUE_23,
                           ' ' AS VALUE_24,
                           ' ' AS VALUE_25,
                           0 AS SAMPLE_COUNT,
                           ' ' AS SPEC_OUT_MASK,
                           ' ' AS INSP_JUDGE_FLAG,
                           ' ' AS INSP_JUDGE_TYPE,
                           ' ' AS INSP_JUDGE_TIME,
                           ' ' AS RWK_FLOW,
                           ' ' AS RWK_OPER,
                           ' ' AS CMF_1,
                           ' ' AS CMF_2,
                           ' ' AS CMF_3,
                           ' ' AS CMF_4,
                           ' ' AS CMF_5,
                           ' ' AS CMF_6,
                           ' ' AS CMF_7,
                           ' ' AS CMF_8,
                           ' ' AS CMF_9,
                           ' ' AS CMF_10,
                           ' ' AS CREATE_USER_ID,
                           ' ' AS CREATE_TIME,
                           ' ' AS UPDATE_USER_ID,
                           ' ' AS UPDATE_TIME
       
                      FROM MEDCCOLCHR A, ( SELECT DECODE(SIEVE_CODE, '++' ,'PSD_TOP',
																							'+','PSD_UP',
																							'SS','PSD_SS',
																							'-','PSD_LO',
																							'PAN','PSD_PAN',
																							' ') AS CHAR_ID,
																		TI_VALUE_1 AS VALUE_1
																	FROM CQCMGRTSIV
																WHERE FACTORY = :CQCMISPDAT_N.FACTORY
																	AND INSP_ID = :CQCMISPDAT_N.INSP_ID
																	AND INSP_DTL_TYPE = 'PSD'
																	AND SIEVE_CODE IN ('++','+','SS','-','PAN')
																	AND INSP_COUNT = (SELECT MAX(INSP_COUNT) 
																						FROM CQCMGRTSIV
																						WHERE FACTORY = :CQCMISPDAT_N.FACTORY
																						AND INSP_ID = :CQCMISPDAT_N.INSP_ID
																						AND INSP_DTL_TYPE = 'PSD'
																					)
														UNION ALL
            
																	SELECT 'PSD_SO' AS CHAR_ID,
																		SUM(TI_VALUE_1) AS VALUE_1
																	FROM CQCMGRTSIV
																WHERE FACTORY = :CQCMISPDAT_N.FACTORY
																	AND INSP_ID = :CQCMISPDAT_N.INSP_ID
																	AND INSP_DTL_TYPE = 'PSD'
																	AND SIEVE_CODE IN ('SS','OS')
																	AND INSP_COUNT = (SELECT MAX(INSP_COUNT) 
																						FROM CQCMGRTSIV
																						WHERE FACTORY = :CQCMISPDAT_N.FACTORY
																						AND INSP_ID = :CQCMISPDAT_N.INSP_ID
																						AND INSP_DTL_TYPE = 'PSD'
																					)

                                     UNION ALL
                                           
                                           SELECT 'TI' AS CHAR_ID,
                                                   TI_CHANGE AS VALUE_1
                                              FROM CQCMGRTSIV
                                            WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                              AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                              AND INSP_DTL_TYPE = 'BI'
                                              AND SIEVE_CODE = '#1'
                                              AND INSP_COUNT = (SELECT MAX(INSP_COUNT) FROM CQCMGRTSIV
                                                                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                                                  AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                                                  AND INSP_DTL_TYPE = 'BI'
                                                                )

                                     UNION ALL

                                        SELECT 'TTI' AS CHAR_ID,
                                               TI_CHANGE AS VALUE_1
                                          FROM CQCMGRTSIV
                                        WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                          AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                          AND INSP_DTL_TYPE = 'BTI'
                                          AND SIEVE_CODE = '#1'
                                          AND INSP_COUNT = (SELECT MAX(INSP_COUNT) FROM CQCMGRTSIV
                                                            WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                                              AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                                              AND INSP_DTL_TYPE = 'BTI'
                                                            )                                                                                                                                          
                                     UNION ALL
                                        
                                        SELECT   'HLT_TI' AS CHAR_ID,
                                                  TI_RESULT AS VALUE_1
                                         FROM CQCMGRTHLT
                                        WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                          AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                          AND INSP_DTL_TYPE = 'HLT'
                                          AND INSP_COUNT = (SELECT MAX(INSP_COUNT) 
                                                              FROM CQCMGRTHLT
                                                             WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                                               AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                                               AND INSP_DTL_TYPE = 'HLT'
                                                                )
                                           AND ROWNUM <= 1
                                    UNION ALL
                                    SELECT   DECODE(QC_NAME, 'ASPECT RATIO' ,'GOQC038',
                                              'MAX FERET DIAMETER','GOQC204',
                                              'MIN FERET DIAMETER','GOQC205',
                                              'ELLIPTICITY','GOQC206',
                                              ' ') AS CHAR_ID,
                                                  VAL_1 AS VALUE_1
                                         FROM CQCMGRTASP
                                        WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                          AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                          AND INSP_DTL_TYPE = 'ASPECT'
                                          AND INSP_COUNT = (SELECT MAX(INSP_COUNT) 
                                                              FROM CQCMGRTASP
                                                             WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                                               AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                                               AND INSP_DTL_TYPE = 'ASPECT'
                                                                )
                                      UNION ALL        

                                        SELECT A.CHAR_ID,
                                               CASE WHEN CHAR_ID = 'GIQC46' THEN MA_RESULT
                                                    WHEN CHAR_ID = 'WT_PER' THEN WT_RESULT
                                                    WHEN CHAR_ID = 'BD' THEN BD_RESULT
                                                    WHEN CHAR_ID = 'GIQC41' THEN CM_L
                                                    WHEN CHAR_ID = 'GOQC63' THEN CM_A
                                                    WHEN CHAR_ID = 'GIQC01' THEN CM_B
                                                    WHEN CHAR_ID = 'GOQC056' THEN SURFACE_B 
                                                    
                                                    WHEN CHAR_ID = 'GOQC103' THEN CON_O_VALUE
                                                    WHEN CHAR_ID = 'GOQC084' THEN GRAIN_SIZE
                                                    WHEN CHAR_ID = 'GOQC083' THEN ROUG_VALUE
                                                    WHEN CHAR_ID = 'GOQC082' THEN ELIP_VALUE2
                                                    WHEN CHAR_ID = 'GOQC081' THEN SHAPE_FACTOR
                                                    WHEN CHAR_ID = 'GOQC039' THEN CIRCULRARITY END AS VALUE_1
                                
                                          FROM
                                        (SELECT 'GIQC46' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'WT_PER' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'BD' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GIQC41' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC63' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GIQC01' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC056' AS CHAR_ID FROM DUAL UNION ALL 
                                        
                                        SELECT 'GOQC103' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC084' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC083' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC082' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC081' AS CHAR_ID FROM DUAL UNION ALL
                                        SELECT 'GOQC039' AS CHAR_ID FROM DUAL

                                        ) A , (SELECT MA_RESULT,
                                                       WT_RESULT,
                                                       BD_RESULT,
                                                       CM_L,
                                                       CM_A,
                                                       CM_B,
                                                       SURFACE_B,
                                                       CON_O_VALUE,
                                                       GRAIN_SIZE,
                                                       ROUG_VALUE,
                                                       ELIP_VALUE2,
                                                       SHAPE_FACTOR,
                                                       CIRCULRARITY
                                                  FROM CQCMGRTCOT
                                                WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                                  AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                                                  AND INSP_DTL_TYPE = 'COATING'
                                                  AND INSP_COUNT = 1) B
                                                                                                  
                                                                                       ) X
                    WHERE A.CHAR_ID = X.CHAR_ID(+)
                    AND A.FACTORY = :CQCMISPDAT_N.FACTORY
                    AND A.COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                    AND A.COL_SET_VERSION = ( SELECT MAX(COL_SET_VERSION) FROM MEDCCOLVER
                                            WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                              AND COL_SET_ID = :CQCMISPDAT_N.COL_SET_ID
                                              AND RELEASE_FLAG = 'Y'
                                           ) 
                    ORDER BY A.SEQ_NUM; */ 

            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select A.COL_SET_ID COL_SET_ID ,A.COL_SET_VERSION COL_SET_VER\
 ,1 INSP_SEQ ,A.CHAR_ID CHAR_ID ,A.SEQ_NUM CHAR_SEQ ,1 UNIT_SEQ ,1 VALUE_SEQ\
 ,' ' UNIT_ID ,'N' VALUE_TYPE ,A.VALUE_COUNT VALUE_COUNT ,RTRIM(TO_CHAR(NVL(\
X.VALUE_1,0),'FM9999999990.09999'),'.') VALUE_1 ,' ' VALUE_2 ,' ' VALUE_3 ,'\
 ' VALUE_4 ,' ' VALUE_5 ,' ' VALUE_6 ,' ' VALUE_7 ,' ' VALUE_8 ,' ' VALUE_9 \
,' ' VALUE_10 ,' ' VALUE_11 ,' ' VALUE_12 ,' ' VALUE_13 ,' ' VALUE_14 ,' ' V\
ALUE_15 ,' ' VALUE_16 ,' ' VALUE_17 ,' ' VALUE_18 ,' ' VALUE_19 ,' ' VALUE_2\
0 ,' ' VALUE_21 ,' ' VALUE_22 ,' ' VALUE_23 ,' ' VALUE_24 ,' ' VALUE_25 ,0 S\
AMPLE_COUNT ,' ' SPEC_OUT_MASK ,' ' INSP_JUDGE_FLAG ,' ' INSP_JUDGE_TYPE ,' \
' INSP_JUDGE_TIME ,' ' RWK_FLOW ,' ' RWK_OPER ,' ' CMF_1 ,' ' CMF_2 ,' ' CMF\
_3 ,' ' CMF_4 ,' ' CMF_5 ,' ' CMF_6 ,' ' CMF_7 ,' ' CMF_8 ,' ' CMF_9 ,' ' CM\
F_10 ,' ' CREATE_USER_ID ,' ' CREATE_TIME ,' ' UPDATE_USER_ID ,' ' UPDATE_TI\
ME  from MEDCCOLCHR A ,(select DECODE(SIEVE_CODE,'++','PSD_TOP','+','PSD_UP'\
,'SS','PSD_SS','-','PSD_LO','PAN','PSD_PAN',' ') CH");
            sqlbuft((void **)0,
              "AR_ID ,TI_VALUE_1 VALUE_1  from CQCMGRTSIV where ((((FACTORY=\
:b0 and INSP_ID=:b1) and INSP_DTL_TYPE='PSD') and SIEVE_CODE in ('++','+','S\
S','-','PAN')) and INSP_COUNT=(select max(INSP_COUNT)  from CQCMGRTSIV where\
 ((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE='PSD'))) union all select \
'PSD_SO' CHAR_ID ,sum(TI_VALUE_1) VALUE_1  from CQCMGRTSIV where ((((FACTORY\
=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE='PSD') and SIEVE_CODE in ('SS','OS')\
) and INSP_COUNT=(select max(INSP_COUNT)  from CQCMGRTSIV where ((FACTORY=:b\
0 and INSP_ID=:b1) and INSP_DTL_TYPE='PSD'))) union all select 'TI' CHAR_ID \
,TI_CHANGE VALUE_1  from CQCMGRTSIV where ((((FACTORY=:b0 and INSP_ID=:b1) a\
nd INSP_DTL_TYPE='BI') and SIEVE_CODE='#1') and INSP_COUNT=(select max(INSP_\
COUNT)  from CQCMGRTSIV where ((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TY\
PE='BI'))) union all select 'TTI' CHAR_ID ,TI_CHANGE VALUE_1  from CQCMGRTSI\
V where ((((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE='BTI') and SIEVE_\
CODE='#1') and INSP_COUNT=(select max(INSP_COUNT)  ");
            sqlbuft((void **)0,
              "from CQCMGRTSIV where ((FACTORY=:b0 and INSP_ID=:b1) and INSP\
_DTL_TYPE='BTI'))) union all select 'HLT_TI' CHAR_ID ,TI_RESULT VALUE_1  fro\
m CQCMGRTHLT where ((((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE='HLT')\
 and INSP_COUNT=(select max(INSP_COUNT)  from CQCMGRTHLT where ((FACTORY=:b0\
 and INSP_ID=:b1) and INSP_DTL_TYPE='HLT'))) and ROWNUM<=1) union all select\
 DECODE(QC_NAME,'ASPECT RATIO','GOQC038','MAX FERET DIAMETER','GOQC204','MIN\
 FERET DIAMETER','GOQC205','ELLIPTICITY','GOQC206',' ') CHAR_ID ,VAL_1 VALUE\
_1  from CQCMGRTASP where (((FACTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE=\
'ASPECT') and INSP_COUNT=(select max(INSP_COUNT)  from CQCMGRTASP where ((FA\
CTORY=:b0 and INSP_ID=:b1) and INSP_DTL_TYPE='ASPECT'))) union all select A.\
CHAR_ID , case  when CHAR_ID='GIQC46' then MA_RESULT when CHAR_ID='WT_PER' t\
hen WT_RESULT when CHAR_ID='BD' then BD_RESULT when CHAR_ID='GIQC41' then CM\
_L when CHAR_ID='GOQC63' then CM_A when CHAR_ID='GIQC01' then CM_B when CHAR\
_ID='GOQC056' then SURFACE_B when CHAR_ID='GOQC103'");
            sqlbuft((void **)0,
              " then CON_O_VALUE when CHAR_ID='GOQC084' then GRAIN_SIZE when\
 CHAR_ID='GOQC083' then ROUG_VALUE when CHAR_ID='GOQC082' then ELIP_VALUE2 w\
hen CHAR_ID='GOQC081' then SHAPE_FACTOR when CHAR_ID='GOQC039' then CIRCULRA\
RITY end  VALUE_1  from (select 'GIQC46' CHAR_ID  from DUAL  union all selec\
t 'WT_PER' CHAR_ID  from DUAL  union all select 'BD' CHAR_ID  from DUAL  uni\
on all select 'GIQC41' CHAR_ID  from DUAL  union all select 'GOQC63' CHAR_ID\
  from DUAL  union all select 'GIQC01' CHAR_ID  from DUAL  union all select \
'GOQC056' CHAR_ID  from DUAL  union all select 'GOQC103' CHAR_ID  from DUAL \
 union all select 'GOQC084' CHAR_ID  from DUAL  union all select 'GOQC083' C\
HAR_ID  from DUAL  union all select 'GOQC082' CHAR_ID  from DUAL  union all \
select 'GOQC081' CHAR_ID  from DUAL  union all select 'GOQC039' CHAR_ID  fro\
m DUAL ) A ,(select MA_RESULT ,WT_RESULT ,BD_RESULT ,CM_L ,CM_A ,CM_B ,SURFA\
CE_B ,CON_O_VALUE ,GRAIN_SIZE ,ROUG_VALUE ,ELIP_VALUE2 ,SHAPE_FACTOR ,CIRCUL\
RARITY  from CQCMGRTCOT where (((FACTORY=:b0 and IN");
            sqlstm.stmt = sq0022;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1656;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[8] = (unsigned int  )11;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[12] = (unsigned int  )11;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[20] = (unsigned int  )11;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[22] = (unsigned int  )11;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[24] = (unsigned int  )11;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[26] = (unsigned int  )11;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[28] = (unsigned int  )11;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
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
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_5 CURSOR FOR
                SELECT 
                    FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    INSP_SEQ,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
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
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RWK_FLOW,
                    RWK_OPER,
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
            FROM CQCMISPDAT A
           WHERE FACTORY = :CQCMISPDAT_N.FACTORY
             AND INSP_ID = :CQCMISPDAT_N.INSP_ID
             AND INSP_SEQ = (SELECT MAX(INSP_SEQ)
                               FROM CQCMISPDAT
                              WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                             ); */ 

            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0023;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1791;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
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

		case 6:
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_6 CURSOR FOR
                SELECT 
                    FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    INSP_SEQ,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
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
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RWK_FLOW,
                    RWK_OPER,
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
            FROM CQCMISPDAT A
           WHERE FACTORY = :CQCMISPDAT_N.FACTORY
             AND INSP_ID = :CQCMISPDAT_N.INSP_ID
             AND INSP_SEQ = (SELECT MAX(INSP_SEQ)
                               FROM CQCMISPDAT
                              WHERE FACTORY = :CQCMISPDAT_N.FACTORY
                                AND INSP_ID = :CQCMISPDAT_N.INSP_ID
                             )
             ; */ 

            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0024;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1822;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
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

		case 7:
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_7 CURSOR FOR
                SELECT 
                    FACTORY,
                    INSP_ID,
                    COL_SET_ID,
                    COL_SET_VER,
                    INSP_SEQ,
                    CHAR_ID,
                    CHAR_SEQ,
                    UNIT_SEQ,
                    VALUE_SEQ,
                    UNIT_ID,
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
                    SPEC_OUT_MASK,
                    INSP_JUDGE_FLAG,
                    INSP_JUDGE_TYPE,
                    INSP_JUDGE_TIME,
                    RWK_FLOW,
                    RWK_OPER,
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
            FROM CQCMISPDAT A
           WHERE FACTORY = :CQCMISPDAT_N.FACTORY
             AND INSP_ID = :CQCMISPDAT_N.INSP_ID; */ 


            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_7; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0025;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1853;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
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

		case 8:
            /* EXEC SQL DECLARE DBU_CQCMISPDAT_CUR_8 CURSOR FOR
                SELECT A.FACTORY,
						    A.CHAR_ID,
						    A.SEQ_NUM,
							C.VALUE_TYPE,
						    A.VALUE_COUNT,
						    NVL(RTRIM(TO_CHAR(B.VALUE_1,'FM99999990.99999'),'.'),' ') AS VALUE_1,
						    NVL(RTRIM(TO_CHAR(B.VALUE_2,'FM99999990.99999'),'.'),' ')  AS VALUE_2,
						    NVL(RTRIM(TO_CHAR(B.VALUE_3,'FM99999990.99999'),'.'),' ')  AS VALUE_3,
						    NVL(RTRIM(TO_CHAR(B.VALUE_4,'FM99999990.99999'),'.'),' ')  AS VALUE_4,
						    NVL(RTRIM(TO_CHAR(B.VALUE_5,'FM99999990.99999'),'.'),' ')  AS VALUE_5,
						    NVL(RTRIM(TO_CHAR(B.VALUE_6,'FM99999990.99999'),'.'),' ')  AS VALUE_6,
						    NVL(RTRIM(TO_CHAR(B.VALUE_7,'FM99999990.99999'),'.'),' ')  AS VALUE_7,
						    NVL(RTRIM(TO_CHAR(B.VALUE_8,'FM99999990.99999'),'.'),' ')  AS VALUE_8,
						    NVL(RTRIM(TO_CHAR(B.VALUE_9,'FM99999990.99999'),'.'),' ')  AS VALUE_9,
							NVL(RTRIM(TO_CHAR(B.VALUE_10,'FM99999990.99999'),'.'),' ')  AS VALUE_10, 
						    NVL(RTRIM(TO_CHAR(B.VALUE_11,'FM99999990.99999'),'.'),' ')  AS VALUE_11,
						    NVL(RTRIM(TO_CHAR(B.VALUE_12,'FM99999990.99999'),'.'),' ')  AS VALUE_12,
							NVL(RTRIM(TO_CHAR(B.VALUE_13,'FM99999990.99999'),'.'),' ')  AS VALUE_13 
					  FROM MEDCCOLCHR A, (SELECT 'ALL-T' AS CHAR_ID,
														ALL_THICKNESS_1 AS VALUE_1,
														ALL_THICKNESS_2 AS VALUE_2,
														ALL_THICKNESS_3 AS VALUE_3,
														ALL_THICKNESS_4 AS VALUE_4,
														ALL_THICKNESS_5 AS VALUE_5,
														ALL_THICKNESS_6 AS VALUE_6,
														ALL_THICKNESS_7 AS VALUE_7,
														ALL_THICKNESS_8 AS VALUE_8,
														ALL_THICKNESS_9 AS VALUE_9,
														ALL_THICKNESS_10 AS VALUE_10,
														ALL_THICKNESS_11 AS VALUE_11,
														ALL_THICKNESS_12 AS VALUE_12,
														ALL_THICKNESS_13 AS VALUE_13
												  FROM cwiplotrnd
												 WHERE lot_id = :CQCMISPDAT_N.CMF_1
												   AND hist_seq = :CQCMISPDAT_N.INSP_SEQ
                               
												UNION ALL

												SELECT 'FLAT' AS CHAR_ID,
														FLATNESS_1 AS VALUE_1,
														FLATNESS_2 AS VALUE_2,
														FLATNESS_3 AS VALUE_3,
														FLATNESS_4 AS VALUE_4,
														FLATNESS_5 AS VALUE_5,
														FLATNESS_6 AS VALUE_6,
														FLATNESS_7 AS VALUE_7,
														FLATNESS_8 AS VALUE_8,
														FLATNESS_9 AS VALUE_9,
														FLATNESS_10 AS VALUE_10,
														FLATNESS_11 AS VALUE_11,
														FLATNESS_12 AS VALUE_12,
														FLATNESS_13 AS VALUE_13
												  FROM cwiplotrnd
												 WHERE lot_id = :CQCMISPDAT_N.CMF_1
												   AND hist_seq =:CQCMISPDAT_N.INSP_SEQ

												UNION ALL

												SELECT 'MAX-D' AS CHAR_ID,
														OUTER_DIAMETER_1 AS VALUE_1,
														OUTER_DIAMETER_2 AS VALUE_2,
														NULL AS VALUE_3,
														NULL AS VALUE_4,
														NULL AS VALUE_5,
														NULL AS VALUE_6,
														NULL AS VALUE_7,
														NULL AS VALUE_8,
														NULL AS VALUE_9,
														NULL AS VALUE_10,
														NULL AS VALUE_11,
														NULL AS VALUE_12,
														NULL AS VALUE_13
												  FROM cwiplotrnd
												 WHERE lot_id = :CQCMISPDAT_N.CMF_1
												   AND hist_seq = :CQCMISPDAT_N.INSP_SEQ

												UNION ALL


												SELECT 'REAL-D' AS CHAR_ID,
														OUTER_DIAMETER_1 - 1 AS VALUE_1,
														OUTER_DIAMETER_2 - 1 AS VALUE_2,
														NULL AS VALUE_3,
														NULL AS VALUE_4,
														NULL AS VALUE_5,
														NULL AS VALUE_6,
														NULL AS VALUE_7,
														NULL AS VALUE_8,
														NULL AS VALUE_9,
														NULL AS VALUE_10,
														NULL AS VALUE_11,
														NULL AS VALUE_12,
														NULL AS VALUE_13
												  FROM cwiplotrnd
												 WHERE lot_id = :CQCMISPDAT_N.CMF_1
												   AND hist_seq =:CQCMISPDAT_N.INSP_SEQ
														) B,
														 MEDCCHRDEF C
							WHERE A.CHAR_ID = B.CHAR_ID
							  AND A.COL_SET_ID = (SELECT COL_SET_ID FROM MEDCCOLDEF WHERE COL_CMF_2 = 'A')
							  AND A.FACTORY = C.FACTORY
							  AND A.CHAR_ID = C.CHAR_ID
							ORDER BY A.SEQ_NUM; */ 


            /* EXEC SQL OPEN DBU_CQCMISPDAT_CUR_8; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select A.FACTORY ,A.CHAR_ID ,A.SEQ_NUM ,C.VALUE_TYPE ,A.VALUE\
_COUNT ,NVL(RTRIM(TO_CHAR(B.VALUE_1,'FM99999990.99999'),'.'),' ') VALUE_1 ,N\
VL(RTRIM(TO_CHAR(B.VALUE_2,'FM99999990.99999'),'.'),' ') VALUE_2 ,NVL(RTRIM(\
TO_CHAR(B.VALUE_3,'FM99999990.99999'),'.'),' ') VALUE_3 ,NVL(RTRIM(TO_CHAR(B\
.VALUE_4,'FM99999990.99999'),'.'),' ') VALUE_4 ,NVL(RTRIM(TO_CHAR(B.VALUE_5,\
'FM99999990.99999'),'.'),' ') VALUE_5 ,NVL(RTRIM(TO_CHAR(B.VALUE_6,'FM999999\
90.99999'),'.'),' ') VALUE_6 ,NVL(RTRIM(TO_CHAR(B.VALUE_7,'FM99999990.99999'\
),'.'),' ') VALUE_7 ,NVL(RTRIM(TO_CHAR(B.VALUE_8,'FM99999990.99999'),'.'),' \
') VALUE_8 ,NVL(RTRIM(TO_CHAR(B.VALUE_9,'FM99999990.99999'),'.'),' ') VALUE_\
9 ,NVL(RTRIM(TO_CHAR(B.VALUE_10,'FM99999990.99999'),'.'),' ') VALUE_10 ,NVL(\
RTRIM(TO_CHAR(B.VALUE_11,'FM99999990.99999'),'.'),' ') VALUE_11 ,NVL(RTRIM(T\
O_CHAR(B.VALUE_12,'FM99999990.99999'),'.'),' ') VALUE_12 ,NVL(RTRIM(TO_CHAR(\
B.VALUE_13,'FM99999990.99999'),'.'),' ') VALUE_13  from MEDCCOLCHR A ,(selec\
t 'ALL-T' CHAR_ID ,ALL_THICKNESS_1 VALUE_1 ,ALL_THI");
            sqlbuft((void **)0,
              "CKNESS_2 VALUE_2 ,ALL_THICKNESS_3 VALUE_3 ,ALL_THICKNESS_4 VA\
LUE_4 ,ALL_THICKNESS_5 VALUE_5 ,ALL_THICKNESS_6 VALUE_6 ,ALL_THICKNESS_7 VAL\
UE_7 ,ALL_THICKNESS_8 VALUE_8 ,ALL_THICKNESS_9 VALUE_9 ,ALL_THICKNESS_10 VAL\
UE_10 ,ALL_THICKNESS_11 VALUE_11 ,ALL_THICKNESS_12 VALUE_12 ,ALL_THICKNESS_1\
3 VALUE_13  from cwiplotrnd where (lot_id=:b0 and hist_seq=:b1) union all se\
lect 'FLAT' CHAR_ID ,FLATNESS_1 VALUE_1 ,FLATNESS_2 VALUE_2 ,FLATNESS_3 VALU\
E_3 ,FLATNESS_4 VALUE_4 ,FLATNESS_5 VALUE_5 ,FLATNESS_6 VALUE_6 ,FLATNESS_7 \
VALUE_7 ,FLATNESS_8 VALUE_8 ,FLATNESS_9 VALUE_9 ,FLATNESS_10 VALUE_10 ,FLATN\
ESS_11 VALUE_11 ,FLATNESS_12 VALUE_12 ,FLATNESS_13 VALUE_13  from cwiplotrnd\
 where (lot_id=:b0 and hist_seq=:b1) union all select 'MAX-D' CHAR_ID ,OUTER\
_DIAMETER_1 VALUE_1 ,OUTER_DIAMETER_2 VALUE_2 ,null  VALUE_3 ,null  VALUE_4 \
,null  VALUE_5 ,null  VALUE_6 ,null  VALUE_7 ,null  VALUE_8 ,null  VALUE_9 ,\
null  VALUE_10 ,null  VALUE_11 ,null  VALUE_12 ,null  VALUE_13  from cwiplot\
rnd where (lot_id=:b0 and hist_seq=:b1) union all s");
            sqlstm.stmt = sq0026;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1876;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[0] = (unsigned int  )51;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[2] = (unsigned int  )51;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[4] = (unsigned int  )51;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[6] = (unsigned int  )51;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_cqcmispdat", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_cqcmispdat(int sel_type, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CQCMISPDAT_N_TAG CQCMISPDAT_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_1 INTO
                :CQCMISPDAT_N.FACTORY,
                :CQCMISPDAT_N.INSP_ID,
                :CQCMISPDAT_N.COL_SET_ID,
                :CQCMISPDAT_N.COL_SET_VER,
                :CQCMISPDAT_N.INSP_SEQ,
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.CHAR_SEQ,
                :CQCMISPDAT_N.UNIT_SEQ,
                :CQCMISPDAT_N.VALUE_SEQ,
                :CQCMISPDAT_N.UNIT_ID,
                :CQCMISPDAT_N.VALUE_TYPE,
                :CQCMISPDAT_N.VALUE_COUNT,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.VALUE_2,
                :CQCMISPDAT_N.VALUE_3,
                :CQCMISPDAT_N.VALUE_4,
                :CQCMISPDAT_N.VALUE_5,
                :CQCMISPDAT_N.VALUE_6,
                :CQCMISPDAT_N.VALUE_7,
                :CQCMISPDAT_N.VALUE_8,
                :CQCMISPDAT_N.VALUE_9,
                :CQCMISPDAT_N.VALUE_10,
                :CQCMISPDAT_N.VALUE_11,
                :CQCMISPDAT_N.VALUE_12,
                :CQCMISPDAT_N.VALUE_13,
                :CQCMISPDAT_N.VALUE_14,
                :CQCMISPDAT_N.VALUE_15,
                :CQCMISPDAT_N.VALUE_16,
                :CQCMISPDAT_N.VALUE_17,
                :CQCMISPDAT_N.VALUE_18,
                :CQCMISPDAT_N.VALUE_19,
                :CQCMISPDAT_N.VALUE_20,
                :CQCMISPDAT_N.VALUE_21,
                :CQCMISPDAT_N.VALUE_22,
                :CQCMISPDAT_N.VALUE_23,
                :CQCMISPDAT_N.VALUE_24,
                :CQCMISPDAT_N.VALUE_25,
                :CQCMISPDAT_N.SAMPLE_COUNT,
                :CQCMISPDAT_N.SPEC_OUT_MASK,
                :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                :CQCMISPDAT_N.INSP_JUDGE_TIME,
                :CQCMISPDAT_N.RWK_FLOW,
                :CQCMISPDAT_N.RWK_OPER,
                :CQCMISPDAT_N.CMF_1,
                :CQCMISPDAT_N.CMF_2,
                :CQCMISPDAT_N.CMF_3,
                :CQCMISPDAT_N.CMF_4,
                :CQCMISPDAT_N.CMF_5,
                :CQCMISPDAT_N.CMF_6,
                :CQCMISPDAT_N.CMF_7,
                :CQCMISPDAT_N.CMF_8,
                :CQCMISPDAT_N.CMF_9,
                :CQCMISPDAT_N.CMF_10,
                :CQCMISPDAT_N.CREATE_USER_ID,
                :CQCMISPDAT_N.CREATE_TIME,
                :CQCMISPDAT_N.UPDATE_USER_ID,
                :CQCMISPDAT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1923;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )51;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
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

		case 2:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_2 INTO
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.SAMPLE_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2170;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
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

		case 3:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_3 INTO
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.SAMPLE_COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2197;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
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

		case 4:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_4 INTO
                :CQCMISPDAT_N.COL_SET_ID,
                :CQCMISPDAT_N.COL_SET_VER,
                :CQCMISPDAT_N.INSP_SEQ,
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.CHAR_SEQ,
                :CQCMISPDAT_N.UNIT_SEQ,
                :CQCMISPDAT_N.VALUE_SEQ,
                :CQCMISPDAT_N.UNIT_ID,
                :CQCMISPDAT_N.VALUE_TYPE,
                :CQCMISPDAT_N.VALUE_COUNT,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.VALUE_2,
                :CQCMISPDAT_N.VALUE_3,
                :CQCMISPDAT_N.VALUE_4,
                :CQCMISPDAT_N.VALUE_5,
                :CQCMISPDAT_N.VALUE_6,
                :CQCMISPDAT_N.VALUE_7,
                :CQCMISPDAT_N.VALUE_8,
                :CQCMISPDAT_N.VALUE_9,
                :CQCMISPDAT_N.VALUE_10,
                :CQCMISPDAT_N.VALUE_11,
                :CQCMISPDAT_N.VALUE_12,
                :CQCMISPDAT_N.VALUE_13,
                :CQCMISPDAT_N.VALUE_14,
                :CQCMISPDAT_N.VALUE_15,
                :CQCMISPDAT_N.VALUE_16,
                :CQCMISPDAT_N.VALUE_17,
                :CQCMISPDAT_N.VALUE_18,
                :CQCMISPDAT_N.VALUE_19,
                :CQCMISPDAT_N.VALUE_20,
                :CQCMISPDAT_N.VALUE_21,
                :CQCMISPDAT_N.VALUE_22,
                :CQCMISPDAT_N.VALUE_23,
                :CQCMISPDAT_N.VALUE_24,
                :CQCMISPDAT_N.VALUE_25,
                :CQCMISPDAT_N.SAMPLE_COUNT,
                :CQCMISPDAT_N.SPEC_OUT_MASK,
                :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                :CQCMISPDAT_N.INSP_JUDGE_TIME,
                :CQCMISPDAT_N.RWK_FLOW,
                :CQCMISPDAT_N.RWK_OPER,
                :CQCMISPDAT_N.CMF_1,
                :CQCMISPDAT_N.CMF_2,
                :CQCMISPDAT_N.CMF_3,
                :CQCMISPDAT_N.CMF_4,
                :CQCMISPDAT_N.CMF_5,
                :CQCMISPDAT_N.CMF_6,
                :CQCMISPDAT_N.CMF_7,
                :CQCMISPDAT_N.CMF_8,
                :CQCMISPDAT_N.CMF_9,
                :CQCMISPDAT_N.CMF_10,
                :CQCMISPDAT_N.CREATE_USER_ID,
                :CQCMISPDAT_N.CREATE_TIME,
                :CQCMISPDAT_N.UPDATE_USER_ID,
                :CQCMISPDAT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2220;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[7] = (unsigned int  )51;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[10] = (unsigned int  )26;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[35] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[39] = (unsigned int  )31;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[41] = (unsigned int  )11;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[42] = (unsigned int  )51;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[43] = (unsigned int  )51;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[53] = (unsigned int  )15;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_5 INTO
                :CQCMISPDAT_N.FACTORY,
                :CQCMISPDAT_N.INSP_ID,
                :CQCMISPDAT_N.COL_SET_ID,
                :CQCMISPDAT_N.COL_SET_VER,
                :CQCMISPDAT_N.INSP_SEQ,
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.CHAR_SEQ,
                :CQCMISPDAT_N.UNIT_SEQ,
                :CQCMISPDAT_N.VALUE_SEQ,
                :CQCMISPDAT_N.UNIT_ID,
                :CQCMISPDAT_N.VALUE_TYPE,
                :CQCMISPDAT_N.VALUE_COUNT,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.VALUE_2,
                :CQCMISPDAT_N.VALUE_3,
                :CQCMISPDAT_N.VALUE_4,
                :CQCMISPDAT_N.VALUE_5,
                :CQCMISPDAT_N.VALUE_6,
                :CQCMISPDAT_N.VALUE_7,
                :CQCMISPDAT_N.VALUE_8,
                :CQCMISPDAT_N.VALUE_9,
                :CQCMISPDAT_N.VALUE_10,
                :CQCMISPDAT_N.VALUE_11,
                :CQCMISPDAT_N.VALUE_12,
                :CQCMISPDAT_N.VALUE_13,
                :CQCMISPDAT_N.VALUE_14,
                :CQCMISPDAT_N.VALUE_15,
                :CQCMISPDAT_N.VALUE_16,
                :CQCMISPDAT_N.VALUE_17,
                :CQCMISPDAT_N.VALUE_18,
                :CQCMISPDAT_N.VALUE_19,
                :CQCMISPDAT_N.VALUE_20,
                :CQCMISPDAT_N.VALUE_21,
                :CQCMISPDAT_N.VALUE_22,
                :CQCMISPDAT_N.VALUE_23,
                :CQCMISPDAT_N.VALUE_24,
                :CQCMISPDAT_N.VALUE_25,
                :CQCMISPDAT_N.SAMPLE_COUNT,
                :CQCMISPDAT_N.SPEC_OUT_MASK,
                :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                :CQCMISPDAT_N.INSP_JUDGE_TIME,
                :CQCMISPDAT_N.RWK_FLOW,
                :CQCMISPDAT_N.RWK_OPER,
                :CQCMISPDAT_N.CMF_1,
                :CQCMISPDAT_N.CMF_2,
                :CQCMISPDAT_N.CMF_3,
                :CQCMISPDAT_N.CMF_4,
                :CQCMISPDAT_N.CMF_5,
                :CQCMISPDAT_N.CMF_6,
                :CQCMISPDAT_N.CMF_7,
                :CQCMISPDAT_N.CMF_8,
                :CQCMISPDAT_N.CMF_9,
                :CQCMISPDAT_N.CMF_10,
                :CQCMISPDAT_N.CREATE_USER_ID,
                :CQCMISPDAT_N.CREATE_TIME,
                :CQCMISPDAT_N.UPDATE_USER_ID,
                :CQCMISPDAT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2459;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )51;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
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

		case 6:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_6 INTO
                :CQCMISPDAT_N.FACTORY,
                :CQCMISPDAT_N.INSP_ID,
                :CQCMISPDAT_N.COL_SET_ID,
                :CQCMISPDAT_N.COL_SET_VER,
                :CQCMISPDAT_N.INSP_SEQ,
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.CHAR_SEQ,
                :CQCMISPDAT_N.UNIT_SEQ,
                :CQCMISPDAT_N.VALUE_SEQ,
                :CQCMISPDAT_N.UNIT_ID,
                :CQCMISPDAT_N.VALUE_TYPE,
                :CQCMISPDAT_N.VALUE_COUNT,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.VALUE_2,
                :CQCMISPDAT_N.VALUE_3,
                :CQCMISPDAT_N.VALUE_4,
                :CQCMISPDAT_N.VALUE_5,
                :CQCMISPDAT_N.VALUE_6,
                :CQCMISPDAT_N.VALUE_7,
                :CQCMISPDAT_N.VALUE_8,
                :CQCMISPDAT_N.VALUE_9,
                :CQCMISPDAT_N.VALUE_10,
                :CQCMISPDAT_N.VALUE_11,
                :CQCMISPDAT_N.VALUE_12,
                :CQCMISPDAT_N.VALUE_13,
                :CQCMISPDAT_N.VALUE_14,
                :CQCMISPDAT_N.VALUE_15,
                :CQCMISPDAT_N.VALUE_16,
                :CQCMISPDAT_N.VALUE_17,
                :CQCMISPDAT_N.VALUE_18,
                :CQCMISPDAT_N.VALUE_19,
                :CQCMISPDAT_N.VALUE_20,
                :CQCMISPDAT_N.VALUE_21,
                :CQCMISPDAT_N.VALUE_22,
                :CQCMISPDAT_N.VALUE_23,
                :CQCMISPDAT_N.VALUE_24,
                :CQCMISPDAT_N.VALUE_25,
                :CQCMISPDAT_N.SAMPLE_COUNT,
                :CQCMISPDAT_N.SPEC_OUT_MASK,
                :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                :CQCMISPDAT_N.INSP_JUDGE_TIME,
                :CQCMISPDAT_N.RWK_FLOW,
                :CQCMISPDAT_N.RWK_OPER,
                :CQCMISPDAT_N.CMF_1,
                :CQCMISPDAT_N.CMF_2,
                :CQCMISPDAT_N.CMF_3,
                :CQCMISPDAT_N.CMF_4,
                :CQCMISPDAT_N.CMF_5,
                :CQCMISPDAT_N.CMF_6,
                :CQCMISPDAT_N.CMF_7,
                :CQCMISPDAT_N.CMF_8,
                :CQCMISPDAT_N.CMF_9,
                :CQCMISPDAT_N.CMF_10,
                :CQCMISPDAT_N.CREATE_USER_ID,
                :CQCMISPDAT_N.CREATE_TIME,
                :CQCMISPDAT_N.UPDATE_USER_ID,
                :CQCMISPDAT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2706;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )51;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
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

		case 7:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_7 INTO
                :CQCMISPDAT_N.FACTORY,
                :CQCMISPDAT_N.INSP_ID,
                :CQCMISPDAT_N.COL_SET_ID,
                :CQCMISPDAT_N.COL_SET_VER,
                :CQCMISPDAT_N.INSP_SEQ,
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.CHAR_SEQ,
                :CQCMISPDAT_N.UNIT_SEQ,
                :CQCMISPDAT_N.VALUE_SEQ,
                :CQCMISPDAT_N.UNIT_ID,
                :CQCMISPDAT_N.VALUE_TYPE,
                :CQCMISPDAT_N.VALUE_COUNT,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.VALUE_2,
                :CQCMISPDAT_N.VALUE_3,
                :CQCMISPDAT_N.VALUE_4,
                :CQCMISPDAT_N.VALUE_5,
                :CQCMISPDAT_N.VALUE_6,
                :CQCMISPDAT_N.VALUE_7,
                :CQCMISPDAT_N.VALUE_8,
                :CQCMISPDAT_N.VALUE_9,
                :CQCMISPDAT_N.VALUE_10,
                :CQCMISPDAT_N.VALUE_11,
                :CQCMISPDAT_N.VALUE_12,
                :CQCMISPDAT_N.VALUE_13,
                :CQCMISPDAT_N.VALUE_14,
                :CQCMISPDAT_N.VALUE_15,
                :CQCMISPDAT_N.VALUE_16,
                :CQCMISPDAT_N.VALUE_17,
                :CQCMISPDAT_N.VALUE_18,
                :CQCMISPDAT_N.VALUE_19,
                :CQCMISPDAT_N.VALUE_20,
                :CQCMISPDAT_N.VALUE_21,
                :CQCMISPDAT_N.VALUE_22,
                :CQCMISPDAT_N.VALUE_23,
                :CQCMISPDAT_N.VALUE_24,
                :CQCMISPDAT_N.VALUE_25,
                :CQCMISPDAT_N.SAMPLE_COUNT,
                :CQCMISPDAT_N.SPEC_OUT_MASK,
                :CQCMISPDAT_N.INSP_JUDGE_FLAG,
                :CQCMISPDAT_N.INSP_JUDGE_TYPE,
                :CQCMISPDAT_N.INSP_JUDGE_TIME,
                :CQCMISPDAT_N.RWK_FLOW,
                :CQCMISPDAT_N.RWK_OPER,
                :CQCMISPDAT_N.CMF_1,
                :CQCMISPDAT_N.CMF_2,
                :CQCMISPDAT_N.CMF_3,
                :CQCMISPDAT_N.CMF_4,
                :CQCMISPDAT_N.CMF_5,
                :CQCMISPDAT_N.CMF_6,
                :CQCMISPDAT_N.CMF_7,
                :CQCMISPDAT_N.CMF_8,
                :CQCMISPDAT_N.CMF_9,
                :CQCMISPDAT_N.CMF_10,
                :CQCMISPDAT_N.CREATE_USER_ID,
                :CQCMISPDAT_N.CREATE_TIME,
                :CQCMISPDAT_N.UPDATE_USER_ID,
                :CQCMISPDAT_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
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
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.INSP_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CQCMISPDAT_N.COL_SET_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CQCMISPDAT_N.COL_SET_VER);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.INSP_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CQCMISPDAT_N.UNIT_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CQCMISPDAT_N.VALUE_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.UNIT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )51;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[10] = (unsigned int  )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[24] = (unsigned int  )26;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(CQCMISPDAT_N.VALUE_14);
            sqlstm.sqhstl[25] = (unsigned int  )26;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(CQCMISPDAT_N.VALUE_15);
            sqlstm.sqhstl[26] = (unsigned int  )26;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(CQCMISPDAT_N.VALUE_16);
            sqlstm.sqhstl[27] = (unsigned int  )26;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(CQCMISPDAT_N.VALUE_17);
            sqlstm.sqhstl[28] = (unsigned int  )26;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(CQCMISPDAT_N.VALUE_18);
            sqlstm.sqhstl[29] = (unsigned int  )26;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(CQCMISPDAT_N.VALUE_19);
            sqlstm.sqhstl[30] = (unsigned int  )26;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(CQCMISPDAT_N.VALUE_20);
            sqlstm.sqhstl[31] = (unsigned int  )26;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(CQCMISPDAT_N.VALUE_21);
            sqlstm.sqhstl[32] = (unsigned int  )26;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(CQCMISPDAT_N.VALUE_22);
            sqlstm.sqhstl[33] = (unsigned int  )26;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(CQCMISPDAT_N.VALUE_23);
            sqlstm.sqhstl[34] = (unsigned int  )26;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(CQCMISPDAT_N.VALUE_24);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(CQCMISPDAT_N.VALUE_25);
            sqlstm.sqhstl[36] = (unsigned int  )26;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(CQCMISPDAT_N.SAMPLE_COUNT);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(CQCMISPDAT_N.SPEC_OUT_MASK);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TYPE);
            sqlstm.sqhstl[40] = (unsigned int  )31;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(CQCMISPDAT_N.INSP_JUDGE_TIME);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(CQCMISPDAT_N.RWK_FLOW);
            sqlstm.sqhstl[42] = (unsigned int  )21;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(CQCMISPDAT_N.RWK_OPER);
            sqlstm.sqhstl[43] = (unsigned int  )11;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(CQCMISPDAT_N.CMF_1);
            sqlstm.sqhstl[44] = (unsigned int  )51;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(CQCMISPDAT_N.CMF_2);
            sqlstm.sqhstl[45] = (unsigned int  )51;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(CQCMISPDAT_N.CMF_3);
            sqlstm.sqhstl[46] = (unsigned int  )51;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(CQCMISPDAT_N.CMF_4);
            sqlstm.sqhstl[47] = (unsigned int  )51;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(CQCMISPDAT_N.CMF_5);
            sqlstm.sqhstl[48] = (unsigned int  )51;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(CQCMISPDAT_N.CMF_6);
            sqlstm.sqhstl[49] = (unsigned int  )51;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(CQCMISPDAT_N.CMF_7);
            sqlstm.sqhstl[50] = (unsigned int  )51;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(CQCMISPDAT_N.CMF_8);
            sqlstm.sqhstl[51] = (unsigned int  )51;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(CQCMISPDAT_N.CMF_9);
            sqlstm.sqhstl[52] = (unsigned int  )51;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(CQCMISPDAT_N.CMF_10);
            sqlstm.sqhstl[53] = (unsigned int  )51;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(CQCMISPDAT_N.CREATE_USER_ID);
            sqlstm.sqhstl[54] = (unsigned int  )21;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(CQCMISPDAT_N.CREATE_TIME);
            sqlstm.sqhstl[55] = (unsigned int  )15;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(CQCMISPDAT_N.UPDATE_USER_ID);
            sqlstm.sqhstl[56] = (unsigned int  )21;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(CQCMISPDAT_N.UPDATE_TIME);
            sqlstm.sqhstl[57] = (unsigned int  )15;
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

		case 8:
            /* EXEC SQL FETCH DBU_CQCMISPDAT_CUR_8 INTO
                :CQCMISPDAT_N.FACTORY,
                :CQCMISPDAT_N.CHAR_ID,
                :CQCMISPDAT_N.CHAR_SEQ,
                :CQCMISPDAT_N.VALUE_TYPE,
                :CQCMISPDAT_N.VALUE_COUNT,
                :CQCMISPDAT_N.VALUE_1,
                :CQCMISPDAT_N.VALUE_2,
                :CQCMISPDAT_N.VALUE_3,
                :CQCMISPDAT_N.VALUE_4,
                :CQCMISPDAT_N.VALUE_5,
                :CQCMISPDAT_N.VALUE_6,
                :CQCMISPDAT_N.VALUE_7,
                :CQCMISPDAT_N.VALUE_8,
                :CQCMISPDAT_N.VALUE_9,
				:CQCMISPDAT_N.VALUE_10,
                :CQCMISPDAT_N.VALUE_11,
                :CQCMISPDAT_N.VALUE_12,
                :CQCMISPDAT_N.VALUE_13; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3200;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CQCMISPDAT_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CQCMISPDAT_N.CHAR_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CQCMISPDAT_N.CHAR_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CQCMISPDAT_N.VALUE_TYPE);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CQCMISPDAT_N.VALUE_COUNT);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CQCMISPDAT_N.VALUE_1);
            sqlstm.sqhstl[5] = (unsigned int  )26;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(CQCMISPDAT_N.VALUE_2);
            sqlstm.sqhstl[6] = (unsigned int  )26;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(CQCMISPDAT_N.VALUE_3);
            sqlstm.sqhstl[7] = (unsigned int  )26;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(CQCMISPDAT_N.VALUE_4);
            sqlstm.sqhstl[8] = (unsigned int  )26;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(CQCMISPDAT_N.VALUE_5);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(CQCMISPDAT_N.VALUE_6);
            sqlstm.sqhstl[10] = (unsigned int  )26;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(CQCMISPDAT_N.VALUE_7);
            sqlstm.sqhstl[11] = (unsigned int  )26;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(CQCMISPDAT_N.VALUE_8);
            sqlstm.sqhstl[12] = (unsigned int  )26;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(CQCMISPDAT_N.VALUE_9);
            sqlstm.sqhstl[13] = (unsigned int  )26;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(CQCMISPDAT_N.VALUE_10);
            sqlstm.sqhstl[14] = (unsigned int  )26;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(CQCMISPDAT_N.VALUE_11);
            sqlstm.sqhstl[15] = (unsigned int  )26;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(CQCMISPDAT_N.VALUE_12);
            sqlstm.sqhstl[16] = (unsigned int  )26;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(CQCMISPDAT_N.VALUE_13);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
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
        DBU_del_null_cqcmispdat(&CQCMISPDAT_N, CQCMISPDAT);
    }

    DB_stop_query_timer("DBU_fetch_cqcmispdat", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_cqcmispdat(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3287;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 2:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3302;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 3:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3317;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 4:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3332;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 5:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3347;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 6:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3362;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 7:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_7; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3377;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

		case 8:
            /* EXEC SQL CLOSE DBU_CQCMISPDAT_CUR_8; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 65;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3392;
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

    DB_stop_query_timer("DBU_close_cqcmispdat", sel_type);
}


/* Initialize Function */
void DBU_init_cqcmispdat(struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* memset by Space */
    memset(CQCMISPDAT, ' ', sizeof(struct CQCMISPDAT_TAG));
    
	CQCMISPDAT->COL_SET_VER = 0;
    CQCMISPDAT->INSP_SEQ = 0;
    CQCMISPDAT->CHAR_SEQ = 0;
    CQCMISPDAT->UNIT_SEQ = 0;
    CQCMISPDAT->VALUE_SEQ = 0;
    CQCMISPDAT->VALUE_COUNT = 0;
    CQCMISPDAT->SAMPLE_COUNT = 0;
}


/* Add Null Function */
void DBU_add_null_cqcmispdat(struct CQCMISPDAT_N_TAG *CQCMISPDAT_N, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    /* memset by NULL */
    memset(CQCMISPDAT_N, '\0', sizeof(struct CQCMISPDAT_N_TAG));
    
    MEMCPY_AN(CQCMISPDAT_N->FACTORY, CQCMISPDAT->FACTORY, sizeof(CQCMISPDAT->FACTORY));
    MEMCPY_AN(CQCMISPDAT_N->INSP_ID, CQCMISPDAT->INSP_ID, sizeof(CQCMISPDAT->INSP_ID));
	MEMCPY_AN(CQCMISPDAT_N->COL_SET_ID, CQCMISPDAT->COL_SET_ID, sizeof(CQCMISPDAT->COL_SET_ID));
	CQCMISPDAT_N->COL_SET_VER = CQCMISPDAT->COL_SET_VER;
    CQCMISPDAT_N->INSP_SEQ = CQCMISPDAT->INSP_SEQ;
    MEMCPY_AN(CQCMISPDAT_N->CHAR_ID, CQCMISPDAT->CHAR_ID, sizeof(CQCMISPDAT->CHAR_ID));
    CQCMISPDAT_N->CHAR_SEQ = CQCMISPDAT->CHAR_SEQ;
    CQCMISPDAT_N->UNIT_SEQ = CQCMISPDAT->UNIT_SEQ;
    CQCMISPDAT_N->VALUE_SEQ = CQCMISPDAT->VALUE_SEQ;
    MEMCPY_AN(CQCMISPDAT_N->UNIT_ID, CQCMISPDAT->UNIT_ID, sizeof(CQCMISPDAT->UNIT_ID));
    CQCMISPDAT_N->VALUE_TYPE[0] = CQCMISPDAT->VALUE_TYPE;
    CQCMISPDAT_N->VALUE_COUNT = CQCMISPDAT->VALUE_COUNT;
    MEMCPY_AN(CQCMISPDAT_N->VALUE_1, CQCMISPDAT->VALUE_1, sizeof(CQCMISPDAT->VALUE_1));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_2, CQCMISPDAT->VALUE_2, sizeof(CQCMISPDAT->VALUE_2));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_3, CQCMISPDAT->VALUE_3, sizeof(CQCMISPDAT->VALUE_3));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_4, CQCMISPDAT->VALUE_4, sizeof(CQCMISPDAT->VALUE_4));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_5, CQCMISPDAT->VALUE_5, sizeof(CQCMISPDAT->VALUE_5));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_6, CQCMISPDAT->VALUE_6, sizeof(CQCMISPDAT->VALUE_6));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_7, CQCMISPDAT->VALUE_7, sizeof(CQCMISPDAT->VALUE_7));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_8, CQCMISPDAT->VALUE_8, sizeof(CQCMISPDAT->VALUE_8));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_9, CQCMISPDAT->VALUE_9, sizeof(CQCMISPDAT->VALUE_9));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_10, CQCMISPDAT->VALUE_10, sizeof(CQCMISPDAT->VALUE_10));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_11, CQCMISPDAT->VALUE_11, sizeof(CQCMISPDAT->VALUE_11));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_12, CQCMISPDAT->VALUE_12, sizeof(CQCMISPDAT->VALUE_12));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_13, CQCMISPDAT->VALUE_13, sizeof(CQCMISPDAT->VALUE_13));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_14, CQCMISPDAT->VALUE_14, sizeof(CQCMISPDAT->VALUE_14));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_15, CQCMISPDAT->VALUE_15, sizeof(CQCMISPDAT->VALUE_15));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_16, CQCMISPDAT->VALUE_16, sizeof(CQCMISPDAT->VALUE_16));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_17, CQCMISPDAT->VALUE_17, sizeof(CQCMISPDAT->VALUE_17));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_18, CQCMISPDAT->VALUE_18, sizeof(CQCMISPDAT->VALUE_18));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_19, CQCMISPDAT->VALUE_19, sizeof(CQCMISPDAT->VALUE_19));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_20, CQCMISPDAT->VALUE_20, sizeof(CQCMISPDAT->VALUE_20));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_21, CQCMISPDAT->VALUE_21, sizeof(CQCMISPDAT->VALUE_21));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_22, CQCMISPDAT->VALUE_22, sizeof(CQCMISPDAT->VALUE_22));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_23, CQCMISPDAT->VALUE_23, sizeof(CQCMISPDAT->VALUE_23));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_24, CQCMISPDAT->VALUE_24, sizeof(CQCMISPDAT->VALUE_24));
    MEMCPY_AN(CQCMISPDAT_N->VALUE_25, CQCMISPDAT->VALUE_25, sizeof(CQCMISPDAT->VALUE_25));
    CQCMISPDAT_N->SAMPLE_COUNT = CQCMISPDAT->SAMPLE_COUNT;
    MEMCPY_AN(CQCMISPDAT_N->SPEC_OUT_MASK, CQCMISPDAT->SPEC_OUT_MASK, sizeof(CQCMISPDAT->SPEC_OUT_MASK));
    CQCMISPDAT_N->INSP_JUDGE_FLAG[0] = CQCMISPDAT->INSP_JUDGE_FLAG;
    MEMCPY_AN(CQCMISPDAT_N->INSP_JUDGE_TYPE, CQCMISPDAT->INSP_JUDGE_TYPE, sizeof(CQCMISPDAT->INSP_JUDGE_TYPE));
    MEMCPY_AN(CQCMISPDAT_N->INSP_JUDGE_TIME, CQCMISPDAT->INSP_JUDGE_TIME, sizeof(CQCMISPDAT->INSP_JUDGE_TIME));
    MEMCPY_AN(CQCMISPDAT_N->RWK_FLOW, CQCMISPDAT->RWK_FLOW, sizeof(CQCMISPDAT->RWK_FLOW));
    MEMCPY_AN(CQCMISPDAT_N->RWK_OPER, CQCMISPDAT->RWK_OPER, sizeof(CQCMISPDAT->RWK_OPER));
    MEMCPY_AN(CQCMISPDAT_N->CMF_1, CQCMISPDAT->CMF_1, sizeof(CQCMISPDAT->CMF_1));
    MEMCPY_AN(CQCMISPDAT_N->CMF_2, CQCMISPDAT->CMF_2, sizeof(CQCMISPDAT->CMF_2));
    MEMCPY_AN(CQCMISPDAT_N->CMF_3, CQCMISPDAT->CMF_3, sizeof(CQCMISPDAT->CMF_3));
    MEMCPY_AN(CQCMISPDAT_N->CMF_4, CQCMISPDAT->CMF_4, sizeof(CQCMISPDAT->CMF_4));
    MEMCPY_AN(CQCMISPDAT_N->CMF_5, CQCMISPDAT->CMF_5, sizeof(CQCMISPDAT->CMF_5));
    MEMCPY_AN(CQCMISPDAT_N->CMF_6, CQCMISPDAT->CMF_6, sizeof(CQCMISPDAT->CMF_6));
    MEMCPY_AN(CQCMISPDAT_N->CMF_7, CQCMISPDAT->CMF_7, sizeof(CQCMISPDAT->CMF_7));
    MEMCPY_AN(CQCMISPDAT_N->CMF_8, CQCMISPDAT->CMF_8, sizeof(CQCMISPDAT->CMF_8));
    MEMCPY_AN(CQCMISPDAT_N->CMF_9, CQCMISPDAT->CMF_9, sizeof(CQCMISPDAT->CMF_9));
    MEMCPY_AN(CQCMISPDAT_N->CMF_10, CQCMISPDAT->CMF_10, sizeof(CQCMISPDAT->CMF_10));
    MEMCPY_AN(CQCMISPDAT_N->CREATE_USER_ID, CQCMISPDAT->CREATE_USER_ID, sizeof(CQCMISPDAT->CREATE_USER_ID));
    MEMCPY_AN(CQCMISPDAT_N->CREATE_TIME, CQCMISPDAT->CREATE_TIME, sizeof(CQCMISPDAT->CREATE_TIME));
    MEMCPY_AN(CQCMISPDAT_N->UPDATE_USER_ID, CQCMISPDAT->UPDATE_USER_ID, sizeof(CQCMISPDAT->UPDATE_USER_ID));
    MEMCPY_AN(CQCMISPDAT_N->UPDATE_TIME, CQCMISPDAT->UPDATE_TIME, sizeof(CQCMISPDAT->UPDATE_TIME));
}


/* Del Null Function */
void DBU_del_null_cqcmispdat(struct CQCMISPDAT_N_TAG *CQCMISPDAT_N, struct CQCMISPDAT_TAG *CQCMISPDAT)
{
    MEMCPY_DN(CQCMISPDAT->FACTORY, CQCMISPDAT_N->FACTORY, sizeof(CQCMISPDAT->FACTORY));
    MEMCPY_DN(CQCMISPDAT->INSP_ID, CQCMISPDAT_N->INSP_ID, sizeof(CQCMISPDAT->INSP_ID));
    MEMCPY_DN(CQCMISPDAT->COL_SET_ID, CQCMISPDAT_N->COL_SET_ID, sizeof(CQCMISPDAT->COL_SET_ID));
	CQCMISPDAT->COL_SET_VER = CQCMISPDAT_N->COL_SET_VER;
    CQCMISPDAT->INSP_SEQ = CQCMISPDAT_N->INSP_SEQ;
    MEMCPY_DN(CQCMISPDAT->CHAR_ID, CQCMISPDAT_N->CHAR_ID, sizeof(CQCMISPDAT->CHAR_ID));
    CQCMISPDAT->CHAR_SEQ = CQCMISPDAT_N->CHAR_SEQ;
    CQCMISPDAT->UNIT_SEQ = CQCMISPDAT_N->UNIT_SEQ;
    CQCMISPDAT->VALUE_SEQ = CQCMISPDAT_N->VALUE_SEQ;
    MEMCPY_DN(CQCMISPDAT->UNIT_ID, CQCMISPDAT_N->UNIT_ID, sizeof(CQCMISPDAT->UNIT_ID));
    CQCMISPDAT->VALUE_TYPE = CQCMISPDAT_N->VALUE_TYPE[0];
    CQCMISPDAT->VALUE_COUNT = CQCMISPDAT_N->VALUE_COUNT;
    MEMCPY_DN(CQCMISPDAT->VALUE_1, CQCMISPDAT_N->VALUE_1, sizeof(CQCMISPDAT->VALUE_1));
    MEMCPY_DN(CQCMISPDAT->VALUE_2, CQCMISPDAT_N->VALUE_2, sizeof(CQCMISPDAT->VALUE_2));
    MEMCPY_DN(CQCMISPDAT->VALUE_3, CQCMISPDAT_N->VALUE_3, sizeof(CQCMISPDAT->VALUE_3));
    MEMCPY_DN(CQCMISPDAT->VALUE_4, CQCMISPDAT_N->VALUE_4, sizeof(CQCMISPDAT->VALUE_4));
    MEMCPY_DN(CQCMISPDAT->VALUE_5, CQCMISPDAT_N->VALUE_5, sizeof(CQCMISPDAT->VALUE_5));
    MEMCPY_DN(CQCMISPDAT->VALUE_6, CQCMISPDAT_N->VALUE_6, sizeof(CQCMISPDAT->VALUE_6));
    MEMCPY_DN(CQCMISPDAT->VALUE_7, CQCMISPDAT_N->VALUE_7, sizeof(CQCMISPDAT->VALUE_7));
    MEMCPY_DN(CQCMISPDAT->VALUE_8, CQCMISPDAT_N->VALUE_8, sizeof(CQCMISPDAT->VALUE_8));
    MEMCPY_DN(CQCMISPDAT->VALUE_9, CQCMISPDAT_N->VALUE_9, sizeof(CQCMISPDAT->VALUE_9));
    MEMCPY_DN(CQCMISPDAT->VALUE_10, CQCMISPDAT_N->VALUE_10, sizeof(CQCMISPDAT->VALUE_10));
    MEMCPY_DN(CQCMISPDAT->VALUE_11, CQCMISPDAT_N->VALUE_11, sizeof(CQCMISPDAT->VALUE_11));
    MEMCPY_DN(CQCMISPDAT->VALUE_12, CQCMISPDAT_N->VALUE_12, sizeof(CQCMISPDAT->VALUE_12));
    MEMCPY_DN(CQCMISPDAT->VALUE_13, CQCMISPDAT_N->VALUE_13, sizeof(CQCMISPDAT->VALUE_13));
    MEMCPY_DN(CQCMISPDAT->VALUE_14, CQCMISPDAT_N->VALUE_14, sizeof(CQCMISPDAT->VALUE_14));
    MEMCPY_DN(CQCMISPDAT->VALUE_15, CQCMISPDAT_N->VALUE_15, sizeof(CQCMISPDAT->VALUE_15));
    MEMCPY_DN(CQCMISPDAT->VALUE_16, CQCMISPDAT_N->VALUE_16, sizeof(CQCMISPDAT->VALUE_16));
    MEMCPY_DN(CQCMISPDAT->VALUE_17, CQCMISPDAT_N->VALUE_17, sizeof(CQCMISPDAT->VALUE_17));
    MEMCPY_DN(CQCMISPDAT->VALUE_18, CQCMISPDAT_N->VALUE_18, sizeof(CQCMISPDAT->VALUE_18));
    MEMCPY_DN(CQCMISPDAT->VALUE_19, CQCMISPDAT_N->VALUE_19, sizeof(CQCMISPDAT->VALUE_19));
    MEMCPY_DN(CQCMISPDAT->VALUE_20, CQCMISPDAT_N->VALUE_20, sizeof(CQCMISPDAT->VALUE_20));
    MEMCPY_DN(CQCMISPDAT->VALUE_21, CQCMISPDAT_N->VALUE_21, sizeof(CQCMISPDAT->VALUE_21));
    MEMCPY_DN(CQCMISPDAT->VALUE_22, CQCMISPDAT_N->VALUE_22, sizeof(CQCMISPDAT->VALUE_22));
    MEMCPY_DN(CQCMISPDAT->VALUE_23, CQCMISPDAT_N->VALUE_23, sizeof(CQCMISPDAT->VALUE_23));
    MEMCPY_DN(CQCMISPDAT->VALUE_24, CQCMISPDAT_N->VALUE_24, sizeof(CQCMISPDAT->VALUE_24));
    MEMCPY_DN(CQCMISPDAT->VALUE_25, CQCMISPDAT_N->VALUE_25, sizeof(CQCMISPDAT->VALUE_25));
    CQCMISPDAT->SAMPLE_COUNT = CQCMISPDAT_N->SAMPLE_COUNT;
    MEMCPY_DN(CQCMISPDAT->SPEC_OUT_MASK, CQCMISPDAT_N->SPEC_OUT_MASK, sizeof(CQCMISPDAT->SPEC_OUT_MASK));
    CQCMISPDAT->INSP_JUDGE_FLAG = CQCMISPDAT_N->INSP_JUDGE_FLAG[0];
    MEMCPY_DN(CQCMISPDAT->INSP_JUDGE_TYPE, CQCMISPDAT_N->INSP_JUDGE_TYPE, sizeof(CQCMISPDAT->INSP_JUDGE_TYPE));
    MEMCPY_DN(CQCMISPDAT->INSP_JUDGE_TIME, CQCMISPDAT_N->INSP_JUDGE_TIME, sizeof(CQCMISPDAT->INSP_JUDGE_TIME));
    MEMCPY_DN(CQCMISPDAT->RWK_FLOW, CQCMISPDAT_N->RWK_FLOW, sizeof(CQCMISPDAT->RWK_FLOW));
    MEMCPY_DN(CQCMISPDAT->RWK_OPER, CQCMISPDAT_N->RWK_OPER, sizeof(CQCMISPDAT->RWK_OPER));
    MEMCPY_DN(CQCMISPDAT->CMF_1, CQCMISPDAT_N->CMF_1, sizeof(CQCMISPDAT->CMF_1));
    MEMCPY_DN(CQCMISPDAT->CMF_2, CQCMISPDAT_N->CMF_2, sizeof(CQCMISPDAT->CMF_2));
    MEMCPY_DN(CQCMISPDAT->CMF_3, CQCMISPDAT_N->CMF_3, sizeof(CQCMISPDAT->CMF_3));
    MEMCPY_DN(CQCMISPDAT->CMF_4, CQCMISPDAT_N->CMF_4, sizeof(CQCMISPDAT->CMF_4));
    MEMCPY_DN(CQCMISPDAT->CMF_5, CQCMISPDAT_N->CMF_5, sizeof(CQCMISPDAT->CMF_5));
    MEMCPY_DN(CQCMISPDAT->CMF_6, CQCMISPDAT_N->CMF_6, sizeof(CQCMISPDAT->CMF_6));
    MEMCPY_DN(CQCMISPDAT->CMF_7, CQCMISPDAT_N->CMF_7, sizeof(CQCMISPDAT->CMF_7));
    MEMCPY_DN(CQCMISPDAT->CMF_8, CQCMISPDAT_N->CMF_8, sizeof(CQCMISPDAT->CMF_8));
    MEMCPY_DN(CQCMISPDAT->CMF_9, CQCMISPDAT_N->CMF_9, sizeof(CQCMISPDAT->CMF_9));
    MEMCPY_DN(CQCMISPDAT->CMF_10, CQCMISPDAT_N->CMF_10, sizeof(CQCMISPDAT->CMF_10));
    MEMCPY_DN(CQCMISPDAT->CREATE_USER_ID, CQCMISPDAT_N->CREATE_USER_ID, sizeof(CQCMISPDAT->CREATE_USER_ID));
    MEMCPY_DN(CQCMISPDAT->CREATE_TIME, CQCMISPDAT_N->CREATE_TIME, sizeof(CQCMISPDAT->CREATE_TIME));
    MEMCPY_DN(CQCMISPDAT->UPDATE_USER_ID, CQCMISPDAT_N->UPDATE_USER_ID, sizeof(CQCMISPDAT->UPDATE_USER_ID));
    MEMCPY_DN(CQCMISPDAT->UPDATE_TIME, CQCMISPDAT_N->UPDATE_TIME, sizeof(CQCMISPDAT->UPDATE_TIME));
}


