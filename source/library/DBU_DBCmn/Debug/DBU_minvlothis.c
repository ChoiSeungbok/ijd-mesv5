
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
    "DBU_minvlothis.pc"
};


static unsigned int sqlctx = 9418307;


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
            void  *sqhstv[123];
   unsigned int   sqhstl[123];
            int   sqhsts[123];
            void  *sqindv[123];
            int   sqinds[123];
   unsigned int   sqharm[123];
   unsigned int   *sqharc[123];
   unsigned short  sqadto[123];
   unsigned short  sqtdso[123];
} sqlstm = {13,123};

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
"_10 ,ORG_INV_LOT_ID ,FROM_TO_DIV ,FR\
OM_TO_INV_LOT_ID ,FROM_TO_HIST_SEQ ,OLD_ACTIVE_HIST_SEQ ,OLD_FACTORY ,OLD_MAT\
_ID ,OLD_AREA_ID ,OLD_SUB_AREA_ID ,OLD_OPER ,OLD_QTY ,OLD_QTY_2 ,OLD_QTY_3 ,O\
LD_UNIT ,OLD_UNIT_2 ,OLD_UNIT_3 ,CHANGE_QTY ,CHANGE_QTY_2 ,CHANGE_QTY_3 ,CREA\
TE_QTY ,CREATE_QTY_2 ,CREATE_QTY_3 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_\
ID ,UPDATE_TIME ,HIST_DEL_FLAG ,HIST_DEL_USER_ID ,HIST_DEL_TIME ,HIST_DEL_COM\
MENT  from MINVLOTHIS  order by FACTORY asc ,INV_LOT_ID asc ,HIST_SEQ asc    \
         ";

 static const char *sq0010 = 
"_10 ,ORG_INV_LOT_ID ,FROM_TO_DIV ,FR\
OM_TO_INV_LOT_ID ,FROM_TO_HIST_SEQ ,OLD_ACTIVE_HIST_SEQ ,OLD_FACTORY ,OLD_MAT\
_ID ,OLD_AREA_ID ,OLD_SUB_AREA_ID ,OLD_OPER ,OLD_QTY ,OLD_QTY_2 ,OLD_QTY_3 ,O\
LD_UNIT ,OLD_UNIT_2 ,OLD_UNIT_3 ,CHANGE_QTY ,CHANGE_QTY_2 ,CHANGE_QTY_3 ,CREA\
TE_QTY ,CREATE_QTY_2 ,CREATE_QTY_3 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_\
ID ,UPDATE_TIME ,HIST_DEL_FLAG ,HIST_DEL_USER_ID ,HIST_DEL_TIME ,HIST_DEL_COM\
MENT  from MINVLOTHIS where (FACTORY=:b0 and INV_LOT_ID=:b1) order by HIST_SE\
Q desc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,2139,0,4,46,0,0,123,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,
512,0,0,2,2151,0,4,328,0,0,123,3,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,
97,0,0,1,97,0,0,1,3,0,0,
1019,0,0,3,100,0,4,613,0,0,4,3,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
1050,0,0,4,92,0,4,622,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
1077,0,0,5,82,0,2,659,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
1104,0,0,6,63,0,2,666,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1127,0,0,7,1967,0,3,696,0,0,120,120,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1622,0,0,8,1974,0,5,961,0,0,120,120,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,0,
0,
2117,0,0,9,1531,0,9,1238,0,0,0,0,0,1,0,
2132,0,0,10,1541,0,9,1368,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
2155,0,0,9,0,0,13,1396,0,0,120,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2650,0,0,10,0,0,13,1520,0,0,120,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3145,0,0,9,0,0,15,1669,0,0,0,0,0,1,0,
3160,0,0,10,0,0,15,1673,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBU_minvlothis.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2020-07-31 16:58:56
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
void DBU_add_null_minvlothis(struct MINVLOTHIS_N_TAG *MINVLOTHIS_N, struct MINVLOTHIS_TAG *MINVLOTHIS);
void DBU_del_null_minvlothis(struct MINVLOTHIS_N_TAG *MINVLOTHIS_N, struct MINVLOTHIS_TAG *MINVLOTHIS);


