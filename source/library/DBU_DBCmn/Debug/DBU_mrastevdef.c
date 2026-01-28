
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
    "DBU_mrastevdef.pc"
};


static unsigned int sqlctx = 9422491;


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
            void  *sqhstv[284];
   unsigned int   sqhstl[284];
            int   sqhsts[284];
            void  *sqindv[284];
            int   sqinds[284];
   unsigned int   sqharm[284];
   unsigned int   *sqharc[284];
   unsigned short  sqadto[284];
   unsigned short  sqtdso[284];
} sqlstm = {13,284};

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

 static const char *sq0007 = 
"18 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_\
21 ,CHG_OPT_22 ,CHG_OPT_23 ,CHG_OPT_24 ,CHG_OPT_25 ,CHG_OPT_26 ,CHG_OPT_27 ,C\
HG_OPT_28 ,CHG_OPT_29 ,CHG_OPT_30 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_I\
D ,UPDATE_TIME ,CHG_FIELD_1 ,CHG_FIELD_2 ,CHG_FIELD_3 ,CHG_FIELD_4 ,CHG_FIELD\
_5 ,CHG_FIELD_6 ,CHG_FIELD_7 ,CHG_FIELD_8 ,CHG_FIELD_9 ,CHG_FIELD_10 ,CHG_FIE\
LD_11 ,CHG_FIELD_12 ,CHG_FIELD_13 ,CHG_FIELD_14 ,CHG_FIELD_15 ,CHG_FIELD_16 ,\
CHG_FIELD_17 ,CHG_FIELD_18 ,CHG_FIELD_19 ,CHG_FIELD_20 ,CHG_FIELD_21 ,CHG_FIE\
LD_22 ,CHG_FIELD_23 ,CHG_FIELD_24 ,CHG_FIELD_25 ,CHG_FIELD_26 ,CHG_FIELD_27 ,\
CHG_FIELD_28 ,CHG_FIELD_29 ,CHG_FIELD_30  from MRASTEVDEF  order by FACTORY a\
sc ,TOOL_TYPE asc ,TOOL_EVENT_ID asc             ";

 static const char *sq0008 = 
"18 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_\
21 ,CHG_OPT_22 ,CHG_OPT_23 ,CHG_OPT_24 ,CHG_OPT_25 ,CHG_OPT_26 ,CHG_OPT_27 ,C\
HG_OPT_28 ,CHG_OPT_29 ,CHG_OPT_30 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_I\
D ,UPDATE_TIME ,CHG_FIELD_1 ,CHG_FIELD_2 ,CHG_FIELD_3 ,CHG_FIELD_4 ,CHG_FIELD\
_5 ,CHG_FIELD_6 ,CHG_FIELD_7 ,CHG_FIELD_8 ,CHG_FIELD_9 ,CHG_FIELD_10 ,CHG_FIE\
LD_11 ,CHG_FIELD_12 ,CHG_FIELD_13 ,CHG_FIELD_14 ,CHG_FIELD_15 ,CHG_FIELD_16 ,\
CHG_FIELD_17 ,CHG_FIELD_18 ,CHG_FIELD_19 ,CHG_FIELD_20 ,CHG_FIELD_21 ,CHG_FIE\
LD_22 ,CHG_FIELD_23 ,CHG_FIELD_24 ,CHG_FIELD_25 ,CHG_FIELD_26 ,CHG_FIELD_27 ,\
CHG_FIELD_28 ,CHG_FIELD_29 ,CHG_FIELD_30  from MRASTEVDEF where ((FACTORY=:b0\
 and TOOL_TYPE=:b1) and SYSTEM_FLAG<>'Y') order by TOOL_EVENT_ID asc         \
    ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,873,0,0,
5,0,0,1,5347,0,4,46,0,0,284,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1156,0,0,2,5359,0,4,650,0,0,284,3,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2307,0,0,3,104,0,4,1257,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
2338,0,0,4,86,0,2,1295,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
2365,0,0,5,5010,0,3,1326,0,0,281,281,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
3504,0,0,6,5017,0,5,1913,0,0,281,281,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
4643,0,0,7,3773,0,9,2512,0,0,0,0,0,1,0,
4658,0,0,8,3805,0,9,2804,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
4681,0,0,7,0,0,13,2833,0,0,281,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5820,0,0,8,0,0,13,3118,0,0,281,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
6959,0,0,7,0,0,15,3428,0,0,0,0,0,1,0,
6974,0,0,8,0,0,15,3432,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_mrastevdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-11-24 10:29:56
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
void DBU_add_null_mrastevdef(struct MRASTEVDEF_N_TAG *MRASTEVDEF_N, struct MRASTEVDEF_TAG *MRASTEVDEF);
void DBU_del_null_mrastevdef(struct MRASTEVDEF_N_TAG *MRASTEVDEF_N, struct MRASTEVDEF_TAG *MRASTEVDEF);


/* SQL SELECT Function */
void DBU_select_mrastevdef(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TOOL_EVENT_DESC,
                    SYSTEM_FLAG,
                    COLLECT_DEFECT_FLAG,
                    CLEAN_DEFECT_FLAG,
                    CHK_ITEM_1,
                    CHK_ITEM_2,
                    CHK_ITEM_3,
                    CHK_ITEM_4,
                    CHK_ITEM_5,
                    CHK_ITEM_6,
                    CHK_ITEM_7,
                    CHK_ITEM_8,
                    CHK_ITEM_9,
                    CHK_ITEM_10,
                    CHK_ITEM_11,
                    CHK_ITEM_12,
                    CHK_ITEM_13,
                    CHK_ITEM_14,
                    CHK_ITEM_15,
                    CHK_ITEM_16,
                    CHK_ITEM_17,
                    CHK_ITEM_18,
                    CHK_ITEM_19,
                    CHK_ITEM_20,
                    CHK_ITEM_21,
                    CHK_ITEM_22,
                    CHK_ITEM_23,
                    CHK_ITEM_24,
                    CHK_ITEM_25,
                    CHK_ITEM_26,
                    CHK_ITEM_27,
                    CHK_ITEM_28,
                    CHK_ITEM_29,
                    CHK_ITEM_30,
                    CHK_FLAG_1,
                    CHK_FLAG_2,
                    CHK_FLAG_3,
                    CHK_FLAG_4,
                    CHK_FLAG_5,
                    CHK_FLAG_6,
                    CHK_FLAG_7,
                    CHK_FLAG_8,
                    CHK_FLAG_9,
                    CHK_FLAG_10,
                    CHK_FLAG_11,
                    CHK_FLAG_12,
                    CHK_FLAG_13,
                    CHK_FLAG_14,
                    CHK_FLAG_15,
                    CHK_FLAG_16,
                    CHK_FLAG_17,
                    CHK_FLAG_18,
                    CHK_FLAG_19,
                    CHK_FLAG_20,
                    CHK_FLAG_21,
                    CHK_FLAG_22,
                    CHK_FLAG_23,
                    CHK_FLAG_24,
                    CHK_FLAG_25,
                    CHK_FLAG_26,
                    CHK_FLAG_27,
                    CHK_FLAG_28,
                    CHK_FLAG_29,
                    CHK_FLAG_30,
                    CHK_VALUE_1,
                    CHK_VALUE_2,
                    CHK_VALUE_3,
                    CHK_VALUE_4,
                    CHK_VALUE_5,
                    CHK_VALUE_6,
                    CHK_VALUE_7,
                    CHK_VALUE_8,
                    CHK_VALUE_9,
                    CHK_VALUE_10,
                    CHK_VALUE_11,
                    CHK_VALUE_12,
                    CHK_VALUE_13,
                    CHK_VALUE_14,
                    CHK_VALUE_15,
                    CHK_VALUE_16,
                    CHK_VALUE_17,
                    CHK_VALUE_18,
                    CHK_VALUE_19,
                    CHK_VALUE_20,
                    CHK_VALUE_21,
                    CHK_VALUE_22,
                    CHK_VALUE_23,
                    CHK_VALUE_24,
                    CHK_VALUE_25,
                    CHK_VALUE_26,
                    CHK_VALUE_27,
                    CHK_VALUE_28,
                    CHK_VALUE_29,
                    CHK_VALUE_30,
                    CHK_FIELD_1,
                    CHK_FIELD_2,
                    CHK_FIELD_3,
                    CHK_FIELD_4,
                    CHK_FIELD_5,
                    CHK_FIELD_6,
                    CHK_FIELD_7,
                    CHK_FIELD_8,
                    CHK_FIELD_9,
                    CHK_FIELD_10,
                    CHK_FIELD_11,
                    CHK_FIELD_12,
                    CHK_FIELD_13,
                    CHK_FIELD_14,
                    CHK_FIELD_15,
                    CHK_FIELD_16,
                    CHK_FIELD_17,
                    CHK_FIELD_18,
                    CHK_FIELD_19,
                    CHK_FIELD_20,
                    CHK_FIELD_21,
                    CHK_FIELD_22,
                    CHK_FIELD_23,
                    CHK_FIELD_24,
                    CHK_FIELD_25,
                    CHK_FIELD_26,
                    CHK_FIELD_27,
                    CHK_FIELD_28,
                    CHK_FIELD_29,
                    CHK_FIELD_30,
                    CHG_ITEM_1,
                    CHG_ITEM_2,
                    CHG_ITEM_3,
                    CHG_ITEM_4,
                    CHG_ITEM_5,
                    CHG_ITEM_6,
                    CHG_ITEM_7,
                    CHG_ITEM_8,
                    CHG_ITEM_9,
                    CHG_ITEM_10,
                    CHG_ITEM_11,
                    CHG_ITEM_12,
                    CHG_ITEM_13,
                    CHG_ITEM_14,
                    CHG_ITEM_15,
                    CHG_ITEM_16,
                    CHG_ITEM_17,
                    CHG_ITEM_18,
                    CHG_ITEM_19,
                    CHG_ITEM_20,
                    CHG_ITEM_21,
                    CHG_ITEM_22,
                    CHG_ITEM_23,
                    CHG_ITEM_24,
                    CHG_ITEM_25,
                    CHG_ITEM_26,
                    CHG_ITEM_27,
                    CHG_ITEM_28,
                    CHG_ITEM_29,
                    CHG_ITEM_30,
                    CHG_FLAG_1,
                    CHG_FLAG_2,
                    CHG_FLAG_3,
                    CHG_FLAG_4,
                    CHG_FLAG_5,
                    CHG_FLAG_6,
                    CHG_FLAG_7,
                    CHG_FLAG_8,
                    CHG_FLAG_9,
                    CHG_FLAG_10,
                    CHG_FLAG_11,
                    CHG_FLAG_12,
                    CHG_FLAG_13,
                    CHG_FLAG_14,
                    CHG_FLAG_15,
                    CHG_FLAG_16,
                    CHG_FLAG_17,
                    CHG_FLAG_18,
                    CHG_FLAG_19,
                    CHG_FLAG_20,
                    CHG_FLAG_21,
                    CHG_FLAG_22,
                    CHG_FLAG_23,
                    CHG_FLAG_24,
                    CHG_FLAG_25,
                    CHG_FLAG_26,
                    CHG_FLAG_27,
                    CHG_FLAG_28,
                    CHG_FLAG_29,
                    CHG_FLAG_30,
                    CHG_VALUE_1,
                    CHG_VALUE_2,
                    CHG_VALUE_3,
                    CHG_VALUE_4,
                    CHG_VALUE_5,
                    CHG_VALUE_6,
                    CHG_VALUE_7,
                    CHG_VALUE_8,
                    CHG_VALUE_9,
                    CHG_VALUE_10,
                    CHG_VALUE_11,
                    CHG_VALUE_12,
                    CHG_VALUE_13,
                    CHG_VALUE_14,
                    CHG_VALUE_15,
                    CHG_VALUE_16,
                    CHG_VALUE_17,
                    CHG_VALUE_18,
                    CHG_VALUE_19,
                    CHG_VALUE_20,
                    CHG_VALUE_21,
                    CHG_VALUE_22,
                    CHG_VALUE_23,
                    CHG_VALUE_24,
                    CHG_VALUE_25,
                    CHG_VALUE_26,
                    CHG_VALUE_27,
                    CHG_VALUE_28,
                    CHG_VALUE_29,
                    CHG_VALUE_30,
                    CHG_OPT_1,
                    CHG_OPT_2,
                    CHG_OPT_3,
                    CHG_OPT_4,
                    CHG_OPT_5,
                    CHG_OPT_6,
                    CHG_OPT_7,
                    CHG_OPT_8,
                    CHG_OPT_9,
                    CHG_OPT_10,
                    CHG_OPT_11,
                    CHG_OPT_12,
                    CHG_OPT_13,
                    CHG_OPT_14,
                    CHG_OPT_15,
                    CHG_OPT_16,
                    CHG_OPT_17,
                    CHG_OPT_18,
                    CHG_OPT_19,
                    CHG_OPT_20,
                    CHG_OPT_21,
                    CHG_OPT_22,
                    CHG_OPT_23,
                    CHG_OPT_24,
                    CHG_OPT_25,
                    CHG_OPT_26,
                    CHG_OPT_27,
                    CHG_OPT_28,
                    CHG_OPT_29,
                    CHG_OPT_30,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CHG_FIELD_1,
                    CHG_FIELD_2,
                    CHG_FIELD_3,
                    CHG_FIELD_4,
                    CHG_FIELD_5,
                    CHG_FIELD_6,
                    CHG_FIELD_7,
                    CHG_FIELD_8,
                    CHG_FIELD_9,
                    CHG_FIELD_10,
                    CHG_FIELD_11,
                    CHG_FIELD_12,
                    CHG_FIELD_13,
                    CHG_FIELD_14,
                    CHG_FIELD_15,
                    CHG_FIELD_16,
                    CHG_FIELD_17,
                    CHG_FIELD_18,
                    CHG_FIELD_19,
                    CHG_FIELD_20,
                    CHG_FIELD_21,
                    CHG_FIELD_22,
                    CHG_FIELD_23,
                    CHG_FIELD_24,
                    CHG_FIELD_25,
                    CHG_FIELD_26,
                    CHG_FIELD_27,
                    CHG_FIELD_28,
                    CHG_FIELD_29,
                    CHG_FIELD_30
                INTO 
                    :MRASTEVDEF_N.FACTORY,
                    :MRASTEVDEF_N.TOOL_TYPE,
                    :MRASTEVDEF_N.TOOL_EVENT_ID,
                    :MRASTEVDEF_N.TOOL_EVENT_DESC,
                    :MRASTEVDEF_N.SYSTEM_FLAG,
                    :MRASTEVDEF_N.COLLECT_DEFECT_FLAG,
                    :MRASTEVDEF_N.CLEAN_DEFECT_FLAG,
                    :MRASTEVDEF_N.CHK_ITEM_1,
                    :MRASTEVDEF_N.CHK_ITEM_2,
                    :MRASTEVDEF_N.CHK_ITEM_3,
                    :MRASTEVDEF_N.CHK_ITEM_4,
                    :MRASTEVDEF_N.CHK_ITEM_5,
                    :MRASTEVDEF_N.CHK_ITEM_6,
                    :MRASTEVDEF_N.CHK_ITEM_7,
                    :MRASTEVDEF_N.CHK_ITEM_8,
                    :MRASTEVDEF_N.CHK_ITEM_9,
                    :MRASTEVDEF_N.CHK_ITEM_10,
                    :MRASTEVDEF_N.CHK_ITEM_11,
                    :MRASTEVDEF_N.CHK_ITEM_12,
                    :MRASTEVDEF_N.CHK_ITEM_13,
                    :MRASTEVDEF_N.CHK_ITEM_14,
                    :MRASTEVDEF_N.CHK_ITEM_15,
                    :MRASTEVDEF_N.CHK_ITEM_16,
                    :MRASTEVDEF_N.CHK_ITEM_17,
                    :MRASTEVDEF_N.CHK_ITEM_18,
                    :MRASTEVDEF_N.CHK_ITEM_19,
                    :MRASTEVDEF_N.CHK_ITEM_20,
                    :MRASTEVDEF_N.CHK_ITEM_21,
                    :MRASTEVDEF_N.CHK_ITEM_22,
                    :MRASTEVDEF_N.CHK_ITEM_23,
                    :MRASTEVDEF_N.CHK_ITEM_24,
                    :MRASTEVDEF_N.CHK_ITEM_25,
                    :MRASTEVDEF_N.CHK_ITEM_26,
                    :MRASTEVDEF_N.CHK_ITEM_27,
                    :MRASTEVDEF_N.CHK_ITEM_28,
                    :MRASTEVDEF_N.CHK_ITEM_29,
                    :MRASTEVDEF_N.CHK_ITEM_30,
                    :MRASTEVDEF_N.CHK_FLAG_1,
                    :MRASTEVDEF_N.CHK_FLAG_2,
                    :MRASTEVDEF_N.CHK_FLAG_3,
                    :MRASTEVDEF_N.CHK_FLAG_4,
                    :MRASTEVDEF_N.CHK_FLAG_5,
                    :MRASTEVDEF_N.CHK_FLAG_6,
                    :MRASTEVDEF_N.CHK_FLAG_7,
                    :MRASTEVDEF_N.CHK_FLAG_8,
                    :MRASTEVDEF_N.CHK_FLAG_9,
                    :MRASTEVDEF_N.CHK_FLAG_10,
                    :MRASTEVDEF_N.CHK_FLAG_11,
                    :MRASTEVDEF_N.CHK_FLAG_12,
                    :MRASTEVDEF_N.CHK_FLAG_13,
                    :MRASTEVDEF_N.CHK_FLAG_14,
                    :MRASTEVDEF_N.CHK_FLAG_15,
                    :MRASTEVDEF_N.CHK_FLAG_16,
                    :MRASTEVDEF_N.CHK_FLAG_17,
                    :MRASTEVDEF_N.CHK_FLAG_18,
                    :MRASTEVDEF_N.CHK_FLAG_19,
                    :MRASTEVDEF_N.CHK_FLAG_20,
                    :MRASTEVDEF_N.CHK_FLAG_21,
                    :MRASTEVDEF_N.CHK_FLAG_22,
                    :MRASTEVDEF_N.CHK_FLAG_23,
                    :MRASTEVDEF_N.CHK_FLAG_24,
                    :MRASTEVDEF_N.CHK_FLAG_25,
                    :MRASTEVDEF_N.CHK_FLAG_26,
                    :MRASTEVDEF_N.CHK_FLAG_27,
                    :MRASTEVDEF_N.CHK_FLAG_28,
                    :MRASTEVDEF_N.CHK_FLAG_29,
                    :MRASTEVDEF_N.CHK_FLAG_30,
                    :MRASTEVDEF_N.CHK_VALUE_1,
                    :MRASTEVDEF_N.CHK_VALUE_2,
                    :MRASTEVDEF_N.CHK_VALUE_3,
                    :MRASTEVDEF_N.CHK_VALUE_4,
                    :MRASTEVDEF_N.CHK_VALUE_5,
                    :MRASTEVDEF_N.CHK_VALUE_6,
                    :MRASTEVDEF_N.CHK_VALUE_7,
                    :MRASTEVDEF_N.CHK_VALUE_8,
                    :MRASTEVDEF_N.CHK_VALUE_9,
                    :MRASTEVDEF_N.CHK_VALUE_10,
                    :MRASTEVDEF_N.CHK_VALUE_11,
                    :MRASTEVDEF_N.CHK_VALUE_12,
                    :MRASTEVDEF_N.CHK_VALUE_13,
                    :MRASTEVDEF_N.CHK_VALUE_14,
                    :MRASTEVDEF_N.CHK_VALUE_15,
                    :MRASTEVDEF_N.CHK_VALUE_16,
                    :MRASTEVDEF_N.CHK_VALUE_17,
                    :MRASTEVDEF_N.CHK_VALUE_18,
                    :MRASTEVDEF_N.CHK_VALUE_19,
                    :MRASTEVDEF_N.CHK_VALUE_20,
                    :MRASTEVDEF_N.CHK_VALUE_21,
                    :MRASTEVDEF_N.CHK_VALUE_22,
                    :MRASTEVDEF_N.CHK_VALUE_23,
                    :MRASTEVDEF_N.CHK_VALUE_24,
                    :MRASTEVDEF_N.CHK_VALUE_25,
                    :MRASTEVDEF_N.CHK_VALUE_26,
                    :MRASTEVDEF_N.CHK_VALUE_27,
                    :MRASTEVDEF_N.CHK_VALUE_28,
                    :MRASTEVDEF_N.CHK_VALUE_29,
                    :MRASTEVDEF_N.CHK_VALUE_30,
                    :MRASTEVDEF_N.CHK_FIELD_1,
                    :MRASTEVDEF_N.CHK_FIELD_2,
                    :MRASTEVDEF_N.CHK_FIELD_3,
                    :MRASTEVDEF_N.CHK_FIELD_4,
                    :MRASTEVDEF_N.CHK_FIELD_5,
                    :MRASTEVDEF_N.CHK_FIELD_6,
                    :MRASTEVDEF_N.CHK_FIELD_7,
                    :MRASTEVDEF_N.CHK_FIELD_8,
                    :MRASTEVDEF_N.CHK_FIELD_9,
                    :MRASTEVDEF_N.CHK_FIELD_10,
                    :MRASTEVDEF_N.CHK_FIELD_11,
                    :MRASTEVDEF_N.CHK_FIELD_12,
                    :MRASTEVDEF_N.CHK_FIELD_13,
                    :MRASTEVDEF_N.CHK_FIELD_14,
                    :MRASTEVDEF_N.CHK_FIELD_15,
                    :MRASTEVDEF_N.CHK_FIELD_16,
                    :MRASTEVDEF_N.CHK_FIELD_17,
                    :MRASTEVDEF_N.CHK_FIELD_18,
                    :MRASTEVDEF_N.CHK_FIELD_19,
                    :MRASTEVDEF_N.CHK_FIELD_20,
                    :MRASTEVDEF_N.CHK_FIELD_21,
                    :MRASTEVDEF_N.CHK_FIELD_22,
                    :MRASTEVDEF_N.CHK_FIELD_23,
                    :MRASTEVDEF_N.CHK_FIELD_24,
                    :MRASTEVDEF_N.CHK_FIELD_25,
                    :MRASTEVDEF_N.CHK_FIELD_26,
                    :MRASTEVDEF_N.CHK_FIELD_27,
                    :MRASTEVDEF_N.CHK_FIELD_28,
                    :MRASTEVDEF_N.CHK_FIELD_29,
                    :MRASTEVDEF_N.CHK_FIELD_30,
                    :MRASTEVDEF_N.CHG_ITEM_1,
                    :MRASTEVDEF_N.CHG_ITEM_2,
                    :MRASTEVDEF_N.CHG_ITEM_3,
                    :MRASTEVDEF_N.CHG_ITEM_4,
                    :MRASTEVDEF_N.CHG_ITEM_5,
                    :MRASTEVDEF_N.CHG_ITEM_6,
                    :MRASTEVDEF_N.CHG_ITEM_7,
                    :MRASTEVDEF_N.CHG_ITEM_8,
                    :MRASTEVDEF_N.CHG_ITEM_9,
                    :MRASTEVDEF_N.CHG_ITEM_10,
                    :MRASTEVDEF_N.CHG_ITEM_11,
                    :MRASTEVDEF_N.CHG_ITEM_12,
                    :MRASTEVDEF_N.CHG_ITEM_13,
                    :MRASTEVDEF_N.CHG_ITEM_14,
                    :MRASTEVDEF_N.CHG_ITEM_15,
                    :MRASTEVDEF_N.CHG_ITEM_16,
                    :MRASTEVDEF_N.CHG_ITEM_17,
                    :MRASTEVDEF_N.CHG_ITEM_18,
                    :MRASTEVDEF_N.CHG_ITEM_19,
                    :MRASTEVDEF_N.CHG_ITEM_20,
                    :MRASTEVDEF_N.CHG_ITEM_21,
                    :MRASTEVDEF_N.CHG_ITEM_22,
                    :MRASTEVDEF_N.CHG_ITEM_23,
                    :MRASTEVDEF_N.CHG_ITEM_24,
                    :MRASTEVDEF_N.CHG_ITEM_25,
                    :MRASTEVDEF_N.CHG_ITEM_26,
                    :MRASTEVDEF_N.CHG_ITEM_27,
                    :MRASTEVDEF_N.CHG_ITEM_28,
                    :MRASTEVDEF_N.CHG_ITEM_29,
                    :MRASTEVDEF_N.CHG_ITEM_30,
                    :MRASTEVDEF_N.CHG_FLAG_1,
                    :MRASTEVDEF_N.CHG_FLAG_2,
                    :MRASTEVDEF_N.CHG_FLAG_3,
                    :MRASTEVDEF_N.CHG_FLAG_4,
                    :MRASTEVDEF_N.CHG_FLAG_5,
                    :MRASTEVDEF_N.CHG_FLAG_6,
                    :MRASTEVDEF_N.CHG_FLAG_7,
                    :MRASTEVDEF_N.CHG_FLAG_8,
                    :MRASTEVDEF_N.CHG_FLAG_9,
                    :MRASTEVDEF_N.CHG_FLAG_10,
                    :MRASTEVDEF_N.CHG_FLAG_11,
                    :MRASTEVDEF_N.CHG_FLAG_12,
                    :MRASTEVDEF_N.CHG_FLAG_13,
                    :MRASTEVDEF_N.CHG_FLAG_14,
                    :MRASTEVDEF_N.CHG_FLAG_15,
                    :MRASTEVDEF_N.CHG_FLAG_16,
                    :MRASTEVDEF_N.CHG_FLAG_17,
                    :MRASTEVDEF_N.CHG_FLAG_18,
                    :MRASTEVDEF_N.CHG_FLAG_19,
                    :MRASTEVDEF_N.CHG_FLAG_20,
                    :MRASTEVDEF_N.CHG_FLAG_21,
                    :MRASTEVDEF_N.CHG_FLAG_22,
                    :MRASTEVDEF_N.CHG_FLAG_23,
                    :MRASTEVDEF_N.CHG_FLAG_24,
                    :MRASTEVDEF_N.CHG_FLAG_25,
                    :MRASTEVDEF_N.CHG_FLAG_26,
                    :MRASTEVDEF_N.CHG_FLAG_27,
                    :MRASTEVDEF_N.CHG_FLAG_28,
                    :MRASTEVDEF_N.CHG_FLAG_29,
                    :MRASTEVDEF_N.CHG_FLAG_30,
                    :MRASTEVDEF_N.CHG_VALUE_1,
                    :MRASTEVDEF_N.CHG_VALUE_2,
                    :MRASTEVDEF_N.CHG_VALUE_3,
                    :MRASTEVDEF_N.CHG_VALUE_4,
                    :MRASTEVDEF_N.CHG_VALUE_5,
                    :MRASTEVDEF_N.CHG_VALUE_6,
                    :MRASTEVDEF_N.CHG_VALUE_7,
                    :MRASTEVDEF_N.CHG_VALUE_8,
                    :MRASTEVDEF_N.CHG_VALUE_9,
                    :MRASTEVDEF_N.CHG_VALUE_10,
                    :MRASTEVDEF_N.CHG_VALUE_11,
                    :MRASTEVDEF_N.CHG_VALUE_12,
                    :MRASTEVDEF_N.CHG_VALUE_13,
                    :MRASTEVDEF_N.CHG_VALUE_14,
                    :MRASTEVDEF_N.CHG_VALUE_15,
                    :MRASTEVDEF_N.CHG_VALUE_16,
                    :MRASTEVDEF_N.CHG_VALUE_17,
                    :MRASTEVDEF_N.CHG_VALUE_18,
                    :MRASTEVDEF_N.CHG_VALUE_19,
                    :MRASTEVDEF_N.CHG_VALUE_20,
                    :MRASTEVDEF_N.CHG_VALUE_21,
                    :MRASTEVDEF_N.CHG_VALUE_22,
                    :MRASTEVDEF_N.CHG_VALUE_23,
                    :MRASTEVDEF_N.CHG_VALUE_24,
                    :MRASTEVDEF_N.CHG_VALUE_25,
                    :MRASTEVDEF_N.CHG_VALUE_26,
                    :MRASTEVDEF_N.CHG_VALUE_27,
                    :MRASTEVDEF_N.CHG_VALUE_28,
                    :MRASTEVDEF_N.CHG_VALUE_29,
                    :MRASTEVDEF_N.CHG_VALUE_30,
                    :MRASTEVDEF_N.CHG_OPT_1,
                    :MRASTEVDEF_N.CHG_OPT_2,
                    :MRASTEVDEF_N.CHG_OPT_3,
                    :MRASTEVDEF_N.CHG_OPT_4,
                    :MRASTEVDEF_N.CHG_OPT_5,
                    :MRASTEVDEF_N.CHG_OPT_6,
                    :MRASTEVDEF_N.CHG_OPT_7,
                    :MRASTEVDEF_N.CHG_OPT_8,
                    :MRASTEVDEF_N.CHG_OPT_9,
                    :MRASTEVDEF_N.CHG_OPT_10,
                    :MRASTEVDEF_N.CHG_OPT_11,
                    :MRASTEVDEF_N.CHG_OPT_12,
                    :MRASTEVDEF_N.CHG_OPT_13,
                    :MRASTEVDEF_N.CHG_OPT_14,
                    :MRASTEVDEF_N.CHG_OPT_15,
                    :MRASTEVDEF_N.CHG_OPT_16,
                    :MRASTEVDEF_N.CHG_OPT_17,
                    :MRASTEVDEF_N.CHG_OPT_18,
                    :MRASTEVDEF_N.CHG_OPT_19,
                    :MRASTEVDEF_N.CHG_OPT_20,
                    :MRASTEVDEF_N.CHG_OPT_21,
                    :MRASTEVDEF_N.CHG_OPT_22,
                    :MRASTEVDEF_N.CHG_OPT_23,
                    :MRASTEVDEF_N.CHG_OPT_24,
                    :MRASTEVDEF_N.CHG_OPT_25,
                    :MRASTEVDEF_N.CHG_OPT_26,
                    :MRASTEVDEF_N.CHG_OPT_27,
                    :MRASTEVDEF_N.CHG_OPT_28,
                    :MRASTEVDEF_N.CHG_OPT_29,
                    :MRASTEVDEF_N.CHG_OPT_30,
                    :MRASTEVDEF_N.CREATE_USER_ID,
                    :MRASTEVDEF_N.CREATE_TIME,
                    :MRASTEVDEF_N.UPDATE_USER_ID,
                    :MRASTEVDEF_N.UPDATE_TIME,
                    :MRASTEVDEF_N.CHG_FIELD_1,
                    :MRASTEVDEF_N.CHG_FIELD_2,
                    :MRASTEVDEF_N.CHG_FIELD_3,
                    :MRASTEVDEF_N.CHG_FIELD_4,
                    :MRASTEVDEF_N.CHG_FIELD_5,
                    :MRASTEVDEF_N.CHG_FIELD_6,
                    :MRASTEVDEF_N.CHG_FIELD_7,
                    :MRASTEVDEF_N.CHG_FIELD_8,
                    :MRASTEVDEF_N.CHG_FIELD_9,
                    :MRASTEVDEF_N.CHG_FIELD_10,
                    :MRASTEVDEF_N.CHG_FIELD_11,
                    :MRASTEVDEF_N.CHG_FIELD_12,
                    :MRASTEVDEF_N.CHG_FIELD_13,
                    :MRASTEVDEF_N.CHG_FIELD_14,
                    :MRASTEVDEF_N.CHG_FIELD_15,
                    :MRASTEVDEF_N.CHG_FIELD_16,
                    :MRASTEVDEF_N.CHG_FIELD_17,
                    :MRASTEVDEF_N.CHG_FIELD_18,
                    :MRASTEVDEF_N.CHG_FIELD_19,
                    :MRASTEVDEF_N.CHG_FIELD_20,
                    :MRASTEVDEF_N.CHG_FIELD_21,
                    :MRASTEVDEF_N.CHG_FIELD_22,
                    :MRASTEVDEF_N.CHG_FIELD_23,
                    :MRASTEVDEF_N.CHG_FIELD_24,
                    :MRASTEVDEF_N.CHG_FIELD_25,
                    :MRASTEVDEF_N.CHG_FIELD_26,
                    :MRASTEVDEF_N.CHG_FIELD_27,
                    :MRASTEVDEF_N.CHG_FIELD_28,
                    :MRASTEVDEF_N.CHG_FIELD_29,
                    :MRASTEVDEF_N.CHG_FIELD_30
                FROM MRASTEVDEF
                WHERE FACTORY = :MRASTEVDEF_N.FACTORY
                    AND TOOL_TYPE = :MRASTEVDEF_N.TOOL_TYPE
                    AND TOOL_EVENT_ID = :MRASTEVDEF_N.TOOL_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_TYPE ,TOOL_EVENT_ID ,TOOL_EVENT_DESC ,SY\
STEM_FLAG ,COLLECT_DEFECT_FLAG ,CLEAN_DEFECT_FLAG ,CHK_ITEM_1 ,CHK_ITEM_2 ,C\
HK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_ITEM_7 ,CHK_ITEM_8 ,CHK_I\
TEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITEM_13 ,CHK_ITEM_14 ,CHK_\
ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_ITEM_19 ,CHK_ITEM_20 ,CH\
K_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK_ITEM_25 ,CHK_ITEM_26 ,\
CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,CHK_FLAG_1 ,CHK_FLAG_2 ,\
CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_FLAG_7 ,CHK_FLAG_8 ,CHK_\
FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FLAG_13 ,CHK_FLAG_14 ,CHK\
_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_FLAG_19 ,CHK_FLAG_20 ,C\
HK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CHK_FLAG_25 ,CHK_FLAG_26 \
,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,CHK_VALUE_1 ,CHK_VALUE_\
2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6 ,CHK_VALUE_7 ,CHK_VALU\
E_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_V");
            sqlbuft((void **)0,
              "ALUE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CHK_VALUE_\
16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VALUE_20 ,CHK_VALUE_21 ,CH\
K_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 ,CHK_VALUE_26 ,CHK_VALU\
E_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_FIELD_1 ,CHK_FIELD_2 ,CH\
K_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK_FIELD_7 ,CHK_FIELD_8 ,\
CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12 ,CHK_FIELD_13 ,CHK_FIE\
LD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_FIELD_18 ,CHK_FIELD_19 \
,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_23 ,CHK_FIELD_24 ,CHK_F\
IELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CHK_FIELD_29 ,CHK_FIELD_3\
0 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CHG_ITEM_5 ,CHG_ITEM_6 ,C\
HG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_ITEM_11 ,CHG_ITEM_12 ,CH\
G_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG_ITEM_17 ,CHG_ITEM_18 ,\
CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,CHG_ITEM_23 ,CHG_ITEM_24\
 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_2");
            sqlbuft((void **)0,
              "8 ,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,CHG_FLAG\
_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,CHG_FLAG_8 ,CHG_FLAG_9 ,\
CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,CHG_FLAG_14 ,CHG_FLAG_15\
 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 ,CHG_FLAG_20 ,CHG_FLAG_\
21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_25 ,CHG_FLAG_26 ,CHG_FLA\
G_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALUE_1 ,CHG_VALUE_2 ,CHG_V\
ALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VALUE_7 ,CHG_VALUE_8 ,CHG\
_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,CHG_VALUE_13 ,CHG_VALUE_\
14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VALUE_18 ,CHG_VALUE_19 ,CH\
G_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 ,CHG_VALUE_24 ,CHG_VALU\
E_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_VALUE_29 ,CHG_VALUE_30 ,\
CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5 ,CHG_OPT_6 ,CHG_OPT_7 \
,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OPT_12 ,CHG_OPT_13 ,CHG_O\
PT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_");
            sqlbuft((void **)0,
              "18 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_21 ,CHG_OPT_22 ,CHG_OPT_2\
3 ,CHG_OPT_24 ,CHG_OPT_25 ,CHG_OPT_26 ,CHG_OPT_27 ,CHG_OPT_28 ,CHG_OPT_29 ,C\
HG_OPT_30 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,CHG_FIE\
LD_1 ,CHG_FIELD_2 ,CHG_FIELD_3 ,CHG_FIELD_4 ,CHG_FIELD_5 ,CHG_FIELD_6 ,CHG_F\
IELD_7 ,CHG_FIELD_8 ,CHG_FIELD_9 ,CHG_FIELD_10 ,CHG_FIELD_11 ,CHG_FIELD_12 ,\
CHG_FIELD_13 ,CHG_FIELD_14 ,CHG_FIELD_15 ,CHG_FIELD_16 ,CHG_FIELD_17 ,CHG_FI\
ELD_18 ,CHG_FIELD_19 ,CHG_FIELD_20 ,CHG_FIELD_21 ,CHG_FIELD_22 ,CHG_FIELD_23\
 ,CHG_FIELD_24 ,CHG_FIELD_25 ,CHG_FIELD_26 ,CHG_FIELD_27 ,CHG_FIELD_28 ,CHG_\
FIELD_29 ,CHG_FIELD_30 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b1\
1,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26\
,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,\
:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:\
b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b\
72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b8");
            sqlbuft((void **)0,
              "2,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94\
,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b\
108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b120,\
:b121,:b122,:b123,:b124,:b125,:b126,:b127,:b128,:b129,:b130,:b131,:b132,:b13\
3,:b134,:b135,:b136,:b137,:b138,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b\
146,:b147,:b148,:b149,:b150,:b151,:b152,:b153,:b154,:b155,:b156,:b157,:b158,\
:b159,:b160,:b161,:b162,:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170,:b17\
1,:b172,:b173,:b174,:b175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b\
184,:b185,:b186,:b187,:b188,:b189,:b190,:b191,:b192,:b193,:b194,:b195,:b196,\
:b197,:b198,:b199,:b200,:b201,:b202,:b203,:b204,:b205,:b206,:b207,:b208,:b20\
9,:b210,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b218,:b219,:b220,:b221,:b\
222,:b223,:b224,:b225,:b226,:b227,:b228,:b229,:b230,:b231,:b232,:b233,:b234,\
:b235,:b236,:b237,:b238,:b239,:b240,:b241,:b242,:b243,:b244,:b245,:b246,:b24\
7,:b248,:b249,:b250,:b251,:b252,:b253,:b254,:b255,:");
            sqlstm.stmt = "b256,:b257,:b258,:b259,:b260,:b261,:b262,:b263,:\
b264,:b265,:b266,:b267,:b268,:b269,:b270,:b271,:b272,:b273,:b274,:b275,:b276,\
:b277,:b278,:b279,:b280  from MRASTEVDEF where ((FACTORY=:b0 and TOOL_TYPE=:b\
1) and TOOL_EVENT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )13;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTEVDEF_N.COLLECT_DEFECT_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTEVDEF_N.CLEAN_DEFECT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[154] = (unsigned int  )31;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[155] = (unsigned int  )31;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[156] = (unsigned int  )31;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[184] = (unsigned int  )2;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[186] = (unsigned int  )2;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[214] = (unsigned int  )31;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[215] = (unsigned int  )31;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[216] = (unsigned int  )31;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASTEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASTEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASTEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASTEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASTEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASTEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASTEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASTEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASTEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASTEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASTEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASTEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASTEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASTEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASTEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASTEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASTEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASTEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASTEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASTEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASTEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASTEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASTEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASTEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASTEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASTEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASTEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASTEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[244] = (unsigned int  )2;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASTEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[245] = (unsigned int  )2;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASTEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[246] = (unsigned int  )2;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASTEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[247] = (unsigned int  )21;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASTEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[248] = (unsigned int  )15;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASTEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[249] = (unsigned int  )21;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
            sqlstm.sqhstv[250] = (         void  *)(MRASTEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[250] = (unsigned int  )15;
            sqlstm.sqhsts[250] = (         int  )0;
            sqlstm.sqindv[250] = (         void  *)0;
            sqlstm.sqinds[250] = (         int  )0;
            sqlstm.sqharm[250] = (unsigned int  )0;
            sqlstm.sqadto[250] = (unsigned short )0;
            sqlstm.sqtdso[250] = (unsigned short )0;
            sqlstm.sqhstv[251] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_1);
            sqlstm.sqhstl[251] = (unsigned int  )31;
            sqlstm.sqhsts[251] = (         int  )0;
            sqlstm.sqindv[251] = (         void  *)0;
            sqlstm.sqinds[251] = (         int  )0;
            sqlstm.sqharm[251] = (unsigned int  )0;
            sqlstm.sqadto[251] = (unsigned short )0;
            sqlstm.sqtdso[251] = (unsigned short )0;
            sqlstm.sqhstv[252] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_2);
            sqlstm.sqhstl[252] = (unsigned int  )31;
            sqlstm.sqhsts[252] = (         int  )0;
            sqlstm.sqindv[252] = (         void  *)0;
            sqlstm.sqinds[252] = (         int  )0;
            sqlstm.sqharm[252] = (unsigned int  )0;
            sqlstm.sqadto[252] = (unsigned short )0;
            sqlstm.sqtdso[252] = (unsigned short )0;
            sqlstm.sqhstv[253] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_3);
            sqlstm.sqhstl[253] = (unsigned int  )31;
            sqlstm.sqhsts[253] = (         int  )0;
            sqlstm.sqindv[253] = (         void  *)0;
            sqlstm.sqinds[253] = (         int  )0;
            sqlstm.sqharm[253] = (unsigned int  )0;
            sqlstm.sqadto[253] = (unsigned short )0;
            sqlstm.sqtdso[253] = (unsigned short )0;
            sqlstm.sqhstv[254] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_4);
            sqlstm.sqhstl[254] = (unsigned int  )31;
            sqlstm.sqhsts[254] = (         int  )0;
            sqlstm.sqindv[254] = (         void  *)0;
            sqlstm.sqinds[254] = (         int  )0;
            sqlstm.sqharm[254] = (unsigned int  )0;
            sqlstm.sqadto[254] = (unsigned short )0;
            sqlstm.sqtdso[254] = (unsigned short )0;
            sqlstm.sqhstv[255] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_5);
            sqlstm.sqhstl[255] = (unsigned int  )31;
            sqlstm.sqhsts[255] = (         int  )0;
            sqlstm.sqindv[255] = (         void  *)0;
            sqlstm.sqinds[255] = (         int  )0;
            sqlstm.sqharm[255] = (unsigned int  )0;
            sqlstm.sqadto[255] = (unsigned short )0;
            sqlstm.sqtdso[255] = (unsigned short )0;
            sqlstm.sqhstv[256] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_6);
            sqlstm.sqhstl[256] = (unsigned int  )31;
            sqlstm.sqhsts[256] = (         int  )0;
            sqlstm.sqindv[256] = (         void  *)0;
            sqlstm.sqinds[256] = (         int  )0;
            sqlstm.sqharm[256] = (unsigned int  )0;
            sqlstm.sqadto[256] = (unsigned short )0;
            sqlstm.sqtdso[256] = (unsigned short )0;
            sqlstm.sqhstv[257] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_7);
            sqlstm.sqhstl[257] = (unsigned int  )31;
            sqlstm.sqhsts[257] = (         int  )0;
            sqlstm.sqindv[257] = (         void  *)0;
            sqlstm.sqinds[257] = (         int  )0;
            sqlstm.sqharm[257] = (unsigned int  )0;
            sqlstm.sqadto[257] = (unsigned short )0;
            sqlstm.sqtdso[257] = (unsigned short )0;
            sqlstm.sqhstv[258] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_8);
            sqlstm.sqhstl[258] = (unsigned int  )31;
            sqlstm.sqhsts[258] = (         int  )0;
            sqlstm.sqindv[258] = (         void  *)0;
            sqlstm.sqinds[258] = (         int  )0;
            sqlstm.sqharm[258] = (unsigned int  )0;
            sqlstm.sqadto[258] = (unsigned short )0;
            sqlstm.sqtdso[258] = (unsigned short )0;
            sqlstm.sqhstv[259] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_9);
            sqlstm.sqhstl[259] = (unsigned int  )31;
            sqlstm.sqhsts[259] = (         int  )0;
            sqlstm.sqindv[259] = (         void  *)0;
            sqlstm.sqinds[259] = (         int  )0;
            sqlstm.sqharm[259] = (unsigned int  )0;
            sqlstm.sqadto[259] = (unsigned short )0;
            sqlstm.sqtdso[259] = (unsigned short )0;
            sqlstm.sqhstv[260] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_10);
            sqlstm.sqhstl[260] = (unsigned int  )31;
            sqlstm.sqhsts[260] = (         int  )0;
            sqlstm.sqindv[260] = (         void  *)0;
            sqlstm.sqinds[260] = (         int  )0;
            sqlstm.sqharm[260] = (unsigned int  )0;
            sqlstm.sqadto[260] = (unsigned short )0;
            sqlstm.sqtdso[260] = (unsigned short )0;
            sqlstm.sqhstv[261] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_11);
            sqlstm.sqhstl[261] = (unsigned int  )31;
            sqlstm.sqhsts[261] = (         int  )0;
            sqlstm.sqindv[261] = (         void  *)0;
            sqlstm.sqinds[261] = (         int  )0;
            sqlstm.sqharm[261] = (unsigned int  )0;
            sqlstm.sqadto[261] = (unsigned short )0;
            sqlstm.sqtdso[261] = (unsigned short )0;
            sqlstm.sqhstv[262] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_12);
            sqlstm.sqhstl[262] = (unsigned int  )31;
            sqlstm.sqhsts[262] = (         int  )0;
            sqlstm.sqindv[262] = (         void  *)0;
            sqlstm.sqinds[262] = (         int  )0;
            sqlstm.sqharm[262] = (unsigned int  )0;
            sqlstm.sqadto[262] = (unsigned short )0;
            sqlstm.sqtdso[262] = (unsigned short )0;
            sqlstm.sqhstv[263] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_13);
            sqlstm.sqhstl[263] = (unsigned int  )31;
            sqlstm.sqhsts[263] = (         int  )0;
            sqlstm.sqindv[263] = (         void  *)0;
            sqlstm.sqinds[263] = (         int  )0;
            sqlstm.sqharm[263] = (unsigned int  )0;
            sqlstm.sqadto[263] = (unsigned short )0;
            sqlstm.sqtdso[263] = (unsigned short )0;
            sqlstm.sqhstv[264] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_14);
            sqlstm.sqhstl[264] = (unsigned int  )31;
            sqlstm.sqhsts[264] = (         int  )0;
            sqlstm.sqindv[264] = (         void  *)0;
            sqlstm.sqinds[264] = (         int  )0;
            sqlstm.sqharm[264] = (unsigned int  )0;
            sqlstm.sqadto[264] = (unsigned short )0;
            sqlstm.sqtdso[264] = (unsigned short )0;
            sqlstm.sqhstv[265] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_15);
            sqlstm.sqhstl[265] = (unsigned int  )31;
            sqlstm.sqhsts[265] = (         int  )0;
            sqlstm.sqindv[265] = (         void  *)0;
            sqlstm.sqinds[265] = (         int  )0;
            sqlstm.sqharm[265] = (unsigned int  )0;
            sqlstm.sqadto[265] = (unsigned short )0;
            sqlstm.sqtdso[265] = (unsigned short )0;
            sqlstm.sqhstv[266] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_16);
            sqlstm.sqhstl[266] = (unsigned int  )31;
            sqlstm.sqhsts[266] = (         int  )0;
            sqlstm.sqindv[266] = (         void  *)0;
            sqlstm.sqinds[266] = (         int  )0;
            sqlstm.sqharm[266] = (unsigned int  )0;
            sqlstm.sqadto[266] = (unsigned short )0;
            sqlstm.sqtdso[266] = (unsigned short )0;
            sqlstm.sqhstv[267] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_17);
            sqlstm.sqhstl[267] = (unsigned int  )31;
            sqlstm.sqhsts[267] = (         int  )0;
            sqlstm.sqindv[267] = (         void  *)0;
            sqlstm.sqinds[267] = (         int  )0;
            sqlstm.sqharm[267] = (unsigned int  )0;
            sqlstm.sqadto[267] = (unsigned short )0;
            sqlstm.sqtdso[267] = (unsigned short )0;
            sqlstm.sqhstv[268] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_18);
            sqlstm.sqhstl[268] = (unsigned int  )31;
            sqlstm.sqhsts[268] = (         int  )0;
            sqlstm.sqindv[268] = (         void  *)0;
            sqlstm.sqinds[268] = (         int  )0;
            sqlstm.sqharm[268] = (unsigned int  )0;
            sqlstm.sqadto[268] = (unsigned short )0;
            sqlstm.sqtdso[268] = (unsigned short )0;
            sqlstm.sqhstv[269] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_19);
            sqlstm.sqhstl[269] = (unsigned int  )31;
            sqlstm.sqhsts[269] = (         int  )0;
            sqlstm.sqindv[269] = (         void  *)0;
            sqlstm.sqinds[269] = (         int  )0;
            sqlstm.sqharm[269] = (unsigned int  )0;
            sqlstm.sqadto[269] = (unsigned short )0;
            sqlstm.sqtdso[269] = (unsigned short )0;
            sqlstm.sqhstv[270] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_20);
            sqlstm.sqhstl[270] = (unsigned int  )31;
            sqlstm.sqhsts[270] = (         int  )0;
            sqlstm.sqindv[270] = (         void  *)0;
            sqlstm.sqinds[270] = (         int  )0;
            sqlstm.sqharm[270] = (unsigned int  )0;
            sqlstm.sqadto[270] = (unsigned short )0;
            sqlstm.sqtdso[270] = (unsigned short )0;
            sqlstm.sqhstv[271] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_21);
            sqlstm.sqhstl[271] = (unsigned int  )31;
            sqlstm.sqhsts[271] = (         int  )0;
            sqlstm.sqindv[271] = (         void  *)0;
            sqlstm.sqinds[271] = (         int  )0;
            sqlstm.sqharm[271] = (unsigned int  )0;
            sqlstm.sqadto[271] = (unsigned short )0;
            sqlstm.sqtdso[271] = (unsigned short )0;
            sqlstm.sqhstv[272] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_22);
            sqlstm.sqhstl[272] = (unsigned int  )31;
            sqlstm.sqhsts[272] = (         int  )0;
            sqlstm.sqindv[272] = (         void  *)0;
            sqlstm.sqinds[272] = (         int  )0;
            sqlstm.sqharm[272] = (unsigned int  )0;
            sqlstm.sqadto[272] = (unsigned short )0;
            sqlstm.sqtdso[272] = (unsigned short )0;
            sqlstm.sqhstv[273] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_23);
            sqlstm.sqhstl[273] = (unsigned int  )31;
            sqlstm.sqhsts[273] = (         int  )0;
            sqlstm.sqindv[273] = (         void  *)0;
            sqlstm.sqinds[273] = (         int  )0;
            sqlstm.sqharm[273] = (unsigned int  )0;
            sqlstm.sqadto[273] = (unsigned short )0;
            sqlstm.sqtdso[273] = (unsigned short )0;
            sqlstm.sqhstv[274] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_24);
            sqlstm.sqhstl[274] = (unsigned int  )31;
            sqlstm.sqhsts[274] = (         int  )0;
            sqlstm.sqindv[274] = (         void  *)0;
            sqlstm.sqinds[274] = (         int  )0;
            sqlstm.sqharm[274] = (unsigned int  )0;
            sqlstm.sqadto[274] = (unsigned short )0;
            sqlstm.sqtdso[274] = (unsigned short )0;
            sqlstm.sqhstv[275] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_25);
            sqlstm.sqhstl[275] = (unsigned int  )31;
            sqlstm.sqhsts[275] = (         int  )0;
            sqlstm.sqindv[275] = (         void  *)0;
            sqlstm.sqinds[275] = (         int  )0;
            sqlstm.sqharm[275] = (unsigned int  )0;
            sqlstm.sqadto[275] = (unsigned short )0;
            sqlstm.sqtdso[275] = (unsigned short )0;
            sqlstm.sqhstv[276] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_26);
            sqlstm.sqhstl[276] = (unsigned int  )31;
            sqlstm.sqhsts[276] = (         int  )0;
            sqlstm.sqindv[276] = (         void  *)0;
            sqlstm.sqinds[276] = (         int  )0;
            sqlstm.sqharm[276] = (unsigned int  )0;
            sqlstm.sqadto[276] = (unsigned short )0;
            sqlstm.sqtdso[276] = (unsigned short )0;
            sqlstm.sqhstv[277] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_27);
            sqlstm.sqhstl[277] = (unsigned int  )31;
            sqlstm.sqhsts[277] = (         int  )0;
            sqlstm.sqindv[277] = (         void  *)0;
            sqlstm.sqinds[277] = (         int  )0;
            sqlstm.sqharm[277] = (unsigned int  )0;
            sqlstm.sqadto[277] = (unsigned short )0;
            sqlstm.sqtdso[277] = (unsigned short )0;
            sqlstm.sqhstv[278] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_28);
            sqlstm.sqhstl[278] = (unsigned int  )31;
            sqlstm.sqhsts[278] = (         int  )0;
            sqlstm.sqindv[278] = (         void  *)0;
            sqlstm.sqinds[278] = (         int  )0;
            sqlstm.sqharm[278] = (unsigned int  )0;
            sqlstm.sqadto[278] = (unsigned short )0;
            sqlstm.sqtdso[278] = (unsigned short )0;
            sqlstm.sqhstv[279] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_29);
            sqlstm.sqhstl[279] = (unsigned int  )31;
            sqlstm.sqhsts[279] = (         int  )0;
            sqlstm.sqindv[279] = (         void  *)0;
            sqlstm.sqinds[279] = (         int  )0;
            sqlstm.sqharm[279] = (unsigned int  )0;
            sqlstm.sqadto[279] = (unsigned short )0;
            sqlstm.sqtdso[279] = (unsigned short )0;
            sqlstm.sqhstv[280] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_30);
            sqlstm.sqhstl[280] = (unsigned int  )31;
            sqlstm.sqhsts[280] = (         int  )0;
            sqlstm.sqindv[280] = (         void  *)0;
            sqlstm.sqinds[280] = (         int  )0;
            sqlstm.sqharm[280] = (unsigned int  )0;
            sqlstm.sqadto[280] = (unsigned short )0;
            sqlstm.sqtdso[280] = (unsigned short )0;
            sqlstm.sqhstv[281] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[281] = (unsigned int  )11;
            sqlstm.sqhsts[281] = (         int  )0;
            sqlstm.sqindv[281] = (         void  *)0;
            sqlstm.sqinds[281] = (         int  )0;
            sqlstm.sqharm[281] = (unsigned int  )0;
            sqlstm.sqadto[281] = (unsigned short )0;
            sqlstm.sqtdso[281] = (unsigned short )0;
            sqlstm.sqhstv[282] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[282] = (unsigned int  )21;
            sqlstm.sqhsts[282] = (         int  )0;
            sqlstm.sqindv[282] = (         void  *)0;
            sqlstm.sqinds[282] = (         int  )0;
            sqlstm.sqharm[282] = (unsigned int  )0;
            sqlstm.sqadto[282] = (unsigned short )0;
            sqlstm.sqtdso[282] = (unsigned short )0;
            sqlstm.sqhstv[283] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[283] = (unsigned int  )13;
            sqlstm.sqhsts[283] = (         int  )0;
            sqlstm.sqindv[283] = (         void  *)0;
            sqlstm.sqinds[283] = (         int  )0;
            sqlstm.sqharm[283] = (unsigned int  )0;
            sqlstm.sqadto[283] = (unsigned short )0;
            sqlstm.sqtdso[283] = (unsigned short )0;
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
        DBU_del_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    }

    DB_stop_query_timer("DBU_select_mrastevdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_mrastevdef_for_update(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TOOL_EVENT_DESC,
                    SYSTEM_FLAG,
                    COLLECT_DEFECT_FLAG,
                    CLEAN_DEFECT_FLAG,
                    CHK_ITEM_1,
                    CHK_ITEM_2,
                    CHK_ITEM_3,
                    CHK_ITEM_4,
                    CHK_ITEM_5,
                    CHK_ITEM_6,
                    CHK_ITEM_7,
                    CHK_ITEM_8,
                    CHK_ITEM_9,
                    CHK_ITEM_10,
                    CHK_ITEM_11,
                    CHK_ITEM_12,
                    CHK_ITEM_13,
                    CHK_ITEM_14,
                    CHK_ITEM_15,
                    CHK_ITEM_16,
                    CHK_ITEM_17,
                    CHK_ITEM_18,
                    CHK_ITEM_19,
                    CHK_ITEM_20,
                    CHK_ITEM_21,
                    CHK_ITEM_22,
                    CHK_ITEM_23,
                    CHK_ITEM_24,
                    CHK_ITEM_25,
                    CHK_ITEM_26,
                    CHK_ITEM_27,
                    CHK_ITEM_28,
                    CHK_ITEM_29,
                    CHK_ITEM_30,
                    CHK_FLAG_1,
                    CHK_FLAG_2,
                    CHK_FLAG_3,
                    CHK_FLAG_4,
                    CHK_FLAG_5,
                    CHK_FLAG_6,
                    CHK_FLAG_7,
                    CHK_FLAG_8,
                    CHK_FLAG_9,
                    CHK_FLAG_10,
                    CHK_FLAG_11,
                    CHK_FLAG_12,
                    CHK_FLAG_13,
                    CHK_FLAG_14,
                    CHK_FLAG_15,
                    CHK_FLAG_16,
                    CHK_FLAG_17,
                    CHK_FLAG_18,
                    CHK_FLAG_19,
                    CHK_FLAG_20,
                    CHK_FLAG_21,
                    CHK_FLAG_22,
                    CHK_FLAG_23,
                    CHK_FLAG_24,
                    CHK_FLAG_25,
                    CHK_FLAG_26,
                    CHK_FLAG_27,
                    CHK_FLAG_28,
                    CHK_FLAG_29,
                    CHK_FLAG_30,
                    CHK_VALUE_1,
                    CHK_VALUE_2,
                    CHK_VALUE_3,
                    CHK_VALUE_4,
                    CHK_VALUE_5,
                    CHK_VALUE_6,
                    CHK_VALUE_7,
                    CHK_VALUE_8,
                    CHK_VALUE_9,
                    CHK_VALUE_10,
                    CHK_VALUE_11,
                    CHK_VALUE_12,
                    CHK_VALUE_13,
                    CHK_VALUE_14,
                    CHK_VALUE_15,
                    CHK_VALUE_16,
                    CHK_VALUE_17,
                    CHK_VALUE_18,
                    CHK_VALUE_19,
                    CHK_VALUE_20,
                    CHK_VALUE_21,
                    CHK_VALUE_22,
                    CHK_VALUE_23,
                    CHK_VALUE_24,
                    CHK_VALUE_25,
                    CHK_VALUE_26,
                    CHK_VALUE_27,
                    CHK_VALUE_28,
                    CHK_VALUE_29,
                    CHK_VALUE_30,
                    CHK_FIELD_1,
                    CHK_FIELD_2,
                    CHK_FIELD_3,
                    CHK_FIELD_4,
                    CHK_FIELD_5,
                    CHK_FIELD_6,
                    CHK_FIELD_7,
                    CHK_FIELD_8,
                    CHK_FIELD_9,
                    CHK_FIELD_10,
                    CHK_FIELD_11,
                    CHK_FIELD_12,
                    CHK_FIELD_13,
                    CHK_FIELD_14,
                    CHK_FIELD_15,
                    CHK_FIELD_16,
                    CHK_FIELD_17,
                    CHK_FIELD_18,
                    CHK_FIELD_19,
                    CHK_FIELD_20,
                    CHK_FIELD_21,
                    CHK_FIELD_22,
                    CHK_FIELD_23,
                    CHK_FIELD_24,
                    CHK_FIELD_25,
                    CHK_FIELD_26,
                    CHK_FIELD_27,
                    CHK_FIELD_28,
                    CHK_FIELD_29,
                    CHK_FIELD_30,
                    CHG_ITEM_1,
                    CHG_ITEM_2,
                    CHG_ITEM_3,
                    CHG_ITEM_4,
                    CHG_ITEM_5,
                    CHG_ITEM_6,
                    CHG_ITEM_7,
                    CHG_ITEM_8,
                    CHG_ITEM_9,
                    CHG_ITEM_10,
                    CHG_ITEM_11,
                    CHG_ITEM_12,
                    CHG_ITEM_13,
                    CHG_ITEM_14,
                    CHG_ITEM_15,
                    CHG_ITEM_16,
                    CHG_ITEM_17,
                    CHG_ITEM_18,
                    CHG_ITEM_19,
                    CHG_ITEM_20,
                    CHG_ITEM_21,
                    CHG_ITEM_22,
                    CHG_ITEM_23,
                    CHG_ITEM_24,
                    CHG_ITEM_25,
                    CHG_ITEM_26,
                    CHG_ITEM_27,
                    CHG_ITEM_28,
                    CHG_ITEM_29,
                    CHG_ITEM_30,
                    CHG_FLAG_1,
                    CHG_FLAG_2,
                    CHG_FLAG_3,
                    CHG_FLAG_4,
                    CHG_FLAG_5,
                    CHG_FLAG_6,
                    CHG_FLAG_7,
                    CHG_FLAG_8,
                    CHG_FLAG_9,
                    CHG_FLAG_10,
                    CHG_FLAG_11,
                    CHG_FLAG_12,
                    CHG_FLAG_13,
                    CHG_FLAG_14,
                    CHG_FLAG_15,
                    CHG_FLAG_16,
                    CHG_FLAG_17,
                    CHG_FLAG_18,
                    CHG_FLAG_19,
                    CHG_FLAG_20,
                    CHG_FLAG_21,
                    CHG_FLAG_22,
                    CHG_FLAG_23,
                    CHG_FLAG_24,
                    CHG_FLAG_25,
                    CHG_FLAG_26,
                    CHG_FLAG_27,
                    CHG_FLAG_28,
                    CHG_FLAG_29,
                    CHG_FLAG_30,
                    CHG_VALUE_1,
                    CHG_VALUE_2,
                    CHG_VALUE_3,
                    CHG_VALUE_4,
                    CHG_VALUE_5,
                    CHG_VALUE_6,
                    CHG_VALUE_7,
                    CHG_VALUE_8,
                    CHG_VALUE_9,
                    CHG_VALUE_10,
                    CHG_VALUE_11,
                    CHG_VALUE_12,
                    CHG_VALUE_13,
                    CHG_VALUE_14,
                    CHG_VALUE_15,
                    CHG_VALUE_16,
                    CHG_VALUE_17,
                    CHG_VALUE_18,
                    CHG_VALUE_19,
                    CHG_VALUE_20,
                    CHG_VALUE_21,
                    CHG_VALUE_22,
                    CHG_VALUE_23,
                    CHG_VALUE_24,
                    CHG_VALUE_25,
                    CHG_VALUE_26,
                    CHG_VALUE_27,
                    CHG_VALUE_28,
                    CHG_VALUE_29,
                    CHG_VALUE_30,
                    CHG_OPT_1,
                    CHG_OPT_2,
                    CHG_OPT_3,
                    CHG_OPT_4,
                    CHG_OPT_5,
                    CHG_OPT_6,
                    CHG_OPT_7,
                    CHG_OPT_8,
                    CHG_OPT_9,
                    CHG_OPT_10,
                    CHG_OPT_11,
                    CHG_OPT_12,
                    CHG_OPT_13,
                    CHG_OPT_14,
                    CHG_OPT_15,
                    CHG_OPT_16,
                    CHG_OPT_17,
                    CHG_OPT_18,
                    CHG_OPT_19,
                    CHG_OPT_20,
                    CHG_OPT_21,
                    CHG_OPT_22,
                    CHG_OPT_23,
                    CHG_OPT_24,
                    CHG_OPT_25,
                    CHG_OPT_26,
                    CHG_OPT_27,
                    CHG_OPT_28,
                    CHG_OPT_29,
                    CHG_OPT_30,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CHG_FIELD_1,
                    CHG_FIELD_2,
                    CHG_FIELD_3,
                    CHG_FIELD_4,
                    CHG_FIELD_5,
                    CHG_FIELD_6,
                    CHG_FIELD_7,
                    CHG_FIELD_8,
                    CHG_FIELD_9,
                    CHG_FIELD_10,
                    CHG_FIELD_11,
                    CHG_FIELD_12,
                    CHG_FIELD_13,
                    CHG_FIELD_14,
                    CHG_FIELD_15,
                    CHG_FIELD_16,
                    CHG_FIELD_17,
                    CHG_FIELD_18,
                    CHG_FIELD_19,
                    CHG_FIELD_20,
                    CHG_FIELD_21,
                    CHG_FIELD_22,
                    CHG_FIELD_23,
                    CHG_FIELD_24,
                    CHG_FIELD_25,
                    CHG_FIELD_26,
                    CHG_FIELD_27,
                    CHG_FIELD_28,
                    CHG_FIELD_29,
                    CHG_FIELD_30
                INTO 
                    :MRASTEVDEF_N.FACTORY,
                    :MRASTEVDEF_N.TOOL_TYPE,
                    :MRASTEVDEF_N.TOOL_EVENT_ID,
                    :MRASTEVDEF_N.TOOL_EVENT_DESC,
                    :MRASTEVDEF_N.SYSTEM_FLAG,
                    :MRASTEVDEF_N.COLLECT_DEFECT_FLAG,
                    :MRASTEVDEF_N.CLEAN_DEFECT_FLAG,
                    :MRASTEVDEF_N.CHK_ITEM_1,
                    :MRASTEVDEF_N.CHK_ITEM_2,
                    :MRASTEVDEF_N.CHK_ITEM_3,
                    :MRASTEVDEF_N.CHK_ITEM_4,
                    :MRASTEVDEF_N.CHK_ITEM_5,
                    :MRASTEVDEF_N.CHK_ITEM_6,
                    :MRASTEVDEF_N.CHK_ITEM_7,
                    :MRASTEVDEF_N.CHK_ITEM_8,
                    :MRASTEVDEF_N.CHK_ITEM_9,
                    :MRASTEVDEF_N.CHK_ITEM_10,
                    :MRASTEVDEF_N.CHK_ITEM_11,
                    :MRASTEVDEF_N.CHK_ITEM_12,
                    :MRASTEVDEF_N.CHK_ITEM_13,
                    :MRASTEVDEF_N.CHK_ITEM_14,
                    :MRASTEVDEF_N.CHK_ITEM_15,
                    :MRASTEVDEF_N.CHK_ITEM_16,
                    :MRASTEVDEF_N.CHK_ITEM_17,
                    :MRASTEVDEF_N.CHK_ITEM_18,
                    :MRASTEVDEF_N.CHK_ITEM_19,
                    :MRASTEVDEF_N.CHK_ITEM_20,
                    :MRASTEVDEF_N.CHK_ITEM_21,
                    :MRASTEVDEF_N.CHK_ITEM_22,
                    :MRASTEVDEF_N.CHK_ITEM_23,
                    :MRASTEVDEF_N.CHK_ITEM_24,
                    :MRASTEVDEF_N.CHK_ITEM_25,
                    :MRASTEVDEF_N.CHK_ITEM_26,
                    :MRASTEVDEF_N.CHK_ITEM_27,
                    :MRASTEVDEF_N.CHK_ITEM_28,
                    :MRASTEVDEF_N.CHK_ITEM_29,
                    :MRASTEVDEF_N.CHK_ITEM_30,
                    :MRASTEVDEF_N.CHK_FLAG_1,
                    :MRASTEVDEF_N.CHK_FLAG_2,
                    :MRASTEVDEF_N.CHK_FLAG_3,
                    :MRASTEVDEF_N.CHK_FLAG_4,
                    :MRASTEVDEF_N.CHK_FLAG_5,
                    :MRASTEVDEF_N.CHK_FLAG_6,
                    :MRASTEVDEF_N.CHK_FLAG_7,
                    :MRASTEVDEF_N.CHK_FLAG_8,
                    :MRASTEVDEF_N.CHK_FLAG_9,
                    :MRASTEVDEF_N.CHK_FLAG_10,
                    :MRASTEVDEF_N.CHK_FLAG_11,
                    :MRASTEVDEF_N.CHK_FLAG_12,
                    :MRASTEVDEF_N.CHK_FLAG_13,
                    :MRASTEVDEF_N.CHK_FLAG_14,
                    :MRASTEVDEF_N.CHK_FLAG_15,
                    :MRASTEVDEF_N.CHK_FLAG_16,
                    :MRASTEVDEF_N.CHK_FLAG_17,
                    :MRASTEVDEF_N.CHK_FLAG_18,
                    :MRASTEVDEF_N.CHK_FLAG_19,
                    :MRASTEVDEF_N.CHK_FLAG_20,
                    :MRASTEVDEF_N.CHK_FLAG_21,
                    :MRASTEVDEF_N.CHK_FLAG_22,
                    :MRASTEVDEF_N.CHK_FLAG_23,
                    :MRASTEVDEF_N.CHK_FLAG_24,
                    :MRASTEVDEF_N.CHK_FLAG_25,
                    :MRASTEVDEF_N.CHK_FLAG_26,
                    :MRASTEVDEF_N.CHK_FLAG_27,
                    :MRASTEVDEF_N.CHK_FLAG_28,
                    :MRASTEVDEF_N.CHK_FLAG_29,
                    :MRASTEVDEF_N.CHK_FLAG_30,
                    :MRASTEVDEF_N.CHK_VALUE_1,
                    :MRASTEVDEF_N.CHK_VALUE_2,
                    :MRASTEVDEF_N.CHK_VALUE_3,
                    :MRASTEVDEF_N.CHK_VALUE_4,
                    :MRASTEVDEF_N.CHK_VALUE_5,
                    :MRASTEVDEF_N.CHK_VALUE_6,
                    :MRASTEVDEF_N.CHK_VALUE_7,
                    :MRASTEVDEF_N.CHK_VALUE_8,
                    :MRASTEVDEF_N.CHK_VALUE_9,
                    :MRASTEVDEF_N.CHK_VALUE_10,
                    :MRASTEVDEF_N.CHK_VALUE_11,
                    :MRASTEVDEF_N.CHK_VALUE_12,
                    :MRASTEVDEF_N.CHK_VALUE_13,
                    :MRASTEVDEF_N.CHK_VALUE_14,
                    :MRASTEVDEF_N.CHK_VALUE_15,
                    :MRASTEVDEF_N.CHK_VALUE_16,
                    :MRASTEVDEF_N.CHK_VALUE_17,
                    :MRASTEVDEF_N.CHK_VALUE_18,
                    :MRASTEVDEF_N.CHK_VALUE_19,
                    :MRASTEVDEF_N.CHK_VALUE_20,
                    :MRASTEVDEF_N.CHK_VALUE_21,
                    :MRASTEVDEF_N.CHK_VALUE_22,
                    :MRASTEVDEF_N.CHK_VALUE_23,
                    :MRASTEVDEF_N.CHK_VALUE_24,
                    :MRASTEVDEF_N.CHK_VALUE_25,
                    :MRASTEVDEF_N.CHK_VALUE_26,
                    :MRASTEVDEF_N.CHK_VALUE_27,
                    :MRASTEVDEF_N.CHK_VALUE_28,
                    :MRASTEVDEF_N.CHK_VALUE_29,
                    :MRASTEVDEF_N.CHK_VALUE_30,
                    :MRASTEVDEF_N.CHK_FIELD_1,
                    :MRASTEVDEF_N.CHK_FIELD_2,
                    :MRASTEVDEF_N.CHK_FIELD_3,
                    :MRASTEVDEF_N.CHK_FIELD_4,
                    :MRASTEVDEF_N.CHK_FIELD_5,
                    :MRASTEVDEF_N.CHK_FIELD_6,
                    :MRASTEVDEF_N.CHK_FIELD_7,
                    :MRASTEVDEF_N.CHK_FIELD_8,
                    :MRASTEVDEF_N.CHK_FIELD_9,
                    :MRASTEVDEF_N.CHK_FIELD_10,
                    :MRASTEVDEF_N.CHK_FIELD_11,
                    :MRASTEVDEF_N.CHK_FIELD_12,
                    :MRASTEVDEF_N.CHK_FIELD_13,
                    :MRASTEVDEF_N.CHK_FIELD_14,
                    :MRASTEVDEF_N.CHK_FIELD_15,
                    :MRASTEVDEF_N.CHK_FIELD_16,
                    :MRASTEVDEF_N.CHK_FIELD_17,
                    :MRASTEVDEF_N.CHK_FIELD_18,
                    :MRASTEVDEF_N.CHK_FIELD_19,
                    :MRASTEVDEF_N.CHK_FIELD_20,
                    :MRASTEVDEF_N.CHK_FIELD_21,
                    :MRASTEVDEF_N.CHK_FIELD_22,
                    :MRASTEVDEF_N.CHK_FIELD_23,
                    :MRASTEVDEF_N.CHK_FIELD_24,
                    :MRASTEVDEF_N.CHK_FIELD_25,
                    :MRASTEVDEF_N.CHK_FIELD_26,
                    :MRASTEVDEF_N.CHK_FIELD_27,
                    :MRASTEVDEF_N.CHK_FIELD_28,
                    :MRASTEVDEF_N.CHK_FIELD_29,
                    :MRASTEVDEF_N.CHK_FIELD_30,
                    :MRASTEVDEF_N.CHG_ITEM_1,
                    :MRASTEVDEF_N.CHG_ITEM_2,
                    :MRASTEVDEF_N.CHG_ITEM_3,
                    :MRASTEVDEF_N.CHG_ITEM_4,
                    :MRASTEVDEF_N.CHG_ITEM_5,
                    :MRASTEVDEF_N.CHG_ITEM_6,
                    :MRASTEVDEF_N.CHG_ITEM_7,
                    :MRASTEVDEF_N.CHG_ITEM_8,
                    :MRASTEVDEF_N.CHG_ITEM_9,
                    :MRASTEVDEF_N.CHG_ITEM_10,
                    :MRASTEVDEF_N.CHG_ITEM_11,
                    :MRASTEVDEF_N.CHG_ITEM_12,
                    :MRASTEVDEF_N.CHG_ITEM_13,
                    :MRASTEVDEF_N.CHG_ITEM_14,
                    :MRASTEVDEF_N.CHG_ITEM_15,
                    :MRASTEVDEF_N.CHG_ITEM_16,
                    :MRASTEVDEF_N.CHG_ITEM_17,
                    :MRASTEVDEF_N.CHG_ITEM_18,
                    :MRASTEVDEF_N.CHG_ITEM_19,
                    :MRASTEVDEF_N.CHG_ITEM_20,
                    :MRASTEVDEF_N.CHG_ITEM_21,
                    :MRASTEVDEF_N.CHG_ITEM_22,
                    :MRASTEVDEF_N.CHG_ITEM_23,
                    :MRASTEVDEF_N.CHG_ITEM_24,
                    :MRASTEVDEF_N.CHG_ITEM_25,
                    :MRASTEVDEF_N.CHG_ITEM_26,
                    :MRASTEVDEF_N.CHG_ITEM_27,
                    :MRASTEVDEF_N.CHG_ITEM_28,
                    :MRASTEVDEF_N.CHG_ITEM_29,
                    :MRASTEVDEF_N.CHG_ITEM_30,
                    :MRASTEVDEF_N.CHG_FLAG_1,
                    :MRASTEVDEF_N.CHG_FLAG_2,
                    :MRASTEVDEF_N.CHG_FLAG_3,
                    :MRASTEVDEF_N.CHG_FLAG_4,
                    :MRASTEVDEF_N.CHG_FLAG_5,
                    :MRASTEVDEF_N.CHG_FLAG_6,
                    :MRASTEVDEF_N.CHG_FLAG_7,
                    :MRASTEVDEF_N.CHG_FLAG_8,
                    :MRASTEVDEF_N.CHG_FLAG_9,
                    :MRASTEVDEF_N.CHG_FLAG_10,
                    :MRASTEVDEF_N.CHG_FLAG_11,
                    :MRASTEVDEF_N.CHG_FLAG_12,
                    :MRASTEVDEF_N.CHG_FLAG_13,
                    :MRASTEVDEF_N.CHG_FLAG_14,
                    :MRASTEVDEF_N.CHG_FLAG_15,
                    :MRASTEVDEF_N.CHG_FLAG_16,
                    :MRASTEVDEF_N.CHG_FLAG_17,
                    :MRASTEVDEF_N.CHG_FLAG_18,
                    :MRASTEVDEF_N.CHG_FLAG_19,
                    :MRASTEVDEF_N.CHG_FLAG_20,
                    :MRASTEVDEF_N.CHG_FLAG_21,
                    :MRASTEVDEF_N.CHG_FLAG_22,
                    :MRASTEVDEF_N.CHG_FLAG_23,
                    :MRASTEVDEF_N.CHG_FLAG_24,
                    :MRASTEVDEF_N.CHG_FLAG_25,
                    :MRASTEVDEF_N.CHG_FLAG_26,
                    :MRASTEVDEF_N.CHG_FLAG_27,
                    :MRASTEVDEF_N.CHG_FLAG_28,
                    :MRASTEVDEF_N.CHG_FLAG_29,
                    :MRASTEVDEF_N.CHG_FLAG_30,
                    :MRASTEVDEF_N.CHG_VALUE_1,
                    :MRASTEVDEF_N.CHG_VALUE_2,
                    :MRASTEVDEF_N.CHG_VALUE_3,
                    :MRASTEVDEF_N.CHG_VALUE_4,
                    :MRASTEVDEF_N.CHG_VALUE_5,
                    :MRASTEVDEF_N.CHG_VALUE_6,
                    :MRASTEVDEF_N.CHG_VALUE_7,
                    :MRASTEVDEF_N.CHG_VALUE_8,
                    :MRASTEVDEF_N.CHG_VALUE_9,
                    :MRASTEVDEF_N.CHG_VALUE_10,
                    :MRASTEVDEF_N.CHG_VALUE_11,
                    :MRASTEVDEF_N.CHG_VALUE_12,
                    :MRASTEVDEF_N.CHG_VALUE_13,
                    :MRASTEVDEF_N.CHG_VALUE_14,
                    :MRASTEVDEF_N.CHG_VALUE_15,
                    :MRASTEVDEF_N.CHG_VALUE_16,
                    :MRASTEVDEF_N.CHG_VALUE_17,
                    :MRASTEVDEF_N.CHG_VALUE_18,
                    :MRASTEVDEF_N.CHG_VALUE_19,
                    :MRASTEVDEF_N.CHG_VALUE_20,
                    :MRASTEVDEF_N.CHG_VALUE_21,
                    :MRASTEVDEF_N.CHG_VALUE_22,
                    :MRASTEVDEF_N.CHG_VALUE_23,
                    :MRASTEVDEF_N.CHG_VALUE_24,
                    :MRASTEVDEF_N.CHG_VALUE_25,
                    :MRASTEVDEF_N.CHG_VALUE_26,
                    :MRASTEVDEF_N.CHG_VALUE_27,
                    :MRASTEVDEF_N.CHG_VALUE_28,
                    :MRASTEVDEF_N.CHG_VALUE_29,
                    :MRASTEVDEF_N.CHG_VALUE_30,
                    :MRASTEVDEF_N.CHG_OPT_1,
                    :MRASTEVDEF_N.CHG_OPT_2,
                    :MRASTEVDEF_N.CHG_OPT_3,
                    :MRASTEVDEF_N.CHG_OPT_4,
                    :MRASTEVDEF_N.CHG_OPT_5,
                    :MRASTEVDEF_N.CHG_OPT_6,
                    :MRASTEVDEF_N.CHG_OPT_7,
                    :MRASTEVDEF_N.CHG_OPT_8,
                    :MRASTEVDEF_N.CHG_OPT_9,
                    :MRASTEVDEF_N.CHG_OPT_10,
                    :MRASTEVDEF_N.CHG_OPT_11,
                    :MRASTEVDEF_N.CHG_OPT_12,
                    :MRASTEVDEF_N.CHG_OPT_13,
                    :MRASTEVDEF_N.CHG_OPT_14,
                    :MRASTEVDEF_N.CHG_OPT_15,
                    :MRASTEVDEF_N.CHG_OPT_16,
                    :MRASTEVDEF_N.CHG_OPT_17,
                    :MRASTEVDEF_N.CHG_OPT_18,
                    :MRASTEVDEF_N.CHG_OPT_19,
                    :MRASTEVDEF_N.CHG_OPT_20,
                    :MRASTEVDEF_N.CHG_OPT_21,
                    :MRASTEVDEF_N.CHG_OPT_22,
                    :MRASTEVDEF_N.CHG_OPT_23,
                    :MRASTEVDEF_N.CHG_OPT_24,
                    :MRASTEVDEF_N.CHG_OPT_25,
                    :MRASTEVDEF_N.CHG_OPT_26,
                    :MRASTEVDEF_N.CHG_OPT_27,
                    :MRASTEVDEF_N.CHG_OPT_28,
                    :MRASTEVDEF_N.CHG_OPT_29,
                    :MRASTEVDEF_N.CHG_OPT_30,
                    :MRASTEVDEF_N.CREATE_USER_ID,
                    :MRASTEVDEF_N.CREATE_TIME,
                    :MRASTEVDEF_N.UPDATE_USER_ID,
                    :MRASTEVDEF_N.UPDATE_TIME,
                    :MRASTEVDEF_N.CHG_FIELD_1,
                    :MRASTEVDEF_N.CHG_FIELD_2,
                    :MRASTEVDEF_N.CHG_FIELD_3,
                    :MRASTEVDEF_N.CHG_FIELD_4,
                    :MRASTEVDEF_N.CHG_FIELD_5,
                    :MRASTEVDEF_N.CHG_FIELD_6,
                    :MRASTEVDEF_N.CHG_FIELD_7,
                    :MRASTEVDEF_N.CHG_FIELD_8,
                    :MRASTEVDEF_N.CHG_FIELD_9,
                    :MRASTEVDEF_N.CHG_FIELD_10,
                    :MRASTEVDEF_N.CHG_FIELD_11,
                    :MRASTEVDEF_N.CHG_FIELD_12,
                    :MRASTEVDEF_N.CHG_FIELD_13,
                    :MRASTEVDEF_N.CHG_FIELD_14,
                    :MRASTEVDEF_N.CHG_FIELD_15,
                    :MRASTEVDEF_N.CHG_FIELD_16,
                    :MRASTEVDEF_N.CHG_FIELD_17,
                    :MRASTEVDEF_N.CHG_FIELD_18,
                    :MRASTEVDEF_N.CHG_FIELD_19,
                    :MRASTEVDEF_N.CHG_FIELD_20,
                    :MRASTEVDEF_N.CHG_FIELD_21,
                    :MRASTEVDEF_N.CHG_FIELD_22,
                    :MRASTEVDEF_N.CHG_FIELD_23,
                    :MRASTEVDEF_N.CHG_FIELD_24,
                    :MRASTEVDEF_N.CHG_FIELD_25,
                    :MRASTEVDEF_N.CHG_FIELD_26,
                    :MRASTEVDEF_N.CHG_FIELD_27,
                    :MRASTEVDEF_N.CHG_FIELD_28,
                    :MRASTEVDEF_N.CHG_FIELD_29,
                    :MRASTEVDEF_N.CHG_FIELD_30
                FROM MRASTEVDEF
                WHERE FACTORY = :MRASTEVDEF_N.FACTORY
                    AND TOOL_TYPE = :MRASTEVDEF_N.TOOL_TYPE
                    AND TOOL_EVENT_ID = :MRASTEVDEF_N.TOOL_EVENT_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_TYPE ,TOOL_EVENT_ID ,TOOL_EVENT_DESC ,SY\
STEM_FLAG ,COLLECT_DEFECT_FLAG ,CLEAN_DEFECT_FLAG ,CHK_ITEM_1 ,CHK_ITEM_2 ,C\
HK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_ITEM_7 ,CHK_ITEM_8 ,CHK_I\
TEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITEM_13 ,CHK_ITEM_14 ,CHK_\
ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_ITEM_19 ,CHK_ITEM_20 ,CH\
K_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK_ITEM_25 ,CHK_ITEM_26 ,\
CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,CHK_FLAG_1 ,CHK_FLAG_2 ,\
CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_FLAG_7 ,CHK_FLAG_8 ,CHK_\
FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FLAG_13 ,CHK_FLAG_14 ,CHK\
_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_FLAG_19 ,CHK_FLAG_20 ,C\
HK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CHK_FLAG_25 ,CHK_FLAG_26 \
,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,CHK_VALUE_1 ,CHK_VALUE_\
2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6 ,CHK_VALUE_7 ,CHK_VALU\
E_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_V");
            sqlbuft((void **)0,
              "ALUE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CHK_VALUE_\
16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VALUE_20 ,CHK_VALUE_21 ,CH\
K_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 ,CHK_VALUE_26 ,CHK_VALU\
E_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_FIELD_1 ,CHK_FIELD_2 ,CH\
K_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK_FIELD_7 ,CHK_FIELD_8 ,\
CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12 ,CHK_FIELD_13 ,CHK_FIE\
LD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_FIELD_18 ,CHK_FIELD_19 \
,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_23 ,CHK_FIELD_24 ,CHK_F\
IELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CHK_FIELD_29 ,CHK_FIELD_3\
0 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CHG_ITEM_5 ,CHG_ITEM_6 ,C\
HG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_ITEM_11 ,CHG_ITEM_12 ,CH\
G_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG_ITEM_17 ,CHG_ITEM_18 ,\
CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,CHG_ITEM_23 ,CHG_ITEM_24\
 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_2");
            sqlbuft((void **)0,
              "8 ,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,CHG_FLAG\
_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,CHG_FLAG_8 ,CHG_FLAG_9 ,\
CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,CHG_FLAG_14 ,CHG_FLAG_15\
 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 ,CHG_FLAG_20 ,CHG_FLAG_\
21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_25 ,CHG_FLAG_26 ,CHG_FLA\
G_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALUE_1 ,CHG_VALUE_2 ,CHG_V\
ALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VALUE_7 ,CHG_VALUE_8 ,CHG\
_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,CHG_VALUE_13 ,CHG_VALUE_\
14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VALUE_18 ,CHG_VALUE_19 ,CH\
G_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 ,CHG_VALUE_24 ,CHG_VALU\
E_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_VALUE_29 ,CHG_VALUE_30 ,\
CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5 ,CHG_OPT_6 ,CHG_OPT_7 \
,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OPT_12 ,CHG_OPT_13 ,CHG_O\
PT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_");
            sqlbuft((void **)0,
              "18 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_21 ,CHG_OPT_22 ,CHG_OPT_2\
3 ,CHG_OPT_24 ,CHG_OPT_25 ,CHG_OPT_26 ,CHG_OPT_27 ,CHG_OPT_28 ,CHG_OPT_29 ,C\
HG_OPT_30 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,CHG_FIE\
LD_1 ,CHG_FIELD_2 ,CHG_FIELD_3 ,CHG_FIELD_4 ,CHG_FIELD_5 ,CHG_FIELD_6 ,CHG_F\
IELD_7 ,CHG_FIELD_8 ,CHG_FIELD_9 ,CHG_FIELD_10 ,CHG_FIELD_11 ,CHG_FIELD_12 ,\
CHG_FIELD_13 ,CHG_FIELD_14 ,CHG_FIELD_15 ,CHG_FIELD_16 ,CHG_FIELD_17 ,CHG_FI\
ELD_18 ,CHG_FIELD_19 ,CHG_FIELD_20 ,CHG_FIELD_21 ,CHG_FIELD_22 ,CHG_FIELD_23\
 ,CHG_FIELD_24 ,CHG_FIELD_25 ,CHG_FIELD_26 ,CHG_FIELD_27 ,CHG_FIELD_28 ,CHG_\
FIELD_29 ,CHG_FIELD_30 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b1\
1,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26\
,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,\
:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:\
b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b\
72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b8");
            sqlbuft((void **)0,
              "2,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94\
,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b\
108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b120,\
:b121,:b122,:b123,:b124,:b125,:b126,:b127,:b128,:b129,:b130,:b131,:b132,:b13\
3,:b134,:b135,:b136,:b137,:b138,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b\
146,:b147,:b148,:b149,:b150,:b151,:b152,:b153,:b154,:b155,:b156,:b157,:b158,\
:b159,:b160,:b161,:b162,:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170,:b17\
1,:b172,:b173,:b174,:b175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b\
184,:b185,:b186,:b187,:b188,:b189,:b190,:b191,:b192,:b193,:b194,:b195,:b196,\
:b197,:b198,:b199,:b200,:b201,:b202,:b203,:b204,:b205,:b206,:b207,:b208,:b20\
9,:b210,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b218,:b219,:b220,:b221,:b\
222,:b223,:b224,:b225,:b226,:b227,:b228,:b229,:b230,:b231,:b232,:b233,:b234,\
:b235,:b236,:b237,:b238,:b239,:b240,:b241,:b242,:b243,:b244,:b245,:b246,:b24\
7,:b248,:b249,:b250,:b251,:b252,:b253,:b254,:b255,:");
            sqlstm.stmt = "b256,:b257,:b258,:b259,:b260,:b261,:b262,:b263,:\
b264,:b265,:b266,:b267,:b268,:b269,:b270,:b271,:b272,:b273,:b274,:b275,:b276,\
:b277,:b278,:b279,:b280  from MRASTEVDEF where ((FACTORY=:b0 and TOOL_TYPE=:b\
1) and TOOL_EVENT_ID=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1156;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )13;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTEVDEF_N.COLLECT_DEFECT_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTEVDEF_N.CLEAN_DEFECT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[154] = (unsigned int  )31;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[155] = (unsigned int  )31;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[156] = (unsigned int  )31;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[184] = (unsigned int  )2;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[186] = (unsigned int  )2;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[214] = (unsigned int  )31;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[215] = (unsigned int  )31;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[216] = (unsigned int  )31;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASTEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASTEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASTEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASTEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASTEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASTEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASTEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASTEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASTEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASTEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASTEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASTEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASTEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASTEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASTEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASTEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASTEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASTEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASTEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASTEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASTEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASTEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASTEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASTEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASTEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASTEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASTEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASTEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[244] = (unsigned int  )2;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASTEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[245] = (unsigned int  )2;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASTEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[246] = (unsigned int  )2;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASTEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[247] = (unsigned int  )21;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASTEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[248] = (unsigned int  )15;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASTEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[249] = (unsigned int  )21;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
            sqlstm.sqhstv[250] = (         void  *)(MRASTEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[250] = (unsigned int  )15;
            sqlstm.sqhsts[250] = (         int  )0;
            sqlstm.sqindv[250] = (         void  *)0;
            sqlstm.sqinds[250] = (         int  )0;
            sqlstm.sqharm[250] = (unsigned int  )0;
            sqlstm.sqadto[250] = (unsigned short )0;
            sqlstm.sqtdso[250] = (unsigned short )0;
            sqlstm.sqhstv[251] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_1);
            sqlstm.sqhstl[251] = (unsigned int  )31;
            sqlstm.sqhsts[251] = (         int  )0;
            sqlstm.sqindv[251] = (         void  *)0;
            sqlstm.sqinds[251] = (         int  )0;
            sqlstm.sqharm[251] = (unsigned int  )0;
            sqlstm.sqadto[251] = (unsigned short )0;
            sqlstm.sqtdso[251] = (unsigned short )0;
            sqlstm.sqhstv[252] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_2);
            sqlstm.sqhstl[252] = (unsigned int  )31;
            sqlstm.sqhsts[252] = (         int  )0;
            sqlstm.sqindv[252] = (         void  *)0;
            sqlstm.sqinds[252] = (         int  )0;
            sqlstm.sqharm[252] = (unsigned int  )0;
            sqlstm.sqadto[252] = (unsigned short )0;
            sqlstm.sqtdso[252] = (unsigned short )0;
            sqlstm.sqhstv[253] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_3);
            sqlstm.sqhstl[253] = (unsigned int  )31;
            sqlstm.sqhsts[253] = (         int  )0;
            sqlstm.sqindv[253] = (         void  *)0;
            sqlstm.sqinds[253] = (         int  )0;
            sqlstm.sqharm[253] = (unsigned int  )0;
            sqlstm.sqadto[253] = (unsigned short )0;
            sqlstm.sqtdso[253] = (unsigned short )0;
            sqlstm.sqhstv[254] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_4);
            sqlstm.sqhstl[254] = (unsigned int  )31;
            sqlstm.sqhsts[254] = (         int  )0;
            sqlstm.sqindv[254] = (         void  *)0;
            sqlstm.sqinds[254] = (         int  )0;
            sqlstm.sqharm[254] = (unsigned int  )0;
            sqlstm.sqadto[254] = (unsigned short )0;
            sqlstm.sqtdso[254] = (unsigned short )0;
            sqlstm.sqhstv[255] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_5);
            sqlstm.sqhstl[255] = (unsigned int  )31;
            sqlstm.sqhsts[255] = (         int  )0;
            sqlstm.sqindv[255] = (         void  *)0;
            sqlstm.sqinds[255] = (         int  )0;
            sqlstm.sqharm[255] = (unsigned int  )0;
            sqlstm.sqadto[255] = (unsigned short )0;
            sqlstm.sqtdso[255] = (unsigned short )0;
            sqlstm.sqhstv[256] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_6);
            sqlstm.sqhstl[256] = (unsigned int  )31;
            sqlstm.sqhsts[256] = (         int  )0;
            sqlstm.sqindv[256] = (         void  *)0;
            sqlstm.sqinds[256] = (         int  )0;
            sqlstm.sqharm[256] = (unsigned int  )0;
            sqlstm.sqadto[256] = (unsigned short )0;
            sqlstm.sqtdso[256] = (unsigned short )0;
            sqlstm.sqhstv[257] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_7);
            sqlstm.sqhstl[257] = (unsigned int  )31;
            sqlstm.sqhsts[257] = (         int  )0;
            sqlstm.sqindv[257] = (         void  *)0;
            sqlstm.sqinds[257] = (         int  )0;
            sqlstm.sqharm[257] = (unsigned int  )0;
            sqlstm.sqadto[257] = (unsigned short )0;
            sqlstm.sqtdso[257] = (unsigned short )0;
            sqlstm.sqhstv[258] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_8);
            sqlstm.sqhstl[258] = (unsigned int  )31;
            sqlstm.sqhsts[258] = (         int  )0;
            sqlstm.sqindv[258] = (         void  *)0;
            sqlstm.sqinds[258] = (         int  )0;
            sqlstm.sqharm[258] = (unsigned int  )0;
            sqlstm.sqadto[258] = (unsigned short )0;
            sqlstm.sqtdso[258] = (unsigned short )0;
            sqlstm.sqhstv[259] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_9);
            sqlstm.sqhstl[259] = (unsigned int  )31;
            sqlstm.sqhsts[259] = (         int  )0;
            sqlstm.sqindv[259] = (         void  *)0;
            sqlstm.sqinds[259] = (         int  )0;
            sqlstm.sqharm[259] = (unsigned int  )0;
            sqlstm.sqadto[259] = (unsigned short )0;
            sqlstm.sqtdso[259] = (unsigned short )0;
            sqlstm.sqhstv[260] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_10);
            sqlstm.sqhstl[260] = (unsigned int  )31;
            sqlstm.sqhsts[260] = (         int  )0;
            sqlstm.sqindv[260] = (         void  *)0;
            sqlstm.sqinds[260] = (         int  )0;
            sqlstm.sqharm[260] = (unsigned int  )0;
            sqlstm.sqadto[260] = (unsigned short )0;
            sqlstm.sqtdso[260] = (unsigned short )0;
            sqlstm.sqhstv[261] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_11);
            sqlstm.sqhstl[261] = (unsigned int  )31;
            sqlstm.sqhsts[261] = (         int  )0;
            sqlstm.sqindv[261] = (         void  *)0;
            sqlstm.sqinds[261] = (         int  )0;
            sqlstm.sqharm[261] = (unsigned int  )0;
            sqlstm.sqadto[261] = (unsigned short )0;
            sqlstm.sqtdso[261] = (unsigned short )0;
            sqlstm.sqhstv[262] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_12);
            sqlstm.sqhstl[262] = (unsigned int  )31;
            sqlstm.sqhsts[262] = (         int  )0;
            sqlstm.sqindv[262] = (         void  *)0;
            sqlstm.sqinds[262] = (         int  )0;
            sqlstm.sqharm[262] = (unsigned int  )0;
            sqlstm.sqadto[262] = (unsigned short )0;
            sqlstm.sqtdso[262] = (unsigned short )0;
            sqlstm.sqhstv[263] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_13);
            sqlstm.sqhstl[263] = (unsigned int  )31;
            sqlstm.sqhsts[263] = (         int  )0;
            sqlstm.sqindv[263] = (         void  *)0;
            sqlstm.sqinds[263] = (         int  )0;
            sqlstm.sqharm[263] = (unsigned int  )0;
            sqlstm.sqadto[263] = (unsigned short )0;
            sqlstm.sqtdso[263] = (unsigned short )0;
            sqlstm.sqhstv[264] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_14);
            sqlstm.sqhstl[264] = (unsigned int  )31;
            sqlstm.sqhsts[264] = (         int  )0;
            sqlstm.sqindv[264] = (         void  *)0;
            sqlstm.sqinds[264] = (         int  )0;
            sqlstm.sqharm[264] = (unsigned int  )0;
            sqlstm.sqadto[264] = (unsigned short )0;
            sqlstm.sqtdso[264] = (unsigned short )0;
            sqlstm.sqhstv[265] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_15);
            sqlstm.sqhstl[265] = (unsigned int  )31;
            sqlstm.sqhsts[265] = (         int  )0;
            sqlstm.sqindv[265] = (         void  *)0;
            sqlstm.sqinds[265] = (         int  )0;
            sqlstm.sqharm[265] = (unsigned int  )0;
            sqlstm.sqadto[265] = (unsigned short )0;
            sqlstm.sqtdso[265] = (unsigned short )0;
            sqlstm.sqhstv[266] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_16);
            sqlstm.sqhstl[266] = (unsigned int  )31;
            sqlstm.sqhsts[266] = (         int  )0;
            sqlstm.sqindv[266] = (         void  *)0;
            sqlstm.sqinds[266] = (         int  )0;
            sqlstm.sqharm[266] = (unsigned int  )0;
            sqlstm.sqadto[266] = (unsigned short )0;
            sqlstm.sqtdso[266] = (unsigned short )0;
            sqlstm.sqhstv[267] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_17);
            sqlstm.sqhstl[267] = (unsigned int  )31;
            sqlstm.sqhsts[267] = (         int  )0;
            sqlstm.sqindv[267] = (         void  *)0;
            sqlstm.sqinds[267] = (         int  )0;
            sqlstm.sqharm[267] = (unsigned int  )0;
            sqlstm.sqadto[267] = (unsigned short )0;
            sqlstm.sqtdso[267] = (unsigned short )0;
            sqlstm.sqhstv[268] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_18);
            sqlstm.sqhstl[268] = (unsigned int  )31;
            sqlstm.sqhsts[268] = (         int  )0;
            sqlstm.sqindv[268] = (         void  *)0;
            sqlstm.sqinds[268] = (         int  )0;
            sqlstm.sqharm[268] = (unsigned int  )0;
            sqlstm.sqadto[268] = (unsigned short )0;
            sqlstm.sqtdso[268] = (unsigned short )0;
            sqlstm.sqhstv[269] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_19);
            sqlstm.sqhstl[269] = (unsigned int  )31;
            sqlstm.sqhsts[269] = (         int  )0;
            sqlstm.sqindv[269] = (         void  *)0;
            sqlstm.sqinds[269] = (         int  )0;
            sqlstm.sqharm[269] = (unsigned int  )0;
            sqlstm.sqadto[269] = (unsigned short )0;
            sqlstm.sqtdso[269] = (unsigned short )0;
            sqlstm.sqhstv[270] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_20);
            sqlstm.sqhstl[270] = (unsigned int  )31;
            sqlstm.sqhsts[270] = (         int  )0;
            sqlstm.sqindv[270] = (         void  *)0;
            sqlstm.sqinds[270] = (         int  )0;
            sqlstm.sqharm[270] = (unsigned int  )0;
            sqlstm.sqadto[270] = (unsigned short )0;
            sqlstm.sqtdso[270] = (unsigned short )0;
            sqlstm.sqhstv[271] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_21);
            sqlstm.sqhstl[271] = (unsigned int  )31;
            sqlstm.sqhsts[271] = (         int  )0;
            sqlstm.sqindv[271] = (         void  *)0;
            sqlstm.sqinds[271] = (         int  )0;
            sqlstm.sqharm[271] = (unsigned int  )0;
            sqlstm.sqadto[271] = (unsigned short )0;
            sqlstm.sqtdso[271] = (unsigned short )0;
            sqlstm.sqhstv[272] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_22);
            sqlstm.sqhstl[272] = (unsigned int  )31;
            sqlstm.sqhsts[272] = (         int  )0;
            sqlstm.sqindv[272] = (         void  *)0;
            sqlstm.sqinds[272] = (         int  )0;
            sqlstm.sqharm[272] = (unsigned int  )0;
            sqlstm.sqadto[272] = (unsigned short )0;
            sqlstm.sqtdso[272] = (unsigned short )0;
            sqlstm.sqhstv[273] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_23);
            sqlstm.sqhstl[273] = (unsigned int  )31;
            sqlstm.sqhsts[273] = (         int  )0;
            sqlstm.sqindv[273] = (         void  *)0;
            sqlstm.sqinds[273] = (         int  )0;
            sqlstm.sqharm[273] = (unsigned int  )0;
            sqlstm.sqadto[273] = (unsigned short )0;
            sqlstm.sqtdso[273] = (unsigned short )0;
            sqlstm.sqhstv[274] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_24);
            sqlstm.sqhstl[274] = (unsigned int  )31;
            sqlstm.sqhsts[274] = (         int  )0;
            sqlstm.sqindv[274] = (         void  *)0;
            sqlstm.sqinds[274] = (         int  )0;
            sqlstm.sqharm[274] = (unsigned int  )0;
            sqlstm.sqadto[274] = (unsigned short )0;
            sqlstm.sqtdso[274] = (unsigned short )0;
            sqlstm.sqhstv[275] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_25);
            sqlstm.sqhstl[275] = (unsigned int  )31;
            sqlstm.sqhsts[275] = (         int  )0;
            sqlstm.sqindv[275] = (         void  *)0;
            sqlstm.sqinds[275] = (         int  )0;
            sqlstm.sqharm[275] = (unsigned int  )0;
            sqlstm.sqadto[275] = (unsigned short )0;
            sqlstm.sqtdso[275] = (unsigned short )0;
            sqlstm.sqhstv[276] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_26);
            sqlstm.sqhstl[276] = (unsigned int  )31;
            sqlstm.sqhsts[276] = (         int  )0;
            sqlstm.sqindv[276] = (         void  *)0;
            sqlstm.sqinds[276] = (         int  )0;
            sqlstm.sqharm[276] = (unsigned int  )0;
            sqlstm.sqadto[276] = (unsigned short )0;
            sqlstm.sqtdso[276] = (unsigned short )0;
            sqlstm.sqhstv[277] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_27);
            sqlstm.sqhstl[277] = (unsigned int  )31;
            sqlstm.sqhsts[277] = (         int  )0;
            sqlstm.sqindv[277] = (         void  *)0;
            sqlstm.sqinds[277] = (         int  )0;
            sqlstm.sqharm[277] = (unsigned int  )0;
            sqlstm.sqadto[277] = (unsigned short )0;
            sqlstm.sqtdso[277] = (unsigned short )0;
            sqlstm.sqhstv[278] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_28);
            sqlstm.sqhstl[278] = (unsigned int  )31;
            sqlstm.sqhsts[278] = (         int  )0;
            sqlstm.sqindv[278] = (         void  *)0;
            sqlstm.sqinds[278] = (         int  )0;
            sqlstm.sqharm[278] = (unsigned int  )0;
            sqlstm.sqadto[278] = (unsigned short )0;
            sqlstm.sqtdso[278] = (unsigned short )0;
            sqlstm.sqhstv[279] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_29);
            sqlstm.sqhstl[279] = (unsigned int  )31;
            sqlstm.sqhsts[279] = (         int  )0;
            sqlstm.sqindv[279] = (         void  *)0;
            sqlstm.sqinds[279] = (         int  )0;
            sqlstm.sqharm[279] = (unsigned int  )0;
            sqlstm.sqadto[279] = (unsigned short )0;
            sqlstm.sqtdso[279] = (unsigned short )0;
            sqlstm.sqhstv[280] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_30);
            sqlstm.sqhstl[280] = (unsigned int  )31;
            sqlstm.sqhsts[280] = (         int  )0;
            sqlstm.sqindv[280] = (         void  *)0;
            sqlstm.sqinds[280] = (         int  )0;
            sqlstm.sqharm[280] = (unsigned int  )0;
            sqlstm.sqadto[280] = (unsigned short )0;
            sqlstm.sqtdso[280] = (unsigned short )0;
            sqlstm.sqhstv[281] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[281] = (unsigned int  )11;
            sqlstm.sqhsts[281] = (         int  )0;
            sqlstm.sqindv[281] = (         void  *)0;
            sqlstm.sqinds[281] = (         int  )0;
            sqlstm.sqharm[281] = (unsigned int  )0;
            sqlstm.sqadto[281] = (unsigned short )0;
            sqlstm.sqtdso[281] = (unsigned short )0;
            sqlstm.sqhstv[282] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[282] = (unsigned int  )21;
            sqlstm.sqhsts[282] = (         int  )0;
            sqlstm.sqindv[282] = (         void  *)0;
            sqlstm.sqinds[282] = (         int  )0;
            sqlstm.sqharm[282] = (unsigned int  )0;
            sqlstm.sqadto[282] = (unsigned short )0;
            sqlstm.sqtdso[282] = (unsigned short )0;
            sqlstm.sqhstv[283] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[283] = (unsigned int  )13;
            sqlstm.sqhsts[283] = (         int  )0;
            sqlstm.sqindv[283] = (         void  *)0;
            sqlstm.sqinds[283] = (         int  )0;
            sqlstm.sqharm[283] = (unsigned int  )0;
            sqlstm.sqadto[283] = (unsigned short )0;
            sqlstm.sqtdso[283] = (unsigned short )0;
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
        DBU_del_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    }

    DB_stop_query_timer("DBU_select_mrastevdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_mrastevdef_scalar(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MRASTEVDEF
                WHERE FACTORY = :MRASTEVDEF_N.FACTORY
                    AND TOOL_TYPE = :MRASTEVDEF_N.TOOL_TYPE
                    AND TOOL_EVENT_ID = :MRASTEVDEF_N.TOOL_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MRASTEVDEF where\
 ((FACTORY=:b1 and TOOL_TYPE=:b2) and TOOL_EVENT_ID=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2307;
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
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )13;
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

    DB_stop_query_timer("DBU_select_mrastevdef_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_mrastevdef(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MRASTEVDEF
                WHERE FACTORY = :MRASTEVDEF_N.FACTORY
                    AND TOOL_TYPE = :MRASTEVDEF_N.TOOL_TYPE
                    AND TOOL_EVENT_ID = :MRASTEVDEF_N.TOOL_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MRASTEVDEF  where ((FACTORY=:b0 and\
 TOOL_TYPE=:b1) and TOOL_EVENT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2338;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )13;
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

    DB_stop_query_timer("DBU_delete_mrastevdef", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_mrastevdef(struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MRASTEVDEF( 
                    FACTORY, 
                    TOOL_TYPE, 
                    TOOL_EVENT_ID, 
                    TOOL_EVENT_DESC, 
                    SYSTEM_FLAG, 
                    COLLECT_DEFECT_FLAG, 
                    CLEAN_DEFECT_FLAG, 
                    CHK_ITEM_1, 
                    CHK_ITEM_2, 
                    CHK_ITEM_3, 
                    CHK_ITEM_4, 
                    CHK_ITEM_5, 
                    CHK_ITEM_6, 
                    CHK_ITEM_7, 
                    CHK_ITEM_8, 
                    CHK_ITEM_9, 
                    CHK_ITEM_10, 
                    CHK_ITEM_11, 
                    CHK_ITEM_12, 
                    CHK_ITEM_13, 
                    CHK_ITEM_14, 
                    CHK_ITEM_15, 
                    CHK_ITEM_16, 
                    CHK_ITEM_17, 
                    CHK_ITEM_18, 
                    CHK_ITEM_19, 
                    CHK_ITEM_20, 
                    CHK_ITEM_21, 
                    CHK_ITEM_22, 
                    CHK_ITEM_23, 
                    CHK_ITEM_24, 
                    CHK_ITEM_25, 
                    CHK_ITEM_26, 
                    CHK_ITEM_27, 
                    CHK_ITEM_28, 
                    CHK_ITEM_29, 
                    CHK_ITEM_30, 
                    CHK_FLAG_1, 
                    CHK_FLAG_2, 
                    CHK_FLAG_3, 
                    CHK_FLAG_4, 
                    CHK_FLAG_5, 
                    CHK_FLAG_6, 
                    CHK_FLAG_7, 
                    CHK_FLAG_8, 
                    CHK_FLAG_9, 
                    CHK_FLAG_10, 
                    CHK_FLAG_11, 
                    CHK_FLAG_12, 
                    CHK_FLAG_13, 
                    CHK_FLAG_14, 
                    CHK_FLAG_15, 
                    CHK_FLAG_16, 
                    CHK_FLAG_17, 
                    CHK_FLAG_18, 
                    CHK_FLAG_19, 
                    CHK_FLAG_20, 
                    CHK_FLAG_21, 
                    CHK_FLAG_22, 
                    CHK_FLAG_23, 
                    CHK_FLAG_24, 
                    CHK_FLAG_25, 
                    CHK_FLAG_26, 
                    CHK_FLAG_27, 
                    CHK_FLAG_28, 
                    CHK_FLAG_29, 
                    CHK_FLAG_30, 
                    CHK_VALUE_1, 
                    CHK_VALUE_2, 
                    CHK_VALUE_3, 
                    CHK_VALUE_4, 
                    CHK_VALUE_5, 
                    CHK_VALUE_6, 
                    CHK_VALUE_7, 
                    CHK_VALUE_8, 
                    CHK_VALUE_9, 
                    CHK_VALUE_10, 
                    CHK_VALUE_11, 
                    CHK_VALUE_12, 
                    CHK_VALUE_13, 
                    CHK_VALUE_14, 
                    CHK_VALUE_15, 
                    CHK_VALUE_16, 
                    CHK_VALUE_17, 
                    CHK_VALUE_18, 
                    CHK_VALUE_19, 
                    CHK_VALUE_20, 
                    CHK_VALUE_21, 
                    CHK_VALUE_22, 
                    CHK_VALUE_23, 
                    CHK_VALUE_24, 
                    CHK_VALUE_25, 
                    CHK_VALUE_26, 
                    CHK_VALUE_27, 
                    CHK_VALUE_28, 
                    CHK_VALUE_29, 
                    CHK_VALUE_30, 
                    CHK_FIELD_1, 
                    CHK_FIELD_2, 
                    CHK_FIELD_3, 
                    CHK_FIELD_4, 
                    CHK_FIELD_5, 
                    CHK_FIELD_6, 
                    CHK_FIELD_7, 
                    CHK_FIELD_8, 
                    CHK_FIELD_9, 
                    CHK_FIELD_10, 
                    CHK_FIELD_11, 
                    CHK_FIELD_12, 
                    CHK_FIELD_13, 
                    CHK_FIELD_14, 
                    CHK_FIELD_15, 
                    CHK_FIELD_16, 
                    CHK_FIELD_17, 
                    CHK_FIELD_18, 
                    CHK_FIELD_19, 
                    CHK_FIELD_20, 
                    CHK_FIELD_21, 
                    CHK_FIELD_22, 
                    CHK_FIELD_23, 
                    CHK_FIELD_24, 
                    CHK_FIELD_25, 
                    CHK_FIELD_26, 
                    CHK_FIELD_27, 
                    CHK_FIELD_28, 
                    CHK_FIELD_29, 
                    CHK_FIELD_30, 
                    CHG_ITEM_1, 
                    CHG_ITEM_2, 
                    CHG_ITEM_3, 
                    CHG_ITEM_4, 
                    CHG_ITEM_5, 
                    CHG_ITEM_6, 
                    CHG_ITEM_7, 
                    CHG_ITEM_8, 
                    CHG_ITEM_9, 
                    CHG_ITEM_10, 
                    CHG_ITEM_11, 
                    CHG_ITEM_12, 
                    CHG_ITEM_13, 
                    CHG_ITEM_14, 
                    CHG_ITEM_15, 
                    CHG_ITEM_16, 
                    CHG_ITEM_17, 
                    CHG_ITEM_18, 
                    CHG_ITEM_19, 
                    CHG_ITEM_20, 
                    CHG_ITEM_21, 
                    CHG_ITEM_22, 
                    CHG_ITEM_23, 
                    CHG_ITEM_24, 
                    CHG_ITEM_25, 
                    CHG_ITEM_26, 
                    CHG_ITEM_27, 
                    CHG_ITEM_28, 
                    CHG_ITEM_29, 
                    CHG_ITEM_30, 
                    CHG_FLAG_1, 
                    CHG_FLAG_2, 
                    CHG_FLAG_3, 
                    CHG_FLAG_4, 
                    CHG_FLAG_5, 
                    CHG_FLAG_6, 
                    CHG_FLAG_7, 
                    CHG_FLAG_8, 
                    CHG_FLAG_9, 
                    CHG_FLAG_10, 
                    CHG_FLAG_11, 
                    CHG_FLAG_12, 
                    CHG_FLAG_13, 
                    CHG_FLAG_14, 
                    CHG_FLAG_15, 
                    CHG_FLAG_16, 
                    CHG_FLAG_17, 
                    CHG_FLAG_18, 
                    CHG_FLAG_19, 
                    CHG_FLAG_20, 
                    CHG_FLAG_21, 
                    CHG_FLAG_22, 
                    CHG_FLAG_23, 
                    CHG_FLAG_24, 
                    CHG_FLAG_25, 
                    CHG_FLAG_26, 
                    CHG_FLAG_27, 
                    CHG_FLAG_28, 
                    CHG_FLAG_29, 
                    CHG_FLAG_30, 
                    CHG_VALUE_1, 
                    CHG_VALUE_2, 
                    CHG_VALUE_3, 
                    CHG_VALUE_4, 
                    CHG_VALUE_5, 
                    CHG_VALUE_6, 
                    CHG_VALUE_7, 
                    CHG_VALUE_8, 
                    CHG_VALUE_9, 
                    CHG_VALUE_10, 
                    CHG_VALUE_11, 
                    CHG_VALUE_12, 
                    CHG_VALUE_13, 
                    CHG_VALUE_14, 
                    CHG_VALUE_15, 
                    CHG_VALUE_16, 
                    CHG_VALUE_17, 
                    CHG_VALUE_18, 
                    CHG_VALUE_19, 
                    CHG_VALUE_20, 
                    CHG_VALUE_21, 
                    CHG_VALUE_22, 
                    CHG_VALUE_23, 
                    CHG_VALUE_24, 
                    CHG_VALUE_25, 
                    CHG_VALUE_26, 
                    CHG_VALUE_27, 
                    CHG_VALUE_28, 
                    CHG_VALUE_29, 
                    CHG_VALUE_30, 
                    CHG_OPT_1, 
                    CHG_OPT_2, 
                    CHG_OPT_3, 
                    CHG_OPT_4, 
                    CHG_OPT_5, 
                    CHG_OPT_6, 
                    CHG_OPT_7, 
                    CHG_OPT_8, 
                    CHG_OPT_9, 
                    CHG_OPT_10, 
                    CHG_OPT_11, 
                    CHG_OPT_12, 
                    CHG_OPT_13, 
                    CHG_OPT_14, 
                    CHG_OPT_15, 
                    CHG_OPT_16, 
                    CHG_OPT_17, 
                    CHG_OPT_18, 
                    CHG_OPT_19, 
                    CHG_OPT_20, 
                    CHG_OPT_21, 
                    CHG_OPT_22, 
                    CHG_OPT_23, 
                    CHG_OPT_24, 
                    CHG_OPT_25, 
                    CHG_OPT_26, 
                    CHG_OPT_27, 
                    CHG_OPT_28, 
                    CHG_OPT_29, 
                    CHG_OPT_30, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    CHG_FIELD_1, 
                    CHG_FIELD_2, 
                    CHG_FIELD_3, 
                    CHG_FIELD_4, 
                    CHG_FIELD_5, 
                    CHG_FIELD_6, 
                    CHG_FIELD_7, 
                    CHG_FIELD_8, 
                    CHG_FIELD_9, 
                    CHG_FIELD_10, 
                    CHG_FIELD_11, 
                    CHG_FIELD_12, 
                    CHG_FIELD_13, 
                    CHG_FIELD_14, 
                    CHG_FIELD_15, 
                    CHG_FIELD_16, 
                    CHG_FIELD_17, 
                    CHG_FIELD_18, 
                    CHG_FIELD_19, 
                    CHG_FIELD_20, 
                    CHG_FIELD_21, 
                    CHG_FIELD_22, 
                    CHG_FIELD_23, 
                    CHG_FIELD_24, 
                    CHG_FIELD_25, 
                    CHG_FIELD_26, 
                    CHG_FIELD_27, 
                    CHG_FIELD_28, 
                    CHG_FIELD_29, 
                    CHG_FIELD_30
         ) 
        VALUES (
                    :MRASTEVDEF_N.FACTORY,
                    :MRASTEVDEF_N.TOOL_TYPE,
                    :MRASTEVDEF_N.TOOL_EVENT_ID,
                    :MRASTEVDEF_N.TOOL_EVENT_DESC,
                    :MRASTEVDEF_N.SYSTEM_FLAG,
                    :MRASTEVDEF_N.COLLECT_DEFECT_FLAG,
                    :MRASTEVDEF_N.CLEAN_DEFECT_FLAG,
                    :MRASTEVDEF_N.CHK_ITEM_1,
                    :MRASTEVDEF_N.CHK_ITEM_2,
                    :MRASTEVDEF_N.CHK_ITEM_3,
                    :MRASTEVDEF_N.CHK_ITEM_4,
                    :MRASTEVDEF_N.CHK_ITEM_5,
                    :MRASTEVDEF_N.CHK_ITEM_6,
                    :MRASTEVDEF_N.CHK_ITEM_7,
                    :MRASTEVDEF_N.CHK_ITEM_8,
                    :MRASTEVDEF_N.CHK_ITEM_9,
                    :MRASTEVDEF_N.CHK_ITEM_10,
                    :MRASTEVDEF_N.CHK_ITEM_11,
                    :MRASTEVDEF_N.CHK_ITEM_12,
                    :MRASTEVDEF_N.CHK_ITEM_13,
                    :MRASTEVDEF_N.CHK_ITEM_14,
                    :MRASTEVDEF_N.CHK_ITEM_15,
                    :MRASTEVDEF_N.CHK_ITEM_16,
                    :MRASTEVDEF_N.CHK_ITEM_17,
                    :MRASTEVDEF_N.CHK_ITEM_18,
                    :MRASTEVDEF_N.CHK_ITEM_19,
                    :MRASTEVDEF_N.CHK_ITEM_20,
                    :MRASTEVDEF_N.CHK_ITEM_21,
                    :MRASTEVDEF_N.CHK_ITEM_22,
                    :MRASTEVDEF_N.CHK_ITEM_23,
                    :MRASTEVDEF_N.CHK_ITEM_24,
                    :MRASTEVDEF_N.CHK_ITEM_25,
                    :MRASTEVDEF_N.CHK_ITEM_26,
                    :MRASTEVDEF_N.CHK_ITEM_27,
                    :MRASTEVDEF_N.CHK_ITEM_28,
                    :MRASTEVDEF_N.CHK_ITEM_29,
                    :MRASTEVDEF_N.CHK_ITEM_30,
                    :MRASTEVDEF_N.CHK_FLAG_1,
                    :MRASTEVDEF_N.CHK_FLAG_2,
                    :MRASTEVDEF_N.CHK_FLAG_3,
                    :MRASTEVDEF_N.CHK_FLAG_4,
                    :MRASTEVDEF_N.CHK_FLAG_5,
                    :MRASTEVDEF_N.CHK_FLAG_6,
                    :MRASTEVDEF_N.CHK_FLAG_7,
                    :MRASTEVDEF_N.CHK_FLAG_8,
                    :MRASTEVDEF_N.CHK_FLAG_9,
                    :MRASTEVDEF_N.CHK_FLAG_10,
                    :MRASTEVDEF_N.CHK_FLAG_11,
                    :MRASTEVDEF_N.CHK_FLAG_12,
                    :MRASTEVDEF_N.CHK_FLAG_13,
                    :MRASTEVDEF_N.CHK_FLAG_14,
                    :MRASTEVDEF_N.CHK_FLAG_15,
                    :MRASTEVDEF_N.CHK_FLAG_16,
                    :MRASTEVDEF_N.CHK_FLAG_17,
                    :MRASTEVDEF_N.CHK_FLAG_18,
                    :MRASTEVDEF_N.CHK_FLAG_19,
                    :MRASTEVDEF_N.CHK_FLAG_20,
                    :MRASTEVDEF_N.CHK_FLAG_21,
                    :MRASTEVDEF_N.CHK_FLAG_22,
                    :MRASTEVDEF_N.CHK_FLAG_23,
                    :MRASTEVDEF_N.CHK_FLAG_24,
                    :MRASTEVDEF_N.CHK_FLAG_25,
                    :MRASTEVDEF_N.CHK_FLAG_26,
                    :MRASTEVDEF_N.CHK_FLAG_27,
                    :MRASTEVDEF_N.CHK_FLAG_28,
                    :MRASTEVDEF_N.CHK_FLAG_29,
                    :MRASTEVDEF_N.CHK_FLAG_30,
                    :MRASTEVDEF_N.CHK_VALUE_1,
                    :MRASTEVDEF_N.CHK_VALUE_2,
                    :MRASTEVDEF_N.CHK_VALUE_3,
                    :MRASTEVDEF_N.CHK_VALUE_4,
                    :MRASTEVDEF_N.CHK_VALUE_5,
                    :MRASTEVDEF_N.CHK_VALUE_6,
                    :MRASTEVDEF_N.CHK_VALUE_7,
                    :MRASTEVDEF_N.CHK_VALUE_8,
                    :MRASTEVDEF_N.CHK_VALUE_9,
                    :MRASTEVDEF_N.CHK_VALUE_10,
                    :MRASTEVDEF_N.CHK_VALUE_11,
                    :MRASTEVDEF_N.CHK_VALUE_12,
                    :MRASTEVDEF_N.CHK_VALUE_13,
                    :MRASTEVDEF_N.CHK_VALUE_14,
                    :MRASTEVDEF_N.CHK_VALUE_15,
                    :MRASTEVDEF_N.CHK_VALUE_16,
                    :MRASTEVDEF_N.CHK_VALUE_17,
                    :MRASTEVDEF_N.CHK_VALUE_18,
                    :MRASTEVDEF_N.CHK_VALUE_19,
                    :MRASTEVDEF_N.CHK_VALUE_20,
                    :MRASTEVDEF_N.CHK_VALUE_21,
                    :MRASTEVDEF_N.CHK_VALUE_22,
                    :MRASTEVDEF_N.CHK_VALUE_23,
                    :MRASTEVDEF_N.CHK_VALUE_24,
                    :MRASTEVDEF_N.CHK_VALUE_25,
                    :MRASTEVDEF_N.CHK_VALUE_26,
                    :MRASTEVDEF_N.CHK_VALUE_27,
                    :MRASTEVDEF_N.CHK_VALUE_28,
                    :MRASTEVDEF_N.CHK_VALUE_29,
                    :MRASTEVDEF_N.CHK_VALUE_30,
                    :MRASTEVDEF_N.CHK_FIELD_1,
                    :MRASTEVDEF_N.CHK_FIELD_2,
                    :MRASTEVDEF_N.CHK_FIELD_3,
                    :MRASTEVDEF_N.CHK_FIELD_4,
                    :MRASTEVDEF_N.CHK_FIELD_5,
                    :MRASTEVDEF_N.CHK_FIELD_6,
                    :MRASTEVDEF_N.CHK_FIELD_7,
                    :MRASTEVDEF_N.CHK_FIELD_8,
                    :MRASTEVDEF_N.CHK_FIELD_9,
                    :MRASTEVDEF_N.CHK_FIELD_10,
                    :MRASTEVDEF_N.CHK_FIELD_11,
                    :MRASTEVDEF_N.CHK_FIELD_12,
                    :MRASTEVDEF_N.CHK_FIELD_13,
                    :MRASTEVDEF_N.CHK_FIELD_14,
                    :MRASTEVDEF_N.CHK_FIELD_15,
                    :MRASTEVDEF_N.CHK_FIELD_16,
                    :MRASTEVDEF_N.CHK_FIELD_17,
                    :MRASTEVDEF_N.CHK_FIELD_18,
                    :MRASTEVDEF_N.CHK_FIELD_19,
                    :MRASTEVDEF_N.CHK_FIELD_20,
                    :MRASTEVDEF_N.CHK_FIELD_21,
                    :MRASTEVDEF_N.CHK_FIELD_22,
                    :MRASTEVDEF_N.CHK_FIELD_23,
                    :MRASTEVDEF_N.CHK_FIELD_24,
                    :MRASTEVDEF_N.CHK_FIELD_25,
                    :MRASTEVDEF_N.CHK_FIELD_26,
                    :MRASTEVDEF_N.CHK_FIELD_27,
                    :MRASTEVDEF_N.CHK_FIELD_28,
                    :MRASTEVDEF_N.CHK_FIELD_29,
                    :MRASTEVDEF_N.CHK_FIELD_30,
                    :MRASTEVDEF_N.CHG_ITEM_1,
                    :MRASTEVDEF_N.CHG_ITEM_2,
                    :MRASTEVDEF_N.CHG_ITEM_3,
                    :MRASTEVDEF_N.CHG_ITEM_4,
                    :MRASTEVDEF_N.CHG_ITEM_5,
                    :MRASTEVDEF_N.CHG_ITEM_6,
                    :MRASTEVDEF_N.CHG_ITEM_7,
                    :MRASTEVDEF_N.CHG_ITEM_8,
                    :MRASTEVDEF_N.CHG_ITEM_9,
                    :MRASTEVDEF_N.CHG_ITEM_10,
                    :MRASTEVDEF_N.CHG_ITEM_11,
                    :MRASTEVDEF_N.CHG_ITEM_12,
                    :MRASTEVDEF_N.CHG_ITEM_13,
                    :MRASTEVDEF_N.CHG_ITEM_14,
                    :MRASTEVDEF_N.CHG_ITEM_15,
                    :MRASTEVDEF_N.CHG_ITEM_16,
                    :MRASTEVDEF_N.CHG_ITEM_17,
                    :MRASTEVDEF_N.CHG_ITEM_18,
                    :MRASTEVDEF_N.CHG_ITEM_19,
                    :MRASTEVDEF_N.CHG_ITEM_20,
                    :MRASTEVDEF_N.CHG_ITEM_21,
                    :MRASTEVDEF_N.CHG_ITEM_22,
                    :MRASTEVDEF_N.CHG_ITEM_23,
                    :MRASTEVDEF_N.CHG_ITEM_24,
                    :MRASTEVDEF_N.CHG_ITEM_25,
                    :MRASTEVDEF_N.CHG_ITEM_26,
                    :MRASTEVDEF_N.CHG_ITEM_27,
                    :MRASTEVDEF_N.CHG_ITEM_28,
                    :MRASTEVDEF_N.CHG_ITEM_29,
                    :MRASTEVDEF_N.CHG_ITEM_30,
                    :MRASTEVDEF_N.CHG_FLAG_1,
                    :MRASTEVDEF_N.CHG_FLAG_2,
                    :MRASTEVDEF_N.CHG_FLAG_3,
                    :MRASTEVDEF_N.CHG_FLAG_4,
                    :MRASTEVDEF_N.CHG_FLAG_5,
                    :MRASTEVDEF_N.CHG_FLAG_6,
                    :MRASTEVDEF_N.CHG_FLAG_7,
                    :MRASTEVDEF_N.CHG_FLAG_8,
                    :MRASTEVDEF_N.CHG_FLAG_9,
                    :MRASTEVDEF_N.CHG_FLAG_10,
                    :MRASTEVDEF_N.CHG_FLAG_11,
                    :MRASTEVDEF_N.CHG_FLAG_12,
                    :MRASTEVDEF_N.CHG_FLAG_13,
                    :MRASTEVDEF_N.CHG_FLAG_14,
                    :MRASTEVDEF_N.CHG_FLAG_15,
                    :MRASTEVDEF_N.CHG_FLAG_16,
                    :MRASTEVDEF_N.CHG_FLAG_17,
                    :MRASTEVDEF_N.CHG_FLAG_18,
                    :MRASTEVDEF_N.CHG_FLAG_19,
                    :MRASTEVDEF_N.CHG_FLAG_20,
                    :MRASTEVDEF_N.CHG_FLAG_21,
                    :MRASTEVDEF_N.CHG_FLAG_22,
                    :MRASTEVDEF_N.CHG_FLAG_23,
                    :MRASTEVDEF_N.CHG_FLAG_24,
                    :MRASTEVDEF_N.CHG_FLAG_25,
                    :MRASTEVDEF_N.CHG_FLAG_26,
                    :MRASTEVDEF_N.CHG_FLAG_27,
                    :MRASTEVDEF_N.CHG_FLAG_28,
                    :MRASTEVDEF_N.CHG_FLAG_29,
                    :MRASTEVDEF_N.CHG_FLAG_30,
                    :MRASTEVDEF_N.CHG_VALUE_1,
                    :MRASTEVDEF_N.CHG_VALUE_2,
                    :MRASTEVDEF_N.CHG_VALUE_3,
                    :MRASTEVDEF_N.CHG_VALUE_4,
                    :MRASTEVDEF_N.CHG_VALUE_5,
                    :MRASTEVDEF_N.CHG_VALUE_6,
                    :MRASTEVDEF_N.CHG_VALUE_7,
                    :MRASTEVDEF_N.CHG_VALUE_8,
                    :MRASTEVDEF_N.CHG_VALUE_9,
                    :MRASTEVDEF_N.CHG_VALUE_10,
                    :MRASTEVDEF_N.CHG_VALUE_11,
                    :MRASTEVDEF_N.CHG_VALUE_12,
                    :MRASTEVDEF_N.CHG_VALUE_13,
                    :MRASTEVDEF_N.CHG_VALUE_14,
                    :MRASTEVDEF_N.CHG_VALUE_15,
                    :MRASTEVDEF_N.CHG_VALUE_16,
                    :MRASTEVDEF_N.CHG_VALUE_17,
                    :MRASTEVDEF_N.CHG_VALUE_18,
                    :MRASTEVDEF_N.CHG_VALUE_19,
                    :MRASTEVDEF_N.CHG_VALUE_20,
                    :MRASTEVDEF_N.CHG_VALUE_21,
                    :MRASTEVDEF_N.CHG_VALUE_22,
                    :MRASTEVDEF_N.CHG_VALUE_23,
                    :MRASTEVDEF_N.CHG_VALUE_24,
                    :MRASTEVDEF_N.CHG_VALUE_25,
                    :MRASTEVDEF_N.CHG_VALUE_26,
                    :MRASTEVDEF_N.CHG_VALUE_27,
                    :MRASTEVDEF_N.CHG_VALUE_28,
                    :MRASTEVDEF_N.CHG_VALUE_29,
                    :MRASTEVDEF_N.CHG_VALUE_30,
                    :MRASTEVDEF_N.CHG_OPT_1,
                    :MRASTEVDEF_N.CHG_OPT_2,
                    :MRASTEVDEF_N.CHG_OPT_3,
                    :MRASTEVDEF_N.CHG_OPT_4,
                    :MRASTEVDEF_N.CHG_OPT_5,
                    :MRASTEVDEF_N.CHG_OPT_6,
                    :MRASTEVDEF_N.CHG_OPT_7,
                    :MRASTEVDEF_N.CHG_OPT_8,
                    :MRASTEVDEF_N.CHG_OPT_9,
                    :MRASTEVDEF_N.CHG_OPT_10,
                    :MRASTEVDEF_N.CHG_OPT_11,
                    :MRASTEVDEF_N.CHG_OPT_12,
                    :MRASTEVDEF_N.CHG_OPT_13,
                    :MRASTEVDEF_N.CHG_OPT_14,
                    :MRASTEVDEF_N.CHG_OPT_15,
                    :MRASTEVDEF_N.CHG_OPT_16,
                    :MRASTEVDEF_N.CHG_OPT_17,
                    :MRASTEVDEF_N.CHG_OPT_18,
                    :MRASTEVDEF_N.CHG_OPT_19,
                    :MRASTEVDEF_N.CHG_OPT_20,
                    :MRASTEVDEF_N.CHG_OPT_21,
                    :MRASTEVDEF_N.CHG_OPT_22,
                    :MRASTEVDEF_N.CHG_OPT_23,
                    :MRASTEVDEF_N.CHG_OPT_24,
                    :MRASTEVDEF_N.CHG_OPT_25,
                    :MRASTEVDEF_N.CHG_OPT_26,
                    :MRASTEVDEF_N.CHG_OPT_27,
                    :MRASTEVDEF_N.CHG_OPT_28,
                    :MRASTEVDEF_N.CHG_OPT_29,
                    :MRASTEVDEF_N.CHG_OPT_30,
                    :MRASTEVDEF_N.CREATE_USER_ID,
                    :MRASTEVDEF_N.CREATE_TIME,
                    :MRASTEVDEF_N.UPDATE_USER_ID,
                    :MRASTEVDEF_N.UPDATE_TIME,
                    :MRASTEVDEF_N.CHG_FIELD_1,
                    :MRASTEVDEF_N.CHG_FIELD_2,
                    :MRASTEVDEF_N.CHG_FIELD_3,
                    :MRASTEVDEF_N.CHG_FIELD_4,
                    :MRASTEVDEF_N.CHG_FIELD_5,
                    :MRASTEVDEF_N.CHG_FIELD_6,
                    :MRASTEVDEF_N.CHG_FIELD_7,
                    :MRASTEVDEF_N.CHG_FIELD_8,
                    :MRASTEVDEF_N.CHG_FIELD_9,
                    :MRASTEVDEF_N.CHG_FIELD_10,
                    :MRASTEVDEF_N.CHG_FIELD_11,
                    :MRASTEVDEF_N.CHG_FIELD_12,
                    :MRASTEVDEF_N.CHG_FIELD_13,
                    :MRASTEVDEF_N.CHG_FIELD_14,
                    :MRASTEVDEF_N.CHG_FIELD_15,
                    :MRASTEVDEF_N.CHG_FIELD_16,
                    :MRASTEVDEF_N.CHG_FIELD_17,
                    :MRASTEVDEF_N.CHG_FIELD_18,
                    :MRASTEVDEF_N.CHG_FIELD_19,
                    :MRASTEVDEF_N.CHG_FIELD_20,
                    :MRASTEVDEF_N.CHG_FIELD_21,
                    :MRASTEVDEF_N.CHG_FIELD_22,
                    :MRASTEVDEF_N.CHG_FIELD_23,
                    :MRASTEVDEF_N.CHG_FIELD_24,
                    :MRASTEVDEF_N.CHG_FIELD_25,
                    :MRASTEVDEF_N.CHG_FIELD_26,
                    :MRASTEVDEF_N.CHG_FIELD_27,
                    :MRASTEVDEF_N.CHG_FIELD_28,
                    :MRASTEVDEF_N.CHG_FIELD_29,
                    :MRASTEVDEF_N.CHG_FIELD_30
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 284;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MRASTEVDEF (FACTORY,TOOL_TYPE,TOOL_EVENT_ID,TOOL_EVENT_DE\
SC,SYSTEM_FLAG,COLLECT_DEFECT_FLAG,CLEAN_DEFECT_FLAG,CHK_ITEM_1,CHK_ITEM_2,C\
HK_ITEM_3,CHK_ITEM_4,CHK_ITEM_5,CHK_ITEM_6,CHK_ITEM_7,CHK_ITEM_8,CHK_ITEM_9,\
CHK_ITEM_10,CHK_ITEM_11,CHK_ITEM_12,CHK_ITEM_13,CHK_ITEM_14,CHK_ITEM_15,CHK_\
ITEM_16,CHK_ITEM_17,CHK_ITEM_18,CHK_ITEM_19,CHK_ITEM_20,CHK_ITEM_21,CHK_ITEM\
_22,CHK_ITEM_23,CHK_ITEM_24,CHK_ITEM_25,CHK_ITEM_26,CHK_ITEM_27,CHK_ITEM_28,\
CHK_ITEM_29,CHK_ITEM_30,CHK_FLAG_1,CHK_FLAG_2,CHK_FLAG_3,CHK_FLAG_4,CHK_FLAG\
_5,CHK_FLAG_6,CHK_FLAG_7,CHK_FLAG_8,CHK_FLAG_9,CHK_FLAG_10,CHK_FLAG_11,CHK_F\
LAG_12,CHK_FLAG_13,CHK_FLAG_14,CHK_FLAG_15,CHK_FLAG_16,CHK_FLAG_17,CHK_FLAG_\
18,CHK_FLAG_19,CHK_FLAG_20,CHK_FLAG_21,CHK_FLAG_22,CHK_FLAG_23,CHK_FLAG_24,C\
HK_FLAG_25,CHK_FLAG_26,CHK_FLAG_27,CHK_FLAG_28,CHK_FLAG_29,CHK_FLAG_30,CHK_V\
ALUE_1,CHK_VALUE_2,CHK_VALUE_3,CHK_VALUE_4,CHK_VALUE_5,CHK_VALUE_6,CHK_VALUE\
_7,CHK_VALUE_8,CHK_VALUE_9,CHK_VALUE_10,CHK_VALUE_11,CHK_VALUE_12,CHK_VALUE_\
13,CHK_VALUE_14,CHK_VALUE_15,CHK_VALUE_16,C");
    sqlbuft((void **)0,
      "HK_VALUE_17,CHK_VALUE_18,CHK_VALUE_19,CHK_VALUE_20,CHK_VALUE_21,CHK_V\
ALUE_22,CHK_VALUE_23,CHK_VALUE_24,CHK_VALUE_25,CHK_VALUE_26,CHK_VALUE_27,CHK\
_VALUE_28,CHK_VALUE_29,CHK_VALUE_30,CHK_FIELD_1,CHK_FIELD_2,CHK_FIELD_3,CHK_\
FIELD_4,CHK_FIELD_5,CHK_FIELD_6,CHK_FIELD_7,CHK_FIELD_8,CHK_FIELD_9,CHK_FIEL\
D_10,CHK_FIELD_11,CHK_FIELD_12,CHK_FIELD_13,CHK_FIELD_14,CHK_FIELD_15,CHK_FI\
ELD_16,CHK_FIELD_17,CHK_FIELD_18,CHK_FIELD_19,CHK_FIELD_20,CHK_FIELD_21,CHK_\
FIELD_22,CHK_FIELD_23,CHK_FIELD_24,CHK_FIELD_25,CHK_FIELD_26,CHK_FIELD_27,CH\
K_FIELD_28,CHK_FIELD_29,CHK_FIELD_30,CHG_ITEM_1,CHG_ITEM_2,CHG_ITEM_3,CHG_IT\
EM_4,CHG_ITEM_5,CHG_ITEM_6,CHG_ITEM_7,CHG_ITEM_8,CHG_ITEM_9,CHG_ITEM_10,CHG_\
ITEM_11,CHG_ITEM_12,CHG_ITEM_13,CHG_ITEM_14,CHG_ITEM_15,CHG_ITEM_16,CHG_ITEM\
_17,CHG_ITEM_18,CHG_ITEM_19,CHG_ITEM_20,CHG_ITEM_21,CHG_ITEM_22,CHG_ITEM_23,\
CHG_ITEM_24,CHG_ITEM_25,CHG_ITEM_26,CHG_ITEM_27,CHG_ITEM_28,CHG_ITEM_29,CHG_\
ITEM_30,CHG_FLAG_1,CHG_FLAG_2,CHG_FLAG_3,CHG_FLAG_4,CHG_FLAG_5,CHG_FLAG_6,CH\
G_FLAG_7,CHG_FLAG_8,CHG_FLAG_9,CHG_FLAG_10,");
    sqlbuft((void **)0,
      "CHG_FLAG_11,CHG_FLAG_12,CHG_FLAG_13,CHG_FLAG_14,CHG_FLAG_15,CHG_FLAG_\
16,CHG_FLAG_17,CHG_FLAG_18,CHG_FLAG_19,CHG_FLAG_20,CHG_FLAG_21,CHG_FLAG_22,C\
HG_FLAG_23,CHG_FLAG_24,CHG_FLAG_25,CHG_FLAG_26,CHG_FLAG_27,CHG_FLAG_28,CHG_F\
LAG_29,CHG_FLAG_30,CHG_VALUE_1,CHG_VALUE_2,CHG_VALUE_3,CHG_VALUE_4,CHG_VALUE\
_5,CHG_VALUE_6,CHG_VALUE_7,CHG_VALUE_8,CHG_VALUE_9,CHG_VALUE_10,CHG_VALUE_11\
,CHG_VALUE_12,CHG_VALUE_13,CHG_VALUE_14,CHG_VALUE_15,CHG_VALUE_16,CHG_VALUE_\
17,CHG_VALUE_18,CHG_VALUE_19,CHG_VALUE_20,CHG_VALUE_21,CHG_VALUE_22,CHG_VALU\
E_23,CHG_VALUE_24,CHG_VALUE_25,CHG_VALUE_26,CHG_VALUE_27,CHG_VALUE_28,CHG_VA\
LUE_29,CHG_VALUE_30,CHG_OPT_1,CHG_OPT_2,CHG_OPT_3,CHG_OPT_4,CHG_OPT_5,CHG_OP\
T_6,CHG_OPT_7,CHG_OPT_8,CHG_OPT_9,CHG_OPT_10,CHG_OPT_11,CHG_OPT_12,CHG_OPT_1\
3,CHG_OPT_14,CHG_OPT_15,CHG_OPT_16,CHG_OPT_17,CHG_OPT_18,CHG_OPT_19,CHG_OPT_\
20,CHG_OPT_21,CHG_OPT_22,CHG_OPT_23,CHG_OPT_24,CHG_OPT_25,CHG_OPT_26,CHG_OPT\
_27,CHG_OPT_28,CHG_OPT_29,CHG_OPT_30,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_\
ID,UPDATE_TIME,CHG_FIELD_1,CHG_FIELD_2,CHG_");
    sqlbuft((void **)0,
      "FIELD_3,CHG_FIELD_4,CHG_FIELD_5,CHG_FIELD_6,CHG_FIELD_7,CHG_FIELD_8,C\
HG_FIELD_9,CHG_FIELD_10,CHG_FIELD_11,CHG_FIELD_12,CHG_FIELD_13,CHG_FIELD_14,\
CHG_FIELD_15,CHG_FIELD_16,CHG_FIELD_17,CHG_FIELD_18,CHG_FIELD_19,CHG_FIELD_2\
0,CHG_FIELD_21,CHG_FIELD_22,CHG_FIELD_23,CHG_FIELD_24,CHG_FIELD_25,CHG_FIELD\
_26,CHG_FIELD_27,CHG_FIELD_28,CHG_FIELD_29,CHG_FIELD_30) values (:b0,:b1,:b2\
,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b\
19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b3\
4,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49\
,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,\
:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:\
b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b\
95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108\
,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:b117,:b118,:b119,:b120,:b1\
21,:b122,:b123,:b124,:b125,:b126,:b127,:b12");
    sqlstm.stmt = "8,:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136,:b137,\
:b138,:b139,:b140,:b141,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150\
,:b151,:b152,:b153,:b154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b162,:b16\
3,:b164,:b165,:b166,:b167,:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b175,:b1\
76,:b177,:b178,:b179,:b180,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:b188,:b\
189,:b190,:b191,:b192,:b193,:b194,:b195,:b196,:b197,:b198,:b199,:b200,:b201,:\
b202,:b203,:b204,:b205,:b206,:b207,:b208,:b209,:b210,:b211,:b212,:b213,:b214,\
:b215,:b216,:b217,:b218,:b219,:b220,:b221,:b222,:b223,:b224,:b225,:b226,:b227\
,:b228,:b229,:b230,:b231,:b232,:b233,:b234,:b235,:b236,:b237,:b238,:b239,:b24\
0,:b241,:b242,:b243,:b244,:b245,:b246,:b247,:b248,:b249,:b250,:b251,:b252,:b2\
53,:b254,:b255,:b256,:b257,:b258,:b259,:b260,:b261,:b262,:b263,:b264,:b265,:b\
266,:b267,:b268,:b269,:b270,:b271,:b272,:b273,:b274,:b275,:b276,:b277,:b278,:\
b279,:b280)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2365;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
    sqlstm.sqhstl[1] = (unsigned int  )21;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
    sqlstm.sqhstl[2] = (unsigned int  )13;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_DESC);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MRASTEVDEF_N.SYSTEM_FLAG);
    sqlstm.sqhstl[4] = (unsigned int  )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MRASTEVDEF_N.COLLECT_DEFECT_FLAG);
    sqlstm.sqhstl[5] = (unsigned int  )2;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MRASTEVDEF_N.CLEAN_DEFECT_FLAG);
    sqlstm.sqhstl[6] = (unsigned int  )2;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_1);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_2);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_3);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_4);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_5);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_6);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_7);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_8);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_9);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_10);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_11);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_12);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_13);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_14);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_15);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_16);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_17);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_18);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_19);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_20);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_21);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_22);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_23);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_24);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_25);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_26);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_27);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_28);
    sqlstm.sqhstl[34] = (unsigned int  )31;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_29);
    sqlstm.sqhstl[35] = (unsigned int  )31;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_30);
    sqlstm.sqhstl[36] = (unsigned int  )31;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_1);
    sqlstm.sqhstl[37] = (unsigned int  )2;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_2);
    sqlstm.sqhstl[38] = (unsigned int  )2;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_3);
    sqlstm.sqhstl[39] = (unsigned int  )2;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_4);
    sqlstm.sqhstl[40] = (unsigned int  )2;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_5);
    sqlstm.sqhstl[41] = (unsigned int  )2;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_6);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_7);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_8);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_9);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_10);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_11);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_12);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_13);
    sqlstm.sqhstl[49] = (unsigned int  )2;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_14);
    sqlstm.sqhstl[50] = (unsigned int  )2;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_15);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_16);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_17);
    sqlstm.sqhstl[53] = (unsigned int  )2;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_18);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_19);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_20);
    sqlstm.sqhstl[56] = (unsigned int  )2;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_21);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_22);
    sqlstm.sqhstl[58] = (unsigned int  )2;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_23);
    sqlstm.sqhstl[59] = (unsigned int  )2;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_24);
    sqlstm.sqhstl[60] = (unsigned int  )2;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_25);
    sqlstm.sqhstl[61] = (unsigned int  )2;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_26);
    sqlstm.sqhstl[62] = (unsigned int  )2;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_27);
    sqlstm.sqhstl[63] = (unsigned int  )2;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_28);
    sqlstm.sqhstl[64] = (unsigned int  )2;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_29);
    sqlstm.sqhstl[65] = (unsigned int  )2;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_30);
    sqlstm.sqhstl[66] = (unsigned int  )2;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_1);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_2);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_3);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_4);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_5);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_6);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_7);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_8);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_9);
    sqlstm.sqhstl[75] = (unsigned int  )31;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_10);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_11);
    sqlstm.sqhstl[77] = (unsigned int  )31;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_12);
    sqlstm.sqhstl[78] = (unsigned int  )31;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_13);
    sqlstm.sqhstl[79] = (unsigned int  )31;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_14);
    sqlstm.sqhstl[80] = (unsigned int  )31;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_15);
    sqlstm.sqhstl[81] = (unsigned int  )31;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_16);
    sqlstm.sqhstl[82] = (unsigned int  )31;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_17);
    sqlstm.sqhstl[83] = (unsigned int  )31;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_18);
    sqlstm.sqhstl[84] = (unsigned int  )31;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_19);
    sqlstm.sqhstl[85] = (unsigned int  )31;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_20);
    sqlstm.sqhstl[86] = (unsigned int  )31;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_21);
    sqlstm.sqhstl[87] = (unsigned int  )31;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_22);
    sqlstm.sqhstl[88] = (unsigned int  )31;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_23);
    sqlstm.sqhstl[89] = (unsigned int  )31;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_24);
    sqlstm.sqhstl[90] = (unsigned int  )31;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_25);
    sqlstm.sqhstl[91] = (unsigned int  )31;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_26);
    sqlstm.sqhstl[92] = (unsigned int  )31;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_27);
    sqlstm.sqhstl[93] = (unsigned int  )31;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_28);
    sqlstm.sqhstl[94] = (unsigned int  )31;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_29);
    sqlstm.sqhstl[95] = (unsigned int  )31;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_30);
    sqlstm.sqhstl[96] = (unsigned int  )31;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_1);
    sqlstm.sqhstl[97] = (unsigned int  )31;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_2);
    sqlstm.sqhstl[98] = (unsigned int  )31;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_3);
    sqlstm.sqhstl[99] = (unsigned int  )31;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_4);
    sqlstm.sqhstl[100] = (unsigned int  )31;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_5);
    sqlstm.sqhstl[101] = (unsigned int  )31;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_6);
    sqlstm.sqhstl[102] = (unsigned int  )31;
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_7);
    sqlstm.sqhstl[103] = (unsigned int  )31;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_8);
    sqlstm.sqhstl[104] = (unsigned int  )31;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_9);
    sqlstm.sqhstl[105] = (unsigned int  )31;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_10);
    sqlstm.sqhstl[106] = (unsigned int  )31;
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_11);
    sqlstm.sqhstl[107] = (unsigned int  )31;
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
    sqlstm.sqhstv[108] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_12);
    sqlstm.sqhstl[108] = (unsigned int  )31;
    sqlstm.sqhsts[108] = (         int  )0;
    sqlstm.sqindv[108] = (         void  *)0;
    sqlstm.sqinds[108] = (         int  )0;
    sqlstm.sqharm[108] = (unsigned int  )0;
    sqlstm.sqadto[108] = (unsigned short )0;
    sqlstm.sqtdso[108] = (unsigned short )0;
    sqlstm.sqhstv[109] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_13);
    sqlstm.sqhstl[109] = (unsigned int  )31;
    sqlstm.sqhsts[109] = (         int  )0;
    sqlstm.sqindv[109] = (         void  *)0;
    sqlstm.sqinds[109] = (         int  )0;
    sqlstm.sqharm[109] = (unsigned int  )0;
    sqlstm.sqadto[109] = (unsigned short )0;
    sqlstm.sqtdso[109] = (unsigned short )0;
    sqlstm.sqhstv[110] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_14);
    sqlstm.sqhstl[110] = (unsigned int  )31;
    sqlstm.sqhsts[110] = (         int  )0;
    sqlstm.sqindv[110] = (         void  *)0;
    sqlstm.sqinds[110] = (         int  )0;
    sqlstm.sqharm[110] = (unsigned int  )0;
    sqlstm.sqadto[110] = (unsigned short )0;
    sqlstm.sqtdso[110] = (unsigned short )0;
    sqlstm.sqhstv[111] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_15);
    sqlstm.sqhstl[111] = (unsigned int  )31;
    sqlstm.sqhsts[111] = (         int  )0;
    sqlstm.sqindv[111] = (         void  *)0;
    sqlstm.sqinds[111] = (         int  )0;
    sqlstm.sqharm[111] = (unsigned int  )0;
    sqlstm.sqadto[111] = (unsigned short )0;
    sqlstm.sqtdso[111] = (unsigned short )0;
    sqlstm.sqhstv[112] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_16);
    sqlstm.sqhstl[112] = (unsigned int  )31;
    sqlstm.sqhsts[112] = (         int  )0;
    sqlstm.sqindv[112] = (         void  *)0;
    sqlstm.sqinds[112] = (         int  )0;
    sqlstm.sqharm[112] = (unsigned int  )0;
    sqlstm.sqadto[112] = (unsigned short )0;
    sqlstm.sqtdso[112] = (unsigned short )0;
    sqlstm.sqhstv[113] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_17);
    sqlstm.sqhstl[113] = (unsigned int  )31;
    sqlstm.sqhsts[113] = (         int  )0;
    sqlstm.sqindv[113] = (         void  *)0;
    sqlstm.sqinds[113] = (         int  )0;
    sqlstm.sqharm[113] = (unsigned int  )0;
    sqlstm.sqadto[113] = (unsigned short )0;
    sqlstm.sqtdso[113] = (unsigned short )0;
    sqlstm.sqhstv[114] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_18);
    sqlstm.sqhstl[114] = (unsigned int  )31;
    sqlstm.sqhsts[114] = (         int  )0;
    sqlstm.sqindv[114] = (         void  *)0;
    sqlstm.sqinds[114] = (         int  )0;
    sqlstm.sqharm[114] = (unsigned int  )0;
    sqlstm.sqadto[114] = (unsigned short )0;
    sqlstm.sqtdso[114] = (unsigned short )0;
    sqlstm.sqhstv[115] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_19);
    sqlstm.sqhstl[115] = (unsigned int  )31;
    sqlstm.sqhsts[115] = (         int  )0;
    sqlstm.sqindv[115] = (         void  *)0;
    sqlstm.sqinds[115] = (         int  )0;
    sqlstm.sqharm[115] = (unsigned int  )0;
    sqlstm.sqadto[115] = (unsigned short )0;
    sqlstm.sqtdso[115] = (unsigned short )0;
    sqlstm.sqhstv[116] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_20);
    sqlstm.sqhstl[116] = (unsigned int  )31;
    sqlstm.sqhsts[116] = (         int  )0;
    sqlstm.sqindv[116] = (         void  *)0;
    sqlstm.sqinds[116] = (         int  )0;
    sqlstm.sqharm[116] = (unsigned int  )0;
    sqlstm.sqadto[116] = (unsigned short )0;
    sqlstm.sqtdso[116] = (unsigned short )0;
    sqlstm.sqhstv[117] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_21);
    sqlstm.sqhstl[117] = (unsigned int  )31;
    sqlstm.sqhsts[117] = (         int  )0;
    sqlstm.sqindv[117] = (         void  *)0;
    sqlstm.sqinds[117] = (         int  )0;
    sqlstm.sqharm[117] = (unsigned int  )0;
    sqlstm.sqadto[117] = (unsigned short )0;
    sqlstm.sqtdso[117] = (unsigned short )0;
    sqlstm.sqhstv[118] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_22);
    sqlstm.sqhstl[118] = (unsigned int  )31;
    sqlstm.sqhsts[118] = (         int  )0;
    sqlstm.sqindv[118] = (         void  *)0;
    sqlstm.sqinds[118] = (         int  )0;
    sqlstm.sqharm[118] = (unsigned int  )0;
    sqlstm.sqadto[118] = (unsigned short )0;
    sqlstm.sqtdso[118] = (unsigned short )0;
    sqlstm.sqhstv[119] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_23);
    sqlstm.sqhstl[119] = (unsigned int  )31;
    sqlstm.sqhsts[119] = (         int  )0;
    sqlstm.sqindv[119] = (         void  *)0;
    sqlstm.sqinds[119] = (         int  )0;
    sqlstm.sqharm[119] = (unsigned int  )0;
    sqlstm.sqadto[119] = (unsigned short )0;
    sqlstm.sqtdso[119] = (unsigned short )0;
    sqlstm.sqhstv[120] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_24);
    sqlstm.sqhstl[120] = (unsigned int  )31;
    sqlstm.sqhsts[120] = (         int  )0;
    sqlstm.sqindv[120] = (         void  *)0;
    sqlstm.sqinds[120] = (         int  )0;
    sqlstm.sqharm[120] = (unsigned int  )0;
    sqlstm.sqadto[120] = (unsigned short )0;
    sqlstm.sqtdso[120] = (unsigned short )0;
    sqlstm.sqhstv[121] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_25);
    sqlstm.sqhstl[121] = (unsigned int  )31;
    sqlstm.sqhsts[121] = (         int  )0;
    sqlstm.sqindv[121] = (         void  *)0;
    sqlstm.sqinds[121] = (         int  )0;
    sqlstm.sqharm[121] = (unsigned int  )0;
    sqlstm.sqadto[121] = (unsigned short )0;
    sqlstm.sqtdso[121] = (unsigned short )0;
    sqlstm.sqhstv[122] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_26);
    sqlstm.sqhstl[122] = (unsigned int  )31;
    sqlstm.sqhsts[122] = (         int  )0;
    sqlstm.sqindv[122] = (         void  *)0;
    sqlstm.sqinds[122] = (         int  )0;
    sqlstm.sqharm[122] = (unsigned int  )0;
    sqlstm.sqadto[122] = (unsigned short )0;
    sqlstm.sqtdso[122] = (unsigned short )0;
    sqlstm.sqhstv[123] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_27);
    sqlstm.sqhstl[123] = (unsigned int  )31;
    sqlstm.sqhsts[123] = (         int  )0;
    sqlstm.sqindv[123] = (         void  *)0;
    sqlstm.sqinds[123] = (         int  )0;
    sqlstm.sqharm[123] = (unsigned int  )0;
    sqlstm.sqadto[123] = (unsigned short )0;
    sqlstm.sqtdso[123] = (unsigned short )0;
    sqlstm.sqhstv[124] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_28);
    sqlstm.sqhstl[124] = (unsigned int  )31;
    sqlstm.sqhsts[124] = (         int  )0;
    sqlstm.sqindv[124] = (         void  *)0;
    sqlstm.sqinds[124] = (         int  )0;
    sqlstm.sqharm[124] = (unsigned int  )0;
    sqlstm.sqadto[124] = (unsigned short )0;
    sqlstm.sqtdso[124] = (unsigned short )0;
    sqlstm.sqhstv[125] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_29);
    sqlstm.sqhstl[125] = (unsigned int  )31;
    sqlstm.sqhsts[125] = (         int  )0;
    sqlstm.sqindv[125] = (         void  *)0;
    sqlstm.sqinds[125] = (         int  )0;
    sqlstm.sqharm[125] = (unsigned int  )0;
    sqlstm.sqadto[125] = (unsigned short )0;
    sqlstm.sqtdso[125] = (unsigned short )0;
    sqlstm.sqhstv[126] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_30);
    sqlstm.sqhstl[126] = (unsigned int  )31;
    sqlstm.sqhsts[126] = (         int  )0;
    sqlstm.sqindv[126] = (         void  *)0;
    sqlstm.sqinds[126] = (         int  )0;
    sqlstm.sqharm[126] = (unsigned int  )0;
    sqlstm.sqadto[126] = (unsigned short )0;
    sqlstm.sqtdso[126] = (unsigned short )0;
    sqlstm.sqhstv[127] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_1);
    sqlstm.sqhstl[127] = (unsigned int  )31;
    sqlstm.sqhsts[127] = (         int  )0;
    sqlstm.sqindv[127] = (         void  *)0;
    sqlstm.sqinds[127] = (         int  )0;
    sqlstm.sqharm[127] = (unsigned int  )0;
    sqlstm.sqadto[127] = (unsigned short )0;
    sqlstm.sqtdso[127] = (unsigned short )0;
    sqlstm.sqhstv[128] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_2);
    sqlstm.sqhstl[128] = (unsigned int  )31;
    sqlstm.sqhsts[128] = (         int  )0;
    sqlstm.sqindv[128] = (         void  *)0;
    sqlstm.sqinds[128] = (         int  )0;
    sqlstm.sqharm[128] = (unsigned int  )0;
    sqlstm.sqadto[128] = (unsigned short )0;
    sqlstm.sqtdso[128] = (unsigned short )0;
    sqlstm.sqhstv[129] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_3);
    sqlstm.sqhstl[129] = (unsigned int  )31;
    sqlstm.sqhsts[129] = (         int  )0;
    sqlstm.sqindv[129] = (         void  *)0;
    sqlstm.sqinds[129] = (         int  )0;
    sqlstm.sqharm[129] = (unsigned int  )0;
    sqlstm.sqadto[129] = (unsigned short )0;
    sqlstm.sqtdso[129] = (unsigned short )0;
    sqlstm.sqhstv[130] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_4);
    sqlstm.sqhstl[130] = (unsigned int  )31;
    sqlstm.sqhsts[130] = (         int  )0;
    sqlstm.sqindv[130] = (         void  *)0;
    sqlstm.sqinds[130] = (         int  )0;
    sqlstm.sqharm[130] = (unsigned int  )0;
    sqlstm.sqadto[130] = (unsigned short )0;
    sqlstm.sqtdso[130] = (unsigned short )0;
    sqlstm.sqhstv[131] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_5);
    sqlstm.sqhstl[131] = (unsigned int  )31;
    sqlstm.sqhsts[131] = (         int  )0;
    sqlstm.sqindv[131] = (         void  *)0;
    sqlstm.sqinds[131] = (         int  )0;
    sqlstm.sqharm[131] = (unsigned int  )0;
    sqlstm.sqadto[131] = (unsigned short )0;
    sqlstm.sqtdso[131] = (unsigned short )0;
    sqlstm.sqhstv[132] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_6);
    sqlstm.sqhstl[132] = (unsigned int  )31;
    sqlstm.sqhsts[132] = (         int  )0;
    sqlstm.sqindv[132] = (         void  *)0;
    sqlstm.sqinds[132] = (         int  )0;
    sqlstm.sqharm[132] = (unsigned int  )0;
    sqlstm.sqadto[132] = (unsigned short )0;
    sqlstm.sqtdso[132] = (unsigned short )0;
    sqlstm.sqhstv[133] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_7);
    sqlstm.sqhstl[133] = (unsigned int  )31;
    sqlstm.sqhsts[133] = (         int  )0;
    sqlstm.sqindv[133] = (         void  *)0;
    sqlstm.sqinds[133] = (         int  )0;
    sqlstm.sqharm[133] = (unsigned int  )0;
    sqlstm.sqadto[133] = (unsigned short )0;
    sqlstm.sqtdso[133] = (unsigned short )0;
    sqlstm.sqhstv[134] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_8);
    sqlstm.sqhstl[134] = (unsigned int  )31;
    sqlstm.sqhsts[134] = (         int  )0;
    sqlstm.sqindv[134] = (         void  *)0;
    sqlstm.sqinds[134] = (         int  )0;
    sqlstm.sqharm[134] = (unsigned int  )0;
    sqlstm.sqadto[134] = (unsigned short )0;
    sqlstm.sqtdso[134] = (unsigned short )0;
    sqlstm.sqhstv[135] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_9);
    sqlstm.sqhstl[135] = (unsigned int  )31;
    sqlstm.sqhsts[135] = (         int  )0;
    sqlstm.sqindv[135] = (         void  *)0;
    sqlstm.sqinds[135] = (         int  )0;
    sqlstm.sqharm[135] = (unsigned int  )0;
    sqlstm.sqadto[135] = (unsigned short )0;
    sqlstm.sqtdso[135] = (unsigned short )0;
    sqlstm.sqhstv[136] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_10);
    sqlstm.sqhstl[136] = (unsigned int  )31;
    sqlstm.sqhsts[136] = (         int  )0;
    sqlstm.sqindv[136] = (         void  *)0;
    sqlstm.sqinds[136] = (         int  )0;
    sqlstm.sqharm[136] = (unsigned int  )0;
    sqlstm.sqadto[136] = (unsigned short )0;
    sqlstm.sqtdso[136] = (unsigned short )0;
    sqlstm.sqhstv[137] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_11);
    sqlstm.sqhstl[137] = (unsigned int  )31;
    sqlstm.sqhsts[137] = (         int  )0;
    sqlstm.sqindv[137] = (         void  *)0;
    sqlstm.sqinds[137] = (         int  )0;
    sqlstm.sqharm[137] = (unsigned int  )0;
    sqlstm.sqadto[137] = (unsigned short )0;
    sqlstm.sqtdso[137] = (unsigned short )0;
    sqlstm.sqhstv[138] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_12);
    sqlstm.sqhstl[138] = (unsigned int  )31;
    sqlstm.sqhsts[138] = (         int  )0;
    sqlstm.sqindv[138] = (         void  *)0;
    sqlstm.sqinds[138] = (         int  )0;
    sqlstm.sqharm[138] = (unsigned int  )0;
    sqlstm.sqadto[138] = (unsigned short )0;
    sqlstm.sqtdso[138] = (unsigned short )0;
    sqlstm.sqhstv[139] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_13);
    sqlstm.sqhstl[139] = (unsigned int  )31;
    sqlstm.sqhsts[139] = (         int  )0;
    sqlstm.sqindv[139] = (         void  *)0;
    sqlstm.sqinds[139] = (         int  )0;
    sqlstm.sqharm[139] = (unsigned int  )0;
    sqlstm.sqadto[139] = (unsigned short )0;
    sqlstm.sqtdso[139] = (unsigned short )0;
    sqlstm.sqhstv[140] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_14);
    sqlstm.sqhstl[140] = (unsigned int  )31;
    sqlstm.sqhsts[140] = (         int  )0;
    sqlstm.sqindv[140] = (         void  *)0;
    sqlstm.sqinds[140] = (         int  )0;
    sqlstm.sqharm[140] = (unsigned int  )0;
    sqlstm.sqadto[140] = (unsigned short )0;
    sqlstm.sqtdso[140] = (unsigned short )0;
    sqlstm.sqhstv[141] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_15);
    sqlstm.sqhstl[141] = (unsigned int  )31;
    sqlstm.sqhsts[141] = (         int  )0;
    sqlstm.sqindv[141] = (         void  *)0;
    sqlstm.sqinds[141] = (         int  )0;
    sqlstm.sqharm[141] = (unsigned int  )0;
    sqlstm.sqadto[141] = (unsigned short )0;
    sqlstm.sqtdso[141] = (unsigned short )0;
    sqlstm.sqhstv[142] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_16);
    sqlstm.sqhstl[142] = (unsigned int  )31;
    sqlstm.sqhsts[142] = (         int  )0;
    sqlstm.sqindv[142] = (         void  *)0;
    sqlstm.sqinds[142] = (         int  )0;
    sqlstm.sqharm[142] = (unsigned int  )0;
    sqlstm.sqadto[142] = (unsigned short )0;
    sqlstm.sqtdso[142] = (unsigned short )0;
    sqlstm.sqhstv[143] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_17);
    sqlstm.sqhstl[143] = (unsigned int  )31;
    sqlstm.sqhsts[143] = (         int  )0;
    sqlstm.sqindv[143] = (         void  *)0;
    sqlstm.sqinds[143] = (         int  )0;
    sqlstm.sqharm[143] = (unsigned int  )0;
    sqlstm.sqadto[143] = (unsigned short )0;
    sqlstm.sqtdso[143] = (unsigned short )0;
    sqlstm.sqhstv[144] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_18);
    sqlstm.sqhstl[144] = (unsigned int  )31;
    sqlstm.sqhsts[144] = (         int  )0;
    sqlstm.sqindv[144] = (         void  *)0;
    sqlstm.sqinds[144] = (         int  )0;
    sqlstm.sqharm[144] = (unsigned int  )0;
    sqlstm.sqadto[144] = (unsigned short )0;
    sqlstm.sqtdso[144] = (unsigned short )0;
    sqlstm.sqhstv[145] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_19);
    sqlstm.sqhstl[145] = (unsigned int  )31;
    sqlstm.sqhsts[145] = (         int  )0;
    sqlstm.sqindv[145] = (         void  *)0;
    sqlstm.sqinds[145] = (         int  )0;
    sqlstm.sqharm[145] = (unsigned int  )0;
    sqlstm.sqadto[145] = (unsigned short )0;
    sqlstm.sqtdso[145] = (unsigned short )0;
    sqlstm.sqhstv[146] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_20);
    sqlstm.sqhstl[146] = (unsigned int  )31;
    sqlstm.sqhsts[146] = (         int  )0;
    sqlstm.sqindv[146] = (         void  *)0;
    sqlstm.sqinds[146] = (         int  )0;
    sqlstm.sqharm[146] = (unsigned int  )0;
    sqlstm.sqadto[146] = (unsigned short )0;
    sqlstm.sqtdso[146] = (unsigned short )0;
    sqlstm.sqhstv[147] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_21);
    sqlstm.sqhstl[147] = (unsigned int  )31;
    sqlstm.sqhsts[147] = (         int  )0;
    sqlstm.sqindv[147] = (         void  *)0;
    sqlstm.sqinds[147] = (         int  )0;
    sqlstm.sqharm[147] = (unsigned int  )0;
    sqlstm.sqadto[147] = (unsigned short )0;
    sqlstm.sqtdso[147] = (unsigned short )0;
    sqlstm.sqhstv[148] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_22);
    sqlstm.sqhstl[148] = (unsigned int  )31;
    sqlstm.sqhsts[148] = (         int  )0;
    sqlstm.sqindv[148] = (         void  *)0;
    sqlstm.sqinds[148] = (         int  )0;
    sqlstm.sqharm[148] = (unsigned int  )0;
    sqlstm.sqadto[148] = (unsigned short )0;
    sqlstm.sqtdso[148] = (unsigned short )0;
    sqlstm.sqhstv[149] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_23);
    sqlstm.sqhstl[149] = (unsigned int  )31;
    sqlstm.sqhsts[149] = (         int  )0;
    sqlstm.sqindv[149] = (         void  *)0;
    sqlstm.sqinds[149] = (         int  )0;
    sqlstm.sqharm[149] = (unsigned int  )0;
    sqlstm.sqadto[149] = (unsigned short )0;
    sqlstm.sqtdso[149] = (unsigned short )0;
    sqlstm.sqhstv[150] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_24);
    sqlstm.sqhstl[150] = (unsigned int  )31;
    sqlstm.sqhsts[150] = (         int  )0;
    sqlstm.sqindv[150] = (         void  *)0;
    sqlstm.sqinds[150] = (         int  )0;
    sqlstm.sqharm[150] = (unsigned int  )0;
    sqlstm.sqadto[150] = (unsigned short )0;
    sqlstm.sqtdso[150] = (unsigned short )0;
    sqlstm.sqhstv[151] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_25);
    sqlstm.sqhstl[151] = (unsigned int  )31;
    sqlstm.sqhsts[151] = (         int  )0;
    sqlstm.sqindv[151] = (         void  *)0;
    sqlstm.sqinds[151] = (         int  )0;
    sqlstm.sqharm[151] = (unsigned int  )0;
    sqlstm.sqadto[151] = (unsigned short )0;
    sqlstm.sqtdso[151] = (unsigned short )0;
    sqlstm.sqhstv[152] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_26);
    sqlstm.sqhstl[152] = (unsigned int  )31;
    sqlstm.sqhsts[152] = (         int  )0;
    sqlstm.sqindv[152] = (         void  *)0;
    sqlstm.sqinds[152] = (         int  )0;
    sqlstm.sqharm[152] = (unsigned int  )0;
    sqlstm.sqadto[152] = (unsigned short )0;
    sqlstm.sqtdso[152] = (unsigned short )0;
    sqlstm.sqhstv[153] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_27);
    sqlstm.sqhstl[153] = (unsigned int  )31;
    sqlstm.sqhsts[153] = (         int  )0;
    sqlstm.sqindv[153] = (         void  *)0;
    sqlstm.sqinds[153] = (         int  )0;
    sqlstm.sqharm[153] = (unsigned int  )0;
    sqlstm.sqadto[153] = (unsigned short )0;
    sqlstm.sqtdso[153] = (unsigned short )0;
    sqlstm.sqhstv[154] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_28);
    sqlstm.sqhstl[154] = (unsigned int  )31;
    sqlstm.sqhsts[154] = (         int  )0;
    sqlstm.sqindv[154] = (         void  *)0;
    sqlstm.sqinds[154] = (         int  )0;
    sqlstm.sqharm[154] = (unsigned int  )0;
    sqlstm.sqadto[154] = (unsigned short )0;
    sqlstm.sqtdso[154] = (unsigned short )0;
    sqlstm.sqhstv[155] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_29);
    sqlstm.sqhstl[155] = (unsigned int  )31;
    sqlstm.sqhsts[155] = (         int  )0;
    sqlstm.sqindv[155] = (         void  *)0;
    sqlstm.sqinds[155] = (         int  )0;
    sqlstm.sqharm[155] = (unsigned int  )0;
    sqlstm.sqadto[155] = (unsigned short )0;
    sqlstm.sqtdso[155] = (unsigned short )0;
    sqlstm.sqhstv[156] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_30);
    sqlstm.sqhstl[156] = (unsigned int  )31;
    sqlstm.sqhsts[156] = (         int  )0;
    sqlstm.sqindv[156] = (         void  *)0;
    sqlstm.sqinds[156] = (         int  )0;
    sqlstm.sqharm[156] = (unsigned int  )0;
    sqlstm.sqadto[156] = (unsigned short )0;
    sqlstm.sqtdso[156] = (unsigned short )0;
    sqlstm.sqhstv[157] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_1);
    sqlstm.sqhstl[157] = (unsigned int  )2;
    sqlstm.sqhsts[157] = (         int  )0;
    sqlstm.sqindv[157] = (         void  *)0;
    sqlstm.sqinds[157] = (         int  )0;
    sqlstm.sqharm[157] = (unsigned int  )0;
    sqlstm.sqadto[157] = (unsigned short )0;
    sqlstm.sqtdso[157] = (unsigned short )0;
    sqlstm.sqhstv[158] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_2);
    sqlstm.sqhstl[158] = (unsigned int  )2;
    sqlstm.sqhsts[158] = (         int  )0;
    sqlstm.sqindv[158] = (         void  *)0;
    sqlstm.sqinds[158] = (         int  )0;
    sqlstm.sqharm[158] = (unsigned int  )0;
    sqlstm.sqadto[158] = (unsigned short )0;
    sqlstm.sqtdso[158] = (unsigned short )0;
    sqlstm.sqhstv[159] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_3);
    sqlstm.sqhstl[159] = (unsigned int  )2;
    sqlstm.sqhsts[159] = (         int  )0;
    sqlstm.sqindv[159] = (         void  *)0;
    sqlstm.sqinds[159] = (         int  )0;
    sqlstm.sqharm[159] = (unsigned int  )0;
    sqlstm.sqadto[159] = (unsigned short )0;
    sqlstm.sqtdso[159] = (unsigned short )0;
    sqlstm.sqhstv[160] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_4);
    sqlstm.sqhstl[160] = (unsigned int  )2;
    sqlstm.sqhsts[160] = (         int  )0;
    sqlstm.sqindv[160] = (         void  *)0;
    sqlstm.sqinds[160] = (         int  )0;
    sqlstm.sqharm[160] = (unsigned int  )0;
    sqlstm.sqadto[160] = (unsigned short )0;
    sqlstm.sqtdso[160] = (unsigned short )0;
    sqlstm.sqhstv[161] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_5);
    sqlstm.sqhstl[161] = (unsigned int  )2;
    sqlstm.sqhsts[161] = (         int  )0;
    sqlstm.sqindv[161] = (         void  *)0;
    sqlstm.sqinds[161] = (         int  )0;
    sqlstm.sqharm[161] = (unsigned int  )0;
    sqlstm.sqadto[161] = (unsigned short )0;
    sqlstm.sqtdso[161] = (unsigned short )0;
    sqlstm.sqhstv[162] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_6);
    sqlstm.sqhstl[162] = (unsigned int  )2;
    sqlstm.sqhsts[162] = (         int  )0;
    sqlstm.sqindv[162] = (         void  *)0;
    sqlstm.sqinds[162] = (         int  )0;
    sqlstm.sqharm[162] = (unsigned int  )0;
    sqlstm.sqadto[162] = (unsigned short )0;
    sqlstm.sqtdso[162] = (unsigned short )0;
    sqlstm.sqhstv[163] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_7);
    sqlstm.sqhstl[163] = (unsigned int  )2;
    sqlstm.sqhsts[163] = (         int  )0;
    sqlstm.sqindv[163] = (         void  *)0;
    sqlstm.sqinds[163] = (         int  )0;
    sqlstm.sqharm[163] = (unsigned int  )0;
    sqlstm.sqadto[163] = (unsigned short )0;
    sqlstm.sqtdso[163] = (unsigned short )0;
    sqlstm.sqhstv[164] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_8);
    sqlstm.sqhstl[164] = (unsigned int  )2;
    sqlstm.sqhsts[164] = (         int  )0;
    sqlstm.sqindv[164] = (         void  *)0;
    sqlstm.sqinds[164] = (         int  )0;
    sqlstm.sqharm[164] = (unsigned int  )0;
    sqlstm.sqadto[164] = (unsigned short )0;
    sqlstm.sqtdso[164] = (unsigned short )0;
    sqlstm.sqhstv[165] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_9);
    sqlstm.sqhstl[165] = (unsigned int  )2;
    sqlstm.sqhsts[165] = (         int  )0;
    sqlstm.sqindv[165] = (         void  *)0;
    sqlstm.sqinds[165] = (         int  )0;
    sqlstm.sqharm[165] = (unsigned int  )0;
    sqlstm.sqadto[165] = (unsigned short )0;
    sqlstm.sqtdso[165] = (unsigned short )0;
    sqlstm.sqhstv[166] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_10);
    sqlstm.sqhstl[166] = (unsigned int  )2;
    sqlstm.sqhsts[166] = (         int  )0;
    sqlstm.sqindv[166] = (         void  *)0;
    sqlstm.sqinds[166] = (         int  )0;
    sqlstm.sqharm[166] = (unsigned int  )0;
    sqlstm.sqadto[166] = (unsigned short )0;
    sqlstm.sqtdso[166] = (unsigned short )0;
    sqlstm.sqhstv[167] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_11);
    sqlstm.sqhstl[167] = (unsigned int  )2;
    sqlstm.sqhsts[167] = (         int  )0;
    sqlstm.sqindv[167] = (         void  *)0;
    sqlstm.sqinds[167] = (         int  )0;
    sqlstm.sqharm[167] = (unsigned int  )0;
    sqlstm.sqadto[167] = (unsigned short )0;
    sqlstm.sqtdso[167] = (unsigned short )0;
    sqlstm.sqhstv[168] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_12);
    sqlstm.sqhstl[168] = (unsigned int  )2;
    sqlstm.sqhsts[168] = (         int  )0;
    sqlstm.sqindv[168] = (         void  *)0;
    sqlstm.sqinds[168] = (         int  )0;
    sqlstm.sqharm[168] = (unsigned int  )0;
    sqlstm.sqadto[168] = (unsigned short )0;
    sqlstm.sqtdso[168] = (unsigned short )0;
    sqlstm.sqhstv[169] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_13);
    sqlstm.sqhstl[169] = (unsigned int  )2;
    sqlstm.sqhsts[169] = (         int  )0;
    sqlstm.sqindv[169] = (         void  *)0;
    sqlstm.sqinds[169] = (         int  )0;
    sqlstm.sqharm[169] = (unsigned int  )0;
    sqlstm.sqadto[169] = (unsigned short )0;
    sqlstm.sqtdso[169] = (unsigned short )0;
    sqlstm.sqhstv[170] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_14);
    sqlstm.sqhstl[170] = (unsigned int  )2;
    sqlstm.sqhsts[170] = (         int  )0;
    sqlstm.sqindv[170] = (         void  *)0;
    sqlstm.sqinds[170] = (         int  )0;
    sqlstm.sqharm[170] = (unsigned int  )0;
    sqlstm.sqadto[170] = (unsigned short )0;
    sqlstm.sqtdso[170] = (unsigned short )0;
    sqlstm.sqhstv[171] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_15);
    sqlstm.sqhstl[171] = (unsigned int  )2;
    sqlstm.sqhsts[171] = (         int  )0;
    sqlstm.sqindv[171] = (         void  *)0;
    sqlstm.sqinds[171] = (         int  )0;
    sqlstm.sqharm[171] = (unsigned int  )0;
    sqlstm.sqadto[171] = (unsigned short )0;
    sqlstm.sqtdso[171] = (unsigned short )0;
    sqlstm.sqhstv[172] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_16);
    sqlstm.sqhstl[172] = (unsigned int  )2;
    sqlstm.sqhsts[172] = (         int  )0;
    sqlstm.sqindv[172] = (         void  *)0;
    sqlstm.sqinds[172] = (         int  )0;
    sqlstm.sqharm[172] = (unsigned int  )0;
    sqlstm.sqadto[172] = (unsigned short )0;
    sqlstm.sqtdso[172] = (unsigned short )0;
    sqlstm.sqhstv[173] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_17);
    sqlstm.sqhstl[173] = (unsigned int  )2;
    sqlstm.sqhsts[173] = (         int  )0;
    sqlstm.sqindv[173] = (         void  *)0;
    sqlstm.sqinds[173] = (         int  )0;
    sqlstm.sqharm[173] = (unsigned int  )0;
    sqlstm.sqadto[173] = (unsigned short )0;
    sqlstm.sqtdso[173] = (unsigned short )0;
    sqlstm.sqhstv[174] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_18);
    sqlstm.sqhstl[174] = (unsigned int  )2;
    sqlstm.sqhsts[174] = (         int  )0;
    sqlstm.sqindv[174] = (         void  *)0;
    sqlstm.sqinds[174] = (         int  )0;
    sqlstm.sqharm[174] = (unsigned int  )0;
    sqlstm.sqadto[174] = (unsigned short )0;
    sqlstm.sqtdso[174] = (unsigned short )0;
    sqlstm.sqhstv[175] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_19);
    sqlstm.sqhstl[175] = (unsigned int  )2;
    sqlstm.sqhsts[175] = (         int  )0;
    sqlstm.sqindv[175] = (         void  *)0;
    sqlstm.sqinds[175] = (         int  )0;
    sqlstm.sqharm[175] = (unsigned int  )0;
    sqlstm.sqadto[175] = (unsigned short )0;
    sqlstm.sqtdso[175] = (unsigned short )0;
    sqlstm.sqhstv[176] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_20);
    sqlstm.sqhstl[176] = (unsigned int  )2;
    sqlstm.sqhsts[176] = (         int  )0;
    sqlstm.sqindv[176] = (         void  *)0;
    sqlstm.sqinds[176] = (         int  )0;
    sqlstm.sqharm[176] = (unsigned int  )0;
    sqlstm.sqadto[176] = (unsigned short )0;
    sqlstm.sqtdso[176] = (unsigned short )0;
    sqlstm.sqhstv[177] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_21);
    sqlstm.sqhstl[177] = (unsigned int  )2;
    sqlstm.sqhsts[177] = (         int  )0;
    sqlstm.sqindv[177] = (         void  *)0;
    sqlstm.sqinds[177] = (         int  )0;
    sqlstm.sqharm[177] = (unsigned int  )0;
    sqlstm.sqadto[177] = (unsigned short )0;
    sqlstm.sqtdso[177] = (unsigned short )0;
    sqlstm.sqhstv[178] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_22);
    sqlstm.sqhstl[178] = (unsigned int  )2;
    sqlstm.sqhsts[178] = (         int  )0;
    sqlstm.sqindv[178] = (         void  *)0;
    sqlstm.sqinds[178] = (         int  )0;
    sqlstm.sqharm[178] = (unsigned int  )0;
    sqlstm.sqadto[178] = (unsigned short )0;
    sqlstm.sqtdso[178] = (unsigned short )0;
    sqlstm.sqhstv[179] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_23);
    sqlstm.sqhstl[179] = (unsigned int  )2;
    sqlstm.sqhsts[179] = (         int  )0;
    sqlstm.sqindv[179] = (         void  *)0;
    sqlstm.sqinds[179] = (         int  )0;
    sqlstm.sqharm[179] = (unsigned int  )0;
    sqlstm.sqadto[179] = (unsigned short )0;
    sqlstm.sqtdso[179] = (unsigned short )0;
    sqlstm.sqhstv[180] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_24);
    sqlstm.sqhstl[180] = (unsigned int  )2;
    sqlstm.sqhsts[180] = (         int  )0;
    sqlstm.sqindv[180] = (         void  *)0;
    sqlstm.sqinds[180] = (         int  )0;
    sqlstm.sqharm[180] = (unsigned int  )0;
    sqlstm.sqadto[180] = (unsigned short )0;
    sqlstm.sqtdso[180] = (unsigned short )0;
    sqlstm.sqhstv[181] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_25);
    sqlstm.sqhstl[181] = (unsigned int  )2;
    sqlstm.sqhsts[181] = (         int  )0;
    sqlstm.sqindv[181] = (         void  *)0;
    sqlstm.sqinds[181] = (         int  )0;
    sqlstm.sqharm[181] = (unsigned int  )0;
    sqlstm.sqadto[181] = (unsigned short )0;
    sqlstm.sqtdso[181] = (unsigned short )0;
    sqlstm.sqhstv[182] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_26);
    sqlstm.sqhstl[182] = (unsigned int  )2;
    sqlstm.sqhsts[182] = (         int  )0;
    sqlstm.sqindv[182] = (         void  *)0;
    sqlstm.sqinds[182] = (         int  )0;
    sqlstm.sqharm[182] = (unsigned int  )0;
    sqlstm.sqadto[182] = (unsigned short )0;
    sqlstm.sqtdso[182] = (unsigned short )0;
    sqlstm.sqhstv[183] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_27);
    sqlstm.sqhstl[183] = (unsigned int  )2;
    sqlstm.sqhsts[183] = (         int  )0;
    sqlstm.sqindv[183] = (         void  *)0;
    sqlstm.sqinds[183] = (         int  )0;
    sqlstm.sqharm[183] = (unsigned int  )0;
    sqlstm.sqadto[183] = (unsigned short )0;
    sqlstm.sqtdso[183] = (unsigned short )0;
    sqlstm.sqhstv[184] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_28);
    sqlstm.sqhstl[184] = (unsigned int  )2;
    sqlstm.sqhsts[184] = (         int  )0;
    sqlstm.sqindv[184] = (         void  *)0;
    sqlstm.sqinds[184] = (         int  )0;
    sqlstm.sqharm[184] = (unsigned int  )0;
    sqlstm.sqadto[184] = (unsigned short )0;
    sqlstm.sqtdso[184] = (unsigned short )0;
    sqlstm.sqhstv[185] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_29);
    sqlstm.sqhstl[185] = (unsigned int  )2;
    sqlstm.sqhsts[185] = (         int  )0;
    sqlstm.sqindv[185] = (         void  *)0;
    sqlstm.sqinds[185] = (         int  )0;
    sqlstm.sqharm[185] = (unsigned int  )0;
    sqlstm.sqadto[185] = (unsigned short )0;
    sqlstm.sqtdso[185] = (unsigned short )0;
    sqlstm.sqhstv[186] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_30);
    sqlstm.sqhstl[186] = (unsigned int  )2;
    sqlstm.sqhsts[186] = (         int  )0;
    sqlstm.sqindv[186] = (         void  *)0;
    sqlstm.sqinds[186] = (         int  )0;
    sqlstm.sqharm[186] = (unsigned int  )0;
    sqlstm.sqadto[186] = (unsigned short )0;
    sqlstm.sqtdso[186] = (unsigned short )0;
    sqlstm.sqhstv[187] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_1);
    sqlstm.sqhstl[187] = (unsigned int  )31;
    sqlstm.sqhsts[187] = (         int  )0;
    sqlstm.sqindv[187] = (         void  *)0;
    sqlstm.sqinds[187] = (         int  )0;
    sqlstm.sqharm[187] = (unsigned int  )0;
    sqlstm.sqadto[187] = (unsigned short )0;
    sqlstm.sqtdso[187] = (unsigned short )0;
    sqlstm.sqhstv[188] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_2);
    sqlstm.sqhstl[188] = (unsigned int  )31;
    sqlstm.sqhsts[188] = (         int  )0;
    sqlstm.sqindv[188] = (         void  *)0;
    sqlstm.sqinds[188] = (         int  )0;
    sqlstm.sqharm[188] = (unsigned int  )0;
    sqlstm.sqadto[188] = (unsigned short )0;
    sqlstm.sqtdso[188] = (unsigned short )0;
    sqlstm.sqhstv[189] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_3);
    sqlstm.sqhstl[189] = (unsigned int  )31;
    sqlstm.sqhsts[189] = (         int  )0;
    sqlstm.sqindv[189] = (         void  *)0;
    sqlstm.sqinds[189] = (         int  )0;
    sqlstm.sqharm[189] = (unsigned int  )0;
    sqlstm.sqadto[189] = (unsigned short )0;
    sqlstm.sqtdso[189] = (unsigned short )0;
    sqlstm.sqhstv[190] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_4);
    sqlstm.sqhstl[190] = (unsigned int  )31;
    sqlstm.sqhsts[190] = (         int  )0;
    sqlstm.sqindv[190] = (         void  *)0;
    sqlstm.sqinds[190] = (         int  )0;
    sqlstm.sqharm[190] = (unsigned int  )0;
    sqlstm.sqadto[190] = (unsigned short )0;
    sqlstm.sqtdso[190] = (unsigned short )0;
    sqlstm.sqhstv[191] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_5);
    sqlstm.sqhstl[191] = (unsigned int  )31;
    sqlstm.sqhsts[191] = (         int  )0;
    sqlstm.sqindv[191] = (         void  *)0;
    sqlstm.sqinds[191] = (         int  )0;
    sqlstm.sqharm[191] = (unsigned int  )0;
    sqlstm.sqadto[191] = (unsigned short )0;
    sqlstm.sqtdso[191] = (unsigned short )0;
    sqlstm.sqhstv[192] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_6);
    sqlstm.sqhstl[192] = (unsigned int  )31;
    sqlstm.sqhsts[192] = (         int  )0;
    sqlstm.sqindv[192] = (         void  *)0;
    sqlstm.sqinds[192] = (         int  )0;
    sqlstm.sqharm[192] = (unsigned int  )0;
    sqlstm.sqadto[192] = (unsigned short )0;
    sqlstm.sqtdso[192] = (unsigned short )0;
    sqlstm.sqhstv[193] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_7);
    sqlstm.sqhstl[193] = (unsigned int  )31;
    sqlstm.sqhsts[193] = (         int  )0;
    sqlstm.sqindv[193] = (         void  *)0;
    sqlstm.sqinds[193] = (         int  )0;
    sqlstm.sqharm[193] = (unsigned int  )0;
    sqlstm.sqadto[193] = (unsigned short )0;
    sqlstm.sqtdso[193] = (unsigned short )0;
    sqlstm.sqhstv[194] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_8);
    sqlstm.sqhstl[194] = (unsigned int  )31;
    sqlstm.sqhsts[194] = (         int  )0;
    sqlstm.sqindv[194] = (         void  *)0;
    sqlstm.sqinds[194] = (         int  )0;
    sqlstm.sqharm[194] = (unsigned int  )0;
    sqlstm.sqadto[194] = (unsigned short )0;
    sqlstm.sqtdso[194] = (unsigned short )0;
    sqlstm.sqhstv[195] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_9);
    sqlstm.sqhstl[195] = (unsigned int  )31;
    sqlstm.sqhsts[195] = (         int  )0;
    sqlstm.sqindv[195] = (         void  *)0;
    sqlstm.sqinds[195] = (         int  )0;
    sqlstm.sqharm[195] = (unsigned int  )0;
    sqlstm.sqadto[195] = (unsigned short )0;
    sqlstm.sqtdso[195] = (unsigned short )0;
    sqlstm.sqhstv[196] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_10);
    sqlstm.sqhstl[196] = (unsigned int  )31;
    sqlstm.sqhsts[196] = (         int  )0;
    sqlstm.sqindv[196] = (         void  *)0;
    sqlstm.sqinds[196] = (         int  )0;
    sqlstm.sqharm[196] = (unsigned int  )0;
    sqlstm.sqadto[196] = (unsigned short )0;
    sqlstm.sqtdso[196] = (unsigned short )0;
    sqlstm.sqhstv[197] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_11);
    sqlstm.sqhstl[197] = (unsigned int  )31;
    sqlstm.sqhsts[197] = (         int  )0;
    sqlstm.sqindv[197] = (         void  *)0;
    sqlstm.sqinds[197] = (         int  )0;
    sqlstm.sqharm[197] = (unsigned int  )0;
    sqlstm.sqadto[197] = (unsigned short )0;
    sqlstm.sqtdso[197] = (unsigned short )0;
    sqlstm.sqhstv[198] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_12);
    sqlstm.sqhstl[198] = (unsigned int  )31;
    sqlstm.sqhsts[198] = (         int  )0;
    sqlstm.sqindv[198] = (         void  *)0;
    sqlstm.sqinds[198] = (         int  )0;
    sqlstm.sqharm[198] = (unsigned int  )0;
    sqlstm.sqadto[198] = (unsigned short )0;
    sqlstm.sqtdso[198] = (unsigned short )0;
    sqlstm.sqhstv[199] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_13);
    sqlstm.sqhstl[199] = (unsigned int  )31;
    sqlstm.sqhsts[199] = (         int  )0;
    sqlstm.sqindv[199] = (         void  *)0;
    sqlstm.sqinds[199] = (         int  )0;
    sqlstm.sqharm[199] = (unsigned int  )0;
    sqlstm.sqadto[199] = (unsigned short )0;
    sqlstm.sqtdso[199] = (unsigned short )0;
    sqlstm.sqhstv[200] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_14);
    sqlstm.sqhstl[200] = (unsigned int  )31;
    sqlstm.sqhsts[200] = (         int  )0;
    sqlstm.sqindv[200] = (         void  *)0;
    sqlstm.sqinds[200] = (         int  )0;
    sqlstm.sqharm[200] = (unsigned int  )0;
    sqlstm.sqadto[200] = (unsigned short )0;
    sqlstm.sqtdso[200] = (unsigned short )0;
    sqlstm.sqhstv[201] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_15);
    sqlstm.sqhstl[201] = (unsigned int  )31;
    sqlstm.sqhsts[201] = (         int  )0;
    sqlstm.sqindv[201] = (         void  *)0;
    sqlstm.sqinds[201] = (         int  )0;
    sqlstm.sqharm[201] = (unsigned int  )0;
    sqlstm.sqadto[201] = (unsigned short )0;
    sqlstm.sqtdso[201] = (unsigned short )0;
    sqlstm.sqhstv[202] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_16);
    sqlstm.sqhstl[202] = (unsigned int  )31;
    sqlstm.sqhsts[202] = (         int  )0;
    sqlstm.sqindv[202] = (         void  *)0;
    sqlstm.sqinds[202] = (         int  )0;
    sqlstm.sqharm[202] = (unsigned int  )0;
    sqlstm.sqadto[202] = (unsigned short )0;
    sqlstm.sqtdso[202] = (unsigned short )0;
    sqlstm.sqhstv[203] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_17);
    sqlstm.sqhstl[203] = (unsigned int  )31;
    sqlstm.sqhsts[203] = (         int  )0;
    sqlstm.sqindv[203] = (         void  *)0;
    sqlstm.sqinds[203] = (         int  )0;
    sqlstm.sqharm[203] = (unsigned int  )0;
    sqlstm.sqadto[203] = (unsigned short )0;
    sqlstm.sqtdso[203] = (unsigned short )0;
    sqlstm.sqhstv[204] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_18);
    sqlstm.sqhstl[204] = (unsigned int  )31;
    sqlstm.sqhsts[204] = (         int  )0;
    sqlstm.sqindv[204] = (         void  *)0;
    sqlstm.sqinds[204] = (         int  )0;
    sqlstm.sqharm[204] = (unsigned int  )0;
    sqlstm.sqadto[204] = (unsigned short )0;
    sqlstm.sqtdso[204] = (unsigned short )0;
    sqlstm.sqhstv[205] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_19);
    sqlstm.sqhstl[205] = (unsigned int  )31;
    sqlstm.sqhsts[205] = (         int  )0;
    sqlstm.sqindv[205] = (         void  *)0;
    sqlstm.sqinds[205] = (         int  )0;
    sqlstm.sqharm[205] = (unsigned int  )0;
    sqlstm.sqadto[205] = (unsigned short )0;
    sqlstm.sqtdso[205] = (unsigned short )0;
    sqlstm.sqhstv[206] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_20);
    sqlstm.sqhstl[206] = (unsigned int  )31;
    sqlstm.sqhsts[206] = (         int  )0;
    sqlstm.sqindv[206] = (         void  *)0;
    sqlstm.sqinds[206] = (         int  )0;
    sqlstm.sqharm[206] = (unsigned int  )0;
    sqlstm.sqadto[206] = (unsigned short )0;
    sqlstm.sqtdso[206] = (unsigned short )0;
    sqlstm.sqhstv[207] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_21);
    sqlstm.sqhstl[207] = (unsigned int  )31;
    sqlstm.sqhsts[207] = (         int  )0;
    sqlstm.sqindv[207] = (         void  *)0;
    sqlstm.sqinds[207] = (         int  )0;
    sqlstm.sqharm[207] = (unsigned int  )0;
    sqlstm.sqadto[207] = (unsigned short )0;
    sqlstm.sqtdso[207] = (unsigned short )0;
    sqlstm.sqhstv[208] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_22);
    sqlstm.sqhstl[208] = (unsigned int  )31;
    sqlstm.sqhsts[208] = (         int  )0;
    sqlstm.sqindv[208] = (         void  *)0;
    sqlstm.sqinds[208] = (         int  )0;
    sqlstm.sqharm[208] = (unsigned int  )0;
    sqlstm.sqadto[208] = (unsigned short )0;
    sqlstm.sqtdso[208] = (unsigned short )0;
    sqlstm.sqhstv[209] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_23);
    sqlstm.sqhstl[209] = (unsigned int  )31;
    sqlstm.sqhsts[209] = (         int  )0;
    sqlstm.sqindv[209] = (         void  *)0;
    sqlstm.sqinds[209] = (         int  )0;
    sqlstm.sqharm[209] = (unsigned int  )0;
    sqlstm.sqadto[209] = (unsigned short )0;
    sqlstm.sqtdso[209] = (unsigned short )0;
    sqlstm.sqhstv[210] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_24);
    sqlstm.sqhstl[210] = (unsigned int  )31;
    sqlstm.sqhsts[210] = (         int  )0;
    sqlstm.sqindv[210] = (         void  *)0;
    sqlstm.sqinds[210] = (         int  )0;
    sqlstm.sqharm[210] = (unsigned int  )0;
    sqlstm.sqadto[210] = (unsigned short )0;
    sqlstm.sqtdso[210] = (unsigned short )0;
    sqlstm.sqhstv[211] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_25);
    sqlstm.sqhstl[211] = (unsigned int  )31;
    sqlstm.sqhsts[211] = (         int  )0;
    sqlstm.sqindv[211] = (         void  *)0;
    sqlstm.sqinds[211] = (         int  )0;
    sqlstm.sqharm[211] = (unsigned int  )0;
    sqlstm.sqadto[211] = (unsigned short )0;
    sqlstm.sqtdso[211] = (unsigned short )0;
    sqlstm.sqhstv[212] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_26);
    sqlstm.sqhstl[212] = (unsigned int  )31;
    sqlstm.sqhsts[212] = (         int  )0;
    sqlstm.sqindv[212] = (         void  *)0;
    sqlstm.sqinds[212] = (         int  )0;
    sqlstm.sqharm[212] = (unsigned int  )0;
    sqlstm.sqadto[212] = (unsigned short )0;
    sqlstm.sqtdso[212] = (unsigned short )0;
    sqlstm.sqhstv[213] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_27);
    sqlstm.sqhstl[213] = (unsigned int  )31;
    sqlstm.sqhsts[213] = (         int  )0;
    sqlstm.sqindv[213] = (         void  *)0;
    sqlstm.sqinds[213] = (         int  )0;
    sqlstm.sqharm[213] = (unsigned int  )0;
    sqlstm.sqadto[213] = (unsigned short )0;
    sqlstm.sqtdso[213] = (unsigned short )0;
    sqlstm.sqhstv[214] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_28);
    sqlstm.sqhstl[214] = (unsigned int  )31;
    sqlstm.sqhsts[214] = (         int  )0;
    sqlstm.sqindv[214] = (         void  *)0;
    sqlstm.sqinds[214] = (         int  )0;
    sqlstm.sqharm[214] = (unsigned int  )0;
    sqlstm.sqadto[214] = (unsigned short )0;
    sqlstm.sqtdso[214] = (unsigned short )0;
    sqlstm.sqhstv[215] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_29);
    sqlstm.sqhstl[215] = (unsigned int  )31;
    sqlstm.sqhsts[215] = (         int  )0;
    sqlstm.sqindv[215] = (         void  *)0;
    sqlstm.sqinds[215] = (         int  )0;
    sqlstm.sqharm[215] = (unsigned int  )0;
    sqlstm.sqadto[215] = (unsigned short )0;
    sqlstm.sqtdso[215] = (unsigned short )0;
    sqlstm.sqhstv[216] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_30);
    sqlstm.sqhstl[216] = (unsigned int  )31;
    sqlstm.sqhsts[216] = (         int  )0;
    sqlstm.sqindv[216] = (         void  *)0;
    sqlstm.sqinds[216] = (         int  )0;
    sqlstm.sqharm[216] = (unsigned int  )0;
    sqlstm.sqadto[216] = (unsigned short )0;
    sqlstm.sqtdso[216] = (unsigned short )0;
    sqlstm.sqhstv[217] = (         void  *)(MRASTEVDEF_N.CHG_OPT_1);
    sqlstm.sqhstl[217] = (unsigned int  )2;
    sqlstm.sqhsts[217] = (         int  )0;
    sqlstm.sqindv[217] = (         void  *)0;
    sqlstm.sqinds[217] = (         int  )0;
    sqlstm.sqharm[217] = (unsigned int  )0;
    sqlstm.sqadto[217] = (unsigned short )0;
    sqlstm.sqtdso[217] = (unsigned short )0;
    sqlstm.sqhstv[218] = (         void  *)(MRASTEVDEF_N.CHG_OPT_2);
    sqlstm.sqhstl[218] = (unsigned int  )2;
    sqlstm.sqhsts[218] = (         int  )0;
    sqlstm.sqindv[218] = (         void  *)0;
    sqlstm.sqinds[218] = (         int  )0;
    sqlstm.sqharm[218] = (unsigned int  )0;
    sqlstm.sqadto[218] = (unsigned short )0;
    sqlstm.sqtdso[218] = (unsigned short )0;
    sqlstm.sqhstv[219] = (         void  *)(MRASTEVDEF_N.CHG_OPT_3);
    sqlstm.sqhstl[219] = (unsigned int  )2;
    sqlstm.sqhsts[219] = (         int  )0;
    sqlstm.sqindv[219] = (         void  *)0;
    sqlstm.sqinds[219] = (         int  )0;
    sqlstm.sqharm[219] = (unsigned int  )0;
    sqlstm.sqadto[219] = (unsigned short )0;
    sqlstm.sqtdso[219] = (unsigned short )0;
    sqlstm.sqhstv[220] = (         void  *)(MRASTEVDEF_N.CHG_OPT_4);
    sqlstm.sqhstl[220] = (unsigned int  )2;
    sqlstm.sqhsts[220] = (         int  )0;
    sqlstm.sqindv[220] = (         void  *)0;
    sqlstm.sqinds[220] = (         int  )0;
    sqlstm.sqharm[220] = (unsigned int  )0;
    sqlstm.sqadto[220] = (unsigned short )0;
    sqlstm.sqtdso[220] = (unsigned short )0;
    sqlstm.sqhstv[221] = (         void  *)(MRASTEVDEF_N.CHG_OPT_5);
    sqlstm.sqhstl[221] = (unsigned int  )2;
    sqlstm.sqhsts[221] = (         int  )0;
    sqlstm.sqindv[221] = (         void  *)0;
    sqlstm.sqinds[221] = (         int  )0;
    sqlstm.sqharm[221] = (unsigned int  )0;
    sqlstm.sqadto[221] = (unsigned short )0;
    sqlstm.sqtdso[221] = (unsigned short )0;
    sqlstm.sqhstv[222] = (         void  *)(MRASTEVDEF_N.CHG_OPT_6);
    sqlstm.sqhstl[222] = (unsigned int  )2;
    sqlstm.sqhsts[222] = (         int  )0;
    sqlstm.sqindv[222] = (         void  *)0;
    sqlstm.sqinds[222] = (         int  )0;
    sqlstm.sqharm[222] = (unsigned int  )0;
    sqlstm.sqadto[222] = (unsigned short )0;
    sqlstm.sqtdso[222] = (unsigned short )0;
    sqlstm.sqhstv[223] = (         void  *)(MRASTEVDEF_N.CHG_OPT_7);
    sqlstm.sqhstl[223] = (unsigned int  )2;
    sqlstm.sqhsts[223] = (         int  )0;
    sqlstm.sqindv[223] = (         void  *)0;
    sqlstm.sqinds[223] = (         int  )0;
    sqlstm.sqharm[223] = (unsigned int  )0;
    sqlstm.sqadto[223] = (unsigned short )0;
    sqlstm.sqtdso[223] = (unsigned short )0;
    sqlstm.sqhstv[224] = (         void  *)(MRASTEVDEF_N.CHG_OPT_8);
    sqlstm.sqhstl[224] = (unsigned int  )2;
    sqlstm.sqhsts[224] = (         int  )0;
    sqlstm.sqindv[224] = (         void  *)0;
    sqlstm.sqinds[224] = (         int  )0;
    sqlstm.sqharm[224] = (unsigned int  )0;
    sqlstm.sqadto[224] = (unsigned short )0;
    sqlstm.sqtdso[224] = (unsigned short )0;
    sqlstm.sqhstv[225] = (         void  *)(MRASTEVDEF_N.CHG_OPT_9);
    sqlstm.sqhstl[225] = (unsigned int  )2;
    sqlstm.sqhsts[225] = (         int  )0;
    sqlstm.sqindv[225] = (         void  *)0;
    sqlstm.sqinds[225] = (         int  )0;
    sqlstm.sqharm[225] = (unsigned int  )0;
    sqlstm.sqadto[225] = (unsigned short )0;
    sqlstm.sqtdso[225] = (unsigned short )0;
    sqlstm.sqhstv[226] = (         void  *)(MRASTEVDEF_N.CHG_OPT_10);
    sqlstm.sqhstl[226] = (unsigned int  )2;
    sqlstm.sqhsts[226] = (         int  )0;
    sqlstm.sqindv[226] = (         void  *)0;
    sqlstm.sqinds[226] = (         int  )0;
    sqlstm.sqharm[226] = (unsigned int  )0;
    sqlstm.sqadto[226] = (unsigned short )0;
    sqlstm.sqtdso[226] = (unsigned short )0;
    sqlstm.sqhstv[227] = (         void  *)(MRASTEVDEF_N.CHG_OPT_11);
    sqlstm.sqhstl[227] = (unsigned int  )2;
    sqlstm.sqhsts[227] = (         int  )0;
    sqlstm.sqindv[227] = (         void  *)0;
    sqlstm.sqinds[227] = (         int  )0;
    sqlstm.sqharm[227] = (unsigned int  )0;
    sqlstm.sqadto[227] = (unsigned short )0;
    sqlstm.sqtdso[227] = (unsigned short )0;
    sqlstm.sqhstv[228] = (         void  *)(MRASTEVDEF_N.CHG_OPT_12);
    sqlstm.sqhstl[228] = (unsigned int  )2;
    sqlstm.sqhsts[228] = (         int  )0;
    sqlstm.sqindv[228] = (         void  *)0;
    sqlstm.sqinds[228] = (         int  )0;
    sqlstm.sqharm[228] = (unsigned int  )0;
    sqlstm.sqadto[228] = (unsigned short )0;
    sqlstm.sqtdso[228] = (unsigned short )0;
    sqlstm.sqhstv[229] = (         void  *)(MRASTEVDEF_N.CHG_OPT_13);
    sqlstm.sqhstl[229] = (unsigned int  )2;
    sqlstm.sqhsts[229] = (         int  )0;
    sqlstm.sqindv[229] = (         void  *)0;
    sqlstm.sqinds[229] = (         int  )0;
    sqlstm.sqharm[229] = (unsigned int  )0;
    sqlstm.sqadto[229] = (unsigned short )0;
    sqlstm.sqtdso[229] = (unsigned short )0;
    sqlstm.sqhstv[230] = (         void  *)(MRASTEVDEF_N.CHG_OPT_14);
    sqlstm.sqhstl[230] = (unsigned int  )2;
    sqlstm.sqhsts[230] = (         int  )0;
    sqlstm.sqindv[230] = (         void  *)0;
    sqlstm.sqinds[230] = (         int  )0;
    sqlstm.sqharm[230] = (unsigned int  )0;
    sqlstm.sqadto[230] = (unsigned short )0;
    sqlstm.sqtdso[230] = (unsigned short )0;
    sqlstm.sqhstv[231] = (         void  *)(MRASTEVDEF_N.CHG_OPT_15);
    sqlstm.sqhstl[231] = (unsigned int  )2;
    sqlstm.sqhsts[231] = (         int  )0;
    sqlstm.sqindv[231] = (         void  *)0;
    sqlstm.sqinds[231] = (         int  )0;
    sqlstm.sqharm[231] = (unsigned int  )0;
    sqlstm.sqadto[231] = (unsigned short )0;
    sqlstm.sqtdso[231] = (unsigned short )0;
    sqlstm.sqhstv[232] = (         void  *)(MRASTEVDEF_N.CHG_OPT_16);
    sqlstm.sqhstl[232] = (unsigned int  )2;
    sqlstm.sqhsts[232] = (         int  )0;
    sqlstm.sqindv[232] = (         void  *)0;
    sqlstm.sqinds[232] = (         int  )0;
    sqlstm.sqharm[232] = (unsigned int  )0;
    sqlstm.sqadto[232] = (unsigned short )0;
    sqlstm.sqtdso[232] = (unsigned short )0;
    sqlstm.sqhstv[233] = (         void  *)(MRASTEVDEF_N.CHG_OPT_17);
    sqlstm.sqhstl[233] = (unsigned int  )2;
    sqlstm.sqhsts[233] = (         int  )0;
    sqlstm.sqindv[233] = (         void  *)0;
    sqlstm.sqinds[233] = (         int  )0;
    sqlstm.sqharm[233] = (unsigned int  )0;
    sqlstm.sqadto[233] = (unsigned short )0;
    sqlstm.sqtdso[233] = (unsigned short )0;
    sqlstm.sqhstv[234] = (         void  *)(MRASTEVDEF_N.CHG_OPT_18);
    sqlstm.sqhstl[234] = (unsigned int  )2;
    sqlstm.sqhsts[234] = (         int  )0;
    sqlstm.sqindv[234] = (         void  *)0;
    sqlstm.sqinds[234] = (         int  )0;
    sqlstm.sqharm[234] = (unsigned int  )0;
    sqlstm.sqadto[234] = (unsigned short )0;
    sqlstm.sqtdso[234] = (unsigned short )0;
    sqlstm.sqhstv[235] = (         void  *)(MRASTEVDEF_N.CHG_OPT_19);
    sqlstm.sqhstl[235] = (unsigned int  )2;
    sqlstm.sqhsts[235] = (         int  )0;
    sqlstm.sqindv[235] = (         void  *)0;
    sqlstm.sqinds[235] = (         int  )0;
    sqlstm.sqharm[235] = (unsigned int  )0;
    sqlstm.sqadto[235] = (unsigned short )0;
    sqlstm.sqtdso[235] = (unsigned short )0;
    sqlstm.sqhstv[236] = (         void  *)(MRASTEVDEF_N.CHG_OPT_20);
    sqlstm.sqhstl[236] = (unsigned int  )2;
    sqlstm.sqhsts[236] = (         int  )0;
    sqlstm.sqindv[236] = (         void  *)0;
    sqlstm.sqinds[236] = (         int  )0;
    sqlstm.sqharm[236] = (unsigned int  )0;
    sqlstm.sqadto[236] = (unsigned short )0;
    sqlstm.sqtdso[236] = (unsigned short )0;
    sqlstm.sqhstv[237] = (         void  *)(MRASTEVDEF_N.CHG_OPT_21);
    sqlstm.sqhstl[237] = (unsigned int  )2;
    sqlstm.sqhsts[237] = (         int  )0;
    sqlstm.sqindv[237] = (         void  *)0;
    sqlstm.sqinds[237] = (         int  )0;
    sqlstm.sqharm[237] = (unsigned int  )0;
    sqlstm.sqadto[237] = (unsigned short )0;
    sqlstm.sqtdso[237] = (unsigned short )0;
    sqlstm.sqhstv[238] = (         void  *)(MRASTEVDEF_N.CHG_OPT_22);
    sqlstm.sqhstl[238] = (unsigned int  )2;
    sqlstm.sqhsts[238] = (         int  )0;
    sqlstm.sqindv[238] = (         void  *)0;
    sqlstm.sqinds[238] = (         int  )0;
    sqlstm.sqharm[238] = (unsigned int  )0;
    sqlstm.sqadto[238] = (unsigned short )0;
    sqlstm.sqtdso[238] = (unsigned short )0;
    sqlstm.sqhstv[239] = (         void  *)(MRASTEVDEF_N.CHG_OPT_23);
    sqlstm.sqhstl[239] = (unsigned int  )2;
    sqlstm.sqhsts[239] = (         int  )0;
    sqlstm.sqindv[239] = (         void  *)0;
    sqlstm.sqinds[239] = (         int  )0;
    sqlstm.sqharm[239] = (unsigned int  )0;
    sqlstm.sqadto[239] = (unsigned short )0;
    sqlstm.sqtdso[239] = (unsigned short )0;
    sqlstm.sqhstv[240] = (         void  *)(MRASTEVDEF_N.CHG_OPT_24);
    sqlstm.sqhstl[240] = (unsigned int  )2;
    sqlstm.sqhsts[240] = (         int  )0;
    sqlstm.sqindv[240] = (         void  *)0;
    sqlstm.sqinds[240] = (         int  )0;
    sqlstm.sqharm[240] = (unsigned int  )0;
    sqlstm.sqadto[240] = (unsigned short )0;
    sqlstm.sqtdso[240] = (unsigned short )0;
    sqlstm.sqhstv[241] = (         void  *)(MRASTEVDEF_N.CHG_OPT_25);
    sqlstm.sqhstl[241] = (unsigned int  )2;
    sqlstm.sqhsts[241] = (         int  )0;
    sqlstm.sqindv[241] = (         void  *)0;
    sqlstm.sqinds[241] = (         int  )0;
    sqlstm.sqharm[241] = (unsigned int  )0;
    sqlstm.sqadto[241] = (unsigned short )0;
    sqlstm.sqtdso[241] = (unsigned short )0;
    sqlstm.sqhstv[242] = (         void  *)(MRASTEVDEF_N.CHG_OPT_26);
    sqlstm.sqhstl[242] = (unsigned int  )2;
    sqlstm.sqhsts[242] = (         int  )0;
    sqlstm.sqindv[242] = (         void  *)0;
    sqlstm.sqinds[242] = (         int  )0;
    sqlstm.sqharm[242] = (unsigned int  )0;
    sqlstm.sqadto[242] = (unsigned short )0;
    sqlstm.sqtdso[242] = (unsigned short )0;
    sqlstm.sqhstv[243] = (         void  *)(MRASTEVDEF_N.CHG_OPT_27);
    sqlstm.sqhstl[243] = (unsigned int  )2;
    sqlstm.sqhsts[243] = (         int  )0;
    sqlstm.sqindv[243] = (         void  *)0;
    sqlstm.sqinds[243] = (         int  )0;
    sqlstm.sqharm[243] = (unsigned int  )0;
    sqlstm.sqadto[243] = (unsigned short )0;
    sqlstm.sqtdso[243] = (unsigned short )0;
    sqlstm.sqhstv[244] = (         void  *)(MRASTEVDEF_N.CHG_OPT_28);
    sqlstm.sqhstl[244] = (unsigned int  )2;
    sqlstm.sqhsts[244] = (         int  )0;
    sqlstm.sqindv[244] = (         void  *)0;
    sqlstm.sqinds[244] = (         int  )0;
    sqlstm.sqharm[244] = (unsigned int  )0;
    sqlstm.sqadto[244] = (unsigned short )0;
    sqlstm.sqtdso[244] = (unsigned short )0;
    sqlstm.sqhstv[245] = (         void  *)(MRASTEVDEF_N.CHG_OPT_29);
    sqlstm.sqhstl[245] = (unsigned int  )2;
    sqlstm.sqhsts[245] = (         int  )0;
    sqlstm.sqindv[245] = (         void  *)0;
    sqlstm.sqinds[245] = (         int  )0;
    sqlstm.sqharm[245] = (unsigned int  )0;
    sqlstm.sqadto[245] = (unsigned short )0;
    sqlstm.sqtdso[245] = (unsigned short )0;
    sqlstm.sqhstv[246] = (         void  *)(MRASTEVDEF_N.CHG_OPT_30);
    sqlstm.sqhstl[246] = (unsigned int  )2;
    sqlstm.sqhsts[246] = (         int  )0;
    sqlstm.sqindv[246] = (         void  *)0;
    sqlstm.sqinds[246] = (         int  )0;
    sqlstm.sqharm[246] = (unsigned int  )0;
    sqlstm.sqadto[246] = (unsigned short )0;
    sqlstm.sqtdso[246] = (unsigned short )0;
    sqlstm.sqhstv[247] = (         void  *)(MRASTEVDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[247] = (unsigned int  )21;
    sqlstm.sqhsts[247] = (         int  )0;
    sqlstm.sqindv[247] = (         void  *)0;
    sqlstm.sqinds[247] = (         int  )0;
    sqlstm.sqharm[247] = (unsigned int  )0;
    sqlstm.sqadto[247] = (unsigned short )0;
    sqlstm.sqtdso[247] = (unsigned short )0;
    sqlstm.sqhstv[248] = (         void  *)(MRASTEVDEF_N.CREATE_TIME);
    sqlstm.sqhstl[248] = (unsigned int  )15;
    sqlstm.sqhsts[248] = (         int  )0;
    sqlstm.sqindv[248] = (         void  *)0;
    sqlstm.sqinds[248] = (         int  )0;
    sqlstm.sqharm[248] = (unsigned int  )0;
    sqlstm.sqadto[248] = (unsigned short )0;
    sqlstm.sqtdso[248] = (unsigned short )0;
    sqlstm.sqhstv[249] = (         void  *)(MRASTEVDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[249] = (unsigned int  )21;
    sqlstm.sqhsts[249] = (         int  )0;
    sqlstm.sqindv[249] = (         void  *)0;
    sqlstm.sqinds[249] = (         int  )0;
    sqlstm.sqharm[249] = (unsigned int  )0;
    sqlstm.sqadto[249] = (unsigned short )0;
    sqlstm.sqtdso[249] = (unsigned short )0;
    sqlstm.sqhstv[250] = (         void  *)(MRASTEVDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[250] = (unsigned int  )15;
    sqlstm.sqhsts[250] = (         int  )0;
    sqlstm.sqindv[250] = (         void  *)0;
    sqlstm.sqinds[250] = (         int  )0;
    sqlstm.sqharm[250] = (unsigned int  )0;
    sqlstm.sqadto[250] = (unsigned short )0;
    sqlstm.sqtdso[250] = (unsigned short )0;
    sqlstm.sqhstv[251] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_1);
    sqlstm.sqhstl[251] = (unsigned int  )31;
    sqlstm.sqhsts[251] = (         int  )0;
    sqlstm.sqindv[251] = (         void  *)0;
    sqlstm.sqinds[251] = (         int  )0;
    sqlstm.sqharm[251] = (unsigned int  )0;
    sqlstm.sqadto[251] = (unsigned short )0;
    sqlstm.sqtdso[251] = (unsigned short )0;
    sqlstm.sqhstv[252] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_2);
    sqlstm.sqhstl[252] = (unsigned int  )31;
    sqlstm.sqhsts[252] = (         int  )0;
    sqlstm.sqindv[252] = (         void  *)0;
    sqlstm.sqinds[252] = (         int  )0;
    sqlstm.sqharm[252] = (unsigned int  )0;
    sqlstm.sqadto[252] = (unsigned short )0;
    sqlstm.sqtdso[252] = (unsigned short )0;
    sqlstm.sqhstv[253] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_3);
    sqlstm.sqhstl[253] = (unsigned int  )31;
    sqlstm.sqhsts[253] = (         int  )0;
    sqlstm.sqindv[253] = (         void  *)0;
    sqlstm.sqinds[253] = (         int  )0;
    sqlstm.sqharm[253] = (unsigned int  )0;
    sqlstm.sqadto[253] = (unsigned short )0;
    sqlstm.sqtdso[253] = (unsigned short )0;
    sqlstm.sqhstv[254] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_4);
    sqlstm.sqhstl[254] = (unsigned int  )31;
    sqlstm.sqhsts[254] = (         int  )0;
    sqlstm.sqindv[254] = (         void  *)0;
    sqlstm.sqinds[254] = (         int  )0;
    sqlstm.sqharm[254] = (unsigned int  )0;
    sqlstm.sqadto[254] = (unsigned short )0;
    sqlstm.sqtdso[254] = (unsigned short )0;
    sqlstm.sqhstv[255] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_5);
    sqlstm.sqhstl[255] = (unsigned int  )31;
    sqlstm.sqhsts[255] = (         int  )0;
    sqlstm.sqindv[255] = (         void  *)0;
    sqlstm.sqinds[255] = (         int  )0;
    sqlstm.sqharm[255] = (unsigned int  )0;
    sqlstm.sqadto[255] = (unsigned short )0;
    sqlstm.sqtdso[255] = (unsigned short )0;
    sqlstm.sqhstv[256] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_6);
    sqlstm.sqhstl[256] = (unsigned int  )31;
    sqlstm.sqhsts[256] = (         int  )0;
    sqlstm.sqindv[256] = (         void  *)0;
    sqlstm.sqinds[256] = (         int  )0;
    sqlstm.sqharm[256] = (unsigned int  )0;
    sqlstm.sqadto[256] = (unsigned short )0;
    sqlstm.sqtdso[256] = (unsigned short )0;
    sqlstm.sqhstv[257] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_7);
    sqlstm.sqhstl[257] = (unsigned int  )31;
    sqlstm.sqhsts[257] = (         int  )0;
    sqlstm.sqindv[257] = (         void  *)0;
    sqlstm.sqinds[257] = (         int  )0;
    sqlstm.sqharm[257] = (unsigned int  )0;
    sqlstm.sqadto[257] = (unsigned short )0;
    sqlstm.sqtdso[257] = (unsigned short )0;
    sqlstm.sqhstv[258] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_8);
    sqlstm.sqhstl[258] = (unsigned int  )31;
    sqlstm.sqhsts[258] = (         int  )0;
    sqlstm.sqindv[258] = (         void  *)0;
    sqlstm.sqinds[258] = (         int  )0;
    sqlstm.sqharm[258] = (unsigned int  )0;
    sqlstm.sqadto[258] = (unsigned short )0;
    sqlstm.sqtdso[258] = (unsigned short )0;
    sqlstm.sqhstv[259] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_9);
    sqlstm.sqhstl[259] = (unsigned int  )31;
    sqlstm.sqhsts[259] = (         int  )0;
    sqlstm.sqindv[259] = (         void  *)0;
    sqlstm.sqinds[259] = (         int  )0;
    sqlstm.sqharm[259] = (unsigned int  )0;
    sqlstm.sqadto[259] = (unsigned short )0;
    sqlstm.sqtdso[259] = (unsigned short )0;
    sqlstm.sqhstv[260] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_10);
    sqlstm.sqhstl[260] = (unsigned int  )31;
    sqlstm.sqhsts[260] = (         int  )0;
    sqlstm.sqindv[260] = (         void  *)0;
    sqlstm.sqinds[260] = (         int  )0;
    sqlstm.sqharm[260] = (unsigned int  )0;
    sqlstm.sqadto[260] = (unsigned short )0;
    sqlstm.sqtdso[260] = (unsigned short )0;
    sqlstm.sqhstv[261] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_11);
    sqlstm.sqhstl[261] = (unsigned int  )31;
    sqlstm.sqhsts[261] = (         int  )0;
    sqlstm.sqindv[261] = (         void  *)0;
    sqlstm.sqinds[261] = (         int  )0;
    sqlstm.sqharm[261] = (unsigned int  )0;
    sqlstm.sqadto[261] = (unsigned short )0;
    sqlstm.sqtdso[261] = (unsigned short )0;
    sqlstm.sqhstv[262] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_12);
    sqlstm.sqhstl[262] = (unsigned int  )31;
    sqlstm.sqhsts[262] = (         int  )0;
    sqlstm.sqindv[262] = (         void  *)0;
    sqlstm.sqinds[262] = (         int  )0;
    sqlstm.sqharm[262] = (unsigned int  )0;
    sqlstm.sqadto[262] = (unsigned short )0;
    sqlstm.sqtdso[262] = (unsigned short )0;
    sqlstm.sqhstv[263] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_13);
    sqlstm.sqhstl[263] = (unsigned int  )31;
    sqlstm.sqhsts[263] = (         int  )0;
    sqlstm.sqindv[263] = (         void  *)0;
    sqlstm.sqinds[263] = (         int  )0;
    sqlstm.sqharm[263] = (unsigned int  )0;
    sqlstm.sqadto[263] = (unsigned short )0;
    sqlstm.sqtdso[263] = (unsigned short )0;
    sqlstm.sqhstv[264] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_14);
    sqlstm.sqhstl[264] = (unsigned int  )31;
    sqlstm.sqhsts[264] = (         int  )0;
    sqlstm.sqindv[264] = (         void  *)0;
    sqlstm.sqinds[264] = (         int  )0;
    sqlstm.sqharm[264] = (unsigned int  )0;
    sqlstm.sqadto[264] = (unsigned short )0;
    sqlstm.sqtdso[264] = (unsigned short )0;
    sqlstm.sqhstv[265] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_15);
    sqlstm.sqhstl[265] = (unsigned int  )31;
    sqlstm.sqhsts[265] = (         int  )0;
    sqlstm.sqindv[265] = (         void  *)0;
    sqlstm.sqinds[265] = (         int  )0;
    sqlstm.sqharm[265] = (unsigned int  )0;
    sqlstm.sqadto[265] = (unsigned short )0;
    sqlstm.sqtdso[265] = (unsigned short )0;
    sqlstm.sqhstv[266] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_16);
    sqlstm.sqhstl[266] = (unsigned int  )31;
    sqlstm.sqhsts[266] = (         int  )0;
    sqlstm.sqindv[266] = (         void  *)0;
    sqlstm.sqinds[266] = (         int  )0;
    sqlstm.sqharm[266] = (unsigned int  )0;
    sqlstm.sqadto[266] = (unsigned short )0;
    sqlstm.sqtdso[266] = (unsigned short )0;
    sqlstm.sqhstv[267] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_17);
    sqlstm.sqhstl[267] = (unsigned int  )31;
    sqlstm.sqhsts[267] = (         int  )0;
    sqlstm.sqindv[267] = (         void  *)0;
    sqlstm.sqinds[267] = (         int  )0;
    sqlstm.sqharm[267] = (unsigned int  )0;
    sqlstm.sqadto[267] = (unsigned short )0;
    sqlstm.sqtdso[267] = (unsigned short )0;
    sqlstm.sqhstv[268] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_18);
    sqlstm.sqhstl[268] = (unsigned int  )31;
    sqlstm.sqhsts[268] = (         int  )0;
    sqlstm.sqindv[268] = (         void  *)0;
    sqlstm.sqinds[268] = (         int  )0;
    sqlstm.sqharm[268] = (unsigned int  )0;
    sqlstm.sqadto[268] = (unsigned short )0;
    sqlstm.sqtdso[268] = (unsigned short )0;
    sqlstm.sqhstv[269] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_19);
    sqlstm.sqhstl[269] = (unsigned int  )31;
    sqlstm.sqhsts[269] = (         int  )0;
    sqlstm.sqindv[269] = (         void  *)0;
    sqlstm.sqinds[269] = (         int  )0;
    sqlstm.sqharm[269] = (unsigned int  )0;
    sqlstm.sqadto[269] = (unsigned short )0;
    sqlstm.sqtdso[269] = (unsigned short )0;
    sqlstm.sqhstv[270] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_20);
    sqlstm.sqhstl[270] = (unsigned int  )31;
    sqlstm.sqhsts[270] = (         int  )0;
    sqlstm.sqindv[270] = (         void  *)0;
    sqlstm.sqinds[270] = (         int  )0;
    sqlstm.sqharm[270] = (unsigned int  )0;
    sqlstm.sqadto[270] = (unsigned short )0;
    sqlstm.sqtdso[270] = (unsigned short )0;
    sqlstm.sqhstv[271] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_21);
    sqlstm.sqhstl[271] = (unsigned int  )31;
    sqlstm.sqhsts[271] = (         int  )0;
    sqlstm.sqindv[271] = (         void  *)0;
    sqlstm.sqinds[271] = (         int  )0;
    sqlstm.sqharm[271] = (unsigned int  )0;
    sqlstm.sqadto[271] = (unsigned short )0;
    sqlstm.sqtdso[271] = (unsigned short )0;
    sqlstm.sqhstv[272] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_22);
    sqlstm.sqhstl[272] = (unsigned int  )31;
    sqlstm.sqhsts[272] = (         int  )0;
    sqlstm.sqindv[272] = (         void  *)0;
    sqlstm.sqinds[272] = (         int  )0;
    sqlstm.sqharm[272] = (unsigned int  )0;
    sqlstm.sqadto[272] = (unsigned short )0;
    sqlstm.sqtdso[272] = (unsigned short )0;
    sqlstm.sqhstv[273] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_23);
    sqlstm.sqhstl[273] = (unsigned int  )31;
    sqlstm.sqhsts[273] = (         int  )0;
    sqlstm.sqindv[273] = (         void  *)0;
    sqlstm.sqinds[273] = (         int  )0;
    sqlstm.sqharm[273] = (unsigned int  )0;
    sqlstm.sqadto[273] = (unsigned short )0;
    sqlstm.sqtdso[273] = (unsigned short )0;
    sqlstm.sqhstv[274] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_24);
    sqlstm.sqhstl[274] = (unsigned int  )31;
    sqlstm.sqhsts[274] = (         int  )0;
    sqlstm.sqindv[274] = (         void  *)0;
    sqlstm.sqinds[274] = (         int  )0;
    sqlstm.sqharm[274] = (unsigned int  )0;
    sqlstm.sqadto[274] = (unsigned short )0;
    sqlstm.sqtdso[274] = (unsigned short )0;
    sqlstm.sqhstv[275] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_25);
    sqlstm.sqhstl[275] = (unsigned int  )31;
    sqlstm.sqhsts[275] = (         int  )0;
    sqlstm.sqindv[275] = (         void  *)0;
    sqlstm.sqinds[275] = (         int  )0;
    sqlstm.sqharm[275] = (unsigned int  )0;
    sqlstm.sqadto[275] = (unsigned short )0;
    sqlstm.sqtdso[275] = (unsigned short )0;
    sqlstm.sqhstv[276] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_26);
    sqlstm.sqhstl[276] = (unsigned int  )31;
    sqlstm.sqhsts[276] = (         int  )0;
    sqlstm.sqindv[276] = (         void  *)0;
    sqlstm.sqinds[276] = (         int  )0;
    sqlstm.sqharm[276] = (unsigned int  )0;
    sqlstm.sqadto[276] = (unsigned short )0;
    sqlstm.sqtdso[276] = (unsigned short )0;
    sqlstm.sqhstv[277] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_27);
    sqlstm.sqhstl[277] = (unsigned int  )31;
    sqlstm.sqhsts[277] = (         int  )0;
    sqlstm.sqindv[277] = (         void  *)0;
    sqlstm.sqinds[277] = (         int  )0;
    sqlstm.sqharm[277] = (unsigned int  )0;
    sqlstm.sqadto[277] = (unsigned short )0;
    sqlstm.sqtdso[277] = (unsigned short )0;
    sqlstm.sqhstv[278] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_28);
    sqlstm.sqhstl[278] = (unsigned int  )31;
    sqlstm.sqhsts[278] = (         int  )0;
    sqlstm.sqindv[278] = (         void  *)0;
    sqlstm.sqinds[278] = (         int  )0;
    sqlstm.sqharm[278] = (unsigned int  )0;
    sqlstm.sqadto[278] = (unsigned short )0;
    sqlstm.sqtdso[278] = (unsigned short )0;
    sqlstm.sqhstv[279] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_29);
    sqlstm.sqhstl[279] = (unsigned int  )31;
    sqlstm.sqhsts[279] = (         int  )0;
    sqlstm.sqindv[279] = (         void  *)0;
    sqlstm.sqinds[279] = (         int  )0;
    sqlstm.sqharm[279] = (unsigned int  )0;
    sqlstm.sqadto[279] = (unsigned short )0;
    sqlstm.sqtdso[279] = (unsigned short )0;
    sqlstm.sqhstv[280] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_30);
    sqlstm.sqhstl[280] = (unsigned int  )31;
    sqlstm.sqhsts[280] = (         int  )0;
    sqlstm.sqindv[280] = (         void  *)0;
    sqlstm.sqinds[280] = (         int  )0;
    sqlstm.sqharm[280] = (unsigned int  )0;
    sqlstm.sqadto[280] = (unsigned short )0;
    sqlstm.sqtdso[280] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_mrastevdef", 0);
}


/* SQL UPDATE Function */
void DBU_update_mrastevdef(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MRASTEVDEF SET
                    TOOL_EVENT_DESC = :MRASTEVDEF_N.TOOL_EVENT_DESC,
                    SYSTEM_FLAG = :MRASTEVDEF_N.SYSTEM_FLAG,
                    COLLECT_DEFECT_FLAG = :MRASTEVDEF_N.COLLECT_DEFECT_FLAG,
                    CLEAN_DEFECT_FLAG = :MRASTEVDEF_N.CLEAN_DEFECT_FLAG,
                    CHK_ITEM_1 = :MRASTEVDEF_N.CHK_ITEM_1,
                    CHK_ITEM_2 = :MRASTEVDEF_N.CHK_ITEM_2,
                    CHK_ITEM_3 = :MRASTEVDEF_N.CHK_ITEM_3,
                    CHK_ITEM_4 = :MRASTEVDEF_N.CHK_ITEM_4,
                    CHK_ITEM_5 = :MRASTEVDEF_N.CHK_ITEM_5,
                    CHK_ITEM_6 = :MRASTEVDEF_N.CHK_ITEM_6,
                    CHK_ITEM_7 = :MRASTEVDEF_N.CHK_ITEM_7,
                    CHK_ITEM_8 = :MRASTEVDEF_N.CHK_ITEM_8,
                    CHK_ITEM_9 = :MRASTEVDEF_N.CHK_ITEM_9,
                    CHK_ITEM_10 = :MRASTEVDEF_N.CHK_ITEM_10,
                    CHK_ITEM_11 = :MRASTEVDEF_N.CHK_ITEM_11,
                    CHK_ITEM_12 = :MRASTEVDEF_N.CHK_ITEM_12,
                    CHK_ITEM_13 = :MRASTEVDEF_N.CHK_ITEM_13,
                    CHK_ITEM_14 = :MRASTEVDEF_N.CHK_ITEM_14,
                    CHK_ITEM_15 = :MRASTEVDEF_N.CHK_ITEM_15,
                    CHK_ITEM_16 = :MRASTEVDEF_N.CHK_ITEM_16,
                    CHK_ITEM_17 = :MRASTEVDEF_N.CHK_ITEM_17,
                    CHK_ITEM_18 = :MRASTEVDEF_N.CHK_ITEM_18,
                    CHK_ITEM_19 = :MRASTEVDEF_N.CHK_ITEM_19,
                    CHK_ITEM_20 = :MRASTEVDEF_N.CHK_ITEM_20,
                    CHK_ITEM_21 = :MRASTEVDEF_N.CHK_ITEM_21,
                    CHK_ITEM_22 = :MRASTEVDEF_N.CHK_ITEM_22,
                    CHK_ITEM_23 = :MRASTEVDEF_N.CHK_ITEM_23,
                    CHK_ITEM_24 = :MRASTEVDEF_N.CHK_ITEM_24,
                    CHK_ITEM_25 = :MRASTEVDEF_N.CHK_ITEM_25,
                    CHK_ITEM_26 = :MRASTEVDEF_N.CHK_ITEM_26,
                    CHK_ITEM_27 = :MRASTEVDEF_N.CHK_ITEM_27,
                    CHK_ITEM_28 = :MRASTEVDEF_N.CHK_ITEM_28,
                    CHK_ITEM_29 = :MRASTEVDEF_N.CHK_ITEM_29,
                    CHK_ITEM_30 = :MRASTEVDEF_N.CHK_ITEM_30,
                    CHK_FLAG_1 = :MRASTEVDEF_N.CHK_FLAG_1,
                    CHK_FLAG_2 = :MRASTEVDEF_N.CHK_FLAG_2,
                    CHK_FLAG_3 = :MRASTEVDEF_N.CHK_FLAG_3,
                    CHK_FLAG_4 = :MRASTEVDEF_N.CHK_FLAG_4,
                    CHK_FLAG_5 = :MRASTEVDEF_N.CHK_FLAG_5,
                    CHK_FLAG_6 = :MRASTEVDEF_N.CHK_FLAG_6,
                    CHK_FLAG_7 = :MRASTEVDEF_N.CHK_FLAG_7,
                    CHK_FLAG_8 = :MRASTEVDEF_N.CHK_FLAG_8,
                    CHK_FLAG_9 = :MRASTEVDEF_N.CHK_FLAG_9,
                    CHK_FLAG_10 = :MRASTEVDEF_N.CHK_FLAG_10,
                    CHK_FLAG_11 = :MRASTEVDEF_N.CHK_FLAG_11,
                    CHK_FLAG_12 = :MRASTEVDEF_N.CHK_FLAG_12,
                    CHK_FLAG_13 = :MRASTEVDEF_N.CHK_FLAG_13,
                    CHK_FLAG_14 = :MRASTEVDEF_N.CHK_FLAG_14,
                    CHK_FLAG_15 = :MRASTEVDEF_N.CHK_FLAG_15,
                    CHK_FLAG_16 = :MRASTEVDEF_N.CHK_FLAG_16,
                    CHK_FLAG_17 = :MRASTEVDEF_N.CHK_FLAG_17,
                    CHK_FLAG_18 = :MRASTEVDEF_N.CHK_FLAG_18,
                    CHK_FLAG_19 = :MRASTEVDEF_N.CHK_FLAG_19,
                    CHK_FLAG_20 = :MRASTEVDEF_N.CHK_FLAG_20,
                    CHK_FLAG_21 = :MRASTEVDEF_N.CHK_FLAG_21,
                    CHK_FLAG_22 = :MRASTEVDEF_N.CHK_FLAG_22,
                    CHK_FLAG_23 = :MRASTEVDEF_N.CHK_FLAG_23,
                    CHK_FLAG_24 = :MRASTEVDEF_N.CHK_FLAG_24,
                    CHK_FLAG_25 = :MRASTEVDEF_N.CHK_FLAG_25,
                    CHK_FLAG_26 = :MRASTEVDEF_N.CHK_FLAG_26,
                    CHK_FLAG_27 = :MRASTEVDEF_N.CHK_FLAG_27,
                    CHK_FLAG_28 = :MRASTEVDEF_N.CHK_FLAG_28,
                    CHK_FLAG_29 = :MRASTEVDEF_N.CHK_FLAG_29,
                    CHK_FLAG_30 = :MRASTEVDEF_N.CHK_FLAG_30,
                    CHK_VALUE_1 = :MRASTEVDEF_N.CHK_VALUE_1,
                    CHK_VALUE_2 = :MRASTEVDEF_N.CHK_VALUE_2,
                    CHK_VALUE_3 = :MRASTEVDEF_N.CHK_VALUE_3,
                    CHK_VALUE_4 = :MRASTEVDEF_N.CHK_VALUE_4,
                    CHK_VALUE_5 = :MRASTEVDEF_N.CHK_VALUE_5,
                    CHK_VALUE_6 = :MRASTEVDEF_N.CHK_VALUE_6,
                    CHK_VALUE_7 = :MRASTEVDEF_N.CHK_VALUE_7,
                    CHK_VALUE_8 = :MRASTEVDEF_N.CHK_VALUE_8,
                    CHK_VALUE_9 = :MRASTEVDEF_N.CHK_VALUE_9,
                    CHK_VALUE_10 = :MRASTEVDEF_N.CHK_VALUE_10,
                    CHK_VALUE_11 = :MRASTEVDEF_N.CHK_VALUE_11,
                    CHK_VALUE_12 = :MRASTEVDEF_N.CHK_VALUE_12,
                    CHK_VALUE_13 = :MRASTEVDEF_N.CHK_VALUE_13,
                    CHK_VALUE_14 = :MRASTEVDEF_N.CHK_VALUE_14,
                    CHK_VALUE_15 = :MRASTEVDEF_N.CHK_VALUE_15,
                    CHK_VALUE_16 = :MRASTEVDEF_N.CHK_VALUE_16,
                    CHK_VALUE_17 = :MRASTEVDEF_N.CHK_VALUE_17,
                    CHK_VALUE_18 = :MRASTEVDEF_N.CHK_VALUE_18,
                    CHK_VALUE_19 = :MRASTEVDEF_N.CHK_VALUE_19,
                    CHK_VALUE_20 = :MRASTEVDEF_N.CHK_VALUE_20,
                    CHK_VALUE_21 = :MRASTEVDEF_N.CHK_VALUE_21,
                    CHK_VALUE_22 = :MRASTEVDEF_N.CHK_VALUE_22,
                    CHK_VALUE_23 = :MRASTEVDEF_N.CHK_VALUE_23,
                    CHK_VALUE_24 = :MRASTEVDEF_N.CHK_VALUE_24,
                    CHK_VALUE_25 = :MRASTEVDEF_N.CHK_VALUE_25,
                    CHK_VALUE_26 = :MRASTEVDEF_N.CHK_VALUE_26,
                    CHK_VALUE_27 = :MRASTEVDEF_N.CHK_VALUE_27,
                    CHK_VALUE_28 = :MRASTEVDEF_N.CHK_VALUE_28,
                    CHK_VALUE_29 = :MRASTEVDEF_N.CHK_VALUE_29,
                    CHK_VALUE_30 = :MRASTEVDEF_N.CHK_VALUE_30,
                    CHK_FIELD_1 = :MRASTEVDEF_N.CHK_FIELD_1,
                    CHK_FIELD_2 = :MRASTEVDEF_N.CHK_FIELD_2,
                    CHK_FIELD_3 = :MRASTEVDEF_N.CHK_FIELD_3,
                    CHK_FIELD_4 = :MRASTEVDEF_N.CHK_FIELD_4,
                    CHK_FIELD_5 = :MRASTEVDEF_N.CHK_FIELD_5,
                    CHK_FIELD_6 = :MRASTEVDEF_N.CHK_FIELD_6,
                    CHK_FIELD_7 = :MRASTEVDEF_N.CHK_FIELD_7,
                    CHK_FIELD_8 = :MRASTEVDEF_N.CHK_FIELD_8,
                    CHK_FIELD_9 = :MRASTEVDEF_N.CHK_FIELD_9,
                    CHK_FIELD_10 = :MRASTEVDEF_N.CHK_FIELD_10,
                    CHK_FIELD_11 = :MRASTEVDEF_N.CHK_FIELD_11,
                    CHK_FIELD_12 = :MRASTEVDEF_N.CHK_FIELD_12,
                    CHK_FIELD_13 = :MRASTEVDEF_N.CHK_FIELD_13,
                    CHK_FIELD_14 = :MRASTEVDEF_N.CHK_FIELD_14,
                    CHK_FIELD_15 = :MRASTEVDEF_N.CHK_FIELD_15,
                    CHK_FIELD_16 = :MRASTEVDEF_N.CHK_FIELD_16,
                    CHK_FIELD_17 = :MRASTEVDEF_N.CHK_FIELD_17,
                    CHK_FIELD_18 = :MRASTEVDEF_N.CHK_FIELD_18,
                    CHK_FIELD_19 = :MRASTEVDEF_N.CHK_FIELD_19,
                    CHK_FIELD_20 = :MRASTEVDEF_N.CHK_FIELD_20,
                    CHK_FIELD_21 = :MRASTEVDEF_N.CHK_FIELD_21,
                    CHK_FIELD_22 = :MRASTEVDEF_N.CHK_FIELD_22,
                    CHK_FIELD_23 = :MRASTEVDEF_N.CHK_FIELD_23,
                    CHK_FIELD_24 = :MRASTEVDEF_N.CHK_FIELD_24,
                    CHK_FIELD_25 = :MRASTEVDEF_N.CHK_FIELD_25,
                    CHK_FIELD_26 = :MRASTEVDEF_N.CHK_FIELD_26,
                    CHK_FIELD_27 = :MRASTEVDEF_N.CHK_FIELD_27,
                    CHK_FIELD_28 = :MRASTEVDEF_N.CHK_FIELD_28,
                    CHK_FIELD_29 = :MRASTEVDEF_N.CHK_FIELD_29,
                    CHK_FIELD_30 = :MRASTEVDEF_N.CHK_FIELD_30,
                    CHG_ITEM_1 = :MRASTEVDEF_N.CHG_ITEM_1,
                    CHG_ITEM_2 = :MRASTEVDEF_N.CHG_ITEM_2,
                    CHG_ITEM_3 = :MRASTEVDEF_N.CHG_ITEM_3,
                    CHG_ITEM_4 = :MRASTEVDEF_N.CHG_ITEM_4,
                    CHG_ITEM_5 = :MRASTEVDEF_N.CHG_ITEM_5,
                    CHG_ITEM_6 = :MRASTEVDEF_N.CHG_ITEM_6,
                    CHG_ITEM_7 = :MRASTEVDEF_N.CHG_ITEM_7,
                    CHG_ITEM_8 = :MRASTEVDEF_N.CHG_ITEM_8,
                    CHG_ITEM_9 = :MRASTEVDEF_N.CHG_ITEM_9,
                    CHG_ITEM_10 = :MRASTEVDEF_N.CHG_ITEM_10,
                    CHG_ITEM_11 = :MRASTEVDEF_N.CHG_ITEM_11,
                    CHG_ITEM_12 = :MRASTEVDEF_N.CHG_ITEM_12,
                    CHG_ITEM_13 = :MRASTEVDEF_N.CHG_ITEM_13,
                    CHG_ITEM_14 = :MRASTEVDEF_N.CHG_ITEM_14,
                    CHG_ITEM_15 = :MRASTEVDEF_N.CHG_ITEM_15,
                    CHG_ITEM_16 = :MRASTEVDEF_N.CHG_ITEM_16,
                    CHG_ITEM_17 = :MRASTEVDEF_N.CHG_ITEM_17,
                    CHG_ITEM_18 = :MRASTEVDEF_N.CHG_ITEM_18,
                    CHG_ITEM_19 = :MRASTEVDEF_N.CHG_ITEM_19,
                    CHG_ITEM_20 = :MRASTEVDEF_N.CHG_ITEM_20,
                    CHG_ITEM_21 = :MRASTEVDEF_N.CHG_ITEM_21,
                    CHG_ITEM_22 = :MRASTEVDEF_N.CHG_ITEM_22,
                    CHG_ITEM_23 = :MRASTEVDEF_N.CHG_ITEM_23,
                    CHG_ITEM_24 = :MRASTEVDEF_N.CHG_ITEM_24,
                    CHG_ITEM_25 = :MRASTEVDEF_N.CHG_ITEM_25,
                    CHG_ITEM_26 = :MRASTEVDEF_N.CHG_ITEM_26,
                    CHG_ITEM_27 = :MRASTEVDEF_N.CHG_ITEM_27,
                    CHG_ITEM_28 = :MRASTEVDEF_N.CHG_ITEM_28,
                    CHG_ITEM_29 = :MRASTEVDEF_N.CHG_ITEM_29,
                    CHG_ITEM_30 = :MRASTEVDEF_N.CHG_ITEM_30,
                    CHG_FLAG_1 = :MRASTEVDEF_N.CHG_FLAG_1,
                    CHG_FLAG_2 = :MRASTEVDEF_N.CHG_FLAG_2,
                    CHG_FLAG_3 = :MRASTEVDEF_N.CHG_FLAG_3,
                    CHG_FLAG_4 = :MRASTEVDEF_N.CHG_FLAG_4,
                    CHG_FLAG_5 = :MRASTEVDEF_N.CHG_FLAG_5,
                    CHG_FLAG_6 = :MRASTEVDEF_N.CHG_FLAG_6,
                    CHG_FLAG_7 = :MRASTEVDEF_N.CHG_FLAG_7,
                    CHG_FLAG_8 = :MRASTEVDEF_N.CHG_FLAG_8,
                    CHG_FLAG_9 = :MRASTEVDEF_N.CHG_FLAG_9,
                    CHG_FLAG_10 = :MRASTEVDEF_N.CHG_FLAG_10,
                    CHG_FLAG_11 = :MRASTEVDEF_N.CHG_FLAG_11,
                    CHG_FLAG_12 = :MRASTEVDEF_N.CHG_FLAG_12,
                    CHG_FLAG_13 = :MRASTEVDEF_N.CHG_FLAG_13,
                    CHG_FLAG_14 = :MRASTEVDEF_N.CHG_FLAG_14,
                    CHG_FLAG_15 = :MRASTEVDEF_N.CHG_FLAG_15,
                    CHG_FLAG_16 = :MRASTEVDEF_N.CHG_FLAG_16,
                    CHG_FLAG_17 = :MRASTEVDEF_N.CHG_FLAG_17,
                    CHG_FLAG_18 = :MRASTEVDEF_N.CHG_FLAG_18,
                    CHG_FLAG_19 = :MRASTEVDEF_N.CHG_FLAG_19,
                    CHG_FLAG_20 = :MRASTEVDEF_N.CHG_FLAG_20,
                    CHG_FLAG_21 = :MRASTEVDEF_N.CHG_FLAG_21,
                    CHG_FLAG_22 = :MRASTEVDEF_N.CHG_FLAG_22,
                    CHG_FLAG_23 = :MRASTEVDEF_N.CHG_FLAG_23,
                    CHG_FLAG_24 = :MRASTEVDEF_N.CHG_FLAG_24,
                    CHG_FLAG_25 = :MRASTEVDEF_N.CHG_FLAG_25,
                    CHG_FLAG_26 = :MRASTEVDEF_N.CHG_FLAG_26,
                    CHG_FLAG_27 = :MRASTEVDEF_N.CHG_FLAG_27,
                    CHG_FLAG_28 = :MRASTEVDEF_N.CHG_FLAG_28,
                    CHG_FLAG_29 = :MRASTEVDEF_N.CHG_FLAG_29,
                    CHG_FLAG_30 = :MRASTEVDEF_N.CHG_FLAG_30,
                    CHG_VALUE_1 = :MRASTEVDEF_N.CHG_VALUE_1,
                    CHG_VALUE_2 = :MRASTEVDEF_N.CHG_VALUE_2,
                    CHG_VALUE_3 = :MRASTEVDEF_N.CHG_VALUE_3,
                    CHG_VALUE_4 = :MRASTEVDEF_N.CHG_VALUE_4,
                    CHG_VALUE_5 = :MRASTEVDEF_N.CHG_VALUE_5,
                    CHG_VALUE_6 = :MRASTEVDEF_N.CHG_VALUE_6,
                    CHG_VALUE_7 = :MRASTEVDEF_N.CHG_VALUE_7,
                    CHG_VALUE_8 = :MRASTEVDEF_N.CHG_VALUE_8,
                    CHG_VALUE_9 = :MRASTEVDEF_N.CHG_VALUE_9,
                    CHG_VALUE_10 = :MRASTEVDEF_N.CHG_VALUE_10,
                    CHG_VALUE_11 = :MRASTEVDEF_N.CHG_VALUE_11,
                    CHG_VALUE_12 = :MRASTEVDEF_N.CHG_VALUE_12,
                    CHG_VALUE_13 = :MRASTEVDEF_N.CHG_VALUE_13,
                    CHG_VALUE_14 = :MRASTEVDEF_N.CHG_VALUE_14,
                    CHG_VALUE_15 = :MRASTEVDEF_N.CHG_VALUE_15,
                    CHG_VALUE_16 = :MRASTEVDEF_N.CHG_VALUE_16,
                    CHG_VALUE_17 = :MRASTEVDEF_N.CHG_VALUE_17,
                    CHG_VALUE_18 = :MRASTEVDEF_N.CHG_VALUE_18,
                    CHG_VALUE_19 = :MRASTEVDEF_N.CHG_VALUE_19,
                    CHG_VALUE_20 = :MRASTEVDEF_N.CHG_VALUE_20,
                    CHG_VALUE_21 = :MRASTEVDEF_N.CHG_VALUE_21,
                    CHG_VALUE_22 = :MRASTEVDEF_N.CHG_VALUE_22,
                    CHG_VALUE_23 = :MRASTEVDEF_N.CHG_VALUE_23,
                    CHG_VALUE_24 = :MRASTEVDEF_N.CHG_VALUE_24,
                    CHG_VALUE_25 = :MRASTEVDEF_N.CHG_VALUE_25,
                    CHG_VALUE_26 = :MRASTEVDEF_N.CHG_VALUE_26,
                    CHG_VALUE_27 = :MRASTEVDEF_N.CHG_VALUE_27,
                    CHG_VALUE_28 = :MRASTEVDEF_N.CHG_VALUE_28,
                    CHG_VALUE_29 = :MRASTEVDEF_N.CHG_VALUE_29,
                    CHG_VALUE_30 = :MRASTEVDEF_N.CHG_VALUE_30,
                    CHG_OPT_1 = :MRASTEVDEF_N.CHG_OPT_1,
                    CHG_OPT_2 = :MRASTEVDEF_N.CHG_OPT_2,
                    CHG_OPT_3 = :MRASTEVDEF_N.CHG_OPT_3,
                    CHG_OPT_4 = :MRASTEVDEF_N.CHG_OPT_4,
                    CHG_OPT_5 = :MRASTEVDEF_N.CHG_OPT_5,
                    CHG_OPT_6 = :MRASTEVDEF_N.CHG_OPT_6,
                    CHG_OPT_7 = :MRASTEVDEF_N.CHG_OPT_7,
                    CHG_OPT_8 = :MRASTEVDEF_N.CHG_OPT_8,
                    CHG_OPT_9 = :MRASTEVDEF_N.CHG_OPT_9,
                    CHG_OPT_10 = :MRASTEVDEF_N.CHG_OPT_10,
                    CHG_OPT_11 = :MRASTEVDEF_N.CHG_OPT_11,
                    CHG_OPT_12 = :MRASTEVDEF_N.CHG_OPT_12,
                    CHG_OPT_13 = :MRASTEVDEF_N.CHG_OPT_13,
                    CHG_OPT_14 = :MRASTEVDEF_N.CHG_OPT_14,
                    CHG_OPT_15 = :MRASTEVDEF_N.CHG_OPT_15,
                    CHG_OPT_16 = :MRASTEVDEF_N.CHG_OPT_16,
                    CHG_OPT_17 = :MRASTEVDEF_N.CHG_OPT_17,
                    CHG_OPT_18 = :MRASTEVDEF_N.CHG_OPT_18,
                    CHG_OPT_19 = :MRASTEVDEF_N.CHG_OPT_19,
                    CHG_OPT_20 = :MRASTEVDEF_N.CHG_OPT_20,
                    CHG_OPT_21 = :MRASTEVDEF_N.CHG_OPT_21,
                    CHG_OPT_22 = :MRASTEVDEF_N.CHG_OPT_22,
                    CHG_OPT_23 = :MRASTEVDEF_N.CHG_OPT_23,
                    CHG_OPT_24 = :MRASTEVDEF_N.CHG_OPT_24,
                    CHG_OPT_25 = :MRASTEVDEF_N.CHG_OPT_25,
                    CHG_OPT_26 = :MRASTEVDEF_N.CHG_OPT_26,
                    CHG_OPT_27 = :MRASTEVDEF_N.CHG_OPT_27,
                    CHG_OPT_28 = :MRASTEVDEF_N.CHG_OPT_28,
                    CHG_OPT_29 = :MRASTEVDEF_N.CHG_OPT_29,
                    CHG_OPT_30 = :MRASTEVDEF_N.CHG_OPT_30,
                    CREATE_USER_ID = :MRASTEVDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MRASTEVDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MRASTEVDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MRASTEVDEF_N.UPDATE_TIME,
                    CHG_FIELD_1 = :MRASTEVDEF_N.CHG_FIELD_1,
                    CHG_FIELD_2 = :MRASTEVDEF_N.CHG_FIELD_2,
                    CHG_FIELD_3 = :MRASTEVDEF_N.CHG_FIELD_3,
                    CHG_FIELD_4 = :MRASTEVDEF_N.CHG_FIELD_4,
                    CHG_FIELD_5 = :MRASTEVDEF_N.CHG_FIELD_5,
                    CHG_FIELD_6 = :MRASTEVDEF_N.CHG_FIELD_6,
                    CHG_FIELD_7 = :MRASTEVDEF_N.CHG_FIELD_7,
                    CHG_FIELD_8 = :MRASTEVDEF_N.CHG_FIELD_8,
                    CHG_FIELD_9 = :MRASTEVDEF_N.CHG_FIELD_9,
                    CHG_FIELD_10 = :MRASTEVDEF_N.CHG_FIELD_10,
                    CHG_FIELD_11 = :MRASTEVDEF_N.CHG_FIELD_11,
                    CHG_FIELD_12 = :MRASTEVDEF_N.CHG_FIELD_12,
                    CHG_FIELD_13 = :MRASTEVDEF_N.CHG_FIELD_13,
                    CHG_FIELD_14 = :MRASTEVDEF_N.CHG_FIELD_14,
                    CHG_FIELD_15 = :MRASTEVDEF_N.CHG_FIELD_15,
                    CHG_FIELD_16 = :MRASTEVDEF_N.CHG_FIELD_16,
                    CHG_FIELD_17 = :MRASTEVDEF_N.CHG_FIELD_17,
                    CHG_FIELD_18 = :MRASTEVDEF_N.CHG_FIELD_18,
                    CHG_FIELD_19 = :MRASTEVDEF_N.CHG_FIELD_19,
                    CHG_FIELD_20 = :MRASTEVDEF_N.CHG_FIELD_20,
                    CHG_FIELD_21 = :MRASTEVDEF_N.CHG_FIELD_21,
                    CHG_FIELD_22 = :MRASTEVDEF_N.CHG_FIELD_22,
                    CHG_FIELD_23 = :MRASTEVDEF_N.CHG_FIELD_23,
                    CHG_FIELD_24 = :MRASTEVDEF_N.CHG_FIELD_24,
                    CHG_FIELD_25 = :MRASTEVDEF_N.CHG_FIELD_25,
                    CHG_FIELD_26 = :MRASTEVDEF_N.CHG_FIELD_26,
                    CHG_FIELD_27 = :MRASTEVDEF_N.CHG_FIELD_27,
                    CHG_FIELD_28 = :MRASTEVDEF_N.CHG_FIELD_28,
                    CHG_FIELD_29 = :MRASTEVDEF_N.CHG_FIELD_29,
                    CHG_FIELD_30 = :MRASTEVDEF_N.CHG_FIELD_30
                WHERE FACTORY = :MRASTEVDEF_N.FACTORY
                    AND TOOL_TYPE = :MRASTEVDEF_N.TOOL_TYPE
                    AND TOOL_EVENT_ID = :MRASTEVDEF_N.TOOL_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MRASTEVDEF  set TOOL_EVENT_DESC=:b0,SYSTEM_FLAG=:b1,CO\
LLECT_DEFECT_FLAG=:b2,CLEAN_DEFECT_FLAG=:b3,CHK_ITEM_1=:b4,CHK_ITEM_2=:b5,CH\
K_ITEM_3=:b6,CHK_ITEM_4=:b7,CHK_ITEM_5=:b8,CHK_ITEM_6=:b9,CHK_ITEM_7=:b10,CH\
K_ITEM_8=:b11,CHK_ITEM_9=:b12,CHK_ITEM_10=:b13,CHK_ITEM_11=:b14,CHK_ITEM_12=\
:b15,CHK_ITEM_13=:b16,CHK_ITEM_14=:b17,CHK_ITEM_15=:b18,CHK_ITEM_16=:b19,CHK\
_ITEM_17=:b20,CHK_ITEM_18=:b21,CHK_ITEM_19=:b22,CHK_ITEM_20=:b23,CHK_ITEM_21\
=:b24,CHK_ITEM_22=:b25,CHK_ITEM_23=:b26,CHK_ITEM_24=:b27,CHK_ITEM_25=:b28,CH\
K_ITEM_26=:b29,CHK_ITEM_27=:b30,CHK_ITEM_28=:b31,CHK_ITEM_29=:b32,CHK_ITEM_3\
0=:b33,CHK_FLAG_1=:b34,CHK_FLAG_2=:b35,CHK_FLAG_3=:b36,CHK_FLAG_4=:b37,CHK_F\
LAG_5=:b38,CHK_FLAG_6=:b39,CHK_FLAG_7=:b40,CHK_FLAG_8=:b41,CHK_FLAG_9=:b42,C\
HK_FLAG_10=:b43,CHK_FLAG_11=:b44,CHK_FLAG_12=:b45,CHK_FLAG_13=:b46,CHK_FLAG_\
14=:b47,CHK_FLAG_15=:b48,CHK_FLAG_16=:b49,CHK_FLAG_17=:b50,CHK_FLAG_18=:b51,\
CHK_FLAG_19=:b52,CHK_FLAG_20=:b53,CHK_FLAG_21=:b54,CHK_FLAG_22=:b55,CHK_FLAG\
_23=:b56,CHK_FLAG_24=:b57,CHK_FLAG_25=:b58,CHK_FLAG");
            sqlbuft((void **)0,
              "_26=:b59,CHK_FLAG_27=:b60,CHK_FLAG_28=:b61,CHK_FLAG_29=:b62,C\
HK_FLAG_30=:b63,CHK_VALUE_1=:b64,CHK_VALUE_2=:b65,CHK_VALUE_3=:b66,CHK_VALUE\
_4=:b67,CHK_VALUE_5=:b68,CHK_VALUE_6=:b69,CHK_VALUE_7=:b70,CHK_VALUE_8=:b71,\
CHK_VALUE_9=:b72,CHK_VALUE_10=:b73,CHK_VALUE_11=:b74,CHK_VALUE_12=:b75,CHK_V\
ALUE_13=:b76,CHK_VALUE_14=:b77,CHK_VALUE_15=:b78,CHK_VALUE_16=:b79,CHK_VALUE\
_17=:b80,CHK_VALUE_18=:b81,CHK_VALUE_19=:b82,CHK_VALUE_20=:b83,CHK_VALUE_21=\
:b84,CHK_VALUE_22=:b85,CHK_VALUE_23=:b86,CHK_VALUE_24=:b87,CHK_VALUE_25=:b88\
,CHK_VALUE_26=:b89,CHK_VALUE_27=:b90,CHK_VALUE_28=:b91,CHK_VALUE_29=:b92,CHK\
_VALUE_30=:b93,CHK_FIELD_1=:b94,CHK_FIELD_2=:b95,CHK_FIELD_3=:b96,CHK_FIELD_\
4=:b97,CHK_FIELD_5=:b98,CHK_FIELD_6=:b99,CHK_FIELD_7=:b100,CHK_FIELD_8=:b101\
,CHK_FIELD_9=:b102,CHK_FIELD_10=:b103,CHK_FIELD_11=:b104,CHK_FIELD_12=:b105,\
CHK_FIELD_13=:b106,CHK_FIELD_14=:b107,CHK_FIELD_15=:b108,CHK_FIELD_16=:b109,\
CHK_FIELD_17=:b110,CHK_FIELD_18=:b111,CHK_FIELD_19=:b112,CHK_FIELD_20=:b113,\
CHK_FIELD_21=:b114,CHK_FIELD_22=:b115,CHK_FIELD_23=");
            sqlbuft((void **)0,
              ":b116,CHK_FIELD_24=:b117,CHK_FIELD_25=:b118,CHK_FIELD_26=:b11\
9,CHK_FIELD_27=:b120,CHK_FIELD_28=:b121,CHK_FIELD_29=:b122,CHK_FIELD_30=:b12\
3,CHG_ITEM_1=:b124,CHG_ITEM_2=:b125,CHG_ITEM_3=:b126,CHG_ITEM_4=:b127,CHG_IT\
EM_5=:b128,CHG_ITEM_6=:b129,CHG_ITEM_7=:b130,CHG_ITEM_8=:b131,CHG_ITEM_9=:b1\
32,CHG_ITEM_10=:b133,CHG_ITEM_11=:b134,CHG_ITEM_12=:b135,CHG_ITEM_13=:b136,C\
HG_ITEM_14=:b137,CHG_ITEM_15=:b138,CHG_ITEM_16=:b139,CHG_ITEM_17=:b140,CHG_I\
TEM_18=:b141,CHG_ITEM_19=:b142,CHG_ITEM_20=:b143,CHG_ITEM_21=:b144,CHG_ITEM_\
22=:b145,CHG_ITEM_23=:b146,CHG_ITEM_24=:b147,CHG_ITEM_25=:b148,CHG_ITEM_26=:\
b149,CHG_ITEM_27=:b150,CHG_ITEM_28=:b151,CHG_ITEM_29=:b152,CHG_ITEM_30=:b153\
,CHG_FLAG_1=:b154,CHG_FLAG_2=:b155,CHG_FLAG_3=:b156,CHG_FLAG_4=:b157,CHG_FLA\
G_5=:b158,CHG_FLAG_6=:b159,CHG_FLAG_7=:b160,CHG_FLAG_8=:b161,CHG_FLAG_9=:b16\
2,CHG_FLAG_10=:b163,CHG_FLAG_11=:b164,CHG_FLAG_12=:b165,CHG_FLAG_13=:b166,CH\
G_FLAG_14=:b167,CHG_FLAG_15=:b168,CHG_FLAG_16=:b169,CHG_FLAG_17=:b170,CHG_FL\
AG_18=:b171,CHG_FLAG_19=:b172,CHG_FLAG_20=:b173,CHG");
            sqlbuft((void **)0,
              "_FLAG_21=:b174,CHG_FLAG_22=:b175,CHG_FLAG_23=:b176,CHG_FLAG_2\
4=:b177,CHG_FLAG_25=:b178,CHG_FLAG_26=:b179,CHG_FLAG_27=:b180,CHG_FLAG_28=:b\
181,CHG_FLAG_29=:b182,CHG_FLAG_30=:b183,CHG_VALUE_1=:b184,CHG_VALUE_2=:b185,\
CHG_VALUE_3=:b186,CHG_VALUE_4=:b187,CHG_VALUE_5=:b188,CHG_VALUE_6=:b189,CHG_\
VALUE_7=:b190,CHG_VALUE_8=:b191,CHG_VALUE_9=:b192,CHG_VALUE_10=:b193,CHG_VAL\
UE_11=:b194,CHG_VALUE_12=:b195,CHG_VALUE_13=:b196,CHG_VALUE_14=:b197,CHG_VAL\
UE_15=:b198,CHG_VALUE_16=:b199,CHG_VALUE_17=:b200,CHG_VALUE_18=:b201,CHG_VAL\
UE_19=:b202,CHG_VALUE_20=:b203,CHG_VALUE_21=:b204,CHG_VALUE_22=:b205,CHG_VAL\
UE_23=:b206,CHG_VALUE_24=:b207,CHG_VALUE_25=:b208,CHG_VALUE_26=:b209,CHG_VAL\
UE_27=:b210,CHG_VALUE_28=:b211,CHG_VALUE_29=:b212,CHG_VALUE_30=:b213,CHG_OPT\
_1=:b214,CHG_OPT_2=:b215,CHG_OPT_3=:b216,CHG_OPT_4=:b217,CHG_OPT_5=:b218,CHG\
_OPT_6=:b219,CHG_OPT_7=:b220,CHG_OPT_8=:b221,CHG_OPT_9=:b222,CHG_OPT_10=:b22\
3,CHG_OPT_11=:b224,CHG_OPT_12=:b225,CHG_OPT_13=:b226,CHG_OPT_14=:b227,CHG_OP\
T_15=:b228,CHG_OPT_16=:b229,CHG_OPT_17=:b230,CHG_OP");
            sqlstm.stmt = "T_18=:b231,CHG_OPT_19=:b232,CHG_OPT_20=:b233,CHG\
_OPT_21=:b234,CHG_OPT_22=:b235,CHG_OPT_23=:b236,CHG_OPT_24=:b237,CHG_OPT_25=:\
b238,CHG_OPT_26=:b239,CHG_OPT_27=:b240,CHG_OPT_28=:b241,CHG_OPT_29=:b242,CHG_\
OPT_30=:b243,CREATE_USER_ID=:b244,CREATE_TIME=:b245,UPDATE_USER_ID=:b246,UPDA\
TE_TIME=:b247,CHG_FIELD_1=:b248,CHG_FIELD_2=:b249,CHG_FIELD_3=:b250,CHG_FIELD\
_4=:b251,CHG_FIELD_5=:b252,CHG_FIELD_6=:b253,CHG_FIELD_7=:b254,CHG_FIELD_8=:b\
255,CHG_FIELD_9=:b256,CHG_FIELD_10=:b257,CHG_FIELD_11=:b258,CHG_FIELD_12=:b25\
9,CHG_FIELD_13=:b260,CHG_FIELD_14=:b261,CHG_FIELD_15=:b262,CHG_FIELD_16=:b263\
,CHG_FIELD_17=:b264,CHG_FIELD_18=:b265,CHG_FIELD_19=:b266,CHG_FIELD_20=:b267,\
CHG_FIELD_21=:b268,CHG_FIELD_22=:b269,CHG_FIELD_23=:b270,CHG_FIELD_24=:b271,C\
HG_FIELD_25=:b272,CHG_FIELD_26=:b273,CHG_FIELD_27=:b274,CHG_FIELD_28=:b275,CH\
G_FIELD_29=:b276,CHG_FIELD_30=:b277 where ((FACTORY=:b278 and TOOL_TYPE=:b279\
) and TOOL_EVENT_ID=:b280)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3504;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.COLLECT_DEFECT_FLAG);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.CLEAN_DEFECT_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[154] = (unsigned int  )2;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[155] = (unsigned int  )2;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[184] = (unsigned int  )31;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[186] = (unsigned int  )31;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASTEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASTEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[215] = (unsigned int  )2;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASTEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[216] = (unsigned int  )2;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASTEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASTEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASTEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASTEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASTEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASTEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASTEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASTEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASTEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASTEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASTEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASTEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASTEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASTEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASTEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASTEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASTEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASTEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASTEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASTEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASTEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASTEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASTEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASTEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASTEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASTEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASTEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASTEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[244] = (unsigned int  )21;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASTEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[245] = (unsigned int  )15;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASTEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[246] = (unsigned int  )21;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASTEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[247] = (unsigned int  )15;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_1);
            sqlstm.sqhstl[248] = (unsigned int  )31;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_2);
            sqlstm.sqhstl[249] = (unsigned int  )31;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
            sqlstm.sqhstv[250] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_3);
            sqlstm.sqhstl[250] = (unsigned int  )31;
            sqlstm.sqhsts[250] = (         int  )0;
            sqlstm.sqindv[250] = (         void  *)0;
            sqlstm.sqinds[250] = (         int  )0;
            sqlstm.sqharm[250] = (unsigned int  )0;
            sqlstm.sqadto[250] = (unsigned short )0;
            sqlstm.sqtdso[250] = (unsigned short )0;
            sqlstm.sqhstv[251] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_4);
            sqlstm.sqhstl[251] = (unsigned int  )31;
            sqlstm.sqhsts[251] = (         int  )0;
            sqlstm.sqindv[251] = (         void  *)0;
            sqlstm.sqinds[251] = (         int  )0;
            sqlstm.sqharm[251] = (unsigned int  )0;
            sqlstm.sqadto[251] = (unsigned short )0;
            sqlstm.sqtdso[251] = (unsigned short )0;
            sqlstm.sqhstv[252] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_5);
            sqlstm.sqhstl[252] = (unsigned int  )31;
            sqlstm.sqhsts[252] = (         int  )0;
            sqlstm.sqindv[252] = (         void  *)0;
            sqlstm.sqinds[252] = (         int  )0;
            sqlstm.sqharm[252] = (unsigned int  )0;
            sqlstm.sqadto[252] = (unsigned short )0;
            sqlstm.sqtdso[252] = (unsigned short )0;
            sqlstm.sqhstv[253] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_6);
            sqlstm.sqhstl[253] = (unsigned int  )31;
            sqlstm.sqhsts[253] = (         int  )0;
            sqlstm.sqindv[253] = (         void  *)0;
            sqlstm.sqinds[253] = (         int  )0;
            sqlstm.sqharm[253] = (unsigned int  )0;
            sqlstm.sqadto[253] = (unsigned short )0;
            sqlstm.sqtdso[253] = (unsigned short )0;
            sqlstm.sqhstv[254] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_7);
            sqlstm.sqhstl[254] = (unsigned int  )31;
            sqlstm.sqhsts[254] = (         int  )0;
            sqlstm.sqindv[254] = (         void  *)0;
            sqlstm.sqinds[254] = (         int  )0;
            sqlstm.sqharm[254] = (unsigned int  )0;
            sqlstm.sqadto[254] = (unsigned short )0;
            sqlstm.sqtdso[254] = (unsigned short )0;
            sqlstm.sqhstv[255] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_8);
            sqlstm.sqhstl[255] = (unsigned int  )31;
            sqlstm.sqhsts[255] = (         int  )0;
            sqlstm.sqindv[255] = (         void  *)0;
            sqlstm.sqinds[255] = (         int  )0;
            sqlstm.sqharm[255] = (unsigned int  )0;
            sqlstm.sqadto[255] = (unsigned short )0;
            sqlstm.sqtdso[255] = (unsigned short )0;
            sqlstm.sqhstv[256] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_9);
            sqlstm.sqhstl[256] = (unsigned int  )31;
            sqlstm.sqhsts[256] = (         int  )0;
            sqlstm.sqindv[256] = (         void  *)0;
            sqlstm.sqinds[256] = (         int  )0;
            sqlstm.sqharm[256] = (unsigned int  )0;
            sqlstm.sqadto[256] = (unsigned short )0;
            sqlstm.sqtdso[256] = (unsigned short )0;
            sqlstm.sqhstv[257] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_10);
            sqlstm.sqhstl[257] = (unsigned int  )31;
            sqlstm.sqhsts[257] = (         int  )0;
            sqlstm.sqindv[257] = (         void  *)0;
            sqlstm.sqinds[257] = (         int  )0;
            sqlstm.sqharm[257] = (unsigned int  )0;
            sqlstm.sqadto[257] = (unsigned short )0;
            sqlstm.sqtdso[257] = (unsigned short )0;
            sqlstm.sqhstv[258] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_11);
            sqlstm.sqhstl[258] = (unsigned int  )31;
            sqlstm.sqhsts[258] = (         int  )0;
            sqlstm.sqindv[258] = (         void  *)0;
            sqlstm.sqinds[258] = (         int  )0;
            sqlstm.sqharm[258] = (unsigned int  )0;
            sqlstm.sqadto[258] = (unsigned short )0;
            sqlstm.sqtdso[258] = (unsigned short )0;
            sqlstm.sqhstv[259] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_12);
            sqlstm.sqhstl[259] = (unsigned int  )31;
            sqlstm.sqhsts[259] = (         int  )0;
            sqlstm.sqindv[259] = (         void  *)0;
            sqlstm.sqinds[259] = (         int  )0;
            sqlstm.sqharm[259] = (unsigned int  )0;
            sqlstm.sqadto[259] = (unsigned short )0;
            sqlstm.sqtdso[259] = (unsigned short )0;
            sqlstm.sqhstv[260] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_13);
            sqlstm.sqhstl[260] = (unsigned int  )31;
            sqlstm.sqhsts[260] = (         int  )0;
            sqlstm.sqindv[260] = (         void  *)0;
            sqlstm.sqinds[260] = (         int  )0;
            sqlstm.sqharm[260] = (unsigned int  )0;
            sqlstm.sqadto[260] = (unsigned short )0;
            sqlstm.sqtdso[260] = (unsigned short )0;
            sqlstm.sqhstv[261] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_14);
            sqlstm.sqhstl[261] = (unsigned int  )31;
            sqlstm.sqhsts[261] = (         int  )0;
            sqlstm.sqindv[261] = (         void  *)0;
            sqlstm.sqinds[261] = (         int  )0;
            sqlstm.sqharm[261] = (unsigned int  )0;
            sqlstm.sqadto[261] = (unsigned short )0;
            sqlstm.sqtdso[261] = (unsigned short )0;
            sqlstm.sqhstv[262] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_15);
            sqlstm.sqhstl[262] = (unsigned int  )31;
            sqlstm.sqhsts[262] = (         int  )0;
            sqlstm.sqindv[262] = (         void  *)0;
            sqlstm.sqinds[262] = (         int  )0;
            sqlstm.sqharm[262] = (unsigned int  )0;
            sqlstm.sqadto[262] = (unsigned short )0;
            sqlstm.sqtdso[262] = (unsigned short )0;
            sqlstm.sqhstv[263] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_16);
            sqlstm.sqhstl[263] = (unsigned int  )31;
            sqlstm.sqhsts[263] = (         int  )0;
            sqlstm.sqindv[263] = (         void  *)0;
            sqlstm.sqinds[263] = (         int  )0;
            sqlstm.sqharm[263] = (unsigned int  )0;
            sqlstm.sqadto[263] = (unsigned short )0;
            sqlstm.sqtdso[263] = (unsigned short )0;
            sqlstm.sqhstv[264] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_17);
            sqlstm.sqhstl[264] = (unsigned int  )31;
            sqlstm.sqhsts[264] = (         int  )0;
            sqlstm.sqindv[264] = (         void  *)0;
            sqlstm.sqinds[264] = (         int  )0;
            sqlstm.sqharm[264] = (unsigned int  )0;
            sqlstm.sqadto[264] = (unsigned short )0;
            sqlstm.sqtdso[264] = (unsigned short )0;
            sqlstm.sqhstv[265] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_18);
            sqlstm.sqhstl[265] = (unsigned int  )31;
            sqlstm.sqhsts[265] = (         int  )0;
            sqlstm.sqindv[265] = (         void  *)0;
            sqlstm.sqinds[265] = (         int  )0;
            sqlstm.sqharm[265] = (unsigned int  )0;
            sqlstm.sqadto[265] = (unsigned short )0;
            sqlstm.sqtdso[265] = (unsigned short )0;
            sqlstm.sqhstv[266] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_19);
            sqlstm.sqhstl[266] = (unsigned int  )31;
            sqlstm.sqhsts[266] = (         int  )0;
            sqlstm.sqindv[266] = (         void  *)0;
            sqlstm.sqinds[266] = (         int  )0;
            sqlstm.sqharm[266] = (unsigned int  )0;
            sqlstm.sqadto[266] = (unsigned short )0;
            sqlstm.sqtdso[266] = (unsigned short )0;
            sqlstm.sqhstv[267] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_20);
            sqlstm.sqhstl[267] = (unsigned int  )31;
            sqlstm.sqhsts[267] = (         int  )0;
            sqlstm.sqindv[267] = (         void  *)0;
            sqlstm.sqinds[267] = (         int  )0;
            sqlstm.sqharm[267] = (unsigned int  )0;
            sqlstm.sqadto[267] = (unsigned short )0;
            sqlstm.sqtdso[267] = (unsigned short )0;
            sqlstm.sqhstv[268] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_21);
            sqlstm.sqhstl[268] = (unsigned int  )31;
            sqlstm.sqhsts[268] = (         int  )0;
            sqlstm.sqindv[268] = (         void  *)0;
            sqlstm.sqinds[268] = (         int  )0;
            sqlstm.sqharm[268] = (unsigned int  )0;
            sqlstm.sqadto[268] = (unsigned short )0;
            sqlstm.sqtdso[268] = (unsigned short )0;
            sqlstm.sqhstv[269] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_22);
            sqlstm.sqhstl[269] = (unsigned int  )31;
            sqlstm.sqhsts[269] = (         int  )0;
            sqlstm.sqindv[269] = (         void  *)0;
            sqlstm.sqinds[269] = (         int  )0;
            sqlstm.sqharm[269] = (unsigned int  )0;
            sqlstm.sqadto[269] = (unsigned short )0;
            sqlstm.sqtdso[269] = (unsigned short )0;
            sqlstm.sqhstv[270] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_23);
            sqlstm.sqhstl[270] = (unsigned int  )31;
            sqlstm.sqhsts[270] = (         int  )0;
            sqlstm.sqindv[270] = (         void  *)0;
            sqlstm.sqinds[270] = (         int  )0;
            sqlstm.sqharm[270] = (unsigned int  )0;
            sqlstm.sqadto[270] = (unsigned short )0;
            sqlstm.sqtdso[270] = (unsigned short )0;
            sqlstm.sqhstv[271] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_24);
            sqlstm.sqhstl[271] = (unsigned int  )31;
            sqlstm.sqhsts[271] = (         int  )0;
            sqlstm.sqindv[271] = (         void  *)0;
            sqlstm.sqinds[271] = (         int  )0;
            sqlstm.sqharm[271] = (unsigned int  )0;
            sqlstm.sqadto[271] = (unsigned short )0;
            sqlstm.sqtdso[271] = (unsigned short )0;
            sqlstm.sqhstv[272] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_25);
            sqlstm.sqhstl[272] = (unsigned int  )31;
            sqlstm.sqhsts[272] = (         int  )0;
            sqlstm.sqindv[272] = (         void  *)0;
            sqlstm.sqinds[272] = (         int  )0;
            sqlstm.sqharm[272] = (unsigned int  )0;
            sqlstm.sqadto[272] = (unsigned short )0;
            sqlstm.sqtdso[272] = (unsigned short )0;
            sqlstm.sqhstv[273] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_26);
            sqlstm.sqhstl[273] = (unsigned int  )31;
            sqlstm.sqhsts[273] = (         int  )0;
            sqlstm.sqindv[273] = (         void  *)0;
            sqlstm.sqinds[273] = (         int  )0;
            sqlstm.sqharm[273] = (unsigned int  )0;
            sqlstm.sqadto[273] = (unsigned short )0;
            sqlstm.sqtdso[273] = (unsigned short )0;
            sqlstm.sqhstv[274] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_27);
            sqlstm.sqhstl[274] = (unsigned int  )31;
            sqlstm.sqhsts[274] = (         int  )0;
            sqlstm.sqindv[274] = (         void  *)0;
            sqlstm.sqinds[274] = (         int  )0;
            sqlstm.sqharm[274] = (unsigned int  )0;
            sqlstm.sqadto[274] = (unsigned short )0;
            sqlstm.sqtdso[274] = (unsigned short )0;
            sqlstm.sqhstv[275] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_28);
            sqlstm.sqhstl[275] = (unsigned int  )31;
            sqlstm.sqhsts[275] = (         int  )0;
            sqlstm.sqindv[275] = (         void  *)0;
            sqlstm.sqinds[275] = (         int  )0;
            sqlstm.sqharm[275] = (unsigned int  )0;
            sqlstm.sqadto[275] = (unsigned short )0;
            sqlstm.sqtdso[275] = (unsigned short )0;
            sqlstm.sqhstv[276] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_29);
            sqlstm.sqhstl[276] = (unsigned int  )31;
            sqlstm.sqhsts[276] = (         int  )0;
            sqlstm.sqindv[276] = (         void  *)0;
            sqlstm.sqinds[276] = (         int  )0;
            sqlstm.sqharm[276] = (unsigned int  )0;
            sqlstm.sqadto[276] = (unsigned short )0;
            sqlstm.sqtdso[276] = (unsigned short )0;
            sqlstm.sqhstv[277] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_30);
            sqlstm.sqhstl[277] = (unsigned int  )31;
            sqlstm.sqhsts[277] = (         int  )0;
            sqlstm.sqindv[277] = (         void  *)0;
            sqlstm.sqinds[277] = (         int  )0;
            sqlstm.sqharm[277] = (unsigned int  )0;
            sqlstm.sqadto[277] = (unsigned short )0;
            sqlstm.sqtdso[277] = (unsigned short )0;
            sqlstm.sqhstv[278] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[278] = (unsigned int  )11;
            sqlstm.sqhsts[278] = (         int  )0;
            sqlstm.sqindv[278] = (         void  *)0;
            sqlstm.sqinds[278] = (         int  )0;
            sqlstm.sqharm[278] = (unsigned int  )0;
            sqlstm.sqadto[278] = (unsigned short )0;
            sqlstm.sqtdso[278] = (unsigned short )0;
            sqlstm.sqhstv[279] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[279] = (unsigned int  )21;
            sqlstm.sqhsts[279] = (         int  )0;
            sqlstm.sqindv[279] = (         void  *)0;
            sqlstm.sqinds[279] = (         int  )0;
            sqlstm.sqharm[279] = (unsigned int  )0;
            sqlstm.sqadto[279] = (unsigned short )0;
            sqlstm.sqtdso[279] = (unsigned short )0;
            sqlstm.sqhstv[280] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[280] = (unsigned int  )13;
            sqlstm.sqhsts[280] = (         int  )0;
            sqlstm.sqindv[280] = (         void  *)0;
            sqlstm.sqinds[280] = (         int  )0;
            sqlstm.sqharm[280] = (unsigned int  )0;
            sqlstm.sqadto[280] = (unsigned short )0;
            sqlstm.sqtdso[280] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_mrastevdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_mrastevdef(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MRASTEVDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TOOL_EVENT_DESC,
                    SYSTEM_FLAG,
                    COLLECT_DEFECT_FLAG,
                    CLEAN_DEFECT_FLAG,
                    CHK_ITEM_1,
                    CHK_ITEM_2,
                    CHK_ITEM_3,
                    CHK_ITEM_4,
                    CHK_ITEM_5,
                    CHK_ITEM_6,
                    CHK_ITEM_7,
                    CHK_ITEM_8,
                    CHK_ITEM_9,
                    CHK_ITEM_10,
                    CHK_ITEM_11,
                    CHK_ITEM_12,
                    CHK_ITEM_13,
                    CHK_ITEM_14,
                    CHK_ITEM_15,
                    CHK_ITEM_16,
                    CHK_ITEM_17,
                    CHK_ITEM_18,
                    CHK_ITEM_19,
                    CHK_ITEM_20,
                    CHK_ITEM_21,
                    CHK_ITEM_22,
                    CHK_ITEM_23,
                    CHK_ITEM_24,
                    CHK_ITEM_25,
                    CHK_ITEM_26,
                    CHK_ITEM_27,
                    CHK_ITEM_28,
                    CHK_ITEM_29,
                    CHK_ITEM_30,
                    CHK_FLAG_1,
                    CHK_FLAG_2,
                    CHK_FLAG_3,
                    CHK_FLAG_4,
                    CHK_FLAG_5,
                    CHK_FLAG_6,
                    CHK_FLAG_7,
                    CHK_FLAG_8,
                    CHK_FLAG_9,
                    CHK_FLAG_10,
                    CHK_FLAG_11,
                    CHK_FLAG_12,
                    CHK_FLAG_13,
                    CHK_FLAG_14,
                    CHK_FLAG_15,
                    CHK_FLAG_16,
                    CHK_FLAG_17,
                    CHK_FLAG_18,
                    CHK_FLAG_19,
                    CHK_FLAG_20,
                    CHK_FLAG_21,
                    CHK_FLAG_22,
                    CHK_FLAG_23,
                    CHK_FLAG_24,
                    CHK_FLAG_25,
                    CHK_FLAG_26,
                    CHK_FLAG_27,
                    CHK_FLAG_28,
                    CHK_FLAG_29,
                    CHK_FLAG_30,
                    CHK_VALUE_1,
                    CHK_VALUE_2,
                    CHK_VALUE_3,
                    CHK_VALUE_4,
                    CHK_VALUE_5,
                    CHK_VALUE_6,
                    CHK_VALUE_7,
                    CHK_VALUE_8,
                    CHK_VALUE_9,
                    CHK_VALUE_10,
                    CHK_VALUE_11,
                    CHK_VALUE_12,
                    CHK_VALUE_13,
                    CHK_VALUE_14,
                    CHK_VALUE_15,
                    CHK_VALUE_16,
                    CHK_VALUE_17,
                    CHK_VALUE_18,
                    CHK_VALUE_19,
                    CHK_VALUE_20,
                    CHK_VALUE_21,
                    CHK_VALUE_22,
                    CHK_VALUE_23,
                    CHK_VALUE_24,
                    CHK_VALUE_25,
                    CHK_VALUE_26,
                    CHK_VALUE_27,
                    CHK_VALUE_28,
                    CHK_VALUE_29,
                    CHK_VALUE_30,
                    CHK_FIELD_1,
                    CHK_FIELD_2,
                    CHK_FIELD_3,
                    CHK_FIELD_4,
                    CHK_FIELD_5,
                    CHK_FIELD_6,
                    CHK_FIELD_7,
                    CHK_FIELD_8,
                    CHK_FIELD_9,
                    CHK_FIELD_10,
                    CHK_FIELD_11,
                    CHK_FIELD_12,
                    CHK_FIELD_13,
                    CHK_FIELD_14,
                    CHK_FIELD_15,
                    CHK_FIELD_16,
                    CHK_FIELD_17,
                    CHK_FIELD_18,
                    CHK_FIELD_19,
                    CHK_FIELD_20,
                    CHK_FIELD_21,
                    CHK_FIELD_22,
                    CHK_FIELD_23,
                    CHK_FIELD_24,
                    CHK_FIELD_25,
                    CHK_FIELD_26,
                    CHK_FIELD_27,
                    CHK_FIELD_28,
                    CHK_FIELD_29,
                    CHK_FIELD_30,
                    CHG_ITEM_1,
                    CHG_ITEM_2,
                    CHG_ITEM_3,
                    CHG_ITEM_4,
                    CHG_ITEM_5,
                    CHG_ITEM_6,
                    CHG_ITEM_7,
                    CHG_ITEM_8,
                    CHG_ITEM_9,
                    CHG_ITEM_10,
                    CHG_ITEM_11,
                    CHG_ITEM_12,
                    CHG_ITEM_13,
                    CHG_ITEM_14,
                    CHG_ITEM_15,
                    CHG_ITEM_16,
                    CHG_ITEM_17,
                    CHG_ITEM_18,
                    CHG_ITEM_19,
                    CHG_ITEM_20,
                    CHG_ITEM_21,
                    CHG_ITEM_22,
                    CHG_ITEM_23,
                    CHG_ITEM_24,
                    CHG_ITEM_25,
                    CHG_ITEM_26,
                    CHG_ITEM_27,
                    CHG_ITEM_28,
                    CHG_ITEM_29,
                    CHG_ITEM_30,
                    CHG_FLAG_1,
                    CHG_FLAG_2,
                    CHG_FLAG_3,
                    CHG_FLAG_4,
                    CHG_FLAG_5,
                    CHG_FLAG_6,
                    CHG_FLAG_7,
                    CHG_FLAG_8,
                    CHG_FLAG_9,
                    CHG_FLAG_10,
                    CHG_FLAG_11,
                    CHG_FLAG_12,
                    CHG_FLAG_13,
                    CHG_FLAG_14,
                    CHG_FLAG_15,
                    CHG_FLAG_16,
                    CHG_FLAG_17,
                    CHG_FLAG_18,
                    CHG_FLAG_19,
                    CHG_FLAG_20,
                    CHG_FLAG_21,
                    CHG_FLAG_22,
                    CHG_FLAG_23,
                    CHG_FLAG_24,
                    CHG_FLAG_25,
                    CHG_FLAG_26,
                    CHG_FLAG_27,
                    CHG_FLAG_28,
                    CHG_FLAG_29,
                    CHG_FLAG_30,
                    CHG_VALUE_1,
                    CHG_VALUE_2,
                    CHG_VALUE_3,
                    CHG_VALUE_4,
                    CHG_VALUE_5,
                    CHG_VALUE_6,
                    CHG_VALUE_7,
                    CHG_VALUE_8,
                    CHG_VALUE_9,
                    CHG_VALUE_10,
                    CHG_VALUE_11,
                    CHG_VALUE_12,
                    CHG_VALUE_13,
                    CHG_VALUE_14,
                    CHG_VALUE_15,
                    CHG_VALUE_16,
                    CHG_VALUE_17,
                    CHG_VALUE_18,
                    CHG_VALUE_19,
                    CHG_VALUE_20,
                    CHG_VALUE_21,
                    CHG_VALUE_22,
                    CHG_VALUE_23,
                    CHG_VALUE_24,
                    CHG_VALUE_25,
                    CHG_VALUE_26,
                    CHG_VALUE_27,
                    CHG_VALUE_28,
                    CHG_VALUE_29,
                    CHG_VALUE_30,
                    CHG_OPT_1,
                    CHG_OPT_2,
                    CHG_OPT_3,
                    CHG_OPT_4,
                    CHG_OPT_5,
                    CHG_OPT_6,
                    CHG_OPT_7,
                    CHG_OPT_8,
                    CHG_OPT_9,
                    CHG_OPT_10,
                    CHG_OPT_11,
                    CHG_OPT_12,
                    CHG_OPT_13,
                    CHG_OPT_14,
                    CHG_OPT_15,
                    CHG_OPT_16,
                    CHG_OPT_17,
                    CHG_OPT_18,
                    CHG_OPT_19,
                    CHG_OPT_20,
                    CHG_OPT_21,
                    CHG_OPT_22,
                    CHG_OPT_23,
                    CHG_OPT_24,
                    CHG_OPT_25,
                    CHG_OPT_26,
                    CHG_OPT_27,
                    CHG_OPT_28,
                    CHG_OPT_29,
                    CHG_OPT_30,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CHG_FIELD_1,
                    CHG_FIELD_2,
                    CHG_FIELD_3,
                    CHG_FIELD_4,
                    CHG_FIELD_5,
                    CHG_FIELD_6,
                    CHG_FIELD_7,
                    CHG_FIELD_8,
                    CHG_FIELD_9,
                    CHG_FIELD_10,
                    CHG_FIELD_11,
                    CHG_FIELD_12,
                    CHG_FIELD_13,
                    CHG_FIELD_14,
                    CHG_FIELD_15,
                    CHG_FIELD_16,
                    CHG_FIELD_17,
                    CHG_FIELD_18,
                    CHG_FIELD_19,
                    CHG_FIELD_20,
                    CHG_FIELD_21,
                    CHG_FIELD_22,
                    CHG_FIELD_23,
                    CHG_FIELD_24,
                    CHG_FIELD_25,
                    CHG_FIELD_26,
                    CHG_FIELD_27,
                    CHG_FIELD_28,
                    CHG_FIELD_29,
                    CHG_FIELD_30
                FROM MRASTEVDEF
                ORDER BY FACTORY ASC,
                    TOOL_TYPE ASC,
                    TOOL_EVENT_ID ASC; */ 

            /* EXEC SQL OPEN DBU_MRASTEVDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_TYPE ,TOOL_EVENT_ID ,TOOL_EVENT_DESC ,SY\
STEM_FLAG ,COLLECT_DEFECT_FLAG ,CLEAN_DEFECT_FLAG ,CHK_ITEM_1 ,CHK_ITEM_2 ,C\
HK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_ITEM_7 ,CHK_ITEM_8 ,CHK_I\
TEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITEM_13 ,CHK_ITEM_14 ,CHK_\
ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_ITEM_19 ,CHK_ITEM_20 ,CH\
K_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK_ITEM_25 ,CHK_ITEM_26 ,\
CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,CHK_FLAG_1 ,CHK_FLAG_2 ,\
CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_FLAG_7 ,CHK_FLAG_8 ,CHK_\
FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FLAG_13 ,CHK_FLAG_14 ,CHK\
_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_FLAG_19 ,CHK_FLAG_20 ,C\
HK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CHK_FLAG_25 ,CHK_FLAG_26 \
,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,CHK_VALUE_1 ,CHK_VALUE_\
2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6 ,CHK_VALUE_7 ,CHK_VALU\
E_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_V");
            sqlbuft((void **)0,
              "ALUE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CHK_VALUE_\
16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VALUE_20 ,CHK_VALUE_21 ,CH\
K_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 ,CHK_VALUE_26 ,CHK_VALU\
E_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_FIELD_1 ,CHK_FIELD_2 ,CH\
K_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK_FIELD_7 ,CHK_FIELD_8 ,\
CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12 ,CHK_FIELD_13 ,CHK_FIE\
LD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_FIELD_18 ,CHK_FIELD_19 \
,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_23 ,CHK_FIELD_24 ,CHK_F\
IELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CHK_FIELD_29 ,CHK_FIELD_3\
0 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CHG_ITEM_5 ,CHG_ITEM_6 ,C\
HG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_ITEM_11 ,CHG_ITEM_12 ,CH\
G_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG_ITEM_17 ,CHG_ITEM_18 ,\
CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,CHG_ITEM_23 ,CHG_ITEM_24\
 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_2");
            sqlbuft((void **)0,
              "8 ,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,CHG_FLAG\
_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,CHG_FLAG_8 ,CHG_FLAG_9 ,\
CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,CHG_FLAG_14 ,CHG_FLAG_15\
 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 ,CHG_FLAG_20 ,CHG_FLAG_\
21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_25 ,CHG_FLAG_26 ,CHG_FLA\
G_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALUE_1 ,CHG_VALUE_2 ,CHG_V\
ALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VALUE_7 ,CHG_VALUE_8 ,CHG\
_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,CHG_VALUE_13 ,CHG_VALUE_\
14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VALUE_18 ,CHG_VALUE_19 ,CH\
G_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 ,CHG_VALUE_24 ,CHG_VALU\
E_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_VALUE_29 ,CHG_VALUE_30 ,\
CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5 ,CHG_OPT_6 ,CHG_OPT_7 \
,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OPT_12 ,CHG_OPT_13 ,CHG_O\
PT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_");
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4643;
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
            /* EXEC SQL DECLARE DBU_MRASTEVDEF_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    TOOL_TYPE,
                    TOOL_EVENT_ID,
                    TOOL_EVENT_DESC,
                    SYSTEM_FLAG,
                    COLLECT_DEFECT_FLAG,
                    CLEAN_DEFECT_FLAG,
                    CHK_ITEM_1,
                    CHK_ITEM_2,
                    CHK_ITEM_3,
                    CHK_ITEM_4,
                    CHK_ITEM_5,
                    CHK_ITEM_6,
                    CHK_ITEM_7,
                    CHK_ITEM_8,
                    CHK_ITEM_9,
                    CHK_ITEM_10,
                    CHK_ITEM_11,
                    CHK_ITEM_12,
                    CHK_ITEM_13,
                    CHK_ITEM_14,
                    CHK_ITEM_15,
                    CHK_ITEM_16,
                    CHK_ITEM_17,
                    CHK_ITEM_18,
                    CHK_ITEM_19,
                    CHK_ITEM_20,
                    CHK_ITEM_21,
                    CHK_ITEM_22,
                    CHK_ITEM_23,
                    CHK_ITEM_24,
                    CHK_ITEM_25,
                    CHK_ITEM_26,
                    CHK_ITEM_27,
                    CHK_ITEM_28,
                    CHK_ITEM_29,
                    CHK_ITEM_30,
                    CHK_FLAG_1,
                    CHK_FLAG_2,
                    CHK_FLAG_3,
                    CHK_FLAG_4,
                    CHK_FLAG_5,
                    CHK_FLAG_6,
                    CHK_FLAG_7,
                    CHK_FLAG_8,
                    CHK_FLAG_9,
                    CHK_FLAG_10,
                    CHK_FLAG_11,
                    CHK_FLAG_12,
                    CHK_FLAG_13,
                    CHK_FLAG_14,
                    CHK_FLAG_15,
                    CHK_FLAG_16,
                    CHK_FLAG_17,
                    CHK_FLAG_18,
                    CHK_FLAG_19,
                    CHK_FLAG_20,
                    CHK_FLAG_21,
                    CHK_FLAG_22,
                    CHK_FLAG_23,
                    CHK_FLAG_24,
                    CHK_FLAG_25,
                    CHK_FLAG_26,
                    CHK_FLAG_27,
                    CHK_FLAG_28,
                    CHK_FLAG_29,
                    CHK_FLAG_30,
                    CHK_VALUE_1,
                    CHK_VALUE_2,
                    CHK_VALUE_3,
                    CHK_VALUE_4,
                    CHK_VALUE_5,
                    CHK_VALUE_6,
                    CHK_VALUE_7,
                    CHK_VALUE_8,
                    CHK_VALUE_9,
                    CHK_VALUE_10,
                    CHK_VALUE_11,
                    CHK_VALUE_12,
                    CHK_VALUE_13,
                    CHK_VALUE_14,
                    CHK_VALUE_15,
                    CHK_VALUE_16,
                    CHK_VALUE_17,
                    CHK_VALUE_18,
                    CHK_VALUE_19,
                    CHK_VALUE_20,
                    CHK_VALUE_21,
                    CHK_VALUE_22,
                    CHK_VALUE_23,
                    CHK_VALUE_24,
                    CHK_VALUE_25,
                    CHK_VALUE_26,
                    CHK_VALUE_27,
                    CHK_VALUE_28,
                    CHK_VALUE_29,
                    CHK_VALUE_30,
                    CHK_FIELD_1,
                    CHK_FIELD_2,
                    CHK_FIELD_3,
                    CHK_FIELD_4,
                    CHK_FIELD_5,
                    CHK_FIELD_6,
                    CHK_FIELD_7,
                    CHK_FIELD_8,
                    CHK_FIELD_9,
                    CHK_FIELD_10,
                    CHK_FIELD_11,
                    CHK_FIELD_12,
                    CHK_FIELD_13,
                    CHK_FIELD_14,
                    CHK_FIELD_15,
                    CHK_FIELD_16,
                    CHK_FIELD_17,
                    CHK_FIELD_18,
                    CHK_FIELD_19,
                    CHK_FIELD_20,
                    CHK_FIELD_21,
                    CHK_FIELD_22,
                    CHK_FIELD_23,
                    CHK_FIELD_24,
                    CHK_FIELD_25,
                    CHK_FIELD_26,
                    CHK_FIELD_27,
                    CHK_FIELD_28,
                    CHK_FIELD_29,
                    CHK_FIELD_30,
                    CHG_ITEM_1,
                    CHG_ITEM_2,
                    CHG_ITEM_3,
                    CHG_ITEM_4,
                    CHG_ITEM_5,
                    CHG_ITEM_6,
                    CHG_ITEM_7,
                    CHG_ITEM_8,
                    CHG_ITEM_9,
                    CHG_ITEM_10,
                    CHG_ITEM_11,
                    CHG_ITEM_12,
                    CHG_ITEM_13,
                    CHG_ITEM_14,
                    CHG_ITEM_15,
                    CHG_ITEM_16,
                    CHG_ITEM_17,
                    CHG_ITEM_18,
                    CHG_ITEM_19,
                    CHG_ITEM_20,
                    CHG_ITEM_21,
                    CHG_ITEM_22,
                    CHG_ITEM_23,
                    CHG_ITEM_24,
                    CHG_ITEM_25,
                    CHG_ITEM_26,
                    CHG_ITEM_27,
                    CHG_ITEM_28,
                    CHG_ITEM_29,
                    CHG_ITEM_30,
                    CHG_FLAG_1,
                    CHG_FLAG_2,
                    CHG_FLAG_3,
                    CHG_FLAG_4,
                    CHG_FLAG_5,
                    CHG_FLAG_6,
                    CHG_FLAG_7,
                    CHG_FLAG_8,
                    CHG_FLAG_9,
                    CHG_FLAG_10,
                    CHG_FLAG_11,
                    CHG_FLAG_12,
                    CHG_FLAG_13,
                    CHG_FLAG_14,
                    CHG_FLAG_15,
                    CHG_FLAG_16,
                    CHG_FLAG_17,
                    CHG_FLAG_18,
                    CHG_FLAG_19,
                    CHG_FLAG_20,
                    CHG_FLAG_21,
                    CHG_FLAG_22,
                    CHG_FLAG_23,
                    CHG_FLAG_24,
                    CHG_FLAG_25,
                    CHG_FLAG_26,
                    CHG_FLAG_27,
                    CHG_FLAG_28,
                    CHG_FLAG_29,
                    CHG_FLAG_30,
                    CHG_VALUE_1,
                    CHG_VALUE_2,
                    CHG_VALUE_3,
                    CHG_VALUE_4,
                    CHG_VALUE_5,
                    CHG_VALUE_6,
                    CHG_VALUE_7,
                    CHG_VALUE_8,
                    CHG_VALUE_9,
                    CHG_VALUE_10,
                    CHG_VALUE_11,
                    CHG_VALUE_12,
                    CHG_VALUE_13,
                    CHG_VALUE_14,
                    CHG_VALUE_15,
                    CHG_VALUE_16,
                    CHG_VALUE_17,
                    CHG_VALUE_18,
                    CHG_VALUE_19,
                    CHG_VALUE_20,
                    CHG_VALUE_21,
                    CHG_VALUE_22,
                    CHG_VALUE_23,
                    CHG_VALUE_24,
                    CHG_VALUE_25,
                    CHG_VALUE_26,
                    CHG_VALUE_27,
                    CHG_VALUE_28,
                    CHG_VALUE_29,
                    CHG_VALUE_30,
                    CHG_OPT_1,
                    CHG_OPT_2,
                    CHG_OPT_3,
                    CHG_OPT_4,
                    CHG_OPT_5,
                    CHG_OPT_6,
                    CHG_OPT_7,
                    CHG_OPT_8,
                    CHG_OPT_9,
                    CHG_OPT_10,
                    CHG_OPT_11,
                    CHG_OPT_12,
                    CHG_OPT_13,
                    CHG_OPT_14,
                    CHG_OPT_15,
                    CHG_OPT_16,
                    CHG_OPT_17,
                    CHG_OPT_18,
                    CHG_OPT_19,
                    CHG_OPT_20,
                    CHG_OPT_21,
                    CHG_OPT_22,
                    CHG_OPT_23,
                    CHG_OPT_24,
                    CHG_OPT_25,
                    CHG_OPT_26,
                    CHG_OPT_27,
                    CHG_OPT_28,
                    CHG_OPT_29,
                    CHG_OPT_30,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    CHG_FIELD_1,
                    CHG_FIELD_2,
                    CHG_FIELD_3,
                    CHG_FIELD_4,
                    CHG_FIELD_5,
                    CHG_FIELD_6,
                    CHG_FIELD_7,
                    CHG_FIELD_8,
                    CHG_FIELD_9,
                    CHG_FIELD_10,
                    CHG_FIELD_11,
                    CHG_FIELD_12,
                    CHG_FIELD_13,
                    CHG_FIELD_14,
                    CHG_FIELD_15,
                    CHG_FIELD_16,
                    CHG_FIELD_17,
                    CHG_FIELD_18,
                    CHG_FIELD_19,
                    CHG_FIELD_20,
                    CHG_FIELD_21,
                    CHG_FIELD_22,
                    CHG_FIELD_23,
                    CHG_FIELD_24,
                    CHG_FIELD_25,
                    CHG_FIELD_26,
                    CHG_FIELD_27,
                    CHG_FIELD_28,
                    CHG_FIELD_29,
                    CHG_FIELD_30
                FROM MRASTEVDEF
                WHERE FACTORY = :MRASTEVDEF_N.FACTORY
                    AND TOOL_TYPE = :MRASTEVDEF_N.TOOL_TYPE
                    AND SYSTEM_FLAG<>'Y'
                ORDER BY TOOL_EVENT_ID ASC; */ 

            /* EXEC SQL OPEN DBU_MRASTEVDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,TOOL_TYPE ,TOOL_EVENT_ID ,TOOL_EVENT_DESC ,SY\
STEM_FLAG ,COLLECT_DEFECT_FLAG ,CLEAN_DEFECT_FLAG ,CHK_ITEM_1 ,CHK_ITEM_2 ,C\
HK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_ITEM_7 ,CHK_ITEM_8 ,CHK_I\
TEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITEM_13 ,CHK_ITEM_14 ,CHK_\
ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_ITEM_19 ,CHK_ITEM_20 ,CH\
K_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK_ITEM_25 ,CHK_ITEM_26 ,\
CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,CHK_FLAG_1 ,CHK_FLAG_2 ,\
CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_FLAG_7 ,CHK_FLAG_8 ,CHK_\
FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FLAG_13 ,CHK_FLAG_14 ,CHK\
_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_FLAG_19 ,CHK_FLAG_20 ,C\
HK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CHK_FLAG_25 ,CHK_FLAG_26 \
,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,CHK_VALUE_1 ,CHK_VALUE_\
2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6 ,CHK_VALUE_7 ,CHK_VALU\
E_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_V");
            sqlbuft((void **)0,
              "ALUE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CHK_VALUE_\
16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VALUE_20 ,CHK_VALUE_21 ,CH\
K_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 ,CHK_VALUE_26 ,CHK_VALU\
E_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_FIELD_1 ,CHK_FIELD_2 ,CH\
K_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK_FIELD_7 ,CHK_FIELD_8 ,\
CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12 ,CHK_FIELD_13 ,CHK_FIE\
LD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_FIELD_18 ,CHK_FIELD_19 \
,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_23 ,CHK_FIELD_24 ,CHK_F\
IELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CHK_FIELD_29 ,CHK_FIELD_3\
0 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CHG_ITEM_5 ,CHG_ITEM_6 ,C\
HG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_ITEM_11 ,CHG_ITEM_12 ,CH\
G_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG_ITEM_17 ,CHG_ITEM_18 ,\
CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,CHG_ITEM_23 ,CHG_ITEM_24\
 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_2");
            sqlbuft((void **)0,
              "8 ,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,CHG_FLAG\
_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,CHG_FLAG_8 ,CHG_FLAG_9 ,\
CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,CHG_FLAG_14 ,CHG_FLAG_15\
 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 ,CHG_FLAG_20 ,CHG_FLAG_\
21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_25 ,CHG_FLAG_26 ,CHG_FLA\
G_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALUE_1 ,CHG_VALUE_2 ,CHG_V\
ALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VALUE_7 ,CHG_VALUE_8 ,CHG\
_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,CHG_VALUE_13 ,CHG_VALUE_\
14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VALUE_18 ,CHG_VALUE_19 ,CH\
G_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 ,CHG_VALUE_24 ,CHG_VALU\
E_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_VALUE_29 ,CHG_VALUE_30 ,\
CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5 ,CHG_OPT_6 ,CHG_OPT_7 \
,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OPT_12 ,CHG_OPT_13 ,CHG_O\
PT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_");
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4658;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_mrastevdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_mrastevdef(int sel_type, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASTEVDEF_N_TAG MRASTEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MRASTEVDEF_CUR_1 INTO
                :MRASTEVDEF_N.FACTORY,
                :MRASTEVDEF_N.TOOL_TYPE,
                :MRASTEVDEF_N.TOOL_EVENT_ID,
                :MRASTEVDEF_N.TOOL_EVENT_DESC,
                :MRASTEVDEF_N.SYSTEM_FLAG,
                :MRASTEVDEF_N.COLLECT_DEFECT_FLAG,
                :MRASTEVDEF_N.CLEAN_DEFECT_FLAG,
                :MRASTEVDEF_N.CHK_ITEM_1,
                :MRASTEVDEF_N.CHK_ITEM_2,
                :MRASTEVDEF_N.CHK_ITEM_3,
                :MRASTEVDEF_N.CHK_ITEM_4,
                :MRASTEVDEF_N.CHK_ITEM_5,
                :MRASTEVDEF_N.CHK_ITEM_6,
                :MRASTEVDEF_N.CHK_ITEM_7,
                :MRASTEVDEF_N.CHK_ITEM_8,
                :MRASTEVDEF_N.CHK_ITEM_9,
                :MRASTEVDEF_N.CHK_ITEM_10,
                :MRASTEVDEF_N.CHK_ITEM_11,
                :MRASTEVDEF_N.CHK_ITEM_12,
                :MRASTEVDEF_N.CHK_ITEM_13,
                :MRASTEVDEF_N.CHK_ITEM_14,
                :MRASTEVDEF_N.CHK_ITEM_15,
                :MRASTEVDEF_N.CHK_ITEM_16,
                :MRASTEVDEF_N.CHK_ITEM_17,
                :MRASTEVDEF_N.CHK_ITEM_18,
                :MRASTEVDEF_N.CHK_ITEM_19,
                :MRASTEVDEF_N.CHK_ITEM_20,
                :MRASTEVDEF_N.CHK_ITEM_21,
                :MRASTEVDEF_N.CHK_ITEM_22,
                :MRASTEVDEF_N.CHK_ITEM_23,
                :MRASTEVDEF_N.CHK_ITEM_24,
                :MRASTEVDEF_N.CHK_ITEM_25,
                :MRASTEVDEF_N.CHK_ITEM_26,
                :MRASTEVDEF_N.CHK_ITEM_27,
                :MRASTEVDEF_N.CHK_ITEM_28,
                :MRASTEVDEF_N.CHK_ITEM_29,
                :MRASTEVDEF_N.CHK_ITEM_30,
                :MRASTEVDEF_N.CHK_FLAG_1,
                :MRASTEVDEF_N.CHK_FLAG_2,
                :MRASTEVDEF_N.CHK_FLAG_3,
                :MRASTEVDEF_N.CHK_FLAG_4,
                :MRASTEVDEF_N.CHK_FLAG_5,
                :MRASTEVDEF_N.CHK_FLAG_6,
                :MRASTEVDEF_N.CHK_FLAG_7,
                :MRASTEVDEF_N.CHK_FLAG_8,
                :MRASTEVDEF_N.CHK_FLAG_9,
                :MRASTEVDEF_N.CHK_FLAG_10,
                :MRASTEVDEF_N.CHK_FLAG_11,
                :MRASTEVDEF_N.CHK_FLAG_12,
                :MRASTEVDEF_N.CHK_FLAG_13,
                :MRASTEVDEF_N.CHK_FLAG_14,
                :MRASTEVDEF_N.CHK_FLAG_15,
                :MRASTEVDEF_N.CHK_FLAG_16,
                :MRASTEVDEF_N.CHK_FLAG_17,
                :MRASTEVDEF_N.CHK_FLAG_18,
                :MRASTEVDEF_N.CHK_FLAG_19,
                :MRASTEVDEF_N.CHK_FLAG_20,
                :MRASTEVDEF_N.CHK_FLAG_21,
                :MRASTEVDEF_N.CHK_FLAG_22,
                :MRASTEVDEF_N.CHK_FLAG_23,
                :MRASTEVDEF_N.CHK_FLAG_24,
                :MRASTEVDEF_N.CHK_FLAG_25,
                :MRASTEVDEF_N.CHK_FLAG_26,
                :MRASTEVDEF_N.CHK_FLAG_27,
                :MRASTEVDEF_N.CHK_FLAG_28,
                :MRASTEVDEF_N.CHK_FLAG_29,
                :MRASTEVDEF_N.CHK_FLAG_30,
                :MRASTEVDEF_N.CHK_VALUE_1,
                :MRASTEVDEF_N.CHK_VALUE_2,
                :MRASTEVDEF_N.CHK_VALUE_3,
                :MRASTEVDEF_N.CHK_VALUE_4,
                :MRASTEVDEF_N.CHK_VALUE_5,
                :MRASTEVDEF_N.CHK_VALUE_6,
                :MRASTEVDEF_N.CHK_VALUE_7,
                :MRASTEVDEF_N.CHK_VALUE_8,
                :MRASTEVDEF_N.CHK_VALUE_9,
                :MRASTEVDEF_N.CHK_VALUE_10,
                :MRASTEVDEF_N.CHK_VALUE_11,
                :MRASTEVDEF_N.CHK_VALUE_12,
                :MRASTEVDEF_N.CHK_VALUE_13,
                :MRASTEVDEF_N.CHK_VALUE_14,
                :MRASTEVDEF_N.CHK_VALUE_15,
                :MRASTEVDEF_N.CHK_VALUE_16,
                :MRASTEVDEF_N.CHK_VALUE_17,
                :MRASTEVDEF_N.CHK_VALUE_18,
                :MRASTEVDEF_N.CHK_VALUE_19,
                :MRASTEVDEF_N.CHK_VALUE_20,
                :MRASTEVDEF_N.CHK_VALUE_21,
                :MRASTEVDEF_N.CHK_VALUE_22,
                :MRASTEVDEF_N.CHK_VALUE_23,
                :MRASTEVDEF_N.CHK_VALUE_24,
                :MRASTEVDEF_N.CHK_VALUE_25,
                :MRASTEVDEF_N.CHK_VALUE_26,
                :MRASTEVDEF_N.CHK_VALUE_27,
                :MRASTEVDEF_N.CHK_VALUE_28,
                :MRASTEVDEF_N.CHK_VALUE_29,
                :MRASTEVDEF_N.CHK_VALUE_30,
                :MRASTEVDEF_N.CHK_FIELD_1,
                :MRASTEVDEF_N.CHK_FIELD_2,
                :MRASTEVDEF_N.CHK_FIELD_3,
                :MRASTEVDEF_N.CHK_FIELD_4,
                :MRASTEVDEF_N.CHK_FIELD_5,
                :MRASTEVDEF_N.CHK_FIELD_6,
                :MRASTEVDEF_N.CHK_FIELD_7,
                :MRASTEVDEF_N.CHK_FIELD_8,
                :MRASTEVDEF_N.CHK_FIELD_9,
                :MRASTEVDEF_N.CHK_FIELD_10,
                :MRASTEVDEF_N.CHK_FIELD_11,
                :MRASTEVDEF_N.CHK_FIELD_12,
                :MRASTEVDEF_N.CHK_FIELD_13,
                :MRASTEVDEF_N.CHK_FIELD_14,
                :MRASTEVDEF_N.CHK_FIELD_15,
                :MRASTEVDEF_N.CHK_FIELD_16,
                :MRASTEVDEF_N.CHK_FIELD_17,
                :MRASTEVDEF_N.CHK_FIELD_18,
                :MRASTEVDEF_N.CHK_FIELD_19,
                :MRASTEVDEF_N.CHK_FIELD_20,
                :MRASTEVDEF_N.CHK_FIELD_21,
                :MRASTEVDEF_N.CHK_FIELD_22,
                :MRASTEVDEF_N.CHK_FIELD_23,
                :MRASTEVDEF_N.CHK_FIELD_24,
                :MRASTEVDEF_N.CHK_FIELD_25,
                :MRASTEVDEF_N.CHK_FIELD_26,
                :MRASTEVDEF_N.CHK_FIELD_27,
                :MRASTEVDEF_N.CHK_FIELD_28,
                :MRASTEVDEF_N.CHK_FIELD_29,
                :MRASTEVDEF_N.CHK_FIELD_30,
                :MRASTEVDEF_N.CHG_ITEM_1,
                :MRASTEVDEF_N.CHG_ITEM_2,
                :MRASTEVDEF_N.CHG_ITEM_3,
                :MRASTEVDEF_N.CHG_ITEM_4,
                :MRASTEVDEF_N.CHG_ITEM_5,
                :MRASTEVDEF_N.CHG_ITEM_6,
                :MRASTEVDEF_N.CHG_ITEM_7,
                :MRASTEVDEF_N.CHG_ITEM_8,
                :MRASTEVDEF_N.CHG_ITEM_9,
                :MRASTEVDEF_N.CHG_ITEM_10,
                :MRASTEVDEF_N.CHG_ITEM_11,
                :MRASTEVDEF_N.CHG_ITEM_12,
                :MRASTEVDEF_N.CHG_ITEM_13,
                :MRASTEVDEF_N.CHG_ITEM_14,
                :MRASTEVDEF_N.CHG_ITEM_15,
                :MRASTEVDEF_N.CHG_ITEM_16,
                :MRASTEVDEF_N.CHG_ITEM_17,
                :MRASTEVDEF_N.CHG_ITEM_18,
                :MRASTEVDEF_N.CHG_ITEM_19,
                :MRASTEVDEF_N.CHG_ITEM_20,
                :MRASTEVDEF_N.CHG_ITEM_21,
                :MRASTEVDEF_N.CHG_ITEM_22,
                :MRASTEVDEF_N.CHG_ITEM_23,
                :MRASTEVDEF_N.CHG_ITEM_24,
                :MRASTEVDEF_N.CHG_ITEM_25,
                :MRASTEVDEF_N.CHG_ITEM_26,
                :MRASTEVDEF_N.CHG_ITEM_27,
                :MRASTEVDEF_N.CHG_ITEM_28,
                :MRASTEVDEF_N.CHG_ITEM_29,
                :MRASTEVDEF_N.CHG_ITEM_30,
                :MRASTEVDEF_N.CHG_FLAG_1,
                :MRASTEVDEF_N.CHG_FLAG_2,
                :MRASTEVDEF_N.CHG_FLAG_3,
                :MRASTEVDEF_N.CHG_FLAG_4,
                :MRASTEVDEF_N.CHG_FLAG_5,
                :MRASTEVDEF_N.CHG_FLAG_6,
                :MRASTEVDEF_N.CHG_FLAG_7,
                :MRASTEVDEF_N.CHG_FLAG_8,
                :MRASTEVDEF_N.CHG_FLAG_9,
                :MRASTEVDEF_N.CHG_FLAG_10,
                :MRASTEVDEF_N.CHG_FLAG_11,
                :MRASTEVDEF_N.CHG_FLAG_12,
                :MRASTEVDEF_N.CHG_FLAG_13,
                :MRASTEVDEF_N.CHG_FLAG_14,
                :MRASTEVDEF_N.CHG_FLAG_15,
                :MRASTEVDEF_N.CHG_FLAG_16,
                :MRASTEVDEF_N.CHG_FLAG_17,
                :MRASTEVDEF_N.CHG_FLAG_18,
                :MRASTEVDEF_N.CHG_FLAG_19,
                :MRASTEVDEF_N.CHG_FLAG_20,
                :MRASTEVDEF_N.CHG_FLAG_21,
                :MRASTEVDEF_N.CHG_FLAG_22,
                :MRASTEVDEF_N.CHG_FLAG_23,
                :MRASTEVDEF_N.CHG_FLAG_24,
                :MRASTEVDEF_N.CHG_FLAG_25,
                :MRASTEVDEF_N.CHG_FLAG_26,
                :MRASTEVDEF_N.CHG_FLAG_27,
                :MRASTEVDEF_N.CHG_FLAG_28,
                :MRASTEVDEF_N.CHG_FLAG_29,
                :MRASTEVDEF_N.CHG_FLAG_30,
                :MRASTEVDEF_N.CHG_VALUE_1,
                :MRASTEVDEF_N.CHG_VALUE_2,
                :MRASTEVDEF_N.CHG_VALUE_3,
                :MRASTEVDEF_N.CHG_VALUE_4,
                :MRASTEVDEF_N.CHG_VALUE_5,
                :MRASTEVDEF_N.CHG_VALUE_6,
                :MRASTEVDEF_N.CHG_VALUE_7,
                :MRASTEVDEF_N.CHG_VALUE_8,
                :MRASTEVDEF_N.CHG_VALUE_9,
                :MRASTEVDEF_N.CHG_VALUE_10,
                :MRASTEVDEF_N.CHG_VALUE_11,
                :MRASTEVDEF_N.CHG_VALUE_12,
                :MRASTEVDEF_N.CHG_VALUE_13,
                :MRASTEVDEF_N.CHG_VALUE_14,
                :MRASTEVDEF_N.CHG_VALUE_15,
                :MRASTEVDEF_N.CHG_VALUE_16,
                :MRASTEVDEF_N.CHG_VALUE_17,
                :MRASTEVDEF_N.CHG_VALUE_18,
                :MRASTEVDEF_N.CHG_VALUE_19,
                :MRASTEVDEF_N.CHG_VALUE_20,
                :MRASTEVDEF_N.CHG_VALUE_21,
                :MRASTEVDEF_N.CHG_VALUE_22,
                :MRASTEVDEF_N.CHG_VALUE_23,
                :MRASTEVDEF_N.CHG_VALUE_24,
                :MRASTEVDEF_N.CHG_VALUE_25,
                :MRASTEVDEF_N.CHG_VALUE_26,
                :MRASTEVDEF_N.CHG_VALUE_27,
                :MRASTEVDEF_N.CHG_VALUE_28,
                :MRASTEVDEF_N.CHG_VALUE_29,
                :MRASTEVDEF_N.CHG_VALUE_30,
                :MRASTEVDEF_N.CHG_OPT_1,
                :MRASTEVDEF_N.CHG_OPT_2,
                :MRASTEVDEF_N.CHG_OPT_3,
                :MRASTEVDEF_N.CHG_OPT_4,
                :MRASTEVDEF_N.CHG_OPT_5,
                :MRASTEVDEF_N.CHG_OPT_6,
                :MRASTEVDEF_N.CHG_OPT_7,
                :MRASTEVDEF_N.CHG_OPT_8,
                :MRASTEVDEF_N.CHG_OPT_9,
                :MRASTEVDEF_N.CHG_OPT_10,
                :MRASTEVDEF_N.CHG_OPT_11,
                :MRASTEVDEF_N.CHG_OPT_12,
                :MRASTEVDEF_N.CHG_OPT_13,
                :MRASTEVDEF_N.CHG_OPT_14,
                :MRASTEVDEF_N.CHG_OPT_15,
                :MRASTEVDEF_N.CHG_OPT_16,
                :MRASTEVDEF_N.CHG_OPT_17,
                :MRASTEVDEF_N.CHG_OPT_18,
                :MRASTEVDEF_N.CHG_OPT_19,
                :MRASTEVDEF_N.CHG_OPT_20,
                :MRASTEVDEF_N.CHG_OPT_21,
                :MRASTEVDEF_N.CHG_OPT_22,
                :MRASTEVDEF_N.CHG_OPT_23,
                :MRASTEVDEF_N.CHG_OPT_24,
                :MRASTEVDEF_N.CHG_OPT_25,
                :MRASTEVDEF_N.CHG_OPT_26,
                :MRASTEVDEF_N.CHG_OPT_27,
                :MRASTEVDEF_N.CHG_OPT_28,
                :MRASTEVDEF_N.CHG_OPT_29,
                :MRASTEVDEF_N.CHG_OPT_30,
                :MRASTEVDEF_N.CREATE_USER_ID,
                :MRASTEVDEF_N.CREATE_TIME,
                :MRASTEVDEF_N.UPDATE_USER_ID,
                :MRASTEVDEF_N.UPDATE_TIME,
                :MRASTEVDEF_N.CHG_FIELD_1,
                :MRASTEVDEF_N.CHG_FIELD_2,
                :MRASTEVDEF_N.CHG_FIELD_3,
                :MRASTEVDEF_N.CHG_FIELD_4,
                :MRASTEVDEF_N.CHG_FIELD_5,
                :MRASTEVDEF_N.CHG_FIELD_6,
                :MRASTEVDEF_N.CHG_FIELD_7,
                :MRASTEVDEF_N.CHG_FIELD_8,
                :MRASTEVDEF_N.CHG_FIELD_9,
                :MRASTEVDEF_N.CHG_FIELD_10,
                :MRASTEVDEF_N.CHG_FIELD_11,
                :MRASTEVDEF_N.CHG_FIELD_12,
                :MRASTEVDEF_N.CHG_FIELD_13,
                :MRASTEVDEF_N.CHG_FIELD_14,
                :MRASTEVDEF_N.CHG_FIELD_15,
                :MRASTEVDEF_N.CHG_FIELD_16,
                :MRASTEVDEF_N.CHG_FIELD_17,
                :MRASTEVDEF_N.CHG_FIELD_18,
                :MRASTEVDEF_N.CHG_FIELD_19,
                :MRASTEVDEF_N.CHG_FIELD_20,
                :MRASTEVDEF_N.CHG_FIELD_21,
                :MRASTEVDEF_N.CHG_FIELD_22,
                :MRASTEVDEF_N.CHG_FIELD_23,
                :MRASTEVDEF_N.CHG_FIELD_24,
                :MRASTEVDEF_N.CHG_FIELD_25,
                :MRASTEVDEF_N.CHG_FIELD_26,
                :MRASTEVDEF_N.CHG_FIELD_27,
                :MRASTEVDEF_N.CHG_FIELD_28,
                :MRASTEVDEF_N.CHG_FIELD_29,
                :MRASTEVDEF_N.CHG_FIELD_30; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4681;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )13;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTEVDEF_N.COLLECT_DEFECT_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTEVDEF_N.CLEAN_DEFECT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[154] = (unsigned int  )31;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[155] = (unsigned int  )31;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[156] = (unsigned int  )31;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[184] = (unsigned int  )2;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[186] = (unsigned int  )2;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[214] = (unsigned int  )31;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[215] = (unsigned int  )31;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[216] = (unsigned int  )31;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASTEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASTEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASTEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASTEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASTEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASTEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASTEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASTEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASTEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASTEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASTEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASTEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASTEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASTEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASTEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASTEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASTEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASTEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASTEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASTEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASTEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASTEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASTEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASTEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASTEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASTEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASTEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASTEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[244] = (unsigned int  )2;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASTEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[245] = (unsigned int  )2;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASTEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[246] = (unsigned int  )2;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASTEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[247] = (unsigned int  )21;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASTEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[248] = (unsigned int  )15;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASTEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[249] = (unsigned int  )21;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
            sqlstm.sqhstv[250] = (         void  *)(MRASTEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[250] = (unsigned int  )15;
            sqlstm.sqhsts[250] = (         int  )0;
            sqlstm.sqindv[250] = (         void  *)0;
            sqlstm.sqinds[250] = (         int  )0;
            sqlstm.sqharm[250] = (unsigned int  )0;
            sqlstm.sqadto[250] = (unsigned short )0;
            sqlstm.sqtdso[250] = (unsigned short )0;
            sqlstm.sqhstv[251] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_1);
            sqlstm.sqhstl[251] = (unsigned int  )31;
            sqlstm.sqhsts[251] = (         int  )0;
            sqlstm.sqindv[251] = (         void  *)0;
            sqlstm.sqinds[251] = (         int  )0;
            sqlstm.sqharm[251] = (unsigned int  )0;
            sqlstm.sqadto[251] = (unsigned short )0;
            sqlstm.sqtdso[251] = (unsigned short )0;
            sqlstm.sqhstv[252] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_2);
            sqlstm.sqhstl[252] = (unsigned int  )31;
            sqlstm.sqhsts[252] = (         int  )0;
            sqlstm.sqindv[252] = (         void  *)0;
            sqlstm.sqinds[252] = (         int  )0;
            sqlstm.sqharm[252] = (unsigned int  )0;
            sqlstm.sqadto[252] = (unsigned short )0;
            sqlstm.sqtdso[252] = (unsigned short )0;
            sqlstm.sqhstv[253] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_3);
            sqlstm.sqhstl[253] = (unsigned int  )31;
            sqlstm.sqhsts[253] = (         int  )0;
            sqlstm.sqindv[253] = (         void  *)0;
            sqlstm.sqinds[253] = (         int  )0;
            sqlstm.sqharm[253] = (unsigned int  )0;
            sqlstm.sqadto[253] = (unsigned short )0;
            sqlstm.sqtdso[253] = (unsigned short )0;
            sqlstm.sqhstv[254] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_4);
            sqlstm.sqhstl[254] = (unsigned int  )31;
            sqlstm.sqhsts[254] = (         int  )0;
            sqlstm.sqindv[254] = (         void  *)0;
            sqlstm.sqinds[254] = (         int  )0;
            sqlstm.sqharm[254] = (unsigned int  )0;
            sqlstm.sqadto[254] = (unsigned short )0;
            sqlstm.sqtdso[254] = (unsigned short )0;
            sqlstm.sqhstv[255] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_5);
            sqlstm.sqhstl[255] = (unsigned int  )31;
            sqlstm.sqhsts[255] = (         int  )0;
            sqlstm.sqindv[255] = (         void  *)0;
            sqlstm.sqinds[255] = (         int  )0;
            sqlstm.sqharm[255] = (unsigned int  )0;
            sqlstm.sqadto[255] = (unsigned short )0;
            sqlstm.sqtdso[255] = (unsigned short )0;
            sqlstm.sqhstv[256] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_6);
            sqlstm.sqhstl[256] = (unsigned int  )31;
            sqlstm.sqhsts[256] = (         int  )0;
            sqlstm.sqindv[256] = (         void  *)0;
            sqlstm.sqinds[256] = (         int  )0;
            sqlstm.sqharm[256] = (unsigned int  )0;
            sqlstm.sqadto[256] = (unsigned short )0;
            sqlstm.sqtdso[256] = (unsigned short )0;
            sqlstm.sqhstv[257] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_7);
            sqlstm.sqhstl[257] = (unsigned int  )31;
            sqlstm.sqhsts[257] = (         int  )0;
            sqlstm.sqindv[257] = (         void  *)0;
            sqlstm.sqinds[257] = (         int  )0;
            sqlstm.sqharm[257] = (unsigned int  )0;
            sqlstm.sqadto[257] = (unsigned short )0;
            sqlstm.sqtdso[257] = (unsigned short )0;
            sqlstm.sqhstv[258] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_8);
            sqlstm.sqhstl[258] = (unsigned int  )31;
            sqlstm.sqhsts[258] = (         int  )0;
            sqlstm.sqindv[258] = (         void  *)0;
            sqlstm.sqinds[258] = (         int  )0;
            sqlstm.sqharm[258] = (unsigned int  )0;
            sqlstm.sqadto[258] = (unsigned short )0;
            sqlstm.sqtdso[258] = (unsigned short )0;
            sqlstm.sqhstv[259] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_9);
            sqlstm.sqhstl[259] = (unsigned int  )31;
            sqlstm.sqhsts[259] = (         int  )0;
            sqlstm.sqindv[259] = (         void  *)0;
            sqlstm.sqinds[259] = (         int  )0;
            sqlstm.sqharm[259] = (unsigned int  )0;
            sqlstm.sqadto[259] = (unsigned short )0;
            sqlstm.sqtdso[259] = (unsigned short )0;
            sqlstm.sqhstv[260] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_10);
            sqlstm.sqhstl[260] = (unsigned int  )31;
            sqlstm.sqhsts[260] = (         int  )0;
            sqlstm.sqindv[260] = (         void  *)0;
            sqlstm.sqinds[260] = (         int  )0;
            sqlstm.sqharm[260] = (unsigned int  )0;
            sqlstm.sqadto[260] = (unsigned short )0;
            sqlstm.sqtdso[260] = (unsigned short )0;
            sqlstm.sqhstv[261] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_11);
            sqlstm.sqhstl[261] = (unsigned int  )31;
            sqlstm.sqhsts[261] = (         int  )0;
            sqlstm.sqindv[261] = (         void  *)0;
            sqlstm.sqinds[261] = (         int  )0;
            sqlstm.sqharm[261] = (unsigned int  )0;
            sqlstm.sqadto[261] = (unsigned short )0;
            sqlstm.sqtdso[261] = (unsigned short )0;
            sqlstm.sqhstv[262] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_12);
            sqlstm.sqhstl[262] = (unsigned int  )31;
            sqlstm.sqhsts[262] = (         int  )0;
            sqlstm.sqindv[262] = (         void  *)0;
            sqlstm.sqinds[262] = (         int  )0;
            sqlstm.sqharm[262] = (unsigned int  )0;
            sqlstm.sqadto[262] = (unsigned short )0;
            sqlstm.sqtdso[262] = (unsigned short )0;
            sqlstm.sqhstv[263] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_13);
            sqlstm.sqhstl[263] = (unsigned int  )31;
            sqlstm.sqhsts[263] = (         int  )0;
            sqlstm.sqindv[263] = (         void  *)0;
            sqlstm.sqinds[263] = (         int  )0;
            sqlstm.sqharm[263] = (unsigned int  )0;
            sqlstm.sqadto[263] = (unsigned short )0;
            sqlstm.sqtdso[263] = (unsigned short )0;
            sqlstm.sqhstv[264] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_14);
            sqlstm.sqhstl[264] = (unsigned int  )31;
            sqlstm.sqhsts[264] = (         int  )0;
            sqlstm.sqindv[264] = (         void  *)0;
            sqlstm.sqinds[264] = (         int  )0;
            sqlstm.sqharm[264] = (unsigned int  )0;
            sqlstm.sqadto[264] = (unsigned short )0;
            sqlstm.sqtdso[264] = (unsigned short )0;
            sqlstm.sqhstv[265] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_15);
            sqlstm.sqhstl[265] = (unsigned int  )31;
            sqlstm.sqhsts[265] = (         int  )0;
            sqlstm.sqindv[265] = (         void  *)0;
            sqlstm.sqinds[265] = (         int  )0;
            sqlstm.sqharm[265] = (unsigned int  )0;
            sqlstm.sqadto[265] = (unsigned short )0;
            sqlstm.sqtdso[265] = (unsigned short )0;
            sqlstm.sqhstv[266] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_16);
            sqlstm.sqhstl[266] = (unsigned int  )31;
            sqlstm.sqhsts[266] = (         int  )0;
            sqlstm.sqindv[266] = (         void  *)0;
            sqlstm.sqinds[266] = (         int  )0;
            sqlstm.sqharm[266] = (unsigned int  )0;
            sqlstm.sqadto[266] = (unsigned short )0;
            sqlstm.sqtdso[266] = (unsigned short )0;
            sqlstm.sqhstv[267] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_17);
            sqlstm.sqhstl[267] = (unsigned int  )31;
            sqlstm.sqhsts[267] = (         int  )0;
            sqlstm.sqindv[267] = (         void  *)0;
            sqlstm.sqinds[267] = (         int  )0;
            sqlstm.sqharm[267] = (unsigned int  )0;
            sqlstm.sqadto[267] = (unsigned short )0;
            sqlstm.sqtdso[267] = (unsigned short )0;
            sqlstm.sqhstv[268] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_18);
            sqlstm.sqhstl[268] = (unsigned int  )31;
            sqlstm.sqhsts[268] = (         int  )0;
            sqlstm.sqindv[268] = (         void  *)0;
            sqlstm.sqinds[268] = (         int  )0;
            sqlstm.sqharm[268] = (unsigned int  )0;
            sqlstm.sqadto[268] = (unsigned short )0;
            sqlstm.sqtdso[268] = (unsigned short )0;
            sqlstm.sqhstv[269] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_19);
            sqlstm.sqhstl[269] = (unsigned int  )31;
            sqlstm.sqhsts[269] = (         int  )0;
            sqlstm.sqindv[269] = (         void  *)0;
            sqlstm.sqinds[269] = (         int  )0;
            sqlstm.sqharm[269] = (unsigned int  )0;
            sqlstm.sqadto[269] = (unsigned short )0;
            sqlstm.sqtdso[269] = (unsigned short )0;
            sqlstm.sqhstv[270] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_20);
            sqlstm.sqhstl[270] = (unsigned int  )31;
            sqlstm.sqhsts[270] = (         int  )0;
            sqlstm.sqindv[270] = (         void  *)0;
            sqlstm.sqinds[270] = (         int  )0;
            sqlstm.sqharm[270] = (unsigned int  )0;
            sqlstm.sqadto[270] = (unsigned short )0;
            sqlstm.sqtdso[270] = (unsigned short )0;
            sqlstm.sqhstv[271] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_21);
            sqlstm.sqhstl[271] = (unsigned int  )31;
            sqlstm.sqhsts[271] = (         int  )0;
            sqlstm.sqindv[271] = (         void  *)0;
            sqlstm.sqinds[271] = (         int  )0;
            sqlstm.sqharm[271] = (unsigned int  )0;
            sqlstm.sqadto[271] = (unsigned short )0;
            sqlstm.sqtdso[271] = (unsigned short )0;
            sqlstm.sqhstv[272] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_22);
            sqlstm.sqhstl[272] = (unsigned int  )31;
            sqlstm.sqhsts[272] = (         int  )0;
            sqlstm.sqindv[272] = (         void  *)0;
            sqlstm.sqinds[272] = (         int  )0;
            sqlstm.sqharm[272] = (unsigned int  )0;
            sqlstm.sqadto[272] = (unsigned short )0;
            sqlstm.sqtdso[272] = (unsigned short )0;
            sqlstm.sqhstv[273] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_23);
            sqlstm.sqhstl[273] = (unsigned int  )31;
            sqlstm.sqhsts[273] = (         int  )0;
            sqlstm.sqindv[273] = (         void  *)0;
            sqlstm.sqinds[273] = (         int  )0;
            sqlstm.sqharm[273] = (unsigned int  )0;
            sqlstm.sqadto[273] = (unsigned short )0;
            sqlstm.sqtdso[273] = (unsigned short )0;
            sqlstm.sqhstv[274] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_24);
            sqlstm.sqhstl[274] = (unsigned int  )31;
            sqlstm.sqhsts[274] = (         int  )0;
            sqlstm.sqindv[274] = (         void  *)0;
            sqlstm.sqinds[274] = (         int  )0;
            sqlstm.sqharm[274] = (unsigned int  )0;
            sqlstm.sqadto[274] = (unsigned short )0;
            sqlstm.sqtdso[274] = (unsigned short )0;
            sqlstm.sqhstv[275] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_25);
            sqlstm.sqhstl[275] = (unsigned int  )31;
            sqlstm.sqhsts[275] = (         int  )0;
            sqlstm.sqindv[275] = (         void  *)0;
            sqlstm.sqinds[275] = (         int  )0;
            sqlstm.sqharm[275] = (unsigned int  )0;
            sqlstm.sqadto[275] = (unsigned short )0;
            sqlstm.sqtdso[275] = (unsigned short )0;
            sqlstm.sqhstv[276] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_26);
            sqlstm.sqhstl[276] = (unsigned int  )31;
            sqlstm.sqhsts[276] = (         int  )0;
            sqlstm.sqindv[276] = (         void  *)0;
            sqlstm.sqinds[276] = (         int  )0;
            sqlstm.sqharm[276] = (unsigned int  )0;
            sqlstm.sqadto[276] = (unsigned short )0;
            sqlstm.sqtdso[276] = (unsigned short )0;
            sqlstm.sqhstv[277] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_27);
            sqlstm.sqhstl[277] = (unsigned int  )31;
            sqlstm.sqhsts[277] = (         int  )0;
            sqlstm.sqindv[277] = (         void  *)0;
            sqlstm.sqinds[277] = (         int  )0;
            sqlstm.sqharm[277] = (unsigned int  )0;
            sqlstm.sqadto[277] = (unsigned short )0;
            sqlstm.sqtdso[277] = (unsigned short )0;
            sqlstm.sqhstv[278] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_28);
            sqlstm.sqhstl[278] = (unsigned int  )31;
            sqlstm.sqhsts[278] = (         int  )0;
            sqlstm.sqindv[278] = (         void  *)0;
            sqlstm.sqinds[278] = (         int  )0;
            sqlstm.sqharm[278] = (unsigned int  )0;
            sqlstm.sqadto[278] = (unsigned short )0;
            sqlstm.sqtdso[278] = (unsigned short )0;
            sqlstm.sqhstv[279] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_29);
            sqlstm.sqhstl[279] = (unsigned int  )31;
            sqlstm.sqhsts[279] = (         int  )0;
            sqlstm.sqindv[279] = (         void  *)0;
            sqlstm.sqinds[279] = (         int  )0;
            sqlstm.sqharm[279] = (unsigned int  )0;
            sqlstm.sqadto[279] = (unsigned short )0;
            sqlstm.sqtdso[279] = (unsigned short )0;
            sqlstm.sqhstv[280] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_30);
            sqlstm.sqhstl[280] = (unsigned int  )31;
            sqlstm.sqhsts[280] = (         int  )0;
            sqlstm.sqindv[280] = (         void  *)0;
            sqlstm.sqinds[280] = (         int  )0;
            sqlstm.sqharm[280] = (unsigned int  )0;
            sqlstm.sqadto[280] = (unsigned short )0;
            sqlstm.sqtdso[280] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_MRASTEVDEF_CUR_2 INTO
                :MRASTEVDEF_N.FACTORY,
                :MRASTEVDEF_N.TOOL_TYPE,
                :MRASTEVDEF_N.TOOL_EVENT_ID,
                :MRASTEVDEF_N.TOOL_EVENT_DESC,
                :MRASTEVDEF_N.SYSTEM_FLAG,
                :MRASTEVDEF_N.COLLECT_DEFECT_FLAG,
                :MRASTEVDEF_N.CLEAN_DEFECT_FLAG,
                :MRASTEVDEF_N.CHK_ITEM_1,
                :MRASTEVDEF_N.CHK_ITEM_2,
                :MRASTEVDEF_N.CHK_ITEM_3,
                :MRASTEVDEF_N.CHK_ITEM_4,
                :MRASTEVDEF_N.CHK_ITEM_5,
                :MRASTEVDEF_N.CHK_ITEM_6,
                :MRASTEVDEF_N.CHK_ITEM_7,
                :MRASTEVDEF_N.CHK_ITEM_8,
                :MRASTEVDEF_N.CHK_ITEM_9,
                :MRASTEVDEF_N.CHK_ITEM_10,
                :MRASTEVDEF_N.CHK_ITEM_11,
                :MRASTEVDEF_N.CHK_ITEM_12,
                :MRASTEVDEF_N.CHK_ITEM_13,
                :MRASTEVDEF_N.CHK_ITEM_14,
                :MRASTEVDEF_N.CHK_ITEM_15,
                :MRASTEVDEF_N.CHK_ITEM_16,
                :MRASTEVDEF_N.CHK_ITEM_17,
                :MRASTEVDEF_N.CHK_ITEM_18,
                :MRASTEVDEF_N.CHK_ITEM_19,
                :MRASTEVDEF_N.CHK_ITEM_20,
                :MRASTEVDEF_N.CHK_ITEM_21,
                :MRASTEVDEF_N.CHK_ITEM_22,
                :MRASTEVDEF_N.CHK_ITEM_23,
                :MRASTEVDEF_N.CHK_ITEM_24,
                :MRASTEVDEF_N.CHK_ITEM_25,
                :MRASTEVDEF_N.CHK_ITEM_26,
                :MRASTEVDEF_N.CHK_ITEM_27,
                :MRASTEVDEF_N.CHK_ITEM_28,
                :MRASTEVDEF_N.CHK_ITEM_29,
                :MRASTEVDEF_N.CHK_ITEM_30,
                :MRASTEVDEF_N.CHK_FLAG_1,
                :MRASTEVDEF_N.CHK_FLAG_2,
                :MRASTEVDEF_N.CHK_FLAG_3,
                :MRASTEVDEF_N.CHK_FLAG_4,
                :MRASTEVDEF_N.CHK_FLAG_5,
                :MRASTEVDEF_N.CHK_FLAG_6,
                :MRASTEVDEF_N.CHK_FLAG_7,
                :MRASTEVDEF_N.CHK_FLAG_8,
                :MRASTEVDEF_N.CHK_FLAG_9,
                :MRASTEVDEF_N.CHK_FLAG_10,
                :MRASTEVDEF_N.CHK_FLAG_11,
                :MRASTEVDEF_N.CHK_FLAG_12,
                :MRASTEVDEF_N.CHK_FLAG_13,
                :MRASTEVDEF_N.CHK_FLAG_14,
                :MRASTEVDEF_N.CHK_FLAG_15,
                :MRASTEVDEF_N.CHK_FLAG_16,
                :MRASTEVDEF_N.CHK_FLAG_17,
                :MRASTEVDEF_N.CHK_FLAG_18,
                :MRASTEVDEF_N.CHK_FLAG_19,
                :MRASTEVDEF_N.CHK_FLAG_20,
                :MRASTEVDEF_N.CHK_FLAG_21,
                :MRASTEVDEF_N.CHK_FLAG_22,
                :MRASTEVDEF_N.CHK_FLAG_23,
                :MRASTEVDEF_N.CHK_FLAG_24,
                :MRASTEVDEF_N.CHK_FLAG_25,
                :MRASTEVDEF_N.CHK_FLAG_26,
                :MRASTEVDEF_N.CHK_FLAG_27,
                :MRASTEVDEF_N.CHK_FLAG_28,
                :MRASTEVDEF_N.CHK_FLAG_29,
                :MRASTEVDEF_N.CHK_FLAG_30,
                :MRASTEVDEF_N.CHK_VALUE_1,
                :MRASTEVDEF_N.CHK_VALUE_2,
                :MRASTEVDEF_N.CHK_VALUE_3,
                :MRASTEVDEF_N.CHK_VALUE_4,
                :MRASTEVDEF_N.CHK_VALUE_5,
                :MRASTEVDEF_N.CHK_VALUE_6,
                :MRASTEVDEF_N.CHK_VALUE_7,
                :MRASTEVDEF_N.CHK_VALUE_8,
                :MRASTEVDEF_N.CHK_VALUE_9,
                :MRASTEVDEF_N.CHK_VALUE_10,
                :MRASTEVDEF_N.CHK_VALUE_11,
                :MRASTEVDEF_N.CHK_VALUE_12,
                :MRASTEVDEF_N.CHK_VALUE_13,
                :MRASTEVDEF_N.CHK_VALUE_14,
                :MRASTEVDEF_N.CHK_VALUE_15,
                :MRASTEVDEF_N.CHK_VALUE_16,
                :MRASTEVDEF_N.CHK_VALUE_17,
                :MRASTEVDEF_N.CHK_VALUE_18,
                :MRASTEVDEF_N.CHK_VALUE_19,
                :MRASTEVDEF_N.CHK_VALUE_20,
                :MRASTEVDEF_N.CHK_VALUE_21,
                :MRASTEVDEF_N.CHK_VALUE_22,
                :MRASTEVDEF_N.CHK_VALUE_23,
                :MRASTEVDEF_N.CHK_VALUE_24,
                :MRASTEVDEF_N.CHK_VALUE_25,
                :MRASTEVDEF_N.CHK_VALUE_26,
                :MRASTEVDEF_N.CHK_VALUE_27,
                :MRASTEVDEF_N.CHK_VALUE_28,
                :MRASTEVDEF_N.CHK_VALUE_29,
                :MRASTEVDEF_N.CHK_VALUE_30,
                :MRASTEVDEF_N.CHK_FIELD_1,
                :MRASTEVDEF_N.CHK_FIELD_2,
                :MRASTEVDEF_N.CHK_FIELD_3,
                :MRASTEVDEF_N.CHK_FIELD_4,
                :MRASTEVDEF_N.CHK_FIELD_5,
                :MRASTEVDEF_N.CHK_FIELD_6,
                :MRASTEVDEF_N.CHK_FIELD_7,
                :MRASTEVDEF_N.CHK_FIELD_8,
                :MRASTEVDEF_N.CHK_FIELD_9,
                :MRASTEVDEF_N.CHK_FIELD_10,
                :MRASTEVDEF_N.CHK_FIELD_11,
                :MRASTEVDEF_N.CHK_FIELD_12,
                :MRASTEVDEF_N.CHK_FIELD_13,
                :MRASTEVDEF_N.CHK_FIELD_14,
                :MRASTEVDEF_N.CHK_FIELD_15,
                :MRASTEVDEF_N.CHK_FIELD_16,
                :MRASTEVDEF_N.CHK_FIELD_17,
                :MRASTEVDEF_N.CHK_FIELD_18,
                :MRASTEVDEF_N.CHK_FIELD_19,
                :MRASTEVDEF_N.CHK_FIELD_20,
                :MRASTEVDEF_N.CHK_FIELD_21,
                :MRASTEVDEF_N.CHK_FIELD_22,
                :MRASTEVDEF_N.CHK_FIELD_23,
                :MRASTEVDEF_N.CHK_FIELD_24,
                :MRASTEVDEF_N.CHK_FIELD_25,
                :MRASTEVDEF_N.CHK_FIELD_26,
                :MRASTEVDEF_N.CHK_FIELD_27,
                :MRASTEVDEF_N.CHK_FIELD_28,
                :MRASTEVDEF_N.CHK_FIELD_29,
                :MRASTEVDEF_N.CHK_FIELD_30,
                :MRASTEVDEF_N.CHG_ITEM_1,
                :MRASTEVDEF_N.CHG_ITEM_2,
                :MRASTEVDEF_N.CHG_ITEM_3,
                :MRASTEVDEF_N.CHG_ITEM_4,
                :MRASTEVDEF_N.CHG_ITEM_5,
                :MRASTEVDEF_N.CHG_ITEM_6,
                :MRASTEVDEF_N.CHG_ITEM_7,
                :MRASTEVDEF_N.CHG_ITEM_8,
                :MRASTEVDEF_N.CHG_ITEM_9,
                :MRASTEVDEF_N.CHG_ITEM_10,
                :MRASTEVDEF_N.CHG_ITEM_11,
                :MRASTEVDEF_N.CHG_ITEM_12,
                :MRASTEVDEF_N.CHG_ITEM_13,
                :MRASTEVDEF_N.CHG_ITEM_14,
                :MRASTEVDEF_N.CHG_ITEM_15,
                :MRASTEVDEF_N.CHG_ITEM_16,
                :MRASTEVDEF_N.CHG_ITEM_17,
                :MRASTEVDEF_N.CHG_ITEM_18,
                :MRASTEVDEF_N.CHG_ITEM_19,
                :MRASTEVDEF_N.CHG_ITEM_20,
                :MRASTEVDEF_N.CHG_ITEM_21,
                :MRASTEVDEF_N.CHG_ITEM_22,
                :MRASTEVDEF_N.CHG_ITEM_23,
                :MRASTEVDEF_N.CHG_ITEM_24,
                :MRASTEVDEF_N.CHG_ITEM_25,
                :MRASTEVDEF_N.CHG_ITEM_26,
                :MRASTEVDEF_N.CHG_ITEM_27,
                :MRASTEVDEF_N.CHG_ITEM_28,
                :MRASTEVDEF_N.CHG_ITEM_29,
                :MRASTEVDEF_N.CHG_ITEM_30,
                :MRASTEVDEF_N.CHG_FLAG_1,
                :MRASTEVDEF_N.CHG_FLAG_2,
                :MRASTEVDEF_N.CHG_FLAG_3,
                :MRASTEVDEF_N.CHG_FLAG_4,
                :MRASTEVDEF_N.CHG_FLAG_5,
                :MRASTEVDEF_N.CHG_FLAG_6,
                :MRASTEVDEF_N.CHG_FLAG_7,
                :MRASTEVDEF_N.CHG_FLAG_8,
                :MRASTEVDEF_N.CHG_FLAG_9,
                :MRASTEVDEF_N.CHG_FLAG_10,
                :MRASTEVDEF_N.CHG_FLAG_11,
                :MRASTEVDEF_N.CHG_FLAG_12,
                :MRASTEVDEF_N.CHG_FLAG_13,
                :MRASTEVDEF_N.CHG_FLAG_14,
                :MRASTEVDEF_N.CHG_FLAG_15,
                :MRASTEVDEF_N.CHG_FLAG_16,
                :MRASTEVDEF_N.CHG_FLAG_17,
                :MRASTEVDEF_N.CHG_FLAG_18,
                :MRASTEVDEF_N.CHG_FLAG_19,
                :MRASTEVDEF_N.CHG_FLAG_20,
                :MRASTEVDEF_N.CHG_FLAG_21,
                :MRASTEVDEF_N.CHG_FLAG_22,
                :MRASTEVDEF_N.CHG_FLAG_23,
                :MRASTEVDEF_N.CHG_FLAG_24,
                :MRASTEVDEF_N.CHG_FLAG_25,
                :MRASTEVDEF_N.CHG_FLAG_26,
                :MRASTEVDEF_N.CHG_FLAG_27,
                :MRASTEVDEF_N.CHG_FLAG_28,
                :MRASTEVDEF_N.CHG_FLAG_29,
                :MRASTEVDEF_N.CHG_FLAG_30,
                :MRASTEVDEF_N.CHG_VALUE_1,
                :MRASTEVDEF_N.CHG_VALUE_2,
                :MRASTEVDEF_N.CHG_VALUE_3,
                :MRASTEVDEF_N.CHG_VALUE_4,
                :MRASTEVDEF_N.CHG_VALUE_5,
                :MRASTEVDEF_N.CHG_VALUE_6,
                :MRASTEVDEF_N.CHG_VALUE_7,
                :MRASTEVDEF_N.CHG_VALUE_8,
                :MRASTEVDEF_N.CHG_VALUE_9,
                :MRASTEVDEF_N.CHG_VALUE_10,
                :MRASTEVDEF_N.CHG_VALUE_11,
                :MRASTEVDEF_N.CHG_VALUE_12,
                :MRASTEVDEF_N.CHG_VALUE_13,
                :MRASTEVDEF_N.CHG_VALUE_14,
                :MRASTEVDEF_N.CHG_VALUE_15,
                :MRASTEVDEF_N.CHG_VALUE_16,
                :MRASTEVDEF_N.CHG_VALUE_17,
                :MRASTEVDEF_N.CHG_VALUE_18,
                :MRASTEVDEF_N.CHG_VALUE_19,
                :MRASTEVDEF_N.CHG_VALUE_20,
                :MRASTEVDEF_N.CHG_VALUE_21,
                :MRASTEVDEF_N.CHG_VALUE_22,
                :MRASTEVDEF_N.CHG_VALUE_23,
                :MRASTEVDEF_N.CHG_VALUE_24,
                :MRASTEVDEF_N.CHG_VALUE_25,
                :MRASTEVDEF_N.CHG_VALUE_26,
                :MRASTEVDEF_N.CHG_VALUE_27,
                :MRASTEVDEF_N.CHG_VALUE_28,
                :MRASTEVDEF_N.CHG_VALUE_29,
                :MRASTEVDEF_N.CHG_VALUE_30,
                :MRASTEVDEF_N.CHG_OPT_1,
                :MRASTEVDEF_N.CHG_OPT_2,
                :MRASTEVDEF_N.CHG_OPT_3,
                :MRASTEVDEF_N.CHG_OPT_4,
                :MRASTEVDEF_N.CHG_OPT_5,
                :MRASTEVDEF_N.CHG_OPT_6,
                :MRASTEVDEF_N.CHG_OPT_7,
                :MRASTEVDEF_N.CHG_OPT_8,
                :MRASTEVDEF_N.CHG_OPT_9,
                :MRASTEVDEF_N.CHG_OPT_10,
                :MRASTEVDEF_N.CHG_OPT_11,
                :MRASTEVDEF_N.CHG_OPT_12,
                :MRASTEVDEF_N.CHG_OPT_13,
                :MRASTEVDEF_N.CHG_OPT_14,
                :MRASTEVDEF_N.CHG_OPT_15,
                :MRASTEVDEF_N.CHG_OPT_16,
                :MRASTEVDEF_N.CHG_OPT_17,
                :MRASTEVDEF_N.CHG_OPT_18,
                :MRASTEVDEF_N.CHG_OPT_19,
                :MRASTEVDEF_N.CHG_OPT_20,
                :MRASTEVDEF_N.CHG_OPT_21,
                :MRASTEVDEF_N.CHG_OPT_22,
                :MRASTEVDEF_N.CHG_OPT_23,
                :MRASTEVDEF_N.CHG_OPT_24,
                :MRASTEVDEF_N.CHG_OPT_25,
                :MRASTEVDEF_N.CHG_OPT_26,
                :MRASTEVDEF_N.CHG_OPT_27,
                :MRASTEVDEF_N.CHG_OPT_28,
                :MRASTEVDEF_N.CHG_OPT_29,
                :MRASTEVDEF_N.CHG_OPT_30,
                :MRASTEVDEF_N.CREATE_USER_ID,
                :MRASTEVDEF_N.CREATE_TIME,
                :MRASTEVDEF_N.UPDATE_USER_ID,
                :MRASTEVDEF_N.UPDATE_TIME,
                :MRASTEVDEF_N.CHG_FIELD_1,
                :MRASTEVDEF_N.CHG_FIELD_2,
                :MRASTEVDEF_N.CHG_FIELD_3,
                :MRASTEVDEF_N.CHG_FIELD_4,
                :MRASTEVDEF_N.CHG_FIELD_5,
                :MRASTEVDEF_N.CHG_FIELD_6,
                :MRASTEVDEF_N.CHG_FIELD_7,
                :MRASTEVDEF_N.CHG_FIELD_8,
                :MRASTEVDEF_N.CHG_FIELD_9,
                :MRASTEVDEF_N.CHG_FIELD_10,
                :MRASTEVDEF_N.CHG_FIELD_11,
                :MRASTEVDEF_N.CHG_FIELD_12,
                :MRASTEVDEF_N.CHG_FIELD_13,
                :MRASTEVDEF_N.CHG_FIELD_14,
                :MRASTEVDEF_N.CHG_FIELD_15,
                :MRASTEVDEF_N.CHG_FIELD_16,
                :MRASTEVDEF_N.CHG_FIELD_17,
                :MRASTEVDEF_N.CHG_FIELD_18,
                :MRASTEVDEF_N.CHG_FIELD_19,
                :MRASTEVDEF_N.CHG_FIELD_20,
                :MRASTEVDEF_N.CHG_FIELD_21,
                :MRASTEVDEF_N.CHG_FIELD_22,
                :MRASTEVDEF_N.CHG_FIELD_23,
                :MRASTEVDEF_N.CHG_FIELD_24,
                :MRASTEVDEF_N.CHG_FIELD_25,
                :MRASTEVDEF_N.CHG_FIELD_26,
                :MRASTEVDEF_N.CHG_FIELD_27,
                :MRASTEVDEF_N.CHG_FIELD_28,
                :MRASTEVDEF_N.CHG_FIELD_29,
                :MRASTEVDEF_N.CHG_FIELD_30; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5820;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASTEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASTEVDEF_N.TOOL_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )13;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASTEVDEF_N.TOOL_EVENT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASTEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[4] = (unsigned int  )2;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASTEVDEF_N.COLLECT_DEFECT_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASTEVDEF_N.CLEAN_DEFECT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[34] = (unsigned int  )31;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[35] = (unsigned int  )31;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASTEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[36] = (unsigned int  )31;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[65] = (unsigned int  )2;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASTEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[66] = (unsigned int  )2;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASTEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASTEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[154] = (unsigned int  )31;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[155] = (unsigned int  )31;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASTEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[156] = (unsigned int  )31;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[184] = (unsigned int  )2;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[185] = (unsigned int  )2;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASTEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[186] = (unsigned int  )2;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[214] = (unsigned int  )31;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[215] = (unsigned int  )31;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASTEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[216] = (unsigned int  )31;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASTEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASTEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASTEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASTEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASTEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASTEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASTEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASTEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASTEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASTEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASTEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASTEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASTEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASTEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASTEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASTEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASTEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASTEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASTEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASTEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASTEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASTEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASTEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASTEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASTEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASTEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASTEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASTEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[244] = (unsigned int  )2;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASTEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[245] = (unsigned int  )2;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASTEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[246] = (unsigned int  )2;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASTEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[247] = (unsigned int  )21;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASTEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[248] = (unsigned int  )15;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASTEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[249] = (unsigned int  )21;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
            sqlstm.sqhstv[250] = (         void  *)(MRASTEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[250] = (unsigned int  )15;
            sqlstm.sqhsts[250] = (         int  )0;
            sqlstm.sqindv[250] = (         void  *)0;
            sqlstm.sqinds[250] = (         int  )0;
            sqlstm.sqharm[250] = (unsigned int  )0;
            sqlstm.sqadto[250] = (unsigned short )0;
            sqlstm.sqtdso[250] = (unsigned short )0;
            sqlstm.sqhstv[251] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_1);
            sqlstm.sqhstl[251] = (unsigned int  )31;
            sqlstm.sqhsts[251] = (         int  )0;
            sqlstm.sqindv[251] = (         void  *)0;
            sqlstm.sqinds[251] = (         int  )0;
            sqlstm.sqharm[251] = (unsigned int  )0;
            sqlstm.sqadto[251] = (unsigned short )0;
            sqlstm.sqtdso[251] = (unsigned short )0;
            sqlstm.sqhstv[252] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_2);
            sqlstm.sqhstl[252] = (unsigned int  )31;
            sqlstm.sqhsts[252] = (         int  )0;
            sqlstm.sqindv[252] = (         void  *)0;
            sqlstm.sqinds[252] = (         int  )0;
            sqlstm.sqharm[252] = (unsigned int  )0;
            sqlstm.sqadto[252] = (unsigned short )0;
            sqlstm.sqtdso[252] = (unsigned short )0;
            sqlstm.sqhstv[253] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_3);
            sqlstm.sqhstl[253] = (unsigned int  )31;
            sqlstm.sqhsts[253] = (         int  )0;
            sqlstm.sqindv[253] = (         void  *)0;
            sqlstm.sqinds[253] = (         int  )0;
            sqlstm.sqharm[253] = (unsigned int  )0;
            sqlstm.sqadto[253] = (unsigned short )0;
            sqlstm.sqtdso[253] = (unsigned short )0;
            sqlstm.sqhstv[254] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_4);
            sqlstm.sqhstl[254] = (unsigned int  )31;
            sqlstm.sqhsts[254] = (         int  )0;
            sqlstm.sqindv[254] = (         void  *)0;
            sqlstm.sqinds[254] = (         int  )0;
            sqlstm.sqharm[254] = (unsigned int  )0;
            sqlstm.sqadto[254] = (unsigned short )0;
            sqlstm.sqtdso[254] = (unsigned short )0;
            sqlstm.sqhstv[255] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_5);
            sqlstm.sqhstl[255] = (unsigned int  )31;
            sqlstm.sqhsts[255] = (         int  )0;
            sqlstm.sqindv[255] = (         void  *)0;
            sqlstm.sqinds[255] = (         int  )0;
            sqlstm.sqharm[255] = (unsigned int  )0;
            sqlstm.sqadto[255] = (unsigned short )0;
            sqlstm.sqtdso[255] = (unsigned short )0;
            sqlstm.sqhstv[256] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_6);
            sqlstm.sqhstl[256] = (unsigned int  )31;
            sqlstm.sqhsts[256] = (         int  )0;
            sqlstm.sqindv[256] = (         void  *)0;
            sqlstm.sqinds[256] = (         int  )0;
            sqlstm.sqharm[256] = (unsigned int  )0;
            sqlstm.sqadto[256] = (unsigned short )0;
            sqlstm.sqtdso[256] = (unsigned short )0;
            sqlstm.sqhstv[257] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_7);
            sqlstm.sqhstl[257] = (unsigned int  )31;
            sqlstm.sqhsts[257] = (         int  )0;
            sqlstm.sqindv[257] = (         void  *)0;
            sqlstm.sqinds[257] = (         int  )0;
            sqlstm.sqharm[257] = (unsigned int  )0;
            sqlstm.sqadto[257] = (unsigned short )0;
            sqlstm.sqtdso[257] = (unsigned short )0;
            sqlstm.sqhstv[258] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_8);
            sqlstm.sqhstl[258] = (unsigned int  )31;
            sqlstm.sqhsts[258] = (         int  )0;
            sqlstm.sqindv[258] = (         void  *)0;
            sqlstm.sqinds[258] = (         int  )0;
            sqlstm.sqharm[258] = (unsigned int  )0;
            sqlstm.sqadto[258] = (unsigned short )0;
            sqlstm.sqtdso[258] = (unsigned short )0;
            sqlstm.sqhstv[259] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_9);
            sqlstm.sqhstl[259] = (unsigned int  )31;
            sqlstm.sqhsts[259] = (         int  )0;
            sqlstm.sqindv[259] = (         void  *)0;
            sqlstm.sqinds[259] = (         int  )0;
            sqlstm.sqharm[259] = (unsigned int  )0;
            sqlstm.sqadto[259] = (unsigned short )0;
            sqlstm.sqtdso[259] = (unsigned short )0;
            sqlstm.sqhstv[260] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_10);
            sqlstm.sqhstl[260] = (unsigned int  )31;
            sqlstm.sqhsts[260] = (         int  )0;
            sqlstm.sqindv[260] = (         void  *)0;
            sqlstm.sqinds[260] = (         int  )0;
            sqlstm.sqharm[260] = (unsigned int  )0;
            sqlstm.sqadto[260] = (unsigned short )0;
            sqlstm.sqtdso[260] = (unsigned short )0;
            sqlstm.sqhstv[261] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_11);
            sqlstm.sqhstl[261] = (unsigned int  )31;
            sqlstm.sqhsts[261] = (         int  )0;
            sqlstm.sqindv[261] = (         void  *)0;
            sqlstm.sqinds[261] = (         int  )0;
            sqlstm.sqharm[261] = (unsigned int  )0;
            sqlstm.sqadto[261] = (unsigned short )0;
            sqlstm.sqtdso[261] = (unsigned short )0;
            sqlstm.sqhstv[262] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_12);
            sqlstm.sqhstl[262] = (unsigned int  )31;
            sqlstm.sqhsts[262] = (         int  )0;
            sqlstm.sqindv[262] = (         void  *)0;
            sqlstm.sqinds[262] = (         int  )0;
            sqlstm.sqharm[262] = (unsigned int  )0;
            sqlstm.sqadto[262] = (unsigned short )0;
            sqlstm.sqtdso[262] = (unsigned short )0;
            sqlstm.sqhstv[263] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_13);
            sqlstm.sqhstl[263] = (unsigned int  )31;
            sqlstm.sqhsts[263] = (         int  )0;
            sqlstm.sqindv[263] = (         void  *)0;
            sqlstm.sqinds[263] = (         int  )0;
            sqlstm.sqharm[263] = (unsigned int  )0;
            sqlstm.sqadto[263] = (unsigned short )0;
            sqlstm.sqtdso[263] = (unsigned short )0;
            sqlstm.sqhstv[264] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_14);
            sqlstm.sqhstl[264] = (unsigned int  )31;
            sqlstm.sqhsts[264] = (         int  )0;
            sqlstm.sqindv[264] = (         void  *)0;
            sqlstm.sqinds[264] = (         int  )0;
            sqlstm.sqharm[264] = (unsigned int  )0;
            sqlstm.sqadto[264] = (unsigned short )0;
            sqlstm.sqtdso[264] = (unsigned short )0;
            sqlstm.sqhstv[265] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_15);
            sqlstm.sqhstl[265] = (unsigned int  )31;
            sqlstm.sqhsts[265] = (         int  )0;
            sqlstm.sqindv[265] = (         void  *)0;
            sqlstm.sqinds[265] = (         int  )0;
            sqlstm.sqharm[265] = (unsigned int  )0;
            sqlstm.sqadto[265] = (unsigned short )0;
            sqlstm.sqtdso[265] = (unsigned short )0;
            sqlstm.sqhstv[266] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_16);
            sqlstm.sqhstl[266] = (unsigned int  )31;
            sqlstm.sqhsts[266] = (         int  )0;
            sqlstm.sqindv[266] = (         void  *)0;
            sqlstm.sqinds[266] = (         int  )0;
            sqlstm.sqharm[266] = (unsigned int  )0;
            sqlstm.sqadto[266] = (unsigned short )0;
            sqlstm.sqtdso[266] = (unsigned short )0;
            sqlstm.sqhstv[267] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_17);
            sqlstm.sqhstl[267] = (unsigned int  )31;
            sqlstm.sqhsts[267] = (         int  )0;
            sqlstm.sqindv[267] = (         void  *)0;
            sqlstm.sqinds[267] = (         int  )0;
            sqlstm.sqharm[267] = (unsigned int  )0;
            sqlstm.sqadto[267] = (unsigned short )0;
            sqlstm.sqtdso[267] = (unsigned short )0;
            sqlstm.sqhstv[268] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_18);
            sqlstm.sqhstl[268] = (unsigned int  )31;
            sqlstm.sqhsts[268] = (         int  )0;
            sqlstm.sqindv[268] = (         void  *)0;
            sqlstm.sqinds[268] = (         int  )0;
            sqlstm.sqharm[268] = (unsigned int  )0;
            sqlstm.sqadto[268] = (unsigned short )0;
            sqlstm.sqtdso[268] = (unsigned short )0;
            sqlstm.sqhstv[269] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_19);
            sqlstm.sqhstl[269] = (unsigned int  )31;
            sqlstm.sqhsts[269] = (         int  )0;
            sqlstm.sqindv[269] = (         void  *)0;
            sqlstm.sqinds[269] = (         int  )0;
            sqlstm.sqharm[269] = (unsigned int  )0;
            sqlstm.sqadto[269] = (unsigned short )0;
            sqlstm.sqtdso[269] = (unsigned short )0;
            sqlstm.sqhstv[270] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_20);
            sqlstm.sqhstl[270] = (unsigned int  )31;
            sqlstm.sqhsts[270] = (         int  )0;
            sqlstm.sqindv[270] = (         void  *)0;
            sqlstm.sqinds[270] = (         int  )0;
            sqlstm.sqharm[270] = (unsigned int  )0;
            sqlstm.sqadto[270] = (unsigned short )0;
            sqlstm.sqtdso[270] = (unsigned short )0;
            sqlstm.sqhstv[271] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_21);
            sqlstm.sqhstl[271] = (unsigned int  )31;
            sqlstm.sqhsts[271] = (         int  )0;
            sqlstm.sqindv[271] = (         void  *)0;
            sqlstm.sqinds[271] = (         int  )0;
            sqlstm.sqharm[271] = (unsigned int  )0;
            sqlstm.sqadto[271] = (unsigned short )0;
            sqlstm.sqtdso[271] = (unsigned short )0;
            sqlstm.sqhstv[272] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_22);
            sqlstm.sqhstl[272] = (unsigned int  )31;
            sqlstm.sqhsts[272] = (         int  )0;
            sqlstm.sqindv[272] = (         void  *)0;
            sqlstm.sqinds[272] = (         int  )0;
            sqlstm.sqharm[272] = (unsigned int  )0;
            sqlstm.sqadto[272] = (unsigned short )0;
            sqlstm.sqtdso[272] = (unsigned short )0;
            sqlstm.sqhstv[273] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_23);
            sqlstm.sqhstl[273] = (unsigned int  )31;
            sqlstm.sqhsts[273] = (         int  )0;
            sqlstm.sqindv[273] = (         void  *)0;
            sqlstm.sqinds[273] = (         int  )0;
            sqlstm.sqharm[273] = (unsigned int  )0;
            sqlstm.sqadto[273] = (unsigned short )0;
            sqlstm.sqtdso[273] = (unsigned short )0;
            sqlstm.sqhstv[274] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_24);
            sqlstm.sqhstl[274] = (unsigned int  )31;
            sqlstm.sqhsts[274] = (         int  )0;
            sqlstm.sqindv[274] = (         void  *)0;
            sqlstm.sqinds[274] = (         int  )0;
            sqlstm.sqharm[274] = (unsigned int  )0;
            sqlstm.sqadto[274] = (unsigned short )0;
            sqlstm.sqtdso[274] = (unsigned short )0;
            sqlstm.sqhstv[275] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_25);
            sqlstm.sqhstl[275] = (unsigned int  )31;
            sqlstm.sqhsts[275] = (         int  )0;
            sqlstm.sqindv[275] = (         void  *)0;
            sqlstm.sqinds[275] = (         int  )0;
            sqlstm.sqharm[275] = (unsigned int  )0;
            sqlstm.sqadto[275] = (unsigned short )0;
            sqlstm.sqtdso[275] = (unsigned short )0;
            sqlstm.sqhstv[276] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_26);
            sqlstm.sqhstl[276] = (unsigned int  )31;
            sqlstm.sqhsts[276] = (         int  )0;
            sqlstm.sqindv[276] = (         void  *)0;
            sqlstm.sqinds[276] = (         int  )0;
            sqlstm.sqharm[276] = (unsigned int  )0;
            sqlstm.sqadto[276] = (unsigned short )0;
            sqlstm.sqtdso[276] = (unsigned short )0;
            sqlstm.sqhstv[277] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_27);
            sqlstm.sqhstl[277] = (unsigned int  )31;
            sqlstm.sqhsts[277] = (         int  )0;
            sqlstm.sqindv[277] = (         void  *)0;
            sqlstm.sqinds[277] = (         int  )0;
            sqlstm.sqharm[277] = (unsigned int  )0;
            sqlstm.sqadto[277] = (unsigned short )0;
            sqlstm.sqtdso[277] = (unsigned short )0;
            sqlstm.sqhstv[278] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_28);
            sqlstm.sqhstl[278] = (unsigned int  )31;
            sqlstm.sqhsts[278] = (         int  )0;
            sqlstm.sqindv[278] = (         void  *)0;
            sqlstm.sqinds[278] = (         int  )0;
            sqlstm.sqharm[278] = (unsigned int  )0;
            sqlstm.sqadto[278] = (unsigned short )0;
            sqlstm.sqtdso[278] = (unsigned short )0;
            sqlstm.sqhstv[279] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_29);
            sqlstm.sqhstl[279] = (unsigned int  )31;
            sqlstm.sqhsts[279] = (         int  )0;
            sqlstm.sqindv[279] = (         void  *)0;
            sqlstm.sqinds[279] = (         int  )0;
            sqlstm.sqharm[279] = (unsigned int  )0;
            sqlstm.sqadto[279] = (unsigned short )0;
            sqlstm.sqtdso[279] = (unsigned short )0;
            sqlstm.sqhstv[280] = (         void  *)(MRASTEVDEF_N.CHG_FIELD_30);
            sqlstm.sqhstl[280] = (unsigned int  )31;
            sqlstm.sqhsts[280] = (         int  )0;
            sqlstm.sqindv[280] = (         void  *)0;
            sqlstm.sqinds[280] = (         int  )0;
            sqlstm.sqharm[280] = (unsigned int  )0;
            sqlstm.sqadto[280] = (unsigned short )0;
            sqlstm.sqtdso[280] = (unsigned short )0;
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
        DBU_del_null_mrastevdef(&MRASTEVDEF_N, MRASTEVDEF);
    }

    DB_stop_query_timer("DBU_fetch_mrastevdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_mrastevdef(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MRASTEVDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6959;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBU_MRASTEVDEF_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 284;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )6974;
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

    DB_stop_query_timer("DBU_close_mrastevdef", sel_type);
}


/* Initialize Function */
void DBU_init_mrastevdef(struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* memset by Space */
    memset(MRASTEVDEF, ' ', sizeof(struct MRASTEVDEF_TAG));
    
}


/* Add Null Function */
void DBU_add_null_mrastevdef(struct MRASTEVDEF_N_TAG *MRASTEVDEF_N, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    /* memset by NULL */
    memset(MRASTEVDEF_N, '\0', sizeof(struct MRASTEVDEF_N_TAG));
    
    MEMCPY_AN(MRASTEVDEF_N->FACTORY, MRASTEVDEF->FACTORY, sizeof(MRASTEVDEF->FACTORY));
    MEMCPY_AN(MRASTEVDEF_N->TOOL_TYPE, MRASTEVDEF->TOOL_TYPE, sizeof(MRASTEVDEF->TOOL_TYPE));
    MEMCPY_AN(MRASTEVDEF_N->TOOL_EVENT_ID, MRASTEVDEF->TOOL_EVENT_ID, sizeof(MRASTEVDEF->TOOL_EVENT_ID));
    MEMCPY_AN(MRASTEVDEF_N->TOOL_EVENT_DESC, MRASTEVDEF->TOOL_EVENT_DESC, sizeof(MRASTEVDEF->TOOL_EVENT_DESC));
    MRASTEVDEF_N->SYSTEM_FLAG[0] = MRASTEVDEF->SYSTEM_FLAG;
    MRASTEVDEF_N->COLLECT_DEFECT_FLAG[0] = MRASTEVDEF->COLLECT_DEFECT_FLAG;
    MRASTEVDEF_N->CLEAN_DEFECT_FLAG[0] = MRASTEVDEF->CLEAN_DEFECT_FLAG;
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_1, MRASTEVDEF->CHK_ITEM_1, sizeof(MRASTEVDEF->CHK_ITEM_1));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_2, MRASTEVDEF->CHK_ITEM_2, sizeof(MRASTEVDEF->CHK_ITEM_2));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_3, MRASTEVDEF->CHK_ITEM_3, sizeof(MRASTEVDEF->CHK_ITEM_3));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_4, MRASTEVDEF->CHK_ITEM_4, sizeof(MRASTEVDEF->CHK_ITEM_4));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_5, MRASTEVDEF->CHK_ITEM_5, sizeof(MRASTEVDEF->CHK_ITEM_5));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_6, MRASTEVDEF->CHK_ITEM_6, sizeof(MRASTEVDEF->CHK_ITEM_6));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_7, MRASTEVDEF->CHK_ITEM_7, sizeof(MRASTEVDEF->CHK_ITEM_7));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_8, MRASTEVDEF->CHK_ITEM_8, sizeof(MRASTEVDEF->CHK_ITEM_8));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_9, MRASTEVDEF->CHK_ITEM_9, sizeof(MRASTEVDEF->CHK_ITEM_9));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_10, MRASTEVDEF->CHK_ITEM_10, sizeof(MRASTEVDEF->CHK_ITEM_10));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_11, MRASTEVDEF->CHK_ITEM_11, sizeof(MRASTEVDEF->CHK_ITEM_11));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_12, MRASTEVDEF->CHK_ITEM_12, sizeof(MRASTEVDEF->CHK_ITEM_12));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_13, MRASTEVDEF->CHK_ITEM_13, sizeof(MRASTEVDEF->CHK_ITEM_13));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_14, MRASTEVDEF->CHK_ITEM_14, sizeof(MRASTEVDEF->CHK_ITEM_14));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_15, MRASTEVDEF->CHK_ITEM_15, sizeof(MRASTEVDEF->CHK_ITEM_15));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_16, MRASTEVDEF->CHK_ITEM_16, sizeof(MRASTEVDEF->CHK_ITEM_16));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_17, MRASTEVDEF->CHK_ITEM_17, sizeof(MRASTEVDEF->CHK_ITEM_17));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_18, MRASTEVDEF->CHK_ITEM_18, sizeof(MRASTEVDEF->CHK_ITEM_18));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_19, MRASTEVDEF->CHK_ITEM_19, sizeof(MRASTEVDEF->CHK_ITEM_19));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_20, MRASTEVDEF->CHK_ITEM_20, sizeof(MRASTEVDEF->CHK_ITEM_20));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_21, MRASTEVDEF->CHK_ITEM_21, sizeof(MRASTEVDEF->CHK_ITEM_21));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_22, MRASTEVDEF->CHK_ITEM_22, sizeof(MRASTEVDEF->CHK_ITEM_22));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_23, MRASTEVDEF->CHK_ITEM_23, sizeof(MRASTEVDEF->CHK_ITEM_23));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_24, MRASTEVDEF->CHK_ITEM_24, sizeof(MRASTEVDEF->CHK_ITEM_24));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_25, MRASTEVDEF->CHK_ITEM_25, sizeof(MRASTEVDEF->CHK_ITEM_25));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_26, MRASTEVDEF->CHK_ITEM_26, sizeof(MRASTEVDEF->CHK_ITEM_26));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_27, MRASTEVDEF->CHK_ITEM_27, sizeof(MRASTEVDEF->CHK_ITEM_27));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_28, MRASTEVDEF->CHK_ITEM_28, sizeof(MRASTEVDEF->CHK_ITEM_28));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_29, MRASTEVDEF->CHK_ITEM_29, sizeof(MRASTEVDEF->CHK_ITEM_29));
    MEMCPY_AN(MRASTEVDEF_N->CHK_ITEM_30, MRASTEVDEF->CHK_ITEM_30, sizeof(MRASTEVDEF->CHK_ITEM_30));
    MRASTEVDEF_N->CHK_FLAG_1[0] = MRASTEVDEF->CHK_FLAG_1;
    MRASTEVDEF_N->CHK_FLAG_2[0] = MRASTEVDEF->CHK_FLAG_2;
    MRASTEVDEF_N->CHK_FLAG_3[0] = MRASTEVDEF->CHK_FLAG_3;
    MRASTEVDEF_N->CHK_FLAG_4[0] = MRASTEVDEF->CHK_FLAG_4;
    MRASTEVDEF_N->CHK_FLAG_5[0] = MRASTEVDEF->CHK_FLAG_5;
    MRASTEVDEF_N->CHK_FLAG_6[0] = MRASTEVDEF->CHK_FLAG_6;
    MRASTEVDEF_N->CHK_FLAG_7[0] = MRASTEVDEF->CHK_FLAG_7;
    MRASTEVDEF_N->CHK_FLAG_8[0] = MRASTEVDEF->CHK_FLAG_8;
    MRASTEVDEF_N->CHK_FLAG_9[0] = MRASTEVDEF->CHK_FLAG_9;
    MRASTEVDEF_N->CHK_FLAG_10[0] = MRASTEVDEF->CHK_FLAG_10;
    MRASTEVDEF_N->CHK_FLAG_11[0] = MRASTEVDEF->CHK_FLAG_11;
    MRASTEVDEF_N->CHK_FLAG_12[0] = MRASTEVDEF->CHK_FLAG_12;
    MRASTEVDEF_N->CHK_FLAG_13[0] = MRASTEVDEF->CHK_FLAG_13;
    MRASTEVDEF_N->CHK_FLAG_14[0] = MRASTEVDEF->CHK_FLAG_14;
    MRASTEVDEF_N->CHK_FLAG_15[0] = MRASTEVDEF->CHK_FLAG_15;
    MRASTEVDEF_N->CHK_FLAG_16[0] = MRASTEVDEF->CHK_FLAG_16;
    MRASTEVDEF_N->CHK_FLAG_17[0] = MRASTEVDEF->CHK_FLAG_17;
    MRASTEVDEF_N->CHK_FLAG_18[0] = MRASTEVDEF->CHK_FLAG_18;
    MRASTEVDEF_N->CHK_FLAG_19[0] = MRASTEVDEF->CHK_FLAG_19;
    MRASTEVDEF_N->CHK_FLAG_20[0] = MRASTEVDEF->CHK_FLAG_20;
    MRASTEVDEF_N->CHK_FLAG_21[0] = MRASTEVDEF->CHK_FLAG_21;
    MRASTEVDEF_N->CHK_FLAG_22[0] = MRASTEVDEF->CHK_FLAG_22;
    MRASTEVDEF_N->CHK_FLAG_23[0] = MRASTEVDEF->CHK_FLAG_23;
    MRASTEVDEF_N->CHK_FLAG_24[0] = MRASTEVDEF->CHK_FLAG_24;
    MRASTEVDEF_N->CHK_FLAG_25[0] = MRASTEVDEF->CHK_FLAG_25;
    MRASTEVDEF_N->CHK_FLAG_26[0] = MRASTEVDEF->CHK_FLAG_26;
    MRASTEVDEF_N->CHK_FLAG_27[0] = MRASTEVDEF->CHK_FLAG_27;
    MRASTEVDEF_N->CHK_FLAG_28[0] = MRASTEVDEF->CHK_FLAG_28;
    MRASTEVDEF_N->CHK_FLAG_29[0] = MRASTEVDEF->CHK_FLAG_29;
    MRASTEVDEF_N->CHK_FLAG_30[0] = MRASTEVDEF->CHK_FLAG_30;
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_1, MRASTEVDEF->CHK_VALUE_1, sizeof(MRASTEVDEF->CHK_VALUE_1));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_2, MRASTEVDEF->CHK_VALUE_2, sizeof(MRASTEVDEF->CHK_VALUE_2));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_3, MRASTEVDEF->CHK_VALUE_3, sizeof(MRASTEVDEF->CHK_VALUE_3));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_4, MRASTEVDEF->CHK_VALUE_4, sizeof(MRASTEVDEF->CHK_VALUE_4));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_5, MRASTEVDEF->CHK_VALUE_5, sizeof(MRASTEVDEF->CHK_VALUE_5));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_6, MRASTEVDEF->CHK_VALUE_6, sizeof(MRASTEVDEF->CHK_VALUE_6));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_7, MRASTEVDEF->CHK_VALUE_7, sizeof(MRASTEVDEF->CHK_VALUE_7));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_8, MRASTEVDEF->CHK_VALUE_8, sizeof(MRASTEVDEF->CHK_VALUE_8));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_9, MRASTEVDEF->CHK_VALUE_9, sizeof(MRASTEVDEF->CHK_VALUE_9));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_10, MRASTEVDEF->CHK_VALUE_10, sizeof(MRASTEVDEF->CHK_VALUE_10));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_11, MRASTEVDEF->CHK_VALUE_11, sizeof(MRASTEVDEF->CHK_VALUE_11));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_12, MRASTEVDEF->CHK_VALUE_12, sizeof(MRASTEVDEF->CHK_VALUE_12));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_13, MRASTEVDEF->CHK_VALUE_13, sizeof(MRASTEVDEF->CHK_VALUE_13));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_14, MRASTEVDEF->CHK_VALUE_14, sizeof(MRASTEVDEF->CHK_VALUE_14));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_15, MRASTEVDEF->CHK_VALUE_15, sizeof(MRASTEVDEF->CHK_VALUE_15));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_16, MRASTEVDEF->CHK_VALUE_16, sizeof(MRASTEVDEF->CHK_VALUE_16));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_17, MRASTEVDEF->CHK_VALUE_17, sizeof(MRASTEVDEF->CHK_VALUE_17));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_18, MRASTEVDEF->CHK_VALUE_18, sizeof(MRASTEVDEF->CHK_VALUE_18));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_19, MRASTEVDEF->CHK_VALUE_19, sizeof(MRASTEVDEF->CHK_VALUE_19));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_20, MRASTEVDEF->CHK_VALUE_20, sizeof(MRASTEVDEF->CHK_VALUE_20));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_21, MRASTEVDEF->CHK_VALUE_21, sizeof(MRASTEVDEF->CHK_VALUE_21));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_22, MRASTEVDEF->CHK_VALUE_22, sizeof(MRASTEVDEF->CHK_VALUE_22));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_23, MRASTEVDEF->CHK_VALUE_23, sizeof(MRASTEVDEF->CHK_VALUE_23));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_24, MRASTEVDEF->CHK_VALUE_24, sizeof(MRASTEVDEF->CHK_VALUE_24));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_25, MRASTEVDEF->CHK_VALUE_25, sizeof(MRASTEVDEF->CHK_VALUE_25));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_26, MRASTEVDEF->CHK_VALUE_26, sizeof(MRASTEVDEF->CHK_VALUE_26));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_27, MRASTEVDEF->CHK_VALUE_27, sizeof(MRASTEVDEF->CHK_VALUE_27));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_28, MRASTEVDEF->CHK_VALUE_28, sizeof(MRASTEVDEF->CHK_VALUE_28));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_29, MRASTEVDEF->CHK_VALUE_29, sizeof(MRASTEVDEF->CHK_VALUE_29));
    MEMCPY_AN(MRASTEVDEF_N->CHK_VALUE_30, MRASTEVDEF->CHK_VALUE_30, sizeof(MRASTEVDEF->CHK_VALUE_30));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_1, MRASTEVDEF->CHK_FIELD_1, sizeof(MRASTEVDEF->CHK_FIELD_1));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_2, MRASTEVDEF->CHK_FIELD_2, sizeof(MRASTEVDEF->CHK_FIELD_2));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_3, MRASTEVDEF->CHK_FIELD_3, sizeof(MRASTEVDEF->CHK_FIELD_3));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_4, MRASTEVDEF->CHK_FIELD_4, sizeof(MRASTEVDEF->CHK_FIELD_4));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_5, MRASTEVDEF->CHK_FIELD_5, sizeof(MRASTEVDEF->CHK_FIELD_5));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_6, MRASTEVDEF->CHK_FIELD_6, sizeof(MRASTEVDEF->CHK_FIELD_6));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_7, MRASTEVDEF->CHK_FIELD_7, sizeof(MRASTEVDEF->CHK_FIELD_7));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_8, MRASTEVDEF->CHK_FIELD_8, sizeof(MRASTEVDEF->CHK_FIELD_8));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_9, MRASTEVDEF->CHK_FIELD_9, sizeof(MRASTEVDEF->CHK_FIELD_9));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_10, MRASTEVDEF->CHK_FIELD_10, sizeof(MRASTEVDEF->CHK_FIELD_10));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_11, MRASTEVDEF->CHK_FIELD_11, sizeof(MRASTEVDEF->CHK_FIELD_11));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_12, MRASTEVDEF->CHK_FIELD_12, sizeof(MRASTEVDEF->CHK_FIELD_12));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_13, MRASTEVDEF->CHK_FIELD_13, sizeof(MRASTEVDEF->CHK_FIELD_13));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_14, MRASTEVDEF->CHK_FIELD_14, sizeof(MRASTEVDEF->CHK_FIELD_14));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_15, MRASTEVDEF->CHK_FIELD_15, sizeof(MRASTEVDEF->CHK_FIELD_15));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_16, MRASTEVDEF->CHK_FIELD_16, sizeof(MRASTEVDEF->CHK_FIELD_16));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_17, MRASTEVDEF->CHK_FIELD_17, sizeof(MRASTEVDEF->CHK_FIELD_17));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_18, MRASTEVDEF->CHK_FIELD_18, sizeof(MRASTEVDEF->CHK_FIELD_18));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_19, MRASTEVDEF->CHK_FIELD_19, sizeof(MRASTEVDEF->CHK_FIELD_19));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_20, MRASTEVDEF->CHK_FIELD_20, sizeof(MRASTEVDEF->CHK_FIELD_20));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_21, MRASTEVDEF->CHK_FIELD_21, sizeof(MRASTEVDEF->CHK_FIELD_21));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_22, MRASTEVDEF->CHK_FIELD_22, sizeof(MRASTEVDEF->CHK_FIELD_22));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_23, MRASTEVDEF->CHK_FIELD_23, sizeof(MRASTEVDEF->CHK_FIELD_23));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_24, MRASTEVDEF->CHK_FIELD_24, sizeof(MRASTEVDEF->CHK_FIELD_24));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_25, MRASTEVDEF->CHK_FIELD_25, sizeof(MRASTEVDEF->CHK_FIELD_25));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_26, MRASTEVDEF->CHK_FIELD_26, sizeof(MRASTEVDEF->CHK_FIELD_26));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_27, MRASTEVDEF->CHK_FIELD_27, sizeof(MRASTEVDEF->CHK_FIELD_27));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_28, MRASTEVDEF->CHK_FIELD_28, sizeof(MRASTEVDEF->CHK_FIELD_28));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_29, MRASTEVDEF->CHK_FIELD_29, sizeof(MRASTEVDEF->CHK_FIELD_29));
    MEMCPY_AN(MRASTEVDEF_N->CHK_FIELD_30, MRASTEVDEF->CHK_FIELD_30, sizeof(MRASTEVDEF->CHK_FIELD_30));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_1, MRASTEVDEF->CHG_ITEM_1, sizeof(MRASTEVDEF->CHG_ITEM_1));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_2, MRASTEVDEF->CHG_ITEM_2, sizeof(MRASTEVDEF->CHG_ITEM_2));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_3, MRASTEVDEF->CHG_ITEM_3, sizeof(MRASTEVDEF->CHG_ITEM_3));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_4, MRASTEVDEF->CHG_ITEM_4, sizeof(MRASTEVDEF->CHG_ITEM_4));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_5, MRASTEVDEF->CHG_ITEM_5, sizeof(MRASTEVDEF->CHG_ITEM_5));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_6, MRASTEVDEF->CHG_ITEM_6, sizeof(MRASTEVDEF->CHG_ITEM_6));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_7, MRASTEVDEF->CHG_ITEM_7, sizeof(MRASTEVDEF->CHG_ITEM_7));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_8, MRASTEVDEF->CHG_ITEM_8, sizeof(MRASTEVDEF->CHG_ITEM_8));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_9, MRASTEVDEF->CHG_ITEM_9, sizeof(MRASTEVDEF->CHG_ITEM_9));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_10, MRASTEVDEF->CHG_ITEM_10, sizeof(MRASTEVDEF->CHG_ITEM_10));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_11, MRASTEVDEF->CHG_ITEM_11, sizeof(MRASTEVDEF->CHG_ITEM_11));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_12, MRASTEVDEF->CHG_ITEM_12, sizeof(MRASTEVDEF->CHG_ITEM_12));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_13, MRASTEVDEF->CHG_ITEM_13, sizeof(MRASTEVDEF->CHG_ITEM_13));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_14, MRASTEVDEF->CHG_ITEM_14, sizeof(MRASTEVDEF->CHG_ITEM_14));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_15, MRASTEVDEF->CHG_ITEM_15, sizeof(MRASTEVDEF->CHG_ITEM_15));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_16, MRASTEVDEF->CHG_ITEM_16, sizeof(MRASTEVDEF->CHG_ITEM_16));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_17, MRASTEVDEF->CHG_ITEM_17, sizeof(MRASTEVDEF->CHG_ITEM_17));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_18, MRASTEVDEF->CHG_ITEM_18, sizeof(MRASTEVDEF->CHG_ITEM_18));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_19, MRASTEVDEF->CHG_ITEM_19, sizeof(MRASTEVDEF->CHG_ITEM_19));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_20, MRASTEVDEF->CHG_ITEM_20, sizeof(MRASTEVDEF->CHG_ITEM_20));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_21, MRASTEVDEF->CHG_ITEM_21, sizeof(MRASTEVDEF->CHG_ITEM_21));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_22, MRASTEVDEF->CHG_ITEM_22, sizeof(MRASTEVDEF->CHG_ITEM_22));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_23, MRASTEVDEF->CHG_ITEM_23, sizeof(MRASTEVDEF->CHG_ITEM_23));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_24, MRASTEVDEF->CHG_ITEM_24, sizeof(MRASTEVDEF->CHG_ITEM_24));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_25, MRASTEVDEF->CHG_ITEM_25, sizeof(MRASTEVDEF->CHG_ITEM_25));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_26, MRASTEVDEF->CHG_ITEM_26, sizeof(MRASTEVDEF->CHG_ITEM_26));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_27, MRASTEVDEF->CHG_ITEM_27, sizeof(MRASTEVDEF->CHG_ITEM_27));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_28, MRASTEVDEF->CHG_ITEM_28, sizeof(MRASTEVDEF->CHG_ITEM_28));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_29, MRASTEVDEF->CHG_ITEM_29, sizeof(MRASTEVDEF->CHG_ITEM_29));
    MEMCPY_AN(MRASTEVDEF_N->CHG_ITEM_30, MRASTEVDEF->CHG_ITEM_30, sizeof(MRASTEVDEF->CHG_ITEM_30));
    MRASTEVDEF_N->CHG_FLAG_1[0] = MRASTEVDEF->CHG_FLAG_1;
    MRASTEVDEF_N->CHG_FLAG_2[0] = MRASTEVDEF->CHG_FLAG_2;
    MRASTEVDEF_N->CHG_FLAG_3[0] = MRASTEVDEF->CHG_FLAG_3;
    MRASTEVDEF_N->CHG_FLAG_4[0] = MRASTEVDEF->CHG_FLAG_4;
    MRASTEVDEF_N->CHG_FLAG_5[0] = MRASTEVDEF->CHG_FLAG_5;
    MRASTEVDEF_N->CHG_FLAG_6[0] = MRASTEVDEF->CHG_FLAG_6;
    MRASTEVDEF_N->CHG_FLAG_7[0] = MRASTEVDEF->CHG_FLAG_7;
    MRASTEVDEF_N->CHG_FLAG_8[0] = MRASTEVDEF->CHG_FLAG_8;
    MRASTEVDEF_N->CHG_FLAG_9[0] = MRASTEVDEF->CHG_FLAG_9;
    MRASTEVDEF_N->CHG_FLAG_10[0] = MRASTEVDEF->CHG_FLAG_10;
    MRASTEVDEF_N->CHG_FLAG_11[0] = MRASTEVDEF->CHG_FLAG_11;
    MRASTEVDEF_N->CHG_FLAG_12[0] = MRASTEVDEF->CHG_FLAG_12;
    MRASTEVDEF_N->CHG_FLAG_13[0] = MRASTEVDEF->CHG_FLAG_13;
    MRASTEVDEF_N->CHG_FLAG_14[0] = MRASTEVDEF->CHG_FLAG_14;
    MRASTEVDEF_N->CHG_FLAG_15[0] = MRASTEVDEF->CHG_FLAG_15;
    MRASTEVDEF_N->CHG_FLAG_16[0] = MRASTEVDEF->CHG_FLAG_16;
    MRASTEVDEF_N->CHG_FLAG_17[0] = MRASTEVDEF->CHG_FLAG_17;
    MRASTEVDEF_N->CHG_FLAG_18[0] = MRASTEVDEF->CHG_FLAG_18;
    MRASTEVDEF_N->CHG_FLAG_19[0] = MRASTEVDEF->CHG_FLAG_19;
    MRASTEVDEF_N->CHG_FLAG_20[0] = MRASTEVDEF->CHG_FLAG_20;
    MRASTEVDEF_N->CHG_FLAG_21[0] = MRASTEVDEF->CHG_FLAG_21;
    MRASTEVDEF_N->CHG_FLAG_22[0] = MRASTEVDEF->CHG_FLAG_22;
    MRASTEVDEF_N->CHG_FLAG_23[0] = MRASTEVDEF->CHG_FLAG_23;
    MRASTEVDEF_N->CHG_FLAG_24[0] = MRASTEVDEF->CHG_FLAG_24;
    MRASTEVDEF_N->CHG_FLAG_25[0] = MRASTEVDEF->CHG_FLAG_25;
    MRASTEVDEF_N->CHG_FLAG_26[0] = MRASTEVDEF->CHG_FLAG_26;
    MRASTEVDEF_N->CHG_FLAG_27[0] = MRASTEVDEF->CHG_FLAG_27;
    MRASTEVDEF_N->CHG_FLAG_28[0] = MRASTEVDEF->CHG_FLAG_28;
    MRASTEVDEF_N->CHG_FLAG_29[0] = MRASTEVDEF->CHG_FLAG_29;
    MRASTEVDEF_N->CHG_FLAG_30[0] = MRASTEVDEF->CHG_FLAG_30;
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_1, MRASTEVDEF->CHG_VALUE_1, sizeof(MRASTEVDEF->CHG_VALUE_1));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_2, MRASTEVDEF->CHG_VALUE_2, sizeof(MRASTEVDEF->CHG_VALUE_2));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_3, MRASTEVDEF->CHG_VALUE_3, sizeof(MRASTEVDEF->CHG_VALUE_3));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_4, MRASTEVDEF->CHG_VALUE_4, sizeof(MRASTEVDEF->CHG_VALUE_4));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_5, MRASTEVDEF->CHG_VALUE_5, sizeof(MRASTEVDEF->CHG_VALUE_5));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_6, MRASTEVDEF->CHG_VALUE_6, sizeof(MRASTEVDEF->CHG_VALUE_6));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_7, MRASTEVDEF->CHG_VALUE_7, sizeof(MRASTEVDEF->CHG_VALUE_7));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_8, MRASTEVDEF->CHG_VALUE_8, sizeof(MRASTEVDEF->CHG_VALUE_8));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_9, MRASTEVDEF->CHG_VALUE_9, sizeof(MRASTEVDEF->CHG_VALUE_9));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_10, MRASTEVDEF->CHG_VALUE_10, sizeof(MRASTEVDEF->CHG_VALUE_10));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_11, MRASTEVDEF->CHG_VALUE_11, sizeof(MRASTEVDEF->CHG_VALUE_11));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_12, MRASTEVDEF->CHG_VALUE_12, sizeof(MRASTEVDEF->CHG_VALUE_12));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_13, MRASTEVDEF->CHG_VALUE_13, sizeof(MRASTEVDEF->CHG_VALUE_13));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_14, MRASTEVDEF->CHG_VALUE_14, sizeof(MRASTEVDEF->CHG_VALUE_14));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_15, MRASTEVDEF->CHG_VALUE_15, sizeof(MRASTEVDEF->CHG_VALUE_15));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_16, MRASTEVDEF->CHG_VALUE_16, sizeof(MRASTEVDEF->CHG_VALUE_16));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_17, MRASTEVDEF->CHG_VALUE_17, sizeof(MRASTEVDEF->CHG_VALUE_17));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_18, MRASTEVDEF->CHG_VALUE_18, sizeof(MRASTEVDEF->CHG_VALUE_18));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_19, MRASTEVDEF->CHG_VALUE_19, sizeof(MRASTEVDEF->CHG_VALUE_19));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_20, MRASTEVDEF->CHG_VALUE_20, sizeof(MRASTEVDEF->CHG_VALUE_20));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_21, MRASTEVDEF->CHG_VALUE_21, sizeof(MRASTEVDEF->CHG_VALUE_21));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_22, MRASTEVDEF->CHG_VALUE_22, sizeof(MRASTEVDEF->CHG_VALUE_22));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_23, MRASTEVDEF->CHG_VALUE_23, sizeof(MRASTEVDEF->CHG_VALUE_23));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_24, MRASTEVDEF->CHG_VALUE_24, sizeof(MRASTEVDEF->CHG_VALUE_24));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_25, MRASTEVDEF->CHG_VALUE_25, sizeof(MRASTEVDEF->CHG_VALUE_25));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_26, MRASTEVDEF->CHG_VALUE_26, sizeof(MRASTEVDEF->CHG_VALUE_26));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_27, MRASTEVDEF->CHG_VALUE_27, sizeof(MRASTEVDEF->CHG_VALUE_27));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_28, MRASTEVDEF->CHG_VALUE_28, sizeof(MRASTEVDEF->CHG_VALUE_28));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_29, MRASTEVDEF->CHG_VALUE_29, sizeof(MRASTEVDEF->CHG_VALUE_29));
    MEMCPY_AN(MRASTEVDEF_N->CHG_VALUE_30, MRASTEVDEF->CHG_VALUE_30, sizeof(MRASTEVDEF->CHG_VALUE_30));
    MRASTEVDEF_N->CHG_OPT_1[0] = MRASTEVDEF->CHG_OPT_1;
    MRASTEVDEF_N->CHG_OPT_2[0] = MRASTEVDEF->CHG_OPT_2;
    MRASTEVDEF_N->CHG_OPT_3[0] = MRASTEVDEF->CHG_OPT_3;
    MRASTEVDEF_N->CHG_OPT_4[0] = MRASTEVDEF->CHG_OPT_4;
    MRASTEVDEF_N->CHG_OPT_5[0] = MRASTEVDEF->CHG_OPT_5;
    MRASTEVDEF_N->CHG_OPT_6[0] = MRASTEVDEF->CHG_OPT_6;
    MRASTEVDEF_N->CHG_OPT_7[0] = MRASTEVDEF->CHG_OPT_7;
    MRASTEVDEF_N->CHG_OPT_8[0] = MRASTEVDEF->CHG_OPT_8;
    MRASTEVDEF_N->CHG_OPT_9[0] = MRASTEVDEF->CHG_OPT_9;
    MRASTEVDEF_N->CHG_OPT_10[0] = MRASTEVDEF->CHG_OPT_10;
    MRASTEVDEF_N->CHG_OPT_11[0] = MRASTEVDEF->CHG_OPT_11;
    MRASTEVDEF_N->CHG_OPT_12[0] = MRASTEVDEF->CHG_OPT_12;
    MRASTEVDEF_N->CHG_OPT_13[0] = MRASTEVDEF->CHG_OPT_13;
    MRASTEVDEF_N->CHG_OPT_14[0] = MRASTEVDEF->CHG_OPT_14;
    MRASTEVDEF_N->CHG_OPT_15[0] = MRASTEVDEF->CHG_OPT_15;
    MRASTEVDEF_N->CHG_OPT_16[0] = MRASTEVDEF->CHG_OPT_16;
    MRASTEVDEF_N->CHG_OPT_17[0] = MRASTEVDEF->CHG_OPT_17;
    MRASTEVDEF_N->CHG_OPT_18[0] = MRASTEVDEF->CHG_OPT_18;
    MRASTEVDEF_N->CHG_OPT_19[0] = MRASTEVDEF->CHG_OPT_19;
    MRASTEVDEF_N->CHG_OPT_20[0] = MRASTEVDEF->CHG_OPT_20;
    MRASTEVDEF_N->CHG_OPT_21[0] = MRASTEVDEF->CHG_OPT_21;
    MRASTEVDEF_N->CHG_OPT_22[0] = MRASTEVDEF->CHG_OPT_22;
    MRASTEVDEF_N->CHG_OPT_23[0] = MRASTEVDEF->CHG_OPT_23;
    MRASTEVDEF_N->CHG_OPT_24[0] = MRASTEVDEF->CHG_OPT_24;
    MRASTEVDEF_N->CHG_OPT_25[0] = MRASTEVDEF->CHG_OPT_25;
    MRASTEVDEF_N->CHG_OPT_26[0] = MRASTEVDEF->CHG_OPT_26;
    MRASTEVDEF_N->CHG_OPT_27[0] = MRASTEVDEF->CHG_OPT_27;
    MRASTEVDEF_N->CHG_OPT_28[0] = MRASTEVDEF->CHG_OPT_28;
    MRASTEVDEF_N->CHG_OPT_29[0] = MRASTEVDEF->CHG_OPT_29;
    MRASTEVDEF_N->CHG_OPT_30[0] = MRASTEVDEF->CHG_OPT_30;
    MEMCPY_AN(MRASTEVDEF_N->CREATE_USER_ID, MRASTEVDEF->CREATE_USER_ID, sizeof(MRASTEVDEF->CREATE_USER_ID));
    MEMCPY_AN(MRASTEVDEF_N->CREATE_TIME, MRASTEVDEF->CREATE_TIME, sizeof(MRASTEVDEF->CREATE_TIME));
    MEMCPY_AN(MRASTEVDEF_N->UPDATE_USER_ID, MRASTEVDEF->UPDATE_USER_ID, sizeof(MRASTEVDEF->UPDATE_USER_ID));
    MEMCPY_AN(MRASTEVDEF_N->UPDATE_TIME, MRASTEVDEF->UPDATE_TIME, sizeof(MRASTEVDEF->UPDATE_TIME));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_1, MRASTEVDEF->CHG_FIELD_1, sizeof(MRASTEVDEF->CHG_FIELD_1));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_2, MRASTEVDEF->CHG_FIELD_2, sizeof(MRASTEVDEF->CHG_FIELD_2));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_3, MRASTEVDEF->CHG_FIELD_3, sizeof(MRASTEVDEF->CHG_FIELD_3));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_4, MRASTEVDEF->CHG_FIELD_4, sizeof(MRASTEVDEF->CHG_FIELD_4));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_5, MRASTEVDEF->CHG_FIELD_5, sizeof(MRASTEVDEF->CHG_FIELD_5));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_6, MRASTEVDEF->CHG_FIELD_6, sizeof(MRASTEVDEF->CHG_FIELD_6));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_7, MRASTEVDEF->CHG_FIELD_7, sizeof(MRASTEVDEF->CHG_FIELD_7));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_8, MRASTEVDEF->CHG_FIELD_8, sizeof(MRASTEVDEF->CHG_FIELD_8));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_9, MRASTEVDEF->CHG_FIELD_9, sizeof(MRASTEVDEF->CHG_FIELD_9));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_10, MRASTEVDEF->CHG_FIELD_10, sizeof(MRASTEVDEF->CHG_FIELD_10));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_11, MRASTEVDEF->CHG_FIELD_11, sizeof(MRASTEVDEF->CHG_FIELD_11));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_12, MRASTEVDEF->CHG_FIELD_12, sizeof(MRASTEVDEF->CHG_FIELD_12));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_13, MRASTEVDEF->CHG_FIELD_13, sizeof(MRASTEVDEF->CHG_FIELD_13));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_14, MRASTEVDEF->CHG_FIELD_14, sizeof(MRASTEVDEF->CHG_FIELD_14));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_15, MRASTEVDEF->CHG_FIELD_15, sizeof(MRASTEVDEF->CHG_FIELD_15));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_16, MRASTEVDEF->CHG_FIELD_16, sizeof(MRASTEVDEF->CHG_FIELD_16));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_17, MRASTEVDEF->CHG_FIELD_17, sizeof(MRASTEVDEF->CHG_FIELD_17));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_18, MRASTEVDEF->CHG_FIELD_18, sizeof(MRASTEVDEF->CHG_FIELD_18));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_19, MRASTEVDEF->CHG_FIELD_19, sizeof(MRASTEVDEF->CHG_FIELD_19));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_20, MRASTEVDEF->CHG_FIELD_20, sizeof(MRASTEVDEF->CHG_FIELD_20));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_21, MRASTEVDEF->CHG_FIELD_21, sizeof(MRASTEVDEF->CHG_FIELD_21));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_22, MRASTEVDEF->CHG_FIELD_22, sizeof(MRASTEVDEF->CHG_FIELD_22));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_23, MRASTEVDEF->CHG_FIELD_23, sizeof(MRASTEVDEF->CHG_FIELD_23));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_24, MRASTEVDEF->CHG_FIELD_24, sizeof(MRASTEVDEF->CHG_FIELD_24));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_25, MRASTEVDEF->CHG_FIELD_25, sizeof(MRASTEVDEF->CHG_FIELD_25));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_26, MRASTEVDEF->CHG_FIELD_26, sizeof(MRASTEVDEF->CHG_FIELD_26));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_27, MRASTEVDEF->CHG_FIELD_27, sizeof(MRASTEVDEF->CHG_FIELD_27));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_28, MRASTEVDEF->CHG_FIELD_28, sizeof(MRASTEVDEF->CHG_FIELD_28));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_29, MRASTEVDEF->CHG_FIELD_29, sizeof(MRASTEVDEF->CHG_FIELD_29));
    MEMCPY_AN(MRASTEVDEF_N->CHG_FIELD_30, MRASTEVDEF->CHG_FIELD_30, sizeof(MRASTEVDEF->CHG_FIELD_30));
}


/* Del Null Function */
void DBU_del_null_mrastevdef(struct MRASTEVDEF_N_TAG *MRASTEVDEF_N, struct MRASTEVDEF_TAG *MRASTEVDEF)
{
    MEMCPY_DN(MRASTEVDEF->FACTORY, MRASTEVDEF_N->FACTORY, sizeof(MRASTEVDEF->FACTORY));
    MEMCPY_DN(MRASTEVDEF->TOOL_TYPE, MRASTEVDEF_N->TOOL_TYPE, sizeof(MRASTEVDEF->TOOL_TYPE));
    MEMCPY_DN(MRASTEVDEF->TOOL_EVENT_ID, MRASTEVDEF_N->TOOL_EVENT_ID, sizeof(MRASTEVDEF->TOOL_EVENT_ID));
    MEMCPY_DN(MRASTEVDEF->TOOL_EVENT_DESC, MRASTEVDEF_N->TOOL_EVENT_DESC, sizeof(MRASTEVDEF->TOOL_EVENT_DESC));
    MRASTEVDEF->SYSTEM_FLAG = MRASTEVDEF_N->SYSTEM_FLAG[0];
    MRASTEVDEF->COLLECT_DEFECT_FLAG = MRASTEVDEF_N->COLLECT_DEFECT_FLAG[0];
    MRASTEVDEF->CLEAN_DEFECT_FLAG = MRASTEVDEF_N->CLEAN_DEFECT_FLAG[0];
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_1, MRASTEVDEF_N->CHK_ITEM_1, sizeof(MRASTEVDEF->CHK_ITEM_1));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_2, MRASTEVDEF_N->CHK_ITEM_2, sizeof(MRASTEVDEF->CHK_ITEM_2));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_3, MRASTEVDEF_N->CHK_ITEM_3, sizeof(MRASTEVDEF->CHK_ITEM_3));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_4, MRASTEVDEF_N->CHK_ITEM_4, sizeof(MRASTEVDEF->CHK_ITEM_4));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_5, MRASTEVDEF_N->CHK_ITEM_5, sizeof(MRASTEVDEF->CHK_ITEM_5));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_6, MRASTEVDEF_N->CHK_ITEM_6, sizeof(MRASTEVDEF->CHK_ITEM_6));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_7, MRASTEVDEF_N->CHK_ITEM_7, sizeof(MRASTEVDEF->CHK_ITEM_7));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_8, MRASTEVDEF_N->CHK_ITEM_8, sizeof(MRASTEVDEF->CHK_ITEM_8));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_9, MRASTEVDEF_N->CHK_ITEM_9, sizeof(MRASTEVDEF->CHK_ITEM_9));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_10, MRASTEVDEF_N->CHK_ITEM_10, sizeof(MRASTEVDEF->CHK_ITEM_10));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_11, MRASTEVDEF_N->CHK_ITEM_11, sizeof(MRASTEVDEF->CHK_ITEM_11));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_12, MRASTEVDEF_N->CHK_ITEM_12, sizeof(MRASTEVDEF->CHK_ITEM_12));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_13, MRASTEVDEF_N->CHK_ITEM_13, sizeof(MRASTEVDEF->CHK_ITEM_13));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_14, MRASTEVDEF_N->CHK_ITEM_14, sizeof(MRASTEVDEF->CHK_ITEM_14));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_15, MRASTEVDEF_N->CHK_ITEM_15, sizeof(MRASTEVDEF->CHK_ITEM_15));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_16, MRASTEVDEF_N->CHK_ITEM_16, sizeof(MRASTEVDEF->CHK_ITEM_16));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_17, MRASTEVDEF_N->CHK_ITEM_17, sizeof(MRASTEVDEF->CHK_ITEM_17));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_18, MRASTEVDEF_N->CHK_ITEM_18, sizeof(MRASTEVDEF->CHK_ITEM_18));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_19, MRASTEVDEF_N->CHK_ITEM_19, sizeof(MRASTEVDEF->CHK_ITEM_19));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_20, MRASTEVDEF_N->CHK_ITEM_20, sizeof(MRASTEVDEF->CHK_ITEM_20));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_21, MRASTEVDEF_N->CHK_ITEM_21, sizeof(MRASTEVDEF->CHK_ITEM_21));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_22, MRASTEVDEF_N->CHK_ITEM_22, sizeof(MRASTEVDEF->CHK_ITEM_22));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_23, MRASTEVDEF_N->CHK_ITEM_23, sizeof(MRASTEVDEF->CHK_ITEM_23));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_24, MRASTEVDEF_N->CHK_ITEM_24, sizeof(MRASTEVDEF->CHK_ITEM_24));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_25, MRASTEVDEF_N->CHK_ITEM_25, sizeof(MRASTEVDEF->CHK_ITEM_25));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_26, MRASTEVDEF_N->CHK_ITEM_26, sizeof(MRASTEVDEF->CHK_ITEM_26));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_27, MRASTEVDEF_N->CHK_ITEM_27, sizeof(MRASTEVDEF->CHK_ITEM_27));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_28, MRASTEVDEF_N->CHK_ITEM_28, sizeof(MRASTEVDEF->CHK_ITEM_28));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_29, MRASTEVDEF_N->CHK_ITEM_29, sizeof(MRASTEVDEF->CHK_ITEM_29));
    MEMCPY_DN(MRASTEVDEF->CHK_ITEM_30, MRASTEVDEF_N->CHK_ITEM_30, sizeof(MRASTEVDEF->CHK_ITEM_30));
    MRASTEVDEF->CHK_FLAG_1 = MRASTEVDEF_N->CHK_FLAG_1[0];
    MRASTEVDEF->CHK_FLAG_2 = MRASTEVDEF_N->CHK_FLAG_2[0];
    MRASTEVDEF->CHK_FLAG_3 = MRASTEVDEF_N->CHK_FLAG_3[0];
    MRASTEVDEF->CHK_FLAG_4 = MRASTEVDEF_N->CHK_FLAG_4[0];
    MRASTEVDEF->CHK_FLAG_5 = MRASTEVDEF_N->CHK_FLAG_5[0];
    MRASTEVDEF->CHK_FLAG_6 = MRASTEVDEF_N->CHK_FLAG_6[0];
    MRASTEVDEF->CHK_FLAG_7 = MRASTEVDEF_N->CHK_FLAG_7[0];
    MRASTEVDEF->CHK_FLAG_8 = MRASTEVDEF_N->CHK_FLAG_8[0];
    MRASTEVDEF->CHK_FLAG_9 = MRASTEVDEF_N->CHK_FLAG_9[0];
    MRASTEVDEF->CHK_FLAG_10 = MRASTEVDEF_N->CHK_FLAG_10[0];
    MRASTEVDEF->CHK_FLAG_11 = MRASTEVDEF_N->CHK_FLAG_11[0];
    MRASTEVDEF->CHK_FLAG_12 = MRASTEVDEF_N->CHK_FLAG_12[0];
    MRASTEVDEF->CHK_FLAG_13 = MRASTEVDEF_N->CHK_FLAG_13[0];
    MRASTEVDEF->CHK_FLAG_14 = MRASTEVDEF_N->CHK_FLAG_14[0];
    MRASTEVDEF->CHK_FLAG_15 = MRASTEVDEF_N->CHK_FLAG_15[0];
    MRASTEVDEF->CHK_FLAG_16 = MRASTEVDEF_N->CHK_FLAG_16[0];
    MRASTEVDEF->CHK_FLAG_17 = MRASTEVDEF_N->CHK_FLAG_17[0];
    MRASTEVDEF->CHK_FLAG_18 = MRASTEVDEF_N->CHK_FLAG_18[0];
    MRASTEVDEF->CHK_FLAG_19 = MRASTEVDEF_N->CHK_FLAG_19[0];
    MRASTEVDEF->CHK_FLAG_20 = MRASTEVDEF_N->CHK_FLAG_20[0];
    MRASTEVDEF->CHK_FLAG_21 = MRASTEVDEF_N->CHK_FLAG_21[0];
    MRASTEVDEF->CHK_FLAG_22 = MRASTEVDEF_N->CHK_FLAG_22[0];
    MRASTEVDEF->CHK_FLAG_23 = MRASTEVDEF_N->CHK_FLAG_23[0];
    MRASTEVDEF->CHK_FLAG_24 = MRASTEVDEF_N->CHK_FLAG_24[0];
    MRASTEVDEF->CHK_FLAG_25 = MRASTEVDEF_N->CHK_FLAG_25[0];
    MRASTEVDEF->CHK_FLAG_26 = MRASTEVDEF_N->CHK_FLAG_26[0];
    MRASTEVDEF->CHK_FLAG_27 = MRASTEVDEF_N->CHK_FLAG_27[0];
    MRASTEVDEF->CHK_FLAG_28 = MRASTEVDEF_N->CHK_FLAG_28[0];
    MRASTEVDEF->CHK_FLAG_29 = MRASTEVDEF_N->CHK_FLAG_29[0];
    MRASTEVDEF->CHK_FLAG_30 = MRASTEVDEF_N->CHK_FLAG_30[0];
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_1, MRASTEVDEF_N->CHK_VALUE_1, sizeof(MRASTEVDEF->CHK_VALUE_1));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_2, MRASTEVDEF_N->CHK_VALUE_2, sizeof(MRASTEVDEF->CHK_VALUE_2));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_3, MRASTEVDEF_N->CHK_VALUE_3, sizeof(MRASTEVDEF->CHK_VALUE_3));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_4, MRASTEVDEF_N->CHK_VALUE_4, sizeof(MRASTEVDEF->CHK_VALUE_4));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_5, MRASTEVDEF_N->CHK_VALUE_5, sizeof(MRASTEVDEF->CHK_VALUE_5));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_6, MRASTEVDEF_N->CHK_VALUE_6, sizeof(MRASTEVDEF->CHK_VALUE_6));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_7, MRASTEVDEF_N->CHK_VALUE_7, sizeof(MRASTEVDEF->CHK_VALUE_7));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_8, MRASTEVDEF_N->CHK_VALUE_8, sizeof(MRASTEVDEF->CHK_VALUE_8));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_9, MRASTEVDEF_N->CHK_VALUE_9, sizeof(MRASTEVDEF->CHK_VALUE_9));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_10, MRASTEVDEF_N->CHK_VALUE_10, sizeof(MRASTEVDEF->CHK_VALUE_10));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_11, MRASTEVDEF_N->CHK_VALUE_11, sizeof(MRASTEVDEF->CHK_VALUE_11));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_12, MRASTEVDEF_N->CHK_VALUE_12, sizeof(MRASTEVDEF->CHK_VALUE_12));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_13, MRASTEVDEF_N->CHK_VALUE_13, sizeof(MRASTEVDEF->CHK_VALUE_13));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_14, MRASTEVDEF_N->CHK_VALUE_14, sizeof(MRASTEVDEF->CHK_VALUE_14));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_15, MRASTEVDEF_N->CHK_VALUE_15, sizeof(MRASTEVDEF->CHK_VALUE_15));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_16, MRASTEVDEF_N->CHK_VALUE_16, sizeof(MRASTEVDEF->CHK_VALUE_16));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_17, MRASTEVDEF_N->CHK_VALUE_17, sizeof(MRASTEVDEF->CHK_VALUE_17));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_18, MRASTEVDEF_N->CHK_VALUE_18, sizeof(MRASTEVDEF->CHK_VALUE_18));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_19, MRASTEVDEF_N->CHK_VALUE_19, sizeof(MRASTEVDEF->CHK_VALUE_19));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_20, MRASTEVDEF_N->CHK_VALUE_20, sizeof(MRASTEVDEF->CHK_VALUE_20));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_21, MRASTEVDEF_N->CHK_VALUE_21, sizeof(MRASTEVDEF->CHK_VALUE_21));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_22, MRASTEVDEF_N->CHK_VALUE_22, sizeof(MRASTEVDEF->CHK_VALUE_22));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_23, MRASTEVDEF_N->CHK_VALUE_23, sizeof(MRASTEVDEF->CHK_VALUE_23));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_24, MRASTEVDEF_N->CHK_VALUE_24, sizeof(MRASTEVDEF->CHK_VALUE_24));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_25, MRASTEVDEF_N->CHK_VALUE_25, sizeof(MRASTEVDEF->CHK_VALUE_25));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_26, MRASTEVDEF_N->CHK_VALUE_26, sizeof(MRASTEVDEF->CHK_VALUE_26));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_27, MRASTEVDEF_N->CHK_VALUE_27, sizeof(MRASTEVDEF->CHK_VALUE_27));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_28, MRASTEVDEF_N->CHK_VALUE_28, sizeof(MRASTEVDEF->CHK_VALUE_28));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_29, MRASTEVDEF_N->CHK_VALUE_29, sizeof(MRASTEVDEF->CHK_VALUE_29));
    MEMCPY_DN(MRASTEVDEF->CHK_VALUE_30, MRASTEVDEF_N->CHK_VALUE_30, sizeof(MRASTEVDEF->CHK_VALUE_30));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_1, MRASTEVDEF_N->CHK_FIELD_1, sizeof(MRASTEVDEF->CHK_FIELD_1));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_2, MRASTEVDEF_N->CHK_FIELD_2, sizeof(MRASTEVDEF->CHK_FIELD_2));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_3, MRASTEVDEF_N->CHK_FIELD_3, sizeof(MRASTEVDEF->CHK_FIELD_3));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_4, MRASTEVDEF_N->CHK_FIELD_4, sizeof(MRASTEVDEF->CHK_FIELD_4));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_5, MRASTEVDEF_N->CHK_FIELD_5, sizeof(MRASTEVDEF->CHK_FIELD_5));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_6, MRASTEVDEF_N->CHK_FIELD_6, sizeof(MRASTEVDEF->CHK_FIELD_6));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_7, MRASTEVDEF_N->CHK_FIELD_7, sizeof(MRASTEVDEF->CHK_FIELD_7));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_8, MRASTEVDEF_N->CHK_FIELD_8, sizeof(MRASTEVDEF->CHK_FIELD_8));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_9, MRASTEVDEF_N->CHK_FIELD_9, sizeof(MRASTEVDEF->CHK_FIELD_9));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_10, MRASTEVDEF_N->CHK_FIELD_10, sizeof(MRASTEVDEF->CHK_FIELD_10));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_11, MRASTEVDEF_N->CHK_FIELD_11, sizeof(MRASTEVDEF->CHK_FIELD_11));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_12, MRASTEVDEF_N->CHK_FIELD_12, sizeof(MRASTEVDEF->CHK_FIELD_12));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_13, MRASTEVDEF_N->CHK_FIELD_13, sizeof(MRASTEVDEF->CHK_FIELD_13));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_14, MRASTEVDEF_N->CHK_FIELD_14, sizeof(MRASTEVDEF->CHK_FIELD_14));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_15, MRASTEVDEF_N->CHK_FIELD_15, sizeof(MRASTEVDEF->CHK_FIELD_15));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_16, MRASTEVDEF_N->CHK_FIELD_16, sizeof(MRASTEVDEF->CHK_FIELD_16));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_17, MRASTEVDEF_N->CHK_FIELD_17, sizeof(MRASTEVDEF->CHK_FIELD_17));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_18, MRASTEVDEF_N->CHK_FIELD_18, sizeof(MRASTEVDEF->CHK_FIELD_18));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_19, MRASTEVDEF_N->CHK_FIELD_19, sizeof(MRASTEVDEF->CHK_FIELD_19));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_20, MRASTEVDEF_N->CHK_FIELD_20, sizeof(MRASTEVDEF->CHK_FIELD_20));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_21, MRASTEVDEF_N->CHK_FIELD_21, sizeof(MRASTEVDEF->CHK_FIELD_21));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_22, MRASTEVDEF_N->CHK_FIELD_22, sizeof(MRASTEVDEF->CHK_FIELD_22));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_23, MRASTEVDEF_N->CHK_FIELD_23, sizeof(MRASTEVDEF->CHK_FIELD_23));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_24, MRASTEVDEF_N->CHK_FIELD_24, sizeof(MRASTEVDEF->CHK_FIELD_24));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_25, MRASTEVDEF_N->CHK_FIELD_25, sizeof(MRASTEVDEF->CHK_FIELD_25));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_26, MRASTEVDEF_N->CHK_FIELD_26, sizeof(MRASTEVDEF->CHK_FIELD_26));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_27, MRASTEVDEF_N->CHK_FIELD_27, sizeof(MRASTEVDEF->CHK_FIELD_27));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_28, MRASTEVDEF_N->CHK_FIELD_28, sizeof(MRASTEVDEF->CHK_FIELD_28));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_29, MRASTEVDEF_N->CHK_FIELD_29, sizeof(MRASTEVDEF->CHK_FIELD_29));
    MEMCPY_DN(MRASTEVDEF->CHK_FIELD_30, MRASTEVDEF_N->CHK_FIELD_30, sizeof(MRASTEVDEF->CHK_FIELD_30));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_1, MRASTEVDEF_N->CHG_ITEM_1, sizeof(MRASTEVDEF->CHG_ITEM_1));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_2, MRASTEVDEF_N->CHG_ITEM_2, sizeof(MRASTEVDEF->CHG_ITEM_2));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_3, MRASTEVDEF_N->CHG_ITEM_3, sizeof(MRASTEVDEF->CHG_ITEM_3));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_4, MRASTEVDEF_N->CHG_ITEM_4, sizeof(MRASTEVDEF->CHG_ITEM_4));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_5, MRASTEVDEF_N->CHG_ITEM_5, sizeof(MRASTEVDEF->CHG_ITEM_5));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_6, MRASTEVDEF_N->CHG_ITEM_6, sizeof(MRASTEVDEF->CHG_ITEM_6));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_7, MRASTEVDEF_N->CHG_ITEM_7, sizeof(MRASTEVDEF->CHG_ITEM_7));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_8, MRASTEVDEF_N->CHG_ITEM_8, sizeof(MRASTEVDEF->CHG_ITEM_8));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_9, MRASTEVDEF_N->CHG_ITEM_9, sizeof(MRASTEVDEF->CHG_ITEM_9));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_10, MRASTEVDEF_N->CHG_ITEM_10, sizeof(MRASTEVDEF->CHG_ITEM_10));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_11, MRASTEVDEF_N->CHG_ITEM_11, sizeof(MRASTEVDEF->CHG_ITEM_11));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_12, MRASTEVDEF_N->CHG_ITEM_12, sizeof(MRASTEVDEF->CHG_ITEM_12));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_13, MRASTEVDEF_N->CHG_ITEM_13, sizeof(MRASTEVDEF->CHG_ITEM_13));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_14, MRASTEVDEF_N->CHG_ITEM_14, sizeof(MRASTEVDEF->CHG_ITEM_14));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_15, MRASTEVDEF_N->CHG_ITEM_15, sizeof(MRASTEVDEF->CHG_ITEM_15));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_16, MRASTEVDEF_N->CHG_ITEM_16, sizeof(MRASTEVDEF->CHG_ITEM_16));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_17, MRASTEVDEF_N->CHG_ITEM_17, sizeof(MRASTEVDEF->CHG_ITEM_17));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_18, MRASTEVDEF_N->CHG_ITEM_18, sizeof(MRASTEVDEF->CHG_ITEM_18));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_19, MRASTEVDEF_N->CHG_ITEM_19, sizeof(MRASTEVDEF->CHG_ITEM_19));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_20, MRASTEVDEF_N->CHG_ITEM_20, sizeof(MRASTEVDEF->CHG_ITEM_20));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_21, MRASTEVDEF_N->CHG_ITEM_21, sizeof(MRASTEVDEF->CHG_ITEM_21));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_22, MRASTEVDEF_N->CHG_ITEM_22, sizeof(MRASTEVDEF->CHG_ITEM_22));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_23, MRASTEVDEF_N->CHG_ITEM_23, sizeof(MRASTEVDEF->CHG_ITEM_23));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_24, MRASTEVDEF_N->CHG_ITEM_24, sizeof(MRASTEVDEF->CHG_ITEM_24));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_25, MRASTEVDEF_N->CHG_ITEM_25, sizeof(MRASTEVDEF->CHG_ITEM_25));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_26, MRASTEVDEF_N->CHG_ITEM_26, sizeof(MRASTEVDEF->CHG_ITEM_26));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_27, MRASTEVDEF_N->CHG_ITEM_27, sizeof(MRASTEVDEF->CHG_ITEM_27));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_28, MRASTEVDEF_N->CHG_ITEM_28, sizeof(MRASTEVDEF->CHG_ITEM_28));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_29, MRASTEVDEF_N->CHG_ITEM_29, sizeof(MRASTEVDEF->CHG_ITEM_29));
    MEMCPY_DN(MRASTEVDEF->CHG_ITEM_30, MRASTEVDEF_N->CHG_ITEM_30, sizeof(MRASTEVDEF->CHG_ITEM_30));
    MRASTEVDEF->CHG_FLAG_1 = MRASTEVDEF_N->CHG_FLAG_1[0];
    MRASTEVDEF->CHG_FLAG_2 = MRASTEVDEF_N->CHG_FLAG_2[0];
    MRASTEVDEF->CHG_FLAG_3 = MRASTEVDEF_N->CHG_FLAG_3[0];
    MRASTEVDEF->CHG_FLAG_4 = MRASTEVDEF_N->CHG_FLAG_4[0];
    MRASTEVDEF->CHG_FLAG_5 = MRASTEVDEF_N->CHG_FLAG_5[0];
    MRASTEVDEF->CHG_FLAG_6 = MRASTEVDEF_N->CHG_FLAG_6[0];
    MRASTEVDEF->CHG_FLAG_7 = MRASTEVDEF_N->CHG_FLAG_7[0];
    MRASTEVDEF->CHG_FLAG_8 = MRASTEVDEF_N->CHG_FLAG_8[0];
    MRASTEVDEF->CHG_FLAG_9 = MRASTEVDEF_N->CHG_FLAG_9[0];
    MRASTEVDEF->CHG_FLAG_10 = MRASTEVDEF_N->CHG_FLAG_10[0];
    MRASTEVDEF->CHG_FLAG_11 = MRASTEVDEF_N->CHG_FLAG_11[0];
    MRASTEVDEF->CHG_FLAG_12 = MRASTEVDEF_N->CHG_FLAG_12[0];
    MRASTEVDEF->CHG_FLAG_13 = MRASTEVDEF_N->CHG_FLAG_13[0];
    MRASTEVDEF->CHG_FLAG_14 = MRASTEVDEF_N->CHG_FLAG_14[0];
    MRASTEVDEF->CHG_FLAG_15 = MRASTEVDEF_N->CHG_FLAG_15[0];
    MRASTEVDEF->CHG_FLAG_16 = MRASTEVDEF_N->CHG_FLAG_16[0];
    MRASTEVDEF->CHG_FLAG_17 = MRASTEVDEF_N->CHG_FLAG_17[0];
    MRASTEVDEF->CHG_FLAG_18 = MRASTEVDEF_N->CHG_FLAG_18[0];
    MRASTEVDEF->CHG_FLAG_19 = MRASTEVDEF_N->CHG_FLAG_19[0];
    MRASTEVDEF->CHG_FLAG_20 = MRASTEVDEF_N->CHG_FLAG_20[0];
    MRASTEVDEF->CHG_FLAG_21 = MRASTEVDEF_N->CHG_FLAG_21[0];
    MRASTEVDEF->CHG_FLAG_22 = MRASTEVDEF_N->CHG_FLAG_22[0];
    MRASTEVDEF->CHG_FLAG_23 = MRASTEVDEF_N->CHG_FLAG_23[0];
    MRASTEVDEF->CHG_FLAG_24 = MRASTEVDEF_N->CHG_FLAG_24[0];
    MRASTEVDEF->CHG_FLAG_25 = MRASTEVDEF_N->CHG_FLAG_25[0];
    MRASTEVDEF->CHG_FLAG_26 = MRASTEVDEF_N->CHG_FLAG_26[0];
    MRASTEVDEF->CHG_FLAG_27 = MRASTEVDEF_N->CHG_FLAG_27[0];
    MRASTEVDEF->CHG_FLAG_28 = MRASTEVDEF_N->CHG_FLAG_28[0];
    MRASTEVDEF->CHG_FLAG_29 = MRASTEVDEF_N->CHG_FLAG_29[0];
    MRASTEVDEF->CHG_FLAG_30 = MRASTEVDEF_N->CHG_FLAG_30[0];
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_1, MRASTEVDEF_N->CHG_VALUE_1, sizeof(MRASTEVDEF->CHG_VALUE_1));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_2, MRASTEVDEF_N->CHG_VALUE_2, sizeof(MRASTEVDEF->CHG_VALUE_2));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_3, MRASTEVDEF_N->CHG_VALUE_3, sizeof(MRASTEVDEF->CHG_VALUE_3));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_4, MRASTEVDEF_N->CHG_VALUE_4, sizeof(MRASTEVDEF->CHG_VALUE_4));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_5, MRASTEVDEF_N->CHG_VALUE_5, sizeof(MRASTEVDEF->CHG_VALUE_5));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_6, MRASTEVDEF_N->CHG_VALUE_6, sizeof(MRASTEVDEF->CHG_VALUE_6));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_7, MRASTEVDEF_N->CHG_VALUE_7, sizeof(MRASTEVDEF->CHG_VALUE_7));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_8, MRASTEVDEF_N->CHG_VALUE_8, sizeof(MRASTEVDEF->CHG_VALUE_8));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_9, MRASTEVDEF_N->CHG_VALUE_9, sizeof(MRASTEVDEF->CHG_VALUE_9));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_10, MRASTEVDEF_N->CHG_VALUE_10, sizeof(MRASTEVDEF->CHG_VALUE_10));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_11, MRASTEVDEF_N->CHG_VALUE_11, sizeof(MRASTEVDEF->CHG_VALUE_11));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_12, MRASTEVDEF_N->CHG_VALUE_12, sizeof(MRASTEVDEF->CHG_VALUE_12));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_13, MRASTEVDEF_N->CHG_VALUE_13, sizeof(MRASTEVDEF->CHG_VALUE_13));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_14, MRASTEVDEF_N->CHG_VALUE_14, sizeof(MRASTEVDEF->CHG_VALUE_14));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_15, MRASTEVDEF_N->CHG_VALUE_15, sizeof(MRASTEVDEF->CHG_VALUE_15));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_16, MRASTEVDEF_N->CHG_VALUE_16, sizeof(MRASTEVDEF->CHG_VALUE_16));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_17, MRASTEVDEF_N->CHG_VALUE_17, sizeof(MRASTEVDEF->CHG_VALUE_17));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_18, MRASTEVDEF_N->CHG_VALUE_18, sizeof(MRASTEVDEF->CHG_VALUE_18));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_19, MRASTEVDEF_N->CHG_VALUE_19, sizeof(MRASTEVDEF->CHG_VALUE_19));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_20, MRASTEVDEF_N->CHG_VALUE_20, sizeof(MRASTEVDEF->CHG_VALUE_20));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_21, MRASTEVDEF_N->CHG_VALUE_21, sizeof(MRASTEVDEF->CHG_VALUE_21));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_22, MRASTEVDEF_N->CHG_VALUE_22, sizeof(MRASTEVDEF->CHG_VALUE_22));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_23, MRASTEVDEF_N->CHG_VALUE_23, sizeof(MRASTEVDEF->CHG_VALUE_23));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_24, MRASTEVDEF_N->CHG_VALUE_24, sizeof(MRASTEVDEF->CHG_VALUE_24));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_25, MRASTEVDEF_N->CHG_VALUE_25, sizeof(MRASTEVDEF->CHG_VALUE_25));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_26, MRASTEVDEF_N->CHG_VALUE_26, sizeof(MRASTEVDEF->CHG_VALUE_26));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_27, MRASTEVDEF_N->CHG_VALUE_27, sizeof(MRASTEVDEF->CHG_VALUE_27));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_28, MRASTEVDEF_N->CHG_VALUE_28, sizeof(MRASTEVDEF->CHG_VALUE_28));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_29, MRASTEVDEF_N->CHG_VALUE_29, sizeof(MRASTEVDEF->CHG_VALUE_29));
    MEMCPY_DN(MRASTEVDEF->CHG_VALUE_30, MRASTEVDEF_N->CHG_VALUE_30, sizeof(MRASTEVDEF->CHG_VALUE_30));
    MRASTEVDEF->CHG_OPT_1 = MRASTEVDEF_N->CHG_OPT_1[0];
    MRASTEVDEF->CHG_OPT_2 = MRASTEVDEF_N->CHG_OPT_2[0];
    MRASTEVDEF->CHG_OPT_3 = MRASTEVDEF_N->CHG_OPT_3[0];
    MRASTEVDEF->CHG_OPT_4 = MRASTEVDEF_N->CHG_OPT_4[0];
    MRASTEVDEF->CHG_OPT_5 = MRASTEVDEF_N->CHG_OPT_5[0];
    MRASTEVDEF->CHG_OPT_6 = MRASTEVDEF_N->CHG_OPT_6[0];
    MRASTEVDEF->CHG_OPT_7 = MRASTEVDEF_N->CHG_OPT_7[0];
    MRASTEVDEF->CHG_OPT_8 = MRASTEVDEF_N->CHG_OPT_8[0];
    MRASTEVDEF->CHG_OPT_9 = MRASTEVDEF_N->CHG_OPT_9[0];
    MRASTEVDEF->CHG_OPT_10 = MRASTEVDEF_N->CHG_OPT_10[0];
    MRASTEVDEF->CHG_OPT_11 = MRASTEVDEF_N->CHG_OPT_11[0];
    MRASTEVDEF->CHG_OPT_12 = MRASTEVDEF_N->CHG_OPT_12[0];
    MRASTEVDEF->CHG_OPT_13 = MRASTEVDEF_N->CHG_OPT_13[0];
    MRASTEVDEF->CHG_OPT_14 = MRASTEVDEF_N->CHG_OPT_14[0];
    MRASTEVDEF->CHG_OPT_15 = MRASTEVDEF_N->CHG_OPT_15[0];
    MRASTEVDEF->CHG_OPT_16 = MRASTEVDEF_N->CHG_OPT_16[0];
    MRASTEVDEF->CHG_OPT_17 = MRASTEVDEF_N->CHG_OPT_17[0];
    MRASTEVDEF->CHG_OPT_18 = MRASTEVDEF_N->CHG_OPT_18[0];
    MRASTEVDEF->CHG_OPT_19 = MRASTEVDEF_N->CHG_OPT_19[0];
    MRASTEVDEF->CHG_OPT_20 = MRASTEVDEF_N->CHG_OPT_20[0];
    MRASTEVDEF->CHG_OPT_21 = MRASTEVDEF_N->CHG_OPT_21[0];
    MRASTEVDEF->CHG_OPT_22 = MRASTEVDEF_N->CHG_OPT_22[0];
    MRASTEVDEF->CHG_OPT_23 = MRASTEVDEF_N->CHG_OPT_23[0];
    MRASTEVDEF->CHG_OPT_24 = MRASTEVDEF_N->CHG_OPT_24[0];
    MRASTEVDEF->CHG_OPT_25 = MRASTEVDEF_N->CHG_OPT_25[0];
    MRASTEVDEF->CHG_OPT_26 = MRASTEVDEF_N->CHG_OPT_26[0];
    MRASTEVDEF->CHG_OPT_27 = MRASTEVDEF_N->CHG_OPT_27[0];
    MRASTEVDEF->CHG_OPT_28 = MRASTEVDEF_N->CHG_OPT_28[0];
    MRASTEVDEF->CHG_OPT_29 = MRASTEVDEF_N->CHG_OPT_29[0];
    MRASTEVDEF->CHG_OPT_30 = MRASTEVDEF_N->CHG_OPT_30[0];
    MEMCPY_DN(MRASTEVDEF->CREATE_USER_ID, MRASTEVDEF_N->CREATE_USER_ID, sizeof(MRASTEVDEF->CREATE_USER_ID));
    MEMCPY_DN(MRASTEVDEF->CREATE_TIME, MRASTEVDEF_N->CREATE_TIME, sizeof(MRASTEVDEF->CREATE_TIME));
    MEMCPY_DN(MRASTEVDEF->UPDATE_USER_ID, MRASTEVDEF_N->UPDATE_USER_ID, sizeof(MRASTEVDEF->UPDATE_USER_ID));
    MEMCPY_DN(MRASTEVDEF->UPDATE_TIME, MRASTEVDEF_N->UPDATE_TIME, sizeof(MRASTEVDEF->UPDATE_TIME));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_1, MRASTEVDEF_N->CHG_FIELD_1, sizeof(MRASTEVDEF->CHG_FIELD_1));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_2, MRASTEVDEF_N->CHG_FIELD_2, sizeof(MRASTEVDEF->CHG_FIELD_2));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_3, MRASTEVDEF_N->CHG_FIELD_3, sizeof(MRASTEVDEF->CHG_FIELD_3));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_4, MRASTEVDEF_N->CHG_FIELD_4, sizeof(MRASTEVDEF->CHG_FIELD_4));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_5, MRASTEVDEF_N->CHG_FIELD_5, sizeof(MRASTEVDEF->CHG_FIELD_5));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_6, MRASTEVDEF_N->CHG_FIELD_6, sizeof(MRASTEVDEF->CHG_FIELD_6));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_7, MRASTEVDEF_N->CHG_FIELD_7, sizeof(MRASTEVDEF->CHG_FIELD_7));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_8, MRASTEVDEF_N->CHG_FIELD_8, sizeof(MRASTEVDEF->CHG_FIELD_8));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_9, MRASTEVDEF_N->CHG_FIELD_9, sizeof(MRASTEVDEF->CHG_FIELD_9));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_10, MRASTEVDEF_N->CHG_FIELD_10, sizeof(MRASTEVDEF->CHG_FIELD_10));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_11, MRASTEVDEF_N->CHG_FIELD_11, sizeof(MRASTEVDEF->CHG_FIELD_11));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_12, MRASTEVDEF_N->CHG_FIELD_12, sizeof(MRASTEVDEF->CHG_FIELD_12));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_13, MRASTEVDEF_N->CHG_FIELD_13, sizeof(MRASTEVDEF->CHG_FIELD_13));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_14, MRASTEVDEF_N->CHG_FIELD_14, sizeof(MRASTEVDEF->CHG_FIELD_14));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_15, MRASTEVDEF_N->CHG_FIELD_15, sizeof(MRASTEVDEF->CHG_FIELD_15));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_16, MRASTEVDEF_N->CHG_FIELD_16, sizeof(MRASTEVDEF->CHG_FIELD_16));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_17, MRASTEVDEF_N->CHG_FIELD_17, sizeof(MRASTEVDEF->CHG_FIELD_17));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_18, MRASTEVDEF_N->CHG_FIELD_18, sizeof(MRASTEVDEF->CHG_FIELD_18));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_19, MRASTEVDEF_N->CHG_FIELD_19, sizeof(MRASTEVDEF->CHG_FIELD_19));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_20, MRASTEVDEF_N->CHG_FIELD_20, sizeof(MRASTEVDEF->CHG_FIELD_20));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_21, MRASTEVDEF_N->CHG_FIELD_21, sizeof(MRASTEVDEF->CHG_FIELD_21));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_22, MRASTEVDEF_N->CHG_FIELD_22, sizeof(MRASTEVDEF->CHG_FIELD_22));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_23, MRASTEVDEF_N->CHG_FIELD_23, sizeof(MRASTEVDEF->CHG_FIELD_23));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_24, MRASTEVDEF_N->CHG_FIELD_24, sizeof(MRASTEVDEF->CHG_FIELD_24));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_25, MRASTEVDEF_N->CHG_FIELD_25, sizeof(MRASTEVDEF->CHG_FIELD_25));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_26, MRASTEVDEF_N->CHG_FIELD_26, sizeof(MRASTEVDEF->CHG_FIELD_26));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_27, MRASTEVDEF_N->CHG_FIELD_27, sizeof(MRASTEVDEF->CHG_FIELD_27));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_28, MRASTEVDEF_N->CHG_FIELD_28, sizeof(MRASTEVDEF->CHG_FIELD_28));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_29, MRASTEVDEF_N->CHG_FIELD_29, sizeof(MRASTEVDEF->CHG_FIELD_29));
    MEMCPY_DN(MRASTEVDEF->CHG_FIELD_30, MRASTEVDEF_N->CHG_FIELD_30, sizeof(MRASTEVDEF->CHG_FIELD_30));
}


