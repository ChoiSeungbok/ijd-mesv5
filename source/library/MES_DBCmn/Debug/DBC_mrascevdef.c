
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
    "DBC_mrascevdef.pc"
};


static unsigned int sqlctx = 9123227;


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
            void  *sqhstv[250];
   unsigned int   sqhstl[250];
            int   sqhsts[250];
            void  *sqindv[250];
            int   sqinds[250];
   unsigned int   sqharm[250];
   unsigned int   *sqharc[250];
   unsigned short  sqadto[250];
   unsigned short  sqtdso[250];
} sqlstm = {13,250};

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
"HG_OPT_23 ,CHG_OPT_24 ,CHG_OPT_25 ,C\
HG_OPT_26 ,CHG_OPT_27 ,CHG_OPT_28 ,CHG_OPT_29 ,CHG_OPT_30 ,CREATE_USER_ID ,CR\
EATE_TIME ,UPDATE_USER_ID ,UPDATE_TIME  from MRASCEVDEF where (FACTORY=:b0 an\
d CRR_EVENT_ID>=:b1) order by CRR_EVENT_ID asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,4664,0,4,44,0,0,250,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
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
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,97,0,
0,
1020,0,0,2,4676,0,4,579,0,0,250,2,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
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
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,97,0,0,1,
97,0,0,
2035,0,0,3,83,0,4,1117,0,0,3,2,0,1,0,2,4,0,0,1,97,0,0,1,97,0,0,
2062,0,0,4,65,0,2,1152,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
2085,0,0,5,4381,0,3,1180,0,0,248,248,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
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
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
3092,0,0,6,4382,0,5,1699,0,0,248,248,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
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
97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
4099,0,0,7,3321,0,9,2230,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
4122,0,0,7,0,0,13,2258,0,0,248,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
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
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
5129,0,0,7,0,0,15,2536,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_mrascevdef.pc
**    DB Type     : Unix Oracle
**    Description : Table Access Function Source File
**    Create date : 2008/09/23 10:33:26
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
void DBC_add_null_mrascevdef(struct MRASCEVDEF_N_TAG *MRASCEVDEF_N, struct MRASCEVDEF_TAG *MRASCEVDEF);
void DBC_del_null_mrascevdef(struct MRASCEVDEF_N_TAG *MRASCEVDEF_N, struct MRASCEVDEF_TAG *MRASCEVDEF);


/* SQL SELECT Function */
void DBC_select_mrascevdef(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         CRR_EVENT_ID,
                         CRR_EVENT_DESC,
                         SYSTEM_FLAG,
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
                         UPDATE_TIME
                INTO 
                    :MRASCEVDEF_N.FACTORY,
                    :MRASCEVDEF_N.CRR_EVENT_ID,
                    :MRASCEVDEF_N.CRR_EVENT_DESC,
                    :MRASCEVDEF_N.SYSTEM_FLAG,
                    :MRASCEVDEF_N.CHK_ITEM_1,
                    :MRASCEVDEF_N.CHK_ITEM_2,
                    :MRASCEVDEF_N.CHK_ITEM_3,
                    :MRASCEVDEF_N.CHK_ITEM_4,
                    :MRASCEVDEF_N.CHK_ITEM_5,
                    :MRASCEVDEF_N.CHK_ITEM_6,
                    :MRASCEVDEF_N.CHK_ITEM_7,
                    :MRASCEVDEF_N.CHK_ITEM_8,
                    :MRASCEVDEF_N.CHK_ITEM_9,
                    :MRASCEVDEF_N.CHK_ITEM_10,
                    :MRASCEVDEF_N.CHK_ITEM_11,
                    :MRASCEVDEF_N.CHK_ITEM_12,
                    :MRASCEVDEF_N.CHK_ITEM_13,
                    :MRASCEVDEF_N.CHK_ITEM_14,
                    :MRASCEVDEF_N.CHK_ITEM_15,
                    :MRASCEVDEF_N.CHK_ITEM_16,
                    :MRASCEVDEF_N.CHK_ITEM_17,
                    :MRASCEVDEF_N.CHK_ITEM_18,
                    :MRASCEVDEF_N.CHK_ITEM_19,
                    :MRASCEVDEF_N.CHK_ITEM_20,
                    :MRASCEVDEF_N.CHK_ITEM_21,
                    :MRASCEVDEF_N.CHK_ITEM_22,
                    :MRASCEVDEF_N.CHK_ITEM_23,
                    :MRASCEVDEF_N.CHK_ITEM_24,
                    :MRASCEVDEF_N.CHK_ITEM_25,
                    :MRASCEVDEF_N.CHK_ITEM_26,
                    :MRASCEVDEF_N.CHK_ITEM_27,
                    :MRASCEVDEF_N.CHK_ITEM_28,
                    :MRASCEVDEF_N.CHK_ITEM_29,
                    :MRASCEVDEF_N.CHK_ITEM_30,
                    :MRASCEVDEF_N.CHK_FLAG_1,
                    :MRASCEVDEF_N.CHK_FLAG_2,
                    :MRASCEVDEF_N.CHK_FLAG_3,
                    :MRASCEVDEF_N.CHK_FLAG_4,
                    :MRASCEVDEF_N.CHK_FLAG_5,
                    :MRASCEVDEF_N.CHK_FLAG_6,
                    :MRASCEVDEF_N.CHK_FLAG_7,
                    :MRASCEVDEF_N.CHK_FLAG_8,
                    :MRASCEVDEF_N.CHK_FLAG_9,
                    :MRASCEVDEF_N.CHK_FLAG_10,
                    :MRASCEVDEF_N.CHK_FLAG_11,
                    :MRASCEVDEF_N.CHK_FLAG_12,
                    :MRASCEVDEF_N.CHK_FLAG_13,
                    :MRASCEVDEF_N.CHK_FLAG_14,
                    :MRASCEVDEF_N.CHK_FLAG_15,
                    :MRASCEVDEF_N.CHK_FLAG_16,
                    :MRASCEVDEF_N.CHK_FLAG_17,
                    :MRASCEVDEF_N.CHK_FLAG_18,
                    :MRASCEVDEF_N.CHK_FLAG_19,
                    :MRASCEVDEF_N.CHK_FLAG_20,
                    :MRASCEVDEF_N.CHK_FLAG_21,
                    :MRASCEVDEF_N.CHK_FLAG_22,
                    :MRASCEVDEF_N.CHK_FLAG_23,
                    :MRASCEVDEF_N.CHK_FLAG_24,
                    :MRASCEVDEF_N.CHK_FLAG_25,
                    :MRASCEVDEF_N.CHK_FLAG_26,
                    :MRASCEVDEF_N.CHK_FLAG_27,
                    :MRASCEVDEF_N.CHK_FLAG_28,
                    :MRASCEVDEF_N.CHK_FLAG_29,
                    :MRASCEVDEF_N.CHK_FLAG_30,
                    :MRASCEVDEF_N.CHK_VALUE_1,
                    :MRASCEVDEF_N.CHK_VALUE_2,
                    :MRASCEVDEF_N.CHK_VALUE_3,
                    :MRASCEVDEF_N.CHK_VALUE_4,
                    :MRASCEVDEF_N.CHK_VALUE_5,
                    :MRASCEVDEF_N.CHK_VALUE_6,
                    :MRASCEVDEF_N.CHK_VALUE_7,
                    :MRASCEVDEF_N.CHK_VALUE_8,
                    :MRASCEVDEF_N.CHK_VALUE_9,
                    :MRASCEVDEF_N.CHK_VALUE_10,
                    :MRASCEVDEF_N.CHK_VALUE_11,
                    :MRASCEVDEF_N.CHK_VALUE_12,
                    :MRASCEVDEF_N.CHK_VALUE_13,
                    :MRASCEVDEF_N.CHK_VALUE_14,
                    :MRASCEVDEF_N.CHK_VALUE_15,
                    :MRASCEVDEF_N.CHK_VALUE_16,
                    :MRASCEVDEF_N.CHK_VALUE_17,
                    :MRASCEVDEF_N.CHK_VALUE_18,
                    :MRASCEVDEF_N.CHK_VALUE_19,
                    :MRASCEVDEF_N.CHK_VALUE_20,
                    :MRASCEVDEF_N.CHK_VALUE_21,
                    :MRASCEVDEF_N.CHK_VALUE_22,
                    :MRASCEVDEF_N.CHK_VALUE_23,
                    :MRASCEVDEF_N.CHK_VALUE_24,
                    :MRASCEVDEF_N.CHK_VALUE_25,
                    :MRASCEVDEF_N.CHK_VALUE_26,
                    :MRASCEVDEF_N.CHK_VALUE_27,
                    :MRASCEVDEF_N.CHK_VALUE_28,
                    :MRASCEVDEF_N.CHK_VALUE_29,
                    :MRASCEVDEF_N.CHK_VALUE_30,
                    :MRASCEVDEF_N.CHK_FIELD_1,
                    :MRASCEVDEF_N.CHK_FIELD_2,
                    :MRASCEVDEF_N.CHK_FIELD_3,
                    :MRASCEVDEF_N.CHK_FIELD_4,
                    :MRASCEVDEF_N.CHK_FIELD_5,
                    :MRASCEVDEF_N.CHK_FIELD_6,
                    :MRASCEVDEF_N.CHK_FIELD_7,
                    :MRASCEVDEF_N.CHK_FIELD_8,
                    :MRASCEVDEF_N.CHK_FIELD_9,
                    :MRASCEVDEF_N.CHK_FIELD_10,
                    :MRASCEVDEF_N.CHK_FIELD_11,
                    :MRASCEVDEF_N.CHK_FIELD_12,
                    :MRASCEVDEF_N.CHK_FIELD_13,
                    :MRASCEVDEF_N.CHK_FIELD_14,
                    :MRASCEVDEF_N.CHK_FIELD_15,
                    :MRASCEVDEF_N.CHK_FIELD_16,
                    :MRASCEVDEF_N.CHK_FIELD_17,
                    :MRASCEVDEF_N.CHK_FIELD_18,
                    :MRASCEVDEF_N.CHK_FIELD_19,
                    :MRASCEVDEF_N.CHK_FIELD_20,
                    :MRASCEVDEF_N.CHK_FIELD_21,
                    :MRASCEVDEF_N.CHK_FIELD_22,
                    :MRASCEVDEF_N.CHK_FIELD_23,
                    :MRASCEVDEF_N.CHK_FIELD_24,
                    :MRASCEVDEF_N.CHK_FIELD_25,
                    :MRASCEVDEF_N.CHK_FIELD_26,
                    :MRASCEVDEF_N.CHK_FIELD_27,
                    :MRASCEVDEF_N.CHK_FIELD_28,
                    :MRASCEVDEF_N.CHK_FIELD_29,
                    :MRASCEVDEF_N.CHK_FIELD_30,
                    :MRASCEVDEF_N.CHG_ITEM_1,
                    :MRASCEVDEF_N.CHG_ITEM_2,
                    :MRASCEVDEF_N.CHG_ITEM_3,
                    :MRASCEVDEF_N.CHG_ITEM_4,
                    :MRASCEVDEF_N.CHG_ITEM_5,
                    :MRASCEVDEF_N.CHG_ITEM_6,
                    :MRASCEVDEF_N.CHG_ITEM_7,
                    :MRASCEVDEF_N.CHG_ITEM_8,
                    :MRASCEVDEF_N.CHG_ITEM_9,
                    :MRASCEVDEF_N.CHG_ITEM_10,
                    :MRASCEVDEF_N.CHG_ITEM_11,
                    :MRASCEVDEF_N.CHG_ITEM_12,
                    :MRASCEVDEF_N.CHG_ITEM_13,
                    :MRASCEVDEF_N.CHG_ITEM_14,
                    :MRASCEVDEF_N.CHG_ITEM_15,
                    :MRASCEVDEF_N.CHG_ITEM_16,
                    :MRASCEVDEF_N.CHG_ITEM_17,
                    :MRASCEVDEF_N.CHG_ITEM_18,
                    :MRASCEVDEF_N.CHG_ITEM_19,
                    :MRASCEVDEF_N.CHG_ITEM_20,
                    :MRASCEVDEF_N.CHG_ITEM_21,
                    :MRASCEVDEF_N.CHG_ITEM_22,
                    :MRASCEVDEF_N.CHG_ITEM_23,
                    :MRASCEVDEF_N.CHG_ITEM_24,
                    :MRASCEVDEF_N.CHG_ITEM_25,
                    :MRASCEVDEF_N.CHG_ITEM_26,
                    :MRASCEVDEF_N.CHG_ITEM_27,
                    :MRASCEVDEF_N.CHG_ITEM_28,
                    :MRASCEVDEF_N.CHG_ITEM_29,
                    :MRASCEVDEF_N.CHG_ITEM_30,
                    :MRASCEVDEF_N.CHG_FLAG_1,
                    :MRASCEVDEF_N.CHG_FLAG_2,
                    :MRASCEVDEF_N.CHG_FLAG_3,
                    :MRASCEVDEF_N.CHG_FLAG_4,
                    :MRASCEVDEF_N.CHG_FLAG_5,
                    :MRASCEVDEF_N.CHG_FLAG_6,
                    :MRASCEVDEF_N.CHG_FLAG_7,
                    :MRASCEVDEF_N.CHG_FLAG_8,
                    :MRASCEVDEF_N.CHG_FLAG_9,
                    :MRASCEVDEF_N.CHG_FLAG_10,
                    :MRASCEVDEF_N.CHG_FLAG_11,
                    :MRASCEVDEF_N.CHG_FLAG_12,
                    :MRASCEVDEF_N.CHG_FLAG_13,
                    :MRASCEVDEF_N.CHG_FLAG_14,
                    :MRASCEVDEF_N.CHG_FLAG_15,
                    :MRASCEVDEF_N.CHG_FLAG_16,
                    :MRASCEVDEF_N.CHG_FLAG_17,
                    :MRASCEVDEF_N.CHG_FLAG_18,
                    :MRASCEVDEF_N.CHG_FLAG_19,
                    :MRASCEVDEF_N.CHG_FLAG_20,
                    :MRASCEVDEF_N.CHG_FLAG_21,
                    :MRASCEVDEF_N.CHG_FLAG_22,
                    :MRASCEVDEF_N.CHG_FLAG_23,
                    :MRASCEVDEF_N.CHG_FLAG_24,
                    :MRASCEVDEF_N.CHG_FLAG_25,
                    :MRASCEVDEF_N.CHG_FLAG_26,
                    :MRASCEVDEF_N.CHG_FLAG_27,
                    :MRASCEVDEF_N.CHG_FLAG_28,
                    :MRASCEVDEF_N.CHG_FLAG_29,
                    :MRASCEVDEF_N.CHG_FLAG_30,
                    :MRASCEVDEF_N.CHG_VALUE_1,
                    :MRASCEVDEF_N.CHG_VALUE_2,
                    :MRASCEVDEF_N.CHG_VALUE_3,
                    :MRASCEVDEF_N.CHG_VALUE_4,
                    :MRASCEVDEF_N.CHG_VALUE_5,
                    :MRASCEVDEF_N.CHG_VALUE_6,
                    :MRASCEVDEF_N.CHG_VALUE_7,
                    :MRASCEVDEF_N.CHG_VALUE_8,
                    :MRASCEVDEF_N.CHG_VALUE_9,
                    :MRASCEVDEF_N.CHG_VALUE_10,
                    :MRASCEVDEF_N.CHG_VALUE_11,
                    :MRASCEVDEF_N.CHG_VALUE_12,
                    :MRASCEVDEF_N.CHG_VALUE_13,
                    :MRASCEVDEF_N.CHG_VALUE_14,
                    :MRASCEVDEF_N.CHG_VALUE_15,
                    :MRASCEVDEF_N.CHG_VALUE_16,
                    :MRASCEVDEF_N.CHG_VALUE_17,
                    :MRASCEVDEF_N.CHG_VALUE_18,
                    :MRASCEVDEF_N.CHG_VALUE_19,
                    :MRASCEVDEF_N.CHG_VALUE_20,
                    :MRASCEVDEF_N.CHG_VALUE_21,
                    :MRASCEVDEF_N.CHG_VALUE_22,
                    :MRASCEVDEF_N.CHG_VALUE_23,
                    :MRASCEVDEF_N.CHG_VALUE_24,
                    :MRASCEVDEF_N.CHG_VALUE_25,
                    :MRASCEVDEF_N.CHG_VALUE_26,
                    :MRASCEVDEF_N.CHG_VALUE_27,
                    :MRASCEVDEF_N.CHG_VALUE_28,
                    :MRASCEVDEF_N.CHG_VALUE_29,
                    :MRASCEVDEF_N.CHG_VALUE_30,
                    :MRASCEVDEF_N.CHG_OPT_1,
                    :MRASCEVDEF_N.CHG_OPT_2,
                    :MRASCEVDEF_N.CHG_OPT_3,
                    :MRASCEVDEF_N.CHG_OPT_4,
                    :MRASCEVDEF_N.CHG_OPT_5,
                    :MRASCEVDEF_N.CHG_OPT_6,
                    :MRASCEVDEF_N.CHG_OPT_7,
                    :MRASCEVDEF_N.CHG_OPT_8,
                    :MRASCEVDEF_N.CHG_OPT_9,
                    :MRASCEVDEF_N.CHG_OPT_10,
                    :MRASCEVDEF_N.CHG_OPT_11,
                    :MRASCEVDEF_N.CHG_OPT_12,
                    :MRASCEVDEF_N.CHG_OPT_13,
                    :MRASCEVDEF_N.CHG_OPT_14,
                    :MRASCEVDEF_N.CHG_OPT_15,
                    :MRASCEVDEF_N.CHG_OPT_16,
                    :MRASCEVDEF_N.CHG_OPT_17,
                    :MRASCEVDEF_N.CHG_OPT_18,
                    :MRASCEVDEF_N.CHG_OPT_19,
                    :MRASCEVDEF_N.CHG_OPT_20,
                    :MRASCEVDEF_N.CHG_OPT_21,
                    :MRASCEVDEF_N.CHG_OPT_22,
                    :MRASCEVDEF_N.CHG_OPT_23,
                    :MRASCEVDEF_N.CHG_OPT_24,
                    :MRASCEVDEF_N.CHG_OPT_25,
                    :MRASCEVDEF_N.CHG_OPT_26,
                    :MRASCEVDEF_N.CHG_OPT_27,
                    :MRASCEVDEF_N.CHG_OPT_28,
                    :MRASCEVDEF_N.CHG_OPT_29,
                    :MRASCEVDEF_N.CHG_OPT_30,
                    :MRASCEVDEF_N.CREATE_USER_ID,
                    :MRASCEVDEF_N.CREATE_TIME,
                    :MRASCEVDEF_N.UPDATE_USER_ID,
                    :MRASCEVDEF_N.UPDATE_TIME
                FROM MRASCEVDEF
                WHERE FACTORY = :MRASCEVDEF_N.FACTORY
                    AND CRR_EVENT_ID = :MRASCEVDEF_N.CRR_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,CRR_EVENT_ID ,CRR_EVENT_DESC ,SYSTEM_FLAG ,CH\
K_ITEM_1 ,CHK_ITEM_2 ,CHK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_IT\
EM_7 ,CHK_ITEM_8 ,CHK_ITEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITE\
M_13 ,CHK_ITEM_14 ,CHK_ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_I\
TEM_19 ,CHK_ITEM_20 ,CHK_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK\
_ITEM_25 ,CHK_ITEM_26 ,CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,C\
HK_FLAG_1 ,CHK_FLAG_2 ,CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_F\
LAG_7 ,CHK_FLAG_8 ,CHK_FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FL\
AG_13 ,CHK_FLAG_14 ,CHK_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_\
FLAG_19 ,CHK_FLAG_20 ,CHK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CH\
K_FLAG_25 ,CHK_FLAG_26 ,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,\
CHK_VALUE_1 ,CHK_VALUE_2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6\
 ,CHK_VALUE_7 ,CHK_VALUE_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_VAL\
UE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CH");
            sqlbuft((void **)0,
              "K_VALUE_16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VAL\
UE_20 ,CHK_VALUE_21 ,CHK_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 \
,CHK_VALUE_26 ,CHK_VALUE_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_F\
IELD_1 ,CHK_FIELD_2 ,CHK_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK\
_FIELD_7 ,CHK_FIELD_8 ,CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12\
 ,CHK_FIELD_13 ,CHK_FIELD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_\
FIELD_18 ,CHK_FIELD_19 ,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_\
23 ,CHK_FIELD_24 ,CHK_FIELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CH\
K_FIELD_29 ,CHK_FIELD_30 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CH\
G_ITEM_5 ,CHG_ITEM_6 ,CHG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_I\
TEM_11 ,CHG_ITEM_12 ,CHG_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG\
_ITEM_17 ,CHG_ITEM_18 ,CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,C\
HG_ITEM_23 ,CHG_ITEM_24 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_28 \
,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,");
            sqlbuft((void **)0,
              "CHG_FLAG_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,C\
HG_FLAG_8 ,CHG_FLAG_9 ,CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,C\
HG_FLAG_14 ,CHG_FLAG_15 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 \
,CHG_FLAG_20 ,CHG_FLAG_21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_2\
5 ,CHG_FLAG_26 ,CHG_FLAG_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALU\
E_1 ,CHG_VALUE_2 ,CHG_VALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VA\
LUE_7 ,CHG_VALUE_8 ,CHG_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,C\
HG_VALUE_13 ,CHG_VALUE_14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VAL\
UE_18 ,CHG_VALUE_19 ,CHG_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 \
,CHG_VALUE_24 ,CHG_VALUE_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_V\
ALUE_29 ,CHG_VALUE_30 ,CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5\
 ,CHG_OPT_6 ,CHG_OPT_7 ,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OP\
T_12 ,CHG_OPT_13 ,CHG_OPT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_18\
 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_21 ,CHG_OPT_22 ,C");
            sqlbuft((void **)0,
              "HG_OPT_23 ,CHG_OPT_24 ,CHG_OPT_25 ,CHG_OPT_26 ,CHG_OPT_27 ,CH\
G_OPT_28 ,CHG_OPT_29 ,CHG_OPT_30 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_I\
D ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:\
b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b4\
3,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58\
,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,\
:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:\
b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b10\
3,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b\
116,:b117,:b118,:b119,:b120,:b121,:b122,:b123,:b124,:b125,:b126,:b127,:b128,\
:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136,:b137,:b138,:b139,:b140,:b14\
1,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150,:b151,:b152,:b153,:b\
154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b162");
            sqlstm.stmt = ",:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170\
,:b171,:b172,:b173,:b174,:b175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b18\
3,:b184,:b185,:b186,:b187,:b188,:b189,:b190,:b191,:b192,:b193,:b194,:b195,:b1\
96,:b197,:b198,:b199,:b200,:b201,:b202,:b203,:b204,:b205,:b206,:b207,:b208,:b\
209,:b210,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b218,:b219,:b220,:b221,:\
b222,:b223,:b224,:b225,:b226,:b227,:b228,:b229,:b230,:b231,:b232,:b233,:b234,\
:b235,:b236,:b237,:b238,:b239,:b240,:b241,:b242,:b243,:b244,:b245,:b246,:b247\
  from MRASCEVDEF where (FACTORY=:b0 and CRR_EVENT_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASCEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[154] = (unsigned int  )2;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[155] = (unsigned int  )2;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[184] = (unsigned int  )31;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[186] = (unsigned int  )31;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASCEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASCEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[215] = (unsigned int  )2;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASCEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[216] = (unsigned int  )2;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASCEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASCEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASCEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASCEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASCEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASCEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASCEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASCEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASCEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASCEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASCEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASCEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASCEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASCEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASCEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASCEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASCEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASCEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASCEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASCEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASCEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASCEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASCEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASCEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASCEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASCEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASCEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASCEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[244] = (unsigned int  )21;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASCEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[245] = (unsigned int  )15;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASCEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[246] = (unsigned int  )21;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASCEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[247] = (unsigned int  )15;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[248] = (unsigned int  )11;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[249] = (unsigned int  )13;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
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
        DBC_del_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    }
    DB_stop_query_timer("DBC_select_mrascevdef", sel_type);
}


/* SQL SELECT_FOR_UPDATE Function */
void DBC_select_mrascevdef_for_update(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT 
                         FACTORY,
                         CRR_EVENT_ID,
                         CRR_EVENT_DESC,
                         SYSTEM_FLAG,
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
                         UPDATE_TIME
                INTO 
                    :MRASCEVDEF_N.FACTORY,
                    :MRASCEVDEF_N.CRR_EVENT_ID,
                    :MRASCEVDEF_N.CRR_EVENT_DESC,
                    :MRASCEVDEF_N.SYSTEM_FLAG,
                    :MRASCEVDEF_N.CHK_ITEM_1,
                    :MRASCEVDEF_N.CHK_ITEM_2,
                    :MRASCEVDEF_N.CHK_ITEM_3,
                    :MRASCEVDEF_N.CHK_ITEM_4,
                    :MRASCEVDEF_N.CHK_ITEM_5,
                    :MRASCEVDEF_N.CHK_ITEM_6,
                    :MRASCEVDEF_N.CHK_ITEM_7,
                    :MRASCEVDEF_N.CHK_ITEM_8,
                    :MRASCEVDEF_N.CHK_ITEM_9,
                    :MRASCEVDEF_N.CHK_ITEM_10,
                    :MRASCEVDEF_N.CHK_ITEM_11,
                    :MRASCEVDEF_N.CHK_ITEM_12,
                    :MRASCEVDEF_N.CHK_ITEM_13,
                    :MRASCEVDEF_N.CHK_ITEM_14,
                    :MRASCEVDEF_N.CHK_ITEM_15,
                    :MRASCEVDEF_N.CHK_ITEM_16,
                    :MRASCEVDEF_N.CHK_ITEM_17,
                    :MRASCEVDEF_N.CHK_ITEM_18,
                    :MRASCEVDEF_N.CHK_ITEM_19,
                    :MRASCEVDEF_N.CHK_ITEM_20,
                    :MRASCEVDEF_N.CHK_ITEM_21,
                    :MRASCEVDEF_N.CHK_ITEM_22,
                    :MRASCEVDEF_N.CHK_ITEM_23,
                    :MRASCEVDEF_N.CHK_ITEM_24,
                    :MRASCEVDEF_N.CHK_ITEM_25,
                    :MRASCEVDEF_N.CHK_ITEM_26,
                    :MRASCEVDEF_N.CHK_ITEM_27,
                    :MRASCEVDEF_N.CHK_ITEM_28,
                    :MRASCEVDEF_N.CHK_ITEM_29,
                    :MRASCEVDEF_N.CHK_ITEM_30,
                    :MRASCEVDEF_N.CHK_FLAG_1,
                    :MRASCEVDEF_N.CHK_FLAG_2,
                    :MRASCEVDEF_N.CHK_FLAG_3,
                    :MRASCEVDEF_N.CHK_FLAG_4,
                    :MRASCEVDEF_N.CHK_FLAG_5,
                    :MRASCEVDEF_N.CHK_FLAG_6,
                    :MRASCEVDEF_N.CHK_FLAG_7,
                    :MRASCEVDEF_N.CHK_FLAG_8,
                    :MRASCEVDEF_N.CHK_FLAG_9,
                    :MRASCEVDEF_N.CHK_FLAG_10,
                    :MRASCEVDEF_N.CHK_FLAG_11,
                    :MRASCEVDEF_N.CHK_FLAG_12,
                    :MRASCEVDEF_N.CHK_FLAG_13,
                    :MRASCEVDEF_N.CHK_FLAG_14,
                    :MRASCEVDEF_N.CHK_FLAG_15,
                    :MRASCEVDEF_N.CHK_FLAG_16,
                    :MRASCEVDEF_N.CHK_FLAG_17,
                    :MRASCEVDEF_N.CHK_FLAG_18,
                    :MRASCEVDEF_N.CHK_FLAG_19,
                    :MRASCEVDEF_N.CHK_FLAG_20,
                    :MRASCEVDEF_N.CHK_FLAG_21,
                    :MRASCEVDEF_N.CHK_FLAG_22,
                    :MRASCEVDEF_N.CHK_FLAG_23,
                    :MRASCEVDEF_N.CHK_FLAG_24,
                    :MRASCEVDEF_N.CHK_FLAG_25,
                    :MRASCEVDEF_N.CHK_FLAG_26,
                    :MRASCEVDEF_N.CHK_FLAG_27,
                    :MRASCEVDEF_N.CHK_FLAG_28,
                    :MRASCEVDEF_N.CHK_FLAG_29,
                    :MRASCEVDEF_N.CHK_FLAG_30,
                    :MRASCEVDEF_N.CHK_VALUE_1,
                    :MRASCEVDEF_N.CHK_VALUE_2,
                    :MRASCEVDEF_N.CHK_VALUE_3,
                    :MRASCEVDEF_N.CHK_VALUE_4,
                    :MRASCEVDEF_N.CHK_VALUE_5,
                    :MRASCEVDEF_N.CHK_VALUE_6,
                    :MRASCEVDEF_N.CHK_VALUE_7,
                    :MRASCEVDEF_N.CHK_VALUE_8,
                    :MRASCEVDEF_N.CHK_VALUE_9,
                    :MRASCEVDEF_N.CHK_VALUE_10,
                    :MRASCEVDEF_N.CHK_VALUE_11,
                    :MRASCEVDEF_N.CHK_VALUE_12,
                    :MRASCEVDEF_N.CHK_VALUE_13,
                    :MRASCEVDEF_N.CHK_VALUE_14,
                    :MRASCEVDEF_N.CHK_VALUE_15,
                    :MRASCEVDEF_N.CHK_VALUE_16,
                    :MRASCEVDEF_N.CHK_VALUE_17,
                    :MRASCEVDEF_N.CHK_VALUE_18,
                    :MRASCEVDEF_N.CHK_VALUE_19,
                    :MRASCEVDEF_N.CHK_VALUE_20,
                    :MRASCEVDEF_N.CHK_VALUE_21,
                    :MRASCEVDEF_N.CHK_VALUE_22,
                    :MRASCEVDEF_N.CHK_VALUE_23,
                    :MRASCEVDEF_N.CHK_VALUE_24,
                    :MRASCEVDEF_N.CHK_VALUE_25,
                    :MRASCEVDEF_N.CHK_VALUE_26,
                    :MRASCEVDEF_N.CHK_VALUE_27,
                    :MRASCEVDEF_N.CHK_VALUE_28,
                    :MRASCEVDEF_N.CHK_VALUE_29,
                    :MRASCEVDEF_N.CHK_VALUE_30,
                    :MRASCEVDEF_N.CHK_FIELD_1,
                    :MRASCEVDEF_N.CHK_FIELD_2,
                    :MRASCEVDEF_N.CHK_FIELD_3,
                    :MRASCEVDEF_N.CHK_FIELD_4,
                    :MRASCEVDEF_N.CHK_FIELD_5,
                    :MRASCEVDEF_N.CHK_FIELD_6,
                    :MRASCEVDEF_N.CHK_FIELD_7,
                    :MRASCEVDEF_N.CHK_FIELD_8,
                    :MRASCEVDEF_N.CHK_FIELD_9,
                    :MRASCEVDEF_N.CHK_FIELD_10,
                    :MRASCEVDEF_N.CHK_FIELD_11,
                    :MRASCEVDEF_N.CHK_FIELD_12,
                    :MRASCEVDEF_N.CHK_FIELD_13,
                    :MRASCEVDEF_N.CHK_FIELD_14,
                    :MRASCEVDEF_N.CHK_FIELD_15,
                    :MRASCEVDEF_N.CHK_FIELD_16,
                    :MRASCEVDEF_N.CHK_FIELD_17,
                    :MRASCEVDEF_N.CHK_FIELD_18,
                    :MRASCEVDEF_N.CHK_FIELD_19,
                    :MRASCEVDEF_N.CHK_FIELD_20,
                    :MRASCEVDEF_N.CHK_FIELD_21,
                    :MRASCEVDEF_N.CHK_FIELD_22,
                    :MRASCEVDEF_N.CHK_FIELD_23,
                    :MRASCEVDEF_N.CHK_FIELD_24,
                    :MRASCEVDEF_N.CHK_FIELD_25,
                    :MRASCEVDEF_N.CHK_FIELD_26,
                    :MRASCEVDEF_N.CHK_FIELD_27,
                    :MRASCEVDEF_N.CHK_FIELD_28,
                    :MRASCEVDEF_N.CHK_FIELD_29,
                    :MRASCEVDEF_N.CHK_FIELD_30,
                    :MRASCEVDEF_N.CHG_ITEM_1,
                    :MRASCEVDEF_N.CHG_ITEM_2,
                    :MRASCEVDEF_N.CHG_ITEM_3,
                    :MRASCEVDEF_N.CHG_ITEM_4,
                    :MRASCEVDEF_N.CHG_ITEM_5,
                    :MRASCEVDEF_N.CHG_ITEM_6,
                    :MRASCEVDEF_N.CHG_ITEM_7,
                    :MRASCEVDEF_N.CHG_ITEM_8,
                    :MRASCEVDEF_N.CHG_ITEM_9,
                    :MRASCEVDEF_N.CHG_ITEM_10,
                    :MRASCEVDEF_N.CHG_ITEM_11,
                    :MRASCEVDEF_N.CHG_ITEM_12,
                    :MRASCEVDEF_N.CHG_ITEM_13,
                    :MRASCEVDEF_N.CHG_ITEM_14,
                    :MRASCEVDEF_N.CHG_ITEM_15,
                    :MRASCEVDEF_N.CHG_ITEM_16,
                    :MRASCEVDEF_N.CHG_ITEM_17,
                    :MRASCEVDEF_N.CHG_ITEM_18,
                    :MRASCEVDEF_N.CHG_ITEM_19,
                    :MRASCEVDEF_N.CHG_ITEM_20,
                    :MRASCEVDEF_N.CHG_ITEM_21,
                    :MRASCEVDEF_N.CHG_ITEM_22,
                    :MRASCEVDEF_N.CHG_ITEM_23,
                    :MRASCEVDEF_N.CHG_ITEM_24,
                    :MRASCEVDEF_N.CHG_ITEM_25,
                    :MRASCEVDEF_N.CHG_ITEM_26,
                    :MRASCEVDEF_N.CHG_ITEM_27,
                    :MRASCEVDEF_N.CHG_ITEM_28,
                    :MRASCEVDEF_N.CHG_ITEM_29,
                    :MRASCEVDEF_N.CHG_ITEM_30,
                    :MRASCEVDEF_N.CHG_FLAG_1,
                    :MRASCEVDEF_N.CHG_FLAG_2,
                    :MRASCEVDEF_N.CHG_FLAG_3,
                    :MRASCEVDEF_N.CHG_FLAG_4,
                    :MRASCEVDEF_N.CHG_FLAG_5,
                    :MRASCEVDEF_N.CHG_FLAG_6,
                    :MRASCEVDEF_N.CHG_FLAG_7,
                    :MRASCEVDEF_N.CHG_FLAG_8,
                    :MRASCEVDEF_N.CHG_FLAG_9,
                    :MRASCEVDEF_N.CHG_FLAG_10,
                    :MRASCEVDEF_N.CHG_FLAG_11,
                    :MRASCEVDEF_N.CHG_FLAG_12,
                    :MRASCEVDEF_N.CHG_FLAG_13,
                    :MRASCEVDEF_N.CHG_FLAG_14,
                    :MRASCEVDEF_N.CHG_FLAG_15,
                    :MRASCEVDEF_N.CHG_FLAG_16,
                    :MRASCEVDEF_N.CHG_FLAG_17,
                    :MRASCEVDEF_N.CHG_FLAG_18,
                    :MRASCEVDEF_N.CHG_FLAG_19,
                    :MRASCEVDEF_N.CHG_FLAG_20,
                    :MRASCEVDEF_N.CHG_FLAG_21,
                    :MRASCEVDEF_N.CHG_FLAG_22,
                    :MRASCEVDEF_N.CHG_FLAG_23,
                    :MRASCEVDEF_N.CHG_FLAG_24,
                    :MRASCEVDEF_N.CHG_FLAG_25,
                    :MRASCEVDEF_N.CHG_FLAG_26,
                    :MRASCEVDEF_N.CHG_FLAG_27,
                    :MRASCEVDEF_N.CHG_FLAG_28,
                    :MRASCEVDEF_N.CHG_FLAG_29,
                    :MRASCEVDEF_N.CHG_FLAG_30,
                    :MRASCEVDEF_N.CHG_VALUE_1,
                    :MRASCEVDEF_N.CHG_VALUE_2,
                    :MRASCEVDEF_N.CHG_VALUE_3,
                    :MRASCEVDEF_N.CHG_VALUE_4,
                    :MRASCEVDEF_N.CHG_VALUE_5,
                    :MRASCEVDEF_N.CHG_VALUE_6,
                    :MRASCEVDEF_N.CHG_VALUE_7,
                    :MRASCEVDEF_N.CHG_VALUE_8,
                    :MRASCEVDEF_N.CHG_VALUE_9,
                    :MRASCEVDEF_N.CHG_VALUE_10,
                    :MRASCEVDEF_N.CHG_VALUE_11,
                    :MRASCEVDEF_N.CHG_VALUE_12,
                    :MRASCEVDEF_N.CHG_VALUE_13,
                    :MRASCEVDEF_N.CHG_VALUE_14,
                    :MRASCEVDEF_N.CHG_VALUE_15,
                    :MRASCEVDEF_N.CHG_VALUE_16,
                    :MRASCEVDEF_N.CHG_VALUE_17,
                    :MRASCEVDEF_N.CHG_VALUE_18,
                    :MRASCEVDEF_N.CHG_VALUE_19,
                    :MRASCEVDEF_N.CHG_VALUE_20,
                    :MRASCEVDEF_N.CHG_VALUE_21,
                    :MRASCEVDEF_N.CHG_VALUE_22,
                    :MRASCEVDEF_N.CHG_VALUE_23,
                    :MRASCEVDEF_N.CHG_VALUE_24,
                    :MRASCEVDEF_N.CHG_VALUE_25,
                    :MRASCEVDEF_N.CHG_VALUE_26,
                    :MRASCEVDEF_N.CHG_VALUE_27,
                    :MRASCEVDEF_N.CHG_VALUE_28,
                    :MRASCEVDEF_N.CHG_VALUE_29,
                    :MRASCEVDEF_N.CHG_VALUE_30,
                    :MRASCEVDEF_N.CHG_OPT_1,
                    :MRASCEVDEF_N.CHG_OPT_2,
                    :MRASCEVDEF_N.CHG_OPT_3,
                    :MRASCEVDEF_N.CHG_OPT_4,
                    :MRASCEVDEF_N.CHG_OPT_5,
                    :MRASCEVDEF_N.CHG_OPT_6,
                    :MRASCEVDEF_N.CHG_OPT_7,
                    :MRASCEVDEF_N.CHG_OPT_8,
                    :MRASCEVDEF_N.CHG_OPT_9,
                    :MRASCEVDEF_N.CHG_OPT_10,
                    :MRASCEVDEF_N.CHG_OPT_11,
                    :MRASCEVDEF_N.CHG_OPT_12,
                    :MRASCEVDEF_N.CHG_OPT_13,
                    :MRASCEVDEF_N.CHG_OPT_14,
                    :MRASCEVDEF_N.CHG_OPT_15,
                    :MRASCEVDEF_N.CHG_OPT_16,
                    :MRASCEVDEF_N.CHG_OPT_17,
                    :MRASCEVDEF_N.CHG_OPT_18,
                    :MRASCEVDEF_N.CHG_OPT_19,
                    :MRASCEVDEF_N.CHG_OPT_20,
                    :MRASCEVDEF_N.CHG_OPT_21,
                    :MRASCEVDEF_N.CHG_OPT_22,
                    :MRASCEVDEF_N.CHG_OPT_23,
                    :MRASCEVDEF_N.CHG_OPT_24,
                    :MRASCEVDEF_N.CHG_OPT_25,
                    :MRASCEVDEF_N.CHG_OPT_26,
                    :MRASCEVDEF_N.CHG_OPT_27,
                    :MRASCEVDEF_N.CHG_OPT_28,
                    :MRASCEVDEF_N.CHG_OPT_29,
                    :MRASCEVDEF_N.CHG_OPT_30,
                    :MRASCEVDEF_N.CREATE_USER_ID,
                    :MRASCEVDEF_N.CREATE_TIME,
                    :MRASCEVDEF_N.UPDATE_USER_ID,
                    :MRASCEVDEF_N.UPDATE_TIME
                FROM MRASCEVDEF
                WHERE FACTORY = :MRASCEVDEF_N.FACTORY
                    AND CRR_EVENT_ID = :MRASCEVDEF_N.CRR_EVENT_ID
                FOR UPDATE; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,CRR_EVENT_ID ,CRR_EVENT_DESC ,SYSTEM_FLAG ,CH\
K_ITEM_1 ,CHK_ITEM_2 ,CHK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_IT\
EM_7 ,CHK_ITEM_8 ,CHK_ITEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITE\
M_13 ,CHK_ITEM_14 ,CHK_ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_I\
TEM_19 ,CHK_ITEM_20 ,CHK_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK\
_ITEM_25 ,CHK_ITEM_26 ,CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,C\
HK_FLAG_1 ,CHK_FLAG_2 ,CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_F\
LAG_7 ,CHK_FLAG_8 ,CHK_FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FL\
AG_13 ,CHK_FLAG_14 ,CHK_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_\
FLAG_19 ,CHK_FLAG_20 ,CHK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CH\
K_FLAG_25 ,CHK_FLAG_26 ,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,\
CHK_VALUE_1 ,CHK_VALUE_2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6\
 ,CHK_VALUE_7 ,CHK_VALUE_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_VAL\
UE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CH");
            sqlbuft((void **)0,
              "K_VALUE_16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VAL\
UE_20 ,CHK_VALUE_21 ,CHK_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 \
,CHK_VALUE_26 ,CHK_VALUE_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_F\
IELD_1 ,CHK_FIELD_2 ,CHK_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK\
_FIELD_7 ,CHK_FIELD_8 ,CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12\
 ,CHK_FIELD_13 ,CHK_FIELD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_\
FIELD_18 ,CHK_FIELD_19 ,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_\
23 ,CHK_FIELD_24 ,CHK_FIELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CH\
K_FIELD_29 ,CHK_FIELD_30 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CH\
G_ITEM_5 ,CHG_ITEM_6 ,CHG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_I\
TEM_11 ,CHG_ITEM_12 ,CHG_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG\
_ITEM_17 ,CHG_ITEM_18 ,CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,C\
HG_ITEM_23 ,CHG_ITEM_24 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_28 \
,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,");
            sqlbuft((void **)0,
              "CHG_FLAG_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,C\
HG_FLAG_8 ,CHG_FLAG_9 ,CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,C\
HG_FLAG_14 ,CHG_FLAG_15 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 \
,CHG_FLAG_20 ,CHG_FLAG_21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_2\
5 ,CHG_FLAG_26 ,CHG_FLAG_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALU\
E_1 ,CHG_VALUE_2 ,CHG_VALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VA\
LUE_7 ,CHG_VALUE_8 ,CHG_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,C\
HG_VALUE_13 ,CHG_VALUE_14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VAL\
UE_18 ,CHG_VALUE_19 ,CHG_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 \
,CHG_VALUE_24 ,CHG_VALUE_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_V\
ALUE_29 ,CHG_VALUE_30 ,CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5\
 ,CHG_OPT_6 ,CHG_OPT_7 ,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OP\
T_12 ,CHG_OPT_13 ,CHG_OPT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_18\
 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_21 ,CHG_OPT_22 ,C");
            sqlbuft((void **)0,
              "HG_OPT_23 ,CHG_OPT_24 ,CHG_OPT_25 ,CHG_OPT_26 ,CHG_OPT_27 ,CH\
G_OPT_28 ,CHG_OPT_29 ,CHG_OPT_30 ,CREATE_USER_ID ,CREATE_TIME ,UPDATE_USER_I\
D ,UPDATE_TIME into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:\
b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b\
28,:b29,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b4\
3,:b44,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58\
,:b59,:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,\
:b74,:b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:\
b89,:b90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b10\
3,:b104,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b\
116,:b117,:b118,:b119,:b120,:b121,:b122,:b123,:b124,:b125,:b126,:b127,:b128,\
:b129,:b130,:b131,:b132,:b133,:b134,:b135,:b136,:b137,:b138,:b139,:b140,:b14\
1,:b142,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150,:b151,:b152,:b153,:b\
154,:b155,:b156,:b157,:b158,:b159,:b160,:b161,:b162");
            sqlstm.stmt = ",:b163,:b164,:b165,:b166,:b167,:b168,:b169,:b170\
,:b171,:b172,:b173,:b174,:b175,:b176,:b177,:b178,:b179,:b180,:b181,:b182,:b18\
3,:b184,:b185,:b186,:b187,:b188,:b189,:b190,:b191,:b192,:b193,:b194,:b195,:b1\
96,:b197,:b198,:b199,:b200,:b201,:b202,:b203,:b204,:b205,:b206,:b207,:b208,:b\
209,:b210,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b218,:b219,:b220,:b221,:\
b222,:b223,:b224,:b225,:b226,:b227,:b228,:b229,:b230,:b231,:b232,:b233,:b234,\
:b235,:b236,:b237,:b238,:b239,:b240,:b241,:b242,:b243,:b244,:b245,:b246,:b247\
  from MRASCEVDEF where (FACTORY=:b0 and CRR_EVENT_ID=:b1) for update ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1020;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASCEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[154] = (unsigned int  )2;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[155] = (unsigned int  )2;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[184] = (unsigned int  )31;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[186] = (unsigned int  )31;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASCEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASCEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[215] = (unsigned int  )2;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASCEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[216] = (unsigned int  )2;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASCEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASCEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASCEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASCEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASCEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASCEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASCEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASCEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASCEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASCEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASCEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASCEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASCEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASCEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASCEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASCEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASCEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASCEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASCEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASCEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASCEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASCEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASCEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASCEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASCEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASCEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASCEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASCEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[244] = (unsigned int  )21;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASCEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[245] = (unsigned int  )15;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASCEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[246] = (unsigned int  )21;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASCEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[247] = (unsigned int  )15;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
            sqlstm.sqhstv[248] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[248] = (unsigned int  )11;
            sqlstm.sqhsts[248] = (         int  )0;
            sqlstm.sqindv[248] = (         void  *)0;
            sqlstm.sqinds[248] = (         int  )0;
            sqlstm.sqharm[248] = (unsigned int  )0;
            sqlstm.sqadto[248] = (unsigned short )0;
            sqlstm.sqtdso[248] = (unsigned short )0;
            sqlstm.sqhstv[249] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[249] = (unsigned int  )13;
            sqlstm.sqhsts[249] = (         int  )0;
            sqlstm.sqindv[249] = (         void  *)0;
            sqlstm.sqinds[249] = (         int  )0;
            sqlstm.sqharm[249] = (unsigned int  )0;
            sqlstm.sqadto[249] = (unsigned short )0;
            sqlstm.sqtdso[249] = (unsigned short )0;
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
        DBC_del_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    }
    DB_stop_query_timer("DBC_select_mrascevdef_for_update", sel_type);
}


/* SQL SELECT_SCALAR Function */
double DBC_select_mrascevdef_scalar(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
        double d_value;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;
    d_value = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL SELECT count(*) 
                INTO :d_value
                FROM MRASCEVDEF
                WHERE FACTORY = :MRASCEVDEF_N.FACTORY
                    AND CRR_EVENT_ID = :MRASCEVDEF_N.CRR_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select count(*)  into :b0  from MRASCEVDEF where\
 (FACTORY=:b1 and CRR_EVENT_ID=:b2)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2035;
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
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
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

    DB_stop_query_timer("DBC_select_mrascevdef_scalar", sel_type);
    return d_value;
}


/* SQL DELETE Function */
void DBC_delete_mrascevdef(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DELETE FROM MRASCEVDEF
                WHERE FACTORY = :MRASCEVDEF_N.FACTORY
                    AND CRR_EVENT_ID = :MRASCEVDEF_N.CRR_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "delete  from MRASCEVDEF  where (FACTORY=:b0 and \
CRR_EVENT_ID=:b1)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2062;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )13;
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
    DB_stop_query_timer("DBC_delete_mrascevdef", sel_type);
}


/* SQL INSERT Function */
void DBC_insert_mrascevdef(struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;

    /* EXEC SQL INSERT INTO MRASCEVDEF (
                    FACTORY,
                    CRR_EVENT_ID,
                    CRR_EVENT_DESC,
                    SYSTEM_FLAG,
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
                    UPDATE_TIME
        )
        VALUES (
                    :MRASCEVDEF_N.FACTORY,
                    :MRASCEVDEF_N.CRR_EVENT_ID,
                    :MRASCEVDEF_N.CRR_EVENT_DESC,
                    :MRASCEVDEF_N.SYSTEM_FLAG,
                    :MRASCEVDEF_N.CHK_ITEM_1,
                    :MRASCEVDEF_N.CHK_ITEM_2,
                    :MRASCEVDEF_N.CHK_ITEM_3,
                    :MRASCEVDEF_N.CHK_ITEM_4,
                    :MRASCEVDEF_N.CHK_ITEM_5,
                    :MRASCEVDEF_N.CHK_ITEM_6,
                    :MRASCEVDEF_N.CHK_ITEM_7,
                    :MRASCEVDEF_N.CHK_ITEM_8,
                    :MRASCEVDEF_N.CHK_ITEM_9,
                    :MRASCEVDEF_N.CHK_ITEM_10,
                    :MRASCEVDEF_N.CHK_ITEM_11,
                    :MRASCEVDEF_N.CHK_ITEM_12,
                    :MRASCEVDEF_N.CHK_ITEM_13,
                    :MRASCEVDEF_N.CHK_ITEM_14,
                    :MRASCEVDEF_N.CHK_ITEM_15,
                    :MRASCEVDEF_N.CHK_ITEM_16,
                    :MRASCEVDEF_N.CHK_ITEM_17,
                    :MRASCEVDEF_N.CHK_ITEM_18,
                    :MRASCEVDEF_N.CHK_ITEM_19,
                    :MRASCEVDEF_N.CHK_ITEM_20,
                    :MRASCEVDEF_N.CHK_ITEM_21,
                    :MRASCEVDEF_N.CHK_ITEM_22,
                    :MRASCEVDEF_N.CHK_ITEM_23,
                    :MRASCEVDEF_N.CHK_ITEM_24,
                    :MRASCEVDEF_N.CHK_ITEM_25,
                    :MRASCEVDEF_N.CHK_ITEM_26,
                    :MRASCEVDEF_N.CHK_ITEM_27,
                    :MRASCEVDEF_N.CHK_ITEM_28,
                    :MRASCEVDEF_N.CHK_ITEM_29,
                    :MRASCEVDEF_N.CHK_ITEM_30,
                    :MRASCEVDEF_N.CHK_FLAG_1,
                    :MRASCEVDEF_N.CHK_FLAG_2,
                    :MRASCEVDEF_N.CHK_FLAG_3,
                    :MRASCEVDEF_N.CHK_FLAG_4,
                    :MRASCEVDEF_N.CHK_FLAG_5,
                    :MRASCEVDEF_N.CHK_FLAG_6,
                    :MRASCEVDEF_N.CHK_FLAG_7,
                    :MRASCEVDEF_N.CHK_FLAG_8,
                    :MRASCEVDEF_N.CHK_FLAG_9,
                    :MRASCEVDEF_N.CHK_FLAG_10,
                    :MRASCEVDEF_N.CHK_FLAG_11,
                    :MRASCEVDEF_N.CHK_FLAG_12,
                    :MRASCEVDEF_N.CHK_FLAG_13,
                    :MRASCEVDEF_N.CHK_FLAG_14,
                    :MRASCEVDEF_N.CHK_FLAG_15,
                    :MRASCEVDEF_N.CHK_FLAG_16,
                    :MRASCEVDEF_N.CHK_FLAG_17,
                    :MRASCEVDEF_N.CHK_FLAG_18,
                    :MRASCEVDEF_N.CHK_FLAG_19,
                    :MRASCEVDEF_N.CHK_FLAG_20,
                    :MRASCEVDEF_N.CHK_FLAG_21,
                    :MRASCEVDEF_N.CHK_FLAG_22,
                    :MRASCEVDEF_N.CHK_FLAG_23,
                    :MRASCEVDEF_N.CHK_FLAG_24,
                    :MRASCEVDEF_N.CHK_FLAG_25,
                    :MRASCEVDEF_N.CHK_FLAG_26,
                    :MRASCEVDEF_N.CHK_FLAG_27,
                    :MRASCEVDEF_N.CHK_FLAG_28,
                    :MRASCEVDEF_N.CHK_FLAG_29,
                    :MRASCEVDEF_N.CHK_FLAG_30,
                    :MRASCEVDEF_N.CHK_VALUE_1,
                    :MRASCEVDEF_N.CHK_VALUE_2,
                    :MRASCEVDEF_N.CHK_VALUE_3,
                    :MRASCEVDEF_N.CHK_VALUE_4,
                    :MRASCEVDEF_N.CHK_VALUE_5,
                    :MRASCEVDEF_N.CHK_VALUE_6,
                    :MRASCEVDEF_N.CHK_VALUE_7,
                    :MRASCEVDEF_N.CHK_VALUE_8,
                    :MRASCEVDEF_N.CHK_VALUE_9,
                    :MRASCEVDEF_N.CHK_VALUE_10,
                    :MRASCEVDEF_N.CHK_VALUE_11,
                    :MRASCEVDEF_N.CHK_VALUE_12,
                    :MRASCEVDEF_N.CHK_VALUE_13,
                    :MRASCEVDEF_N.CHK_VALUE_14,
                    :MRASCEVDEF_N.CHK_VALUE_15,
                    :MRASCEVDEF_N.CHK_VALUE_16,
                    :MRASCEVDEF_N.CHK_VALUE_17,
                    :MRASCEVDEF_N.CHK_VALUE_18,
                    :MRASCEVDEF_N.CHK_VALUE_19,
                    :MRASCEVDEF_N.CHK_VALUE_20,
                    :MRASCEVDEF_N.CHK_VALUE_21,
                    :MRASCEVDEF_N.CHK_VALUE_22,
                    :MRASCEVDEF_N.CHK_VALUE_23,
                    :MRASCEVDEF_N.CHK_VALUE_24,
                    :MRASCEVDEF_N.CHK_VALUE_25,
                    :MRASCEVDEF_N.CHK_VALUE_26,
                    :MRASCEVDEF_N.CHK_VALUE_27,
                    :MRASCEVDEF_N.CHK_VALUE_28,
                    :MRASCEVDEF_N.CHK_VALUE_29,
                    :MRASCEVDEF_N.CHK_VALUE_30,
                    :MRASCEVDEF_N.CHK_FIELD_1,
                    :MRASCEVDEF_N.CHK_FIELD_2,
                    :MRASCEVDEF_N.CHK_FIELD_3,
                    :MRASCEVDEF_N.CHK_FIELD_4,
                    :MRASCEVDEF_N.CHK_FIELD_5,
                    :MRASCEVDEF_N.CHK_FIELD_6,
                    :MRASCEVDEF_N.CHK_FIELD_7,
                    :MRASCEVDEF_N.CHK_FIELD_8,
                    :MRASCEVDEF_N.CHK_FIELD_9,
                    :MRASCEVDEF_N.CHK_FIELD_10,
                    :MRASCEVDEF_N.CHK_FIELD_11,
                    :MRASCEVDEF_N.CHK_FIELD_12,
                    :MRASCEVDEF_N.CHK_FIELD_13,
                    :MRASCEVDEF_N.CHK_FIELD_14,
                    :MRASCEVDEF_N.CHK_FIELD_15,
                    :MRASCEVDEF_N.CHK_FIELD_16,
                    :MRASCEVDEF_N.CHK_FIELD_17,
                    :MRASCEVDEF_N.CHK_FIELD_18,
                    :MRASCEVDEF_N.CHK_FIELD_19,
                    :MRASCEVDEF_N.CHK_FIELD_20,
                    :MRASCEVDEF_N.CHK_FIELD_21,
                    :MRASCEVDEF_N.CHK_FIELD_22,
                    :MRASCEVDEF_N.CHK_FIELD_23,
                    :MRASCEVDEF_N.CHK_FIELD_24,
                    :MRASCEVDEF_N.CHK_FIELD_25,
                    :MRASCEVDEF_N.CHK_FIELD_26,
                    :MRASCEVDEF_N.CHK_FIELD_27,
                    :MRASCEVDEF_N.CHK_FIELD_28,
                    :MRASCEVDEF_N.CHK_FIELD_29,
                    :MRASCEVDEF_N.CHK_FIELD_30,
                    :MRASCEVDEF_N.CHG_ITEM_1,
                    :MRASCEVDEF_N.CHG_ITEM_2,
                    :MRASCEVDEF_N.CHG_ITEM_3,
                    :MRASCEVDEF_N.CHG_ITEM_4,
                    :MRASCEVDEF_N.CHG_ITEM_5,
                    :MRASCEVDEF_N.CHG_ITEM_6,
                    :MRASCEVDEF_N.CHG_ITEM_7,
                    :MRASCEVDEF_N.CHG_ITEM_8,
                    :MRASCEVDEF_N.CHG_ITEM_9,
                    :MRASCEVDEF_N.CHG_ITEM_10,
                    :MRASCEVDEF_N.CHG_ITEM_11,
                    :MRASCEVDEF_N.CHG_ITEM_12,
                    :MRASCEVDEF_N.CHG_ITEM_13,
                    :MRASCEVDEF_N.CHG_ITEM_14,
                    :MRASCEVDEF_N.CHG_ITEM_15,
                    :MRASCEVDEF_N.CHG_ITEM_16,
                    :MRASCEVDEF_N.CHG_ITEM_17,
                    :MRASCEVDEF_N.CHG_ITEM_18,
                    :MRASCEVDEF_N.CHG_ITEM_19,
                    :MRASCEVDEF_N.CHG_ITEM_20,
                    :MRASCEVDEF_N.CHG_ITEM_21,
                    :MRASCEVDEF_N.CHG_ITEM_22,
                    :MRASCEVDEF_N.CHG_ITEM_23,
                    :MRASCEVDEF_N.CHG_ITEM_24,
                    :MRASCEVDEF_N.CHG_ITEM_25,
                    :MRASCEVDEF_N.CHG_ITEM_26,
                    :MRASCEVDEF_N.CHG_ITEM_27,
                    :MRASCEVDEF_N.CHG_ITEM_28,
                    :MRASCEVDEF_N.CHG_ITEM_29,
                    :MRASCEVDEF_N.CHG_ITEM_30,
                    :MRASCEVDEF_N.CHG_FLAG_1,
                    :MRASCEVDEF_N.CHG_FLAG_2,
                    :MRASCEVDEF_N.CHG_FLAG_3,
                    :MRASCEVDEF_N.CHG_FLAG_4,
                    :MRASCEVDEF_N.CHG_FLAG_5,
                    :MRASCEVDEF_N.CHG_FLAG_6,
                    :MRASCEVDEF_N.CHG_FLAG_7,
                    :MRASCEVDEF_N.CHG_FLAG_8,
                    :MRASCEVDEF_N.CHG_FLAG_9,
                    :MRASCEVDEF_N.CHG_FLAG_10,
                    :MRASCEVDEF_N.CHG_FLAG_11,
                    :MRASCEVDEF_N.CHG_FLAG_12,
                    :MRASCEVDEF_N.CHG_FLAG_13,
                    :MRASCEVDEF_N.CHG_FLAG_14,
                    :MRASCEVDEF_N.CHG_FLAG_15,
                    :MRASCEVDEF_N.CHG_FLAG_16,
                    :MRASCEVDEF_N.CHG_FLAG_17,
                    :MRASCEVDEF_N.CHG_FLAG_18,
                    :MRASCEVDEF_N.CHG_FLAG_19,
                    :MRASCEVDEF_N.CHG_FLAG_20,
                    :MRASCEVDEF_N.CHG_FLAG_21,
                    :MRASCEVDEF_N.CHG_FLAG_22,
                    :MRASCEVDEF_N.CHG_FLAG_23,
                    :MRASCEVDEF_N.CHG_FLAG_24,
                    :MRASCEVDEF_N.CHG_FLAG_25,
                    :MRASCEVDEF_N.CHG_FLAG_26,
                    :MRASCEVDEF_N.CHG_FLAG_27,
                    :MRASCEVDEF_N.CHG_FLAG_28,
                    :MRASCEVDEF_N.CHG_FLAG_29,
                    :MRASCEVDEF_N.CHG_FLAG_30,
                    :MRASCEVDEF_N.CHG_VALUE_1,
                    :MRASCEVDEF_N.CHG_VALUE_2,
                    :MRASCEVDEF_N.CHG_VALUE_3,
                    :MRASCEVDEF_N.CHG_VALUE_4,
                    :MRASCEVDEF_N.CHG_VALUE_5,
                    :MRASCEVDEF_N.CHG_VALUE_6,
                    :MRASCEVDEF_N.CHG_VALUE_7,
                    :MRASCEVDEF_N.CHG_VALUE_8,
                    :MRASCEVDEF_N.CHG_VALUE_9,
                    :MRASCEVDEF_N.CHG_VALUE_10,
                    :MRASCEVDEF_N.CHG_VALUE_11,
                    :MRASCEVDEF_N.CHG_VALUE_12,
                    :MRASCEVDEF_N.CHG_VALUE_13,
                    :MRASCEVDEF_N.CHG_VALUE_14,
                    :MRASCEVDEF_N.CHG_VALUE_15,
                    :MRASCEVDEF_N.CHG_VALUE_16,
                    :MRASCEVDEF_N.CHG_VALUE_17,
                    :MRASCEVDEF_N.CHG_VALUE_18,
                    :MRASCEVDEF_N.CHG_VALUE_19,
                    :MRASCEVDEF_N.CHG_VALUE_20,
                    :MRASCEVDEF_N.CHG_VALUE_21,
                    :MRASCEVDEF_N.CHG_VALUE_22,
                    :MRASCEVDEF_N.CHG_VALUE_23,
                    :MRASCEVDEF_N.CHG_VALUE_24,
                    :MRASCEVDEF_N.CHG_VALUE_25,
                    :MRASCEVDEF_N.CHG_VALUE_26,
                    :MRASCEVDEF_N.CHG_VALUE_27,
                    :MRASCEVDEF_N.CHG_VALUE_28,
                    :MRASCEVDEF_N.CHG_VALUE_29,
                    :MRASCEVDEF_N.CHG_VALUE_30,
                    :MRASCEVDEF_N.CHG_OPT_1,
                    :MRASCEVDEF_N.CHG_OPT_2,
                    :MRASCEVDEF_N.CHG_OPT_3,
                    :MRASCEVDEF_N.CHG_OPT_4,
                    :MRASCEVDEF_N.CHG_OPT_5,
                    :MRASCEVDEF_N.CHG_OPT_6,
                    :MRASCEVDEF_N.CHG_OPT_7,
                    :MRASCEVDEF_N.CHG_OPT_8,
                    :MRASCEVDEF_N.CHG_OPT_9,
                    :MRASCEVDEF_N.CHG_OPT_10,
                    :MRASCEVDEF_N.CHG_OPT_11,
                    :MRASCEVDEF_N.CHG_OPT_12,
                    :MRASCEVDEF_N.CHG_OPT_13,
                    :MRASCEVDEF_N.CHG_OPT_14,
                    :MRASCEVDEF_N.CHG_OPT_15,
                    :MRASCEVDEF_N.CHG_OPT_16,
                    :MRASCEVDEF_N.CHG_OPT_17,
                    :MRASCEVDEF_N.CHG_OPT_18,
                    :MRASCEVDEF_N.CHG_OPT_19,
                    :MRASCEVDEF_N.CHG_OPT_20,
                    :MRASCEVDEF_N.CHG_OPT_21,
                    :MRASCEVDEF_N.CHG_OPT_22,
                    :MRASCEVDEF_N.CHG_OPT_23,
                    :MRASCEVDEF_N.CHG_OPT_24,
                    :MRASCEVDEF_N.CHG_OPT_25,
                    :MRASCEVDEF_N.CHG_OPT_26,
                    :MRASCEVDEF_N.CHG_OPT_27,
                    :MRASCEVDEF_N.CHG_OPT_28,
                    :MRASCEVDEF_N.CHG_OPT_29,
                    :MRASCEVDEF_N.CHG_OPT_30,
                    :MRASCEVDEF_N.CREATE_USER_ID,
                    :MRASCEVDEF_N.CREATE_TIME,
                    :MRASCEVDEF_N.UPDATE_USER_ID,
                    :MRASCEVDEF_N.UPDATE_TIME
        ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 250;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlbuft((void **)0,
      "insert into MRASCEVDEF (FACTORY,CRR_EVENT_ID,CRR_EVENT_DESC,SYSTEM_FL\
AG,CHK_ITEM_1,CHK_ITEM_2,CHK_ITEM_3,CHK_ITEM_4,CHK_ITEM_5,CHK_ITEM_6,CHK_ITE\
M_7,CHK_ITEM_8,CHK_ITEM_9,CHK_ITEM_10,CHK_ITEM_11,CHK_ITEM_12,CHK_ITEM_13,CH\
K_ITEM_14,CHK_ITEM_15,CHK_ITEM_16,CHK_ITEM_17,CHK_ITEM_18,CHK_ITEM_19,CHK_IT\
EM_20,CHK_ITEM_21,CHK_ITEM_22,CHK_ITEM_23,CHK_ITEM_24,CHK_ITEM_25,CHK_ITEM_2\
6,CHK_ITEM_27,CHK_ITEM_28,CHK_ITEM_29,CHK_ITEM_30,CHK_FLAG_1,CHK_FLAG_2,CHK_\
FLAG_3,CHK_FLAG_4,CHK_FLAG_5,CHK_FLAG_6,CHK_FLAG_7,CHK_FLAG_8,CHK_FLAG_9,CHK\
_FLAG_10,CHK_FLAG_11,CHK_FLAG_12,CHK_FLAG_13,CHK_FLAG_14,CHK_FLAG_15,CHK_FLA\
G_16,CHK_FLAG_17,CHK_FLAG_18,CHK_FLAG_19,CHK_FLAG_20,CHK_FLAG_21,CHK_FLAG_22\
,CHK_FLAG_23,CHK_FLAG_24,CHK_FLAG_25,CHK_FLAG_26,CHK_FLAG_27,CHK_FLAG_28,CHK\
_FLAG_29,CHK_FLAG_30,CHK_VALUE_1,CHK_VALUE_2,CHK_VALUE_3,CHK_VALUE_4,CHK_VAL\
UE_5,CHK_VALUE_6,CHK_VALUE_7,CHK_VALUE_8,CHK_VALUE_9,CHK_VALUE_10,CHK_VALUE_\
11,CHK_VALUE_12,CHK_VALUE_13,CHK_VALUE_14,CHK_VALUE_15,CHK_VALUE_16,CHK_VALU\
E_17,CHK_VALUE_18,CHK_VALUE_19,CHK_VALUE_20");
    sqlbuft((void **)0,
      ",CHK_VALUE_21,CHK_VALUE_22,CHK_VALUE_23,CHK_VALUE_24,CHK_VALUE_25,CHK\
_VALUE_26,CHK_VALUE_27,CHK_VALUE_28,CHK_VALUE_29,CHK_VALUE_30,CHK_FIELD_1,CH\
K_FIELD_2,CHK_FIELD_3,CHK_FIELD_4,CHK_FIELD_5,CHK_FIELD_6,CHK_FIELD_7,CHK_FI\
ELD_8,CHK_FIELD_9,CHK_FIELD_10,CHK_FIELD_11,CHK_FIELD_12,CHK_FIELD_13,CHK_FI\
ELD_14,CHK_FIELD_15,CHK_FIELD_16,CHK_FIELD_17,CHK_FIELD_18,CHK_FIELD_19,CHK_\
FIELD_20,CHK_FIELD_21,CHK_FIELD_22,CHK_FIELD_23,CHK_FIELD_24,CHK_FIELD_25,CH\
K_FIELD_26,CHK_FIELD_27,CHK_FIELD_28,CHK_FIELD_29,CHK_FIELD_30,CHG_ITEM_1,CH\
G_ITEM_2,CHG_ITEM_3,CHG_ITEM_4,CHG_ITEM_5,CHG_ITEM_6,CHG_ITEM_7,CHG_ITEM_8,C\
HG_ITEM_9,CHG_ITEM_10,CHG_ITEM_11,CHG_ITEM_12,CHG_ITEM_13,CHG_ITEM_14,CHG_IT\
EM_15,CHG_ITEM_16,CHG_ITEM_17,CHG_ITEM_18,CHG_ITEM_19,CHG_ITEM_20,CHG_ITEM_2\
1,CHG_ITEM_22,CHG_ITEM_23,CHG_ITEM_24,CHG_ITEM_25,CHG_ITEM_26,CHG_ITEM_27,CH\
G_ITEM_28,CHG_ITEM_29,CHG_ITEM_30,CHG_FLAG_1,CHG_FLAG_2,CHG_FLAG_3,CHG_FLAG_\
4,CHG_FLAG_5,CHG_FLAG_6,CHG_FLAG_7,CHG_FLAG_8,CHG_FLAG_9,CHG_FLAG_10,CHG_FLA\
G_11,CHG_FLAG_12,CHG_FLAG_13,CHG_FLAG_14,CH");
    sqlbuft((void **)0,
      "G_FLAG_15,CHG_FLAG_16,CHG_FLAG_17,CHG_FLAG_18,CHG_FLAG_19,CHG_FLAG_20\
,CHG_FLAG_21,CHG_FLAG_22,CHG_FLAG_23,CHG_FLAG_24,CHG_FLAG_25,CHG_FLAG_26,CHG\
_FLAG_27,CHG_FLAG_28,CHG_FLAG_29,CHG_FLAG_30,CHG_VALUE_1,CHG_VALUE_2,CHG_VAL\
UE_3,CHG_VALUE_4,CHG_VALUE_5,CHG_VALUE_6,CHG_VALUE_7,CHG_VALUE_8,CHG_VALUE_9\
,CHG_VALUE_10,CHG_VALUE_11,CHG_VALUE_12,CHG_VALUE_13,CHG_VALUE_14,CHG_VALUE_\
15,CHG_VALUE_16,CHG_VALUE_17,CHG_VALUE_18,CHG_VALUE_19,CHG_VALUE_20,CHG_VALU\
E_21,CHG_VALUE_22,CHG_VALUE_23,CHG_VALUE_24,CHG_VALUE_25,CHG_VALUE_26,CHG_VA\
LUE_27,CHG_VALUE_28,CHG_VALUE_29,CHG_VALUE_30,CHG_OPT_1,CHG_OPT_2,CHG_OPT_3,\
CHG_OPT_4,CHG_OPT_5,CHG_OPT_6,CHG_OPT_7,CHG_OPT_8,CHG_OPT_9,CHG_OPT_10,CHG_O\
PT_11,CHG_OPT_12,CHG_OPT_13,CHG_OPT_14,CHG_OPT_15,CHG_OPT_16,CHG_OPT_17,CHG_\
OPT_18,CHG_OPT_19,CHG_OPT_20,CHG_OPT_21,CHG_OPT_22,CHG_OPT_23,CHG_OPT_24,CHG\
_OPT_25,CHG_OPT_26,CHG_OPT_27,CHG_OPT_28,CHG_OPT_29,CHG_OPT_30,CREATE_USER_I\
D,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) values (:b0,:b1,:b2,:b3,:b4,:b5,:b\
6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15");
    sqlbuft((void **)0,
      ",:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,:b28,:b2\
9,:b30,:b31,:b32,:b33,:b34,:b35,:b36,:b37,:b38,:b39,:b40,:b41,:b42,:b43,:b44\
,:b45,:b46,:b47,:b48,:b49,:b50,:b51,:b52,:b53,:b54,:b55,:b56,:b57,:b58,:b59,\
:b60,:b61,:b62,:b63,:b64,:b65,:b66,:b67,:b68,:b69,:b70,:b71,:b72,:b73,:b74,:\
b75,:b76,:b77,:b78,:b79,:b80,:b81,:b82,:b83,:b84,:b85,:b86,:b87,:b88,:b89,:b\
90,:b91,:b92,:b93,:b94,:b95,:b96,:b97,:b98,:b99,:b100,:b101,:b102,:b103,:b10\
4,:b105,:b106,:b107,:b108,:b109,:b110,:b111,:b112,:b113,:b114,:b115,:b116,:b\
117,:b118,:b119,:b120,:b121,:b122,:b123,:b124,:b125,:b126,:b127,:b128,:b129,\
:b130,:b131,:b132,:b133,:b134,:b135,:b136,:b137,:b138,:b139,:b140,:b141,:b14\
2,:b143,:b144,:b145,:b146,:b147,:b148,:b149,:b150,:b151,:b152,:b153,:b154,:b\
155,:b156,:b157,:b158,:b159,:b160,:b161,:b162,:b163,:b164,:b165,:b166,:b167,\
:b168,:b169,:b170,:b171,:b172,:b173,:b174,:b175,:b176,:b177,:b178,:b179,:b18\
0,:b181,:b182,:b183,:b184,:b185,:b186,:b187,:b188,:b189,:b190,:b191,:b192,:b\
193,:b194,:b195,:b196,:b197,:b198,:b199,:b2");
    sqlstm.stmt = "00,:b201,:b202,:b203,:b204,:b205,:b206,:b207,:b208,:b209\
,:b210,:b211,:b212,:b213,:b214,:b215,:b216,:b217,:b218,:b219,:b220,:b221,:b22\
2,:b223,:b224,:b225,:b226,:b227,:b228,:b229,:b230,:b231,:b232,:b233,:b234,:b2\
35,:b236,:b237,:b238,:b239,:b240,:b241,:b242,:b243,:b244,:b245,:b246,:b247)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2085;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.FACTORY);
    sqlstm.sqhstl[0] = (unsigned int  )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
    sqlstm.sqhstl[1] = (unsigned int  )13;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_DESC);
    sqlstm.sqhstl[2] = (unsigned int  )201;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)(MRASCEVDEF_N.SYSTEM_FLAG);
    sqlstm.sqhstl[3] = (unsigned int  )2;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_1);
    sqlstm.sqhstl[4] = (unsigned int  )31;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_2);
    sqlstm.sqhstl[5] = (unsigned int  )31;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         void  *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned int  )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_3);
    sqlstm.sqhstl[6] = (unsigned int  )31;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         void  *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned int  )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_4);
    sqlstm.sqhstl[7] = (unsigned int  )31;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         void  *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned int  )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_5);
    sqlstm.sqhstl[8] = (unsigned int  )31;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         void  *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned int  )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_6);
    sqlstm.sqhstl[9] = (unsigned int  )31;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         void  *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned int  )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_7);
    sqlstm.sqhstl[10] = (unsigned int  )31;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         void  *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned int  )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_8);
    sqlstm.sqhstl[11] = (unsigned int  )31;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         void  *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned int  )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_9);
    sqlstm.sqhstl[12] = (unsigned int  )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         void  *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned int  )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_10);
    sqlstm.sqhstl[13] = (unsigned int  )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         void  *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned int  )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_11);
    sqlstm.sqhstl[14] = (unsigned int  )31;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         void  *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned int  )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_12);
    sqlstm.sqhstl[15] = (unsigned int  )31;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         void  *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned int  )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_13);
    sqlstm.sqhstl[16] = (unsigned int  )31;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         void  *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned int  )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_14);
    sqlstm.sqhstl[17] = (unsigned int  )31;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         void  *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned int  )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_15);
    sqlstm.sqhstl[18] = (unsigned int  )31;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         void  *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned int  )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_16);
    sqlstm.sqhstl[19] = (unsigned int  )31;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         void  *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned int  )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_17);
    sqlstm.sqhstl[20] = (unsigned int  )31;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         void  *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned int  )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_18);
    sqlstm.sqhstl[21] = (unsigned int  )31;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         void  *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned int  )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_19);
    sqlstm.sqhstl[22] = (unsigned int  )31;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         void  *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned int  )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_20);
    sqlstm.sqhstl[23] = (unsigned int  )31;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         void  *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned int  )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_21);
    sqlstm.sqhstl[24] = (unsigned int  )31;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         void  *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned int  )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_22);
    sqlstm.sqhstl[25] = (unsigned int  )31;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         void  *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned int  )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_23);
    sqlstm.sqhstl[26] = (unsigned int  )31;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         void  *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned int  )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_24);
    sqlstm.sqhstl[27] = (unsigned int  )31;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         void  *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned int  )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_25);
    sqlstm.sqhstl[28] = (unsigned int  )31;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         void  *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned int  )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_26);
    sqlstm.sqhstl[29] = (unsigned int  )31;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         void  *)0;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned int  )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqhstv[30] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_27);
    sqlstm.sqhstl[30] = (unsigned int  )31;
    sqlstm.sqhsts[30] = (         int  )0;
    sqlstm.sqindv[30] = (         void  *)0;
    sqlstm.sqinds[30] = (         int  )0;
    sqlstm.sqharm[30] = (unsigned int  )0;
    sqlstm.sqadto[30] = (unsigned short )0;
    sqlstm.sqtdso[30] = (unsigned short )0;
    sqlstm.sqhstv[31] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_28);
    sqlstm.sqhstl[31] = (unsigned int  )31;
    sqlstm.sqhsts[31] = (         int  )0;
    sqlstm.sqindv[31] = (         void  *)0;
    sqlstm.sqinds[31] = (         int  )0;
    sqlstm.sqharm[31] = (unsigned int  )0;
    sqlstm.sqadto[31] = (unsigned short )0;
    sqlstm.sqtdso[31] = (unsigned short )0;
    sqlstm.sqhstv[32] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_29);
    sqlstm.sqhstl[32] = (unsigned int  )31;
    sqlstm.sqhsts[32] = (         int  )0;
    sqlstm.sqindv[32] = (         void  *)0;
    sqlstm.sqinds[32] = (         int  )0;
    sqlstm.sqharm[32] = (unsigned int  )0;
    sqlstm.sqadto[32] = (unsigned short )0;
    sqlstm.sqtdso[32] = (unsigned short )0;
    sqlstm.sqhstv[33] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_30);
    sqlstm.sqhstl[33] = (unsigned int  )31;
    sqlstm.sqhsts[33] = (         int  )0;
    sqlstm.sqindv[33] = (         void  *)0;
    sqlstm.sqinds[33] = (         int  )0;
    sqlstm.sqharm[33] = (unsigned int  )0;
    sqlstm.sqadto[33] = (unsigned short )0;
    sqlstm.sqtdso[33] = (unsigned short )0;
    sqlstm.sqhstv[34] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_1);
    sqlstm.sqhstl[34] = (unsigned int  )2;
    sqlstm.sqhsts[34] = (         int  )0;
    sqlstm.sqindv[34] = (         void  *)0;
    sqlstm.sqinds[34] = (         int  )0;
    sqlstm.sqharm[34] = (unsigned int  )0;
    sqlstm.sqadto[34] = (unsigned short )0;
    sqlstm.sqtdso[34] = (unsigned short )0;
    sqlstm.sqhstv[35] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_2);
    sqlstm.sqhstl[35] = (unsigned int  )2;
    sqlstm.sqhsts[35] = (         int  )0;
    sqlstm.sqindv[35] = (         void  *)0;
    sqlstm.sqinds[35] = (         int  )0;
    sqlstm.sqharm[35] = (unsigned int  )0;
    sqlstm.sqadto[35] = (unsigned short )0;
    sqlstm.sqtdso[35] = (unsigned short )0;
    sqlstm.sqhstv[36] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_3);
    sqlstm.sqhstl[36] = (unsigned int  )2;
    sqlstm.sqhsts[36] = (         int  )0;
    sqlstm.sqindv[36] = (         void  *)0;
    sqlstm.sqinds[36] = (         int  )0;
    sqlstm.sqharm[36] = (unsigned int  )0;
    sqlstm.sqadto[36] = (unsigned short )0;
    sqlstm.sqtdso[36] = (unsigned short )0;
    sqlstm.sqhstv[37] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_4);
    sqlstm.sqhstl[37] = (unsigned int  )2;
    sqlstm.sqhsts[37] = (         int  )0;
    sqlstm.sqindv[37] = (         void  *)0;
    sqlstm.sqinds[37] = (         int  )0;
    sqlstm.sqharm[37] = (unsigned int  )0;
    sqlstm.sqadto[37] = (unsigned short )0;
    sqlstm.sqtdso[37] = (unsigned short )0;
    sqlstm.sqhstv[38] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_5);
    sqlstm.sqhstl[38] = (unsigned int  )2;
    sqlstm.sqhsts[38] = (         int  )0;
    sqlstm.sqindv[38] = (         void  *)0;
    sqlstm.sqinds[38] = (         int  )0;
    sqlstm.sqharm[38] = (unsigned int  )0;
    sqlstm.sqadto[38] = (unsigned short )0;
    sqlstm.sqtdso[38] = (unsigned short )0;
    sqlstm.sqhstv[39] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_6);
    sqlstm.sqhstl[39] = (unsigned int  )2;
    sqlstm.sqhsts[39] = (         int  )0;
    sqlstm.sqindv[39] = (         void  *)0;
    sqlstm.sqinds[39] = (         int  )0;
    sqlstm.sqharm[39] = (unsigned int  )0;
    sqlstm.sqadto[39] = (unsigned short )0;
    sqlstm.sqtdso[39] = (unsigned short )0;
    sqlstm.sqhstv[40] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_7);
    sqlstm.sqhstl[40] = (unsigned int  )2;
    sqlstm.sqhsts[40] = (         int  )0;
    sqlstm.sqindv[40] = (         void  *)0;
    sqlstm.sqinds[40] = (         int  )0;
    sqlstm.sqharm[40] = (unsigned int  )0;
    sqlstm.sqadto[40] = (unsigned short )0;
    sqlstm.sqtdso[40] = (unsigned short )0;
    sqlstm.sqhstv[41] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_8);
    sqlstm.sqhstl[41] = (unsigned int  )2;
    sqlstm.sqhsts[41] = (         int  )0;
    sqlstm.sqindv[41] = (         void  *)0;
    sqlstm.sqinds[41] = (         int  )0;
    sqlstm.sqharm[41] = (unsigned int  )0;
    sqlstm.sqadto[41] = (unsigned short )0;
    sqlstm.sqtdso[41] = (unsigned short )0;
    sqlstm.sqhstv[42] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_9);
    sqlstm.sqhstl[42] = (unsigned int  )2;
    sqlstm.sqhsts[42] = (         int  )0;
    sqlstm.sqindv[42] = (         void  *)0;
    sqlstm.sqinds[42] = (         int  )0;
    sqlstm.sqharm[42] = (unsigned int  )0;
    sqlstm.sqadto[42] = (unsigned short )0;
    sqlstm.sqtdso[42] = (unsigned short )0;
    sqlstm.sqhstv[43] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_10);
    sqlstm.sqhstl[43] = (unsigned int  )2;
    sqlstm.sqhsts[43] = (         int  )0;
    sqlstm.sqindv[43] = (         void  *)0;
    sqlstm.sqinds[43] = (         int  )0;
    sqlstm.sqharm[43] = (unsigned int  )0;
    sqlstm.sqadto[43] = (unsigned short )0;
    sqlstm.sqtdso[43] = (unsigned short )0;
    sqlstm.sqhstv[44] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_11);
    sqlstm.sqhstl[44] = (unsigned int  )2;
    sqlstm.sqhsts[44] = (         int  )0;
    sqlstm.sqindv[44] = (         void  *)0;
    sqlstm.sqinds[44] = (         int  )0;
    sqlstm.sqharm[44] = (unsigned int  )0;
    sqlstm.sqadto[44] = (unsigned short )0;
    sqlstm.sqtdso[44] = (unsigned short )0;
    sqlstm.sqhstv[45] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_12);
    sqlstm.sqhstl[45] = (unsigned int  )2;
    sqlstm.sqhsts[45] = (         int  )0;
    sqlstm.sqindv[45] = (         void  *)0;
    sqlstm.sqinds[45] = (         int  )0;
    sqlstm.sqharm[45] = (unsigned int  )0;
    sqlstm.sqadto[45] = (unsigned short )0;
    sqlstm.sqtdso[45] = (unsigned short )0;
    sqlstm.sqhstv[46] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_13);
    sqlstm.sqhstl[46] = (unsigned int  )2;
    sqlstm.sqhsts[46] = (         int  )0;
    sqlstm.sqindv[46] = (         void  *)0;
    sqlstm.sqinds[46] = (         int  )0;
    sqlstm.sqharm[46] = (unsigned int  )0;
    sqlstm.sqadto[46] = (unsigned short )0;
    sqlstm.sqtdso[46] = (unsigned short )0;
    sqlstm.sqhstv[47] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_14);
    sqlstm.sqhstl[47] = (unsigned int  )2;
    sqlstm.sqhsts[47] = (         int  )0;
    sqlstm.sqindv[47] = (         void  *)0;
    sqlstm.sqinds[47] = (         int  )0;
    sqlstm.sqharm[47] = (unsigned int  )0;
    sqlstm.sqadto[47] = (unsigned short )0;
    sqlstm.sqtdso[47] = (unsigned short )0;
    sqlstm.sqhstv[48] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_15);
    sqlstm.sqhstl[48] = (unsigned int  )2;
    sqlstm.sqhsts[48] = (         int  )0;
    sqlstm.sqindv[48] = (         void  *)0;
    sqlstm.sqinds[48] = (         int  )0;
    sqlstm.sqharm[48] = (unsigned int  )0;
    sqlstm.sqadto[48] = (unsigned short )0;
    sqlstm.sqtdso[48] = (unsigned short )0;
    sqlstm.sqhstv[49] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_16);
    sqlstm.sqhstl[49] = (unsigned int  )2;
    sqlstm.sqhsts[49] = (         int  )0;
    sqlstm.sqindv[49] = (         void  *)0;
    sqlstm.sqinds[49] = (         int  )0;
    sqlstm.sqharm[49] = (unsigned int  )0;
    sqlstm.sqadto[49] = (unsigned short )0;
    sqlstm.sqtdso[49] = (unsigned short )0;
    sqlstm.sqhstv[50] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_17);
    sqlstm.sqhstl[50] = (unsigned int  )2;
    sqlstm.sqhsts[50] = (         int  )0;
    sqlstm.sqindv[50] = (         void  *)0;
    sqlstm.sqinds[50] = (         int  )0;
    sqlstm.sqharm[50] = (unsigned int  )0;
    sqlstm.sqadto[50] = (unsigned short )0;
    sqlstm.sqtdso[50] = (unsigned short )0;
    sqlstm.sqhstv[51] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_18);
    sqlstm.sqhstl[51] = (unsigned int  )2;
    sqlstm.sqhsts[51] = (         int  )0;
    sqlstm.sqindv[51] = (         void  *)0;
    sqlstm.sqinds[51] = (         int  )0;
    sqlstm.sqharm[51] = (unsigned int  )0;
    sqlstm.sqadto[51] = (unsigned short )0;
    sqlstm.sqtdso[51] = (unsigned short )0;
    sqlstm.sqhstv[52] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_19);
    sqlstm.sqhstl[52] = (unsigned int  )2;
    sqlstm.sqhsts[52] = (         int  )0;
    sqlstm.sqindv[52] = (         void  *)0;
    sqlstm.sqinds[52] = (         int  )0;
    sqlstm.sqharm[52] = (unsigned int  )0;
    sqlstm.sqadto[52] = (unsigned short )0;
    sqlstm.sqtdso[52] = (unsigned short )0;
    sqlstm.sqhstv[53] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_20);
    sqlstm.sqhstl[53] = (unsigned int  )2;
    sqlstm.sqhsts[53] = (         int  )0;
    sqlstm.sqindv[53] = (         void  *)0;
    sqlstm.sqinds[53] = (         int  )0;
    sqlstm.sqharm[53] = (unsigned int  )0;
    sqlstm.sqadto[53] = (unsigned short )0;
    sqlstm.sqtdso[53] = (unsigned short )0;
    sqlstm.sqhstv[54] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_21);
    sqlstm.sqhstl[54] = (unsigned int  )2;
    sqlstm.sqhsts[54] = (         int  )0;
    sqlstm.sqindv[54] = (         void  *)0;
    sqlstm.sqinds[54] = (         int  )0;
    sqlstm.sqharm[54] = (unsigned int  )0;
    sqlstm.sqadto[54] = (unsigned short )0;
    sqlstm.sqtdso[54] = (unsigned short )0;
    sqlstm.sqhstv[55] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_22);
    sqlstm.sqhstl[55] = (unsigned int  )2;
    sqlstm.sqhsts[55] = (         int  )0;
    sqlstm.sqindv[55] = (         void  *)0;
    sqlstm.sqinds[55] = (         int  )0;
    sqlstm.sqharm[55] = (unsigned int  )0;
    sqlstm.sqadto[55] = (unsigned short )0;
    sqlstm.sqtdso[55] = (unsigned short )0;
    sqlstm.sqhstv[56] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_23);
    sqlstm.sqhstl[56] = (unsigned int  )2;
    sqlstm.sqhsts[56] = (         int  )0;
    sqlstm.sqindv[56] = (         void  *)0;
    sqlstm.sqinds[56] = (         int  )0;
    sqlstm.sqharm[56] = (unsigned int  )0;
    sqlstm.sqadto[56] = (unsigned short )0;
    sqlstm.sqtdso[56] = (unsigned short )0;
    sqlstm.sqhstv[57] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_24);
    sqlstm.sqhstl[57] = (unsigned int  )2;
    sqlstm.sqhsts[57] = (         int  )0;
    sqlstm.sqindv[57] = (         void  *)0;
    sqlstm.sqinds[57] = (         int  )0;
    sqlstm.sqharm[57] = (unsigned int  )0;
    sqlstm.sqadto[57] = (unsigned short )0;
    sqlstm.sqtdso[57] = (unsigned short )0;
    sqlstm.sqhstv[58] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_25);
    sqlstm.sqhstl[58] = (unsigned int  )2;
    sqlstm.sqhsts[58] = (         int  )0;
    sqlstm.sqindv[58] = (         void  *)0;
    sqlstm.sqinds[58] = (         int  )0;
    sqlstm.sqharm[58] = (unsigned int  )0;
    sqlstm.sqadto[58] = (unsigned short )0;
    sqlstm.sqtdso[58] = (unsigned short )0;
    sqlstm.sqhstv[59] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_26);
    sqlstm.sqhstl[59] = (unsigned int  )2;
    sqlstm.sqhsts[59] = (         int  )0;
    sqlstm.sqindv[59] = (         void  *)0;
    sqlstm.sqinds[59] = (         int  )0;
    sqlstm.sqharm[59] = (unsigned int  )0;
    sqlstm.sqadto[59] = (unsigned short )0;
    sqlstm.sqtdso[59] = (unsigned short )0;
    sqlstm.sqhstv[60] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_27);
    sqlstm.sqhstl[60] = (unsigned int  )2;
    sqlstm.sqhsts[60] = (         int  )0;
    sqlstm.sqindv[60] = (         void  *)0;
    sqlstm.sqinds[60] = (         int  )0;
    sqlstm.sqharm[60] = (unsigned int  )0;
    sqlstm.sqadto[60] = (unsigned short )0;
    sqlstm.sqtdso[60] = (unsigned short )0;
    sqlstm.sqhstv[61] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_28);
    sqlstm.sqhstl[61] = (unsigned int  )2;
    sqlstm.sqhsts[61] = (         int  )0;
    sqlstm.sqindv[61] = (         void  *)0;
    sqlstm.sqinds[61] = (         int  )0;
    sqlstm.sqharm[61] = (unsigned int  )0;
    sqlstm.sqadto[61] = (unsigned short )0;
    sqlstm.sqtdso[61] = (unsigned short )0;
    sqlstm.sqhstv[62] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_29);
    sqlstm.sqhstl[62] = (unsigned int  )2;
    sqlstm.sqhsts[62] = (         int  )0;
    sqlstm.sqindv[62] = (         void  *)0;
    sqlstm.sqinds[62] = (         int  )0;
    sqlstm.sqharm[62] = (unsigned int  )0;
    sqlstm.sqadto[62] = (unsigned short )0;
    sqlstm.sqtdso[62] = (unsigned short )0;
    sqlstm.sqhstv[63] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_30);
    sqlstm.sqhstl[63] = (unsigned int  )2;
    sqlstm.sqhsts[63] = (         int  )0;
    sqlstm.sqindv[63] = (         void  *)0;
    sqlstm.sqinds[63] = (         int  )0;
    sqlstm.sqharm[63] = (unsigned int  )0;
    sqlstm.sqadto[63] = (unsigned short )0;
    sqlstm.sqtdso[63] = (unsigned short )0;
    sqlstm.sqhstv[64] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_1);
    sqlstm.sqhstl[64] = (unsigned int  )31;
    sqlstm.sqhsts[64] = (         int  )0;
    sqlstm.sqindv[64] = (         void  *)0;
    sqlstm.sqinds[64] = (         int  )0;
    sqlstm.sqharm[64] = (unsigned int  )0;
    sqlstm.sqadto[64] = (unsigned short )0;
    sqlstm.sqtdso[64] = (unsigned short )0;
    sqlstm.sqhstv[65] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_2);
    sqlstm.sqhstl[65] = (unsigned int  )31;
    sqlstm.sqhsts[65] = (         int  )0;
    sqlstm.sqindv[65] = (         void  *)0;
    sqlstm.sqinds[65] = (         int  )0;
    sqlstm.sqharm[65] = (unsigned int  )0;
    sqlstm.sqadto[65] = (unsigned short )0;
    sqlstm.sqtdso[65] = (unsigned short )0;
    sqlstm.sqhstv[66] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_3);
    sqlstm.sqhstl[66] = (unsigned int  )31;
    sqlstm.sqhsts[66] = (         int  )0;
    sqlstm.sqindv[66] = (         void  *)0;
    sqlstm.sqinds[66] = (         int  )0;
    sqlstm.sqharm[66] = (unsigned int  )0;
    sqlstm.sqadto[66] = (unsigned short )0;
    sqlstm.sqtdso[66] = (unsigned short )0;
    sqlstm.sqhstv[67] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_4);
    sqlstm.sqhstl[67] = (unsigned int  )31;
    sqlstm.sqhsts[67] = (         int  )0;
    sqlstm.sqindv[67] = (         void  *)0;
    sqlstm.sqinds[67] = (         int  )0;
    sqlstm.sqharm[67] = (unsigned int  )0;
    sqlstm.sqadto[67] = (unsigned short )0;
    sqlstm.sqtdso[67] = (unsigned short )0;
    sqlstm.sqhstv[68] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_5);
    sqlstm.sqhstl[68] = (unsigned int  )31;
    sqlstm.sqhsts[68] = (         int  )0;
    sqlstm.sqindv[68] = (         void  *)0;
    sqlstm.sqinds[68] = (         int  )0;
    sqlstm.sqharm[68] = (unsigned int  )0;
    sqlstm.sqadto[68] = (unsigned short )0;
    sqlstm.sqtdso[68] = (unsigned short )0;
    sqlstm.sqhstv[69] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_6);
    sqlstm.sqhstl[69] = (unsigned int  )31;
    sqlstm.sqhsts[69] = (         int  )0;
    sqlstm.sqindv[69] = (         void  *)0;
    sqlstm.sqinds[69] = (         int  )0;
    sqlstm.sqharm[69] = (unsigned int  )0;
    sqlstm.sqadto[69] = (unsigned short )0;
    sqlstm.sqtdso[69] = (unsigned short )0;
    sqlstm.sqhstv[70] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_7);
    sqlstm.sqhstl[70] = (unsigned int  )31;
    sqlstm.sqhsts[70] = (         int  )0;
    sqlstm.sqindv[70] = (         void  *)0;
    sqlstm.sqinds[70] = (         int  )0;
    sqlstm.sqharm[70] = (unsigned int  )0;
    sqlstm.sqadto[70] = (unsigned short )0;
    sqlstm.sqtdso[70] = (unsigned short )0;
    sqlstm.sqhstv[71] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_8);
    sqlstm.sqhstl[71] = (unsigned int  )31;
    sqlstm.sqhsts[71] = (         int  )0;
    sqlstm.sqindv[71] = (         void  *)0;
    sqlstm.sqinds[71] = (         int  )0;
    sqlstm.sqharm[71] = (unsigned int  )0;
    sqlstm.sqadto[71] = (unsigned short )0;
    sqlstm.sqtdso[71] = (unsigned short )0;
    sqlstm.sqhstv[72] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_9);
    sqlstm.sqhstl[72] = (unsigned int  )31;
    sqlstm.sqhsts[72] = (         int  )0;
    sqlstm.sqindv[72] = (         void  *)0;
    sqlstm.sqinds[72] = (         int  )0;
    sqlstm.sqharm[72] = (unsigned int  )0;
    sqlstm.sqadto[72] = (unsigned short )0;
    sqlstm.sqtdso[72] = (unsigned short )0;
    sqlstm.sqhstv[73] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_10);
    sqlstm.sqhstl[73] = (unsigned int  )31;
    sqlstm.sqhsts[73] = (         int  )0;
    sqlstm.sqindv[73] = (         void  *)0;
    sqlstm.sqinds[73] = (         int  )0;
    sqlstm.sqharm[73] = (unsigned int  )0;
    sqlstm.sqadto[73] = (unsigned short )0;
    sqlstm.sqtdso[73] = (unsigned short )0;
    sqlstm.sqhstv[74] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_11);
    sqlstm.sqhstl[74] = (unsigned int  )31;
    sqlstm.sqhsts[74] = (         int  )0;
    sqlstm.sqindv[74] = (         void  *)0;
    sqlstm.sqinds[74] = (         int  )0;
    sqlstm.sqharm[74] = (unsigned int  )0;
    sqlstm.sqadto[74] = (unsigned short )0;
    sqlstm.sqtdso[74] = (unsigned short )0;
    sqlstm.sqhstv[75] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_12);
    sqlstm.sqhstl[75] = (unsigned int  )31;
    sqlstm.sqhsts[75] = (         int  )0;
    sqlstm.sqindv[75] = (         void  *)0;
    sqlstm.sqinds[75] = (         int  )0;
    sqlstm.sqharm[75] = (unsigned int  )0;
    sqlstm.sqadto[75] = (unsigned short )0;
    sqlstm.sqtdso[75] = (unsigned short )0;
    sqlstm.sqhstv[76] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_13);
    sqlstm.sqhstl[76] = (unsigned int  )31;
    sqlstm.sqhsts[76] = (         int  )0;
    sqlstm.sqindv[76] = (         void  *)0;
    sqlstm.sqinds[76] = (         int  )0;
    sqlstm.sqharm[76] = (unsigned int  )0;
    sqlstm.sqadto[76] = (unsigned short )0;
    sqlstm.sqtdso[76] = (unsigned short )0;
    sqlstm.sqhstv[77] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_14);
    sqlstm.sqhstl[77] = (unsigned int  )31;
    sqlstm.sqhsts[77] = (         int  )0;
    sqlstm.sqindv[77] = (         void  *)0;
    sqlstm.sqinds[77] = (         int  )0;
    sqlstm.sqharm[77] = (unsigned int  )0;
    sqlstm.sqadto[77] = (unsigned short )0;
    sqlstm.sqtdso[77] = (unsigned short )0;
    sqlstm.sqhstv[78] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_15);
    sqlstm.sqhstl[78] = (unsigned int  )31;
    sqlstm.sqhsts[78] = (         int  )0;
    sqlstm.sqindv[78] = (         void  *)0;
    sqlstm.sqinds[78] = (         int  )0;
    sqlstm.sqharm[78] = (unsigned int  )0;
    sqlstm.sqadto[78] = (unsigned short )0;
    sqlstm.sqtdso[78] = (unsigned short )0;
    sqlstm.sqhstv[79] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_16);
    sqlstm.sqhstl[79] = (unsigned int  )31;
    sqlstm.sqhsts[79] = (         int  )0;
    sqlstm.sqindv[79] = (         void  *)0;
    sqlstm.sqinds[79] = (         int  )0;
    sqlstm.sqharm[79] = (unsigned int  )0;
    sqlstm.sqadto[79] = (unsigned short )0;
    sqlstm.sqtdso[79] = (unsigned short )0;
    sqlstm.sqhstv[80] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_17);
    sqlstm.sqhstl[80] = (unsigned int  )31;
    sqlstm.sqhsts[80] = (         int  )0;
    sqlstm.sqindv[80] = (         void  *)0;
    sqlstm.sqinds[80] = (         int  )0;
    sqlstm.sqharm[80] = (unsigned int  )0;
    sqlstm.sqadto[80] = (unsigned short )0;
    sqlstm.sqtdso[80] = (unsigned short )0;
    sqlstm.sqhstv[81] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_18);
    sqlstm.sqhstl[81] = (unsigned int  )31;
    sqlstm.sqhsts[81] = (         int  )0;
    sqlstm.sqindv[81] = (         void  *)0;
    sqlstm.sqinds[81] = (         int  )0;
    sqlstm.sqharm[81] = (unsigned int  )0;
    sqlstm.sqadto[81] = (unsigned short )0;
    sqlstm.sqtdso[81] = (unsigned short )0;
    sqlstm.sqhstv[82] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_19);
    sqlstm.sqhstl[82] = (unsigned int  )31;
    sqlstm.sqhsts[82] = (         int  )0;
    sqlstm.sqindv[82] = (         void  *)0;
    sqlstm.sqinds[82] = (         int  )0;
    sqlstm.sqharm[82] = (unsigned int  )0;
    sqlstm.sqadto[82] = (unsigned short )0;
    sqlstm.sqtdso[82] = (unsigned short )0;
    sqlstm.sqhstv[83] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_20);
    sqlstm.sqhstl[83] = (unsigned int  )31;
    sqlstm.sqhsts[83] = (         int  )0;
    sqlstm.sqindv[83] = (         void  *)0;
    sqlstm.sqinds[83] = (         int  )0;
    sqlstm.sqharm[83] = (unsigned int  )0;
    sqlstm.sqadto[83] = (unsigned short )0;
    sqlstm.sqtdso[83] = (unsigned short )0;
    sqlstm.sqhstv[84] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_21);
    sqlstm.sqhstl[84] = (unsigned int  )31;
    sqlstm.sqhsts[84] = (         int  )0;
    sqlstm.sqindv[84] = (         void  *)0;
    sqlstm.sqinds[84] = (         int  )0;
    sqlstm.sqharm[84] = (unsigned int  )0;
    sqlstm.sqadto[84] = (unsigned short )0;
    sqlstm.sqtdso[84] = (unsigned short )0;
    sqlstm.sqhstv[85] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_22);
    sqlstm.sqhstl[85] = (unsigned int  )31;
    sqlstm.sqhsts[85] = (         int  )0;
    sqlstm.sqindv[85] = (         void  *)0;
    sqlstm.sqinds[85] = (         int  )0;
    sqlstm.sqharm[85] = (unsigned int  )0;
    sqlstm.sqadto[85] = (unsigned short )0;
    sqlstm.sqtdso[85] = (unsigned short )0;
    sqlstm.sqhstv[86] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_23);
    sqlstm.sqhstl[86] = (unsigned int  )31;
    sqlstm.sqhsts[86] = (         int  )0;
    sqlstm.sqindv[86] = (         void  *)0;
    sqlstm.sqinds[86] = (         int  )0;
    sqlstm.sqharm[86] = (unsigned int  )0;
    sqlstm.sqadto[86] = (unsigned short )0;
    sqlstm.sqtdso[86] = (unsigned short )0;
    sqlstm.sqhstv[87] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_24);
    sqlstm.sqhstl[87] = (unsigned int  )31;
    sqlstm.sqhsts[87] = (         int  )0;
    sqlstm.sqindv[87] = (         void  *)0;
    sqlstm.sqinds[87] = (         int  )0;
    sqlstm.sqharm[87] = (unsigned int  )0;
    sqlstm.sqadto[87] = (unsigned short )0;
    sqlstm.sqtdso[87] = (unsigned short )0;
    sqlstm.sqhstv[88] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_25);
    sqlstm.sqhstl[88] = (unsigned int  )31;
    sqlstm.sqhsts[88] = (         int  )0;
    sqlstm.sqindv[88] = (         void  *)0;
    sqlstm.sqinds[88] = (         int  )0;
    sqlstm.sqharm[88] = (unsigned int  )0;
    sqlstm.sqadto[88] = (unsigned short )0;
    sqlstm.sqtdso[88] = (unsigned short )0;
    sqlstm.sqhstv[89] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_26);
    sqlstm.sqhstl[89] = (unsigned int  )31;
    sqlstm.sqhsts[89] = (         int  )0;
    sqlstm.sqindv[89] = (         void  *)0;
    sqlstm.sqinds[89] = (         int  )0;
    sqlstm.sqharm[89] = (unsigned int  )0;
    sqlstm.sqadto[89] = (unsigned short )0;
    sqlstm.sqtdso[89] = (unsigned short )0;
    sqlstm.sqhstv[90] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_27);
    sqlstm.sqhstl[90] = (unsigned int  )31;
    sqlstm.sqhsts[90] = (         int  )0;
    sqlstm.sqindv[90] = (         void  *)0;
    sqlstm.sqinds[90] = (         int  )0;
    sqlstm.sqharm[90] = (unsigned int  )0;
    sqlstm.sqadto[90] = (unsigned short )0;
    sqlstm.sqtdso[90] = (unsigned short )0;
    sqlstm.sqhstv[91] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_28);
    sqlstm.sqhstl[91] = (unsigned int  )31;
    sqlstm.sqhsts[91] = (         int  )0;
    sqlstm.sqindv[91] = (         void  *)0;
    sqlstm.sqinds[91] = (         int  )0;
    sqlstm.sqharm[91] = (unsigned int  )0;
    sqlstm.sqadto[91] = (unsigned short )0;
    sqlstm.sqtdso[91] = (unsigned short )0;
    sqlstm.sqhstv[92] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_29);
    sqlstm.sqhstl[92] = (unsigned int  )31;
    sqlstm.sqhsts[92] = (         int  )0;
    sqlstm.sqindv[92] = (         void  *)0;
    sqlstm.sqinds[92] = (         int  )0;
    sqlstm.sqharm[92] = (unsigned int  )0;
    sqlstm.sqadto[92] = (unsigned short )0;
    sqlstm.sqtdso[92] = (unsigned short )0;
    sqlstm.sqhstv[93] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_30);
    sqlstm.sqhstl[93] = (unsigned int  )31;
    sqlstm.sqhsts[93] = (         int  )0;
    sqlstm.sqindv[93] = (         void  *)0;
    sqlstm.sqinds[93] = (         int  )0;
    sqlstm.sqharm[93] = (unsigned int  )0;
    sqlstm.sqadto[93] = (unsigned short )0;
    sqlstm.sqtdso[93] = (unsigned short )0;
    sqlstm.sqhstv[94] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_1);
    sqlstm.sqhstl[94] = (unsigned int  )31;
    sqlstm.sqhsts[94] = (         int  )0;
    sqlstm.sqindv[94] = (         void  *)0;
    sqlstm.sqinds[94] = (         int  )0;
    sqlstm.sqharm[94] = (unsigned int  )0;
    sqlstm.sqadto[94] = (unsigned short )0;
    sqlstm.sqtdso[94] = (unsigned short )0;
    sqlstm.sqhstv[95] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_2);
    sqlstm.sqhstl[95] = (unsigned int  )31;
    sqlstm.sqhsts[95] = (         int  )0;
    sqlstm.sqindv[95] = (         void  *)0;
    sqlstm.sqinds[95] = (         int  )0;
    sqlstm.sqharm[95] = (unsigned int  )0;
    sqlstm.sqadto[95] = (unsigned short )0;
    sqlstm.sqtdso[95] = (unsigned short )0;
    sqlstm.sqhstv[96] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_3);
    sqlstm.sqhstl[96] = (unsigned int  )31;
    sqlstm.sqhsts[96] = (         int  )0;
    sqlstm.sqindv[96] = (         void  *)0;
    sqlstm.sqinds[96] = (         int  )0;
    sqlstm.sqharm[96] = (unsigned int  )0;
    sqlstm.sqadto[96] = (unsigned short )0;
    sqlstm.sqtdso[96] = (unsigned short )0;
    sqlstm.sqhstv[97] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_4);
    sqlstm.sqhstl[97] = (unsigned int  )31;
    sqlstm.sqhsts[97] = (         int  )0;
    sqlstm.sqindv[97] = (         void  *)0;
    sqlstm.sqinds[97] = (         int  )0;
    sqlstm.sqharm[97] = (unsigned int  )0;
    sqlstm.sqadto[97] = (unsigned short )0;
    sqlstm.sqtdso[97] = (unsigned short )0;
    sqlstm.sqhstv[98] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_5);
    sqlstm.sqhstl[98] = (unsigned int  )31;
    sqlstm.sqhsts[98] = (         int  )0;
    sqlstm.sqindv[98] = (         void  *)0;
    sqlstm.sqinds[98] = (         int  )0;
    sqlstm.sqharm[98] = (unsigned int  )0;
    sqlstm.sqadto[98] = (unsigned short )0;
    sqlstm.sqtdso[98] = (unsigned short )0;
    sqlstm.sqhstv[99] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_6);
    sqlstm.sqhstl[99] = (unsigned int  )31;
    sqlstm.sqhsts[99] = (         int  )0;
    sqlstm.sqindv[99] = (         void  *)0;
    sqlstm.sqinds[99] = (         int  )0;
    sqlstm.sqharm[99] = (unsigned int  )0;
    sqlstm.sqadto[99] = (unsigned short )0;
    sqlstm.sqtdso[99] = (unsigned short )0;
    sqlstm.sqhstv[100] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_7);
    sqlstm.sqhstl[100] = (unsigned int  )31;
    sqlstm.sqhsts[100] = (         int  )0;
    sqlstm.sqindv[100] = (         void  *)0;
    sqlstm.sqinds[100] = (         int  )0;
    sqlstm.sqharm[100] = (unsigned int  )0;
    sqlstm.sqadto[100] = (unsigned short )0;
    sqlstm.sqtdso[100] = (unsigned short )0;
    sqlstm.sqhstv[101] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_8);
    sqlstm.sqhstl[101] = (unsigned int  )31;
    sqlstm.sqhsts[101] = (         int  )0;
    sqlstm.sqindv[101] = (         void  *)0;
    sqlstm.sqinds[101] = (         int  )0;
    sqlstm.sqharm[101] = (unsigned int  )0;
    sqlstm.sqadto[101] = (unsigned short )0;
    sqlstm.sqtdso[101] = (unsigned short )0;
    sqlstm.sqhstv[102] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_9);
    sqlstm.sqhstl[102] = (unsigned int  )31;
    sqlstm.sqhsts[102] = (         int  )0;
    sqlstm.sqindv[102] = (         void  *)0;
    sqlstm.sqinds[102] = (         int  )0;
    sqlstm.sqharm[102] = (unsigned int  )0;
    sqlstm.sqadto[102] = (unsigned short )0;
    sqlstm.sqtdso[102] = (unsigned short )0;
    sqlstm.sqhstv[103] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_10);
    sqlstm.sqhstl[103] = (unsigned int  )31;
    sqlstm.sqhsts[103] = (         int  )0;
    sqlstm.sqindv[103] = (         void  *)0;
    sqlstm.sqinds[103] = (         int  )0;
    sqlstm.sqharm[103] = (unsigned int  )0;
    sqlstm.sqadto[103] = (unsigned short )0;
    sqlstm.sqtdso[103] = (unsigned short )0;
    sqlstm.sqhstv[104] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_11);
    sqlstm.sqhstl[104] = (unsigned int  )31;
    sqlstm.sqhsts[104] = (         int  )0;
    sqlstm.sqindv[104] = (         void  *)0;
    sqlstm.sqinds[104] = (         int  )0;
    sqlstm.sqharm[104] = (unsigned int  )0;
    sqlstm.sqadto[104] = (unsigned short )0;
    sqlstm.sqtdso[104] = (unsigned short )0;
    sqlstm.sqhstv[105] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_12);
    sqlstm.sqhstl[105] = (unsigned int  )31;
    sqlstm.sqhsts[105] = (         int  )0;
    sqlstm.sqindv[105] = (         void  *)0;
    sqlstm.sqinds[105] = (         int  )0;
    sqlstm.sqharm[105] = (unsigned int  )0;
    sqlstm.sqadto[105] = (unsigned short )0;
    sqlstm.sqtdso[105] = (unsigned short )0;
    sqlstm.sqhstv[106] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_13);
    sqlstm.sqhstl[106] = (unsigned int  )31;
    sqlstm.sqhsts[106] = (         int  )0;
    sqlstm.sqindv[106] = (         void  *)0;
    sqlstm.sqinds[106] = (         int  )0;
    sqlstm.sqharm[106] = (unsigned int  )0;
    sqlstm.sqadto[106] = (unsigned short )0;
    sqlstm.sqtdso[106] = (unsigned short )0;
    sqlstm.sqhstv[107] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_14);
    sqlstm.sqhstl[107] = (unsigned int  )31;
    sqlstm.sqhsts[107] = (         int  )0;
    sqlstm.sqindv[107] = (         void  *)0;
    sqlstm.sqinds[107] = (         int  )0;
    sqlstm.sqharm[107] = (unsigned int  )0;
    sqlstm.sqadto[107] = (unsigned short )0;
    sqlstm.sqtdso[107] = (unsigned short )0;
    sqlstm.sqhstv[108] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_15);
    sqlstm.sqhstl[108] = (unsigned int  )31;
    sqlstm.sqhsts[108] = (         int  )0;
    sqlstm.sqindv[108] = (         void  *)0;
    sqlstm.sqinds[108] = (         int  )0;
    sqlstm.sqharm[108] = (unsigned int  )0;
    sqlstm.sqadto[108] = (unsigned short )0;
    sqlstm.sqtdso[108] = (unsigned short )0;
    sqlstm.sqhstv[109] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_16);
    sqlstm.sqhstl[109] = (unsigned int  )31;
    sqlstm.sqhsts[109] = (         int  )0;
    sqlstm.sqindv[109] = (         void  *)0;
    sqlstm.sqinds[109] = (         int  )0;
    sqlstm.sqharm[109] = (unsigned int  )0;
    sqlstm.sqadto[109] = (unsigned short )0;
    sqlstm.sqtdso[109] = (unsigned short )0;
    sqlstm.sqhstv[110] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_17);
    sqlstm.sqhstl[110] = (unsigned int  )31;
    sqlstm.sqhsts[110] = (         int  )0;
    sqlstm.sqindv[110] = (         void  *)0;
    sqlstm.sqinds[110] = (         int  )0;
    sqlstm.sqharm[110] = (unsigned int  )0;
    sqlstm.sqadto[110] = (unsigned short )0;
    sqlstm.sqtdso[110] = (unsigned short )0;
    sqlstm.sqhstv[111] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_18);
    sqlstm.sqhstl[111] = (unsigned int  )31;
    sqlstm.sqhsts[111] = (         int  )0;
    sqlstm.sqindv[111] = (         void  *)0;
    sqlstm.sqinds[111] = (         int  )0;
    sqlstm.sqharm[111] = (unsigned int  )0;
    sqlstm.sqadto[111] = (unsigned short )0;
    sqlstm.sqtdso[111] = (unsigned short )0;
    sqlstm.sqhstv[112] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_19);
    sqlstm.sqhstl[112] = (unsigned int  )31;
    sqlstm.sqhsts[112] = (         int  )0;
    sqlstm.sqindv[112] = (         void  *)0;
    sqlstm.sqinds[112] = (         int  )0;
    sqlstm.sqharm[112] = (unsigned int  )0;
    sqlstm.sqadto[112] = (unsigned short )0;
    sqlstm.sqtdso[112] = (unsigned short )0;
    sqlstm.sqhstv[113] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_20);
    sqlstm.sqhstl[113] = (unsigned int  )31;
    sqlstm.sqhsts[113] = (         int  )0;
    sqlstm.sqindv[113] = (         void  *)0;
    sqlstm.sqinds[113] = (         int  )0;
    sqlstm.sqharm[113] = (unsigned int  )0;
    sqlstm.sqadto[113] = (unsigned short )0;
    sqlstm.sqtdso[113] = (unsigned short )0;
    sqlstm.sqhstv[114] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_21);
    sqlstm.sqhstl[114] = (unsigned int  )31;
    sqlstm.sqhsts[114] = (         int  )0;
    sqlstm.sqindv[114] = (         void  *)0;
    sqlstm.sqinds[114] = (         int  )0;
    sqlstm.sqharm[114] = (unsigned int  )0;
    sqlstm.sqadto[114] = (unsigned short )0;
    sqlstm.sqtdso[114] = (unsigned short )0;
    sqlstm.sqhstv[115] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_22);
    sqlstm.sqhstl[115] = (unsigned int  )31;
    sqlstm.sqhsts[115] = (         int  )0;
    sqlstm.sqindv[115] = (         void  *)0;
    sqlstm.sqinds[115] = (         int  )0;
    sqlstm.sqharm[115] = (unsigned int  )0;
    sqlstm.sqadto[115] = (unsigned short )0;
    sqlstm.sqtdso[115] = (unsigned short )0;
    sqlstm.sqhstv[116] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_23);
    sqlstm.sqhstl[116] = (unsigned int  )31;
    sqlstm.sqhsts[116] = (         int  )0;
    sqlstm.sqindv[116] = (         void  *)0;
    sqlstm.sqinds[116] = (         int  )0;
    sqlstm.sqharm[116] = (unsigned int  )0;
    sqlstm.sqadto[116] = (unsigned short )0;
    sqlstm.sqtdso[116] = (unsigned short )0;
    sqlstm.sqhstv[117] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_24);
    sqlstm.sqhstl[117] = (unsigned int  )31;
    sqlstm.sqhsts[117] = (         int  )0;
    sqlstm.sqindv[117] = (         void  *)0;
    sqlstm.sqinds[117] = (         int  )0;
    sqlstm.sqharm[117] = (unsigned int  )0;
    sqlstm.sqadto[117] = (unsigned short )0;
    sqlstm.sqtdso[117] = (unsigned short )0;
    sqlstm.sqhstv[118] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_25);
    sqlstm.sqhstl[118] = (unsigned int  )31;
    sqlstm.sqhsts[118] = (         int  )0;
    sqlstm.sqindv[118] = (         void  *)0;
    sqlstm.sqinds[118] = (         int  )0;
    sqlstm.sqharm[118] = (unsigned int  )0;
    sqlstm.sqadto[118] = (unsigned short )0;
    sqlstm.sqtdso[118] = (unsigned short )0;
    sqlstm.sqhstv[119] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_26);
    sqlstm.sqhstl[119] = (unsigned int  )31;
    sqlstm.sqhsts[119] = (         int  )0;
    sqlstm.sqindv[119] = (         void  *)0;
    sqlstm.sqinds[119] = (         int  )0;
    sqlstm.sqharm[119] = (unsigned int  )0;
    sqlstm.sqadto[119] = (unsigned short )0;
    sqlstm.sqtdso[119] = (unsigned short )0;
    sqlstm.sqhstv[120] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_27);
    sqlstm.sqhstl[120] = (unsigned int  )31;
    sqlstm.sqhsts[120] = (         int  )0;
    sqlstm.sqindv[120] = (         void  *)0;
    sqlstm.sqinds[120] = (         int  )0;
    sqlstm.sqharm[120] = (unsigned int  )0;
    sqlstm.sqadto[120] = (unsigned short )0;
    sqlstm.sqtdso[120] = (unsigned short )0;
    sqlstm.sqhstv[121] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_28);
    sqlstm.sqhstl[121] = (unsigned int  )31;
    sqlstm.sqhsts[121] = (         int  )0;
    sqlstm.sqindv[121] = (         void  *)0;
    sqlstm.sqinds[121] = (         int  )0;
    sqlstm.sqharm[121] = (unsigned int  )0;
    sqlstm.sqadto[121] = (unsigned short )0;
    sqlstm.sqtdso[121] = (unsigned short )0;
    sqlstm.sqhstv[122] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_29);
    sqlstm.sqhstl[122] = (unsigned int  )31;
    sqlstm.sqhsts[122] = (         int  )0;
    sqlstm.sqindv[122] = (         void  *)0;
    sqlstm.sqinds[122] = (         int  )0;
    sqlstm.sqharm[122] = (unsigned int  )0;
    sqlstm.sqadto[122] = (unsigned short )0;
    sqlstm.sqtdso[122] = (unsigned short )0;
    sqlstm.sqhstv[123] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_30);
    sqlstm.sqhstl[123] = (unsigned int  )31;
    sqlstm.sqhsts[123] = (         int  )0;
    sqlstm.sqindv[123] = (         void  *)0;
    sqlstm.sqinds[123] = (         int  )0;
    sqlstm.sqharm[123] = (unsigned int  )0;
    sqlstm.sqadto[123] = (unsigned short )0;
    sqlstm.sqtdso[123] = (unsigned short )0;
    sqlstm.sqhstv[124] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_1);
    sqlstm.sqhstl[124] = (unsigned int  )31;
    sqlstm.sqhsts[124] = (         int  )0;
    sqlstm.sqindv[124] = (         void  *)0;
    sqlstm.sqinds[124] = (         int  )0;
    sqlstm.sqharm[124] = (unsigned int  )0;
    sqlstm.sqadto[124] = (unsigned short )0;
    sqlstm.sqtdso[124] = (unsigned short )0;
    sqlstm.sqhstv[125] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_2);
    sqlstm.sqhstl[125] = (unsigned int  )31;
    sqlstm.sqhsts[125] = (         int  )0;
    sqlstm.sqindv[125] = (         void  *)0;
    sqlstm.sqinds[125] = (         int  )0;
    sqlstm.sqharm[125] = (unsigned int  )0;
    sqlstm.sqadto[125] = (unsigned short )0;
    sqlstm.sqtdso[125] = (unsigned short )0;
    sqlstm.sqhstv[126] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_3);
    sqlstm.sqhstl[126] = (unsigned int  )31;
    sqlstm.sqhsts[126] = (         int  )0;
    sqlstm.sqindv[126] = (         void  *)0;
    sqlstm.sqinds[126] = (         int  )0;
    sqlstm.sqharm[126] = (unsigned int  )0;
    sqlstm.sqadto[126] = (unsigned short )0;
    sqlstm.sqtdso[126] = (unsigned short )0;
    sqlstm.sqhstv[127] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_4);
    sqlstm.sqhstl[127] = (unsigned int  )31;
    sqlstm.sqhsts[127] = (         int  )0;
    sqlstm.sqindv[127] = (         void  *)0;
    sqlstm.sqinds[127] = (         int  )0;
    sqlstm.sqharm[127] = (unsigned int  )0;
    sqlstm.sqadto[127] = (unsigned short )0;
    sqlstm.sqtdso[127] = (unsigned short )0;
    sqlstm.sqhstv[128] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_5);
    sqlstm.sqhstl[128] = (unsigned int  )31;
    sqlstm.sqhsts[128] = (         int  )0;
    sqlstm.sqindv[128] = (         void  *)0;
    sqlstm.sqinds[128] = (         int  )0;
    sqlstm.sqharm[128] = (unsigned int  )0;
    sqlstm.sqadto[128] = (unsigned short )0;
    sqlstm.sqtdso[128] = (unsigned short )0;
    sqlstm.sqhstv[129] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_6);
    sqlstm.sqhstl[129] = (unsigned int  )31;
    sqlstm.sqhsts[129] = (         int  )0;
    sqlstm.sqindv[129] = (         void  *)0;
    sqlstm.sqinds[129] = (         int  )0;
    sqlstm.sqharm[129] = (unsigned int  )0;
    sqlstm.sqadto[129] = (unsigned short )0;
    sqlstm.sqtdso[129] = (unsigned short )0;
    sqlstm.sqhstv[130] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_7);
    sqlstm.sqhstl[130] = (unsigned int  )31;
    sqlstm.sqhsts[130] = (         int  )0;
    sqlstm.sqindv[130] = (         void  *)0;
    sqlstm.sqinds[130] = (         int  )0;
    sqlstm.sqharm[130] = (unsigned int  )0;
    sqlstm.sqadto[130] = (unsigned short )0;
    sqlstm.sqtdso[130] = (unsigned short )0;
    sqlstm.sqhstv[131] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_8);
    sqlstm.sqhstl[131] = (unsigned int  )31;
    sqlstm.sqhsts[131] = (         int  )0;
    sqlstm.sqindv[131] = (         void  *)0;
    sqlstm.sqinds[131] = (         int  )0;
    sqlstm.sqharm[131] = (unsigned int  )0;
    sqlstm.sqadto[131] = (unsigned short )0;
    sqlstm.sqtdso[131] = (unsigned short )0;
    sqlstm.sqhstv[132] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_9);
    sqlstm.sqhstl[132] = (unsigned int  )31;
    sqlstm.sqhsts[132] = (         int  )0;
    sqlstm.sqindv[132] = (         void  *)0;
    sqlstm.sqinds[132] = (         int  )0;
    sqlstm.sqharm[132] = (unsigned int  )0;
    sqlstm.sqadto[132] = (unsigned short )0;
    sqlstm.sqtdso[132] = (unsigned short )0;
    sqlstm.sqhstv[133] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_10);
    sqlstm.sqhstl[133] = (unsigned int  )31;
    sqlstm.sqhsts[133] = (         int  )0;
    sqlstm.sqindv[133] = (         void  *)0;
    sqlstm.sqinds[133] = (         int  )0;
    sqlstm.sqharm[133] = (unsigned int  )0;
    sqlstm.sqadto[133] = (unsigned short )0;
    sqlstm.sqtdso[133] = (unsigned short )0;
    sqlstm.sqhstv[134] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_11);
    sqlstm.sqhstl[134] = (unsigned int  )31;
    sqlstm.sqhsts[134] = (         int  )0;
    sqlstm.sqindv[134] = (         void  *)0;
    sqlstm.sqinds[134] = (         int  )0;
    sqlstm.sqharm[134] = (unsigned int  )0;
    sqlstm.sqadto[134] = (unsigned short )0;
    sqlstm.sqtdso[134] = (unsigned short )0;
    sqlstm.sqhstv[135] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_12);
    sqlstm.sqhstl[135] = (unsigned int  )31;
    sqlstm.sqhsts[135] = (         int  )0;
    sqlstm.sqindv[135] = (         void  *)0;
    sqlstm.sqinds[135] = (         int  )0;
    sqlstm.sqharm[135] = (unsigned int  )0;
    sqlstm.sqadto[135] = (unsigned short )0;
    sqlstm.sqtdso[135] = (unsigned short )0;
    sqlstm.sqhstv[136] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_13);
    sqlstm.sqhstl[136] = (unsigned int  )31;
    sqlstm.sqhsts[136] = (         int  )0;
    sqlstm.sqindv[136] = (         void  *)0;
    sqlstm.sqinds[136] = (         int  )0;
    sqlstm.sqharm[136] = (unsigned int  )0;
    sqlstm.sqadto[136] = (unsigned short )0;
    sqlstm.sqtdso[136] = (unsigned short )0;
    sqlstm.sqhstv[137] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_14);
    sqlstm.sqhstl[137] = (unsigned int  )31;
    sqlstm.sqhsts[137] = (         int  )0;
    sqlstm.sqindv[137] = (         void  *)0;
    sqlstm.sqinds[137] = (         int  )0;
    sqlstm.sqharm[137] = (unsigned int  )0;
    sqlstm.sqadto[137] = (unsigned short )0;
    sqlstm.sqtdso[137] = (unsigned short )0;
    sqlstm.sqhstv[138] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_15);
    sqlstm.sqhstl[138] = (unsigned int  )31;
    sqlstm.sqhsts[138] = (         int  )0;
    sqlstm.sqindv[138] = (         void  *)0;
    sqlstm.sqinds[138] = (         int  )0;
    sqlstm.sqharm[138] = (unsigned int  )0;
    sqlstm.sqadto[138] = (unsigned short )0;
    sqlstm.sqtdso[138] = (unsigned short )0;
    sqlstm.sqhstv[139] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_16);
    sqlstm.sqhstl[139] = (unsigned int  )31;
    sqlstm.sqhsts[139] = (         int  )0;
    sqlstm.sqindv[139] = (         void  *)0;
    sqlstm.sqinds[139] = (         int  )0;
    sqlstm.sqharm[139] = (unsigned int  )0;
    sqlstm.sqadto[139] = (unsigned short )0;
    sqlstm.sqtdso[139] = (unsigned short )0;
    sqlstm.sqhstv[140] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_17);
    sqlstm.sqhstl[140] = (unsigned int  )31;
    sqlstm.sqhsts[140] = (         int  )0;
    sqlstm.sqindv[140] = (         void  *)0;
    sqlstm.sqinds[140] = (         int  )0;
    sqlstm.sqharm[140] = (unsigned int  )0;
    sqlstm.sqadto[140] = (unsigned short )0;
    sqlstm.sqtdso[140] = (unsigned short )0;
    sqlstm.sqhstv[141] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_18);
    sqlstm.sqhstl[141] = (unsigned int  )31;
    sqlstm.sqhsts[141] = (         int  )0;
    sqlstm.sqindv[141] = (         void  *)0;
    sqlstm.sqinds[141] = (         int  )0;
    sqlstm.sqharm[141] = (unsigned int  )0;
    sqlstm.sqadto[141] = (unsigned short )0;
    sqlstm.sqtdso[141] = (unsigned short )0;
    sqlstm.sqhstv[142] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_19);
    sqlstm.sqhstl[142] = (unsigned int  )31;
    sqlstm.sqhsts[142] = (         int  )0;
    sqlstm.sqindv[142] = (         void  *)0;
    sqlstm.sqinds[142] = (         int  )0;
    sqlstm.sqharm[142] = (unsigned int  )0;
    sqlstm.sqadto[142] = (unsigned short )0;
    sqlstm.sqtdso[142] = (unsigned short )0;
    sqlstm.sqhstv[143] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_20);
    sqlstm.sqhstl[143] = (unsigned int  )31;
    sqlstm.sqhsts[143] = (         int  )0;
    sqlstm.sqindv[143] = (         void  *)0;
    sqlstm.sqinds[143] = (         int  )0;
    sqlstm.sqharm[143] = (unsigned int  )0;
    sqlstm.sqadto[143] = (unsigned short )0;
    sqlstm.sqtdso[143] = (unsigned short )0;
    sqlstm.sqhstv[144] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_21);
    sqlstm.sqhstl[144] = (unsigned int  )31;
    sqlstm.sqhsts[144] = (         int  )0;
    sqlstm.sqindv[144] = (         void  *)0;
    sqlstm.sqinds[144] = (         int  )0;
    sqlstm.sqharm[144] = (unsigned int  )0;
    sqlstm.sqadto[144] = (unsigned short )0;
    sqlstm.sqtdso[144] = (unsigned short )0;
    sqlstm.sqhstv[145] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_22);
    sqlstm.sqhstl[145] = (unsigned int  )31;
    sqlstm.sqhsts[145] = (         int  )0;
    sqlstm.sqindv[145] = (         void  *)0;
    sqlstm.sqinds[145] = (         int  )0;
    sqlstm.sqharm[145] = (unsigned int  )0;
    sqlstm.sqadto[145] = (unsigned short )0;
    sqlstm.sqtdso[145] = (unsigned short )0;
    sqlstm.sqhstv[146] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_23);
    sqlstm.sqhstl[146] = (unsigned int  )31;
    sqlstm.sqhsts[146] = (         int  )0;
    sqlstm.sqindv[146] = (         void  *)0;
    sqlstm.sqinds[146] = (         int  )0;
    sqlstm.sqharm[146] = (unsigned int  )0;
    sqlstm.sqadto[146] = (unsigned short )0;
    sqlstm.sqtdso[146] = (unsigned short )0;
    sqlstm.sqhstv[147] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_24);
    sqlstm.sqhstl[147] = (unsigned int  )31;
    sqlstm.sqhsts[147] = (         int  )0;
    sqlstm.sqindv[147] = (         void  *)0;
    sqlstm.sqinds[147] = (         int  )0;
    sqlstm.sqharm[147] = (unsigned int  )0;
    sqlstm.sqadto[147] = (unsigned short )0;
    sqlstm.sqtdso[147] = (unsigned short )0;
    sqlstm.sqhstv[148] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_25);
    sqlstm.sqhstl[148] = (unsigned int  )31;
    sqlstm.sqhsts[148] = (         int  )0;
    sqlstm.sqindv[148] = (         void  *)0;
    sqlstm.sqinds[148] = (         int  )0;
    sqlstm.sqharm[148] = (unsigned int  )0;
    sqlstm.sqadto[148] = (unsigned short )0;
    sqlstm.sqtdso[148] = (unsigned short )0;
    sqlstm.sqhstv[149] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_26);
    sqlstm.sqhstl[149] = (unsigned int  )31;
    sqlstm.sqhsts[149] = (         int  )0;
    sqlstm.sqindv[149] = (         void  *)0;
    sqlstm.sqinds[149] = (         int  )0;
    sqlstm.sqharm[149] = (unsigned int  )0;
    sqlstm.sqadto[149] = (unsigned short )0;
    sqlstm.sqtdso[149] = (unsigned short )0;
    sqlstm.sqhstv[150] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_27);
    sqlstm.sqhstl[150] = (unsigned int  )31;
    sqlstm.sqhsts[150] = (         int  )0;
    sqlstm.sqindv[150] = (         void  *)0;
    sqlstm.sqinds[150] = (         int  )0;
    sqlstm.sqharm[150] = (unsigned int  )0;
    sqlstm.sqadto[150] = (unsigned short )0;
    sqlstm.sqtdso[150] = (unsigned short )0;
    sqlstm.sqhstv[151] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_28);
    sqlstm.sqhstl[151] = (unsigned int  )31;
    sqlstm.sqhsts[151] = (         int  )0;
    sqlstm.sqindv[151] = (         void  *)0;
    sqlstm.sqinds[151] = (         int  )0;
    sqlstm.sqharm[151] = (unsigned int  )0;
    sqlstm.sqadto[151] = (unsigned short )0;
    sqlstm.sqtdso[151] = (unsigned short )0;
    sqlstm.sqhstv[152] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_29);
    sqlstm.sqhstl[152] = (unsigned int  )31;
    sqlstm.sqhsts[152] = (         int  )0;
    sqlstm.sqindv[152] = (         void  *)0;
    sqlstm.sqinds[152] = (         int  )0;
    sqlstm.sqharm[152] = (unsigned int  )0;
    sqlstm.sqadto[152] = (unsigned short )0;
    sqlstm.sqtdso[152] = (unsigned short )0;
    sqlstm.sqhstv[153] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_30);
    sqlstm.sqhstl[153] = (unsigned int  )31;
    sqlstm.sqhsts[153] = (         int  )0;
    sqlstm.sqindv[153] = (         void  *)0;
    sqlstm.sqinds[153] = (         int  )0;
    sqlstm.sqharm[153] = (unsigned int  )0;
    sqlstm.sqadto[153] = (unsigned short )0;
    sqlstm.sqtdso[153] = (unsigned short )0;
    sqlstm.sqhstv[154] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_1);
    sqlstm.sqhstl[154] = (unsigned int  )2;
    sqlstm.sqhsts[154] = (         int  )0;
    sqlstm.sqindv[154] = (         void  *)0;
    sqlstm.sqinds[154] = (         int  )0;
    sqlstm.sqharm[154] = (unsigned int  )0;
    sqlstm.sqadto[154] = (unsigned short )0;
    sqlstm.sqtdso[154] = (unsigned short )0;
    sqlstm.sqhstv[155] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_2);
    sqlstm.sqhstl[155] = (unsigned int  )2;
    sqlstm.sqhsts[155] = (         int  )0;
    sqlstm.sqindv[155] = (         void  *)0;
    sqlstm.sqinds[155] = (         int  )0;
    sqlstm.sqharm[155] = (unsigned int  )0;
    sqlstm.sqadto[155] = (unsigned short )0;
    sqlstm.sqtdso[155] = (unsigned short )0;
    sqlstm.sqhstv[156] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_3);
    sqlstm.sqhstl[156] = (unsigned int  )2;
    sqlstm.sqhsts[156] = (         int  )0;
    sqlstm.sqindv[156] = (         void  *)0;
    sqlstm.sqinds[156] = (         int  )0;
    sqlstm.sqharm[156] = (unsigned int  )0;
    sqlstm.sqadto[156] = (unsigned short )0;
    sqlstm.sqtdso[156] = (unsigned short )0;
    sqlstm.sqhstv[157] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_4);
    sqlstm.sqhstl[157] = (unsigned int  )2;
    sqlstm.sqhsts[157] = (         int  )0;
    sqlstm.sqindv[157] = (         void  *)0;
    sqlstm.sqinds[157] = (         int  )0;
    sqlstm.sqharm[157] = (unsigned int  )0;
    sqlstm.sqadto[157] = (unsigned short )0;
    sqlstm.sqtdso[157] = (unsigned short )0;
    sqlstm.sqhstv[158] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_5);
    sqlstm.sqhstl[158] = (unsigned int  )2;
    sqlstm.sqhsts[158] = (         int  )0;
    sqlstm.sqindv[158] = (         void  *)0;
    sqlstm.sqinds[158] = (         int  )0;
    sqlstm.sqharm[158] = (unsigned int  )0;
    sqlstm.sqadto[158] = (unsigned short )0;
    sqlstm.sqtdso[158] = (unsigned short )0;
    sqlstm.sqhstv[159] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_6);
    sqlstm.sqhstl[159] = (unsigned int  )2;
    sqlstm.sqhsts[159] = (         int  )0;
    sqlstm.sqindv[159] = (         void  *)0;
    sqlstm.sqinds[159] = (         int  )0;
    sqlstm.sqharm[159] = (unsigned int  )0;
    sqlstm.sqadto[159] = (unsigned short )0;
    sqlstm.sqtdso[159] = (unsigned short )0;
    sqlstm.sqhstv[160] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_7);
    sqlstm.sqhstl[160] = (unsigned int  )2;
    sqlstm.sqhsts[160] = (         int  )0;
    sqlstm.sqindv[160] = (         void  *)0;
    sqlstm.sqinds[160] = (         int  )0;
    sqlstm.sqharm[160] = (unsigned int  )0;
    sqlstm.sqadto[160] = (unsigned short )0;
    sqlstm.sqtdso[160] = (unsigned short )0;
    sqlstm.sqhstv[161] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_8);
    sqlstm.sqhstl[161] = (unsigned int  )2;
    sqlstm.sqhsts[161] = (         int  )0;
    sqlstm.sqindv[161] = (         void  *)0;
    sqlstm.sqinds[161] = (         int  )0;
    sqlstm.sqharm[161] = (unsigned int  )0;
    sqlstm.sqadto[161] = (unsigned short )0;
    sqlstm.sqtdso[161] = (unsigned short )0;
    sqlstm.sqhstv[162] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_9);
    sqlstm.sqhstl[162] = (unsigned int  )2;
    sqlstm.sqhsts[162] = (         int  )0;
    sqlstm.sqindv[162] = (         void  *)0;
    sqlstm.sqinds[162] = (         int  )0;
    sqlstm.sqharm[162] = (unsigned int  )0;
    sqlstm.sqadto[162] = (unsigned short )0;
    sqlstm.sqtdso[162] = (unsigned short )0;
    sqlstm.sqhstv[163] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_10);
    sqlstm.sqhstl[163] = (unsigned int  )2;
    sqlstm.sqhsts[163] = (         int  )0;
    sqlstm.sqindv[163] = (         void  *)0;
    sqlstm.sqinds[163] = (         int  )0;
    sqlstm.sqharm[163] = (unsigned int  )0;
    sqlstm.sqadto[163] = (unsigned short )0;
    sqlstm.sqtdso[163] = (unsigned short )0;
    sqlstm.sqhstv[164] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_11);
    sqlstm.sqhstl[164] = (unsigned int  )2;
    sqlstm.sqhsts[164] = (         int  )0;
    sqlstm.sqindv[164] = (         void  *)0;
    sqlstm.sqinds[164] = (         int  )0;
    sqlstm.sqharm[164] = (unsigned int  )0;
    sqlstm.sqadto[164] = (unsigned short )0;
    sqlstm.sqtdso[164] = (unsigned short )0;
    sqlstm.sqhstv[165] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_12);
    sqlstm.sqhstl[165] = (unsigned int  )2;
    sqlstm.sqhsts[165] = (         int  )0;
    sqlstm.sqindv[165] = (         void  *)0;
    sqlstm.sqinds[165] = (         int  )0;
    sqlstm.sqharm[165] = (unsigned int  )0;
    sqlstm.sqadto[165] = (unsigned short )0;
    sqlstm.sqtdso[165] = (unsigned short )0;
    sqlstm.sqhstv[166] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_13);
    sqlstm.sqhstl[166] = (unsigned int  )2;
    sqlstm.sqhsts[166] = (         int  )0;
    sqlstm.sqindv[166] = (         void  *)0;
    sqlstm.sqinds[166] = (         int  )0;
    sqlstm.sqharm[166] = (unsigned int  )0;
    sqlstm.sqadto[166] = (unsigned short )0;
    sqlstm.sqtdso[166] = (unsigned short )0;
    sqlstm.sqhstv[167] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_14);
    sqlstm.sqhstl[167] = (unsigned int  )2;
    sqlstm.sqhsts[167] = (         int  )0;
    sqlstm.sqindv[167] = (         void  *)0;
    sqlstm.sqinds[167] = (         int  )0;
    sqlstm.sqharm[167] = (unsigned int  )0;
    sqlstm.sqadto[167] = (unsigned short )0;
    sqlstm.sqtdso[167] = (unsigned short )0;
    sqlstm.sqhstv[168] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_15);
    sqlstm.sqhstl[168] = (unsigned int  )2;
    sqlstm.sqhsts[168] = (         int  )0;
    sqlstm.sqindv[168] = (         void  *)0;
    sqlstm.sqinds[168] = (         int  )0;
    sqlstm.sqharm[168] = (unsigned int  )0;
    sqlstm.sqadto[168] = (unsigned short )0;
    sqlstm.sqtdso[168] = (unsigned short )0;
    sqlstm.sqhstv[169] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_16);
    sqlstm.sqhstl[169] = (unsigned int  )2;
    sqlstm.sqhsts[169] = (         int  )0;
    sqlstm.sqindv[169] = (         void  *)0;
    sqlstm.sqinds[169] = (         int  )0;
    sqlstm.sqharm[169] = (unsigned int  )0;
    sqlstm.sqadto[169] = (unsigned short )0;
    sqlstm.sqtdso[169] = (unsigned short )0;
    sqlstm.sqhstv[170] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_17);
    sqlstm.sqhstl[170] = (unsigned int  )2;
    sqlstm.sqhsts[170] = (         int  )0;
    sqlstm.sqindv[170] = (         void  *)0;
    sqlstm.sqinds[170] = (         int  )0;
    sqlstm.sqharm[170] = (unsigned int  )0;
    sqlstm.sqadto[170] = (unsigned short )0;
    sqlstm.sqtdso[170] = (unsigned short )0;
    sqlstm.sqhstv[171] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_18);
    sqlstm.sqhstl[171] = (unsigned int  )2;
    sqlstm.sqhsts[171] = (         int  )0;
    sqlstm.sqindv[171] = (         void  *)0;
    sqlstm.sqinds[171] = (         int  )0;
    sqlstm.sqharm[171] = (unsigned int  )0;
    sqlstm.sqadto[171] = (unsigned short )0;
    sqlstm.sqtdso[171] = (unsigned short )0;
    sqlstm.sqhstv[172] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_19);
    sqlstm.sqhstl[172] = (unsigned int  )2;
    sqlstm.sqhsts[172] = (         int  )0;
    sqlstm.sqindv[172] = (         void  *)0;
    sqlstm.sqinds[172] = (         int  )0;
    sqlstm.sqharm[172] = (unsigned int  )0;
    sqlstm.sqadto[172] = (unsigned short )0;
    sqlstm.sqtdso[172] = (unsigned short )0;
    sqlstm.sqhstv[173] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_20);
    sqlstm.sqhstl[173] = (unsigned int  )2;
    sqlstm.sqhsts[173] = (         int  )0;
    sqlstm.sqindv[173] = (         void  *)0;
    sqlstm.sqinds[173] = (         int  )0;
    sqlstm.sqharm[173] = (unsigned int  )0;
    sqlstm.sqadto[173] = (unsigned short )0;
    sqlstm.sqtdso[173] = (unsigned short )0;
    sqlstm.sqhstv[174] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_21);
    sqlstm.sqhstl[174] = (unsigned int  )2;
    sqlstm.sqhsts[174] = (         int  )0;
    sqlstm.sqindv[174] = (         void  *)0;
    sqlstm.sqinds[174] = (         int  )0;
    sqlstm.sqharm[174] = (unsigned int  )0;
    sqlstm.sqadto[174] = (unsigned short )0;
    sqlstm.sqtdso[174] = (unsigned short )0;
    sqlstm.sqhstv[175] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_22);
    sqlstm.sqhstl[175] = (unsigned int  )2;
    sqlstm.sqhsts[175] = (         int  )0;
    sqlstm.sqindv[175] = (         void  *)0;
    sqlstm.sqinds[175] = (         int  )0;
    sqlstm.sqharm[175] = (unsigned int  )0;
    sqlstm.sqadto[175] = (unsigned short )0;
    sqlstm.sqtdso[175] = (unsigned short )0;
    sqlstm.sqhstv[176] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_23);
    sqlstm.sqhstl[176] = (unsigned int  )2;
    sqlstm.sqhsts[176] = (         int  )0;
    sqlstm.sqindv[176] = (         void  *)0;
    sqlstm.sqinds[176] = (         int  )0;
    sqlstm.sqharm[176] = (unsigned int  )0;
    sqlstm.sqadto[176] = (unsigned short )0;
    sqlstm.sqtdso[176] = (unsigned short )0;
    sqlstm.sqhstv[177] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_24);
    sqlstm.sqhstl[177] = (unsigned int  )2;
    sqlstm.sqhsts[177] = (         int  )0;
    sqlstm.sqindv[177] = (         void  *)0;
    sqlstm.sqinds[177] = (         int  )0;
    sqlstm.sqharm[177] = (unsigned int  )0;
    sqlstm.sqadto[177] = (unsigned short )0;
    sqlstm.sqtdso[177] = (unsigned short )0;
    sqlstm.sqhstv[178] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_25);
    sqlstm.sqhstl[178] = (unsigned int  )2;
    sqlstm.sqhsts[178] = (         int  )0;
    sqlstm.sqindv[178] = (         void  *)0;
    sqlstm.sqinds[178] = (         int  )0;
    sqlstm.sqharm[178] = (unsigned int  )0;
    sqlstm.sqadto[178] = (unsigned short )0;
    sqlstm.sqtdso[178] = (unsigned short )0;
    sqlstm.sqhstv[179] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_26);
    sqlstm.sqhstl[179] = (unsigned int  )2;
    sqlstm.sqhsts[179] = (         int  )0;
    sqlstm.sqindv[179] = (         void  *)0;
    sqlstm.sqinds[179] = (         int  )0;
    sqlstm.sqharm[179] = (unsigned int  )0;
    sqlstm.sqadto[179] = (unsigned short )0;
    sqlstm.sqtdso[179] = (unsigned short )0;
    sqlstm.sqhstv[180] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_27);
    sqlstm.sqhstl[180] = (unsigned int  )2;
    sqlstm.sqhsts[180] = (         int  )0;
    sqlstm.sqindv[180] = (         void  *)0;
    sqlstm.sqinds[180] = (         int  )0;
    sqlstm.sqharm[180] = (unsigned int  )0;
    sqlstm.sqadto[180] = (unsigned short )0;
    sqlstm.sqtdso[180] = (unsigned short )0;
    sqlstm.sqhstv[181] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_28);
    sqlstm.sqhstl[181] = (unsigned int  )2;
    sqlstm.sqhsts[181] = (         int  )0;
    sqlstm.sqindv[181] = (         void  *)0;
    sqlstm.sqinds[181] = (         int  )0;
    sqlstm.sqharm[181] = (unsigned int  )0;
    sqlstm.sqadto[181] = (unsigned short )0;
    sqlstm.sqtdso[181] = (unsigned short )0;
    sqlstm.sqhstv[182] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_29);
    sqlstm.sqhstl[182] = (unsigned int  )2;
    sqlstm.sqhsts[182] = (         int  )0;
    sqlstm.sqindv[182] = (         void  *)0;
    sqlstm.sqinds[182] = (         int  )0;
    sqlstm.sqharm[182] = (unsigned int  )0;
    sqlstm.sqadto[182] = (unsigned short )0;
    sqlstm.sqtdso[182] = (unsigned short )0;
    sqlstm.sqhstv[183] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_30);
    sqlstm.sqhstl[183] = (unsigned int  )2;
    sqlstm.sqhsts[183] = (         int  )0;
    sqlstm.sqindv[183] = (         void  *)0;
    sqlstm.sqinds[183] = (         int  )0;
    sqlstm.sqharm[183] = (unsigned int  )0;
    sqlstm.sqadto[183] = (unsigned short )0;
    sqlstm.sqtdso[183] = (unsigned short )0;
    sqlstm.sqhstv[184] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_1);
    sqlstm.sqhstl[184] = (unsigned int  )31;
    sqlstm.sqhsts[184] = (         int  )0;
    sqlstm.sqindv[184] = (         void  *)0;
    sqlstm.sqinds[184] = (         int  )0;
    sqlstm.sqharm[184] = (unsigned int  )0;
    sqlstm.sqadto[184] = (unsigned short )0;
    sqlstm.sqtdso[184] = (unsigned short )0;
    sqlstm.sqhstv[185] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_2);
    sqlstm.sqhstl[185] = (unsigned int  )31;
    sqlstm.sqhsts[185] = (         int  )0;
    sqlstm.sqindv[185] = (         void  *)0;
    sqlstm.sqinds[185] = (         int  )0;
    sqlstm.sqharm[185] = (unsigned int  )0;
    sqlstm.sqadto[185] = (unsigned short )0;
    sqlstm.sqtdso[185] = (unsigned short )0;
    sqlstm.sqhstv[186] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_3);
    sqlstm.sqhstl[186] = (unsigned int  )31;
    sqlstm.sqhsts[186] = (         int  )0;
    sqlstm.sqindv[186] = (         void  *)0;
    sqlstm.sqinds[186] = (         int  )0;
    sqlstm.sqharm[186] = (unsigned int  )0;
    sqlstm.sqadto[186] = (unsigned short )0;
    sqlstm.sqtdso[186] = (unsigned short )0;
    sqlstm.sqhstv[187] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_4);
    sqlstm.sqhstl[187] = (unsigned int  )31;
    sqlstm.sqhsts[187] = (         int  )0;
    sqlstm.sqindv[187] = (         void  *)0;
    sqlstm.sqinds[187] = (         int  )0;
    sqlstm.sqharm[187] = (unsigned int  )0;
    sqlstm.sqadto[187] = (unsigned short )0;
    sqlstm.sqtdso[187] = (unsigned short )0;
    sqlstm.sqhstv[188] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_5);
    sqlstm.sqhstl[188] = (unsigned int  )31;
    sqlstm.sqhsts[188] = (         int  )0;
    sqlstm.sqindv[188] = (         void  *)0;
    sqlstm.sqinds[188] = (         int  )0;
    sqlstm.sqharm[188] = (unsigned int  )0;
    sqlstm.sqadto[188] = (unsigned short )0;
    sqlstm.sqtdso[188] = (unsigned short )0;
    sqlstm.sqhstv[189] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_6);
    sqlstm.sqhstl[189] = (unsigned int  )31;
    sqlstm.sqhsts[189] = (         int  )0;
    sqlstm.sqindv[189] = (         void  *)0;
    sqlstm.sqinds[189] = (         int  )0;
    sqlstm.sqharm[189] = (unsigned int  )0;
    sqlstm.sqadto[189] = (unsigned short )0;
    sqlstm.sqtdso[189] = (unsigned short )0;
    sqlstm.sqhstv[190] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_7);
    sqlstm.sqhstl[190] = (unsigned int  )31;
    sqlstm.sqhsts[190] = (         int  )0;
    sqlstm.sqindv[190] = (         void  *)0;
    sqlstm.sqinds[190] = (         int  )0;
    sqlstm.sqharm[190] = (unsigned int  )0;
    sqlstm.sqadto[190] = (unsigned short )0;
    sqlstm.sqtdso[190] = (unsigned short )0;
    sqlstm.sqhstv[191] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_8);
    sqlstm.sqhstl[191] = (unsigned int  )31;
    sqlstm.sqhsts[191] = (         int  )0;
    sqlstm.sqindv[191] = (         void  *)0;
    sqlstm.sqinds[191] = (         int  )0;
    sqlstm.sqharm[191] = (unsigned int  )0;
    sqlstm.sqadto[191] = (unsigned short )0;
    sqlstm.sqtdso[191] = (unsigned short )0;
    sqlstm.sqhstv[192] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_9);
    sqlstm.sqhstl[192] = (unsigned int  )31;
    sqlstm.sqhsts[192] = (         int  )0;
    sqlstm.sqindv[192] = (         void  *)0;
    sqlstm.sqinds[192] = (         int  )0;
    sqlstm.sqharm[192] = (unsigned int  )0;
    sqlstm.sqadto[192] = (unsigned short )0;
    sqlstm.sqtdso[192] = (unsigned short )0;
    sqlstm.sqhstv[193] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_10);
    sqlstm.sqhstl[193] = (unsigned int  )31;
    sqlstm.sqhsts[193] = (         int  )0;
    sqlstm.sqindv[193] = (         void  *)0;
    sqlstm.sqinds[193] = (         int  )0;
    sqlstm.sqharm[193] = (unsigned int  )0;
    sqlstm.sqadto[193] = (unsigned short )0;
    sqlstm.sqtdso[193] = (unsigned short )0;
    sqlstm.sqhstv[194] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_11);
    sqlstm.sqhstl[194] = (unsigned int  )31;
    sqlstm.sqhsts[194] = (         int  )0;
    sqlstm.sqindv[194] = (         void  *)0;
    sqlstm.sqinds[194] = (         int  )0;
    sqlstm.sqharm[194] = (unsigned int  )0;
    sqlstm.sqadto[194] = (unsigned short )0;
    sqlstm.sqtdso[194] = (unsigned short )0;
    sqlstm.sqhstv[195] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_12);
    sqlstm.sqhstl[195] = (unsigned int  )31;
    sqlstm.sqhsts[195] = (         int  )0;
    sqlstm.sqindv[195] = (         void  *)0;
    sqlstm.sqinds[195] = (         int  )0;
    sqlstm.sqharm[195] = (unsigned int  )0;
    sqlstm.sqadto[195] = (unsigned short )0;
    sqlstm.sqtdso[195] = (unsigned short )0;
    sqlstm.sqhstv[196] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_13);
    sqlstm.sqhstl[196] = (unsigned int  )31;
    sqlstm.sqhsts[196] = (         int  )0;
    sqlstm.sqindv[196] = (         void  *)0;
    sqlstm.sqinds[196] = (         int  )0;
    sqlstm.sqharm[196] = (unsigned int  )0;
    sqlstm.sqadto[196] = (unsigned short )0;
    sqlstm.sqtdso[196] = (unsigned short )0;
    sqlstm.sqhstv[197] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_14);
    sqlstm.sqhstl[197] = (unsigned int  )31;
    sqlstm.sqhsts[197] = (         int  )0;
    sqlstm.sqindv[197] = (         void  *)0;
    sqlstm.sqinds[197] = (         int  )0;
    sqlstm.sqharm[197] = (unsigned int  )0;
    sqlstm.sqadto[197] = (unsigned short )0;
    sqlstm.sqtdso[197] = (unsigned short )0;
    sqlstm.sqhstv[198] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_15);
    sqlstm.sqhstl[198] = (unsigned int  )31;
    sqlstm.sqhsts[198] = (         int  )0;
    sqlstm.sqindv[198] = (         void  *)0;
    sqlstm.sqinds[198] = (         int  )0;
    sqlstm.sqharm[198] = (unsigned int  )0;
    sqlstm.sqadto[198] = (unsigned short )0;
    sqlstm.sqtdso[198] = (unsigned short )0;
    sqlstm.sqhstv[199] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_16);
    sqlstm.sqhstl[199] = (unsigned int  )31;
    sqlstm.sqhsts[199] = (         int  )0;
    sqlstm.sqindv[199] = (         void  *)0;
    sqlstm.sqinds[199] = (         int  )0;
    sqlstm.sqharm[199] = (unsigned int  )0;
    sqlstm.sqadto[199] = (unsigned short )0;
    sqlstm.sqtdso[199] = (unsigned short )0;
    sqlstm.sqhstv[200] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_17);
    sqlstm.sqhstl[200] = (unsigned int  )31;
    sqlstm.sqhsts[200] = (         int  )0;
    sqlstm.sqindv[200] = (         void  *)0;
    sqlstm.sqinds[200] = (         int  )0;
    sqlstm.sqharm[200] = (unsigned int  )0;
    sqlstm.sqadto[200] = (unsigned short )0;
    sqlstm.sqtdso[200] = (unsigned short )0;
    sqlstm.sqhstv[201] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_18);
    sqlstm.sqhstl[201] = (unsigned int  )31;
    sqlstm.sqhsts[201] = (         int  )0;
    sqlstm.sqindv[201] = (         void  *)0;
    sqlstm.sqinds[201] = (         int  )0;
    sqlstm.sqharm[201] = (unsigned int  )0;
    sqlstm.sqadto[201] = (unsigned short )0;
    sqlstm.sqtdso[201] = (unsigned short )0;
    sqlstm.sqhstv[202] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_19);
    sqlstm.sqhstl[202] = (unsigned int  )31;
    sqlstm.sqhsts[202] = (         int  )0;
    sqlstm.sqindv[202] = (         void  *)0;
    sqlstm.sqinds[202] = (         int  )0;
    sqlstm.sqharm[202] = (unsigned int  )0;
    sqlstm.sqadto[202] = (unsigned short )0;
    sqlstm.sqtdso[202] = (unsigned short )0;
    sqlstm.sqhstv[203] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_20);
    sqlstm.sqhstl[203] = (unsigned int  )31;
    sqlstm.sqhsts[203] = (         int  )0;
    sqlstm.sqindv[203] = (         void  *)0;
    sqlstm.sqinds[203] = (         int  )0;
    sqlstm.sqharm[203] = (unsigned int  )0;
    sqlstm.sqadto[203] = (unsigned short )0;
    sqlstm.sqtdso[203] = (unsigned short )0;
    sqlstm.sqhstv[204] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_21);
    sqlstm.sqhstl[204] = (unsigned int  )31;
    sqlstm.sqhsts[204] = (         int  )0;
    sqlstm.sqindv[204] = (         void  *)0;
    sqlstm.sqinds[204] = (         int  )0;
    sqlstm.sqharm[204] = (unsigned int  )0;
    sqlstm.sqadto[204] = (unsigned short )0;
    sqlstm.sqtdso[204] = (unsigned short )0;
    sqlstm.sqhstv[205] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_22);
    sqlstm.sqhstl[205] = (unsigned int  )31;
    sqlstm.sqhsts[205] = (         int  )0;
    sqlstm.sqindv[205] = (         void  *)0;
    sqlstm.sqinds[205] = (         int  )0;
    sqlstm.sqharm[205] = (unsigned int  )0;
    sqlstm.sqadto[205] = (unsigned short )0;
    sqlstm.sqtdso[205] = (unsigned short )0;
    sqlstm.sqhstv[206] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_23);
    sqlstm.sqhstl[206] = (unsigned int  )31;
    sqlstm.sqhsts[206] = (         int  )0;
    sqlstm.sqindv[206] = (         void  *)0;
    sqlstm.sqinds[206] = (         int  )0;
    sqlstm.sqharm[206] = (unsigned int  )0;
    sqlstm.sqadto[206] = (unsigned short )0;
    sqlstm.sqtdso[206] = (unsigned short )0;
    sqlstm.sqhstv[207] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_24);
    sqlstm.sqhstl[207] = (unsigned int  )31;
    sqlstm.sqhsts[207] = (         int  )0;
    sqlstm.sqindv[207] = (         void  *)0;
    sqlstm.sqinds[207] = (         int  )0;
    sqlstm.sqharm[207] = (unsigned int  )0;
    sqlstm.sqadto[207] = (unsigned short )0;
    sqlstm.sqtdso[207] = (unsigned short )0;
    sqlstm.sqhstv[208] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_25);
    sqlstm.sqhstl[208] = (unsigned int  )31;
    sqlstm.sqhsts[208] = (         int  )0;
    sqlstm.sqindv[208] = (         void  *)0;
    sqlstm.sqinds[208] = (         int  )0;
    sqlstm.sqharm[208] = (unsigned int  )0;
    sqlstm.sqadto[208] = (unsigned short )0;
    sqlstm.sqtdso[208] = (unsigned short )0;
    sqlstm.sqhstv[209] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_26);
    sqlstm.sqhstl[209] = (unsigned int  )31;
    sqlstm.sqhsts[209] = (         int  )0;
    sqlstm.sqindv[209] = (         void  *)0;
    sqlstm.sqinds[209] = (         int  )0;
    sqlstm.sqharm[209] = (unsigned int  )0;
    sqlstm.sqadto[209] = (unsigned short )0;
    sqlstm.sqtdso[209] = (unsigned short )0;
    sqlstm.sqhstv[210] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_27);
    sqlstm.sqhstl[210] = (unsigned int  )31;
    sqlstm.sqhsts[210] = (         int  )0;
    sqlstm.sqindv[210] = (         void  *)0;
    sqlstm.sqinds[210] = (         int  )0;
    sqlstm.sqharm[210] = (unsigned int  )0;
    sqlstm.sqadto[210] = (unsigned short )0;
    sqlstm.sqtdso[210] = (unsigned short )0;
    sqlstm.sqhstv[211] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_28);
    sqlstm.sqhstl[211] = (unsigned int  )31;
    sqlstm.sqhsts[211] = (         int  )0;
    sqlstm.sqindv[211] = (         void  *)0;
    sqlstm.sqinds[211] = (         int  )0;
    sqlstm.sqharm[211] = (unsigned int  )0;
    sqlstm.sqadto[211] = (unsigned short )0;
    sqlstm.sqtdso[211] = (unsigned short )0;
    sqlstm.sqhstv[212] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_29);
    sqlstm.sqhstl[212] = (unsigned int  )31;
    sqlstm.sqhsts[212] = (         int  )0;
    sqlstm.sqindv[212] = (         void  *)0;
    sqlstm.sqinds[212] = (         int  )0;
    sqlstm.sqharm[212] = (unsigned int  )0;
    sqlstm.sqadto[212] = (unsigned short )0;
    sqlstm.sqtdso[212] = (unsigned short )0;
    sqlstm.sqhstv[213] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_30);
    sqlstm.sqhstl[213] = (unsigned int  )31;
    sqlstm.sqhsts[213] = (         int  )0;
    sqlstm.sqindv[213] = (         void  *)0;
    sqlstm.sqinds[213] = (         int  )0;
    sqlstm.sqharm[213] = (unsigned int  )0;
    sqlstm.sqadto[213] = (unsigned short )0;
    sqlstm.sqtdso[213] = (unsigned short )0;
    sqlstm.sqhstv[214] = (         void  *)(MRASCEVDEF_N.CHG_OPT_1);
    sqlstm.sqhstl[214] = (unsigned int  )2;
    sqlstm.sqhsts[214] = (         int  )0;
    sqlstm.sqindv[214] = (         void  *)0;
    sqlstm.sqinds[214] = (         int  )0;
    sqlstm.sqharm[214] = (unsigned int  )0;
    sqlstm.sqadto[214] = (unsigned short )0;
    sqlstm.sqtdso[214] = (unsigned short )0;
    sqlstm.sqhstv[215] = (         void  *)(MRASCEVDEF_N.CHG_OPT_2);
    sqlstm.sqhstl[215] = (unsigned int  )2;
    sqlstm.sqhsts[215] = (         int  )0;
    sqlstm.sqindv[215] = (         void  *)0;
    sqlstm.sqinds[215] = (         int  )0;
    sqlstm.sqharm[215] = (unsigned int  )0;
    sqlstm.sqadto[215] = (unsigned short )0;
    sqlstm.sqtdso[215] = (unsigned short )0;
    sqlstm.sqhstv[216] = (         void  *)(MRASCEVDEF_N.CHG_OPT_3);
    sqlstm.sqhstl[216] = (unsigned int  )2;
    sqlstm.sqhsts[216] = (         int  )0;
    sqlstm.sqindv[216] = (         void  *)0;
    sqlstm.sqinds[216] = (         int  )0;
    sqlstm.sqharm[216] = (unsigned int  )0;
    sqlstm.sqadto[216] = (unsigned short )0;
    sqlstm.sqtdso[216] = (unsigned short )0;
    sqlstm.sqhstv[217] = (         void  *)(MRASCEVDEF_N.CHG_OPT_4);
    sqlstm.sqhstl[217] = (unsigned int  )2;
    sqlstm.sqhsts[217] = (         int  )0;
    sqlstm.sqindv[217] = (         void  *)0;
    sqlstm.sqinds[217] = (         int  )0;
    sqlstm.sqharm[217] = (unsigned int  )0;
    sqlstm.sqadto[217] = (unsigned short )0;
    sqlstm.sqtdso[217] = (unsigned short )0;
    sqlstm.sqhstv[218] = (         void  *)(MRASCEVDEF_N.CHG_OPT_5);
    sqlstm.sqhstl[218] = (unsigned int  )2;
    sqlstm.sqhsts[218] = (         int  )0;
    sqlstm.sqindv[218] = (         void  *)0;
    sqlstm.sqinds[218] = (         int  )0;
    sqlstm.sqharm[218] = (unsigned int  )0;
    sqlstm.sqadto[218] = (unsigned short )0;
    sqlstm.sqtdso[218] = (unsigned short )0;
    sqlstm.sqhstv[219] = (         void  *)(MRASCEVDEF_N.CHG_OPT_6);
    sqlstm.sqhstl[219] = (unsigned int  )2;
    sqlstm.sqhsts[219] = (         int  )0;
    sqlstm.sqindv[219] = (         void  *)0;
    sqlstm.sqinds[219] = (         int  )0;
    sqlstm.sqharm[219] = (unsigned int  )0;
    sqlstm.sqadto[219] = (unsigned short )0;
    sqlstm.sqtdso[219] = (unsigned short )0;
    sqlstm.sqhstv[220] = (         void  *)(MRASCEVDEF_N.CHG_OPT_7);
    sqlstm.sqhstl[220] = (unsigned int  )2;
    sqlstm.sqhsts[220] = (         int  )0;
    sqlstm.sqindv[220] = (         void  *)0;
    sqlstm.sqinds[220] = (         int  )0;
    sqlstm.sqharm[220] = (unsigned int  )0;
    sqlstm.sqadto[220] = (unsigned short )0;
    sqlstm.sqtdso[220] = (unsigned short )0;
    sqlstm.sqhstv[221] = (         void  *)(MRASCEVDEF_N.CHG_OPT_8);
    sqlstm.sqhstl[221] = (unsigned int  )2;
    sqlstm.sqhsts[221] = (         int  )0;
    sqlstm.sqindv[221] = (         void  *)0;
    sqlstm.sqinds[221] = (         int  )0;
    sqlstm.sqharm[221] = (unsigned int  )0;
    sqlstm.sqadto[221] = (unsigned short )0;
    sqlstm.sqtdso[221] = (unsigned short )0;
    sqlstm.sqhstv[222] = (         void  *)(MRASCEVDEF_N.CHG_OPT_9);
    sqlstm.sqhstl[222] = (unsigned int  )2;
    sqlstm.sqhsts[222] = (         int  )0;
    sqlstm.sqindv[222] = (         void  *)0;
    sqlstm.sqinds[222] = (         int  )0;
    sqlstm.sqharm[222] = (unsigned int  )0;
    sqlstm.sqadto[222] = (unsigned short )0;
    sqlstm.sqtdso[222] = (unsigned short )0;
    sqlstm.sqhstv[223] = (         void  *)(MRASCEVDEF_N.CHG_OPT_10);
    sqlstm.sqhstl[223] = (unsigned int  )2;
    sqlstm.sqhsts[223] = (         int  )0;
    sqlstm.sqindv[223] = (         void  *)0;
    sqlstm.sqinds[223] = (         int  )0;
    sqlstm.sqharm[223] = (unsigned int  )0;
    sqlstm.sqadto[223] = (unsigned short )0;
    sqlstm.sqtdso[223] = (unsigned short )0;
    sqlstm.sqhstv[224] = (         void  *)(MRASCEVDEF_N.CHG_OPT_11);
    sqlstm.sqhstl[224] = (unsigned int  )2;
    sqlstm.sqhsts[224] = (         int  )0;
    sqlstm.sqindv[224] = (         void  *)0;
    sqlstm.sqinds[224] = (         int  )0;
    sqlstm.sqharm[224] = (unsigned int  )0;
    sqlstm.sqadto[224] = (unsigned short )0;
    sqlstm.sqtdso[224] = (unsigned short )0;
    sqlstm.sqhstv[225] = (         void  *)(MRASCEVDEF_N.CHG_OPT_12);
    sqlstm.sqhstl[225] = (unsigned int  )2;
    sqlstm.sqhsts[225] = (         int  )0;
    sqlstm.sqindv[225] = (         void  *)0;
    sqlstm.sqinds[225] = (         int  )0;
    sqlstm.sqharm[225] = (unsigned int  )0;
    sqlstm.sqadto[225] = (unsigned short )0;
    sqlstm.sqtdso[225] = (unsigned short )0;
    sqlstm.sqhstv[226] = (         void  *)(MRASCEVDEF_N.CHG_OPT_13);
    sqlstm.sqhstl[226] = (unsigned int  )2;
    sqlstm.sqhsts[226] = (         int  )0;
    sqlstm.sqindv[226] = (         void  *)0;
    sqlstm.sqinds[226] = (         int  )0;
    sqlstm.sqharm[226] = (unsigned int  )0;
    sqlstm.sqadto[226] = (unsigned short )0;
    sqlstm.sqtdso[226] = (unsigned short )0;
    sqlstm.sqhstv[227] = (         void  *)(MRASCEVDEF_N.CHG_OPT_14);
    sqlstm.sqhstl[227] = (unsigned int  )2;
    sqlstm.sqhsts[227] = (         int  )0;
    sqlstm.sqindv[227] = (         void  *)0;
    sqlstm.sqinds[227] = (         int  )0;
    sqlstm.sqharm[227] = (unsigned int  )0;
    sqlstm.sqadto[227] = (unsigned short )0;
    sqlstm.sqtdso[227] = (unsigned short )0;
    sqlstm.sqhstv[228] = (         void  *)(MRASCEVDEF_N.CHG_OPT_15);
    sqlstm.sqhstl[228] = (unsigned int  )2;
    sqlstm.sqhsts[228] = (         int  )0;
    sqlstm.sqindv[228] = (         void  *)0;
    sqlstm.sqinds[228] = (         int  )0;
    sqlstm.sqharm[228] = (unsigned int  )0;
    sqlstm.sqadto[228] = (unsigned short )0;
    sqlstm.sqtdso[228] = (unsigned short )0;
    sqlstm.sqhstv[229] = (         void  *)(MRASCEVDEF_N.CHG_OPT_16);
    sqlstm.sqhstl[229] = (unsigned int  )2;
    sqlstm.sqhsts[229] = (         int  )0;
    sqlstm.sqindv[229] = (         void  *)0;
    sqlstm.sqinds[229] = (         int  )0;
    sqlstm.sqharm[229] = (unsigned int  )0;
    sqlstm.sqadto[229] = (unsigned short )0;
    sqlstm.sqtdso[229] = (unsigned short )0;
    sqlstm.sqhstv[230] = (         void  *)(MRASCEVDEF_N.CHG_OPT_17);
    sqlstm.sqhstl[230] = (unsigned int  )2;
    sqlstm.sqhsts[230] = (         int  )0;
    sqlstm.sqindv[230] = (         void  *)0;
    sqlstm.sqinds[230] = (         int  )0;
    sqlstm.sqharm[230] = (unsigned int  )0;
    sqlstm.sqadto[230] = (unsigned short )0;
    sqlstm.sqtdso[230] = (unsigned short )0;
    sqlstm.sqhstv[231] = (         void  *)(MRASCEVDEF_N.CHG_OPT_18);
    sqlstm.sqhstl[231] = (unsigned int  )2;
    sqlstm.sqhsts[231] = (         int  )0;
    sqlstm.sqindv[231] = (         void  *)0;
    sqlstm.sqinds[231] = (         int  )0;
    sqlstm.sqharm[231] = (unsigned int  )0;
    sqlstm.sqadto[231] = (unsigned short )0;
    sqlstm.sqtdso[231] = (unsigned short )0;
    sqlstm.sqhstv[232] = (         void  *)(MRASCEVDEF_N.CHG_OPT_19);
    sqlstm.sqhstl[232] = (unsigned int  )2;
    sqlstm.sqhsts[232] = (         int  )0;
    sqlstm.sqindv[232] = (         void  *)0;
    sqlstm.sqinds[232] = (         int  )0;
    sqlstm.sqharm[232] = (unsigned int  )0;
    sqlstm.sqadto[232] = (unsigned short )0;
    sqlstm.sqtdso[232] = (unsigned short )0;
    sqlstm.sqhstv[233] = (         void  *)(MRASCEVDEF_N.CHG_OPT_20);
    sqlstm.sqhstl[233] = (unsigned int  )2;
    sqlstm.sqhsts[233] = (         int  )0;
    sqlstm.sqindv[233] = (         void  *)0;
    sqlstm.sqinds[233] = (         int  )0;
    sqlstm.sqharm[233] = (unsigned int  )0;
    sqlstm.sqadto[233] = (unsigned short )0;
    sqlstm.sqtdso[233] = (unsigned short )0;
    sqlstm.sqhstv[234] = (         void  *)(MRASCEVDEF_N.CHG_OPT_21);
    sqlstm.sqhstl[234] = (unsigned int  )2;
    sqlstm.sqhsts[234] = (         int  )0;
    sqlstm.sqindv[234] = (         void  *)0;
    sqlstm.sqinds[234] = (         int  )0;
    sqlstm.sqharm[234] = (unsigned int  )0;
    sqlstm.sqadto[234] = (unsigned short )0;
    sqlstm.sqtdso[234] = (unsigned short )0;
    sqlstm.sqhstv[235] = (         void  *)(MRASCEVDEF_N.CHG_OPT_22);
    sqlstm.sqhstl[235] = (unsigned int  )2;
    sqlstm.sqhsts[235] = (         int  )0;
    sqlstm.sqindv[235] = (         void  *)0;
    sqlstm.sqinds[235] = (         int  )0;
    sqlstm.sqharm[235] = (unsigned int  )0;
    sqlstm.sqadto[235] = (unsigned short )0;
    sqlstm.sqtdso[235] = (unsigned short )0;
    sqlstm.sqhstv[236] = (         void  *)(MRASCEVDEF_N.CHG_OPT_23);
    sqlstm.sqhstl[236] = (unsigned int  )2;
    sqlstm.sqhsts[236] = (         int  )0;
    sqlstm.sqindv[236] = (         void  *)0;
    sqlstm.sqinds[236] = (         int  )0;
    sqlstm.sqharm[236] = (unsigned int  )0;
    sqlstm.sqadto[236] = (unsigned short )0;
    sqlstm.sqtdso[236] = (unsigned short )0;
    sqlstm.sqhstv[237] = (         void  *)(MRASCEVDEF_N.CHG_OPT_24);
    sqlstm.sqhstl[237] = (unsigned int  )2;
    sqlstm.sqhsts[237] = (         int  )0;
    sqlstm.sqindv[237] = (         void  *)0;
    sqlstm.sqinds[237] = (         int  )0;
    sqlstm.sqharm[237] = (unsigned int  )0;
    sqlstm.sqadto[237] = (unsigned short )0;
    sqlstm.sqtdso[237] = (unsigned short )0;
    sqlstm.sqhstv[238] = (         void  *)(MRASCEVDEF_N.CHG_OPT_25);
    sqlstm.sqhstl[238] = (unsigned int  )2;
    sqlstm.sqhsts[238] = (         int  )0;
    sqlstm.sqindv[238] = (         void  *)0;
    sqlstm.sqinds[238] = (         int  )0;
    sqlstm.sqharm[238] = (unsigned int  )0;
    sqlstm.sqadto[238] = (unsigned short )0;
    sqlstm.sqtdso[238] = (unsigned short )0;
    sqlstm.sqhstv[239] = (         void  *)(MRASCEVDEF_N.CHG_OPT_26);
    sqlstm.sqhstl[239] = (unsigned int  )2;
    sqlstm.sqhsts[239] = (         int  )0;
    sqlstm.sqindv[239] = (         void  *)0;
    sqlstm.sqinds[239] = (         int  )0;
    sqlstm.sqharm[239] = (unsigned int  )0;
    sqlstm.sqadto[239] = (unsigned short )0;
    sqlstm.sqtdso[239] = (unsigned short )0;
    sqlstm.sqhstv[240] = (         void  *)(MRASCEVDEF_N.CHG_OPT_27);
    sqlstm.sqhstl[240] = (unsigned int  )2;
    sqlstm.sqhsts[240] = (         int  )0;
    sqlstm.sqindv[240] = (         void  *)0;
    sqlstm.sqinds[240] = (         int  )0;
    sqlstm.sqharm[240] = (unsigned int  )0;
    sqlstm.sqadto[240] = (unsigned short )0;
    sqlstm.sqtdso[240] = (unsigned short )0;
    sqlstm.sqhstv[241] = (         void  *)(MRASCEVDEF_N.CHG_OPT_28);
    sqlstm.sqhstl[241] = (unsigned int  )2;
    sqlstm.sqhsts[241] = (         int  )0;
    sqlstm.sqindv[241] = (         void  *)0;
    sqlstm.sqinds[241] = (         int  )0;
    sqlstm.sqharm[241] = (unsigned int  )0;
    sqlstm.sqadto[241] = (unsigned short )0;
    sqlstm.sqtdso[241] = (unsigned short )0;
    sqlstm.sqhstv[242] = (         void  *)(MRASCEVDEF_N.CHG_OPT_29);
    sqlstm.sqhstl[242] = (unsigned int  )2;
    sqlstm.sqhsts[242] = (         int  )0;
    sqlstm.sqindv[242] = (         void  *)0;
    sqlstm.sqinds[242] = (         int  )0;
    sqlstm.sqharm[242] = (unsigned int  )0;
    sqlstm.sqadto[242] = (unsigned short )0;
    sqlstm.sqtdso[242] = (unsigned short )0;
    sqlstm.sqhstv[243] = (         void  *)(MRASCEVDEF_N.CHG_OPT_30);
    sqlstm.sqhstl[243] = (unsigned int  )2;
    sqlstm.sqhsts[243] = (         int  )0;
    sqlstm.sqindv[243] = (         void  *)0;
    sqlstm.sqinds[243] = (         int  )0;
    sqlstm.sqharm[243] = (unsigned int  )0;
    sqlstm.sqadto[243] = (unsigned short )0;
    sqlstm.sqtdso[243] = (unsigned short )0;
    sqlstm.sqhstv[244] = (         void  *)(MRASCEVDEF_N.CREATE_USER_ID);
    sqlstm.sqhstl[244] = (unsigned int  )21;
    sqlstm.sqhsts[244] = (         int  )0;
    sqlstm.sqindv[244] = (         void  *)0;
    sqlstm.sqinds[244] = (         int  )0;
    sqlstm.sqharm[244] = (unsigned int  )0;
    sqlstm.sqadto[244] = (unsigned short )0;
    sqlstm.sqtdso[244] = (unsigned short )0;
    sqlstm.sqhstv[245] = (         void  *)(MRASCEVDEF_N.CREATE_TIME);
    sqlstm.sqhstl[245] = (unsigned int  )15;
    sqlstm.sqhsts[245] = (         int  )0;
    sqlstm.sqindv[245] = (         void  *)0;
    sqlstm.sqinds[245] = (         int  )0;
    sqlstm.sqharm[245] = (unsigned int  )0;
    sqlstm.sqadto[245] = (unsigned short )0;
    sqlstm.sqtdso[245] = (unsigned short )0;
    sqlstm.sqhstv[246] = (         void  *)(MRASCEVDEF_N.UPDATE_USER_ID);
    sqlstm.sqhstl[246] = (unsigned int  )21;
    sqlstm.sqhsts[246] = (         int  )0;
    sqlstm.sqindv[246] = (         void  *)0;
    sqlstm.sqinds[246] = (         int  )0;
    sqlstm.sqharm[246] = (unsigned int  )0;
    sqlstm.sqadto[246] = (unsigned short )0;
    sqlstm.sqtdso[246] = (unsigned short )0;
    sqlstm.sqhstv[247] = (         void  *)(MRASCEVDEF_N.UPDATE_TIME);
    sqlstm.sqhstl[247] = (unsigned int  )15;
    sqlstm.sqhsts[247] = (         int  )0;
    sqlstm.sqindv[247] = (         void  *)0;
    sqlstm.sqinds[247] = (         int  )0;
    sqlstm.sqharm[247] = (unsigned int  )0;
    sqlstm.sqadto[247] = (unsigned short )0;
    sqlstm.sqtdso[247] = (unsigned short )0;
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


    DB_stop_query_timer("DBC_insert_mrascevdef", 0);
}


/* SQL UPDATE Function */
void DBC_update_mrascevdef(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL UPDATE MRASCEVDEF SET
                    CRR_EVENT_DESC = :MRASCEVDEF_N.CRR_EVENT_DESC,
                    SYSTEM_FLAG = :MRASCEVDEF_N.SYSTEM_FLAG,
                    CHK_ITEM_1 = :MRASCEVDEF_N.CHK_ITEM_1,
                    CHK_ITEM_2 = :MRASCEVDEF_N.CHK_ITEM_2,
                    CHK_ITEM_3 = :MRASCEVDEF_N.CHK_ITEM_3,
                    CHK_ITEM_4 = :MRASCEVDEF_N.CHK_ITEM_4,
                    CHK_ITEM_5 = :MRASCEVDEF_N.CHK_ITEM_5,
                    CHK_ITEM_6 = :MRASCEVDEF_N.CHK_ITEM_6,
                    CHK_ITEM_7 = :MRASCEVDEF_N.CHK_ITEM_7,
                    CHK_ITEM_8 = :MRASCEVDEF_N.CHK_ITEM_8,
                    CHK_ITEM_9 = :MRASCEVDEF_N.CHK_ITEM_9,
                    CHK_ITEM_10 = :MRASCEVDEF_N.CHK_ITEM_10,
                    CHK_ITEM_11 = :MRASCEVDEF_N.CHK_ITEM_11,
                    CHK_ITEM_12 = :MRASCEVDEF_N.CHK_ITEM_12,
                    CHK_ITEM_13 = :MRASCEVDEF_N.CHK_ITEM_13,
                    CHK_ITEM_14 = :MRASCEVDEF_N.CHK_ITEM_14,
                    CHK_ITEM_15 = :MRASCEVDEF_N.CHK_ITEM_15,
                    CHK_ITEM_16 = :MRASCEVDEF_N.CHK_ITEM_16,
                    CHK_ITEM_17 = :MRASCEVDEF_N.CHK_ITEM_17,
                    CHK_ITEM_18 = :MRASCEVDEF_N.CHK_ITEM_18,
                    CHK_ITEM_19 = :MRASCEVDEF_N.CHK_ITEM_19,
                    CHK_ITEM_20 = :MRASCEVDEF_N.CHK_ITEM_20,
                    CHK_ITEM_21 = :MRASCEVDEF_N.CHK_ITEM_21,
                    CHK_ITEM_22 = :MRASCEVDEF_N.CHK_ITEM_22,
                    CHK_ITEM_23 = :MRASCEVDEF_N.CHK_ITEM_23,
                    CHK_ITEM_24 = :MRASCEVDEF_N.CHK_ITEM_24,
                    CHK_ITEM_25 = :MRASCEVDEF_N.CHK_ITEM_25,
                    CHK_ITEM_26 = :MRASCEVDEF_N.CHK_ITEM_26,
                    CHK_ITEM_27 = :MRASCEVDEF_N.CHK_ITEM_27,
                    CHK_ITEM_28 = :MRASCEVDEF_N.CHK_ITEM_28,
                    CHK_ITEM_29 = :MRASCEVDEF_N.CHK_ITEM_29,
                    CHK_ITEM_30 = :MRASCEVDEF_N.CHK_ITEM_30,
                    CHK_FLAG_1 = :MRASCEVDEF_N.CHK_FLAG_1,
                    CHK_FLAG_2 = :MRASCEVDEF_N.CHK_FLAG_2,
                    CHK_FLAG_3 = :MRASCEVDEF_N.CHK_FLAG_3,
                    CHK_FLAG_4 = :MRASCEVDEF_N.CHK_FLAG_4,
                    CHK_FLAG_5 = :MRASCEVDEF_N.CHK_FLAG_5,
                    CHK_FLAG_6 = :MRASCEVDEF_N.CHK_FLAG_6,
                    CHK_FLAG_7 = :MRASCEVDEF_N.CHK_FLAG_7,
                    CHK_FLAG_8 = :MRASCEVDEF_N.CHK_FLAG_8,
                    CHK_FLAG_9 = :MRASCEVDEF_N.CHK_FLAG_9,
                    CHK_FLAG_10 = :MRASCEVDEF_N.CHK_FLAG_10,
                    CHK_FLAG_11 = :MRASCEVDEF_N.CHK_FLAG_11,
                    CHK_FLAG_12 = :MRASCEVDEF_N.CHK_FLAG_12,
                    CHK_FLAG_13 = :MRASCEVDEF_N.CHK_FLAG_13,
                    CHK_FLAG_14 = :MRASCEVDEF_N.CHK_FLAG_14,
                    CHK_FLAG_15 = :MRASCEVDEF_N.CHK_FLAG_15,
                    CHK_FLAG_16 = :MRASCEVDEF_N.CHK_FLAG_16,
                    CHK_FLAG_17 = :MRASCEVDEF_N.CHK_FLAG_17,
                    CHK_FLAG_18 = :MRASCEVDEF_N.CHK_FLAG_18,
                    CHK_FLAG_19 = :MRASCEVDEF_N.CHK_FLAG_19,
                    CHK_FLAG_20 = :MRASCEVDEF_N.CHK_FLAG_20,
                    CHK_FLAG_21 = :MRASCEVDEF_N.CHK_FLAG_21,
                    CHK_FLAG_22 = :MRASCEVDEF_N.CHK_FLAG_22,
                    CHK_FLAG_23 = :MRASCEVDEF_N.CHK_FLAG_23,
                    CHK_FLAG_24 = :MRASCEVDEF_N.CHK_FLAG_24,
                    CHK_FLAG_25 = :MRASCEVDEF_N.CHK_FLAG_25,
                    CHK_FLAG_26 = :MRASCEVDEF_N.CHK_FLAG_26,
                    CHK_FLAG_27 = :MRASCEVDEF_N.CHK_FLAG_27,
                    CHK_FLAG_28 = :MRASCEVDEF_N.CHK_FLAG_28,
                    CHK_FLAG_29 = :MRASCEVDEF_N.CHK_FLAG_29,
                    CHK_FLAG_30 = :MRASCEVDEF_N.CHK_FLAG_30,
                    CHK_VALUE_1 = :MRASCEVDEF_N.CHK_VALUE_1,
                    CHK_VALUE_2 = :MRASCEVDEF_N.CHK_VALUE_2,
                    CHK_VALUE_3 = :MRASCEVDEF_N.CHK_VALUE_3,
                    CHK_VALUE_4 = :MRASCEVDEF_N.CHK_VALUE_4,
                    CHK_VALUE_5 = :MRASCEVDEF_N.CHK_VALUE_5,
                    CHK_VALUE_6 = :MRASCEVDEF_N.CHK_VALUE_6,
                    CHK_VALUE_7 = :MRASCEVDEF_N.CHK_VALUE_7,
                    CHK_VALUE_8 = :MRASCEVDEF_N.CHK_VALUE_8,
                    CHK_VALUE_9 = :MRASCEVDEF_N.CHK_VALUE_9,
                    CHK_VALUE_10 = :MRASCEVDEF_N.CHK_VALUE_10,
                    CHK_VALUE_11 = :MRASCEVDEF_N.CHK_VALUE_11,
                    CHK_VALUE_12 = :MRASCEVDEF_N.CHK_VALUE_12,
                    CHK_VALUE_13 = :MRASCEVDEF_N.CHK_VALUE_13,
                    CHK_VALUE_14 = :MRASCEVDEF_N.CHK_VALUE_14,
                    CHK_VALUE_15 = :MRASCEVDEF_N.CHK_VALUE_15,
                    CHK_VALUE_16 = :MRASCEVDEF_N.CHK_VALUE_16,
                    CHK_VALUE_17 = :MRASCEVDEF_N.CHK_VALUE_17,
                    CHK_VALUE_18 = :MRASCEVDEF_N.CHK_VALUE_18,
                    CHK_VALUE_19 = :MRASCEVDEF_N.CHK_VALUE_19,
                    CHK_VALUE_20 = :MRASCEVDEF_N.CHK_VALUE_20,
                    CHK_VALUE_21 = :MRASCEVDEF_N.CHK_VALUE_21,
                    CHK_VALUE_22 = :MRASCEVDEF_N.CHK_VALUE_22,
                    CHK_VALUE_23 = :MRASCEVDEF_N.CHK_VALUE_23,
                    CHK_VALUE_24 = :MRASCEVDEF_N.CHK_VALUE_24,
                    CHK_VALUE_25 = :MRASCEVDEF_N.CHK_VALUE_25,
                    CHK_VALUE_26 = :MRASCEVDEF_N.CHK_VALUE_26,
                    CHK_VALUE_27 = :MRASCEVDEF_N.CHK_VALUE_27,
                    CHK_VALUE_28 = :MRASCEVDEF_N.CHK_VALUE_28,
                    CHK_VALUE_29 = :MRASCEVDEF_N.CHK_VALUE_29,
                    CHK_VALUE_30 = :MRASCEVDEF_N.CHK_VALUE_30,
                    CHK_FIELD_1 = :MRASCEVDEF_N.CHK_FIELD_1,
                    CHK_FIELD_2 = :MRASCEVDEF_N.CHK_FIELD_2,
                    CHK_FIELD_3 = :MRASCEVDEF_N.CHK_FIELD_3,
                    CHK_FIELD_4 = :MRASCEVDEF_N.CHK_FIELD_4,
                    CHK_FIELD_5 = :MRASCEVDEF_N.CHK_FIELD_5,
                    CHK_FIELD_6 = :MRASCEVDEF_N.CHK_FIELD_6,
                    CHK_FIELD_7 = :MRASCEVDEF_N.CHK_FIELD_7,
                    CHK_FIELD_8 = :MRASCEVDEF_N.CHK_FIELD_8,
                    CHK_FIELD_9 = :MRASCEVDEF_N.CHK_FIELD_9,
                    CHK_FIELD_10 = :MRASCEVDEF_N.CHK_FIELD_10,
                    CHK_FIELD_11 = :MRASCEVDEF_N.CHK_FIELD_11,
                    CHK_FIELD_12 = :MRASCEVDEF_N.CHK_FIELD_12,
                    CHK_FIELD_13 = :MRASCEVDEF_N.CHK_FIELD_13,
                    CHK_FIELD_14 = :MRASCEVDEF_N.CHK_FIELD_14,
                    CHK_FIELD_15 = :MRASCEVDEF_N.CHK_FIELD_15,
                    CHK_FIELD_16 = :MRASCEVDEF_N.CHK_FIELD_16,
                    CHK_FIELD_17 = :MRASCEVDEF_N.CHK_FIELD_17,
                    CHK_FIELD_18 = :MRASCEVDEF_N.CHK_FIELD_18,
                    CHK_FIELD_19 = :MRASCEVDEF_N.CHK_FIELD_19,
                    CHK_FIELD_20 = :MRASCEVDEF_N.CHK_FIELD_20,
                    CHK_FIELD_21 = :MRASCEVDEF_N.CHK_FIELD_21,
                    CHK_FIELD_22 = :MRASCEVDEF_N.CHK_FIELD_22,
                    CHK_FIELD_23 = :MRASCEVDEF_N.CHK_FIELD_23,
                    CHK_FIELD_24 = :MRASCEVDEF_N.CHK_FIELD_24,
                    CHK_FIELD_25 = :MRASCEVDEF_N.CHK_FIELD_25,
                    CHK_FIELD_26 = :MRASCEVDEF_N.CHK_FIELD_26,
                    CHK_FIELD_27 = :MRASCEVDEF_N.CHK_FIELD_27,
                    CHK_FIELD_28 = :MRASCEVDEF_N.CHK_FIELD_28,
                    CHK_FIELD_29 = :MRASCEVDEF_N.CHK_FIELD_29,
                    CHK_FIELD_30 = :MRASCEVDEF_N.CHK_FIELD_30,
                    CHG_ITEM_1 = :MRASCEVDEF_N.CHG_ITEM_1,
                    CHG_ITEM_2 = :MRASCEVDEF_N.CHG_ITEM_2,
                    CHG_ITEM_3 = :MRASCEVDEF_N.CHG_ITEM_3,
                    CHG_ITEM_4 = :MRASCEVDEF_N.CHG_ITEM_4,
                    CHG_ITEM_5 = :MRASCEVDEF_N.CHG_ITEM_5,
                    CHG_ITEM_6 = :MRASCEVDEF_N.CHG_ITEM_6,
                    CHG_ITEM_7 = :MRASCEVDEF_N.CHG_ITEM_7,
                    CHG_ITEM_8 = :MRASCEVDEF_N.CHG_ITEM_8,
                    CHG_ITEM_9 = :MRASCEVDEF_N.CHG_ITEM_9,
                    CHG_ITEM_10 = :MRASCEVDEF_N.CHG_ITEM_10,
                    CHG_ITEM_11 = :MRASCEVDEF_N.CHG_ITEM_11,
                    CHG_ITEM_12 = :MRASCEVDEF_N.CHG_ITEM_12,
                    CHG_ITEM_13 = :MRASCEVDEF_N.CHG_ITEM_13,
                    CHG_ITEM_14 = :MRASCEVDEF_N.CHG_ITEM_14,
                    CHG_ITEM_15 = :MRASCEVDEF_N.CHG_ITEM_15,
                    CHG_ITEM_16 = :MRASCEVDEF_N.CHG_ITEM_16,
                    CHG_ITEM_17 = :MRASCEVDEF_N.CHG_ITEM_17,
                    CHG_ITEM_18 = :MRASCEVDEF_N.CHG_ITEM_18,
                    CHG_ITEM_19 = :MRASCEVDEF_N.CHG_ITEM_19,
                    CHG_ITEM_20 = :MRASCEVDEF_N.CHG_ITEM_20,
                    CHG_ITEM_21 = :MRASCEVDEF_N.CHG_ITEM_21,
                    CHG_ITEM_22 = :MRASCEVDEF_N.CHG_ITEM_22,
                    CHG_ITEM_23 = :MRASCEVDEF_N.CHG_ITEM_23,
                    CHG_ITEM_24 = :MRASCEVDEF_N.CHG_ITEM_24,
                    CHG_ITEM_25 = :MRASCEVDEF_N.CHG_ITEM_25,
                    CHG_ITEM_26 = :MRASCEVDEF_N.CHG_ITEM_26,
                    CHG_ITEM_27 = :MRASCEVDEF_N.CHG_ITEM_27,
                    CHG_ITEM_28 = :MRASCEVDEF_N.CHG_ITEM_28,
                    CHG_ITEM_29 = :MRASCEVDEF_N.CHG_ITEM_29,
                    CHG_ITEM_30 = :MRASCEVDEF_N.CHG_ITEM_30,
                    CHG_FLAG_1 = :MRASCEVDEF_N.CHG_FLAG_1,
                    CHG_FLAG_2 = :MRASCEVDEF_N.CHG_FLAG_2,
                    CHG_FLAG_3 = :MRASCEVDEF_N.CHG_FLAG_3,
                    CHG_FLAG_4 = :MRASCEVDEF_N.CHG_FLAG_4,
                    CHG_FLAG_5 = :MRASCEVDEF_N.CHG_FLAG_5,
                    CHG_FLAG_6 = :MRASCEVDEF_N.CHG_FLAG_6,
                    CHG_FLAG_7 = :MRASCEVDEF_N.CHG_FLAG_7,
                    CHG_FLAG_8 = :MRASCEVDEF_N.CHG_FLAG_8,
                    CHG_FLAG_9 = :MRASCEVDEF_N.CHG_FLAG_9,
                    CHG_FLAG_10 = :MRASCEVDEF_N.CHG_FLAG_10,
                    CHG_FLAG_11 = :MRASCEVDEF_N.CHG_FLAG_11,
                    CHG_FLAG_12 = :MRASCEVDEF_N.CHG_FLAG_12,
                    CHG_FLAG_13 = :MRASCEVDEF_N.CHG_FLAG_13,
                    CHG_FLAG_14 = :MRASCEVDEF_N.CHG_FLAG_14,
                    CHG_FLAG_15 = :MRASCEVDEF_N.CHG_FLAG_15,
                    CHG_FLAG_16 = :MRASCEVDEF_N.CHG_FLAG_16,
                    CHG_FLAG_17 = :MRASCEVDEF_N.CHG_FLAG_17,
                    CHG_FLAG_18 = :MRASCEVDEF_N.CHG_FLAG_18,
                    CHG_FLAG_19 = :MRASCEVDEF_N.CHG_FLAG_19,
                    CHG_FLAG_20 = :MRASCEVDEF_N.CHG_FLAG_20,
                    CHG_FLAG_21 = :MRASCEVDEF_N.CHG_FLAG_21,
                    CHG_FLAG_22 = :MRASCEVDEF_N.CHG_FLAG_22,
                    CHG_FLAG_23 = :MRASCEVDEF_N.CHG_FLAG_23,
                    CHG_FLAG_24 = :MRASCEVDEF_N.CHG_FLAG_24,
                    CHG_FLAG_25 = :MRASCEVDEF_N.CHG_FLAG_25,
                    CHG_FLAG_26 = :MRASCEVDEF_N.CHG_FLAG_26,
                    CHG_FLAG_27 = :MRASCEVDEF_N.CHG_FLAG_27,
                    CHG_FLAG_28 = :MRASCEVDEF_N.CHG_FLAG_28,
                    CHG_FLAG_29 = :MRASCEVDEF_N.CHG_FLAG_29,
                    CHG_FLAG_30 = :MRASCEVDEF_N.CHG_FLAG_30,
                    CHG_VALUE_1 = :MRASCEVDEF_N.CHG_VALUE_1,
                    CHG_VALUE_2 = :MRASCEVDEF_N.CHG_VALUE_2,
                    CHG_VALUE_3 = :MRASCEVDEF_N.CHG_VALUE_3,
                    CHG_VALUE_4 = :MRASCEVDEF_N.CHG_VALUE_4,
                    CHG_VALUE_5 = :MRASCEVDEF_N.CHG_VALUE_5,
                    CHG_VALUE_6 = :MRASCEVDEF_N.CHG_VALUE_6,
                    CHG_VALUE_7 = :MRASCEVDEF_N.CHG_VALUE_7,
                    CHG_VALUE_8 = :MRASCEVDEF_N.CHG_VALUE_8,
                    CHG_VALUE_9 = :MRASCEVDEF_N.CHG_VALUE_9,
                    CHG_VALUE_10 = :MRASCEVDEF_N.CHG_VALUE_10,
                    CHG_VALUE_11 = :MRASCEVDEF_N.CHG_VALUE_11,
                    CHG_VALUE_12 = :MRASCEVDEF_N.CHG_VALUE_12,
                    CHG_VALUE_13 = :MRASCEVDEF_N.CHG_VALUE_13,
                    CHG_VALUE_14 = :MRASCEVDEF_N.CHG_VALUE_14,
                    CHG_VALUE_15 = :MRASCEVDEF_N.CHG_VALUE_15,
                    CHG_VALUE_16 = :MRASCEVDEF_N.CHG_VALUE_16,
                    CHG_VALUE_17 = :MRASCEVDEF_N.CHG_VALUE_17,
                    CHG_VALUE_18 = :MRASCEVDEF_N.CHG_VALUE_18,
                    CHG_VALUE_19 = :MRASCEVDEF_N.CHG_VALUE_19,
                    CHG_VALUE_20 = :MRASCEVDEF_N.CHG_VALUE_20,
                    CHG_VALUE_21 = :MRASCEVDEF_N.CHG_VALUE_21,
                    CHG_VALUE_22 = :MRASCEVDEF_N.CHG_VALUE_22,
                    CHG_VALUE_23 = :MRASCEVDEF_N.CHG_VALUE_23,
                    CHG_VALUE_24 = :MRASCEVDEF_N.CHG_VALUE_24,
                    CHG_VALUE_25 = :MRASCEVDEF_N.CHG_VALUE_25,
                    CHG_VALUE_26 = :MRASCEVDEF_N.CHG_VALUE_26,
                    CHG_VALUE_27 = :MRASCEVDEF_N.CHG_VALUE_27,
                    CHG_VALUE_28 = :MRASCEVDEF_N.CHG_VALUE_28,
                    CHG_VALUE_29 = :MRASCEVDEF_N.CHG_VALUE_29,
                    CHG_VALUE_30 = :MRASCEVDEF_N.CHG_VALUE_30,
                    CHG_OPT_1 = :MRASCEVDEF_N.CHG_OPT_1,
                    CHG_OPT_2 = :MRASCEVDEF_N.CHG_OPT_2,
                    CHG_OPT_3 = :MRASCEVDEF_N.CHG_OPT_3,
                    CHG_OPT_4 = :MRASCEVDEF_N.CHG_OPT_4,
                    CHG_OPT_5 = :MRASCEVDEF_N.CHG_OPT_5,
                    CHG_OPT_6 = :MRASCEVDEF_N.CHG_OPT_6,
                    CHG_OPT_7 = :MRASCEVDEF_N.CHG_OPT_7,
                    CHG_OPT_8 = :MRASCEVDEF_N.CHG_OPT_8,
                    CHG_OPT_9 = :MRASCEVDEF_N.CHG_OPT_9,
                    CHG_OPT_10 = :MRASCEVDEF_N.CHG_OPT_10,
                    CHG_OPT_11 = :MRASCEVDEF_N.CHG_OPT_11,
                    CHG_OPT_12 = :MRASCEVDEF_N.CHG_OPT_12,
                    CHG_OPT_13 = :MRASCEVDEF_N.CHG_OPT_13,
                    CHG_OPT_14 = :MRASCEVDEF_N.CHG_OPT_14,
                    CHG_OPT_15 = :MRASCEVDEF_N.CHG_OPT_15,
                    CHG_OPT_16 = :MRASCEVDEF_N.CHG_OPT_16,
                    CHG_OPT_17 = :MRASCEVDEF_N.CHG_OPT_17,
                    CHG_OPT_18 = :MRASCEVDEF_N.CHG_OPT_18,
                    CHG_OPT_19 = :MRASCEVDEF_N.CHG_OPT_19,
                    CHG_OPT_20 = :MRASCEVDEF_N.CHG_OPT_20,
                    CHG_OPT_21 = :MRASCEVDEF_N.CHG_OPT_21,
                    CHG_OPT_22 = :MRASCEVDEF_N.CHG_OPT_22,
                    CHG_OPT_23 = :MRASCEVDEF_N.CHG_OPT_23,
                    CHG_OPT_24 = :MRASCEVDEF_N.CHG_OPT_24,
                    CHG_OPT_25 = :MRASCEVDEF_N.CHG_OPT_25,
                    CHG_OPT_26 = :MRASCEVDEF_N.CHG_OPT_26,
                    CHG_OPT_27 = :MRASCEVDEF_N.CHG_OPT_27,
                    CHG_OPT_28 = :MRASCEVDEF_N.CHG_OPT_28,
                    CHG_OPT_29 = :MRASCEVDEF_N.CHG_OPT_29,
                    CHG_OPT_30 = :MRASCEVDEF_N.CHG_OPT_30,
                    CREATE_USER_ID = :MRASCEVDEF_N.CREATE_USER_ID,
                    CREATE_TIME = :MRASCEVDEF_N.CREATE_TIME,
                    UPDATE_USER_ID = :MRASCEVDEF_N.UPDATE_USER_ID,
                    UPDATE_TIME = :MRASCEVDEF_N.UPDATE_TIME
                WHERE FACTORY = :MRASCEVDEF_N.FACTORY
                    AND CRR_EVENT_ID = :MRASCEVDEF_N.CRR_EVENT_ID; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "update MRASCEVDEF  set CRR_EVENT_DESC=:b0,SYSTEM_FLAG=:b1,CHK\
_ITEM_1=:b2,CHK_ITEM_2=:b3,CHK_ITEM_3=:b4,CHK_ITEM_4=:b5,CHK_ITEM_5=:b6,CHK_\
ITEM_6=:b7,CHK_ITEM_7=:b8,CHK_ITEM_8=:b9,CHK_ITEM_9=:b10,CHK_ITEM_10=:b11,CH\
K_ITEM_11=:b12,CHK_ITEM_12=:b13,CHK_ITEM_13=:b14,CHK_ITEM_14=:b15,CHK_ITEM_1\
5=:b16,CHK_ITEM_16=:b17,CHK_ITEM_17=:b18,CHK_ITEM_18=:b19,CHK_ITEM_19=:b20,C\
HK_ITEM_20=:b21,CHK_ITEM_21=:b22,CHK_ITEM_22=:b23,CHK_ITEM_23=:b24,CHK_ITEM_\
24=:b25,CHK_ITEM_25=:b26,CHK_ITEM_26=:b27,CHK_ITEM_27=:b28,CHK_ITEM_28=:b29,\
CHK_ITEM_29=:b30,CHK_ITEM_30=:b31,CHK_FLAG_1=:b32,CHK_FLAG_2=:b33,CHK_FLAG_3\
=:b34,CHK_FLAG_4=:b35,CHK_FLAG_5=:b36,CHK_FLAG_6=:b37,CHK_FLAG_7=:b38,CHK_FL\
AG_8=:b39,CHK_FLAG_9=:b40,CHK_FLAG_10=:b41,CHK_FLAG_11=:b42,CHK_FLAG_12=:b43\
,CHK_FLAG_13=:b44,CHK_FLAG_14=:b45,CHK_FLAG_15=:b46,CHK_FLAG_16=:b47,CHK_FLA\
G_17=:b48,CHK_FLAG_18=:b49,CHK_FLAG_19=:b50,CHK_FLAG_20=:b51,CHK_FLAG_21=:b5\
2,CHK_FLAG_22=:b53,CHK_FLAG_23=:b54,CHK_FLAG_24=:b55,CHK_FLAG_25=:b56,CHK_FL\
AG_26=:b57,CHK_FLAG_27=:b58,CHK_FLAG_28=:b59,CHK_FL");
            sqlbuft((void **)0,
              "AG_29=:b60,CHK_FLAG_30=:b61,CHK_VALUE_1=:b62,CHK_VALUE_2=:b63\
,CHK_VALUE_3=:b64,CHK_VALUE_4=:b65,CHK_VALUE_5=:b66,CHK_VALUE_6=:b67,CHK_VAL\
UE_7=:b68,CHK_VALUE_8=:b69,CHK_VALUE_9=:b70,CHK_VALUE_10=:b71,CHK_VALUE_11=:\
b72,CHK_VALUE_12=:b73,CHK_VALUE_13=:b74,CHK_VALUE_14=:b75,CHK_VALUE_15=:b76,\
CHK_VALUE_16=:b77,CHK_VALUE_17=:b78,CHK_VALUE_18=:b79,CHK_VALUE_19=:b80,CHK_\
VALUE_20=:b81,CHK_VALUE_21=:b82,CHK_VALUE_22=:b83,CHK_VALUE_23=:b84,CHK_VALU\
E_24=:b85,CHK_VALUE_25=:b86,CHK_VALUE_26=:b87,CHK_VALUE_27=:b88,CHK_VALUE_28\
=:b89,CHK_VALUE_29=:b90,CHK_VALUE_30=:b91,CHK_FIELD_1=:b92,CHK_FIELD_2=:b93,\
CHK_FIELD_3=:b94,CHK_FIELD_4=:b95,CHK_FIELD_5=:b96,CHK_FIELD_6=:b97,CHK_FIEL\
D_7=:b98,CHK_FIELD_8=:b99,CHK_FIELD_9=:b100,CHK_FIELD_10=:b101,CHK_FIELD_11=\
:b102,CHK_FIELD_12=:b103,CHK_FIELD_13=:b104,CHK_FIELD_14=:b105,CHK_FIELD_15=\
:b106,CHK_FIELD_16=:b107,CHK_FIELD_17=:b108,CHK_FIELD_18=:b109,CHK_FIELD_19=\
:b110,CHK_FIELD_20=:b111,CHK_FIELD_21=:b112,CHK_FIELD_22=:b113,CHK_FIELD_23=\
:b114,CHK_FIELD_24=:b115,CHK_FIELD_25=:b116,CHK_FIE");
            sqlbuft((void **)0,
              "LD_26=:b117,CHK_FIELD_27=:b118,CHK_FIELD_28=:b119,CHK_FIELD_2\
9=:b120,CHK_FIELD_30=:b121,CHG_ITEM_1=:b122,CHG_ITEM_2=:b123,CHG_ITEM_3=:b12\
4,CHG_ITEM_4=:b125,CHG_ITEM_5=:b126,CHG_ITEM_6=:b127,CHG_ITEM_7=:b128,CHG_IT\
EM_8=:b129,CHG_ITEM_9=:b130,CHG_ITEM_10=:b131,CHG_ITEM_11=:b132,CHG_ITEM_12=\
:b133,CHG_ITEM_13=:b134,CHG_ITEM_14=:b135,CHG_ITEM_15=:b136,CHG_ITEM_16=:b13\
7,CHG_ITEM_17=:b138,CHG_ITEM_18=:b139,CHG_ITEM_19=:b140,CHG_ITEM_20=:b141,CH\
G_ITEM_21=:b142,CHG_ITEM_22=:b143,CHG_ITEM_23=:b144,CHG_ITEM_24=:b145,CHG_IT\
EM_25=:b146,CHG_ITEM_26=:b147,CHG_ITEM_27=:b148,CHG_ITEM_28=:b149,CHG_ITEM_2\
9=:b150,CHG_ITEM_30=:b151,CHG_FLAG_1=:b152,CHG_FLAG_2=:b153,CHG_FLAG_3=:b154\
,CHG_FLAG_4=:b155,CHG_FLAG_5=:b156,CHG_FLAG_6=:b157,CHG_FLAG_7=:b158,CHG_FLA\
G_8=:b159,CHG_FLAG_9=:b160,CHG_FLAG_10=:b161,CHG_FLAG_11=:b162,CHG_FLAG_12=:\
b163,CHG_FLAG_13=:b164,CHG_FLAG_14=:b165,CHG_FLAG_15=:b166,CHG_FLAG_16=:b167\
,CHG_FLAG_17=:b168,CHG_FLAG_18=:b169,CHG_FLAG_19=:b170,CHG_FLAG_20=:b171,CHG\
_FLAG_21=:b172,CHG_FLAG_22=:b173,CHG_FLAG_23=:b174,");
            sqlbuft((void **)0,
              "CHG_FLAG_24=:b175,CHG_FLAG_25=:b176,CHG_FLAG_26=:b177,CHG_FLA\
G_27=:b178,CHG_FLAG_28=:b179,CHG_FLAG_29=:b180,CHG_FLAG_30=:b181,CHG_VALUE_1\
=:b182,CHG_VALUE_2=:b183,CHG_VALUE_3=:b184,CHG_VALUE_4=:b185,CHG_VALUE_5=:b1\
86,CHG_VALUE_6=:b187,CHG_VALUE_7=:b188,CHG_VALUE_8=:b189,CHG_VALUE_9=:b190,C\
HG_VALUE_10=:b191,CHG_VALUE_11=:b192,CHG_VALUE_12=:b193,CHG_VALUE_13=:b194,C\
HG_VALUE_14=:b195,CHG_VALUE_15=:b196,CHG_VALUE_16=:b197,CHG_VALUE_17=:b198,C\
HG_VALUE_18=:b199,CHG_VALUE_19=:b200,CHG_VALUE_20=:b201,CHG_VALUE_21=:b202,C\
HG_VALUE_22=:b203,CHG_VALUE_23=:b204,CHG_VALUE_24=:b205,CHG_VALUE_25=:b206,C\
HG_VALUE_26=:b207,CHG_VALUE_27=:b208,CHG_VALUE_28=:b209,CHG_VALUE_29=:b210,C\
HG_VALUE_30=:b211,CHG_OPT_1=:b212,CHG_OPT_2=:b213,CHG_OPT_3=:b214,CHG_OPT_4=\
:b215,CHG_OPT_5=:b216,CHG_OPT_6=:b217,CHG_OPT_7=:b218,CHG_OPT_8=:b219,CHG_OP\
T_9=:b220,CHG_OPT_10=:b221,CHG_OPT_11=:b222,CHG_OPT_12=:b223,CHG_OPT_13=:b22\
4,CHG_OPT_14=:b225,CHG_OPT_15=:b226,CHG_OPT_16=:b227,CHG_OPT_17=:b228,CHG_OP\
T_18=:b229,CHG_OPT_19=:b230,CHG_OPT_20=:b231,CHG_OP");
            sqlstm.stmt = "T_21=:b232,CHG_OPT_22=:b233,CHG_OPT_23=:b234,CHG\
_OPT_24=:b235,CHG_OPT_25=:b236,CHG_OPT_26=:b237,CHG_OPT_27=:b238,CHG_OPT_28=:\
b239,CHG_OPT_29=:b240,CHG_OPT_30=:b241,CREATE_USER_ID=:b242,CREATE_TIME=:b243\
,UPDATE_USER_ID=:b244,UPDATE_TIME=:b245 where (FACTORY=:b246 and CRR_EVENT_ID\
=:b247)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3092;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_DESC);
            sqlstm.sqhstl[0] = (unsigned int  )201;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[1] = (unsigned int  )2;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[2] = (unsigned int  )31;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[33] = (unsigned int  )2;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[62] = (unsigned int  )31;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[63] = (unsigned int  )31;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[152] = (unsigned int  )2;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[153] = (unsigned int  )2;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[154] = (unsigned int  )2;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[155] = (unsigned int  )2;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[182] = (unsigned int  )31;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[183] = (unsigned int  )31;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[184] = (unsigned int  )31;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[186] = (unsigned int  )31;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASCEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[212] = (unsigned int  )2;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASCEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[213] = (unsigned int  )2;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASCEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASCEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[215] = (unsigned int  )2;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASCEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[216] = (unsigned int  )2;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASCEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASCEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASCEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASCEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASCEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASCEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASCEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASCEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASCEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASCEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASCEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASCEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASCEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASCEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASCEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASCEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASCEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASCEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASCEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASCEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASCEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASCEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASCEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASCEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASCEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASCEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[242] = (unsigned int  )21;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASCEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[243] = (unsigned int  )15;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASCEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[244] = (unsigned int  )21;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASCEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[245] = (unsigned int  )15;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[246] = (unsigned int  )11;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[247] = (unsigned int  )13;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_update_mrascevdef", sel_type);
}


/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_mrascevdef(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    
    DBC_add_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_MRASCEVDEF_CUR_1 CURSOR FOR
                SELECT 
                    FACTORY,
                    CRR_EVENT_ID,
                    CRR_EVENT_DESC,
                    SYSTEM_FLAG,
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
                    UPDATE_TIME
                FROM MRASCEVDEF
                WHERE FACTORY = :MRASCEVDEF_N.FACTORY
                    AND CRR_EVENT_ID >= :MRASCEVDEF_N.CRR_EVENT_ID
                ORDER BY CRR_EVENT_ID ASC; */ 

            /* EXEC SQL OPEN DBC_MRASCEVDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select FACTORY ,CRR_EVENT_ID ,CRR_EVENT_DESC ,SYSTEM_FLAG ,CH\
K_ITEM_1 ,CHK_ITEM_2 ,CHK_ITEM_3 ,CHK_ITEM_4 ,CHK_ITEM_5 ,CHK_ITEM_6 ,CHK_IT\
EM_7 ,CHK_ITEM_8 ,CHK_ITEM_9 ,CHK_ITEM_10 ,CHK_ITEM_11 ,CHK_ITEM_12 ,CHK_ITE\
M_13 ,CHK_ITEM_14 ,CHK_ITEM_15 ,CHK_ITEM_16 ,CHK_ITEM_17 ,CHK_ITEM_18 ,CHK_I\
TEM_19 ,CHK_ITEM_20 ,CHK_ITEM_21 ,CHK_ITEM_22 ,CHK_ITEM_23 ,CHK_ITEM_24 ,CHK\
_ITEM_25 ,CHK_ITEM_26 ,CHK_ITEM_27 ,CHK_ITEM_28 ,CHK_ITEM_29 ,CHK_ITEM_30 ,C\
HK_FLAG_1 ,CHK_FLAG_2 ,CHK_FLAG_3 ,CHK_FLAG_4 ,CHK_FLAG_5 ,CHK_FLAG_6 ,CHK_F\
LAG_7 ,CHK_FLAG_8 ,CHK_FLAG_9 ,CHK_FLAG_10 ,CHK_FLAG_11 ,CHK_FLAG_12 ,CHK_FL\
AG_13 ,CHK_FLAG_14 ,CHK_FLAG_15 ,CHK_FLAG_16 ,CHK_FLAG_17 ,CHK_FLAG_18 ,CHK_\
FLAG_19 ,CHK_FLAG_20 ,CHK_FLAG_21 ,CHK_FLAG_22 ,CHK_FLAG_23 ,CHK_FLAG_24 ,CH\
K_FLAG_25 ,CHK_FLAG_26 ,CHK_FLAG_27 ,CHK_FLAG_28 ,CHK_FLAG_29 ,CHK_FLAG_30 ,\
CHK_VALUE_1 ,CHK_VALUE_2 ,CHK_VALUE_3 ,CHK_VALUE_4 ,CHK_VALUE_5 ,CHK_VALUE_6\
 ,CHK_VALUE_7 ,CHK_VALUE_8 ,CHK_VALUE_9 ,CHK_VALUE_10 ,CHK_VALUE_11 ,CHK_VAL\
UE_12 ,CHK_VALUE_13 ,CHK_VALUE_14 ,CHK_VALUE_15 ,CH");
            sqlbuft((void **)0,
              "K_VALUE_16 ,CHK_VALUE_17 ,CHK_VALUE_18 ,CHK_VALUE_19 ,CHK_VAL\
UE_20 ,CHK_VALUE_21 ,CHK_VALUE_22 ,CHK_VALUE_23 ,CHK_VALUE_24 ,CHK_VALUE_25 \
,CHK_VALUE_26 ,CHK_VALUE_27 ,CHK_VALUE_28 ,CHK_VALUE_29 ,CHK_VALUE_30 ,CHK_F\
IELD_1 ,CHK_FIELD_2 ,CHK_FIELD_3 ,CHK_FIELD_4 ,CHK_FIELD_5 ,CHK_FIELD_6 ,CHK\
_FIELD_7 ,CHK_FIELD_8 ,CHK_FIELD_9 ,CHK_FIELD_10 ,CHK_FIELD_11 ,CHK_FIELD_12\
 ,CHK_FIELD_13 ,CHK_FIELD_14 ,CHK_FIELD_15 ,CHK_FIELD_16 ,CHK_FIELD_17 ,CHK_\
FIELD_18 ,CHK_FIELD_19 ,CHK_FIELD_20 ,CHK_FIELD_21 ,CHK_FIELD_22 ,CHK_FIELD_\
23 ,CHK_FIELD_24 ,CHK_FIELD_25 ,CHK_FIELD_26 ,CHK_FIELD_27 ,CHK_FIELD_28 ,CH\
K_FIELD_29 ,CHK_FIELD_30 ,CHG_ITEM_1 ,CHG_ITEM_2 ,CHG_ITEM_3 ,CHG_ITEM_4 ,CH\
G_ITEM_5 ,CHG_ITEM_6 ,CHG_ITEM_7 ,CHG_ITEM_8 ,CHG_ITEM_9 ,CHG_ITEM_10 ,CHG_I\
TEM_11 ,CHG_ITEM_12 ,CHG_ITEM_13 ,CHG_ITEM_14 ,CHG_ITEM_15 ,CHG_ITEM_16 ,CHG\
_ITEM_17 ,CHG_ITEM_18 ,CHG_ITEM_19 ,CHG_ITEM_20 ,CHG_ITEM_21 ,CHG_ITEM_22 ,C\
HG_ITEM_23 ,CHG_ITEM_24 ,CHG_ITEM_25 ,CHG_ITEM_26 ,CHG_ITEM_27 ,CHG_ITEM_28 \
,CHG_ITEM_29 ,CHG_ITEM_30 ,CHG_FLAG_1 ,CHG_FLAG_2 ,");
            sqlbuft((void **)0,
              "CHG_FLAG_3 ,CHG_FLAG_4 ,CHG_FLAG_5 ,CHG_FLAG_6 ,CHG_FLAG_7 ,C\
HG_FLAG_8 ,CHG_FLAG_9 ,CHG_FLAG_10 ,CHG_FLAG_11 ,CHG_FLAG_12 ,CHG_FLAG_13 ,C\
HG_FLAG_14 ,CHG_FLAG_15 ,CHG_FLAG_16 ,CHG_FLAG_17 ,CHG_FLAG_18 ,CHG_FLAG_19 \
,CHG_FLAG_20 ,CHG_FLAG_21 ,CHG_FLAG_22 ,CHG_FLAG_23 ,CHG_FLAG_24 ,CHG_FLAG_2\
5 ,CHG_FLAG_26 ,CHG_FLAG_27 ,CHG_FLAG_28 ,CHG_FLAG_29 ,CHG_FLAG_30 ,CHG_VALU\
E_1 ,CHG_VALUE_2 ,CHG_VALUE_3 ,CHG_VALUE_4 ,CHG_VALUE_5 ,CHG_VALUE_6 ,CHG_VA\
LUE_7 ,CHG_VALUE_8 ,CHG_VALUE_9 ,CHG_VALUE_10 ,CHG_VALUE_11 ,CHG_VALUE_12 ,C\
HG_VALUE_13 ,CHG_VALUE_14 ,CHG_VALUE_15 ,CHG_VALUE_16 ,CHG_VALUE_17 ,CHG_VAL\
UE_18 ,CHG_VALUE_19 ,CHG_VALUE_20 ,CHG_VALUE_21 ,CHG_VALUE_22 ,CHG_VALUE_23 \
,CHG_VALUE_24 ,CHG_VALUE_25 ,CHG_VALUE_26 ,CHG_VALUE_27 ,CHG_VALUE_28 ,CHG_V\
ALUE_29 ,CHG_VALUE_30 ,CHG_OPT_1 ,CHG_OPT_2 ,CHG_OPT_3 ,CHG_OPT_4 ,CHG_OPT_5\
 ,CHG_OPT_6 ,CHG_OPT_7 ,CHG_OPT_8 ,CHG_OPT_9 ,CHG_OPT_10 ,CHG_OPT_11 ,CHG_OP\
T_12 ,CHG_OPT_13 ,CHG_OPT_14 ,CHG_OPT_15 ,CHG_OPT_16 ,CHG_OPT_17 ,CHG_OPT_18\
 ,CHG_OPT_19 ,CHG_OPT_20 ,CHG_OPT_21 ,CHG_OPT_22 ,C");
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4099;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )13;
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
    DB_stop_query_timer("DBC_open_mrascevdef", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_mrascevdef(int sel_type, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct MRASCEVDEF_N_TAG MRASCEVDEF_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_MRASCEVDEF_CUR_1 INTO 
                                                    :MRASCEVDEF_N.FACTORY,
                                                    :MRASCEVDEF_N.CRR_EVENT_ID,
                                                    :MRASCEVDEF_N.CRR_EVENT_DESC,
                                                    :MRASCEVDEF_N.SYSTEM_FLAG,
                                                    :MRASCEVDEF_N.CHK_ITEM_1,
                                                    :MRASCEVDEF_N.CHK_ITEM_2,
                                                    :MRASCEVDEF_N.CHK_ITEM_3,
                                                    :MRASCEVDEF_N.CHK_ITEM_4,
                                                    :MRASCEVDEF_N.CHK_ITEM_5,
                                                    :MRASCEVDEF_N.CHK_ITEM_6,
                                                    :MRASCEVDEF_N.CHK_ITEM_7,
                                                    :MRASCEVDEF_N.CHK_ITEM_8,
                                                    :MRASCEVDEF_N.CHK_ITEM_9,
                                                    :MRASCEVDEF_N.CHK_ITEM_10,
                                                    :MRASCEVDEF_N.CHK_ITEM_11,
                                                    :MRASCEVDEF_N.CHK_ITEM_12,
                                                    :MRASCEVDEF_N.CHK_ITEM_13,
                                                    :MRASCEVDEF_N.CHK_ITEM_14,
                                                    :MRASCEVDEF_N.CHK_ITEM_15,
                                                    :MRASCEVDEF_N.CHK_ITEM_16,
                                                    :MRASCEVDEF_N.CHK_ITEM_17,
                                                    :MRASCEVDEF_N.CHK_ITEM_18,
                                                    :MRASCEVDEF_N.CHK_ITEM_19,
                                                    :MRASCEVDEF_N.CHK_ITEM_20,
                                                    :MRASCEVDEF_N.CHK_ITEM_21,
                                                    :MRASCEVDEF_N.CHK_ITEM_22,
                                                    :MRASCEVDEF_N.CHK_ITEM_23,
                                                    :MRASCEVDEF_N.CHK_ITEM_24,
                                                    :MRASCEVDEF_N.CHK_ITEM_25,
                                                    :MRASCEVDEF_N.CHK_ITEM_26,
                                                    :MRASCEVDEF_N.CHK_ITEM_27,
                                                    :MRASCEVDEF_N.CHK_ITEM_28,
                                                    :MRASCEVDEF_N.CHK_ITEM_29,
                                                    :MRASCEVDEF_N.CHK_ITEM_30,
                                                    :MRASCEVDEF_N.CHK_FLAG_1,
                                                    :MRASCEVDEF_N.CHK_FLAG_2,
                                                    :MRASCEVDEF_N.CHK_FLAG_3,
                                                    :MRASCEVDEF_N.CHK_FLAG_4,
                                                    :MRASCEVDEF_N.CHK_FLAG_5,
                                                    :MRASCEVDEF_N.CHK_FLAG_6,
                                                    :MRASCEVDEF_N.CHK_FLAG_7,
                                                    :MRASCEVDEF_N.CHK_FLAG_8,
                                                    :MRASCEVDEF_N.CHK_FLAG_9,
                                                    :MRASCEVDEF_N.CHK_FLAG_10,
                                                    :MRASCEVDEF_N.CHK_FLAG_11,
                                                    :MRASCEVDEF_N.CHK_FLAG_12,
                                                    :MRASCEVDEF_N.CHK_FLAG_13,
                                                    :MRASCEVDEF_N.CHK_FLAG_14,
                                                    :MRASCEVDEF_N.CHK_FLAG_15,
                                                    :MRASCEVDEF_N.CHK_FLAG_16,
                                                    :MRASCEVDEF_N.CHK_FLAG_17,
                                                    :MRASCEVDEF_N.CHK_FLAG_18,
                                                    :MRASCEVDEF_N.CHK_FLAG_19,
                                                    :MRASCEVDEF_N.CHK_FLAG_20,
                                                    :MRASCEVDEF_N.CHK_FLAG_21,
                                                    :MRASCEVDEF_N.CHK_FLAG_22,
                                                    :MRASCEVDEF_N.CHK_FLAG_23,
                                                    :MRASCEVDEF_N.CHK_FLAG_24,
                                                    :MRASCEVDEF_N.CHK_FLAG_25,
                                                    :MRASCEVDEF_N.CHK_FLAG_26,
                                                    :MRASCEVDEF_N.CHK_FLAG_27,
                                                    :MRASCEVDEF_N.CHK_FLAG_28,
                                                    :MRASCEVDEF_N.CHK_FLAG_29,
                                                    :MRASCEVDEF_N.CHK_FLAG_30,
                                                    :MRASCEVDEF_N.CHK_VALUE_1,
                                                    :MRASCEVDEF_N.CHK_VALUE_2,
                                                    :MRASCEVDEF_N.CHK_VALUE_3,
                                                    :MRASCEVDEF_N.CHK_VALUE_4,
                                                    :MRASCEVDEF_N.CHK_VALUE_5,
                                                    :MRASCEVDEF_N.CHK_VALUE_6,
                                                    :MRASCEVDEF_N.CHK_VALUE_7,
                                                    :MRASCEVDEF_N.CHK_VALUE_8,
                                                    :MRASCEVDEF_N.CHK_VALUE_9,
                                                    :MRASCEVDEF_N.CHK_VALUE_10,
                                                    :MRASCEVDEF_N.CHK_VALUE_11,
                                                    :MRASCEVDEF_N.CHK_VALUE_12,
                                                    :MRASCEVDEF_N.CHK_VALUE_13,
                                                    :MRASCEVDEF_N.CHK_VALUE_14,
                                                    :MRASCEVDEF_N.CHK_VALUE_15,
                                                    :MRASCEVDEF_N.CHK_VALUE_16,
                                                    :MRASCEVDEF_N.CHK_VALUE_17,
                                                    :MRASCEVDEF_N.CHK_VALUE_18,
                                                    :MRASCEVDEF_N.CHK_VALUE_19,
                                                    :MRASCEVDEF_N.CHK_VALUE_20,
                                                    :MRASCEVDEF_N.CHK_VALUE_21,
                                                    :MRASCEVDEF_N.CHK_VALUE_22,
                                                    :MRASCEVDEF_N.CHK_VALUE_23,
                                                    :MRASCEVDEF_N.CHK_VALUE_24,
                                                    :MRASCEVDEF_N.CHK_VALUE_25,
                                                    :MRASCEVDEF_N.CHK_VALUE_26,
                                                    :MRASCEVDEF_N.CHK_VALUE_27,
                                                    :MRASCEVDEF_N.CHK_VALUE_28,
                                                    :MRASCEVDEF_N.CHK_VALUE_29,
                                                    :MRASCEVDEF_N.CHK_VALUE_30,
                                                    :MRASCEVDEF_N.CHK_FIELD_1,
                                                    :MRASCEVDEF_N.CHK_FIELD_2,
                                                    :MRASCEVDEF_N.CHK_FIELD_3,
                                                    :MRASCEVDEF_N.CHK_FIELD_4,
                                                    :MRASCEVDEF_N.CHK_FIELD_5,
                                                    :MRASCEVDEF_N.CHK_FIELD_6,
                                                    :MRASCEVDEF_N.CHK_FIELD_7,
                                                    :MRASCEVDEF_N.CHK_FIELD_8,
                                                    :MRASCEVDEF_N.CHK_FIELD_9,
                                                    :MRASCEVDEF_N.CHK_FIELD_10,
                                                    :MRASCEVDEF_N.CHK_FIELD_11,
                                                    :MRASCEVDEF_N.CHK_FIELD_12,
                                                    :MRASCEVDEF_N.CHK_FIELD_13,
                                                    :MRASCEVDEF_N.CHK_FIELD_14,
                                                    :MRASCEVDEF_N.CHK_FIELD_15,
                                                    :MRASCEVDEF_N.CHK_FIELD_16,
                                                    :MRASCEVDEF_N.CHK_FIELD_17,
                                                    :MRASCEVDEF_N.CHK_FIELD_18,
                                                    :MRASCEVDEF_N.CHK_FIELD_19,
                                                    :MRASCEVDEF_N.CHK_FIELD_20,
                                                    :MRASCEVDEF_N.CHK_FIELD_21,
                                                    :MRASCEVDEF_N.CHK_FIELD_22,
                                                    :MRASCEVDEF_N.CHK_FIELD_23,
                                                    :MRASCEVDEF_N.CHK_FIELD_24,
                                                    :MRASCEVDEF_N.CHK_FIELD_25,
                                                    :MRASCEVDEF_N.CHK_FIELD_26,
                                                    :MRASCEVDEF_N.CHK_FIELD_27,
                                                    :MRASCEVDEF_N.CHK_FIELD_28,
                                                    :MRASCEVDEF_N.CHK_FIELD_29,
                                                    :MRASCEVDEF_N.CHK_FIELD_30,
                                                    :MRASCEVDEF_N.CHG_ITEM_1,
                                                    :MRASCEVDEF_N.CHG_ITEM_2,
                                                    :MRASCEVDEF_N.CHG_ITEM_3,
                                                    :MRASCEVDEF_N.CHG_ITEM_4,
                                                    :MRASCEVDEF_N.CHG_ITEM_5,
                                                    :MRASCEVDEF_N.CHG_ITEM_6,
                                                    :MRASCEVDEF_N.CHG_ITEM_7,
                                                    :MRASCEVDEF_N.CHG_ITEM_8,
                                                    :MRASCEVDEF_N.CHG_ITEM_9,
                                                    :MRASCEVDEF_N.CHG_ITEM_10,
                                                    :MRASCEVDEF_N.CHG_ITEM_11,
                                                    :MRASCEVDEF_N.CHG_ITEM_12,
                                                    :MRASCEVDEF_N.CHG_ITEM_13,
                                                    :MRASCEVDEF_N.CHG_ITEM_14,
                                                    :MRASCEVDEF_N.CHG_ITEM_15,
                                                    :MRASCEVDEF_N.CHG_ITEM_16,
                                                    :MRASCEVDEF_N.CHG_ITEM_17,
                                                    :MRASCEVDEF_N.CHG_ITEM_18,
                                                    :MRASCEVDEF_N.CHG_ITEM_19,
                                                    :MRASCEVDEF_N.CHG_ITEM_20,
                                                    :MRASCEVDEF_N.CHG_ITEM_21,
                                                    :MRASCEVDEF_N.CHG_ITEM_22,
                                                    :MRASCEVDEF_N.CHG_ITEM_23,
                                                    :MRASCEVDEF_N.CHG_ITEM_24,
                                                    :MRASCEVDEF_N.CHG_ITEM_25,
                                                    :MRASCEVDEF_N.CHG_ITEM_26,
                                                    :MRASCEVDEF_N.CHG_ITEM_27,
                                                    :MRASCEVDEF_N.CHG_ITEM_28,
                                                    :MRASCEVDEF_N.CHG_ITEM_29,
                                                    :MRASCEVDEF_N.CHG_ITEM_30,
                                                    :MRASCEVDEF_N.CHG_FLAG_1,
                                                    :MRASCEVDEF_N.CHG_FLAG_2,
                                                    :MRASCEVDEF_N.CHG_FLAG_3,
                                                    :MRASCEVDEF_N.CHG_FLAG_4,
                                                    :MRASCEVDEF_N.CHG_FLAG_5,
                                                    :MRASCEVDEF_N.CHG_FLAG_6,
                                                    :MRASCEVDEF_N.CHG_FLAG_7,
                                                    :MRASCEVDEF_N.CHG_FLAG_8,
                                                    :MRASCEVDEF_N.CHG_FLAG_9,
                                                    :MRASCEVDEF_N.CHG_FLAG_10,
                                                    :MRASCEVDEF_N.CHG_FLAG_11,
                                                    :MRASCEVDEF_N.CHG_FLAG_12,
                                                    :MRASCEVDEF_N.CHG_FLAG_13,
                                                    :MRASCEVDEF_N.CHG_FLAG_14,
                                                    :MRASCEVDEF_N.CHG_FLAG_15,
                                                    :MRASCEVDEF_N.CHG_FLAG_16,
                                                    :MRASCEVDEF_N.CHG_FLAG_17,
                                                    :MRASCEVDEF_N.CHG_FLAG_18,
                                                    :MRASCEVDEF_N.CHG_FLAG_19,
                                                    :MRASCEVDEF_N.CHG_FLAG_20,
                                                    :MRASCEVDEF_N.CHG_FLAG_21,
                                                    :MRASCEVDEF_N.CHG_FLAG_22,
                                                    :MRASCEVDEF_N.CHG_FLAG_23,
                                                    :MRASCEVDEF_N.CHG_FLAG_24,
                                                    :MRASCEVDEF_N.CHG_FLAG_25,
                                                    :MRASCEVDEF_N.CHG_FLAG_26,
                                                    :MRASCEVDEF_N.CHG_FLAG_27,
                                                    :MRASCEVDEF_N.CHG_FLAG_28,
                                                    :MRASCEVDEF_N.CHG_FLAG_29,
                                                    :MRASCEVDEF_N.CHG_FLAG_30,
                                                    :MRASCEVDEF_N.CHG_VALUE_1,
                                                    :MRASCEVDEF_N.CHG_VALUE_2,
                                                    :MRASCEVDEF_N.CHG_VALUE_3,
                                                    :MRASCEVDEF_N.CHG_VALUE_4,
                                                    :MRASCEVDEF_N.CHG_VALUE_5,
                                                    :MRASCEVDEF_N.CHG_VALUE_6,
                                                    :MRASCEVDEF_N.CHG_VALUE_7,
                                                    :MRASCEVDEF_N.CHG_VALUE_8,
                                                    :MRASCEVDEF_N.CHG_VALUE_9,
                                                    :MRASCEVDEF_N.CHG_VALUE_10,
                                                    :MRASCEVDEF_N.CHG_VALUE_11,
                                                    :MRASCEVDEF_N.CHG_VALUE_12,
                                                    :MRASCEVDEF_N.CHG_VALUE_13,
                                                    :MRASCEVDEF_N.CHG_VALUE_14,
                                                    :MRASCEVDEF_N.CHG_VALUE_15,
                                                    :MRASCEVDEF_N.CHG_VALUE_16,
                                                    :MRASCEVDEF_N.CHG_VALUE_17,
                                                    :MRASCEVDEF_N.CHG_VALUE_18,
                                                    :MRASCEVDEF_N.CHG_VALUE_19,
                                                    :MRASCEVDEF_N.CHG_VALUE_20,
                                                    :MRASCEVDEF_N.CHG_VALUE_21,
                                                    :MRASCEVDEF_N.CHG_VALUE_22,
                                                    :MRASCEVDEF_N.CHG_VALUE_23,
                                                    :MRASCEVDEF_N.CHG_VALUE_24,
                                                    :MRASCEVDEF_N.CHG_VALUE_25,
                                                    :MRASCEVDEF_N.CHG_VALUE_26,
                                                    :MRASCEVDEF_N.CHG_VALUE_27,
                                                    :MRASCEVDEF_N.CHG_VALUE_28,
                                                    :MRASCEVDEF_N.CHG_VALUE_29,
                                                    :MRASCEVDEF_N.CHG_VALUE_30,
                                                    :MRASCEVDEF_N.CHG_OPT_1,
                                                    :MRASCEVDEF_N.CHG_OPT_2,
                                                    :MRASCEVDEF_N.CHG_OPT_3,
                                                    :MRASCEVDEF_N.CHG_OPT_4,
                                                    :MRASCEVDEF_N.CHG_OPT_5,
                                                    :MRASCEVDEF_N.CHG_OPT_6,
                                                    :MRASCEVDEF_N.CHG_OPT_7,
                                                    :MRASCEVDEF_N.CHG_OPT_8,
                                                    :MRASCEVDEF_N.CHG_OPT_9,
                                                    :MRASCEVDEF_N.CHG_OPT_10,
                                                    :MRASCEVDEF_N.CHG_OPT_11,
                                                    :MRASCEVDEF_N.CHG_OPT_12,
                                                    :MRASCEVDEF_N.CHG_OPT_13,
                                                    :MRASCEVDEF_N.CHG_OPT_14,
                                                    :MRASCEVDEF_N.CHG_OPT_15,
                                                    :MRASCEVDEF_N.CHG_OPT_16,
                                                    :MRASCEVDEF_N.CHG_OPT_17,
                                                    :MRASCEVDEF_N.CHG_OPT_18,
                                                    :MRASCEVDEF_N.CHG_OPT_19,
                                                    :MRASCEVDEF_N.CHG_OPT_20,
                                                    :MRASCEVDEF_N.CHG_OPT_21,
                                                    :MRASCEVDEF_N.CHG_OPT_22,
                                                    :MRASCEVDEF_N.CHG_OPT_23,
                                                    :MRASCEVDEF_N.CHG_OPT_24,
                                                    :MRASCEVDEF_N.CHG_OPT_25,
                                                    :MRASCEVDEF_N.CHG_OPT_26,
                                                    :MRASCEVDEF_N.CHG_OPT_27,
                                                    :MRASCEVDEF_N.CHG_OPT_28,
                                                    :MRASCEVDEF_N.CHG_OPT_29,
                                                    :MRASCEVDEF_N.CHG_OPT_30,
                                                    :MRASCEVDEF_N.CREATE_USER_ID,
                                                    :MRASCEVDEF_N.CREATE_TIME,
                                                    :MRASCEVDEF_N.UPDATE_USER_ID,
                                                    :MRASCEVDEF_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4122;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(MRASCEVDEF_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(MRASCEVDEF_N.CRR_EVENT_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(MRASCEVDEF_N.SYSTEM_FLAG);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_1);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_2);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_3);
            sqlstm.sqhstl[6] = (unsigned int  )31;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_4);
            sqlstm.sqhstl[7] = (unsigned int  )31;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_5);
            sqlstm.sqhstl[8] = (unsigned int  )31;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_6);
            sqlstm.sqhstl[9] = (unsigned int  )31;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_7);
            sqlstm.sqhstl[10] = (unsigned int  )31;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_8);
            sqlstm.sqhstl[11] = (unsigned int  )31;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_9);
            sqlstm.sqhstl[12] = (unsigned int  )31;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_10);
            sqlstm.sqhstl[13] = (unsigned int  )31;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_11);
            sqlstm.sqhstl[14] = (unsigned int  )31;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_12);
            sqlstm.sqhstl[15] = (unsigned int  )31;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_13);
            sqlstm.sqhstl[16] = (unsigned int  )31;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_14);
            sqlstm.sqhstl[17] = (unsigned int  )31;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_15);
            sqlstm.sqhstl[18] = (unsigned int  )31;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_16);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_17);
            sqlstm.sqhstl[20] = (unsigned int  )31;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_18);
            sqlstm.sqhstl[21] = (unsigned int  )31;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_19);
            sqlstm.sqhstl[22] = (unsigned int  )31;
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_20);
            sqlstm.sqhstl[23] = (unsigned int  )31;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_21);
            sqlstm.sqhstl[24] = (unsigned int  )31;
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_22);
            sqlstm.sqhstl[25] = (unsigned int  )31;
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_23);
            sqlstm.sqhstl[26] = (unsigned int  )31;
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_24);
            sqlstm.sqhstl[27] = (unsigned int  )31;
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_25);
            sqlstm.sqhstl[28] = (unsigned int  )31;
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_26);
            sqlstm.sqhstl[29] = (unsigned int  )31;
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_27);
            sqlstm.sqhstl[30] = (unsigned int  )31;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_28);
            sqlstm.sqhstl[31] = (unsigned int  )31;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_29);
            sqlstm.sqhstl[32] = (unsigned int  )31;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(MRASCEVDEF_N.CHK_ITEM_30);
            sqlstm.sqhstl[33] = (unsigned int  )31;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_1);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_2);
            sqlstm.sqhstl[35] = (unsigned int  )2;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_3);
            sqlstm.sqhstl[36] = (unsigned int  )2;
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_4);
            sqlstm.sqhstl[37] = (unsigned int  )2;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_5);
            sqlstm.sqhstl[38] = (unsigned int  )2;
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_6);
            sqlstm.sqhstl[39] = (unsigned int  )2;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_7);
            sqlstm.sqhstl[40] = (unsigned int  )2;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_8);
            sqlstm.sqhstl[41] = (unsigned int  )2;
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_9);
            sqlstm.sqhstl[42] = (unsigned int  )2;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_10);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_11);
            sqlstm.sqhstl[44] = (unsigned int  )2;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_12);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_13);
            sqlstm.sqhstl[46] = (unsigned int  )2;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_14);
            sqlstm.sqhstl[47] = (unsigned int  )2;
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_15);
            sqlstm.sqhstl[48] = (unsigned int  )2;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_16);
            sqlstm.sqhstl[49] = (unsigned int  )2;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_17);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_18);
            sqlstm.sqhstl[51] = (unsigned int  )2;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_19);
            sqlstm.sqhstl[52] = (unsigned int  )2;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_20);
            sqlstm.sqhstl[53] = (unsigned int  )2;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_21);
            sqlstm.sqhstl[54] = (unsigned int  )2;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_22);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_23);
            sqlstm.sqhstl[56] = (unsigned int  )2;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_24);
            sqlstm.sqhstl[57] = (unsigned int  )2;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_25);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_26);
            sqlstm.sqhstl[59] = (unsigned int  )2;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_27);
            sqlstm.sqhstl[60] = (unsigned int  )2;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_28);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_29);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(MRASCEVDEF_N.CHK_FLAG_30);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_1);
            sqlstm.sqhstl[64] = (unsigned int  )31;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_2);
            sqlstm.sqhstl[65] = (unsigned int  )31;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_3);
            sqlstm.sqhstl[66] = (unsigned int  )31;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_4);
            sqlstm.sqhstl[67] = (unsigned int  )31;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_5);
            sqlstm.sqhstl[68] = (unsigned int  )31;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_6);
            sqlstm.sqhstl[69] = (unsigned int  )31;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_7);
            sqlstm.sqhstl[70] = (unsigned int  )31;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_8);
            sqlstm.sqhstl[71] = (unsigned int  )31;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_9);
            sqlstm.sqhstl[72] = (unsigned int  )31;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_10);
            sqlstm.sqhstl[73] = (unsigned int  )31;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_11);
            sqlstm.sqhstl[74] = (unsigned int  )31;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_12);
            sqlstm.sqhstl[75] = (unsigned int  )31;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_13);
            sqlstm.sqhstl[76] = (unsigned int  )31;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_14);
            sqlstm.sqhstl[77] = (unsigned int  )31;
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_15);
            sqlstm.sqhstl[78] = (unsigned int  )31;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_16);
            sqlstm.sqhstl[79] = (unsigned int  )31;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_17);
            sqlstm.sqhstl[80] = (unsigned int  )31;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_18);
            sqlstm.sqhstl[81] = (unsigned int  )31;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_19);
            sqlstm.sqhstl[82] = (unsigned int  )31;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_20);
            sqlstm.sqhstl[83] = (unsigned int  )31;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_21);
            sqlstm.sqhstl[84] = (unsigned int  )31;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_22);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_23);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_24);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_25);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_26);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_27);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_28);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_29);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(MRASCEVDEF_N.CHK_VALUE_30);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_1);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_2);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_3);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_4);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_5);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_6);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_7);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_8);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_9);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_10);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_11);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_12);
            sqlstm.sqhstl[105] = (unsigned int  )31;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_13);
            sqlstm.sqhstl[106] = (unsigned int  )31;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_14);
            sqlstm.sqhstl[107] = (unsigned int  )31;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_15);
            sqlstm.sqhstl[108] = (unsigned int  )31;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_16);
            sqlstm.sqhstl[109] = (unsigned int  )31;
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_17);
            sqlstm.sqhstl[110] = (unsigned int  )31;
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_18);
            sqlstm.sqhstl[111] = (unsigned int  )31;
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_19);
            sqlstm.sqhstl[112] = (unsigned int  )31;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_20);
            sqlstm.sqhstl[113] = (unsigned int  )31;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_21);
            sqlstm.sqhstl[114] = (unsigned int  )31;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_22);
            sqlstm.sqhstl[115] = (unsigned int  )31;
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_23);
            sqlstm.sqhstl[116] = (unsigned int  )31;
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_24);
            sqlstm.sqhstl[117] = (unsigned int  )31;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_25);
            sqlstm.sqhstl[118] = (unsigned int  )31;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_26);
            sqlstm.sqhstl[119] = (unsigned int  )31;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_27);
            sqlstm.sqhstl[120] = (unsigned int  )31;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_28);
            sqlstm.sqhstl[121] = (unsigned int  )31;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_29);
            sqlstm.sqhstl[122] = (unsigned int  )31;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(MRASCEVDEF_N.CHK_FIELD_30);
            sqlstm.sqhstl[123] = (unsigned int  )31;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_1);
            sqlstm.sqhstl[124] = (unsigned int  )31;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_2);
            sqlstm.sqhstl[125] = (unsigned int  )31;
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_3);
            sqlstm.sqhstl[126] = (unsigned int  )31;
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_4);
            sqlstm.sqhstl[127] = (unsigned int  )31;
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_5);
            sqlstm.sqhstl[128] = (unsigned int  )31;
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_6);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_7);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_8);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_9);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_10);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_11);
            sqlstm.sqhstl[134] = (unsigned int  )31;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_12);
            sqlstm.sqhstl[135] = (unsigned int  )31;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_13);
            sqlstm.sqhstl[136] = (unsigned int  )31;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_14);
            sqlstm.sqhstl[137] = (unsigned int  )31;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_15);
            sqlstm.sqhstl[138] = (unsigned int  )31;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_16);
            sqlstm.sqhstl[139] = (unsigned int  )31;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_17);
            sqlstm.sqhstl[140] = (unsigned int  )31;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_18);
            sqlstm.sqhstl[141] = (unsigned int  )31;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
            sqlstm.sqhstv[142] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_19);
            sqlstm.sqhstl[142] = (unsigned int  )31;
            sqlstm.sqhsts[142] = (         int  )0;
            sqlstm.sqindv[142] = (         void  *)0;
            sqlstm.sqinds[142] = (         int  )0;
            sqlstm.sqharm[142] = (unsigned int  )0;
            sqlstm.sqadto[142] = (unsigned short )0;
            sqlstm.sqtdso[142] = (unsigned short )0;
            sqlstm.sqhstv[143] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_20);
            sqlstm.sqhstl[143] = (unsigned int  )31;
            sqlstm.sqhsts[143] = (         int  )0;
            sqlstm.sqindv[143] = (         void  *)0;
            sqlstm.sqinds[143] = (         int  )0;
            sqlstm.sqharm[143] = (unsigned int  )0;
            sqlstm.sqadto[143] = (unsigned short )0;
            sqlstm.sqtdso[143] = (unsigned short )0;
            sqlstm.sqhstv[144] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_21);
            sqlstm.sqhstl[144] = (unsigned int  )31;
            sqlstm.sqhsts[144] = (         int  )0;
            sqlstm.sqindv[144] = (         void  *)0;
            sqlstm.sqinds[144] = (         int  )0;
            sqlstm.sqharm[144] = (unsigned int  )0;
            sqlstm.sqadto[144] = (unsigned short )0;
            sqlstm.sqtdso[144] = (unsigned short )0;
            sqlstm.sqhstv[145] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_22);
            sqlstm.sqhstl[145] = (unsigned int  )31;
            sqlstm.sqhsts[145] = (         int  )0;
            sqlstm.sqindv[145] = (         void  *)0;
            sqlstm.sqinds[145] = (         int  )0;
            sqlstm.sqharm[145] = (unsigned int  )0;
            sqlstm.sqadto[145] = (unsigned short )0;
            sqlstm.sqtdso[145] = (unsigned short )0;
            sqlstm.sqhstv[146] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_23);
            sqlstm.sqhstl[146] = (unsigned int  )31;
            sqlstm.sqhsts[146] = (         int  )0;
            sqlstm.sqindv[146] = (         void  *)0;
            sqlstm.sqinds[146] = (         int  )0;
            sqlstm.sqharm[146] = (unsigned int  )0;
            sqlstm.sqadto[146] = (unsigned short )0;
            sqlstm.sqtdso[146] = (unsigned short )0;
            sqlstm.sqhstv[147] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_24);
            sqlstm.sqhstl[147] = (unsigned int  )31;
            sqlstm.sqhsts[147] = (         int  )0;
            sqlstm.sqindv[147] = (         void  *)0;
            sqlstm.sqinds[147] = (         int  )0;
            sqlstm.sqharm[147] = (unsigned int  )0;
            sqlstm.sqadto[147] = (unsigned short )0;
            sqlstm.sqtdso[147] = (unsigned short )0;
            sqlstm.sqhstv[148] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_25);
            sqlstm.sqhstl[148] = (unsigned int  )31;
            sqlstm.sqhsts[148] = (         int  )0;
            sqlstm.sqindv[148] = (         void  *)0;
            sqlstm.sqinds[148] = (         int  )0;
            sqlstm.sqharm[148] = (unsigned int  )0;
            sqlstm.sqadto[148] = (unsigned short )0;
            sqlstm.sqtdso[148] = (unsigned short )0;
            sqlstm.sqhstv[149] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_26);
            sqlstm.sqhstl[149] = (unsigned int  )31;
            sqlstm.sqhsts[149] = (         int  )0;
            sqlstm.sqindv[149] = (         void  *)0;
            sqlstm.sqinds[149] = (         int  )0;
            sqlstm.sqharm[149] = (unsigned int  )0;
            sqlstm.sqadto[149] = (unsigned short )0;
            sqlstm.sqtdso[149] = (unsigned short )0;
            sqlstm.sqhstv[150] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_27);
            sqlstm.sqhstl[150] = (unsigned int  )31;
            sqlstm.sqhsts[150] = (         int  )0;
            sqlstm.sqindv[150] = (         void  *)0;
            sqlstm.sqinds[150] = (         int  )0;
            sqlstm.sqharm[150] = (unsigned int  )0;
            sqlstm.sqadto[150] = (unsigned short )0;
            sqlstm.sqtdso[150] = (unsigned short )0;
            sqlstm.sqhstv[151] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_28);
            sqlstm.sqhstl[151] = (unsigned int  )31;
            sqlstm.sqhsts[151] = (         int  )0;
            sqlstm.sqindv[151] = (         void  *)0;
            sqlstm.sqinds[151] = (         int  )0;
            sqlstm.sqharm[151] = (unsigned int  )0;
            sqlstm.sqadto[151] = (unsigned short )0;
            sqlstm.sqtdso[151] = (unsigned short )0;
            sqlstm.sqhstv[152] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_29);
            sqlstm.sqhstl[152] = (unsigned int  )31;
            sqlstm.sqhsts[152] = (         int  )0;
            sqlstm.sqindv[152] = (         void  *)0;
            sqlstm.sqinds[152] = (         int  )0;
            sqlstm.sqharm[152] = (unsigned int  )0;
            sqlstm.sqadto[152] = (unsigned short )0;
            sqlstm.sqtdso[152] = (unsigned short )0;
            sqlstm.sqhstv[153] = (         void  *)(MRASCEVDEF_N.CHG_ITEM_30);
            sqlstm.sqhstl[153] = (unsigned int  )31;
            sqlstm.sqhsts[153] = (         int  )0;
            sqlstm.sqindv[153] = (         void  *)0;
            sqlstm.sqinds[153] = (         int  )0;
            sqlstm.sqharm[153] = (unsigned int  )0;
            sqlstm.sqadto[153] = (unsigned short )0;
            sqlstm.sqtdso[153] = (unsigned short )0;
            sqlstm.sqhstv[154] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_1);
            sqlstm.sqhstl[154] = (unsigned int  )2;
            sqlstm.sqhsts[154] = (         int  )0;
            sqlstm.sqindv[154] = (         void  *)0;
            sqlstm.sqinds[154] = (         int  )0;
            sqlstm.sqharm[154] = (unsigned int  )0;
            sqlstm.sqadto[154] = (unsigned short )0;
            sqlstm.sqtdso[154] = (unsigned short )0;
            sqlstm.sqhstv[155] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_2);
            sqlstm.sqhstl[155] = (unsigned int  )2;
            sqlstm.sqhsts[155] = (         int  )0;
            sqlstm.sqindv[155] = (         void  *)0;
            sqlstm.sqinds[155] = (         int  )0;
            sqlstm.sqharm[155] = (unsigned int  )0;
            sqlstm.sqadto[155] = (unsigned short )0;
            sqlstm.sqtdso[155] = (unsigned short )0;
            sqlstm.sqhstv[156] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_3);
            sqlstm.sqhstl[156] = (unsigned int  )2;
            sqlstm.sqhsts[156] = (         int  )0;
            sqlstm.sqindv[156] = (         void  *)0;
            sqlstm.sqinds[156] = (         int  )0;
            sqlstm.sqharm[156] = (unsigned int  )0;
            sqlstm.sqadto[156] = (unsigned short )0;
            sqlstm.sqtdso[156] = (unsigned short )0;
            sqlstm.sqhstv[157] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_4);
            sqlstm.sqhstl[157] = (unsigned int  )2;
            sqlstm.sqhsts[157] = (         int  )0;
            sqlstm.sqindv[157] = (         void  *)0;
            sqlstm.sqinds[157] = (         int  )0;
            sqlstm.sqharm[157] = (unsigned int  )0;
            sqlstm.sqadto[157] = (unsigned short )0;
            sqlstm.sqtdso[157] = (unsigned short )0;
            sqlstm.sqhstv[158] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_5);
            sqlstm.sqhstl[158] = (unsigned int  )2;
            sqlstm.sqhsts[158] = (         int  )0;
            sqlstm.sqindv[158] = (         void  *)0;
            sqlstm.sqinds[158] = (         int  )0;
            sqlstm.sqharm[158] = (unsigned int  )0;
            sqlstm.sqadto[158] = (unsigned short )0;
            sqlstm.sqtdso[158] = (unsigned short )0;
            sqlstm.sqhstv[159] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_6);
            sqlstm.sqhstl[159] = (unsigned int  )2;
            sqlstm.sqhsts[159] = (         int  )0;
            sqlstm.sqindv[159] = (         void  *)0;
            sqlstm.sqinds[159] = (         int  )0;
            sqlstm.sqharm[159] = (unsigned int  )0;
            sqlstm.sqadto[159] = (unsigned short )0;
            sqlstm.sqtdso[159] = (unsigned short )0;
            sqlstm.sqhstv[160] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_7);
            sqlstm.sqhstl[160] = (unsigned int  )2;
            sqlstm.sqhsts[160] = (         int  )0;
            sqlstm.sqindv[160] = (         void  *)0;
            sqlstm.sqinds[160] = (         int  )0;
            sqlstm.sqharm[160] = (unsigned int  )0;
            sqlstm.sqadto[160] = (unsigned short )0;
            sqlstm.sqtdso[160] = (unsigned short )0;
            sqlstm.sqhstv[161] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_8);
            sqlstm.sqhstl[161] = (unsigned int  )2;
            sqlstm.sqhsts[161] = (         int  )0;
            sqlstm.sqindv[161] = (         void  *)0;
            sqlstm.sqinds[161] = (         int  )0;
            sqlstm.sqharm[161] = (unsigned int  )0;
            sqlstm.sqadto[161] = (unsigned short )0;
            sqlstm.sqtdso[161] = (unsigned short )0;
            sqlstm.sqhstv[162] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_9);
            sqlstm.sqhstl[162] = (unsigned int  )2;
            sqlstm.sqhsts[162] = (         int  )0;
            sqlstm.sqindv[162] = (         void  *)0;
            sqlstm.sqinds[162] = (         int  )0;
            sqlstm.sqharm[162] = (unsigned int  )0;
            sqlstm.sqadto[162] = (unsigned short )0;
            sqlstm.sqtdso[162] = (unsigned short )0;
            sqlstm.sqhstv[163] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_10);
            sqlstm.sqhstl[163] = (unsigned int  )2;
            sqlstm.sqhsts[163] = (         int  )0;
            sqlstm.sqindv[163] = (         void  *)0;
            sqlstm.sqinds[163] = (         int  )0;
            sqlstm.sqharm[163] = (unsigned int  )0;
            sqlstm.sqadto[163] = (unsigned short )0;
            sqlstm.sqtdso[163] = (unsigned short )0;
            sqlstm.sqhstv[164] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_11);
            sqlstm.sqhstl[164] = (unsigned int  )2;
            sqlstm.sqhsts[164] = (         int  )0;
            sqlstm.sqindv[164] = (         void  *)0;
            sqlstm.sqinds[164] = (         int  )0;
            sqlstm.sqharm[164] = (unsigned int  )0;
            sqlstm.sqadto[164] = (unsigned short )0;
            sqlstm.sqtdso[164] = (unsigned short )0;
            sqlstm.sqhstv[165] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_12);
            sqlstm.sqhstl[165] = (unsigned int  )2;
            sqlstm.sqhsts[165] = (         int  )0;
            sqlstm.sqindv[165] = (         void  *)0;
            sqlstm.sqinds[165] = (         int  )0;
            sqlstm.sqharm[165] = (unsigned int  )0;
            sqlstm.sqadto[165] = (unsigned short )0;
            sqlstm.sqtdso[165] = (unsigned short )0;
            sqlstm.sqhstv[166] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_13);
            sqlstm.sqhstl[166] = (unsigned int  )2;
            sqlstm.sqhsts[166] = (         int  )0;
            sqlstm.sqindv[166] = (         void  *)0;
            sqlstm.sqinds[166] = (         int  )0;
            sqlstm.sqharm[166] = (unsigned int  )0;
            sqlstm.sqadto[166] = (unsigned short )0;
            sqlstm.sqtdso[166] = (unsigned short )0;
            sqlstm.sqhstv[167] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_14);
            sqlstm.sqhstl[167] = (unsigned int  )2;
            sqlstm.sqhsts[167] = (         int  )0;
            sqlstm.sqindv[167] = (         void  *)0;
            sqlstm.sqinds[167] = (         int  )0;
            sqlstm.sqharm[167] = (unsigned int  )0;
            sqlstm.sqadto[167] = (unsigned short )0;
            sqlstm.sqtdso[167] = (unsigned short )0;
            sqlstm.sqhstv[168] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_15);
            sqlstm.sqhstl[168] = (unsigned int  )2;
            sqlstm.sqhsts[168] = (         int  )0;
            sqlstm.sqindv[168] = (         void  *)0;
            sqlstm.sqinds[168] = (         int  )0;
            sqlstm.sqharm[168] = (unsigned int  )0;
            sqlstm.sqadto[168] = (unsigned short )0;
            sqlstm.sqtdso[168] = (unsigned short )0;
            sqlstm.sqhstv[169] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_16);
            sqlstm.sqhstl[169] = (unsigned int  )2;
            sqlstm.sqhsts[169] = (         int  )0;
            sqlstm.sqindv[169] = (         void  *)0;
            sqlstm.sqinds[169] = (         int  )0;
            sqlstm.sqharm[169] = (unsigned int  )0;
            sqlstm.sqadto[169] = (unsigned short )0;
            sqlstm.sqtdso[169] = (unsigned short )0;
            sqlstm.sqhstv[170] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_17);
            sqlstm.sqhstl[170] = (unsigned int  )2;
            sqlstm.sqhsts[170] = (         int  )0;
            sqlstm.sqindv[170] = (         void  *)0;
            sqlstm.sqinds[170] = (         int  )0;
            sqlstm.sqharm[170] = (unsigned int  )0;
            sqlstm.sqadto[170] = (unsigned short )0;
            sqlstm.sqtdso[170] = (unsigned short )0;
            sqlstm.sqhstv[171] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_18);
            sqlstm.sqhstl[171] = (unsigned int  )2;
            sqlstm.sqhsts[171] = (         int  )0;
            sqlstm.sqindv[171] = (         void  *)0;
            sqlstm.sqinds[171] = (         int  )0;
            sqlstm.sqharm[171] = (unsigned int  )0;
            sqlstm.sqadto[171] = (unsigned short )0;
            sqlstm.sqtdso[171] = (unsigned short )0;
            sqlstm.sqhstv[172] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_19);
            sqlstm.sqhstl[172] = (unsigned int  )2;
            sqlstm.sqhsts[172] = (         int  )0;
            sqlstm.sqindv[172] = (         void  *)0;
            sqlstm.sqinds[172] = (         int  )0;
            sqlstm.sqharm[172] = (unsigned int  )0;
            sqlstm.sqadto[172] = (unsigned short )0;
            sqlstm.sqtdso[172] = (unsigned short )0;
            sqlstm.sqhstv[173] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_20);
            sqlstm.sqhstl[173] = (unsigned int  )2;
            sqlstm.sqhsts[173] = (         int  )0;
            sqlstm.sqindv[173] = (         void  *)0;
            sqlstm.sqinds[173] = (         int  )0;
            sqlstm.sqharm[173] = (unsigned int  )0;
            sqlstm.sqadto[173] = (unsigned short )0;
            sqlstm.sqtdso[173] = (unsigned short )0;
            sqlstm.sqhstv[174] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_21);
            sqlstm.sqhstl[174] = (unsigned int  )2;
            sqlstm.sqhsts[174] = (         int  )0;
            sqlstm.sqindv[174] = (         void  *)0;
            sqlstm.sqinds[174] = (         int  )0;
            sqlstm.sqharm[174] = (unsigned int  )0;
            sqlstm.sqadto[174] = (unsigned short )0;
            sqlstm.sqtdso[174] = (unsigned short )0;
            sqlstm.sqhstv[175] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_22);
            sqlstm.sqhstl[175] = (unsigned int  )2;
            sqlstm.sqhsts[175] = (         int  )0;
            sqlstm.sqindv[175] = (         void  *)0;
            sqlstm.sqinds[175] = (         int  )0;
            sqlstm.sqharm[175] = (unsigned int  )0;
            sqlstm.sqadto[175] = (unsigned short )0;
            sqlstm.sqtdso[175] = (unsigned short )0;
            sqlstm.sqhstv[176] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_23);
            sqlstm.sqhstl[176] = (unsigned int  )2;
            sqlstm.sqhsts[176] = (         int  )0;
            sqlstm.sqindv[176] = (         void  *)0;
            sqlstm.sqinds[176] = (         int  )0;
            sqlstm.sqharm[176] = (unsigned int  )0;
            sqlstm.sqadto[176] = (unsigned short )0;
            sqlstm.sqtdso[176] = (unsigned short )0;
            sqlstm.sqhstv[177] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_24);
            sqlstm.sqhstl[177] = (unsigned int  )2;
            sqlstm.sqhsts[177] = (         int  )0;
            sqlstm.sqindv[177] = (         void  *)0;
            sqlstm.sqinds[177] = (         int  )0;
            sqlstm.sqharm[177] = (unsigned int  )0;
            sqlstm.sqadto[177] = (unsigned short )0;
            sqlstm.sqtdso[177] = (unsigned short )0;
            sqlstm.sqhstv[178] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_25);
            sqlstm.sqhstl[178] = (unsigned int  )2;
            sqlstm.sqhsts[178] = (         int  )0;
            sqlstm.sqindv[178] = (         void  *)0;
            sqlstm.sqinds[178] = (         int  )0;
            sqlstm.sqharm[178] = (unsigned int  )0;
            sqlstm.sqadto[178] = (unsigned short )0;
            sqlstm.sqtdso[178] = (unsigned short )0;
            sqlstm.sqhstv[179] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_26);
            sqlstm.sqhstl[179] = (unsigned int  )2;
            sqlstm.sqhsts[179] = (         int  )0;
            sqlstm.sqindv[179] = (         void  *)0;
            sqlstm.sqinds[179] = (         int  )0;
            sqlstm.sqharm[179] = (unsigned int  )0;
            sqlstm.sqadto[179] = (unsigned short )0;
            sqlstm.sqtdso[179] = (unsigned short )0;
            sqlstm.sqhstv[180] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_27);
            sqlstm.sqhstl[180] = (unsigned int  )2;
            sqlstm.sqhsts[180] = (         int  )0;
            sqlstm.sqindv[180] = (         void  *)0;
            sqlstm.sqinds[180] = (         int  )0;
            sqlstm.sqharm[180] = (unsigned int  )0;
            sqlstm.sqadto[180] = (unsigned short )0;
            sqlstm.sqtdso[180] = (unsigned short )0;
            sqlstm.sqhstv[181] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_28);
            sqlstm.sqhstl[181] = (unsigned int  )2;
            sqlstm.sqhsts[181] = (         int  )0;
            sqlstm.sqindv[181] = (         void  *)0;
            sqlstm.sqinds[181] = (         int  )0;
            sqlstm.sqharm[181] = (unsigned int  )0;
            sqlstm.sqadto[181] = (unsigned short )0;
            sqlstm.sqtdso[181] = (unsigned short )0;
            sqlstm.sqhstv[182] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_29);
            sqlstm.sqhstl[182] = (unsigned int  )2;
            sqlstm.sqhsts[182] = (         int  )0;
            sqlstm.sqindv[182] = (         void  *)0;
            sqlstm.sqinds[182] = (         int  )0;
            sqlstm.sqharm[182] = (unsigned int  )0;
            sqlstm.sqadto[182] = (unsigned short )0;
            sqlstm.sqtdso[182] = (unsigned short )0;
            sqlstm.sqhstv[183] = (         void  *)(MRASCEVDEF_N.CHG_FLAG_30);
            sqlstm.sqhstl[183] = (unsigned int  )2;
            sqlstm.sqhsts[183] = (         int  )0;
            sqlstm.sqindv[183] = (         void  *)0;
            sqlstm.sqinds[183] = (         int  )0;
            sqlstm.sqharm[183] = (unsigned int  )0;
            sqlstm.sqadto[183] = (unsigned short )0;
            sqlstm.sqtdso[183] = (unsigned short )0;
            sqlstm.sqhstv[184] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_1);
            sqlstm.sqhstl[184] = (unsigned int  )31;
            sqlstm.sqhsts[184] = (         int  )0;
            sqlstm.sqindv[184] = (         void  *)0;
            sqlstm.sqinds[184] = (         int  )0;
            sqlstm.sqharm[184] = (unsigned int  )0;
            sqlstm.sqadto[184] = (unsigned short )0;
            sqlstm.sqtdso[184] = (unsigned short )0;
            sqlstm.sqhstv[185] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_2);
            sqlstm.sqhstl[185] = (unsigned int  )31;
            sqlstm.sqhsts[185] = (         int  )0;
            sqlstm.sqindv[185] = (         void  *)0;
            sqlstm.sqinds[185] = (         int  )0;
            sqlstm.sqharm[185] = (unsigned int  )0;
            sqlstm.sqadto[185] = (unsigned short )0;
            sqlstm.sqtdso[185] = (unsigned short )0;
            sqlstm.sqhstv[186] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_3);
            sqlstm.sqhstl[186] = (unsigned int  )31;
            sqlstm.sqhsts[186] = (         int  )0;
            sqlstm.sqindv[186] = (         void  *)0;
            sqlstm.sqinds[186] = (         int  )0;
            sqlstm.sqharm[186] = (unsigned int  )0;
            sqlstm.sqadto[186] = (unsigned short )0;
            sqlstm.sqtdso[186] = (unsigned short )0;
            sqlstm.sqhstv[187] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_4);
            sqlstm.sqhstl[187] = (unsigned int  )31;
            sqlstm.sqhsts[187] = (         int  )0;
            sqlstm.sqindv[187] = (         void  *)0;
            sqlstm.sqinds[187] = (         int  )0;
            sqlstm.sqharm[187] = (unsigned int  )0;
            sqlstm.sqadto[187] = (unsigned short )0;
            sqlstm.sqtdso[187] = (unsigned short )0;
            sqlstm.sqhstv[188] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_5);
            sqlstm.sqhstl[188] = (unsigned int  )31;
            sqlstm.sqhsts[188] = (         int  )0;
            sqlstm.sqindv[188] = (         void  *)0;
            sqlstm.sqinds[188] = (         int  )0;
            sqlstm.sqharm[188] = (unsigned int  )0;
            sqlstm.sqadto[188] = (unsigned short )0;
            sqlstm.sqtdso[188] = (unsigned short )0;
            sqlstm.sqhstv[189] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_6);
            sqlstm.sqhstl[189] = (unsigned int  )31;
            sqlstm.sqhsts[189] = (         int  )0;
            sqlstm.sqindv[189] = (         void  *)0;
            sqlstm.sqinds[189] = (         int  )0;
            sqlstm.sqharm[189] = (unsigned int  )0;
            sqlstm.sqadto[189] = (unsigned short )0;
            sqlstm.sqtdso[189] = (unsigned short )0;
            sqlstm.sqhstv[190] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_7);
            sqlstm.sqhstl[190] = (unsigned int  )31;
            sqlstm.sqhsts[190] = (         int  )0;
            sqlstm.sqindv[190] = (         void  *)0;
            sqlstm.sqinds[190] = (         int  )0;
            sqlstm.sqharm[190] = (unsigned int  )0;
            sqlstm.sqadto[190] = (unsigned short )0;
            sqlstm.sqtdso[190] = (unsigned short )0;
            sqlstm.sqhstv[191] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_8);
            sqlstm.sqhstl[191] = (unsigned int  )31;
            sqlstm.sqhsts[191] = (         int  )0;
            sqlstm.sqindv[191] = (         void  *)0;
            sqlstm.sqinds[191] = (         int  )0;
            sqlstm.sqharm[191] = (unsigned int  )0;
            sqlstm.sqadto[191] = (unsigned short )0;
            sqlstm.sqtdso[191] = (unsigned short )0;
            sqlstm.sqhstv[192] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_9);
            sqlstm.sqhstl[192] = (unsigned int  )31;
            sqlstm.sqhsts[192] = (         int  )0;
            sqlstm.sqindv[192] = (         void  *)0;
            sqlstm.sqinds[192] = (         int  )0;
            sqlstm.sqharm[192] = (unsigned int  )0;
            sqlstm.sqadto[192] = (unsigned short )0;
            sqlstm.sqtdso[192] = (unsigned short )0;
            sqlstm.sqhstv[193] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_10);
            sqlstm.sqhstl[193] = (unsigned int  )31;
            sqlstm.sqhsts[193] = (         int  )0;
            sqlstm.sqindv[193] = (         void  *)0;
            sqlstm.sqinds[193] = (         int  )0;
            sqlstm.sqharm[193] = (unsigned int  )0;
            sqlstm.sqadto[193] = (unsigned short )0;
            sqlstm.sqtdso[193] = (unsigned short )0;
            sqlstm.sqhstv[194] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_11);
            sqlstm.sqhstl[194] = (unsigned int  )31;
            sqlstm.sqhsts[194] = (         int  )0;
            sqlstm.sqindv[194] = (         void  *)0;
            sqlstm.sqinds[194] = (         int  )0;
            sqlstm.sqharm[194] = (unsigned int  )0;
            sqlstm.sqadto[194] = (unsigned short )0;
            sqlstm.sqtdso[194] = (unsigned short )0;
            sqlstm.sqhstv[195] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_12);
            sqlstm.sqhstl[195] = (unsigned int  )31;
            sqlstm.sqhsts[195] = (         int  )0;
            sqlstm.sqindv[195] = (         void  *)0;
            sqlstm.sqinds[195] = (         int  )0;
            sqlstm.sqharm[195] = (unsigned int  )0;
            sqlstm.sqadto[195] = (unsigned short )0;
            sqlstm.sqtdso[195] = (unsigned short )0;
            sqlstm.sqhstv[196] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_13);
            sqlstm.sqhstl[196] = (unsigned int  )31;
            sqlstm.sqhsts[196] = (         int  )0;
            sqlstm.sqindv[196] = (         void  *)0;
            sqlstm.sqinds[196] = (         int  )0;
            sqlstm.sqharm[196] = (unsigned int  )0;
            sqlstm.sqadto[196] = (unsigned short )0;
            sqlstm.sqtdso[196] = (unsigned short )0;
            sqlstm.sqhstv[197] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_14);
            sqlstm.sqhstl[197] = (unsigned int  )31;
            sqlstm.sqhsts[197] = (         int  )0;
            sqlstm.sqindv[197] = (         void  *)0;
            sqlstm.sqinds[197] = (         int  )0;
            sqlstm.sqharm[197] = (unsigned int  )0;
            sqlstm.sqadto[197] = (unsigned short )0;
            sqlstm.sqtdso[197] = (unsigned short )0;
            sqlstm.sqhstv[198] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_15);
            sqlstm.sqhstl[198] = (unsigned int  )31;
            sqlstm.sqhsts[198] = (         int  )0;
            sqlstm.sqindv[198] = (         void  *)0;
            sqlstm.sqinds[198] = (         int  )0;
            sqlstm.sqharm[198] = (unsigned int  )0;
            sqlstm.sqadto[198] = (unsigned short )0;
            sqlstm.sqtdso[198] = (unsigned short )0;
            sqlstm.sqhstv[199] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_16);
            sqlstm.sqhstl[199] = (unsigned int  )31;
            sqlstm.sqhsts[199] = (         int  )0;
            sqlstm.sqindv[199] = (         void  *)0;
            sqlstm.sqinds[199] = (         int  )0;
            sqlstm.sqharm[199] = (unsigned int  )0;
            sqlstm.sqadto[199] = (unsigned short )0;
            sqlstm.sqtdso[199] = (unsigned short )0;
            sqlstm.sqhstv[200] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_17);
            sqlstm.sqhstl[200] = (unsigned int  )31;
            sqlstm.sqhsts[200] = (         int  )0;
            sqlstm.sqindv[200] = (         void  *)0;
            sqlstm.sqinds[200] = (         int  )0;
            sqlstm.sqharm[200] = (unsigned int  )0;
            sqlstm.sqadto[200] = (unsigned short )0;
            sqlstm.sqtdso[200] = (unsigned short )0;
            sqlstm.sqhstv[201] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_18);
            sqlstm.sqhstl[201] = (unsigned int  )31;
            sqlstm.sqhsts[201] = (         int  )0;
            sqlstm.sqindv[201] = (         void  *)0;
            sqlstm.sqinds[201] = (         int  )0;
            sqlstm.sqharm[201] = (unsigned int  )0;
            sqlstm.sqadto[201] = (unsigned short )0;
            sqlstm.sqtdso[201] = (unsigned short )0;
            sqlstm.sqhstv[202] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_19);
            sqlstm.sqhstl[202] = (unsigned int  )31;
            sqlstm.sqhsts[202] = (         int  )0;
            sqlstm.sqindv[202] = (         void  *)0;
            sqlstm.sqinds[202] = (         int  )0;
            sqlstm.sqharm[202] = (unsigned int  )0;
            sqlstm.sqadto[202] = (unsigned short )0;
            sqlstm.sqtdso[202] = (unsigned short )0;
            sqlstm.sqhstv[203] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_20);
            sqlstm.sqhstl[203] = (unsigned int  )31;
            sqlstm.sqhsts[203] = (         int  )0;
            sqlstm.sqindv[203] = (         void  *)0;
            sqlstm.sqinds[203] = (         int  )0;
            sqlstm.sqharm[203] = (unsigned int  )0;
            sqlstm.sqadto[203] = (unsigned short )0;
            sqlstm.sqtdso[203] = (unsigned short )0;
            sqlstm.sqhstv[204] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_21);
            sqlstm.sqhstl[204] = (unsigned int  )31;
            sqlstm.sqhsts[204] = (         int  )0;
            sqlstm.sqindv[204] = (         void  *)0;
            sqlstm.sqinds[204] = (         int  )0;
            sqlstm.sqharm[204] = (unsigned int  )0;
            sqlstm.sqadto[204] = (unsigned short )0;
            sqlstm.sqtdso[204] = (unsigned short )0;
            sqlstm.sqhstv[205] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_22);
            sqlstm.sqhstl[205] = (unsigned int  )31;
            sqlstm.sqhsts[205] = (         int  )0;
            sqlstm.sqindv[205] = (         void  *)0;
            sqlstm.sqinds[205] = (         int  )0;
            sqlstm.sqharm[205] = (unsigned int  )0;
            sqlstm.sqadto[205] = (unsigned short )0;
            sqlstm.sqtdso[205] = (unsigned short )0;
            sqlstm.sqhstv[206] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_23);
            sqlstm.sqhstl[206] = (unsigned int  )31;
            sqlstm.sqhsts[206] = (         int  )0;
            sqlstm.sqindv[206] = (         void  *)0;
            sqlstm.sqinds[206] = (         int  )0;
            sqlstm.sqharm[206] = (unsigned int  )0;
            sqlstm.sqadto[206] = (unsigned short )0;
            sqlstm.sqtdso[206] = (unsigned short )0;
            sqlstm.sqhstv[207] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_24);
            sqlstm.sqhstl[207] = (unsigned int  )31;
            sqlstm.sqhsts[207] = (         int  )0;
            sqlstm.sqindv[207] = (         void  *)0;
            sqlstm.sqinds[207] = (         int  )0;
            sqlstm.sqharm[207] = (unsigned int  )0;
            sqlstm.sqadto[207] = (unsigned short )0;
            sqlstm.sqtdso[207] = (unsigned short )0;
            sqlstm.sqhstv[208] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_25);
            sqlstm.sqhstl[208] = (unsigned int  )31;
            sqlstm.sqhsts[208] = (         int  )0;
            sqlstm.sqindv[208] = (         void  *)0;
            sqlstm.sqinds[208] = (         int  )0;
            sqlstm.sqharm[208] = (unsigned int  )0;
            sqlstm.sqadto[208] = (unsigned short )0;
            sqlstm.sqtdso[208] = (unsigned short )0;
            sqlstm.sqhstv[209] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_26);
            sqlstm.sqhstl[209] = (unsigned int  )31;
            sqlstm.sqhsts[209] = (         int  )0;
            sqlstm.sqindv[209] = (         void  *)0;
            sqlstm.sqinds[209] = (         int  )0;
            sqlstm.sqharm[209] = (unsigned int  )0;
            sqlstm.sqadto[209] = (unsigned short )0;
            sqlstm.sqtdso[209] = (unsigned short )0;
            sqlstm.sqhstv[210] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_27);
            sqlstm.sqhstl[210] = (unsigned int  )31;
            sqlstm.sqhsts[210] = (         int  )0;
            sqlstm.sqindv[210] = (         void  *)0;
            sqlstm.sqinds[210] = (         int  )0;
            sqlstm.sqharm[210] = (unsigned int  )0;
            sqlstm.sqadto[210] = (unsigned short )0;
            sqlstm.sqtdso[210] = (unsigned short )0;
            sqlstm.sqhstv[211] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_28);
            sqlstm.sqhstl[211] = (unsigned int  )31;
            sqlstm.sqhsts[211] = (         int  )0;
            sqlstm.sqindv[211] = (         void  *)0;
            sqlstm.sqinds[211] = (         int  )0;
            sqlstm.sqharm[211] = (unsigned int  )0;
            sqlstm.sqadto[211] = (unsigned short )0;
            sqlstm.sqtdso[211] = (unsigned short )0;
            sqlstm.sqhstv[212] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_29);
            sqlstm.sqhstl[212] = (unsigned int  )31;
            sqlstm.sqhsts[212] = (         int  )0;
            sqlstm.sqindv[212] = (         void  *)0;
            sqlstm.sqinds[212] = (         int  )0;
            sqlstm.sqharm[212] = (unsigned int  )0;
            sqlstm.sqadto[212] = (unsigned short )0;
            sqlstm.sqtdso[212] = (unsigned short )0;
            sqlstm.sqhstv[213] = (         void  *)(MRASCEVDEF_N.CHG_VALUE_30);
            sqlstm.sqhstl[213] = (unsigned int  )31;
            sqlstm.sqhsts[213] = (         int  )0;
            sqlstm.sqindv[213] = (         void  *)0;
            sqlstm.sqinds[213] = (         int  )0;
            sqlstm.sqharm[213] = (unsigned int  )0;
            sqlstm.sqadto[213] = (unsigned short )0;
            sqlstm.sqtdso[213] = (unsigned short )0;
            sqlstm.sqhstv[214] = (         void  *)(MRASCEVDEF_N.CHG_OPT_1);
            sqlstm.sqhstl[214] = (unsigned int  )2;
            sqlstm.sqhsts[214] = (         int  )0;
            sqlstm.sqindv[214] = (         void  *)0;
            sqlstm.sqinds[214] = (         int  )0;
            sqlstm.sqharm[214] = (unsigned int  )0;
            sqlstm.sqadto[214] = (unsigned short )0;
            sqlstm.sqtdso[214] = (unsigned short )0;
            sqlstm.sqhstv[215] = (         void  *)(MRASCEVDEF_N.CHG_OPT_2);
            sqlstm.sqhstl[215] = (unsigned int  )2;
            sqlstm.sqhsts[215] = (         int  )0;
            sqlstm.sqindv[215] = (         void  *)0;
            sqlstm.sqinds[215] = (         int  )0;
            sqlstm.sqharm[215] = (unsigned int  )0;
            sqlstm.sqadto[215] = (unsigned short )0;
            sqlstm.sqtdso[215] = (unsigned short )0;
            sqlstm.sqhstv[216] = (         void  *)(MRASCEVDEF_N.CHG_OPT_3);
            sqlstm.sqhstl[216] = (unsigned int  )2;
            sqlstm.sqhsts[216] = (         int  )0;
            sqlstm.sqindv[216] = (         void  *)0;
            sqlstm.sqinds[216] = (         int  )0;
            sqlstm.sqharm[216] = (unsigned int  )0;
            sqlstm.sqadto[216] = (unsigned short )0;
            sqlstm.sqtdso[216] = (unsigned short )0;
            sqlstm.sqhstv[217] = (         void  *)(MRASCEVDEF_N.CHG_OPT_4);
            sqlstm.sqhstl[217] = (unsigned int  )2;
            sqlstm.sqhsts[217] = (         int  )0;
            sqlstm.sqindv[217] = (         void  *)0;
            sqlstm.sqinds[217] = (         int  )0;
            sqlstm.sqharm[217] = (unsigned int  )0;
            sqlstm.sqadto[217] = (unsigned short )0;
            sqlstm.sqtdso[217] = (unsigned short )0;
            sqlstm.sqhstv[218] = (         void  *)(MRASCEVDEF_N.CHG_OPT_5);
            sqlstm.sqhstl[218] = (unsigned int  )2;
            sqlstm.sqhsts[218] = (         int  )0;
            sqlstm.sqindv[218] = (         void  *)0;
            sqlstm.sqinds[218] = (         int  )0;
            sqlstm.sqharm[218] = (unsigned int  )0;
            sqlstm.sqadto[218] = (unsigned short )0;
            sqlstm.sqtdso[218] = (unsigned short )0;
            sqlstm.sqhstv[219] = (         void  *)(MRASCEVDEF_N.CHG_OPT_6);
            sqlstm.sqhstl[219] = (unsigned int  )2;
            sqlstm.sqhsts[219] = (         int  )0;
            sqlstm.sqindv[219] = (         void  *)0;
            sqlstm.sqinds[219] = (         int  )0;
            sqlstm.sqharm[219] = (unsigned int  )0;
            sqlstm.sqadto[219] = (unsigned short )0;
            sqlstm.sqtdso[219] = (unsigned short )0;
            sqlstm.sqhstv[220] = (         void  *)(MRASCEVDEF_N.CHG_OPT_7);
            sqlstm.sqhstl[220] = (unsigned int  )2;
            sqlstm.sqhsts[220] = (         int  )0;
            sqlstm.sqindv[220] = (         void  *)0;
            sqlstm.sqinds[220] = (         int  )0;
            sqlstm.sqharm[220] = (unsigned int  )0;
            sqlstm.sqadto[220] = (unsigned short )0;
            sqlstm.sqtdso[220] = (unsigned short )0;
            sqlstm.sqhstv[221] = (         void  *)(MRASCEVDEF_N.CHG_OPT_8);
            sqlstm.sqhstl[221] = (unsigned int  )2;
            sqlstm.sqhsts[221] = (         int  )0;
            sqlstm.sqindv[221] = (         void  *)0;
            sqlstm.sqinds[221] = (         int  )0;
            sqlstm.sqharm[221] = (unsigned int  )0;
            sqlstm.sqadto[221] = (unsigned short )0;
            sqlstm.sqtdso[221] = (unsigned short )0;
            sqlstm.sqhstv[222] = (         void  *)(MRASCEVDEF_N.CHG_OPT_9);
            sqlstm.sqhstl[222] = (unsigned int  )2;
            sqlstm.sqhsts[222] = (         int  )0;
            sqlstm.sqindv[222] = (         void  *)0;
            sqlstm.sqinds[222] = (         int  )0;
            sqlstm.sqharm[222] = (unsigned int  )0;
            sqlstm.sqadto[222] = (unsigned short )0;
            sqlstm.sqtdso[222] = (unsigned short )0;
            sqlstm.sqhstv[223] = (         void  *)(MRASCEVDEF_N.CHG_OPT_10);
            sqlstm.sqhstl[223] = (unsigned int  )2;
            sqlstm.sqhsts[223] = (         int  )0;
            sqlstm.sqindv[223] = (         void  *)0;
            sqlstm.sqinds[223] = (         int  )0;
            sqlstm.sqharm[223] = (unsigned int  )0;
            sqlstm.sqadto[223] = (unsigned short )0;
            sqlstm.sqtdso[223] = (unsigned short )0;
            sqlstm.sqhstv[224] = (         void  *)(MRASCEVDEF_N.CHG_OPT_11);
            sqlstm.sqhstl[224] = (unsigned int  )2;
            sqlstm.sqhsts[224] = (         int  )0;
            sqlstm.sqindv[224] = (         void  *)0;
            sqlstm.sqinds[224] = (         int  )0;
            sqlstm.sqharm[224] = (unsigned int  )0;
            sqlstm.sqadto[224] = (unsigned short )0;
            sqlstm.sqtdso[224] = (unsigned short )0;
            sqlstm.sqhstv[225] = (         void  *)(MRASCEVDEF_N.CHG_OPT_12);
            sqlstm.sqhstl[225] = (unsigned int  )2;
            sqlstm.sqhsts[225] = (         int  )0;
            sqlstm.sqindv[225] = (         void  *)0;
            sqlstm.sqinds[225] = (         int  )0;
            sqlstm.sqharm[225] = (unsigned int  )0;
            sqlstm.sqadto[225] = (unsigned short )0;
            sqlstm.sqtdso[225] = (unsigned short )0;
            sqlstm.sqhstv[226] = (         void  *)(MRASCEVDEF_N.CHG_OPT_13);
            sqlstm.sqhstl[226] = (unsigned int  )2;
            sqlstm.sqhsts[226] = (         int  )0;
            sqlstm.sqindv[226] = (         void  *)0;
            sqlstm.sqinds[226] = (         int  )0;
            sqlstm.sqharm[226] = (unsigned int  )0;
            sqlstm.sqadto[226] = (unsigned short )0;
            sqlstm.sqtdso[226] = (unsigned short )0;
            sqlstm.sqhstv[227] = (         void  *)(MRASCEVDEF_N.CHG_OPT_14);
            sqlstm.sqhstl[227] = (unsigned int  )2;
            sqlstm.sqhsts[227] = (         int  )0;
            sqlstm.sqindv[227] = (         void  *)0;
            sqlstm.sqinds[227] = (         int  )0;
            sqlstm.sqharm[227] = (unsigned int  )0;
            sqlstm.sqadto[227] = (unsigned short )0;
            sqlstm.sqtdso[227] = (unsigned short )0;
            sqlstm.sqhstv[228] = (         void  *)(MRASCEVDEF_N.CHG_OPT_15);
            sqlstm.sqhstl[228] = (unsigned int  )2;
            sqlstm.sqhsts[228] = (         int  )0;
            sqlstm.sqindv[228] = (         void  *)0;
            sqlstm.sqinds[228] = (         int  )0;
            sqlstm.sqharm[228] = (unsigned int  )0;
            sqlstm.sqadto[228] = (unsigned short )0;
            sqlstm.sqtdso[228] = (unsigned short )0;
            sqlstm.sqhstv[229] = (         void  *)(MRASCEVDEF_N.CHG_OPT_16);
            sqlstm.sqhstl[229] = (unsigned int  )2;
            sqlstm.sqhsts[229] = (         int  )0;
            sqlstm.sqindv[229] = (         void  *)0;
            sqlstm.sqinds[229] = (         int  )0;
            sqlstm.sqharm[229] = (unsigned int  )0;
            sqlstm.sqadto[229] = (unsigned short )0;
            sqlstm.sqtdso[229] = (unsigned short )0;
            sqlstm.sqhstv[230] = (         void  *)(MRASCEVDEF_N.CHG_OPT_17);
            sqlstm.sqhstl[230] = (unsigned int  )2;
            sqlstm.sqhsts[230] = (         int  )0;
            sqlstm.sqindv[230] = (         void  *)0;
            sqlstm.sqinds[230] = (         int  )0;
            sqlstm.sqharm[230] = (unsigned int  )0;
            sqlstm.sqadto[230] = (unsigned short )0;
            sqlstm.sqtdso[230] = (unsigned short )0;
            sqlstm.sqhstv[231] = (         void  *)(MRASCEVDEF_N.CHG_OPT_18);
            sqlstm.sqhstl[231] = (unsigned int  )2;
            sqlstm.sqhsts[231] = (         int  )0;
            sqlstm.sqindv[231] = (         void  *)0;
            sqlstm.sqinds[231] = (         int  )0;
            sqlstm.sqharm[231] = (unsigned int  )0;
            sqlstm.sqadto[231] = (unsigned short )0;
            sqlstm.sqtdso[231] = (unsigned short )0;
            sqlstm.sqhstv[232] = (         void  *)(MRASCEVDEF_N.CHG_OPT_19);
            sqlstm.sqhstl[232] = (unsigned int  )2;
            sqlstm.sqhsts[232] = (         int  )0;
            sqlstm.sqindv[232] = (         void  *)0;
            sqlstm.sqinds[232] = (         int  )0;
            sqlstm.sqharm[232] = (unsigned int  )0;
            sqlstm.sqadto[232] = (unsigned short )0;
            sqlstm.sqtdso[232] = (unsigned short )0;
            sqlstm.sqhstv[233] = (         void  *)(MRASCEVDEF_N.CHG_OPT_20);
            sqlstm.sqhstl[233] = (unsigned int  )2;
            sqlstm.sqhsts[233] = (         int  )0;
            sqlstm.sqindv[233] = (         void  *)0;
            sqlstm.sqinds[233] = (         int  )0;
            sqlstm.sqharm[233] = (unsigned int  )0;
            sqlstm.sqadto[233] = (unsigned short )0;
            sqlstm.sqtdso[233] = (unsigned short )0;
            sqlstm.sqhstv[234] = (         void  *)(MRASCEVDEF_N.CHG_OPT_21);
            sqlstm.sqhstl[234] = (unsigned int  )2;
            sqlstm.sqhsts[234] = (         int  )0;
            sqlstm.sqindv[234] = (         void  *)0;
            sqlstm.sqinds[234] = (         int  )0;
            sqlstm.sqharm[234] = (unsigned int  )0;
            sqlstm.sqadto[234] = (unsigned short )0;
            sqlstm.sqtdso[234] = (unsigned short )0;
            sqlstm.sqhstv[235] = (         void  *)(MRASCEVDEF_N.CHG_OPT_22);
            sqlstm.sqhstl[235] = (unsigned int  )2;
            sqlstm.sqhsts[235] = (         int  )0;
            sqlstm.sqindv[235] = (         void  *)0;
            sqlstm.sqinds[235] = (         int  )0;
            sqlstm.sqharm[235] = (unsigned int  )0;
            sqlstm.sqadto[235] = (unsigned short )0;
            sqlstm.sqtdso[235] = (unsigned short )0;
            sqlstm.sqhstv[236] = (         void  *)(MRASCEVDEF_N.CHG_OPT_23);
            sqlstm.sqhstl[236] = (unsigned int  )2;
            sqlstm.sqhsts[236] = (         int  )0;
            sqlstm.sqindv[236] = (         void  *)0;
            sqlstm.sqinds[236] = (         int  )0;
            sqlstm.sqharm[236] = (unsigned int  )0;
            sqlstm.sqadto[236] = (unsigned short )0;
            sqlstm.sqtdso[236] = (unsigned short )0;
            sqlstm.sqhstv[237] = (         void  *)(MRASCEVDEF_N.CHG_OPT_24);
            sqlstm.sqhstl[237] = (unsigned int  )2;
            sqlstm.sqhsts[237] = (         int  )0;
            sqlstm.sqindv[237] = (         void  *)0;
            sqlstm.sqinds[237] = (         int  )0;
            sqlstm.sqharm[237] = (unsigned int  )0;
            sqlstm.sqadto[237] = (unsigned short )0;
            sqlstm.sqtdso[237] = (unsigned short )0;
            sqlstm.sqhstv[238] = (         void  *)(MRASCEVDEF_N.CHG_OPT_25);
            sqlstm.sqhstl[238] = (unsigned int  )2;
            sqlstm.sqhsts[238] = (         int  )0;
            sqlstm.sqindv[238] = (         void  *)0;
            sqlstm.sqinds[238] = (         int  )0;
            sqlstm.sqharm[238] = (unsigned int  )0;
            sqlstm.sqadto[238] = (unsigned short )0;
            sqlstm.sqtdso[238] = (unsigned short )0;
            sqlstm.sqhstv[239] = (         void  *)(MRASCEVDEF_N.CHG_OPT_26);
            sqlstm.sqhstl[239] = (unsigned int  )2;
            sqlstm.sqhsts[239] = (         int  )0;
            sqlstm.sqindv[239] = (         void  *)0;
            sqlstm.sqinds[239] = (         int  )0;
            sqlstm.sqharm[239] = (unsigned int  )0;
            sqlstm.sqadto[239] = (unsigned short )0;
            sqlstm.sqtdso[239] = (unsigned short )0;
            sqlstm.sqhstv[240] = (         void  *)(MRASCEVDEF_N.CHG_OPT_27);
            sqlstm.sqhstl[240] = (unsigned int  )2;
            sqlstm.sqhsts[240] = (         int  )0;
            sqlstm.sqindv[240] = (         void  *)0;
            sqlstm.sqinds[240] = (         int  )0;
            sqlstm.sqharm[240] = (unsigned int  )0;
            sqlstm.sqadto[240] = (unsigned short )0;
            sqlstm.sqtdso[240] = (unsigned short )0;
            sqlstm.sqhstv[241] = (         void  *)(MRASCEVDEF_N.CHG_OPT_28);
            sqlstm.sqhstl[241] = (unsigned int  )2;
            sqlstm.sqhsts[241] = (         int  )0;
            sqlstm.sqindv[241] = (         void  *)0;
            sqlstm.sqinds[241] = (         int  )0;
            sqlstm.sqharm[241] = (unsigned int  )0;
            sqlstm.sqadto[241] = (unsigned short )0;
            sqlstm.sqtdso[241] = (unsigned short )0;
            sqlstm.sqhstv[242] = (         void  *)(MRASCEVDEF_N.CHG_OPT_29);
            sqlstm.sqhstl[242] = (unsigned int  )2;
            sqlstm.sqhsts[242] = (         int  )0;
            sqlstm.sqindv[242] = (         void  *)0;
            sqlstm.sqinds[242] = (         int  )0;
            sqlstm.sqharm[242] = (unsigned int  )0;
            sqlstm.sqadto[242] = (unsigned short )0;
            sqlstm.sqtdso[242] = (unsigned short )0;
            sqlstm.sqhstv[243] = (         void  *)(MRASCEVDEF_N.CHG_OPT_30);
            sqlstm.sqhstl[243] = (unsigned int  )2;
            sqlstm.sqhsts[243] = (         int  )0;
            sqlstm.sqindv[243] = (         void  *)0;
            sqlstm.sqinds[243] = (         int  )0;
            sqlstm.sqharm[243] = (unsigned int  )0;
            sqlstm.sqadto[243] = (unsigned short )0;
            sqlstm.sqtdso[243] = (unsigned short )0;
            sqlstm.sqhstv[244] = (         void  *)(MRASCEVDEF_N.CREATE_USER_ID);
            sqlstm.sqhstl[244] = (unsigned int  )21;
            sqlstm.sqhsts[244] = (         int  )0;
            sqlstm.sqindv[244] = (         void  *)0;
            sqlstm.sqinds[244] = (         int  )0;
            sqlstm.sqharm[244] = (unsigned int  )0;
            sqlstm.sqadto[244] = (unsigned short )0;
            sqlstm.sqtdso[244] = (unsigned short )0;
            sqlstm.sqhstv[245] = (         void  *)(MRASCEVDEF_N.CREATE_TIME);
            sqlstm.sqhstl[245] = (unsigned int  )15;
            sqlstm.sqhsts[245] = (         int  )0;
            sqlstm.sqindv[245] = (         void  *)0;
            sqlstm.sqinds[245] = (         int  )0;
            sqlstm.sqharm[245] = (unsigned int  )0;
            sqlstm.sqadto[245] = (unsigned short )0;
            sqlstm.sqtdso[245] = (unsigned short )0;
            sqlstm.sqhstv[246] = (         void  *)(MRASCEVDEF_N.UPDATE_USER_ID);
            sqlstm.sqhstl[246] = (unsigned int  )21;
            sqlstm.sqhsts[246] = (         int  )0;
            sqlstm.sqindv[246] = (         void  *)0;
            sqlstm.sqinds[246] = (         int  )0;
            sqlstm.sqharm[246] = (unsigned int  )0;
            sqlstm.sqadto[246] = (unsigned short )0;
            sqlstm.sqtdso[246] = (unsigned short )0;
            sqlstm.sqhstv[247] = (         void  *)(MRASCEVDEF_N.UPDATE_TIME);
            sqlstm.sqhstl[247] = (unsigned int  )15;
            sqlstm.sqhsts[247] = (         int  )0;
            sqlstm.sqindv[247] = (         void  *)0;
            sqlstm.sqinds[247] = (         int  )0;
            sqlstm.sqharm[247] = (unsigned int  )0;
            sqlstm.sqadto[247] = (unsigned short )0;
            sqlstm.sqtdso[247] = (unsigned short )0;
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
        DBC_del_null_mrascevdef(&MRASCEVDEF_N, MRASCEVDEF);
    }
    DB_stop_query_timer("DBC_fetch_mrascevdef", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_mrascevdef(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_MRASCEVDEF_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 250;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5129;
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
    DB_stop_query_timer("DBC_close_mrascevdef", sel_type);
}


/* Initialize Function */
void DBC_init_mrascevdef(struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* memset by Space */
    memset(MRASCEVDEF, ' ', sizeof(struct MRASCEVDEF_TAG));
    
}


/* Add Null Function */
void DBC_add_null_mrascevdef(struct MRASCEVDEF_N_TAG *MRASCEVDEF_N, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    /* memset by NULL */
    memset(MRASCEVDEF_N, '\0', sizeof(struct MRASCEVDEF_N_TAG));
    
    MEMCPY_AN(MRASCEVDEF_N->FACTORY, MRASCEVDEF->FACTORY, sizeof(MRASCEVDEF->FACTORY));
    MEMCPY_AN(MRASCEVDEF_N->CRR_EVENT_ID, MRASCEVDEF->CRR_EVENT_ID, sizeof(MRASCEVDEF->CRR_EVENT_ID));
    MEMCPY_AN(MRASCEVDEF_N->CRR_EVENT_DESC, MRASCEVDEF->CRR_EVENT_DESC, sizeof(MRASCEVDEF->CRR_EVENT_DESC));
    MRASCEVDEF_N->SYSTEM_FLAG[0] = MRASCEVDEF->SYSTEM_FLAG;
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_1, MRASCEVDEF->CHK_ITEM_1, sizeof(MRASCEVDEF->CHK_ITEM_1));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_2, MRASCEVDEF->CHK_ITEM_2, sizeof(MRASCEVDEF->CHK_ITEM_2));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_3, MRASCEVDEF->CHK_ITEM_3, sizeof(MRASCEVDEF->CHK_ITEM_3));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_4, MRASCEVDEF->CHK_ITEM_4, sizeof(MRASCEVDEF->CHK_ITEM_4));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_5, MRASCEVDEF->CHK_ITEM_5, sizeof(MRASCEVDEF->CHK_ITEM_5));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_6, MRASCEVDEF->CHK_ITEM_6, sizeof(MRASCEVDEF->CHK_ITEM_6));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_7, MRASCEVDEF->CHK_ITEM_7, sizeof(MRASCEVDEF->CHK_ITEM_7));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_8, MRASCEVDEF->CHK_ITEM_8, sizeof(MRASCEVDEF->CHK_ITEM_8));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_9, MRASCEVDEF->CHK_ITEM_9, sizeof(MRASCEVDEF->CHK_ITEM_9));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_10, MRASCEVDEF->CHK_ITEM_10, sizeof(MRASCEVDEF->CHK_ITEM_10));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_11, MRASCEVDEF->CHK_ITEM_11, sizeof(MRASCEVDEF->CHK_ITEM_11));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_12, MRASCEVDEF->CHK_ITEM_12, sizeof(MRASCEVDEF->CHK_ITEM_12));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_13, MRASCEVDEF->CHK_ITEM_13, sizeof(MRASCEVDEF->CHK_ITEM_13));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_14, MRASCEVDEF->CHK_ITEM_14, sizeof(MRASCEVDEF->CHK_ITEM_14));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_15, MRASCEVDEF->CHK_ITEM_15, sizeof(MRASCEVDEF->CHK_ITEM_15));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_16, MRASCEVDEF->CHK_ITEM_16, sizeof(MRASCEVDEF->CHK_ITEM_16));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_17, MRASCEVDEF->CHK_ITEM_17, sizeof(MRASCEVDEF->CHK_ITEM_17));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_18, MRASCEVDEF->CHK_ITEM_18, sizeof(MRASCEVDEF->CHK_ITEM_18));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_19, MRASCEVDEF->CHK_ITEM_19, sizeof(MRASCEVDEF->CHK_ITEM_19));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_20, MRASCEVDEF->CHK_ITEM_20, sizeof(MRASCEVDEF->CHK_ITEM_20));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_21, MRASCEVDEF->CHK_ITEM_21, sizeof(MRASCEVDEF->CHK_ITEM_21));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_22, MRASCEVDEF->CHK_ITEM_22, sizeof(MRASCEVDEF->CHK_ITEM_22));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_23, MRASCEVDEF->CHK_ITEM_23, sizeof(MRASCEVDEF->CHK_ITEM_23));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_24, MRASCEVDEF->CHK_ITEM_24, sizeof(MRASCEVDEF->CHK_ITEM_24));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_25, MRASCEVDEF->CHK_ITEM_25, sizeof(MRASCEVDEF->CHK_ITEM_25));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_26, MRASCEVDEF->CHK_ITEM_26, sizeof(MRASCEVDEF->CHK_ITEM_26));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_27, MRASCEVDEF->CHK_ITEM_27, sizeof(MRASCEVDEF->CHK_ITEM_27));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_28, MRASCEVDEF->CHK_ITEM_28, sizeof(MRASCEVDEF->CHK_ITEM_28));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_29, MRASCEVDEF->CHK_ITEM_29, sizeof(MRASCEVDEF->CHK_ITEM_29));
    MEMCPY_AN(MRASCEVDEF_N->CHK_ITEM_30, MRASCEVDEF->CHK_ITEM_30, sizeof(MRASCEVDEF->CHK_ITEM_30));
    MRASCEVDEF_N->CHK_FLAG_1[0] = MRASCEVDEF->CHK_FLAG_1;
    MRASCEVDEF_N->CHK_FLAG_2[0] = MRASCEVDEF->CHK_FLAG_2;
    MRASCEVDEF_N->CHK_FLAG_3[0] = MRASCEVDEF->CHK_FLAG_3;
    MRASCEVDEF_N->CHK_FLAG_4[0] = MRASCEVDEF->CHK_FLAG_4;
    MRASCEVDEF_N->CHK_FLAG_5[0] = MRASCEVDEF->CHK_FLAG_5;
    MRASCEVDEF_N->CHK_FLAG_6[0] = MRASCEVDEF->CHK_FLAG_6;
    MRASCEVDEF_N->CHK_FLAG_7[0] = MRASCEVDEF->CHK_FLAG_7;
    MRASCEVDEF_N->CHK_FLAG_8[0] = MRASCEVDEF->CHK_FLAG_8;
    MRASCEVDEF_N->CHK_FLAG_9[0] = MRASCEVDEF->CHK_FLAG_9;
    MRASCEVDEF_N->CHK_FLAG_10[0] = MRASCEVDEF->CHK_FLAG_10;
    MRASCEVDEF_N->CHK_FLAG_11[0] = MRASCEVDEF->CHK_FLAG_11;
    MRASCEVDEF_N->CHK_FLAG_12[0] = MRASCEVDEF->CHK_FLAG_12;
    MRASCEVDEF_N->CHK_FLAG_13[0] = MRASCEVDEF->CHK_FLAG_13;
    MRASCEVDEF_N->CHK_FLAG_14[0] = MRASCEVDEF->CHK_FLAG_14;
    MRASCEVDEF_N->CHK_FLAG_15[0] = MRASCEVDEF->CHK_FLAG_15;
    MRASCEVDEF_N->CHK_FLAG_16[0] = MRASCEVDEF->CHK_FLAG_16;
    MRASCEVDEF_N->CHK_FLAG_17[0] = MRASCEVDEF->CHK_FLAG_17;
    MRASCEVDEF_N->CHK_FLAG_18[0] = MRASCEVDEF->CHK_FLAG_18;
    MRASCEVDEF_N->CHK_FLAG_19[0] = MRASCEVDEF->CHK_FLAG_19;
    MRASCEVDEF_N->CHK_FLAG_20[0] = MRASCEVDEF->CHK_FLAG_20;
    MRASCEVDEF_N->CHK_FLAG_21[0] = MRASCEVDEF->CHK_FLAG_21;
    MRASCEVDEF_N->CHK_FLAG_22[0] = MRASCEVDEF->CHK_FLAG_22;
    MRASCEVDEF_N->CHK_FLAG_23[0] = MRASCEVDEF->CHK_FLAG_23;
    MRASCEVDEF_N->CHK_FLAG_24[0] = MRASCEVDEF->CHK_FLAG_24;
    MRASCEVDEF_N->CHK_FLAG_25[0] = MRASCEVDEF->CHK_FLAG_25;
    MRASCEVDEF_N->CHK_FLAG_26[0] = MRASCEVDEF->CHK_FLAG_26;
    MRASCEVDEF_N->CHK_FLAG_27[0] = MRASCEVDEF->CHK_FLAG_27;
    MRASCEVDEF_N->CHK_FLAG_28[0] = MRASCEVDEF->CHK_FLAG_28;
    MRASCEVDEF_N->CHK_FLAG_29[0] = MRASCEVDEF->CHK_FLAG_29;
    MRASCEVDEF_N->CHK_FLAG_30[0] = MRASCEVDEF->CHK_FLAG_30;
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_1, MRASCEVDEF->CHK_VALUE_1, sizeof(MRASCEVDEF->CHK_VALUE_1));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_2, MRASCEVDEF->CHK_VALUE_2, sizeof(MRASCEVDEF->CHK_VALUE_2));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_3, MRASCEVDEF->CHK_VALUE_3, sizeof(MRASCEVDEF->CHK_VALUE_3));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_4, MRASCEVDEF->CHK_VALUE_4, sizeof(MRASCEVDEF->CHK_VALUE_4));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_5, MRASCEVDEF->CHK_VALUE_5, sizeof(MRASCEVDEF->CHK_VALUE_5));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_6, MRASCEVDEF->CHK_VALUE_6, sizeof(MRASCEVDEF->CHK_VALUE_6));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_7, MRASCEVDEF->CHK_VALUE_7, sizeof(MRASCEVDEF->CHK_VALUE_7));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_8, MRASCEVDEF->CHK_VALUE_8, sizeof(MRASCEVDEF->CHK_VALUE_8));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_9, MRASCEVDEF->CHK_VALUE_9, sizeof(MRASCEVDEF->CHK_VALUE_9));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_10, MRASCEVDEF->CHK_VALUE_10, sizeof(MRASCEVDEF->CHK_VALUE_10));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_11, MRASCEVDEF->CHK_VALUE_11, sizeof(MRASCEVDEF->CHK_VALUE_11));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_12, MRASCEVDEF->CHK_VALUE_12, sizeof(MRASCEVDEF->CHK_VALUE_12));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_13, MRASCEVDEF->CHK_VALUE_13, sizeof(MRASCEVDEF->CHK_VALUE_13));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_14, MRASCEVDEF->CHK_VALUE_14, sizeof(MRASCEVDEF->CHK_VALUE_14));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_15, MRASCEVDEF->CHK_VALUE_15, sizeof(MRASCEVDEF->CHK_VALUE_15));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_16, MRASCEVDEF->CHK_VALUE_16, sizeof(MRASCEVDEF->CHK_VALUE_16));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_17, MRASCEVDEF->CHK_VALUE_17, sizeof(MRASCEVDEF->CHK_VALUE_17));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_18, MRASCEVDEF->CHK_VALUE_18, sizeof(MRASCEVDEF->CHK_VALUE_18));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_19, MRASCEVDEF->CHK_VALUE_19, sizeof(MRASCEVDEF->CHK_VALUE_19));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_20, MRASCEVDEF->CHK_VALUE_20, sizeof(MRASCEVDEF->CHK_VALUE_20));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_21, MRASCEVDEF->CHK_VALUE_21, sizeof(MRASCEVDEF->CHK_VALUE_21));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_22, MRASCEVDEF->CHK_VALUE_22, sizeof(MRASCEVDEF->CHK_VALUE_22));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_23, MRASCEVDEF->CHK_VALUE_23, sizeof(MRASCEVDEF->CHK_VALUE_23));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_24, MRASCEVDEF->CHK_VALUE_24, sizeof(MRASCEVDEF->CHK_VALUE_24));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_25, MRASCEVDEF->CHK_VALUE_25, sizeof(MRASCEVDEF->CHK_VALUE_25));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_26, MRASCEVDEF->CHK_VALUE_26, sizeof(MRASCEVDEF->CHK_VALUE_26));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_27, MRASCEVDEF->CHK_VALUE_27, sizeof(MRASCEVDEF->CHK_VALUE_27));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_28, MRASCEVDEF->CHK_VALUE_28, sizeof(MRASCEVDEF->CHK_VALUE_28));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_29, MRASCEVDEF->CHK_VALUE_29, sizeof(MRASCEVDEF->CHK_VALUE_29));
    MEMCPY_AN(MRASCEVDEF_N->CHK_VALUE_30, MRASCEVDEF->CHK_VALUE_30, sizeof(MRASCEVDEF->CHK_VALUE_30));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_1, MRASCEVDEF->CHK_FIELD_1, sizeof(MRASCEVDEF->CHK_FIELD_1));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_2, MRASCEVDEF->CHK_FIELD_2, sizeof(MRASCEVDEF->CHK_FIELD_2));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_3, MRASCEVDEF->CHK_FIELD_3, sizeof(MRASCEVDEF->CHK_FIELD_3));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_4, MRASCEVDEF->CHK_FIELD_4, sizeof(MRASCEVDEF->CHK_FIELD_4));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_5, MRASCEVDEF->CHK_FIELD_5, sizeof(MRASCEVDEF->CHK_FIELD_5));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_6, MRASCEVDEF->CHK_FIELD_6, sizeof(MRASCEVDEF->CHK_FIELD_6));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_7, MRASCEVDEF->CHK_FIELD_7, sizeof(MRASCEVDEF->CHK_FIELD_7));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_8, MRASCEVDEF->CHK_FIELD_8, sizeof(MRASCEVDEF->CHK_FIELD_8));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_9, MRASCEVDEF->CHK_FIELD_9, sizeof(MRASCEVDEF->CHK_FIELD_9));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_10, MRASCEVDEF->CHK_FIELD_10, sizeof(MRASCEVDEF->CHK_FIELD_10));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_11, MRASCEVDEF->CHK_FIELD_11, sizeof(MRASCEVDEF->CHK_FIELD_11));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_12, MRASCEVDEF->CHK_FIELD_12, sizeof(MRASCEVDEF->CHK_FIELD_12));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_13, MRASCEVDEF->CHK_FIELD_13, sizeof(MRASCEVDEF->CHK_FIELD_13));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_14, MRASCEVDEF->CHK_FIELD_14, sizeof(MRASCEVDEF->CHK_FIELD_14));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_15, MRASCEVDEF->CHK_FIELD_15, sizeof(MRASCEVDEF->CHK_FIELD_15));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_16, MRASCEVDEF->CHK_FIELD_16, sizeof(MRASCEVDEF->CHK_FIELD_16));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_17, MRASCEVDEF->CHK_FIELD_17, sizeof(MRASCEVDEF->CHK_FIELD_17));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_18, MRASCEVDEF->CHK_FIELD_18, sizeof(MRASCEVDEF->CHK_FIELD_18));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_19, MRASCEVDEF->CHK_FIELD_19, sizeof(MRASCEVDEF->CHK_FIELD_19));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_20, MRASCEVDEF->CHK_FIELD_20, sizeof(MRASCEVDEF->CHK_FIELD_20));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_21, MRASCEVDEF->CHK_FIELD_21, sizeof(MRASCEVDEF->CHK_FIELD_21));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_22, MRASCEVDEF->CHK_FIELD_22, sizeof(MRASCEVDEF->CHK_FIELD_22));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_23, MRASCEVDEF->CHK_FIELD_23, sizeof(MRASCEVDEF->CHK_FIELD_23));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_24, MRASCEVDEF->CHK_FIELD_24, sizeof(MRASCEVDEF->CHK_FIELD_24));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_25, MRASCEVDEF->CHK_FIELD_25, sizeof(MRASCEVDEF->CHK_FIELD_25));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_26, MRASCEVDEF->CHK_FIELD_26, sizeof(MRASCEVDEF->CHK_FIELD_26));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_27, MRASCEVDEF->CHK_FIELD_27, sizeof(MRASCEVDEF->CHK_FIELD_27));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_28, MRASCEVDEF->CHK_FIELD_28, sizeof(MRASCEVDEF->CHK_FIELD_28));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_29, MRASCEVDEF->CHK_FIELD_29, sizeof(MRASCEVDEF->CHK_FIELD_29));
    MEMCPY_AN(MRASCEVDEF_N->CHK_FIELD_30, MRASCEVDEF->CHK_FIELD_30, sizeof(MRASCEVDEF->CHK_FIELD_30));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_1, MRASCEVDEF->CHG_ITEM_1, sizeof(MRASCEVDEF->CHG_ITEM_1));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_2, MRASCEVDEF->CHG_ITEM_2, sizeof(MRASCEVDEF->CHG_ITEM_2));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_3, MRASCEVDEF->CHG_ITEM_3, sizeof(MRASCEVDEF->CHG_ITEM_3));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_4, MRASCEVDEF->CHG_ITEM_4, sizeof(MRASCEVDEF->CHG_ITEM_4));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_5, MRASCEVDEF->CHG_ITEM_5, sizeof(MRASCEVDEF->CHG_ITEM_5));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_6, MRASCEVDEF->CHG_ITEM_6, sizeof(MRASCEVDEF->CHG_ITEM_6));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_7, MRASCEVDEF->CHG_ITEM_7, sizeof(MRASCEVDEF->CHG_ITEM_7));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_8, MRASCEVDEF->CHG_ITEM_8, sizeof(MRASCEVDEF->CHG_ITEM_8));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_9, MRASCEVDEF->CHG_ITEM_9, sizeof(MRASCEVDEF->CHG_ITEM_9));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_10, MRASCEVDEF->CHG_ITEM_10, sizeof(MRASCEVDEF->CHG_ITEM_10));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_11, MRASCEVDEF->CHG_ITEM_11, sizeof(MRASCEVDEF->CHG_ITEM_11));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_12, MRASCEVDEF->CHG_ITEM_12, sizeof(MRASCEVDEF->CHG_ITEM_12));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_13, MRASCEVDEF->CHG_ITEM_13, sizeof(MRASCEVDEF->CHG_ITEM_13));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_14, MRASCEVDEF->CHG_ITEM_14, sizeof(MRASCEVDEF->CHG_ITEM_14));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_15, MRASCEVDEF->CHG_ITEM_15, sizeof(MRASCEVDEF->CHG_ITEM_15));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_16, MRASCEVDEF->CHG_ITEM_16, sizeof(MRASCEVDEF->CHG_ITEM_16));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_17, MRASCEVDEF->CHG_ITEM_17, sizeof(MRASCEVDEF->CHG_ITEM_17));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_18, MRASCEVDEF->CHG_ITEM_18, sizeof(MRASCEVDEF->CHG_ITEM_18));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_19, MRASCEVDEF->CHG_ITEM_19, sizeof(MRASCEVDEF->CHG_ITEM_19));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_20, MRASCEVDEF->CHG_ITEM_20, sizeof(MRASCEVDEF->CHG_ITEM_20));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_21, MRASCEVDEF->CHG_ITEM_21, sizeof(MRASCEVDEF->CHG_ITEM_21));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_22, MRASCEVDEF->CHG_ITEM_22, sizeof(MRASCEVDEF->CHG_ITEM_22));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_23, MRASCEVDEF->CHG_ITEM_23, sizeof(MRASCEVDEF->CHG_ITEM_23));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_24, MRASCEVDEF->CHG_ITEM_24, sizeof(MRASCEVDEF->CHG_ITEM_24));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_25, MRASCEVDEF->CHG_ITEM_25, sizeof(MRASCEVDEF->CHG_ITEM_25));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_26, MRASCEVDEF->CHG_ITEM_26, sizeof(MRASCEVDEF->CHG_ITEM_26));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_27, MRASCEVDEF->CHG_ITEM_27, sizeof(MRASCEVDEF->CHG_ITEM_27));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_28, MRASCEVDEF->CHG_ITEM_28, sizeof(MRASCEVDEF->CHG_ITEM_28));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_29, MRASCEVDEF->CHG_ITEM_29, sizeof(MRASCEVDEF->CHG_ITEM_29));
    MEMCPY_AN(MRASCEVDEF_N->CHG_ITEM_30, MRASCEVDEF->CHG_ITEM_30, sizeof(MRASCEVDEF->CHG_ITEM_30));
    MRASCEVDEF_N->CHG_FLAG_1[0] = MRASCEVDEF->CHG_FLAG_1;
    MRASCEVDEF_N->CHG_FLAG_2[0] = MRASCEVDEF->CHG_FLAG_2;
    MRASCEVDEF_N->CHG_FLAG_3[0] = MRASCEVDEF->CHG_FLAG_3;
    MRASCEVDEF_N->CHG_FLAG_4[0] = MRASCEVDEF->CHG_FLAG_4;
    MRASCEVDEF_N->CHG_FLAG_5[0] = MRASCEVDEF->CHG_FLAG_5;
    MRASCEVDEF_N->CHG_FLAG_6[0] = MRASCEVDEF->CHG_FLAG_6;
    MRASCEVDEF_N->CHG_FLAG_7[0] = MRASCEVDEF->CHG_FLAG_7;
    MRASCEVDEF_N->CHG_FLAG_8[0] = MRASCEVDEF->CHG_FLAG_8;
    MRASCEVDEF_N->CHG_FLAG_9[0] = MRASCEVDEF->CHG_FLAG_9;
    MRASCEVDEF_N->CHG_FLAG_10[0] = MRASCEVDEF->CHG_FLAG_10;
    MRASCEVDEF_N->CHG_FLAG_11[0] = MRASCEVDEF->CHG_FLAG_11;
    MRASCEVDEF_N->CHG_FLAG_12[0] = MRASCEVDEF->CHG_FLAG_12;
    MRASCEVDEF_N->CHG_FLAG_13[0] = MRASCEVDEF->CHG_FLAG_13;
    MRASCEVDEF_N->CHG_FLAG_14[0] = MRASCEVDEF->CHG_FLAG_14;
    MRASCEVDEF_N->CHG_FLAG_15[0] = MRASCEVDEF->CHG_FLAG_15;
    MRASCEVDEF_N->CHG_FLAG_16[0] = MRASCEVDEF->CHG_FLAG_16;
    MRASCEVDEF_N->CHG_FLAG_17[0] = MRASCEVDEF->CHG_FLAG_17;
    MRASCEVDEF_N->CHG_FLAG_18[0] = MRASCEVDEF->CHG_FLAG_18;
    MRASCEVDEF_N->CHG_FLAG_19[0] = MRASCEVDEF->CHG_FLAG_19;
    MRASCEVDEF_N->CHG_FLAG_20[0] = MRASCEVDEF->CHG_FLAG_20;
    MRASCEVDEF_N->CHG_FLAG_21[0] = MRASCEVDEF->CHG_FLAG_21;
    MRASCEVDEF_N->CHG_FLAG_22[0] = MRASCEVDEF->CHG_FLAG_22;
    MRASCEVDEF_N->CHG_FLAG_23[0] = MRASCEVDEF->CHG_FLAG_23;
    MRASCEVDEF_N->CHG_FLAG_24[0] = MRASCEVDEF->CHG_FLAG_24;
    MRASCEVDEF_N->CHG_FLAG_25[0] = MRASCEVDEF->CHG_FLAG_25;
    MRASCEVDEF_N->CHG_FLAG_26[0] = MRASCEVDEF->CHG_FLAG_26;
    MRASCEVDEF_N->CHG_FLAG_27[0] = MRASCEVDEF->CHG_FLAG_27;
    MRASCEVDEF_N->CHG_FLAG_28[0] = MRASCEVDEF->CHG_FLAG_28;
    MRASCEVDEF_N->CHG_FLAG_29[0] = MRASCEVDEF->CHG_FLAG_29;
    MRASCEVDEF_N->CHG_FLAG_30[0] = MRASCEVDEF->CHG_FLAG_30;
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_1, MRASCEVDEF->CHG_VALUE_1, sizeof(MRASCEVDEF->CHG_VALUE_1));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_2, MRASCEVDEF->CHG_VALUE_2, sizeof(MRASCEVDEF->CHG_VALUE_2));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_3, MRASCEVDEF->CHG_VALUE_3, sizeof(MRASCEVDEF->CHG_VALUE_3));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_4, MRASCEVDEF->CHG_VALUE_4, sizeof(MRASCEVDEF->CHG_VALUE_4));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_5, MRASCEVDEF->CHG_VALUE_5, sizeof(MRASCEVDEF->CHG_VALUE_5));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_6, MRASCEVDEF->CHG_VALUE_6, sizeof(MRASCEVDEF->CHG_VALUE_6));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_7, MRASCEVDEF->CHG_VALUE_7, sizeof(MRASCEVDEF->CHG_VALUE_7));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_8, MRASCEVDEF->CHG_VALUE_8, sizeof(MRASCEVDEF->CHG_VALUE_8));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_9, MRASCEVDEF->CHG_VALUE_9, sizeof(MRASCEVDEF->CHG_VALUE_9));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_10, MRASCEVDEF->CHG_VALUE_10, sizeof(MRASCEVDEF->CHG_VALUE_10));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_11, MRASCEVDEF->CHG_VALUE_11, sizeof(MRASCEVDEF->CHG_VALUE_11));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_12, MRASCEVDEF->CHG_VALUE_12, sizeof(MRASCEVDEF->CHG_VALUE_12));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_13, MRASCEVDEF->CHG_VALUE_13, sizeof(MRASCEVDEF->CHG_VALUE_13));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_14, MRASCEVDEF->CHG_VALUE_14, sizeof(MRASCEVDEF->CHG_VALUE_14));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_15, MRASCEVDEF->CHG_VALUE_15, sizeof(MRASCEVDEF->CHG_VALUE_15));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_16, MRASCEVDEF->CHG_VALUE_16, sizeof(MRASCEVDEF->CHG_VALUE_16));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_17, MRASCEVDEF->CHG_VALUE_17, sizeof(MRASCEVDEF->CHG_VALUE_17));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_18, MRASCEVDEF->CHG_VALUE_18, sizeof(MRASCEVDEF->CHG_VALUE_18));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_19, MRASCEVDEF->CHG_VALUE_19, sizeof(MRASCEVDEF->CHG_VALUE_19));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_20, MRASCEVDEF->CHG_VALUE_20, sizeof(MRASCEVDEF->CHG_VALUE_20));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_21, MRASCEVDEF->CHG_VALUE_21, sizeof(MRASCEVDEF->CHG_VALUE_21));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_22, MRASCEVDEF->CHG_VALUE_22, sizeof(MRASCEVDEF->CHG_VALUE_22));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_23, MRASCEVDEF->CHG_VALUE_23, sizeof(MRASCEVDEF->CHG_VALUE_23));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_24, MRASCEVDEF->CHG_VALUE_24, sizeof(MRASCEVDEF->CHG_VALUE_24));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_25, MRASCEVDEF->CHG_VALUE_25, sizeof(MRASCEVDEF->CHG_VALUE_25));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_26, MRASCEVDEF->CHG_VALUE_26, sizeof(MRASCEVDEF->CHG_VALUE_26));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_27, MRASCEVDEF->CHG_VALUE_27, sizeof(MRASCEVDEF->CHG_VALUE_27));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_28, MRASCEVDEF->CHG_VALUE_28, sizeof(MRASCEVDEF->CHG_VALUE_28));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_29, MRASCEVDEF->CHG_VALUE_29, sizeof(MRASCEVDEF->CHG_VALUE_29));
    MEMCPY_AN(MRASCEVDEF_N->CHG_VALUE_30, MRASCEVDEF->CHG_VALUE_30, sizeof(MRASCEVDEF->CHG_VALUE_30));
    MRASCEVDEF_N->CHG_OPT_1[0] = MRASCEVDEF->CHG_OPT_1;
    MRASCEVDEF_N->CHG_OPT_2[0] = MRASCEVDEF->CHG_OPT_2;
    MRASCEVDEF_N->CHG_OPT_3[0] = MRASCEVDEF->CHG_OPT_3;
    MRASCEVDEF_N->CHG_OPT_4[0] = MRASCEVDEF->CHG_OPT_4;
    MRASCEVDEF_N->CHG_OPT_5[0] = MRASCEVDEF->CHG_OPT_5;
    MRASCEVDEF_N->CHG_OPT_6[0] = MRASCEVDEF->CHG_OPT_6;
    MRASCEVDEF_N->CHG_OPT_7[0] = MRASCEVDEF->CHG_OPT_7;
    MRASCEVDEF_N->CHG_OPT_8[0] = MRASCEVDEF->CHG_OPT_8;
    MRASCEVDEF_N->CHG_OPT_9[0] = MRASCEVDEF->CHG_OPT_9;
    MRASCEVDEF_N->CHG_OPT_10[0] = MRASCEVDEF->CHG_OPT_10;
    MRASCEVDEF_N->CHG_OPT_11[0] = MRASCEVDEF->CHG_OPT_11;
    MRASCEVDEF_N->CHG_OPT_12[0] = MRASCEVDEF->CHG_OPT_12;
    MRASCEVDEF_N->CHG_OPT_13[0] = MRASCEVDEF->CHG_OPT_13;
    MRASCEVDEF_N->CHG_OPT_14[0] = MRASCEVDEF->CHG_OPT_14;
    MRASCEVDEF_N->CHG_OPT_15[0] = MRASCEVDEF->CHG_OPT_15;
    MRASCEVDEF_N->CHG_OPT_16[0] = MRASCEVDEF->CHG_OPT_16;
    MRASCEVDEF_N->CHG_OPT_17[0] = MRASCEVDEF->CHG_OPT_17;
    MRASCEVDEF_N->CHG_OPT_18[0] = MRASCEVDEF->CHG_OPT_18;
    MRASCEVDEF_N->CHG_OPT_19[0] = MRASCEVDEF->CHG_OPT_19;
    MRASCEVDEF_N->CHG_OPT_20[0] = MRASCEVDEF->CHG_OPT_20;
    MRASCEVDEF_N->CHG_OPT_21[0] = MRASCEVDEF->CHG_OPT_21;
    MRASCEVDEF_N->CHG_OPT_22[0] = MRASCEVDEF->CHG_OPT_22;
    MRASCEVDEF_N->CHG_OPT_23[0] = MRASCEVDEF->CHG_OPT_23;
    MRASCEVDEF_N->CHG_OPT_24[0] = MRASCEVDEF->CHG_OPT_24;
    MRASCEVDEF_N->CHG_OPT_25[0] = MRASCEVDEF->CHG_OPT_25;
    MRASCEVDEF_N->CHG_OPT_26[0] = MRASCEVDEF->CHG_OPT_26;
    MRASCEVDEF_N->CHG_OPT_27[0] = MRASCEVDEF->CHG_OPT_27;
    MRASCEVDEF_N->CHG_OPT_28[0] = MRASCEVDEF->CHG_OPT_28;
    MRASCEVDEF_N->CHG_OPT_29[0] = MRASCEVDEF->CHG_OPT_29;
    MRASCEVDEF_N->CHG_OPT_30[0] = MRASCEVDEF->CHG_OPT_30;
    MEMCPY_AN(MRASCEVDEF_N->CREATE_USER_ID, MRASCEVDEF->CREATE_USER_ID, sizeof(MRASCEVDEF->CREATE_USER_ID));
    MEMCPY_AN(MRASCEVDEF_N->CREATE_TIME, MRASCEVDEF->CREATE_TIME, sizeof(MRASCEVDEF->CREATE_TIME));
    MEMCPY_AN(MRASCEVDEF_N->UPDATE_USER_ID, MRASCEVDEF->UPDATE_USER_ID, sizeof(MRASCEVDEF->UPDATE_USER_ID));
    MEMCPY_AN(MRASCEVDEF_N->UPDATE_TIME, MRASCEVDEF->UPDATE_TIME, sizeof(MRASCEVDEF->UPDATE_TIME));
}


/* Del Null Function */
void DBC_del_null_mrascevdef(struct MRASCEVDEF_N_TAG *MRASCEVDEF_N, struct MRASCEVDEF_TAG *MRASCEVDEF)
{
    MEMCPY_DN(MRASCEVDEF->FACTORY, MRASCEVDEF_N->FACTORY, sizeof(MRASCEVDEF->FACTORY));
    MEMCPY_DN(MRASCEVDEF->CRR_EVENT_ID, MRASCEVDEF_N->CRR_EVENT_ID, sizeof(MRASCEVDEF->CRR_EVENT_ID));
    MEMCPY_DN(MRASCEVDEF->CRR_EVENT_DESC, MRASCEVDEF_N->CRR_EVENT_DESC, sizeof(MRASCEVDEF->CRR_EVENT_DESC));
    MRASCEVDEF->SYSTEM_FLAG = MRASCEVDEF_N->SYSTEM_FLAG[0];
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_1, MRASCEVDEF_N->CHK_ITEM_1, sizeof(MRASCEVDEF->CHK_ITEM_1));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_2, MRASCEVDEF_N->CHK_ITEM_2, sizeof(MRASCEVDEF->CHK_ITEM_2));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_3, MRASCEVDEF_N->CHK_ITEM_3, sizeof(MRASCEVDEF->CHK_ITEM_3));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_4, MRASCEVDEF_N->CHK_ITEM_4, sizeof(MRASCEVDEF->CHK_ITEM_4));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_5, MRASCEVDEF_N->CHK_ITEM_5, sizeof(MRASCEVDEF->CHK_ITEM_5));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_6, MRASCEVDEF_N->CHK_ITEM_6, sizeof(MRASCEVDEF->CHK_ITEM_6));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_7, MRASCEVDEF_N->CHK_ITEM_7, sizeof(MRASCEVDEF->CHK_ITEM_7));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_8, MRASCEVDEF_N->CHK_ITEM_8, sizeof(MRASCEVDEF->CHK_ITEM_8));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_9, MRASCEVDEF_N->CHK_ITEM_9, sizeof(MRASCEVDEF->CHK_ITEM_9));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_10, MRASCEVDEF_N->CHK_ITEM_10, sizeof(MRASCEVDEF->CHK_ITEM_10));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_11, MRASCEVDEF_N->CHK_ITEM_11, sizeof(MRASCEVDEF->CHK_ITEM_11));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_12, MRASCEVDEF_N->CHK_ITEM_12, sizeof(MRASCEVDEF->CHK_ITEM_12));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_13, MRASCEVDEF_N->CHK_ITEM_13, sizeof(MRASCEVDEF->CHK_ITEM_13));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_14, MRASCEVDEF_N->CHK_ITEM_14, sizeof(MRASCEVDEF->CHK_ITEM_14));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_15, MRASCEVDEF_N->CHK_ITEM_15, sizeof(MRASCEVDEF->CHK_ITEM_15));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_16, MRASCEVDEF_N->CHK_ITEM_16, sizeof(MRASCEVDEF->CHK_ITEM_16));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_17, MRASCEVDEF_N->CHK_ITEM_17, sizeof(MRASCEVDEF->CHK_ITEM_17));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_18, MRASCEVDEF_N->CHK_ITEM_18, sizeof(MRASCEVDEF->CHK_ITEM_18));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_19, MRASCEVDEF_N->CHK_ITEM_19, sizeof(MRASCEVDEF->CHK_ITEM_19));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_20, MRASCEVDEF_N->CHK_ITEM_20, sizeof(MRASCEVDEF->CHK_ITEM_20));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_21, MRASCEVDEF_N->CHK_ITEM_21, sizeof(MRASCEVDEF->CHK_ITEM_21));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_22, MRASCEVDEF_N->CHK_ITEM_22, sizeof(MRASCEVDEF->CHK_ITEM_22));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_23, MRASCEVDEF_N->CHK_ITEM_23, sizeof(MRASCEVDEF->CHK_ITEM_23));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_24, MRASCEVDEF_N->CHK_ITEM_24, sizeof(MRASCEVDEF->CHK_ITEM_24));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_25, MRASCEVDEF_N->CHK_ITEM_25, sizeof(MRASCEVDEF->CHK_ITEM_25));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_26, MRASCEVDEF_N->CHK_ITEM_26, sizeof(MRASCEVDEF->CHK_ITEM_26));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_27, MRASCEVDEF_N->CHK_ITEM_27, sizeof(MRASCEVDEF->CHK_ITEM_27));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_28, MRASCEVDEF_N->CHK_ITEM_28, sizeof(MRASCEVDEF->CHK_ITEM_28));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_29, MRASCEVDEF_N->CHK_ITEM_29, sizeof(MRASCEVDEF->CHK_ITEM_29));
    MEMCPY_DN(MRASCEVDEF->CHK_ITEM_30, MRASCEVDEF_N->CHK_ITEM_30, sizeof(MRASCEVDEF->CHK_ITEM_30));
    MRASCEVDEF->CHK_FLAG_1 = MRASCEVDEF_N->CHK_FLAG_1[0];
    MRASCEVDEF->CHK_FLAG_2 = MRASCEVDEF_N->CHK_FLAG_2[0];
    MRASCEVDEF->CHK_FLAG_3 = MRASCEVDEF_N->CHK_FLAG_3[0];
    MRASCEVDEF->CHK_FLAG_4 = MRASCEVDEF_N->CHK_FLAG_4[0];
    MRASCEVDEF->CHK_FLAG_5 = MRASCEVDEF_N->CHK_FLAG_5[0];
    MRASCEVDEF->CHK_FLAG_6 = MRASCEVDEF_N->CHK_FLAG_6[0];
    MRASCEVDEF->CHK_FLAG_7 = MRASCEVDEF_N->CHK_FLAG_7[0];
    MRASCEVDEF->CHK_FLAG_8 = MRASCEVDEF_N->CHK_FLAG_8[0];
    MRASCEVDEF->CHK_FLAG_9 = MRASCEVDEF_N->CHK_FLAG_9[0];
    MRASCEVDEF->CHK_FLAG_10 = MRASCEVDEF_N->CHK_FLAG_10[0];
    MRASCEVDEF->CHK_FLAG_11 = MRASCEVDEF_N->CHK_FLAG_11[0];
    MRASCEVDEF->CHK_FLAG_12 = MRASCEVDEF_N->CHK_FLAG_12[0];
    MRASCEVDEF->CHK_FLAG_13 = MRASCEVDEF_N->CHK_FLAG_13[0];
    MRASCEVDEF->CHK_FLAG_14 = MRASCEVDEF_N->CHK_FLAG_14[0];
    MRASCEVDEF->CHK_FLAG_15 = MRASCEVDEF_N->CHK_FLAG_15[0];
    MRASCEVDEF->CHK_FLAG_16 = MRASCEVDEF_N->CHK_FLAG_16[0];
    MRASCEVDEF->CHK_FLAG_17 = MRASCEVDEF_N->CHK_FLAG_17[0];
    MRASCEVDEF->CHK_FLAG_18 = MRASCEVDEF_N->CHK_FLAG_18[0];
    MRASCEVDEF->CHK_FLAG_19 = MRASCEVDEF_N->CHK_FLAG_19[0];
    MRASCEVDEF->CHK_FLAG_20 = MRASCEVDEF_N->CHK_FLAG_20[0];
    MRASCEVDEF->CHK_FLAG_21 = MRASCEVDEF_N->CHK_FLAG_21[0];
    MRASCEVDEF->CHK_FLAG_22 = MRASCEVDEF_N->CHK_FLAG_22[0];
    MRASCEVDEF->CHK_FLAG_23 = MRASCEVDEF_N->CHK_FLAG_23[0];
    MRASCEVDEF->CHK_FLAG_24 = MRASCEVDEF_N->CHK_FLAG_24[0];
    MRASCEVDEF->CHK_FLAG_25 = MRASCEVDEF_N->CHK_FLAG_25[0];
    MRASCEVDEF->CHK_FLAG_26 = MRASCEVDEF_N->CHK_FLAG_26[0];
    MRASCEVDEF->CHK_FLAG_27 = MRASCEVDEF_N->CHK_FLAG_27[0];
    MRASCEVDEF->CHK_FLAG_28 = MRASCEVDEF_N->CHK_FLAG_28[0];
    MRASCEVDEF->CHK_FLAG_29 = MRASCEVDEF_N->CHK_FLAG_29[0];
    MRASCEVDEF->CHK_FLAG_30 = MRASCEVDEF_N->CHK_FLAG_30[0];
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_1, MRASCEVDEF_N->CHK_VALUE_1, sizeof(MRASCEVDEF->CHK_VALUE_1));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_2, MRASCEVDEF_N->CHK_VALUE_2, sizeof(MRASCEVDEF->CHK_VALUE_2));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_3, MRASCEVDEF_N->CHK_VALUE_3, sizeof(MRASCEVDEF->CHK_VALUE_3));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_4, MRASCEVDEF_N->CHK_VALUE_4, sizeof(MRASCEVDEF->CHK_VALUE_4));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_5, MRASCEVDEF_N->CHK_VALUE_5, sizeof(MRASCEVDEF->CHK_VALUE_5));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_6, MRASCEVDEF_N->CHK_VALUE_6, sizeof(MRASCEVDEF->CHK_VALUE_6));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_7, MRASCEVDEF_N->CHK_VALUE_7, sizeof(MRASCEVDEF->CHK_VALUE_7));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_8, MRASCEVDEF_N->CHK_VALUE_8, sizeof(MRASCEVDEF->CHK_VALUE_8));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_9, MRASCEVDEF_N->CHK_VALUE_9, sizeof(MRASCEVDEF->CHK_VALUE_9));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_10, MRASCEVDEF_N->CHK_VALUE_10, sizeof(MRASCEVDEF->CHK_VALUE_10));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_11, MRASCEVDEF_N->CHK_VALUE_11, sizeof(MRASCEVDEF->CHK_VALUE_11));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_12, MRASCEVDEF_N->CHK_VALUE_12, sizeof(MRASCEVDEF->CHK_VALUE_12));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_13, MRASCEVDEF_N->CHK_VALUE_13, sizeof(MRASCEVDEF->CHK_VALUE_13));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_14, MRASCEVDEF_N->CHK_VALUE_14, sizeof(MRASCEVDEF->CHK_VALUE_14));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_15, MRASCEVDEF_N->CHK_VALUE_15, sizeof(MRASCEVDEF->CHK_VALUE_15));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_16, MRASCEVDEF_N->CHK_VALUE_16, sizeof(MRASCEVDEF->CHK_VALUE_16));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_17, MRASCEVDEF_N->CHK_VALUE_17, sizeof(MRASCEVDEF->CHK_VALUE_17));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_18, MRASCEVDEF_N->CHK_VALUE_18, sizeof(MRASCEVDEF->CHK_VALUE_18));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_19, MRASCEVDEF_N->CHK_VALUE_19, sizeof(MRASCEVDEF->CHK_VALUE_19));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_20, MRASCEVDEF_N->CHK_VALUE_20, sizeof(MRASCEVDEF->CHK_VALUE_20));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_21, MRASCEVDEF_N->CHK_VALUE_21, sizeof(MRASCEVDEF->CHK_VALUE_21));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_22, MRASCEVDEF_N->CHK_VALUE_22, sizeof(MRASCEVDEF->CHK_VALUE_22));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_23, MRASCEVDEF_N->CHK_VALUE_23, sizeof(MRASCEVDEF->CHK_VALUE_23));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_24, MRASCEVDEF_N->CHK_VALUE_24, sizeof(MRASCEVDEF->CHK_VALUE_24));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_25, MRASCEVDEF_N->CHK_VALUE_25, sizeof(MRASCEVDEF->CHK_VALUE_25));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_26, MRASCEVDEF_N->CHK_VALUE_26, sizeof(MRASCEVDEF->CHK_VALUE_26));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_27, MRASCEVDEF_N->CHK_VALUE_27, sizeof(MRASCEVDEF->CHK_VALUE_27));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_28, MRASCEVDEF_N->CHK_VALUE_28, sizeof(MRASCEVDEF->CHK_VALUE_28));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_29, MRASCEVDEF_N->CHK_VALUE_29, sizeof(MRASCEVDEF->CHK_VALUE_29));
    MEMCPY_DN(MRASCEVDEF->CHK_VALUE_30, MRASCEVDEF_N->CHK_VALUE_30, sizeof(MRASCEVDEF->CHK_VALUE_30));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_1, MRASCEVDEF_N->CHK_FIELD_1, sizeof(MRASCEVDEF->CHK_FIELD_1));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_2, MRASCEVDEF_N->CHK_FIELD_2, sizeof(MRASCEVDEF->CHK_FIELD_2));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_3, MRASCEVDEF_N->CHK_FIELD_3, sizeof(MRASCEVDEF->CHK_FIELD_3));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_4, MRASCEVDEF_N->CHK_FIELD_4, sizeof(MRASCEVDEF->CHK_FIELD_4));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_5, MRASCEVDEF_N->CHK_FIELD_5, sizeof(MRASCEVDEF->CHK_FIELD_5));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_6, MRASCEVDEF_N->CHK_FIELD_6, sizeof(MRASCEVDEF->CHK_FIELD_6));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_7, MRASCEVDEF_N->CHK_FIELD_7, sizeof(MRASCEVDEF->CHK_FIELD_7));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_8, MRASCEVDEF_N->CHK_FIELD_8, sizeof(MRASCEVDEF->CHK_FIELD_8));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_9, MRASCEVDEF_N->CHK_FIELD_9, sizeof(MRASCEVDEF->CHK_FIELD_9));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_10, MRASCEVDEF_N->CHK_FIELD_10, sizeof(MRASCEVDEF->CHK_FIELD_10));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_11, MRASCEVDEF_N->CHK_FIELD_11, sizeof(MRASCEVDEF->CHK_FIELD_11));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_12, MRASCEVDEF_N->CHK_FIELD_12, sizeof(MRASCEVDEF->CHK_FIELD_12));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_13, MRASCEVDEF_N->CHK_FIELD_13, sizeof(MRASCEVDEF->CHK_FIELD_13));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_14, MRASCEVDEF_N->CHK_FIELD_14, sizeof(MRASCEVDEF->CHK_FIELD_14));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_15, MRASCEVDEF_N->CHK_FIELD_15, sizeof(MRASCEVDEF->CHK_FIELD_15));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_16, MRASCEVDEF_N->CHK_FIELD_16, sizeof(MRASCEVDEF->CHK_FIELD_16));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_17, MRASCEVDEF_N->CHK_FIELD_17, sizeof(MRASCEVDEF->CHK_FIELD_17));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_18, MRASCEVDEF_N->CHK_FIELD_18, sizeof(MRASCEVDEF->CHK_FIELD_18));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_19, MRASCEVDEF_N->CHK_FIELD_19, sizeof(MRASCEVDEF->CHK_FIELD_19));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_20, MRASCEVDEF_N->CHK_FIELD_20, sizeof(MRASCEVDEF->CHK_FIELD_20));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_21, MRASCEVDEF_N->CHK_FIELD_21, sizeof(MRASCEVDEF->CHK_FIELD_21));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_22, MRASCEVDEF_N->CHK_FIELD_22, sizeof(MRASCEVDEF->CHK_FIELD_22));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_23, MRASCEVDEF_N->CHK_FIELD_23, sizeof(MRASCEVDEF->CHK_FIELD_23));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_24, MRASCEVDEF_N->CHK_FIELD_24, sizeof(MRASCEVDEF->CHK_FIELD_24));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_25, MRASCEVDEF_N->CHK_FIELD_25, sizeof(MRASCEVDEF->CHK_FIELD_25));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_26, MRASCEVDEF_N->CHK_FIELD_26, sizeof(MRASCEVDEF->CHK_FIELD_26));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_27, MRASCEVDEF_N->CHK_FIELD_27, sizeof(MRASCEVDEF->CHK_FIELD_27));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_28, MRASCEVDEF_N->CHK_FIELD_28, sizeof(MRASCEVDEF->CHK_FIELD_28));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_29, MRASCEVDEF_N->CHK_FIELD_29, sizeof(MRASCEVDEF->CHK_FIELD_29));
    MEMCPY_DN(MRASCEVDEF->CHK_FIELD_30, MRASCEVDEF_N->CHK_FIELD_30, sizeof(MRASCEVDEF->CHK_FIELD_30));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_1, MRASCEVDEF_N->CHG_ITEM_1, sizeof(MRASCEVDEF->CHG_ITEM_1));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_2, MRASCEVDEF_N->CHG_ITEM_2, sizeof(MRASCEVDEF->CHG_ITEM_2));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_3, MRASCEVDEF_N->CHG_ITEM_3, sizeof(MRASCEVDEF->CHG_ITEM_3));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_4, MRASCEVDEF_N->CHG_ITEM_4, sizeof(MRASCEVDEF->CHG_ITEM_4));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_5, MRASCEVDEF_N->CHG_ITEM_5, sizeof(MRASCEVDEF->CHG_ITEM_5));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_6, MRASCEVDEF_N->CHG_ITEM_6, sizeof(MRASCEVDEF->CHG_ITEM_6));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_7, MRASCEVDEF_N->CHG_ITEM_7, sizeof(MRASCEVDEF->CHG_ITEM_7));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_8, MRASCEVDEF_N->CHG_ITEM_8, sizeof(MRASCEVDEF->CHG_ITEM_8));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_9, MRASCEVDEF_N->CHG_ITEM_9, sizeof(MRASCEVDEF->CHG_ITEM_9));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_10, MRASCEVDEF_N->CHG_ITEM_10, sizeof(MRASCEVDEF->CHG_ITEM_10));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_11, MRASCEVDEF_N->CHG_ITEM_11, sizeof(MRASCEVDEF->CHG_ITEM_11));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_12, MRASCEVDEF_N->CHG_ITEM_12, sizeof(MRASCEVDEF->CHG_ITEM_12));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_13, MRASCEVDEF_N->CHG_ITEM_13, sizeof(MRASCEVDEF->CHG_ITEM_13));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_14, MRASCEVDEF_N->CHG_ITEM_14, sizeof(MRASCEVDEF->CHG_ITEM_14));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_15, MRASCEVDEF_N->CHG_ITEM_15, sizeof(MRASCEVDEF->CHG_ITEM_15));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_16, MRASCEVDEF_N->CHG_ITEM_16, sizeof(MRASCEVDEF->CHG_ITEM_16));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_17, MRASCEVDEF_N->CHG_ITEM_17, sizeof(MRASCEVDEF->CHG_ITEM_17));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_18, MRASCEVDEF_N->CHG_ITEM_18, sizeof(MRASCEVDEF->CHG_ITEM_18));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_19, MRASCEVDEF_N->CHG_ITEM_19, sizeof(MRASCEVDEF->CHG_ITEM_19));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_20, MRASCEVDEF_N->CHG_ITEM_20, sizeof(MRASCEVDEF->CHG_ITEM_20));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_21, MRASCEVDEF_N->CHG_ITEM_21, sizeof(MRASCEVDEF->CHG_ITEM_21));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_22, MRASCEVDEF_N->CHG_ITEM_22, sizeof(MRASCEVDEF->CHG_ITEM_22));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_23, MRASCEVDEF_N->CHG_ITEM_23, sizeof(MRASCEVDEF->CHG_ITEM_23));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_24, MRASCEVDEF_N->CHG_ITEM_24, sizeof(MRASCEVDEF->CHG_ITEM_24));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_25, MRASCEVDEF_N->CHG_ITEM_25, sizeof(MRASCEVDEF->CHG_ITEM_25));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_26, MRASCEVDEF_N->CHG_ITEM_26, sizeof(MRASCEVDEF->CHG_ITEM_26));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_27, MRASCEVDEF_N->CHG_ITEM_27, sizeof(MRASCEVDEF->CHG_ITEM_27));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_28, MRASCEVDEF_N->CHG_ITEM_28, sizeof(MRASCEVDEF->CHG_ITEM_28));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_29, MRASCEVDEF_N->CHG_ITEM_29, sizeof(MRASCEVDEF->CHG_ITEM_29));
    MEMCPY_DN(MRASCEVDEF->CHG_ITEM_30, MRASCEVDEF_N->CHG_ITEM_30, sizeof(MRASCEVDEF->CHG_ITEM_30));
    MRASCEVDEF->CHG_FLAG_1 = MRASCEVDEF_N->CHG_FLAG_1[0];
    MRASCEVDEF->CHG_FLAG_2 = MRASCEVDEF_N->CHG_FLAG_2[0];
    MRASCEVDEF->CHG_FLAG_3 = MRASCEVDEF_N->CHG_FLAG_3[0];
    MRASCEVDEF->CHG_FLAG_4 = MRASCEVDEF_N->CHG_FLAG_4[0];
    MRASCEVDEF->CHG_FLAG_5 = MRASCEVDEF_N->CHG_FLAG_5[0];
    MRASCEVDEF->CHG_FLAG_6 = MRASCEVDEF_N->CHG_FLAG_6[0];
    MRASCEVDEF->CHG_FLAG_7 = MRASCEVDEF_N->CHG_FLAG_7[0];
    MRASCEVDEF->CHG_FLAG_8 = MRASCEVDEF_N->CHG_FLAG_8[0];
    MRASCEVDEF->CHG_FLAG_9 = MRASCEVDEF_N->CHG_FLAG_9[0];
    MRASCEVDEF->CHG_FLAG_10 = MRASCEVDEF_N->CHG_FLAG_10[0];
    MRASCEVDEF->CHG_FLAG_11 = MRASCEVDEF_N->CHG_FLAG_11[0];
    MRASCEVDEF->CHG_FLAG_12 = MRASCEVDEF_N->CHG_FLAG_12[0];
    MRASCEVDEF->CHG_FLAG_13 = MRASCEVDEF_N->CHG_FLAG_13[0];
    MRASCEVDEF->CHG_FLAG_14 = MRASCEVDEF_N->CHG_FLAG_14[0];
    MRASCEVDEF->CHG_FLAG_15 = MRASCEVDEF_N->CHG_FLAG_15[0];
    MRASCEVDEF->CHG_FLAG_16 = MRASCEVDEF_N->CHG_FLAG_16[0];
    MRASCEVDEF->CHG_FLAG_17 = MRASCEVDEF_N->CHG_FLAG_17[0];
    MRASCEVDEF->CHG_FLAG_18 = MRASCEVDEF_N->CHG_FLAG_18[0];
    MRASCEVDEF->CHG_FLAG_19 = MRASCEVDEF_N->CHG_FLAG_19[0];
    MRASCEVDEF->CHG_FLAG_20 = MRASCEVDEF_N->CHG_FLAG_20[0];
    MRASCEVDEF->CHG_FLAG_21 = MRASCEVDEF_N->CHG_FLAG_21[0];
    MRASCEVDEF->CHG_FLAG_22 = MRASCEVDEF_N->CHG_FLAG_22[0];
    MRASCEVDEF->CHG_FLAG_23 = MRASCEVDEF_N->CHG_FLAG_23[0];
    MRASCEVDEF->CHG_FLAG_24 = MRASCEVDEF_N->CHG_FLAG_24[0];
    MRASCEVDEF->CHG_FLAG_25 = MRASCEVDEF_N->CHG_FLAG_25[0];
    MRASCEVDEF->CHG_FLAG_26 = MRASCEVDEF_N->CHG_FLAG_26[0];
    MRASCEVDEF->CHG_FLAG_27 = MRASCEVDEF_N->CHG_FLAG_27[0];
    MRASCEVDEF->CHG_FLAG_28 = MRASCEVDEF_N->CHG_FLAG_28[0];
    MRASCEVDEF->CHG_FLAG_29 = MRASCEVDEF_N->CHG_FLAG_29[0];
    MRASCEVDEF->CHG_FLAG_30 = MRASCEVDEF_N->CHG_FLAG_30[0];
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_1, MRASCEVDEF_N->CHG_VALUE_1, sizeof(MRASCEVDEF->CHG_VALUE_1));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_2, MRASCEVDEF_N->CHG_VALUE_2, sizeof(MRASCEVDEF->CHG_VALUE_2));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_3, MRASCEVDEF_N->CHG_VALUE_3, sizeof(MRASCEVDEF->CHG_VALUE_3));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_4, MRASCEVDEF_N->CHG_VALUE_4, sizeof(MRASCEVDEF->CHG_VALUE_4));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_5, MRASCEVDEF_N->CHG_VALUE_5, sizeof(MRASCEVDEF->CHG_VALUE_5));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_6, MRASCEVDEF_N->CHG_VALUE_6, sizeof(MRASCEVDEF->CHG_VALUE_6));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_7, MRASCEVDEF_N->CHG_VALUE_7, sizeof(MRASCEVDEF->CHG_VALUE_7));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_8, MRASCEVDEF_N->CHG_VALUE_8, sizeof(MRASCEVDEF->CHG_VALUE_8));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_9, MRASCEVDEF_N->CHG_VALUE_9, sizeof(MRASCEVDEF->CHG_VALUE_9));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_10, MRASCEVDEF_N->CHG_VALUE_10, sizeof(MRASCEVDEF->CHG_VALUE_10));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_11, MRASCEVDEF_N->CHG_VALUE_11, sizeof(MRASCEVDEF->CHG_VALUE_11));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_12, MRASCEVDEF_N->CHG_VALUE_12, sizeof(MRASCEVDEF->CHG_VALUE_12));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_13, MRASCEVDEF_N->CHG_VALUE_13, sizeof(MRASCEVDEF->CHG_VALUE_13));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_14, MRASCEVDEF_N->CHG_VALUE_14, sizeof(MRASCEVDEF->CHG_VALUE_14));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_15, MRASCEVDEF_N->CHG_VALUE_15, sizeof(MRASCEVDEF->CHG_VALUE_15));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_16, MRASCEVDEF_N->CHG_VALUE_16, sizeof(MRASCEVDEF->CHG_VALUE_16));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_17, MRASCEVDEF_N->CHG_VALUE_17, sizeof(MRASCEVDEF->CHG_VALUE_17));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_18, MRASCEVDEF_N->CHG_VALUE_18, sizeof(MRASCEVDEF->CHG_VALUE_18));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_19, MRASCEVDEF_N->CHG_VALUE_19, sizeof(MRASCEVDEF->CHG_VALUE_19));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_20, MRASCEVDEF_N->CHG_VALUE_20, sizeof(MRASCEVDEF->CHG_VALUE_20));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_21, MRASCEVDEF_N->CHG_VALUE_21, sizeof(MRASCEVDEF->CHG_VALUE_21));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_22, MRASCEVDEF_N->CHG_VALUE_22, sizeof(MRASCEVDEF->CHG_VALUE_22));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_23, MRASCEVDEF_N->CHG_VALUE_23, sizeof(MRASCEVDEF->CHG_VALUE_23));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_24, MRASCEVDEF_N->CHG_VALUE_24, sizeof(MRASCEVDEF->CHG_VALUE_24));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_25, MRASCEVDEF_N->CHG_VALUE_25, sizeof(MRASCEVDEF->CHG_VALUE_25));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_26, MRASCEVDEF_N->CHG_VALUE_26, sizeof(MRASCEVDEF->CHG_VALUE_26));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_27, MRASCEVDEF_N->CHG_VALUE_27, sizeof(MRASCEVDEF->CHG_VALUE_27));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_28, MRASCEVDEF_N->CHG_VALUE_28, sizeof(MRASCEVDEF->CHG_VALUE_28));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_29, MRASCEVDEF_N->CHG_VALUE_29, sizeof(MRASCEVDEF->CHG_VALUE_29));
    MEMCPY_DN(MRASCEVDEF->CHG_VALUE_30, MRASCEVDEF_N->CHG_VALUE_30, sizeof(MRASCEVDEF->CHG_VALUE_30));
    MRASCEVDEF->CHG_OPT_1 = MRASCEVDEF_N->CHG_OPT_1[0];
    MRASCEVDEF->CHG_OPT_2 = MRASCEVDEF_N->CHG_OPT_2[0];
    MRASCEVDEF->CHG_OPT_3 = MRASCEVDEF_N->CHG_OPT_3[0];
    MRASCEVDEF->CHG_OPT_4 = MRASCEVDEF_N->CHG_OPT_4[0];
    MRASCEVDEF->CHG_OPT_5 = MRASCEVDEF_N->CHG_OPT_5[0];
    MRASCEVDEF->CHG_OPT_6 = MRASCEVDEF_N->CHG_OPT_6[0];
    MRASCEVDEF->CHG_OPT_7 = MRASCEVDEF_N->CHG_OPT_7[0];
    MRASCEVDEF->CHG_OPT_8 = MRASCEVDEF_N->CHG_OPT_8[0];
    MRASCEVDEF->CHG_OPT_9 = MRASCEVDEF_N->CHG_OPT_9[0];
    MRASCEVDEF->CHG_OPT_10 = MRASCEVDEF_N->CHG_OPT_10[0];
    MRASCEVDEF->CHG_OPT_11 = MRASCEVDEF_N->CHG_OPT_11[0];
    MRASCEVDEF->CHG_OPT_12 = MRASCEVDEF_N->CHG_OPT_12[0];
    MRASCEVDEF->CHG_OPT_13 = MRASCEVDEF_N->CHG_OPT_13[0];
    MRASCEVDEF->CHG_OPT_14 = MRASCEVDEF_N->CHG_OPT_14[0];
    MRASCEVDEF->CHG_OPT_15 = MRASCEVDEF_N->CHG_OPT_15[0];
    MRASCEVDEF->CHG_OPT_16 = MRASCEVDEF_N->CHG_OPT_16[0];
    MRASCEVDEF->CHG_OPT_17 = MRASCEVDEF_N->CHG_OPT_17[0];
    MRASCEVDEF->CHG_OPT_18 = MRASCEVDEF_N->CHG_OPT_18[0];
    MRASCEVDEF->CHG_OPT_19 = MRASCEVDEF_N->CHG_OPT_19[0];
    MRASCEVDEF->CHG_OPT_20 = MRASCEVDEF_N->CHG_OPT_20[0];
    MRASCEVDEF->CHG_OPT_21 = MRASCEVDEF_N->CHG_OPT_21[0];
    MRASCEVDEF->CHG_OPT_22 = MRASCEVDEF_N->CHG_OPT_22[0];
    MRASCEVDEF->CHG_OPT_23 = MRASCEVDEF_N->CHG_OPT_23[0];
    MRASCEVDEF->CHG_OPT_24 = MRASCEVDEF_N->CHG_OPT_24[0];
    MRASCEVDEF->CHG_OPT_25 = MRASCEVDEF_N->CHG_OPT_25[0];
    MRASCEVDEF->CHG_OPT_26 = MRASCEVDEF_N->CHG_OPT_26[0];
    MRASCEVDEF->CHG_OPT_27 = MRASCEVDEF_N->CHG_OPT_27[0];
    MRASCEVDEF->CHG_OPT_28 = MRASCEVDEF_N->CHG_OPT_28[0];
    MRASCEVDEF->CHG_OPT_29 = MRASCEVDEF_N->CHG_OPT_29[0];
    MRASCEVDEF->CHG_OPT_30 = MRASCEVDEF_N->CHG_OPT_30[0];
    MEMCPY_DN(MRASCEVDEF->CREATE_USER_ID, MRASCEVDEF_N->CREATE_USER_ID, sizeof(MRASCEVDEF->CREATE_USER_ID));
    MEMCPY_DN(MRASCEVDEF->CREATE_TIME, MRASCEVDEF_N->CREATE_TIME, sizeof(MRASCEVDEF->CREATE_TIME));
    MEMCPY_DN(MRASCEVDEF->UPDATE_USER_ID, MRASCEVDEF_N->UPDATE_USER_ID, sizeof(MRASCEVDEF->UPDATE_USER_ID));
    MEMCPY_DN(MRASCEVDEF->UPDATE_TIME, MRASCEVDEF_N->UPDATE_TIME, sizeof(MRASCEVDEF->UPDATE_TIME));
}