/* SQL SELECT Function */
void DBU_select_minvlothis(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    INV_LOT_ID,
                    HIST_SEQ,
                    INV_LOT_DESC,
                    INV_LOT_TYPE,
                    TRAN_CODE,
                    TRAN_USER_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_COMMENT,
                    INV_LOT_STATUS,
                    INV_LOT_PRIORITY,
                    MAT_ID,
                    MAT_VER,
                    QTY,
                    QTY_2,
                    QTY_3,
                    UNIT,
                    UNIT_2,
                    UNIT_3,
                    ORDER_ID,
                    ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3,
                    VENDOR_ID,
					VENDOR_SITE_ID,
                    VENDOR_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    LOCATION_1,
                    LOCATION_2,
                    LOCATION_3,
                    OPER,
                    LOC_NO,
                    RES_ID,
                    PORT_ID,
                    SLOT_NO,
                    CRR_ID,
                    LOT_ID,
                    RECV_DATE,
                    RECV_QTY,
                    REASON_CODE,
                    LOAD_FLAG,
                    TRANSIT_FLAG,
                    DELETE_FLAG,
                    DELETE_CODE,
                    DELETE_TIME,
                    HOLD_FLAG,
                    HOLD_CODE,
                    INSP_FLAG,
                    INSP_ID,
                    INSP_RESULT_FLAG,
                    INV_LOT_GRADE,
                    DLV_NO,
                    DLV_SEQ,
                    PO_NO,
                    PO_SEQ,
                    BL_NO,
                    BL_SEQ,
					PO_DISTRIBUTION_ID,
                    INV_CMF_1,
                    INV_CMF_2,
                    INV_CMF_3,
                    INV_CMF_4,
                    INV_CMF_5,
                    INV_CMF_6,
                    INV_CMF_7,
                    INV_CMF_8,
                    INV_CMF_9,
                    INV_CMF_10,
                    INV_CMF_11,
                    INV_CMF_12,
                    INV_CMF_13,
                    INV_CMF_14,
                    INV_CMF_15,
                    INV_CMF_16,
                    INV_CMF_17,
                    INV_CMF_18,
                    INV_CMF_19,
                    INV_CMF_20,
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
                    ORG_INV_LOT_ID,
                    FROM_TO_DIV,
                    FROM_TO_INV_LOT_ID,
                    FROM_TO_HIST_SEQ,
                    OLD_ACTIVE_HIST_SEQ,
                    OLD_FACTORY,
                    OLD_MAT_ID,
					OLD_AREA_ID,
                    OLD_SUB_AREA_ID,
                    OLD_OPER,
                    OLD_QTY,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_UNIT,
                    OLD_UNIT_2,
                    OLD_UNIT_3,
                    CHANGE_QTY,
                    CHANGE_QTY_2,
                    CHANGE_QTY_3,
                    CREATE_QTY,
                    CREATE_QTY_2,
                    CREATE_QTY_3,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    HIST_DEL_FLAG,
                    HIST_DEL_USER_ID,
                    HIST_DEL_TIME,
                    HIST_DEL_COMMENT
                INTO 
                    :MINVLOTHIS_N.FACTORY,
                    :MINVLOTHIS_N.INV_LOT_ID,
                    :MINVLOTHIS_N.HIST_SEQ,
                    :MINVLOTHIS_N.INV_LOT_DESC,
                    :MINVLOTHIS_N.INV_LOT_TYPE,
                    :MINVLOTHIS_N.TRAN_CODE,
                    :MINVLOTHIS_N.TRAN_USER_ID,
                    :MINVLOTHIS_N.TRAN_TIME,
                    :MINVLOTHIS_N.SYS_TRAN_TIME,
                    :MINVLOTHIS_N.TRAN_COMMENT,
                    :MINVLOTHIS_N.INV_LOT_STATUS,
                    :MINVLOTHIS_N.INV_LOT_PRIORITY,
                    :MINVLOTHIS_N.MAT_ID,
                    :MINVLOTHIS_N.MAT_VER,
                    :MINVLOTHIS_N.QTY,
                    :MINVLOTHIS_N.QTY_2,
                    :MINVLOTHIS_N.QTY_3,
                    :MINVLOTHIS_N.UNIT,
                    :MINVLOTHIS_N.UNIT_2,
                    :MINVLOTHIS_N.UNIT_3,
                    :MINVLOTHIS_N.ORDER_ID,
                    :MINVLOTHIS_N.ADD_ORDER_ID_1,
                    :MINVLOTHIS_N.ADD_ORDER_ID_2,
                    :MINVLOTHIS_N.ADD_ORDER_ID_3,
                    :MINVLOTHIS_N.VENDOR_ID,
					:MINVLOTHIS_N.VENDOR_SITE_ID,
                    :MINVLOTHIS_N.VENDOR_LOT_ID,
                    :MINVLOTHIS_N.AREA_ID,
                    :MINVLOTHIS_N.SUB_AREA_ID,
                    :MINVLOTHIS_N.LOCATION_1,
                    :MINVLOTHIS_N.LOCATION_2,
                    :MINVLOTHIS_N.LOCATION_3,
                    :MINVLOTHIS_N.OPER,
                    :MINVLOTHIS_N.LOC_NO,
                    :MINVLOTHIS_N.RES_ID,
                    :MINVLOTHIS_N.PORT_ID,
                    :MINVLOTHIS_N.SLOT_NO,
                    :MINVLOTHIS_N.CRR_ID,
                    :MINVLOTHIS_N.LOT_ID,
                    :MINVLOTHIS_N.RECV_DATE,
                    :MINVLOTHIS_N.RECV_QTY,
                    :MINVLOTHIS_N.REASON_CODE,
                    :MINVLOTHIS_N.LOAD_FLAG,
                    :MINVLOTHIS_N.TRANSIT_FLAG,
                    :MINVLOTHIS_N.DELETE_FLAG,
                    :MINVLOTHIS_N.DELETE_CODE,
                    :MINVLOTHIS_N.DELETE_TIME,
                    :MINVLOTHIS_N.HOLD_FLAG,
                    :MINVLOTHIS_N.HOLD_CODE,
                    :MINVLOTHIS_N.INSP_FLAG,
                    :MINVLOTHIS_N.INSP_ID,
                    :MINVLOTHIS_N.INSP_RESULT_FLAG,
                    :MINVLOTHIS_N.INV_LOT_GRADE,
                    :MINVLOTHIS_N.DLV_NO,
                    :MINVLOTHIS_N.DLV_SEQ,
                    :MINVLOTHIS_N.PO_NO,
                    :MINVLOTHIS_N.PO_SEQ,
                    :MINVLOTHIS_N.BL_NO,
                    :MINVLOTHIS_N.BL_SEQ,
					:MINVLOTHIS_N.PO_DISTRIBUTION_ID,
                    :MINVLOTHIS_N.INV_CMF_1,
                    :MINVLOTHIS_N.INV_CMF_2,
                    :MINVLOTHIS_N.INV_CMF_3,
                    :MINVLOTHIS_N.INV_CMF_4,
                    :MINVLOTHIS_N.INV_CMF_5,
                    :MINVLOTHIS_N.INV_CMF_6,
                    :MINVLOTHIS_N.INV_CMF_7,
                    :MINVLOTHIS_N.INV_CMF_8,
                    :MINVLOTHIS_N.INV_CMF_9,
                    :MINVLOTHIS_N.INV_CMF_10,
                    :MINVLOTHIS_N.INV_CMF_11,
                    :MINVLOTHIS_N.INV_CMF_12,
                    :MINVLOTHIS_N.INV_CMF_13,
                    :MINVLOTHIS_N.INV_CMF_14,
                    :MINVLOTHIS_N.INV_CMF_15,
                    :MINVLOTHIS_N.INV_CMF_16,
                    :MINVLOTHIS_N.INV_CMF_17,
                    :MINVLOTHIS_N.INV_CMF_18,
                    :MINVLOTHIS_N.INV_CMF_19,
                    :MINVLOTHIS_N.INV_CMF_20,
                    :MINVLOTHIS_N.TRAN_CMF_1,
                    :MINVLOTHIS_N.TRAN_CMF_2,
                    :MINVLOTHIS_N.TRAN_CMF_3,
                    :MINVLOTHIS_N.TRAN_CMF_4,
                    :MINVLOTHIS_N.TRAN_CMF_5,
                    :MINVLOTHIS_N.TRAN_CMF_6,
                    :MINVLOTHIS_N.TRAN_CMF_7,
                    :MINVLOTHIS_N.TRAN_CMF_8,
                    :MINVLOTHIS_N.TRAN_CMF_9,
                    :MINVLOTHIS_N.TRAN_CMF_10,
                    :MINVLOTHIS_N.ORG_INV_LOT_ID,
                    :MINVLOTHIS_N.FROM_TO_DIV,
                    :MINVLOTHIS_N.FROM_TO_INV_LOT_ID,
                    :MINVLOTHIS_N.FROM_TO_HIST_SEQ,
                    :MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ,
                    :MINVLOTHIS_N.OLD_FACTORY,
                    :MINVLOTHIS_N.OLD_MAT_ID,
					:MINVLOTHIS_N.OLD_AREA_ID,
                    :MINVLOTHIS_N.OLD_SUB_AREA_ID,
                    :MINVLOTHIS_N.OLD_OPER,
                    :MINVLOTHIS_N.OLD_QTY,
                    :MINVLOTHIS_N.OLD_QTY_2,
                    :MINVLOTHIS_N.OLD_QTY_3,
                    :MINVLOTHIS_N.OLD_UNIT,
                    :MINVLOTHIS_N.OLD_UNIT_2,
                    :MINVLOTHIS_N.OLD_UNIT_3,
                    :MINVLOTHIS_N.CHANGE_QTY,
                    :MINVLOTHIS_N.CHANGE_QTY_2,
                    :MINVLOTHIS_N.CHANGE_QTY_3,
                    :MINVLOTHIS_N.CREATE_QTY,
                    :MINVLOTHIS_N.CREATE_QTY_2,
                    :MINVLOTHIS_N.CREATE_QTY_3,
                    :MINVLOTHIS_N.CREATE_USER_ID,
                    :MINVLOTHIS_N.CREATE_TIME,
                    :MINVLOTHIS_N.UPDATE_USER_ID,
                    :MINVLOTHIS_N.UPDATE_TIME,
                    :MINVLOTHIS_N.HIST_DEL_FLAG,
                    :MINVLOTHIS_N.HIST_DEL_USER_ID,
                    :MINVLOTHIS_N.HIST_DEL_TIME,
                    :MINVLOTHIS_N.HIST_DEL_COMMENT
                FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID
                    AND HIST_SEQ = :MINVLOTHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,INV_LOT_ID ,HIST_SEQ ,INV_LOT_DESC ,INV_LOT_T\
YPE ,TRAN_CODE ,TRAN_USER_ID ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_COMMENT ,INV_LO\
T_STATUS ,INV_LOT_PRIORITY ,MAT_ID ,MAT_VER ,QTY ,QTY_2 ,QTY_3 ,UNIT ,UNIT_2\
 ,UNIT_3 ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,VENDOR_I\
D ,VENDOR_SITE_ID ,VENDOR_LOT_ID ,AREA_ID ,SUB_AREA_ID ,LOCATION_1 ,LOCATION\
_2 ,LOCATION_3 ,OPER ,LOC_NO ,RES_ID ,PORT_ID ,SLOT_NO ,CRR_ID ,LOT_ID ,RECV\
_DATE ,RECV_QTY ,REASON_CODE ,LOAD_FLAG ,TRANSIT_FLAG ,DELETE_FLAG ,DELETE_C\
ODE ,DELETE_TIME ,HOLD_FLAG ,HOLD_CODE ,INSP_FLAG ,INSP_ID ,INSP_RESULT_FLAG\
 ,INV_LOT_GRADE ,DLV_NO ,DLV_SEQ ,PO_NO ,PO_SEQ ,BL_NO ,BL_SEQ ,PO_DISTRIBUT\
ION_ID ,INV_CMF_1 ,INV_CMF_2 ,INV_CMF_3 ,INV_CMF_4 ,INV_CMF_5 ,INV_CMF_6 ,IN\
V_CMF_7 ,INV_CMF_8 ,INV_CMF_9 ,INV_CMF_10 ,INV_CMF_11 ,INV_CMF_12 ,INV_CMF_1\
3 ,INV_CMF_14 ,INV_CMF_15 ,INV_CMF_16 ,INV_CMF_17 ,INV_CMF_18 ,INV_CMF_19 ,I\
NV_CMF_20 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_\
CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF");
            sqlbuft((void **)0,
              "_10 ,ORG_INV_LOT_ID ,FROM_TO_DIV ,FROM_TO_INV_LOT_ID ,FROM_TO\
_HIST_SEQ ,OLD_ACTIVE_HIST_SEQ ,OLD_FACTORY ,OLD_MAT_ID ,OLD_AREA_ID ,OLD_SU\
B_AREA_ID ,OLD_OPER ,OLD_QTY ,OLD_QTY_2 ,OLD_QTY_3 ,OLD_UNIT ,OLD_UNIT_2 ,OL\
D_UNIT_3 ,CHANGE_QTY ,CHANGE_QTY_2 ,CHANGE_QTY_3 ,CREATE_QTY ,CREATE_QTY_2 ,\
CREATE_QTY_3 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,HIST\
_DEL_FLAG ,HIST_DEL_USER_ID ,HIST_DEL_TIME ,HIST_DEL_COMMENT into :b0,:b1,:b\
2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:\
b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b\
34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b4\
9,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64\
,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,\
:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:\
b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b10\
8,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:");
            sqlstm.stmt = "b117,:b118,:b119  from MINVLOTHIS where ((FACTOR\
Y=:b0 and INV_LOT_ID=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MINVLOTHIS_N.INV_LOT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MINVLOTHIS_N.INV_LOT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MINVLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )13;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MINVLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MINVLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MINVLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MINVLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[9] = (unsigned int  )401;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MINVLOTHIS_N.INV_LOT_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MINVLOTHIS_N.INV_LOT_PRIORITY);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MINVLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MINVLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MINVLOTHIS_N.QTY);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MINVLOTHIS_N.QTY_2);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MINVLOTHIS_N.QTY_3);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MINVLOTHIS_N.UNIT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MINVLOTHIS_N.UNIT_2);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MINVLOTHIS_N.UNIT_3);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MINVLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MINVLOTHIS_N.VENDOR_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MINVLOTHIS_N.VENDOR_SITE_ID);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MINVLOTHIS_N.VENDOR_LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MINVLOTHIS_N.AREA_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MINVLOTHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MINVLOTHIS_N.LOCATION_1);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MINVLOTHIS_N.LOCATION_2);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MINVLOTHIS_N.LOCATION_3);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MINVLOTHIS_N.OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MINVLOTHIS_N.LOC_NO);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MINVLOTHIS_N.RES_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MINVLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MINVLOTHIS_N.SLOT_NO);
            sqlstm.sqhstl[36] = (unsigned int  )11;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MINVLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MINVLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MINVLOTHIS_N.RECV_DATE);
            sqlstm.sqhstl[39] = (unsigned int  )9;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MINVLOTHIS_N.RECV_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MINVLOTHIS_N.REASON_CODE);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MINVLOTHIS_N.LOAD_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MINVLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MINVLOTHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MINVLOTHIS_N.DELETE_CODE);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MINVLOTHIS_N.DELETE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )15;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MINVLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MINVLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MINVLOTHIS_N.INSP_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MINVLOTHIS_N.INSP_ID);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MINVLOTHIS_N.INSP_RESULT_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MINVLOTHIS_N.INV_LOT_GRADE);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MINVLOTHIS_N.DLV_NO);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MINVLOTHIS_N.DLV_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MINVLOTHIS_N.PO_NO);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MINVLOTHIS_N.PO_SEQ);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MINVLOTHIS_N.BL_NO);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MINVLOTHIS_N.BL_SEQ);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MINVLOTHIS_N.PO_DISTRIBUTION_ID);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MINVLOTHIS_N.INV_CMF_1);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MINVLOTHIS_N.INV_CMF_2);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MINVLOTHIS_N.INV_CMF_3);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MINVLOTHIS_N.INV_CMF_4);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MINVLOTHIS_N.INV_CMF_5);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MINVLOTHIS_N.INV_CMF_6);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MINVLOTHIS_N.INV_CMF_7);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MINVLOTHIS_N.INV_CMF_8);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MINVLOTHIS_N.INV_CMF_9);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MINVLOTHIS_N.INV_CMF_10);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MINVLOTHIS_N.INV_CMF_11);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MINVLOTHIS_N.INV_CMF_12);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MINVLOTHIS_N.INV_CMF_13);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MINVLOTHIS_N.INV_CMF_14);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MINVLOTHIS_N.INV_CMF_15);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MINVLOTHIS_N.INV_CMF_16);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MINVLOTHIS_N.INV_CMF_17);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MINVLOTHIS_N.INV_CMF_18);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MINVLOTHIS_N.INV_CMF_19);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MINVLOTHIS_N.INV_CMF_20);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MINVLOTHIS_N.ORG_INV_LOT_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MINVLOTHIS_N.FROM_TO_DIV);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MINVLOTHIS_N.FROM_TO_INV_LOT_ID);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)&(MINVLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[93] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)&(MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[94] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MINVLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[95] = (unsigned int  )11;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MINVLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MINVLOTHIS_N.OLD_AREA_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MINVLOTHIS_N.OLD_SUB_AREA_ID);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MINVLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[99] = (unsigned int  )11;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)&(MINVLOTHIS_N.OLD_QTY);
            sqlstm.sqhstl[100] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[101] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[102] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MINVLOTHIS_N.OLD_UNIT);
            sqlstm.sqhstl[103] = (unsigned int  )11;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_2);
            sqlstm.sqhstl[104] = (unsigned int  )11;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_3);
            sqlstm.sqhstl[105] = (unsigned int  )11;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY);
            sqlstm.sqhstl[106] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_2);
            sqlstm.sqhstl[107] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_3);
            sqlstm.sqhstl[108] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY);
            sqlstm.sqhstl[109] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MINVLOTHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[112] = (unsigned int  )21;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MINVLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[113] = (unsigned int  )15;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MINVLOTHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[114] = (unsigned int  )21;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MINVLOTHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[115] = (unsigned int  )15;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MINVLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[116] = (unsigned int  )2;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MINVLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MINVLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[118] = (unsigned int  )15;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MINVLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[119] = (unsigned int  )401;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[120] = (unsigned int  )11;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[121] = (unsigned int  )26;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
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
        DBU_del_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    }

    DB_stop_query_timer("DBU_select_minvlothis", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBU_select_minvlothis_for_update(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                    FACTORY,
                    INV_LOT_ID,
                    HIST_SEQ,
                    INV_LOT_DESC,
                    INV_LOT_TYPE,
                    TRAN_CODE,
                    TRAN_USER_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_COMMENT,
                    INV_LOT_STATUS,
                    INV_LOT_PRIORITY,
                    MAT_ID,
                    MAT_VER,
                    QTY,
                    QTY_2,
                    QTY_3,
                    UNIT,
                    UNIT_2,
                    UNIT_3,
                    ORDER_ID,
                    ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3,
                    VENDOR_ID,
					VENDOR_SITE_ID,
                    VENDOR_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    LOCATION_1,
                    LOCATION_2,
                    LOCATION_3,
                    OPER,
                    LOC_NO,
                    RES_ID,
                    PORT_ID,
                    SLOT_NO,
                    CRR_ID,
                    LOT_ID,
                    RECV_DATE,
                    RECV_QTY,
                    REASON_CODE,
                    LOAD_FLAG,
                    TRANSIT_FLAG,
                    DELETE_FLAG,
                    DELETE_CODE,
                    DELETE_TIME,
                    HOLD_FLAG,
                    HOLD_CODE,
                    INSP_FLAG,
                    INSP_ID,
                    INSP_RESULT_FLAG,
                    INV_LOT_GRADE,
                    DLV_NO,
                    DLV_SEQ,
                    PO_NO,
                    PO_SEQ,
                    BL_NO,
                    BL_SEQ,
					PO_DISTRIBUTION_ID,
                    INV_CMF_1,
                    INV_CMF_2,
                    INV_CMF_3,
                    INV_CMF_4,
                    INV_CMF_5,
                    INV_CMF_6,
                    INV_CMF_7,
                    INV_CMF_8,
                    INV_CMF_9,
                    INV_CMF_10,
                    INV_CMF_11,
                    INV_CMF_12,
                    INV_CMF_13,
                    INV_CMF_14,
                    INV_CMF_15,
                    INV_CMF_16,
                    INV_CMF_17,
                    INV_CMF_18,
                    INV_CMF_19,
                    INV_CMF_20,
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
                    ORG_INV_LOT_ID,
                    FROM_TO_DIV,
                    FROM_TO_INV_LOT_ID,
                    FROM_TO_HIST_SEQ,
                    OLD_ACTIVE_HIST_SEQ,
                    OLD_FACTORY,
                    OLD_MAT_ID,
					OLD_AREA_ID,
                    OLD_SUB_AREA_ID,
                    OLD_OPER,
                    OLD_QTY,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_UNIT,
                    OLD_UNIT_2,
                    OLD_UNIT_3,
                    CHANGE_QTY,
                    CHANGE_QTY_2,
                    CHANGE_QTY_3,
                    CREATE_QTY,
                    CREATE_QTY_2,
                    CREATE_QTY_3,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    HIST_DEL_FLAG,
                    HIST_DEL_USER_ID,
                    HIST_DEL_TIME,
                    HIST_DEL_COMMENT
                INTO 
                    :MINVLOTHIS_N.FACTORY,
                    :MINVLOTHIS_N.INV_LOT_ID,
                    :MINVLOTHIS_N.HIST_SEQ,
                    :MINVLOTHIS_N.INV_LOT_DESC,
                    :MINVLOTHIS_N.INV_LOT_TYPE,
                    :MINVLOTHIS_N.TRAN_CODE,
                    :MINVLOTHIS_N.TRAN_USER_ID,
                    :MINVLOTHIS_N.TRAN_TIME,
                    :MINVLOTHIS_N.SYS_TRAN_TIME,
                    :MINVLOTHIS_N.TRAN_COMMENT,
                    :MINVLOTHIS_N.INV_LOT_STATUS,
                    :MINVLOTHIS_N.INV_LOT_PRIORITY,
                    :MINVLOTHIS_N.MAT_ID,
                    :MINVLOTHIS_N.MAT_VER,
                    :MINVLOTHIS_N.QTY,
                    :MINVLOTHIS_N.QTY_2,
                    :MINVLOTHIS_N.QTY_3,
                    :MINVLOTHIS_N.UNIT,
                    :MINVLOTHIS_N.UNIT_2,
                    :MINVLOTHIS_N.UNIT_3,
                    :MINVLOTHIS_N.ORDER_ID,
                    :MINVLOTHIS_N.ADD_ORDER_ID_1,
                    :MINVLOTHIS_N.ADD_ORDER_ID_2,
                    :MINVLOTHIS_N.ADD_ORDER_ID_3,
                    :MINVLOTHIS_N.VENDOR_ID,
					:MINVLOTHIS_N.VENDOR_SITE_ID,
                    :MINVLOTHIS_N.VENDOR_LOT_ID,
                    :MINVLOTHIS_N.AREA_ID,
                    :MINVLOTHIS_N.SUB_AREA_ID,
                    :MINVLOTHIS_N.LOCATION_1,
                    :MINVLOTHIS_N.LOCATION_2,
                    :MINVLOTHIS_N.LOCATION_3,
                    :MINVLOTHIS_N.OPER,
                    :MINVLOTHIS_N.LOC_NO,
                    :MINVLOTHIS_N.RES_ID,
                    :MINVLOTHIS_N.PORT_ID,
                    :MINVLOTHIS_N.SLOT_NO,
                    :MINVLOTHIS_N.CRR_ID,
                    :MINVLOTHIS_N.LOT_ID,
                    :MINVLOTHIS_N.RECV_DATE,
                    :MINVLOTHIS_N.RECV_QTY,
                    :MINVLOTHIS_N.REASON_CODE,
                    :MINVLOTHIS_N.LOAD_FLAG,
                    :MINVLOTHIS_N.TRANSIT_FLAG,
                    :MINVLOTHIS_N.DELETE_FLAG,
                    :MINVLOTHIS_N.DELETE_CODE,
                    :MINVLOTHIS_N.DELETE_TIME,
                    :MINVLOTHIS_N.HOLD_FLAG,
                    :MINVLOTHIS_N.HOLD_CODE,
                    :MINVLOTHIS_N.INSP_FLAG,
                    :MINVLOTHIS_N.INSP_ID,
                    :MINVLOTHIS_N.INSP_RESULT_FLAG,
                    :MINVLOTHIS_N.INV_LOT_GRADE,
                    :MINVLOTHIS_N.DLV_NO,
                    :MINVLOTHIS_N.DLV_SEQ,
                    :MINVLOTHIS_N.PO_NO,
                    :MINVLOTHIS_N.PO_SEQ,
                    :MINVLOTHIS_N.BL_NO,
                    :MINVLOTHIS_N.BL_SEQ,
					:MINVLOTHIS_N.PO_DISTRIBUTION_ID,
                    :MINVLOTHIS_N.INV_CMF_1,
                    :MINVLOTHIS_N.INV_CMF_2,
                    :MINVLOTHIS_N.INV_CMF_3,
                    :MINVLOTHIS_N.INV_CMF_4,
                    :MINVLOTHIS_N.INV_CMF_5,
                    :MINVLOTHIS_N.INV_CMF_6,
                    :MINVLOTHIS_N.INV_CMF_7,
                    :MINVLOTHIS_N.INV_CMF_8,
                    :MINVLOTHIS_N.INV_CMF_9,
                    :MINVLOTHIS_N.INV_CMF_10,
                    :MINVLOTHIS_N.INV_CMF_11,
                    :MINVLOTHIS_N.INV_CMF_12,
                    :MINVLOTHIS_N.INV_CMF_13,
                    :MINVLOTHIS_N.INV_CMF_14,
                    :MINVLOTHIS_N.INV_CMF_15,
                    :MINVLOTHIS_N.INV_CMF_16,
                    :MINVLOTHIS_N.INV_CMF_17,
                    :MINVLOTHIS_N.INV_CMF_18,
                    :MINVLOTHIS_N.INV_CMF_19,
                    :MINVLOTHIS_N.INV_CMF_20,
                    :MINVLOTHIS_N.TRAN_CMF_1,
                    :MINVLOTHIS_N.TRAN_CMF_2,
                    :MINVLOTHIS_N.TRAN_CMF_3,
                    :MINVLOTHIS_N.TRAN_CMF_4,
                    :MINVLOTHIS_N.TRAN_CMF_5,
                    :MINVLOTHIS_N.TRAN_CMF_6,
                    :MINVLOTHIS_N.TRAN_CMF_7,
                    :MINVLOTHIS_N.TRAN_CMF_8,
                    :MINVLOTHIS_N.TRAN_CMF_9,
                    :MINVLOTHIS_N.TRAN_CMF_10,
                    :MINVLOTHIS_N.ORG_INV_LOT_ID,
                    :MINVLOTHIS_N.FROM_TO_DIV,
                    :MINVLOTHIS_N.FROM_TO_INV_LOT_ID,
                    :MINVLOTHIS_N.FROM_TO_HIST_SEQ,
                    :MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ,
                    :MINVLOTHIS_N.OLD_FACTORY,
                    :MINVLOTHIS_N.OLD_MAT_ID,
					:MINVLOTHIS_N.OLD_AREA_ID,
                    :MINVLOTHIS_N.OLD_SUB_AREA_ID,
                    :MINVLOTHIS_N.OLD_OPER,
                    :MINVLOTHIS_N.OLD_QTY,
                    :MINVLOTHIS_N.OLD_QTY_2,
                    :MINVLOTHIS_N.OLD_QTY_3,
                    :MINVLOTHIS_N.OLD_UNIT,
                    :MINVLOTHIS_N.OLD_UNIT_2,
                    :MINVLOTHIS_N.OLD_UNIT_3,
                    :MINVLOTHIS_N.CHANGE_QTY,
                    :MINVLOTHIS_N.CHANGE_QTY_2,
                    :MINVLOTHIS_N.CHANGE_QTY_3,
                    :MINVLOTHIS_N.CREATE_QTY,
                    :MINVLOTHIS_N.CREATE_QTY_2,
                    :MINVLOTHIS_N.CREATE_QTY_3,
                    :MINVLOTHIS_N.CREATE_USER_ID,
                    :MINVLOTHIS_N.CREATE_TIME,
                    :MINVLOTHIS_N.UPDATE_USER_ID,
                    :MINVLOTHIS_N.UPDATE_TIME,
                    :MINVLOTHIS_N.HIST_DEL_FLAG,
                    :MINVLOTHIS_N.HIST_DEL_USER_ID,
                    :MINVLOTHIS_N.HIST_DEL_TIME,
                    :MINVLOTHIS_N.HIST_DEL_COMMENT
                FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID
                    AND HIST_SEQ = :MINVLOTHIS_N.HIST_SEQ
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,INV_LOT_ID ,HIST_SEQ ,INV_LOT_DESC ,INV_LOT_T\
YPE ,TRAN_CODE ,TRAN_USER_ID ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_COMMENT ,INV_LO\
T_STATUS ,INV_LOT_PRIORITY ,MAT_ID ,MAT_VER ,QTY ,QTY_2 ,QTY_3 ,UNIT ,UNIT_2\
 ,UNIT_3 ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,VENDOR_I\
D ,VENDOR_SITE_ID ,VENDOR_LOT_ID ,AREA_ID ,SUB_AREA_ID ,LOCATION_1 ,LOCATION\
_2 ,LOCATION_3 ,OPER ,LOC_NO ,RES_ID ,PORT_ID ,SLOT_NO ,CRR_ID ,LOT_ID ,RECV\
_DATE ,RECV_QTY ,REASON_CODE ,LOAD_FLAG ,TRANSIT_FLAG ,DELETE_FLAG ,DELETE_C\
ODE ,DELETE_TIME ,HOLD_FLAG ,HOLD_CODE ,INSP_FLAG ,INSP_ID ,INSP_RESULT_FLAG\
 ,INV_LOT_GRADE ,DLV_NO ,DLV_SEQ ,PO_NO ,PO_SEQ ,BL_NO ,BL_SEQ ,PO_DISTRIBUT\
ION_ID ,INV_CMF_1 ,INV_CMF_2 ,INV_CMF_3 ,INV_CMF_4 ,INV_CMF_5 ,INV_CMF_6 ,IN\
V_CMF_7 ,INV_CMF_8 ,INV_CMF_9 ,INV_CMF_10 ,INV_CMF_11 ,INV_CMF_12 ,INV_CMF_1\
3 ,INV_CMF_14 ,INV_CMF_15 ,INV_CMF_16 ,INV_CMF_17 ,INV_CMF_18 ,INV_CMF_19 ,I\
NV_CMF_20 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_\
CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF");
            sqlbuft((void **)0,
              "_10 ,ORG_INV_LOT_ID ,FROM_TO_DIV ,FROM_TO_INV_LOT_ID ,FROM_TO\
_HIST_SEQ ,OLD_ACTIVE_HIST_SEQ ,OLD_FACTORY ,OLD_MAT_ID ,OLD_AREA_ID ,OLD_SU\
B_AREA_ID ,OLD_OPER ,OLD_QTY ,OLD_QTY_2 ,OLD_QTY_3 ,OLD_UNIT ,OLD_UNIT_2 ,OL\
D_UNIT_3 ,CHANGE_QTY ,CHANGE_QTY_2 ,CHANGE_QTY_3 ,CREATE_QTY ,CREATE_QTY_2 ,\
CREATE_QTY_3 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME ,HIST\
_DEL_FLAG ,HIST_DEL_USER_ID ,HIST_DEL_TIME ,HIST_DEL_COMMENT into :b0,:b1,:b\
2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:\
b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b\
34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b4\
9,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64\
,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,\
:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:\
b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b10\
8,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:");
            sqlstm.stmt = "b117,:b118,:b119  from MINVLOTHIS where ((FACTOR\
Y=:b0 and INV_LOT_ID=:b1) and HIST_SEQ=:b2) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )512;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MINVLOTHIS_N.INV_LOT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MINVLOTHIS_N.INV_LOT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MINVLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )13;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MINVLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MINVLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MINVLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MINVLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[9] = (unsigned int  )401;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MINVLOTHIS_N.INV_LOT_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MINVLOTHIS_N.INV_LOT_PRIORITY);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MINVLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MINVLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MINVLOTHIS_N.QTY);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MINVLOTHIS_N.QTY_2);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MINVLOTHIS_N.QTY_3);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MINVLOTHIS_N.UNIT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MINVLOTHIS_N.UNIT_2);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MINVLOTHIS_N.UNIT_3);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MINVLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MINVLOTHIS_N.VENDOR_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MINVLOTHIS_N.VENDOR_SITE_ID);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MINVLOTHIS_N.VENDOR_LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MINVLOTHIS_N.AREA_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MINVLOTHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MINVLOTHIS_N.LOCATION_1);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MINVLOTHIS_N.LOCATION_2);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MINVLOTHIS_N.LOCATION_3);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MINVLOTHIS_N.OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MINVLOTHIS_N.LOC_NO);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MINVLOTHIS_N.RES_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MINVLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MINVLOTHIS_N.SLOT_NO);
            sqlstm.sqhstl[36] = (unsigned int  )11;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MINVLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MINVLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MINVLOTHIS_N.RECV_DATE);
            sqlstm.sqhstl[39] = (unsigned int  )9;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MINVLOTHIS_N.RECV_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MINVLOTHIS_N.REASON_CODE);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MINVLOTHIS_N.LOAD_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MINVLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MINVLOTHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MINVLOTHIS_N.DELETE_CODE);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MINVLOTHIS_N.DELETE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )15;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MINVLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MINVLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MINVLOTHIS_N.INSP_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MINVLOTHIS_N.INSP_ID);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MINVLOTHIS_N.INSP_RESULT_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MINVLOTHIS_N.INV_LOT_GRADE);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MINVLOTHIS_N.DLV_NO);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MINVLOTHIS_N.DLV_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MINVLOTHIS_N.PO_NO);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MINVLOTHIS_N.PO_SEQ);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MINVLOTHIS_N.BL_NO);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MINVLOTHIS_N.BL_SEQ);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MINVLOTHIS_N.PO_DISTRIBUTION_ID);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MINVLOTHIS_N.INV_CMF_1);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MINVLOTHIS_N.INV_CMF_2);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MINVLOTHIS_N.INV_CMF_3);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MINVLOTHIS_N.INV_CMF_4);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MINVLOTHIS_N.INV_CMF_5);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MINVLOTHIS_N.INV_CMF_6);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MINVLOTHIS_N.INV_CMF_7);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MINVLOTHIS_N.INV_CMF_8);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MINVLOTHIS_N.INV_CMF_9);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MINVLOTHIS_N.INV_CMF_10);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MINVLOTHIS_N.INV_CMF_11);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MINVLOTHIS_N.INV_CMF_12);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MINVLOTHIS_N.INV_CMF_13);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MINVLOTHIS_N.INV_CMF_14);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MINVLOTHIS_N.INV_CMF_15);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MINVLOTHIS_N.INV_CMF_16);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MINVLOTHIS_N.INV_CMF_17);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MINVLOTHIS_N.INV_CMF_18);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MINVLOTHIS_N.INV_CMF_19);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MINVLOTHIS_N.INV_CMF_20);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MINVLOTHIS_N.ORG_INV_LOT_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MINVLOTHIS_N.FROM_TO_DIV);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MINVLOTHIS_N.FROM_TO_INV_LOT_ID);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)&(MINVLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[93] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)&(MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[94] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MINVLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[95] = (unsigned int  )11;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MINVLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MINVLOTHIS_N.OLD_AREA_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MINVLOTHIS_N.OLD_SUB_AREA_ID);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MINVLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[99] = (unsigned int  )11;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)&(MINVLOTHIS_N.OLD_QTY);
            sqlstm.sqhstl[100] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[101] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[102] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MINVLOTHIS_N.OLD_UNIT);
            sqlstm.sqhstl[103] = (unsigned int  )11;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_2);
            sqlstm.sqhstl[104] = (unsigned int  )11;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_3);
            sqlstm.sqhstl[105] = (unsigned int  )11;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY);
            sqlstm.sqhstl[106] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_2);
            sqlstm.sqhstl[107] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_3);
            sqlstm.sqhstl[108] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY);
            sqlstm.sqhstl[109] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MINVLOTHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[112] = (unsigned int  )21;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MINVLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[113] = (unsigned int  )15;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MINVLOTHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[114] = (unsigned int  )21;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MINVLOTHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[115] = (unsigned int  )15;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MINVLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[116] = (unsigned int  )2;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MINVLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MINVLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[118] = (unsigned int  )15;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MINVLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[119] = (unsigned int  )401;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[120] = (unsigned int  )11;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[121] = (unsigned int  )26;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[122] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
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
        DBU_del_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    }

    DB_stop_query_timer("DBU_select_minvlothis_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBU_select_minvlothis_scalar(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;
    d_value = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID
                    AND HIST_SEQ = :MINVLOTHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MINVLOTHIS where\
 ((FACTORY=:b1 and INV_LOT_ID=:b2) and HIST_SEQ=:b3)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1019;
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
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[2] = (unsigned int  )26;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
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
            /* EXEC SQL SELECT NVL(MAX(HIST_SEQ), 0)
                INTO :d_value
                FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(max(HIST_SEQ),0) into :b0  from MINVL\
OTHIS where (FACTORY=:b1 and INV_LOT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1050;
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
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
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

    DB_stop_query_timer("DBU_select_minvlothis_scalar", sel_type);

    return d_value;
}


/* SQL DELETE Function */
void DBU_delete_minvlothis(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID
                    AND HIST_SEQ = :MINVLOTHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MINVLOTHIS  where ((FACTORY=:b0 and\
 INV_LOT_ID=:b1) and HIST_SEQ=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1077;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
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

		case 2:
            /* EXEC SQL DELETE FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MINVLOTHIS  where (FACTORY=:b0 and \
INV_LOT_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1104;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
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

    DB_stop_query_timer("DBU_delete_minvlothis", sel_type);
}


/* SQL INSERT Function */
void DBU_insert_minvlothis(struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;


    /* EXEC SQL INSERT INTO MINVLOTHIS( 
                    FACTORY, 
                    INV_LOT_ID, 
                    HIST_SEQ, 
                    INV_LOT_DESC, 
                    INV_LOT_TYPE, 
                    TRAN_CODE, 
                    TRAN_USER_ID, 
                    TRAN_TIME, 
                    SYS_TRAN_TIME, 
                    TRAN_COMMENT, 
                    INV_LOT_STATUS, 
                    INV_LOT_PRIORITY, 
                    MAT_ID, 
                    MAT_VER, 
                    QTY, 
                    QTY_2, 
                    QTY_3, 
                    UNIT, 
                    UNIT_2, 
                    UNIT_3, 
                    ORDER_ID, 
                    ADD_ORDER_ID_1, 
                    ADD_ORDER_ID_2, 
                    ADD_ORDER_ID_3, 
                    VENDOR_ID, 
					VENDOR_SITE_ID,
                    VENDOR_LOT_ID, 
                    AREA_ID, 
                    SUB_AREA_ID, 
                    LOCATION_1, 
                    LOCATION_2, 
                    LOCATION_3, 
                    OPER, 
                    LOC_NO, 
                    RES_ID, 
                    PORT_ID, 
                    SLOT_NO, 
                    CRR_ID, 
                    LOT_ID, 
                    RECV_DATE, 
                    RECV_QTY, 
                    REASON_CODE, 
                    LOAD_FLAG, 
                    TRANSIT_FLAG, 
                    DELETE_FLAG, 
                    DELETE_CODE, 
                    DELETE_TIME, 
                    HOLD_FLAG, 
                    HOLD_CODE, 
                    INSP_FLAG, 
                    INSP_ID, 
                    INSP_RESULT_FLAG, 
                    INV_LOT_GRADE, 
                    DLV_NO, 
                    DLV_SEQ, 
                    PO_NO, 
                    PO_SEQ, 
                    BL_NO, 
                    BL_SEQ,
					PO_DISTRIBUTION_ID, 
                    INV_CMF_1, 
                    INV_CMF_2, 
                    INV_CMF_3, 
                    INV_CMF_4, 
                    INV_CMF_5, 
                    INV_CMF_6, 
                    INV_CMF_7, 
                    INV_CMF_8, 
                    INV_CMF_9, 
                    INV_CMF_10, 
                    INV_CMF_11, 
                    INV_CMF_12, 
                    INV_CMF_13, 
                    INV_CMF_14, 
                    INV_CMF_15, 
                    INV_CMF_16, 
                    INV_CMF_17, 
                    INV_CMF_18, 
                    INV_CMF_19, 
                    INV_CMF_20, 
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
                    ORG_INV_LOT_ID, 
                    FROM_TO_DIV, 
                    FROM_TO_INV_LOT_ID, 
                    FROM_TO_HIST_SEQ, 
                    OLD_ACTIVE_HIST_SEQ, 
                    OLD_FACTORY, 
                    OLD_MAT_ID, 
					OLD_AREA_ID, 
                    OLD_SUB_AREA_ID, 
                    OLD_OPER, 
                    OLD_QTY, 
                    OLD_QTY_2, 
                    OLD_QTY_3, 
                    OLD_UNIT, 
                    OLD_UNIT_2, 
                    OLD_UNIT_3, 
                    CHANGE_QTY, 
                    CHANGE_QTY_2, 
                    CHANGE_QTY_3, 
                    CREATE_QTY, 
                    CREATE_QTY_2, 
                    CREATE_QTY_3, 
                    CREATE_USER_ID, 
                    CREATE_TIME, 
                    UPDATE_USER_ID, 
                    UPDATE_TIME, 
                    HIST_DEL_FLAG, 
                    HIST_DEL_USER_ID, 
                    HIST_DEL_TIME, 
                    HIST_DEL_COMMENT
         ) 
        VALUES (
                    :MINVLOTHIS_N.FACTORY,
                    :MINVLOTHIS_N.INV_LOT_ID,
                    :MINVLOTHIS_N.HIST_SEQ,
                    :MINVLOTHIS_N.INV_LOT_DESC,
                    :MINVLOTHIS_N.INV_LOT_TYPE,
                    :MINVLOTHIS_N.TRAN_CODE,
                    :MINVLOTHIS_N.TRAN_USER_ID,
                    :MINVLOTHIS_N.TRAN_TIME,
                    :MINVLOTHIS_N.SYS_TRAN_TIME,
                    :MINVLOTHIS_N.TRAN_COMMENT,
                    :MINVLOTHIS_N.INV_LOT_STATUS,
                    :MINVLOTHIS_N.INV_LOT_PRIORITY,
                    :MINVLOTHIS_N.MAT_ID,
                    :MINVLOTHIS_N.MAT_VER,
                    :MINVLOTHIS_N.QTY,
                    :MINVLOTHIS_N.QTY_2,
                    :MINVLOTHIS_N.QTY_3,
                    :MINVLOTHIS_N.UNIT,
                    :MINVLOTHIS_N.UNIT_2,
                    :MINVLOTHIS_N.UNIT_3,
                    :MINVLOTHIS_N.ORDER_ID,
                    :MINVLOTHIS_N.ADD_ORDER_ID_1,
                    :MINVLOTHIS_N.ADD_ORDER_ID_2,
                    :MINVLOTHIS_N.ADD_ORDER_ID_3,
                    :MINVLOTHIS_N.VENDOR_ID,
					:MINVLOTHIS_N.VENDOR_SITE_ID,
                    :MINVLOTHIS_N.VENDOR_LOT_ID,
                    :MINVLOTHIS_N.AREA_ID,
                    :MINVLOTHIS_N.SUB_AREA_ID,
                    :MINVLOTHIS_N.LOCATION_1,
                    :MINVLOTHIS_N.LOCATION_2,
                    :MINVLOTHIS_N.LOCATION_3,
                    :MINVLOTHIS_N.OPER,
                    :MINVLOTHIS_N.LOC_NO,
                    :MINVLOTHIS_N.RES_ID,
                    :MINVLOTHIS_N.PORT_ID,
                    :MINVLOTHIS_N.SLOT_NO,
                    :MINVLOTHIS_N.CRR_ID,
                    :MINVLOTHIS_N.LOT_ID,
                    :MINVLOTHIS_N.RECV_DATE,
                    :MINVLOTHIS_N.RECV_QTY,
                    :MINVLOTHIS_N.REASON_CODE,
                    :MINVLOTHIS_N.LOAD_FLAG,
                    :MINVLOTHIS_N.TRANSIT_FLAG,
                    :MINVLOTHIS_N.DELETE_FLAG,
                    :MINVLOTHIS_N.DELETE_CODE,
                    :MINVLOTHIS_N.DELETE_TIME,
                    :MINVLOTHIS_N.HOLD_FLAG,
                    :MINVLOTHIS_N.HOLD_CODE,
                    :MINVLOTHIS_N.INSP_FLAG,
                    :MINVLOTHIS_N.INSP_ID,
                    :MINVLOTHIS_N.INSP_RESULT_FLAG,
                    :MINVLOTHIS_N.INV_LOT_GRADE,
                    :MINVLOTHIS_N.DLV_NO,
                    :MINVLOTHIS_N.DLV_SEQ,
                    :MINVLOTHIS_N.PO_NO,
                    :MINVLOTHIS_N.PO_SEQ,
                    :MINVLOTHIS_N.BL_NO,
                    :MINVLOTHIS_N.BL_SEQ,
					:MINVLOTHIS_N.PO_DISTRIBUTION_ID,
                    :MINVLOTHIS_N.INV_CMF_1,
                    :MINVLOTHIS_N.INV_CMF_2,
                    :MINVLOTHIS_N.INV_CMF_3,
                    :MINVLOTHIS_N.INV_CMF_4,
                    :MINVLOTHIS_N.INV_CMF_5,
                    :MINVLOTHIS_N.INV_CMF_6,
                    :MINVLOTHIS_N.INV_CMF_7,
                    :MINVLOTHIS_N.INV_CMF_8,
                    :MINVLOTHIS_N.INV_CMF_9,
                    :MINVLOTHIS_N.INV_CMF_10,
                    :MINVLOTHIS_N.INV_CMF_11,
                    :MINVLOTHIS_N.INV_CMF_12,
                    :MINVLOTHIS_N.INV_CMF_13,
                    :MINVLOTHIS_N.INV_CMF_14,
                    :MINVLOTHIS_N.INV_CMF_15,
                    :MINVLOTHIS_N.INV_CMF_16,
                    :MINVLOTHIS_N.INV_CMF_17,
                    :MINVLOTHIS_N.INV_CMF_18,
                    :MINVLOTHIS_N.INV_CMF_19,
                    :MINVLOTHIS_N.INV_CMF_20,
                    :MINVLOTHIS_N.TRAN_CMF_1,
                    :MINVLOTHIS_N.TRAN_CMF_2,
                    :MINVLOTHIS_N.TRAN_CMF_3,
                    :MINVLOTHIS_N.TRAN_CMF_4,
                    :MINVLOTHIS_N.TRAN_CMF_5,
                    :MINVLOTHIS_N.TRAN_CMF_6,
                    :MINVLOTHIS_N.TRAN_CMF_7,
                    :MINVLOTHIS_N.TRAN_CMF_8,
                    :MINVLOTHIS_N.TRAN_CMF_9,
                    :MINVLOTHIS_N.TRAN_CMF_10,
                    :MINVLOTHIS_N.ORG_INV_LOT_ID,
                    :MINVLOTHIS_N.FROM_TO_DIV,
                    :MINVLOTHIS_N.FROM_TO_INV_LOT_ID,
                    :MINVLOTHIS_N.FROM_TO_HIST_SEQ,
                    :MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ,
                    :MINVLOTHIS_N.OLD_FACTORY,
                    :MINVLOTHIS_N.OLD_MAT_ID,
					:MINVLOTHIS_N.OLD_AREA_ID,
                    :MINVLOTHIS_N.OLD_SUB_AREA_ID,
                    :MINVLOTHIS_N.OLD_OPER,
                    :MINVLOTHIS_N.OLD_QTY,
                    :MINVLOTHIS_N.OLD_QTY_2,
                    :MINVLOTHIS_N.OLD_QTY_3,
                    :MINVLOTHIS_N.OLD_UNIT,
                    :MINVLOTHIS_N.OLD_UNIT_2,
                    :MINVLOTHIS_N.OLD_UNIT_3,
                    :MINVLOTHIS_N.CHANGE_QTY,
                    :MINVLOTHIS_N.CHANGE_QTY_2,
                    :MINVLOTHIS_N.CHANGE_QTY_3,
                    :MINVLOTHIS_N.CREATE_QTY,
                    :MINVLOTHIS_N.CREATE_QTY_2,
                    :MINVLOTHIS_N.CREATE_QTY_3,
                    :MINVLOTHIS_N.CREATE_USER_ID,
                    :MINVLOTHIS_N.CREATE_TIME,
                    :MINVLOTHIS_N.UPDATE_USER_ID,
                    :MINVLOTHIS_N.UPDATE_TIME,
                    :MINVLOTHIS_N.HIST_DEL_FLAG,
                    :MINVLOTHIS_N.HIST_DEL_USER_ID,
                    :MINVLOTHIS_N.HIST_DEL_TIME,
                    :MINVLOTHIS_N.HIST_DEL_COMMENT
         ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 123;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MINVLOTHIS (FACTORY,INV_LOT_ID,HIST_SEQ,INV_LOT_DESC,INV_\
LOT_TYPE,TRAN_CODE,TRAN_USER_ID,TRAN_TIME,SYS_TRAN_TIME,TRAN_COMMENT,INV_LOT\
_STATUS,INV_LOT_PRIORITY,MAT_ID,MAT_VER,QTY,QTY_2,QTY_3,UNIT,UNIT_2,UNIT_3,O\
RDER_ID,ADD_ORDER_ID_1,ADD_ORDER_ID_2,ADD_ORDER_ID_3,VENDOR_ID,VENDOR_SITE_I\
D,VENDOR_LOT_ID,AREA_ID,SUB_AREA_ID,LOCATION_1,LOCATION_2,LOCATION_3,OPER,LO\
C_NO,RES_ID,PORT_ID,SLOT_NO,CRR_ID,LOT_ID,RECV_DATE,RECV_QTY,REASON_CODE,LOA\
D_FLAG,TRANSIT_FLAG,DELETE_FLAG,DELETE_CODE,DELETE_TIME,HOLD_FLAG,HOLD_CODE,\
INSP_FLAG,INSP_ID,INSP_RESULT_FLAG,INV_LOT_GRADE,DLV_NO,DLV_SEQ,PO_NO,PO_SEQ\
,BL_NO,BL_SEQ,PO_DISTRIBUTION_ID,INV_CMF_1,INV_CMF_2,INV_CMF_3,INV_CMF_4,INV\
_CMF_5,INV_CMF_6,INV_CMF_7,INV_CMF_8,INV_CMF_9,INV_CMF_10,INV_CMF_11,INV_CMF\
_12,INV_CMF_13,INV_CMF_14,INV_CMF_15,INV_CMF_16,INV_CMF_17,INV_CMF_18,INV_CM\
F_19,INV_CMF_20,TRAN_CMF_1,TRAN_CMF_2,TRAN_CMF_3,TRAN_CMF_4,TRAN_CMF_5,TRAN_\
CMF_6,TRAN_CMF_7,TRAN_CMF_8,TRAN_CMF_9,TRAN_CMF_10,ORG_INV_LOT_ID,FROM_TO_DI\
V,FROM_TO_INV_LOT_ID,FROM_TO_HIST_SEQ,OLD_A");
    sqlstm.stmt = "CTIVE_HIST_SEQ,OLD_FACTORY,OLD_MAT_ID,OLD_AREA_ID,OLD_SU\
B_AREA_ID,OLD_OPER,OLD_QTY,OLD_QTY_2,OLD_QTY_3,OLD_UNIT,OLD_UNIT_2,OLD_UNIT_3\
,CHANGE_QTY,CHANGE_QTY_2,CHANGE_QTY_3,CREATE_QTY,CREATE_QTY_2,CREATE_QTY_3,CR\
EATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME,HIST_DEL_FLAG,HIST_DEL_US\
ER_ID,HIST_DEL_TIME,HIST_DEL_COMMENT) values (:b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7\
,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b2\
3,:b24,:b25,:b26,:b27,:b28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,\
:b39,:b40,:b41,:b42,:b43,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b\
54,:b55,:b56,:b57,:b58,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69\
,:b70,:b71,:b72,:b73,:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:\
b85,:b86,:b87,:b88,:b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b1\
00,:b101,:b102,:b103,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b\
113,:b114,:b115,:b116,:b117,:b118,:b119)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1127;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
    sqlstm.sqhstl[1] = (unsigned int  )26;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MINVLOTHIS_N.INV_LOT_DESC);
    sqlstm.sqhstl[3] = (unsigned int  )201;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MINVLOTHIS_N.INV_LOT_TYPE);
    sqlstm.sqhstl[4] = (unsigned int  )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MINVLOTHIS_N.TRAN_CODE);
    sqlstm.sqhstl[5] = (unsigned int  )13;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MINVLOTHIS_N.TRAN_USER_ID);
    sqlstm.sqhstl[6] = (unsigned int  )21;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MINVLOTHIS_N.TRAN_TIME);
    sqlstm.sqhstl[7] = (unsigned int  )15;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MINVLOTHIS_N.SYS_TRAN_TIME);
    sqlstm.sqhstl[8] = (unsigned int  )15;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MINVLOTHIS_N.TRAN_COMMENT);
    sqlstm.sqhstl[9] = (unsigned int  )401;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MINVLOTHIS_N.INV_LOT_STATUS);
    sqlstm.sqhstl[10] = (unsigned int  )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MINVLOTHIS_N.INV_LOT_PRIORITY);
    sqlstm.sqhstl[11] = (unsigned int  )2;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MINVLOTHIS_N.MAT_ID);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)&(MINVLOTHIS_N.MAT_VER);
    sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)&(MINVLOTHIS_N.QTY);
    sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)&(MINVLOTHIS_N.QTY_2);
    sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)&(MINVLOTHIS_N.QTY_3);
    sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MINVLOTHIS_N.UNIT);
    sqlstm.sqhstl[17] = (unsigned int  )11;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MINVLOTHIS_N.UNIT_2);
    sqlstm.sqhstl[18] = (unsigned int  )11;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MINVLOTHIS_N.UNIT_3);
    sqlstm.sqhstl[19] = (unsigned int  )11;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MINVLOTHIS_N.ORDER_ID);
    sqlstm.sqhstl[20] = (unsigned int  )26;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_1);
    sqlstm.sqhstl[21] = (unsigned int  )26;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_2);
    sqlstm.sqhstl[22] = (unsigned int  )26;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_3);
    sqlstm.sqhstl[23] = (unsigned int  )26;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MINVLOTHIS_N.VENDOR_ID);
    sqlstm.sqhstl[24] = (unsigned int  )21;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)&(MINVLOTHIS_N.VENDOR_SITE_ID);
    sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MINVLOTHIS_N.VENDOR_LOT_ID);
    sqlstm.sqhstl[26] = (unsigned int  )51;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MINVLOTHIS_N.AREA_ID);
    sqlstm.sqhstl[27] = (unsigned int  )21;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MINVLOTHIS_N.SUB_AREA_ID);
    sqlstm.sqhstl[28] = (unsigned int  )21;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MINVLOTHIS_N.LOCATION_1);
    sqlstm.sqhstl[29] = (unsigned int  )21;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MINVLOTHIS_N.LOCATION_2);
    sqlstm.sqhstl[30] = (unsigned int  )21;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MINVLOTHIS_N.LOCATION_3);
    sqlstm.sqhstl[31] = (unsigned int  )21;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MINVLOTHIS_N.OPER);
    sqlstm.sqhstl[32] = (unsigned int  )11;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MINVLOTHIS_N.LOC_NO);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MINVLOTHIS_N.RES_ID);
    sqlstm.sqhstl[34] = (unsigned int  )21;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MINVLOTHIS_N.PORT_ID);
    sqlstm.sqhstl[35] = (unsigned int  )11;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MINVLOTHIS_N.SLOT_NO);
    sqlstm.sqhstl[36] = (unsigned int  )11;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MINVLOTHIS_N.CRR_ID);
    sqlstm.sqhstl[37] = (unsigned int  )21;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MINVLOTHIS_N.LOT_ID);
    sqlstm.sqhstl[38] = (unsigned int  )26;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MINVLOTHIS_N.RECV_DATE);
    sqlstm.sqhstl[39] = (unsigned int  )9;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)&(MINVLOTHIS_N.RECV_QTY);
    sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MINVLOTHIS_N.REASON_CODE);
    sqlstm.sqhstl[41] = (unsigned int  )31;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MINVLOTHIS_N.LOAD_FLAG);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MINVLOTHIS_N.TRANSIT_FLAG);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MINVLOTHIS_N.DELETE_FLAG);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MINVLOTHIS_N.DELETE_CODE);
    sqlstm.sqhstl[45] = (unsigned int  )31;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MINVLOTHIS_N.DELETE_TIME);
    sqlstm.sqhstl[46] = (unsigned int  )15;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MINVLOTHIS_N.HOLD_FLAG);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MINVLOTHIS_N.HOLD_CODE);
    sqlstm.sqhstl[48] = (unsigned int  )31;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MINVLOTHIS_N.INSP_FLAG);
    sqlstm.sqhstl[49] = (unsigned int  )2;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MINVLOTHIS_N.INSP_ID);
    sqlstm.sqhstl[50] = (unsigned int  )31;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MINVLOTHIS_N.INSP_RESULT_FLAG);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MINVLOTHIS_N.INV_LOT_GRADE);
    sqlstm.sqhstl[52] = (unsigned int  )11;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MINVLOTHIS_N.DLV_NO);
    sqlstm.sqhstl[53] = (unsigned int  )31;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)&(MINVLOTHIS_N.DLV_SEQ);
    sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MINVLOTHIS_N.PO_NO);
    sqlstm.sqhstl[55] = (unsigned int  )31;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)&(MINVLOTHIS_N.PO_SEQ);
    sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MINVLOTHIS_N.BL_NO);
    sqlstm.sqhstl[57] = (unsigned int  )31;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)&(MINVLOTHIS_N.BL_SEQ);
    sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)&(MINVLOTHIS_N.PO_DISTRIBUTION_ID);
    sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MINVLOTHIS_N.INV_CMF_1);
    sqlstm.sqhstl[60] = (unsigned int  )31;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MINVLOTHIS_N.INV_CMF_2);
    sqlstm.sqhstl[61] = (unsigned int  )31;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MINVLOTHIS_N.INV_CMF_3);
    sqlstm.sqhstl[62] = (unsigned int  )31;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MINVLOTHIS_N.INV_CMF_4);
    sqlstm.sqhstl[63] = (unsigned int  )31;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MINVLOTHIS_N.INV_CMF_5);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MINVLOTHIS_N.INV_CMF_6);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MINVLOTHIS_N.INV_CMF_7);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MINVLOTHIS_N.INV_CMF_8);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MINVLOTHIS_N.INV_CMF_9);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MINVLOTHIS_N.INV_CMF_10);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MINVLOTHIS_N.INV_CMF_11);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MINVLOTHIS_N.INV_CMF_12);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MINVLOTHIS_N.INV_CMF_13);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MINVLOTHIS_N.INV_CMF_14);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MINVLOTHIS_N.INV_CMF_15);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MINVLOTHIS_N.INV_CMF_16);
    sqlstm.sqhstl[75] = (unsigned int  )31;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MINVLOTHIS_N.INV_CMF_17);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MINVLOTHIS_N.INV_CMF_18);
    sqlstm.sqhstl[77] = (unsigned int  )31;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MINVLOTHIS_N.INV_CMF_19);
    sqlstm.sqhstl[78] = (unsigned int  )31;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MINVLOTHIS_N.INV_CMF_20);
    sqlstm.sqhstl[79] = (unsigned int  )31;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_1);
    sqlstm.sqhstl[80] = (unsigned int  )31;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_2);
    sqlstm.sqhstl[81] = (unsigned int  )31;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_3);
    sqlstm.sqhstl[82] = (unsigned int  )31;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_4);
    sqlstm.sqhstl[83] = (unsigned int  )31;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_5);
    sqlstm.sqhstl[84] = (unsigned int  )31;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_6);
    sqlstm.sqhstl[85] = (unsigned int  )31;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_7);
    sqlstm.sqhstl[86] = (unsigned int  )31;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_8);
    sqlstm.sqhstl[87] = (unsigned int  )31;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_9);
    sqlstm.sqhstl[88] = (unsigned int  )31;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_10);
    sqlstm.sqhstl[89] = (unsigned int  )31;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MINVLOTHIS_N.ORG_INV_LOT_ID);
    sqlstm.sqhstl[90] = (unsigned int  )26;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MINVLOTHIS_N.FROM_TO_DIV);
    sqlstm.sqhstl[91] = (unsigned int  )2;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MINVLOTHIS_N.FROM_TO_INV_LOT_ID);
    sqlstm.sqhstl[92] = (unsigned int  )26;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)&(MINVLOTHIS_N.FROM_TO_HIST_SEQ);
    sqlstm.sqhstl[93] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)&(MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ);
    sqlstm.sqhstl[94] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MINVLOTHIS_N.OLD_FACTORY);
    sqlstm.sqhstl[95] = (unsigned int  )11;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MINVLOTHIS_N.OLD_MAT_ID);
    sqlstm.sqhstl[96] = (unsigned int  )31;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MINVLOTHIS_N.OLD_AREA_ID);
    sqlstm.sqhstl[97] = (unsigned int  )21;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MINVLOTHIS_N.OLD_SUB_AREA_ID);
    sqlstm.sqhstl[98] = (unsigned int  )21;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MINVLOTHIS_N.OLD_OPER);
    sqlstm.sqhstl[99] = (unsigned int  )11;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)&(MINVLOTHIS_N.OLD_QTY);
    sqlstm.sqhstl[100] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_2);
    sqlstm.sqhstl[101] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_3);
    sqlstm.sqhstl[102] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MINVLOTHIS_N.OLD_UNIT);
    sqlstm.sqhstl[103] = (unsigned int  )11;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_2);
    sqlstm.sqhstl[104] = (unsigned int  )11;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_3);
    sqlstm.sqhstl[105] = (unsigned int  )11;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY);
    sqlstm.sqhstl[106] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_2);
    sqlstm.sqhstl[107] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
    sqlstm.sqhstv[108] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_3);
    sqlstm.sqhstl[108] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[108] = (         int  )0;
    sqlstm.sqindv[108] = (         void  *)0;
    sqlstm.sqinds[108] = (         int  )0;
    sqlstm.sqharm[108] = (unsigned int  )0;
    sqlstm.sqadto[108] = (unsigned short )0;
    sqlstm.sqtdso[108] = (unsigned short )0;
    sqlstm.sqhstv[109] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY);
    sqlstm.sqhstl[109] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[109] = (         int  )0;
    sqlstm.sqindv[109] = (         void  *)0;
    sqlstm.sqinds[109] = (         int  )0;
    sqlstm.sqharm[109] = (unsigned int  )0;
    sqlstm.sqadto[109] = (unsigned short )0;
    sqlstm.sqtdso[109] = (unsigned short )0;
    sqlstm.sqhstv[110] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_2);
    sqlstm.sqhstl[110] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[110] = (         int  )0;
    sqlstm.sqindv[110] = (         void  *)0;
    sqlstm.sqinds[110] = (         int  )0;
    sqlstm.sqharm[110] = (unsigned int  )0;
    sqlstm.sqadto[110] = (unsigned short )0;
    sqlstm.sqtdso[110] = (unsigned short )0;
    sqlstm.sqhstv[111] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_3);
    sqlstm.sqhstl[111] = (unsigned int  )sizeof(double);
    sqlstm.sqhsts[111] = (         int  )0;
    sqlstm.sqindv[111] = (         void  *)0;
    sqlstm.sqinds[111] = (         int  )0;
    sqlstm.sqharm[111] = (unsigned int  )0;
    sqlstm.sqadto[111] = (unsigned short )0;
    sqlstm.sqtdso[111] = (unsigned short )0;
    sqlstm.sqhstv[112] = (         void  *)(MINVLOTHIS_N.CREATE_USER_ID);
    sqlstm.sqhstl[112] = (unsigned int  )21;
    sqlstm.sqhsts[112] = (         int  )0;
    sqlstm.sqindv[112] = (         void  *)0;
    sqlstm.sqinds[112] = (         int  )0;
    sqlstm.sqharm[112] = (unsigned int  )0;
    sqlstm.sqadto[112] = (unsigned short )0;
    sqlstm.sqtdso[112] = (unsigned short )0;
    sqlstm.sqhstv[113] = (         void  *)(MINVLOTHIS_N.CREATE_TIME);
    sqlstm.sqhstl[113] = (unsigned int  )15;
    sqlstm.sqhsts[113] = (         int  )0;
    sqlstm.sqindv[113] = (         void  *)0;
    sqlstm.sqinds[113] = (         int  )0;
    sqlstm.sqharm[113] = (unsigned int  )0;
    sqlstm.sqadto[113] = (unsigned short )0;
    sqlstm.sqtdso[113] = (unsigned short )0;
    sqlstm.sqhstv[114] = (         void  *)(MINVLOTHIS_N.UPDATE_USER_ID);
    sqlstm.sqhstl[114] = (unsigned int  )21;
    sqlstm.sqhsts[114] = (         int  )0;
    sqlstm.sqindv[114] = (         void  *)0;
    sqlstm.sqinds[114] = (         int  )0;
    sqlstm.sqharm[114] = (unsigned int  )0;
    sqlstm.sqadto[114] = (unsigned short )0;
    sqlstm.sqtdso[114] = (unsigned short )0;
    sqlstm.sqhstv[115] = (         void  *)(MINVLOTHIS_N.UPDATE_TIME);
    sqlstm.sqhstl[115] = (unsigned int  )15;
    sqlstm.sqhsts[115] = (         int  )0;
    sqlstm.sqindv[115] = (         void  *)0;
    sqlstm.sqinds[115] = (         int  )0;
    sqlstm.sqharm[115] = (unsigned int  )0;
    sqlstm.sqadto[115] = (unsigned short )0;
    sqlstm.sqtdso[115] = (unsigned short )0;
    sqlstm.sqhstv[116] = (         void  *)(MINVLOTHIS_N.HIST_DEL_FLAG);
    sqlstm.sqhstl[116] = (unsigned int  )2;
    sqlstm.sqhsts[116] = (         int  )0;
    sqlstm.sqindv[116] = (         void  *)0;
    sqlstm.sqinds[116] = (         int  )0;
    sqlstm.sqharm[116] = (unsigned int  )0;
    sqlstm.sqadto[116] = (unsigned short )0;
    sqlstm.sqtdso[116] = (unsigned short )0;
    sqlstm.sqhstv[117] = (         void  *)(MINVLOTHIS_N.HIST_DEL_USER_ID);
    sqlstm.sqhstl[117] = (unsigned int  )21;
    sqlstm.sqhsts[117] = (         int  )0;
    sqlstm.sqindv[117] = (         void  *)0;
    sqlstm.sqinds[117] = (         int  )0;
    sqlstm.sqharm[117] = (unsigned int  )0;
    sqlstm.sqadto[117] = (unsigned short )0;
    sqlstm.sqtdso[117] = (unsigned short )0;
    sqlstm.sqhstv[118] = (         void  *)(MINVLOTHIS_N.HIST_DEL_TIME);
    sqlstm.sqhstl[118] = (unsigned int  )15;
    sqlstm.sqhsts[118] = (         int  )0;
    sqlstm.sqindv[118] = (         void  *)0;
    sqlstm.sqinds[118] = (         int  )0;
    sqlstm.sqharm[118] = (unsigned int  )0;
    sqlstm.sqadto[118] = (unsigned short )0;
    sqlstm.sqtdso[118] = (unsigned short )0;
    sqlstm.sqhstv[119] = (         void  *)(MINVLOTHIS_N.HIST_DEL_COMMENT);
    sqlstm.sqhstl[119] = (unsigned int  )401;
    sqlstm.sqhsts[119] = (         int  )0;
    sqlstm.sqindv[119] = (         void  *)0;
    sqlstm.sqinds[119] = (         int  )0;
    sqlstm.sqharm[119] = (unsigned int  )0;
    sqlstm.sqadto[119] = (unsigned short )0;
    sqlstm.sqtdso[119] = (unsigned short )0;
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



    DB_stop_query_timer("DBU_insert_minvlothis", 0);
}


/* SQL UPDATE Function */
void DBU_update_minvlothis(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MINVLOTHIS SET
                    INV_LOT_DESC = :MINVLOTHIS_N.INV_LOT_DESC,
                    INV_LOT_TYPE = :MINVLOTHIS_N.INV_LOT_TYPE,
                    TRAN_CODE = :MINVLOTHIS_N.TRAN_CODE,
                    TRAN_USER_ID = :MINVLOTHIS_N.TRAN_USER_ID,
                    TRAN_TIME = :MINVLOTHIS_N.TRAN_TIME,
                    SYS_TRAN_TIME = :MINVLOTHIS_N.SYS_TRAN_TIME,
                    TRAN_COMMENT = :MINVLOTHIS_N.TRAN_COMMENT,
                    INV_LOT_STATUS = :MINVLOTHIS_N.INV_LOT_STATUS,
                    INV_LOT_PRIORITY = :MINVLOTHIS_N.INV_LOT_PRIORITY,
                    MAT_ID = :MINVLOTHIS_N.MAT_ID,
                    MAT_VER = :MINVLOTHIS_N.MAT_VER,
                    QTY = :MINVLOTHIS_N.QTY,
                    QTY_2 = :MINVLOTHIS_N.QTY_2,
                    QTY_3 = :MINVLOTHIS_N.QTY_3,
                    UNIT = :MINVLOTHIS_N.UNIT,
                    UNIT_2 = :MINVLOTHIS_N.UNIT_2,
                    UNIT_3 = :MINVLOTHIS_N.UNIT_3,
                    ORDER_ID = :MINVLOTHIS_N.ORDER_ID,
                    ADD_ORDER_ID_1 = :MINVLOTHIS_N.ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2 = :MINVLOTHIS_N.ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3 = :MINVLOTHIS_N.ADD_ORDER_ID_3,
                    VENDOR_ID = :MINVLOTHIS_N.VENDOR_ID,
					VENDOR_SITE_ID = :MINVLOTHIS_N.VENDOR_SITE_ID,
                    VENDOR_LOT_ID = :MINVLOTHIS_N.VENDOR_LOT_ID,
                    AREA_ID = :MINVLOTHIS_N.AREA_ID,
                    SUB_AREA_ID = :MINVLOTHIS_N.SUB_AREA_ID,
                    LOCATION_1 = :MINVLOTHIS_N.LOCATION_1,
                    LOCATION_2 = :MINVLOTHIS_N.LOCATION_2,
                    LOCATION_3 = :MINVLOTHIS_N.LOCATION_3,
                    OPER = :MINVLOTHIS_N.OPER,
                    LOC_NO = :MINVLOTHIS_N.LOC_NO,
                    RES_ID = :MINVLOTHIS_N.RES_ID,
                    PORT_ID = :MINVLOTHIS_N.PORT_ID,
                    SLOT_NO = :MINVLOTHIS_N.SLOT_NO,
                    CRR_ID = :MINVLOTHIS_N.CRR_ID,
                    LOT_ID = :MINVLOTHIS_N.LOT_ID,
                    RECV_DATE = :MINVLOTHIS_N.RECV_DATE,
                    RECV_QTY = :MINVLOTHIS_N.RECV_QTY,
                    REASON_CODE = :MINVLOTHIS_N.REASON_CODE,
                    LOAD_FLAG = :MINVLOTHIS_N.LOAD_FLAG,
                    TRANSIT_FLAG = :MINVLOTHIS_N.TRANSIT_FLAG,
                    DELETE_FLAG = :MINVLOTHIS_N.DELETE_FLAG,
                    DELETE_CODE = :MINVLOTHIS_N.DELETE_CODE,
                    DELETE_TIME = :MINVLOTHIS_N.DELETE_TIME,
                    HOLD_FLAG = :MINVLOTHIS_N.HOLD_FLAG,
                    HOLD_CODE = :MINVLOTHIS_N.HOLD_CODE,
                    INSP_FLAG = :MINVLOTHIS_N.INSP_FLAG,
                    INSP_ID = :MINVLOTHIS_N.INSP_ID,
                    INSP_RESULT_FLAG = :MINVLOTHIS_N.INSP_RESULT_FLAG,
                    INV_LOT_GRADE = :MINVLOTHIS_N.INV_LOT_GRADE,
                    DLV_NO = :MINVLOTHIS_N.DLV_NO,
                    DLV_SEQ = :MINVLOTHIS_N.DLV_SEQ,
                    PO_NO = :MINVLOTHIS_N.PO_NO,
                    PO_SEQ = :MINVLOTHIS_N.PO_SEQ,
                    BL_NO = :MINVLOTHIS_N.BL_NO,
                    BL_SEQ = :MINVLOTHIS_N.BL_SEQ,
					PO_DISTRIBUTION_ID = :MINVLOTHIS_N.PO_DISTRIBUTION_ID,
                    INV_CMF_1 = :MINVLOTHIS_N.INV_CMF_1,
                    INV_CMF_2 = :MINVLOTHIS_N.INV_CMF_2,
                    INV_CMF_3 = :MINVLOTHIS_N.INV_CMF_3,
                    INV_CMF_4 = :MINVLOTHIS_N.INV_CMF_4,
                    INV_CMF_5 = :MINVLOTHIS_N.INV_CMF_5,
                    INV_CMF_6 = :MINVLOTHIS_N.INV_CMF_6,
                    INV_CMF_7 = :MINVLOTHIS_N.INV_CMF_7,
                    INV_CMF_8 = :MINVLOTHIS_N.INV_CMF_8,
                    INV_CMF_9 = :MINVLOTHIS_N.INV_CMF_9,
                    INV_CMF_10 = :MINVLOTHIS_N.INV_CMF_10,
                    INV_CMF_11 = :MINVLOTHIS_N.INV_CMF_11,
                    INV_CMF_12 = :MINVLOTHIS_N.INV_CMF_12,
                    INV_CMF_13 = :MINVLOTHIS_N.INV_CMF_13,
                    INV_CMF_14 = :MINVLOTHIS_N.INV_CMF_14,
                    INV_CMF_15 = :MINVLOTHIS_N.INV_CMF_15,
                    INV_CMF_16 = :MINVLOTHIS_N.INV_CMF_16,
                    INV_CMF_17 = :MINVLOTHIS_N.INV_CMF_17,
                    INV_CMF_18 = :MINVLOTHIS_N.INV_CMF_18,
                    INV_CMF_19 = :MINVLOTHIS_N.INV_CMF_19,
                    INV_CMF_20 = :MINVLOTHIS_N.INV_CMF_20,
                    TRAN_CMF_1 = :MINVLOTHIS_N.TRAN_CMF_1,
                    TRAN_CMF_2 = :MINVLOTHIS_N.TRAN_CMF_2,
                    TRAN_CMF_3 = :MINVLOTHIS_N.TRAN_CMF_3,
                    TRAN_CMF_4 = :MINVLOTHIS_N.TRAN_CMF_4,
                    TRAN_CMF_5 = :MINVLOTHIS_N.TRAN_CMF_5,
                    TRAN_CMF_6 = :MINVLOTHIS_N.TRAN_CMF_6,
                    TRAN_CMF_7 = :MINVLOTHIS_N.TRAN_CMF_7,
                    TRAN_CMF_8 = :MINVLOTHIS_N.TRAN_CMF_8,
                    TRAN_CMF_9 = :MINVLOTHIS_N.TRAN_CMF_9,
                    TRAN_CMF_10 = :MINVLOTHIS_N.TRAN_CMF_10,
                    ORG_INV_LOT_ID = :MINVLOTHIS_N.ORG_INV_LOT_ID,
                    FROM_TO_DIV = :MINVLOTHIS_N.FROM_TO_DIV,
                    FROM_TO_INV_LOT_ID = :MINVLOTHIS_N.FROM_TO_INV_LOT_ID,
                    FROM_TO_HIST_SEQ = :MINVLOTHIS_N.FROM_TO_HIST_SEQ,
                    OLD_ACTIVE_HIST_SEQ = :MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ,
                    OLD_FACTORY = :MINVLOTHIS_N.OLD_FACTORY,
                    OLD_MAT_ID = :MINVLOTHIS_N.OLD_MAT_ID,
					OLD_AREA_ID = :MINVLOTHIS_N.OLD_AREA_ID,
                    OLD_SUB_AREA_ID = :MINVLOTHIS_N.OLD_SUB_AREA_ID,
                    OLD_OPER = :MINVLOTHIS_N.OLD_OPER,
                    OLD_QTY = :MINVLOTHIS_N.OLD_QTY,
                    OLD_QTY_2 = :MINVLOTHIS_N.OLD_QTY_2,
                    OLD_QTY_3 = :MINVLOTHIS_N.OLD_QTY_3,
                    OLD_UNIT = :MINVLOTHIS_N.OLD_UNIT,
                    OLD_UNIT_2 = :MINVLOTHIS_N.OLD_UNIT_2,
                    OLD_UNIT_3 = :MINVLOTHIS_N.OLD_UNIT_3,
                    CHANGE_QTY = :MINVLOTHIS_N.CHANGE_QTY,
                    CHANGE_QTY_2 = :MINVLOTHIS_N.CHANGE_QTY_2,
                    CHANGE_QTY_3 = :MINVLOTHIS_N.CHANGE_QTY_3,
                    CREATE_QTY = :MINVLOTHIS_N.CREATE_QTY,
                    CREATE_QTY_2 = :MINVLOTHIS_N.CREATE_QTY_2,
                    CREATE_QTY_3 = :MINVLOTHIS_N.CREATE_QTY_3,
                    CREATE_USER_ID = :MINVLOTHIS_N.CREATE_USER_ID,
                    CREATE_TIME = :MINVLOTHIS_N.CREATE_TIME,
                    UPDATE_USER_ID = :MINVLOTHIS_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MINVLOTHIS_N.UPDATE_TIME,
                    HIST_DEL_FLAG = :MINVLOTHIS_N.HIST_DEL_FLAG,
                    HIST_DEL_USER_ID = :MINVLOTHIS_N.HIST_DEL_USER_ID,
                    HIST_DEL_TIME = :MINVLOTHIS_N.HIST_DEL_TIME,
                    HIST_DEL_COMMENT = :MINVLOTHIS_N.HIST_DEL_COMMENT
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID
                    AND HIST_SEQ = :MINVLOTHIS_N.HIST_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MINVLOTHIS  set INV_LOT_DESC=:b0,INV_LOT_TYPE=:b1,TRAN\
_CODE=:b2,TRAN_USER_ID=:b3,TRAN_TIME=:b4,SYS_TRAN_TIME=:b5,TRAN_COMMENT=:b6,\
INV_LOT_STATUS=:b7,INV_LOT_PRIORITY=:b8,MAT_ID=:b9,MAT_VER=:b10,QTY=:b11,QTY\
_2=:b12,QTY_3=:b13,UNIT=:b14,UNIT_2=:b15,UNIT_3=:b16,ORDER_ID=:b17,ADD_ORDER\
_ID_1=:b18,ADD_ORDER_ID_2=:b19,ADD_ORDER_ID_3=:b20,VENDOR_ID=:b21,VENDOR_SIT\
E_ID=:b22,VENDOR_LOT_ID=:b23,AREA_ID=:b24,SUB_AREA_ID=:b25,LOCATION_1=:b26,L\
OCATION_2=:b27,LOCATION_3=:b28,OPER=:b29,LOC_NO=:b30,RES_ID=:b31,PORT_ID=:b3\
2,SLOT_NO=:b33,CRR_ID=:b34,LOT_ID=:b35,RECV_DATE=:b36,RECV_QTY=:b37,REASON_C\
ODE=:b38,LOAD_FLAG=:b39,TRANSIT_FLAG=:b40,DELETE_FLAG=:b41,DELETE_CODE=:b42,\
DELETE_TIME=:b43,HOLD_FLAG=:b44,HOLD_CODE=:b45,INSP_FLAG=:b46,INSP_ID=:b47,I\
NSP_RESULT_FLAG=:b48,INV_LOT_GRADE=:b49,DLV_NO=:b50,DLV_SEQ=:b51,PO_NO=:b52,\
PO_SEQ=:b53,BL_NO=:b54,BL_SEQ=:b55,PO_DISTRIBUTION_ID=:b56,INV_CMF_1=:b57,IN\
V_CMF_2=:b58,INV_CMF_3=:b59,INV_CMF_4=:b60,INV_CMF_5=:b61,INV_CMF_6=:b62,INV\
_CMF_7=:b63,INV_CMF_8=:b64,INV_CMF_9=:b65,INV_CMF_1");
            sqlstm.stmt = "0=:b66,INV_CMF_11=:b67,INV_CMF_12=:b68,INV_CMF_1\
3=:b69,INV_CMF_14=:b70,INV_CMF_15=:b71,INV_CMF_16=:b72,INV_CMF_17=:b73,INV_CM\
F_18=:b74,INV_CMF_19=:b75,INV_CMF_20=:b76,TRAN_CMF_1=:b77,TRAN_CMF_2=:b78,TRA\
N_CMF_3=:b79,TRAN_CMF_4=:b80,TRAN_CMF_5=:b81,TRAN_CMF_6=:b82,TRAN_CMF_7=:b83,\
TRAN_CMF_8=:b84,TRAN_CMF_9=:b85,TRAN_CMF_10=:b86,ORG_INV_LOT_ID=:b87,FROM_TO_\
DIV=:b88,FROM_TO_INV_LOT_ID=:b89,FROM_TO_HIST_SEQ=:b90,OLD_ACTIVE_HIST_SEQ=:b\
91,OLD_FACTORY=:b92,OLD_MAT_ID=:b93,OLD_AREA_ID=:b94,OLD_SUB_AREA_ID=:b95,OLD\
_OPER=:b96,OLD_QTY=:b97,OLD_QTY_2=:b98,OLD_QTY_3=:b99,OLD_UNIT=:b100,OLD_UNIT\
_2=:b101,OLD_UNIT_3=:b102,CHANGE_QTY=:b103,CHANGE_QTY_2=:b104,CHANGE_QTY_3=:b\
105,CREATE_QTY=:b106,CREATE_QTY_2=:b107,CREATE_QTY_3=:b108,CREATE_USER_ID=:b1\
09,CREATE_TIME=:b110,UPDATE_USER_ID=:b111,UPDATE_TIME=:b112,HIST_DEL_FLAG=:b1\
13,HIST_DEL_USER_ID=:b114,HIST_DEL_TIME=:b115,HIST_DEL_COMMENT=:b116 where ((\
FACTORY=:b117 and INV_LOT_ID=:b118) and HIST_SEQ=:b119)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1622;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.INV_LOT_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_TYPE);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MINVLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[2] = (unsigned int  )13;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MINVLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MINVLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )15;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MINVLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MINVLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[6] = (unsigned int  )401;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MINVLOTHIS_N.INV_LOT_STATUS);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MINVLOTHIS_N.INV_LOT_PRIORITY);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MINVLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(MINVLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(MINVLOTHIS_N.QTY);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(MINVLOTHIS_N.QTY_2);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MINVLOTHIS_N.QTY_3);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MINVLOTHIS_N.UNIT);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MINVLOTHIS_N.UNIT_2);
            sqlstm.sqhstl[15] = (unsigned int  )11;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MINVLOTHIS_N.UNIT_3);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MINVLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[18] = (unsigned int  )26;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[19] = (unsigned int  )26;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MINVLOTHIS_N.VENDOR_ID);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(MINVLOTHIS_N.VENDOR_SITE_ID);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MINVLOTHIS_N.VENDOR_LOT_ID);
            sqlstm.sqhstl[23] = (unsigned int  )51;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MINVLOTHIS_N.AREA_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MINVLOTHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[25] = (unsigned int  )21;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MINVLOTHIS_N.LOCATION_1);
            sqlstm.sqhstl[26] = (unsigned int  )21;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MINVLOTHIS_N.LOCATION_2);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MINVLOTHIS_N.LOCATION_3);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MINVLOTHIS_N.OPER);
            sqlstm.sqhstl[29] = (unsigned int  )11;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MINVLOTHIS_N.LOC_NO);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MINVLOTHIS_N.RES_ID);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MINVLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MINVLOTHIS_N.SLOT_NO);
            sqlstm.sqhstl[33] = (unsigned int  )11;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MINVLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MINVLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )26;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MINVLOTHIS_N.RECV_DATE);
            sqlstm.sqhstl[36] = (unsigned int  )9;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)&(MINVLOTHIS_N.RECV_QTY);
            sqlstm.sqhstl[37] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MINVLOTHIS_N.REASON_CODE);
            sqlstm.sqhstl[38] = (unsigned int  )31;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MINVLOTHIS_N.LOAD_FLAG);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MINVLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MINVLOTHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MINVLOTHIS_N.DELETE_CODE);
            sqlstm.sqhstl[42] = (unsigned int  )31;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MINVLOTHIS_N.DELETE_TIME);
            sqlstm.sqhstl[43] = (unsigned int  )15;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MINVLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MINVLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MINVLOTHIS_N.INSP_FLAG);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MINVLOTHIS_N.INSP_ID);
            sqlstm.sqhstl[47] = (unsigned int  )31;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MINVLOTHIS_N.INSP_RESULT_FLAG);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MINVLOTHIS_N.INV_LOT_GRADE);
            sqlstm.sqhstl[49] = (unsigned int  )11;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MINVLOTHIS_N.DLV_NO);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)&(MINVLOTHIS_N.DLV_SEQ);
            sqlstm.sqhstl[51] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MINVLOTHIS_N.PO_NO);
            sqlstm.sqhstl[52] = (unsigned int  )31;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(MINVLOTHIS_N.PO_SEQ);
            sqlstm.sqhstl[53] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MINVLOTHIS_N.BL_NO);
            sqlstm.sqhstl[54] = (unsigned int  )31;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)&(MINVLOTHIS_N.BL_SEQ);
            sqlstm.sqhstl[55] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MINVLOTHIS_N.PO_DISTRIBUTION_ID);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MINVLOTHIS_N.INV_CMF_1);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MINVLOTHIS_N.INV_CMF_2);
            sqlstm.sqhstl[58] = (unsigned int  )31;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MINVLOTHIS_N.INV_CMF_3);
            sqlstm.sqhstl[59] = (unsigned int  )31;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MINVLOTHIS_N.INV_CMF_4);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MINVLOTHIS_N.INV_CMF_5);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MINVLOTHIS_N.INV_CMF_6);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MINVLOTHIS_N.INV_CMF_7);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MINVLOTHIS_N.INV_CMF_8);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MINVLOTHIS_N.INV_CMF_9);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MINVLOTHIS_N.INV_CMF_10);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MINVLOTHIS_N.INV_CMF_11);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MINVLOTHIS_N.INV_CMF_12);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MINVLOTHIS_N.INV_CMF_13);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MINVLOTHIS_N.INV_CMF_14);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MINVLOTHIS_N.INV_CMF_15);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MINVLOTHIS_N.INV_CMF_16);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MINVLOTHIS_N.INV_CMF_17);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MINVLOTHIS_N.INV_CMF_18);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MINVLOTHIS_N.INV_CMF_19);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MINVLOTHIS_N.INV_CMF_20);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MINVLOTHIS_N.ORG_INV_LOT_ID);
            sqlstm.sqhstl[87] = (unsigned int  )26;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MINVLOTHIS_N.FROM_TO_DIV);
            sqlstm.sqhstl[88] = (unsigned int  )2;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MINVLOTHIS_N.FROM_TO_INV_LOT_ID);
            sqlstm.sqhstl[89] = (unsigned int  )26;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)&(MINVLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[90] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)&(MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[91] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MINVLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[92] = (unsigned int  )11;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MINVLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MINVLOTHIS_N.OLD_AREA_ID);
            sqlstm.sqhstl[94] = (unsigned int  )21;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MINVLOTHIS_N.OLD_SUB_AREA_ID);
            sqlstm.sqhstl[95] = (unsigned int  )21;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MINVLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[96] = (unsigned int  )11;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)&(MINVLOTHIS_N.OLD_QTY);
            sqlstm.sqhstl[97] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[98] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[99] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MINVLOTHIS_N.OLD_UNIT);
            sqlstm.sqhstl[100] = (unsigned int  )11;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_2);
            sqlstm.sqhstl[101] = (unsigned int  )11;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_3);
            sqlstm.sqhstl[102] = (unsigned int  )11;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY);
            sqlstm.sqhstl[103] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_2);
            sqlstm.sqhstl[104] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_3);
            sqlstm.sqhstl[105] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY);
            sqlstm.sqhstl[106] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[107] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[108] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MINVLOTHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[109] = (unsigned int  )21;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MINVLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[110] = (unsigned int  )15;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MINVLOTHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[111] = (unsigned int  )21;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MINVLOTHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[112] = (unsigned int  )15;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MINVLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[113] = (unsigned int  )2;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MINVLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[114] = (unsigned int  )21;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MINVLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[115] = (unsigned int  )15;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MINVLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[116] = (unsigned int  )401;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[117] = (unsigned int  )11;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[118] = (unsigned int  )26;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[119] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
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

    DB_stop_query_timer("DBU_update_minvlothis", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBU_open_minvlothis(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBU_add_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBU_MINVLOTHIS_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    INV_LOT_ID,
                    HIST_SEQ,
                    INV_LOT_DESC,
                    INV_LOT_TYPE,
                    TRAN_CODE,
                    TRAN_USER_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_COMMENT,
                    INV_LOT_STATUS,
                    INV_LOT_PRIORITY,
                    MAT_ID,
                    MAT_VER,
                    QTY,
                    QTY_2,
                    QTY_3,
                    UNIT,
                    UNIT_2,
                    UNIT_3,
                    ORDER_ID,
                    ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3,
                    VENDOR_ID,
					VENDOR_SITE_ID,
                    VENDOR_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    LOCATION_1,
                    LOCATION_2,
                    LOCATION_3,
                    OPER,
                    LOC_NO,
                    RES_ID,
                    PORT_ID,
                    SLOT_NO,
                    CRR_ID,
                    LOT_ID,
                    RECV_DATE,
                    RECV_QTY,
                    REASON_CODE,
                    LOAD_FLAG,
                    TRANSIT_FLAG,
                    DELETE_FLAG,
                    DELETE_CODE,
                    DELETE_TIME,
                    HOLD_FLAG,
                    HOLD_CODE,
                    INSP_FLAG,
                    INSP_ID,
                    INSP_RESULT_FLAG,
                    INV_LOT_GRADE,
                    DLV_NO,
                    DLV_SEQ,
                    PO_NO,
                    PO_SEQ,
                    BL_NO,
                    BL_SEQ,
					PO_DISTRIBUTION_ID,
                    INV_CMF_1,
                    INV_CMF_2,
                    INV_CMF_3,
                    INV_CMF_4,
                    INV_CMF_5,
                    INV_CMF_6,
                    INV_CMF_7,
                    INV_CMF_8,
                    INV_CMF_9,
                    INV_CMF_10,
                    INV_CMF_11,
                    INV_CMF_12,
                    INV_CMF_13,
                    INV_CMF_14,
                    INV_CMF_15,
                    INV_CMF_16,
                    INV_CMF_17,
                    INV_CMF_18,
                    INV_CMF_19,
                    INV_CMF_20,
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
                    ORG_INV_LOT_ID,
                    FROM_TO_DIV,
                    FROM_TO_INV_LOT_ID,
                    FROM_TO_HIST_SEQ,
                    OLD_ACTIVE_HIST_SEQ,
                    OLD_FACTORY,
                    OLD_MAT_ID,
					OLD_AREA_ID,
                    OLD_SUB_AREA_ID,
                    OLD_OPER,
                    OLD_QTY,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_UNIT,
                    OLD_UNIT_2,
                    OLD_UNIT_3,
                    CHANGE_QTY,
                    CHANGE_QTY_2,
                    CHANGE_QTY_3,
                    CREATE_QTY,
                    CREATE_QTY_2,
                    CREATE_QTY_3,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    HIST_DEL_FLAG,
                    HIST_DEL_USER_ID,
                    HIST_DEL_TIME,
                    HIST_DEL_COMMENT
                FROM MINVLOTHIS
                ORDER BY FACTORY ASC,
                    INV_LOT_ID ASC,
                    HIST_SEQ ASC; */ 

            /* EXEC SQL OPEN DBU_MINVLOTHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,INV_LOT_ID ,HIST_SEQ ,INV_LOT_DESC ,INV_LOT_T\
YPE ,TRAN_CODE ,TRAN_USER_ID ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_COMMENT ,INV_LO\
T_STATUS ,INV_LOT_PRIORITY ,MAT_ID ,MAT_VER ,QTY ,QTY_2 ,QTY_3 ,UNIT ,UNIT_2\
 ,UNIT_3 ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,VENDOR_I\
D ,VENDOR_SITE_ID ,VENDOR_LOT_ID ,AREA_ID ,SUB_AREA_ID ,LOCATION_1 ,LOCATION\
_2 ,LOCATION_3 ,OPER ,LOC_NO ,RES_ID ,PORT_ID ,SLOT_NO ,CRR_ID ,LOT_ID ,RECV\
_DATE ,RECV_QTY ,REASON_CODE ,LOAD_FLAG ,TRANSIT_FLAG ,DELETE_FLAG ,DELETE_C\
ODE ,DELETE_TIME ,HOLD_FLAG ,HOLD_CODE ,INSP_FLAG ,INSP_ID ,INSP_RESULT_FLAG\
 ,INV_LOT_GRADE ,DLV_NO ,DLV_SEQ ,PO_NO ,PO_SEQ ,BL_NO ,BL_SEQ ,PO_DISTRIBUT\
ION_ID ,INV_CMF_1 ,INV_CMF_2 ,INV_CMF_3 ,INV_CMF_4 ,INV_CMF_5 ,INV_CMF_6 ,IN\
V_CMF_7 ,INV_CMF_8 ,INV_CMF_9 ,INV_CMF_10 ,INV_CMF_11 ,INV_CMF_12 ,INV_CMF_1\
3 ,INV_CMF_14 ,INV_CMF_15 ,INV_CMF_16 ,INV_CMF_17 ,INV_CMF_18 ,INV_CMF_19 ,I\
NV_CMF_20 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_\
CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF");
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2117;
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
            /* EXEC SQL DECLARE DBU_MINVLOTHIS_CUR_2 CURSOR FOR
                SELECT 
                    FACTORY,
                    INV_LOT_ID,
                    HIST_SEQ,
                    INV_LOT_DESC,
                    INV_LOT_TYPE,
                    TRAN_CODE,
                    TRAN_USER_ID,
                    TRAN_TIME,
                    SYS_TRAN_TIME,
                    TRAN_COMMENT,
                    INV_LOT_STATUS,
                    INV_LOT_PRIORITY,
                    MAT_ID,
                    MAT_VER,
                    QTY,
                    QTY_2,
                    QTY_3,
                    UNIT,
                    UNIT_2,
                    UNIT_3,
                    ORDER_ID,
                    ADD_ORDER_ID_1,
                    ADD_ORDER_ID_2,
                    ADD_ORDER_ID_3,
                    VENDOR_ID,
					VENDOR_SITE_ID,
                    VENDOR_LOT_ID,
                    AREA_ID,
                    SUB_AREA_ID,
                    LOCATION_1,
                    LOCATION_2,
                    LOCATION_3,
                    OPER,
                    LOC_NO,
                    RES_ID,
                    PORT_ID,
                    SLOT_NO,
                    CRR_ID,
                    LOT_ID,
                    RECV_DATE,
                    RECV_QTY,
                    REASON_CODE,
                    LOAD_FLAG,
                    TRANSIT_FLAG,
                    DELETE_FLAG,
                    DELETE_CODE,
                    DELETE_TIME,
                    HOLD_FLAG,
                    HOLD_CODE,
                    INSP_FLAG,
                    INSP_ID,
                    INSP_RESULT_FLAG,
                    INV_LOT_GRADE,
                    DLV_NO,
                    DLV_SEQ,
                    PO_NO,
                    PO_SEQ,
                    BL_NO,
                    BL_SEQ,
					PO_DISTRIBUTION_ID,
                    INV_CMF_1,
                    INV_CMF_2,
                    INV_CMF_3,
                    INV_CMF_4,
                    INV_CMF_5,
                    INV_CMF_6,
                    INV_CMF_7,
                    INV_CMF_8,
                    INV_CMF_9,
                    INV_CMF_10,
                    INV_CMF_11,
                    INV_CMF_12,
                    INV_CMF_13,
                    INV_CMF_14,
                    INV_CMF_15,
                    INV_CMF_16,
                    INV_CMF_17,
                    INV_CMF_18,
                    INV_CMF_19,
                    INV_CMF_20,
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
                    ORG_INV_LOT_ID,
                    FROM_TO_DIV,
                    FROM_TO_INV_LOT_ID,
                    FROM_TO_HIST_SEQ,
                    OLD_ACTIVE_HIST_SEQ,
                    OLD_FACTORY,
                    OLD_MAT_ID,
					OLD_AREA_ID,
                    OLD_SUB_AREA_ID,
                    OLD_OPER,
                    OLD_QTY,
                    OLD_QTY_2,
                    OLD_QTY_3,
                    OLD_UNIT,
                    OLD_UNIT_2,
                    OLD_UNIT_3,
                    CHANGE_QTY,
                    CHANGE_QTY_2,
                    CHANGE_QTY_3,
                    CREATE_QTY,
                    CREATE_QTY_2,
                    CREATE_QTY_3,
                    CREATE_USER_ID,
                    CREATE_TIME,
                    UPDATE_USER_ID,
                    UPDATE_TIME,
                    HIST_DEL_FLAG,
                    HIST_DEL_USER_ID,
                    HIST_DEL_TIME,
                    HIST_DEL_COMMENT
                FROM MINVLOTHIS
                WHERE FACTORY = :MINVLOTHIS_N.FACTORY
                    AND INV_LOT_ID = :MINVLOTHIS_N.INV_LOT_ID 
                ORDER BY HIST_SEQ DESC; */ 

            /* EXEC SQL OPEN DBU_MINVLOTHIS_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,INV_LOT_ID ,HIST_SEQ ,INV_LOT_DESC ,INV_LOT_T\
YPE ,TRAN_CODE ,TRAN_USER_ID ,TRAN_TIME ,SYS_TRAN_TIME ,TRAN_COMMENT ,INV_LO\
T_STATUS ,INV_LOT_PRIORITY ,MAT_ID ,MAT_VER ,QTY ,QTY_2 ,QTY_3 ,UNIT ,UNIT_2\
 ,UNIT_3 ,ORDER_ID ,ADD_ORDER_ID_1 ,ADD_ORDER_ID_2 ,ADD_ORDER_ID_3 ,VENDOR_I\
D ,VENDOR_SITE_ID ,VENDOR_LOT_ID ,AREA_ID ,SUB_AREA_ID ,LOCATION_1 ,LOCATION\
_2 ,LOCATION_3 ,OPER ,LOC_NO ,RES_ID ,PORT_ID ,SLOT_NO ,CRR_ID ,LOT_ID ,RECV\
_DATE ,RECV_QTY ,REASON_CODE ,LOAD_FLAG ,TRANSIT_FLAG ,DELETE_FLAG ,DELETE_C\
ODE ,DELETE_TIME ,HOLD_FLAG ,HOLD_CODE ,INSP_FLAG ,INSP_ID ,INSP_RESULT_FLAG\
 ,INV_LOT_GRADE ,DLV_NO ,DLV_SEQ ,PO_NO ,PO_SEQ ,BL_NO ,BL_SEQ ,PO_DISTRIBUT\
ION_ID ,INV_CMF_1 ,INV_CMF_2 ,INV_CMF_3 ,INV_CMF_4 ,INV_CMF_5 ,INV_CMF_6 ,IN\
V_CMF_7 ,INV_CMF_8 ,INV_CMF_9 ,INV_CMF_10 ,INV_CMF_11 ,INV_CMF_12 ,INV_CMF_1\
3 ,INV_CMF_14 ,INV_CMF_15 ,INV_CMF_16 ,INV_CMF_17 ,INV_CMF_18 ,INV_CMF_19 ,I\
NV_CMF_20 ,TRAN_CMF_1 ,TRAN_CMF_2 ,TRAN_CMF_3 ,TRAN_CMF_4 ,TRAN_CMF_5 ,TRAN_\
CMF_6 ,TRAN_CMF_7 ,TRAN_CMF_8 ,TRAN_CMF_9 ,TRAN_CMF");
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2132;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }

    DB_stop_query_timer("DBU_open_minvlothis", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBU_fetch_minvlothis(int sel_type, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MINVLOTHIS_N_TAG MINVLOTHIS_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    DB_error_code = 0;


    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBU_MINVLOTHIS_CUR_1 INTO
                :MINVLOTHIS_N.FACTORY,
                :MINVLOTHIS_N.INV_LOT_ID,
                :MINVLOTHIS_N.HIST_SEQ,
                :MINVLOTHIS_N.INV_LOT_DESC,
                :MINVLOTHIS_N.INV_LOT_TYPE,
                :MINVLOTHIS_N.TRAN_CODE,
                :MINVLOTHIS_N.TRAN_USER_ID,
                :MINVLOTHIS_N.TRAN_TIME,
                :MINVLOTHIS_N.SYS_TRAN_TIME,
                :MINVLOTHIS_N.TRAN_COMMENT,
                :MINVLOTHIS_N.INV_LOT_STATUS,
                :MINVLOTHIS_N.INV_LOT_PRIORITY,
                :MINVLOTHIS_N.MAT_ID,
                :MINVLOTHIS_N.MAT_VER,
                :MINVLOTHIS_N.QTY,
                :MINVLOTHIS_N.QTY_2,
                :MINVLOTHIS_N.QTY_3,
                :MINVLOTHIS_N.UNIT,
                :MINVLOTHIS_N.UNIT_2,
                :MINVLOTHIS_N.UNIT_3,
                :MINVLOTHIS_N.ORDER_ID,
                :MINVLOTHIS_N.ADD_ORDER_ID_1,
                :MINVLOTHIS_N.ADD_ORDER_ID_2,
                :MINVLOTHIS_N.ADD_ORDER_ID_3,
                :MINVLOTHIS_N.VENDOR_ID,
				:MINVLOTHIS_N.VENDOR_SITE_ID,
                :MINVLOTHIS_N.VENDOR_LOT_ID,
                :MINVLOTHIS_N.AREA_ID,
                :MINVLOTHIS_N.SUB_AREA_ID,
                :MINVLOTHIS_N.LOCATION_1,
                :MINVLOTHIS_N.LOCATION_2,
                :MINVLOTHIS_N.LOCATION_3,
                :MINVLOTHIS_N.OPER,
                :MINVLOTHIS_N.LOC_NO,
                :MINVLOTHIS_N.RES_ID,
                :MINVLOTHIS_N.PORT_ID,
                :MINVLOTHIS_N.SLOT_NO,
                :MINVLOTHIS_N.CRR_ID,
                :MINVLOTHIS_N.LOT_ID,
                :MINVLOTHIS_N.RECV_DATE,
                :MINVLOTHIS_N.RECV_QTY,
                :MINVLOTHIS_N.REASON_CODE,
                :MINVLOTHIS_N.LOAD_FLAG,
                :MINVLOTHIS_N.TRANSIT_FLAG,
                :MINVLOTHIS_N.DELETE_FLAG,
                :MINVLOTHIS_N.DELETE_CODE,
                :MINVLOTHIS_N.DELETE_TIME,
                :MINVLOTHIS_N.HOLD_FLAG,
                :MINVLOTHIS_N.HOLD_CODE,
                :MINVLOTHIS_N.INSP_FLAG,
                :MINVLOTHIS_N.INSP_ID,
                :MINVLOTHIS_N.INSP_RESULT_FLAG,
                :MINVLOTHIS_N.INV_LOT_GRADE,
                :MINVLOTHIS_N.DLV_NO,
                :MINVLOTHIS_N.DLV_SEQ,
                :MINVLOTHIS_N.PO_NO,
                :MINVLOTHIS_N.PO_SEQ,
                :MINVLOTHIS_N.BL_NO,
                :MINVLOTHIS_N.BL_SEQ,
				:MINVLOTHIS_N.PO_DISTRIBUTION_ID,
                :MINVLOTHIS_N.INV_CMF_1,
                :MINVLOTHIS_N.INV_CMF_2,
                :MINVLOTHIS_N.INV_CMF_3,
                :MINVLOTHIS_N.INV_CMF_4,
                :MINVLOTHIS_N.INV_CMF_5,
                :MINVLOTHIS_N.INV_CMF_6,
                :MINVLOTHIS_N.INV_CMF_7,
                :MINVLOTHIS_N.INV_CMF_8,
                :MINVLOTHIS_N.INV_CMF_9,
                :MINVLOTHIS_N.INV_CMF_10,
                :MINVLOTHIS_N.INV_CMF_11,
                :MINVLOTHIS_N.INV_CMF_12,
                :MINVLOTHIS_N.INV_CMF_13,
                :MINVLOTHIS_N.INV_CMF_14,
                :MINVLOTHIS_N.INV_CMF_15,
                :MINVLOTHIS_N.INV_CMF_16,
                :MINVLOTHIS_N.INV_CMF_17,
                :MINVLOTHIS_N.INV_CMF_18,
                :MINVLOTHIS_N.INV_CMF_19,
                :MINVLOTHIS_N.INV_CMF_20,
                :MINVLOTHIS_N.TRAN_CMF_1,
                :MINVLOTHIS_N.TRAN_CMF_2,
                :MINVLOTHIS_N.TRAN_CMF_3,
                :MINVLOTHIS_N.TRAN_CMF_4,
                :MINVLOTHIS_N.TRAN_CMF_5,
                :MINVLOTHIS_N.TRAN_CMF_6,
                :MINVLOTHIS_N.TRAN_CMF_7,
                :MINVLOTHIS_N.TRAN_CMF_8,
                :MINVLOTHIS_N.TRAN_CMF_9,
                :MINVLOTHIS_N.TRAN_CMF_10,
                :MINVLOTHIS_N.ORG_INV_LOT_ID,
                :MINVLOTHIS_N.FROM_TO_DIV,
                :MINVLOTHIS_N.FROM_TO_INV_LOT_ID,
                :MINVLOTHIS_N.FROM_TO_HIST_SEQ,
                :MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ,
                :MINVLOTHIS_N.OLD_FACTORY,
                :MINVLOTHIS_N.OLD_MAT_ID,
				:MINVLOTHIS_N.OLD_AREA_ID,
                :MINVLOTHIS_N.OLD_SUB_AREA_ID,
                :MINVLOTHIS_N.OLD_OPER,
                :MINVLOTHIS_N.OLD_QTY,
                :MINVLOTHIS_N.OLD_QTY_2,
                :MINVLOTHIS_N.OLD_QTY_3,
                :MINVLOTHIS_N.OLD_UNIT,
                :MINVLOTHIS_N.OLD_UNIT_2,
                :MINVLOTHIS_N.OLD_UNIT_3,
                :MINVLOTHIS_N.CHANGE_QTY,
                :MINVLOTHIS_N.CHANGE_QTY_2,
                :MINVLOTHIS_N.CHANGE_QTY_3,
                :MINVLOTHIS_N.CREATE_QTY,
                :MINVLOTHIS_N.CREATE_QTY_2,
                :MINVLOTHIS_N.CREATE_QTY_3,
                :MINVLOTHIS_N.CREATE_USER_ID,
                :MINVLOTHIS_N.CREATE_TIME,
                :MINVLOTHIS_N.UPDATE_USER_ID,
                :MINVLOTHIS_N.UPDATE_TIME,
                :MINVLOTHIS_N.HIST_DEL_FLAG,
                :MINVLOTHIS_N.HIST_DEL_USER_ID,
                :MINVLOTHIS_N.HIST_DEL_TIME,
                :MINVLOTHIS_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2155;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MINVLOTHIS_N.INV_LOT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MINVLOTHIS_N.INV_LOT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MINVLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )13;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MINVLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MINVLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MINVLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MINVLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[9] = (unsigned int  )401;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MINVLOTHIS_N.INV_LOT_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MINVLOTHIS_N.INV_LOT_PRIORITY);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MINVLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MINVLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MINVLOTHIS_N.QTY);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MINVLOTHIS_N.QTY_2);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MINVLOTHIS_N.QTY_3);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MINVLOTHIS_N.UNIT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MINVLOTHIS_N.UNIT_2);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MINVLOTHIS_N.UNIT_3);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MINVLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MINVLOTHIS_N.VENDOR_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MINVLOTHIS_N.VENDOR_SITE_ID);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MINVLOTHIS_N.VENDOR_LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MINVLOTHIS_N.AREA_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MINVLOTHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MINVLOTHIS_N.LOCATION_1);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MINVLOTHIS_N.LOCATION_2);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MINVLOTHIS_N.LOCATION_3);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MINVLOTHIS_N.OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MINVLOTHIS_N.LOC_NO);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MINVLOTHIS_N.RES_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MINVLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MINVLOTHIS_N.SLOT_NO);
            sqlstm.sqhstl[36] = (unsigned int  )11;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MINVLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MINVLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MINVLOTHIS_N.RECV_DATE);
            sqlstm.sqhstl[39] = (unsigned int  )9;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MINVLOTHIS_N.RECV_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MINVLOTHIS_N.REASON_CODE);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MINVLOTHIS_N.LOAD_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MINVLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MINVLOTHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MINVLOTHIS_N.DELETE_CODE);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MINVLOTHIS_N.DELETE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )15;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MINVLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MINVLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MINVLOTHIS_N.INSP_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MINVLOTHIS_N.INSP_ID);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MINVLOTHIS_N.INSP_RESULT_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MINVLOTHIS_N.INV_LOT_GRADE);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MINVLOTHIS_N.DLV_NO);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MINVLOTHIS_N.DLV_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MINVLOTHIS_N.PO_NO);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MINVLOTHIS_N.PO_SEQ);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MINVLOTHIS_N.BL_NO);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MINVLOTHIS_N.BL_SEQ);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MINVLOTHIS_N.PO_DISTRIBUTION_ID);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MINVLOTHIS_N.INV_CMF_1);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MINVLOTHIS_N.INV_CMF_2);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MINVLOTHIS_N.INV_CMF_3);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MINVLOTHIS_N.INV_CMF_4);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MINVLOTHIS_N.INV_CMF_5);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MINVLOTHIS_N.INV_CMF_6);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MINVLOTHIS_N.INV_CMF_7);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MINVLOTHIS_N.INV_CMF_8);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MINVLOTHIS_N.INV_CMF_9);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MINVLOTHIS_N.INV_CMF_10);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MINVLOTHIS_N.INV_CMF_11);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MINVLOTHIS_N.INV_CMF_12);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MINVLOTHIS_N.INV_CMF_13);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MINVLOTHIS_N.INV_CMF_14);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MINVLOTHIS_N.INV_CMF_15);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MINVLOTHIS_N.INV_CMF_16);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MINVLOTHIS_N.INV_CMF_17);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MINVLOTHIS_N.INV_CMF_18);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MINVLOTHIS_N.INV_CMF_19);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MINVLOTHIS_N.INV_CMF_20);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MINVLOTHIS_N.ORG_INV_LOT_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MINVLOTHIS_N.FROM_TO_DIV);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MINVLOTHIS_N.FROM_TO_INV_LOT_ID);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)&(MINVLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[93] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)&(MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[94] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MINVLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[95] = (unsigned int  )11;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MINVLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MINVLOTHIS_N.OLD_AREA_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MINVLOTHIS_N.OLD_SUB_AREA_ID);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MINVLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[99] = (unsigned int  )11;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)&(MINVLOTHIS_N.OLD_QTY);
            sqlstm.sqhstl[100] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[101] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[102] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MINVLOTHIS_N.OLD_UNIT);
            sqlstm.sqhstl[103] = (unsigned int  )11;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_2);
            sqlstm.sqhstl[104] = (unsigned int  )11;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_3);
            sqlstm.sqhstl[105] = (unsigned int  )11;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY);
            sqlstm.sqhstl[106] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_2);
            sqlstm.sqhstl[107] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_3);
            sqlstm.sqhstl[108] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY);
            sqlstm.sqhstl[109] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MINVLOTHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[112] = (unsigned int  )21;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MINVLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[113] = (unsigned int  )15;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MINVLOTHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[114] = (unsigned int  )21;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MINVLOTHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[115] = (unsigned int  )15;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MINVLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[116] = (unsigned int  )2;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MINVLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MINVLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[118] = (unsigned int  )15;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MINVLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[119] = (unsigned int  )401;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBU_MINVLOTHIS_CUR_2 INTO
                :MINVLOTHIS_N.FACTORY,
                :MINVLOTHIS_N.INV_LOT_ID,
                :MINVLOTHIS_N.HIST_SEQ,
                :MINVLOTHIS_N.INV_LOT_DESC,
                :MINVLOTHIS_N.INV_LOT_TYPE,
                :MINVLOTHIS_N.TRAN_CODE,
                :MINVLOTHIS_N.TRAN_USER_ID,
                :MINVLOTHIS_N.TRAN_TIME,
                :MINVLOTHIS_N.SYS_TRAN_TIME,
                :MINVLOTHIS_N.TRAN_COMMENT,
                :MINVLOTHIS_N.INV_LOT_STATUS,
                :MINVLOTHIS_N.INV_LOT_PRIORITY,
                :MINVLOTHIS_N.MAT_ID,
                :MINVLOTHIS_N.MAT_VER,
                :MINVLOTHIS_N.QTY,
                :MINVLOTHIS_N.QTY_2,
                :MINVLOTHIS_N.QTY_3,
                :MINVLOTHIS_N.UNIT,
                :MINVLOTHIS_N.UNIT_2,
                :MINVLOTHIS_N.UNIT_3,
                :MINVLOTHIS_N.ORDER_ID,
                :MINVLOTHIS_N.ADD_ORDER_ID_1,
                :MINVLOTHIS_N.ADD_ORDER_ID_2,
                :MINVLOTHIS_N.ADD_ORDER_ID_3,
                :MINVLOTHIS_N.VENDOR_ID,
				:MINVLOTHIS_N.VENDOR_SITE_ID,
                :MINVLOTHIS_N.VENDOR_LOT_ID,
                :MINVLOTHIS_N.AREA_ID,
                :MINVLOTHIS_N.SUB_AREA_ID,
                :MINVLOTHIS_N.LOCATION_1,
                :MINVLOTHIS_N.LOCATION_2,
                :MINVLOTHIS_N.LOCATION_3,
                :MINVLOTHIS_N.OPER,
                :MINVLOTHIS_N.LOC_NO,
                :MINVLOTHIS_N.RES_ID,
                :MINVLOTHIS_N.PORT_ID,
                :MINVLOTHIS_N.SLOT_NO,
                :MINVLOTHIS_N.CRR_ID,
                :MINVLOTHIS_N.LOT_ID,
                :MINVLOTHIS_N.RECV_DATE,
                :MINVLOTHIS_N.RECV_QTY,
                :MINVLOTHIS_N.REASON_CODE,
                :MINVLOTHIS_N.LOAD_FLAG,
                :MINVLOTHIS_N.TRANSIT_FLAG,
                :MINVLOTHIS_N.DELETE_FLAG,
                :MINVLOTHIS_N.DELETE_CODE,
                :MINVLOTHIS_N.DELETE_TIME,
                :MINVLOTHIS_N.HOLD_FLAG,
                :MINVLOTHIS_N.HOLD_CODE,
                :MINVLOTHIS_N.INSP_FLAG,
                :MINVLOTHIS_N.INSP_ID,
                :MINVLOTHIS_N.INSP_RESULT_FLAG,
                :MINVLOTHIS_N.INV_LOT_GRADE,
                :MINVLOTHIS_N.DLV_NO,
                :MINVLOTHIS_N.DLV_SEQ,
                :MINVLOTHIS_N.PO_NO,
                :MINVLOTHIS_N.PO_SEQ,
                :MINVLOTHIS_N.BL_NO,
                :MINVLOTHIS_N.BL_SEQ,
				:MINVLOTHIS_N.PO_DISTRIBUTION_ID,
                :MINVLOTHIS_N.INV_CMF_1,
                :MINVLOTHIS_N.INV_CMF_2,
                :MINVLOTHIS_N.INV_CMF_3,
                :MINVLOTHIS_N.INV_CMF_4,
                :MINVLOTHIS_N.INV_CMF_5,
                :MINVLOTHIS_N.INV_CMF_6,
                :MINVLOTHIS_N.INV_CMF_7,
                :MINVLOTHIS_N.INV_CMF_8,
                :MINVLOTHIS_N.INV_CMF_9,
                :MINVLOTHIS_N.INV_CMF_10,
                :MINVLOTHIS_N.INV_CMF_11,
                :MINVLOTHIS_N.INV_CMF_12,
                :MINVLOTHIS_N.INV_CMF_13,
                :MINVLOTHIS_N.INV_CMF_14,
                :MINVLOTHIS_N.INV_CMF_15,
                :MINVLOTHIS_N.INV_CMF_16,
                :MINVLOTHIS_N.INV_CMF_17,
                :MINVLOTHIS_N.INV_CMF_18,
                :MINVLOTHIS_N.INV_CMF_19,
                :MINVLOTHIS_N.INV_CMF_20,
                :MINVLOTHIS_N.TRAN_CMF_1,
                :MINVLOTHIS_N.TRAN_CMF_2,
                :MINVLOTHIS_N.TRAN_CMF_3,
                :MINVLOTHIS_N.TRAN_CMF_4,
                :MINVLOTHIS_N.TRAN_CMF_5,
                :MINVLOTHIS_N.TRAN_CMF_6,
                :MINVLOTHIS_N.TRAN_CMF_7,
                :MINVLOTHIS_N.TRAN_CMF_8,
                :MINVLOTHIS_N.TRAN_CMF_9,
                :MINVLOTHIS_N.TRAN_CMF_10,
                :MINVLOTHIS_N.ORG_INV_LOT_ID,
                :MINVLOTHIS_N.FROM_TO_DIV,
                :MINVLOTHIS_N.FROM_TO_INV_LOT_ID,
                :MINVLOTHIS_N.FROM_TO_HIST_SEQ,
                :MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ,
                :MINVLOTHIS_N.OLD_FACTORY,
                :MINVLOTHIS_N.OLD_MAT_ID,
				:MINVLOTHIS_N.OLD_AREA_ID,
                :MINVLOTHIS_N.OLD_SUB_AREA_ID,
                :MINVLOTHIS_N.OLD_OPER,
                :MINVLOTHIS_N.OLD_QTY,
                :MINVLOTHIS_N.OLD_QTY_2,
                :MINVLOTHIS_N.OLD_QTY_3,
                :MINVLOTHIS_N.OLD_UNIT,
                :MINVLOTHIS_N.OLD_UNIT_2,
                :MINVLOTHIS_N.OLD_UNIT_3,
                :MINVLOTHIS_N.CHANGE_QTY,
                :MINVLOTHIS_N.CHANGE_QTY_2,
                :MINVLOTHIS_N.CHANGE_QTY_3,
                :MINVLOTHIS_N.CREATE_QTY,
                :MINVLOTHIS_N.CREATE_QTY_2,
                :MINVLOTHIS_N.CREATE_QTY_3,
                :MINVLOTHIS_N.CREATE_USER_ID,
                :MINVLOTHIS_N.CREATE_TIME,
                :MINVLOTHIS_N.UPDATE_USER_ID,
                :MINVLOTHIS_N.UPDATE_TIME,
                :MINVLOTHIS_N.HIST_DEL_FLAG,
                :MINVLOTHIS_N.HIST_DEL_USER_ID,
                :MINVLOTHIS_N.HIST_DEL_TIME,
                :MINVLOTHIS_N.HIST_DEL_COMMENT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2650;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MINVLOTHIS_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MINVLOTHIS_N.INV_LOT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )26;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(MINVLOTHIS_N.HIST_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MINVLOTHIS_N.INV_LOT_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MINVLOTHIS_N.INV_LOT_TYPE);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MINVLOTHIS_N.TRAN_CODE);
            sqlstm.sqhstl[5] = (unsigned int  )13;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MINVLOTHIS_N.TRAN_USER_ID);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MINVLOTHIS_N.TRAN_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )15;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MINVLOTHIS_N.SYS_TRAN_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )15;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MINVLOTHIS_N.TRAN_COMMENT);
            sqlstm.sqhstl[9] = (unsigned int  )401;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MINVLOTHIS_N.INV_LOT_STATUS);
            sqlstm.sqhstl[10] = (unsigned int  )11;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MINVLOTHIS_N.INV_LOT_PRIORITY);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MINVLOTHIS_N.MAT_ID);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(MINVLOTHIS_N.MAT_VER);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(MINVLOTHIS_N.QTY);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(MINVLOTHIS_N.QTY_2);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)&(MINVLOTHIS_N.QTY_3);
            sqlstm.sqhstl[16] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MINVLOTHIS_N.UNIT);
            sqlstm.sqhstl[17] = (unsigned int  )11;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MINVLOTHIS_N.UNIT_2);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MINVLOTHIS_N.UNIT_3);
            sqlstm.sqhstl[19] = (unsigned int  )11;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MINVLOTHIS_N.ORDER_ID);
            sqlstm.sqhstl[20] = (unsigned int  )26;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[21] = (unsigned int  )26;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[22] = (unsigned int  )26;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MINVLOTHIS_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[23] = (unsigned int  )26;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MINVLOTHIS_N.VENDOR_ID);
            sqlstm.sqhstl[24] = (unsigned int  )21;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(MINVLOTHIS_N.VENDOR_SITE_ID);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MINVLOTHIS_N.VENDOR_LOT_ID);
            sqlstm.sqhstl[26] = (unsigned int  )51;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MINVLOTHIS_N.AREA_ID);
            sqlstm.sqhstl[27] = (unsigned int  )21;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MINVLOTHIS_N.SUB_AREA_ID);
            sqlstm.sqhstl[28] = (unsigned int  )21;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MINVLOTHIS_N.LOCATION_1);
            sqlstm.sqhstl[29] = (unsigned int  )21;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MINVLOTHIS_N.LOCATION_2);
            sqlstm.sqhstl[30] = (unsigned int  )21;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MINVLOTHIS_N.LOCATION_3);
            sqlstm.sqhstl[31] = (unsigned int  )21;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MINVLOTHIS_N.OPER);
            sqlstm.sqhstl[32] = (unsigned int  )11;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MINVLOTHIS_N.LOC_NO);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MINVLOTHIS_N.RES_ID);
            sqlstm.sqhstl[34] = (unsigned int  )21;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MINVLOTHIS_N.PORT_ID);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MINVLOTHIS_N.SLOT_NO);
            sqlstm.sqhstl[36] = (unsigned int  )11;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MINVLOTHIS_N.CRR_ID);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MINVLOTHIS_N.LOT_ID);
            sqlstm.sqhstl[38] = (unsigned int  )26;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MINVLOTHIS_N.RECV_DATE);
            sqlstm.sqhstl[39] = (unsigned int  )9;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)&(MINVLOTHIS_N.RECV_QTY);
            sqlstm.sqhstl[40] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MINVLOTHIS_N.REASON_CODE);
            sqlstm.sqhstl[41] = (unsigned int  )31;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MINVLOTHIS_N.LOAD_FLAG);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MINVLOTHIS_N.TRANSIT_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MINVLOTHIS_N.DELETE_FLAG);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MINVLOTHIS_N.DELETE_CODE);
            sqlstm.sqhstl[45] = (unsigned int  )31;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MINVLOTHIS_N.DELETE_TIME);
            sqlstm.sqhstl[46] = (unsigned int  )15;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MINVLOTHIS_N.HOLD_FLAG);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MINVLOTHIS_N.HOLD_CODE);
            sqlstm.sqhstl[48] = (unsigned int  )31;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MINVLOTHIS_N.INSP_FLAG);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MINVLOTHIS_N.INSP_ID);
            sqlstm.sqhstl[50] = (unsigned int  )31;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MINVLOTHIS_N.INSP_RESULT_FLAG);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MINVLOTHIS_N.INV_LOT_GRADE);
            sqlstm.sqhstl[52] = (unsigned int  )11;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MINVLOTHIS_N.DLV_NO);
            sqlstm.sqhstl[53] = (unsigned int  )31;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)&(MINVLOTHIS_N.DLV_SEQ);
            sqlstm.sqhstl[54] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MINVLOTHIS_N.PO_NO);
            sqlstm.sqhstl[55] = (unsigned int  )31;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)&(MINVLOTHIS_N.PO_SEQ);
            sqlstm.sqhstl[56] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MINVLOTHIS_N.BL_NO);
            sqlstm.sqhstl[57] = (unsigned int  )31;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)&(MINVLOTHIS_N.BL_SEQ);
            sqlstm.sqhstl[58] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)&(MINVLOTHIS_N.PO_DISTRIBUTION_ID);
            sqlstm.sqhstl[59] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MINVLOTHIS_N.INV_CMF_1);
            sqlstm.sqhstl[60] = (unsigned int  )31;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MINVLOTHIS_N.INV_CMF_2);
            sqlstm.sqhstl[61] = (unsigned int  )31;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MINVLOTHIS_N.INV_CMF_3);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MINVLOTHIS_N.INV_CMF_4);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MINVLOTHIS_N.INV_CMF_5);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MINVLOTHIS_N.INV_CMF_6);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MINVLOTHIS_N.INV_CMF_7);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MINVLOTHIS_N.INV_CMF_8);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MINVLOTHIS_N.INV_CMF_9);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MINVLOTHIS_N.INV_CMF_10);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MINVLOTHIS_N.INV_CMF_11);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MINVLOTHIS_N.INV_CMF_12);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MINVLOTHIS_N.INV_CMF_13);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MINVLOTHIS_N.INV_CMF_14);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MINVLOTHIS_N.INV_CMF_15);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MINVLOTHIS_N.INV_CMF_16);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MINVLOTHIS_N.INV_CMF_17);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MINVLOTHIS_N.INV_CMF_18);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MINVLOTHIS_N.INV_CMF_19);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MINVLOTHIS_N.INV_CMF_20);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_1);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_2);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_3);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_4);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_5);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_6);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_7);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_8);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_9);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MINVLOTHIS_N.TRAN_CMF_10);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MINVLOTHIS_N.ORG_INV_LOT_ID);
            sqlstm.sqhstl[90] = (unsigned int  )26;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MINVLOTHIS_N.FROM_TO_DIV);
            sqlstm.sqhstl[91] = (unsigned int  )2;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MINVLOTHIS_N.FROM_TO_INV_LOT_ID);
            sqlstm.sqhstl[92] = (unsigned int  )26;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)&(MINVLOTHIS_N.FROM_TO_HIST_SEQ);
            sqlstm.sqhstl[93] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)&(MINVLOTHIS_N.OLD_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[94] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MINVLOTHIS_N.OLD_FACTORY);
            sqlstm.sqhstl[95] = (unsigned int  )11;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MINVLOTHIS_N.OLD_MAT_ID);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MINVLOTHIS_N.OLD_AREA_ID);
            sqlstm.sqhstl[97] = (unsigned int  )21;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MINVLOTHIS_N.OLD_SUB_AREA_ID);
            sqlstm.sqhstl[98] = (unsigned int  )21;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MINVLOTHIS_N.OLD_OPER);
            sqlstm.sqhstl[99] = (unsigned int  )11;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)&(MINVLOTHIS_N.OLD_QTY);
            sqlstm.sqhstl[100] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_2);
            sqlstm.sqhstl[101] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)&(MINVLOTHIS_N.OLD_QTY_3);
            sqlstm.sqhstl[102] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MINVLOTHIS_N.OLD_UNIT);
            sqlstm.sqhstl[103] = (unsigned int  )11;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_2);
            sqlstm.sqhstl[104] = (unsigned int  )11;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MINVLOTHIS_N.OLD_UNIT_3);
            sqlstm.sqhstl[105] = (unsigned int  )11;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY);
            sqlstm.sqhstl[106] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_2);
            sqlstm.sqhstl[107] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)&(MINVLOTHIS_N.CHANGE_QTY_3);
            sqlstm.sqhstl[108] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY);
            sqlstm.sqhstl[109] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_2);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(MINVLOTHIS_N.CREATE_QTY_3);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MINVLOTHIS_N.CREATE_USER_ID);
            sqlstm.sqhstl[112] = (unsigned int  )21;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MINVLOTHIS_N.CREATE_TIME);
            sqlstm.sqhstl[113] = (unsigned int  )15;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MINVLOTHIS_N.UPDATE_USER_ID);
            sqlstm.sqhstl[114] = (unsigned int  )21;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MINVLOTHIS_N.UPDATE_TIME);
            sqlstm.sqhstl[115] = (unsigned int  )15;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MINVLOTHIS_N.HIST_DEL_FLAG);
            sqlstm.sqhstl[116] = (unsigned int  )2;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MINVLOTHIS_N.HIST_DEL_USER_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MINVLOTHIS_N.HIST_DEL_TIME);
            sqlstm.sqhstl[118] = (unsigned int  )15;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MINVLOTHIS_N.HIST_DEL_COMMENT);
            sqlstm.sqhstl[119] = (unsigned int  )401;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
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
        DBU_del_null_minvlothis(&MINVLOTHIS_N, MINVLOTHIS);
    }

    DB_stop_query_timer("DBU_fetch_minvlothis", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBU_close_minvlothis(int sel_type)
{
    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBU_MINVLOTHIS_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3145;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 2:
            /* EXEC SQL CLOSE DBU_MINVLOTHIS_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 123;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3160;
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

    DB_stop_query_timer("DBU_close_minvlothis", sel_type);
}


/* Initialize Function */
void DBU_init_minvlothis(struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* memset by Space */
    memset(MINVLOTHIS, ' ', sizeof(struct MINVLOTHIS_TAG));
    
    MINVLOTHIS->HIST_SEQ = 0;
    MINVLOTHIS->MAT_VER = 0;
    MINVLOTHIS->QTY = 0;
    MINVLOTHIS->QTY_2 = 0;
    MINVLOTHIS->QTY_3 = 0;
    MINVLOTHIS->RECV_QTY = 0;
	MINVLOTHIS->DLV_SEQ = 0;
    MINVLOTHIS->PO_SEQ = 0;
    MINVLOTHIS->BL_SEQ = 0;
	MINVLOTHIS->PO_DISTRIBUTION_ID = 0;
    MINVLOTHIS->FROM_TO_HIST_SEQ = 0;
	MINVLOTHIS->VENDOR_SITE_ID = 0;
    MINVLOTHIS->OLD_ACTIVE_HIST_SEQ = 0;
    MINVLOTHIS->OLD_QTY = 0;
    MINVLOTHIS->OLD_QTY_2 = 0;
    MINVLOTHIS->OLD_QTY_3 = 0;
    MINVLOTHIS->CHANGE_QTY = 0;
    MINVLOTHIS->CHANGE_QTY_2 = 0;
    MINVLOTHIS->CHANGE_QTY_3 = 0;
    MINVLOTHIS->CREATE_QTY = 0;
    MINVLOTHIS->CREATE_QTY_2 = 0;
    MINVLOTHIS->CREATE_QTY_3 = 0;
}


/* Add Null Function */
void DBU_add_null_minvlothis(struct MINVLOTHIS_N_TAG *MINVLOTHIS_N, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    /* memset by NULL */
    memset(MINVLOTHIS_N, '\0', sizeof(struct MINVLOTHIS_N_TAG));
    
    MEMCPY_AN(MINVLOTHIS_N->FACTORY, MINVLOTHIS->FACTORY, sizeof(MINVLOTHIS->FACTORY));
    MEMCPY_AN(MINVLOTHIS_N->INV_LOT_ID, MINVLOTHIS->INV_LOT_ID, sizeof(MINVLOTHIS->INV_LOT_ID));
    MINVLOTHIS_N->HIST_SEQ = MINVLOTHIS->HIST_SEQ;
    MEMCPY_AN(MINVLOTHIS_N->INV_LOT_DESC, MINVLOTHIS->INV_LOT_DESC, sizeof(MINVLOTHIS->INV_LOT_DESC));
    MEMCPY_AN(MINVLOTHIS_N->INV_LOT_TYPE, MINVLOTHIS->INV_LOT_TYPE, sizeof(MINVLOTHIS->INV_LOT_TYPE));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CODE, MINVLOTHIS->TRAN_CODE, sizeof(MINVLOTHIS->TRAN_CODE));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_USER_ID, MINVLOTHIS->TRAN_USER_ID, sizeof(MINVLOTHIS->TRAN_USER_ID));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_TIME, MINVLOTHIS->TRAN_TIME, sizeof(MINVLOTHIS->TRAN_TIME));
    MEMCPY_AN(MINVLOTHIS_N->SYS_TRAN_TIME, MINVLOTHIS->SYS_TRAN_TIME, sizeof(MINVLOTHIS->SYS_TRAN_TIME));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_COMMENT, MINVLOTHIS->TRAN_COMMENT, sizeof(MINVLOTHIS->TRAN_COMMENT));
    MEMCPY_AN(MINVLOTHIS_N->INV_LOT_STATUS, MINVLOTHIS->INV_LOT_STATUS, sizeof(MINVLOTHIS->INV_LOT_STATUS));
    MINVLOTHIS_N->INV_LOT_PRIORITY[0] = MINVLOTHIS->INV_LOT_PRIORITY;
    MEMCPY_AN(MINVLOTHIS_N->MAT_ID, MINVLOTHIS->MAT_ID, sizeof(MINVLOTHIS->MAT_ID));
    MINVLOTHIS_N->MAT_VER = MINVLOTHIS->MAT_VER;
    MINVLOTHIS_N->QTY = MINVLOTHIS->QTY;
    MINVLOTHIS_N->QTY_2 = MINVLOTHIS->QTY_2;
    MINVLOTHIS_N->QTY_3 = MINVLOTHIS->QTY_3;
    MEMCPY_AN(MINVLOTHIS_N->UNIT, MINVLOTHIS->UNIT, sizeof(MINVLOTHIS->UNIT));
    MEMCPY_AN(MINVLOTHIS_N->UNIT_2, MINVLOTHIS->UNIT_2, sizeof(MINVLOTHIS->UNIT_2));
    MEMCPY_AN(MINVLOTHIS_N->UNIT_3, MINVLOTHIS->UNIT_3, sizeof(MINVLOTHIS->UNIT_3));
    MEMCPY_AN(MINVLOTHIS_N->ORDER_ID, MINVLOTHIS->ORDER_ID, sizeof(MINVLOTHIS->ORDER_ID));
    MEMCPY_AN(MINVLOTHIS_N->ADD_ORDER_ID_1, MINVLOTHIS->ADD_ORDER_ID_1, sizeof(MINVLOTHIS->ADD_ORDER_ID_1));
    MEMCPY_AN(MINVLOTHIS_N->ADD_ORDER_ID_2, MINVLOTHIS->ADD_ORDER_ID_2, sizeof(MINVLOTHIS->ADD_ORDER_ID_2));
    MEMCPY_AN(MINVLOTHIS_N->ADD_ORDER_ID_3, MINVLOTHIS->ADD_ORDER_ID_3, sizeof(MINVLOTHIS->ADD_ORDER_ID_3));
    MEMCPY_AN(MINVLOTHIS_N->VENDOR_ID, MINVLOTHIS->VENDOR_ID, sizeof(MINVLOTHIS->VENDOR_ID));
	MINVLOTHIS_N->VENDOR_SITE_ID = MINVLOTHIS->VENDOR_SITE_ID;
    MEMCPY_AN(MINVLOTHIS_N->VENDOR_LOT_ID, MINVLOTHIS->VENDOR_LOT_ID, sizeof(MINVLOTHIS->VENDOR_LOT_ID));
    MEMCPY_AN(MINVLOTHIS_N->AREA_ID, MINVLOTHIS->AREA_ID, sizeof(MINVLOTHIS->AREA_ID));
    MEMCPY_AN(MINVLOTHIS_N->SUB_AREA_ID, MINVLOTHIS->SUB_AREA_ID, sizeof(MINVLOTHIS->SUB_AREA_ID));
    MEMCPY_AN(MINVLOTHIS_N->LOCATION_1, MINVLOTHIS->LOCATION_1, sizeof(MINVLOTHIS->LOCATION_1));
    MEMCPY_AN(MINVLOTHIS_N->LOCATION_2, MINVLOTHIS->LOCATION_2, sizeof(MINVLOTHIS->LOCATION_2));
    MEMCPY_AN(MINVLOTHIS_N->LOCATION_3, MINVLOTHIS->LOCATION_3, sizeof(MINVLOTHIS->LOCATION_3));
    MEMCPY_AN(MINVLOTHIS_N->OPER, MINVLOTHIS->OPER, sizeof(MINVLOTHIS->OPER));
    MEMCPY_AN(MINVLOTHIS_N->LOC_NO, MINVLOTHIS->LOC_NO, sizeof(MINVLOTHIS->LOC_NO));
    MEMCPY_AN(MINVLOTHIS_N->RES_ID, MINVLOTHIS->RES_ID, sizeof(MINVLOTHIS->RES_ID));
    MEMCPY_AN(MINVLOTHIS_N->PORT_ID, MINVLOTHIS->PORT_ID, sizeof(MINVLOTHIS->PORT_ID));
    MEMCPY_AN(MINVLOTHIS_N->SLOT_NO, MINVLOTHIS->SLOT_NO, sizeof(MINVLOTHIS->SLOT_NO));
    MEMCPY_AN(MINVLOTHIS_N->CRR_ID, MINVLOTHIS->CRR_ID, sizeof(MINVLOTHIS->CRR_ID));
    MEMCPY_AN(MINVLOTHIS_N->LOT_ID, MINVLOTHIS->LOT_ID, sizeof(MINVLOTHIS->LOT_ID));
    MEMCPY_AN(MINVLOTHIS_N->RECV_DATE, MINVLOTHIS->RECV_DATE, sizeof(MINVLOTHIS->RECV_DATE));
    MINVLOTHIS_N->RECV_QTY = MINVLOTHIS->RECV_QTY;
    MEMCPY_AN(MINVLOTHIS_N->REASON_CODE, MINVLOTHIS->REASON_CODE, sizeof(MINVLOTHIS->REASON_CODE));
    MINVLOTHIS_N->LOAD_FLAG[0] = MINVLOTHIS->LOAD_FLAG;
    MINVLOTHIS_N->TRANSIT_FLAG[0] = MINVLOTHIS->TRANSIT_FLAG;
    MINVLOTHIS_N->DELETE_FLAG[0] = MINVLOTHIS->DELETE_FLAG;
    MEMCPY_AN(MINVLOTHIS_N->DELETE_CODE, MINVLOTHIS->DELETE_CODE, sizeof(MINVLOTHIS->DELETE_CODE));
    MEMCPY_AN(MINVLOTHIS_N->DELETE_TIME, MINVLOTHIS->DELETE_TIME, sizeof(MINVLOTHIS->DELETE_TIME));
    MINVLOTHIS_N->HOLD_FLAG[0] = MINVLOTHIS->HOLD_FLAG;
    MEMCPY_AN(MINVLOTHIS_N->HOLD_CODE, MINVLOTHIS->HOLD_CODE, sizeof(MINVLOTHIS->HOLD_CODE));
    MINVLOTHIS_N->INSP_FLAG[0] = MINVLOTHIS->INSP_FLAG;
    MEMCPY_AN(MINVLOTHIS_N->INSP_ID, MINVLOTHIS->INSP_ID, sizeof(MINVLOTHIS->INSP_ID));
	MINVLOTHIS_N->INSP_RESULT_FLAG[0] = MINVLOTHIS->INSP_RESULT_FLAG;
    MEMCPY_AN(MINVLOTHIS_N->INV_LOT_GRADE, MINVLOTHIS->INV_LOT_GRADE, sizeof(MINVLOTHIS->INV_LOT_GRADE));
    MEMCPY_AN(MINVLOTHIS_N->DLV_NO, MINVLOTHIS->DLV_NO, sizeof(MINVLOTHIS->DLV_NO));
    MINVLOTHIS_N->DLV_SEQ = MINVLOTHIS->DLV_SEQ;
    MEMCPY_AN(MINVLOTHIS_N->PO_NO, MINVLOTHIS->PO_NO, sizeof(MINVLOTHIS->PO_NO));
    MINVLOTHIS_N->PO_SEQ = MINVLOTHIS->PO_SEQ;
    MEMCPY_AN(MINVLOTHIS_N->BL_NO, MINVLOTHIS->BL_NO, sizeof(MINVLOTHIS->BL_NO));
    MINVLOTHIS_N->BL_SEQ = MINVLOTHIS->BL_SEQ;
	MINVLOTHIS_N->PO_DISTRIBUTION_ID = MINVLOTHIS->PO_DISTRIBUTION_ID;
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_1, MINVLOTHIS->INV_CMF_1, sizeof(MINVLOTHIS->INV_CMF_1));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_2, MINVLOTHIS->INV_CMF_2, sizeof(MINVLOTHIS->INV_CMF_2));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_3, MINVLOTHIS->INV_CMF_3, sizeof(MINVLOTHIS->INV_CMF_3));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_4, MINVLOTHIS->INV_CMF_4, sizeof(MINVLOTHIS->INV_CMF_4));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_5, MINVLOTHIS->INV_CMF_5, sizeof(MINVLOTHIS->INV_CMF_5));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_6, MINVLOTHIS->INV_CMF_6, sizeof(MINVLOTHIS->INV_CMF_6));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_7, MINVLOTHIS->INV_CMF_7, sizeof(MINVLOTHIS->INV_CMF_7));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_8, MINVLOTHIS->INV_CMF_8, sizeof(MINVLOTHIS->INV_CMF_8));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_9, MINVLOTHIS->INV_CMF_9, sizeof(MINVLOTHIS->INV_CMF_9));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_10, MINVLOTHIS->INV_CMF_10, sizeof(MINVLOTHIS->INV_CMF_10));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_11, MINVLOTHIS->INV_CMF_11, sizeof(MINVLOTHIS->INV_CMF_11));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_12, MINVLOTHIS->INV_CMF_12, sizeof(MINVLOTHIS->INV_CMF_12));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_13, MINVLOTHIS->INV_CMF_13, sizeof(MINVLOTHIS->INV_CMF_13));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_14, MINVLOTHIS->INV_CMF_14, sizeof(MINVLOTHIS->INV_CMF_14));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_15, MINVLOTHIS->INV_CMF_15, sizeof(MINVLOTHIS->INV_CMF_15));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_16, MINVLOTHIS->INV_CMF_16, sizeof(MINVLOTHIS->INV_CMF_16));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_17, MINVLOTHIS->INV_CMF_17, sizeof(MINVLOTHIS->INV_CMF_17));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_18, MINVLOTHIS->INV_CMF_18, sizeof(MINVLOTHIS->INV_CMF_18));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_19, MINVLOTHIS->INV_CMF_19, sizeof(MINVLOTHIS->INV_CMF_19));
    MEMCPY_AN(MINVLOTHIS_N->INV_CMF_20, MINVLOTHIS->INV_CMF_20, sizeof(MINVLOTHIS->INV_CMF_20));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_1, MINVLOTHIS->TRAN_CMF_1, sizeof(MINVLOTHIS->TRAN_CMF_1));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_2, MINVLOTHIS->TRAN_CMF_2, sizeof(MINVLOTHIS->TRAN_CMF_2));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_3, MINVLOTHIS->TRAN_CMF_3, sizeof(MINVLOTHIS->TRAN_CMF_3));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_4, MINVLOTHIS->TRAN_CMF_4, sizeof(MINVLOTHIS->TRAN_CMF_4));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_5, MINVLOTHIS->TRAN_CMF_5, sizeof(MINVLOTHIS->TRAN_CMF_5));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_6, MINVLOTHIS->TRAN_CMF_6, sizeof(MINVLOTHIS->TRAN_CMF_6));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_7, MINVLOTHIS->TRAN_CMF_7, sizeof(MINVLOTHIS->TRAN_CMF_7));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_8, MINVLOTHIS->TRAN_CMF_8, sizeof(MINVLOTHIS->TRAN_CMF_8));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_9, MINVLOTHIS->TRAN_CMF_9, sizeof(MINVLOTHIS->TRAN_CMF_9));
    MEMCPY_AN(MINVLOTHIS_N->TRAN_CMF_10, MINVLOTHIS->TRAN_CMF_10, sizeof(MINVLOTHIS->TRAN_CMF_10));
    MEMCPY_AN(MINVLOTHIS_N->ORG_INV_LOT_ID, MINVLOTHIS->ORG_INV_LOT_ID, sizeof(MINVLOTHIS->ORG_INV_LOT_ID));
    MINVLOTHIS_N->FROM_TO_DIV[0] = MINVLOTHIS->FROM_TO_DIV;
    MEMCPY_AN(MINVLOTHIS_N->FROM_TO_INV_LOT_ID, MINVLOTHIS->FROM_TO_INV_LOT_ID, sizeof(MINVLOTHIS->FROM_TO_INV_LOT_ID));
    MINVLOTHIS_N->FROM_TO_HIST_SEQ = MINVLOTHIS->FROM_TO_HIST_SEQ;
    MINVLOTHIS_N->OLD_ACTIVE_HIST_SEQ = MINVLOTHIS->OLD_ACTIVE_HIST_SEQ;
    MEMCPY_AN(MINVLOTHIS_N->OLD_FACTORY, MINVLOTHIS->OLD_FACTORY, sizeof(MINVLOTHIS->OLD_FACTORY));
    MEMCPY_AN(MINVLOTHIS_N->OLD_MAT_ID, MINVLOTHIS->OLD_MAT_ID, sizeof(MINVLOTHIS->OLD_MAT_ID));
	MEMCPY_AN(MINVLOTHIS_N->OLD_AREA_ID, MINVLOTHIS->OLD_AREA_ID, sizeof(MINVLOTHIS->OLD_AREA_ID));
    MEMCPY_AN(MINVLOTHIS_N->OLD_SUB_AREA_ID, MINVLOTHIS->OLD_SUB_AREA_ID, sizeof(MINVLOTHIS->OLD_SUB_AREA_ID));
    MEMCPY_AN(MINVLOTHIS_N->OLD_OPER, MINVLOTHIS->OLD_OPER, sizeof(MINVLOTHIS->OLD_OPER));
    MINVLOTHIS_N->OLD_QTY = MINVLOTHIS->OLD_QTY;
    MINVLOTHIS_N->OLD_QTY_2 = MINVLOTHIS->OLD_QTY_2;
    MINVLOTHIS_N->OLD_QTY_3 = MINVLOTHIS->OLD_QTY_3;
    MEMCPY_AN(MINVLOTHIS_N->OLD_UNIT, MINVLOTHIS->OLD_UNIT, sizeof(MINVLOTHIS->OLD_UNIT));
    MEMCPY_AN(MINVLOTHIS_N->OLD_UNIT_2, MINVLOTHIS->OLD_UNIT_2, sizeof(MINVLOTHIS->OLD_UNIT_2));
    MEMCPY_AN(MINVLOTHIS_N->OLD_UNIT_3, MINVLOTHIS->OLD_UNIT_3, sizeof(MINVLOTHIS->OLD_UNIT_3));
    MINVLOTHIS_N->CHANGE_QTY = MINVLOTHIS->CHANGE_QTY;
    MINVLOTHIS_N->CHANGE_QTY_2 = MINVLOTHIS->CHANGE_QTY_2;
    MINVLOTHIS_N->CHANGE_QTY_3 = MINVLOTHIS->CHANGE_QTY_3;
    MINVLOTHIS_N->CREATE_QTY = MINVLOTHIS->CREATE_QTY;
    MINVLOTHIS_N->CREATE_QTY_2 = MINVLOTHIS->CREATE_QTY_2;
    MINVLOTHIS_N->CREATE_QTY_3 = MINVLOTHIS->CREATE_QTY_3;
    MEMCPY_AN(MINVLOTHIS_N->CREATE_USER_ID, MINVLOTHIS->CREATE_USER_ID, sizeof(MINVLOTHIS->CREATE_USER_ID));
    MEMCPY_AN(MINVLOTHIS_N->CREATE_TIME, MINVLOTHIS->CREATE_TIME, sizeof(MINVLOTHIS->CREATE_TIME));
    MEMCPY_AN(MINVLOTHIS_N->UPDATE_USER_ID, MINVLOTHIS->UPDATE_USER_ID, sizeof(MINVLOTHIS->UPDATE_USER_ID));
    MEMCPY_AN(MINVLOTHIS_N->UPDATE_TIME, MINVLOTHIS->UPDATE_TIME, sizeof(MINVLOTHIS->UPDATE_TIME));
    MINVLOTHIS_N->HIST_DEL_FLAG[0] = MINVLOTHIS->HIST_DEL_FLAG;
    MEMCPY_AN(MINVLOTHIS_N->HIST_DEL_USER_ID, MINVLOTHIS->HIST_DEL_USER_ID, sizeof(MINVLOTHIS->HIST_DEL_USER_ID));
    MEMCPY_AN(MINVLOTHIS_N->HIST_DEL_TIME, MINVLOTHIS->HIST_DEL_TIME, sizeof(MINVLOTHIS->HIST_DEL_TIME));
    MEMCPY_AN(MINVLOTHIS_N->HIST_DEL_COMMENT, MINVLOTHIS->HIST_DEL_COMMENT, sizeof(MINVLOTHIS->HIST_DEL_COMMENT));
}


/* Del Null Function */
void DBU_del_null_minvlothis(struct MINVLOTHIS_N_TAG *MINVLOTHIS_N, struct MINVLOTHIS_TAG *MINVLOTHIS)
{
    MEMCPY_DN(MINVLOTHIS->FACTORY, MINVLOTHIS_N->FACTORY, sizeof(MINVLOTHIS->FACTORY));
    MEMCPY_DN(MINVLOTHIS->INV_LOT_ID, MINVLOTHIS_N->INV_LOT_ID, sizeof(MINVLOTHIS->INV_LOT_ID));
    MINVLOTHIS->HIST_SEQ = MINVLOTHIS_N->HIST_SEQ;
    MEMCPY_DN(MINVLOTHIS->INV_LOT_DESC, MINVLOTHIS_N->INV_LOT_DESC, sizeof(MINVLOTHIS->INV_LOT_DESC));
    MEMCPY_DN(MINVLOTHIS->INV_LOT_TYPE, MINVLOTHIS_N->INV_LOT_TYPE, sizeof(MINVLOTHIS->INV_LOT_TYPE));
    MEMCPY_DN(MINVLOTHIS->TRAN_CODE, MINVLOTHIS_N->TRAN_CODE, sizeof(MINVLOTHIS->TRAN_CODE));
    MEMCPY_DN(MINVLOTHIS->TRAN_USER_ID, MINVLOTHIS_N->TRAN_USER_ID, sizeof(MINVLOTHIS->TRAN_USER_ID));
    MEMCPY_DN(MINVLOTHIS->TRAN_TIME, MINVLOTHIS_N->TRAN_TIME, sizeof(MINVLOTHIS->TRAN_TIME));
    MEMCPY_DN(MINVLOTHIS->SYS_TRAN_TIME, MINVLOTHIS_N->SYS_TRAN_TIME, sizeof(MINVLOTHIS->SYS_TRAN_TIME));
    MEMCPY_DN(MINVLOTHIS->TRAN_COMMENT, MINVLOTHIS_N->TRAN_COMMENT, sizeof(MINVLOTHIS->TRAN_COMMENT));
    MEMCPY_DN(MINVLOTHIS->INV_LOT_STATUS, MINVLOTHIS_N->INV_LOT_STATUS, sizeof(MINVLOTHIS->INV_LOT_STATUS));
    MINVLOTHIS->INV_LOT_PRIORITY = MINVLOTHIS_N->INV_LOT_PRIORITY[0];
    MEMCPY_DN(MINVLOTHIS->MAT_ID, MINVLOTHIS_N->MAT_ID, sizeof(MINVLOTHIS->MAT_ID));
    MINVLOTHIS->MAT_VER = MINVLOTHIS_N->MAT_VER;
    MINVLOTHIS->QTY = MINVLOTHIS_N->QTY;
    MINVLOTHIS->QTY_2 = MINVLOTHIS_N->QTY_2;
    MINVLOTHIS->QTY_3 = MINVLOTHIS_N->QTY_3;
    MEMCPY_DN(MINVLOTHIS->UNIT, MINVLOTHIS_N->UNIT, sizeof(MINVLOTHIS->UNIT));
    MEMCPY_DN(MINVLOTHIS->UNIT_2, MINVLOTHIS_N->UNIT_2, sizeof(MINVLOTHIS->UNIT_2));
    MEMCPY_DN(MINVLOTHIS->UNIT_3, MINVLOTHIS_N->UNIT_3, sizeof(MINVLOTHIS->UNIT_3));
    MEMCPY_DN(MINVLOTHIS->ORDER_ID, MINVLOTHIS_N->ORDER_ID, sizeof(MINVLOTHIS->ORDER_ID));
    MEMCPY_DN(MINVLOTHIS->ADD_ORDER_ID_1, MINVLOTHIS_N->ADD_ORDER_ID_1, sizeof(MINVLOTHIS->ADD_ORDER_ID_1));
    MEMCPY_DN(MINVLOTHIS->ADD_ORDER_ID_2, MINVLOTHIS_N->ADD_ORDER_ID_2, sizeof(MINVLOTHIS->ADD_ORDER_ID_2));
    MEMCPY_DN(MINVLOTHIS->ADD_ORDER_ID_3, MINVLOTHIS_N->ADD_ORDER_ID_3, sizeof(MINVLOTHIS->ADD_ORDER_ID_3));
    MEMCPY_DN(MINVLOTHIS->VENDOR_ID, MINVLOTHIS_N->VENDOR_ID, sizeof(MINVLOTHIS->VENDOR_ID));
	MINVLOTHIS->VENDOR_SITE_ID = MINVLOTHIS_N->VENDOR_SITE_ID;
    MEMCPY_DN(MINVLOTHIS->VENDOR_LOT_ID, MINVLOTHIS_N->VENDOR_LOT_ID, sizeof(MINVLOTHIS->VENDOR_LOT_ID));
    MEMCPY_DN(MINVLOTHIS->AREA_ID, MINVLOTHIS_N->AREA_ID, sizeof(MINVLOTHIS->AREA_ID));
    MEMCPY_DN(MINVLOTHIS->SUB_AREA_ID, MINVLOTHIS_N->SUB_AREA_ID, sizeof(MINVLOTHIS->SUB_AREA_ID));
    MEMCPY_DN(MINVLOTHIS->LOCATION_1, MINVLOTHIS_N->LOCATION_1, sizeof(MINVLOTHIS->LOCATION_1));
    MEMCPY_DN(MINVLOTHIS->LOCATION_2, MINVLOTHIS_N->LOCATION_2, sizeof(MINVLOTHIS->LOCATION_2));
    MEMCPY_DN(MINVLOTHIS->LOCATION_3, MINVLOTHIS_N->LOCATION_3, sizeof(MINVLOTHIS->LOCATION_3));
    MEMCPY_DN(MINVLOTHIS->OPER, MINVLOTHIS_N->OPER, sizeof(MINVLOTHIS->OPER));
    MEMCPY_DN(MINVLOTHIS->LOC_NO, MINVLOTHIS_N->LOC_NO, sizeof(MINVLOTHIS->LOC_NO));
    MEMCPY_DN(MINVLOTHIS->RES_ID, MINVLOTHIS_N->RES_ID, sizeof(MINVLOTHIS->RES_ID));
    MEMCPY_DN(MINVLOTHIS->PORT_ID, MINVLOTHIS_N->PORT_ID, sizeof(MINVLOTHIS->PORT_ID));
    MEMCPY_DN(MINVLOTHIS->SLOT_NO, MINVLOTHIS_N->SLOT_NO, sizeof(MINVLOTHIS->SLOT_NO));
    MEMCPY_DN(MINVLOTHIS->CRR_ID, MINVLOTHIS_N->CRR_ID, sizeof(MINVLOTHIS->CRR_ID));
    MEMCPY_DN(MINVLOTHIS->LOT_ID, MINVLOTHIS_N->LOT_ID, sizeof(MINVLOTHIS->LOT_ID));
    MEMCPY_DN(MINVLOTHIS->RECV_DATE, MINVLOTHIS_N->RECV_DATE, sizeof(MINVLOTHIS->RECV_DATE));
    MINVLOTHIS->RECV_QTY = MINVLOTHIS_N->RECV_QTY;
    MEMCPY_DN(MINVLOTHIS->REASON_CODE, MINVLOTHIS_N->REASON_CODE, sizeof(MINVLOTHIS->REASON_CODE));
    MINVLOTHIS->LOAD_FLAG = MINVLOTHIS_N->LOAD_FLAG[0];
    MINVLOTHIS->TRANSIT_FLAG = MINVLOTHIS_N->TRANSIT_FLAG[0];
    MINVLOTHIS->DELETE_FLAG = MINVLOTHIS_N->DELETE_FLAG[0];
    MEMCPY_DN(MINVLOTHIS->DELETE_CODE, MINVLOTHIS_N->DELETE_CODE, sizeof(MINVLOTHIS->DELETE_CODE));
    MEMCPY_DN(MINVLOTHIS->DELETE_TIME, MINVLOTHIS_N->DELETE_TIME, sizeof(MINVLOTHIS->DELETE_TIME));
    MINVLOTHIS->HOLD_FLAG = MINVLOTHIS_N->HOLD_FLAG[0];
    MEMCPY_DN(MINVLOTHIS->HOLD_CODE, MINVLOTHIS_N->HOLD_CODE, sizeof(MINVLOTHIS->HOLD_CODE));
    MINVLOTHIS->INSP_FLAG = MINVLOTHIS_N->INSP_FLAG[0];
    MEMCPY_DN(MINVLOTHIS->INSP_ID, MINVLOTHIS_N->INSP_ID, sizeof(MINVLOTHIS->INSP_ID));
	MINVLOTHIS->INSP_RESULT_FLAG = MINVLOTHIS_N->INSP_RESULT_FLAG[0];
    MEMCPY_DN(MINVLOTHIS->INV_LOT_GRADE, MINVLOTHIS_N->INV_LOT_GRADE, sizeof(MINVLOTHIS->INV_LOT_GRADE));
    MEMCPY_DN(MINVLOTHIS->DLV_NO, MINVLOTHIS_N->DLV_NO, sizeof(MINVLOTHIS->DLV_NO));
    MINVLOTHIS->DLV_SEQ = MINVLOTHIS_N->DLV_SEQ;
    MEMCPY_DN(MINVLOTHIS->PO_NO, MINVLOTHIS_N->PO_NO, sizeof(MINVLOTHIS->PO_NO));
    MINVLOTHIS->PO_SEQ = MINVLOTHIS_N->PO_SEQ;
    MEMCPY_DN(MINVLOTHIS->BL_NO, MINVLOTHIS_N->BL_NO, sizeof(MINVLOTHIS->BL_NO));
    MINVLOTHIS->BL_SEQ = MINVLOTHIS_N->BL_SEQ;
	MINVLOTHIS->PO_DISTRIBUTION_ID = MINVLOTHIS_N->PO_DISTRIBUTION_ID;
    MEMCPY_DN(MINVLOTHIS->INV_CMF_1, MINVLOTHIS_N->INV_CMF_1, sizeof(MINVLOTHIS->INV_CMF_1));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_2, MINVLOTHIS_N->INV_CMF_2, sizeof(MINVLOTHIS->INV_CMF_2));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_3, MINVLOTHIS_N->INV_CMF_3, sizeof(MINVLOTHIS->INV_CMF_3));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_4, MINVLOTHIS_N->INV_CMF_4, sizeof(MINVLOTHIS->INV_CMF_4));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_5, MINVLOTHIS_N->INV_CMF_5, sizeof(MINVLOTHIS->INV_CMF_5));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_6, MINVLOTHIS_N->INV_CMF_6, sizeof(MINVLOTHIS->INV_CMF_6));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_7, MINVLOTHIS_N->INV_CMF_7, sizeof(MINVLOTHIS->INV_CMF_7));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_8, MINVLOTHIS_N->INV_CMF_8, sizeof(MINVLOTHIS->INV_CMF_8));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_9, MINVLOTHIS_N->INV_CMF_9, sizeof(MINVLOTHIS->INV_CMF_9));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_10, MINVLOTHIS_N->INV_CMF_10, sizeof(MINVLOTHIS->INV_CMF_10));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_11, MINVLOTHIS_N->INV_CMF_11, sizeof(MINVLOTHIS->INV_CMF_11));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_12, MINVLOTHIS_N->INV_CMF_12, sizeof(MINVLOTHIS->INV_CMF_12));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_13, MINVLOTHIS_N->INV_CMF_13, sizeof(MINVLOTHIS->INV_CMF_13));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_14, MINVLOTHIS_N->INV_CMF_14, sizeof(MINVLOTHIS->INV_CMF_14));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_15, MINVLOTHIS_N->INV_CMF_15, sizeof(MINVLOTHIS->INV_CMF_15));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_16, MINVLOTHIS_N->INV_CMF_16, sizeof(MINVLOTHIS->INV_CMF_16));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_17, MINVLOTHIS_N->INV_CMF_17, sizeof(MINVLOTHIS->INV_CMF_17));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_18, MINVLOTHIS_N->INV_CMF_18, sizeof(MINVLOTHIS->INV_CMF_18));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_19, MINVLOTHIS_N->INV_CMF_19, sizeof(MINVLOTHIS->INV_CMF_19));
    MEMCPY_DN(MINVLOTHIS->INV_CMF_20, MINVLOTHIS_N->INV_CMF_20, sizeof(MINVLOTHIS->INV_CMF_20));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_1, MINVLOTHIS_N->TRAN_CMF_1, sizeof(MINVLOTHIS->TRAN_CMF_1));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_2, MINVLOTHIS_N->TRAN_CMF_2, sizeof(MINVLOTHIS->TRAN_CMF_2));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_3, MINVLOTHIS_N->TRAN_CMF_3, sizeof(MINVLOTHIS->TRAN_CMF_3));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_4, MINVLOTHIS_N->TRAN_CMF_4, sizeof(MINVLOTHIS->TRAN_CMF_4));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_5, MINVLOTHIS_N->TRAN_CMF_5, sizeof(MINVLOTHIS->TRAN_CMF_5));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_6, MINVLOTHIS_N->TRAN_CMF_6, sizeof(MINVLOTHIS->TRAN_CMF_6));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_7, MINVLOTHIS_N->TRAN_CMF_7, sizeof(MINVLOTHIS->TRAN_CMF_7));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_8, MINVLOTHIS_N->TRAN_CMF_8, sizeof(MINVLOTHIS->TRAN_CMF_8));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_9, MINVLOTHIS_N->TRAN_CMF_9, sizeof(MINVLOTHIS->TRAN_CMF_9));
    MEMCPY_DN(MINVLOTHIS->TRAN_CMF_10, MINVLOTHIS_N->TRAN_CMF_10, sizeof(MINVLOTHIS->TRAN_CMF_10));
    MEMCPY_DN(MINVLOTHIS->ORG_INV_LOT_ID, MINVLOTHIS_N->ORG_INV_LOT_ID, sizeof(MINVLOTHIS->ORG_INV_LOT_ID));
    MINVLOTHIS->FROM_TO_DIV = MINVLOTHIS_N->FROM_TO_DIV[0];
    MEMCPY_DN(MINVLOTHIS->FROM_TO_INV_LOT_ID, MINVLOTHIS_N->FROM_TO_INV_LOT_ID, sizeof(MINVLOTHIS->FROM_TO_INV_LOT_ID));
    MINVLOTHIS->FROM_TO_HIST_SEQ = MINVLOTHIS_N->FROM_TO_HIST_SEQ;
    MINVLOTHIS->OLD_ACTIVE_HIST_SEQ = MINVLOTHIS_N->OLD_ACTIVE_HIST_SEQ;
    MEMCPY_DN(MINVLOTHIS->OLD_FACTORY, MINVLOTHIS_N->OLD_FACTORY, sizeof(MINVLOTHIS->OLD_FACTORY));
    MEMCPY_DN(MINVLOTHIS->OLD_MAT_ID, MINVLOTHIS_N->OLD_MAT_ID, sizeof(MINVLOTHIS->OLD_MAT_ID));
	MEMCPY_DN(MINVLOTHIS->OLD_AREA_ID, MINVLOTHIS_N->OLD_AREA_ID, sizeof(MINVLOTHIS->OLD_AREA_ID));
    MEMCPY_DN(MINVLOTHIS->OLD_SUB_AREA_ID, MINVLOTHIS_N->OLD_SUB_AREA_ID, sizeof(MINVLOTHIS->OLD_SUB_AREA_ID));
    MEMCPY_DN(MINVLOTHIS->OLD_OPER, MINVLOTHIS_N->OLD_OPER, sizeof(MINVLOTHIS->OLD_OPER));
    MINVLOTHIS->OLD_QTY = MINVLOTHIS_N->OLD_QTY;
    MINVLOTHIS->OLD_QTY_2 = MINVLOTHIS_N->OLD_QTY_2;
    MINVLOTHIS->OLD_QTY_3 = MINVLOTHIS_N->OLD_QTY_3;
    MEMCPY_DN(MINVLOTHIS->OLD_UNIT, MINVLOTHIS_N->OLD_UNIT, sizeof(MINVLOTHIS->OLD_UNIT));
    MEMCPY_DN(MINVLOTHIS->OLD_UNIT_2, MINVLOTHIS_N->OLD_UNIT_2, sizeof(MINVLOTHIS->OLD_UNIT_2));
    MEMCPY_DN(MINVLOTHIS->OLD_UNIT_3, MINVLOTHIS_N->OLD_UNIT_3, sizeof(MINVLOTHIS->OLD_UNIT_3));
    MINVLOTHIS->CHANGE_QTY = MINVLOTHIS_N->CHANGE_QTY;
    MINVLOTHIS->CHANGE_QTY_2 = MINVLOTHIS_N->CHANGE_QTY_2;
    MINVLOTHIS->CHANGE_QTY_3 = MINVLOTHIS_N->CHANGE_QTY_3;
    MINVLOTHIS->CREATE_QTY = MINVLOTHIS_N->CREATE_QTY;
    MINVLOTHIS->CREATE_QTY_2 = MINVLOTHIS_N->CREATE_QTY_2;
    MINVLOTHIS->CREATE_QTY_3 = MINVLOTHIS_N->CREATE_QTY_3;
    MEMCPY_DN(MINVLOTHIS->CREATE_USER_ID, MINVLOTHIS_N->CREATE_USER_ID, sizeof(MINVLOTHIS->CREATE_USER_ID));
    MEMCPY_DN(MINVLOTHIS->CREATE_TIME, MINVLOTHIS_N->CREATE_TIME, sizeof(MINVLOTHIS->CREATE_TIME));
    MEMCPY_DN(MINVLOTHIS->UPDATE_USER_ID, MINVLOTHIS_N->UPDATE_USER_ID, sizeof(MINVLOTHIS->UPDATE_USER_ID));
    MEMCPY_DN(MINVLOTHIS->UPDATE_TIME, MINVLOTHIS_N->UPDATE_TIME, sizeof(MINVLOTHIS->UPDATE_TIME));
    MINVLOTHIS->HIST_DEL_FLAG = MINVLOTHIS_N->HIST_DEL_FLAG[0];
    MEMCPY_DN(MINVLOTHIS->HIST_DEL_USER_ID, MINVLOTHIS_N->HIST_DEL_USER_ID, sizeof(MINVLOTHIS->HIST_DEL_USER_ID));
    MEMCPY_DN(MINVLOTHIS->HIST_DEL_TIME, MINVLOTHIS_N->HIST_DEL_TIME, sizeof(MINVLOTHIS->HIST_DEL_TIME));
    MEMCPY_DN(MINVLOTHIS->HIST_DEL_COMMENT, MINVLOTHIS_N->HIST_DEL_COMMENT, sizeof(MINVLOTHIS->HIST_DEL_COMMENT));
}


